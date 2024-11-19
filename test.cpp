//C++ 언어에서 사용되는 가장 기본적인 소스 파일 C 언어에서 #include <stdio.h>라고 생각하면 됨
//알아야 하는 것: C++ 언어는 stream이라는 것을 이용하여 내용을 입력받고 출력함. Stream은 입력을 받거나 출력을 할 내용을 저장하는 임시 저장 공간이라고 생각하면 됨
//그리고 이 임시 저장 공간에 있는 내용을 입력 받거나 출력하겠다는 신호를 받으면 stream을 비우고 값을 움직임
//C++ 기본 문법: std::cin은 scanf()라고 생각하면 됨, 그 대신 %d, %s, %c 같은 입력 데이터 타입을 지정해줄 필요가 없고 >> 기호를 사용해서 저장 공간에 저장
//std::cout은 printf(), 이 역시 데이터 타입 지정 필요 X, << 기호로 출력 값 지정
#include <iostream>

#include <cstring>
#include <fstream>
#include <sstream>

//벡터는 배열이라고 생각하면 되는데, 배열의 크기가 유동성이 있음, 즉, 자유롭게 임의로 변경할 수 있음
//문법은 std::vector<데이터 타입> 변수 이름 ex) std::vector(int) test;
#include <vector>
//세계 나라/지역마다 다른 단위/표기법 등을 자동으로 설정해주는 헤더 소스 파일
#include <locale>

//수학적 연산 가능하게 하는 소스 파일
#include <cmath>
//한국어를 더 다양하게 입력받을 수 있도록 하는 소스 파일; 한국어는 유니코드로 입력을 받는데, 기본적인 유니코드로는 한국어 전체를 자유롭게 입력받지 못 할 수 있음
//따라서 extended unicode 라는 것을 사용해서 한국어 입력받음
#include <cwchar>
#include <numeric>
#include <algorithm>

//외부에서 다운받고 설치한 헤더 소스 파일 --> 프로그램이 엑셀 파일 접근/수정 등을 할 수 있게 함
#include "OpenXLSX.hpp"


using namespace OpenXLSX;

//나중에 사용할 함수, 약어는 "한국어 학습용 단어 목록" 및 국립국어원 - 한국어 학습용 어휘 목록(엑셀 파일) 참조

/*
wchar_t interj() {

}

wchar_t natVocab() {

}

wchar_t adj() {

}

wchar_t pron() {

}

wchar_t v() {

}

wchar_t n() {

}

wchar_t auxV() {

}

wchar_t notIden() {

}

wchar_t num() {

}

wchar_t boundN() {

}

wchar_t pred() {

}
*/

