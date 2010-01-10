begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: aureg.h,v 1.18 2006/10/02 06:44:00 gdamore Exp $ */
end_comment

begin_comment
comment|/*  * Copyright 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Simon Burge for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_ALCHEMY_AUREG_H
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_ALCHEMY_AUREG_H
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/********************   AC97 Controller registers   *********************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AC97_BASE
value|0x10000000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/***********************   USB Host registers   *************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|USBH_BASE
value|0x10100000
end_define

begin_define
define|#
directive|define
name|AU1550_USBH_BASE
value|0x14020000
end_define

begin_define
define|#
directive|define
name|USBH_ENABLE
value|0x7fffc
end_define

begin_define
define|#
directive|define
name|USBH_SIZE
value|0x100000
end_define

begin_define
define|#
directive|define
name|AU1550_USBH_ENABLE
value|0x7ffc
end_define

begin_define
define|#
directive|define
name|AU1550_USBH_SIZE
value|0x60000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/**********************   USB Device registers   ************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|USBD_BASE
value|0x10200000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*************************   IRDA registers   ***************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IRDA_BASE
value|0x10300000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/******************   Interrupt Controller registers   ******************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IC0_BASE
value|0x10400000
end_define

begin_define
define|#
directive|define
name|IC1_BASE
value|0x11800000
end_define

begin_comment
comment|/*  * The *_READ registers read the current value of the register  * The *_SET registers set to 1 all bits that are written 1  * The *_CLEAR registers clear to zero all bits that are written as 1  */
end_comment

begin_define
define|#
directive|define
name|IC_CONFIG0_READ
value|0x40
end_define

begin_comment
comment|/* See table below */
end_comment

begin_define
define|#
directive|define
name|IC_CONFIG0_SET
value|0x40
end_define

begin_define
define|#
directive|define
name|IC_CONFIG0_CLEAR
value|0x44
end_define

begin_define
define|#
directive|define
name|IC_CONFIG1_READ
value|0x48
end_define

begin_comment
comment|/* See table below */
end_comment

begin_define
define|#
directive|define
name|IC_CONFIG1_SET
value|0x48
end_define

begin_define
define|#
directive|define
name|IC_CONFIG1_CLEAR
value|0x4c
end_define

begin_define
define|#
directive|define
name|IC_CONFIG2_READ
value|0x50
end_define

begin_comment
comment|/* See table below */
end_comment

begin_define
define|#
directive|define
name|IC_CONFIG2_SET
value|0x50
end_define

begin_define
define|#
directive|define
name|IC_CONFIG2_CLEAR
value|0x54
end_define

begin_define
define|#
directive|define
name|IC_REQUEST0_INT
value|0x54
end_define

begin_comment
comment|/* Show active interrupts on request 0 */
end_comment

begin_define
define|#
directive|define
name|IC_SOURCE_READ
value|0x58
end_define

begin_comment
comment|/* Interrupt source */
end_comment

begin_define
define|#
directive|define
name|IC_SOURCE_SET
value|0x58
end_define

begin_comment
comment|/*  0 - test bit used as source */
end_comment

begin_define
define|#
directive|define
name|IC_SOURCE_CLEAR
value|0x5c
end_define

begin_comment
comment|/*  1 - peripheral/GPIO used as source */
end_comment

begin_define
define|#
directive|define
name|IC_REQUEST1_INT
value|0x5c
end_define

begin_comment
comment|/* Show active interrupts on request 1 */
end_comment

begin_define
define|#
directive|define
name|IC_ASSIGN_REQUEST_READ
value|0x60
end_define

begin_comment
comment|/* Assigns the interrupt to one of the */
end_comment

begin_define
define|#
directive|define
name|IC_ASSIGN_REQUEST_SET
value|0x60
end_define

begin_comment
comment|/* CPU requests (0 - assign to request 1, */
end_comment

begin_define
define|#
directive|define
name|IC_ASSIGN_REQUEST_CLEAR
value|0x64
end_define

begin_comment
comment|/* 1 - assign to request 0) */
end_comment

begin_define
define|#
directive|define
name|IC_WAKEUP_READ
value|0x68
end_define

begin_comment
comment|/* Controls whether the interrupt can */
end_comment

