#include <iostream>
using namespace std;

class Node {
public:
    int giaTri;
    Node* nhanhTrai;
    Node* nhanhPhai;

    Node(int giaTriMoi) {
        giaTri = giaTriMoi;
        nhanhTrai = nhanhPhai = nullptr;
    }
};

class CayNhiPhanTimKiem {
public:
    Node* goc;

    CayNhiPhanTimKiem() {
        goc = nullptr;
    }

    void chen(int giaTriMoi) {
        goc = chenDeQuy(goc, giaTriMoi);
    }

    void duyetLNR() {
        duyetLNRDeQuy(goc);
        cout << endl;
    }

    void xoa(int giaTriXoa) {
        goc = xoaDeQuy(goc, giaTriXoa);
    }

private:
    Node* chenDeQuy(Node* nut, int giaTriMoi) {
        if (nut == nullptr) {
            return new Node(giaTriMoi);
        }
        if (giaTriMoi < nut->giaTri) {
            nut->nhanhTrai = chenDeQuy(nut->nhanhTrai, giaTriMoi);
        } else {
            nut->nhanhPhai = chenDeQuy(nut->nhanhPhai, giaTriMoi);
        }
        return nut;
    }

    Node* xoaDeQuy(Node* nut, int giaTriXoa) {
        if (nut == nullptr) return nut;
        if (giaTriXoa < nut->giaTri) {
            nut->nhanhTrai = xoaDeQuy(nut->nhanhTrai, giaTriXoa);
        } else if (giaTriXoa > nut->giaTri) {
            nut->nhanhPhai = xoaDeQuy(nut->nhanhPhai, giaTriXoa);
        } else {
            if (nut->nhanhTrai == nullptr) {
                Node* tam = nut->nhanhPhai;
                delete nut;
                return tam;
            } else if (nut->nhanhPhai == nullptr) {
                Node* tam = nut->nhanhTrai;
                delete nut;
                return tam;
            }
            Node* tam = timMin(nut->nhanhPhai);
            nut->giaTri = tam->giaTri;
            nut->nhanhPhai = xoaDeQuy(nut->nhanhPhai, tam->giaTri);
        }
        return nut;
    }

    Node* timMin(Node* nut) {
        while (nut->nhanhTrai != nullptr) {
            nut = nut->nhanhTrai;
        }
        return nut;
    }

    void duyetLNRDeQuy(Node* nut) {
        if (nut != nullptr) {
            duyetLNRDeQuy(nut->nhanhTrai);
            cout << nut->giaTri << " ";
            duyetLNRDeQuy(nut->nhanhPhai);
        }
    }
};

int main() {
    CayNhiPhanTimKiem cay;
    int danhSach[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int so : danhSach) {
        cay.chen(so);
    }
    cout << "Cay nhi phan ban dau: ";
    cay.duyetLNR();

    int them[] = {14, 0, 35};
    for (int so : them) {
        cay.chen(so);
    }
    cout << "Sau khi chen 14, 0, 35: ";
    cay.duyetLNR();

    int xoa[] = {6, 13, 35};
    for (int so : xoa) {
        cay.xoa(so);
    }
    cout << "Sau khi xoa 6, 13, 35: ";
    cay.duyetLNR();
    return 0;
}
