#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
using namespace std;

struct Triangle {
    double Normal[3];
    double V1[3];
    double V2[3];
    double V3[3];
};

int main()
{
    string filename = "E:\\PROJECT\\cube.stl";
    ifstream ip(filename);
    ifstream in(filename);
    string line;
    string c1 = "normal";
    string c2 = "vertex";
    int v = 0;
    int n = 0;
    int f = 0;
    
    if (ip.is_open())
    {
        while (getline(ip, line)) {
            if (line.find(c1) != std::string::npos) {
                n++;
                f = 1;
            }
        }
        ip.close();
    }
    if (f==1){
        Triangle* t = (Triangle*)malloc(sizeof(Triangle) * n);
        int i = 0;
        if (in.is_open())
        {

            while (getline(in, line)) {
                

                if (line.find(c1) != std::string::npos) {

                    size_t found = line.find(" ");
                    found = line.find(" ", found + 15);
                    string f = line.substr(15, found - 15);
                    t[i].Normal[0] = std::stod(f);

                    int k = found + 1;
                    found = line.find(" ", found + 1);
                    f = line.substr(k, found - k);
                    t[i].Normal[1] = std::stod(f);

                    k = found + 1;
                    found = line.find(" ", found + 1);
                    f = line.substr(k, found - k);
                    t[i].Normal[2] = std::stod(f);

                }


                if (line.find(c2) != std::string::npos) {
                    if (v == 0) {

                        size_t found = line.find(" ");
                        found = line.find(" ", found + 13);
                        string f = line.substr(13, found - 13);
                        t[i].V1[0] = std::stod(f);

                        int k = found + 1;
                        found = line.find(" ", found + 1);
                        f = line.substr(k, found - k);
                        t[i].V1[1] = std::stod(f);

                        k = found + 1;
                        found = line.find(" ", found + 1);
                        f = line.substr(k, found - k);
                        t[i].V1[2] = std::stod(f);

                        v = 1;

                    }
                    else if (v == 1) {

                        size_t found = line.find(" ");
                        found = line.find(" ", found + 13);
                        string f = line.substr(13, found - 13);
                        t[i].V2[0] = std::stod(f);

                        int k = found + 1;
                        found = line.find(" ", found + 1);
                        f = line.substr(k, found - k);
                        t[i].V2[1] = std::stod(f);

                        k = found + 1;
                        found = line.find(" ", found + 1);
                        f = line.substr(k, found - k);
                        t[i].V2[2] = std::stod(f);

                        v = 2;

                    }
                    else if (v == 2) {

                        size_t found = line.find(" ");
                        found = line.find(" ", found + 13);
                        string f = line.substr(13, found - 13);
                        t[i].V3[0] = std::stod(f);

                        int k = found + 1;
                        found = line.find(" ", found + 1);
                        f = line.substr(k, found - k);
                        t[i].V3[1] = std::stod(f);

                        k = found + 1;
                        found = line.find(" ", found + 1);
                        f = line.substr(k, found - k);
                        t[i].V3[2] = std::stod(f);

                        v = 0;
                        i++;

                    }

                }
            }
            in.close();

        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < 3; i++)    cout << t[j].Normal[i] << ',';
            cout << '\n';
            for (int i = 0; i < 3; i++)    cout << t[j].V1[i] << ',';
            cout << '\n';
            for (int i = 0; i < 3; i++)    cout << t[j].V2[i] << ',';
            cout << '\n';
            for (int i = 0; i < 3; i++)    cout << t[j].V3[i] << ',';
            cout << '\n';
            cout << '\n';
        }
    }
    else {
        ifstream ifs(filename, ifstream::binary);
        filebuf* pbuf = ifs.rdbuf();

        auto size = pbuf->pubseekoff(0, ifs.end);
        pbuf->pubseekpos(0);


        char* buffer = new char[(size_t)size];
        pbuf->sgetn(buffer, size);
        char* bufptr = buffer;
        bufptr += 80;
        int n = *(unsigned int*)(bufptr);
        bufptr += 4;



        Triangle* t = (Triangle*)malloc(sizeof(Triangle) * n);
        for (int i = 0; i < n; i++) {
            t[i].Normal[0] = *(float*)(bufptr);
            t[i].Normal[1] = *(float*)(bufptr + 4);
            t[i].Normal[2] = *(float*)(bufptr + 8);
            bufptr += 12;

            t[i].V1[0] = *(float*)(bufptr);
            t[i].V1[1] = *(float*)(bufptr + 4);
            t[i].V1[2] = *(float*)(bufptr + 8);
            bufptr += 12;

            t[i].V2[0] = *(float*)(bufptr);
            t[i].V2[1] = *(float*)(bufptr + 4);
            t[i].V2[2] = *(float*)(bufptr + 8);
            bufptr += 12;

            t[i].V3[0] = *(float*)(bufptr);
            t[i].V3[1] = *(float*)(bufptr + 4);
            t[i].V3[2] = *(float*)(bufptr + 8);
            bufptr += 14;

        }

        ifs.close();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < 3; i++)    cout << t[j].Normal[i] << ',';
            cout << '\n';
            for (int i = 0; i < 3; i++)    cout << t[j].V1[i] << ',';
            cout << '\n';
            for (int i = 0; i < 3; i++)    cout << t[j].V2[i] << ',';
            cout << '\n';
            for (int i = 0; i < 3; i++)    cout << t[j].V3[i] << ',';
            cout << '\n';
            cout << '\n';
        }
    }
    

}
