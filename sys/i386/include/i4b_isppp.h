begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for synchronous PPP/Cisco link level subroutines.  *  * Copyright (C) 1994 Cronyx Ltd.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * Heavily revamped to conform to RFC 1661.  * Copyright (C) 1997, Joerg Wunsch.  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organizations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * From: Version 2.0, Fri Oct  6 20:39:21 MSK 1995  *  * From: if_sppp.h,v 1.14 1999/03/30 13:28:26 phk Exp  *  * $Id: i4b_isppp.h,v 1.5 2000/07/18 15:05:37 hm Exp $  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_ISPPP_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_ISPPP_H_
end_define

begin_define
define|#
directive|define
name|SPPP_VJ
end_define

begin_comment
comment|/* use VJ compression */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SPPP_VJ
end_ifdef

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * this is needed on FreeBSD to make /usr/src/usr.bin/kdump and  * /usr/src/usr.bin/truss compile.  */
end_comment

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<net/slcompress.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
define|#
directive|define
name|IPCP_MYADDR_SEEN
value|4
comment|/* have seen his address already */
define|#
directive|define
name|IPCP_VJ
value|8
comment|/* We can use VJ compression */
name|int
name|max_state
decl_stmt|;
comment|/* Max-Slot-Id */
name|int
name|compress_cid
decl_stmt|;
comment|/* Comp-Slot-Id */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AUTHNAMELEN
value|42
end_define

begin_define
define|#
directive|define
name|AUTHKEYLEN
value|16
end_define

begin_struct
struct|struct
name|sauth
block|{
name|u_short
name|proto
decl_stmt|;
comment|/* authentication protocol to use */
name|u_short
name|flags
decl_stmt|;
define|#
directive|define
name|AUTHFLAG_NOCALLOUT
value|1
comment|/* do not require authentication on */
comment|/* callouts */
define|#
directive|define
name|AUTHFLAG_NORECHALLENGE
value|2
comment|/* do not re-challenge CHAP */
name|u_char
name|name
index|[
name|AUTHNAMELEN
index|]
decl_stmt|;
comment|/* system identification name */
name|u_char
name|secret
index|[
name|AUTHKEYLEN
index|]
decl_stmt|;
comment|/* secret password */
name|u_char
name|challenge
index|[
name|AUTHKEYLEN
index|]
decl_stmt|;
comment|/* random challenge */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDX_PAP
value|2
end_define

begin_define
define|#
directive|define
name|IDX_CHAP
value|3
end_define

begin_define
define|#
directive|define
name|IDX_COUNT
value|(IDX_CHAP + 1)
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
name|pp_mode
decl_stmt|;
comment|/* major protocol modes (cisco/ppp/...) */
name|u_int
name|pp_flags
decl_stmt|;
comment|/* sub modes */
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
name|time_t
name|pp_last_sent
decl_stmt|;
name|time_t
name|pp_last_recv
decl_stmt|;
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
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
name|struct
name|callout_handle
name|ch
index|[
name|IDX_COUNT
index|]
decl_stmt|;
comment|/* per-proto and if callouts */
name|struct
name|callout_handle
name|pap_my_to_ch
decl_stmt|;
comment|/* PAP needs one more... */
endif|#
directive|endif
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
name|struct
name|sauth
name|myauth
decl_stmt|;
comment|/* auth params, i'm peer */
name|struct
name|sauth
name|hisauth
decl_stmt|;
comment|/* auth params, i'm authenticator */
ifdef|#
directive|ifdef
name|SPPP_VJ
name|int
name|enable_vj
decl_stmt|;
comment|/* enable VJ negotiation */
name|struct
name|slcompress
name|pp_comp
decl_stmt|;
comment|/* for VJ compression */
endif|#
directive|endif
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
comment|/* 	 * These (optional) functions may be filled by the hardware 	 * driver if any notification of established connections 	 * (currently: IPCP up) is desired (pp_con) or any internal 	 * state change of the interface state machine should be 	 * signaled for monitoring purposes (pp_chg). 	 */
name|void
function_decl|(
modifier|*
name|pp_con
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
name|pp_chg
function_decl|)
parameter_list|(
name|struct
name|sppp
modifier|*
name|sp
parameter_list|,
name|int
name|new_state
parameter_list|)
function_decl|;
comment|/* These two fields are for use by the lower layer */
name|void
modifier|*
name|pp_lowerp
decl_stmt|;
name|int
name|pp_loweri
decl_stmt|;
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
name|PP_CALLIN
value|0x08
end_define

begin_comment
comment|/* we are being called */
end_comment

begin_define
define|#
directive|define
name|PP_NEEDAUTH
value|0x10
end_define

begin_comment
comment|/* remote requested authentication */
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

begin_comment
comment|/*  * Definitions to pass struct sppp data down into the kernel using the  * SIOC[SG]IFGENERIC ioctl interface.  *  * In order to use this, create a struct spppreq, fill in the cmd  * field with SPPPIOGDEFS, and put the address of this structure into  * the ifr_data portion of a struct ifreq.  Pass this struct to a  * SIOCGIFGENERIC ioctl.  Then replace the cmd field by SPPPIOCDEFS,  * modify the defs field as desired, and pass the struct ifreq now  * to a SIOCSIFGENERIC ioctl.  */
end_comment

begin_define
define|#
directive|define
name|SPPPIOGDEFS
value|((caddr_t)(('S'<< 24) + (1<< 16) + sizeof(struct sppp)))
end_define

begin_define
define|#
directive|define
name|SPPPIOSDEFS
value|((caddr_t)(('S'<< 24) + (2<< 16) + sizeof(struct sppp)))
end_define

begin_struct
struct|struct
name|spppreq
block|{
name|u_long
name|cmd
decl_stmt|;
name|struct
name|sppp
name|defs
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCSIFGENERIC
end_ifndef

begin_define
define|#
directive|define
name|SIOCSIFGENERIC
value|_IOW('i', 57, struct ifreq)
end_define

begin_comment
comment|/* generic IF set op */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIOCGIFGENERIC
end_ifndef

begin_define
define|#
directive|define
name|SIOCGIFGENERIC
value|_IOWR('i', 58, struct ifreq)
end_define

begin_comment
comment|/* generic IF get op */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|USE_ISPPP
end_ifndef

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|300003
end_if

begin_function_decl
name|int
name|sppp_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|sppp_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
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
name|struct
name|mbuf
modifier|*
name|sppp_pick
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_ISPPP */
end_comment

begin_function_decl
name|void
name|isppp_attach
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
name|isppp_detach
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
name|isppp_input
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|300003
end_if

begin_function_decl
name|int
name|isppp_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_function_decl
name|int
name|isppp_ioctl
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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|isppp_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|void
modifier|*
name|data
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

begin_function_decl
name|struct
name|mbuf
modifier|*
name|isppp_dequeue
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|isppp_pick
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
name|isppp_isempty
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
name|isppp_flush
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

begin_comment
comment|/* USE_ISPPP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_ISPPP_H_ */
end_comment

end_unit

