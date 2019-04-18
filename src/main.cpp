/**
* Thai Painting Restoration 
* Author: Pakkapon Phongthawee (github.com/pureexe)
* This is part of my final project at Silpakorn University
**/
#include "header.h"

#include "inpainter/toDoubleBand.h"
#include "inpainter/MultiColorSplitBergman.h"

string get(string name,string default_parameter);
double get_double(string name,string default_parameter);
int get_int(string name,string default_parameter);
void help_message();
bool restoration();

bool INVALID_INPUT = false;
string DAMAGED_IMAGE,INPAINT_DOMAIN,OUTPUT_IMAGE,TEST_DATA; 
int DEPTH,COARSE_STEP,MIDDLE_STEP,FINEST_STEP;
double LAMBDA,EPSILON,THETA;

int main(int argc, char **argv)
{
    cout << "=== start === " << endl;
    DAMAGED_IMAGE = get("DAMAGED_IMAGE","");
    INPAINT_DOMAIN = get("INPAINT_DOMAIN","");
    OUTPUT_IMAGE = get("OUTPUT_IMAGE","output.png");
    TEST_DATA = get("LAMBDA","250");
    cout << "TEST_DATA: " << TEST_DATA << endl;
    LAMBDA = stod(TEST_DATA); 
    //LAMBDA = get_double("LAMBDA","250");
    /*
    THETA = get_double("THETA","5");
    DEPTH = get_int("DEPTH","4");
    EPSILON = get_double("EPSILON","0.0001");
    COARSE_STEP = get_int("COARSE_STEP","10");
    MIDDLE_STEP = get_int("MIDDLE_STEP","3");
    FINEST_STEP = get_int("FINEST_STEP","10");
    */
    cout << LAMBDA << endl;
    cout << "=== readed parameter === " << endl;
    return 0;

    if(DAMAGED_IMAGE.size() == 0 || INPAINT_DOMAIN.size() == 0){
        help_message();
        return 1;
    }
    if(INVALID_INPUT){
        cout << "== INVALID INPUT == " << endl; 
        return 2;   
    }
    restoration();   
    return 0;
}

string get(string name,string default_parameter="")
{
	char* variable = getenv(name.c_str());
	if(strlen(variable)>0){
		return variable;
	}else{
		return default_parameter;
	}
}

double get_double(string name,string default_parameter="")
{
    return stod(get(name,default_parameter));
   /* try {
        return stod(get(name,default_parameter));
    }
    catch (...) {
        INVALID_INPUT = true;
        cout << name << " must be floating point"<< endl;
        return 0;
    }*/
}

int get_int(string name,string default_parameter="")
{
    try {
        return stoi(get(name,default_parameter));
    }
    catch (...) {
        INVALID_INPUT = true;
        cout << name << " must be integer"<< endl;
        return 0;
    }
}

void help_message(){
    cout << "Thai painting restorationg" << endl;
    cout << "usage: \'DAMAGED_IMAGE=\"input.png\" INPAINT_DOMAIN=\"domain.png\" ./thai-painting-restoration" << endl;
    cout << "avaliable option:" << endl; 
    cout << "- DAMAGED_IMAGE: path of image to restoration (required)" << endl;
    cout << "- INPAINT_DOMAIN: path of inpaint domain which is binary image on grayscale color space (required)" << endl;
    cout << "- OUTPUT_IMAGE: path of image after restoration (default: output.png)" << endl;
    cout << "- LAMBDA: lambda parameter in Chan-Shen inpainting model (default: 250)" << endl;
    cout << "- THETA: theta parameter in split-breman numerical method (defualt: 5) " << endl;
    cout << "- EPSILON: epsilon aka. tolerant which use to determine neighborhood (defualt: 1e-4) " << endl;
    cout << "- DEPTH: image pyramid depth (default: 4)" << endl;
    cout << "- COARSE_STEP: maximum iteration on coarse level resolution of image pyramid (default: 10)" << endl;
    cout << "- MIDDLE_STEP: maximum iteration on middle level resolution of image pyramid (default: 3)" << endl;
    cout << "- FINEST_STEP: maximum iteration on finest level resolution of image pyramid (default: 10)" << endl;
    cout << "more info: github.com/pureexe/thai-painting-restoration";
}
bool restoration()
{
    Mat image_input = toDoubleBand(imread(DAMAGED_IMAGE));
    Mat inpaint_domain = imread(INPAINT_DOMAIN,CV_LOAD_IMAGE_GRAYSCALE);
    int max_gaussseidel = 1;
    int current_step = 1;
    Mat result = MultiColorSplitBergman(image_input, inpaint_domain, LAMBDA, THETA, EPSILON, max_gaussseidel, COARSE_STEP, MIDDLE_STEP, FINEST_STEP, DEPTH, current_step);
    imwrite(OUTPUT_IMAGE,result.mul(255));
}