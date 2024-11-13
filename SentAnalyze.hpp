#include <iostream>
#include <string>
#include <locale>
#include <filesystem>
#include <cmath>
#include "openXLSX.hpp"

using namespace OpenXLSX;




class sentAnalysis {
public:

	wchar_t sentDivide(wchar_t sentence[]) {
		//사용자 입력 문장의 각 글자를 wchar_t로 받아 배열에 저장, length 변수로 문장 길이 설정, spaceBefPeriod로 어절 구분

		std::vector<wchar_t> wordSeg;
		int length{ 0 };


		while (sentence[length] != '\0') {
			length++;
		}

		for (int i{ 0 }; i < length; i++) {
			wordSeg.at(i) = sentence[i];
		}




		/*wchar_t koreanLetters[1000];
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

		*/
	};

	wchar_t sentConsistAnalysis(wchar_t sentence[]) {

	};


};

	

		/*
	//문장 분석 시작
	for (int n{ 0 }; n <= length; n++) {
		while (koreanLetters[n] != ' ') {

		}
	}

	*/






	//입력 받은 문장 출력; 테스트용
//	for (int i{ 0 }; i <= length; i++) {
//		std::wcout << koreanLetters[i];
//	}
//	std::cout << '.' << '\n';
//
//	std::cout << length << ", " << spaceBefPeriod << std::endl;
//}
