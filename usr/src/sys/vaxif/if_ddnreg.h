begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)if_ddnreg.h	7.1 (Berkeley) 6/5/86 */
end_comment

begin_comment
comment|/************************************************************************\       ________________________________________________________     /                                                        \    |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |    |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |    |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |    |       AAAA AAAA      CCCC              CCCC              |    |      AAAA   AAAA     CCCC              CCCC              |    |     AAAA     AAAA    CCCC              CCCC              |    |    AAAA       AAAA   CCCC              CCCC              |    |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |    |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |    | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |     \________________________________________________________/  	Copyright (c) 1985 by Advanced Computer Communications 	720 Santa Barbara Street, Santa Barbara, California  93101 	(805) 963-9431  	This software may be duplicated and used on systems 	which are licensed to run U.C. Berkeley versions of 	the UNIX operating system.  Any duplication of any 	part of this software must include a copy of ACC's 	copyright notice.   File: 		if_ddnreg.h  Author: 		Art Berggreen  Project: 		4.2 DDN X.25 network driver  Function: 		This file contains definitions of the hardware 		interface of the ACP625 (IF-11/X25).  Components:  Revision History: 		16-May-1985:	V1.0 - First release. 				Art Berggreen.  \************************************************************************/
end_comment

begin_escape
end_escape

begin_comment
comment|/*	if_ddnvar.h	 V1.0	5/16/85	*/
end_comment

begin_comment
comment|/*  * ACC IF-11/DDN-X25 interface  */
end_comment

