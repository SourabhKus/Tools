ffmpeg-3.2-msys+msvc17
----------------------

1) Add FFMPEG in your windows Environment Variable with path.
2) Add below lines in your .pro file 
For Windows
	win32{
		CFLAGS = -D__STDC_CONSTANT_MACROS
		DEFINES += __STDC_CONSTANT_MACROS
		INCLUDEPATH += $$(FFMPEG)/include
		LIBS += -L$$(FFMPEG)/lib
		LIBS +=  -lavfilter -lavcodec -lavformat -lavutil -lswscale -lswresample
	}
	
For Android 
	android{
		CONFIG*=c++11
		CFLAGS=-D__STDC_CONSTANT_MACROS
		DEFINES +=__STDC_CONSTANT_MACROS
		INCLUDEPATH += $$(FFMPEG)/include
		LIBS += -L$$(FFMPEG)/lib
		LIBS +=  -lavfilter-6 -lavcodec-57 -lavformat-57 -lavutil-55 -lswscale-4 -lswresample-2
	}

2) Copy paste FFMPEG libraries along with your Application.exe 
