#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <string>

bool getTips(QString zText,int zoneNum, int upNum);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString zText;

    //QString zText = {"%Zaa22%Z111a 2%Z22 %Z 33aa%Z1%Z%Z%Z%Z"};

    int ile_stref = 10;
    int upNum  = 0;

    for(int z = 1; z < ile_stref ; z++ ){
      QTextStream stream(stdin);
      zText = stream.readLine();
      if(getTips(zText,z, upNum))upNum++;
      else upNum = 0;
    }
    return a.exec();
}

bool getTips(QString zText,int zoneNum, int upNum)
{
    QString numStr{};
    int numInt{};
    QString charZ = "%Z";
    bool znacznik = false;
    bool upsign = false;
    int i = 0;

    for( i = zText.indexOf(charZ, i) ; i > -1 && i < zText.size()  ; i++){   //PS 22.11.2021

        if((zText[i+2].isDigit() || znacznik == true ) )
        {
            numStr.append((zText[i+2]));
            znacznik = true;
            upsign = true;
        }
        if(!(zText[i+3].isDigit()) && znacznik == true)
        {
            numInt = numStr.toInt();
            zText.replace(charZ + numStr , QString::number(numInt + upNum));
            numStr.clear();
            i = (zText.indexOf(charZ, (i))-1);
            znacznik = false;
            if(i==-2) break;
        };
    }
    zText.replace(charZ,QString::number(zoneNum)); //PS 17.11.2021
    qDebug() << zText;
    return upsign ;
}
