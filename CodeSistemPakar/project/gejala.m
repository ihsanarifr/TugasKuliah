function varargout = gejala(varargin)
% GEJALA MATLAB code for gejala.fig
%      GEJALA, by itself, creates a new GEJALA or raises the existing
%      singleton*.
%
%      H = GEJALA returns the handle to a new GEJALA or the handle to
%      the existing singleton*.
%
%      GEJALA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GEJALA.M with the given input arguments.
%
%      GEJALA('Property','Value',...) creates a new GEJALA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gejala_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gejala_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gejala

% Last Modified by GUIDE v2.5 21-Jan-2016 16:31:00

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gejala_OpeningFcn, ...
                   'gui_OutputFcn',  @gejala_OutputFcn, ...
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


% --- Executes just before gejala is made visible.
function gejala_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gejala (see VARARGIN)

% Choose default command line output for gejala
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes gejala wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = gejala_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in mSirip.
function mSirip_Callback(hObject, eventdata, handles)
% hObject    handle to mSirip (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns mSirip contents as cell array
%        contents{get(hObject,'Value')} returns selected item from mSirip

% --- Executes during object creation, after setting all properties.
function mSirip_CreateFcn(hObject, eventdata, handles)
% hObject    handle to mSirip (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
set(hObject,'String',{'Tidak Ada';'Rusak';'Merah';'Luka';'Benang Halus'});


% --- Executes on selection change in mInsang.
function mInsang_Callback(hObject, eventdata, handles)
% hObject    handle to mInsang (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns mInsang contents as cell array
%        contents{get(hObject,'Value')} returns selected item from mInsang


% --- Executes during object creation, after setting all properties.
function mInsang_CreateFcn(hObject, eventdata, handles)
% hObject    handle to mInsang (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu6.
function popupmenu6_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu6 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu6


% --- Executes during object creation, after setting all properties.
function popupmenu6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in mKulit.
function mKulit_Callback(hObject, eventdata, handles)
% hObject    handle to mKulit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns mKulit contents as cell array
%        contents{get(hObject,'Value')} returns selected item from mKulit


% --- Executes during object creation, after setting all properties.
function mKulit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to mKulit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in mOrgan.
function mOrgan_Callback(hObject, eventdata, handles)
% hObject    handle to mOrgan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns mOrgan contents as cell array
%        contents{get(hObject,'Value')} returns selected item from mOrgan


% --- Executes during object creation, after setting all properties.
function mOrgan_CreateFcn(hObject, eventdata, handles)
% hObject    handle to mOrgan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in rKembung.
function rKembung_Callback(hObject, eventdata, handles)
% hObject    handle to rKembung (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rKembung


% --- Executes on button press in rTidakKembung.
function rTidakKembung_Callback(hObject, eventdata, handles)
% hObject    handle to rTidakKembung (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rTidakKembung


% --- Executes on button press in rLuka.
function rLuka_Callback(hObject, eventdata, handles)
% hObject    handle to rLuka (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rLuka


% --- Executes on button press in rMenonjol.
function rMenonjol_Callback(hObject, eventdata, handles)
% hObject    handle to rMenonjol (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rMenonjol


% --- Executes on button press in btnDiagnosis.
function btnDiagnosis_Callback(hObject, eventdata, handles)
% hObject    handle to btnDiagnosis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
items = get(handles.mSirip,'String');
index_selected = get(handles.mSirip,'Value');
item_selected = items{index_selected};
msgbox(num2str(index_selected),'Success');

