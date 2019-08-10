#pragma once
//消息类型的定义
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