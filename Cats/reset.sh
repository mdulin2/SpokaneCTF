#!/bin/bash
mv .replace.zip ../
cd ..
rm -rf Cats 

# Replace existing file structure 
unzip .replace.zip -d Cats/ 
rm .replace.zip 
cd Cats 
zip -r .replace.zip .
