#pragma once

/**
 * @brief �ͻ����������֮�䴫�ݵ���Ϣ����
 * ����:�ͻ��˺ͷ�����������Ϣ��type�ֶε����ͣ��Բ�ͬ����Ϣ����ͬ�Ĵ���
 */
enum MsgType
{
	/*client to server*/
	signup,				//ע������
	signin,				//��¼����
	addContact,			//��Ӻ�������
	getFriendList,		//��ȡ�����б�����
	getLog,				//��ȡ�����¼����
	sendMsg,			//������Ϣ
	preFileTran,		//�����ʼ���ļ����������

	/*server to client*/
	signupSuccess,		//ע��ɹ���Ϣ
	signupFail,			//ע��ʧ����Ϣ
	signinSuccess,		//��¼�ɹ���Ϣ
	signinFail,			//��¼ʧ����Ϣ
	addContactSuccess,	//��Ӻ��ѳɹ���Ϣ
	addContactFail,		//��Ӻ���ʧ����Ϣ
	friendListResult,	//���غ����б���
	logResult			//���������¼���
};