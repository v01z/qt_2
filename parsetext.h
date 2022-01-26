#ifndef PARSETEXT_H
#define PARSETEXT_H

#include <QString>

const std::pair <const std::string, const std::string> specSymbols [] =
{
    { "#@RUB@", "₽" },
    { "#@EUR@", "€" },
    { "#@ART@", "©" },
    { "#@PRML@", "‰" }
};

class ParseText
{
public:
    ParseText();
    bool findAndReplace(QString);
    bool change(QString);
    QString calc(QString);
    QString getText();
private:
    QString text;//Последний текст
    QString preText; //Текст с правкой примера
    qint32 pos;//позиция указателя поиска

};

#endif // PARSETEXT_H
