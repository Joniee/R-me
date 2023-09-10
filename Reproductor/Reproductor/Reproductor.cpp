// Reproductor.cpp : Define el punto de entrada de la aplicación.
//

#define ALLEGRO_UNSTABLE

#include "framework.h"
#include "Reproductor.h"
#include <CommCtrl.h>
#include <iostream>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

#define MAX_LOADSTRING 100



// Variables globales:
HINSTANCE hInst;                                // instancia actual
WCHAR szTitle[MAX_LOADSTRING];                  // Texto de la barra de título
WCHAR szWindowClass[MAX_LOADSTRING];            // nombre de clase de la ventana principal

// Declaraciones de funciones adelantadas incluidas en este módulo de código:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    LogIn(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    LoadMusic(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Colocar código aquí.

    // Inicializar cadenas globales
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_REPRODUCTOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    // Realizar la inicialización de la aplicación:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REPRODUCTOR));

    MSG msg;

    // Bucle principal de mensajes:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//
//  FUNCIÓN: MyRegisterClass()
//
//  PROPÓSITO: Registra la clase de ventana.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_REPRODUCTOR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_REPRODUCTOR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCIÓN: InitInstance(HINSTANCE, int)
//
//   PROPÓSITO: Guarda el identificador de instancia y crea la ventana principal
//
//   COMENTARIOS:
//
//        En esta función, se guarda el identificador de instancia en una variable común y
//        se crea y muestra la ventana principal del programa.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Almacenar identificador de instancia en una variable global

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1440, 850, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCIÓN: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PROPÓSITO: Procesa mensajes de la ventana principal.
//
//  WM_COMMAND  - procesar el menú de aplicaciones
//  WM_PAINT    - Pintar la ventana principal
//  WM_DESTROY  - publicar un mensaje de salida y volver
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HFONT hFont = CreateFont(-14, 0, 0, 0, 0, FALSE, FALSE, FALSE, 1, 0, 0, 0, 0, L"Ms Shell Dlg");
    int VH = WS_VISIBLE;

  
    
    WPARAM nResult;

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizar las selecciones de menú:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case ID_LOGIN:
                nResult = DialogBox(hInst, MAKEINTRESOURCE(IDD_LOGINBOX), hWnd, LogIn);

                if (nResult == ID_STARTED) {
                    CreateWindowEx(0, L"button", L">", VH | WS_CHILD | 0x00000001, 747, 701, 30, 30, hWnd, (HMENU)IDC_PLAY, hInst, 0);
                    CreateWindowEx(0, L"button", L"||", VH | WS_CHILD | 0x00000001, 787, 701, 30, 30, hWnd, (HMENU)IDC_PAUSE, hInst, 0);
                    CreateWindowEx(0, L"button", L">>|", VH | WS_CHILD | 0x00000001, 831, 701, 30, 30, hWnd, (HMENU)IDC_NEXT, hInst, 0);
                    CreateWindowEx(0, L"button", L"|<<", VH | WS_CHILD | 0x00000001, 702, 701, 30, 30, hWnd, (HMENU)IDC_PREVIOUS, hInst, 0);

                    for (int j = 0; j < 600; j += 300) {
                        for (int i = 0; i < 1100; i += 220) {
                            HBITMAP logoImage;
                            logoImage = (HBITMAP)LoadImage(GetModuleHandle(L"D:\\Proyectos\\R-me\\Reproductor\\Debug\\Donde_nace_el_infarto.bmp"), L"D:\\Proyectos\\R-me\\Reproductor\\Debug\\Donde_nace_el_infarto.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
                            HWND logo = CreateWindowEx(0, L"button", L"Label", BS_BITMAP | SS_CENTER | WS_CHILD | WS_VISIBLE, (330 + i), (20 + j), 190, 190, hWnd, (HMENU)IDB_ALBUM, hInst, 0);
                            SendMessage(logo, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)logoImage);
                            CreateWindowEx(0, L"edit", L"Donde Nace el Infarto", VH | WS_CHILD | 0x00000001, (330 + i), (220 + j), 185, 20, hWnd, 0, hInst, 0);
                            CreateWindowEx(0, L"edit", L"Ciudad Jara", VH | WS_CHILD | 0x00000001, (330 + i), (250 + j), 185, 20, hWnd, 0, hInst, 0);
                        }
                    }


                    CreateWindowEx(0, TRACKBAR_CLASS, NULL,
                        WS_CHILD | VH | WS_TABSTOP | TBS_HORZ, 467, 651, 600, 20, hWnd, (HMENU)IDC_TIME,
                        hInst, NULL);
                    SendDlgItemMessage(hWnd, IDC_TIME, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(FALSE, 0));
                    SendDlgItemMessage(hWnd, IDC_TIME, TBM_SETRANGE, (WPARAM)FALSE, MAKELPARAM(0, 1000));
                    SendDlgItemMessage(hWnd, IDC_TIME, TBM_SETTICFREQ, (WPARAM)1, 0);
                    SendDlgItemMessage(hWnd, IDC_TIME, TBM_SETTHUMBLENGTH, (WPARAM)FALSE, 1000);
                }
                else {
                    PostQuitMessage(0);
                }
                break;
            case IDB_ALBUM:
                for (int i = 0; i < 1; i++) {
                    CreateWindowEx(0, L"button", L"Donde Nace el Infarto", VH | WS_CHILD | WS_VSCROLL | ES_LEFT | 0x00000001, 5, (5 + (i * 30)), 260, 20, hWnd, (HMENU)ID_LOADMUSIC, hInst, 0);
                }
                break;
            case ID_LOADMUSIC:
                mciSendString(L"close Music", 0, 0, 0);
                mciSendString(L"open D:\\Proyectos\\R-me\\Reproductor\\Debug\\song.wav type waveaudio alias Music", 0, 0, 0);
                mciSendString(L"seek Music to start", 0, 0, 0);
                mciSendString(L"play Music", 0, 0, 0);
                {
                    HBITMAP logoImage;
                    logoImage = (HBITMAP)LoadImage(GetModuleHandle(L"D:\\Proyectos\\R-me\\Reproductor\\Debug\\Donde_nace_el_infarto.bmp"), L"D:\\Proyectos\\R-me\\Reproductor\\Debug\\Donde_nace_el_infarto.bmp", IMAGE_BITMAP, 95, 95, LR_LOADFROMFILE);
                    HWND logo = CreateWindowEx(0, L"button", L"Label", BS_BITMAP | SS_CENTER | WS_CHILD | WS_VISIBLE, 10, 612, 95, 95, hWnd, (HMENU)IDB_ALBUM, hInst, 0);
                    SendMessage(logo, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)logoImage);
                }
                CreateWindowEx(0, L"edit", L"Donde Nace el Infarto", VH | WS_CHILD | 0x00000001, 115, 612, 185, 20, hWnd, 0, hInst, 0);
                CreateWindowEx(0, L"edit", L"Donde Nace el Infarto", VH | WS_CHILD | 0x00000001, 115, 642, 185, 20, hWnd, 0, hInst, 0);
                CreateWindowEx(0, L"edit", L"Ciudad Jara", VH | WS_CHILD | 0x00000001, 115, 672, 185, 20, hWnd, 0, hInst, 0);
                break;
            case IDC_PLAY:
                mciSendString(L"resume Music", 0, 0, 0);
                break;
            case IDC_PAUSE:
                mciSendString(L"pause Music", 0, 0, 0);
                break;
            case IDC_NEXT:
                break;
            case IDC_PREVIOUS:
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_CREATE:
        {
            nResult = DialogBox(hInst, MAKEINTRESOURCE(IDD_LOGINBOX), hWnd, LogIn);

            if (nResult == ID_STARTED) {
                CreateWindowEx(0, L"button", L">", VH | WS_CHILD | 0x00000001, 747, 701, 30, 30, hWnd, (HMENU)IDC_PLAY, hInst, 0);
                CreateWindowEx(0, L"button", L"||", VH | WS_CHILD | 0x00000001, 787, 701, 30, 30, hWnd, (HMENU)IDC_PAUSE, hInst, 0);
                CreateWindowEx(0, L"button", L">>|", VH | WS_CHILD | 0x00000001, 831, 701, 30, 30, hWnd, (HMENU)IDC_NEXT, hInst, 0);
                CreateWindowEx(0, L"button", L"|<<", VH | WS_CHILD | 0x00000001, 702, 701, 30, 30, hWnd, (HMENU)IDC_PREVIOUS, hInst, 0);

                for (int j = 0; j < 600; j += 300) {
                    for (int i = 0; i < 1100; i += 220) {
                        HBITMAP logoImage;
                        logoImage = (HBITMAP)LoadImage(GetModuleHandle(L"D:\\Proyectos\\R-me\\Reproductor\\Debug\\Donde_nace_el_infarto.bmp"), L"D:\\Proyectos\\R-me\\Reproductor\\Debug\\Donde_nace_el_infarto.bmp", IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
                        HWND logo = CreateWindowEx(0, L"button", L"Label", BS_BITMAP | SS_CENTER | WS_CHILD | WS_VISIBLE, (330 + i), (20 + j), 190, 190, hWnd, (HMENU)IDB_ALBUM, hInst, 0);
                        SendMessage(logo, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)logoImage);
                        CreateWindowEx(0, L"edit", L"Donde Nace el Infarto", VH | WS_CHILD | 0x00000001, (330 + i), (220 + j), 185, 20, hWnd, 0, hInst, 0);
                        CreateWindowEx(0, L"edit", L"Ciudad Jara", VH | WS_CHILD | 0x00000001, (330 + i), (250 + j), 185, 20, hWnd, 0, hInst, 0);
                    }
                }


                CreateWindowEx(0, TRACKBAR_CLASS, NULL,
                    WS_CHILD | VH | WS_TABSTOP | TBS_HORZ, 467, 651, 600, 20, hWnd, (HMENU)IDC_TIME,
                    hInst, NULL);
                SendDlgItemMessage(hWnd, IDC_TIME, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(FALSE, 0));
                SendDlgItemMessage(hWnd, IDC_TIME, TBM_SETRANGE, (WPARAM)FALSE, MAKELPARAM(0, 1000));
                SendDlgItemMessage(hWnd, IDC_TIME, TBM_SETTICFREQ, (WPARAM)1, 0);
                SendDlgItemMessage(hWnd, IDC_TIME, TBM_SETTHUMBLENGTH, (WPARAM)FALSE, 1000);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            FillRgn(hdc, CreateRoundRectRgn(0, 0, 1425, 800, 5, 5), CreateSolidBrush(RGB(0, 0, 0)));
            FillRgn(hdc, CreateRoundRectRgn(0, 0, 298, 598, 5, 5), CreateSolidBrush(RGB(50, 50, 50))); // Superior iz.
            FillRgn(hdc, CreateRoundRectRgn(0, 602, 1425, 800, 5, 5), CreateSolidBrush(RGB(50, 50, 50))); //Inferior
            FillRgn(hdc, CreateRoundRectRgn(302, 0, 1425, 598, 5, 5), CreateSolidBrush(RGB(50, 50, 50)));  //Superior der.
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case UIS_INITIALIZE:
       // DialogBox(hInst, MAKEINTRESOURCE(IDD_LOGINBOX), hWnd, LogIn);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Controlador de mensajes del cuadro Acerca de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

// Controlador de mensajes del cuadro Opciones.
INT_PTR CALLBACK LogIn(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDCANCEL || LOWORD(wParam) == IDC_CANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDYES)
        {
            PostMessage(hDlg, ID_STARTED, MAKEWPARAM(ID_STARTED, BN_CLICKED), 0);
            EndDialog(hDlg, LOWORD(ID_STARTED));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK LoadMusic(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    EndDialog(hDlg, LOWORD(ID_LOADMUSIC));
    return (INT_PTR)FALSE;
}
