#pragma once

/**
 * @brief 客户端与服务器之间传递的消息类型
 * 描述:客户端和服务器根据消息的type字段的类型，对不同的消息做不同的处理
 */
enum MsgType
{
	/*client to server*/
	signup,				//注册请求
	signin,				//登录请求
	addContact,			//添加好友请求
	getFriendList,		//获取好友列表请求
	getLog,				//获取聊天记录请求
	sendMsg,			//发送消息
	preFileTran,		//请求初始化文件传输服务器

	/*server to client*/
	signupSuccess,		//注册成功消息
	signupFail,			//注册失败消息
	signinSuccess,		//登录成功消息
	signinFail,			//登录失败消息
	addContactSuccess,	//添加好友成功消息
	addContactFail,		//添加好友失败消息
	friendListResult,	//返回好友列表结果
	logResult			//返回聊天记录结果
};