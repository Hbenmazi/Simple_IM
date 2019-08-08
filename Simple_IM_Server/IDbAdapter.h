#pragma once

#include <QtSql>

class IDbAdapter
{
public:
	IDbAdapter();

	~IDbAdapter();

private:
	static IDbAdapter* m_instanse();
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
};

