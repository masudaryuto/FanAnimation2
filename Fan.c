#include "Definition.h"

/***************************扇風機関数********************/
Fan fanSetup(double fancircle_x, double fancircle_y, double bigfancircle_r1, double bigfancircle_r2, double smallfancircle_r1, double smallfancircle_r2, int red_button_flag, int spin_button_flag, int fan_face_flag, double add, double counter, int end_flag){

    Fan fan;
    //大きな楕円の中心座標
    fan.fancircle_x = fancircle_x;
    fan.fancircle_y = fancircle_y;
    //大きな楕円のxの半径(r1)とyの半径(r2)
    fan.bigfancircle_r1 = bigfancircle_r1;
    fan.bigfancircle_r2 = bigfancircle_r2;
    //大きな楕円の真ん中の小さな楕円のxの半径(r1)とyの半径(r2)
    fan.smallfancircle_r1 = smallfancircle_r1;
    fan.smallfancircle_r2 = smallfancircle_r2;
    //stopボタンのフラグ//押されたら、flag=1
    fan.red_button_flag = red_button_flag;
    //spinボタンのフラグ
    fan.spin_button_flag = spin_button_flag;
    //spin_fan_judge関数で、首を回す判定に利用する。
    fan.fan_face_flag = fan_face_flag;
    //スピード調整
    fan.add = add;
    //counterを使って、回転させる
    fan.counter = counter;
    //プログラム終了フラグ
    fan.end_flag = end_flag;

    return fan;
}


//文字列描写
void stringDraw(int strlayeid, Fan fan){
    int t;
    //文字列(ボタン)
    char spin_str[] = "SPIN";
    //文字の格納場所
    char single[2];
    single[1] = '\0';
    char weak_button[] = "Now weak";
    char middle_button[] = "Now middle";
    char strong_button[] = "Now strong";
    char off_str[] = "Now OFF";

    if(fan.counter == 0){
        //spinボタン
        HgSetFillColor(HG_RED);
        HgBoxFill(WINDOWSIZEx-40, WINDOWSIZEy-60, 40, 60,1);
        //spin描写
        HgSetColor(HG_BLACK);
        for(t=0; t<5; t++){
            single[0] = spin_str[t];
            HgText(WINDOWSIZEx-25 + 10 * pow(-1.0, t), WINDOWSIZEy - 20 - (14 * t), single);
        }
    }
    //羽が回っている時
    HgLClear(strlayeid);
    if(fan.red_button_flag == 0){

        //強
        if(fan.add == 12){
            HgWText(strlayeid, 0, WINDOWSIZEy - 20, strong_button, 1);
        }        
        //中
        else if(fan.add == 8){
            HgWText(strlayeid, 0, WINDOWSIZEy - 20, middle_button, 1);
        }
        //弱
        else if(fan.add == 4){
            HgWText(strlayeid, 0, WINDOWSIZEy - 20, weak_button, 1);
        }
    }
    //止まっている時
    else {
        HgWText(strlayeid, 0, WINDOWSIZEy - 20, off_str, 1);
    }
}

