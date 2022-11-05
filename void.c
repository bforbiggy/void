#include "void.h"

// Spiral function
longle r(longle theta){
	return theta;
}

// Updates grid with sampled values
void updateGrid(){
	longle longest = max(WIDTH, HEIGHT);

	longle theta = offset;
	longle radius = r(theta) - offset;
	while (radius <= longest){
		// Convert to cartesian
		int x = radius * cos(theta);
		int y = radius * sin(theta);

		// Convert to index then modify grid
		int w = xToW(x, WIDTH);
		int h = yToH(y, HEIGHT);
		if(h >= HEIGHT || w >= WIDTH) return;
		putpixel(w, h, WHITE);

		// Iterate to next point
		longle multiplier = radius/5.0;
		multiplier = multiplier > 1 ? multiplier : 1;
		theta += SAMPLE_RATE / multiplier;
		radius = r(theta) - offset;
	}
}

int main(){
  initwindow(WIDTH, HEIGHT);
	while(true){
		cleardevice();
		updateGrid();
		offset += OFFSET_INC;
		usleep(SLEEP_DURATION * 1000);
	}
	return 0;
}