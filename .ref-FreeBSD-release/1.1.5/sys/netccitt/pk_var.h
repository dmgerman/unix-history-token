begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) University of British Columbia, 1984  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Laboratory for Computation Vision and the Computer Science Department  * of the University of British Columbia.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pk_var.h	7.11 (Berkeley) 5/29/91  *	$Id: pk_var.h,v 1.4 1993/11/25 01:34:36 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCCITT_PK_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCCITT_PK_VAR_H_
value|1
end_define

begin_comment
comment|/*  *  *  X.25 Logical Channel Descriptor  *  */
end_comment

begin_struct
struct|struct
name|pklcd
block|{
struct|struct
name|pklcd_q
block|{
name|struct
name|pklcd_q
modifier|*
name|q_forw
decl_stmt|;
comment|/* debugging chain */
name|struct
name|pklcd_q
modifier|*
name|q_back
decl_stmt|;
comment|/* debugging chain */
block|}
name|lcd_q
struct|;
name|void
function_decl|(
modifier|*
name|lcd_upper
function_decl|)
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* switch to socket vs datagram vs ...*/
name|caddr_t
name|lcd_upnext
decl_stmt|;
comment|/* reference for lcd_upper() */
name|int
function_decl|(
modifier|*
name|lcd_send
function_decl|)
parameter_list|()
function_decl|;
comment|/* if X.25 front end, direct connect */
name|caddr_t
name|lcd_downnext
decl_stmt|;
comment|/* reference for lcd_send() */
name|short
name|lcd_lcn
decl_stmt|;
comment|/* Logical channel number */
name|short
name|lcd_state
decl_stmt|;
comment|/* Logical Channel state */
name|short
name|lcd_timer
decl_stmt|;
comment|/* Various timer values */
name|short
name|lcd_dg_timer
decl_stmt|;
comment|/* to reclaim idle datagram circuits */
name|bool
name|lcd_intrconf_pending
decl_stmt|;
comment|/* Interrupt confirmation pending */
name|octet
name|lcd_intrdata
decl_stmt|;
comment|/* Octet of incoming intr data */
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
name|bool
name|lcd_rxrnr_condition
decl_stmt|;
comment|/* True, if we have sent rnr */
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
name|mbuf
modifier|*
name|lcd_facilities
decl_stmt|;
comment|/* user supplied facilities for cr */
name|struct
name|mbuf
modifier|*
name|lcd_template
decl_stmt|;
comment|/* Address of response packet */
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
comment|/* Calling address pointer */
name|struct
name|sockaddr_x25
modifier|*
name|lcd_ceaddr
decl_stmt|;
comment|/* Called address pointer */
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
comment|/* Network this lcd is attached to */
name|struct
name|mbuf
modifier|*
name|lcd_cps
decl_stmt|;
comment|/* Complete Packet Sequence reassembly*/
name|long
name|lcd_cpsmax
decl_stmt|;
comment|/* Max length for CPS */
name|struct
name|sockaddr_x25
name|lcd_faddr
decl_stmt|;
comment|/* Remote Address (Calling) */
name|struct
name|sockaddr_x25
name|lcd_laddr
decl_stmt|;
comment|/* Local Address (Called) */
name|struct
name|sockbuf
name|lcd_sb
decl_stmt|;
comment|/* alternate for datagram service */
block|}
struct|;
end_struct

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
name|short
name|pk_state
decl_stmt|;
comment|/* packet level status */
name|short
name|pk_maxlcn
decl_stmt|;
comment|/* local copy of xc_maxlcn */
name|int
function_decl|(
modifier|*
name|pk_lloutput
function_decl|)
parameter_list|()
function_decl|;
comment|/* link level output procedure */
name|caddr_t
name|pk_llnext
decl_stmt|;
comment|/* handle for next level down */
name|struct
name|x25config
modifier|*
name|pk_xcp
decl_stmt|;
comment|/* network specific configuration */
name|struct
name|x25_ifaddr
modifier|*
name|pk_ia
decl_stmt|;
comment|/* backpointer to ifaddr */
name|struct
name|pklcd
modifier|*
modifier|*
name|pk_chan
decl_stmt|;
comment|/* actual size == xc_maxlcn+1 */
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
name|x25config
name|ia_xc
decl_stmt|;
comment|/* network specific configuration */
define|#
directive|define
name|ia_maxlcn
value|ia_xc.xc_maxlcn
name|int
function_decl|(
modifier|*
name|ia_start
function_decl|)
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
comment|/* connect, confirm method */
name|struct
name|sockaddr_x25
name|ia_dstaddr
decl_stmt|;
comment|/* reserve space for route dst */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ``Link-Level'' extension to Routing Entry for upper level  * packet switching via X.25 virtual circuits.  */
end_comment

