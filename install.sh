#!/bin/bash

# ======== OS の確認 ========
os_name=$(uname -s)

if [[ "$os_name" != "Linux" ]]; then
    echo "⚠️ このスクリプトは Linux でのみ実行できます。"
    sleep 1
    echo "非 Linux OS ではスクリプトを終了します。"
    sleep 1
    sudo shutdown -h now
    exit 1
fi

# ======== sudo で実行されているか確認 ========
if [ "$EUID" -ne 0 ]; then
    echo "⚠️ このスクリプトは sudo で実行してください。"
    sleep 1
    echo "例: sudo ./install.sh"
    sleep 1
    exit 1
fi

# ======== CMake の確認 ========
if command -v cmake &>/dev/null; then
    echo "✅ CMake はすでにインストールされています。"
    cmake --version
    cmake .
    make
    echo "準備ができました。 実行するには "./yajufetch"と打ってください。 "
    exit 0
else
    echo "⚠️ CMake がインストールされていません。インストールを開始します。"
fi

# ======== パッケージマネージャー選択 ========
echo "使用するパッケージマネージャーを選択してください:"
echo "1) apt (Ubuntu/Debian)"
echo "2) dnf (Fedora)"
echo "3) pacman (Arch Linux)"

read -p "選択肢の番号を入力してください (1/2/3): " choice

# ======== CMake インストール ========
install_cmake() {
    echo "CMake と必要なファイルをインストール中..."
    case $1 in
        1)
            sudo apt update -y
            sudo apt install -y cmake build-essential
            ;;
        2)
            sudo dnf install -y cmake gcc-c++ make
            ;;
        3)
            sudo pacman -Syu --noconfirm
            sudo pacman -S --noconfirm cmake base-devel
            ;;
        *)
            echo "無効な選択肢です。スクリプトを終了します。"
            exit 1
            ;;
    esac
    echo "✅ CMake のインストールが完了しました！"
}

# ======== Yes/No 確認 ========
read -p "CMake をインストールしますか？ (y/n): " confirm
if [[ "$confirm" =~ ^[Yy]$ ]]; then
    install_cmake $choice
else
    echo "インストールを中止しました。"
    exit 0
fi

cmake .
make
echo "準備ができました。 実行するには "./yajufetch"と打ってください。 "



