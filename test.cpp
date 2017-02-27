#include <gnuradio/top_block.h>
#include <gnuradio/analog/sig_source_f.h>
#include <gnuradio/audio/sink.h>
#include <gnuradio/blocks/add_ff.h>
#include <gnuradio/blocks/file_sink.h>

#include <iostream>

using std::cout;
using gr::top_block;
using gr::analog::sig_source_f;
using gr::blocks::add_ff;
using gr::blocks::file_sink;
using gr::flowgraph;

int main(int argc, char const *argv[])
{
	cout << "Hello world" << std::endl;
	// top block
	gr::top_block_sptr tb = gr::make_top_block("Test flowgraph");

	// sine wave 350 hz
	sig_source_f::sptr src1
		= sig_source_f::make(32000, gr::analog::GR_SIN_WAVE, 350, 0.5, 0);
	// sine wave 440 hz
	sig_source_f::sptr src2
		= sig_source_f::make(32000, gr::analog::GR_SIN_WAVE, 440, 0.5, 0);

	add_ff::sptr add1 = add_ff::make();

	tb->connect(src1,0,add1,0);
	tb->connect(src2,0,add1,1);

	file_sink::sptr file_out = file_sink::make(4,"/dev/stdout");

	tb->connect(add1,0,file_out,0);

	tb->run();
	return 0;
}
