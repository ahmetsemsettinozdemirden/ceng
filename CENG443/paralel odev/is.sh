#!/bin/bash
 
#SBATCH -J "GPU"                         # isin adi
 
#SBATCH -A ippgd1                         # account / proje adi
#SBATCH -p gpuq                          # kuyruk (partition/queue) adi
 
#SBATCH -n 4                             # cekirdek / islemci sayisi
#SBATCH -N 1                             # bilgisayar sayisi
#SBATCH --gres=gpu:1                     # ilave kaynak (1 gpu gerekli)
 
module load cuda/cuda-8.0
 
#calisacak gpu isi
./saxpy 250000000 4
