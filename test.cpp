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
#include <queue>

//외부에서 다운받고 설치한 헤더 소스 파일 --> 프로그램이 엑셀 파일 접근/수정 등을 할 수 있게 함
//#include "OpenXLSX.hpp"
//using namespace OpenXLSX;


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



struct tree_node {
	int val;
	std::vector<tree_node*> children;
};

void add_child(tree_node* parent, tree_node* child) {
	if (parent) {
		parent->children.push_back(child);
	}
}

void printTree(tree_node* root, int depth = 0) {
	if (!root) return;

	for (int i = 0; i < depth; ++i) std::cout << "	";
	std::cout << root->val << std::endl;

	for (tree_node* child : root->children) {
		printTree(child, depth + 1);
	}
}

void level_order_traversal(tree_node* root) {
	if (!root) return;

	std::queue<tree_node*> q;
	q.push(root);

	while (!q.empty()) {
		tree_node* current = q.front();
		q.pop();

		std::cout << current->val << " ";

		for (tree_node* child : current->children) {
			q.push(child);
		}
	}
	std::cout << std::endl;
}



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
	std::ifstream kPL1("C:\\Users\\hijun\\source\\repos\\SejongHS6CProgrammingProject\\resourcesForCode\\조사 목록-격조사.csv");
	if (kPL1.is_open()) {
		std::cout << "File successfully opened kPL1" << std::endl;
	}
	else {
		std::cerr << "Failed to open file kPL1" << std::endl;
	}

	std::string kPL1_line;
	std::vector<std::vector<std::string>> kPL1_div;

	while (std::getline(kPL1, kPL1_line)) {
		std::stringstream kPL1_elements(kPL1_line);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(kPL1_elements, token, ',')) {
			tokens.push_back(token);
		}

		kPL1_div.push_back(tokens);
	}

	//previous way of making lists --> saved for emergencies.
	// kPL_sheet1.seekg(0, std::ios::end);
	// std::streamsize kPL_sheet1_fileSize = kPL_sheet1.tellg();
	// kPL_sheet1.seekg(0, std::ios::beg);
	
	// char* kPL1_inputFBuffer = new char[kPL_sheet1_fileSize];
	// kPL_sheet1.read(kPL1_inputFBuffer, kPL_sheet1_fileSize);

	// char* context_kPL1_file = nullptr;
	// char* kPL1_DivPtr = strtok_s(kPL1_inputFBuffer, "\n", &context_kPL1_file);
	// std::vector<std::vector<char*>> kPL1_Div;

	// while (kPL1_DivPtr != nullptr) {
	// 	std::vector<char*> token;
	// 	char* context_kPL1_line = nullptr;
	// 	char* wordNPartsOfSpeech_Div = strtok_s(kPL1_DivPtr, ",", &context_kPL1_line);
	// 	while (wordNPartsOfSpeech_Div != nullptr) {
	// 		token.push_back(wordNPartsOfSpeech_Div);
	// 		wordNPartsOfSpeech_Div = strtok_s(nullptr, ",", &context_kPL1_line);
	// 	}
	// 	kPL1_Div.push_back(token);
	// 	kPL1_DivPtr = strtok_s(nullptr, "\n", &context_kPL1_file);
	// }
	std::cout << "Finished operation kPL1\n";
	/*===========================================================================================================*/
	//koreanParticleLis_Sheet2
	std::ifstream kPL2("C:\\Users\\hijun\\source\\repos\\SejongHS6CProgrammingProject\\resourcesForCode\\조사 목록-보조사.csv");
	if (kPL2.is_open()) {
		std::cout << "File successfully opened kPL2" << std::endl;
	}
	else {
		std::cerr << "Failed to open file kPL2" << std::endl;
	}

	std::string kPL2_line;
	std::vector<std::vector<std::string>> kPL2_div;

	while (std::getline(kPL2, kPL2_line)) {
		std::stringstream kPL2_elements(kPL2_line);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(kPL2_elements, token, ',')) {
			tokens.push_back(token);
		}

		kPL2_div.push_back(tokens);
	}

	std::cout << "Finished operation kPL2\n";
	/*===========================================================================================================*/
	//리을 종성 음절절
	std::ifstream rieulEndSyllable("C:\\Users\\hijun\\source\\repos\\SejongHS6CProgrammingProject\\resourcesForCode\\ㄹ받침 한글 음절 유니코드.txt");
	if (rieulEndSyllable.is_open()) {
		std::cout << "File successfully opened rieulEndSyllable" << std::endl;
	}
	else {
		std::cerr << "Failed to open file rieulEndSyllable" << std::endl;
	}

	std::string rieulEndSyllable_line;
	std::vector<std::vector<std::string>> rieulEndSyllable_div;

	while (std::getline(rieulEndSyllable, rieulEndSyllable_line)) {
		std::stringstream rieulEndSyllable_elements(rieulEndSyllable_line);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(rieulEndSyllable_elements, token, ',')) {
			tokens.push_back(token);
		}

		rieulEndSyllable_div.push_back(tokens);
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

	std::cout << "Input Buffer Content: ";
	for (const auto& iterator : inputFBuffer) {
		std::cout << iterator;
	}
	std::cout << std::endl;

	std::string buffer(inputFBuffer.data(), fileSize);
	const std::string article_div_delimiters{ ".!?" };

	std::vector<std::string> article_div = split_by_delimiters(buffer, article_div_delimiters);

	for (const auto& sentence_div : article_div) {
		std::cout << "Sentence: " << sentence_div << std::endl;

		char* sentence_cstr = new char[sentence_div.size() + 1];
		std::strcpy(sentence_cstr, sentence_div.c_str());

		std::vector<char*> token;
		char* word = std::strtok(sentence_cstr, " ");

		while (word != nullptr) {
			std::cout << "Word: " << word << std::endl;
			token.push_back(word);
			word = std::strtok(nullptr, " ");
		}

		

		delete[] sentence_cstr;
	}


	int column_exclude_idx = 0;
	for (const auto& article_row : article_div) {
		for (size_t col_idx{ 0 }; col_idx < article_row.size(); ++col_idx) {
			if ( col_idx == column_exclude_idx) {
				continue;
			}

			const auto& article_col = article_row[col_idx];
			for (const auto& kPL1RowTarget : kPL1_div) {
		 		for (const auto& kPL1ColTarget : kPL1RowTarget) {
		 			std::string article_col_target(1, article_col);

		 			const char* article_col_target_cstr = article_col_target.c_str(); 
		 			const char* kPL1ColTarget_cstr = kPL1ColTarget.c_str();

		 			const char* target = strstr(article_col_target_cstr, kPL1ColTarget_cstr);

		 			if (target != nullptr) {
		 				std::wcout << "Found \"" << kPL1ColTarget_cstr << "\" in \"" << article_col_target_cstr << std::endl;
		 			}
		 		}
			}
		}	
	}
		
	

	std::cout << std::endl;

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

	//delete[] kPL1_inputFBuffer;
	//delete[] kPL2_inputFBuffer;
	//delete[] rieulEndSyllable_inputFBuffer;
	//delete[] kSVL_inputFBuffer;
	//delete[] inputFBuffer;
	
	kPL1.close();
	kPL2.close();
	rieulEndSyllable.close();
	kSVL.close();
	inputF.close();

	return 0;
	}
	









	