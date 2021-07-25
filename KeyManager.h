#pragma once
#include <bitset>

#define KEYMAX 256
class KeyManager
{
private:
    bitset<KEYMAX> m_keyUp;
    bitset<KEYMAX> m_keyDown;
public:
    KeyManager();
    ~KeyManager();

    HRESULT Initialize();
    void release();

    //Ű�� �ѹ��� ������
    bool isOnceKeyDown(int key);
    //�ѹ� �����ٰ� �ô���
    bool isOnceKeyUp(int key);
    //Ű�� ��� ������ �ִ���
    bool isStayKeyDown(int key);
    //���Ű�� ĸ���� �ѹ���
    bool isToggleKey(int key);
};