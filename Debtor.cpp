#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Debtor {
public:
    Debtor(string fullname, string birthDay, string phone, string email, string address, int debt)
        : FullName(fullname), BirthDay(birthDay), Phone(phone), Email(email), Address(address), Debt(debt) {}

    string FullName;
    string BirthDay;
    string Phone;
    string Email;
    string Address;
    int Debt;

    friend ostream& operator<<(ostream& os, const Debtor& debtor) {
        os << debtor.FullName << " " << debtor.BirthDay << " " << debtor.Phone << " " << debtor.Email << " " << debtor.Address << " " << debtor.Debt;
        return os;
    }
};

void printDebtors(const vector<Debtor>& debtors) {
    for (const Debtor& debtor : debtors) {
        cout << debtor << endl;
    }
}

void task2(const vector<Debtor>& debtors) {
    cout << "Task 2:" << endl;
    for (const Debtor& debtor : debtors) {
        size_t foundRhyta = debtor.Email.find("rhyta.com");
        size_t foundDayrep = debtor.Email.find("dayrep.com");
        if (foundRhyta != string::npos || foundDayrep != string::npos) {
            cout << debtor << endl;
        }
    }
}

void task3(const vector<Debtor>& debtors) {
    cout << "Task 3:" << endl;
    for (const Debtor& debtor : debtors) {
        int age = 2024 - stoi(debtor.BirthDay.substr(debtor.BirthDay.find_last_of(' ') + 1));
        if (age >= 26 && age <= 36) {
            cout << debtor << endl;
        }
    }
}

void task4(const vector<Debtor>& debtors) {
    cout << "Task 4:" << endl;
    for (const Debtor& debtor : debtors) {
        if (debtor.Debt <= 5000) {
            cout << debtor << endl;
        }
    }
}

void task5(const vector<Debtor>& debtors) {
    cout << "Task 5:" << endl;
    for (const Debtor& debtor : debtors) {
        if (debtor.FullName.length() > 18 && count(debtor.Phone.begin(), debtor.Phone.end(), '2') + count(debtor.Phone.begin(), debtor.Phone.end(), '7') >= 2) {
            cout << debtor << endl;
        }
    }
}

void task7(const vector<Debtor>& debtors) {
    cout << "Task 7:" << endl;
    for (const Debtor& debtor : debtors) {
        if (debtor.BirthDay.find("December") != string::npos || debtor.BirthDay.find("January") != string::npos || debtor.BirthDay.find("February") != string::npos) {
            cout << debtor << endl;
        }
    }
}

void task8(vector<Debtor>& debtors) {
    cout << "Task 8:" << endl;
    sort(debtors.begin(), debtors.end(), [](const Debtor& a, const Debtor& b) {
        return a.FullName < b.FullName;
        });

    int totalDebt = 0;
    for (const Debtor& debtor : debtors) {
        totalDebt += debtor.Debt;
    }

    int averageDebt = totalDebt / debtors.size();

    for (const Debtor& debtor : debtors) {
        if (debtor.Debt > averageDebt) {
            cout << debtor << endl;
        }
    }

    sort(debtors.begin(), debtors.end(), [](const Debtor& a, const Debtor& b) {
        return a.Debt > b.Debt;
        });
}

void task9(const vector<Debtor>& debtors) {
    cout << "Task 9:" << endl;
    for (const Debtor& debtor : debtors) {
        if (debtor.Phone.find('8') == string::npos) {
            cout << "Name: " << debtor.FullName << ", Age: " << 2024 - stoi(debtor.BirthDay.substr(debtor.BirthDay.find_last_of(' ') + 1)) << ", Debt: " << debtor.Debt << endl;
        }
    }
}

void task11(vector<Debtor>& debtors) {
    cout << "Task 11:" << endl;
    vector<Debtor> filteredDebtors;

    for (const Debtor& debtor : debtors) {
        string nameAndFamily = debtor.FullName + debtor.FullName;
        sort(nameAndFamily.begin(), nameAndFamily.end());
        nameAndFamily.erase(unique(nameAndFamily.begin(), nameAndFamily.end()), nameAndFamily.end());

        if (nameAndFamily.length() >= 3) {
            filteredDebtors.push_back(debtor);
        }
    }

    sort(filteredDebtors.begin(), filteredDebtors.end(), [](const Debtor& a, const Debtor& b) {
        return a.FullName < b.FullName;
        });

    for (const Debtor& debtor : filteredDebtors) {
        cout << debtor << endl;
    }
}

void task13(const vector<Debtor>& debtors) {
    cout << "Task 13:" << endl;
    vector<string> birthYears;
    for (const Debtor& debtor : debtors) {
        string birthYear = debtor.BirthDay.substr(debtor.BirthDay.find_last_of(' ') + 1);
        birthYears.push_back(birthYear);
    }

    sort(birthYears.begin(), birthYears.end());
    birthYears.erase(unique(birthYears.begin(), birthYears.end()), birthYears.end());

    for (const string& year : birthYears) {
        cout << "Born in " << year << ":" << endl;
        for (const Debtor& debtor : debtors) {
            if (debtor.BirthDay.find(year) != string::npos) {
                cout << debtor << endl;
            }
        }
        cout << endl;
    }
}

