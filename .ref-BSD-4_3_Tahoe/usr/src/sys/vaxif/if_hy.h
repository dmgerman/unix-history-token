begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_hy.h	7.2 (Berkeley) 12/22/87  */
end_comment

begin_comment
comment|/*  * 4.2 BSD Unix Kernel - Vax Network Interface Support  *  * $Header: if_hy.h,v 10.0 84/06/30 19:51:21 steveg Stable $  * $Locker:  $  *  * Modifications from Berkeley 4.2 BSD  * Copyright (c) 1983, Tektronix Inc.  * All Rights Reserved  *  *  * $Log:	if_hy.h,v $  *	Revision 10.0  84/06/30  19:51:21  steveg  *	Big Build  *	  *	Revision 3.13  84/05/30  19:40:58  steveg  *	update hy_stat to reflect new microcode  *	  *	Revision 3.12  84/05/30  19:06:57  steveg  *	move driver state number definition here from if_hy.c  *	  *	Revision 3.11  84/05/30  18:56:15  steveg  *	add definition of HYE_MAX and HYE_SIZE  *	  *	Revision 3.10  84/05/30  17:14:04  steveg  *	add hyl_filter  *	  *	Revision 3.9  84/05/30  13:45:24  steveg  *	rework logging  *	  *	Revision 3.8  84/05/04  05:18:59  steveg  *	hyr_key now a u_long  *	  *	Revision 3.7  84/05/01  22:45:20  steveg  *	add H_RLOOPBK for A710 remote end loopback command  *	  *  */
end_comment

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
name|short
name|hyh_addr
decl_stmt|;
name|char
name|hyh_baddr
index|[
literal|2
index|]
decl_stmt|;
block|}
name|hyh_uto
union|,
name|hyh_ufrom
union|;
comment|/* to/from address */
name|short
name|hyh_param
decl_stmt|;
comment|/* parameter word */
name|short
name|hyh_type
decl_stmt|;
comment|/* record type */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|hyh_to
value|hyh_uto.hyh_addr
end_define

begin_define
define|#
directive|define
name|hyh_to_port
value|hyh_uto.hyh_baddr[1]
end_define

begin_define
define|#
directive|define
name|hyh_to_adapter
value|hyh_uto.hyh_baddr[0]
end_define

begin_define
define|#
directive|define
name|hyh_from
value|hyh_ufrom.hyh_addr
end_define

begin_define
define|#
directive|define
name|hyh_from_port
value|hyh_ufrom.hyh_baddr[1]
end_define

begin_define
define|#
directive|define
name|hyh_from_adapter
value|hyh_ufrom.hyh_baddr[0]
end_define

begin_comment
comment|/*  * Structure of a HYPERchannel message header (from software)  */
end_comment

