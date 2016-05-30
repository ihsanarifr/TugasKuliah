%% Tugas CI - GA code - 05/31/2015
%% membangkitkan individu
nGen = 600; %banyaknya generasi
Npop = 20;
Nkromosom = 33;
Nx1 = 18;
Nx2 = 15;
x1 = zeros(Npop,1);
x2 = zeros(Npop,1);
fitness = zeros(Npop,1);
allFitness = zeros(Npop,nGen);
newInd = floor(rand(Npop,Nkromosom)*2);

%% iterasi
for iter=1:nGen %looping sebanyak epoch yang ditentukan
    %inisialisasi
    individu = newInd;
    v1 = zeros(Npop,Nx1);
    v2 = zeros(Npop,Nx2);
    %% perhitungan fitness
    for i=1:size(individu,1) %membagi individu menjadi x1
        v1(i,:) = individu(i,1:18);
        v2(i,:) = individu(i,19:end);
    end
    %mengubah v1 dan v2 ke bilangan desimal
    v1 = bi2de(v1,'left-msb');
    v2 = bi2de(v2,'left-msb');
    %konversi nilai desimal ke nilai x1 dan x2
    for i=1:size(individu,1)
        x1(i) = -3 + v1(i)*((12.1-(-3))/(2^18-1));
        x2(i) = 4.1 + v2(i)*((5.8-4.1)/(2^15-1));
    end
    %menghitung fitness function
    for i=1:size(individu,1)
        fitness(i) = 21.5+(x1(i)*sin(4*pi*x1(i)))+(x2(i)*sin(20*x2(i)));
    end
    allFitness(:,iter) = fitness;
    %% roulette wheel
    sumF = sum(fitness);
    probFit = fitness/sumF; %probabilitas fitness
    probKum = cumsum(probfit); %probablilitas kumulatif
    