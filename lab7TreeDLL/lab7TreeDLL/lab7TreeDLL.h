// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LAB7TREEDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LAB7TREEDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB7TREEDLL_EXPORTS
#define LAB7TREEDLL_API __declspec(dllexport)
#else
#define LAB7TREEDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class LAB7TREEDLL_API Clab7TreeDLL {
public:
	Clab7TreeDLL(void);
	// TODO: add your methods here.
};

//Jakob Was Here
// rofl

extern LAB7TREEDLL_API int nlab7TreeDLL;

LAB7TREEDLL_API int fnlab7TreeDLL(void);
