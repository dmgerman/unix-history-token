begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)if_hdhreg.h	7.1 (Berkeley) 6/5/86 */
end_comment

begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * ACC IF-11/HDH interface  */
end_comment

begin_struct
struct|struct
name|hdhregs
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
name|ioxfrg
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

begin_comment
comment|/* defines for CSR */
end_comment

begin_define
define|#
directive|define
name|HDH_UER
value|0100000
end_define

begin_comment
comment|/* UMC error condition */
end_comment

begin_define
define|#
directive|define
name|HDH_NXM
value|0040000
end_define

begin_comment
comment|/* non-existent memory error */
end_comment

begin_define
define|#
directive|define
name|HDH_PER
value|0020000
end_define

begin_comment
comment|/* UNIBUS parity error */
end_comment

begin_define
define|#
directive|define
name|HDH_ZRUN
value|0010000
end_define

begin_comment
comment|/* Z80 running */
end_comment

begin_define
define|#
directive|define
name|HDH_ZGO
value|0004000
end_define

begin_comment
comment|/* Z80 not in wait state */
end_comment

begin_define
define|#
directive|define
name|HDH_MBLK
value|0000200
end_define

begin_comment
comment|/* memory swap state (0=main, 1=srv) */
end_comment

begin_define
define|#
directive|define
name|HDH_SRV
value|0000100
end_define

begin_comment
comment|/* select UMC service memory */
end_comment

begin_define
define|#
directive|define
name|HDH_MAIN
value|0000040
end_define

begin_comment
comment|/* select UMC main memory */
end_comment

begin_define
define|#
directive|define
name|HDH_DMA
value|0000020
end_define

begin_comment
comment|/* DMA enable */
end_comment

begin_define
define|#
directive|define
name|HDH_WRT
value|0000010
end_define

begin_comment
comment|/* DMA write enable */
end_comment

begin_define
define|#
directive|define
name|HDH_IEN
value|0000004
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|HDH_RST
value|0000002
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|HDH_NMI
value|0000001
end_define

begin_comment
comment|/* cause NMI */
end_comment

begin_define
define|#
directive|define
name|HDH_BITS
define|\
value|"\10\20UER\17NXM\16PER\15ZRUN\14ZGO\10MBLK\7SRV\6MAIN\5DMA\4WRT\3IEN\2RST\1NMI"
end_define

begin_comment
comment|/* start i/o function code definitions */
end_comment

begin_define
define|#
directive|define
name|HDHWRT
value|0
end_define

begin_comment
comment|/* write to if-11 */
end_comment

begin_define
define|#
directive|define
name|HDHRDB
value|1
end_define

begin_comment
comment|/* read from if-11 */
end_comment

begin_define
define|#
directive|define
name|HDHSTR
value|2
end_define

begin_comment
comment|/* stream flag */
end_comment

begin_define
define|#
directive|define
name|HDHEOS
value|6
end_define

begin_comment
comment|/* end of stream flag */
end_comment

begin_define
define|#
directive|define
name|HDHABT
value|8
end_define

begin_comment
comment|/* abort flag */
end_comment

begin_define
define|#
directive|define
name|HDHUMR
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
name|HDHSACK
value|0
end_define

begin_comment
comment|/* start i/o ack */
end_comment

begin_define
define|#
directive|define
name|HDHDONE
value|1
end_define

begin_comment
comment|/* i/o completion */
end_comment

begin_define
define|#
directive|define
name|HDHXREQ
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
name|HDHIOCOK
value|0001
end_define

begin_comment
comment|/* successful completion */
end_comment

begin_define
define|#
directive|define
name|HDHIOCOKP
value|0002
end_define

begin_comment
comment|/* successful completion, more data pending */
end_comment

begin_define
define|#
directive|define
name|HDHIOCABT
value|0361
end_define

begin_comment
comment|/* i/o aborted */
end_comment

begin_define
define|#
directive|define
name|HDHIOCERR
value|0321
end_define

