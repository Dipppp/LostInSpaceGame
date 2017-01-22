#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(BITMAP *Screen, BITMAP *ImagePage, SoundEffects *SoundEffect){
	mScreen = Screen;
	mImagePage = ImagePage;
	
	mBackgroundWidth = SCREEN_W;
	mBackgroundHeight = SCREEN_H;
	mBackgroundImage = create_bitmap(mBackgroundWidth,mBackgroundHeight);
	blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	
	mLetterAndNumWidth = 10;
	mLetterAndNumHeight = 13;
	mAllLetters = create_bitmap(mLetterAndNumWidth*26,mLetterAndNumHeight); 
	clear_to_color(mAllLetters, makecol(255, 0, 255));
	blit(mImagePage,mAllLetters,0,mBackgroundHeight,0,0,mLetterAndNumWidth*26,mLetterAndNumHeight);
	mAllNumbers = create_bitmap(mLetterAndNumWidth*10,mLetterAndNumHeight); 
	clear_to_color(mAllNumbers, makecol(255, 0, 255));
	blit(mImagePage,mAllNumbers,0,mBackgroundHeight+mLetterAndNumHeight,0,0,mLetterAndNumWidth*10,mLetterAndNumHeight);
	
	mNameBox = create_bitmap(mLetterAndNumWidth*10,mLetterAndNumHeight); 
	clear_to_color(mNameBox, makecol(255, 0, 255));
	
	mHighScoreWidth = mLetterAndNumWidth*25;
	mHighScoreHeight = 13;
	mHighScores = new BITMAP*[10];
	mName = new string[10];
	mScore = new string[10];
	for(int i = 0; i < 10; i++){
		mHighScores[i] = create_bitmap(mHighScoreWidth,mHighScoreHeight); 
		clear_to_color(mHighScores[i], makecol(255, 0, 255));
	}
	
	mNameEnter = true;
	mPlayAgain = false;
	mEnterButton = new Button(SoundEffect,350,307,101,23);
	mPlayAgainButton = new Button(SoundEffect,299,503,202,200);
	
	mInputBox = create_bitmap(400,200); 
	blit(mImagePage,mInputBox,0,mBackgroundHeight+mLetterAndNumHeight+mLetterAndNumHeight,0,0,400,200);
	
}

GameOverScreen::~GameOverScreen(){
	destroy_bitmap(mAllLetters); 
	destroy_bitmap(mAllNumbers); 
	destroy_bitmap(mInputBox); 
	destroy_bitmap(mNameBox); 
	for(int i = 0; i < 10; i++){
		destroy_bitmap(mHighScores[i]); 
	}
	delete mName;
	delete mScore;
	delete mEnterButton;
	delete mPlayAgainButton;
}

void GameOverScreen::gameoverSwitch(int Score){
	loadFromFileHighScores();
	int temp;
	stringstream ss; 
	ss << Score;
	for(int i = 0; i < 10; i++){
		istringstream buffer(mScore[i]);
		temp = 0;
		buffer >> temp;
		if (temp < Score){
			string tempA = mName[i];
			string tempB = mScore[i];
			for(int j = i+1; j < 10; j++){
				string replaceName = tempA;
				string replaceScore = tempB;
				if(j < 9){
					tempA = mName[j];
					tempB = mScore[j];
				}
				mName[j] = replaceName;
				mScore[j] = replaceScore;
			}
			mNameEnter = false;
			mTempName = "";
			mPositionToReplace = i;
			mScore[i] = ss.str();
			break;
		}
	}
}

void GameOverScreen::update(){
	//textprintf_ex(mScreen, font, 400, 305, makecol(0,0,255), -1, "b");
	if(!mNameEnter){
		mTempName = inputText(mTempName);
		clear_to_color(mNameBox, makecol(255, 0, 255));
		loadLetterToBitmap(mTempName, mNameBox);
	}
	
}

void GameOverScreen::draw(){
	BaseInterface::draw();
	if(!mNameEnter){
		draw_sprite(mScreen, mInputBox, 201, 200);
		draw_sprite(mScreen,mNameBox,352,280);
	}else{
		displayHighScore();
	}
}

void GameOverScreen::displayHighScore(){
	int x = 300;
	int y = 150;
	//textprintf_ex(screen, font, 250, 105, makecol(0,0,255), -1, "%d", (15*mLetterAndNumWidth));
	for(int i = 0; i < 10; i++){
		clear_to_color(mHighScores[i], makecol(255, 0, 255));
		loadLetterToBitmap(mName[i], mHighScores[i]);
		loadNumberToBitmap(mScore[i], mHighScores[i], (15*mLetterAndNumWidth));
		draw_sprite(mScreen, mHighScores[i], x, y);
		y+=25;
	}
	
}