begin_define
define|#
directive|define
name|IC_WAKEUP_SET
value|0x68
end_define

begin_comment
comment|/* cause a wakeup from IDLE */
end_comment

begin_define
define|#
directive|define
name|IC_WAKEUP_CLEAR
value|0x6c
end_define

begin_define
define|#
directive|define
name|IC_MASK_READ
value|0x70
end_define

begin_comment
comment|/* Enables/Disables the interrupt */
end_comment

begin_define
define|#
directive|define
name|IC_MASK_SET
value|0x70
end_define

begin_define
define|#
directive|define
name|IC_MASK_CLEAR
value|0x74
end_define

begin_define
define|#
directive|define
name|IC_RISING_EDGE
value|0x78
end_define

begin_comment
comment|/* Check/clear rising edge */
end_comment

begin_define
define|#
directive|define
name|IC_FALLING_EDGE
value|0x7c
end_define

begin_comment
comment|/* Check/clear falling edge */
end_comment

begin_define
define|#
directive|define
name|IC_TEST_BIT
value|0x80
end_define

begin_comment
comment|/* single bit source select */
end_comment

begin_comment
comment|/*  *	Interrupt Configuration Register Functions  *  *	Cfg2[n]	Cfg1[n]	Cfg0[n]		Function  *	   0	   0	   0		Interrupts Disabled  *	   0	   0	   1		Rising Edge Enabled  *	   0	   1	   0		Falling Edge Enabled  *	   0	   1	   1		Rising and Falling Edge Enabled  *	   1	   0	   0		Interrupts Disabled  *	   1	   0	   1		High Level Enabled  *	   1	   1	   0		Low Level Enabled  *	   1	   1	   1		Both Levels and Both Edges Enabled  */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*************   Programable Serial Controller registers   **************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PSC0_BASE
value|0x11A00000
end_define

begin_define
define|#
directive|define
name|PSC1_BASE
value|0x11B00000
end_define

begin_define
define|#
directive|define
name|PSC2_BASE
value|0x10A00000
end_define

begin_define
define|#
directive|define
name|PSC3_BASE
value|0x10B00000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/**********************   Ethernet MAC registers   **********************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MAC0_BASE
value|0x10500000
end_define

begin_define
define|#
directive|define
name|MAC1_BASE
value|0x10510000
end_define

begin_define
define|#
directive|define
name|MACx_SIZE
value|0x28
end_define

begin_define
define|#
directive|define
name|AU1500_MAC0_BASE
value|0x11500000
end_define

begin_comment
comment|/* Grr, different on Au1500 */
end_comment

begin_define
define|#
directive|define
name|AU1500_MAC1_BASE
value|0x11510000
end_define

begin_comment
comment|/* Grr, different on Au1500 */
end_comment

begin_define
define|#
directive|define
name|MAC0_ENABLE
value|0x10520000
end_define

begin_define
define|#
directive|define
name|MAC1_ENABLE
value|0x10520004
end_define

begin_define
define|#
directive|define
name|MACENx_SIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|AU1500_MAC0_ENABLE
value|0x11520000
end_define

begin_comment
comment|/* Grr, different on Au1500 */
end_comment

begin_define
define|#
directive|define
name|AU1500_MAC1_ENABLE
value|0x11520004
end_define

begin_comment
comment|/* Grr, different on Au1500 */
end_comment

begin_define
define|#
directive|define
name|MAC0_DMA_BASE
value|0x14004000
end_define

begin_define
define|#
directive|define
name|MAC1_DMA_BASE
value|0x14004200
end_define

