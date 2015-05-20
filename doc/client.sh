#!/bin/sh
# Клиент обменивается командами через FIFO файл созданный програмой server
#

#FIFO файл для обмена с сервером командами
FifoFile='./FIFO1'
clear
test -e $FifoFile
if [ $? -ne 0 ] 
then
 echo "FIFO file - '"$FifoFile "' does not exist"
 exit 1
fi
echo "Enter command for camera :"
read cmd
echo "write command to FIFO file ..."
echo $cmd > $FifoFile
echo "waiting for a answer from the server ..."
read ans < $FifoFile
echo "The answer from the server is "$ans

