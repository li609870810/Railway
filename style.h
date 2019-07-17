#ifndef STYLE_H
#define STYLE_H
#include<QString>
static QString TableView = /*QTableView 左上角样式*/
        "QTableView QTableCornerButton::section {"
           /*  background: red;
            border: 2px outset red;*/
            "color: red;"\
            "background-color: rgb(64, 64, 64);"\
            "border: 5px solid #f6f7fa;"\
            "border-radius:0px;"\
            "border-color: rgb(64, 64, 64);"\
         "}"\
         "QTableView {"
            "color: white;"                                       /*表格内文字颜色*/
            "gridline-color: black;"                              /*表格内框颜色*/
            "background-color: rgb(108, 108, 108);"               /*表格内背景色*/
            "alternate-background-color: rgb(64, 64, 64);"
            "selection-color: white;"                             /*选中区域的文字颜色*/
            "selection-background-color: rgb(77, 77, 77);"        /*选中区域的背景色*/
            "border: 2px groove gray;"
            "border-radius: 0px;"
            "padding: 2px 4px;"
        "}"

        "QHeaderView {"\
            "color: white;"\
            "font: bold 10pt;"\
            "background-color: rgb(108, 108, 108);"\
            "border: 0px solid rgb(144, 144, 144);"\
            "border:0px solid rgb(191,191,191);"\
            "border-left-color: rgba(255, 255, 255, 0);"\
            "border-top-color: rgba(255, 255, 255, 0);"\
            "border-radius:0px;"\
            "min-height:29px;"\
        "}"\
        \
        "QHeaderView::section {"\
            "color: white;"\
            "background-color: rgb(64, 64, 64);"\
            "border: 5px solid #f6f7fa;"\
            "border-radius:0px;"\
            "border-color: rgb(64, 64, 64);"\
        "}";


#endif // STYLE_H

