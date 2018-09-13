#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QDialog>

// ���ǰ������
class QLabel;
class QLineEdit;
class QPushButton;

class LoginDialog: public QDialog
{

    Q_OBJECT // ʹ���źźͲ�ʱ����ʹ�øú�

public:
    explicit LoginDialog(QWidget *prent = nullptr);
    ~LoginDialog();

private:
    // ����һЩ�ؼ��Ķ���ָ��
    // QLable �൱��android�е�textView
    QLabel *userLabel;
    QLabel *pwdLabel;

    // QLineEdit �൱��android�е�EditText
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;

    // QPushButton �൱��android��Button
    QPushButton *loginBtn;
    QPushButton *exitBtn;


private slots:// �����ۺ���
    void login();


};

#endif // LOGINDIALOG_H
