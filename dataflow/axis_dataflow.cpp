#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

void axis_dataflow(hls::stream<ap_axis<32,1,1,1> > &outa,
		       hls::stream<ap_axis<32,1,1,1> > &outb)
{
#pragma HLS INTERFACE axis register both port=outa
#pragma HLS INTERFACE axis register both port=outb

	ap_axis<32,1,1,1> bufa;
	ap_axis<32,1,1,1> bufb;

#pragma HLS dataflow
	for(int a=0; a<100; a++){
#pragma HLS pipeline
		bufa.data = a;
		outa << bufa;
	}

	for(int b=0; b<100; b++){
#pragma HLS pipeline
		bufb.data = b;
		outb << bufb;
	}
}
