#include "qtobjectvisitor.h"

   #include <iostream>
   #include <stdarg.h>

   #include <QtCore/QDebug>
   #include <QtCore/QMetaType>

   Q_DECLARE_METATYPE(QList<QVariantMap>)

   QtObjectVisitor::QtObjectVisitor()
   {
   }

   void QtObjectVisitor::traverse(const QVariant &value, QString &out) const
   {
       switch (value.type()) {
           case QVariant::Map:
               {
                   const QVariantMap object = value.value<QVariantMap>();
                   QMapIterator<QString, QVariant> it(object);
                   while(it.hasNext()) {
                       it.next();
                       out += it.key();
                       out += ": ";
                       traverse(it.value(), out);
                       out += "\n";
                   }
               }
               break;
           case QVariant::List:
               {
                   const QVariantList list = value.value<QVariantList>();
                   QListIterator<QVariant> it(list);
                   int index = 0;
                   while(it.hasNext()) {
                       QVariant value = it.next();
                       out += "item[";
                       out += QString::number(index++);
                       out += "]:\n";
                       traverse(value, out);
                   }
                   out += "\n";
               }
               break;
           case QVariant::String:
               {
                   out += "\"";
                   out += value.toString();
                   out += "\"";
               }
               break;
           case QVariant::Bool:
               {
                   out += value.toString();
                   out += " (Bool)";
               }
               break;
           case QVariant::Int:
               {
                   out += value.toString();
                   out += " (Int)";
               }
               break;
           case QVariant::Double:
               {
                   out += value.toString();
                   out += " (Double)";
               }
               break;
           case QVariant::LongLong:
               {
                   out += value.toString();
                   out += " (LongLong)";
               }
               break;
           default:
               if (value.canConvert< QList<QVariantMap> >())
               {
                   const QList<QVariantMap> list = value.value< QList<QVariantMap> >();
                   QListIterator<QVariantMap> it(list);
                   int index = 0;
                   while(it.hasNext()) {
                       QVariant value = it.next();
                       out += "item[";
                       out += QString::number(index++);
                       out += "]:\n";
                       traverse(value, out);
                   }
                   out += "\n";
                   break;
               }
               qWarning() << "Unsupported property type: " << value.typeName();
               break;
       }
   }

   QString QtObjectVisitor::asString(const QVariant &value) const
   {
       QString out;
       out.reserve(200);
       traverse(value, out);
       return out;
   }
