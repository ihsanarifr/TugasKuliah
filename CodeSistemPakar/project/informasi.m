function varargout = informasi(varargin)
% INFORMASI MATLAB code for informasi.fig
%      INFORMASI, by itself, creates a new INFORMASI or raises the existing
%      singleton*.
%
%      H = INFORMASI returns the handle to a new INFORMASI or the handle to
%      the existing singleton*.
%
%      INFORMASI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in INFORMASI.M with the given input arguments.
%
%      INFORMASI('Property','Value',...) creates a new INFORMASI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before informasi_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to informasi_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help informasi

% Last Modified by GUIDE v2.5 26-Jan-2016 10:20:05

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @informasi_OpeningFcn, ...
                   'gui_OutputFcn',  @informasi_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before informasi is made visible.
function informasi_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to informasi (see VARARGIN)

% Choose default command line output for informasi
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes informasi wait for user response (see UIRESUME)
% uiwait(handles.figure1);
set(handles.cekgejala,'enable','off')

% --- Outputs from this function are returned to the command line.
function varargout = informasi_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function txtBerat_Callback(hObject, eventdata, handles)
% hObject    handle to txtBerat (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txtBerat as text
%        str2double(get(hObject,'String')) returns contents of txtBerat as a double


% --- Executes during object creation, after setting all properties.
function txtBerat_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtBerat (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double


% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function txtTumbuh_Callback(hObject, eventdata, handles)
% hObject    handle to txtTumbuh (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txtTumbuh as text
%        str2double(get(hObject,'String')) returns contents of txtTumbuh as a double


% --- Executes during object creation, after setting all properties.
function txtTumbuh_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtTumbuh (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in txtNafsu.
function txtNafsu_Callback(hObject, eventdata, handles)
% hObject    handle to txtNafsu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns txtNafsu contents as cell array
%        contents{get(hObject,'Value')} returns selected item from txtNafsu


% --- Executes during object creation, after setting all properties.
function txtNafsu_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtNafsu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function txtSuhu_Callback(hObject, eventdata, handles)
% hObject    handle to txtSuhu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txtSuhu as text
%        str2double(get(hObject,'String')) returns contents of txtSuhu as a double


% --- Executes during object creation, after setting all properties.
function txtSuhu_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtSuhu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in checkbox5.
function checkbox5_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox5


% --- Executes on button press in checkbox6.
function checkbox6_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox6


% --- Executes on button press in checkbox7.
function checkbox7_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox7


% --- Executes on button press in checkbox8.
function checkbox8_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox8


% --- Executes on button press in checkbox9.
function checkbox9_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox9


% --- Executes on button press in checkbox1.
function checkbox1_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox1


% --- Executes on button press in checkbox4.
function checkbox4_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox4


% --- Executes on button press in checkbox2.
function checkbox2_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox2


% --- Executes on button press in checkbox3.
function checkbox3_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox3


% --- Executes on button press in checkbox15.
function checkbox15_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox15


% --- Executes on button press in checkbox16.
function checkbox16_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox16


% --- Executes on button press in checkbox17.
function checkbox17_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox17 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox17


% --- Executes on button press in checkbox18.
function checkbox18_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox18 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox18


% --- Executes on button press in checkbox14.
function checkbox14_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox14


% --- Executes on button press in checkbox10.
function checkbox10_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox10


% --- Executes on button press in checkbox12.
function checkbox12_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox12


% --- Executes on button press in checkbox11.
function checkbox11_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox11


% --- Executes on button press in checkbox27.
function checkbox27_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox27 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox27


% --- Executes on button press in checkbox28.
function checkbox28_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox28 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox28


% --- Executes on button press in checkbox29.
function checkbox29_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox29 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox29


% --- Executes on button press in checkbox23.
function checkbox23_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox23 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox23


% --- Executes on button press in checkbox24.
function checkbox24_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox24 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox24


% --- Executes on button press in checkbox19.
function checkbox19_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox19 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox19



function txtpH_Callback(hObject, eventdata, handles)
% hObject    handle to txtpH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txtpH as text
%        str2double(get(hObject,'String')) returns contents of txtpH as a double


% --- Executes during object creation, after setting all properties.
function txtpH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtpH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function txtOksigen_Callback(hObject, eventdata, handles)
% hObject    handle to txtOksigen (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txtOksigen as text
%        str2double(get(hObject,'String')) returns contents of txtOksigen as a double


% --- Executes during object creation, after setting all properties.
function txtOksigen_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtOksigen (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function txtKecerahan_Callback(hObject, eventdata, handles)
% hObject    handle to txtKecerahan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txtKecerahan as text
%        str2double(get(hObject,'String')) returns contents of txtKecerahan as a double


% --- Executes during object creation, after setting all properties.
function txtKecerahan_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtKecerahan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function txtAmoniak_Callback(hObject, eventdata, handles)
% hObject    handle to txtAmoniak (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txtAmoniak as text
%        str2double(get(hObject,'String')) returns contents of txtAmoniak as a double


% --- Executes during object creation, after setting all properties.
function txtAmoniak_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txtAmoniak (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in btnDiagnosis.
function btnDiagnosis_Callback(hObject, eventdata, handles)
% hObject    handle to btnDiagnosis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% nangkep variabel dulu
berat_badan = str2num(get(handles.txtBerat,'String'));
nafsu = 2; %str2num(get(handles.txtNafsu,'String'));
tumbuh = str2num(get(handles.txtTumbuh,'String'));

suhu = str2num(get(handles.txtSuhu,'String'));
ph = str2num(get(handles.txtpH,'String'));
oksigen = str2num(get(handles.txtOksigen,'String'));
kecerahan = str2num(get(handles.txtKecerahan,'String'));
amoniak = str2num(get(handles.txtAmoniak,'String'));

if isempty(suhu) || isempty(ph) || isempty(oksigen) || isempty(kecerahan) ||  isempty(amoniak)
   msgbox('Harus Diisi','Success');
else
    % jumlah_str = num2str(suhu+ph+oksigen+kecerahan+amoniak);
    x = readfis('project-penyakit-ikan.fis');
    hasil = evalfis([suhu,ph,oksigen,kecerahan,amoniak],x);
    % msgbox(num2str(hasil),'Success');
    
    if hasil>=0.1 & hasil<0.4
        %eval(['pic' num2str(i) '= rgb2gray(citra' num2str(i) ')']);
        set(findobj(gcf, 'Tag', 'hasilfuzzy'), 'String', ['Kualitas Air Bagus Dengan nilai :' num2str(hasil)]);
    else
%         set(findobj(gcf, 'Tag', 'hasilfuzzy'), 'String', ['Kualitas Air Kurang Bagus Dengan nilai :' num2str(hasil)]);
        set(findobj(gcf, 'Tag', 'hasilfuzzy'), 'String', 'Kualitas Air Kurang Bagus');
        % kirim ke file
        fid = fopen('info-fuzzy.txt','wt');
        fprintf(fid, '%s;%s;%s;%s;%s;%s;%s;%s;%s', num2str(berat_badan),num2str(nafsu),num2str(tumbuh),num2str(suhu),num2str(ph),num2str(oksigen),num2str(kecerahan),num2str(amoniak),num2str(hasil));
        fclose(fid);
        set(handles.cekgejala,'enable','on')
    end
end


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATAx = get(handles.edit1,'String'); %edit1 being Tag of ur edit box



function hasilfuzzy_Callback(hObject, eventdata, handles)
% hObject    handle to hasilfuzzy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of hasilfuzzy as text
%        str2double(get(hObject,'String')) returns contents of hasilfuzzy as a double


% --- Executes during object creation, after setting all properties.
function hasilfuzzy_CreateFcn(hObject, eventdata, handles)
% hObject    handle to hasilfuzzy (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2


% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in cekgejala.
function cekgejala_Callback(hObject, eventdata, handles)
% hObject    handle to cekgejala (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close(informasi);
gejala();
