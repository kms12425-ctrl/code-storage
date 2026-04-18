from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.feature_extraction.text import TfidfTransformer


def news_predict(train_sample, train_label, test_sample):
    '''
    训练模型并进行预测，返回预测结果
    :param train_sample:原始训练集中的新闻文本，类型为ndarray
    :param train_label:训练集中新闻文本对应的主题标签，类型为ndarray
    :param test_sample:原始测试集中的新闻文本，类型为ndarray
    :return 预测结果，类型为ndarray
    '''

    # ********* Begin *********#
    # 实例化向量化对象
    vec = CountVectorizer()
    # 将训练集中的新闻向量化
    X_train = vec.fit_transform(train_sample)
    # 将测试集中的新闻向量化
    X_test = vec.transform(test_sample)

    # 实例化tf-idf对象
    tfidf = TfidfTransformer()
    # 将训练集中的词频向量用tf-idf进行转换
    X_train_tfidf = tfidf.fit_transform(X_train)
    # 将测试集中的词频向量用tf-idf进行转换
    X_test_tfidf = tfidf.transform(X_test)
    clf = MultinomialNB(alpha=1)

    clf.fit(X_train_tfidf, train_label)
    result = clf.predict(X_test_tfidf)
# ********* End *********#
