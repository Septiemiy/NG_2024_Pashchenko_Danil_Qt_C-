#include "cryptographer.h"
#include "ui_cryptographer.h"
#include <QRegularExpression>

Cryptographer::Cryptographer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cryptographer)
{
    ui->setupUi(this);

    m_alphabet = "abcdefghijklmnopqrstuvwxyz";

    ui->t_result->setReadOnly(true);

    connect(ui->rb_encrypt, &QRadioButton::toggled, this, &Cryptographer::encrypt);
    connect(ui->rb_decrypt, &QRadioButton::toggled, this, &Cryptographer::decrypt);
    connect(ui->rb_decrypt, &QRadioButton::toggled, this, &Cryptographer::decryptOnClicked);
    connect(ui->rb_encrypt, &QRadioButton::toggled, this, &Cryptographer::encryptOnClicked);
}

QString Cryptographer::getKey()
{
    return ui->e_key->text().toLower();
}

void Cryptographer::makeKeyLetterCountEqualInputedText(QString inputedText)
{
    cleanedInputedText(inputedText);
    QString key = getKey();
    m_equalKeyToInputedText = key;
    for(int index = 0; index < m_cleanedInputedText.size() - key.size(); index++)
    {
        m_equalKeyToInputedText += m_equalKeyToInputedText[index];
    }
}

void Cryptographer::cleanedInputedText(QString inputedText)
{
    m_cleanedInputedText = inputedText.remove(QRegularExpression("[^A-Za-z]"));
}

void Cryptographer::encryptOnClicked()
{
    disconnect(ui->t_inputText, &QTextEdit::textChanged, this, &Cryptographer::decrypt);
    connect(ui->t_inputText, &QTextEdit::textChanged, this, &Cryptographer::encrypt);
    disconnect(ui->e_key, &QLineEdit::textEdited, this, &Cryptographer::decrypt);
    connect(ui->e_key, &QLineEdit::textEdited, this, &Cryptographer::encrypt);
}

void Cryptographer::decryptOnClicked()
{
    disconnect(ui->t_inputText, &QTextEdit::textChanged, this, &Cryptographer::encrypt);
    connect(ui->t_inputText, &QTextEdit::textChanged, this, &Cryptographer::decrypt);
    disconnect(ui->e_key, &QLineEdit::textEdited, this, &Cryptographer::encrypt);
    connect(ui->e_key, &QLineEdit::textEdited, this, &Cryptographer::decrypt);
}

void Cryptographer::encrypt()
{
    if(getKey().isEmpty())
    {
        ui->t_result->setText("Please, input key!");
    }
    else
    {
        m_result = "";
        int letterIndex = 0;
        int keyLetterIndex = 0;
        QString cipherLetter = "";
        QString inputedText = ui->t_inputText->toPlainText();

        makeKeyLetterCountEqualInputedText(inputedText);
        for (int index = 0, indexForKey = 0; index < inputedText.size(); index++, indexForKey++) {
            if(inputedText[index].isLetter())
            {
                bool isUpperLetter = false;
                if(inputedText[index].isUpper()) {
                    isUpperLetter = true;
                    inputedText[index] = inputedText[index].toLower();
                }

                letterIndex = m_alphabet.indexOf(inputedText[index]);
                keyLetterIndex = m_alphabet.indexOf(m_equalKeyToInputedText[indexForKey]);
                cipherLetter = m_alphabet[(letterIndex + keyLetterIndex) % 26];
                if(isUpperLetter)
                    cipherLetter = cipherLetter.toUpper();

                m_result += cipherLetter;
            }
            else
            {
                m_result += inputedText[index];
                indexForKey--;
            }
        }
        ui->t_result->setText(m_result);
    }
}

void Cryptographer::decrypt()
{
    if(getKey().isEmpty())
    {
        ui->t_result->setText("Please, input key!");
    }
    else
    {
        m_result = "";
        int letterIndex = 0;
        int keyLetterIndex = 0;
        QString cipherLetter = "";
        QString inputedText = ui->t_inputText->toPlainText();

        makeKeyLetterCountEqualInputedText(inputedText);
        for (int index = 0, indexForKey = 0; index < inputedText.size(); index++, indexForKey++) {
            if(inputedText[index].isLetter())
            {
                bool isUpperLetter = false;
                if(inputedText[index].isUpper()) {
                    isUpperLetter = true;
                    inputedText[index] = inputedText[index].toLower();
                }

                letterIndex = m_alphabet.indexOf(inputedText[index]);
                keyLetterIndex = m_alphabet.indexOf(m_equalKeyToInputedText[indexForKey]);
                cipherLetter = m_alphabet[(letterIndex - keyLetterIndex + 26) % 26];
                if(isUpperLetter)
                    cipherLetter = cipherLetter.toUpper();

                m_result += cipherLetter;
            }
            else
            {
                m_result += inputedText[index];
                indexForKey--;
            }
        }
        ui->t_result->setText(m_result);
    }
}

Cryptographer::~Cryptographer()
{
    delete ui;
}
