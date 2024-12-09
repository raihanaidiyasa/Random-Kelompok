#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>
#include <string>
#include <QApplication>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QFileDialog>
using namespace std;

const int MAX_ANGGOTA = 100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Pilih File", "", "Text Files (*.txt)");
    ui->lineAbsolutPath->setText(fileName);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString namaFile = ui->lineAbsolutPath->text();
    int jumlahKelompok = ui->lineJumlahKel->text().toInt();
    QString jumlahKelompokText = ui->lineJumlahKel->text();
    bool pembagianRata = ui->cbBagiRata->isChecked();

    ifstream listNama(namaFile.toStdString());
    if (listNama.is_open()) {
        string anggota[MAX_ANGGOTA];
        string anggotaL[MAX_ANGGOTA];
        string anggotaP[MAX_ANGGOTA];

        string nama;
        int jumlahAnggota = 0;
        while (getline(listNama, nama) && jumlahAnggota < MAX_ANGGOTA) {
            anggota[jumlahAnggota] = nama;
            jumlahAnggota++;
        }
        listNama.close();

        // Random generator untuk menambah efektivitas pengacakan
        random_device rd;
        mt19937 generator(rd());

        // Mengacak urutan anggota dalam kelompok
        shuffle(anggota, anggota + jumlahAnggota, generator);

        // Pembagian anggota menjadi kelompok
        string hasil[jumlahKelompok];
        string hasilFinal;
        int jumlahAnggotaL = 0;
        int jumlahAnggotaP = 0;
        // Dibuat anggotaCount agar indeks tidak reset ketika pengulangan
        int anggotaLCount = 0;
        int anggotaPCount = 0;
        int anggotaCount = 0;

        // Jika membagi rata laki-laki dan perempuan
        if (pembagianRata) {
            // Menentukan laki-laki dan perempuan
            for (int i = 0; i < jumlahAnggota; i++){
                int len = anggota[i].length();

                if (anggota[i][len-2] == 'L'){
                    anggotaL[jumlahAnggotaL] = anggota[i];
                    jumlahAnggotaL++;
                }
                else if (anggota[i][len-2] == 'P'){
                    anggotaP[jumlahAnggotaP] = anggota[i];
                    jumlahAnggotaP++;
                }
            }
            int anggotaLPerKelompok = jumlahAnggotaL / jumlahKelompok;
            int anggotaPPerKelompok = jumlahAnggotaP / jumlahKelompok;

            // Hitung jumlah sisa anggota yang tidak terbagi merata
            int sisaAnggotaL = jumlahAnggotaL % jumlahKelompok;
            int sisaAnggotaP = jumlahAnggotaP % jumlahKelompok;
            for (int i = 0; i < jumlahKelompok; i++) {
                hasil[i] += "Kelompok " + to_string(i + 1) + ":\n";

                for (int j = 0; j < anggotaLPerKelompok; j++) {
                    hasil[i] += anggotaL[anggotaLCount] + "\n";
                    anggotaLCount++;
                }

                if (sisaAnggotaL > 0) {
                    hasil[i] += anggotaL[anggotaLCount] + "\n";
                    anggotaLCount++;
                    sisaAnggotaL--;
                }

                for (int j = 0; j < anggotaPPerKelompok; j++) {
                    hasil[i] += anggotaP[anggotaPCount] + "\n";
                    anggotaPCount++;
                }

                if (sisaAnggotaP > 0) {
                    hasil[i] += anggotaP[anggotaPCount] + "\n";
                    anggotaPCount++;
                    sisaAnggotaP--;
                }
                hasil[i] += "\n";
            }
        }
        // Jika tidak membagi rata laki-laki dan perempuan
        else {
            int anggotaPerKelompok = jumlahAnggota / jumlahKelompok;
            int sisaAnggota = jumlahAnggota % jumlahKelompok;
            for (int i = 0; i < jumlahKelompok; i++) {
                hasil[i] += "Kelompok " + to_string(i + 1) + ":\n";


                for (int j = 0; j < anggotaPerKelompok; j++) {
                    hasil[i] += anggota[anggotaCount] + "\n";
                    anggotaCount++;
                }

                if (sisaAnggota > 0) {
                    hasil[i] += anggota[anggotaCount] + "\n";
                    anggotaCount++;
                    sisaAnggota--;
                }
                hasil[i] += "\n";
            }
        }


        for (int i = 0; i < jumlahKelompok; i++) {
            hasilFinal += hasil[i];
        }

        ui->hasilTextEdit->setPlainText(QString::fromStdString(hasilFinal));
    }
    else {
        ui->hasilTextEdit->setPlainText("File tidak terbaca!");
    }

    if (jumlahKelompokText.isEmpty()) {
        ui->hasilTextEdit->setPlainText("Mohon untuk memasukkan jumlah kelompok!");
        return;
    }

    if (jumlahKelompok <= 0) {
        ui->hasilTextEdit->setPlainText("Jumlah Kelompok tidak valid!");
        return;
    }
}

