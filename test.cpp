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
#include <filesystem>

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


std::string remove_num(const std::string& input) {
	std::string result;
	for (char ch : input) {
		if (!std::isdigit(ch)) {
			result += ch;
		}
	}
	return result;
}

std::vector<std::string> split_by_delimiters(const std::string& input, const std::string& delimiters) {
	std::vector<std::string> tokens;

	size_t start{ 0 }; 
	size_t end{ input.find_first_of(delimiters) };

	while (end != std::string::npos) {
		if (end > start) {
			tokens.push_back(input.substr(start, end - start));
		}
		start = end + 1;
		end = input.find_first_of(delimiters, start);
	}

	if (start < input.size()) {
		tokens.push_back(input.substr(start));
	}

	return tokens;
}

// char* customStrtok(char* str, const char* delimiters) {
//     static char* current;
//     if (str != nullptr) {
//         current = str;  // Initialize with the input string
//     }
//     if (current == nullptr) {
//         return nullptr;  // End of tokens
//     }

//     // Skip leading delimiters and spaces
//     while (*current && (std::strchr(delimiters, *current) || std::isspace(*current))) {
//         current++;
//     }

//     if (*current == '\0') {
//         return nullptr;  // No more tokens
//     }

//     char* tokenStart = current;  // Mark the beginning of the token

//     // Find the next delimiter
//     while (*current && !std::strchr(delimiters, *current)) {
//         current++;
//     }

//     if (*current) {
//         *current = '\0';  // Null-terminate the token
//         current++;        // Move to the next position
//     } else {
//         current = nullptr;  // End of tokens
//     }

//     return tokenStart;
// }


class subject {
public:
	
};

class object {

};

class verb {

};

class adverb {

};





