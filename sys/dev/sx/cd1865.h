begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Device driver for Specialix I/O8+ multiport serial card.  *  * Copyright 2003 Frank Mayhar<frank@exit.com>  *  * Derived from the "si" driver by Peter Wemm<peter@netplex.com.au>, using  * lots of information from the Linux "specialix" driver by Roger Wolff  *<R.E.Wolff@BitWizard.nl> and from the Intel CD1865 "Intelligent Eight-  * Channel Communications Controller" datasheet.  Roger was also nice  * enough to answer numerous questions about stuff specific to the I/O8+  * not covered by the CD1865 datasheet.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notices, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notices, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN  * NO EVENT SHALL THE AUTHORS BE LIABLE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* CD1865 chip register definitions.  */
end_comment

begin_comment
comment|/*  * Service Match Register interrupt acknowledgement values.  *  * These values are "obligatory" if you use the register based  * interrupt acknowledgements; the wrong values can cause a lockup.  * See section 8.11.1 of the Intel CD1865 "Intelligent Eight-Channel  * Communications Controller" datasheet.  */
end_comment

begin_define
define|#
directive|define
name|CD1865_ACK_MINT
value|0x75
end_define

begin_comment
comment|/* goes to MSMR                               */
end_comment

begin_define
define|#
directive|define
name|CD1865_ACK_TINT
value|0x76
end_define

begin_comment
comment|/* goes to TSMR                               */
end_comment

begin_define
define|#
directive|define
name|CD1865_ACK_RINT
value|0x77
end_define

begin_comment
comment|/* goes to RSMR                               */
end_comment

begin_define
define|#
directive|define
name|CD1865_NUMCHAN
value|8
end_define

begin_comment
comment|/* Total number of channels.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CHARTICK
value|16
end_define

begin_comment
comment|/* Ticks per character.                       */
end_comment

begin_define
define|#
directive|define
name|CD1865_TFIFOSZ
value|8
end_define

begin_comment
comment|/* TX FIFO size.                              */
end_comment

begin_define
define|#
directive|define
name|CD1865_RFIFOSZ
value|8
end_define

begin_comment
comment|/* RX FIFO size.                              */
end_comment

begin_comment
comment|/*  * Global registers.  *	These registers are not associated with any particular channel;  *	some define the general behavior of the card and others are only  *	active during service requests.  */
end_comment

begin_define
define|#
directive|define
name|CD1865_GIVR
value|0x40
end_define

begin_comment
comment|/* Global Interrupt Vector Register.          */
end_comment

begin_comment
comment|/* The CD1865 datasheet calls this the        */
end_comment

begin_comment
comment|/* "Global Vector Register" _and_ the         */
end_comment

begin_comment
comment|/* "Global Service Vector Register," GSVR.    */
end_comment

begin_define
define|#
directive|define
name|CD1865_GSVR
value|CD1865_GIVR
end_define

begin_define
define|#
directive|define
name|CD1865_GICR
value|0x41
end_define

begin_comment
comment|/* Global Interrupting Channel Register.      */
end_comment

begin_comment
comment|/* The CD1865 datasheet calls this the        */
end_comment

begin_comment
comment|/* "Global Channel Register 1," GSCR1.        */
end_comment

begin_define
define|#
directive|define
name|CD1865_GSCR1
value|CD1865_GICR
end_define

begin_define
define|#
directive|define
name|CD1865_GSCR2
value|0x42
end_define

begin_comment
comment|/* Global Channel Register 2.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_GSCR3
value|0x43
end_define

begin_comment
comment|/* Global Channel Register 3.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSMR
value|0x61
end_define

begin_comment
comment|/* Priority Interrupt Level Register 1.       */
end_comment

begin_define
define|#
directive|define
name|CD1865_TSMR
value|0x62
end_define

begin_comment
comment|/* Priority Interrupt Level Register 2.       */
end_comment

begin_define
define|#
directive|define
name|CD1865_RSMR
value|0x63
end_define

