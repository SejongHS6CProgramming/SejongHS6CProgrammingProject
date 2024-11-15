#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale>
#include <cmath>
#include <cwchar>
#include "OpenXLSX.hpp"
#include "SentAnalyze.hpp"

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


	//국립국어원에서 다운받은 "한국어 학습용 단어 목록" 파일 열기, 따로 제작한 "조사 목록" 파일 열기
	XLDocument korStudyVocabList;
	XLDocument korParticleList;
	std::string filePath_korStudyVocabList = "./한국어 학습용 단어 목록.xlsx";
	std::string filePath_korParticleList = "./조사 목록.xlsx";

	korStudyVocabList.open(filePath_korStudyVocabList);
	korParticleList.open(filePath_korParticleList);


	//엑셀 파일 원본에 따라 시트 설정
	auto kSVL = korStudyVocabList.workbook().worksheet("한국어학습용어휘등급표 원어 정보 정리 쿼리");
	auto kPL1 = korParticleList.workbook().worksheet("격조사(접속조사)");
	auto kPL2 = korParticleList.workbook().worksheet("보조사");

	auto rngForkPL1 = kPL1.range(XLCellReference("B1"), XLCellReference("P5"));
	auto rngForkPL2 = kPL2.range(XLCellReference("B1"), XLCellReference("W1"));
	auto rngForkSVL = kSVL.range(XLCellReference("A1"), XLCellReference("B5966"));
	//입력 텍스트 파일 읽고 저장
	std::wstring fileName;
	std::wcin >> fileName;

	std::wifstream inputF(fileName);
	if (!inputF) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	std::wstringstream fileContent;
	fileContent << inputF.rdbuf();
	std::wstring contents = fileContent.str();

	std::vector<wchar_t> wcharArticle(contents.begin(), contents.end());
	wcharArticle.push_back('\0');


	//이차원 벡터를 이용해서 문장의 어절 단위로 각 인덱스에 wchar_t로 넣음
	std::vector<std::vector<wchar_t[20]>> sentPerDiv;
	std::vector<int> lengthOfSentence;
	std::vector<int> temp;


	sentAnalysis sentence;
	sentence.sentDivide();

	int sentRowIdx{ 0 };

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
	
	
	/*
	* 1. paragraph 문장으로 분할
	* 2. 문장 당 독립적인 계산 공간 생성
	* 3. 
	*/

	wchar_t eachWordSeg[20];

	
	
	for (int i{ 0 }; i < sentPerDiv.at(i).size(); i++) {
		int rowSize = sentPerDiv.at(i).size();
		for (int j{ 0 }; j < rowSize; j++) {
			int indexSize = std::wcslen(sentPerDiv.at(i).at(j));
			for (int k{ indexSize - 1 }; k >= 0; k--) {
				/*eachWordSeg[k] = */if (sentPerDiv.at(i).at(j)[k] == cell(rngForkPL1.begin(), rngForkPL1.end(), 0, [](wchar_t a, XLCell& ));
			}
		}
	}
	


	//엑셀 파일 닫기
	korStudyVocabList.close();
	korParticleList.close();
	inputF.close();

	return 0;
}