begin_define
define|#
directive|define
name|MACx_DMA_SIZE
value|0x140
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/**********************   Static Bus registers   ************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|STATIC_BUS_BASE
value|0x14001000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/********************   Secure Digital registers   **********************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SD0_BASE
value|0x10600000
end_define

begin_define
define|#
directive|define
name|SD1_BASE
value|0x10680000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*************************   I^2S registers   ***************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|I2S_BASE
value|0x11000000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/**************************   UART registers   **************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|UART0_BASE
value|0x11100000
end_define

begin_define
define|#
directive|define
name|UART1_BASE
value|0x11200000
end_define

begin_define
define|#
directive|define
name|UART2_BASE
value|0x11300000
end_define

begin_define
define|#
directive|define
name|UART3_BASE
value|0x11400000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*************************   SSI registers   ****************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SSI0_BASE
value|0x11600000
end_define

begin_define
define|#
directive|define
name|SSI1_BASE
value|0x11680000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/************************   GPIO2 registers   ***************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|GPIO_BASE
value|0x11900100
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/************************   GPIO2 registers   ***************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|GPIO2_BASE
value|0x11700000
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*************************   PCI registers   ****************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PCI_BASE
value|0x14005000
end_define

begin_define
define|#
directive|define
name|PCI_HEADER
value|0x14005100
end_define

begin_define
define|#
directive|define
name|PCI_MEM_BASE
value|0x400000000ULL
end_define

begin_define
define|#
directive|define
name|PCI_IO_BASE
value|0x500000000ULL
end_define

begin_define
define|#
directive|define
name|PCI_CONFIG_BASE
value|0x600000000ULL
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/***********************   PCMCIA registers   ***************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PCMCIA_BASE
value|0xF00000000ULL
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/******************   Programmable Counter registers   ******************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SYS_BASE
value|0x11900000
end_define

begin_define
define|#
directive|define
name|PC_BASE
value|SYS_BASE
end_define

begin_define
define|#
directive|define
name|PC_TRIM0
value|0x00
end_define

begin_comment
comment|/* PC0 Divide (16 bits) */
end_comment

begin_define
define|#
directive|define
name|PC_COUNTER_WRITE0
value|0x04
end_define

begin_comment
comment|/* set PC0 */
end_comment

begin_define
define|#
directive|define
name|PC_MATCH0_0
value|0x08
end_define

begin_comment
comment|/* match counter& interrupt */
end_comment

begin_define
define|#
directive|define
name|PC_MATCH1_0
value|0x0c
end_define

begin_comment
comment|/* match counter& interrupt */
end_comment

begin_define
define|#
directive|define
name|PC_MATCH2_0
value|0x10
end_define

begin_comment
comment|/* match counter& interrupt */
end_comment

begin_define
define|#
directive|define
name|PC_COUNTER_CONTROL
value|0x14
end_define

begin_comment
comment|/* Programmable Counter Control */
end_comment

begin_define
define|#
directive|define
name|CC_E1S
value|0x00800000
end_define

begin_comment
comment|/* Enable PC1 write status */
end_comment

begin_define
define|#
directive|define
name|CC_T1S
value|0x00100000
end_define

begin_comment
comment|/* Trim PC1 write status */
end_comment

begin_define
define|#
directive|define
name|CC_M21
value|0x00080000
end_define

begin_comment
comment|/* Match 2 of PC1 write status */
end_comment

begin_define
define|#
directive|define
name|CC_M11
value|0x00040000
end_define

begin_comment
comment|/* Match 1 of PC1 write status */
end_comment

begin_define
define|#
directive|define
name|CC_M01
value|0x00020000
end_define

begin_comment
comment|/* Match 0 of PC1 write status */
end_comment

begin_define
define|#
directive|define
name|CC_C1S
value|0x00010000
end_define

begin_comment
comment|/* PC1 write status */
end_comment

begin_define
define|#
directive|define
name|CC_BP
value|0x00004000
end_define

begin_comment
comment|/* Bypass OSC (use GPIO1) */
end_comment

begin_define
define|#
directive|define
name|CC_EN1
value|0x00002000
end_define

begin_comment
comment|/* Enable PC1 */
end_comment

begin_define
define|#
directive|define
name|CC_BT1
value|0x00001000
end_define

begin_comment
comment|/* Bypass Trim on PC1 */
end_comment

begin_define
define|#
directive|define
name|CC_EN0
value|0x00000800
end_define

begin_comment
comment|/* Enable PC0 */
end_comment

begin_define
define|#
directive|define
name|CC_BT0
value|0x00000400
end_define

begin_comment
comment|/* Bypass Trim on PC0 */
end_comment

begin_define
define|#
directive|define
name|CC_EO
value|0x00000100
end_define

begin_comment
comment|/* Enable Oscillator */
end_comment

