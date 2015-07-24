TI DAC7565, DAC7564, DAC8164 and DAC8564 Library
------------------------------------------------
By Charles-Henri Hallard
<br/>
Texas Instrument DAC7565, DAC7564, DAC8164 and DAC8564 Library for Arduino

##License
Creative Commons Attrib Share-Alike License
https://creativecommons.org/licenses/by-sa/4.0/
You are free to share and adapt. But you need to give attribution and use the same license to redistribute.

For any explanation see Texas Instrument DAC information at http://www.ti.com/product/dac7565

Code based on following datasheet http://www.ti.com/lit/gpn/dac7565 

##Features
List of features implemented in this library:

- Setting all channels outputs (one by one or broadcast)
- Setting power down mode
- Setting reference mode

This is an initial release, it could contain bugs, but works fine for now. Please let me know if you find issues.

###Installation
Copy the content of this library in your Arduino libraries folder in your sketchbook location, you should have now "your_sketchbook_folder/libraries/TH02".
<br />
To find your Arduino sketchbook location folder, in Arduino IDE, go to File>Preferences in the Arduino IDE.
<br/>
See [this tutorial][1] on Arduino libraries.
<br/>

###Possible issues
- The library and examples are continuously improved as bugs and stability issues are discovered. Be sure to check back often for changes.


###Sample usage
- [Dac_Simple_Output][3] Move DAC output back and forth 
- [DAC-Shield][6] A powerfull DAC Shield and other board for Arduino

##Blog dedicated post
Not yet

##Why
- I have spent a lot of time developing this library. I made it open source because I believe a lot of people can benefit from this powerful DAC. I hope people will also contribute and build on my work.

##Misc
See news and other projects on my [blog][4] 
 
[1]: http://learn.adafruit.com/arduino-tips-tricks-and-techniques/arduino-libraries
[2]: http://www.dsscircuits.com/index.php/articles/66-arduino-i2c-master-library
[3]: https://github.com/hallard/DAC7565/blob/master/examples/DAC_Simple_Output/DAC_Simple_Output.ino
[4]: http://hallard.me
[5]: http://hallard.me/th02-library/
[6]: https://github.com/hallard/DAC-Shield