begin_comment
comment|/* Priority Interrupt Level Register 3.       */
end_comment

begin_define
define|#
directive|define
name|CD1865_CAR
value|0x64
end_define

begin_comment
comment|/* Channel Access Register.                   */
end_comment

begin_define
define|#
directive|define
name|CD1865_SRSR
value|0x65
end_define

begin_comment
comment|/* Service Request Status Register.           */
end_comment

begin_define
define|#
directive|define
name|CD1865_SRCR
value|0x66
end_define

begin_comment
comment|/* Service Request Configuration Register.    */
end_comment

begin_define
define|#
directive|define
name|CD1865_GFRCR
value|0x6b
end_define

begin_comment
comment|/* Global Firmware Revision Code Register.    */
end_comment

begin_define
define|#
directive|define
name|CD1865_PPRH
value|0x70
end_define

begin_comment
comment|/* Prescaler Period Register High.            */
end_comment

begin_define
define|#
directive|define
name|CD1865_PPRL
value|0x71
end_define

begin_comment
comment|/* Prescaler Period Register Low.             */
end_comment

begin_define
define|#
directive|define
name|CD1865_RDR
value|0x78
end_define

begin_comment
comment|/* Receiver Data Register.                    */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR
value|0x7a
end_define

begin_comment
comment|/* Receiver Character Status Register.        */
end_comment

begin_define
define|#
directive|define
name|CD1865_TDR
value|0x7b
end_define

begin_comment
comment|/* Transmit Data Register.                    */
end_comment

begin_define
define|#
directive|define
name|CD1865_EOIR
value|0x7f
end_define

begin_comment
comment|/* End of Interrupt Register.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_MRAR
value|0x75
end_define

begin_comment
comment|/* Modem Request Acknowlege Register.         */
end_comment

begin_define
define|#
directive|define
name|CD1865_TRAR
value|0x76
end_define

begin_comment
comment|/* Transmit Request Acknowlege Register.      */
end_comment

begin_define
define|#
directive|define
name|CD1865_RRAR
value|0x77
end_define

begin_comment
comment|/* Receive Request Acknowlege Register.       */
end_comment

begin_comment
comment|/*  * Channel Registers  *	These registers control or provide status for individual channels.  *	Use the CD1865_CAR register to set up access to the channel before  *	using these registers.  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR
value|0x01
end_define

begin_comment
comment|/* Channel Command Register.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER
value|0x02
end_define

begin_comment
comment|/* Interrupt Enable Register.                 */
end_comment

begin_comment
comment|/* The CD1865 datasheet calls this the        */
end_comment

begin_comment
comment|/* "Service Request Enable Register," SRER.   */
end_comment

begin_define
define|#
directive|define
name|CD1865_SRER
value|CD1865_IER
end_define

begin_define
define|#
directive|define
name|CD1865_COR1
value|0x03
end_define

begin_comment
comment|/* Channel Option Register 1.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2
value|0x04
end_define

begin_comment
comment|/* Channel Option Register 2.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR3
value|0x05
end_define

begin_comment
comment|/* Channel Option Register 3.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCSR
value|0x06
end_define

begin_comment
comment|/* Channel Control Status Register.           */
end_comment

begin_define
define|#
directive|define
name|CD1865_RDCR
value|0x07
end_define

begin_comment
comment|/* Receive Data Count Register.               */
end_comment

begin_define
define|#
directive|define
name|CD1865_SCHR1
value|0x09
end_define

begin_comment
comment|/* Special Character Register 1.              */
end_comment

begin_define
define|#
directive|define
name|CD1865_SCHR2
value|0x0a
end_define

begin_comment
comment|/* Special Character Register 2.              */
end_comment

begin_define
define|#
directive|define
name|CD1865_SCHR3
value|0x0b
end_define

begin_comment
comment|/* Special Character Register 3.              */
end_comment

begin_define
define|#
directive|define
name|CD1865_SCHR4
value|0x0c
end_define

begin_comment
comment|/* Special Character Register 4.              */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR1
value|0x10
end_define

