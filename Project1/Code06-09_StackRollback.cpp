#include "Common.h"
#include <Windows.h>
#include <stdlib.h>

int S_SIZE;
Array <string> stack;
int top = -1;

bool isStackFull() // 스택이 꽉 찼는지 확인하는 함수
{
    if (top >= (S_SIZE - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isStackEmpty() // 스택이 비었는지 확인하는 함수
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(string data) // 스택에 데이터를 삽입하는 함수
{
    if (isStackFull())
    {
        println("스택이 꽉 찼습니다. ");
        return;
    }
    top++;
    stack[top] = data;
}

string pop() // 스택에서 데이터를 추출하는 함수
{
    if (isStackEmpty())
    {
        println("스택이 비었습니다. ");
        return "None";
    }
    string data = stack[top];
    stack[top] = "None";
    top--;
    return data;
}

string peek()
{
    if (isStackEmpty())
    {
        println("스택이 비었습니다. ");
        return "None";
    }
    return stack[top];
}

int main()
{
    S_SIZE = 100;
    for (int i = 0; i < S_SIZE; i++)
        stack.push_back("None");

    string browser = "\"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe\" ";
    Array <string> urls = { "naver.com", "daum.net", "nate.com" };

    for (int i = 0; i < len(urls); i++)
    {
        string url = urls[i];
        push(url);
        string cmd = browser + url;
        //system(cmd.c_str());
        print(url + "-->");
        Sleep(1000);
    }
    println("방문 종료");
    Sleep(5000);

    while (true)
    {
        string url = pop();
        if (url == "None")
            break;
        string cmd = browser + url;
        system(cmd.c_str());
        print(url + "-->");
        Sleep(1000);
    }
    println("방문 종료");
    return 0;
}