begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_hyreg.h	4.2	83/02/21	*/
end_comment

begin_comment
comment|/*  * Network Systems Corporation Hyperchannel interface  *  * supports A410 adapter interfaced via a DEC DR-11B, NSC PI-13 or PI-14  *	(PI-14 is a PI-13 with different line drivers, software is  *	identical to a PI-13)  *  * Written by Steve Glaser, Tektronix Inc., July 1982  *  * NOTE:  *  * DR11B code has not been fully checked out with 4.1a.  * The first adapters at Tek came with DR11Bs, and the code once worked,  * but those have been upgraded to PI-13s.  */
end_comment

begin_define
define|#
directive|define
name|PI13
value|1
end_define

begin_comment
comment|/* PI13 vs. DR11B device depandant code */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HYLOG
end_ifndef

begin_define
define|#
directive|define
name|HYLOG
value|1
end_define

begin_comment
comment|/* enable logging of errors */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure of a HYPERchannel adapter header  */
end_comment

begin_struct
struct|struct
name|hy_hdr
block|{
name|short
name|hyh_ctl
decl_stmt|;
comment|/* control */
name|short
name|hyh_access
decl_stmt|;
comment|/* access code */
union|union
block|{
comment|/* to/from addresses */
name|short
name|hyh_addr
decl_stmt|;
comment|/* full address */
name|char
name|hyh_baddr
index|[
literal|2
index|]
decl_stmt|;
comment|/* adapter/port number from address */
block|}
name|hyhu_to
union|,
name|hyhu_from
union|;
define|#
directive|define
name|hyh_to
value|hyhu_to.hyh_addr
define|#
directive|define
name|hyh_from
value|hyhu_from.hyh_addr
define|#
directive|define
name|hyh_to_adapter
value|hyhu_to.hyh_baddr[0]
define|#
directive|define
name|hyh_to_port
value|hyhu_to.hyh_baddr[1]
define|#
directive|define
name|hyh_from_adapter
value|hyhu_from.hyh_baddr[0]
define|#
directive|define
name|hyh_from_port
value|hyhu_from.hyh_baddr[1]
name|short
name|hyh_param
decl_stmt|;
comment|/* parameter (for loopback) */
name|char
name|hyh_type
decl_stmt|;
comment|/* record type */
name|char
name|hyh_off
decl_stmt|;
comment|/* offset from end of hy_hdr to ip data */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a HYPERchannel message header (from software)  */
end_comment

begin_struct
struct|struct
name|hym_data
block|{
name|short
name|hymd_mplen
decl_stmt|;
comment|/* message proper length, if associated data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hym_hdr
block|{
name|struct
name|hym_data
name|hym_d
decl_stmt|;
define|#
directive|define
name|hym_mplen
value|hym_d.hymd_mplen
name|struct
name|hy_hdr
name|hym_hdr
decl_stmt|;
comment|/* hardware header, MUST BE LAST */
block|}
struct|;
end_struct

begin_comment
comment|/*  * HYPERchannel header word control bits  */
end_comment

begin_define
define|#
directive|define
name|H_XTRUNKS
value|0x00F0
end_define

begin_comment
comment|/* transmit trunks */
end_comment

begin_define
define|#
directive|define
name|H_RTRUNKS
value|0x000F
end_define

begin_comment
comment|/* remote trunks to transmit on for loopback */
end_comment

begin_define
define|#
directive|define
name|H_ASSOC
value|0x0100
end_define

begin_comment
comment|/* has associated data */
end_comment

begin_define
define|#
directive|define
name|H_LOOPBK
value|0x00FF
end_define

begin_comment
comment|/* loopback command */
end_comment

begin_comment
comment|/*  * Structure of Statistics Record (counters)  */
end_comment

begin_struct
struct|struct
name|hy_stat
block|{
name|u_long
name|hyc_msgcnt
decl_stmt|;
comment|/* # messages transmitted */
name|u_long
name|hyc_dbcnt
decl_stmt|;
comment|/* # data buffers transmitted */
name|u_long
name|hyc_tbusy
decl_stmt|;
comment|/* # available trunks busy */
name|u_long
name|hyc_hwret
decl_stmt|;
comment|/* # hardware retransmits */
name|u_long
name|hyc_crcbad
decl_stmt|;
comment|/* # crc errors on trunk */
name|u_long
name|hyc_mcret
decl_stmt|;
comment|/* # microcode retransmits */
name|u_long
name|hyc_tdabort
decl_stmt|;
comment|/* # trunk driver aborts */
name|u_char
name|hyc_atype
index|[
literal|3
index|]
decl_stmt|;
comment|/* adapter type and revision level */
name|u_char
name|hyc_uaddr
decl_stmt|;
comment|/* adapter unit number */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of the Status Record  */
end_comment

begin_struct
struct|struct
name|hy_status
block|{
name|u_char
name|hys_gen_status
decl_stmt|;
comment|/* general status byte */
name|u_char
name|hys_last_fcn
decl_stmt|;
comment|/* last function code issued */
name|u_char
name|hys_resp_trunk
decl_stmt|;
comment|/* trunk response byte */
name|u_char
name|hys_status_trunk
decl_stmt|;
comment|/* trunk status byte */
name|u_char
name|hys_recd_resp
decl_stmt|;
comment|/* recieved response byte */
name|u_char
name|hys_error
decl_stmt|;
comment|/* error code */
name|u_char
name|hys_caddr
decl_stmt|;
comment|/* compressed addr of 1st msg on chain */
name|u_char
name|hys_pad
decl_stmt|;
comment|/* not used */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Get port number from status record  */
end_comment

begin_define
define|#
directive|define
name|PORTNUM
parameter_list|(
name|p
parameter_list|)
value|(((p)->hys_gen_status>> 6)& 0x03)
end_define

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
value|"\20\20ERROR\17NEX\16ATTN\15STKINTR\14RECV_DATA\13NORMAL\12ABNORMAL\11POWER\10READY\07IENABLE\06XBA17\05XBA16\04IATTN\03IWC\02BURST\01GO"
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

begin_comment
comment|/*  * Hyperchannel record types  */
end_comment

begin_define
define|#
directive|define
name|HYLINK_IP
value|0
end_define

begin_comment
comment|/* Internet Protocol Packet */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HYLOG
end_ifdef

begin_define
define|#
directive|define
name|HYL_SIZE
value|16*1024
end_define

begin_struct
struct|struct
name|hy_log
block|{
name|struct
name|hy_log
modifier|*
name|hyl_self
decl_stmt|;
name|u_char
name|hyl_enable
decl_stmt|;
comment|/* logging enabled? */
name|u_char
name|hyl_onerr
decl_stmt|;
comment|/* state to enter on error */
name|u_char
modifier|*
name|hyl_eptr
decl_stmt|;
comment|/*&hy_log.hyl_buf[HYL_SIZE] */
name|u_char
modifier|*
name|hyl_ptr
decl_stmt|;
comment|/* pointer into hyl_buf */
name|u_char
name|hyl_buf
index|[
name|HYL_SIZE
index|]
decl_stmt|;
comment|/* log buffer space */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HYL_NOP
value|0
end_define

begin_define
define|#
directive|define
name|HYL_UP
value|1
end_define

begin_comment
comment|/* markup */
end_comment

begin_define
define|#
directive|define
name|HYL_STATUS
value|2
end_define

begin_comment
comment|/* status results (struct hy_status) */
end_comment

begin_define
define|#
directive|define
name|HYL_STATISTICS
value|3
end_define

begin_comment
comment|/* statistics (struct hy_stat) */
end_comment

begin_define
define|#
directive|define
name|HYL_XMIT
value|4
end_define

begin_comment
comment|/* packed being send (struct hym_hdr) */
end_comment

begin_define
define|#
directive|define
name|HYL_RECV
value|5
end_define

begin_comment
comment|/* recieved packet (short len; struct hy_hdr) */
end_comment

begin_define
define|#
directive|define
name|HYL_CMD
value|6
end_define

begin_comment
comment|/* cmd issued (uchar cmd, state; short count) */
end_comment

begin_define
define|#
directive|define
name|HYL_INT
value|7
end_define

begin_comment
comment|/* interrupt (short csr, wcr) */
end_comment

begin_define
define|#
directive|define
name|HYL_DISABLED
value|0
end_define

begin_comment
comment|/* logging disabled */
end_comment

begin_define
define|#
directive|define
name|HYL_CONTINUOUS
value|1
end_define

begin_comment
comment|/* continuous logging */
end_comment

begin_define
define|#
directive|define
name|HYL_CAUGHT1
value|2
end_define

begin_comment
comment|/* one buffer full captured */
end_comment

begin_define
define|#
directive|define
name|HYL_CATCH1
value|3
end_define

begin_comment
comment|/* one buffer full being captured */
end_comment

begin_define
define|#
directive|define
name|HYL_CAUGHTSTATUS
value|4
end_define

begin_comment
comment|/* one buffer of status captured */
end_comment

begin_define
define|#
directive|define
name|HYL_CATCHSTATUS
value|5
end_define

begin_comment
comment|/* one buffer fill of status being captured */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|hy_log
name|hy_log
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

