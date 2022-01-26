#ifndef PARSETEXT_H
#define PARSETEXT_H

#include <QString>

const std::pair <const QString, const QString> specSymbols [] =
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
    QString getText()const;
private:
    QString text;

};

#endif // PARSETEXT_H
