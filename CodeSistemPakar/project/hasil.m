function varargout = hasil(varargin)
% HASIL MATLAB code for hasil.fig
%      HASIL, by itself, creates a new HASIL or raises the existing
%      singleton*.
%
%      H = HASIL returns the handle to a new HASIL or the handle to
%      the existing singleton*.
%
%      HASIL('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in HASIL.M with the given input arguments.
%
%      HASIL('Property','Value',...) creates a new HASIL or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before hasil_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to hasil_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help hasil

% Last Modified by GUIDE v2.5 26-Jan-2016 11:35:25

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @hasil_OpeningFcn, ...
                   'gui_OutputFcn',  @hasil_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin & ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before hasil is made visible.
function hasil_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to hasil (see VARARGIN)

% Choose default command line output for hasil
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes hasil wait for user response (see UIRESUME)
% uiwait(handles.figure1);

%% ambil data txt dari identitas dan fuzzy
fileID = fopen('info-fuzzy.txt','r');
delim = char(59);
[A,count] = fscanf(fileID,['%f' delim]);

% variabel diambil
berat_badan = A(1);
nafsu_makan = A(2);
pertumbuhan = A(3);
suhu = A(4);
ph = A(5);
oksigen = A(6);
kecerahan = A(7);
amoniak = A(8);
kualitas_air = A(9);

% set berat badan & nafsu makan dan pertumbuhan
set(findobj(gcf, 'Tag', 'txtBeratBadan'), 'String', num2str(berat_badan));
set(findobj(gcf, 'Tag', 'txtNafsuMakan'), 'String', num2str(nafsu_makan));
set(findobj(gcf, 'Tag', 'txtPertumbuhan'), 'String', num2str(pertumbuhan));

% set kualitas air text
if kualitas_air>=0.1 & kualitas_air<0.4
    set(findobj(gcf, 'Tag', 'txtKualitasAir'), 'String', ['Kualitas Air Bagus Dengan nilai :' num2str(kualitas_air)]);
else
    set(findobj(gcf, 'Tag', 'txtKualitasAir'), 'String', ['Kualitas Air Kurang Bagus Dengan nilai :' num2str(kualitas_air)]);
end

%% ambil data txt dari gejala gejala
fileID = fopen('info-gejala.txt','r');
delim = char(59);
[A,count] = fscanf(fileID,['%f' delim]);

% set variabel gejala
sirip = A(1);
insang = A(2);
kulit = A(3);
perut = A(4);
mata = A(5);
organ = A(6);

% konversi ke kata-kata
switch sirip
    case 1
        tsirip = 'rusak';
    case 2
        tsirip = 'merah';
    case 3
        tsirip = 'luka';
    case 4
        tsirip = 'benang halus';
    otherwise
        tsirip = 'tidak ada';
end
switch insang
    case 1
        tinsang = 'bercak merah';
    case 2
        tinsang = 'benjolan';
    case 3
        tinsang = 'luka';
    case 4
        tinsang = 'pucat';
    case 5
        tinsang = 'benang-benang halus';
    otherwise
        tinsang = 'Tida Ada';
end

switch kulit
    case 1
        tkulit = 'benang alus';
    case 2
        tkulit = 'bintik putih';
    case 3
        tkulit = 'warna cerah';
    case 4
        tkulit = 'warna gelap';
    case 5
        tkulit = 'warna pucat';
    case 6  
        tkulit = 'melepuh';
    case 7
        tkulit = 'luka';
    case 8
        tkulit = 'lendir berlebihan';
    otherwise
        tkulit = 'Tida Ada';
end

switch perut
    case 1
        tperut = 'kembung';
    otherwise
        tperut = 'tidak ada';
end

switch mata
    case 1
        tmata = 'luka';
    case 2
        tmata = 'menonjol';
    otherwise
        tmata = 'tidak ada';
end

switch organ
    case 1
        torgan = 'bintik-bintik';
    case 2
        torgan = 'rusak';
    case 3
        torgan = 'luka';
    otherwise
        torgan = 'tidak ada';
end
% set berat badan & nafsu makan dan pertumbuhan
set(findobj(gcf, 'Tag', 'txtGejala'), 'String', ['Sirip ' tsirip ', insang ' tinsang ', kulit ' tkulit ', perut ' tperut ', mata ' tmata ', organ ' torgan]);


% base rule penyakit penyakit
if(sirip == 0 & insang == 0 & kulit == 3 & perut == 0 & mata == 0 & organ == 0)
	indonesia = 'sehat';
    latin = 'health';
    singkat = 'Sehat selalu';
    penanganan = 'selalu rajin bersihkan kolam';
elseif(sirip == 4 & insang == 5 & (kulit == 3 | kulit == 1) & perut == 0 & mata == 0 & organ == 0)
	indonesia = 'Si Kapas Putih';
    latin = 'Jamur Saprolegnia ';
    singkat = 'Penyakit jenis ini akan menyerang koi yang terluka atau akan tumbuh pada air kolam yang kotor, karena jamur tumbuh baik pada lingkungan berbahan organik tinggi. Jamur juga tumbuh baik pada jaringan mati seperti pada jaringan tubuh ikan yang luka. Bekas luka parasit seperti luka bekas gigitan kutu ikan. ';
    penanganan = 'Koi yang terserang jamur dapat diobati dengan larutan garam dapur (NaCI) dengan konsentrasi 1,5 - 2,5 % melalui pencelupan. Buang bulu-bulu halus jamur dengan mengolesnya pakai kapas yang diberi obat merah. Selanjutnya, ikan sakit dimandikan dalam larutan Monofuracin.';
elseif(sirip == 0 & insang == 0 & kulit == 4 & perut == 1 & mata == 0 & organ == 1)
	indonesia = 'Tuberkulosis';
    latin = 'Mycobacteriosis';
    singkat = 'Mycobacteriosis adalah penyakit subakut dan kronik, ditandai dengan terbentuknya granuloma. Penyakit ini umumnya terjadi pada ikan-ikan yang dipelihara pada akuarium dalam jangka waktu yang lama atau dibudidaya secara intensif.';
    penanganan = 'Pengobatan dan Pengendalian Kanamisin + Vitamin B-6 selama 30 hari adalah pengobatan yang paling efektif yang diketahui untuk TB. Ikan harus dikarantina selama masa pengobatan. vitamin dalam bentuk cair yang dapat ditemukan di toko obat setempat merupakan sumber yang baik vitamin B-6. Satu tetes per setiap 5 galon air akuarium. Ganti vitamin sesuai dengan berapa banyak air yang berubah di tangki selama waktu pengobatan.';
elseif(sirip == 3 & insang == 0 & kulit == 5 & perut == 0 & mata == 2 & (organ == 2 | organ == 3))
	indonesia = 'Koi Herpes Virus';
    latin = 'Koi Herpes Virus';
    singkat = 'Salah satu penyakit yang menjadi momok ketika kita memelihara ikan koi adalah serangan Koi Herpes Virus (KHV) atau Virus Herpes pada ikan koi. KHV merupakan penyakit yang mudah menular pada berbagai jenis ikan termasuk koi dan keluarga karper. Kematian ikan yang disebabkan Virus Herpes bisa mencapai 20% sampai dengan 100%. Virus ini biasa menyebar pada musim panas saat suhu air cukup tinggi, antara suhu 18 sampai 27 derajat celcius. ';
    penanganan = 'Pisahkan ikan koi yang sudah terinfeksi dari ikan yang masih sehat masukkan dalam kolam karantina. Pastikan air dalam kolam karantina bersih.Naikkan suhu air kolam karantina secara perlahan-lahan hingga 30 derajat celcius dan berikan aerasi yang cukup.Selama masa pengobatan tidak diberi makan dan berikan antibiotik untuk mencegah infeksi sekunder.';
elseif(sirip == 0 & (insang == 3 | insang == 4) & (kulit == 4 | kulit == 7 | kulit == 8) & perut == 0 & mata == 0 & organ == 0)
	indonesia = 'penyakit parasitik';
    latin = 'Myxobolus celebralis';
    singkat = 'Myxosporeasis merupakan salah satu jenis penyakit parasitik yang disebabkan oleh protozoa Myxobolus celebralis, dimana inang devenitivenya adalah semua janis ikan salmonidae kecuali Rainbow trout terutama ikan yang muda (Salmo fario, S. lacurstris, S. iridens, Onchorhynchus kisutch, O. tshawytscha, dan Salvelinus namaycus).';
    penanganan = 'Menerapkan manajemen kesehatan ikan secara baik dan benar, Segera memusnahkan ikan yang terinfeksi, Menghindari penggunaan air dari kolam yang sedang terinfeksi, Menerapkan sistem filtrasi air sebelum menggunakannya, Mendesinfeksikan kolam yang terserang dengan melakukan pengeringan dan pengapuran (CaO) sebanyak 25 kg/ha yang kemudian dibiarkan selama seminggu, Spora dapat dibunuh (dieradikasi) dengan menggunakan unslaked lime (calsium oxide) 25% yang dibenamkan di dasar kolam sedalam 3 cm dan 380 g calsium oxide/m2 selama 2 hari.';
elseif(sirip == 3 & insang == 3 & (kulit == 4 | kulit == 5 | kulit == 7 | kulit == 8) & perut == 0 & mata == 1 & organ == 0)
	indonesia = 'Si Cacing Jangkar';
    latin = 'Lernaea';
    singkat = 'Parasit lernaea atau disebut juga dengan cacing jangkar. Cacing jangkar sangat mudah terlihat. Sobat dapat menemukan biasanya letaknya menempel pada bagian luar tubuh ikan atau pada insang. ';
    penanganan = 'Dalam jumlah sedikit, lernaea pada seekor koi dapat dicabut dengan pinset. Bekas luka yang berdarah diolesi obat merah. Kalau serangan sudah merata, sebaiknya koi diobati dengan larutan formalin atau Dephterex. Pengobatan dengan larutan formalin, gunakan larutan dengan konsentrasi 25 ppm. Ikan dimandikan selama 10 menit dengan pengulangan 2-3 kali setiap 2 hari sekali. ';
elseif((sirip == 1 | sirip == 2 | sirip == 3) & insang == 0 & (kulit == 4 | kulit == 7) & perut == 1 & mata == 2 & organ == 0)
	indonesia = 'Bakteri Aeromonas';
    latin = 'Pseudomonas';
    singkat = 'bakteri aeromonas menjadi bakteri yang paling sering menyerang ikan-ikan koi, namun sebenarnya ada beberapa kemungkinan jenis bakteri lain yang bisa menyerang ikan koi. Bakteri-bakteri pada koi tersebut antara lain Pseudomonas, Flexibacter, Streptococcus dan Edwardsiella. Bakteri aeromonas menjadi bakteri yang banyak menyebabkan kematian pada ikan koi, maka sebelum aeromonas membunuh koi alangkah baiknya dicegah dengan membasmi aeromonas.';
    penanganan = 'Jangan Over Populasi.	Menjaga Kualitas air agar tetap bagus. Karantina koi pendatang baru. Mengkarantina Ikan Koi. Memberikan Antibiotik. Menyuntikkan Antibiotik. ';
elseif(sirip == 3 & insang == 3 & kulit == 3 & perut == 0 & mata == 0 & organ == 0)
	indonesia = 'bintik putih';
    latin = 'white spot';
    singkat = 'Penyakit white spot berupa bintik putih yang menyebar pada seluruh permukaan kulit. Awalnya bintik putih muncul di bagian permukaan tubuh dan meluas ke bagian lainnya, bisa ke ke insang, sirip, dan lain-lain. Penyakit ini biasanya menyerang ikan yang dipelihara di akuarium. ';
    penanganan = 'Koi yang terkena bintik putih diobati dengan menaikan suhu air kolam sampai beberapa derajat dari suhu awal. Air kolam ditambah 0,5 gram Metheline blue per 1 ton air. Cara pengobatan ini efektif untuk menyembuhkan dan membunuh white spote. ';
elseif(sirip == 2 & insang == 0 & (kulit == 4 | kulit == 5 | kulit == 7) & perut == 0 & mata == 0 & organ == 0)
	indonesia = 'kutu';
    latin = 'kutu';
    singkat = 'Terlihat ada binatang bulat berwarna bening menempel pada badan dan sirip ikan ( kutu ). Ada semacam jarum menancap pada sirip atau badan koi ( kutu jarum, anchor worm ). Tampak jamur bergerombol menempel pada ikan ( hexamita ).';
    penanganan = 'GESUND magic parasite';
elseif((sirip == 1 | sirip == 2) & insang == 0 & (kulit == 6 | kulit == 7) & perut == 1 & mata == 0 & organ == 3)
	indonesia = 'motil aeromonas';
    latin = 'Motile Aeromonas Septicemia';
    singkat = 'Motile Aeromonas Septicemia (MAS) merupakan penyakit pada ikan yang disebabkan oleh Aeromonas hydrophila (White, 1989). Penyakit ini mempunyai beberapa nama lain yaitu Hemorrhagic Septicemia, Ulcer Disease,Motile Aeromonad Infection (MAI), Redpest atau Red-Sore Disease.';
    penanganan = 'Tindakan pengobatan yang dapat dilakukan dengan pemberian antibiotik seperti oxytetracycline dan sulfonamide. Hal-hal yang perlu diperhatikan dalam pemberian terapi antibiotik adalah dosis, pertimbangan terjadinya resisten dan kelasi kalsium (White, 1989).';
else
    indonesia = 'Penyakit tidak Ada';
    latin = 'Penyakit tidak Ada';
    singkat = 'Penyakit tidak Ada';
    penanganan = 'Penyakit tidak Ada';
end

%msgbox([indonesia latin singkat solusi penanganan]);
% set variable
set(findobj(gcf, 'Tag', 'txtIndonesia'), 'String', indonesia);
set(findobj(gcf, 'Tag', 'txtLatin'), 'String', latin);
set(findobj(gcf, 'Tag', 'txtSingkat'), 'String', singkat);
% set(findobj(gcf, 'Tag', 'txtSolusi'), 'String', solusi);
set(findobj(gcf, 'Tag', 'txtPenanganan'), 'String', penanganan);

% --- Outputs from this function are returned to the command line.
function varargout = hasil_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close(hasil);
Home();
