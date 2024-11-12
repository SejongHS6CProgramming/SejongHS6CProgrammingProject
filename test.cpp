#include <iostream>
#include <locale>
#include <filesystem>
#include <cmath>
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

	//이 코드 프로젝트 전체 포멧을 한국으로 설정, wcin과 wcout의 포멧 한국으로 설정
	std::locale::global(std::locale("ko_KR.UTF-8"));
	std::wcin.imbue(std::locale("ko_KR.UTF-8"));
	std::wcout.imbue(std::locale("ko_KR.UTF-8"));



	/*
	* 
	* 테스트 및 표본 코드
	* 
	*XLDocument test;
	*std::string filePath = "./한국어 학습용 단어 목록.xlsx";
	*
	*test.open(filePath);
	*auto wks = test.workbook().worksheet("한국어학습용어휘등급표 원어 정보 정리 쿼리");
	*
	*std::string vB7 = wks.cell("B7").value();
	*
	*std::cout << vB7 << std::endl;
	*
	*test.close();
	*
	*
	*
	*/


	//국립국어원에서 다운받은 "한국어 학습용 단어 목록" 파일 열기, 
	XLDocument korStudyVocabList;
	std::string filePath_korStudyVocabList = "./한국어 학습용 단어 목록.xlsx";
	korStudyVocabList.open(filePath_korStudyVocabList);

	//엑셀 파일 원본에 따라 시트 설정
	auto kSVL = korStudyVocabList.workbook().worksheet("한국어학습용어휘등급표 원어 정보 정리 쿼리");

	//사용자 입력 문장의 각 글자를 wchar_t로 받아 배열에 저장, length 변수로 문장 길이 설정, spaceBefPeriod로 어절 구분
	wchar_t koreanLetters[1000];
	int length{ 0 };
	int spaceBefPeriod{ 0 };
	int temp{ 0 };

	std::wcin.getline(koreanLetters, 1000, '.');

	while (koreanLetters[length] != '\0' && length < 1000)
		length++;

	while (koreanLetters[length] != '\0' && length < 1000) {
		if (koreanLetters[length] == ' ') {
			temp++;
			spaceBefPeriod = temp;
		}
		length++;
	}
		
	/*

	//문장 분석 시작
	for (int n{ 0 }; n <= length; n++) {
		while (koreanLetters[n] != ' ') {

		}
	}

	*/

	//입력 받은 문장 출력; 테스트용
	for (int i{ 0 }; i <= length; i++) {
		std::wcout << koreanLetters[i];
	}
	std::cout << '.' << '\n';

	std::cout << length << ", " << spaceBefPeriod << std::endl;


	//엑셀 파일 닫기
	korStudyVocabList.close();

	return 0;
}