begin_comment
comment|/* Modem Change Option 1 Register.            */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR2
value|0x11
end_define

begin_comment
comment|/* Modem Change Option 2 Register.            */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCR
value|0x12
end_define

begin_comment
comment|/* Modem Change Register.                     */
end_comment

begin_define
define|#
directive|define
name|CD1865_RTPR
value|0x18
end_define

begin_comment
comment|/* Receive Timeout Period Register.           */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR
value|0x28
end_define

begin_comment
comment|/* Modem Signal Value Register.               */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVRTS
value|0x29
end_define

begin_comment
comment|/* Modem Signal Value Register.               */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVDTR
value|0x2a
end_define

begin_comment
comment|/* Modem Signal Value Register.               */
end_comment

begin_define
define|#
directive|define
name|CD1865_RBPRH
value|0x31
end_define

begin_comment
comment|/* Receive Baud Rate Period Register High.    */
end_comment

begin_define
define|#
directive|define
name|CD1865_RBPRL
value|0x32
end_define

begin_comment
comment|/* Receive Baud Rate Period Register Low.     */
end_comment

begin_define
define|#
directive|define
name|CD1865_TBPRH
value|0x39
end_define

begin_comment
comment|/* Transmit Baud Rate Period Register High.   */
end_comment

begin_define
define|#
directive|define
name|CD1865_TBPRL
value|0x3a
end_define

begin_comment
comment|/* Transmit Baud Rate Period Register Low.    */
end_comment

begin_comment
comment|/*  * Global Interrupt Vector Register, read/write (0x40).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_GIVR_ITMASK
value|0x07
end_define

begin_comment
comment|/* Interrupt type mask.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_GIVR_IT_MODEM
value|0x01
end_define

begin_comment
comment|/* Modem Signal Change Interrupt.        */
end_comment

begin_define
define|#
directive|define
name|CD1865_GIVR_IT_TX
value|0x02
end_define

begin_comment
comment|/* Transmit Data Interrupt.              */
end_comment

begin_define
define|#
directive|define
name|CD1865_GIVR_IT_RCV
value|0x03
end_define

begin_comment
comment|/* Receive Good Data Interrupt.          */
end_comment

begin_define
define|#
directive|define
name|CD1865_GIVR_IT_REXC
value|0x07
end_define

begin_comment
comment|/* Receive Exception Interrupt.          */
end_comment

begin_comment
comment|/*  * Global Interrupt Channel Register read/write (0x41)  */
end_comment

begin_define
define|#
directive|define
name|CD1865_GICR_CHAN_MASK
value|0x1c
end_define

begin_comment
comment|/* Channel Number Mask.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_GICR_CHAN_SHIFT
value|2
end_define

begin_comment
comment|/* Channel Number shift.                 */
end_comment

begin_comment
comment|/*  * Channel Access Register, read/write (0x64).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CAR_CHAN_MASK
value|0x07
end_define

begin_comment
comment|/* Channel Number Mask.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CAR_A7
value|0x08
end_define

begin_comment
comment|/* A7 Address Extension (unused).        */
end_comment

begin_comment
comment|/*  * Receive Character Status Register, readonly (0x7a).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_TOUT
value|0x80
end_define

begin_comment
comment|/* Rx Timeout.                           */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_SCDET
value|0x70
end_define

begin_comment
comment|/* Special Character Detected Mask.      */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_NO_SC
value|0x00
end_define

begin_comment
comment|/* No Special Characters Detected.       */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_SC_1
value|0x10
end_define

begin_comment
comment|/* Special Char 1 (or 1& 3) Detected.   */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_SC_2
value|0x20
end_define

begin_comment
comment|/* Special Char 2 (or 2& 4) Detected.   */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_SC_3
value|0x30
end_define

begin_comment
comment|/* Special Char 3 Detected.              */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_SC_4
value|0x40
end_define

begin_comment
comment|/* Special Char 4 Detected.              */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_BREAK
value|0x08
end_define

begin_comment
comment|/* Break detected.                       */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_PE
value|0x04
end_define

