/*
File: absolute_triallist.hpp
________________________________
Author(s): Joshua Fleck (jjf8@rice.edu)
Edited by: Zane Zook (gadzooks@rice.edu), Andrew Low (andrew.low@rice.edu)

Defines a class to randomize a list of trial conditions for
Absolute Threshold experiment.
*/

#ifndef ABSOLUTE_TRIALLIST
#define ABSOLUTE_TRIALLIST

/***********************************************************
******************** LIBRARY IMPORT ************************
************************************************************/
// libraries for MEL
#include <MEL/Logging/Csv.hpp>
#include <MEL/Core/Console.hpp>

// other misc standard libraries
#include <random>
#include <array>

/***********************************************************
************************ CONSTANTS *************************
************************************************************/
const int	kNumberAngles_(7);
const int 	kNumberConditions_(4);
const int	kNumberTrials_(50);
const int 	kInterferenceAngle_(52);
const int 	kZeroAngle_(0);
const std::array<double, kNumberAngles_> kStretchAngles_ = 
	{0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3};
const std::array<double, kNumberAngles_> kStretchAnglesInterference_ = 
	{0, 7, 14, 21, 28, 35, 42};	
const std::array<double, kNumberAngles_> kSqueezeAngles_ = 
	{0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0};
const std::array<double, kNumberAngles_> kSqueezeAnglesInterference_ = 
	{0, 7, 14, 21, 28, 35, 42};	

/***********************************************************
****************** CLASS DECLARATION ***********************
************************************************************/
class TrialList
{
private:		
	// private array variables
	std::array<std::array<double, kNumberAngles_ * kNumberTrials_>, kNumberConditions_> angles_; // array of arrays that hold angle positions
	std::array<std::string, kNumberConditions_> condition_names_ = 
		{
		"Stretch",
		"Stretch_Squeeze",
		"Squeeze",
		"Squeeze_Stretch"
		}; // array of conditions_
	std::array<int, kNumberConditions_> conditions_ = { 0,1,2,3 };
	
	// random device variable
	std::random_device random_device_; // create random generator
	
	// iterator variables
	int condition_iterator_; // iterators on arrays
	int angle_iterator_;

	// overloaded functions to directly access name information
	std::string	GetTrialName(int condition, int angle);
	double		GetAngleNumber(int condition, int angle);
	int		 	GetIterationNumber(int condition, int angle);
	void	 	GetTestPositions(std::array<std::array<double, 2>,2> &position_desired, int condition, int angle);

public:
	// constructor
	TrialList();
	~TrialList();

	// randomizer
	void 	scramble();

	// read various combinations names
	std::string  	GetTrialName();
	std::string  	GetConditionName();
	std::string		GetConditionName(int condition_number);
	std::string		GetComboNames(); // get full list of combination orderings

	// read various angle values
	double	GetAngleNumber();
	int		GetInterferenceAngle();
	int		GetInterferenceAngle(int condition_number);
	void	GetTestPositions(std::array<std::array<double, 2>,2> &position_desired);
	int		GetIterationNumber();

	// control iterator positions
	void	NextAngle();
	void	PrevAngle();
	bool	HasNextAngle();
	void	NextCondition();
	void	PrevCondition();
	bool	HasNextCondition();
	void	SetCombo(int iteration, int angle);

	// get iterator positions
	int		GetConditionNum();
	int		GetAngleIndex();	

	// inport/export functions
	bool	ImportList(std::string filepath);
	void	ExportList(std::string filepath, bool timestamp);
};
#endif