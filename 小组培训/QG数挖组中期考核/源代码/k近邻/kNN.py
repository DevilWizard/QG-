import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import operator
import math
from  sklearn.neighbors import KNeighborsClassifier

data_path = "C:\\Users\\13415\\Desktop\\小组培训\\中期考核\\数据集\\iris\\iris.data"

data_set = pd.read_csv(data_path)
data_set = data_set.sample(frac=1).reset_index(drop=True)       #随机打乱处理
label = list(data_set)
print(data_set,label)
#训练集和测试集为2：1分配
x_train,x_test,y_train,y_test = ((data_set[label[:4]]).values)[:100,:] , ((data_set[label[:4]]).values)[100:,:],((data_set[label[4:]]).values)[:100,:] , ((data_set[label[4:]]).values)[100:,:]

print(x_train.shape , x_test.shape , y_train.shape , y_test.shape)

def knn_model(inX , x_train , y_train , k):

    inX = np.array(inX).reshape(1,4)
    square = (inX - x_train)**2
    square_sum = square.sum(axis=1)
    d = square_sum**0.5
    sortindex = d.argsort()     #返回按距离从小到大排序的索引值
    sort_label = y_train[sortindex]
    k_label = sort_label[:k]
    class_count={}
    for i in range(k):
        class_count[k_label[i][0]] = class_count.get(k_label[i][0] , 0 ) + 1

    sort_class_count = sorted(class_count.items() , key=operator.itemgetter(1) ,reverse =True)
    return sort_class_count[0][0]

#knn_model([7.0,3.2,4.7,1.4] , x_train , y_train ,3)




#计算优化前和优化后的模型在50个测试集上的错误率
def error_rate(x_test , y_test , x_train , y_train , k , model_name='model'):

    test_size = x_test.shape[0]
    error_num = 0
    if model_name == 'knn':

        for sample in x_test  :
            for label in y_test :
                if knn_model(sample ,x_train , y_train , k ) != label[0] :
                    error_num+=1

        print("该模型在%d个测试集上的错误率为%.2f" %( test_size, error_num/test_size) + "%")
        return  error_num/test_size

    elif model_name == 'optimizer_knn':

        for sample in x_test:
            for label in y_test:
                if optimizer_knn(sample, x_train, y_train, k) != label[0]:
                    error_num += 1

        print("经加权优化后的模型在%d个测试集上的错误率为%.2f" % (test_size, error_num/test_size) + "%")
        return  error_num/test_size



error_rate(x_test , y_test , x_train , y_train , 3 ,model_name='knn')

def gaussian_weight(x , a=1 , b=0.9 , c=0.8):
    return a*((math.e)**(-( (x-b)**2 )/(2*(c**2) ) ))


#用高斯函数加权优化，避免平均分配权值为1,距离越远，权值越大
def optimizer_knn(inX, x_train, y_train, k):

        inX = np.array(inX).reshape(1, 4)
        square = (inX- x_train) ** 2
        square_sum = square.sum(axis=1)
        d = square_sum ** 0.5
        sortindex = d.argsort()  # 返回按距离从小到大排序的索引值
        sort_label = y_train[sortindex]
        sort_d = d[sortindex]
        k_label = sort_label[:k]
        class_count = {}
        for i in range(k):
            class_count[k_label[i][0]] = class_count.get(k_label[i][0], 0) + 1*gaussian_weight(sort_d[i])   #具体优化处
        sort_class_count = sorted(class_count.items(), key=operator.itemgetter(1), reverse=True)
        return sort_class_count[0][0]

#optimizer_knn([7.0,3.2,4.7,1.4],x_train , y_train ,3)



error_rate(x_test , y_test ,x_train,y_train ,3,model_name='optimizer_knn')

def sk_knn(x_train , y_train , x_test , y_test):
    #y_train = y_train.reshape()
    sk_knn_model = KNeighborsClassifier(n_neighbors=3 , weights='distance')
    sk_knn_model.fit(x_train , y_train)

    def sk_knn_error(x_test , y_test) :
        test_size = x_test.shape[0]
        error_num = 0
        for pred in sk_knn_model.predict(x_test):
            for label in y_test:
                if  pred != label[0]:
                    error_num += 1

        print("sklearn的KNN模型在%d个测试集上的错误率为%.2f" % (test_size, error_num / test_size) + "%")

    sk_knn_error(x_test , y_test)

sk_knn(x_train , y_train , x_test , y_test)