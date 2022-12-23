# 필요한 라이브러리
from konlpy.tag import Mecab
import pandas as pd
import re
import numpy as np
import matplotlib.pyplot as plt
import os
import warnings
from transformers import ElectraTokenizer, ElectraModel
import torch
import string
import csv
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity
from sentence_transformers import SentenceTransformer
from keybert import KeyBERT
from scipy import stats
import io
from sklearn.feature_extraction.text import TfidfVectorizer

# 토크나이저 선언 및 데이터 가져오기
mecab = Mecab()
data = pd.read_csv("가져올 데이터 파일명", sep=";", encoding = "euc kr")

# 데이터 전처리 - 결측값 처리
data.dropna(subset=['isbn'])
data.fillna('없음', inplace = True)


# 제목에서 괄호 속 내용 제거
title_list = data['title'].to_list()
for i in range(len(title_list)):
    pattern = r"\([^)]*\)"
    title_list[i] = re.sub(pattern = pattern, repl="", string=title_list[i])

# 키워드 추출을 위해 제목, 소개, 서평이 합쳐진 새로운 열 soup 생성
intro_list = data['introduction'].to_list()
comment_list = data['publisher_comment'].to_list()
soup_list = []
for i in range(len(title_list)):
  soup = str(title_list[i]) + ' ' + str(intro_list[i]) + ' ' +  str(comment_list[i])
  soup_list.append(soup)
data['soup'] = soup_list

# 불용어 처리
def erase(x):
    x = str(x)
    x = x.replace("이 책은", "")
    x = x.replace("없음", "")
    x = x.replace("양장본", "")
    x = x.replace("전집", "")
    x = x.replace("위주", "")
    x = x.replace("세트", "")
    x = x.replace("최신판", "")
    x = x.replace("최신간", "")
    x = x.replace("개정판", "")
    x = x.replace("최신개정판", "")
    x = x.replace("단행본", "")
    x = x.replace("목차", "")
    x = x.replace("상품", "")
    x = re.sub('[-=+,#/\?:^.@*\"※~ㆍ!』‘|\(\)\[\]`\'…》\”\“\’·]', ' ', x)

data['soup'] = data['soup'].apply(erase)

# Mecab 품사 태깅으로 명사만 뽑아 키워드 추출하기
def make_keyword(x):
    x = str(x)
    li1 = x.split(" ")
    li2 = mecab.pos(x)
    li3 = []
    for a in li1:
        token = ""
        for b in li2:
            if b[1] == 'NNG' or b[1] == 'NNP' or b[1] == 'SN' or b[1] == 'NNBC':
                word = b[0]
                if a.find(word) != -1:
                    li3.append(word)
                    if token.find(word) == -1:
                        token = token + word
                if len(token) > 1 and len(token) < 15:
                    li3.append(token)
    set3 = set(li3)
    li3 = list(set3)
    return li3
data['token'] = data['soup'].apply(make_keyword)

# 키워드 추출을 위해 키버트 모델 생성
model = KeyBERT("ddobokki/electra-small-nli-sts")

# 키워드 추출 후 리스트에 저장
token = df['token']
token_list = token.tolist()
a = 0
b = 0
keywords_list = []
for i in token_list:
    doc = "".join(token_list[a])
    keywords = model.extract_keywords(doc,top_n = 10)
    keywords = " ".join(list(x for x,y in keywords))
    keywords_list.append(keywords)
    a += 1
    if(a%2000 == 0):
        print(a,'/',len(token_list),'.....')
df['main_keywords'] = keywords_list

# 카테고리 정보를 이용해 TF-IDF 키워드 추출
cat1 = data['Cn_1'].to_list()
cat2 = data['Cn_2'].to_list()
cat3 = data['Cn_3'].to_list()
cat4 = data['Cn_4'].to_list()

cat_list = []

for i in range(len(cat1)):
  content = cat1[i] + " " + cat2[i] + " " + cat3[i] + " " +  cat4[i]
  cat_list.append(content)

data['soup'] = cat_list

regex1 = '\([^)]*\)'
regex2 = '[^0-9]'
def find_max(x):
    x = str(x)
    x = x.replace(":", "")
    index_list = re.findall(regex1, x)
    text = re.sub(regex1, "", x)
    tfidf_list = text.split()
    
    tfidf_list = list(map(float, tfidf_list))
    
    max1 = 0
    index = 0
    return_value = []
    for i in range(len(tfidf_list)):
        if tfidf_list[i] >= max1:
            max1 = tfidf_list[i]
            index= i
    if index < len(index_list):
        return_value.append(index_list[index])
        return_value.append(tfidf_list[index])
        #return index_list[index]
        return return_value
    else:
        return -1

def separate1(x):
  if x != -1:
    x = list(map(str, x))
    x1 = x[0]
    x2 = x[1]
    x = x1
    return x2
  else:
    return -1

def separate2(x):
  if x != -1:
    x = list(map(str, x))
    x1 = x[0]
    x2 = x[1]
    return x1
  else:
    return -1

def remove(x):
    x = str(x)
    x = x.replace("(", "")
    x = x.replace(")", "")
    x = x.replace("0,", "")
    return int(x)

def keyword(data):
    
  #tfidf 계산
  tfidfv = TfidfVectorizer().fit(cat_list)
  #x = tfidfv.transform(data['keyword_introduction'].values.astype('U'))
  x = tfidfv.transform(cat_list)
  y = pd.DataFrame(x, columns = ['tfidf'])
  dict = tfidfv.vocabulary_
  
  #id랑 키워드 정보 있는 데이터프레임 생성
  dict1 = list(dict.keys())
  dict2 = list(dict.values())
  df1 = pd.DataFrame(dict1, columns=['word'])
  df2 = pd.DataFrame(dict2, columns=['id'])
  df = pd.concat([df1, df2], axis = 1)

  #tfidf값이 가장 큰 키워드 한 개 추출
  y['max_id'] = y['tfidf'].apply(find_max)
  y['tfidf_value'] = y['max_id'].apply(separate1)
  y['max_id'] = y['max_id'].apply(separate2)
  y['id'] = y['max_id'].apply(remove)
  y.drop(['max_id'], axis = 1, inplace = True)
  y.drop(['tfidf'], axis = 1, inplace = True)
  dataframe = pd.merge(y, df, how='left', on = 'id')
  
  #원래 데이터프레임에 합치기
  result = pd.concat([data, dataframe], axis = 1)
  return result

data = keyword(data)

# 메인 키워드와 TF-IDF 키워드 합치기
kw_list = data['main_keywords'].to_list()
word_list = data['word'].to_list()

for i in range(len(kw_list)):
      if kw_list[i].find(word_list[i]) == -1 and word_list[i] != '없음':
        kw_list[i] = word_list[i] + " " + kw_list[i]

data['main_keywords'] = kw_list
data.drop(['word'], inplace = True, axis =1)

# 키워드 후처리 - 자주 등장하거나 너무 적게 등장하는 단어 제거
count = pd.read_csv("파일명", encoding="utf8", sep=";") #vocab 파일 - 단어와 각 단어의 빈도 수가 저장됨

word_list = ['조침', '한계령', '염려증', '브라이트너', '학습', '작품', '이론', '작가', '양장본', '교재'] # 빈도 수 6만 이상은 직접 추가
words = count[count['counts'] < 15]
wordList = words['keyword'].to_list()
for x in wordList:
    word_list.append(x)

def delete_words(x):
    x = str(x)
    for a in word_list:
        x = x.replace(a, "")
    return x

data['main_keywords'] = data['main_keywords'].apply(delete_words)