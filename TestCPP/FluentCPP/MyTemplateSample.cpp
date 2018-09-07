#include <stdafx.h>

enum OperationType
{
	ADD,
	EDIT,
	REMOVE,
	FIND
};
using FieldName = string;
using FieldValue = string;
using TableData = vector<pair<FieldName, FieldValue>>;

class TemplateData
{
public:
	void fillData(TableData data);
private:
	TableData data_;
};

template<typename T>
class DbTableHandler(T t)
{
};

// template<class T, OperationType opType>
// class DbTableHandler 
// {
// };



// template<class T, OperationType opType>
// class DbTableHandler
// {
// public:
// 	bool add(T t);
// 	bool edit(T t);
// 	bool remove(T t);
// 	bool find(T t);
// private:
// };
// 
// 
// 
// 
// template<class T, OperationType opType>
// bool DbTableHandler<T, opType>::add(T t)
// {
// 	return false;
// }
// 
// template<class T, OperationType opType>
// bool DbTableHandler<T, opType>::edit(T t)
// {
// 	return false;
// }
// 
// template<class T, OperationType opType>
// bool DbTableHandler<T, opType>::remove(T t)
// {
// 	return false;
// }
// 
// template<class T, OperationType opType>
// bool DbTableHandler<T, opType>::find(T t)
// {
// 	return false;
// }
