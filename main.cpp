#include <QtCore>
#include "qcompressor.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

//    QString initialPlainText = "This is a test program for verifying that the QCompressor class works fine!";

//    qDebug() << "Initial plain text is: " << initialPlainText;

//    QByteArray compressed;

//    if(QCompressor::gzipCompress(initialPlainText.toLatin1(), compressed))
//    {
//        qDebug() << "Compressed text length is:" << compressed.length();

//        QByteArray decompressed;

//        if(QCompressor::gzipDecompress(compressed, decompressed))
//        {
//            qDebug() << "Decompressed text is: " << QString::fromLatin1(decompressed);
//        }
//        else
//            qDebug() << "Can't decompress";
//    }
//    else
//        qDebug() << "Can't compress";

        QFile origFile("/home/logan/Desktop/2.txt");
        QFile destFile("/home/logan/Desktop/222_readline.txt.gz");

        QByteArray compressed;

        if (!(origFile.open(QIODevice::ReadOnly) && destFile.open(QIODevice::WriteOnly)))
            return 1;

//        QByteArray ba = origFile.readAll();

//        quint64 index = 677;

//        auto leftBaCompressed = ba.left(index);
//        auto midBaCompressed = ba.mid(index,index);
//        auto rightBaCompressed = ba.right(ba.length()- index*2);


//        if(QCompressor::gzipCompress(leftBaCompressed, compressed)){
//               qDebug() << "Compressed text length is:" << compressed.length();
//               qint64 count = destFile.write(compressed);
//               qDebug() << "Wrote" << count << "compressed bytes";
//               compressed.clear();
//        }

//        if(QCompressor::gzipCompress(midBaCompressed, compressed)){
//               qDebug() << "Compressed text length is:" << compressed.length();
//               qint64 count = destFile.write(compressed);
//               qDebug() << "Wrote" << count << "compressed bytes";
//               compressed.clear();
//        }


//        if(QCompressor::gzipCompress(rightBaCompressed, compressed)){
//               qDebug() << "Compressed text length is:" << compressed.length();
//               qint64 count = destFile.write(compressed);
//               qDebug() << "Wrote" << count << "compressed bytes";
//               compressed.clear();
//        }
        qint64 compressCount = 0;
        qint64 writeCount = 0;

        while(!origFile.atEnd())
        {
            QByteArray ba = origFile.readAll();
            if(QCompressor::gzipCompress(ba, compressed)){

                  compressCount += compressed.length();
                   writeCount +=  destFile.write(compressed);

            }

        }
        qDebug() << "Compressed text length is:" << compressCount;
        qDebug() << "Wrote" << writeCount << "compressed bytes";




}
