#pragma once
//��Ϣ���͵Ķ���
enum MsgType
{
	/*client to server*/
	signup,
	signin,

	/*server to client*/
	signupSuccess,
	signupFail,
	signinSuccess,
	signinFail
};