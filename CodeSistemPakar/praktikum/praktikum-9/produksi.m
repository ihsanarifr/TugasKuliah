
function varargout = produksi(varargin)
% PRODUKSI MATLAB code for produksi.fig
%      PRODUKSI, by itself, creates a new PRODUKSI or raises the existing
%      singleton*.
%
%      H = PRODUKSI returns the handle to a new PRODUKSI or the handle to
%      the existing singleton*.
%
%      PRODUKSI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PRODUKSI.M with the given input arguments.
%
%      PRODUKSI('Property','Value',...) creates a new PRODUKSI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before produksi_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to produksi_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help produksi

% Last Modified by GUIDE v2.5 16-Dec-2015 21:26:22

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @produksi_OpeningFcn, ...
                   'gui_OutputFcn',  @produksi_OutputFcn, ...
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


% --- Executes just before produksi is made visible.
function produksi_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to produksi (see VARARGIN)

% Choose default command line output for produksi
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes produksi wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = produksi_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function txt_permintaan_Callback(hObject, eventdata, handles)
% hObject    handle to txt_permintaan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txt_permintaan as text
%        str2double(get(hObject,'String')) returns contents of txt_permintaan as a double


% --- Executes during object creation, after setting all properties.
function txt_permintaan_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txt_permintaan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function txt_persediaan_Callback(hObject, eventdata, handles)
% hObject    handle to txt_persediaan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txt_persediaan as text
%        str2double(get(hObject,'String')) returns contents of txt_persediaan as a double


% --- Executes during object creation, after setting all properties.
function txt_persediaan_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txt_persediaan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function txt_produksi_Callback(hObject, eventdata, handles)
% hObject    handle to txt_produksi (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of txt_produksi as text
%        str2double(get(hObject,'String')) returns contents of txt_produksi as a double


% --- Executes during object creation, after setting all properties.
function txt_produksi_CreateFcn(hObject, eventdata, handles)
% hObject    handle to txt_produksi (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in proses.
function proses_Callback(hObject, eventdata, handles)
% hObject    handle to proses (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fis = readfis('produksi.fis')
%ruleview(fis)
permintaan = get(handles.txt_permintaan,'String');
permintaan = str2num(permintaan);

persediaan = get(handles.txt_persediaan,'String');
persediaan = str2num(persepdiaan);

output = evalfis([permintaan persediaan],fis);
disp(output);

set(handles.txt_produksi,'String',output);

% --- Executes on button press in Reset.
function Reset_Callback(hObject, eventdata, handles)
% hObject    handle to Reset (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
