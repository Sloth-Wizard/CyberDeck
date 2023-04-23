#include "EPD_Test.h"
#include "EPD_2in13b_V3.h"
#include "ImageData.h"

#if 0
    EPD_2IN13B_V3_Init();
    EPD_2IN13_V3_Clear();

    UBYTE *BlackImage, *RYImage; // red
    UWORD Imagesize = ((EPD_2IN13B_V3_WIDTH % 8 == 0) ? (EPD_2IN13B_V3_WIDTH / 8) : (EPD_2IN13B_V3_WIDTH / 8 + 1)) * EPD_2IN13B_V3_HEIGHT;

    // Check for memory errors
    if((BlackImage = (UBYTE *)malloc(ImageSize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        while(1);
    }
    if((RYImage = (UBYTE *)malloc(ImageSize)) == NULL) {
        printf("Failed to apply for red memory...\r\n");
        while(1);
    }

    Paint_NewImage(BlackImage, EPD_2IN13B_V3_WIDTH, EPD_2IN13B_V3_HEIGHT, 270, WHITE);
    Paint_NewImage(RYImage, EPD_2IN13B_V3_WIDTH, EPD_2IN13B_V3_HEIGHT, 270, WHITE);

    // Select the image
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);
    Paint_SelectImage(RyImage);
    Paint_Clear(WHITE);

    // EPD_2IN13B_V3_Display(gImage_2in13b_r);
    EPD_2IN13B_V3_Display(gImage_2in13c_b, gImage_2in13c_y);

    EPD_2IN13_V3_Sleep();
    free(BlackImage);
    free(RYImage);
    BlackImage = NULL;
    RYImage = NULL;

    return 0;
#endif
