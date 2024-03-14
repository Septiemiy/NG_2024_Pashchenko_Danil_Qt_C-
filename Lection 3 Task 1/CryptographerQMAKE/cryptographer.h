#ifndef CRYPTOGRAPHER_H
#define CRYPTOGRAPHER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Cryptographer;
}
QT_END_NAMESPACE

class Cryptographer : public QMainWindow
{
    Q_OBJECT

public:
    Cryptographer(QWidget *parent = nullptr);
    ~Cryptographer();

private:
    QString getKey();
    void makeKeyLetterCountEqualInputedText(QString inputedText);
    void cleanedInputedText(QString inputedText);

private slots:
    void encryptOnClicked();
    void decryptOnClicked();
    void encrypt();
    void decrypt();

private:
    Ui::Cryptographer *ui;
    QString m_alphabet;
    QString m_result;
    QString m_equalKeyToInputedText;
    QString m_cleanedInputedText;
};
#endif // CRYPTOGRAPHER_H
