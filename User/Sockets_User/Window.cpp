#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

char name[] = "Reproductor";
HWND window;
MSG message;
WNDCLASSEX style;

int WINAPI WinMain(HINSTANCE hThisInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszArgument,
	int nCmdShow)
{
	style.hInstance = hThisInstance;
	style.lpszClassName = LPCWSTR(name);
	style.lpfnWndProc = WindowProcedure;
	style.style = CS_DBLCLKS;
	style.cbSize = sizeof(WNDCLASSEX);
	style.hIcon = LoadIcon(NULL, IDI_QUESTION);
    style.hIconSm = LoadIcon(NULL, IDI_INFORMATION);
    style.hCursor = LoadCursor(NULL, IDC_ARROW);
    style.lpszMenuName = NULL;   /* Sin Menu */
    style.cbClsExtra = 0;
    style.cbWndExtra = 0;
    style.hbrBackground = (HBRUSH)COLOR_WINDOW; /* Color del fondo de ventana */



    /* Registramos la clase de la ventana */

    if (!RegisterClassEx(&style))

        return 0;



    /* Ahora creamos la ventana a partir de la clase anterior */

    window = CreateWindowEx(

        0,

        LPCWSTR(name),         /* Nombre de la clase */

        LPCWSTR(("Reproductor")),       /* Titulo de la ventana */

        WS_OVERLAPPEDWINDOW | WS_BORDER, /* Ventana por defecto */

        400,       /* Posicion de la ventana en el eje X (de izquierda a derecha) */

        70,       /* Posicion de la ventana, eje Y (arriba abajo) */

        644,                 /* Ancho de la ventana */

        575,                 /* Alto de la ventana */

        HWND_DESKTOP,

        NULL,                /* Sin menu */

        hThisInstance,

        NULL

    );



    /* Hacemos que la ventana sea visible */

    ShowWindow(window, nCmdShow);

    ShowWindow(GetConsoleWindow(), SW_HIDE); // Funcion para esconder la ventana de consola



    /* Hacemos que la ventan se ejecute hasta que se obtenga resturn 0 */

    while (GetMessage(&message, NULL, 0, 0))

    {

        /* Traduce mensajes virtual-key */

        TranslateMessage(&message);

        /* Envia mensajes a WindowProcedure */

        DispatchMessage(&message);

    }



    return message.wParam;

}



LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)

{

    switch (message) /* Manejamos los mensajes */

    {

    case WM_CLOSE: /* Que hacer en caso de recibir el mensaje WM_CLOSE*/

        DestroyWindow(window); /* Destruir la ventana */

        break;

    case WM_DESTROY:

        PostQuitMessage(0);

        break;

    default:  /* Tratamiento por defecto para mensajes que no especificamos */

        return DefWindowProc(window, message, wParam, lParam);

    }

    return 0;

}