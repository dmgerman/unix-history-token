begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)sioreg.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * sioreg.h -- NEC uPD7201A Hardware Discription  * by A.Fujita, NOV-26-1991  */
end_comment

begin_struct
struct|struct
name|siodevice
block|{
specifier|volatile
name|u_char
name|sio_data
decl_stmt|;
name|u_char
name|sio_pad1
decl_stmt|;
specifier|volatile
name|u_char
name|sio_cmd
decl_stmt|;
name|u_char
name|sio_pad2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sio_stat
value|sio_cmd
end_define

begin_define
define|#
directive|define
name|splsio
value|spl6
end_define

begin_define
define|#
directive|define
name|REG
parameter_list|(
name|u
parameter_list|,
name|r
parameter_list|)
value|( (u<< 4) | r )
end_define

begin_define
define|#
directive|define
name|CHANNEL
parameter_list|(
name|r
parameter_list|)
value|( r>> 4 )
end_define

begin_define
define|#
directive|define
name|REGNO
parameter_list|(
name|r
parameter_list|)
value|( r& 0x07 )
end_define

begin_define
define|#
directive|define
name|isStatusReg
parameter_list|(
name|r
parameter_list|)
value|( r& 0x08 )
end_define

begin_define
define|#
directive|define
name|WR0
value|0x00
end_define

begin_define
define|#
directive|define
name|WR1
value|0x01
end_define

begin_define
define|#
directive|define
name|WR2
value|0x02
end_define

begin_define
define|#
directive|define
name|WR3
value|0x03
end_define

begin_define
define|#
directive|define
name|WR4
value|0x04
end_define

begin_define
define|#
directive|define
name|WR5
value|0x05
end_define

begin_define
define|#
directive|define
name|WR6
value|0x06
end_define

begin_define
define|#
directive|define
name|WR7
value|0x07
end_define

begin_define
define|#
directive|define
name|RR0
value|0x08
end_define

begin_define
define|#
directive|define
name|RR1
value|0x09
end_define

begin_define
define|#
directive|define
name|RR2
value|0x0A
end_define

begin_define
define|#
directive|define
name|RR3
value|0x0B
end_define

begin_define
define|#
directive|define
name|RR4
value|0x0C
end_define

begin_define
define|#
directive|define
name|RR2A
value|0x0A
end_define

begin_define
define|#
directive|define
name|RR2B
value|0x1A
end_define

begin_define
define|#
directive|define
name|WR0_NOP
value|0x00
end_define

begin_comment
comment|/* No Operation */
end_comment

begin_define
define|#
directive|define
name|WR0_SNDABRT
value|0x08
end_define

begin_comment
comment|/* Send Abort (HDLC) */
end_comment

begin_define
define|#
directive|define
name|WR0_RSTINT
value|0x10
end_define

begin_comment
comment|/* Reset External/Status Interrupt */
end_comment

begin_define
define|#
directive|define
name|WR0_CHANRST
value|0x18
end_define

begin_comment
comment|/* Channel Reset */
end_comment

begin_define
define|#
directive|define
name|WR0_INTNXT
value|0x20
end_define

begin_comment
comment|/* Enable Interrupt on Next Receive Character */
end_comment

begin_define
define|#
directive|define
name|WR0_RSTPEND
value|0x28
end_define

begin_comment
comment|/* Reset Transmitter Interrput/DMA Pending */
end_comment

begin_define
define|#
directive|define
name|WR0_ERRRST
value|0x30
end_define

begin_comment
comment|/* Error Reset */
end_comment

begin_define
define|#
directive|define
name|WR0_ENDINTR
value|0x38
end_define

begin_comment
comment|/* End of Interrupt */
end_comment

begin_define
define|#
directive|define
name|WR1_ESENBL
value|0x01
end_define

begin_comment
comment|/* External/Status Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|WR1_TXENBL
value|0x02
end_define

begin_comment
comment|/* Tx Interrupt/DMA Enable */
end_comment

begin_define
define|#
directive|define
name|WR1_STATVEC
value|0x04
end_define

begin_comment
comment|/* Status Affects Vector (Only Chan-B) */
end_comment

begin_define
define|#
directive|define
name|WR1_RXDSEBL
value|0x00
end_define

begin_comment
comment|/* Rx Interrupt/DMA Disable */
end_comment

begin_define
define|#
directive|define
name|WR1_RXFIRST
value|0x08
end_define

begin_comment
comment|/* Interrupt only First Character Received */
end_comment

begin_define
define|#
directive|define
name|WR1_RXALLS
value|0x10
end_define

begin_comment
comment|/* Interrupt Every Characters Received (with Special Char.) */
end_comment

begin_define
define|#
directive|define
name|WR1_RXALL
value|0x18
end_define

begin_comment
comment|/* Interrupt Every Characters Received (without Special Char.) */
end_comment

begin_define
define|#
directive|define
name|WR2_INTR_0
value|0x00
end_define

begin_comment
comment|/* Interrupt Priority: RxA TxA RxB TxB E/SA E/SA */
end_comment

begin_define
define|#
directive|define
name|WR2_INTR_1
value|0x04
end_define

begin_comment
comment|/* Interrupt Priority: RxA RxB TxA TxB E/SA E/SA */
end_comment

begin_define
define|#
directive|define
name|WR2_VEC85_1
value|0x00
end_define

begin_comment
comment|/* 8085 Vectored Mode - 1 */
end_comment

begin_define
define|#
directive|define
name|WR2_VEC85_2
value|0x08
end_define

begin_comment
comment|/* 8085 Vectored Mode - 2 */
end_comment

begin_define
define|#
directive|define
name|WR2_VEC86
value|0x10
end_define

begin_comment
comment|/* 8086 Vectored */
end_comment

begin_define
define|#
directive|define
name|WR2_VEC85_3
value|0x18
end_define

begin_comment
comment|/* 8085 Vectored Mode - 3 */
end_comment

begin_define
define|#
directive|define
name|WR3_RXENBL
value|0x01
end_define

begin_comment
comment|/* Rx Enable */
end_comment

begin_define
define|#
directive|define
name|WR3_RXCRC
value|0x08
end_define

begin_comment
comment|/* Rx CRC Check */
end_comment

begin_define
define|#
directive|define
name|WR3_AUTOEBL
value|0x20
end_define

begin_comment
comment|/* Auto Enable (flow control for MODEM) */
end_comment

begin_define
define|#
directive|define
name|WR3_RX5BIT
value|0x00
end_define

begin_comment
comment|/* Rx Bits/Character: 5 Bits */
end_comment

begin_define
define|#
directive|define
name|WR3_RX7BIT
value|0x40
end_define

begin_comment
comment|/* Rx Bits/Character: 7 Bits */
end_comment

begin_define
define|#
directive|define
name|WR3_RX6BIT
value|0x80
end_define

begin_comment
comment|/* Rx Bits/Character: 6 Bits */
end_comment

begin_define
define|#
directive|define
name|WR3_RX8BIT
value|0xc0
end_define

begin_comment
comment|/* Rx Bits/Character: 8 Bits */
end_comment

begin_define
define|#
directive|define
name|WR4_NPARITY
value|0x00
end_define

begin_comment
comment|/* No Parity */
end_comment

begin_define
define|#
directive|define
name|WR4_PARENAB
value|0x01
end_define

begin_comment
comment|/* Parity Enable */
end_comment

begin_define
define|#
directive|define
name|WR4_OPARITY
value|0x01
end_define

begin_comment
comment|/* Parity Odd */
end_comment

begin_define
define|#
directive|define
name|WR4_EPARITY
value|0x02
end_define

begin_comment
comment|/* Parity Even */
end_comment

begin_define
define|#
directive|define
name|WR4_STOP1
value|0x04
end_define

begin_comment
comment|/* Stop  Bits (1bit) */
end_comment

begin_define
define|#
directive|define
name|WR4_STOP15
value|0x08
end_define

begin_comment
comment|/* Stop  Bits (1.5bit) */
end_comment

begin_define
define|#
directive|define
name|WR4_STOP2
value|0x0c
end_define

begin_comment
comment|/* Stop  Bits (2bit) */
end_comment

begin_define
define|#
directive|define
name|WR4_BAUD96
value|0x40
end_define

begin_comment
comment|/* Clock Rate (9600 BAUD) */
end_comment

begin_define
define|#
directive|define
name|WR4_BAUD48
value|0x80
end_define

begin_comment
comment|/* Clock Rate (4800 BAUD) */
end_comment

begin_define
define|#
directive|define
name|WR4_BAUD24
value|0xc0
end_define

begin_comment
comment|/* Clock Rate (2400 BAUD) */
end_comment

begin_define
define|#
directive|define
name|WR5_TXCRC
value|0x01
end_define

begin_comment
comment|/* Tx CRC Check */
end_comment

begin_define
define|#
directive|define
name|WR5_RTS
value|0x02
end_define

begin_comment
comment|/* Request To Send     [RTS] */
end_comment

begin_define
define|#
directive|define
name|WR5_TXENBL
value|0x08
end_define

begin_comment
comment|/* Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|WR5_BREAK
value|0x10
end_define

begin_comment
comment|/* Send Break          [BRK] */
end_comment

begin_define
define|#
directive|define
name|WR5_TX5BIT
value|0x00
end_define

begin_comment
comment|/* Tx Bits/Character: 5 Bits */
end_comment

begin_define
define|#
directive|define
name|WR5_TX7BIT
value|0x20
end_define

begin_comment
comment|/* Tx Bits/Character: 7 Bits */
end_comment

begin_define
define|#
directive|define
name|WR5_TX6BIT
value|0x40
end_define

begin_comment
comment|/* Tx Bits/Character: 6 Bits */
end_comment

begin_define
define|#
directive|define
name|WR5_TX8BIT
value|0x60
end_define

begin_comment
comment|/* Tx Bits/Character: 8 Bits */
end_comment

begin_define
define|#
directive|define
name|WR5_DTR
value|0x80
end_define

begin_comment
comment|/* Data Terminal Ready [DTR] */
end_comment

begin_define
define|#
directive|define
name|RR0_RXAVAIL
value|0x01
end_define

begin_comment
comment|/* Rx Character Available */
end_comment

begin_define
define|#
directive|define
name|RR0_INTRPEND
value|0x02
end_define

begin_comment
comment|/* Interrupt Pending (Channel-A Only) */
end_comment

begin_define
define|#
directive|define
name|RR0_TXEMPTY
value|0x04
end_define

begin_comment
comment|/* Tx Buffer Empty */
end_comment

begin_define
define|#
directive|define
name|RR0_DCD
value|0x08
end_define

begin_comment
comment|/* Data Carrier Detect [DCD] */
end_comment

begin_define
define|#
directive|define
name|RR0_SYNC
value|0x10
end_define

begin_comment
comment|/* Synchronization */
end_comment

begin_define
define|#
directive|define
name|RR0_CTS
value|0x20
end_define

begin_comment
comment|/* Clear To Send       [CTS] */
end_comment

begin_define
define|#
directive|define
name|RR0_BREAK
value|0x80
end_define

begin_comment
comment|/* Break Detected      [BRK] */
end_comment

begin_define
define|#
directive|define
name|RR1_PARITY
value|0x10
end_define

begin_comment
comment|/* Parity Error */
end_comment

begin_define
define|#
directive|define
name|RR1_OVERRUN
value|0x20
end_define

begin_comment
comment|/* Data Over Run */
end_comment

begin_define
define|#
directive|define
name|RR1_FRAMING
value|0x40
end_define

begin_comment
comment|/* Framing Error */
end_comment

begin_define
define|#
directive|define
name|RR_RXRDY
value|0x0100
end_define

begin_comment
comment|/* Rx Character Available */
end_comment

begin_define
define|#
directive|define
name|RR_INTRPEND
value|0x0200
end_define

begin_comment
comment|/* Interrupt Pending (Channel-A Only) */
end_comment

begin_define
define|#
directive|define
name|RR_TXRDY
value|0x0400
end_define

begin_comment
comment|/* Tx Buffer Empty */
end_comment

begin_define
define|#
directive|define
name|RR_DCD
value|0x0800
end_define

begin_comment
comment|/* Data Carrier Detect [DCD] */
end_comment

begin_define
define|#
directive|define
name|RR_SYNC
value|0x1000
end_define

begin_comment
comment|/* Synchronization */
end_comment

begin_define
define|#
directive|define
name|RR_CTS
value|0x2000
end_define

begin_comment
comment|/* Clear To Send       [CTS] */
end_comment

begin_define
define|#
directive|define
name|RR_BREAK
value|0x8000
end_define

begin_comment
comment|/* Break Detected */
end_comment

begin_define
define|#
directive|define
name|RR_PARITY
value|0x0010
end_define

begin_comment
comment|/* Parity Error */
end_comment

begin_define
define|#
directive|define
name|RR_OVERRUN
value|0x0020
end_define

begin_comment
comment|/* Data Over Run */
end_comment

begin_define
define|#
directive|define
name|RR_FRAMING
value|0x0040
end_define

begin_comment
comment|/* Framing Error */
end_comment

begin_define
define|#
directive|define
name|SIO_HARDADDR
value|0x51000000
end_define

begin_comment
comment|/* build-in serial-interface address */
end_comment

begin_define
define|#
directive|define
name|NPORT
value|2
end_define

begin_define
define|#
directive|define
name|SIO_PORT
value|0
end_define

begin_define
define|#
directive|define
name|BMC_PORT
value|1
end_define

end_unit

