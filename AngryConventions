//##############################################################################
//This file is meant to describe basic conventions to keep our code consistent.
//Right now it is just what I personally do based on prof. Aars' conventions.
//We can address any questions or disagreements as they come up, but I just
//	wanted to throw this out there.
//##############################################################################

/*******************************************************************************
 Filename:                  UpperCamelCase.ext
 Classname:                 ClassName or N/A
 
 Description:               This should be a brief description of the file and
 								its purpose
 
 Last Modified:            				01.23.12
 By:									Name
	- Something that was changed
	- If someone has a question about the change, they will ask you
 ******************************************************************************/

#ifndef ACLASS_H
#define ACLASS_H

#include "BClass"

class ACLass
{
	private:
		int		someInteger;			//Tab identifiers to line up in column
		double 	selfExplanatoryName;	//Include details if name is not enough
										//  but try to use descriptive names
										//  within classes
		BClass	*angryPointer,			//Splat next to identifier
				angrierPointer;			//Mulitple declarations on seperate line
	
	protected:
		bool	isAngry,
				hasTemper;
	
	public:
		AClass();								//Constructors/Destructor
		AClass(int, double);
		ACLass(const ACLass&);
		~AClass();
		
		void setSomeInteger(int);				//Accessors
		void setSelfExplanatoryName(double);
		void setIsAngry(bool);
		void setHasTemper(bool);
		
		int		getSomeInteger();				//Modifiers
		double	getselfExplanatoryName();
		bool	getisAngry();
		bool	getHasTemper();
		
		BClass	*giveMeABClass();				//Others
		
}; /* AClass */				// <--End long blocks with name/short description
 
/*******************************************************************************
 Name:              getSelfExplanatoryName
 Description:       Basic description
 
 Last Modified:            				01.23.12
 By:									Name
	- Something that was changed
	- If someone has a question about the change, they will ask you
 ******************************************************************************/
double AClass::getSelfExplanatoryName()
{
	double 		*a = new double;
	long double *b = new long double;
	double		c  = (*a * *b);
	
	delete a;
	delete b;
	
	return c;
}

#endif