#pragma once
//��Ϣ���͵Ķ���
enum MsgType
{
	/*client to server*/
	signup,
	signin,
	addContact,

	/*server to client*/
	signupSuccess,
	signupFail,
	signinSuccess,
	signinFail,
	addContactSuccess,
	addContactFail
};