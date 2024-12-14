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
#include <codecvt>

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


	/*===========================================================================================================*/

	std::fstream kPL_sheet1("조사 목록-격조사.csv");
	

	kPL_sheet1.seekg(0, std::ios::end);
	std::streamsize kPL_sheet1_fileSize = kPL_sheet1.tellg();
	kPL_sheet1.seekg(0, std::ios::beg);

	char* kPL1_inputFBuffer = new char[kPL_sheet1_fileSize];
	kPL_sheet1.read(kPL1_inputFBuffer, kPL_sheet1_fileSize);

	char* context_kPL1 = nullptr;
	char* kPL1_DivPtr = strtok_s(kPL1_inputFBuffer, "\n", &context_kPL1);
	std::vector<std::vector<char*>> kPL1_Div;

	while (kPL1_DivPtr != nullptr) {
		std::vector<char*> token;
		char* wordNPartsOfSpeech_Div = strtok_s(kPL1_DivPtr, ",", &context_kPL1);
		while (wordNPartsOfSpeech_Div != nullptr) {
			token.push_back(wordNPartsOfSpeech_Div);
			wordNPartsOfSpeech_Div = strtok_s(nullptr, ",", &context_kPL1);
		}
		kPL1_Div.push_back(token);
		kPL1_DivPtr = strtok_s(nullptr, "\n", &context_kPL1);
	}

	/*===========================================================================================================*/

	std::fstream kPL_sheet2("조사 목록-보조사.csv");


	kPL_sheet2.seekg(0, std::ios::end);
	std::streamsize kPL_sheet2_fileSize = kPL_sheet2.tellg();
	kPL_sheet2.seekg(0, std::ios::beg);

	char* kPL2_inputFBuffer = new char[kPL_sheet2_fileSize];
	kPL_sheet2.read(kPL2_inputFBuffer, kPL_sheet2_fileSize);

	char* context_kPL2 = nullptr;
	char* kPL2_DivPtr = strtok_s(kPL2_inputFBuffer, "\n", &context_kPL2);
	std::vector<std::vector<char*>> kPL2_Div;

	while (kPL2_DivPtr != nullptr) {
		std::vector<char*> token;
		char* wordNEmphasisNYield_Div = strtok_s(kPL2_DivPtr, ",", &context_kPL2);
		while (wordNEmphasisNYield_Div != nullptr) {
			token.push_back(wordNEmphasisNYield_Div);
			wordNEmphasisNYield_Div = strtok_s(nullptr, ",", &context_kPL2);
		}
		kPL2_Div.push_back(token);
		kPL2_DivPtr = strtok_s(nullptr, "\n", &context_kPL2);
	}

	/*===========================================================================================================*/

	std::fstream rieulEndSyllable("ㄹ받침 한글 음절 유니코드.txt");


	rieulEndSyllable.seekg(0, std::ios::end);
	std::streamsize rieulEndSyllable_fileSize = rieulEndSyllable.tellg();
	rieulEndSyllable.seekg(0, std::ios::beg);

	char* rieulEndSyllable_inputFBuffer = new char[rieulEndSyllable_fileSize];
	rieulEndSyllable.read(rieulEndSyllable_inputFBuffer, rieulEndSyllable_fileSize);

	char* context_rieulEndSyllable = nullptr;
	char* rieulEndSyllable_DivPtr = strtok_s(rieulEndSyllable_inputFBuffer, "\n", &context_rieulEndSyllable);
	std::vector<std::vector<char*>> rieulEndSyllable_Div;

	while (rieulEndSyllable_DivPtr != nullptr) {
		std::vector<char*> token;
		char* wordNHex_Div = strtok_s(rieulEndSyllable_DivPtr, ",", &context_rieulEndSyllable);
		while (wordNHex_Div != nullptr) {
			token.push_back(wordNHex_Div);
			wordNHex_Div = strtok_s(nullptr, ",", &context_rieulEndSyllable);
		}
		rieulEndSyllable_Div.push_back(token);
		rieulEndSyllable_DivPtr = strtok_s(nullptr, "\n", &context_rieulEndSyllable);
	}

	/*===========================================================================================================*/


	//입력 텍스트 파일 읽고 저장
	//wstring은 wide string, 한국어 extended unicode 입력받기 위함
	std::string fileName;
	//열을 파일의 이름 입력받음
	std::cin >> fileName;
	//wifstream은 wide input file stream의 줄임말, inputF라는 파일 포인터 임의로 설정
	//std::ifstream inputF(fileName);
	//만약 위에서 입력받은 이름의 파일을 찾지 못한다면 다음을 출력


	std::ifstream inputF(fileName, std::ios::binary);
	if (!inputF) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	inputF.seekg(0, std::ios::end);
	std::streamsize fileSize = inputF.tellg();
	inputF.seekg(0, std::ios::beg);

	char* inputFBuffer = new char[fileSize];
	inputF.read(inputFBuffer, fileSize);

	/*
	이차원 벡터를 이용해서 문장의 어절 단위로 각 인덱스에 wchar_t로 넣음
	일반적인 배열은 다음과 같이 이차원으로 만듦: int arr[][];
	벡터는 벡터 안에 또 다른 벡터를 감싸서 이차원으로 만듦:
	
	std::vector<std::vector<int>> vec = {
		{1, 2, 3, 4, 5}
		{6, 7, 8, 9, 10}
		{11, 12, 13, 14, 15}
	 
	};
	
	위와 같은 형식으로 이루어짐
	가장 밖에 있는 벡터가 1, 6, 11의 값을 지정하여 배열의 행을 설정
	안에 있는 벡터가, 행이 1일 경우 뒤에 2, 3, 4, 5 , 행이 6일 경우 뒤에 7, 8, 9, 10 ...
	과 같은 방식으로 
	*/
	int rowNum{ 0 };
	int colNum{ 0 };
	char* context = nullptr;

	char* charArticlePtr = strtok_s(inputFBuffer, ".!?", &context);

	std::vector<std::vector<char*>> articleDiv;

	while (charArticlePtr != nullptr) {
		std::vector<char*> token;
		char* sentencePtr = strtok_s(charArticlePtr, " ", &context);
		while (sentencePtr != nullptr) {
			token.push_back(sentencePtr);
			sentencePtr = strtok_s(nullptr, " ", &context);
			colNum++;
		}
		articleDiv.push_back(token);
		charArticlePtr = strtok_s(nullptr, ".!?", &context);
		rowNum++;	
	}

	/*for (int i{ 0 }; i < articleDiv.size(); i++) {
		for (int j{ 0 }; j < articleDiv.at(i).size(); j++) {
			char* target = strchr(articleDiv.at(i).at(j), );
		}
	}*/

	std::cout << '\n';
	std::cout << articleDiv.at(0).at(0) << ' ' << articleDiv.at(0).at(1) << ' ' << articleDiv.at(0).at(2) << std::endl;
	std::cout << kPL2_Div.at(0).at(0) << ' ' << kPL2_Div.at(0).at(1) << ' ' << kPL2_Div.at(0).at(2) << std::endl;
	


	/*
	* 1. paragraph 문장으로 분할
	* 2. 문장 당 독립적인 계산 공간 생성
	* 3. 
	*/

	std::wstring koreanText = L"갈갤걀걜걸겔결곌";

	for (wchar_t ch : koreanText) {
		
		std::wcout << ch << ": U+" << (int)ch << std::endl;
	}

	//'ㄹ' 받침만 있는 한글 음절은 28 차이가 남


	delete[] inputFBuffer;
	inputF.close();

	return 0;
	}
	









	