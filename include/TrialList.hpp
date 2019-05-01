/*
File: TrialList.hpp
________________________________
Author(s): Joshua Fleck (jjf8@rice.edu)
Edited by: Zane Zook (gadzooks@rice.edu)

Defines a class to randomize a list of trial conditions for
JND experiment.
Last Changed: 12/21/18
*/

#ifndef TRIALLIST_H
#define TRIALLIST_H

/***********************************************************
******************** LIBRARY IMPORT ************************
************************************************************/
// other misc standard libraries
#include <random>
#include <array>

// namespace for std
using namespace std;


/***********************************************************
******************* GLOBAL VARIABLES ***********************
************************************************************/
const int	g_NUMBER_ANGLES = 7;
// const int	g_NUMBER_CONDITIONS = 4; // will change to 3
const int g_NUMBER_CONDITIONS = 3;
const int	g_NUMBER_TRIALS = 50;
//const array<int, g_NUMBER_ANGLES> g_DEFAULT_ANGLES = { 13, 26, 39, 52, 65, 78, 91 };
const array<double, g_NUMBER_ANGLES> g_DEFAULT_ANGLES = { 24, 24, 24, 24, 24, 24, 24 };
// const int g_REFERENCE_ANGLE = 52; //in degrees
// const int g_INTERFERENCE_ANGLE = 52; //in degrees
const int g_INTERFERENCE_ANGLE_LOW = 36;
const int g_INTERFERENCE_ANGLE_HIGH = 72;
const int g_ZERO_ANGLE = 0;



/***********************************************************
****************** CLASS DECLARATION ***********************
************************************************************/
class TrialList
{
private:
	// private array variables
	array<array<double, g_NUMBER_ANGLES * g_NUMBER_TRIALS>, g_NUMBER_CONDITIONS> angles; // array of arrays that hold angle positions
	//array<string, g_NUMBER_CONDITIONS>	conditionNames = { "Stretch", "StretchXSqueeze", "Squeeze", "SqueezeXStretch" }; // array of conditions
	//array<int, g_NUMBER_CONDITIONS>		conditions = { 0,1,2,3 };
	array<string, g_NUMBER_CONDITIONS>	conditionNames = { "Stretch", "StretchXSqueeze(Low)", "StretchXSqueeze(High)" }; // array of conditions
	array<int, g_NUMBER_CONDITIONS>		conditions = { 2,2,2 };
	
	// random device variable
	random_device rd; // create random generator
	
	// iterator variables
	int		 conCurr = 0; // iterators on arrays
	int		 angCurr = 0;

	// overloaded functions to directly access name information
	string	 getTrialName(int con, int ang);
	string	 getConditionName(int con);
	double		 getAngleNumber(int con, int ang);
	// bool	 getTestPositions(array<array<int, 2>,4> &posDes, int con, int ang);
	void	 getTestPositions(array<array<double, 2>,2> &posDes, int con, int ang);
	int		 getIterationNumber(int con, int ang);

public:
	// constructor
	TrialList();
	~TrialList();

	// read various combinations names
	string  getTrialName();
	string  getConditionName();
	double		getAngleNumber();
	// int		getReferenceAngle();
	int		getInterference(int interferenceFlag);
	// bool	getTestPositions(array<array<int, 2>,4> &posDes);
	void	getTestPositions(array<array<double, 2>,2> &posDes);
	int		getIterationNumber();
	string	getComboNames(); // get full list of combination orderings

	// control iterator positions
	void	nextAngle();
	void	prevAngle();
	bool	hasNextAngle();
	void	nextCondition();
	void	prevCondition();
	bool	hasNextCondition();
	void	setCombo(int con, int ang);

	// get iterator positions
	int		getCondNum();
	int		getAngCurr();	

	// inport/export functions
	bool	importList(string filepath);
	void	exportList(string filepath, bool timestamp);
};
#endif