# NS3 软件培训第一讲报告
##实验内容
1. 用命令行读入自己的学号和姓名参数以及输出频率，周期性输出姓名和学号。
2. 利用unix实用工具wc(word count)统计输出的总次数。
3. 利用unix实用工具grep筛选特定信息。
##实验过程
1. 用命令行读入自己的学号和姓名参数以及输出频率，周期性输出姓名和学号。程序如下：
```javascript
#include "ns3/core-module.h"
 #include <iostream>
 using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("HelloSimulator");
	static void printHello(std::string word1,std::string word2,double delay)
        { 
	           std::cout<<Simulator::Now()<<"Hello"<<word1+" "<<word2<<std::endl;
             Simulator::Schedule(Seconds(delay),&printHello,word1,word2,delay);
         }

int 
main (int argc, char *argv[])
{
	CommandLine cmd;
	std::string name;
	std::string number;
  double delay;
	cmd.AddValue ("name", "my name", name);
	cmd.AddValue ("number", "my number", number);
  cmd.AddValue ("delay","my delay",delay);
	cmd.Parse(argc,argv);

	printHello(name,number,delay);
	Simulator::Stop(Seconds(5));
	Simulator::Run ();
	Simulator::Destroy ();
}
```

声明三个变量，分别保存姓名、学号和输出频率，再调用函数Parse。其中程序

``Int main (int argc, char *argv[])
{
   . . . . . .
	CommandLine cmd;
   cmd.Parse(argc,argv);
   . . . . . .
}``

代表了用户可以用命令行来访问代码中的全局变量和ns-3中的属性系统。
在命令行中输入：

``cmd:
./waf --run="scratch/hello-simulator --name=zhm --number=20134368 --delay=0.5"
``

输出结果如下所示。首先输出当前时间，然后依次Hello名字和学号。延迟为0.5，运行5s结束，所以输出了10次。
![命令行读入参数]（http://7xrn7f.com1.z0.glb.clouddn.com/16-6-18/13506989.jpg）
在命令行中输入：

``cmd:
./waf --run="scratch/hello-simulator --name=zhm --number=20134368 --delay=0.5”|wc
``

统计了输出的行数、字符数和字节数，分别是10、20和320。因为延迟时间是0.5，程序中运行5s停止运行（Simulator::Stop(Seconds(5));），所以输出次数为10，可见输出结果正确，结果如下：
![统计输出的总次数]（http://7xrn7f.com1.z0.glb.clouddn.com/16-6-18/75652916.jpg）
在命令行中输入：

``cmd:
./waf --run="scratch/hello-simulator --name=zhm --number=20134368 --delay=1"|grep”+2” 
``

筛选带有+2的信息，可以看到输出了当前时间为+2000000000.0nsHellozhm 20134368的信息，实现的特定信息的筛选。结果如下：
！[筛选信息]（http://7xrn7f.com1.z0.glb.clouddn.com/16-6-18/37252459.jpg）
