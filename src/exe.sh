#!/usr/bin/env bash
convert_ppm() {
    cd ../$1
    convert -delay 10 -scale 400x res*.ppm life.gif
}

rm -r ../*_Output
mkdir ../Blinker_Output
mkdir ../Glider_Output
mkdir ../Tetris_Output
mkdir ../Four_Blinker_Output
mkdir ../Four_Beehives_Output
make
./a.out
echo Animation Part 2/2 in progress.
convert_ppm "Blinker_Output"
convert_ppm "Glider_Output"
convert_ppm "Tetris_Output"
convert_ppm "Four_Blinker_Output"
convert_ppm "Four_Beehives_Output"
echo Animations complete. Watch life unfold at *_Output/life.gif!