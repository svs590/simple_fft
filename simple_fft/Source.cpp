#include <iostream>
#include <fstream>
#include <vector>
#include <complex>

#include "kissfft.hh"

using namespace std;

typedef kissfft<double> FFT;
typedef complex<double> cpx_type;

int main() {

	vector<cpx_type> samples;

	ifstream samples_file("../samples/samples_small.out");
	
	double tmp;
	while (samples_file >> tmp)
		samples.push_back({ tmp, 0 });

	FFT fft(samples.size(), false);
	vector<cpx_type> outbuf(samples.size());
	fft.transform(samples.data(), outbuf.data());

	for (int i = 0; i < outbuf.size(); ++i)
		cout << outbuf[i] << endl;

	system("pause");
	return 0;
}