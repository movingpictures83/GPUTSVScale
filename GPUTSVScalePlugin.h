#ifndef GPUTSVSCALEPLUGIN_H
#define GPUTSVSCALEPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <map>

class GPUTSVScalePlugin : public Plugin {

	public:
		void input(std::string file);
		void run();
		void output(std::string file);
	private:
                std::string inputfile;
		std::string outputfile;
		double* A;
		double* C;
		int N;
		double val;
                std::map<std::string, std::string> parameters;
};

__global__ void multMatByValue(double val, double* A, double* C, int N) {
               int i = blockIdx.x;
               int j = threadIdx.x;
               C[i*N+j] = val * A[i*N+j];

}

#endif
