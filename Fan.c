#include "Definition.h"

Fan* newFan(void){

    Fan* this = NULL;
    this = malloc(sizeof(Fan));

    //扇風機の円
    (*this).fancircle_x = 0.0;
    (*this).fancircle_y = 0.0;
    (*this).bigfancircle_r1 = 0.0;
    (*this).bigfancircle_r2 = 0.0;
    //円の中の小さな円
    (*this).smallfancircle_r1 = 0.0;
    (*this).smallfancircle_r2 = 0.0;
    //フラグ
    (*this).red_button_flag = 0;
    //spin
    (*this).spin_button_flag = 0;
    //関数内で、首を回す判定で必要なフラグ
    (*this).fan_face_flag = 0;
    //HgSleepで速さを調節する。
    (*this).add = 0.0;
    //fanの回転カウント
    (*this).counter = 0.0;
    //プログラム終了フラグ
    (*this).end_flag = 0;

	(*this).fanSetup = &fanSetup;
    (*this).judgeFan = &judgeFan;
	(*this).stringDraw = &stringDraw;
	(*this).fan_blade = &fan_blade;
	(*this).fan_body = &fan_body;
	(*this).fan_cover = &fan_cover;
	(*this).rotation_x = &rotation_x;
	(*this).rotation_y = &rotation_y;
	(*this).fan_cover = &fan_cover;
    (*this).button_judge = &button_judge;
    (*this).spin_fan_judge = &spin_fan_judge;
    


    return this;
}

void judgeFan(Fan* this, View* aView){
	if( (*this).red_button_flag == 0) {
		(*this).counter += (*this).add;
		(*this).fan_blade(this, (*aView).bladelayerid);

		//spinボタン
		if((*this).spin_button_flag % 2 == 0){
			//spin_button_flag(spinボタン)が押されたら、fanの頭の部分が回転する描写が起きる。
			//その時、fanの回転のために、x,y,rが変化されていくため、自然と羽も続いて、回転する。
			(*this).fan_cover(this, (*aView).fancoverlayerid);
        }

	}
	if ((*this).end_flag == 1){
		exit(EXIT_SUCCESS);
	}

    return;
}

void fanSetup(Fan* this, double fancircle_x, double fancircle_y, double bigfancircle_r1, double bigfancircle_r2, double smallfancircle_r1, double smallfancircle_r2, int red_button_flag, int spin_button_flag, int fan_face_flag, double add, double counter, int end_flag){

    //大きな楕円の中心座標
    (*this).fancircle_x = fancircle_x;
    (*this).fancircle_y = fancircle_y;
    //大きな楕円のxの半径(r1)とyの半径(r2)
    (*this).bigfancircle_r1 = bigfancircle_r1;
    (*this).bigfancircle_r2 = bigfancircle_r2;
    //大きな楕円の真ん中の小さな楕円のxの半径(r1)とyの半径(r2)
    (*this).smallfancircle_r1 = smallfancircle_r1;
    (*this).smallfancircle_r2 = smallfancircle_r2;
    //stopボタンのフラグ//押されたら、flag=1
    (*this).red_button_flag = red_button_flag;
    //spinボタンのフラグ
    (*this).spin_button_flag = spin_button_flag;
    //spin_fan_judge関数で、首を回す判定に利用する。
    (*this).fan_face_flag = fan_face_flag;
    //スピード調整
    (*this).add = add;
    //counterを使って、回転させる
    (*this).counter = counter;
    //プログラム終了フラグ
    (*this).end_flag = end_flag;

    return;
}