begin_comment
comment|/* program error */
end_comment

begin_define
define|#
directive|define
name|HDHIOCOVR
value|0363
end_define

begin_comment
comment|/* overrun error */
end_comment

begin_define
define|#
directive|define
name|HDHIOCUBE
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
name|HDHXEVN
value|1
end_define

begin_comment
comment|/* start with even address */
end_comment

begin_define
define|#
directive|define
name|HDHXODD
value|2
end_define

begin_comment
comment|/* start with odd address */
end_comment

begin_define
define|#
directive|define
name|HDHNUMR
value|4
end_define

begin_comment
comment|/* non-UMR transfer */
end_comment

begin_define
define|#
directive|define
name|HDHXABT
value|8
end_define

begin_comment
comment|/* abort transfer */
end_comment

begin_comment
comment|/* HDH supervisor request code definitions */
end_comment

begin_define
define|#
directive|define
name|HDHINIT
value|0x42
end_define

begin_comment
comment|/* SYSINIT opcode */
end_comment

begin_define
define|#
directive|define
name|HDHSUP
value|0xf0
end_define

begin_comment
comment|/* supervisor HDH status/line control prefix */
end_comment

begin_define
define|#
directive|define
name|HDHIMP
value|0x400
end_define

begin_comment
comment|/* IMP line up modifier */
end_comment

begin_define
define|#
directive|define
name|HDHREFL
value|0x800
end_define

begin_comment
comment|/* reflect mode modifier */
end_comment

begin_define
define|#
directive|define
name|HDHINLB
value|0x1000
end_define

begin_comment
comment|/* internal loopback modifier */
end_comment

begin_define
define|#
directive|define
name|HDHEXLP
value|0x2000
end_define

begin_comment
comment|/* external loopback modifier */
end_comment

begin_define
define|#
directive|define
name|HDHRQST
value|(HDHSUP+0x0000)
end_define

begin_comment
comment|/* line status request */
end_comment

begin_define
define|#
directive|define
name|HDHRQUP
value|(HDHSUP+0x0100)
end_define

begin_comment
comment|/* line up request */
end_comment

begin_define
define|#
directive|define
name|HDHRQDN
value|(HDHSUP+0x0200)
end_define

begin_comment
comment|/* line down request */
end_comment

begin_comment
comment|/* HDH supervisor reply code definitions */
end_comment

begin_define
define|#
directive|define
name|HDHIACK
value|(HDHSUP+0x4200)
end_define

begin_comment
comment|/* line init ack */
end_comment

begin_define
define|#
directive|define
name|HDHLNUP
value|(HDHSUP+0x0100)
end_define

begin_comment
comment|/* line up reply */
end_comment

begin_define
define|#
directive|define
name|HDHLNDN
value|(HDHSUP+0x0200)
end_define

begin_comment
comment|/* line down reply */
end_comment

begin_define
define|#
directive|define
name|HDHLNACK
value|(HDHSUP+0x0300)
end_define

begin_comment
comment|/* ack line up request (but line is down now) */
end_comment

begin_define
define|#
directive|define
name|HDHTIMO
value|(HDHSUP+0x0400)
end_define

begin_comment
comment|/* line timeout */
end_comment

begin_define
define|#
directive|define
name|HDHLOOP
value|(HDHSUP+0x0500)
end_define

begin_comment
comment|/* loopback message */
end_comment

begin_define
define|#
directive|define
name|HDHDTERR
value|(HDHSUP+0x0600)
end_define

begin_comment
comment|/* host data error detected */
end_comment

begin_define
define|#
directive|define
name|HDHSQRCV
value|(HDHSUP+0x0700)
end_define

begin_comment
comment|/* HDLC sequence error detected by IMP */
end_comment

begin_define
define|#
directive|define
name|HDHSQERR
value|(HDHSUP+0x0800)
end_define

begin_comment
comment|/* HDLC sequence error detected by if-11 */
end_comment

end_unit

