/*
 *  ofxTextWriter.h
 *  CFText
 *
 *  Created by Artem Titoulenko on 1/6/10.
 *  Copyright 2010 Artem Titoulenko. All rights reserved.
 *
 */

class ofxTextWriter {
private:
	string text;
	float timeToRender;
	float timeBegan;
	bool  timeSet, done;
	bool fullTimeMode;
    bool startRender;
public:
	
	//for use if you just want a blank TextWriter, for whatever reason.
	void init() { text = ""; }
	
	ofxTextWriter():timeSet(false),done(false),fullTimeMode(false),startRender(false),timeToRender(0)
    {
		init();
	}
	
	ofxTextWriter(string _text, float _timeToRender = 5):timeSet(false),done(false),fullTimeMode(false),startRender(false)
    {
		text = _text;
		timeToRender= _timeToRender;
	}
	
	string whatToRender() {
        if (startRender) {
            if(!done) {
                static int n = 0;
                if(!timeSet) {
                    timeBegan = ofGetElapsedTimef();
                    timeSet = true;
                    n = 0;
                }
                
                //Lets not draw it, that's too many resources we dont have.
                //Lets just return what part of the string should be already drawn.
                //That way people can decide what they want to do with it and how.
                
                if (!fullTimeMode) {
                    if (ofGetElapsedTimef() - timeBegan >= timeToRender) {
                        n++;
                        timeBegan = ofGetElapsedTimef();
                    }
                }else{
                    n = (int)(((ofGetElapsedTimef() - timeBegan) / (timeSet+timeToRender)) * text.length());
                }
                if (n + 1 == (int)text.length() ) done = true;
                
                return text.substr(0, min( n, (int)text.length()) ); //lets not access outside the buffer, eh?
            } else {
                return text;
            }
        }else{
            return "";
        }
	}
	
	/* -------- HELPER FUNCTIONS --------- */
	void resetTime() {
		timeSet = false;
        if (done) done = false;
	}
	
	void setTimeToRender(float _timeToRender) {
		resetTime();
		timeToRender = _timeToRender;
        fullTimeMode = true;
	}
    
    void setSeperateTimeToRender(float _timeToRender){
        resetTime();
		timeToRender = _timeToRender;
        fullTimeMode = false;
    }
	
	void setTextToRender(string _text) { text = _text; }
    
    void start(){ startRender = true; }
	
	bool isDone() { return done; }
};