begin_comment
comment|/* Parity Error.                         */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_FE
value|0x02
end_define

begin_comment
comment|/* Frame Error.                          */
end_comment

begin_define
define|#
directive|define
name|CD1865_RCSR_OE
value|0x01
end_define

begin_comment
comment|/* Overrun Error.                        */
end_comment

begin_comment
comment|/*  * Channel Command Register, read/write (0x01)  * 	Commands in groups can be OR-ed together.  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_HARDRESET
value|0x81
end_define

begin_comment
comment|/* Reset the CD1865 (like a powercycle). */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_SOFTRESET
value|0x80
end_define

begin_comment
comment|/* Soft Channel Reset (one channel).     */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_CORCHG1
value|0x42
end_define

begin_comment
comment|/* Channel Option Register 1 Changed.    */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_CORCHG2
value|0x44
end_define

begin_comment
comment|/* Channel Option Register 2 Changed.    */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_CORCHG3
value|0x48
end_define

begin_comment
comment|/* Channel Option Register 3 Changed.    */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_SSCH1
value|0x21
end_define

begin_comment
comment|/* Send Special Character 1.             */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_SSCH2
value|0x22
end_define

begin_comment
comment|/* Send Special Character 2.             */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_SSCH3
value|0x23
end_define

begin_comment
comment|/* Send Special Character 3.             */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_SSCH4
value|0x24
end_define

begin_comment
comment|/* Send Special Character 4.             */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_TXEN
value|0x18
end_define

begin_comment
comment|/* Enable Transmitter.                   */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_RXEN
value|0x12
end_define

begin_comment
comment|/* Enable Receiver.                      */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_TXDIS
value|0x14
end_define

begin_comment
comment|/* Disable Transmitter.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCR_RXDIS
value|0x11
end_define

begin_comment
comment|/* Disable Receiver.                     */
end_comment

begin_comment
comment|/*  * Interrupt Enable Register, read/write (0x02).  * 	(aka Service Request Enable Register)  */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_DSR
value|0x80
end_define

begin_comment
comment|/* Enable DSR change interrupt.          */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_CD
value|0x40
end_define

begin_comment
comment|/* Enable CD change interrupt.           */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_CTS
value|0x20
end_define

begin_comment
comment|/* Enable CTS change interrupt.          */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_RXD
value|0x10
end_define

begin_comment
comment|/* Enable Receive Data interrupt.        */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_RXSC
value|0x08
end_define

begin_comment
comment|/* Enable Receive Special Character int. */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_TXRDY
value|0x04
end_define

begin_comment
comment|/* Enable Transmit ready interrupt.      */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_TXEMPTY
value|0x02
end_define

begin_comment
comment|/* Enable Transmit empty interrupt.      */
end_comment

begin_define
define|#
directive|define
name|CD1865_IER_NNDT
value|0x01
end_define

begin_comment
comment|/* Enable "No New Data Timeout" int.     */
end_comment

begin_comment
comment|/*  * Channel Option Register 1, read/write (0x03).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_ODDP
value|0x80
end_define

begin_comment
comment|/* Odd Parity.                           */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_PARMODE
value|0x60
end_define

begin_comment
comment|/* Parity enable mask.                   */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_NOPAR
value|0x00
end_define

begin_comment
comment|/* No Parity.                            */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_FORCEPAR
value|0x20
end_define

begin_comment
comment|/* Force Parity.                         */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_NORMPAR
value|0x40
end_define

begin_comment
comment|/* Normal Parity.                        */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_IGNORE
value|0x10
end_define

begin_comment
comment|/* Ignore Parity on RX.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_STOPBITS
value|0x0c
end_define

begin_comment
comment|/* Number of Stop Bits.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_1SB
value|0x00
end_define

begin_comment
comment|/* 1 Stop Bit.                           */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_15SB
value|0x04
end_define

begin_comment
comment|/* 1.5 Stop Bits.                        */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_2SB
value|0x08
end_define

