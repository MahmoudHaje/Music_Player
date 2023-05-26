#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <thread>

#define   _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , 				__FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG


using namespace std;
#pragma comment(lib, "Winmm.lib")

DWORD WINAPI threadedPlay(LPVOID lpParameter);
LRESULT CALLBACK handleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Player {
private:
	static HANDLE m_pthread;		// handle to the thread that plays the playlist
	HWND		  m_windowHandle;	// handle to dummy window that handles messages
	WNDCLASSEX    m_wx;
public:
	Player() {
		// open a dummy window to handle messages		
		m_wx.cbSize = sizeof(WNDCLASSEX);
		m_wx.lpfnWndProc = handleMsg;
		m_wx.hInstance = GetModuleHandle(NULL);
		m_wx.lpszClassName = L"DUMMY_CLASS";
		m_windowHandle = 0;

		if (RegisterClassEx(&m_wx)) {
			m_windowHandle = CreateWindowEx(0, L"DUMMY_CLASS", L"dummy_name", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
		}
	}
	~Player() {
		stop();
	}

	static HANDLE get_thread() { return m_pthread; };

	void stop() {
		mciSendString(L"close mp3", NULL, 0, NULL);
		if (m_pthread) {
			CloseHandle(m_pthread);
			m_pthread = 0;
		}
	}

	void play(const string& filename, bool wait = false) {
		stop();
		playMp3(filename, wait);
	}

	void playMp3(const string& filename, bool wait = false) {
		string cmd = "open \"" + filename + "\"" + " type mpegvideo alias mp3";
		wstring stemp = wstring(cmd.begin(), cmd.end());
		LPCWSTR m_sw = stemp.c_str();
		mciSendString(m_sw, NULL, 0, NULL);
		if (wait)
			mciSendString(L"play mp3 wait", NULL, 0, m_windowHandle);
		else
			mciSendString(L"play mp3 notify", NULL, 0, m_windowHandle);
	};

	void playList(vector<string>& playlist) {
		stop();
		DWORD temp;
		m_pthread = CreateThread(0, 0, threadedPlay, &playlist, 0, &temp);
	}

};

HANDLE Player::m_pthread = 0;

LRESULT CALLBACK handleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case MM_MCINOTIFY:
		cout << "Song ended" << endl;
		return 0;
	}

	// Handle any messages the switch statement didn't
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

DWORD WINAPI threadedPlay(LPVOID lpParameter) {
	Player player;
	vector<string>* pl = (vector<string>*)lpParameter;
	vector<string>::const_iterator psong;
	for (psong = (*pl).begin(); psong != (*pl).end(); psong++)
		player.play(*psong, true);
	return 0;
}


#endif// PLAYER_H