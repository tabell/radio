#include <gnuradio/top_block.h>
#include <gnuradio/analog/sig_source_f.h>
#include <gnuradio/audio/sink.h>
#include <gnuradio/blocks/add_ff.h>
#include <gnuradio/blocks/file_sink.h>
#include <gnuradio/qtgui/time_sink_f.h>

#include <QApplication>
#include <QtCore>

#include <iostream>

using std::cout;
using gr::top_block;
using gr::analog::sig_source_f;
using gr::blocks::add_ff;
using gr::blocks::file_sink;
using gr::flowgraph;
using gr::qtgui::time_sink_f;

const double samplerate = 32;

gr::top_block_sptr tb;
void done() {
    tb->stop();
    tb->wait();
}
int main(int argc, char *argv[])
{
	cout << "Hello world" << std::endl;
	// top block
	tb = gr::make_top_block("Test flowgraph");

	// sine wave 350 hz
	sig_source_f::sptr src1
		= sig_source_f::make(samplerate, gr::analog::GR_SIN_WAVE, 350, 0.5, 0);
	// sine wave 440 hz
	sig_source_f::sptr src2
		= sig_source_f::make(samplerate, gr::analog::GR_SIN_WAVE, 440, 0.5, 0);

	add_ff::sptr add1 = add_ff::make();

	tb->connect(src1,0,add1,0);
//	tb->connect(src2,0,add1,1);

	time_sink_f::sptr qt_time = time_sink_f::make(512,samplerate,"Kitchen sinc");

	tb->connect(add1,0,qt_time,0);

//    qt_time->exec();

    QApplication a(argc,argv);

    a.connect(a,aboutToQuit,done);
//    cout << "Calling top_block::run" << std::endl;
//	tb->run();
    cout << "Calling QApp::exec" << std::endl;
//    qt_time->show();
	return a.exec();
}
