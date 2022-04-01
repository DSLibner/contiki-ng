#include "contiki.h"
#include "cc2420.h"
#include <stdio.h>

PROCESS(scanner_process, "RSSI Scanner");
AUTOSTART_PROCESSES(&scanner_process);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(scanner_process, ev, data)
{
  static struct etimer timer;
  PROCESS_BEGIN();
  etimer_set(&timer, CLOCK_SECOND * 10);
  cc2420_on();
  int rssi;
  while(1) {

    for(size_t chan = 11; chan <= 26; ++chan) {
      cc2420_set_channel(chan);
      rssi = 0;
      for (size_t i = 0; i < 20; i++)
      {
        rssi += cc2420_rssi();
      }
        rssi /= 20;
      printf("c: %d rssi: %d DBm", chan , rssi);
      }
  printf("\n");
  PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
  etimer_reset(&timer);
  }

  PROCESS_END();
}