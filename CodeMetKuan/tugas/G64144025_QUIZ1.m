tesPeg = [
5 4 3 3;
4 3 3 3;
3 3 3 3;
3 3 3 3;
3 3 2 2;
5 4 4 3;
5 4 3 3;
5 3 3 3;
3 3 3 3;
2 3 3 3;
]

x=[3 1 2 1;]
y=[5 2 3 4;]
z=[4 3 5 2;]

group = [0; 0; 1; 1; 2; 0; 0; 0; 1; 1;]

class1 = knnclassify(x, tesPeg, group, 3)

class2 = knnclassify(y, tesPeg, group, 3)

class3 = knnclassify(z, tesPeg, group, 3)