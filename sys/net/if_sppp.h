begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for synchronous PPP/Cisco link level subroutines.  *  * Copyright (C) 1994 Cronyx Ltd.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * Heavily revamped to conform to RFC 1661.  * Copyright (C) 1997, Joerg Wunsch.  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organizations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * From: Version 1.7, Wed Jun  7 22:12:02 MSD 1995  *  * $Id: if_sppp.h,v 1.6 1997/05/22 22:15:39 joerg Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_HDLC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_HDLC_H_
value|1
end_define

begin_define
define|#
directive|define
name|IDX_LCP
value|0
end_define

begin_comment
comment|/* idx into state table */
end_comment

begin_struct
struct|struct
name|slcp
block|{
name|u_long
name|opts
decl_stmt|;
comment|/* LCP options to send (bitfield) */
name|u_long
name|magic
decl_stmt|;
comment|/* local magic number */
name|u_long
name|mru
decl_stmt|;
comment|/* our max receive unit */
name|u_long
name|their_mru
decl_stmt|;
comment|/* their max receive unit */
name|u_long
name|protos
decl_stmt|;
comment|/* bitmask of protos that are started */
name|u_char
name|echoid
decl_stmt|;
comment|/* id of last keepalive echo request */
comment|/* restart max values, see RFC 1661 */
name|int
name|timeout
decl_stmt|;
name|int
name|max_terminate
decl_stmt|;
name|int
name|max_configure
decl_stmt|;
name|int
name|max_failure
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDX_IPCP
value|1
end_define

begin_comment
comment|/* idx into state table */
end_comment

begin_struct
struct|struct
name|sipcp
block|{
name|u_long
name|opts
decl_stmt|;
comment|/* IPCP options to send (bitfield) */
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|IPCP_HISADDR_SEEN
value|1
comment|/* have seen his address already */
define|#
directive|define
name|IPCP_MYADDR_DYN
value|2
comment|/* my address is dynamically assigned */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDX_COUNT
value|(IDX_IPCP + 1)
end_define

begin_comment
comment|/* bump this when adding cp's! */
end_comment

begin_comment
comment|/*  * Don't change the order of this.  Ordering the phases this way allows  * for a comparision of ``pp_phase>= PHASE_AUTHENTICATE'' in order to  * know whether LCP is up.  */
end_comment

begin_enum
enum|enum
name|ppp_phase
block|{
name|PHASE_DEAD
block|,
name|PHASE_ESTABLISH
block|,
name|PHASE_TERMINATE
block|,
name|PHASE_AUTHENTICATE
block|,
name|PHASE_NETWORK
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sppp
block|{
comment|/* NB: pp_if _must_ be first */
name|struct
name|ifnet
name|pp_if
decl_stmt|;
comment|/* network interface data */
name|struct
name|ifqueue
name|pp_fastq
decl_stmt|;
comment|/* fast output queue */
name|struct
name|ifqueue
name|pp_cpq
decl_stmt|;
comment|/* PPP control protocol queue */
name|struct
name|sppp
modifier|*
name|pp_next
decl_stmt|;
comment|/* next interface in keepalive list */
name|u_int
name|pp_flags
decl_stmt|;
comment|/* use Cisco protocol instead of PPP */
name|u_short
name|pp_alivecnt
decl_stmt|;
comment|/* keepalive packets counter */
name|u_short
name|pp_loopcnt
decl_stmt|;
comment|/* loopback detection counter */
name|u_long
name|pp_seq
decl_stmt|;
comment|/* local sequence number */
name|u_long
name|pp_rseq
decl_stmt|;
comment|/* remote sequence number */
name|enum
name|ppp_phase
name|pp_phase
decl_stmt|;
comment|/* phase we're currently in */
name|int
name|state
index|[
name|IDX_COUNT
index|]
decl_stmt|;
comment|/* state machine */
name|u_char
name|confid
index|[
name|IDX_COUNT
index|]
decl_stmt|;
comment|/* id of last configuration request */
name|int
name|rst_counter
index|[
name|IDX_COUNT
index|]
decl_stmt|;
comment|/* restart counter */
name|int
name|fail_counter
index|[
name|IDX_COUNT
index|]
decl_stmt|;
comment|/* negotiation failure counter */
name|struct
name|callout_handle
name|ch
index|[
name|IDX_COUNT
index|]
decl_stmt|;
name|struct
name|slcp
name|lcp
decl_stmt|;
comment|/* LCP params */
name|struct
name|sipcp
name|ipcp
decl_stmt|;
comment|/* IPCP params */
comment|/* 	 * These functions are filled in by sppp_attach(), and are 	 * expected to be used by the lower layer (hardware) drivers 	 * in order to communicate the (un)availability of the 	 * communication link.  Lower layer drivers that are always 	 * ready to communicate (like hardware HDLC) can shortcut 	 * pp_up from pp_tls, and pp_down from pp_tlf. 	 */
name|void
function_decl|(
modifier|*
name|pp_up
function_decl|)
parameter_list|(
name|struct
name|sppp
modifier|*
name|sp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pp_down
function_decl|)
parameter_list|(
name|struct
name|sppp
modifier|*
name|sp
parameter_list|)
function_decl|;
comment|/* 	 * These functions need to be filled in by the lower layer 	 * (hardware) drivers if they request notification from the 	 * PPP layer whether the link is actually required.  They 	 * correspond to the tls and tlf actions. 	 */
name|void
function_decl|(
modifier|*
name|pp_tls
function_decl|)
parameter_list|(
name|struct
name|sppp
modifier|*
name|sp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pp_tlf
function_decl|)
parameter_list|(
name|struct
name|sppp
modifier|*
name|sp
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PP_KEEPALIVE
value|0x01
end_define

begin_comment
comment|/* use keepalive protocol */
end_comment

begin_define
define|#
directive|define
name|PP_CISCO
value|0x02
end_define

begin_comment
comment|/* use Cisco protocol instead of PPP */
end_comment

begin_define
define|#
directive|define
name|PP_MTU
value|1500
end_define

begin_comment
comment|/* default/minimal MRU */
end_comment

begin_define
define|#
directive|define
name|PP_MAX_MRU
value|2048
end_define

begin_comment
comment|/* maximal MRU we want to negotiate */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|void
name|sppp_attach
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sppp_detach
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sppp_input
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sppp_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sppp_dequeue
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sppp_isempty
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sppp_flush
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
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
comment|/* _NET_IF_HDLC_H_ */
end_comment

end_unit

