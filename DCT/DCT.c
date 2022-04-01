#include "contiki.h"
#include "fastdct8.h"
#include <math.h>
#include <vector>
#include <stdio.h>

/* Create DCT matrix */
PROCESS(DCT, "DCT process");
AUTOSTART_PROCESSES(&DCT);
PROCESS_THREAD(DCT, ev, data)
{
    static struct etimer timer;
    
    PROCESS_BEGIN();
    double data[8] = {5,2,25,12,3,1,1,2};
    etimer_set(&timer, CLOCK_SECOND * 10);

    while(1) 
    {
        for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); i++)
        {
            printf("%d ", (int)data[i]);
        }
        printf("\n");
        FastDct8_transform(data);
        for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); i++)
        {
            printf("%d ", (int)data[i]);
        }
        printf("\n");
        FastDct8_inverseTransform(data);
        for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); i++)
        {
            printf("%d ", (int)data[i]);
        }
        printf("\n");
        PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
        etimer_reset(&timer);
    }
    PROCESS_END();
}