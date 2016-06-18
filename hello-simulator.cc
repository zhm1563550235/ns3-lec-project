/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

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
