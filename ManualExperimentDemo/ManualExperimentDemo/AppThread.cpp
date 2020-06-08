#include "AppThread.h"
void Dowork() {
	AisSquidstatStarter appStarter;
    appStarter.initApp(); // Initializes the AisSquidstatStarter

    /*
     * SquidStateHandler can be traced from the constructor.
     * What it does: ExpDataNotifier is registered as the global notifier.
     * fillAppData is then called which is responsible for loading: the list
     * of custom experiments the user has saved to their documents folder;
     * the builder elements dynamic libraries which are constitutes of the
     * custom  experiments; and the Squidstat device which is connected in
     * some usb port (the port may be specified, but is not required).
     * Then the global notifier ExpDataNotifier is responsible for starting the
     * manual experiment after it registers that a device has connected to the
     * SquidStatHandler.
     */
    SquidStateHandler start;

    appStarter.execApp(); // Must be called on same thread as initApp
}


