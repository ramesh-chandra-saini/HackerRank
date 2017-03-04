/*
    RAMESH CHANDRA
*/
#include<bits/stdc++.h>
using namespace std;

void printImage(vector<string>&image){
    for(int i=0;i<image.size();i++)
        cout<<image[i]<<endl;
}
void dilatedPixel(pair<int,int> imagePixel,vector<string>&dilatedImage,vector<string>&mask,pair<int,int>centerOfMask){
    int N = dilatedImage.size();
    int M = dilatedImage[0].length();
    int deltaI = centerOfMask.first;
    int deltaJ = centerOfMask.second;

    for(int i=imagePixel.first-deltaI,mask_i=0;mask_i<mask.size();mask_i++,i++){
        for(int j=imagePixel.second-deltaJ,mask_j=0;mask_j<mask[mask_i].length();mask_j++,j++){
            if(mask[mask_i][mask_j]=='0') //no operation required....as mask contain 0
                continue;
            if(i<0 || i>= N || j<0 || j>=M) //out of image
                continue;

            if(dilatedImage[i][j]=='0') //pixel contain atleast one zero where mask contain 1
               dilatedImage[i][j]='1';
        }
    }
}
vector<string> dilation(vector<string>&image,vector<string>&mask,pair<int,int>centerOfMask){
    vector<string> dilatedImage = image;

    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].length();j++){

            if(image[i][j]=='0')  //don't need to any thing
                continue;
            //check for this pixel
            dilatedPixel({i,j},dilatedImage,mask,centerOfMask);
        }
    }
    return dilatedImage;
}
int erodedPixel(pair<int,int> imagePixel,vector<string>&image,vector<string>&mask,pair<int,int>centerOfMask){
    int N = image.size();
    int M = image[0].length();
    int deltaI = centerOfMask.first;
    int deltaJ = centerOfMask.second;

    for(int i=imagePixel.first-deltaI,mask_i=0;mask_i<mask.size();mask_i++,i++){
        for(int j=imagePixel.second-deltaJ,mask_j=0;mask_j<mask[mask_i].length();mask_j++,j++){
            if(mask[mask_i][mask_j]=='0') //no operation required....as mask contain 0
                continue;
            if(i<0 || i>= N || j<0 || j>=M) //out of image
                return 0;

            if(image[i][j]=='0') //pixel contain atleast one zero where mask contain 1
               return 0;
        }
    }
    return 1;
}
vector<string> erosion(vector<string>&image,vector<string>&mask,pair<int,int>centerOfMask){
    vector<string> erodedImage = image;

    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[i].length();j++){

            if(image[i][j]=='0')  //don't need to any thing
                continue;
            //check for this pixel
            erodedImage[i][j] = char(erodedPixel({i,j},image,mask,centerOfMask)+'0');
        }
    }
    return erodedImage;
}
int main() {

    vector<string> image =  {
                                "0000000000",
                                "0111111100",
                                "0000111100",
                                "0000111100",
                                "0001111100",
                                "0000111100",
                                "0001100000",
                                "0000000000",
                                "0000000000"
                            };
    vector<string> mask = {
                            "111",
                            "111",
                            "111"
                           };
    //printImage(image);
    vector<string> erodedImage = erosion(image,mask,{1,1});
    //printImage(erodedImage);
    vector<string> dilatedImage = dilation(erodedImage,mask,{1,1});
    //printImage(dilatedImage);
    int count_one = 0;
    for(int i=0;i<dilatedImage.size();i++)
        for(int j=0;j<dilatedImage[i].length();j++)
            count_one+=(dilatedImage[i][j]=='1');
    cout<<count_one<<endl;
    return 0;
}



