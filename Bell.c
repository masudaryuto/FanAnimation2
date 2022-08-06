#include "Definition.h"


/*********************************風鈴の関数******************************/
//風鈴を揺らしたい。計算
double bell_rotation_x(double bell_x, double bell_y, int k){
    double newbell_x;
    double theta_bell;

    theta_bell = M_PI/6;
    newbell_x = bell_x * cos(theta_bell*k) - bell_y * sin(theta_bell*k);

    return newbell_x;
}
//回転計算の関数y
double bell_rotation_y(double bell_x, double bell_y, int k){
    double newbell_y;
    double theta_bell;

    theta_bell = M_PI/6;
    newbell_y = bell_x * sin(theta_bell*k) + bell_y * cos(theta_bell*k);
    
    return newbell_y;
}
//風鈴の描写(どこかに風鈴を置き、そこに扇風機が向いたら、揺れるか音がなるか)
void wide_bell_Draw(int wide_bell_layerid, Bell bell){

    HgLClear(wide_bell_layerid);
    //風鈴の紙の部分に文字を書きたい
    char bell_str[] = "HELLO";
    char single[2];
    single[1] =  '\0';
    //線と長方形
    HgWLine(wide_bell_layerid, bell.line_under_bell[0], bell.line_under_bell[1], bell.line_under_bell[2] - bell.move, bell.line_under_bell[3] + bell.move);
    HgWSetFillColor(wide_bell_layerid, HG_SKYBLUE);
    HgWBoxFill(wide_bell_layerid, bell.box_under_bell[0] - bell.move, bell.box_under_bell[1] + bell.move, bell.box_under_bell[2], bell.box_under_bell[3], 0);

    //本体の部分
    HgWSetFillColor(wide_bell_layerid, HG_CYAN);
    HgWLine(wide_bell_layerid, bell.line_up_bell[0], bell.line_up_bell[1], bell.line_up_bell[2], bell.line_up_bell[3]);
    HgWFanFill(wide_bell_layerid, bell.bell_main[0], bell.bell_main[1], bell.bell_main[2], bell.bell_main[3], bell.bell_main[4], 0);
    HgWPolygonFill(wide_bell_layerid, 3, bell.bellx, bell.belly,0);
    HgWSetFont(wide_bell_layerid,  HG_TBI, 20.0);
    for(int t=0; t<6; t++){
        single[0] = bell_str[t];
        HgWText(wide_bell_layerid, bell.bell_str_x - bell.move,  bell.bell_str_y[t] + bell.move, single);
    }
}
//風鈴の動かす
Bell move_bell(int wide_bell_layerid, Fan fan, Bell bell ){
    //風鈴と扇風機の
    if(fan.fancircle_x - bell.box_under_bell[0] < 185.0 && bell.bell_flag == 0){
        if(fan.red_button_flag == 0){
            //weak
            if (fan.add == 4) {
                bell.move = 10;
            }
            //middle
            else if(fan.add == 8){
                bell.move = 20;
            }
            //strong
            else if(fan.add == 12){
                bell.move = 30;
            }
        }
        else if(fan.red_button_flag == 1){
            bell.bell_flag = 1;
            bell.move = 0;
        }
        //風鈴を動かす。
        wide_bell_Draw(wide_bell_layerid, bell);
    }
    else if(fan.fancircle_x - bell.box_under_bell[0] >= 185.0 && fan.fan_face_flag == 1 ){
        bell.move = 0;
        //風鈴を動かす。
        wide_bell_Draw(wide_bell_layerid, bell);
    }
    return bell;
}
