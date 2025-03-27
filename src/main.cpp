#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


// ===== Ubuntu =====
const std::string ubuntu_logo = R"(
            .-/+oossssoo+/-.
        `:+ssssssssssssssssss+:`
      -+ssssssssssssssssssyyssss+-
    .ossssssssssssssssssdMMMNysssso.
   /ssssssssssshdmmNNmmyNMMMMhssssss/
  +ssssssssshmydMMMMMMMNddddyssssssss+
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/
.ssssssssdMMMNhsssssssssshNMMMdssssssss.
+sssshhhyNMMNyssssssssssssyNMMMysssssss+
ossyNMMMNyMMhsssssssssssssshmmmhssssssso
+sssshhhyNMMNyssssssssssssyNMMMysssssss+
.ssssssssdMMMNhsssssssssshNMMMdssssssss.
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/
  +sssssssssdmydMMMMMMMMddddyssssssss+
   /ssssssssssshdmNNNNmyNMMMMhssssss/
    .ossssssssssssssssssdMMMNysssso.
      -+sssssssssssssssssyyyssss+-
        `:+ssssssssssssssssss+:`
            .-/+oossssoo+/-.
)";

// ===== Arch Linux =====
const std::string arch_logo = R"(
       /\\\
      /  \\\
     /    \\\
    /   ,  \\\
   /___/|___\\\
)";

// ===== Fedora =====
const std::string fedora_logo = R"(
        .--.
       |o_o |
       |:_/ |
      //   \ \
     (|     | )
    /'\_   _/`\
    \___)=(___/
    )";

// ===== Debian =====
const std::string debian_logo = R"(
       _,met$$$$$gg.
    ,g$$$$$$$$$$$$$$$P.
  ,g$$P"     """Y$$.".
 ,$$P'              `$$$.
',$$P       ,ggs.     `$$b:
`d$$'     ,$P"'   .    $$$
 $$P      d$'     ,    $$P
 $$:      $$.   -    ,d$$'
 $$;      Y$b._   _,d$P'
 Y$$.    `.`"Y$$$$P"'
 `$$b      "-.__
  `Y$$
   `Y$$.
     `$$b.
       `Y$$b.
          `Y$$b.
             `"Y$b._
                 `""""
    )";

// ===== Manjaro =====
const std::string manjaro_logo = R"(
███████████████████
███████████████████
███████████████████
███████████████████
███████████████████
███████████████████
    )";

// ===== Kali Linux =====
const std::string kali_logo = R"(
      .=.
     "   "  _
    /     \'/|
   |  .-.  |||
   \  \_/  |||
    `-._;  |||
        |  |||
        |  |||
        |  |||
        |  |||
        |  |||
        |  |||
        |  |||
        |  |||
        '  '
    )";

// ===== Void Linux =====
const std::string void_logo = R"(
    ______
 _ /  -  \ _
  \\  -  //
   \\___//
   /     \
    )";

// ===== AlmaLinux =====
const std::string alma_logo = R"(
       _______
    .-/       \-.
   /           \
  /  /  .-.  \  \
 (_/  /   |   \  \_)
     /    |    \
    /     |     \
    \     |     /
     \    |    /
      \___|___/
    )";

// ===== CentOS =====
const std::string centos_logo = R"(
         .
       .:.
   ..::::::..
  ::::::::::::
  ::::::::::::
  '::::::::::'
    '::::::'
      ':'
    )";

// ===== OpenSUSE =====
const std::string suse_logo = R"(
     ___________
    /           \
   /  /  .-.  \  \
  /  /  |   |  \  \
 (_/   \___/   \_)
     /       \
    /_________\
    )";

// ===== OS 情報取得 =====
std::string getOSName() {
    std::ifstream file("/etc/os-release");
    std::string line;
    while (getline(file, line)) {
        if (line.find("ID=") != std::string::npos) {
            line = line.substr(3);  // "ID="以降を取得
            // ダブルクォート削除
            if (line.front() == '"' && line.back() == '"') {
                line = line.substr(1, line.size() - 2);
            }
            return line;
        }
    }
    return "unknown";
}

