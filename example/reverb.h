/* ------------------------------------------------------------
name: "reverb"
Code generated with Faust 2.34.4 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fRec10[3];
	int IOTA;
	float fVec0[256];
	float fRec8[2];
	float fVec1[128];
	float fRec6[2];
	float fVec2[512];
	float fRec4[2];
	float fVec3[512];
	float fRec2[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fVec4[1024];
	float fRec14[2];
	float fVec5[8192];
	float fRec13[2];
	float fVec6[4096];
	float fRec11[2];
	float fVec7[4096];
	float fRec0[2];
	float fVec8[1024];
	float fRec19[2];
	float fVec9[8192];
	float fRec18[2];
	float fVec10[2048];
	float fRec16[2];
	float fVec11[2048];
	float fRec1[2];
	int fSampleRate;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("filename", "reverb.dsp");
		m->declare("name", "reverb");
		m->declare("reverbs.lib/dattorro_rev:author", "Jakob Zerbian");
		m->declare("reverbs.lib/dattorro_rev:license", "MIT-style STK-4.3 license");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.25f);
		fHslider1 = FAUSTFLOAT(0.59999999999999998f);
		fHslider2 = FAUSTFLOAT(0.80000000000000004f);
		fHslider3 = FAUSTFLOAT(0.25f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 3); l0 = (l0 + 1)) {
			fRec10[l0] = 0.0f;
		}
		IOTA = 0;
		for (int l1 = 0; (l1 < 256); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec8[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 128); l3 = (l3 + 1)) {
			fVec1[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec6[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 512); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec4[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 512); l7 = (l7 + 1)) {
			fVec3[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec2[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 1024); l9 = (l9 + 1)) {
			fVec4[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec14[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 8192); l11 = (l11 + 1)) {
			fVec5[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec13[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 4096); l13 = (l13 + 1)) {
			fVec6[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec11[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 4096); l15 = (l15 + 1)) {
			fVec7[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec0[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 1024); l17 = (l17 + 1)) {
			fVec8[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec19[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 8192); l19 = (l19 + 1)) {
			fVec9[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec18[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2048); l21 = (l21 + 1)) {
			fVec10[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec16[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2048); l23 = (l23 + 1)) {
			fVec11[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec1[l24] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("reverb");
		ui_interface->addHorizontalSlider("Band Width", &fHslider1, FAUSTFLOAT(0.600000024f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("Damping", &fHslider3, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("Decay", &fHslider2, FAUSTFLOAT(0.800000012f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->addHorizontalSlider("Dry/Wet", &fHslider0, FAUSTFLOAT(0.25f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.00100000005f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = float(fHslider1);
		float fSlow2 = (1.0f - fSlow1);
		float fSlow3 = (0.5f * fSlow1);
		float fSlow4 = float(fHslider2);
		float fSlow5 = float(fHslider3);
		float fSlow6 = (1.0f - fSlow5);
		float fSlow7 = (1.0f - fSlow0);
		for (int i0 = 0; (i0 < count); i0 = (i0 + 1)) {
			float fTemp0 = float(input0[i0]);
			float fTemp1 = float(input1[i0]);
			fRec10[0] = ((fSlow2 * fRec10[2]) + (fSlow3 * (fTemp0 + fTemp1)));
			float fTemp2 = (fRec10[0] - (0.75f * fRec8[1]));
			fVec0[(IOTA & 255)] = fTemp2;
			fRec8[0] = fVec0[((IOTA - 142) & 255)];
			float fRec9 = (0.75f * fTemp2);
			float fTemp3 = ((fRec9 + fRec8[1]) - (0.75f * fRec6[1]));
			fVec1[(IOTA & 127)] = fTemp3;
			fRec6[0] = fVec1[((IOTA - 107) & 127)];
			float fRec7 = (0.75f * fTemp3);
			float fTemp4 = ((fRec7 + fRec6[1]) - (0.625f * fRec4[1]));
			fVec2[(IOTA & 511)] = fTemp4;
			fRec4[0] = fVec2[((IOTA - 379) & 511)];
			float fRec5 = (0.625f * fTemp4);
			float fTemp5 = ((fRec5 + fRec4[1]) - (0.625f * fRec2[1]));
			fVec3[(IOTA & 511)] = fTemp5;
			fRec2[0] = fVec3[((IOTA - 277) & 511)];
			float fRec3 = (0.625f * fTemp5);
			float fTemp6 = ((0.699999988f * fRec14[1]) + fRec1[1]);
			fVec4[(IOTA & 1023)] = fTemp6;
			fRec14[0] = fVec4[((IOTA - 908) & 1023)];
			float fRec15 = (0.0f - (0.699999988f * fTemp6));
			fVec5[(IOTA & 8191)] = (fRec15 + fRec14[1]);
			fRec13[0] = ((fSlow5 * fRec13[1]) + (fSlow6 * fVec5[((IOTA - 4217) & 8191)]));
			float fTemp7 = ((fSlow4 * fRec13[0]) - (0.5f * fRec11[1]));
			fVec6[(IOTA & 4095)] = fTemp7;
			fRec11[0] = fVec6[((IOTA - 2656) & 4095)];
			float fRec12 = (0.5f * fTemp7);
			fVec7[(IOTA & 4095)] = (fRec12 + fRec11[1]);
			fRec0[0] = (fRec2[1] + (fRec3 + (fSlow4 * fVec7[((IOTA - 2656) & 4095)])));
			float fTemp8 = ((0.699999988f * fRec19[1]) + fRec0[1]);
			fVec8[(IOTA & 1023)] = fTemp8;
			fRec19[0] = fVec8[((IOTA - 672) & 1023)];
			float fRec20 = (0.0f - (0.699999988f * fTemp8));
			fVec9[(IOTA & 8191)] = (fRec20 + fRec19[1]);
			fRec18[0] = ((fSlow5 * fRec18[1]) + (fSlow6 * fVec9[((IOTA - 4453) & 8191)]));
			float fTemp9 = ((fSlow4 * fRec18[0]) - (0.5f * fRec16[1]));
			fVec10[(IOTA & 2047)] = fTemp9;
			fRec16[0] = fVec10[((IOTA - 1800) & 2047)];
			float fRec17 = (0.5f * fTemp9);
			fVec11[(IOTA & 2047)] = (fRec17 + fRec16[1]);
			fRec1[0] = ((fRec3 + fRec2[1]) + (fSlow4 * fVec11[((IOTA - 1800) & 2047)]));
			output0[i0] = FAUSTFLOAT(((fSlow0 * fRec0[0]) + (fSlow7 * fTemp0)));
			output1[i0] = FAUSTFLOAT(((fSlow0 * fRec1[0]) + (fSlow7 * fTemp1)));
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec11[1] = fRec11[0];
			fRec0[1] = fRec0[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#endif