begin_comment
comment|/* 2 Stop Bits.                          */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_CHARLEN
value|0x03
end_define

begin_comment
comment|/* Character Length.                     */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_5BITS
value|0x00
end_define

begin_comment
comment|/* 5 bits.                               */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_6BITS
value|0x01
end_define

begin_comment
comment|/* 6 bits.                               */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_7BITS
value|0x02
end_define

begin_comment
comment|/* 7 bits.                               */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR1_8BITS
value|0x03
end_define

begin_comment
comment|/* 8 bits.                               */
end_comment

begin_comment
comment|/*  * Channel Option Register 2, read/write (0x04).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_IXM
value|0x80
end_define

begin_comment
comment|/* Implied XON mode.                     */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_TXIBE
value|0x40
end_define

begin_comment
comment|/* Enable In-Band (XON/XOFF) Flow Control*/
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_ETC
value|0x20
end_define

begin_comment
comment|/* Embedded Tx Commands Enable.          */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_LLM
value|0x10
end_define

begin_comment
comment|/* Local Loopback Mode.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_RLM
value|0x08
end_define

begin_comment
comment|/* Remote Loopback Mode.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_RTSAO
value|0x04
end_define

begin_comment
comment|/* RTS Automatic Output Enable.          */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_CTSAE
value|0x02
end_define

begin_comment
comment|/* CTS Automatic Enable.                 */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR2_DSRAE
value|0x01
end_define

begin_comment
comment|/* DSR Automatic Enable.                 */
end_comment

begin_comment
comment|/*  * Channel Option Register 3, read/write (0x05).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR3_XONCH
value|0x80
end_define

begin_comment
comment|/* XON is a pair of characters (1& 3).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR3_XOFFCH
value|0x40
end_define

begin_comment
comment|/* XOFF is a pair of characters (2& 4). */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR3_FCT
value|0x20
end_define

begin_comment
comment|/* Flow-Control Transparency Mode.       */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR3_SCDE
value|0x10
end_define

begin_comment
comment|/* Special Character Detection Enable.   */
end_comment

begin_define
define|#
directive|define
name|CD1865_COR3_RXTH
value|0x0f
end_define

begin_comment
comment|/* RX FIFO Threshold value (1-8).        */
end_comment

begin_comment
comment|/*  * Channel Control Status Register, readonly (0x06)  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCSR_RXEN
value|0x80
end_define

begin_comment
comment|/* Receiver Enabled.                     */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCSR_RXFLOFF
value|0x40
end_define

begin_comment
comment|/* Receive Flow Off (XOFF was sent).     */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCSR_RXFLON
value|0x20
end_define

begin_comment
comment|/* Receive Flow On (XON was sent).       */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCSR_TXEN
value|0x08
end_define

begin_comment
comment|/* Transmitter Enabled.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCSR_TXFLOFF
value|0x04
end_define

begin_comment
comment|/* Transmit Flow Off (got XOFF).         */
end_comment

begin_define
define|#
directive|define
name|CD1865_CCSR_TXFLON
value|0x02
end_define

begin_comment
comment|/* Transmit Flow On (got XON).           */
end_comment

begin_comment
comment|/*  * Modem Change Option Register 1, read/write (0x10).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR1_DSRZD
value|0x80
end_define

begin_comment
comment|/* Detect 0->1 transition of DSR.        */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR1_CDZD
value|0x40
end_define

begin_comment
comment|/* Detect 0->1 transition of CD.         */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR1_CTSZD
value|0x20
end_define

begin_comment
comment|/* Detect 0->1 transition of CTS.        */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR1_DTRTH
value|0x0f
end_define

begin_comment
comment|/* Auto DTR flow control Threshold (1-8).*/
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR1_NODTRFC
value|0x0
end_define

begin_comment
comment|/* Automatic DTR flow control disabled.  */
end_comment

begin_comment
comment|/*  * Modem Change Option Register 2, read/write (0x11).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR2_DSROD
value|0x80
end_define

begin_comment
comment|/* Detect 1->0 transition of DSR.        */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR2_CDOD
value|0x40
end_define

