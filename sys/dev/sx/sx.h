begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Device driver for Specialix I/O8+ multiport serial card.  *  * Copyright 2003 Frank Mayhar<frank@exit.com>  *  * Derived from the "si" driver by Peter Wemm<peter@netplex.com.au>, using  * lots of information from the Linux "specialix" driver by Roger Wolff  *<R.E.Wolff@BitWizard.nl> and from the Intel CD1865 "Intelligent Eight-  * Channel Communications Controller" datasheet.  Roger was also nice  * enough to answer numerous questions about stuff specific to the I/O8+  * not covered by the CD1865 datasheet.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notices, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notices, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN  * NO EVENT SHALL THE AUTHORS BE LIABLE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Per-channel soft information structure, stored in the driver.  It's called  * "sx_port" just because the si driver calls it "si_port."  *  * This information is mostly visible via ioctl().  */
end_comment

begin_struct
struct|struct
name|sx_port
block|{
name|int
name|sp_chan
decl_stmt|;
comment|/* Channel number, for convenience.   */
name|struct
name|tty
modifier|*
name|sp_tty
decl_stmt|;
name|int
name|sp_state
decl_stmt|;
name|int
name|sp_delta_overflows
decl_stmt|;
name|struct
name|sx_softc
modifier|*
name|sp_sc
decl_stmt|;
name|int
name|sp_debug
decl_stmt|;
comment|/* debug mask */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Various important values.  */
end_comment

begin_define
define|#
directive|define
name|SX_NUMCHANS
value|8
end_define

begin_comment
comment|/* Eight channels on an I/O8+.                */
end_comment

begin_define
define|#
directive|define
name|SX_PCI_IO_SPACE
value|8
end_define

begin_comment
comment|/* How much address space to use.             */
end_comment

begin_define
define|#
directive|define
name|SX_CCR_TIMEOUT
value|10000
end_define

begin_comment
comment|/* Channel Command Register timeout, 10ms.    */
end_comment

begin_define
define|#
directive|define
name|SX_GSVR_TIMEOUT
value|1000
end_define

begin_comment
comment|/* GSVR reset timeout, 1ms.                   */
end_comment

begin_define
define|#
directive|define
name|SX_CD1865_ID
value|0x10
end_define

begin_comment
comment|/* ID of the I/O8+ CD1865 chip.               */
end_comment

begin_define
define|#
directive|define
name|SX_EI
value|0x80
end_define

begin_comment
comment|/* "Enable interrupt" flag for I/O8+ commands.*/
end_comment

begin_define
define|#
directive|define
name|SX_DATA_REG
value|0
end_define

begin_comment
comment|/* Data register.                             */
end_comment

begin_define
define|#
directive|define
name|SX_ADDR_REG
value|1
end_define

begin_comment
comment|/* Address register.                          */
end_comment

begin_comment
comment|/*  * The I/O8+ has a 25MHz oscillator on board, but the CD1865 runs at half  * that.  */
end_comment

begin_define
define|#
directive|define
name|SX_CD1865_CLOCK
value|12500000
end_define

begin_comment
comment|/* CD1865 clock on I/O8+.             */
end_comment

begin_define
define|#
directive|define
name|SX_CD1865_TICK
value|4000
end_define

begin_comment
comment|/* Timer tick rate, via prescaler.    */
end_comment

begin_define
define|#
directive|define
name|SX_CD1865_PRESCALE
value|(SX_CD1865_CLOCK/SX_CD1865_TICK)
end_define

begin_comment
comment|/* Prescale value.*/
end_comment

begin_comment
comment|/* Buffer parameters */
end_comment

begin_define
define|#
directive|define
name|SX_BUFFERSIZE
value|CD1865_RFIFOSZ
end_define

begin_comment
comment|/* Just the size of the receive FIFO. */
end_comment

begin_define
define|#
directive|define
name|SX_I_HIGH_WATER
value|(TTYHOG - 2 * SX_BUFFERSIZE)
end_define

begin_comment
comment|/*  * Precomputed bitrate clock divisors.  Formula is  *  *                Clock rate (Hz)        12500000  *	divisor = ---------------  or  ------------  *                 16 * bit rate       16 * bitrate  *  * All values are rounded to the nearest integer.  */
end_comment

begin_define
define|#
directive|define
name|CLK75
value|0x28b1
end_define

begin_comment
comment|/* 10416.666667                       */
end_comment

begin_define
define|#
directive|define
name|CLK110
value|0x1bbe
end_define

begin_comment
comment|/*  7102.272727                       */
end_comment

begin_define
define|#
directive|define
name|CLK150
value|0x1458
end_define

begin_comment
comment|/*  5208.333333                       */
end_comment

begin_define
define|#
directive|define
name|CLK300
value|0x0a2c
end_define

begin_comment
comment|/*  2604.166667                       */
end_comment

begin_define
define|#
directive|define
name|CLK600
value|0x0516
end_define

begin_comment
comment|/*  1302.083333                       */
end_comment

begin_define
define|#
directive|define
name|CLK1200
value|0x028b
end_define

begin_comment
comment|/*   651.0416667                      */
end_comment

begin_define
define|#
directive|define
name|CLK2000
value|0x0187
end_define

begin_comment
comment|/*   390.625                          */
end_comment

begin_define
define|#
directive|define
name|CLK2400
value|0x0146
end_define

begin_comment
comment|/*   325.5208333                      */
end_comment

begin_define
define|#
directive|define
name|CLK4800
value|0x00a3
end_define

begin_comment
comment|/*   162.7604167                      */
end_comment

begin_define
define|#
directive|define
name|CLK7200
value|0x006d
end_define

begin_comment
comment|/*   108.5069444                      */
end_comment

begin_define
define|#
directive|define
name|CLK9600
value|0x0051
end_define

begin_comment
comment|/*    81.38020833                     */
end_comment

begin_define
define|#
directive|define
name|CLK19200
value|0x0029
end_define

begin_comment
comment|/*    40.69010417                     */
end_comment

begin_define
define|#
directive|define
name|CLK38400
value|0x0014
end_define

begin_comment
comment|/*    20.34505208                     */
end_comment

begin_define
define|#
directive|define
name|CLK57600
value|0x000e
end_define

begin_comment
comment|/*    13.56336806                     */
end_comment

begin_define
define|#
directive|define
name|CLK115200
value|0x0007
end_define

begin_comment
comment|/*     6.781684028                    */
end_comment

begin_comment
comment|/* sp_state */
end_comment

begin_define
define|#
directive|define
name|SX_SS_CLOSED
value|0x00000
end_define

begin_comment
comment|/* Port is closed.                    */
end_comment

begin_define
define|#
directive|define
name|SX_SS_OPEN
value|0x00001
end_define

begin_comment
comment|/* Port is open and active.           */
end_comment

begin_define
define|#
directive|define
name|SX_SS_XMIT
value|0x00002
end_define

begin_comment
comment|/* We're transmitting data.           */
end_comment

begin_define
define|#
directive|define
name|SX_SS_INTR
value|0x00004
end_define

begin_comment
comment|/* We're processing an interrupt.     */
end_comment

begin_define
define|#
directive|define
name|SX_SS_CLOSING
value|0x00008
end_define

begin_comment
comment|/* in the middle of an sxclose()      */
end_comment

begin_define
define|#
directive|define
name|SX_SS_WAITWRITE
value|0x00010
end_define

begin_define
define|#
directive|define
name|SX_SS_BLOCKWRITE
value|0x00020
end_define

begin_define
define|#
directive|define
name|SX_SS_DTR_OFF
value|0x00040
end_define

begin_comment
comment|/* DTR held off                       */
end_comment

begin_define
define|#
directive|define
name|SX_SS_IFLOW
value|0x00080
end_define

begin_comment
comment|/* Input (RTS) flow control on.       */
end_comment

begin_define
define|#
directive|define
name|SX_SS_OFLOW
value|0x00100
end_define

begin_comment
comment|/* Output (CTS) flow control on.      */
end_comment

begin_define
define|#
directive|define
name|SX_SS_IRCV
value|0x00200
end_define

begin_comment
comment|/* In a receive interrupt.            */
end_comment

begin_define
define|#
directive|define
name|SX_SS_IMODEM
value|0x00400
end_define

begin_comment
comment|/* In a modem-signal interrupt.       */
end_comment

begin_define
define|#
directive|define
name|SX_SS_IRCVEXC
value|0x00800
end_define

begin_comment
comment|/* In a receive-exception interrupt.  */
end_comment

begin_define
define|#
directive|define
name|SX_SS_IXMIT
value|0x01000
end_define

begin_comment
comment|/* In a transmit interrupt.           */
end_comment

begin_define
define|#
directive|define
name|SX_SS_OSTOP
value|0x02000
end_define

begin_comment
comment|/* Stopped by output flow control.    */
end_comment

begin_define
define|#
directive|define
name|SX_SS_ISTOP
value|0x04000
end_define

begin_comment
comment|/* Stopped by input flow control.     */
end_comment

begin_define
define|#
directive|define
name|SX_SS_DTRPIN
value|0x08000
end_define

begin_comment
comment|/* DTR/RTS pin is DTR.                */
end_comment

begin_define
define|#
directive|define
name|SX_SS_DOBRK
value|0x10000
end_define

begin_comment
comment|/* Change break status.               */
end_comment

begin_define
define|#
directive|define
name|SX_SS_BREAK
value|0x20000
end_define

begin_comment
comment|/* Doing break.                       */
end_comment

begin_define
define|#
directive|define
name|SX_DTRPIN
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_DTRPIN)
end_define

