// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <CL/cl.h>
#include <CL/cl.hpp>
#include <vector>
#include <cuda_runtime.h>

using namespace std;
using namespace std::chrono;


// Defining CTVolume class
class CTVolume {
    public:
        CTVolume(string name) {
			setName(name);
			cout << "Volume " << name << " is created.\n";
		}
        void setName(string name) {
			this->name = name;
		}
        string getName() {
            return name;
        }
    private:
		string name;


};

void Welcome() {
    cout << "Hello World!\n";
    cout << "Input your name: ";
    string a;
    cin >> a;
    cout << "Welcome to C++, " << a << "!\n";
}


void QuadraticEquation(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
		cout << "No real solution\n";
	}
    else if (delta == 0) {
		cout << "x = " << -b / (2 * a) << "\n";
	}
    else {
		cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\n";
		cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << "\n";
	}

}


int main()
{
    cout << "Hi\n";
    auto start = high_resolution_clock::now();
    

    Welcome();

	// 1. Get all platforms (e.g. AMD, Intel, NVIDIA)
    std::vector<cl::Platform> platforms;
	cl::Platform::get(&platforms);

    if (platforms.empty()) {
		std::cerr << "OpenCL platforms not found." << std::endl;
		return 1;
    }



	// 2. Get all available devices on the first platform

	for (auto& platform : platforms) {
		std::string platformName;
		platform.getInfo(CL_PLATFORM_NAME, &platformName);
		std::cout << "Platform: " << platformName << std::endl;

		std::vector<cl::Device> devices;
		platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);



		

		if (devices.empty()) {
			std::cerr << "OpenCL devices not found." << std::endl;

		}
		else {
			for (auto &device : devices) {
				std::string deviceName;
				device.getInfo(CL_DEVICE_NAME, &deviceName);
				std::cout << "Device: " << deviceName << std::endl;
			}

		}

	}

	std::vector<cl::Device> devices;
	platforms[0].getDevices(CL_DEVICE_TYPE_ALL, &devices);

	//// 3. Create an OpenCL context
	//cl::Context context(devices);
	//cl::CommandQueue queue(context, devices[0]);

	//// 4. Define a simple kernel that adds two vectors
 //   const char* kernelSource = R"(
	//	__kernel void add(__global const float* a, __global const float* b, __global float* result) {
	//		int i = get_global_id(0);
	//		result[i] = a[i] + b[i];
 //       }
 //   )";


	//cl::Program::Sources sources;
	//sources.push_back({ kernelSource, strlen(kernelSource) });

	//cl::Program program(context, sources);
 //   if (program.build({ devices[0] }) != CL_SUCCESS) {
	//	std::cerr << "Error building: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(devices[0]) << std::endl;
	//	return 1;
 //   }

	//// 5. Prepare data for the kernel
	//const int dataSize = 1024;
	//std::vector<float> a(dataSize, 1.0f);
	//std::vector<float> b(dataSize, 2.0f);
	//std::vector<float> result(dataSize);

	//cl::Buffer bufferA(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * dataSize, a.data());
	//cl::Buffer bufferB(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * dataSize, b.data());
	//cl::Buffer bufferResult(context, CL_MEM_WRITE_ONLY, sizeof(float) * dataSize);

	//// 6. Set kernel arguments and run the kernel
	//cl::Kernel kernel(program, "vector_add");
	//kernel.setArg(0, bufferA);
	//kernel.setArg(1, bufferB);
	//kernel.setArg(2, bufferResult);

	//queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(dataSize), cl::NullRange);
	//queue.finish();

	//// 7. Read back the result
	//queue.enqueueReadBuffer(bufferResult, CL_TRUE, 0, sizeof(float) * dataSize, result.data());

	//// 8. Output the result
	//for (int i = 0; i < dataSize; i++) {
	//	std::cout << result[i] << " "; // Should output 3 3 3 3 ...
	//}

	//std::cout << std::endl;
	// End of OpenCL example




    // Quadratic equation
    //QuadraticEquation(1, 6, 8);

    CTVolume vol = CTVolume("Blade");


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "It took "
		<< duration.count() << " milliseconds" << endl;
    cout << "Bye\n";

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