int main() {
	//이 코드 프로젝트 전체 포멧을 한국으로 설정
	std::locale::global(std::locale("ko_KR.UTF-8"));
	//wcin은 wide cin 으로, 한국어 입력 받기 위해 extended unicode로 입력을 받겠다는 거, 그리고 입력 받는 형식을 한국 지역으로 설정
	std::wcin.imbue(std::locale("ko_KR.UTF-8"));
	//wcout은 wide cout --> wcin의 출력 버전
	std::wcout.imbue(std::locale("ko_KR.UTF-8"));

	std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
	

	/*===========================================================================================================*/
	std::cout << "Operation start kPL1" << std::endl;

	//koreanParticleList_Sheet1
	std::ifstream kPL_sheet1("C:\\Users\\hijun\\source\\repos\\SejongHS6CProgrammingProject\\resourcesForCode\\조사 목록-격조사.csv");
	if (kPL_sheet1.is_open()) {
		std::cout << "File successfully opened kPL1" << std::endl;
	}
	else {
		std::cerr << "Failed to open file kPL1" << std::endl;
	}

	kPL_sheet1.seekg(0, std::ios::end);
	std::streamsize kPL_sheet1_fileSize = kPL_sheet1.tellg();
	kPL_sheet1.seekg(0, std::ios::beg);
	
	char* kPL1_inputFBuffer = new char[kPL_sheet1_fileSize];
	kPL_sheet1.read(kPL1_inputFBuffer, kPL_sheet1_fileSize);

	char* context_kPL1_file = nullptr;
	char* kPL1_DivPtr = strtok_s(kPL1_inputFBuffer, "\n", &context_kPL1_file);
	std::vector<std::vector<char*>> kPL1_Div;

	while (kPL1_DivPtr != nullptr) {
		std::vector<char*> token;
		char* context_kPL1_line = nullptr;
		char* wordNPartsOfSpeech_Div = strtok_s(kPL1_DivPtr, ",", &context_kPL1_line);
		while (wordNPartsOfSpeech_Div != nullptr) {
			token.push_back(wordNPartsOfSpeech_Div);
			wordNPartsOfSpeech_Div = strtok_s(nullptr, ",", &context_kPL1_line);
		}
		kPL1_Div.push_back(token);
		kPL1_DivPtr = strtok_s(nullptr, "\n", &context_kPL1_file);
	}
	std::cout << "Finished operation kPL1\n";
	/*===========================================================================================================*/
	//koreanParticleLis_Sheet2
	std::ifstream kPL_sheet2("C:\\Users\\hijun\\source\\repos\\SejongHS6CProgrammingProject\\resourcesForCode\\조사 목록-보조사.csv");
	if (kPL_sheet2.is_open()) {
		std::cout << "File successfully opened kPL2" << std::endl;
	}
	else {
		std::cerr << "Failed to open file kPL2" << std::endl;
	}

	kPL_sheet2.seekg(0, std::ios::end);
	std::streamsize kPL_sheet2_fileSize = kPL_sheet2.tellg();
	kPL_sheet2.seekg(0, std::ios::beg);

	char* kPL2_inputFBuffer = new char[kPL_sheet2_fileSize];
	kPL_sheet2.read(kPL2_inputFBuffer, kPL_sheet2_fileSize);

	char* context_kPL2_file = nullptr;
	char* kPL2_DivPtr = strtok_s(kPL2_inputFBuffer, "\n", &context_kPL2_file);
	std::vector<std::vector<char*>> kPL2_Div;

	while (kPL2_DivPtr != nullptr) {
		std::vector<char*> token;
		char* context_kPL2_line = nullptr;
		char* wordNEmphasisNYield_Div = strtok_s(kPL2_DivPtr, ",", &context_kPL2_line);
		while (wordNEmphasisNYield_Div != nullptr) {
			token.push_back(wordNEmphasisNYield_Div);
			wordNEmphasisNYield_Div = strtok_s(nullptr, ",", &context_kPL2_line);
		}
		kPL2_Div.push_back(token);
		kPL2_DivPtr = strtok_s(nullptr, "\n", &context_kPL2_file);
	}
	std::cout << "Finished operation kPL2\n";
	/*===========================================================================================================*/

	std::ifstream rieulEndSyllable("C:\\Users\\hijun\\source\\repos\\SejongHS6CProgrammingProject\\resourcesForCode\\ㄹ받침 한글 음절 유니코드.txt");
	if (rieulEndSyllable.is_open()) {
		std::cout << "File successfully opened rieulEndSyllable" << std::endl;
	}
	else {
		std::cerr << "Failed to open file rieulEndSyllable" << std::endl;
	}

	rieulEndSyllable.seekg(0, std::ios::end);
	std::streamsize rieulEndSyllable_fileSize = rieulEndSyllable.tellg();
	rieulEndSyllable.seekg(0, std::ios::beg);

	char* rieulEndSyllable_inputFBuffer = new char[rieulEndSyllable_fileSize];
	rieulEndSyllable.read(rieulEndSyllable_inputFBuffer, rieulEndSyllable_fileSize);

	char* context_rieulEndSyllable_file = nullptr;
	char* rieulEndSyllable_DivPtr = strtok_s(rieulEndSyllable_inputFBuffer, "\n", &context_rieulEndSyllable_file);
	std::vector<std::vector<char*>> rieulEndSyllable_Div;

	while (rieulEndSyllable_DivPtr != nullptr) {
		std::vector<char*> token;
		char* context_rieulEndSyllable_line = nullptr;
		char* wordNHex_Div = strtok_s(rieulEndSyllable_DivPtr, " ", &context_rieulEndSyllable_line);
		while (wordNHex_Div != nullptr) {
			token.push_back(wordNHex_Div);
			wordNHex_Div = strtok_s(nullptr, " ", &context_rieulEndSyllable_line);
		}
		rieulEndSyllable_Div.push_back(token);
		rieulEndSyllable_DivPtr = strtok_s(nullptr, "\n", &context_rieulEndSyllable_file);
	}
	std::cout << "Finished operation rieulEndSyllable\n";
	/*===========================================================================================================*/

	std::ifstream kSVL("C:\\Users\\hijun\\source\\repos\\SejongHS6CProgrammingProject\\resourcesForCode\\한국어 학습용 단어 목록.csv");
	if (kSVL.is_open()) {
		std::cout << "File successfully opened kSVL" << std::endl;
	}
	else {
		std::cerr << "Failed to open file kSVL" << std::endl;
	}


	std::string kSVL_line;
	std::vector<std::vector<std::string>> kSVL_div;

	while (std::getline(kSVL, kSVL_line)) {
		std::stringstream kSVL_elements(kSVL_line);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(kSVL_elements, token, ',')) {
			tokens.push_back(token);
		}

		kSVL_div.push_back(tokens);
	}

	// kSVL.seekg(0, std::ios::end);
	// std::streamsize kSVL_fileSize = kSVL.tellg();
	// kSVL.seekg(0, std::ios::beg);
	
	// char* kSVL_inputFBuffer = nullptr;
	
	// try {
	// 	kSVL_inputFBuffer = new char[kSVL_fileSize]();
	// 	std::cout << "Memory allocation successful" << std::endl;

	// 	std::strncpy(kSVL_inputFBuffer, "Hello, World!", kSVL_fileSize);

	// 	std::cout << kSVL_inputFBuffer << std::endl;

	// } catch (const std::bad_alloc& e) {
	// 	std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	// 	return -1;
	// }

	
	// kSVL.read(kSVL_inputFBuffer, kSVL_fileSize);

	// char* kSVL_DivPtr = strtok(kSVL_inputFBuffer, "\n");
	// std::vector<std::vector<char*>> kSVL_Div;

	// while (kSVL_DivPtr != nullptr) {
	// 	std::vector<char*> token;
	// 	char* meaningNPOS_Div = strtok(kSVL_DivPtr, " ");
	// 	while (meaningNPOS_Div != nullptr) {
	// 		token.push_back(meaningNPOS_Div);
	// 	}
	// 	kSVL_Div.push_back(token);
	// }

	// for (const auto& kSVLRowTarget : kSVL_Div) {
	// 	for (const auto& kSVLColTarget : kSVLRowTarget) {
	// 		removeNum(kSVLColTarget);
	// 	}
	// }


	std::cout << "Finished operation kSVL\n";




	//입력 텍스트 파일 읽고 저장
	//wstring은 wide string, 한국어 extended unicode 입력받기 위함
	std::string fileName{"testDoc.txt"};
	//열을 파일의 이름 입력받음
	//std::cin >> fileName;
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

	//char* inputFBuffer = new char[fileSize];
	//inputF.read(inputFBuffer, fileSize);

	std::vector<char> inputFBuffer(fileSize);
	inputF.read(inputFBuffer.data(), fileSize);

	for (size_t i = 0; i < fileSize; ++i) {
    std::cout << static_cast<unsigned>(inputFBuffer[i]) << " ";
	}
	std::cout << std::endl;


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
	
	
	// char* charArticlePtr = strtok(inputFBuffer, ".!?");

	// std::vector<std::vector<char*>> articleDiv;

	// while (charArticlePtr != nullptr) {
	// 	std::cout << "Sentence: " << charArticlePtr << std::endl;
	// 	std::vector<char*> token;
	// 	char* sentencePtr = strtok(charArticlePtr, " ");

	// 	while (sentencePtr != nullptr) {
	// 		std::cout << "Token: " << sentencePtr << std::endl;
	// 		token.push_back(sentencePtr);
	// 		sentencePtr = strtok(nullptr, " ");
	// 	}

	// 	articleDiv.push_back(token);
	// 	charArticlePtr = customStrtok(nullptr, ".!?");
	// }

	std::cout << "Input Buffer Content: ";
	for (const auto& iterator : inputFBuffer) {
		std::cout << iterator;
	}
	std::cout << std::endl;

	std::string buffer(inputFBuffer, fileSize);
	const std::string article_div_delimiters{ ".!?" };

	std::vector<std::string> article_div = split_by_delimiters(buffer, article_div_delimiters);
	std::string sentence;

	for (const auto& sentence_div : article_div) {
		std::cout << "Sentence: " << sentence << std::endl;

		char* sentence_cstr = new char[sentence.size() + 1];
		std::strcpy(sentence_cstr, sentence.c_str());

		std::vector<char*> token;
		char* word = std::strtok(sentence_cstr, " ");

		while (word != nullptr) {
			std::cout << "Word: " << word << std::endl;
			token.push_back(word);
			word = std::strtok(nullptr, " ");
		}

	delete[] sentence_cstr;
	}










	// std::vector<int> colIdx{ 1, 2 };

	// for (const auto& articleRow : article_div) {
	// 	for (int colIdxes : colIdx) {
	// 		for (const auto& kPL1RowTarget : kPL1_Div) {
	// 			for (const auto& kPL1ColTarget : kPL1RowTarget) {
	// 				char* target = strstr(articleRow[colIdxes], kPL1ColTarget);
	// 				if (target != nullptr) {
	// 					std::wcout << "Found \"" << kPL1ColTarget << "\" in \"" << articleRow[colIdxes] << std::endl;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	// std::cout << std::endl;

	// int columnIdx{ 1 };

	// for (const auto& i : article_div) {
	// 	for (const auto& j : i) { 
	// 		for (const auto& kPL2RowTarget : kPL2_Div) {
	// 			if (columnIdx < kPL2RowTarget.size()) {
	// 				char* target = strstr(j, kPL2RowTarget.at(1));
	// 				if (target != nullptr) {
	// 					std::cout << "Found \"" << kPL2RowTarget.at(1) << "\" in \"" << j << std::endl;
	// 				}
				
	// 			}
	// 		}
	// 	}
	// }



	std::cout << '\n';

	/*
	* 1. paragraph 문장으로 분할
	* 2. 문장 당 독립적인 계산 공간 생성
	* 3. 
	*/

	//std::wstring koreanText = L"갈갤걀걜걸겔결곌";

	//for (wchar_t ch : koreanText) {
	//	
	//	std::wcout << ch << ": U+" << (int)ch << std::endl;
	//}

	////'ㄹ' 받침만 있는 한글 음절은 28 차이가 남

	delete[] kPL1_inputFBuffer;
	delete[] kPL2_inputFBuffer;
	delete[] rieulEndSyllable_inputFBuffer;
	//delete[] kSVL_inputFBuffer;
	//delete[] inputFBuffer;
	
	kPL_sheet1.close();
	kPL_sheet2.close();
	rieulEndSyllable.close();
	kSVL.close();
	inputF.close();

	return 0;
	}
	









	