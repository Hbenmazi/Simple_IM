#pragma once
#include<qjsonobject.h>
#include<qjsondocument.h>
#include<qvector.h>

/**
*Function: getJsonObjectFromString
*Description: 将QString转成QJsonObject格式
*param;
*jsonQString - QString格式储存的JSON
*return:转化为QJsonObject对象的JSON数据
*/
QJsonObject getJsonObjectFromString(const QString jsonString) {
	QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8());
	if (jsonDocument.isNull()) {
		qDebug() << "===> please check the string " << jsonString.toUtf8();
	}
	QJsonObject jsonObject = jsonDocument.object();
	return jsonObject;
}

QVector<QJsonObject> getJsonObjectArrayFromString(const QString jsonString) {

	QVector<QJsonObject> JsonArray;
	int count = 0;//计算字符串中有几条信息
	int size = jsonString.size();
	for (int i = 0; i < jsonString.size(); i++)
	{
		if (jsonString.at(i) == '}')
			count++;
	}

	for (int k = 0; k < count; k++)
	{
		QString section = jsonString.section('}', k, k);
		section.append('}');

		QJsonDocument jsonDocument = QJsonDocument::fromJson(section.toUtf8());
		if (jsonDocument.isNull()) {
			qDebug() << "===> please check the string " << section.toUtf8();
		}


		QJsonObject jsonObject = jsonDocument.object();
		JsonArray.append(jsonObject);
	}
	
	return JsonArray;

}

