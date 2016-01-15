%% load data
citra1 = imread('iris_setosa.jpg');
citra2 = imread('iris_versicolor.jpg');
citra3 = imread('iris_virginica.jpg');

data = zeros(3,100);

pic = rgb2gray(citra1);
pic = double(pic);
%[m,n] = size(pic);
pic2 = imresize(pic,[10 10]);
[m,n] = size(pic2);
pic_v = reshape(pic2,1,m*n);
data(1,:) = pic_v;

pic = rgb2gray(citra2);
pic = double(pic);
%[m,n] = size(pic);
pic2 = imresize(pic,[10 10]);
[m,n] = size(pic2);
pic_v = reshape(pic2,1,m*n);
data(2,:) = pic_v;

pic = rgb2gray(citra3);
pic = double(pic);
%[m,n] = size(pic);
pic2 = imresize(pic,[10 10]);
[m,n] = size(pic2);
pic_v = reshape(pic2,1,m*n);
data(3,:) = pic_v;
%% pca
cov_data = cov(data);
[pc,eigval,exp] = pcacov(cov_data);
new_data = data*pc(:,1:5);
%% hierarchical clustering
dist = pdist(new_data);
z = linkage(dist);
dendrogram(z);