void GameOverScreen::clicked(int X, int Y){
	if(!mNameEnter){
		if(mEnterButton->clicked(X,Y)){
			mNameEnter = true;
			mName[mPositionToReplace] = mTempName;
			saveToFileHighScores();
		}
	}else{
		if(mPlayAgainButton->clicked(X,Y)){
			mPlayAgain = true;
		}
	}
}

void GameOverScreen::unSetPlayAgain(){
	mPlayAgain =false;
}

bool GameOverScreen::getPlayAgain(){
	return mPlayAgain;
}

//Private Methods
void GameOverScreen::loadFromFileHighScores(){
	int i = 0;
	ifstream myReadFile;
	bool switcher = true;
	myReadFile.open("HighScore.txt");
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			if(!myReadFile.eof()){
				if(i < 10){
					if(switcher){
						getline(myReadFile,mName[i]);
						switcher = false;
					}else{
						getline(myReadFile,mScore[i]);
						switcher = true;
						i++;
					}
				}else{
					break;
				}
			}
		}
	}
	myReadFile.close();
}

void GameOverScreen::saveToFileHighScores(){
	ofstream myWriteFile;
	myWriteFile.open("HighScore.txt");
	if (myWriteFile.is_open()) {
		for(int i = 0; i < 10; i++){
			myWriteFile << mName[i] << "\n";
			myWriteFile << mScore[i] << "\n";
		}
	}
	myWriteFile.close();
}

void GameOverScreen::loadLetterToBitmap(string Text, BITMAP *image){
	int num = 0;
	string temp;
	
	for(int i = 0; i < Text.length(); i++){
		temp = Text[i];
		num = int(*temp.c_str())-65;
		blit(mAllLetters,image,mLetterAndNumWidth*num,0,mLetterAndNumWidth*i,0,mLetterAndNumWidth,mLetterAndNumHeight);
	
	}
}

void GameOverScreen::loadNumberToBitmap(string Text, BITMAP *image, int BitmapStartX){
	int num = 0;
	string temp;
	for(int i = 0; i < Text.length(); i++){
		temp = Text[i];
		num = int(*temp.c_str())-48;
		blit(mAllNumbers,image,mLetterAndNumWidth*num,0,BitmapStartX+(mLetterAndNumWidth*i),0,mLetterAndNumWidth,mLetterAndNumHeight);
	}
}

string GameOverScreen::inputText(string CurrentString){
	if(CurrentString.length() < 10){
		if(key[KEY_A]){
			CurrentString = CurrentString+"A";
		}else if(key[KEY_B]){
			CurrentString = CurrentString+"B";
		}else if(key[KEY_C]){
			CurrentString = CurrentString+"C";
		}else if(key[KEY_D]){
			CurrentString = CurrentString+"D";
		}else if(key[KEY_E]){
			CurrentString = CurrentString+"E";
		}else if(key[KEY_F]){
			CurrentString = CurrentString+"F";
		}else if(key[KEY_G]){
			CurrentString = CurrentString+"G";
		}else if(key[KEY_H]){
			CurrentString = CurrentString+"H";
		}else if(key[KEY_I]){
			CurrentString = CurrentString+"I";
		}else if(key[KEY_J]){
			CurrentString = CurrentString+"J";
		}else if(key[KEY_K]){
			CurrentString = CurrentString+"K";
		}else if(key[KEY_L]){
			CurrentString = CurrentString+"L";
		}else if(key[KEY_M]){
			CurrentString = CurrentString+"M";
		}else if(key[KEY_N]){
			CurrentString = CurrentString+"N";
		}else if(key[KEY_O]){
			CurrentString = CurrentString+"O";
		}else if(key[KEY_P]){
			CurrentString = CurrentString+"P";
		}else if(key[KEY_Q]){
			CurrentString = CurrentString+"Q";
		}else if(key[KEY_R]){
			CurrentString = CurrentString+"R";
		}else if(key[KEY_S]){
			CurrentString = CurrentString+"S";
		}else if(key[KEY_T]){
			CurrentString = CurrentString+"T";
		}else if(key[KEY_U]){
			CurrentString = CurrentString+"U";
		}else if(key[KEY_V]){
			CurrentString = CurrentString+"V";
		}else if(key[KEY_W]){
			CurrentString = CurrentString+"W";
		}else if(key[KEY_X]){
			CurrentString = CurrentString+"X";
		}else if(key[KEY_Y]){
			CurrentString = CurrentString+"Y";
		}else if(key[KEY_Z]){
			CurrentString = CurrentString+"Z";
		}
	}
	if(key[KEY_BACKSPACE]){
		CurrentString.erase(CurrentString.length()-1,CurrentString.length()-1);
	}
	rest(125);
	return CurrentString;
}
