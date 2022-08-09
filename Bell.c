#include "Definition.h"

/* Bell構造体のメモリ確保 */
Bell* newBell(void){
    Bell* this = NULL;
    this = malloc(sizeof(Bell));
    (*this).bellx = malloc(sizeof(double) * 3);
    if((*this).bellx == NULL) exit(EXIT_FAILURE);

    (*this).belly = malloc(sizeof(double) * 3);
    if((*this).belly == NULL) exit(EXIT_FAILURE);

    (*this).bellr = 0.0;

    //風鈴の長方形の部分
    (*this).line_under_bell = malloc(sizeof(double) * 4);
    if((*this).line_under_bell == NULL) exit(EXIT_FAILURE);

    (*this).box_under_bell = malloc(sizeof(double) * 4);
    if((*this).box_under_bell == NULL) exit(EXIT_FAILURE);

    (*this).line_up_bell = malloc(sizeof(double) * 4);
    if((*this).line_up_bell == NULL) exit(EXIT_FAILURE);

    (*this).bell_main = malloc(sizeof(double) * 5);
    if((*this).bell_main == NULL) exit(EXIT_FAILURE);

    (*this).bell_str_x = 0.0;
    (*this).bell_str_y = malloc(sizeof(double) * 5);
    if((*this).bell_str_y== NULL) exit(EXIT_FAILURE);

    //長方形の部分を動かす量
    (*this).move = 0.0;
    //フラグ
    (*this).bell_flag = 0.0;

    //メソッド
    (*this).bellSetup = &bellSetup;
	(*this).bell_rotation_x = &bell_rotation_x;
	(*this).bell_rotation_y = &bell_rotation_y;
	(*this).wide_bell_Draw = &wide_bell_Draw;
	(*this).move_bell = &move_bell;

    return this;
}

/* Bell構造体を初期化 */
void bellSetup(Bell* this){
    (*this).bellx[0] = 2 * WINDOWSIZEx / 9 - 50 * cos(M_PI/3);
    (*this).bellx[1] = 2 * WINDOWSIZEx / 9 + 50 * cos(M_PI/3);
    (*this).bellx[2] = 2 * WINDOWSIZEx / 9;

    (*this).belly[0] = 7 * WINDOWSIZEy / 8 - 50 * sin(M_PI/3);
    (*this).belly[1] = 7 * WINDOWSIZEy / 8 - 50 * sin(M_PI/3);
    (*this).belly[2] = 7 * WINDOWSIZEy / 8;

    (*this).bellr = 50;

    //風鈴の長方形の部分
    (*this).line_under_bell[0] = 2 * WINDOWSIZEx / 9;
    (*this).line_under_bell[1] = 7 * WINDOWSIZEy / 8 + 50;
    (*this).line_under_bell[2] = 2 * WINDOWSIZEx / 9;
    (*this).line_under_bell[3] = 6 * WINDOWSIZEy / 8;

    (*this).box_under_bell[0] = 2 * WINDOWSIZEx / 9 - 50 * cos(M_PI/3);
    (*this).box_under_bell[1] = WINDOWSIZEy / 2;
    (*this).box_under_bell[2] = 2 * 50*cos(M_PI/3);
    (*this).box_under_bell[3] = 6 * WINDOWSIZEy / 8 - WINDOWSIZEy / 2;

    (*this).line_up_bell[0] = 2 * WINDOWSIZEx / 9;
    (*this).line_up_bell[1] = 7 * WINDOWSIZEy / 8 + 50;
    (*this).line_up_bell[2] = 2 * WINDOWSIZEx / 9;
    (*this).line_up_bell[3] = WINDOWSIZEy;

    (*this).bell_main[0] = 2 * WINDOWSIZEx / 9;
    (*this).bell_main[1] = 7 * WINDOWSIZEy / 8;
    (*this).bell_main[2] = 50;
    (*this).bell_main[3] = - M_PI / 3;
    (*this).bell_main[4] = 4 * M_PI / 3;

    (*this).bell_str_x = 2 * WINDOWSIZEx / 9 - (*this).bellr * cos(M_PI/3) + 17;

    (*this).bell_str_y[0] = (6 * WINDOWSIZEy / 8) - 30 * (0 + 1);
    (*this).bell_str_y[1] = (6 * WINDOWSIZEy / 8) - 30 * (1 + 1);
    (*this).bell_str_y[2] = (6 * WINDOWSIZEy / 8) - 30 * (2 + 1);
    (*this).bell_str_y[3] = (6 * WINDOWSIZEy / 8) - 30 * (3 + 1);
    (*this).bell_str_y[4] = (6 * WINDOWSIZEy / 8) - 30 * (4 + 1);

    //長方形の部分を動かす量
    (*this).move = 0.0;
    //フラグ
    (*this).bell_flag = 0.0;

    return;
}

