/*******************************************************************************
* Title                 :   8x8 click HAL
* Filename              :   eight_x_eight_hal.c
* Author                :   CAL
* Origin Date           :   03/29/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials       Description
*  03/29/2016       1.0.0          CAL        Module Created.
*
*******************************************************************************/
/**
 * @file eight_x_eight_hal.c
 * @brief <h2> HAL layer </h2>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "eight_x_eight_hal.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

static void         ( *write_spi_p )            ( unsigned int data_out );
static unsigned long( *read_spi_p )             ( unsigned int buffer );

extern sfr sbit LED_EIGHT_CS;


/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/
void led_eight_hal_cs_high()
{
    LED_EIGHT_CS = 1;
}

void led_eight_hal_cs_low()
{
    LED_EIGHT_CS = 0;
}

void led_eight_hal_init()
{
    write_spi_p             = SPI_Wr_Ptr;
    read_spi_p              = SPI_Rd_Ptr;
    led_eight_hal_cs_high();
}

void led_eight_hal_write( uint8_t *buffer )
{
    led_eight_hal_cs_low();
    write_spi_p( *( buffer )++ );
    write_spi_p( *buffer );
    led_eight_hal_cs_high();
}

/*************** END OF FUNCTIONS ***************************************************************************/