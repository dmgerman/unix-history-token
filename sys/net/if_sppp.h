begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for synchronous PPP/Cisco link level subroutines.  *  * Copyright (C) 1994 Cronyx Ltd.  * Author: Serge Vakulenko,<vak@zebub.msk.su>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Version 1.1, Thu Oct 27 21:15:02 MSK 1994  */
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

begin_struct
struct|struct
name|slcp
block|{
name|u_short
name|state
decl_stmt|;
comment|/* state machine */
name|u_long
name|magic
decl_stmt|;
comment|/* local magic number */
name|u_long
name|rmagic
decl_stmt|;
comment|/* remote magic number */
name|u_char
name|lastid
decl_stmt|;
comment|/* id of last keepalive echo request */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sipcp
block|{
name|u_short
name|state
decl_stmt|;
comment|/* state machine */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sppp
block|{
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
comment|/* max. transmit unit */
end_comment

begin_define
define|#
directive|define
name|LCP_STATE_CLOSED
value|0
end_define

begin_comment
comment|/* LCP state: closed (conf-req sent) */
end_comment

begin_define
define|#
directive|define
name|LCP_STATE_ACK_RCVD
value|1
end_define

begin_comment
comment|/* LCP state: conf-ack received */
end_comment

begin_define
define|#
directive|define
name|LCP_STATE_ACK_SENT
value|2
end_define

begin_comment
comment|/* LCP state: conf-ack sent */
end_comment

begin_define
define|#
directive|define
name|LCP_STATE_OPENED
value|3
end_define

begin_comment
comment|/* LCP state: opened */
end_comment

begin_define
define|#
directive|define
name|IPCP_STATE_CLOSED
value|0
end_define

begin_comment
comment|/* IPCP state: closed (conf-req sent) */
end_comment

begin_define
define|#
directive|define
name|IPCP_STATE_ACK_RCVD
value|1
end_define

begin_comment
comment|/* IPCP state: conf-ack received */
end_comment

begin_define
define|#
directive|define
name|IPCP_STATE_ACK_SENT
value|2
end_define

begin_comment
comment|/* IPCP state: conf-ack sent */
end_comment

begin_define
define|#
directive|define
name|IPCP_STATE_OPENED
value|3
end_define

begin_comment
comment|/* IPCP state: opened */
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
name|sppp_output
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
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|dst
parameter_list|,
name|struct
name|rtentry
modifier|*
name|rt
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
name|caddr_t
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

