#include <Winsock2.h>
#include "iphlpapi.h"
#include <iostream>
using namespace std;

#pragma comment(lib,"Iphlpapi.lib")
#pragma comment(lib,"Ws2_32.lib")

typedef HANDLE (WINAPI* ICMPCREATEFILE)(VOID);
typedef BOOL (WINAPI* ICMPCLOSEHANDLE)(HANDLE);
typedef DWORD (WINAPI* ICMPSENDECHO)(HANDLE, DWORD, LPVOID, WORD,PIP_OPTION_INFORMATION, LPVOID, DWORD, DWORD);

//定义三个指针函数
ICMPCREATEFILE pIcmpCreateFile;
ICMPCLOSEHANDLE pIcmpCloseHandle;
ICMPSENDECHO pIcmpSendEcho;

// 函数功能：初始化ICMP函数：
BOOL InitIcmp()
{
    HINSTANCE hIcmp = LoadLibrary("ICMP.DLL");
    if(hIcmp==NULL)
    {
        return false;
    }
    pIcmpCreateFile = (ICMPCREATEFILE)GetProcAddress(hIcmp,"IcmpCreateFile");
    pIcmpCloseHandle = (ICMPCLOSEHANDLE)GetProcAddress(hIcmp,"IcmpCloseHandle");
    pIcmpSendEcho = (ICMPSENDECHO)GetProcAddress(hIcmp,"IcmpSendEcho");
    if ((pIcmpCreateFile == NULL)||(pIcmpCloseHandle == NULL)||(pIcmpSendEcho == NULL))
        return false;
    return true;
}


// 函数功能：判断是否能ping通IP
// 函数参数：IP地址或域名
BOOL ICMPPing(char* host)
{
    DWORD timeOut=1000;                                              //设置超时
    ULONG hAddr=inet_addr(host);                                     //如果是IP地址就直接转换
    if(hAddr==INADDR_NONE)
    {
        hostent* hp=gethostbyname(host);                             //如果是域名就用DNS解析出IP地址
        if(hp)
            memcpy(&hAddr,hp->h_addr_list,hp->h_length);             //IP地址
        else
        {
            return false;
        }
    }
    HANDLE hIp=pIcmpCreateFile();
    IP_OPTION_INFORMATION ipoi;
    memset(&ipoi,0,sizeof(IP_OPTION_INFORMATION));
    ipoi.Ttl =128;                  //Time-To-Live

    unsigned char pSend[36];                                                                   //发送包
    memset(pSend,'E',32);

    int repSize=sizeof(ICMP_ECHO_REPLY)+32;
    unsigned char pReply[100];                                                                 //接收包
    ICMP_ECHO_REPLY* pEchoReply=(ICMP_ECHO_REPLY*)pReply;

    DWORD nPackets=pIcmpSendEcho(hIp,hAddr,pSend,32,&ipoi,pReply,repSize,timeOut);             //发送ICMP数据报文

    if(pEchoReply->Status!=0)                                                                  //超时，可能是主机禁用了ICMP 或者目标主机不存在
    {
        pIcmpCloseHandle(hIp);
        return false;
    }

    pIcmpCloseHandle(hIp);
    return true;
}

int main()
{
    InitIcmp();
    cout<<ICMPPing("172.16.5.101");
    cout<<ICMPPing("172.16.5.106");
    return 0;
}
////============================================================================
//// Name        : CppUtils.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
////#include <iostream>
////#include <string>
//
////
////#include "../tests/student/Student.h"
////#include "../tests/chooser/Person.h"
////#include "../utils/SortUtils.h"
////#include "../utils/ArrayUtils.h"
////#include "../classes/Map.h"
////#include "../classes/Chooser.h"
//
//#include <cstring>
//#include <algorithm>
//#include <list>
//#include <map>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int main() {
//	std::cout<<system("ping -c 1 -w 1 172.16.5.100");
//}
////////////////////////////////////////////////////////////////
//	Student student;
//	Student student1;
//	student.setName("张三");
//	student.setAge(18);
//	student.setSex(Sex::FEMALE);
//	student.setScore(99.5);
//	SchoolInfo schoolInfo;
//	schoolInfo.mGrade=6;
//	schoolInfo.mClass=10;
//	schoolInfo.mDegree=Degree::SENIOR;
//	student.setSchool(schoolInfo);
//
//	student1=student.copy();
//	student1.setName("李四");
//
//	std::list<Student> studentList;
//	studentList.push_back(student);
//	studentList.push_back(student1);
//	//studentList.sort(student.cmpAsc());

//	student.show();
//	student1.show();
//	cout<<"list size:"<<studentList.size()<<endl;
/////////////////////////////////////////////////////////////////
//int sort[]={6,2,7,3,8,9};
//	char sortc[]={'a','z','k','b','g'};
//	int res[6]={0};
//	char resc[5]={0};
//	int tmp[6]={0};
//	char tmpc[5]={0};
//
//	memcpy(tmp,sort,sizeof(sort));
//	memcpy(tmpc,sortc,sizeof(sortc));
//	QuickSort(tmp);
//	QuickSort(tmpc);
//	cout<<"QuickSort :";
//	ArrayShow(tmp);
//	cout<<endl;
//	cout<<"QuickSortc:";
//	ArrayShow(tmpc);
//	cout<<endl;
//
//	memcpy(tmp,sort,sizeof(sort));
//	memcpy(tmpc,sortc,sizeof(sortc));
//	MergeSort(tmp,res);
//	MergeSort(tmpc,resc);
//	cout<<"MergeSort :";
//	ArrayShow(res);
//	cout<<endl;
//	cout<<"MergeSortc:";
//	ArrayShow(resc);
//	cout<<endl;
//
//
//	memcpy(tmp,sort,sizeof(sort));
//	memcpy(tmpc,sortc,sizeof(sortc));
//	HeapSort(tmp);
//	HeapSort(tmpc);
//	cout<<"HeapSort :";
//	ArrayShow(tmp);
//	cout<<endl;
//	cout<<"HeapSortc:";
//	ArrayShow(tmpc);
//	cout<<endl;
//
//	memcpy(tmp,sort,sizeof(sort));
//	memcpy(tmpc,sortc,sizeof(sortc));
//	SelectionSort(tmp);
//	SelectionSort(tmpc);
//	cout<<"SelectionSort :";
//	ArrayShow(tmp);
//	cout<<endl;
//	cout<<"SelectionSortc:";
//	ArrayShow(tmpc);
//	cout<<endl;
//
//	memcpy(tmp,sort,sizeof(sort));
//	memcpy(tmpc,sortc,sizeof(sortc));
//	ShellSort(tmp);
//	ShellSort(tmpc);
//	cout<<"ShellSort :";
//	ArrayShow(tmp);
//	cout<<endl;
//	cout<<"ShellSortc:";
//	ArrayShow(tmpc);
//	cout<<endl;
///////////////////////////////////////////////////////
