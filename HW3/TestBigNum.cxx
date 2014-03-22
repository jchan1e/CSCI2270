#include <iostream>
#include <cstdlib>
#include "BigNum.h"
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <fstream>
#include <cstring>

using namespace std;
using namespace HW3;
ofstream grade;

#define TOTALTESTS 39

int testNo = 0;
int i = 0;
void tester(){
	cerr << "*** Running test " << (testNo + 1) << " *** "<< endl;
	grade.open ("grade.txt", ios::out | ios::app);
	if (testNo >= TOTALTESTS)
	{
		grade.close();
		cerr << "returning";
		return;
	}
	if (testNo == 0){
		//cout << "DEFAULT CONSTRUCTOR TEST" << endl;
		BigNum test1;
		if (strcmp(test1.printBigNum(), "0") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 1){
		//cout << "INT CONSTRUCTOR TESTS" << endl;
		BigNum test2 = 243;
		if (strcmp(test2.printBigNum(), "243") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 2){
		BigNum test3 = -243;
		if (strcmp(test3.printBigNum(), "-243") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 3){
		BigNum test4 = 0;
		if (strcmp(test4.printBigNum(), "0") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 4){
		BigNum test5 = 3458919;
		if (strcmp(test5.printBigNum(), "3458919") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 5){ 
		//cout << "STRING CONSTRUCTOR TESTS" << endl;  
		BigNum test6 = (string) "0";
		if (strcmp(test6.printBigNum(), "0") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 6){
		BigNum test7 = (string) "9997632187383270741827";
		if (strcmp(test7.printBigNum(), "9997632187383270741827") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 7){
		BigNum test8 = (string) "-9997632187383270741827";
		if (strcmp(test8.printBigNum(), "-9997632187383270741827") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 8){
		BigNum test9 = (string) "-0008";
		if (strcmp(test9.printBigNum(), "-8") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 9){
		BigNum test10 = (string) "-3458919728786732132";
		if (strcmp(test10.printBigNum(), "-3458919728786732132") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 10){
		//cout << "COPY CONSTRUCTOR TESTS" << endl;
		BigNum test11a = 243;
		BigNum test11 = test11a;
		if (strcmp(test11.printBigNum(), "243") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 11){
		BigNum test12a = (string) "-3458919728786732132";
		BigNum test12 = test12a;
		if (strcmp(test12.printBigNum(), "-3458919728786732132") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 12){
		BigNum test13a = -243;
		BigNum test13 = test13a;
		if (strcmp(test13.printBigNum(), "-243") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 13){
		BigNum test14a = 3458919;
		BigNum test14 = test14a;
		if (strcmp(test14.printBigNum(), "3458919") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	//cout << "ASSIGNMENT OPERATOR TESTS" << endl;
	if (testNo == 14){
		BigNum test15;
		BigNum test15a = 3458919;
		
		test15 = test15a;
		if (strcmp(test15.printBigNum(), "3458919") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 15){
		BigNum test16;
		BigNum test16a = (string) "-3458919728786732132";
		BigNum test16b = 243;
		
		test16 = test16a = test16b;
		if (strcmp(test16.printBigNum(), "243") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 16){
		BigNum test17;
		BigNum test17a;
		
		test17 = test17a;
		if (strcmp(test17.printBigNum(), "0") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 17){
		BigNum test18;
		BigNum test18a = (string) "-9997632187383270741827";
		test18 = test18a;
		if (strcmp(test18.printBigNum(), "-9997632187383270741827") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 18){
		BigNum test19b = 76878;
		test19b = test19b;
		if (strcmp(test19b.printBigNum(), "76878") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
	if (testNo == 19){
		
// bad Eliz; can't test resize() directly but can force it
//        test18b.resize(200);
		BigNum test20 = (string) "99999999999999999999999999999999";
		BigNum test20b = 1;
		test20b = test20;
		if (strcmp(test20b.printBigNum(), "99999999999999999999999999999999") == 0){
			cerr << "test " << testNo +1 << " passed.\n";
			grade << "test " << testNo +1 << " passed.\n";
		}else{
			grade << "test " << testNo +1 << " failed.\n";
		}
	}
/*    if (testNo == 20){
		BigNum test21;
		cout << "enter a big number\n";
		cin >> test21;
		cout << test21 << endl;
	}*/
		if (testNo == 21){
			BigNum test22a = 123;
			BigNum test22b = 123;
			if (test22a == test22b){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 22){
			BigNum test23a = 123;
			BigNum test23b = -123;
			if (test23a > test23b){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 23){
			BigNum test24a = 123;
			BigNum test24b = 321;
			if (test24a < test24b){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 24){
			BigNum test25a = -123;
			BigNum test25b = -321;
			if (test25a >= test25b){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 25){
			BigNum test26a = -123;
			BigNum test26b = -321;
			if (test26b <= test26a){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 26){
			BigNum test27a = 321;
			BigNum test27b = -321;
			if (test27b != test27a){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 27){
			BigNum test28a = 0;
			BigNum test28b = 0;
			if (test28a + test28b == 0){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 28){
			BigNum test29a = 12345;
			BigNum test29b = 24680;
			if (test29a + test29b == 37025){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 29){
			BigNum test30a = 999999;
			BigNum test30b = 1;
			if (test30a + test30b == 1000000){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 30){
			BigNum test31a = 98674523;
			BigNum test31b = -555555;
			if (test31a + test31b == 98118968){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 31){
			BigNum test32a = -98674523;
			BigNum test32b = -666666;
			if (test32a - test32b == -98007857){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 32){
			BigNum test33a = (string) "5432109876";
			BigNum test33b = (string) "-5678901234";
			BigNum test33 = test33a - test33b;
			if (strcmp(test33.printBigNum(), "11111011110")){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 33){
			BigNum test33a = (string) "0";
			BigNum test33b = (string) "654321";
			BigNum test33 = test33a * test33b;
			if (strcmp(test33.printBigNum(), "0")){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 34){
			BigNum test33a = (string) "1234";
			BigNum test33b = (string) "-654321";
			BigNum test33 = test33a * test33b;
			if (strcmp(test33.printBigNum(), "-807432114")){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 35){
			BigNum test33a = (string) "-10101";
			BigNum test33b = (string) "-10101";
			BigNum test33 = test33a * test33b;
			if (strcmp(test33.printBigNum(), "102030201")){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 36){
			BigNum test33a = (string) "999999";
			BigNum test33b = (string) "999999";
			BigNum test33 = test33a * test33b;
			if (strcmp(test33.printBigNum(), "999998000001")){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 37){
			BigNum test33a = (string) "88888888888888888888";
			BigNum test33b = (string) "99999999999999999999";
			BigNum test33 = test33a * test33b;
			if (strcmp(test33.printBigNum(), "8888888888888888888711111111111111111112")){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		if (testNo == 38){
			BigNum test33a = (string) "1000";
			BigNum test33 = factorial(test33a);
			if (strcmp(test33.printBigNum(), "402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000")){
				cerr << "test " << testNo +1 << " passed.\n";
				grade << "test " << testNo +1 << " passed.\n";
			}else{
				grade << "test " << testNo +1 << " failed.\n";
			}
		}
		grade.close();
		return;
	}

	void termination_handler (int param)
	{
		grade.close();
		if (++testNo <= TOTALTESTS){
			grade.open ("grade.txt", ios::out | ios::app);
			grade << "test " << testNo << " failed.\n";
			cerr << "\n************** test " << testNo << " failed. ***************\n"; 
			if (testNo == TOTALTESTS){
				cerr << "exiting";
				exit(1);
			}
			return tester();
		}
	}
	int main()
	{
		grade.open ("grade.txt");
		grade.close();
		signal (SIGSEGV, termination_handler);
		signal (SIGABRT, termination_handler);
		signal (SIGFPE, termination_handler);
		signal (SIGILL, termination_handler);
		signal (SIGSEGV, termination_handler);
		signal (SIGTERM, termination_handler);
		for (testNo = 0; testNo < TOTALTESTS; testNo++){
			tester();
		}
		grade.close();
		return 0;
	}