void task14(vector<Debtor>& debtors) {
    cout << "Task 14:" << endl;
    sort(debtors.begin(), debtors.end(), [](const Debtor& a, const Debtor& b) {
        return a.Debt > b.Debt;
        });

    for (int i = 0; i < min(5, static_cast<int>(debtors.size())); ++i) {
        cout << debtors[i] << endl;
    }
}

void task15(const vector<Debtor>& debtors) {
    cout << "Task 15:" << endl;
    int totalDebt = 0;
    for (const Debtor& debtor : debtors) {
        totalDebt += debtor.Debt;
    }
    cout << "Total Debt: " << totalDebt << endl;
}

void task16(const vector<Debtor>& debtors) {
    cout << "Task 16:" << endl;
    for (const Debtor& debtor : debtors) {
        if (stoi(debtor.BirthDay.substr(debtor.BirthDay.find_last_of(' ') + 1)) < 1939) {
            cout << debtor << endl;
        }
    }
}

void task18(const vector<Debtor>& debtors) {
    cout << "Task 18:" << endl;
    for (const Debtor& debtor : debtors) {
        string phoneNumber = debtor.Phone;
        string uniqueDigits = "";
        for (char digit : phoneNumber) {
            if (isdigit(digit) && uniqueDigits.find(digit) == string::npos) {
                uniqueDigits += digit;
            }
        }

        if (uniqueDigits.length() == phoneNumber.length()) {
            cout << "Name: " << debtor.FullName << ", Debt: " << debtor.Debt << endl;
        }
    }
}

void task19(const vector<Debtor>& debtors) {
    cout << "Task 19:" << endl;
    for (const Debtor& debtor : debtors) {
        int monthsToPayOff = ceil(static_cast<double>(debtor.Debt) / 500);
        int birthYear = stoi(debtor.BirthDay.substr(debtor.BirthDay.find_last_of(' ') + 1));
        int currentYear = 2024;
        int age = currentYear - birthYear;
        int remainingMonths = 12 - (age % 12);

        if (monthsToPayOff <= remainingMonths) {
            cout << debtor << ", Months to Pay Off: " << monthsToPayOff << endl;
        }
    }
}

void task20(const vector<Debtor>& debtors) {
    cout << "Task 20:" << endl;
    for (const Debtor& debtor : debtors) {
        string nameAndFamily = debtor.FullName + debtor.FullName;
        transform(nameAndFamily.begin(), nameAndFamily.end(), nameAndFamily.begin(), ::tolower);

        if (count(nameAndFamily.begin(), nameAndFamily.end(), 's') >= 1 &&
            count(nameAndFamily.begin(), nameAndFamily.end(), 'm') >= 1 &&
            count(nameAndFamily.begin(), nameAndFamily.end(), 'i') >= 1 &&
            count(nameAndFamily.begin(), nameAndFamily.end(), 'l') >= 1 &&
            count(nameAndFamily.begin(), nameAndFamily.end(), 'e') >= 1) {
            cout << debtor << endl;
        }
    }
}

