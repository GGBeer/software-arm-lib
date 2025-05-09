/*
 * Tests for the ioports.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 */

#include <catch.hpp>
#include <cstdio>
#include <sblib/ioports.h>
#include "test_ioports.h"


/**
 * Prints all REQUIRE(..) for @ref PortPin
 */
void printGpioValues()
{
    for (const PortPinInfo& pin : allPins) {
        printf("REQUIRE(%s == 0x%.8x);\n", pin.name, pin.pin);
    }
    printf("\n");
}

TEST_CASE("enum Port", "[ioports]")
{
    REQUIRE(PIO0 == 0);
    REQUIRE(PIO1 == 1);
    REQUIRE(PIO2 == 2);
    REQUIRE(PIO3 == 3);
}

TEST_CASE("enum PinFunc", "[ioports]")
{
    REQUIRE(PF_NONE == 0);
    REQUIRE(PF_PIO == 1);
    REQUIRE(PF_AD == 2);
    REQUIRE(PF_RESET == 3);
    REQUIRE(PF_SWDIO == 4);
    REQUIRE(PF_SWCLK == 5);
    REQUIRE(PF_MAT == 6);
    REQUIRE(PF_CAP == 7);
    REQUIRE(PF_CLKOUT == 8);
    REQUIRE(PF_SDA == 9);
    REQUIRE(PF_SCL == 10);
    REQUIRE(PF_SSEL == 11);
    REQUIRE(PF_MISO == 12);
    REQUIRE(PF_MOSI == 13);
    REQUIRE(PF_SCK == 14);
    REQUIRE(PF_RXD == 15);
    REQUIRE(PF_TXD == 16);
    REQUIRE(PF_RTS == 17);
    REQUIRE(PF_DTR == 18);
    REQUIRE(PF_DSR == 19);
    REQUIRE(PF_CTS == 20);
    REQUIRE(PF_DCD == 21);
    REQUIRE(PF_RI == 22);
    REQUIRE(PF_USBP == 23);
    REQUIRE(PF_USB_M == 24);
    REQUIRE(PF_USB_VBUS == 25);
    REQUIRE(PF_USB_CONNECT == 26);
    REQUIRE(PF_USB_FTOGGLE == 27);
    REQUIRE(PF_ARM_TRACE_CLK == 28);
    REQUIRE(PF_ARM_TRACE_SWV == 29);
    REQUIRE(PF_SCLK == 30);
}

TEST_CASE("PINMODE_FUNC", "[ioports]")
{
#ifndef PINMODE_FUNC
#  define PINMODE_FUNC PinModeFunc
#endif
    REQUIRE(PINMODE_FUNC(PF_NONE) == 0x00000000);
    REQUIRE(PINMODE_FUNC(PF_PIO) == 0x00040000);
    REQUIRE(PINMODE_FUNC(PF_AD) == 0x00080000);
    REQUIRE(PINMODE_FUNC(PF_RESET) == 0x000c0000);
    REQUIRE(PINMODE_FUNC(PF_SWDIO) == 0x00100000);
    REQUIRE(PINMODE_FUNC(PF_SWCLK) == 0x00140000);
    REQUIRE(PINMODE_FUNC(PF_MAT) == 0x00180000);
    REQUIRE(PINMODE_FUNC(PF_CAP) == 0x001c0000);
    REQUIRE(PINMODE_FUNC(PF_CLKOUT) == 0x00200000);
    REQUIRE(PINMODE_FUNC(PF_SDA) == 0x00240000);
    REQUIRE(PINMODE_FUNC(PF_SCL) == 0x00280000);
    REQUIRE(PINMODE_FUNC(PF_SSEL) == 0x002c0000);
    REQUIRE(PINMODE_FUNC(PF_MISO) == 0x00300000);
    REQUIRE(PINMODE_FUNC(PF_MOSI) == 0x00340000);
    REQUIRE(PINMODE_FUNC(PF_SCK) == 0x00380000);
    REQUIRE(PINMODE_FUNC(PF_RXD) == 0x003c0000);
    REQUIRE(PINMODE_FUNC(PF_TXD) == 0x00400000);
    REQUIRE(PINMODE_FUNC(PF_RTS) == 0x00440000);
    REQUIRE(PINMODE_FUNC(PF_DTR) == 0x00480000);
    REQUIRE(PINMODE_FUNC(PF_DSR) == 0x004c0000);
    REQUIRE(PINMODE_FUNC(PF_CTS) == 0x00500000);
    REQUIRE(PINMODE_FUNC(PF_DCD) == 0x00540000);
    REQUIRE(PINMODE_FUNC(PF_RI) == 0x00580000);
    REQUIRE(PINMODE_FUNC(PF_USBP) == 0x005c0000);
    REQUIRE(PINMODE_FUNC(PF_USB_M) == 0x00600000);
    REQUIRE(PINMODE_FUNC(PF_USB_VBUS) == 0x00640000);
    REQUIRE(PINMODE_FUNC(PF_USB_CONNECT) == 0x00680000);
    REQUIRE(PINMODE_FUNC(PF_USB_FTOGGLE) == 0x006c0000);
    REQUIRE(PINMODE_FUNC(PF_ARM_TRACE_CLK) == 0x00700000);
    REQUIRE(PINMODE_FUNC(PF_ARM_TRACE_SWV) == 0x00740000);
    REQUIRE(PINMODE_FUNC(PF_SCLK) == 0x00780000);
}

