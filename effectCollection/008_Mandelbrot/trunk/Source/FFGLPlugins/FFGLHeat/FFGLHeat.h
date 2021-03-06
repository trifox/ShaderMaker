#ifndef FFGLHeat_H
#define FFGLHeat_H

#include <FFGLShader.h>
#include "../FFGLPluginSDK.h"

struct SineWave2d{
	float count;
	float frequency;
	float amplitude;
	float wavelength;
	float angle;
};
struct Point2D{
	float x;
	float y;
};

struct SeedAnim{
	float count;
	Point2D center;
	float radius;
		float speed;
		float par1;
		float par2;
};

class FFGLSineWave2D :


public CFreeFrameGLPlugin
{
public:
	FFGLSineWave2D();
  virtual ~FFGLSineWave2D() {}

	///////////////////////////////////////////////////
	// FreeFrameGL plugin methods
	///////////////////////////////////////////////////
	
	DWORD	SetParameter(const SetParameterStruct* pParam);		
	DWORD	GetParameter(DWORD dwIndex);					
	DWORD	ProcessOpenGL(ProcessOpenGLStruct* pGL);
  DWORD InitGL(const FFGLViewportStruct *vp);
  DWORD DeInitGL();
  	DWORD SetTime(double time);
	

double GetTimeInSecondsSinceStart();
	///////////////////////////////////////////////////
	// Factory method
	///////////////////////////////////////////////////

	static DWORD __stdcall CreateInstance(CFreeFrameGLPlugin **ppOutInstance)
  {
  	*ppOutInstance = new FFGLSineWave2D();
	  if (*ppOutInstance != NULL)
      return FF_SUCCESS;
	  return FF_FAIL;
  }
double systemTimeToDouble(SYSTEMTIME *time);
protected:	
	// Time
	double m_Time;
	SYSTEMTIME m_SystemTimeStart;
	SYSTEMTIME m_SystemTimeLastFrame;
	double timeCounter;  
	Point2D fractalCenter;
	float fractalScale;
	float fractalAngle;
	
	SeedAnim seedAnim1;
	SeedAnim seedAnim2;
	SeedAnim seedAnim3; 
	
	int m_initResources;

	GLuint m_heatTextureId;

	float m_modStep;
	float scaleHue;
	float scaleSaturation;
	float scaleValue;
	float imageblendValue;

	FFGLExtensions m_extensions;
    FFGLShader m_shader;
	GLint m_inputTextureLocation;
	GLint m_heatTextureLocation;
	GLint m_maxCoordsLocation; 
	GLint m_timeLocation; 
	GLint m_aspectLocation; 
	GLint m_locationLocation; 
	GLint m_imageblendLocation; 
	  

	
	GLint m_HSVScaleLocation;
	GLint m_seed1Location;
	GLint m_seed2Location;
	GLint m_seed3Location;
	GLint m_modstepLocation;

};


#endif
