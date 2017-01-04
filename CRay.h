#include <math.h>

class CIndex
{
public:
	double ni;
	double nr;
};


class CVector
{
public:
	double x;
	double y;
	double dotproduct(CVector vector)
	{
		double result;
		result=x*vector.x+y*vector.y;
		
		return result;
	}
	double norm()
	{
		double result;
		result=sqrt(x*x+y*y);
		return result;
	}
	
	CVector add(CVector vector)
	{
		CVector result;
		result.x=x+vector.x;
		result.y=y+vector.y;
		return result;
	}
	CVector substract(CVector vector)
	{
		CVector result;
		result.x=x-vector.x;
		result.y=y-vector.y;
		return result;
	}
	CVector scale(double lambda)
	{
		CVector result;
		result.x=x*lambda;
		result.y=y*lambda;
		return result;
	}
	void unit()
	{
		double norm=sqrt(x*x+y*y);
		x=x/norm;
		y=y/norm;
		
	}
};

class CRay
{
public:
	double reflectance;
	double transmittance;
	double absorb;
	double energy;
	unsigned long number;
	CVector direction;
	CPoint curpoint;
	CRay()
	{
		energy=1;
		curpoint.x=110;
		curpoint.y=350;
	}
	~CRay()
	{
		
	}
	double calcreflectance(double thetai,CIndex index)
	{
		double result;
		double thetar;
		double temp;
		double preflcoeff;
		double sreflcoeff;
		temp=index.ni*sin(thetai)/index.nr;
		thetar=asin(temp);
		
		preflcoeff=(index.nr*cos(thetai)-index.ni*cos(thetar))/(index.nr*cos(thetai)+index.ni*cos(thetar));
		sreflcoeff=(index.ni*cos(thetai)-index.nr*cos(thetar))/(index.ni*cos(thetai)+index.nr*cos(thetar));
		result=(preflcoeff*preflcoeff+sreflcoeff*sreflcoeff)/2;
		return result;
		
		
	}
	
	double calctransmittance(double thetai,CIndex index)
	{
		double result;
		
		result=1-calcreflectance(thetai,index);
		return result;
	}
	bool reflect(CVector normal,CIndex index,double dieoutenergy)
	{
		
		double thetai;
		thetai=acos(fabs(direction.dotproduct(normal))/(direction.norm()*normal.norm()));
		if(direction.dotproduct(normal)>0){normal.x=-normal.x;normal.y=-normal.y;	
		thetai=acos(fabs(direction.dotproduct(normal))/(direction.norm()*normal.norm()));
		}
		//掠入射视为折射
		if(0==direction.dotproduct(normal)){energy=0;return false;}
		
		if(1==fabs(direction.dotproduct(normal))/(direction.norm()*normal.norm()))
		{
			direction.x=-direction.x;
			direction.y=-direction.y;
			reflectance=(index.nr-index.ni)*(index.nr-index.ni)/(index.nr+index.ni)/(index.nr+index.ni);
			energy*=reflectance;
			
			
			if(energy>=dieoutenergy)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if(index.nr<index.ni)
		{
			double thetac;
			thetac=asin(index.nr/index.ni);		
			
			if(sin(thetai)<sin(thetac))
			{
				reflectance=calcreflectance(thetai,index);
				energy*=reflectance;
				
			}
		}
		else
		{
			reflectance=calcreflectance(thetai,index);
			energy*=reflectance;
		}
		
		
		CVector refldir;
		normal.unit();
		direction.unit();
		refldir=direction.substract(normal.scale(2*(direction.dotproduct(normal))));
		direction=refldir;
		direction.unit();
		
		if(energy>=dieoutenergy)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool refract(CVector normal,CIndex index,double dieoutenergy)
	{
		
		direction.unit();
		
		double thetai;
		//掠入射视为折射
		if(0==direction.dotproduct(normal)){
			
			if(energy>=dieoutenergy)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		}
		
		thetai=acos(fabs(direction.dotproduct(normal))/(direction.norm()*normal.norm()));
		if(0==thetai)
		{
			transmittance=4*index.ni*index.nr/(index.ni+index.nr)/(index.ni+index.nr);
			energy*=transmittance;
			
			
			if(energy>=dieoutenergy)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		
		if(index.nr<index.ni)
		{
			double thetac;
			thetac=asin(index.nr/index.ni);		
			
			if(sin(thetai)>=sin(thetac))
			{
				//Total Internal Reflection
				energy=0;
				return false;
			}
		}
		transmittance=calctransmittance(thetai,index);
		energy*=transmittance;
		
		CVector refrdir,refrdir1;
		
		double thetar;
		double temp;
		temp=index.ni*sin(thetai)/index.nr;
		thetar=asin(temp);
		
		if(direction.dotproduct(normal)<0)
		{
			normal.x=-normal.x;
			normal.y=-normal.y;
		}
		
		refrdir.x=cos(thetar)*normal.x-sin(thetar)*normal.y;
		refrdir.y=sin(thetar)*normal.x+cos(thetar)*normal.y;
		
		if((direction.x*normal.y-direction.y*normal.x)*(refrdir.x*normal.y-refrdir.y*normal.x)<0)
		{
			refrdir1.x=cos(thetar)*normal.x+sin(thetar)*normal.y;
			refrdir1.y=-sin(thetar)*normal.x+cos(thetar)*normal.y;
			direction=refrdir1;
		}
		else
		{
			direction=refrdir;
		}
		direction.unit();
		
		if(energy>=dieoutenergy)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


