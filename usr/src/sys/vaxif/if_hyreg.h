begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)if_hyreg.h	7.1 (Berkeley) 6/5/86  *  * $Header: if_hyreg.h,v 10.0 84/06/30 19:51:34 steveg Stable $  * $Locker:  $  *  * Modifications from Berkeley 4.2 BSD  * Copyright (c) 1983, Tektronix Inc.  * All Rights Reserved  *  */
end_comment

begin_comment
comment|/*  * Network Systems Corporation Hyperchannel interface  *  * supports A410 adapter interfaced via a DEC DR-11B, NSC PI-13 or PI-14  *	(PI-14 is a PI-13 with different line drivers, software is  *	identical to a PI-13)  *  * Written by Steve Glaser, Tektronix Inc., July 1982  *  * NOTE:  *  * DR11B code has not been fully checked out with 4.1a.  * The first adapters at Tek came with DR11Bs, and the code once worked,  * but those have been upgraded to PI-13s.  */
end_comment

begin_comment
comment|/*  * The HYPERchannel driver sends and receives messages formatted:  *  *	+---------------------------------------+	---  *	|					|	/|\  *	|  HYPERchannel adapter header (hy_hdr)	|	 |  *	|					|	 |  *	+---------------------------------------+	 |  *	|					|	 |  *	|     Internet Protocol header (ip)	|    message proper  *	|					|    (64 bytes max)  *	+---------------------------------------+	 |  *	|					|	 |  *	|	TCP header + user data		|	 |  *	|	(if it all fits here)		|	 |  *	|					|	\|/  *	+---------------------------------------+	---  *  *	+---------------------------------------+	---  *	|					|	/|\  *	|					|	 |  *	|	TCP header + user data		|  associated data  *	|					|	 |  *	|					|	\|/  *	+---------------------------------------+	---  *  * If all of the datagram will fit in the message proper (including  * the TCP header and user data) the entire datagram is passed in  * the message proper and the associated data feature of the HYPERchannel  * is not used.  *  * The mapping from internet addresses to HYPERchannel addresses is:  *  *	 0       7 8      15 16                   31  *	+---------+---------+-----------------------+  *	| network | special | HYPERchannel address  |  *	+---------+---------+-----------------------+  *  *	|<------------ internet address ----------->|  *  * The hyperchannel address is decoded as follows:  *  *       0                 7 8             13 14  15  *	+-------------------+----------------+------+  *	|   adapter number  |      zero      | port |  *	+-------------------+----------------+------+  *  * The low 2 bits are port number (interpreted by hyperchannel hardware).  *  * The encoding of special bits is:  *  *	00	normal packet  *  *	01	loop this packet back to the sender at the  *		specified adapter (ip header source/destination addresses  *		swapped before sending, command bits added to tell the  *		remote HYPERchannel adapter debug& performance studies]  *		this code acts like 02 (below) if the ip destination (before  *		any swapping) and the destination address don't match (e.g.  *		this packet is being routed through a gateway)  *  *	02	loop this packet back to the sender at the  *		specified adapter, but go through the specified adapter's  *		IP.  This is for testing IP's store and forward mechanism.  *  *	other	undefined, currently treated as normal packet  *  */
end_comment

begin_define
define|#
directive|define
name|MPSIZE
value|64
end_define

begin_comment
comment|/* "Message Proper" size */
end_comment

begin_define
define|#
directive|define
name|MAXRETRY
value|4
end_define

begin_comment
comment|/*  * Device registers  */
end_comment

