#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <pthread.h>
#include <thread>
#include <vector>
using namespace std;
class Timer{
private:
using clock_t=std::chrono::high_resolution_clock;
using second_t =std::chrono::duration<double,std::ratio<1>>;
std::chrono::time_point<clock_t> m_beg;
public:
Timer():m_beg(clock_t::now()){
}
void reset(){
m_beg=clock_t::now();
}
double elapsed() const{
return std::chrono::duration_cast<second_t>(
clock_t::now()-m_beg).count();
}
};
int char_to_int(char value) {
char temp[2]="";
temp[0] = value;
temp[1] = '\0';
int result = atoi(temp);
return result;
}
long sum_all_number_in_string(string long_value) {
int n = long_value.length();
long sum = 0;
for (int i = 0; i < n; i++) {
sum +=char_to_int(long_value[i]);
}
return sum;
}
bool div_to_2(string long_value) {
int n = long_value.length();
if (long_value[n - 1] % 2 == 0) {
return true;
}
else {
return false;
}
}
bool div_to_3(string long_value) {
long sum = sum_all_number_in_string(long_value);
if (sum % 3 == 0) {
return true;
}
else {
return false;
}
}
bool div_to_4(string long_value) {
int n = long_value.length();
if (long_value[n - 1]=='0' && long_value[n - 2] == '0') {
return true;
}
string two_last_values;
two_last_values.push_back(long_value[n - 2]);
two_last_values.push_back(long_value[n - 1]);
if (std::stoi(two_last_values) % 4 == 0) {
return true;
}
else {
return false;
}
}
bool div_to_5(string long_value) {
int n = long_value.length();
if (long_value[n - 1] == '5' || long_value[n - 1] == '0') {
return true;
}
else {
return false;
}
}
bool div_to_6(string long_value) {
if (div_to_2(long_value) && div_to_3(long_value)) {
return true;
}
else {
return false;
}
}
bool div_to_7(string long_value) {
int n=long_value.length();
int n_triad_no=n%3;
int triad_length=n/3-n_triad_no+1;
vector<int> triad;
int sum=0;
if(n_triad_no==1){
string buffer="";
buffer.push_back(long_value[0]);
triad.push_back(stoi(buffer));
int i=1;
while(i<n-3){
for(int j=1;j<triad_length;j++){
string temp="";
temp.push_back(long_value[i]);
temp.push_back(long_value[i+1]);
temp.push_back(long_value[i+2]);
triad.push_back(stoi(temp));
i+=3;
}
}
}
if(n_triad_no==2){
string buffer="";
buffer.push_back(long_value[0]);
buffer.push_back(long_value[1]);
triad.push_back(stoi(buffer));
int i=2;
while(i<n-3){
for(int j=1;j<triad_length;j++){
string temp="";
temp.push_back(long_value[i]);
temp.push_back(long_value[i+1]);
temp.push_back(long_value[i+2]);
triad.push_back(stoi(temp));
i+=3;
}
}
}
for(int i=0;i<triad_length;i++){
if((i%2)!=0){
triad[i]=triad[i]*(-1);
}
sum+=triad[i];
}
if(sum%7==0){
return true;
}
else{
return false;
}
}
bool div_to_8(string long_value) {
int n = long_value.length();
string three_last_values;
three_last_values.push_back(long_value[n - 3]);
three_last_values.push_back(long_value[n - 2]);
three_last_values.push_back(long_value[n - 1]);
if (stoi(three_last_values) % 8 == 0) {
return true;
}
else {
return false;
}
}
bool div_to_9(string long_value) {
if (sum_all_number_in_string(long_value) % 8 == 0) {
return true;
}
else {
return false;
}
}
bool div_to_10(string long_value) {
int n = long_value.length();
if (long_value[n - 1] == '0') {
return true;
}
else {
return false;
}
}
void simple_main(){
Timer t;
setlocale(LC_ALL, "rus");
ifstream ifst("input.txt");
string long_value_string;
ifst >> long_value_string;
bool temp=div_to_7(long_value_string);
cout << "Число делится на 2 без остатка?"<<endl;
if (div_to_2(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 3 без остатка?"<<endl;
if (div_to_3(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 4 без остатка?"<<endl;
if (div_to_4(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 5 без остатка?"<<endl;
if (div_to_5(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 6 без остатка?"<<endl;
if (div_to_6(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 7 без остатка?"<<endl;
if (div_to_7(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 8 без остатка?"<<endl;
if (div_to_8(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 9 без остатка?"<<endl;
if (div_to_9(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 10 без остатка?"<<endl;
if (div_to_10(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout<<"Затрачено времени:"<<t.elapsed()<<endl;
}
void* f1(void *param){
string long_value_string=*static_cast<string*>(param);
cout << "Число делится на 2 без остатка?"<<endl;
if (div_to_2(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 3 без остатка?"<<endl;
if (div_to_3(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
return nullptr;
}
void* f2(void *param){
string long_value_string=*static_cast<string*>(param);
cout << "Число делится на 4 без остатка?"<<endl;
if (div_to_4(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 5 без остатка?"<<endl;
if (div_to_5(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
return nullptr;
}
void* f3(void*param){
string long_value_string=*static_cast<string*>(param);
cout << "Число делится на 6 без остатка?"<<endl;
if (div_to_6(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 7 без остатка?"<<endl;
if (div_to_7(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 8 без остатка?"<<endl;
if (div_to_8(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
return nullptr;
}
void* f4(void*param){
string long_value_string=*static_cast<string*>(param);
cout << "Число делится на 9 без остатка?"<<endl;
if (div_to_9(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 10 без остатка?"<<endl;
if (div_to_10(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
return nullptr;
}
void t1(string param){
string long_value_string=param;
cout << "Число делится на 2 без остатка?"<<endl;
if (div_to_2(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 3 без остатка?"<<endl;
if (div_to_3(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
}
void t2(string param){
string long_value_string=param;
cout << "Число делится на 4 без остатка?"<<endl;
if (div_to_4(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 5 без остатка?"<<endl;
if (div_to_5(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
}
void t3(string param){
string long_value_string=param;
cout << "Число делится на 6 без остатка?"<<endl;
if (div_to_6(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 8 без остатка?"<<endl;
if (div_to_8(long_value_string)) {
cout << "Да." << endl;
}
else {
cout << "Нет." << endl;
}
}
void t4(string param){
string long_value_string=param;
cout << "Число делится на 9 без остатка?"<<endl;
if (div_to_9(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
cout << "Число делится на 10 без остатка?"<<endl;
if (div_to_10(long_value_string)) {
cout << "Да."<<endl;
}
else {
cout << "Нет." << endl;
}
}
void parallel_main(){
Timer t;
setlocale(LC_ALL, "rus");
ifstream ifst("input.txt");
string long_value_string;
ifst>>long_value_string;
pthread_t thread[4];
pthread_create(&thread[0],NULL,f1,&long_value_string);
pthread_create(&thread[1],NULL,f2,&long_value_string);
pthread_create(&thread[2],NULL,f3,&long_value_string);
pthread_create(&thread[3],NULL,f4,&long_value_string);
pthread_join(thread[0],NULL);
pthread_join(thread[1],NULL);
pthread_join(thread[2],NULL);
pthread_join(thread[3],NULL);
cout<<"Затрачено времени:"<<t.elapsed()<<endl;
}
void parallel_main2(){
Timer t;
setlocale(LC_ALL, "rus");
ifstream ifst("input.txt");
string long_value_string;
ifst>>long_value_string;
thread thread1(t1,long_value_string);
thread thread2(t2,long_value_string);
thread thread3(t3,long_value_string);
thread thread4(t4,long_value_string);
thread1.join();
thread2.join();
thread3.join();
thread4.join();
cout<<"Затрачено времени:"<<t.elapsed()<<endl;
}
int main() {
cout<<"Один поток"<<endl;
simple_main();
cout<<"Много потоков.Pthread"<<endl;
parallel_main();
cout<<"Много потоков.Thread"<<endl;
//
 parallel_main2();
}
