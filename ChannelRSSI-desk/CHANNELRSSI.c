#include "contiki.h"
#include "cc2420.h"
#include <stdio.h>

PROCESS(scanner_process, "RSSI Scanner");
AUTOSTART_PROCESSES(&scanner_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(scanner_process, ev, data)
{
  static int i=0;
  static struct etimer timer;
  PROCESS_BEGIN();
  etimer_set(&timer, CLOCK_SECOND * 10);
  cc2420_on();
  int RSSI;
  int bestRSSI[2];
  while(1) {
    bestRSSI[0]=1;
    bestRSSI[1]=1;
    i++;
    printf("Run nr: %d\n", i);
    for(size_t chan = 11; chan <= 26; chan++) 
    {
      cc2420_set_channel(chan);
      RSSI = cc2420_rssi();
      if(bestRSSI[0]==1)
      {
        bestRSSI[0] = chan;
        bestRSSI[1] = RSSI;
      }
      if(bestRSSI[1] < RSSI)
      {
        bestRSSI[0] = chan;
        bestRSSI[1] = RSSI;
      }
      printf("channel: %d RSSI: %d dBm\n", chan , RSSI);
    }
    printf("Best channel was: %d with an RSSI of: %d \n\n", bestRSSI[0], bestRSSI[1]);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }
  PROCESS_END();
}