#pragma once
//��Ϣ���͵Ķ���
enum MsgType
{
	/*client to server*/
	signup,
	signin,
	addContact,
	getFriendList,

	/*server to client*/
	signupSuccess,
	signupFail,
	signinSuccess,
	signinFail,
	addContactSuccess,
	addContactFail,
	friendListResult
};