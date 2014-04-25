begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: uftdireg.h,v 1.6 2002/07/11 21:14:28 augustss Exp $ */
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Definitions for the FTDI USB Single Port Serial Converter -  * known as FTDI_SIO (Serial Input/Output application of the chipset)  *  * The device is based on the FTDI FT8U100AX chip. It has a DB25 on one side,  * USB on the other.  *  * Thanx to FTDI (http://www.ftdi.co.uk) for so kindly providing details  * of the protocol required to talk to the device and ongoing assistence  * during development.  *  * Bill Ryder - bryder@sgi.com of Silicon Graphics, Inc. is the original  * author of this file.  */
end_comment

begin_comment
comment|/* Modified by Lennart Augustsson */
end_comment

begin_comment
comment|/* Vendor Request Interface */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_RESET
value|0
end_define

begin_comment
comment|/* Reset the port */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_MODEM_CTRL
value|1
end_define

begin_comment
comment|/* Set the modem control register */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_FLOW_CTRL
value|2
end_define

begin_comment
comment|/* Set flow control register */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_BAUD_RATE
value|3
end_define

begin_comment
comment|/* Set baud rate */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA
value|4
end_define

begin_comment
comment|/* Set the data characteristics of the 					 * port */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_GET_STATUS
value|5
end_define

begin_comment
comment|/* Retrieve current value of status 					 * reg */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_EVENT_CHAR
value|6
end_define

begin_comment
comment|/* Set the event character */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_ERROR_CHAR
value|7
end_define

begin_comment
comment|/* Set the error character */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_LATENCY
value|9
end_define

begin_comment
comment|/* Set the latency timer */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_GET_LATENCY
value|10
end_define

begin_comment
comment|/* Read the latency timer */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_BITMODE
value|11
end_define

begin_comment
comment|/* Set the bit bang I/O mode */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_GET_BITMODE
value|12
end_define

begin_comment
comment|/* Read pin states in bit bang mode */
end_comment

begin_comment
comment|/* Port Identifier Table */
end_comment

begin_define
define|#
directive|define
name|FTDI_PIT_DEFAULT
value|0
end_define

begin_comment
comment|/* SIOA */
end_comment

begin_define
define|#
directive|define
name|FTDI_PIT_SIOA
value|1
end_define

begin_comment
comment|/* SIOA */
end_comment

begin_define
define|#
directive|define
name|FTDI_PIT_SIOB
value|2
end_define

begin_comment
comment|/* SIOB */
end_comment

begin_define
define|#
directive|define
name|FTDI_PIT_PARALLEL
value|3
end_define

begin_comment
comment|/* Parallel */
end_comment

begin_comment
comment|/* Values for driver_info */
end_comment

begin_define
define|#
directive|define
name|UFTDI_JTAG_IFACE
parameter_list|(
name|i
parameter_list|)
value|(1<< i)
end_define

begin_comment
comment|/* Flag interface as jtag */
end_comment

begin_define
define|#
directive|define
name|UFTDI_JTAG_IFACES_MAX
value|8
end_define

begin_comment
comment|/* Allow up to 8 jtag intfs */
end_comment

begin_define
define|#
directive|define
name|UFTDI_JTAG_CHECK_STRING
value|0xff
end_define

begin_comment
comment|/* Check product names table */
end_comment

begin_define
define|#
directive|define
name|UFTDI_JTAG_MASK
value|0xff
end_define

begin_comment
comment|/*  * BmRequestType:  0100 0000B  * bRequest:       FTDI_SIO_RESET  * wValue:         Control Value  *                   0 = Reset SIO  *                   1 = Purge RX buffer  *                   2 = Purge TX buffer  * wIndex:         Port  * wLength:        0  * Data:           None  *  * The Reset SIO command has this effect:  *  *    Sets flow control set to 'none'  *    Event char = 0x0d  *    Event trigger = disabled  *    Purge RX buffer  *    Purge TX buffer  *    Clear DTR  *    Clear RTS  *    baud and data format not reset  *  * The Purge RX and TX buffer commands affect nothing except the buffers  */
end_comment

begin_comment
comment|/* FTDI_SIO_RESET */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_RESET_SIO
value|0
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_RESET_PURGE_RX
value|1
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_RESET_PURGE_TX
value|2
end_define

begin_comment
comment|/*  * BmRequestType:  0100 0000B  * bRequest:       FTDI_SIO_SET_BAUDRATE  * wValue:         BaudRate low bits  * wIndex:         Port and BaudRate high bits   * wLength:        0  * Data:           None  */
end_comment

begin_comment
comment|/* FTDI_SIO_SET_BAUDRATE */
end_comment

begin_comment
comment|/*  * BmRequestType:  0100 0000B  * bRequest:       FTDI_SIO_SET_DATA  * wValue:         Data characteristics (see below)  * wIndex:         Port  * wLength:        0  * Data:           No  *  * Data characteristics  *  *   B0..7   Number of data bits  *   B8..10  Parity  *           0 = None  *           1 = Odd  *           2 = Even  *           3 = Mark  *           4 = Space  *   B11..13 Stop Bits  *           0 = 1  *           1 = 1.5  *           2 = 2  *   B14..15 Reserved  *  */
end_comment

begin_comment
comment|/* FTDI_SIO_SET_DATA */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_BITS
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_PARITY_NONE
value|(0x0<< 8)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_PARITY_ODD
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_PARITY_EVEN
value|(0x2<< 8)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_PARITY_MARK
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_PARITY_SPACE
value|(0x4<< 8)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_STOP_BITS_1
value|(0x0<< 11)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_STOP_BITS_15
value|(0x1<< 11)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DATA_STOP_BITS_2
value|(0x2<< 11)
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_BREAK
value|(0x1<< 14)
end_define

begin_comment
comment|/*  * BmRequestType:   0100 0000B  * bRequest:        FTDI_SIO_MODEM_CTRL  * wValue:          ControlValue (see below)  * wIndex:          Port  * wLength:         0  * Data:            None  *  * NOTE: If the device is in RTS/CTS flow control, the RTS set by this  * command will be IGNORED without an error being returned  * Also - you can not set DTR and RTS with one control message  *  * ControlValue  * B0    DTR state  *          0 = reset  *          1 = set  * B1    RTS state  *          0 = reset  *          1 = set  * B2..7 Reserved  * B8    DTR state enable  *          0 = ignore  *          1 = use DTR state  * B9    RTS state enable  *          0 = ignore  *          1 = use RTS state  * B10..15 Reserved  */
end_comment

begin_comment
comment|/* FTDI_SIO_MODEM_CTRL */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DTR_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DTR_HIGH
value|(1 | ( FTDI_SIO_SET_DTR_MASK<< 8))
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_DTR_LOW
value|(0 | ( FTDI_SIO_SET_DTR_MASK<< 8))
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_RTS_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_RTS_HIGH
value|(2 | ( FTDI_SIO_SET_RTS_MASK<< 8))
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_SET_RTS_LOW
value|(0 | ( FTDI_SIO_SET_RTS_MASK<< 8))
end_define

begin_comment
comment|/*  *   BmRequestType:  0100 0000b  *   bRequest:       FTDI_SIO_SET_FLOW_CTRL  *   wValue:         Xoff/Xon  *   wIndex:         Protocol/Port - hIndex is protocol / lIndex is port  *   wLength:        0  *   Data:           None  *  * hIndex protocol is:  *   B0 Output handshaking using RTS/CTS  *       0 = disabled  *       1 = enabled  *   B1 Output handshaking using DTR/DSR  *       0 = disabled  *       1 = enabled  *   B2 Xon/Xoff handshaking  *       0 = disabled  *       1 = enabled  *  * A value of zero in the hIndex field disables handshaking  *  * If Xon/Xoff handshaking is specified, the hValue field should contain the  * XOFF character and the lValue field contains the XON character.  */
end_comment

begin_comment
comment|/* FTDI_SIO_SET_FLOW_CTRL */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_DISABLE_FLOW_CTRL
value|0x0
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_RTS_CTS_HS
value|0x1
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_DTR_DSR_HS
value|0x2
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_XON_XOFF_HS
value|0x4
end_define

begin_comment
comment|/*  *  BmRequestType:   0100 0000b  *  bRequest:        FTDI_SIO_SET_EVENT_CHAR  *  wValue:          Event Char  *  wIndex:          Port  *  wLength:         0  *  Data:            None  *  * wValue:  *   B0..7   Event Character  *   B8      Event Character Processing  *             0 = disabled  *             1 = enabled  *   B9..15  Reserved  *  * FTDI_SIO_SET_EVENT_CHAR  *  * Set the special event character for the specified communications port.  * If the device sees this character it will immediately return the  * data read so far - rather than wait 40ms or until 62 bytes are read  * which is what normally happens.  */
end_comment

begin_comment
comment|/*  *  BmRequestType:  0100 0000b  *  bRequest:       FTDI_SIO_SET_ERROR_CHAR  *  wValue:         Error Char  *  wIndex:         Port  *  wLength:        0  *  Data:           None  *  *  Error Char  *  B0..7  Error Character  *  B8     Error Character Processing  *           0 = disabled  *           1 = enabled  *  B9..15 Reserved  * FTDI_SIO_SET_ERROR_CHAR  * Set the parity error replacement character for the specified communications  * port.  */
end_comment

begin_comment
comment|/*  *   BmRequestType:   1100 0000b  *   bRequest:        FTDI_SIO_GET_MODEM_STATUS  *   wValue:          zero  *   wIndex:          Port  *   wLength:         1  *   Data:            Status  *  * One byte of data is returned  * B0..3 0  * B4    CTS  *         0 = inactive  *         1 = active  * B5    DSR  *         0 = inactive  *         1 = active  * B6    Ring Indicator (RI)  *         0 = inactive  *         1 = active  * B7    Receive Line Signal Detect (RLSD)  *         0 = inactive  *         1 = active  *  * FTDI_SIO_GET_MODEM_STATUS  * Retrieve the current value of the modem status register.  */
end_comment

begin_define
define|#
directive|define
name|FTDI_SIO_CTS_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_DSR_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_RI_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|FTDI_SIO_RLSD_MASK
value|0x80
end_define

begin_comment
comment|/*  * DATA FORMAT  *  * IN Endpoint  *  * The device reserves the first two bytes of data on this endpoint to contain  * the current values of the modem and line status registers. In the absence of  * data, the device generates a message consisting of these two status bytes  * every 40 ms.  *  * Byte 0: Modem Status  *   NOTE: 4 upper bits have same layout as the MSR register in a 16550  *  * Offset	Description  * B0..3	Port  * B4		Clear to Send (CTS)  * B5		Data Set Ready (DSR)  * B6		Ring Indicator (RI)  * B7		Receive Line Signal Detect (RLSD)  *  * Byte 1: Line Status  *   NOTE: same layout as the LSR register in a 16550  *  * Offset	Description  * B0	Data Ready (DR)  * B1	Overrun Error (OE)  * B2	Parity Error (PE)  * B3	Framing Error (FE)  * B4	Break Interrupt (BI)  * B5	Transmitter Holding Register (THRE)  * B6	Transmitter Empty (TEMT)  * B7	Error in RCVR FIFO  * OUT Endpoint  *  * This device reserves the first bytes of data on this endpoint contain the  * length and port identifier of the message. For the FTDI USB Serial converter  * the port identifier is always 1.  *  * Byte 0: Port& length  *  * Offset	Description  * B0..1	Port  * B2..7	Length of message - (not including Byte 0)  */
end_comment

begin_define
define|#
directive|define
name|FTDI_PORT_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|FTDI_MSR_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|FTDI_GET_MSR
parameter_list|(
name|p
parameter_list|)
value|(((p)[0])& FTDI_MSR_MASK)
end_define

begin_define
define|#
directive|define
name|FTDI_GET_LSR
parameter_list|(
name|p
parameter_list|)
value|((p)[1])
end_define

begin_define
define|#
directive|define
name|FTDI_LSR_MASK
value|(~0x60)
end_define

begin_comment
comment|/* interesting bits */
end_comment

begin_define
define|#
directive|define
name|FTDI_OUT_TAG
parameter_list|(
name|len
parameter_list|,
name|port
parameter_list|)
value|(((len)<< 2) | (port))
end_define

end_unit

