//#include <iostream>
#include <stdio.h>
#include <usb.h>
//using namespace std;

main()
{
struct usb_bus *bus;
struct usb_device *dev;
usb_init();
usb_find_busses();
usb_find_devices();
for(bus = usb_busses; bus;bus= bus->next)
	for(dev= bus->devices; dev; dev=dev->next) { 
		printf("TRying device %s%s\n", bus->dirname, dev->filename);
		printf( "ID_VENDOR =0x%04x\n ",dev->descriptor.idVendor);
		printf( "ID_PRODUCT =0x%04x\n ", dev->descriptor.idProduct);
}
}
