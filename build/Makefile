CXX = g++
CXXOPTS = -std=c++11

all: executable
rebuild: clean all

debug: CXXFLAGS += -g
debug: executable

executable: main.o Storage.o Leg.o Arm.o Head.o RoboModel.o Battery.o Torso.o RoboPart.o Customer.o Order.o Database.o salesman.o
	$(CXX) $(CXXOPTS) -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -g -O2 -fvisibility-inlines-hidden -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -std=c++11 -o 'shop' 'main.o' 'Storage.o' 'Leg.o' 'Arm.o' 'Head.o' 'RoboModel.o' 'Battery.o' 'Torso.o' 'RoboPart.o' 'Database.o' 'Customer.o' 'Order.o' 'salesman.o' -Wl,-Bsymbolic-functions -lfltk_images -lfltk -lX11

salesman.o: salesman.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) salesman.cpp

Database.o: Database.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Database.cpp

main.o: main.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config --use-images -cxxflags) main.cpp

Storage.o: Storage.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Storage.cpp

RoboPart.o: RoboPart.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) RoboPart.cpp

Leg.o: Leg.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Leg.cpp

Arm.o: Arm.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Arm.cpp

Head.o: Head.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Head.cpp

RoboModel.o: RoboModel.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) RoboModel.cpp

Battery.o: Battery.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Battery.cpp

Torso.o: Torso.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Torso.cpp

Customer.o: Customer.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Customer.cpp

Order.o: Order.cpp
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) Order.cpp

res:
	rm main.o ; make

clean:
	-rm -f *.o shop *.h.gch