begin_define
define|#
directive|define
name|CC_E0S
value|0x00000080
end_define

begin_comment
comment|/* Enable PC0 write status */
end_comment

begin_define
define|#
directive|define
name|CC_32S
value|0x00000020
end_define

begin_comment
comment|/* 32.768kHz OSC status */
end_comment

begin_define
define|#
directive|define
name|CC_T0S
value|0x00000010
end_define

begin_comment
comment|/* Trim PC0 write status */
end_comment

begin_define
define|#
directive|define
name|CC_M20
value|0x00000008
end_define

begin_comment
comment|/* Match 2 of PC0 write status */
end_comment

begin_define
define|#
directive|define
name|CC_M10
value|0x00000004
end_define

begin_comment
comment|/* Match 1 of PC0 write status */
end_comment

begin_define
define|#
directive|define
name|CC_M00
value|0x00000002
end_define

begin_comment
comment|/* Match 0 of PC0 write status */
end_comment

begin_define
define|#
directive|define
name|CC_C0S
value|0x00000001
end_define

begin_comment
comment|/* PC0 write status */
end_comment

begin_define
define|#
directive|define
name|PC_COUNTER_READ_0
value|0x40
end_define

begin_comment
comment|/* get PC0 */
end_comment

begin_define
define|#
directive|define
name|PC_TRIM1
value|0x44
end_define

begin_comment
comment|/* PC1 Divide (16 bits) */
end_comment

begin_define
define|#
directive|define
name|PC_COUNTER_WRITE1
value|0x48
end_define

begin_comment
comment|/* set PC1 */
end_comment

begin_define
define|#
directive|define
name|PC_MATCH0_1
value|0x4c
end_define

begin_comment
comment|/* match counter& interrupt */
end_comment

begin_define
define|#
directive|define
name|PC_MATCH1_1
value|0x50
end_define

begin_comment
comment|/* match counter& interrupt */
end_comment

begin_define
define|#
directive|define
name|PC_MATCH2_1
value|0x54
end_define

begin_comment
comment|/* match counter& interrupt */
end_comment

begin_define
define|#
directive|define
name|PC_COUNTER_READ_1
value|0x58
end_define

begin_comment
comment|/* get PC1 */
end_comment

begin_define
define|#
directive|define
name|PC_SIZE
value|0x5c
end_define

begin_comment
comment|/* size of register set */
end_comment

begin_define
define|#
directive|define
name|PC_RATE
value|32768
end_define

begin_comment
comment|/* counter rate is 32.768kHz */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/*******************   Frequency Generator Registers   ******************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SYS_FREQCTRL0
value|(SYS_BASE + 0x20)
end_define

begin_define
define|#
directive|define
name|SFC_FRDIV2
parameter_list|(
name|f
parameter_list|)
value|(f<<22)
end_define

begin_comment
comment|/* 29:22. Freq Divider 2 */
end_comment

begin_define
define|#
directive|define
name|SFC_FE2
value|(1<<21)
end_define

begin_comment
comment|/* Freq generator output enable 2 */
end_comment

begin_define
define|#
directive|define
name|SFC_FS2
value|(1<<20)
end_define

begin_comment
comment|/* Freq generator source 2 */
end_comment

begin_define
define|#
directive|define
name|SFC_FRDIV1
parameter_list|(
name|f
parameter_list|)
value|(f<<12)
end_define

begin_comment
comment|/* 19:12. Freq Divider 1 */
end_comment

begin_define
define|#
directive|define
name|SFC_FE1
value|(1<<11)
end_define

begin_comment
comment|/* Freq generator output enable 1 */
end_comment

begin_define
define|#
directive|define
name|SFC_FS1
value|(1<<10)
end_define

begin_comment
comment|/* Freq generator source 1 */
end_comment

begin_define
define|#
directive|define
name|SFC_FRDIV0
parameter_list|(
name|f
parameter_list|)
value|(f<<2)
end_define

begin_comment
comment|/* 9:2. Freq Divider 0 */
end_comment

begin_define
define|#
directive|define
name|SFC_FE0
value|2
end_define

begin_comment
comment|/* Freq generator output enable 0 */
end_comment

begin_define
define|#
directive|define
name|SFC_FS0
value|1
end_define