begin_struct
struct|struct
name|hydevice
block|{
name|short
name|hyd_wcr
decl_stmt|;
comment|/* word count (negated) */
name|u_short
name|hyd_bar
decl_stmt|;
comment|/* bus address bits 15-0 */
name|u_short
name|hyd_csr
decl_stmt|;
comment|/* control and status */
name|u_short
name|hyd_dbuf
decl_stmt|;
comment|/* data buffer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * CSR bit layout  */
end_comment

begin_define
define|#
directive|define
name|S_ERROR
value|0100000
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|S_NEX
value|0040000
end_define

begin_comment
comment|/* non-existent memory error */
end_comment

begin_define
define|#
directive|define
name|S_ATTN
value|0020000
end_define

begin_comment
comment|/* attn (always zero) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PI13
end_ifdef

begin_define
define|#
directive|define
name|S_STKINTR
value|0010000
end_define

begin_comment
comment|/* stacked interrupt */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_MAINT
value|0010000
end_define

begin_comment
comment|/* maintenance (not used) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_A
value|0004000
end_define

begin_comment
comment|/* device status A (recieve data available) */
end_comment

begin_define
define|#
directive|define
name|S_B
value|0002000
end_define

begin_comment
comment|/* device status B (normal termination) */
end_comment

begin_define
define|#
directive|define
name|S_C
value|0001000
end_define

begin_comment
comment|/* device status C (abnormal termination) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PI13
end_ifdef

begin_define
define|#
directive|define
name|S_POWEROFF
value|0000400
end_define

begin_comment
comment|/* power off indicator */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|S_CYCLE
value|0000400
end_define

begin_comment
comment|/* cycle (not used) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_READY
value|0000200
end_define

begin_comment
comment|/* ready */
end_comment

begin_define
define|#
directive|define
name|S_IE
value|0000100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|S_XBA
value|0000060
end_define

begin_comment
comment|/* bus address bit bits 17 and 16 */
end_comment

begin_define
define|#
directive|define
name|S_CLRINT
value|0000014
end_define

begin_comment
comment|/* clear stacked interrupt */
end_comment

begin_define
define|#
directive|define
name|S_IATTN
value|0000010
end_define

begin_comment
comment|/* interrupt on attention only */
end_comment

begin_define
define|#
directive|define
name|S_WC
value|0000004
end_define

begin_comment
comment|/* interrupt on word count == 0 only */
end_comment

begin_define
define|#
directive|define
name|S_IATTNWC
value|0000000
end_define

begin_comment
comment|/* interrupt on word count == 0 and attention */
end_comment

begin_define
define|#
directive|define
name|S_BURST
value|0000002
end_define

begin_comment
comment|/* burst mode DMA (not used) */
end_comment

begin_define
define|#
directive|define
name|S_GO
value|0000001
end_define

begin_comment
comment|/* go */
end_comment

begin_define
define|#
directive|define
name|XBASHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HY_CSR_BITS
value|"\20\ \20ERROR\17NEX\16ATTN\15STKINTR\14RECV_DATA\13NORMAL\12ABNORMAL\11POWER\ \10READY\07IENABLE\06XBA17\05XBA16\04IATTN\03IWC\02BURST\01GO"
end_define

begin_comment
comment|/*  * PI13 status conditions  */
end_comment

begin_define
define|#
directive|define
name|HYS_RECVDATA
parameter_list|(
name|x
parameter_list|)
value|(((x)->hyd_csr& S_A) != 0)
end_define

begin_comment
comment|/* get adapter data */
end_comment

begin_define
define|#
directive|define
name|HYS_NORMAL
parameter_list|(
name|x
parameter_list|)
value|(((x)->hyd_csr& S_B) != 0)
end_define

begin_comment
comment|/* done normally */
end_comment

begin_define
define|#
directive|define
name|HYS_ABNORMAL
parameter_list|(
name|x
parameter_list|)
value|(((x)->hyd_csr& S_C) != 0)
end_define

begin_comment
comment|/* done abnormally */
end_comment

begin_define
define|#
directive|define
name|HYS_ERROR
parameter_list|(
name|x
parameter_list|)
value|(((x)->hyd_csr& S_ERROR) != 0)
end_define

begin_comment
comment|/* error condition */
end_comment

begin_define
define|#
directive|define
name|HYS_DONE
parameter_list|(
name|x
parameter_list|)
value|(((x)->hyd_csr& (S_ERROR|S_B|S_C)) != 0)
end_define

begin_comment
comment|/*  * Function Codes for the Hyperchannel Adapter  * The codes are offset so they can be "or"ed into  * the reg data buffer  */
end_comment

begin_define
define|#
directive|define
name|HYF_XMITMSG
value|0x04
end_define

begin_comment
comment|/* transmit message */
end_comment

begin_define
define|#
directive|define
name|HYF_XMITDATA
value|0x08
end_define

begin_comment
comment|/* transmit associated data */
end_comment

begin_define
define|#
directive|define
name|HYF_XMITLSTDATA
value|0x0C
end_define

begin_comment
comment|/* transmit last associated data */
end_comment

begin_define
define|#
directive|define
name|HYF_XMITLOCMSG
value|0x10
end_define

begin_comment
comment|/* transmit local message */
end_comment

begin_define
define|#
directive|define
name|HYF_INPUTMSG
value|0x24
end_define

begin_comment
comment|/* input message proper */
end_comment

begin_define
define|#
directive|define
name|HYF_INPUTDATA
value|0x28
end_define

begin_comment
comment|/* input assiciated data */
end_comment

begin_define
define|#
directive|define
name|HYF_STATUS
value|0x40
end_define

begin_comment
comment|/* request status */
end_comment

begin_define
define|#
directive|define
name|HYF_DUMPREGS
value|0x50
end_define

begin_comment
comment|/* dump extention registers */
end_comment

begin_define
define|#
directive|define
name|HYF_MARKP0
value|0x60
end_define

begin_comment
comment|/* mark down port 0 */
end_comment

begin_define
define|#
directive|define
name|HYF_MARKP1
value|0x64
end_define

begin_comment
comment|/* mark down port 1 */
end_comment

begin_define
define|#
directive|define
name|HYF_MARKP2
value|0x68
end_define

begin_comment
comment|/* mark down port 2 */
end_comment

begin_define
define|#
directive|define
name|HYF_MARKP3
value|0x6C
end_define

begin_comment
comment|/* mark down port 3 */
end_comment

begin_define
define|#
directive|define
name|HYF_MP0RR
value|0x70
end_define

begin_comment
comment|/* mark down port 0 and reroute messages */
end_comment

begin_define
define|#
directive|define
name|HYF_MP1RR
value|0x74
end_define

begin_comment
comment|/* mark down port 1 and reroute messages */
end_comment

begin_define
define|#
directive|define
name|HYF_MP2RR
value|0x78
end_define

begin_comment
comment|/* mark down port 2 and reroute messages */
end_comment

begin_define
define|#
directive|define
name|HYF_MP3RR
value|0x7C
end_define

begin_comment
comment|/* mark down port 3 and reroute messages */
end_comment

begin_define
define|#
directive|define
name|HYF_RSTATS
value|0xA0
end_define

begin_comment
comment|/* read statistics */
end_comment

begin_define
define|#
directive|define
name|HYF_RCSTATS
value|0xA4
end_define

begin_comment
comment|/* read and clear statistics */
end_comment

begin_define
define|#
directive|define
name|HYF_SETTEST
value|0xC0
end_define

begin_comment
comment|/* enable test operations *set test mode) */
end_comment

begin_define
define|#
directive|define
name|HYF_SADDR_LEN
value|0xC4
end_define

begin_comment
comment|/* test mode: set address and length */
end_comment

begin_define
define|#
directive|define
name|HYF_WBUFF
value|0xC8
end_define

begin_comment
comment|/* test mode: write buffer */
end_comment

begin_define
define|#
directive|define
name|HYF_RBUFF
value|0xCC
end_define

begin_comment
comment|/* test mode: read buffer */
end_comment

begin_define
define|#
directive|define
name|HYF_CLRADAPTER
value|0xE0
end_define

begin_comment
comment|/* clear adapter */
end_comment

begin_define
define|#
directive|define
name|HYF_END_OP
value|0xE4
end_define

begin_comment
comment|/* end operation */
end_comment

begin_define
define|#
directive|define
name|HYF_CLRWFMSG
value|0xE6
end_define

begin_comment
comment|/* clear wait for mwssage */
end_comment

begin_define
define|#
directive|define
name|HYF_WAITFORMSG
value|0xE8
end_define

begin_comment
comment|/* wait for message */
end_comment

end_unit

