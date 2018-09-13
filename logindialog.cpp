#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


/**
 * 这里的prent相当于调用了super函数
 */
LoginDialog::LoginDialog(QWidget *prent):QDialog (prent)
{
    // 创建一个userLabel 这里的this表示父布局是自己
    userLabel = new QLabel(this);
    // 移动到某个位置
    userLabel->move(70,80);
    // 设置显示的文本
    userLabel->setText(tr("user name:"));

    // 登录输入框
    userLineEdit = new QLineEdit(this);
    userLineEdit->move(140,80);
    // 设置hint效果
    userLineEdit->setPlaceholderText(tr("please input user name"));


    // 创建一个userLabel 这里的this表示父布局是自己
    pwdLabel = new QLabel(this);
    // 移动到某个位置
    pwdLabel->move(70,130);
    // 设置显示的文本
    pwdLabel->setText(tr("user pwd:"));

    // 登录输入框
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140,130);
    // 设置hint效果
    pwdLineEdit->setPlaceholderText(tr("please input user pwd"));
    pwdLineEdit->setEchoMode(QLineEdit::Password);



    loginBtn = new QPushButton(this);
    loginBtn->move(50,200);
    loginBtn->setText(tr("login"));


    exitBtn = new QPushButton(this);
    exitBtn->move(210,200);
    exitBtn->setText(tr("exit"));


    /**
     * connect函数用来关联信号和槽的关系
     * 参数1:信号发射的对象这里是loginBtn
     * 参数2：什么时候触发 这里表示点击时
     * 参数3：监听谁发的信号 这里监听LoginDialog
     * 参数4：回调时候回调哪个槽函数 登录回调login槽函数
     */
    connect(loginBtn,&QPushButton::clicked,this,&LoginDialog::login);
    // close 是QWidget里面的函数表示用来关闭控件
    connect(exitBtn,&QPushButton::clicked,this,&LoginDialog::close);

}

LoginDialog::~LoginDialog(){

}

/**
 * 处理槽函数登录的逻辑
 * 构造器中已经关联了信号
 * 所以当点击登录按钮时会回调到这个函数
 *
 * @brief LoginDialog::login
 */
void LoginDialog::login(){
    // 判断登录的用户名和密码是否正确
    if(userLineEdit->text().trimmed()==tr("tianfeng")&&
            pwdLineEdit->text().trimmed()==tr("123456")){
        accept();
    }else{
        QMessageBox::warning(this,tr("warning"),tr("user name or user pwd error！"),QMessageBox::Yes);

        // 清空内容和指定焦点
        userLineEdit->clear();
        pwdLineEdit->clear();
        userLineEdit->setFocus();
    }
}


















