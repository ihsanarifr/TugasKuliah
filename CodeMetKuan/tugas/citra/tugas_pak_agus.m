%% load data
citra1 = imread('apel1.jpg');
citra2 = imread('apel2.jpg');
citra3 = imread('apel3.jpg');
citra4 = imread('apel4.png');
citra5 = imread('apel5.jpg');
citra6 = imread('apel6.png');
citra7 = imread('apel7.jpg');
citra8 = imread('apel8.jpg');
citra9 = imread('apel9.jpg');
citra10 = imread('hijau10.jpg');
citra11 = imread('hijau1.jpg');
citra12 = imread('hijau2.jpg');
citra13 = imread('hijau3.jpg');
citra14 = imread('hijau4.jpg');
citra15 = imread('hijau5.jpg');
citra16 = imread('hijau6.jpg');
citra17 = imread('hijau7.jpg');
citra18 = imread('hijau8.jpg');
citra19 = imread('hijau9.jpg');
citra20 = imread('hijau10.jpg');
citra21 = imread('kiwi.jpg');
citra22 = imread('kiwi2.jpg');
citra23 = imread('kiwi3.jpg');
citra24 = imread('kiwi4.jpg');
citra25 = imread('kiwi5.jpg');
citra26 = imread('kiwi6.png');
citra27 = imread('kiwi7.jpg');
citra28 = imread('kiwi8.jpg');
citra29 = imread('kiwi9.jpg');
citra30 = imread('kiwi10.jpg');
citra31 = imread('pear1.jpg');
citra32 = imread('pear2.jpg');
citra33 = imread('pear3.jpeg');
citra34 = imread('pear4.jpg');
citra35 = imread('pear5.jpg');
citra36 = imread('pear6.jpg');
citra37 = imread('pear7.jpg');
citra38 = imread('pear8.jpg');
citra39 = imread('pear9.jpg');
citra40 = imread('pear10.jpg');
citra41 = imread('pisang1.jpg');
citra42 = imread('pisang2.jpg');
citra43 = imread('pisang3.jpg');
citra44 = imread('pisang4.jpg');
citra45 = imread('pisang5.jpg');
citra46 = imread('pisang6.jpg');
citra47 = imread('pisang7.jpg');
citra48 = imread('pisang8.jpg');
citra49 = imread('pisang9.jpg');
citra50 = imread('pisang10.jpg');

% data = zeros(3,100);
% 
% pic = rgb2gray(citra1);
% pic = double(pic);
% %[m,n] = size(pic);
% pic2 = imresize(pic,[10 10]);
% [m,n] = size(pic2);
% pic_v = reshape(pic2,1,m*n);
% data(1,:) = pic_v;

%% Looping data image 50
data = zeros(50,900);
for i=1:50
%      eval(['citra' num2str(i) '= imread(apel' num2str(i) '.jpg')]);
    citra1 = imread('apel1.jpg');
    eval(['pic' num2str(i) '= rgb2gray(citra' num2str(i) ')']);
    eval(['pic' num2str(i) '= double(pic' num2str(i) ')']);
    eval(['p_resize' num2str(i) '= imresize(pic' num2str(i) ',[30 30])']);
    eval(['p_v' num2str(i) '= reshape(p_resize' num2str(i) ',1,30*30)']);
    data(i,:) = eval(['p_v' num2str(i)]);
end;


%% pca
% cov_data = cov(data);
% [pc,eigval,exp] = pcacov(cov_data);
% new_data = data*pc(:,1:5);

%% hierarchical clustering
% dist = pdist(new_data);
% z = linkage(dist);
% dendrogram(z);


%% data 70 persen
data70_persen = data*pc(:,1:7);
dist_data70 = pdist(data70_persen);
z_data70 = linkage(dist_data70);
dendrogram(z_data70);

%% data 70 persen
data90_persen = data*pc(:,1:20);
dist_data90 = pdist(data90_persen);
z_data90 = linkage(dist_data90);
dendrogram(z_data90);