void main() {
    vector<Debtor> debtors = {
         Debtor("Shirley T. Qualls", "March 30, 1932", "530-662-7732", "ShirleyTQualls@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414),
         Debtor("Danielle W. Grier", "October 18, 1953", "321-473-4178", "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599),
         Debtor("Connie W. Lemire", "June 18, 1963", "828-321-3751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219),
         Debtor("Coy K. Adams", "March 1, 1976", "410-347-1307", "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784),
         Debtor("Bernice J. Miles", "June 1, 1988", "912-307-6797", "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060),
         Debtor("Bob L. Zambrano", "February 28, 1990", "706-446-1649", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628),
         Debtor("Adam D. Bartlett", "May 6, 1950", "650-693-1758", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412),
         Debtor("Pablo M. Skinner", "August 26, 1936", "630-391-2034", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097),
         Debtor("Dorothy J. Brown", "July 9, 1971", "270-456-3288", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956),
         Debtor("Larry A. Miracle", "May 22, 1998", "301-621-3318", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7150),
         Debtor("Donna B. Maynard", "January 26, 1944", "520-297-0575", "DonnaBMaynard@teleworm.us", "4821 Elk Rd Little Tucson, AZ 85704", 2910),
         Debtor("Jessica J. Stoops", "April 22, 1989", "360-366-8101", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805),
         Debtor("Audry M. Styles", "February 7, 1937", "978-773-4802", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001),
         Debtor("Violet R. Anguiano", "November 4, 1958", "585-340-7888", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128),
         Debtor("Charles P. Segundo", "October 21, 1970", "415-367-3341", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648),
         Debtor("Paul H. Sturtz", "September 15, 1944", "336-376-1732", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437),
         Debtor("Doris B. King", "October 10, 1978", "205-231-8973", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230),
         Debtor("Deanna J. Donofrio", "April 16, 1983", "952-842-7576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515),
         Debtor("Martin S. Malinowski", "January 17, 1992", "765-599-3523", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue New Castle, IN 47362", 1816),
         Debtor("Melissa R. Arner", "May 24, 1974", "530-508-7328", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037),
         Debtor("Kelly G. Hoffman", "September 22, 1969", "505-876-8935", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755),
         Debtor("Doyle B. Short", "June 15, 1986", "989-221-4363", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657),
         Debtor("Lorrie R. Gilmore", "December 23, 1960", "724-306-7138", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693),
         Debtor("Lionel A. Cook", "April 16, 1972", "201-627-5962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712),
         Debtor("Charlene C. Burke", "January 18, 1990", "484-334-9729", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016),
         Debtor("Tommy M. Patton", "June 30, 1981", "774-571-6481", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349),
         Debtor("Kristin S. Bloomer", "June 16, 1944", "443-652-0734", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824),
         Debtor("Daniel K. James", "November 10, 1997", "801-407-4693", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215),
         Debtor("Paula D. Henry", "September 6, 1976", "618-378-5307", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766),
         Debtor("Donna C. Sandoval", "December 13, 1947", "540-482-5463", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363),
         Debtor("Robert T. Taylor", "August 17, 1932", "270-596-6442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785),
         Debtor("Donna W. Alamo", "December 9, 1948", "978-778-2533", "DonnaWAlamo@teleworm.us", "4367 Christie Way Marlboro, MA 01752", 10030),
         Debtor("Amy R. Parmer", "May 19, 1995", "480-883-4934", "AmyRParmer@armyspy.com", "85 Elmwood Avenue Chandler, AZ 85249", 5347),
         Debtor("Newton K. Evans", "October 8, 1986", "303-207-9084", "NewtonKEvans@rhyta.com", "3552 Columbia Road Greenwood Village, CO 80111", 9838),
         Debtor("Kathleen C. Chaney", "January 5, 1949", "605-245-3513", "KathleenCChaney@rhyta.com", "316 Elsie Drive Fort Thompson, SD 57339", 1672),
         Debtor("Manuel C. Johnson", "February 23, 1957", "606-247-2659", "ManuelCJohnson@jourrapide.com", "4146 May Street Sharpsburg, KY 40374", 9195),
         Debtor("Carla A. Creagh", "November 21, 1988", "614-307-8974", "CarlaACreagh@dayrep.com", "3106 Bates Brothers Road Columbus, OH 43215", 11271),
         Debtor("Norma M. New", "May 18, 1988", "857-492-8703", "NormaMNew@jourrapide.com", "965 Metz Lane Woburn, MA 01801", 9761),
         Debtor("Roy D. Green", "January 27, 1983", "308-340-5981", "RoyDGreen@jourrapide.com", "401 Romrog Way Grand Island, NE 68801", 10771),
         Debtor("Cristy J. Jensen", "November 2, 1935", "440-626-9550", "CristyJJensen@jourrapide.com", "2177 Harley Vincent Drive Cleveland, OH 44113", 5205),
         Debtor("Nancy J. Fergerson", "June 10, 1993", "219-987-8498", "NancyJFergerson@dayrep.com", "3584 Jadewood Drive Demotte, IN 46310", 1276),
         Debtor("Dave N. Rodriguez", "January 21, 1938", "214-540-2499", "DaveNRodriguez@rhyta.com", "1890 Poco Mas Drive Dallas, TX 75247", 9132),
         Debtor("James E. Denning", "May 4, 1988", "504-289-8640", "JamesEDenning@jourrapide.com", "1444 Rose Avenue Metairie, LA 70001", 8176),
         Debtor("Richard M. Thomas", "February 13, 1972", "510-735-3359", "RichardMThomas@jourrapide.com", "4454 Green Avenue Oakland, CA 94609", 7875),
         Debtor("Lakisha R. Forrest", "December 1, 1973", "334-830-1181", "LakishaRForrest@armyspy.com", "3121 Quarry Drive Montgomery, AL 36117", 3088),
         Debtor("Pamela H. Beauchamp", "November 20, 1959", "801-559-6347", "PamelaHBeauchamp@jourrapide.com", "3239 Tori Lane Salt Lake City, UT 84104", 6588)
    };

    task2(debtors);
    task3(debtors);
    task4(debtors);
    task5(debtors);
    task7(debtors);
    task8(debtors);
    task9(debtors);
    task11(debtors);
    task13(debtors);
    task14(debtors);
    task15(debtors);
    task16(debtors);
    task18(debtors);
    task19(debtors);
    task20(debtors);

    printDebtors(debtors);

}
