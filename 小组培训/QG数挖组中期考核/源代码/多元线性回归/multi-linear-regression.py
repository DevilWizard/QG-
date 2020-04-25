import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn import metrics

sample_path="C:\\Users\\13415\\Desktop\\小组培训\\中期考核\\数据集\\housing.txt"
# CRIM：城镇人均犯罪率。
# ZN：住宅用地超过 25000 sq.ft. 的比例。
# INDUS：城镇非零售商用土地的比例。
# CHAS：查理斯河空变量（如果边界是河流，则为1；否则为0）。
# NOX：一氧化氮浓度。
# RM：住宅平均房间数。
# AGE：1940 年之前建成的自用房屋比例。
# DIS：到波士顿五个中心区域的加权距离。
# RAD：辐射性公路的接近指数。
# TAX：每 10000 美元的全值财产税率。
# PTRATIO：城镇师生比例。
# B：1000（Bk-0.63）^ 2，其中 Bk 指代城镇中黑人的比例。
# LSTAT：人口中地位低下者的比例。
# MEDV：自住房的平均房价，以千美元计。
#预测MEDV，即房价

class_name=['CRIM','ZN','INDUS','CHAS','NOX','RM','AGE','DIS','RAD','TAX','PTRATIO','B','LSTAT','MEDV']
house_info=pd.read_csv(sample_path ,sep='\s+',header=None ,names=class_name )       #读取空格数不定的文件
sample=house_info[class_name[:len(class_name)-1]]
price=house_info['MEDV']
last=np.ones(len(price))
x,y=np.matrix(np.column_stack((sample.values,last))),np.matrix(price.values)    #转化为matrix矩阵
#print(x.shape,y.shape)
vector_w=((((x.T)*x)).I)*(x.T)*(y.T)        #多元线性回归方程的wi及b组成的向量
print("由最小二乘法法拟合所得线性回归方程为: y = %.2f*x1 + %.2f*x2 + %.2f*x3 + %.2f*x4 + %.2f*x5 + %.2f*x6 + %.2f*x7 + %.2f*x8 + %.2f*x9 + %.2f*x10 + %.2f*x11 + %.2f*x12 + %.2f*x13 + %.2f"
                           %(vector_w[0],vector_w[1],vector_w[2],vector_w[3],vector_w[4],vector_w[5],vector_w[6],
                             vector_w[7],vector_w[8],vector_w[9],vector_w[10],vector_w[11],vector_w[12],vector_w[13]))


#梯度下降法寻找最优w,使损失函数最小

X = np.column_stack((sample.values,last))
w = np.ones([14,1])
true_val = price.values.reshape(506,1)
#print((((X.sum(axis=0))/506).T).reshape(14,1))
#print(X.shape,w.shape,true_val.shape)


def gradient_descent( true_val, X , w , learning_rate = 4e-9 ,range = 1e-8, MAX_LOOP = 1e6  ):      #传入为np.array格式

    #loss=(true_val - pred_val)**2  //用均方差定义损失函数

    def loss(y_true,y_pred):    #传入为np.array格式
        result = np.dot( ( (y_true-y_pred).T ) , y_true-y_pred )[0][0]             #(round(abs((y_true-y_pred)).sum(axis=0)[0],2)/506)**2   #对列求和后平方
        return result

     #w=w-learning_rate*(dloss/dw)     //梯度迭代更新,当dloss<=range时停止迭代


    y_pred_old=np.dot(X,w)
    #print(loss(true_val , y_pred_old))
    #print(np.dot(- X.T , (true_val-y_pred_old) ))
    w = w - (  learning_rate * 2 * np.dot(- X.T , (true_val-y_pred_old) ) )
    y_pred_new = np.dot(X, w)  # 更新预测值
    #print(w)
    #print(loss(true_val,y_pred_new))
    loop_time =0
    while abs( loss(true_val,y_pred_new)-loss(true_val,y_pred_old) ) > range  :

        y_pred_old = y_pred_new
        w = w - (  learning_rate * 2 * np.dot(- X.T , (true_val-y_pred_old) ) )
        y_pred_new = np.dot(X,w)      #更新预测值
        loop_time+=1

        if loop_time == MAX_LOOP :
            break

    return w        #返回最优w


best_w = gradient_descent(true_val , X , w)
#print(best_w)


print("由梯度下降法所得线性回归方程为: y = %.2f*x1 + %.2f*x2 + %.2f*x3 + %.2f*x4 + %.2f*x5 + %.2f*x6 + %.2f*x7 + %.2f*x8 + %.2f*x9 + %.2f*x10 + %.2f*x11 + %.2f*x12 + %.2f*x13 + %.2f"
                           %(best_w[0],best_w[1],best_w[2],best_w[3],best_w[4],best_w[5],best_w[6],
                             best_w[7],best_w[8],best_w[9],best_w[10],best_w[11],best_w[12],best_w[13]))


def sk_model():
    model = LinearRegression()
    x_data = sample.values
    y_data = price.values
    model.fit(x_data, y_data)
    sk_pred = model.predict(x_data)
    MSE = metrics.mean_squared_error(y_data , sk_pred)
    return sk_pred[:250] ,MSE

sk_pred , sk_MSE= sk_model()

#对比梯度下降、sklearn库中的模型所得回归方程的预测与真实值
def evaluate():

    price_predict = (X.dot(best_w)).reshape(506,1)
    price_true = price.values.reshape(506,1)
    plt.figure(figsize=(10,10))
    plt.title('House_predict_model_evaluate',fontsize=20)
    plt.plot(price_predict[:250 ,:],label='gradient_regression_predict')
    plt.plot(sk_pred,label='sklearn_model')
    plt.plot(price_true[:250 ,:],label='true_value')
    plt.xlabel('sample_num',fontsize=20)
    plt.ylabel('house_price',fontsize=20)
    plt.grid('off')
    plt.legend(fontsize=15)
    plt.show()

    gradient_MSE = (((price_predict-price_true).T).dot(price_predict-price_true))/506
    print("梯度下降模型均方差为%.2f , sklearn中多元线性回归模型均方差为%.2f" %(gradient_MSE , sk_MSE)  )

evaluate()



#下面为根据用户输入的参数，预测房价

# print("                   CRIM    ZN   INDUS   CHAS    NOX    RM    AGE   DIS   RAD   TAX   PTRATIO    B   LSTAT")
# L=[i for i in range(13)]
# L[0],L[1],L[2],L[3],L[4],L[5],L[6],L[7],L[8],L[9],L[10],L[11],L[12]=map( lambda x:float(x) , input("请依次输入各参数：").split())
#input=(  0.00632 , 18.00  , 2.310 , 0 , 0.5380 , 6.5750 , 65.20 , 4.0900  , 1 , 296.0 , 15.30 ,396.90 ,  4.98,1)  #输入需要预测的参数，最后加上1
# L.append(1)
# np.matrix(L)
# input=np.matrix(L)
#predict=np.array(input).dot(best_w)
#print("预计平均房价为%.3f千美元"%predict[0])