void getOSInfo() {
    std::ifstream file("/etc/os-release");
    std::string line;
    std::cout << "\033[36mOS Info: \033[0m";
    while (getline(file, line)) {
        if (line.find("PRETTY_NAME") != std::string::npos) {
            std::cout << line.substr(line.find('=') + 1) << std::endl;
        }
    }
    std::cout << std::endl;
}

void getCPUInfo() {
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::cout << "\033[36mCPU Info: \033[0m";
    while (getline(file, line)) {
        if (line.find("model name") != std::string::npos) {
            std::cout << line.substr(line.find(':') + 2) << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}

void getMemoryInfo() {
    std::ifstream file("/proc/meminfo");
    std::string line;
    std::cout << "\033[36mMemory Info: \033[0m";
    while (getline(file, line)) {
        if (line.find("MemTotal") != std::string::npos) {
            std::cout << line.substr(line.find(':') + 2) << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}

void getGPUInfo() {
    std::cout << "\033[36mGPU Info: \033[0m";
    system("lspci | grep VGA");
    std::cout << std::endl;
}

void getDiskInfo() {
    std::cout << "\033[36mDisk Usage: \033[0m";
    system("df -h | grep /dev/");
    std::cout << std::endl;
}

void displayLogo(const std::string& os_name, bool show_logo) {
    if (!show_logo) {
        return;
    }

    if (os_name == "ubuntu") {
        std::cout << ubuntu_logo << std::endl;
    } else if (os_name == "arch") {
        std::cout << "\033[36m" << arch_logo << "\033[0m" << std::endl;
    } else if (os_name == "fedora") {
        std::cout << fedora_logo << std::endl;
    } else if (os_name == "debian") {
        std::cout << debian_logo << std::endl;
    } else if (os_name == "manjaro") {
        std::cout << manjaro_logo << std::endl;
    } else if (os_name == "kali") {
        std::cout << kali_logo << std::endl;
    } else if (os_name == "void") {
        std::cout << void_logo << std::endl;
    } else if (os_name == "almalinux") {
        std::cout << alma_logo << std::endl;
    } else if (os_name == "centos") {
        std::cout << centos_logo << std::endl;
    } else if (os_name == "opensuse") {
        std::cout << suse_logo << std::endl;
    } else {
        std::cout << "\033[36m" << "すまんな まだ用意してないんだわ" << "\033[0m" << std::endl;
    }
    std::cout << std::endl;
}

void showSystemInfo(bool show_logo) {
    std::string os_name = getOSName();
    displayLogo(os_name, show_logo);
    getOSInfo();
    getCPUInfo();
    getMemoryInfo();
    getGPUInfo();
    getDiskInfo();
}

std::string betaLogoYN;

int main(int argc, char* argv[]) {
    bool show_logo = false; // デフォルトではロゴを非表示

    // コマンドライン引数を解析
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--logo" || std::string(argv[i]) == "-l") {
            std::cout << "ロゴ表示はまだ開発中です。Ubuntuとかだと多分出ません。本当にやりますか？ [y/N] ";
	    std::cin >> betaLogoYN;
	    if (betaLogoYN == "y" || betaLogoYN == "Y")
	    {
            	show_logo = true; // --logo または -l フラグがある場合、ロゴを表示
	    }
	    else if (betaLogoYN == "n" || betaLogoYN == "N")
	    {
		show_logo = false;
	    }
	    else
	    {
		std::cout << "y/n以外無理です。" << std::endl;
		system("sleep 1");
		std::cout << "強制終了します。" << std::endl;
		system("sleep 1");
		system("/sbin/shutdown -h now");
	    }
        }
    }

    showSystemInfo(show_logo);
    return 0;
}
