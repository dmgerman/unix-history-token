begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1994, Matthew E. Kimmel.  Permission is hereby granted  * to use, copy, modify and distribute this software provided that both  * the copyright notice and this permission notice appear in all copies  * of the software, derivative works or modified versions, and any  * portions thereof.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* 3COM Etherlink 3C501 Register Definitions */
end_comment

begin_comment
comment|/* I/O Ports */
end_comment

begin_define
define|#
directive|define
name|EL_RXS
value|0x6
end_define

begin_comment
comment|/* Receive status register */
end_comment

begin_define
define|#
directive|define
name|EL_RXC
value|0x6
end_define

begin_comment
comment|/* Receive command register */
end_comment

begin_define
define|#
directive|define
name|EL_TXS
value|0x7
end_define

begin_comment
comment|/* Transmit status register */
end_comment

begin_define
define|#
directive|define
name|EL_TXC
value|0x7
end_define

begin_comment
comment|/* Transmit command register */
end_comment

begin_define
define|#
directive|define
name|EL_GPBL
value|0x8
end_define

begin_comment
comment|/* GP buffer ptr low byte */
end_comment

begin_define
define|#
directive|define
name|EL_GPBH
value|0x9
end_define

begin_comment
comment|/* GP buffer ptr high byte */
end_comment

begin_define
define|#
directive|define
name|EL_RBL
value|0xa
end_define

begin_comment
comment|/* Receive buffer ptr low byte */
end_comment

begin_define
define|#
directive|define
name|EL_RBC
value|0xa
end_define

begin_comment
comment|/* Receive buffer clear */
end_comment

begin_define
define|#
directive|define
name|EL_RBH
value|0xb
end_define

begin_comment
comment|/* Receive buffer ptr high byte */
end_comment

begin_define
define|#
directive|define
name|EL_EAW
value|0xc
end_define

begin_comment
comment|/* Ethernet address window */
end_comment

begin_define
define|#
directive|define
name|EL_AS
value|0xe
end_define

begin_comment
comment|/* Auxiliary status register */
end_comment

begin_define
define|#
directive|define
name|EL_AC
value|0xe
end_define

begin_comment
comment|/* Auxiliary command register */
end_comment

begin_define
define|#
directive|define
name|EL_BUF
value|0xf
end_define

begin_comment
comment|/* Data buffer */
end_comment

begin_comment
comment|/* Receive status register bits */
end_comment

begin_define
define|#
directive|define
name|EL_RXS_OFLOW
value|0x01
end_define

begin_comment
comment|/* Overflow error */
end_comment

begin_define
define|#
directive|define
name|EL_RXS_FCS
value|0x02
end_define

begin_comment
comment|/* FCS error */
end_comment

begin_define
define|#
directive|define
name|EL_RXS_DRIB
value|0x04
end_define

begin_comment
comment|/* Dribble error */
end_comment

begin_define
define|#
directive|define
name|EL_RXS_SHORT
value|0x08
end_define

begin_comment
comment|/* Short frame */
end_comment

begin_define
define|#
directive|define
name|EL_RXS_NOFLOW
value|0x10
end_define

begin_comment
comment|/* No overflow */
end_comment

begin_define
define|#
directive|define
name|EL_RXS_GOOD
value|0x20
end_define

begin_comment
comment|/* Received good frame */
end_comment

begin_define
define|#
directive|define
name|EL_RXS_STALE
value|0x80
end_define

begin_comment
comment|/* Stale receive status */
end_comment

begin_comment
comment|/* Receive command register bits */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_DISABLE
value|0x00
end_define

begin_comment
comment|/* Receiver disabled */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_DOFLOW
value|0x01
end_define

begin_comment
comment|/* Detect overflow */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_DFCS
value|0x02
end_define

begin_comment
comment|/* Detect FCS errs */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_DDRIB
value|0x04
end_define

begin_comment
comment|/* Detect dribble errors */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_DSHORT
value|0x08
end_define

begin_comment
comment|/* Detect short frames */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_DNOFLOW
value|0x10
end_define