begin_comment
comment|/* DTR/RTS pin is DTR.*/
end_comment

begin_define
define|#
directive|define
name|SX_XMITTING
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_XMIT)
end_define

begin_comment
comment|/* We're transmitting.  */
end_comment

begin_define
define|#
directive|define
name|SX_INTR
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_INTR)
end_define

begin_comment
comment|/* In an interrupt.     */
end_comment

begin_define
define|#
directive|define
name|SX_IXMIT
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_IXMIT)
end_define

begin_comment
comment|/* Transmit interrupt. */
end_comment

begin_define
define|#
directive|define
name|SX_IFLOW
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_IFLOW)
end_define

begin_comment
comment|/* Input flow control. */
end_comment

begin_define
define|#
directive|define
name|SX_OFLOW
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_OFLOW)
end_define

begin_comment
comment|/* Output flow control.*/
end_comment

begin_define
define|#
directive|define
name|SX_IRCV
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_IRCV)
end_define

begin_comment
comment|/* Receive interrupt.   */
end_comment

begin_define
define|#
directive|define
name|SX_IMODEM
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_IMODEM)
end_define

begin_comment
comment|/* Modem state change.*/
end_comment

begin_define
define|#
directive|define
name|SX_IRCVEXC
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_IRCVEXC)
end_define

