#!/bin/bash 
./shutdown.sh 

#client reset of the code 
cd client/ 
rm -rf src/
unzip .replace.zip -d tmp/
mkdir src/
mv tmp/client/src/src/ ./
rm tmp/ -rf

# backend reset of the code 
cd ../ 
rm -rf react-backend/routes/ 
rm -rf react-backend/sql/ 
rm -rf react-backend/views/ 
rm -rf react-backend/app.js 
rm -rf react-backend/package.json
cd react-backend/
unzip .replace.zip -d .
mv react-backend/* ./
rm react-backend/ -rf
cd ..

zip -r ./client/.replace.zip client/src


zip -r ./react-backend/.replace.zip react-backend/routes/ react-backend/sql/ react-backend/views/ react-backend/app.js react-backend/package.json
