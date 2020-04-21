#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#ifdef _WIN32
    const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
    const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
    const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
    const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐
    const char *UI_CROSS = "\xC5"; // 197 - ┼
    const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─
    const char *UI_HORIZONTAL_LINE_TOP =  "\xC1"; // 193 - ┴
    const char *UI_HORIZONTAL_LINE_BOTTOM =  "\xC2"; // 194 - ┬";
    const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │
    const char *UI_VERTICAL_LINE_LEFT =  "\xC3"; // 195 - ├
    const char *UI_VERTICAL_LINE_RIGHT =  "\xB4"; // 180 - ┤
    const unsigned short DEFAULT_BACKCOLOR = BLACK;
#else
    const char *UI_BOTTOM_RIGHT = "\e(0\x6a\e(B"; // 217 - ┘
    const char *UI_BOTTOM_LEFT = "\e(0\x6d\e(B"; // 192 - └
    const char *UI_TOP_LEFT = "\e(0\x6c\e(B"; // 218 - ┌
    const char *UI_TOP_RIGHT = "\e(0\x6b\e(B"; // 191 - ┐
    const char *UI_CROSS = "\e(0\x6e\e(B"; // 197 - ┼
    const char *UI_HORIZONTAL_LINE = "\e(0\x71\e(B"; // 196 - ─
    const char *UI_HORIZONTAL_LINE_TOP =  "\e(0\x76\e(B"; // 193 - ┴
    const char *UI_HORIZONTAL_LINE_BOTTOM =  "\e(0\x77\e(B"; // 194 - ┬";
    const char *UI_VERTICAL_LINE = "\e(0\x78\e(B"; // 179 - │
    const char *UI_VERTICAL_LINE_LEFT =  "\e(0\x74\e(B"; // 195 - ├
    const char *UI_VERTICAL_LINE_RIGHT =  "\e(0\x75\e(B"; // 180 - ┤
    const unsigned short DEFAULT_BACKCOLOR = DARKGREY;
#endif

const unsigned short SCR_WIDTH = 80;
const unsigned short SCR_HEIGHT= 25;
const unsigned short TEXT_COLOR = WHITE;
const unsigned short ERROR_COLOR = RED;
const unsigned short SUCCESS_COLOR = BLUE;
const unsigned short LINE_COLOR = WHITE;
const unsigned short BRAND_COLOR = LIGHTCYAN;

const unsigned short MSG_ERROR = 0;
const unsigned short MSG_OK = 1;

/**
  Dimensiones
  [0] -- Top X
  [1] -- Top Y
  [2] -- Bottom X
  [3] -- Bottom Y
*/

const unsigned short PANEL_TOPLEFT[4] = {1, 1, 24, 4};
const unsigned short PANEL_TOP[4] = {24, 1, SCR_WIDTH, 4};
const unsigned short PANEL_LEFT[4] = {1, 5, 22, SCR_HEIGHT};
const unsigned short PANEL_BOTTOM[4] = {24, 22, SCR_WIDTH, SCR_HEIGHT};
const unsigned short PANEL_MAIN[4] = {PANEL_TOP[0], PANEL_TOP[3], SCR_WIDTH, PANEL_BOTTOM[1]};

const unsigned short TOPLEFT_PANEL = 1;
const unsigned short TOP_PANEL = 2;
const unsigned short LEFT_PANEL = 3;
const unsigned short BOTTOM_PANEL = 4;
const unsigned short MAIN_PANEL = 5;

namespace ui{

  unsigned short center_x(const char *someText, const unsigned short left, const unsigned short right){
    unsigned short x;
    x = ceil((right-strlen(someText))/2+(left/2));
    //x = (right-left)/2-strlen(someText)/2;
    return x;
  }
  unsigned short center_y(const unsigned short top, const unsigned short bottom){
    unsigned short y;
    y = (bottom-top)/2;
    return y;
  }
  void textbox(unsigned short x, unsigned short y, unsigned short size, unsigned short backcolor = BLUE ){
    setBackgroundColor(backcolor);
    for (int i=x; i<=x+size; i++){
      gotoxy(i, y);
      cout << " ";
    }
    resetColor();
    setColor(TEXT_COLOR);
  }
  void reset_color(unsigned short color = TEXT_COLOR, unsigned short backcolor = DEFAULT_BACKCOLOR){
        setBackgroundColor(backcolor);
        resetColor();
        setColor(color);
  }