/*風鈴を揺らしたい。計算*/
double bell_rotation_x(double bell_x, double bell_y, int k){
    double newbell_x;
    double theta_bell;

    theta_bell = M_PI/6;
    newbell_x = bell_x * cos(theta_bell*k) - bell_y * sin(theta_bell*k);

    return newbell_x;
}
/*回転計算の関数y*/
double bell_rotation_y(double bell_x, double bell_y, int k){
    double newbell_y;
    double theta_bell;

    theta_bell = M_PI/6;
    newbell_y = bell_x * sin(theta_bell*k) + bell_y * cos(theta_bell*k);
    
    return newbell_y;
}

/*風鈴の描写(どこかに風鈴を置き、そこに扇風機が向いたら、揺れるか音がなるか)*/
void wide_bell_Draw(Bell* this, int wide_bell_layerid){

    HgLClear(wide_bell_layerid);

    //風鈴の紙の部分に文字を書きたい
    char bell_str[] = "HELLO";
    char single[2];
    single[1] =  '\0';
    //線と長方形
    HgWLine(wide_bell_layerid, (*this).line_under_bell[0], (*this).line_under_bell[1], (*this).line_under_bell[2] - (*this).move, (*this).line_under_bell[3] + (*this).move);
    HgWSetFillColor(wide_bell_layerid, HG_SKYBLUE);
    HgWBoxFill(wide_bell_layerid, (*this).box_under_bell[0] - (*this).move, (*this).box_under_bell[1] + (*this).move, (*this).box_under_bell[2], (*this).box_under_bell[3], 0);

    //本体の部分
    HgWSetFillColor(wide_bell_layerid, HG_CYAN);
    HgWLine(wide_bell_layerid, (*this).line_up_bell[0], (*this).line_up_bell[1], (*this).line_up_bell[2], (*this).line_up_bell[3]);
    HgWFanFill(wide_bell_layerid, (*this).bell_main[0], (*this).bell_main[1], (*this).bell_main[2], (*this).bell_main[3], (*this).bell_main[4], 0);
    HgWPolygonFill(wide_bell_layerid, 3, (*this).bellx, (*this).belly,0);
    HgWSetFont(wide_bell_layerid,  HG_TBI, 20.0);

    for(int t=0; t<6; t++){
        single[0] = bell_str[t];
        
        HgWText(wide_bell_layerid, (*this).bell_str_x - (*this).move,  (*this).bell_str_y[t] + (*this).move, single);
    }

    return;
}

/*風鈴の動かす*/
void move_bell(Bell* this, Fan* aFan, int wide_bell_layerid){

    //風鈴と扇風機の
    if((*aFan).fancircle_x - ((*this).bellx[0]) < 185.0 && (*this).bell_flag == 0){
        if((*aFan).red_button_flag == 0){
            //weak
            if ((*aFan).add == 4) {
                (*this).move = 10;
            }
            //middle
            else if((*aFan).add == 8){
                (*this).move = 20;
            }
            //strong
            else if((*aFan).add == 12){
                (*this).move = 30;
            }
        }
        else if((*aFan).red_button_flag == 1){
            (*this).bell_flag = 1;
            (*this).move = 0;
        }
        //風鈴を動かす。
        (*this).wide_bell_Draw(this, wide_bell_layerid);
    }
    else if((*aFan).fancircle_x - ((*this).bellx[0]) >= 185.0 && (*aFan).fan_face_flag == 1 ){
        (*this).move = 0;
        //風鈴を動かす。
        (*this).wide_bell_Draw(this, wide_bell_layerid);
    }

    return;
}
