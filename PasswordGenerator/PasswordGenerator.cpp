#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <fstream>

// パスワード生成関数
std::string generatePassword(int length, bool includeSpecialChars) {
    // 基本的な文字セット（小文字・大文字・数字）
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    // 特殊記号を含める場合、文字セットに追加
    if (includeSpecialChars) {
        charset += "!@#$%^&*()-_=+[]{}|;:',.<>?";
    }

    std::string password = "";

    // 乱数生成器とシード
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charset.size() - 1);

    // パスワードを生成
    for (int i = 0; i < length; ++i) {
        password += charset[dis(gen)];
    }

    return password;
}

int main() {
    int passwordLength, passwordCount;
    char includeSpecialCharsInput;
    
    // ユーザー入力
    std::cout << "パスワードの文字数を入力してください: ";
    std::cin >> passwordLength;

    std::cout << "特殊記号を含めますか？(y/n): ";
    std::cin >> includeSpecialCharsInput;
    bool includeSpecialChars = (includeSpecialCharsInput == 'y' || includeSpecialCharsInput == 'Y');
    
    std::cout << "生成するパスワードの数を入力してください: ";
    std::cin >> passwordCount;

    // ログファイルの設定
    std::ofstream logFile("passwords_log.txt", std::ios::out | std::ios::app);
    if (!logFile) {
        std::cerr << "ログファイルのオープンに失敗しました。" << std::endl;
        return 1;
    }

    logFile << "パスワード生成設定:\n";
    logFile << "文字数: " << passwordLength << "\n";
    logFile << "特殊記号: " << (includeSpecialChars ? "含む" : "含まない") << "\n";
    logFile << "生成するパスワードの数: " << passwordCount << "\n";
    logFile << "生成されたパスワード:\n";
    
    // パスワード生成とログファイルへの書き込み
    for (int i = 0; i < passwordCount; ++i) {
        std::string password = generatePassword(passwordLength, includeSpecialChars);
        std::cout << password << std::endl;
        logFile << password << std::endl;
    }

    // ログファイルを閉じる
    logFile.close();

    std::cout << "パスワードと設定がログファイル 'passwords_log.txt' に保存されました。" << std::endl;

    return 0;
}