//扇風機の頭以外の描写
void fan_body( Fan fan ){
    //扇風機の首
    double fanneck_x[4] = {fan.fancircle_x + fan.smallfancircle_r1 - 30, fan.fancircle_x + fan.smallfancircle_r1, fan.fancircle_x - fan.smallfancircle_r1, fan.fancircle_x - fan.smallfancircle_r1 + 30};
    double fanneck_y[4] = {fan.fancircle_y, (fan.fancircle_y - fan.bigfancircle_r1) / 2, (fan.fancircle_y - fan.bigfancircle_r1) / 2, fan.fancircle_y};
    //扇風機の首の根本
    double fan_root[5] = {fan.fancircle_x, (fan.fancircle_y - fan.bigfancircle_r1) / 2, fan.smallfancircle_r1, (2 * fan.smallfancircle_r1) /3 - 10, 0};
    //扇風機の体
    double fanbody[5] = {fan.fancircle_x, (fan.fancircle_y / 8) + fan.smallfancircle_r1 - 10, fan.bigfancircle_r1, fan.bigfancircle_r1 / 2,0};
    //ボタン
    double red_button[5] = {fan.fancircle_x - fan.smallfancircle_r1, fan.bigfancircle_r1 / 2 - 5, 15, 14, 0};
    double strong_button[5] = {fan.fancircle_x + fan.smallfancircle_r1 + 40, fan.smallfancircle_r1 + 50, 13, 11, 0};
    double middle_button[5] = {fan.fancircle_x + fan.smallfancircle_r1 + 20, fan.smallfancircle_r1 + 23, 13, 11, 0};
    double weak_button[5] = {fan.fancircle_x + fan.smallfancircle_r1 - 15, fan.smallfancircle_r1 + 13, 13, 12, 0};

    //弱い、中、強い, 切
    char weak_str[] = "弱";
    char middle_str[] = "中";
    char strong_str[] = "強";
    char off_str[] = "切";

    char end_button[] = "終";

    //扇風機の体
    HgSetFillColor(HG_GRAY);
    HgOvalFill(fanbody[0], fanbody[1], fanbody[2], fanbody[3], fanbody[4], 1);
    //扇風機の首
    HgSetFillColor(HG_LGRAY);
    HgPolygonFill(4, fanneck_x, fanneck_y, 0);
    //扇風機の首の根本
    HgOvalFill(fan_root[0], fan_root[1], fan_root[2], fan_root[3], fan_root[4], 0); 
    //扇風機と首の結び
    HgSetFillColor(HG_DGRAY);
    HgBoxFill(fanneck_x[3], fanneck_y[0], fanneck_x[0]-fanneck_x[3], fan.smallfancircle_r2 - 20, 0);
    //ボタン
    //切
    HgSetFillColor(HG_RED);
    HgOvalFill(red_button[0], red_button[1], red_button[2], red_button[3], red_button[4], 1);
    //ボタン説明
    HgText(2 * red_button[2], WINDOWSIZEy / 4 - weak_button[3] - 2 * red_button[3], off_str);
    HgOvalFill(red_button[2], WINDOWSIZEy / 4 - weak_button[3] - red_button[3], red_button[2], red_button[3], red_button[4], 1);
    //強い
    HgSetFillColor(HG_GREEN);
    HgOvalFill(strong_button[0], strong_button[1], strong_button[2], strong_button[3], strong_button[4],1);
    //ボタン説明
    HgText(2 * strong_button[2], WINDOWSIZEy / 4 + 2 * weak_button[3] + middle_button[3], strong_str);
    HgOvalFill(strong_button[2], WINDOWSIZEy / 4 + 2 * weak_button[3] + 2 * middle_button[3], strong_button[2], strong_button[3], strong_button[4], 1);

    //中
    HgSetFillColor(HG_BLUE);
    HgOvalFill(middle_button[0], middle_button[1], middle_button[2], middle_button[3], middle_button[4], 1);
    //ボタン説明
    HgText(2 * middle_button[2], WINDOWSIZEy / 4 + weak_button[3], middle_str);
    HgOvalFill(0 + middle_button[2], WINDOWSIZEy / 4 + 2 * weak_button[3], middle_button[2], middle_button[3], middle_button[4], 1);

    //弱い
    HgSetFillColor(HG_YELLOW);
    HgOvalFill(weak_button[0], weak_button[1], weak_button[2], weak_button[3], weak_button[4],1);
    //ボタン説明
    HgText(2 * weak_button[2], WINDOWSIZEy / 4 - weak_button[3], weak_str);
    HgOvalFill(0 + weak_button[2], WINDOWSIZEy / 4, weak_button[2], weak_button[3], weak_button[4], 1);

    //終了ボタン
    HgSetFillColor(HG_RED);
    HgBoxFill(0, 0, 20, 20, 1);
    HgText(2, 0, end_button);
}