begin_struct
struct|struct
name|ddnregs
block|{
comment|/* device registers */
name|u_short
name|csr
decl_stmt|;
comment|/* control and status register */
name|u_char
name|iochn
decl_stmt|;
comment|/* logical channel */
name|u_char
name|ioadx
decl_stmt|;
comment|/* address extension (A16,A17) */
name|u_short
name|ioadl
decl_stmt|;
comment|/* buffer address (A0-A15) */
name|u_short
name|iocnt
decl_stmt|;
comment|/* byte count */
name|u_char
name|iofcn
decl_stmt|;
comment|/* UMC funciton code */
name|u_char
name|iosbf
decl_stmt|;
comment|/* UMC subfunction code */
name|u_char
name|ioini
decl_stmt|;
comment|/* comm regs valid flag */
name|u_char
name|staack
decl_stmt|;
comment|/* interrupt acknowledge flag */
name|u_char
name|ionmi
decl_stmt|;
comment|/* NMI routine active flag */
name|u_char
name|xfrgnt
decl_stmt|;
comment|/* UMR transfer grant flag */
name|u_char
name|stachn
decl_stmt|;
comment|/* interrupt channel number */
name|u_char
name|statyp
decl_stmt|;
comment|/* interrupt type code */
name|u_char
name|stacc
decl_stmt|;
comment|/* completion function code */
name|u_char
name|stacs
decl_stmt|;
comment|/* completion subfunction code */
name|u_short
name|stacnt
decl_stmt|;
comment|/* completion byte count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|iovect
value|iochn
end_define

begin_comment
comment|/* defines for CSR */
end_comment

begin_define
define|#
directive|define
name|DDN_UER
value|0100000
end_define

begin_comment
comment|/* UMC error condition */
end_comment

begin_define
define|#
directive|define
name|DDN_NXM
value|0040000
end_define

begin_comment
comment|/* non-existent memory error */
end_comment

begin_define
define|#
directive|define
name|DDN_PER
value|0020000
end_define

begin_comment
comment|/* UNIBUS parity error */
end_comment

begin_define
define|#
directive|define
name|DDN_ZRUN
value|0010000
end_define

begin_comment
comment|/* Z80 running */
end_comment

begin_define
define|#
directive|define
name|DDN_ZGO
value|0004000
end_define

begin_comment
comment|/* Z80 not in wait state */
end_comment

begin_define
define|#
directive|define
name|DDN_MBLK
value|0000200
end_define

begin_comment
comment|/* memory swap state (0=main, 1=srv) */
end_comment

begin_define
define|#
directive|define
name|DDN_SRV
value|0000100
end_define

begin_comment
comment|/* select UMC service memory */
end_comment

begin_define
define|#
directive|define
name|DDN_MAIN
value|0000040
end_define

begin_comment
comment|/* select UMC main memory */
end_comment

begin_define
define|#
directive|define
name|DDN_DMA
value|0000020
end_define

begin_comment
comment|/* DMA enable */
end_comment

begin_define
define|#
directive|define
name|DDN_WRT
value|0000010
end_define

begin_comment
comment|/* DMA write enable */
end_comment

begin_define
define|#
directive|define
name|DDN_IEN
value|0000004
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DDN_RST
value|0000002
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|DDN_NMI
value|0000001
end_define

begin_comment
comment|/* cause NMI */
end_comment

begin_define
define|#
directive|define
name|DDN_BITS
define|\
value|"\10\20UER\17NXM\16PER\15ZRUN\14ZGO\10MBLK\7SRV\6MAIN\5DMA\4WRT\3IEN\2RST\1NMI"
end_define

begin_comment
comment|/* start i/o function code definitions */
end_comment

begin_define
define|#
directive|define
name|DDNWRT
value|0
end_define

begin_comment
comment|/* write to if-11 */
end_comment

begin_define
define|#
directive|define
name|DDNRDB
value|1
end_define

begin_comment
comment|/* read from if-11 */
end_comment

begin_define
define|#
directive|define
name|DDNSTR
value|2
end_define

begin_comment
comment|/* stream flag */
end_comment

begin_define
define|#
directive|define
name|DDNEOS
value|(4|DDNSTR)
end_define

begin_comment
comment|/* end of stream flag */
end_comment

begin_define
define|#
directive|define
name|DDNABT
value|8
end_define

begin_comment
comment|/* abort flag */
end_comment

begin_define
define|#
directive|define
name|DDNUMR
value|16
end_define

begin_comment
comment|/* UMR protocol flag */
end_comment

begin_comment
comment|/* interrupt type definitions */
end_comment

begin_define
define|#
directive|define
name|DDNSACK
value|0
end_define

begin_comment
comment|/* start i/o ack */
end_comment

begin_define
define|#
directive|define
name|DDNDONE
value|1
end_define

begin_comment
comment|/* i/o completion */
end_comment

begin_define
define|#
directive|define
name|DDNXREQ
value|2
end_define

begin_comment
comment|/* UMR protocol transfer request */
end_comment

begin_comment
comment|/* i/o completion codes */
end_comment

begin_define
define|#
directive|define
name|DDNIOCOK
value|0001
end_define

begin_comment
comment|/* successful completion */
end_comment

begin_define
define|#
directive|define
name|DDNIOCOKP
value|0002
end_define

begin_comment
comment|/* successful completion, more data pending */
end_comment

begin_define
define|#
directive|define
name|DDNIOCABT
value|0361
end_define

begin_comment
comment|/* i/o aborted */
end_comment

begin_define
define|#
directive|define
name|DDNIOCERR
value|0321
end_define

begin_comment
comment|/* program error */
end_comment

begin_define
define|#
directive|define
name|DDNIOCOVR
value|0363
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|DDNIOCUBE
value|0374
end_define

begin_comment
comment|/* non-existant memory or unibus error */
end_comment

begin_comment
comment|/* UMR protocol transfer grant code definitions */
end_comment

begin_define
define|#
directive|define
name|DDNXEVN
value|1
end_define

begin_comment
comment|/* start with even address */
end_comment

begin_define
define|#
directive|define
name|DDNXODD
value|2
end_define

begin_comment
comment|/* start with odd address */
end_comment

begin_define
define|#
directive|define
name|DDNNUMR
value|4
end_define

begin_comment
comment|/* non-UMR transfer */
end_comment

begin_define
define|#
directive|define
name|DDNXABT
value|8
end_define

begin_comment
comment|/* abort transfer */
end_comment

end_unit

