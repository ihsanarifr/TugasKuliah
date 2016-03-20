%% Tugas CI - GA code - 05/31/2015
%% membangkitkan individu
nGen = 600; %banyaknya generasi
Npop = 20;
Nkromosom = 33;
Nx = 18;
Ny = 15;
x = zeros(Npop,1);
y = zeros(Npop,1);
fitness = zeros(Npop,1);
allFitness = zeros(Npop,nGen);
newInd = floor(rand(Npop,Nkromosom)*2);
%% iterasi
for iter=1:nGen %looping sebanyak epoch yang ditentukan
    %inisialisasi
    individu = newInd;
    v1 = zeros(Npop,Nx);
    v2 = zeros(Npop,Ny);
    %% perhitungan fitness
    for i=1:size(individu,1) %membagi individu menjadi x1 dan x2
        v1(i,:) = individu(i,1:18);
        v2(i,:) = individu(i,19:end);
    end
    %mengubah v1 dan v2 ke bilangan desimal
    v1 = bi2de(v1,'left-msb');
    v2 = bi2de(v2,'left-msb');
    %konversi nilai desimal ke nilai x1 dan x2
    for i=1:size(individu,1)
        % -3<= x1 <= 12.1
        % 4.1 <= x2 <= 5.8
        %x1(i) = -3 + v1(i)*((12.1-(-3))/(2^18-1));
        %y1(i) = 4.1 + v2(i)*((5.8-4.1)/(2^15-1));
        x1(i) = -3 + v1(i) * ((3-(-3))/(2^18-1));
        y1(i) = -3 + v2(i) * ((3-(-3))/(2^15-1));
    end
    %menghitung fitness function
    for i=1:size(individu,1)
        fitness(i) = 3 * (1-x1(i))^2 * eps(((-x1(i)^2)-(x2(i)+1)^2)) - 10 * (x1(i)/2-(x1(i)^3)-(x2(i)^4)) * eps((-x1(i)^2 - x2(i)^2)) - ((eps(-(x1(i)+1)^2-x2(i)^2)))/3;
        %fitness(i) = 21.5 + (x1(i)*sin(4*pi*x1(i))) + (x2(i)*sin(20*pi*x2(i)));
    end
    allFitness(:,iter) = fitness;
    %% roulette wheel
    sumF = sum(fitness);
    probfit = fitness/sumF; %probabilitas fitness
    probKum = cumsum(probfit); %probablitas kumulatif
    RN = rand(1,Npop);
    newInd = individu;
    %proses pemilihan parent
    for i=1:Npop
        for j=1:Npop
            if(RN(i) <= probKum(j))
                newInd(i,:) = individu(j,:);
                break;
            end
        end
    end
    %% crossover, pc = 0.88
    parent = newInd;
    uInd = size(newInd,1);
    sumGen = size(newInd,2);
    j=1;
    Pc = 0.88;
    RN = rand(1,uInd);
    %proses memilih kromosom yang akan dipindah silang
    for i=1:uInd
        if RN(i) < Pc
            Pindex(j) = i;
            j = j+1;
        end
    end
    u_index = size(Pindex,2);
    %jika Pindex ganjil maka hilangkan 1
    if mod(u_index,2) ~= 0
        u_index = u_index - 1;
    end
    %proses crossover
    for i=1:2:u_index
        n = Pindex(i);
        m = Pindex(i+1);
        TP = 1 + round(rand*(sumGen-2));
        newInd(n,:) = [parent(n, 1:TP), parent(m, TP+1:sumGen)];
        newInd(m,:) = [parent(m, 1:TP), parent(n, TP+1:sumGen)];
    end
    %% mutasi, pm = 0.20 ==> 20 * 33 = 660, 660*0.2 = 132 gen/bit yg mutasi
    [m n] = size(newInd);
    %banyaknya gen yang akan dimutasi
    Pm = 0.2;
    sumMut = Pm*(m*n);

    for i=1:sumMut
        x = fix(1+m*rand);
        y = fix(1+n*rand);
        if newInd(x,y) == 0
            newInd(x,y) = 1;
        else
            newInd(x,y) = 0;
        end
    end
end
%% pengecekan fitness
sortedFitness = sort(allFitness,'descend'); %diurutkan fitness setiap iterasi
avgFitness = mean(allFitness);
bestFitness = sortedFitness(1,:);
%% plot fitness
plot(1:nGen,bestFitness,'blue',1:nGen,avgFitness,'green');
title('GA untuk optimasi fungsi kompleks');
xlabel('Jumlah Generasi');
ylabel('Fitness');
legend('Fitness Maksimum','Rataan Fitness','Location','southoutside','Orientation','horizontal');