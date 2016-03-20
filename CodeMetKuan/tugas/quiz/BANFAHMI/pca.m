gambar=imread('bunga.jpg');
gambar_gs=rgb2gray(gambar);
gambar_dbl=double(gambar_gs);
cov_gambar=cov(gambar_dbl);
[pc,eigval,exp]=pcacov(cov_gambar);
gambar_baru=gambar_dbl*pc(:,1:35);
figure,imshow(gambar_baru)