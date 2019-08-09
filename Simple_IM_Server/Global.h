#pragma once
#include<qjsonobject.h>
#include<qjsondocument.h>


/**
*Function: getJsonObjectFromString
*Description: 将QString转成QJsonObject格式
*param;
*jsonQString - QString格式储存的JSON
*return:转化为QJsonObject对象的JSON数据
*/
QJsonObject getJsonObjectFromString(const QString jsonString) {
	QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
	if (jsonDocument.isNull()) {
		qDebug() << "===> please check the string " << jsonString.toLocal8Bit().data();
	}
	QJsonObject jsonObject = jsonDocument.object();
	return jsonObject;
}
