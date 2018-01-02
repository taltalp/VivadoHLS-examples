#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

void axis_dataflow(hls::stream<ap_axis<32,1,1,1> > &outa,
		       hls::stream<ap_axis<32,1,1,1> > &outb);

int main(){
	hls::stream<ap_axis<32,1,1,1> > outa;
	hls::stream<ap_axis<32,1,1,1> > outb;

	axis_dataflow(outa, outb);
	return 0;
}
