# パスワードジェネレーター

このプロジェクトは、C++ を使用したシンプルなコンソールベースのパスワードジェネレーターです。ユーザーの入力に基づいて、指定された条件のパスワードを生成し、コンソールに出力するとともにログファイルに記録します。

## 特徴
- 任意の長さのパスワードを生成可能
- 特殊記号を含むかどうかを選択可能
- 一度に複数のパスワードを生成可能
- 生成されたパスワードを `passwords_log.txt` に保存

## 使用方法
1. プログラムをコンパイルします。
   ```sh
   g++ PasswordGenerator.cpp -o PasswordGenerator
   ```
   または Visual Studio 2022 の場合：
   - 新しい C++ コンソールアプリケーションを作成し、`PasswordGenerator.cpp` をプロジェクトに追加
   - ビルドして実行

2. プログラムを実行します。
   ```sh
   ./PasswordGenerator
   ```
3. 以下の情報を入力します。
   - パスワードの文字数
   - 特殊記号を含むか (y/n)
   - 生成するパスワードの数

4. 生成されたパスワードがコンソールに表示され、`passwords_log.txt` に保存されます。

## 動作環境
- Windows / macOS / Linux
- g++ または Visual Studio 2022 の C++ コンパイラ

## コードの説明
このプログラムは、ユーザーの入力を基にランダムなパスワードを生成するシンプルな C++ のコンソールアプリケーションです。

### `generatePassword` 関数
- 指定された長さのパスワードを生成します。
- 小文字・大文字・数字を含むデフォルトの文字セットを使用します。
- ユーザーの指定に応じて特殊記号を追加できます。
- `std::random
