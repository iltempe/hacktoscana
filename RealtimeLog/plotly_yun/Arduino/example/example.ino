#include <PlotlyYun.h>
#include <YunMessenger.h>
#include <Bridge.h>
#include <Console.h>

// Initialize plotly "plotters" with your stream tokens.
// Find your stream tokens in your plotly account here: https://plot.ly/settings
// Initialize as many plotters as you want! Each plotter will send
// data to the same plot as a separate line.
// Make sure that you place these exact-same stream tokens in your `config.json` file
// on the Linino.

plotly plotter1("v6fblb3fux");
plotly plotter2("kzy2sklq8m");

void setup() { 

    // start-up the bridge
    Bridge.begin();

    delay(2000);
    Console.begin();
    while (!Console) {
      ; // wait for Console port to connect.
    }
    
    Console.buffer(64);
    delay(2000);

    plotter1.timezone = "Europe/Rome";
    plotter2.timezone = "Europe/Rome";
} 

void loop() { 
    // Graph data! Place the "y" value that you want to plot
    // the "x" value will automatically be a time-stamped value
    // Each "plotter" will send data to the same plot as separate lines
    plotter1.plot( analogRead(A0) );
    plotter2.plot( analogRead(A1) );

    // You can also set the "x" value manually 
    // by placing a pair of points in the plot function:
//    plotter1.plot( millis(), analogRead(A0) );
//    plotter2.plot( millis(), analogRead(A1) );
    delay(100);
}