//文字列描写
void stringDraw(Fan* this, int strlayeid){
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

    if((*this).counter == 0){
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
    if((*this).red_button_flag == 0){

        //強
        if((*this).add == 12){
            HgWText(strlayeid, 0, WINDOWSIZEy - 20, strong_button, 1);
        }        
        //中
        else if((*this).add == 8){
            HgWText(strlayeid, 0, WINDOWSIZEy - 20, middle_button, 1);
        }
        //弱
        else if((*this).add == 4){
            HgWText(strlayeid, 0, WINDOWSIZEy - 20, weak_button, 1);
        }
    }
    //止まっている時
    else {
        HgWText(strlayeid, 0, WINDOWSIZEy - 20, off_str, 1);
    }

    return;
}

//扇風機の頭以外の描写
void fan_body(Fan* this){
    //扇風機の首
    double fanneck_x[4] = {(*this).fancircle_x + (*this).smallfancircle_r1 - 30, (*this).fancircle_x + (*this).smallfancircle_r1, (*this).fancircle_x - (*this).smallfancircle_r1, (*this).fancircle_x - (*this).smallfancircle_r1 + 30};
    double fanneck_y[4] = {(*this).fancircle_y, ((*this).fancircle_y - (*this).bigfancircle_r1) / 2, ((*this).fancircle_y - (*this).bigfancircle_r1) / 2, (*this).fancircle_y};
    //扇風機の首の根本
    double fan_root[5] = {(*this).fancircle_x, ((*this).fancircle_y - (*this).bigfancircle_r1) / 2, (*this).smallfancircle_r1, (2 * (*this).smallfancircle_r1) /3 - 10, 0};
    //扇風機の体
    double fanbody[5] = {(*this).fancircle_x, ((*this).fancircle_y / 8) + (*this).smallfancircle_r1 - 10, (*this).bigfancircle_r1, (*this).bigfancircle_r1 / 2,0};
    //ボタン
    double red_button[5] = {(*this).fancircle_x - (*this).smallfancircle_r1, (*this).bigfancircle_r1 / 2 - 5, 15, 14, 0};
    double strong_button[5] = {(*this).fancircle_x + (*this).smallfancircle_r1 + 40, (*this).smallfancircle_r1 + 50, 13, 11, 0};
    double middle_button[5] = {(*this).fancircle_x + (*this).smallfancircle_r1 + 20, (*this).smallfancircle_r1 + 23, 13, 11, 0};
    double weak_button[5] = {(*this).fancircle_x + (*this).smallfancircle_r1 - 15, (*this).smallfancircle_r1 + 13, 13, 12, 0};

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
    HgBoxFill(fanneck_x[3], fanneck_y[0], fanneck_x[0]-fanneck_x[3], (*this).smallfancircle_r2 - 20, 0);
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

    return;
}

//fanの頭の部分
void fan_cover(Fan* this, int fancoverlayerid){
    double cover_theta = M_PI / 12;
    int k;
    //網の部分
    double cover_x;
    double cover_y;
    //fanを回転させているように見せたい。
    //偶数だったら、spinボタンが起動し、首が回る。
    if((*this).spin_button_flag % 2 == 0){
        //fanの首を回す
        (*this).spin_fan_judge(this);
    }
    //大きな円
    HgLClear(fancoverlayerid);
    HgWSetWidth(fancoverlayerid, 3.0);
    HgWSetColor(fancoverlayerid, HG_BLACK);
    HgWOval(fancoverlayerid, (*this).fancircle_x, (*this).fancircle_y, (*this).bigfancircle_r1, (*this).bigfancircle_r2, 0);
    //線が太いままなので、ここで、太さを戻す。
    HgWSetWidth(fancoverlayerid, 1.0);
    //円の中に円(fanの網の部分)
    HgWSetColor(fancoverlayerid, HG_BLUE);
    HgWOval(fancoverlayerid, (*this).fancircle_x, (*this).fancircle_y, (*this).smallfancircle_r1 + 1 * ((*this).bigfancircle_r1 - (*this).smallfancircle_r1) / 3, (*this).smallfancircle_r2 + 1 * ((*this).bigfancircle_r2 - (*this).smallfancircle_r2) / 3, 0);
    HgWOval(fancoverlayerid, (*this).fancircle_x, (*this).fancircle_y, (*this).smallfancircle_r1 + 2 * ((*this).bigfancircle_r1 - (*this).smallfancircle_r1) / 3, (*this).smallfancircle_r2 + 2 * ((*this).bigfancircle_r2 - (*this).smallfancircle_r2) / 3, 0);
    //網の縦線の部分
    for(int k = 0; k < 24; k++){
        cover_x = rotation_x(this, (*this).bigfancircle_r1, k, cover_theta);
        cover_y = rotation_y(this, cover_x, (*this).bigfancircle_r1, (*this).bigfancircle_r2, k, cover_theta);
        HgWLine(fancoverlayerid, (*this).fancircle_x, (*this).fancircle_y, cover_x + (*this).fancircle_x, cover_y + (*this).fancircle_y);
    }
    //中心の黒い円(網の真ん中の円)
    HgWSetColor(fancoverlayerid, HG_BLACK);
    HgWSetFillColor(fancoverlayerid, HG_BLACK);
    HgWOvalFill(fancoverlayerid, (*this).fancircle_x, (*this).fancircle_y, (*this).smallfancircle_r1, (*this).smallfancircle_r2, 0, 1);

    return;
}

//羽の回転描写
void fan_blade(Fan* this, int bladelayerid){

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
    double rotation_x1[2] = {(*this).rotation_x(this, (*this).bigfancircle_r1,(*this).counter + timely11, blade_theta), (*this).rotation_x(this, (*this).bigfancircle_r1, (*this).counter + timely12, blade_theta)};
    double rotation_y1[2] = {(*this).rotation_y(this, rotation_x1[0], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter + timely11, blade_theta), (*this).rotation_y(this, rotation_x1[1], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter+timely12, blade_theta)};
    double blade_x1[4] = {(*this).fancircle_x, (*this).fancircle_x + rotation_x1[0], (*this).fancircle_x + rotation_x1[1], (*this).fancircle_x};
    double blade_y1[4] = {(*this).fancircle_y, (*this).fancircle_y + rotation_y1[0], (*this).fancircle_y + rotation_y1[1], (*this).fancircle_y};
    //扇風機の羽2
    double rotation_x2[2] = {(*this).rotation_x(this, (*this).bigfancircle_r1, (*this).counter + timely21, blade_theta), (*this).rotation_x(this, (*this).bigfancircle_r1, (*this).counter+timely22, blade_theta)};
    double rotation_y2[2] = {(*this).rotation_y(this, rotation_x2[0], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter + timely21, blade_theta), (*this).rotation_y(this, rotation_x2[1], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter + timely22, blade_theta)};
    double blade_x2[4] = {(*this).fancircle_x, (*this).fancircle_x+rotation_x2[0], (*this).fancircle_x+rotation_x2[1], (*this).fancircle_x};
    double blade_y2[4] = {(*this).fancircle_y, (*this).fancircle_y+rotation_y2[0], (*this).fancircle_y+rotation_y2[1], (*this).fancircle_y};
    //扇風機の羽3
    double rotation_x3[2] = {(*this).rotation_x(this, (*this).bigfancircle_r1,(*this).counter+timely31, blade_theta), (*this).rotation_x(this, (*this).bigfancircle_r1, (*this).counter + timely32, blade_theta)};
    double rotation_y3[2] = {(*this).rotation_y(this, rotation_x3[0], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter + timely31, blade_theta), (*this).rotation_y(this, rotation_x3[1], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter + timely32, blade_theta)};
    double blade_x3[4] = {(*this).fancircle_x, (*this).fancircle_x + rotation_x3[0], (*this).fancircle_x + rotation_x3[1], (*this).fancircle_x};
    double blade_y3[4] = {(*this).fancircle_y, (*this).fancircle_y + rotation_y3[0], (*this).fancircle_y + rotation_y3[1], (*this).fancircle_y };
    //扇風機の羽4
    double rotation_x4[2] = {(*this).rotation_x(this, (*this).bigfancircle_r1, (*this).counter + timely41, blade_theta), (*this).rotation_x(this, (*this).bigfancircle_r1, (*this).counter + timely42, blade_theta)};
    double rotation_y4[2] = {(*this).rotation_y(this, rotation_x4[0], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter + timely41, blade_theta), rotation_y(this, rotation_x4[1], (*this).bigfancircle_r1, (*this).bigfancircle_r2, (*this).counter + timely42, blade_theta)};
    double blade_x4[4] = {(*this).fancircle_x, (*this).fancircle_x+rotation_x4[0], (*this).fancircle_x+rotation_x4[1], (*this).fancircle_x};
    double blade_y4[4] = {(*this).fancircle_y, (*this).fancircle_y+rotation_y4[0], (*this).fancircle_y+rotation_y4[1], (*this).fancircle_y };

    //printf("%f\n", blade_x1[0]);
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
double rotation_x(Fan* this, double r1, double counter, double theta){
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

double rotation_y(Fan* this, double x, double r1, double r2, double counter , double theta){
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

//ボタンの判定
void button_judge(Fan* this, int strlayerid, Point* aPoint){
    //ボタン
    double red_button[5] = {WINDOWSIZEx / 2 - 40, 120 / 2 - 5, 15, 14, 0};
    double strong_button[5] = {WINDOWSIZEx / 2 + 40 + 40, 40 + 50, 13, 11, 0};
    double middle_button[5] = {WINDOWSIZEx / 2 + 40 + 20, 40 + 23, 13, 11, 0};
    double weak_button[5] = {WINDOWSIZEx / 2 + 40 - 15, 40 + 13, 13, 12, 0};
    //赤いボタン(stop)
    if (red_button[0] - red_button[2] < (*aPoint).x && (*aPoint).x < red_button[0] + red_button[2]){
        if (red_button[1] - red_button[3] < (*aPoint).y && (*aPoint).y < red_button[1] + red_button[3]){
            
            //stopボタンを押したら、flagを1にする。
            (*this).red_button_flag = 1;
            //表示を"Now OFF"
            (*this).stringDraw(this, strlayerid);
        }
    }
    //spinボタン
    if (WINDOWSIZEx - 40< (*aPoint).x && (*aPoint).x < WINDOWSIZEx){
        if (WINDOWSIZEy - 60 < (*aPoint).y && (*aPoint).y < WINDOWSIZEy){
            //偶数だったらON
            (*this).spin_button_flag++;
        }
    }
    //strongボタン
    if (strong_button[0] - strong_button[2] < (*aPoint).x && (*aPoint).x < strong_button[0] + strong_button[2]){
        if (strong_button[1] - strong_button[3] < (*aPoint).y && (*aPoint).y < strong_button[1] + strong_button[3]){
            //conterに足す数を増やし、回転速度を上げる
            (*this).add = 12;
            //フラグを上げて、羽を回す。
            (*this).red_button_flag = 0;
            //表示を"Now strong"
            (*this).stringDraw(this, strlayerid);
        }
    }
    //middleボタン
    if (middle_button[0] - middle_button[2] < (*aPoint).x && (*aPoint).x < middle_button[0] + middle_button[2]){
        if (middle_button[1] - middle_button[3] < (*aPoint).y && (*aPoint).y < middle_button[1] + middle_button[3]){
            //conterに足す数を増やし、回転速度を上げる
            (*this).add = 8;
            //フラグを上げて、羽を回す。
            (*this).red_button_flag = 0;           
            //表示を"Now middle"
            (*this).stringDraw(this, strlayerid);

        }
    }
    //weakボタン
    if (weak_button[0] - weak_button[2] < (*aPoint).x && (*aPoint).x < weak_button[0] + weak_button[2]){
        if (weak_button[1] - weak_button[3] < (*aPoint).y && (*aPoint).y < weak_button[1] + weak_button[3]){
            //conterに足す数を増やし、回転速度を上げる
            (*this).add = 4;
            //フラグを上げて、羽を回す。
            (*this).red_button_flag = 0;         
            //表示を"Now weak"
            stringDraw(this, strlayerid);
        }
    }

    //プログラム終了
    if (0 < (*aPoint).x && (*aPoint).x < 20){
        if (0 < (*aPoint).y && (*aPoint).y < 20){
            (*this).end_flag = 1;
        }
    }
    return;
}


//fanの回転判定
void spin_fan_judge(Fan* this){
    //rが最大の時flag=0、左に首が周り、r1は小さくなっていく。
    if ( (*this).fan_face_flag == 0){
        (*this).bigfancircle_r1 -= 2;
        (*this).smallfancircle_r1 -= 2;
        (*this).fancircle_x --;
        //小さい楕円のx半径が2になったら、flag=1とする。
        if((*this).smallfancircle_r1 == 2){
            (*this).fan_face_flag = 1;
        }
    }
    //fanが、一番左を向いている時、flag=1で、x半径を大きくしていき、首を右に向けていく。
    else if ((*this).fan_face_flag == 1){
        (*this).bigfancircle_r1 += 2;
        (*this).smallfancircle_r1 += 2;

        (*this).fancircle_x++;
        //fanが正面を向いたら、flagを2にする。
        if((*this).smallfancircle_r1 == 40){
            (*this).fan_face_flag = 2;
        }
    }
    //flag=2の時、左に首を回す。
    else if ((*this).fan_face_flag == 2){
        (*this).bigfancircle_r1 -= 2;
        (*this).smallfancircle_r1 -= 2;

        (*this).fancircle_x ++;
        //首が一番左を向いた時、flagを3にする。
        if((*this).smallfancircle_r1 == 2){
            //printf("C\n");
            (*this).fan_face_flag = 3;
        }
    }
    //首が一番左を向いている時、首を右に回す。
    else if ((*this).fan_face_flag == 3){
        (*this).bigfancircle_r1 += 2;
        (*this).smallfancircle_r1 += 2;

        (*this).fancircle_x --;
        //首が正面を向いたら、flagを0にする。
        if((*this).smallfancircle_r1 == 40){
            (*this).fan_face_flag = 0;
        }
    }
    return;
}