begin_struct
struct|struct
name|llinfo_x25
block|{
name|struct
name|llinfo_x25
modifier|*
name|lx_next
decl_stmt|;
comment|/* chain together in linked list */
name|struct
name|llinfo_x25
modifier|*
name|lx_prev
decl_stmt|;
comment|/* chain together in linked list */
name|struct
name|rtentry
modifier|*
name|lx_rt
decl_stmt|;
comment|/* back pointer to route */
name|struct
name|pklcd
modifier|*
name|lx_lcd
decl_stmt|;
comment|/* local connection block */
name|struct
name|x25_ifaddr
modifier|*
name|lx_ia
decl_stmt|;
comment|/* may not be same as rt_ifa */
name|int
name|lx_state
decl_stmt|;
comment|/* can't trust lcd->lcd_state */
name|int
name|lx_flags
decl_stmt|;
name|int
name|lx_timer
decl_stmt|;
comment|/* for idle timeout */
name|int
name|lx_family
decl_stmt|;
comment|/* for dispatch */
block|}
struct|;
end_struct

begin_comment
comment|/* States for lx_state */
end_comment

begin_define
define|#
directive|define
name|LXS_NEWBORN
value|0
end_define

begin_define
define|#
directive|define
name|LXS_RESOLVING
value|1
end_define

begin_define
define|#
directive|define
name|LXS_FREE
value|2
end_define

begin_define
define|#
directive|define
name|LXS_CONNECTING
value|3
end_define

begin_define
define|#
directive|define
name|LXS_CONNECTED
value|4
end_define

begin_define
define|#
directive|define
name|LXS_DISCONNECTING
value|5
end_define

begin_define
define|#
directive|define
name|LXS_LISTENING
value|6
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|LXF_VALID
value|0x1
end_define

begin_comment
comment|/* Circuit is live, etc. */
end_comment

begin_define
define|#
directive|define
name|LXF_RTHELD
value|0x2
end_define

begin_comment
comment|/* this lcb references rtentry */
end_comment

begin_define
define|#
directive|define
name|LXF_LISTEN
value|0x4
end_define

begin_comment
comment|/* accepting incoming calls */
end_comment

begin_comment
comment|/*  * miscellenous debugging info  */
end_comment

begin_struct
struct|struct
name|mbuf_cache
block|{
name|int
name|mbc_size
decl_stmt|;
name|int
name|mbc_num
decl_stmt|;
name|int
name|mbc_oldsize
decl_stmt|;
name|struct
name|mbuf
modifier|*
modifier|*
name|mbc_cache
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|CCITT
argument_list|)
end_if

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

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_x25
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|x25_connect_callback
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|x25_rtrequest
parameter_list|(
name|int
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|x25_rtinvert
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|x25_ddnip_to_ccitt
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|x25_rtattach
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From pk_subr.c: */
end_comment

begin_function_decl
specifier|extern
name|struct
name|pklcd
modifier|*
name|pk_attach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_disconnect
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_close
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|pk_template
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_restart
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_freelcd
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_bind
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_listen
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_protolisten
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
comment|/* XXX */
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_assoc
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|,
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|sockaddr_x25
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_connect
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|sockaddr_x25
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_callrequest
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|sockaddr_x25
modifier|*
parameter_list|,
name|struct
name|x25config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_build_facilities
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr_x25
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_getlcn
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_clear
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_flowcontrol
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_flush
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_procerror
parameter_list|(
name|int
parameter_list|,
name|struct
name|pklcd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_ack
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_decode
parameter_list|(
name|struct
name|x25_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_restartcause
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|,
name|struct
name|x25_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_resetcause
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|,
name|struct
name|x25_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_clearcause
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|,
name|struct
name|x25_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_message
parameter_list|(
name|int
parameter_list|,
name|struct
name|x25config
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_fragment
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From pk_input.c: */
end_comment

begin_function_decl
specifier|extern
name|struct
name|pkcb
modifier|*
name|pk_newlink
parameter_list|(
name|struct
name|x25_ifaddr
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_resize
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
comment|/*void*/
name|pk_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|pkcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|ifqueue
name|pkintrq
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pkintr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* called from locore */
end_comment

begin_function_decl
specifier|extern
name|void
name|pk_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_incoming_call
parameter_list|(
name|struct
name|pkcb
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_call_accepted
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_parse_facilities
parameter_list|(
name|octet
modifier|*
parameter_list|,
name|struct
name|sockaddr_x25
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From pk_output.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|pk_output
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From pk_acct.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|pk_accton
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pk_acct
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From pk_debug.c: */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|pk_name
index|[]
decl_stmt|,
modifier|*
decl_stmt|const
name|pk_state
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pk_trace
parameter_list|(
name|struct
name|x25config
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mbuf_cache
parameter_list|(
name|struct
name|mbuf_cache
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From pk_timer.c: */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pk_t20
decl_stmt|,
name|pk_t21
decl_stmt|,
name|pk_t23
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pk_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From pk_usrreq.c: */
end_comment

begin_function_decl
specifier|extern
name|int
name|pk_usrreq
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_start
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_control
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_ctloutput
parameter_list|(
name|int
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_checksockaddr
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pk_send
parameter_list|(
name|struct
name|pklcd
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETCCITT_PK_VAR_H_ */
end_comment

end_unit

