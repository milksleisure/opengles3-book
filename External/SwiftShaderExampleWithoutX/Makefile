CXX=g++
CXXFLAGS=-I../Include
GLLIB=../../Binary/SwiftShader
LDFLAGS=-Wl,-rpath=$(GLLIB) -L$(GLLIB) -lEGL -lGLESv2

hello:
	$(CXX) $(CXXFLAGS) -o $@ hello_nox.cpp $(LDFLAGS)

clean:
	rm hello
