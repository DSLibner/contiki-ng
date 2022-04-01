#include "contiki.h"
#include "dctMatrix.h"
#include "fastdct8.h"

/* Create DCT matrix */
PROCESS(DCT, "DCT process");
AUTOSTART_PROCESSES(&DCT);
PROCESS_THREAD(DCT, ev, data)
{
    //static struct etimer timer;
    PROCESS_BEGIN();
    DCT_Matrix(TheDCTMatrix);
    INV_DCT_Matrix(TheInvDCTMatrix);
    float data[8] = {5,2,25,12,3,1,1,2};
    //etimer_set(&timer, CLOCK_SECOND * 10);


        for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); i++)
        {
            printf("%d ", (int)data[i]);
        }
        printf("\n");
        DCT_Transform(data);
        for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); i++)
        {
            printf("%d ", (int)data[i]);
        }
        printf("\n");
        inv_DCT_Transform(data);
        for (size_t i = 0; i < sizeof(data)/sizeof(data[0]); i++)
        {
            printf("%d ", (int)data[i]);
        }
        printf("\n");
        //PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
        //etimer_reset(&timer);
    PROCESS_END();
}