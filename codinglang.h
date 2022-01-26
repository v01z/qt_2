#ifndef CODINGLANG_H
#define CODINGLANG_H

#include <QString>
#include <QIcon>

class CodingLang
{
    private:
        QString name;
        QIcon icon;
    public:
        CodingLang();
        CodingLang(const QString&, const QIcon&);

        const QString &getName() const;
        const QIcon &getIcon() const;

};

#endif // CODINGLANG_H