int main() {

	//이 코드 프로젝트 전체 포멧을 한국으로 설정
	std::locale::global(std::locale("ko_KR.UTF-8"));
	//wcin은 wide cin 으로, 한국어 입력 받기 위해 extended unicode로 입력을 받겠다는 거, 그리고 입력 받는 형식을 한국 지역으로 설정
	std::wcin.imbue(std::locale("ko_KR.UTF-8"));
	//wcout은 wide cout --> wcin의 출력 버전
	std::wcout.imbue(std::locale("ko_KR.UTF-8"));


	//국립국어원에서 다운받은 "한국어 학습용 단어 목록" 파일 열기, 따로 제작한 "조사 목록" 파일 열기
	//openXLSX 외부 소스파일의 문법, 크게 중요하진 않음
	//바로 아래 두 줄을 통해 엑셀 파일을 열기 전 프로그램 내 파일 명 지정
	XLDocument korStudyVocabList;
	XLDocument korParticleList;
	//아래 두 줄로 파일 이름 설정
	std::string filePath_korStudyVocabList = "./한국어 학습용 단어 목록.xlsx";
	std::string filePath_korParticleList = "./조사 목록.xlsx";
	//아래 두 줄로 위에서 지정한 파일 명에 대응하는 엑셀 파일 지정하여 열음
	korStudyVocabList.open(filePath_korStudyVocabList);
	korParticleList.open(filePath_korParticleList);


	//엑셀 파일 원본에 따라 시트 설정
	//엑셀 파일에서 사용할 sheet 설정
	//위에서 korStudyVocabList로 연 엑셀 파일에서 sheet 이름이 다음과 같은 걸 사용하겠다는 것, kSVL로 지정
	auto kSVL = korStudyVocabList.workbook().worksheet("한국어학습용어휘등급표 원어 정보 정리 쿼리");
	//위의 korParticleList의 엑셀 파일에는 sheet가 두 개 있는데, 이를 각각 kPL1과 kPL2로 지정
	auto kPL1 = korParticleList.workbook().worksheet("격조사(접속조사)");
	auto kPL2 = korParticleList.workbook().worksheet("보조사");

	//각각의 sheet 내에서 사용할 값이 있는 범위 설정,
	// auto 범위이름 = 시트이름.range(시작, 끝);
	auto rngForkPL1 = kPL1.range(XLCellReference("B1"), XLCellReference("P5"));
	auto rngForkPL2 = kPL2.range(XLCellReference("B1"), XLCellReference("W1"));
	auto rngForkSVL = kSVL.range(XLCellReference("A1"), XLCellReference("B5966"));

	//입력 텍스트 파일 읽고 저장
	//wstring은 wide string, 한국어 extended unicode 입력받기 위함
	std::wstring fileName;
	//열을 파일의 이름 입력받음
	std::wcin >> fileName;

	//wifstream은 wide input file stream의 줄임말, inputF라는 파일 포인터 임의로 설정
	std::wifstream inputF(fileName);
	//만약 위에서 입력받은 이름의 파일을 찾지 못한다면 다음을 출력
	if (!inputF) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	 
	//wide string stream, extended unicode를 문장단위로 저장할 저장 공간의 이름 지정
	std::wstringstream fileContent;
	//바로 위의 fileContent에다가 위에서 설정했던 inputF의 내용을 읽어서 저장
	fileContent << inputF.rdbuf();
	//마지막으로, contents라는 저장 공간에다가 바로 위에서 입력받은 값을 저장
	std::wstring contents = fileContent.str();

	//일차원 벡터로 wchar_t 배열 만듬, wchar_t는 한국어를 글자 단위로 입력받아 저장하기 위함.
	//contents에 있는 내용을 처음부터 끝까지 글자 단위로 나누어 배열에 한 글자씩 저장
	std::vector<wchar_t> wcharArticle(contents.begin(), contents.end());
	wcharArticle.push_back('\0');


	//이차원 벡터를 이용해서 문장의 어절 단위로 각 인덱스에 wchar_t로 넣음
	//일반적인 배열은 다음과 같이 이차원으로 만듦: int arr[][];
	//벡터는 벡터 안에 또 다른 벡터를 감싸서 이차원으로 만듦:
	//
	//std::vector<std::vector<int>> vec = {
	//		{1, 2, 3, 4, 5}
	//		{6, 7, 8, 9, 10}
	//		{11, 12, 13, 14, 15}
	// 
	// };
	//
	//위와 같은 형식으로 이루어짐
	//가장 밖에 있는 벡터가 1, 6, 11의 값을 지정하여 배열의 행을 설정
	//안에 있는 벡터가, 행이 1일 경우 뒤에 2, 3, 4, 5 , 행이 6일 경우 뒤에 7, 8, 9, 10 ...
	//과 같은 방식으로 

	//여기에서는 아까 wcharArticle이라는 벡터 배열에 글자 단위로 입력했던 값을 어절별로 나누어 각 인덱스에 저장할 예정
	//sentPerDiv, sentence per division, 어절별로 넣을 이차원 벡터 선언
	std::vector<std::vector<wchar_t>> sentPerDiv;
	//length of sentence, 문장의 길이를 알아내어 한 행에 들어갈 문장의 길이 파악, for 반복문의 조건으로 사용됨
	int lengthOfSentence{};

	//std::vector<int> temp; <-- 원래는 사용했으나 필요 없을 예정

	//행을 위에서 설정했으니, 이번에는 열 설정, 열의 인덱스 번호
	int sentRowIdx{ 0 };
	//아까 wcharArticle에 받은 내용의 길이를 .size()를 통해 얻어 n에 저장
	int n = wcharArticle.size();
	//for 반복문을 실행하는 동안 sentPerDiv에 입력을 한 누적된 문장의 길이 파악, 파악하여 다음에 어디부터 입력을 하면 되는지 앎
	int accumulateOfSentences{ 0 };

	//for loop 실행, i 변수는 벡터 배열의 행의 역할을 할 예정
	for (int i{ 0 }; i < n; i++) {
		//행의 길이만큼 배열의 행 크기 늘림
		//.push_back()이 배열의 크기를 괄호 안에 값으로 늘림 
		//ex) .push_back(' ') 이라 하면 벡터의 길이를 1만큼 늘리는 동시에 그 빈칸에 ' '를 넣음
		//아래의 .push_back(std::vector<wchar_t>()); 는 배열의 크기를 1만큼 늘리고, 늘린 데에 또 다른 벡터 배열을 넣는다는 거임
		sentPerDiv.push_back(std::vector<wchar_t>());
		//문장 길이 파악
		lengthOfSentence++;
		//누적된 문장 길이 파악
		accumulateOfSentences++;
		//만약 배열의 길이를 늘리는 과정에서 wcharArticle의 i 번째 인덱스 값이 . or ! or ? 라면 다음의 if문 실행
		if (wcharArticle.at(i) == '.' || wcharArticle.at(i) == '!' || wcharArticle.at(i) == '?') {
			//위에서 문장의 길이를 파악한 것이 조건으로 반복문 실행
			for (int j{ 0 }; j < lengthOfSentence; j++) {
				//sentPerDiv의 i번 째 행의 벡터 배열을 1만큼 늘리고, 늘린 칸에 wcharArticle의 accumulateOfSentences 인덱스의 값(한 글자)을 넣음
				sentPerDiv[i].push_back(wcharArticle.at(accumulateOfSentences));
			}
			//문장의 길이를 0으로 리셋
			lengthOfSentence = 0;
		}
	}


	//아래는 아직 짜는 중

	/*
	for (int i{ 0 }; i < wcharArticle.size(); i++) {
		lengthOfSentence.push_back(' ');
		if (temp.size() == 0) {
			if (wcharArticle.at(i) == '.' || wcharArticle.at(i) == '?' || wcharArticle.at(i) == '!') {
				for (int j{ 0 }; j < lengthOfSentence.size() - temp.size(); j++) {
					sentPerDiv.at(sentRowIdx++).at(j) = ;
					for (int k{ 0 }; k <= lengthOfSentence.size(); k++) {
						temp.push_back(' ');
					}
				}
			}
		}

		else {
			if (wcharArticle.at(i) == '.' || wcharArticle.at(i) == '?' || wcharArticle.at(i) == '!') {
				for (int j{ 0 }; j < lengthOfSentence.size() - temp.size() - 1; j++) {
					sentPerDiv.at(sentRowIdx++).at(j);
					for (int k{ 0 }; k <= lengthOfSentence.size() - 1; k++) {
						temp.push_back(' ');
					}
				}
			}
		}
	}
	*/
	
	/*
	* 1. paragraph 문장으로 분할
	* 2. 문장 당 독립적인 계산 공간 생성
	* 3. 
	*/

	

	
	/*
	for (int i{ 0 }; i < sentPerDiv.at(i).size(); i++) {
		int rowSize = sentPerDiv.at(i).size();
		for (int j{ 0 }; j < rowSize; j++) {
			int indexSize = std::wcslen(sentPerDiv.at(i).at(j));
			for (int k{ indexSize - 1 }; k >= 0; k--) {
				if (sentPerDiv.at(i).at(j)[k] == std::find_if(rngForkPL1.begin(), rngForkPL1.end(), 0)
			}
		}
		*/
	}
	









	