//fanの頭の部分
void fan_cover(int fancoverlayerid, Fan fan){
    double cover_theta = M_PI / 12;
    int k;
    //網の部分
    double cover_x;
    double cover_y;
    //fanを回転させているように見せたい。
    //偶数だったら、spinボタンが起動し、首が回る。
    if(fan.spin_button_flag % 2 == 0){
        //fanの首を回す
        //fan = spin_fan_judge(fan);
    }
    //大きな円
    HgLClear(fancoverlayerid);
    HgWSetWidth(fancoverlayerid, 3.0);
    HgWSetColor(fancoverlayerid, HG_BLACK);
    HgWOval(fancoverlayerid, fan.fancircle_x, fan.fancircle_y, fan.bigfancircle_r1, fan.bigfancircle_r2, 0);
    //線が太いままなので、ここで、太さを戻す。
    HgWSetWidth(fancoverlayerid, 1.0);
    //円の中に円(fanの網の部分)
    HgWSetColor(fancoverlayerid, HG_BLUE);
    HgWOval(fancoverlayerid, fan.fancircle_x, fan.fancircle_y, fan.smallfancircle_r1 + 1 * (fan.bigfancircle_r1 - fan.smallfancircle_r1) / 3, fan.smallfancircle_r2 + 1 * (fan.bigfancircle_r2 - fan.smallfancircle_r2) / 3, 0);
    HgWOval(fancoverlayerid, fan.fancircle_x, fan.fancircle_y, fan.smallfancircle_r1 + 2 * (fan.bigfancircle_r1 - fan.smallfancircle_r1) / 3, fan.smallfancircle_r2 + 2 * (fan.bigfancircle_r2 - fan.smallfancircle_r2) / 3, 0);
    //網の縦線の部分
    for(int k = 0; k < 24; k++){
        cover_x = rotation_x(fan.bigfancircle_r1, k, cover_theta);
        cover_y = rotation_y(cover_x, fan.bigfancircle_r1, fan.bigfancircle_r2, k, cover_theta);
        HgWLine(fancoverlayerid, fan.fancircle_x, fan.fancircle_y, cover_x + fan.fancircle_x, cover_y + fan.fancircle_y);
    }
    //中心の黒い円(網の真ん中の円)
    HgWSetColor(fancoverlayerid, HG_BLACK);
    HgWSetFillColor(fancoverlayerid, HG_BLACK);
    HgWOvalFill(fancoverlayerid, fan.fancircle_x, fan.fancircle_y, fan.smallfancircle_r1, fan.smallfancircle_r2, 0, 1);

    return;
}