TEST_CASE("enum PortFunctionManipulator", "[ioports]")
{
    REQUIRE(PFL_ADMODE == 0x100);
    REQUIRE(PFF_SHIFT_OFFSET == 5);
    REQUIRE(PFF_MASK == 31);
    REQUIRE(PF0_SHIFT == 9);
    REQUIRE(PF1_SHIFT == 14);
    REQUIRE(PF2_SHIFT == 19);
    REQUIRE(PF3_SHIFT == 24);
}

TEST_CASE("enum PortPin", "[ioports]")
{
    // printGpioValues();
    REQUIRE(PIO0_0 == 0x00004600);
    REQUIRE(PIO0_1 == 0x00320201);
    REQUIRE(PIO0_2 == 0x003ac202);
    REQUIRE(PIO0_3 == 0x00000203);
    REQUIRE(PIO0_4 == 0x00028204);
    REQUIRE(PIO0_5 == 0x00024205);
    REQUIRE(PIO0_6 == 0x00700206);
    REQUIRE(PIO0_7 == 0x00050207);
    REQUIRE(PIO0_8 == 0x00330208);
    REQUIRE(PIO0_9 == 0x00334209);
    REQUIRE(PIO0_10 == 0x06704a0a);
    REQUIRE(PIO0_11 == 0x0610410b);

    REQUIRE(PIO1_0 == 0x07104120);
    REQUIRE(PIO1_1 == 0x06104121);
    REQUIRE(PIO1_2 == 0x06104122);
    REQUIRE(PIO1_3 == 0x06104923);
    REQUIRE(PIO1_4 == 0x00308324);
    REQUIRE(PIO1_5 == 0x003c4225);
    REQUIRE(PIO1_6 == 0x0033c226);
    REQUIRE(PIO1_7 == 0x00340227);
    REQUIRE(PIO1_8 == 0x0001c228);
    REQUIRE(PIO1_9 == 0x00698229);
    REQUIRE(PIO1_10 == 0x0c30832a);
    REQUIRE(PIO1_11 == 0x0038832b);

    REQUIRE(PIO2_0 == 0x005c8240);
    REQUIRE(PIO2_1 == 0x0074c241);
    REQUIRE(PIO2_2 == 0x00654242);
    REQUIRE(PIO2_3 == 0x006d8243);
    REQUIRE(PIO2_4 == 0x00598244);
    REQUIRE(PIO2_5 == 0x00018245);
    REQUIRE(PIO2_6 == 0x00018246);
    REQUIRE(PIO2_7 == 0x00798247);
    REQUIRE(PIO2_8 == 0x00818248);
    REQUIRE(PIO2_9 == 0x0001c249);
    REQUIRE(PIO2_10 == 0x0000024a);
    REQUIRE(PIO2_11 == 0x003b824b);

    REQUIRE(PIO3_0 == 0x10348260);
    REQUIRE(PIO3_1 == 0x0f34c261);
    REQUIRE(PIO3_2 == 0x0e354262);
    REQUIRE(PIO3_3 == 0x003d8263);
    REQUIRE(PIO3_4 == 0x0079c264);
    REQUIRE(PIO3_5 == 0x0081c265);
}

TEST_CASE("enum AnalogChannel", "[ioports]")
{
    REQUIRE(AD0 == 0);
    REQUIRE(AD1 == 1);
    REQUIRE(AD2 == 2);
    REQUIRE(AD3 == 3);
    REQUIRE(AD4 == 4);
    REQUIRE(AD5 == 5);
    REQUIRE(AD6 == 6);
    REQUIRE(AD7 == 7);
}