begin_comment
comment|/* Rcv exception.    */
end_comment

begin_define
define|#
directive|define
name|SX_OSTOP
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_OSTOP)
end_define

begin_comment
comment|/* Output stopped.     */
end_comment

begin_define
define|#
directive|define
name|SX_ISTOP
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_ISTOP)
end_define

begin_comment
comment|/* Input stopped.      */
end_comment

begin_define
define|#
directive|define
name|SX_DOBRK
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_DOBRK)
end_define

begin_comment
comment|/* Change break status.*/
end_comment

begin_define
define|#
directive|define
name|SX_BREAK
parameter_list|(
name|pp
parameter_list|)
value|((pp)->sp_state& SX_SS_BREAK)
end_define

begin_comment
comment|/* Doing break.        */
end_comment

begin_define
define|#
directive|define
name|DBG_ENTRY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DBG_DRAIN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DBG_OPEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DBG_CLOSE
value|0x00000008
end_define

begin_comment
comment|/*				0x00000010*/
end_comment

begin_define
define|#
directive|define
name|DBG_WRITE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DBG_PARAM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DBG_INTR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DBG_IOCTL
value|0x00000100
end_define

begin_comment
comment|/*				0x00000200 */
end_comment

begin_comment
comment|/*				0x00000400*/
end_comment

begin_define
define|#
directive|define
name|DBG_OPTIM
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DBG_START
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DBG_EXIT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DBG_FAIL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DBG_STOP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DBG_AUTOBOOT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DBG_MODEM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DBG_MODEM_STATE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DBG_RECEIVE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DBG_POLL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DBG_TRANSMIT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DBG_RECEIVE_EXC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DBG_PRINTF
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DBG_ALL
value|0xffffffff
end_define

end_unit