begin_comment
comment|/* Detect 1->0 transition of CD.         */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCOR2_CTSOD
value|0x20
end_define

begin_comment
comment|/* Detect 1->0 transition of CTS.        */
end_comment

begin_comment
comment|/*  * Modem Change Register, read/write (0x12).  */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCR_DSRCHG
value|0x80
end_define

begin_comment
comment|/* DSR Changed.                          */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCR_CDCHG
value|0x40
end_define

begin_comment
comment|/* CD Changed.                           */
end_comment

begin_define
define|#
directive|define
name|CD1865_MCR_CTSCHG
value|0x20
end_define

begin_comment
comment|/* CTS Changed.                          */
end_comment

begin_comment
comment|/*  * Modem Signal Value Register, read/write (0x28)  *  * Note:  *	These are inverted with respect to the actual signals!  If the  *	signal is present, the bit is zero, else the bit is one.  */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR_DSR
value|0x80
end_define

begin_comment
comment|/* Current state of DSR input.           */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR_CD
value|0x40
end_define

begin_comment
comment|/* Current state of CD input.            */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR_CTS
value|0x20
end_define

begin_comment
comment|/* Current state of CTS input.           */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR_DTR
value|0x02
end_define

begin_comment
comment|/* Current state of DTR output.          */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR_RTS
value|0x01
end_define

begin_comment
comment|/* Current state of RTS output.          */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR_OFF
value|0xe3
end_define

begin_comment
comment|/* All signals off.                      */
end_comment

begin_define
define|#
directive|define
name|CD1865_MSVR_ON
value|0x00
end_define

begin_comment
comment|/* All signals on.                       */
end_comment

begin_comment
comment|/*  * Escape characters.  These are sent in-band when embedded commands are  * enabled with CD1865_COR2_ETC.  */
end_comment

begin_define
define|#
directive|define
name|CD1865_C_ESC
value|0x00
end_define

begin_comment
comment|/* Escape character.                     */
end_comment

begin_define
define|#
directive|define
name|CD1865_C_SBRK
value|0x81
end_define

begin_comment
comment|/* Start sending BREAK.                  */
end_comment

begin_define
define|#
directive|define
name|CD1865_C_DELAY
value|0x82
end_define

begin_comment
comment|/* Delay output.                         */
end_comment

begin_define
define|#
directive|define
name|CD1865_C_EBRK
value|0x83
end_define

begin_comment
comment|/* Stop sending BREAK.                   */
end_comment

begin_define
define|#
directive|define
name|CD1865_SRSR_RREQint
value|0x10
end_define

begin_comment
comment|/* Receive request interrupt.            */
end_comment

begin_define
define|#
directive|define
name|CD1865_SRSR_TREQint
value|0x04
end_define

begin_comment
comment|/* Transmit request interrupt.           */
end_comment

begin_define
define|#
directive|define
name|CD1865_SRSR_MREQint
value|0x01
end_define

begin_comment
comment|/* Modem signal change request interrupt.*/
end_comment

begin_define
define|#
directive|define
name|CD1865_SRSR_REQint
value|0x15
end_define

begin_comment
comment|/* All of the above.                     */
end_comment

begin_define
define|#
directive|define
name|CD1865_SRCR_PKGTYPE
value|0x80
end_define

begin_define
define|#
directive|define
name|CD1865_SRCR_REGACKEN
value|0x40
end_define

begin_define
define|#
directive|define
name|CD1865_SRCR_DAISYEN
value|0x20
end_define

begin_define
define|#
directive|define
name|CD1865_SRCR_GLOBPRI
value|0x10
end_define

begin_define
define|#
directive|define
name|CD1865_SRCR_UNFAIR
value|0x08
end_define

begin_define
define|#
directive|define
name|CD1865_SRCR_AUTOPRI
value|0x02
end_define

begin_define
define|#
directive|define
name|CD1865_SRCR_PRISEL
value|0x01
end_define

end_unit

