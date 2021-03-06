#include"libOne.h"
int createTriangle() {
    struct SHAPE_VERTEX vertices[3];
    vertices[0].x = 0;
    vertices[0].y = -1;
    vertices[1].x = 1;
    vertices[1].y = 1;
    vertices[2].x = -1;
    vertices[2].y = 1;
    return createShape(vertices, 3);
}
int createPolygon() {
    const int NUM = 5;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
    vertices[i].x = sin(deg*i);
    vertices[i].y = -cos(deg*i);
    }
    return createShape(vertices, NUM);
}
int createStar() {
    const int NUM = 10;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float radius = 0.5f + 0.5f * (i % 2);;
        vertices[i].x = sin(deg * i) * radius;
        vertices[i].y = cos(deg * i) * radius;
    }
    return createShape(vertices, NUM);
}
int createHeart() {
    const int NUM = 60;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float t = deg * i;
        vertices[i].x = 
           pow( sin(t), 3);
        vertices[i].y = -(
            13 * cos(t) -
            5 * cos(2 * t) -
            2 * cos(3 * t) -
            1 * cos(4 * t)) / 16;
    }
    return createShape(vertices, NUM);
}
void gmain() {
    window(1000, 1000);
    int idx = createHeart();
    float deg = 0;
    angleMode(DEGREES);
    while (notQuit) {
        //deg += 1;
        clear(200);
        strokeWeight(5);
        fill(255, 255, 0);
        shape(idx, 500, 500,deg,20);
    }
}

/*#include"libOne.h"
void gmain() {
    window(1000, 1000);
    let deg = 0;
    let x, y, r;
    angleMode(DEGREES);
    while (notQuit) {
        //角度degを決定
        if (isTrigger(KEY_SPACE))deg = 0;
        if (isTrigger(KEY_D))deg += 30;
        if (isTrigger(KEY_A))deg -= 30;
        if (isPress(KEY_W))deg += 1;
        if (isPress(KEY_S))deg -= 1;
        //原点から引いた長さ１の線を
        //deg度回転させたときのx、yを求める
        x = cos(deg);
        y = sin(deg);
        //線の長さrを求めて、１かどうか確認する
        r = sqrt(x * x + y * y);

        //クリアして軸を描画
        clear(128);
        mathAxis(1.2, 255);
        //線の太さ
        strokeWeight(10);
        //斜辺（長さ１の線）
        stroke(160, 200, 255);
        mathLine(0, 0, x, y);
        //底辺
        stroke(255, 255, 200);
        mathLine(0, 0, x, 0);
        //高さ
        stroke(255, 200, 200);
        mathLine(x, 0, x, y);

        //テキスト情報
        textSize(40);
        fill(255, 255, 200);
        text("底辺=cos(" + deg + ")=" + x, 0, 60);
        fill(255, 200, 200);
        text("高さ=sin(" + deg + ")=" + y, 0, 120);
        fill(160, 200, 255);
        text("斜辺(半径)=" + r, 0, 180);
    }
}*/
/*#include"libOne.h"
void gmain() {
    window(1000, 1000);
    let x=0, y=0, deg = -360;
    angleMode(DEGREES);
    while (notQuit) {
        deg += 2;
        if (deg > 360) {
            deg = -360;
            clear(0);
        }
        x = cos(deg)*100;
        y = sin(deg)*100;
        mathAxis(360);
        strokeWeight(20);
        stroke(160, 200, 255);
        mathPoint(deg, y);
        stroke(160, 255, 255);
        mathPoint(deg, x);

    }
}*/       
