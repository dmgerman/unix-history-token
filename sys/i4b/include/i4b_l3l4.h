begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_l3l4.h - layer 3 / layer 4 interface  *	------------------------------------------  *  *	$Id: i4b_l3l4.h,v 1.32 2000/08/24 11:48:57 hm Exp $  *  * $FreeBSD$  *  *	last edit-date: [Fri Jun  2 14:29:35 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_L3L4_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_L3L4_H_
end_define

begin_define
define|#
directive|define
name|T303VAL
value|(hz*4)
end_define

begin_comment
comment|/* 4 seconds timeout		*/
end_comment

begin_define
define|#
directive|define
name|T305VAL
value|(hz*30)
end_define

begin_comment
comment|/* 30 seconds timeout		*/
end_comment

begin_define
define|#
directive|define
name|T308VAL
value|(hz*4)
end_define

begin_comment
comment|/* 4 seconds timeout		*/
end_comment

begin_define
define|#
directive|define
name|T309VAL
value|(hz*90)
end_define

begin_comment
comment|/* 90 seconds timeout		*/
end_comment

begin_define
define|#
directive|define
name|T310VAL
value|(hz*60)
end_define

begin_comment
comment|/* 30-120 seconds timeout	*/
end_comment

begin_define
define|#
directive|define
name|T313VAL
value|(hz*4)
end_define

begin_comment
comment|/* 4 seconds timeout		*/
end_comment

begin_define
define|#
directive|define
name|T400DEF
value|(hz*10)
end_define

begin_comment
comment|/* 10 seconds timeout		*/
end_comment

begin_define
define|#
directive|define
name|MAX_BCHAN
value|30
end_define

begin_define
define|#
directive|define
name|N_CALL_DESC
value|(MAX_CONTROLLERS*MAX_BCHAN)
end_define

begin_comment
comment|/* no of call descriptors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nctrl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of controllers detected in system */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bchan_statistics
block|{
name|int
name|outbytes
decl_stmt|;
name|int
name|inbytes
decl_stmt|;
block|}
name|bchan_statistics_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  * table of things the driver needs to know about the b channel  * it is connected to for data transfer  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|i4l_isdn_bchan_linktab
block|{
name|int
name|unit
decl_stmt|;
name|int
name|channel
decl_stmt|;
name|void
function_decl|(
modifier|*
name|bch_config
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|,
name|int
name|bprot
parameter_list|,
name|int
name|updown
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bch_tx_start
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bch_stat
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|,
name|bchan_statistics_t
modifier|*
name|bsp
parameter_list|)
function_decl|;
name|struct
name|ifqueue
modifier|*
name|tx_queue
decl_stmt|;
name|struct
name|ifqueue
modifier|*
name|rx_queue
decl_stmt|;
comment|/* data xfer for NON-HDLC traffic   */
name|struct
name|mbuf
modifier|*
modifier|*
name|rx_mbuf
decl_stmt|;
comment|/* data xfer for HDLC based traffic */
block|}
name|isdn_link_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  * table of things the b channel handler needs to know  about  * the driver it is connected to for data transfer  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|i4l_driver_bchan_linktab
block|{
name|int
name|unit
decl_stmt|;
name|void
function_decl|(
modifier|*
name|bch_rx_data_ready
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bch_tx_queue_empty
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|bch_activity
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|rxtx
parameter_list|)
function_decl|;
define|#
directive|define
name|ACT_RX
value|0
define|#
directive|define
name|ACT_TX
value|1
name|void
function_decl|(
modifier|*
name|line_connected
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|cde
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|line_disconnected
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|void
modifier|*
name|cde
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dial_response
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|stat
parameter_list|,
name|cause_t
name|cause
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|updown_ind
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|updown
parameter_list|)
function_decl|;
block|}
name|drvr_link_t
typedef|;
end_typedef

begin_comment
comment|/* global linktab functions for controller types (aka hardware drivers) */
end_comment

begin_struct
struct|struct
name|ctrl_type_desc
block|{
name|isdn_link_t
modifier|*
function_decl|(
modifier|*
name|get_linktab
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_linktab
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|channel
parameter_list|,
name|drvr_link_t
modifier|*
name|dlt
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ctrl_type_desc
name|ctrl_types
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global linktab functions for RBCH userland driver */
end_comment

begin_function_decl
name|drvr_link_t
modifier|*
name|rbch_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rbch_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|isdn_link_t
modifier|*
name|ilt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global linktab functions for IPR network driver */
end_comment

begin_function_decl
name|drvr_link_t
modifier|*
name|ipr_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipr_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|isdn_link_t
modifier|*
name|ilt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global linktab functions for TEL userland driver */
end_comment

begin_function_decl
name|drvr_link_t
modifier|*
name|tel_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tel_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|isdn_link_t
modifier|*
name|ilt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global linktab functions for ISPPP userland driver */
end_comment

begin_function_decl
name|drvr_link_t
modifier|*
name|i4bisppp_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i4bisppp_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|isdn_link_t
modifier|*
name|ilt
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_comment
comment|/* global linktab functions for IBC userland driver */
end_comment

begin_function_decl
name|drvr_link_t
modifier|*
name|ibc_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibc_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|isdn_link_t
modifier|*
name|ilt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* global linktab functions for ING network driver */
end_comment

begin_function_decl
name|drvr_link_t
modifier|*
name|ing_ret_linktab
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ing_set_linktab
parameter_list|(
name|int
name|unit
parameter_list|,
name|isdn_link_t
modifier|*
name|ilt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this structure describes one call/connection on one B-channel  *	and all its parameters  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|cdid
decl_stmt|;
comment|/* call descriptor id		*/
name|int
name|controller
decl_stmt|;
comment|/* isdn controller number	*/
name|int
name|cr
decl_stmt|;
comment|/* call reference value		*/
name|int
name|crflag
decl_stmt|;
comment|/* call reference flag		*/
define|#
directive|define
name|CRF_ORIG
value|0
comment|/* originating side		*/
define|#
directive|define
name|CRF_DEST
value|1
comment|/* destinating side		*/
name|int
name|channelid
decl_stmt|;
comment|/* channel id value		*/
name|int
name|channelexcl
decl_stmt|;
comment|/* channel exclusive		*/
name|int
name|bprot
decl_stmt|;
comment|/* B channel protocol BPROT_XXX */
name|int
name|driver
decl_stmt|;
comment|/* driver to use for B channel	*/
name|int
name|driver_unit
decl_stmt|;
comment|/* unit for above driver number	*/
name|cause_t
name|cause_in
decl_stmt|;
comment|/* cause value from NT	*/
name|cause_t
name|cause_out
decl_stmt|;
comment|/* cause value to NT	*/
name|int
name|call_state
decl_stmt|;
comment|/* from incoming SETUP	*/
name|u_char
name|dst_telno
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* destination number	*/
name|u_char
name|src_telno
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* source number	*/
name|int
name|scr_ind
decl_stmt|;
comment|/* screening ind for incoming call */
name|int
name|prs_ind
decl_stmt|;
comment|/* presentation ind for incoming call */
name|int
name|Q931state
decl_stmt|;
comment|/* Q.931 state for call	*/
name|int
name|event
decl_stmt|;
comment|/* event to be processed */
name|int
name|response
decl_stmt|;
comment|/* setup response type	*/
name|int
name|T303
decl_stmt|;
comment|/* SETUP sent response timeout	*/
name|int
name|T303_first_to
decl_stmt|;
comment|/* first timeout flag		*/
name|int
name|T305
decl_stmt|;
comment|/* DISC without PROG IND	*/
name|int
name|T308
decl_stmt|;
comment|/* RELEASE sent response timeout*/
name|int
name|T308_first_to
decl_stmt|;
comment|/* first timeout flag		*/
name|int
name|T309
decl_stmt|;
comment|/* data link disconnect timeout	*/
name|int
name|T310
decl_stmt|;
comment|/* CALL PROC received		*/
name|int
name|T313
decl_stmt|;
comment|/* CONNECT sent timeout		*/
name|int
name|T400
decl_stmt|;
comment|/* L4 timeout */
name|isdn_link_t
modifier|*
name|ilt
decl_stmt|;
comment|/* isdn B channel linktab	*/
name|drvr_link_t
modifier|*
name|dlt
decl_stmt|;
comment|/* driver linktab		*/
name|int
name|dir
decl_stmt|;
comment|/* outgoing or incoming call	*/
define|#
directive|define
name|DIR_OUTGOING
value|0
define|#
directive|define
name|DIR_INCOMING
value|1
name|int
name|timeout_active
decl_stmt|;
comment|/* idle timeout() active flag	*/
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|300001
operator|)
operator|||
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
operator|)
name|struct
name|callout_handle
name|idle_timeout_handle
decl_stmt|;
name|struct
name|callout_handle
name|T303_callout
decl_stmt|;
name|struct
name|callout_handle
name|T305_callout
decl_stmt|;
name|struct
name|callout_handle
name|T308_callout
decl_stmt|;
name|struct
name|callout_handle
name|T309_callout
decl_stmt|;
name|struct
name|callout_handle
name|T310_callout
decl_stmt|;
name|struct
name|callout_handle
name|T313_callout
decl_stmt|;
name|struct
name|callout_handle
name|T400_callout
decl_stmt|;
name|int
name|callouts_inited
decl_stmt|;
comment|/* must init before use */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
name|__NetBSD_Version__
operator|>=
literal|104230000
name|struct
name|callout
name|idle_timeout_handle
decl_stmt|;
name|struct
name|callout
name|T303_callout
decl_stmt|;
name|struct
name|callout
name|T305_callout
decl_stmt|;
name|struct
name|callout
name|T308_callout
decl_stmt|;
name|struct
name|callout
name|T309_callout
decl_stmt|;
name|struct
name|callout
name|T310_callout
decl_stmt|;
name|struct
name|callout
name|T313_callout
decl_stmt|;
name|struct
name|callout
name|T400_callout
decl_stmt|;
name|int
name|callouts_inited
decl_stmt|;
comment|/* must init before use */
endif|#
directive|endif
name|int
name|idletime_state
decl_stmt|;
comment|/* wait for idle_time begin	*/
define|#
directive|define
name|IST_IDLE
value|0
comment|/* shorthold mode disabled 	*/
define|#
directive|define
name|IST_NONCHK
value|1
comment|/* in non-checked window	*/
define|#
directive|define
name|IST_CHECK
value|2
comment|/* in idle check window		*/
define|#
directive|define
name|IST_SAFE
value|3
comment|/* in safety zone		*/
name|time_t
name|idletimechk_start
decl_stmt|;
comment|/* check idletime window start	*/
name|time_t
name|connect_time
decl_stmt|;
comment|/* time connect was made	*/
name|time_t
name|last_active_time
decl_stmt|;
comment|/* last time with activity	*/
comment|/* for incoming connections:	*/
name|time_t
name|max_idle_time
decl_stmt|;
comment|/* max time without activity	*/
comment|/* for outgoing connections:	*/
name|msg_shorthold_t
name|shorthold_data
decl_stmt|;
comment|/* shorthold data to use */
name|int
name|aocd_flag
decl_stmt|;
comment|/* AOCD used for unitlength calc*/
name|time_t
name|last_aocd_time
decl_stmt|;
comment|/* last time AOCD received	*/
name|int
name|units
decl_stmt|;
comment|/* number of AOCD charging units*/
name|int
name|units_type
decl_stmt|;
comment|/* units type: AOCD, AOCE	*/
name|int
name|cunits
decl_stmt|;
comment|/* calculated units		*/
name|int
name|isdntxdelay
decl_stmt|;
comment|/* isdn tx delay after connect	*/
name|u_char
name|display
index|[
name|DISPLAY_MAX
index|]
decl_stmt|;
comment|/* display information element	*/
name|char
name|datetime
index|[
name|DATETIME_MAX
index|]
decl_stmt|;
comment|/* date/time information element*/
name|u_char
name|keypad
index|[
name|KEYPAD_MAX
index|]
decl_stmt|;
comment|/* keypad facility		*/
block|}
name|call_desc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|call_desc_t
name|call_desc
index|[
name|N_CALL_DESC
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* forward decl. */
end_comment

begin_struct_decl
struct_decl|struct
name|isdn_diagnostic_request
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|isdn_dr_prot
struct_decl|;
end_struct_decl

begin_comment
comment|/*---------------------------------------------------------------------------*  *	this structure "describes" one controller  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|unit
decl_stmt|;
comment|/* unit number of this contr.	*/
name|int
name|ctrl_type
decl_stmt|;
comment|/* controller type   (CTRL_XXX)	*/
name|int
name|card_type
decl_stmt|;
comment|/* card manufacturer (CARD_XXX) */
name|int
name|protocol
decl_stmt|;
comment|/* D-channel protocol type */
name|int
name|dl_est
decl_stmt|;
comment|/* layer 2 established	*/
define|#
directive|define
name|DL_DOWN
value|0
define|#
directive|define
name|DL_UP
value|1
name|int
name|nbch
decl_stmt|;
comment|/* number of b channels */
name|int
name|bch_state
index|[
name|MAX_BCHAN
index|]
decl_stmt|;
comment|/* states of the b channels */
define|#
directive|define
name|BCH_ST_FREE
value|0
comment|/* free to be used, idle */
define|#
directive|define
name|BCH_ST_RSVD
value|1
comment|/* reserved, may become free or used */
define|#
directive|define
name|BCH_ST_USED
value|2
comment|/* in use for data transfer */
name|int
name|tei
decl_stmt|;
comment|/* current tei or -1 if invalid */
comment|/* pointers to functions to be called from L4 */
name|void
function_decl|(
modifier|*
name|N_CONNECT_REQUEST
function_decl|)
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|N_CONNECT_RESPONSE
function_decl|)
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|N_DISCONNECT_REQUEST
function_decl|)
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|N_ALERT_REQUEST
function_decl|)
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|N_DOWNLOAD
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|numprotos
parameter_list|,
name|struct
name|isdn_dr_prot
modifier|*
name|protocols
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|N_DIAGNOSTICS
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|isdn_diagnostic_request
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|N_MGMT_COMMAND
function_decl|)
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|ctrl_desc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ctrl_desc_t
name|ctrl_desc
index|[
name|MAX_CONTROLLERS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_Q931_H_ */
end_comment

end_unit

