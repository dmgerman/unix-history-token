begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * %sccs.include.redist.c%  *  *	@(#)pk_var.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Protocol-Protocol Packet Buffer.  * (Eventually will be replace by system-wide structure).  */
end_comment

begin_struct
struct|struct
name|pq
block|{
name|int
function_decl|(
modifier|*
name|pq_put
function_decl|)
parameter_list|()
function_decl|;
comment|/* How to process data */
name|struct
name|mbuf
modifier|*
name|pq_data
decl_stmt|;
comment|/* Queued data */
name|int
name|pq_space
decl_stmt|;
comment|/* For accounting */
name|int
name|pq_flags
decl_stmt|;
name|int
function_decl|(
modifier|*
name|pq_unblock
function_decl|)
parameter_list|()
function_decl|;
comment|/* called& cleared when unblocking */
name|caddr_t
name|pq_proto
decl_stmt|;
comment|/* for other service entries */
name|caddr_t
name|pq_next
decl_stmt|;
comment|/* next q, or route, or pcb */
block|}
struct|;
end_struct

begin_comment
comment|/*  *  *  X.25 Logical Channel Descriptor  *  */
end_comment

begin_struct
struct|struct
name|pklcd
block|{
name|struct
name|pq
name|lcd_downq
decl_stmt|,
name|lcd_upq
decl_stmt|;
comment|/* protocol glue for datagram service */
name|short
name|lcd_lcn
decl_stmt|;
comment|/* Logical channel number */
name|short
name|lcd_state
decl_stmt|;
comment|/* Logical Channel state */
name|bool
name|lcd_intrconf_pending
decl_stmt|;
comment|/* Interrupt confirmation pending */
name|octet
name|lcd_intrdata
decl_stmt|;
comment|/* Octet of incoming intr data */
name|short
name|lcd_timer
decl_stmt|;
comment|/* Various timer values */
name|short
name|lcd_dg_timer
decl_stmt|;
comment|/* to reclaim idle datagram circuits */
name|char
name|lcd_retry
decl_stmt|;
comment|/* Timer retry count */
name|char
name|lcd_rsn
decl_stmt|;
comment|/* Seq no of last received packet */
name|char
name|lcd_ssn
decl_stmt|;
comment|/* Seq no of next packet to send */
name|char
name|lcd_output_window
decl_stmt|;
comment|/* Output flow control window */
name|char
name|lcd_input_window
decl_stmt|;
comment|/* Input flow control window */
name|char
name|lcd_last_transmitted_pr
decl_stmt|;
comment|/* Last Pr value transmitted */
name|bool
name|lcd_rnr_condition
decl_stmt|;
comment|/* Remote in busy condition */
name|bool
name|lcd_window_condition
decl_stmt|;
comment|/* Output window size exceeded */
name|bool
name|lcd_reset_condition
decl_stmt|;
comment|/* True, if waiting reset confirm */
name|char
name|lcd_packetsize
decl_stmt|;
comment|/* Maximum packet size */
name|char
name|lcd_windowsize
decl_stmt|;
comment|/* Window size - both directions */
name|octet
name|lcd_closed_user_group
decl_stmt|;
comment|/* Closed user group specification */
name|char
name|lcd_flags
decl_stmt|;
comment|/* copy of sockaddr_x25 op_flags */
name|struct
name|x25_packet
modifier|*
name|lcd_template
decl_stmt|;
comment|/* Address of current packet */
name|struct
name|socket
modifier|*
name|lcd_so
decl_stmt|;
comment|/* Socket addr for connection */
name|struct
name|sockaddr_x25
modifier|*
name|lcd_craddr
decl_stmt|;
comment|/* Calling address */
name|struct
name|sockaddr_x25
modifier|*
name|lcd_ceaddr
decl_stmt|;
comment|/* Called address */
name|time_t
name|lcd_stime
decl_stmt|;
comment|/* time circuit established */
name|long
name|lcd_txcnt
decl_stmt|;
comment|/* Data packet transmit count */
name|long
name|lcd_rxcnt
decl_stmt|;
comment|/* Data packet receive count */
name|short
name|lcd_intrcnt
decl_stmt|;
comment|/* Interrupt packet transmit count */
name|struct
name|pklcd
modifier|*
name|lcd_listen
decl_stmt|;
comment|/* Next lcd on listen queue */
name|struct
name|pkcb
modifier|*
name|lcd_pkp
decl_stmt|;
comment|/* network this lcd is attached to */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|X25_DG_CIRCUIT
value|0x10
end_define

begin_comment
comment|/* lcd_flag: used for datagrams */
end_comment

begin_define
define|#
directive|define
name|X25_DG_ROUTING
value|0x20
end_define

begin_comment
comment|/* lcd_flag: peer addr not yet known */
end_comment

begin_comment
comment|/*  * Per network information, allocated dynamically  * when a new network is configured.  */
end_comment

begin_struct
struct|struct
name|pkcb
block|{
name|struct
name|pkcb
modifier|*
name|pk_next
decl_stmt|;
name|struct
name|x25_ifaddr
modifier|*
name|pk_ia
decl_stmt|;
comment|/* backpointer to ifaddr */
name|short
name|pk_state
decl_stmt|;
comment|/* packet level status */
name|int
function_decl|(
modifier|*
name|pk_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* link level output procedure */
name|struct
name|x25config
modifier|*
name|pk_xcp
decl_stmt|;
comment|/* network specific configuration */
name|struct
name|x25config
name|pk_xc
decl_stmt|;
comment|/* network specific configuration */
name|struct
name|pklcd
modifier|*
modifier|*
name|pk_chan
decl_stmt|;
comment|/* actual size == xc_maxlcn+1 */
define|#
directive|define
name|pk_maxlcn
value|pk_xc.xc_maxlcn
comment|/* local copy of xc_maxlcn */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Interface address, x25 version. Exactly one of these structures is   *	allocated for each interface with an x25 address.  *  *	The ifaddr structure conatins the protocol-independent part  *	of the structure, and is assumed to be first.  */
end_comment

begin_struct
struct|struct
name|x25_ifaddr
block|{
name|struct
name|ifaddr
name|ia_ifa
decl_stmt|;
comment|/* protocol-independent info */
define|#
directive|define
name|ia_ifp
value|ia_ifa.ifa_ifp
define|#
directive|define
name|ia_flags
value|ia_ifa.ifa_flags
name|struct
name|pkcb
name|ia_pkcb
decl_stmt|;
comment|/* per network information */
define|#
directive|define
name|ia_maxlcn
value|ia_pkcb.pk_maxlcn
define|#
directive|define
name|ia_chan
value|ia_pkcb.pk_chan
define|#
directive|define
name|ia_addr
value|ia_pkcb.pk_xc.xc_addr
name|struct
name|sockaddr_x25
name|ia_sockmask
decl_stmt|;
comment|/* reserve space for netmask */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ``Link-Level'' extension to Routing Entry for upper level  * packet switching via X.25 virtual circuits.  */
end_comment

begin_struct
struct|struct
name|rtextension_x25
block|{
name|struct
name|pklcd
modifier|*
name|rtx_lcd
decl_stmt|;
comment|/* local connection block */
name|struct
name|rtentry
modifier|*
name|rtx_rt
decl_stmt|;
comment|/* back pointer to route */
name|struct
name|x25_ifaddr
modifier|*
name|rtx_ia
decl_stmt|;
comment|/* may not be same as rt_ifa */
name|int
name|rtx_state
decl_stmt|;
comment|/* can't trust lcd->lcd_state */
name|int
name|rtx_flags
decl_stmt|;
name|int
name|rtx_timer
decl_stmt|;
comment|/* for idle timeout */
block|}
struct|;
end_struct

begin_comment
comment|/* States for rtx_state */
end_comment

begin_define
define|#
directive|define
name|XRS_NEWBORN
value|0
end_define

begin_define
define|#
directive|define
name|XRS_RESOLVING
value|1
end_define

begin_define
define|#
directive|define
name|XRS_FREE
value|2
end_define

begin_define
define|#
directive|define
name|XRS_CONNECTED
value|3
end_define

begin_define
define|#
directive|define
name|XRS_CONNECTING
value|4
end_define

begin_define
define|#
directive|define
name|XRS_DISCONNECTING
value|5
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|XRF_VALID
value|0x1
end_define

begin_comment
comment|/* Circuit is live, etc. */
end_comment

begin_define
define|#
directive|define
name|XRF_RTHELD
value|0x2
end_define

begin_comment
comment|/* this lcb references rtentry */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|pkcb
modifier|*
name|pkcbhead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of linked list of networks */
end_comment

begin_decl_stmt
name|struct
name|pklcd
modifier|*
name|pk_listenhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|pk_name
index|[]
decl_stmt|,
modifier|*
name|pk_state
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pk_t20
decl_stmt|,
name|pk_t21
decl_stmt|,
name|pk_t22
decl_stmt|,
name|pk_t23
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