begin_comment
comment|/* Freq generator source 0 */
end_comment

begin_define
define|#
directive|define
name|SYS_FREQCTRL1
value|(SYS_BASE + 0x24)
end_define

begin_define
define|#
directive|define
name|SFC_FRDIV5
parameter_list|(
name|f
parameter_list|)
value|(f<<22)
end_define

begin_comment
comment|/* 29:22. Freq Divider 5 */
end_comment

begin_define
define|#
directive|define
name|SFC_FE5
value|(1<<21)
end_define

begin_comment
comment|/* Freq generator output enable 5 */
end_comment

begin_define
define|#
directive|define
name|SFC_FS5
value|(1<<20)
end_define

begin_comment
comment|/* Freq generator source 5 */
end_comment

begin_define
define|#
directive|define
name|SFC_FRDIV4
parameter_list|(
name|f
parameter_list|)
value|(f<<12)
end_define

begin_comment
comment|/* 19:12. Freq Divider 4 */
end_comment

begin_define
define|#
directive|define
name|SFC_FE4
value|(1<<11)
end_define

begin_comment
comment|/* Freq generator output enable 4 */
end_comment

begin_define
define|#
directive|define
name|SFC_FS4
value|(1<<10)
end_define

begin_comment
comment|/* Freq generator source 4 */
end_comment

begin_define
define|#
directive|define
name|SFC_FRDIV3
parameter_list|(
name|f
parameter_list|)
value|(f<<2)
end_define

begin_comment
comment|/* 9:2. Freq Divider 3 */
end_comment

begin_define
define|#
directive|define
name|SFC_FE3
value|2
end_define

begin_comment
comment|/* Freq generator output enable 3 */
end_comment

begin_define
define|#
directive|define
name|SFC_FS3
value|1
end_define

begin_comment
comment|/* Freq generator source 3 */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/******************   Clock Source Control Registers   ******************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SYS_CLKSRC
value|(SYS_BASE + 0x28)
end_define

begin_define
define|#
directive|define
name|SCS_ME1
parameter_list|(
name|n
parameter_list|)
value|(n<<27)
end_define

begin_comment
comment|/* EXTCLK1 Clock Mux input select */
end_comment

begin_define
define|#
directive|define
name|SCS_ME0
parameter_list|(
name|n
parameter_list|)
value|(n<<22)
end_define

begin_comment
comment|/* EXTCLK0 Clock Mux input select */
end_comment

begin_define
define|#
directive|define
name|SCS_MPC
parameter_list|(
name|n
parameter_list|)
value|(n<<17)
end_define

begin_comment
comment|/* PCI clock mux input select */
end_comment

begin_define
define|#
directive|define
name|SCS_MUH
parameter_list|(
name|n
parameter_list|)
value|(n<<12)
end_define

begin_comment
comment|/* USB Host clock mux input select */
end_comment

begin_define
define|#
directive|define
name|SCS_MUD
parameter_list|(
name|n
parameter_list|)
value|(n<<7)
end_define

begin_comment
comment|/* USB Device clock mux input select */
end_comment

begin_define
define|#
directive|define
name|SCS_MEx_AUX
value|0x1
end_define

begin_comment
comment|/* Aux clock */
end_comment

begin_define
define|#
directive|define
name|SCS_MEx_FREQ0
value|0x2
end_define

begin_comment
comment|/* FREQ0 */
end_comment

begin_define
define|#
directive|define
name|SCS_MEx_FREQ1
value|0x3
end_define

begin_comment
comment|/* FREQ1 */
end_comment

begin_define
define|#
directive|define
name|SCS_MEx_FREQ2
value|0x4
end_define

begin_comment
comment|/* FREQ2 */
end_comment

begin_define
define|#
directive|define
name|SCS_MEx_FREQ3
value|0x5
end_define

begin_comment
comment|/* FREQ3 */
end_comment

begin_define
define|#
directive|define
name|SCS_MEx_FREQ4
value|0x6
end_define

begin_comment
comment|/* FREQ4 */
end_comment

begin_define
define|#
directive|define
name|SCS_MEx_FREQ5
value|0x7
end_define

begin_comment
comment|/* FREQ5 */
end_comment

