from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler


def classification(train_feature, train_label, test_feature):
    '''
    使用KNeighborsClassifier对test_feature进行分类
    :param train_feature: 训练集数据
    :param train_label: 训练集标签
    :param test_feature: 测试集数据
    :return: 测试集预测结果
    '''

    # ********* Begin *********#
    scaler = StandardScaler()
    X_train = scaler.fit_transform(train_feature)
    X_test = scaler.transform(test_feature)
    clf = KNeighborsClassifier()
    clf.fit(X_train, train_label)
    return clf.predict(X_test)

    # ********* End *********#