//羽の回転描写
void fan_blade(int bladelayerid, Fan fan){

    //M_PI/100刻みで回る
    double blade_theta = M_PI / 100;
    //時差(fan.counterの時間を進めたり、遅らせたりする事で、羽を描く事ができる)
    //1つ目の羽
    double timely11 = 0;
    double timely12 = 20;
    //2つ目の羽
    double timely21 = 50;
    double timely22 = 70;
    //3つ目の羽
    double timely31 = 100;
    double timely32 = 120;
    //4つ目の羽
    double timely41 = 150;
    double timely42 = 170;
    //扇風機の羽1
    double rotation_x1[2] = {rotation_x(fan.bigfancircle_r1,fan.counter + timely11, blade_theta), rotation_x(fan.bigfancircle_r1, fan.counter + timely12, blade_theta)};
    double rotation_y1[2] = {rotation_y(rotation_x1[0], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter + timely11, blade_theta), rotation_y(rotation_x1[1], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter+timely12, blade_theta)};
    double blade_x1[4] = {fan.fancircle_x, fan.fancircle_x + rotation_x1[0], fan.fancircle_x + rotation_x1[1], fan.fancircle_x};
    double blade_y1[4] = {fan.fancircle_y, fan.fancircle_y + rotation_y1[0], fan.fancircle_y + rotation_y1[1], fan.fancircle_y};
    //扇風機の羽2
    double rotation_x2[2] = {rotation_x(fan.bigfancircle_r1, fan.counter + timely21, blade_theta), rotation_x(fan.bigfancircle_r1, fan.counter+timely22, blade_theta)};
    double rotation_y2[2] = {rotation_y(rotation_x2[0], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter + timely21, blade_theta), rotation_y(rotation_x2[1], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter + timely22, blade_theta)};
    double blade_x2[4] = {fan.fancircle_x, fan.fancircle_x+rotation_x2[0], fan.fancircle_x+rotation_x2[1], fan.fancircle_x};
    double blade_y2[4] = {fan.fancircle_y, fan.fancircle_y+rotation_y2[0], fan.fancircle_y+rotation_y2[1], fan.fancircle_y};
    //扇風機の羽3
    double rotation_x3[2] = {rotation_x(fan.bigfancircle_r1,fan.counter+timely31, blade_theta), rotation_x(fan.bigfancircle_r1, fan.counter + timely32, blade_theta)};
    double rotation_y3[2] = {rotation_y(rotation_x3[0], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter + timely31, blade_theta), rotation_y(rotation_x3[1], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter + timely32, blade_theta)};
    double blade_x3[4] = {fan.fancircle_x, fan.fancircle_x + rotation_x3[0], fan.fancircle_x + rotation_x3[1], fan.fancircle_x};
    double blade_y3[4] = {fan.fancircle_y, fan.fancircle_y + rotation_y3[0], fan.fancircle_y + rotation_y3[1], fan.fancircle_y };
    //扇風機の羽4
    double rotation_x4[2] = {rotation_x(fan.bigfancircle_r1, fan.counter + timely41, blade_theta), rotation_x(fan.bigfancircle_r1, fan.counter + timely42, blade_theta)};
    double rotation_y4[2] = {rotation_y(rotation_x4[0], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter + timely41, blade_theta), rotation_y(rotation_x4[1], fan.bigfancircle_r1, fan.bigfancircle_r2, fan.counter + timely42, blade_theta)};
    double blade_x4[4] = {fan.fancircle_x, fan.fancircle_x+rotation_x4[0], fan.fancircle_x+rotation_x4[1], fan.fancircle_x};
    double blade_y4[4] = {fan.fancircle_y, fan.fancircle_y+rotation_y4[0], fan.fancircle_y+rotation_y4[1], fan.fancircle_y };

    HgLClear(bladelayerid);
    //fanの羽の描写
    HgWSetFillColor(bladelayerid, HG_DGRAY);
    HgWSetWidth(bladelayerid, 5.0);
    HgWPolygonFill(bladelayerid, 3, blade_x1, blade_y1, 1);
    HgWPolygonFill(bladelayerid, 3, blade_x2, blade_y2, 1);
    HgWPolygonFill(bladelayerid, 3, blade_x3, blade_y3, 1);
    HgWPolygonFill(bladelayerid, 3, blade_x4, blade_y4, 1);

    return;
}


//回転計算の関数x
double rotation_x(double r1, double counter, double theta){
    double newblade_x;
    // r1 >= r1cos(theta*k) >= -r1
    //k=0の時、r1 = r1で、xは右端
    //k=6の時、r1 = 0で、xは中点０の位置
    //k=12の時、r1 = -r1で、xは左端
    //このように、x座標は、楕円軌道の外に出ることはない。
    //r1が変わっていっても、角度は大きくなっていくため、しっかり楕円軌道上を回転する。
    newblade_x = r1 * cos(theta*counter);
    //もし、x座標が左端に到達したら、y座標を反転させる。
    return newblade_x;
}

double rotation_y( double x, double r1, double r2, double counter , double theta){
    double newblade_y;
    //楕円の式より、+と-と判定する必要がある。
    if(sin(theta*counter) > 0 )
    {
        newblade_y = (r2/r1) * sqrt(r1*r1 - (x*x));
    }
    else
    {
        newblade_y = -(r2/r1) * sqrt(r1*r1 - (x*x));
    }
    return newblade_y;
}
