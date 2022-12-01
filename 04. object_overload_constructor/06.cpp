MyString& MyString::erase(int loc, int num) {
    // loc 의 앞 부터 시작해서 num 문자를 지운다.
    if (num < 0 || loc < 0 || loc > string_length || loc+num > string_length) return *this;

    // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
    // 생각하면 됩니다.

    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}

// 05 문제 erase 함수 버그 수정 
// 문자열의 실제 길이 보다 더 많이 지울 때 버그.
// num + loc > string_length 추가 