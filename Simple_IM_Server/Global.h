#pragma once
#include<qjsonobject.h>
#include<qjsondocument.h>


/**
*Function: getJsonObjectFromString
*Description: ��QStringת��QJsonObject��ʽ
*param;
*jsonQString - QString��ʽ�����JSON
*return:ת��ΪQJsonObject�����JSON����
*/
QJsonObject getJsonObjectFromString(const QString jsonString) {
	QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
	if (jsonDocument.isNull()) {
		qDebug() << "===> please check the string " << jsonString.toLocal8Bit().data();
	}
	QJsonObject jsonObject = jsonDocument.object();
	return jsonObject;
}
