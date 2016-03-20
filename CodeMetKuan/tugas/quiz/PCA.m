picture = imread('bunga.jpg');
picture_g = rgb2gray(picture);
picture_d = double(picture_g);
picture_cov = cov(picture_d);
[pc,eigval,exp] = pcacov(picture_cov);
picture_new = picture_d*pc(:,1:35);
imshow(picture_new);