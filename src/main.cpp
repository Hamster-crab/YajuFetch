#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// ===== Ubuntu =====
const string ubuntu_logo = R"(
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
const string arch_logo = R"(
       /\\\
      /  \\\
     /    \\\
    /   ,  \\\
   /___/|___\\\
)";

// ===== Fedora =====
const string fedora_logo = R"(
        .--.
       |o_o |
       |:_/ |
      //   \ \
     (|     | )
    /'\_   _/`\
    \___)=(___/
    )";

// ===== Debian =====
const string debian_logo = R"(
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
const string manjaro_logo = R"(
███████████████████
███████████████████
███████████████████
███████████████████
███████████████████
███████████████████
    )";

// ===== Kali Linux =====
const string kali_logo = R"(
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
const string void_logo = R"(
    ______
 _ /  -  \ _
  \\  -  //
   \\___//
   /     \
    )";

// ===== AlmaLinux =====
const string alma_logo = R"(
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
const string centos_logo = R"(
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
const string suse_logo = R"(
     ___________
    /           \
   /  /  .-.  \  \
  /  /  |   |  \  \
 (_/   \___/   \_)
     /       \
    /_________\
    )";

// ===== OS 情報取得 =====
string getOSName() {
    ifstream file("/etc/os-release");
    string line;
    while (getline(file, line)) {
        if (line.find("ID=") != string::npos) {
            line = line.substr(3);
            if (line.find('"') != string::npos) {
                line = line.substr(1, line.size() - 2);
            }
            return line;
        }
    }
    return "unknown";
}

void getOSInfo() {
    ifstream file("/etc/os-release");
    string line;
    cout << "\033[36mOS Info: \033[0m";
    while (getline(file, line)) {
        if (line.find("PRETTY_NAME") != string::npos) {
            cout << line.substr(line.find('=') + 1) << endl;
        }
    }
    cout << endl;
}

void getCPUInfo() {
    ifstream file("/proc/cpuinfo");
    string line;
    cout << "\033[36mCPU Info: \033[0m";
    while (getline(file, line)) {
        if (line.find("model name") != string::npos) {
            cout << line.substr(line.find(':') + 2) << endl;
            break;
        }
    }
    cout << endl;
}

void getMemoryInfo() {
    ifstream file("/proc/meminfo");
    string line;
    cout << "\033[36mMemory Info: \033[0m";
    while (getline(file, line)) {
        if (line.find("MemTotal") != string::npos) {
            cout << line.substr(line.find(':') + 2) << endl;
            break;
        }
    }
    cout << endl;
}

void getGPUInfo() {
    cout << "\033[36mGPU Info: \033[0m";
    system("lspci | grep VGA");
    cout << endl;
}

void getDiskInfo() {
    cout << "\033[36mDisk Usage: \033[0m";
    system("df -h | grep /dev/");
    cout << endl;
}

void displayLogo(const string& os_name, bool show_logo) {
    if (!show_logo) {
        return;
    }

    if (os_name == "ubuntu") {
        cout << ubuntu_logo << endl;
    } else if (os_name == "arch") {
        cout << "\033[36m" << arch_logo << "\033[0m" << endl;
    } else if (os_name == "fedora") {
        cout << fedora_logo << endl;
    } else if (os_name == "debian") {
        cout << debian_logo << endl;
    } else if (os_name == "manjaro") {
        cout << manjaro_logo << endl;
    } else if (os_name == "kali") {
        cout << kali_logo << endl;
    } else if (os_name == "void") {
        cout << void_logo << endl;
    } else if (os_name == "almalinux") {
        cout << alma_logo << endl;
    } else if (os_name == "centos") {
        cout << centos_logo << endl;
    } else if (os_name == "opensuse") {
        cout << suse_logo << endl;
    } else {
        cout << "🚫 No logo available for this OS." << endl;
    }
    cout << endl;
}

void showSystemInfo(bool show_logo) {
    string os_name = getOSName();
    displayLogo(os_name, show_logo);
    getOSInfo();
    getCPUInfo();
    getMemoryInfo();
    getGPUInfo();
    getDiskInfo();
}

int main(int argc, char* argv[]) {
    bool show_logo = false; // デフォルトではロゴを非表示

    // コマンドライン引数を解析
    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "--logo" || string(argv[i]) == "-l") {
            show_logo = true; // --logo または -l フラグがある場合、ロゴを表示
        }
    }

    showSystemInfo(show_logo);
    return 0;
}