begin_struct
struct|struct
name|hym_hdr
block|{
struct|struct
block|{
name|short
name|hymd_mplen
decl_stmt|;
comment|/* message proper len, if associated data */
block|}
name|hym_d
struct|;
name|struct
name|hy_hdr
name|hym_h
decl_stmt|;
comment|/* hardware header, MUST BE LAST */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|hym_mplen
value|hym_d.hymd_mplen
end_define

begin_define
define|#
directive|define
name|hym_ctl
value|hym_h.hyh_ctl
end_define

begin_define
define|#
directive|define
name|hym_access
value|hym_h.hyh_access
end_define

begin_define
define|#
directive|define
name|hym_param
value|hym_h.hyh_param
end_define

begin_define
define|#
directive|define
name|hym_type
value|hym_h.hyh_type
end_define

begin_define
define|#
directive|define
name|hym_to
value|hym_h.hyh_to
end_define

begin_define
define|#
directive|define
name|hym_to_port
value|hym_h.hyh_to_port
end_define

begin_define
define|#
directive|define
name|hym_to_adapter
value|hym_h.hyh_to_adapter
end_define

begin_define
define|#
directive|define
name|hym_from
value|hym_h.hyh_from
end_define

begin_define
define|#
directive|define
name|hym_from_port
value|hym_h.hyh_from_port
end_define

begin_define
define|#
directive|define
name|hym_from_adapter
value|hym_h.hyh_from_adapter
end_define

begin_define
define|#
directive|define
name|HYM_SWLEN
value|(sizeof(struct hym_hdr) - sizeof(struct hy_hdr))
end_define

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

begin_define
define|#
directive|define
name|H_RLOOPBK
value|0x008F
end_define

begin_comment
comment|/* A710 remote loopback command */
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

begin_comment
comment|/*  * Routing database  */
end_comment

begin_define
define|#
directive|define
name|HYRSIZE
value|37
end_define

begin_comment
comment|/* max number of adapters in routing tables */
end_comment

begin_struct
struct|struct
name|hy_route
block|{
name|time_t
name|hyr_lasttime
decl_stmt|;
comment|/* last update time */
name|u_char
name|hyr_gateway
index|[
literal|256
index|]
decl_stmt|;
struct|struct
name|hyr_hash
block|{
name|u_long
name|hyr_key
decl_stmt|;
comment|/* desired address */
name|u_short
name|hyr_flags
decl_stmt|;
comment|/* status flags - see below */
name|u_short
name|hyr_size
decl_stmt|;
comment|/* number of entries */
union|union
block|{
comment|/* 			 * direct entry (can get there directly) 			 */
struct|struct
block|{
name|u_short
name|hyru_dst
decl_stmt|;
comment|/* adapter number& port */
name|u_short
name|hyru_ctl
decl_stmt|;
comment|/* trunks to try */
name|u_short
name|hyru_access
decl_stmt|;
comment|/* access code (mostly unused) */
block|}
name|hyr_d
struct|;
define|#
directive|define
name|hyr_dst
value|hyr_u.hyr_d.hyru_dst
define|#
directive|define
name|hyr_ctl
value|hyr_u.hyr_d.hyru_ctl
define|#
directive|define
name|hyr_access
value|hyr_u.hyr_d.hyru_access
comment|/* 			 * indirect entry (one or more hops required) 			 */
struct|struct
block|{
name|u_char
name|hyru_pgate
decl_stmt|;
comment|/* 1st gateway slot */
name|u_char
name|hyru_egate
decl_stmt|;
comment|/* # gateways */
name|u_char
name|hyru_nextgate
decl_stmt|;
comment|/* gateway to use next */
block|}
name|hyr_i
struct|;
define|#
directive|define
name|hyr_pgate
value|hyr_u.hyr_i.hyru_pgate
define|#
directive|define
name|hyr_egate
value|hyr_u.hyr_i.hyru_egate
define|#
directive|define
name|hyr_nextgate
value|hyr_u.hyr_i.hyru_nextgate
block|}
name|hyr_u
union|;
block|}
name|hyr_hash
index|[
name|HYRSIZE
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * routing table set/get structure  *  * used to just pass the entire routing table through, but 4.2 ioctls  * limit the data part of an ioctl to 128 bytes or so and use the  * interface name to get things sent the right place.  * see ../net/if.h for additional details.  */
end_comment

begin_struct
struct|struct
name|hyrsetget
block|{
name|char
name|hyrsg_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "hy0" */
name|struct
name|hy_route
modifier|*
name|hyrsg_ptr
decl_stmt|;
comment|/* pointer to routing table */
name|unsigned
name|hyrsg_len
decl_stmt|;
comment|/* size of routing table provided */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HYR_INUSE
value|0x01
end_define

begin_comment
comment|/* entry in use */
end_comment

begin_define
define|#
directive|define
name|HYR_DIR
value|0x02
end_define

begin_comment
comment|/* direct entry */
end_comment

begin_define
define|#
directive|define
name|HYR_GATE
value|0x04
end_define

begin_comment
comment|/* gateway entry */
end_comment

begin_define
define|#
directive|define
name|HYR_LOOP
value|0x08
end_define

begin_comment
comment|/* hardware loopback entry */
end_comment

begin_define
define|#
directive|define
name|HYR_RLOOP
value|0x10
end_define

begin_comment
comment|/* remote adapter hardware loopback entry */
end_comment

begin_define
define|#
directive|define
name|HYRHASH
parameter_list|(
name|x
parameter_list|)
value|(((x) ^ ((x)>> 16)) % HYRSIZE)
end_define

begin_define
define|#
directive|define
name|HYSETROUTE
value|_IOW('i', 0x80, struct hyrsetget)
end_define

begin_define
define|#
directive|define
name|HYGETROUTE
value|_IOW('i', 0x81, struct hyrsetget)
end_define

begin_struct
struct|struct
name|hylsetget
block|{
name|char
name|hylsg_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "hy0" */
name|int
name|hylsg_cmd
decl_stmt|;
comment|/* logging command */
name|caddr_t
name|hylsg_ptr
decl_stmt|;
comment|/* pointer to table */
name|u_long
name|hylsg_len
decl_stmt|;
comment|/* size of table provided */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HYSETLOG
value|_IOW('i', 0x82, struct hylsetget)
end_define

begin_define
define|#
directive|define
name|HYGETLOG
value|_IOW('i', 0x83, struct hylsetget)
end_define

begin_define
define|#
directive|define
name|HYGETELOG
value|_IOW('i', 0x84, struct hylsetget)
end_define

begin_comment
comment|/*  * Structure of Statistics Record (counters)  */
end_comment

begin_struct
struct|struct
name|hy_stat
block|{
name|u_char
name|hyc_df0
index|[
literal|3
index|]
decl_stmt|;
comment|/* # data frames trunk 0 */
name|u_char
name|hyc_df1
index|[
literal|3
index|]
decl_stmt|;
comment|/* # data frames trunk 1 */
name|u_char
name|hyc_df2
index|[
literal|3
index|]
decl_stmt|;
comment|/* # data frames trunk 2 */
name|u_char
name|hyc_df3
index|[
literal|3
index|]
decl_stmt|;
comment|/* # data frames trunk 3 */
name|u_char
name|hyc_cancel
index|[
literal|2
index|]
decl_stmt|;
comment|/* # cancel operations */
name|u_char
name|hyc_abort
index|[
literal|2
index|]
decl_stmt|;
comment|/* # aborts */
name|u_char
name|hyc_ret0
index|[
literal|3
index|]
decl_stmt|;
comment|/* # retransmissions trunk 0 */
name|u_char
name|hyc_ret1
index|[
literal|3
index|]
decl_stmt|;
comment|/* # retransmissions trunk 1 */
name|u_char
name|hyc_ret2
index|[
literal|3
index|]
decl_stmt|;
comment|/* # retransmissions trunk 2 */
name|u_char
name|hyc_ret3
index|[
literal|3
index|]
decl_stmt|;
comment|/* # retransmissions trunk 3 */
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
name|u_short
name|hyl_wait
decl_stmt|;
comment|/* number of bytes till next wakeup */
name|u_short
name|hyl_count
decl_stmt|;
comment|/* number of samples till stop */
name|u_short
name|hyl_icount
decl_stmt|;
comment|/* initial value of hyl_count */
name|u_long
name|hyl_filter
decl_stmt|;
comment|/* log items with specific bits set */
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
comment|/* recieved pkt (short len; struct hym_hdr) */
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
name|HYL_CANCEL
value|8
end_define

begin_comment
comment|/* cancel transmit attempt */
end_comment

begin_define
define|#
directive|define
name|HYL_RESET
value|9
end_define

begin_comment
comment|/* hyinit or unibus reset */
end_comment

begin_define
define|#
directive|define
name|HYL_IOCTL
value|10
end_define

begin_comment
comment|/* hyioctl */
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
name|HYL_CATCHN
value|2
end_define

begin_comment
comment|/* hyl_count transactions being captured */
end_comment

begin_comment
comment|/*  * error code histograms  */
end_comment

begin_define
define|#
directive|define
name|HYE_MAX
value|0x18
end_define

begin_comment
comment|/* maximum adapter error code */
end_comment

begin_define
define|#
directive|define
name|HYE_BINS
value|4
end_define

begin_comment
comment|/* number of command bins */
end_comment

begin_define
define|#
directive|define
name|HYE_SIZE
value|(HYE_MAX+1)*HYE_BINS
end_define

begin_comment
comment|/* size of histogram buffer */
end_comment

begin_comment
comment|/*  * Requests for service (in order by descending priority).  */
end_comment

begin_define
define|#
directive|define
name|RQ_ENDOP
value|001
end_define

begin_comment
comment|/* end the last adapter function */
end_comment

begin_define
define|#
directive|define
name|RQ_REISSUE
value|002
end_define

begin_comment
comment|/* reissue previous cmd after status */
end_comment

begin_define
define|#
directive|define
name|RQ_STATUS
value|004
end_define

begin_comment
comment|/* get the status of the adapter */
end_comment

begin_define
define|#
directive|define
name|RQ_STATISTICS
value|010
end_define

begin_comment
comment|/* get the statistics of the adapter */
end_comment

begin_define
define|#
directive|define
name|RQ_MARKDOWN
value|020
end_define

begin_comment
comment|/* mark this adapter port down */
end_comment

begin_define
define|#
directive|define
name|RQ_MARKUP
value|040
end_define

begin_comment
comment|/* mark this interface up */
end_comment

begin_define
define|#
directive|define
name|RQ_XASSOC
value|0100
end_define

begin_comment
comment|/* associated data to transmit */
end_comment

begin_comment
comment|/*   * Driver states.  */
end_comment

begin_define
define|#
directive|define
name|STARTUP
value|0
end_define

begin_comment
comment|/* initial state (before fully there) */
end_comment

begin_define
define|#
directive|define
name|IDLE
value|1
end_define

begin_comment
comment|/* idle state */
end_comment

begin_define
define|#
directive|define
name|STATSENT
value|2
end_define

begin_comment
comment|/* status cmd sent to adapter */
end_comment

begin_define
define|#
directive|define
name|ENDOPSENT
value|3
end_define

begin_comment
comment|/* end operation cmd sent */
end_comment

begin_define
define|#
directive|define
name|RECVSENT
value|4
end_define

begin_comment
comment|/* input message cmd sent */
end_comment

begin_define
define|#
directive|define
name|RECVDATASENT
value|5
end_define

begin_comment
comment|/* input data cmd sent */
end_comment

begin_define
define|#
directive|define
name|XMITSENT
value|6
end_define

begin_comment
comment|/* transmit message cmd sent */
end_comment

begin_define
define|#
directive|define
name|XMITDATASENT
value|7
end_define

begin_comment
comment|/* transmit data cmd sent */
end_comment

begin_define
define|#
directive|define
name|WAITING
value|8
end_define

begin_comment
comment|/* waiting for messages */
end_comment

begin_define
define|#
directive|define
name|CLEARSENT
value|9
end_define

begin_comment
comment|/* clear wait for message cmd sent */
end_comment

begin_define
define|#
directive|define
name|MARKPORT
value|10
end_define

begin_comment
comment|/* mark this host's adapter port down issued */
end_comment

begin_define
define|#
directive|define
name|RSTATSENT
value|11
end_define

begin_comment
comment|/* read statistics cmd sent to adapter */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HYLOG
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|hy_state_names
index|[]
init|=
block|{
literal|"Startup"
block|,
literal|"Idle"
block|,
literal|"Status Sent"
block|,
literal|"End op Sent"
block|,
literal|"Recieve Message Proper Sent"
block|,
literal|"Recieve Data Sent"
block|,
literal|"Transmit Message Proper Sent"
block|,
literal|"Transmit Data Sent"
block|,
literal|"Wait for Message Sent"
block|,
literal|"Clear Wait for Message Sent"
block|,
literal|"Mark Port Down Sent"
block|,
literal|"Read Statistics Sent"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