begin_define
define|#
directive|define
name|SCS_DE1
value|(1<<26)
end_define

begin_comment
comment|/* EXTCLK1 clock divider select */
end_comment

begin_define
define|#
directive|define
name|SCS_CE1
value|(1<<25)
end_define

begin_comment
comment|/* EXTCLK1 clock select */
end_comment

begin_define
define|#
directive|define
name|SCS_DE0
value|(1<<21)
end_define

begin_comment
comment|/* EXTCLK0 clock divider select */
end_comment

begin_define
define|#
directive|define
name|SCS_CE0
value|(1<<20)
end_define

begin_comment
comment|/* EXTCLK0 clock select */
end_comment

begin_define
define|#
directive|define
name|SCS_DPC
value|(1<<16)
end_define

begin_comment
comment|/* PCI clock divider select */
end_comment

begin_define
define|#
directive|define
name|SCS_CPC
value|(1<<15)
end_define

begin_comment
comment|/* PCI clock select */
end_comment

begin_define
define|#
directive|define
name|SCS_DUH
value|(1<<11)
end_define

begin_comment
comment|/* USB Host clock divider select */
end_comment

begin_define
define|#
directive|define
name|SCS_CUH
value|(1<<10)
end_define

begin_comment
comment|/* USB Host clock select */
end_comment

begin_define
define|#
directive|define
name|SCS_DUD
value|(1<<6)
end_define

begin_comment
comment|/* USB Device clock divider select */
end_comment

begin_define
define|#
directive|define
name|SCS_CUD
value|(1<<5)
end_define

begin_comment
comment|/* USB Device clock select */
end_comment

begin_comment
comment|/*  * Au1550 bits, needed for PSCs. Note that some bits collide with  * earlier parts.  On Au1550, USB clocks (both device and host) are  * shared with PSC2, and must be configured for 48MHz.  DBAU1550 YAMON  * does this by default.  Also, EXTCLK0 is shared with PSC3.  DBAU1550  * YAMON does not configure any clocks besides PSC2.  */
end_comment

begin_define
define|#
directive|define
name|SCS_MP3
parameter_list|(
name|n
parameter_list|)
value|(n<<22)
end_define

begin_comment
comment|/* psc3_intclock mux */
end_comment

begin_define
define|#
directive|define
name|SCS_DP3
value|(1<<21)
end_define

begin_comment
comment|/* psc3_intclock divider */
end_comment

begin_define
define|#
directive|define
name|SCS_CP3
value|(1<<20)
end_define

begin_comment
comment|/* psc3_intclock select */
end_comment

begin_define
define|#
directive|define
name|SCS_MP1
parameter_list|(
name|n
parameter_list|)
value|(n<<12)
end_define

begin_comment
comment|/* psc1_intclock mux */
end_comment

begin_define
define|#
directive|define
name|SCS_DP1
value|(1<<11)
end_define

begin_comment
comment|/* psc1_intclock divider */
end_comment

begin_define
define|#
directive|define
name|SCS_CP1
value|(1<<10)
end_define

begin_comment
comment|/* psc1_intclock select */
end_comment

begin_define
define|#
directive|define
name|SCS_MP0
parameter_list|(
name|n
parameter_list|)
value|(n<<7)
end_define

begin_comment
comment|/* psc0_intclock mux */
end_comment

begin_define
define|#
directive|define
name|SCS_DP0
value|(1<<6)
end_define

begin_comment
comment|/* psc0_intclock divider */
end_comment

begin_define
define|#
directive|define
name|SCS_CP0
value|(1<<5)
end_define

begin_comment
comment|/* psc0_intclock seelct */
end_comment

begin_define
define|#
directive|define
name|SCS_MP2
parameter_list|(
name|n
parameter_list|)
value|(n<<2)
end_define

begin_comment
comment|/* psc2_intclock mux */
end_comment

begin_define
define|#
directive|define
name|SCS_DP2
value|(1<<1)
end_define

begin_comment
comment|/* psc2_intclock divider */
end_comment

begin_define
define|#
directive|define
name|SCS_CP2
value|(1<<0)
end_define

