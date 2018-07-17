CXX=g++
CXXFLAGS=-I../Include
GLLIB=../../Binary/SwiftShader
LDFLAGS=-Wl,-rpath=$(GLLIB) -L$(GLLIB) -lEGL -lGLESv2

hello:
	$(CXX) $(CXXFLAGS) -o $@ OGLES2HelloAPI_LinuxX11.cpp $(LDFLAGS) -lX11