begin_comment
comment|/* Detect frames w/o overflow ??? */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_AGF
value|0x20
end_define

begin_comment
comment|/* Accept Good Frames */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_PROMISC
value|0x40
end_define

begin_comment
comment|/* Promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_ABROAD
value|0x80
end_define

begin_comment
comment|/* Accept address, broadcast */
end_comment

begin_define
define|#
directive|define
name|EL_RXC_AMULTI
value|0xc0
end_define

begin_comment
comment|/* Accept address, multicast */
end_comment

begin_comment
comment|/* Transmit status register bits */
end_comment

begin_define
define|#
directive|define
name|EL_TXS_UFLOW
value|0x01
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|EL_TXS_COLL
value|0x02
end_define

begin_comment
comment|/* Collision */
end_comment

begin_define
define|#
directive|define
name|EL_TXS_COLL16
value|0x04
end_define

begin_comment
comment|/* Collision 16 */
end_comment

begin_define
define|#
directive|define
name|EL_TXS_READY
value|0x08
end_define

begin_comment
comment|/* Ready for new frame */
end_comment

begin_comment
comment|/* Transmit command register bits */
end_comment

begin_define
define|#
directive|define
name|EL_TXC_DUFLOW
value|0x01
end_define

begin_comment
comment|/* Detect underflow */
end_comment

begin_define
define|#
directive|define
name|EL_TXC_DCOLL
value|0x02
end_define

begin_comment
comment|/* Detect collisions */
end_comment

begin_define
define|#
directive|define
name|EL_TXC_DCOLL16
value|0x04
end_define

begin_comment
comment|/* Detect collision 16 */
end_comment

begin_define
define|#
directive|define
name|EL_TXC_DSUCCESS
value|0x08
end_define

begin_comment
comment|/* Detect success */
end_comment

begin_comment
comment|/* Auxiliary status register bits */
end_comment

begin_define
define|#
directive|define
name|EL_AS_RXBUSY
value|0x01
end_define

begin_comment
comment|/* Receive busy */
end_comment

begin_define
define|#
directive|define
name|EL_AS_DMADONE
value|0x10
end_define

begin_comment
comment|/* DMA finished */
end_comment

begin_define
define|#
directive|define
name|EL_AS_TXBUSY
value|0x80
end_define

begin_comment
comment|/* Transmit busy */
end_comment

begin_comment
comment|/* Auxiliary command register bits */
end_comment

begin_define
define|#
directive|define
name|EL_AC_HOST
value|0x00
end_define

begin_comment
comment|/* System bus can access buffer */
end_comment

begin_define
define|#
directive|define
name|EL_AC_IRQE
value|0x01
end_define

begin_comment
comment|/* IRQ enable */
end_comment

begin_define
define|#
directive|define
name|EL_AC_TXBAD
value|0x02
end_define

begin_comment
comment|/* Transmit frames with bad FCS */
end_comment

begin_define
define|#
directive|define
name|EL_AC_TXFRX
value|0x04
end_define

begin_comment
comment|/* Transmit followed by receive */
end_comment

begin_define
define|#
directive|define
name|EL_AC_RX
value|0x08
end_define

begin_comment
comment|/* Receive */
end_comment

begin_define
define|#
directive|define
name|EL_AC_LB
value|0x0c
end_define

begin_comment
comment|/* Loopback */
end_comment

begin_define
define|#
directive|define
name|EL_AC_DRQ
value|0x20
end_define

begin_comment
comment|/* DMA request */
end_comment

begin_define
define|#
directive|define
name|EL_AC_RIDE
value|0x40
end_define

begin_comment
comment|/* DRQ and IRQ enabled */
end_comment

begin_define
define|#
directive|define
name|EL_AC_RESET
value|0x80
end_define

begin_comment
comment|/* Reset */
end_comment

begin_comment
comment|/* Packet buffer size */
end_comment

begin_define
define|#
directive|define
name|EL_BUFSIZ
value|2048
end_define

end_unit

