#pragma once
//��Ϣ���͵Ķ���
enum MsgType
{
	/*client to server*/
	signup,
	signin,
	addContact,
	getFriendList,
	getLog,
	sendMsg,

	/*server to client*/
	signupSuccess,
	signupFail,
	signinSuccess,
	signinFail,
	addContactSuccess,
	addContactFail,
	friendListResult,
	logResult
};