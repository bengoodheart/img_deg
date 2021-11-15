img_opt:
	g++ -g -Wall -l vips -o img_deg main.cpp degrader.cpp `pkg-config vips-cpp --cflags --libs `

clean:
	/bin/rm -f img_deg