#ifndef FFGLHeat_H
#define FFGLHeat_H

#include <FFGLShader.h>
#include "../FFGLPluginSDK.h"

#include "Shader_Downscale.h"
#include "Shader_Blur.h"

struct Point2D{
	float x;
	float y;
}; 
struct NoiseAnim{
	float countx;
	float countz;
	float angle;
	float scale;
	float persistence;
	float speedx;
	float speedz;
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
	void initBlurShader();
	void initDownScaleBiasShader();
	void initFinalShader();

	void renderDownScaleInput();
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

	void renderQuad(float texMaxX,float texMaxY);


	void updateRenderTargets(int newWidth,int newHeight);
	double systemTimeToDouble(SYSTEMTIME *time);
protected:	
	int lastWidth;
	int lastHeight;
	// Time
	double m_Time;
	SYSTEMTIME m_SystemTimeStart;
	SYSTEMTIME m_SystemTimeLastFrame;
	double timeCounter;   
	 

	float m_Amount;
	float m_Radius;




	int m_initResources; 

	FFGLExtensions m_extensions; 
	FFGLShader m_shaderSimple; 
	GLuint m_inputTextureLocationSimple;  
	GLuint m_blurTextureLocationSimple;  
	GLuint m_maxCoordsLocation; 
	GLuint m_timeLocation; 
	GLuint m_aspectLocation; 
	GLuint m_locationLocation; 


	float s_power;
	float s_brightness;
	float s_poweradd;
	float s_brightnessadd;
	float s_color_red;
	float s_color_green;
	float s_color_blue;



	float m_bias;
	float m_bluramount;
	float m_tolerance;

	ShaderDownscale shaderDownscale;
	ShaderBlur shaderBlur;

	// Blur Shader Uniforms 

	// Blur Shader uniforms end

	GLint m_resolutionLocation; 

	GLuint renderedTextureLoRes;
	GLuint renderedTexture1; 
	GLuint renderedTexture2; 
	GLuint m_FramebufferId;
	int frameindexforswapping;

};


#endif
