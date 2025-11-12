#include <iostream>
#include <iomanip>

// 函數用於判斷是否為閏年


bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

// 函數用於取得每個月的天數
int getDaysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// 函數用於輸出月曆外觀
void printCalendar(int year, int month) {
    std::cout << "=============================" << std::endl;
    std::cout << "      " << year << " 年 " << month << " 月" << std::endl;
    std::cout << "日 一 二 三 四 五 六" << std::endl;

    int daysInMonth = getDaysInMonth(year, month);
    int firstDayOfWeek = 1;  // 假設一號是星期日

    // 根據一號是星期幾，輸出相應的空格
    for (int i = 0; i < firstDayOfWeek - 1; ++i) {
        std::cout << "   ";
    }

    for (int day = 1; day <= daysInMonth; ++day) {
        // 輸出日期，對齊格式
        std::cout << std::setw(2) << day << " ";
        
        // 換行處理，每週七天
        if ((day + firstDayOfWeek - 1) % 7 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main() {
    int year, month;

    std::cout << "請輸入年份: ";
    std::cin >> year;
    std::cout << "請輸入月份: ";
    std::cin >> month;

    if (month < 1 || month > 12) {
        std::cout << "無效的月份。" << std::endl;
    } else {
        printCalendar(year, month);
    }

    return 0;
}

