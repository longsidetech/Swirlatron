# Swirlatron

# Simple WiFI swirly light or anything really.. 

Do you want to control anything with a minimum of fuss just by turning the power on an off via wifi?  Do you want to turn a big swirly light on and off? Then this is what you need! *

I wanted a big swirly light that I could turn off either via a web call or get a system to call because sometimes you need a big swirly light... Out of milk in the office?  Hit the big red button and activate the swirly light! 

Features : 
* simple 
* captive portal
* blindingly obvious code
* can turn things on and off again
* if you are using it for swirly lights contains the obligatory Red Dwarf joke
* most of the work done for what you actually want to use this code for :) 

# Hardware

* 1 x automotive 12v (or anything really) big swirly light
* 1 x power supply for the above (same voltage)
* I prefer to use 12v and automotive stuff for projects like this as if you are buying a relay board for about £2 shipped I don't        really trust them with full mains voltage even if they are "rated" for them... 
* D1 mini 
* D1 mini relay shield (solder it in a way it can plug into the D1 mini above :)

If you are not using a D1 mini then you can either build them from discrete components or use NodeMCU boards with arduino relay shields and I assume you know what you are doing :) 


# Software

Assuming you have your Arduino IDE setup for ESP8266 boards (if not then just google) then download the code, open it,  edit the config section and flash it to your device.  If you are not using a D1 mini then edit the pin (it is in the code). 








( * subject to the load limits on your relay I wouldn't use this with a cooker or washing machine etc... please make sure you are not trying to push too much current through the relay, the normal D1 relay should be good for lights etc).