begin_comment
comment|/* psc2_intclock select */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/***************************  PIN Function  *****************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SYS_PINFUNC
value|(SYS_BASE + 0x2c)
end_define

begin_define
define|#
directive|define
name|SPF_PSC3_MASK
value|(7<<20)
end_define

begin_define
define|#
directive|define
name|SPF_PSC3_AC97
value|(0<<17)
end_define

begin_comment
comment|/* select AC97/SPI */
end_comment

begin_define
define|#
directive|define
name|SPF_PSC3_I2S
value|(1<<17)
end_define

begin_comment
comment|/* select I2S */
end_comment

begin_define
define|#
directive|define
name|SPF_PSC3_SMBUS
value|(3<<17)
end_define

begin_comment
comment|/* select SMbus */
end_comment

begin_define
define|#
directive|define
name|SPF_PSC3_GPIO
value|(7<<17)
end_define

begin_comment
comment|/* select gpio215:211 */
end_comment

begin_define
define|#
directive|define
name|SPF_PSC2_MASK
value|(7<<17)
end_define

begin_define
define|#
directive|define
name|SPF_PSC2_AC97
value|(0<<17)
end_define

begin_comment
comment|/* select AC97/SPI */
end_comment

begin_define
define|#
directive|define
name|SPF_PSC2_I2S
value|(1<<17)
end_define

begin_comment
comment|/* select I2S */
end_comment

begin_define
define|#
directive|define
name|SPF_PSC2_SMBUS
value|(3<<17)
end_define

begin_comment
comment|/* select SMbus */
end_comment

begin_define
define|#
directive|define
name|SPF_PSC2_GPIO
value|(7<<17)
end_define

begin_comment
comment|/* select gpio210:206*/
end_comment

begin_define
define|#
directive|define
name|SPF_CS
value|(1<<16)
end_define

begin_comment
comment|/* extclk0 or 32kHz osc */
end_comment

begin_define
define|#
directive|define
name|SPF_USB
value|(1<<15)
end_define

begin_comment
comment|/* host or device usb otg */
end_comment

begin_define
define|#
directive|define
name|SPF_U3T
value|(1<<14)
end_define

begin_comment
comment|/* uart3 tx or gpio23 */
end_comment

begin_define
define|#
directive|define
name|SPF_U1R
value|(1<<13)
end_define

begin_comment
comment|/* uart1 rx or gpio22 */
end_comment

begin_define
define|#
directive|define
name|SPF_U1T
value|(1<<12)
end_define

begin_comment
comment|/* uart1 tx or gpio21 */
end_comment

begin_define
define|#
directive|define
name|SPF_EX1
value|(1<<10)
end_define

begin_comment
comment|/* gpio3 or extclk1 */
end_comment

begin_define
define|#
directive|define
name|SPF_EX0
value|(1<<9)
end_define

begin_comment
comment|/* gpio2 or extclk0/32kHz osc*/
end_comment

begin_define
define|#
directive|define
name|SPF_U3
value|(1<<7)
end_define

begin_comment
comment|/* gpio14:9 or uart3 */
end_comment

begin_define
define|#
directive|define
name|SPF_MBSa
value|(1<<5)
end_define

begin_comment
comment|/* must be set */
end_comment

begin_define
define|#
directive|define
name|SPF_NI2
value|(1<<4)
end_define

begin_comment
comment|/* enet1 or gpio28:24 */
end_comment

begin_define
define|#
directive|define
name|SPF_U0
value|(1<<3)
end_define

begin_comment
comment|/* uart0 or gpio20 */
end_comment

begin_define
define|#
directive|define
name|SPF_MBSb
value|(1<<2)
end_define

begin_comment
comment|/* must be set */
end_comment

begin_define
define|#
directive|define
name|SPF_S1
value|(1<<1)
end_define

begin_comment
comment|/* gpio17 or psc1_sync1 */
end_comment

begin_define
define|#
directive|define
name|SPF_S0
value|(1<<0)
end_define

begin_comment
comment|/* gpio16 or psc0_sync1 */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/***************************   PLL Control  *****************************/
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SYS_CPUPLL
value|(SYS_BASE + 0x60)
end_define

begin_define
define|#
directive|define
name|SYS_AUXPLL
value|(SYS_BASE + 0x64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_ALCHEMY_AUREG_H */
end_comment

end_unit

