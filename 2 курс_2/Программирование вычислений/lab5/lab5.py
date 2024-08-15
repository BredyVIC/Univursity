import math
coords=[]  #Массив для хранения координат вершин, каждый элемент которого - список из двух координат(x и y)
table={}  #В хэш таблице в качестве ключа выступают номера вершин (0,1)/(2,3),образующих ребро,а в качестве значений сколько раз они встретились

def add_in_table(table,a,b):
    edge=(min(a,b),max(a,b))  # В  таблицу будем добавлять рёбра, между номерами вершин,где первый номер меньше второго,
    if edge in table:  # благодаря этому ребро с номерами вершин 3-4 и 4-3 считаются как одно
        table[edge]+=1
    else:
        table[edge]=1

line=input().split()
N=int(line[0])
M=int(line[1])
for i in range(N):
    line=input().split()
    x=int(line[0])
    y=int(line[1])
    coords.append((x, y))
for i in range(M):
    line=input().split()
    v1=int(line[0])-1  #Нумерация с нуля
    v2=int(line[1])-1
    v3=int(line[2])-1
    add_in_table(table,v1,v2)
    add_in_table(table,v1,v3)
    add_in_table(table,v2,v3)

def len(a,b):  # Расстояние между двумя вершинами
    return math.sqrt(pow(a[0] - b[0],2) + pow(a[1] - b[1],2))

res=0
for edge,k in table.items():  #В итоговый результат будем складывать только длину рёбер, встретившихся один раз,таким образом получим длину забора по периметру
    if k==1:
        res+= len(coords[edge[0]], coords[edge[1]])
print("{:.3f}".format(res))
