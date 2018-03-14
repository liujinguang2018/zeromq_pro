# zeromq_pro

1. Lib库使用VS2013 64bit编译
2. Lib库编译步骤：
	libzmq-4.2.3:
	cd builds & mkdir install
    cmake -G "NMake Makefiles" -DWITH_PERF_TOOL=OFF -DZMQ_BUILD_TESTS=OFF -DENABLE_CPACK=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=install ..
	nmake 
	nmake install

	cppzmq-4.2.2:
	mkdir build & cd build
	cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=E:\libs-compiling\libzmq-4.2.3\builds\install  ..

3. 编译
   mkdir build & cd build
   cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=.. ..
   cmake -G "NMake Makefiles" -DCMAKE_INSTALL_PREFIX=.. -DCMAKE_BUILD_TYPE=Debug ..