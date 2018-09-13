#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


/**
 * �����prent�൱�ڵ�����super����
 */
LoginDialog::LoginDialog(QWidget *prent):QDialog (prent)
{
    // ����һ��userLabel �����this��ʾ���������Լ�
    userLabel = new QLabel(this);
    // �ƶ���ĳ��λ��
    userLabel->move(70,80);
    // ������ʾ���ı�
    userLabel->setText(tr("user name:"));

    // ��¼�����
    userLineEdit = new QLineEdit(this);
    userLineEdit->move(140,80);
    // ����hintЧ��
    userLineEdit->setPlaceholderText(tr("please input user name"));


    // ����һ��userLabel �����this��ʾ���������Լ�
    pwdLabel = new QLabel(this);
    // �ƶ���ĳ��λ��
    pwdLabel->move(70,130);
    // ������ʾ���ı�
    pwdLabel->setText(tr("user pwd:"));

    // ��¼�����
    pwdLineEdit = new QLineEdit(this);
    pwdLineEdit->move(140,130);
    // ����hintЧ��
    pwdLineEdit->setPlaceholderText(tr("please input user pwd"));
    pwdLineEdit->setEchoMode(QLineEdit::Password);



    loginBtn = new QPushButton(this);
    loginBtn->move(50,200);
    loginBtn->setText(tr("login"));


    exitBtn = new QPushButton(this);
    exitBtn->move(210,200);
    exitBtn->setText(tr("exit"));


    /**
     * connect�������������źźͲ۵Ĺ�ϵ
     * ����1:�źŷ���Ķ���������loginBtn
     * ����2��ʲôʱ�򴥷� �����ʾ���ʱ
     * ����3������˭�����ź� �������LoginDialog
     * ����4���ص�ʱ��ص��ĸ��ۺ��� ��¼�ص�login�ۺ���
     */
    connect(loginBtn,&QPushButton::clicked,this,&LoginDialog::login);
    // close ��QWidget����ĺ�����ʾ�����رտؼ�
    connect(exitBtn,&QPushButton::clicked,this,&LoginDialog::close);

}

LoginDialog::~LoginDialog(){

}

/**
 * ����ۺ�����¼���߼�
 * ���������Ѿ��������ź�
 * ���Ե������¼��ťʱ��ص����������
 *
 * @brief LoginDialog::login
 */
void LoginDialog::login(){
    // �жϵ�¼���û����������Ƿ���ȷ
    if(userLineEdit->text().trimmed()==tr("tianfeng")&&
            pwdLineEdit->text().trimmed()==tr("123456")){
        accept();
    }else{
        QMessageBox::warning(this,tr("warning"),tr("user name or user pwd error��"),QMessageBox::Yes);

        // ������ݺ�ָ������
        userLineEdit->clear();
        pwdLineEdit->clear();
        userLineEdit->setFocus();
    }
}


















