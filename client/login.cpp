#include "login.h"
#include "ui_login.h"
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    setFixedSize(600, 400);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->loginImgLabel->setPixmap(QPixmap(R"(:/resource/img/login.svg)"));
    ui->settingBtn->setIcon(QIcon(":/resource/icon/shezhi.svg"));
    ui->closeBtn->setIcon(QIcon(":/resource/icon/guanbi.svg"));
    ui->popmenuBtn->setIcon(QIcon(":/resource/icon/xialajiantou.svg"));
    ui->loginBtn->setIcon(QIcon(":/resource/icon/youjiantou.svg"));

    ui->loginStackedWidget->setCurrentIndex(0);

    connect(ui->closeBtn, &QPushButton::clicked, this, &Login::close);
    connect(ui->cancelLoginBtn, &QPushButton::clicked, this, [=]() {
        // todo: cancel login
        ui->loginStackedWidget->setCurrentIndex(0);
    });
    connect(ui->loginBtn, &QToolButton::clicked, this, &Login::handleLogin);
}

Login::~Login()
{
    delete ui;
}

void Login::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_startPos = event->pos();
    }
}

void Login::mouseMoveEvent(QMouseEvent *event)
{
    if (m_dragging) {
        move(event->globalPos() - m_startPos);
    }
}

void Login::mouseReleaseEvent(QMouseEvent *event)
{
    m_dragging = false;
}

void Login::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return) {
        handleLogin();
    }
}

void Login::handleLogin()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    qDebug() << username << password;

    if (username.isEmpty()) {
        // ui->username->setToolTip("账号不能为空");
        QMessageBox::critical(this, tr("username"), tr("username is empty"));
        return;
    }
    if (password.isEmpty()) {
        QMessageBox::critical(this, tr("password"), tr("password is empty"));
        return;
    }

    ui->loginStackedWidget->setCurrentIndex(1);
    ui->photoBtn->setIcon(QIcon(":/resource/icon/photoboy.svg"));
    ui->photoBtn->setIconSize(QSize(80, 80));

    // todo: login
}