  void clear_panel(unsigned short panel, unsigned short backcolor = DEFAULT_BACKCOLOR){
    panel--;
    const unsigned short PANELS[5][4] = {
      {PANEL_TOPLEFT[0]-1, PANEL_TOPLEFT[1]-1, PANEL_TOPLEFT[2], PANEL_TOPLEFT[3]},
      {PANEL_TOP[0], PANEL_TOP[1]-1, PANEL_TOP[2], PANEL_TOP[3]},
      {PANEL_LEFT[0]-1, PANEL_LEFT[1]-1, PANEL_LEFT[2]+2, PANEL_LEFT[3]},
      {PANEL_BOTTOM[0], PANEL_BOTTOM[1], PANEL_BOTTOM[2], PANEL_BOTTOM[3]},
      {PANEL_MAIN[0], PANEL_MAIN[1], PANEL_MAIN[2], PANEL_MAIN[3]}
    };
    int x, y;
    setBackgroundColor(backcolor);
    for(x = PANELS[panel][0]+1; x <= PANELS[panel][2]-1; x++){
      for(y = PANELS[panel][1]+1; y <= PANELS[panel][3]-1; y++){
        gotoxy(x, y);
        cout << " ";
      }
    }
    resetColor();
  }
  void show_msg(const char *message, const unsigned short backcolor = ERROR_COLOR){
    reset_color(TEXT_COLOR, backcolor);
    clear_panel(BOTTOM_PANEL, backcolor);
    gotoxy (center_x(message, PANEL_BOTTOM[0], PANEL_BOTTOM[2]) ,PANEL_BOTTOM[1]+1);
    setBackgroundColor(backcolor);
    setColor(TEXT_COLOR);
    cout << message;
    cin.ignore();
    anykey();
    resetColor();
    clear_panel(BOTTOM_PANEL);
  }
  void draw_lines(){
    short i;
    setColor(LINE_COLOR);
    //Verticales
    for (i=PANEL_TOPLEFT[1]; i<=SCR_HEIGHT; i++){
      gotoxy(PANEL_TOPLEFT[2], i);
      cout << UI_VERTICAL_LINE;
    }
    //Horizontales
    for(i=PANEL_TOPLEFT[0]; i<=SCR_WIDTH; i++){
      gotoxy(i, PANEL_TOPLEFT[3]);
      cout << UI_HORIZONTAL_LINE;
    }
    for(i=PANEL_BOTTOM[0]; i<=SCR_WIDTH; i++){
      gotoxy(i, PANEL_BOTTOM[1]);
      cout << UI_HORIZONTAL_LINE;
    }
    //Cruces
    gotoxy(PANEL_TOPLEFT[2], PANEL_TOPLEFT[3]);
    cout << UI_CROSS;
    //Otros
    gotoxy(PANEL_BOTTOM[0], PANEL_BOTTOM[1]);
    cout << UI_VERTICAL_LINE_LEFT;

    setColor(TEXT_COLOR);

  }
  void draw_brand(){
    setBackgroundColor(BLUE);
    gotoxy(
      center_x("VOID INC.", PANEL_TOPLEFT[0], PANEL_TOPLEFT[2]),
      center_y(PANEL_TOPLEFT[1], PANEL_TOPLEFT[3]));
      setColor(BRAND_COLOR);
      cout << "VOID INC.";
      gotoxy(2,3);
      setColor(WHITE);
      cout << "www.angelsimon.com.ar";
      resetColor();
      setColor(TEXT_COLOR);

  }
  unsigned short draw_menu(unsigned int option = -1){
    unsigned short opt;
    gotoxy(1, 10);
    const char  menu[][30] = {
    {" 1 - CARGAR "},
    {" 2 - EDITAR "},
    {" 3 - LISTAR X ID "},
    {" 4 - LISTAR TODOS "},
    {" 0 - SALIR "}
    };
    for(unsigned int i = 0; i<5; i++){
      setColor(TEXT_COLOR);
      if (option-1 == i){
        setBackgroundColor(BLUE);
      }
      cout << menu[i] << endl;
      resetColor();
    }
    cout << endl;
    cout << " OPCIÓN: ";
    cin >> opt;
    return opt;
  }
}

#endif // FUNCIONES_H_INCLUDED
