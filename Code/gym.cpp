#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    string address;
    string phone;
public:
        void setName(string name) {
            this->name = name;
        }
        void setAddress(string address) {
            this->address = address;
        }
        void setPhone(string phone) {
            this->phone = phone;
        }
        string getName() {
            return name;
        }
        string getAddress() {
            return address;
        }
        string getPhone() {
            return phone;
        }
};

class CustomerManagement {
public:
    string name;
    string address;
    string phone;
    int count;
    Customer* customers;
    CustomerManagement() {
        customers = NULL;
        count = 0;
    }
    void addCustomer(Customer customer) {
        Customer* newCustomers = new Customer[count + 1];
        for (int i = 0; i < count; i++) {
            newCustomers[i] = customers[i];
        }
        newCustomers[count] = customer;
        count++;
        delete[] customers;
        customers = newCustomers;
    }

    void removeCustomer(int index) {
        if (index >= 0 && index < count) {
            Customer* newCustomers = new Customer[count - 1];
            for (int i = 0; i < index; i++) {
                newCustomers[i] = customers[i];
            }
            for (int i = index + 1; i < count; i++) {
                newCustomers[i - 1] = customers[i];
            }
            count--;
            delete[] customers;
            customers = newCustomers;
        }
    }

    void saveToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "so luong khach hang : " << count << endl;
            for (int i = 0; i < count; i++) {
                file << "----------------------------||------------------------------------"<<endl;
                file <<"| Ten khach hang: "<< customers[i].getName()<<endl;
                file <<"| Dia chi: "<< customers[i].getAddress() <<endl;
                file <<"| So dien thoai: "<< customers[i].getPhone()<< endl;
                file << "----------------------------||------------------------------------"<<endl;
            }
            file.close();
            cout << " <> Danh sach khach hang da duoc luu vao file thanh cong!" << endl;
        } else {
            cout << "Khong the ghi file" << endl;
        }
    }

    void printCustomer(int index) {
        if (index >= 0 && index < count) {
            cout << "===================== THONG TIN KHACH HANG =====================" << endl;
            cout << " <> Khach hang " << index + 1 << ":" << endl;
            cout << " <> Ten: " << customers[index].getName() << endl;
            cout << " <> Dia chi: " << customers[index].getAddress() << endl;
            cout << " <> So dien thoai: " << customers[index].getPhone() << endl;
            cout << "================================================================"<<endl;
        } else {
            cout << "==> Khong tim thay khach hang:  " << index + 1 << "." << endl;
        }
    }

    void printMenu() {
        cout << "[-------------------> MENU <--------------------]" << endl;
        cout << "[      1. Them khach hang                       ]" << endl;
        cout << "[      2. Xoa khach hang                        ]" << endl;
        cout << "[      3. Luu danh sach khach hang vao tep      ]" << endl;
        cout << "[      4. xuat thong tin khach hang             ]" << endl;
        cout << "[      5. Dang ki goi tap GYM                   ]" << endl;
        cout << "[      6. Xuat Bill                             ]" << endl;
        cout << "[      7. Thoat chuong trinh                    ]" << endl;
        cout << "[-----------------------------------------------]" << endl;
        cout << "<=> Nhap lua chon cua ban: ";
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class khai báo các nh viên của PersonalTrainer
class PersonalTrainer {
  private:
    string name;
    string phone;
    string specialize;
  public:
    void setName(string n) {
      name = n;
    }
    void setPhone(string p) {
      phone = p;
    }
    void setSpecialize(string s) {
      specialize = s;
    }
    string getName() {
      return name;
    }
    string getPhone() {
      return phone;
    }
    string getSpecialize() {
      return specialize;
    }
};
//ham ghi danh sach PT vao file
void writePT(PersonalTrainer* trainers, int count) {
  ofstream file("danhsach_PT.txt");
  for (int i = 0; i < count; i++) {
    file << trainers[i].getName() << "-" << trainers[i].getSpecialize() << "-" 
    << trainers[i].getPhone() << endl;
  }
  file.close();
}
PersonalTrainer* readPT(int& count) {
  ifstream file("danhsach_PT.txt");
  string line;
  PersonalTrainer* trainers = new PersonalTrainer[100];
  count = 0;
  while (getline(file, line)) {
    PersonalTrainer trainer;
    trainer.setName(line.substr(0, line.find('-')));
    trainer.setSpecialize(line.substr(line.find('-') + 1, line.rfind('-') - line.find('-') - 1));
    trainer.setPhone(line.substr(line.rfind('-') + 1));
    trainers[count] = trainer;
    count++;
  }
  file.close();
  return trainers;
}
//ham hien thi cac doi tuong trong va yeu cau nguoi dung chon 1 
void selectPT(PersonalTrainer* trainers, int count) {
  cout << " <------------Danh sach PT-------------->:" << endl;
  for (int i = 0; i < count; i++) {
    cout <<" (+) "<< i + 1 << ". " << trainers[i].getName() << " - " << trainers[i].getSpecialize()
     << endl;
  }
}
//ham hien thi chi tiet thong tin cua PT duoc chon va ghi lua chon vào file
void printPT(PersonalTrainer trainer, int count) {
  cout << "------------thong tin PT quy khach da chon------------" << endl;
  cout << " <> Name: " << trainer.getName() << endl;
  cout << " <> Specialize: " << trainer.getSpecialize() << endl;
  cout << " <> Phone: " << trainer.getPhone() << endl;
  cout << "------------------------------------------------------" << endl;
  ofstream file("trainers.txt");
    file << "------------thong tin PT quy khach da chon------------" << endl;
    file << trainer.getName() << "-" << trainer.getSpecialize() << "-" 
    << trainer.getPhone() << endl;
    file.close();
}
void readTrainersFromFile() {
    string line;
    ifstream infile("trainers.txt");

    if (!infile.is_open()) {
        cout << "Khong the doc file trainers.txt" << endl;
        return;
    }
    getline(infile,line) ; //doc dong dau tien
    getline(infile,line) ;
    cout<<" <> Personal Trainer ban chon la: "<<line<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Date {
    int day, month, year;
    friend struct CustomerManager;
    // friend void DisplayBill();
    friend struct Promotion;

    void inputDate() {  // Nhập ngày đăng kí 
        cout << "-------Nhap thoi gian dang ki goi tap:------ " << endl;
        cout << " => Nhap ngay: ";
        cin >> day;
        cout << " => Nhap thang: ";
        cin >> month;
        cout << " => Nhap nam: ";
        cin >> year;
    }
    void setDay(int day) {
        this->day = day;
    }
    int  getDay() {
        return day;
    }
    void setMonth(int month) {
        this->month = month;
    }
    int  getMonth() {
        return month;
    }
    void  setYear(int year) {
        this->year = year;
    }
    int getYear() {
        return year;
    }
    void DisplayRegistrationDate() {  
        string day = to_string(this->day);
        string month = to_string(this->month);
        if (day.length() == 1) day = "0" + day;
        if (month.length() == 1) month = "0" + month;
        cout << " <> Ngay ban da dang ki: " << day << "/" << month << "/" << year << endl;
    }

    void DisplayExpirationDate() {  
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int newMonth = month + 3;
        int newYear = year;
        if (newMonth > 12) {
            newMonth -= 12;
            newYear += 1;
        }
        int newDay = day;
        if (newDay > daysInMonth[newMonth]) {
            newDay = daysInMonth[newMonth];  
        }
        string day = to_string(newDay);
        string month = to_string(newMonth);
        if (day.length() == 1) day = "0" + day;
        if (month.length() == 1) month = "0" + month;
        cout <<" <> Ngay het han goi tap la: " <<day << "/" << month << "/" << newYear << endl;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class GymPackage {
protected:
    string packageName; 
    string packageCode;    
    string packageContent; 
    int usageTime;  
    long packagePrice; 
    
public:
    GymPackage(){
      packageName = "";
      packageCode = "";
      packageContent = "";
      usageTime = 0;
      packagePrice = 0;
    }
    GymPackage(string name, string code, string content, int times, long price)
        : packageName(name), packageCode(code), packageContent(content), usageTime(times), packagePrice(price) {}

     void DisplayInfoGym() { 
        cout << " <> Ten goi: " << packageName << endl;
        cout << " <> Ma goi: " << packageCode << endl;
        cout << " <> Noi dung goi: " << packageContent << endl;
        cout << " <> Thoi gian su dung: " << usageTime << " thang" << endl;
        cout << " <> Gia goi: " << packagePrice << " VND" << endl;
    }
    void setName(string name){
        packageName = name;
    }
    string getName(){
        return packageName;
    }
    void setCode(string code){
        packageCode = code;
    }
    string getCode(){
        return packageCode;
    }
    void setContent(string content){
        packageContent = content;
    }
    string getContent(){
        return packageContent;
    }
    void setUsageTime(int times){
        usageTime = times;
    }
    int getUsageTime(){
        return usageTime;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Promotion : public GymPackage { 
private:
    int discountPercent;
    long payment;
    string schedule;
public:
    Promotion(){}
    Promotion(string name, string code, string content, int times, long price, int discount)
        : GymPackage(name, code, content, times, price), discountPercent(discount) {}
    void setDiscountPercent(int discount) {
        discountPercent = discount;
    }   
    int getDiscountPercent(){
        return discountPercent;
    }
    void setPrice(long price){
        packagePrice = price;
    }
    long getPrice(){
        return packagePrice;
    }
    long calculatePayment() { 
         payment = packagePrice - (packagePrice*discountPercent)/100;
        return payment;
    }
    friend  void PaymentMethod();
    void DisplayInfo() {
        DisplayInfoGym();
        cout << " <> Phan tram giam gia: " << discountPercent << "%" << endl;
        cout << " <> Tien thanh toan sau khi giam gia: " << calculatePayment() << " VND" << endl;
    }
    void detailedMenu(){
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout << "| Noi dung goi: " << packageContent <<endl;
        cout << "| Thoi gian su dung: " << usageTime << " thang " << endl;
        cout << "| Gia goi: " << packagePrice << " VND " << endl;
        cout << "| Phan tram giam gia: " << discountPercent << "% " << endl;
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    void saveScheduleToFile(string schedule) {
    ofstream myfile ("schedule.txt");
    if (myfile.is_open())
    {
        myfile << schedule;
        myfile.close();
        
    }
    else cout << "Khong mo duoc file."<<endl;
}
    string readScheduleFromFile() {
    string schedule;
    ifstream myfile ("schedule.txt");
    if (myfile.is_open())
    {
        getline(myfile, schedule);
        myfile.close();
    }
    else cout << "Khong mo duoc file.";
    return schedule;
}

    void setSchedule(string schedule){
      this->schedule = schedule;
      saveScheduleToFile(schedule);
  }
    void chooseGymSchedule() {
    cout << " <==> Chung toi co 3 khung gio cho ban lua chon:"<<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << " <> 1. Buoi sang: tu 6h den 8h.          "<<endl;
    cout << " <> 2. Buoi chieu: tu 14h den 16h.       "<<endl;
    cout << " <> 3. Buoi toi: tu 18h den 20h.         "<<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    int tempp;
    cout << " => Vui long chon khung gio tap cua ban (1, 2 hoac 3): ";
    cin >> tempp;
    switch (tempp) {
        case 1:
            schedule = "Buoi sang: tu 6h den 8h." ;
            setSchedule("Buoi sang: tu 6h den 8h.");
            break;
        case 2:
            schedule = "Buoi chieu: tu 14h den 16h.";
            setSchedule("Buoi chieu: tu 14h den 16h.");
            break;
        case 3:
            schedule = "Buoi toi: tu 18h den 20h.";
            setSchedule("Buoi toi: tu 18h den 20h.");
            break;
        default:
            cout << "Su lua chon khong hop le. Vui long thu lai.";
            chooseGymSchedule();
            return;
    }
    cout << "<==> Ban da chon khung gio tap Gym sau day: " << getSchedule() << endl;
}
  string getSchedule(){
    string schedule = readScheduleFromFile();
    setSchedule(schedule); 
    return this->schedule;
}
};
int temp;
  void PaymentMethod(Promotion y){ 
     cout<<"-------------------Chon phuong thuc thanh toan:-------------------- "<<endl;
     cout<<" <> 1.Thanh toan bang tien mat."<<endl;
     cout<<" <> 2.Thanh toan bang cach chuyen khoan."<<endl;
     cout<<"<=> Nhap 1 hoac 2 de chon phuong thuc thanh toan: ";
     cin>>temp;
     if(temp == 1) cout<<" <==> Ban da chon thanh toan bang tien mat.Vui long thanh toan: "<<y.calculatePayment()<<" VND"<<endl;
     if(temp == 2) {
         cout<<" <==>  Ban da chon thanh toan bang cach chuyen khoan, xin vui long quet ma QR de hoan tat viec thanh toan:"<<endl;
         cout<<"       So tien ban can thanh toan la: "<<y.calculatePayment()<<" VND"<<endl;
         cout<< "                   ¯¦¯¦¦¦¦¦¦¦¦¦  ¯¦¯¦¦"<<endl;
         cout<< "                   ¦¦¦¦¦¯¦¦¦¦¦¦¦¦¦¦_¦¯"<<endl;
         cout<< "                   ¦¦¯¦¦¦¦¦¦¦¦_¦¯¦¦¦¦ "<<endl;
         cout<< "                   ¦¦¦¦¦¦¯¦¦¦¦¦¦¦¦¦_¦¯"<<endl;
         cout<< "                   ¦¦¯¦¦¦¦¦¦¦¦¦¦_¦¯¦¦¦"<<endl;
         cout<< "                   ¦¦¦¦¦¦¯¦¦¦¦¦¦¦¦_¦¯¦"<<endl;
         cout<< "                   ¦¯¦¦¦¦¦_¦¯¦¦¦¦¦¦¦¦¦"<<endl;
         cout<< "                   ¦¦¦¦¦¯_¦¦¦¦¦¦¦¦¦¦¦¦"<<endl;
 }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void saveToFilePro(Promotion package) {
  ofstream outFile;
  outFile.open("promotion.txt",ios::app);
  outFile <<"Ten goi: "<< package.getName() << endl;
  outFile <<"Ma goi: "<< package.getCode() << endl;
  outFile <<"Noi dung goi: "<< package.getContent() << endl;
  outFile <<"Thoi gian su dung: "<< package.getUsageTime() << endl;
  outFile <<"Gia goi: "<<package.getPrice() << endl;
  outFile <<"Phan tram giam gia: "<< package.getDiscountPercent() << endl;
  outFile.close();
}
void readFromFilePro() {
  ifstream inFile;
  inFile.open("promotion.txt");

  if (!inFile) {
    cout << "Khong the mo tap tin!" << endl;
    return;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int main() {
        
PersonalTrainer* trainers = new PersonalTrainer[100];
  int count = 0;
  PersonalTrainer pt1;
  pt1.setName("Le Hoang Long");
  pt1.setPhone("0754368595");
  pt1.setSpecialize("gym");
  PersonalTrainer pt2;
  pt2.setName("Nguyen Thanh Dat");
  pt2.setPhone("0956239659");
  pt2.setSpecialize("tang can");
  PersonalTrainer pt3;
  pt3.setName("Duong Thanh Tien");
  pt3.setPhone("0354683782");
  pt3.setSpecialize("giam can");
  PersonalTrainer pt4;
  pt4.setName("Bui Van Vu");
  pt4.setPhone("0743849624");
  pt4.setSpecialize("boxing");
  PersonalTrainer pt5;
  pt5.setName("Le Thi Bao Han");
  pt5.setPhone("0835287765");
  pt5.setSpecialize("yoga");
  PersonalTrainer pt6;
  pt6.setName("Tran Thi Thanh Thuy");
  pt6.setPhone("0993457663");
  pt6.setSpecialize("dance");
  trainers[0] = pt1;
  trainers[1] = pt2;
  trainers[2] = pt3;
  trainers[3] = pt4;
  trainers[4] = pt5;
  trainers[5] = pt6;
  count = 6;
  writePT(trainers, count);
  delete[] trainers;
  trainers = readPT(count);

////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int choices;
    char change;
    Date D;
    Promotion mediumPackage("Goi Medium", "MED", "Goi binh thuong chi su dung tat ca dich vu tap luyen", 3, 1000000, 10);
    Promotion luxuryPackage("Goi Luxury", "LUX", "Goi cao cap  bao gom tat ca dich vu tap luyen va thuc an, nuoc uong mien phi"
    , 3, 2000000, 15);
    Promotion royarPackage("Goi Royar", "ROY","Goi dac biet bao gom tat ca dich vu tap luyen, thuc an, nuoc uong mien phi, co them personal Trainer huong dan"
    ,3,4000000,20);
  
  ///////////////////////////////////////////////////////////////////////////////////
    CustomerManagement manager;
        cout <<"             CHAO MUNG BAN DEN VOI PHONG TAP GYM BINKY           " << endl;
        cout <<"                       MOI BAN NHAP THONG TIN              "<<endl;
    while (true) {
        cout << "<<<<<<<<<<<<<<<<<<<<<<<TONG SO KHACH HANG>>>>>>>>>>>>>>>>>>>>>>>>>>: " << manager.count << endl;
        for (int i = 0; i < manager.count; i++) {
            cout << (i + 1) << ". " << manager.customers[i].getName() << endl;
        }
        cout << "_______________________________________________________________________________"<<endl;
        manager.printMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cin.ignore();
                Customer customer;
                cout << " => Ten khach hang: ";
                getline(cin, manager.name);
                customer.setName(manager.name);
                cout << " => Dia chi: ";
                getline(cin, manager.address);
                customer.setAddress(manager.address);
                cout << " => So dien thoai: ";
                getline(cin, manager.phone);
                customer.setPhone(manager.phone);
                manager.addCustomer(customer);
                break;
            }
            case 2: {
                int index;
                cout << " => Chon khach hang muon xoa: ";
                cin >> index;
                manager.removeCustomer(index - 1);
                cout<<" <==> Da xoa khach hang thanh cong!"<<endl;
                break;
            }
            case 3: {
                manager.saveToFile("danhsach_KH.txt");
                break;
            }
            case 4: {
                int index;
                cout << " => Chon khach hang muon xuat: ";
                cin >> index;
                manager.printCustomer(index-1);
                break;
            }
            case 5: {
                int index;
                cout << " => Chon khach hang muon dang ki goi tap : ";
                cin >> index;
                D.inputDate();
                do{
                cout << " ============================Menu cac goi tap voi khuyen mai:===========================" << endl;
                cout << " <> 1. Goi Medium" << endl;
                mediumPackage.detailedMenu();
                cout << " <> 2. Goi Luxury" << endl;
                luxuryPackage.detailedMenu();
                cout << " <> 3. Goi Royar" << endl;
                royarPackage.detailedMenu();
                cout << " => Vui long chon goi: ";
                cin >> choices;
                Promotion y;
                if (choices==1) y=mediumPackage;
                else if(choices==2) y=luxuryPackage;
                else if(choices==3) y=royarPackage;
                switch (choices) {
                    case 1:{
                        cout << "------------------------------Xuat Thong Tin Khuyen Mai----------------------------------" << endl;
                        mediumPackage.DisplayInfo();
                        saveToFilePro(mediumPackage);
                        break;
                    }
                    case 2:{
                        cout << "------------------------------Xuat Thong Tin Khuyen Mai----------------------------------" << endl;
                        luxuryPackage.DisplayInfo();
                        saveToFilePro(luxuryPackage);
                        break;
                    }
                    case 3:
                        cout << "------------------------------Xuat Thong Tin Khuyen Mai----------------------------------" << endl;
                        royarPackage.DisplayInfo();
                        saveToFilePro(royarPackage);
                        selectPT(trainers, count);
                        int choicess;
                        cout<<" => moi quy khach lua chon PT: ";
                        cin >> choicess;
                        if (choicess > count || choicess < 1) {
                        cout << " <> Luu chon khong hop le." << endl;
                        return -1;
                        } 
                        printPT(trainers[choicess -1],count);
                        delete[] trainers;
                        y.chooseGymSchedule();
                        break;
                    default:
                        cout << " <> Lua chon khong hop le." << endl;
                        break;
                }
                cout<<" "<<endl;
                cout<<" <===> Nhap N de thay doi viec dang ki hoac nhap bat ki ki tu nao de tiep tuc viec dang ki : ";
                cin>>change;
                }
                  while(change == 'n' || change == 'N');
                  Promotion y;
                  if (choices==1) y=mediumPackage;
                  else if(choices==2) y=luxuryPackage;
                  else if(choices==3) y=royarPackage;
                  PaymentMethod(y);
                  break;
                }
            case 6:{
                int index;
                cout << " => Chon khach hang muon xuat Bill: ";
                cin >> index;
                    
                cout << "------------------------------------------------HOA DON THANH TOAN----------------------------------------------------" << endl;
                manager.printCustomer(index-1);
                Promotion y;
                if (choices==1) y=mediumPackage;
                else if(choices==2) y=luxuryPackage;
                else if(choices==3) y=royarPackage;
                  
                y.DisplayInfo();
                if(choices == 3) readTrainersFromFile();
                if(choices == 3) cout<<" <> Khung gio tap ban chon la: "<<y.getSchedule()<<endl;
                if(temp == 1) cout<<" <> Ban da thanh toan bang tien mat."<<endl;
                else if (temp == 2) cout<<" <> Ban da thanh toan bang cach chuyen khoan."<<endl;
                D.DisplayRegistrationDate();
                D.DisplayExpirationDate();
                cout << "              CAM ON BAN DA SU DUNG PHONG GYM CUA CHUNG TOI                       "<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
                break;

                }
            case 7: {
                cout<<"=> CAM ON QUY KHACH DA DEN VOI CHUNG TOI"<<endl;
                cout<<"=> CHUC QUY KHACH MOT NGAY TOT LANH"<<endl;
                cout<<" <> Tam biet!"<<endl;
                return 0;
            }
            default: {
                cout << "==> Lua chon khong hop le!" <<endl;
                break;
            }
        }
    }
  return 0;
}