%membuat FIS baru dengan nama FIS = perusahaan
a=newfis('perusahaan');

%menambahkan variabel input permintaan dan persediaan
a=addvar(a,'input','permintaan',[8 24]);
a=addvar(a,'input','persediaan',[30 60]);

%menambahkan variabel output jml_produksi
a=addvar(a,'output','jml_produksi',[10 25]);

%menambahkan membership function untuk permintaan
a=addmf(a,'input',1,'sedikit','trimf',[8 11 14]);
a=addmf(a,'input',1,'sedang','trimf',[13 16 19]);
a=addmf(a,'input',1,'banyak','trimf',[18 21 24]);

%menambahkan membership function untuk persediaan
a=addmf(a,'input',2,'sedikit','trimf',[30 36 42]);
a=addmf(a,'input',2,'sedang','trimf',[38 45 50]);
a=addmf(a,'input',2,'banyak','trimf',[47 55 60]);

%menambahkan membership function untuk jml_produksi
a=addmf(a,'output',1,'sedikit','trapmf',[10 10 14 20]);
a=addmf(a,'output',1,'banyak','trapmf',[17 21 25 25]);

%menambahkan rule
ruleList=[1 1 1 1 1; 2 1 1 1 1; 2 3 2 1 1; 3 1 1 1 1; 3 2 2 1 1; 3 3 2 1 1];
a=addrule(a,ruleList);

%evaluasi FIS
output=evalfis([18 38;20 40; 22 52],a)
