begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) Dirk Husemann, Computer Science Department IV,  * 		 University of Erlangen-Nuremberg, Germany, 1990, 1991, 1992  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Dirk Husemann and the Computer Science Department (IV) of  * the University of Erlangen-Nuremberg, Germany.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)llc_var.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETCCITT_LLC_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETCCITT_LLC_VAR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/*  * Forward structure declarations for function prototypes [sic].  */
end_comment

begin_struct_decl
struct_decl|struct
name|llc
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NPAIDB_LINK
value|0
end_define

begin_struct
struct|struct
name|npaidbentry
block|{
union|union
block|{
comment|/* MAC,DLSAP -> CONS */
struct|struct
block|{
name|struct
name|llc_linkcb
modifier|*
name|NE_link
decl_stmt|;
name|struct
name|rtentry
modifier|*
name|NE_rt
decl_stmt|;
block|}
name|NE
struct|;
comment|/* SAP info for unconfigured incoming calls */
struct|struct
block|{
name|u_short
name|SI_class
decl_stmt|;
define|#
directive|define
name|LLC_CLASS_I
value|0x1
define|#
directive|define
name|LLC_CLASS_II
value|0x3
define|#
directive|define
name|LLC_CLASS_III
value|0x4
comment|/* Future */
define|#
directive|define
name|LLC_CLASS_IV
value|0x7
comment|/* Future */
name|u_short
name|SI_window
decl_stmt|;
name|u_short
name|SI_trace
decl_stmt|;
name|u_short
name|SI_xchxid
decl_stmt|;
name|void
argument_list|(
argument|*SI_input
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
expr_stmt|;
name|caddr_t
argument_list|(
argument|*SI_ctlinput
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
expr_stmt|;
block|}
name|SI
struct|;
block|}
name|NESIun
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|np_link
value|NESIun.NE.NE_link
end_define

begin_define
define|#
directive|define
name|np_rt
value|NESIun.NE.NE_rt
end_define

begin_define
define|#
directive|define
name|si_class
value|NESIun.SI.SI_class
end_define

begin_define
define|#
directive|define
name|si_window
value|NESIun.SI.SI_window
end_define

begin_define
define|#
directive|define
name|si_trace
value|NESIun.SI.SI_trace
end_define

begin_define
define|#
directive|define
name|si_xchxid
value|NESIun.SI.SI_xchxid
end_define

begin_define
define|#
directive|define
name|si_input
value|NESIun.SI.SI_input
end_define

begin_define
define|#
directive|define
name|si_ctlinput
value|NESIun.SI.SI_ctlinput
end_define

begin_define
define|#
directive|define
name|NPDL_SAPNETMASK
value|0x7e
end_define

begin_comment
comment|/*  * Definitions for accessing bitfields/bitslices inside  * LLC2 headers  */
end_comment

begin_struct
struct|struct
name|bitslice
block|{
name|unsigned
name|int
name|bs_mask
decl_stmt|;
name|unsigned
name|int
name|bs_shift
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_z
value|0
end_define

begin_define
define|#
directive|define
name|i_ns
value|1
end_define

begin_define
define|#
directive|define
name|i_pf
value|0
end_define

begin_define
define|#
directive|define
name|i_nr
value|1
end_define

begin_define
define|#
directive|define
name|s_oz
value|2
end_define

begin_define
define|#
directive|define
name|s_selector
value|3
end_define

begin_define
define|#
directive|define
name|s_pf
value|0
end_define

begin_define
define|#
directive|define
name|s_nr
value|1
end_define

begin_define
define|#
directive|define
name|u_bb
value|2
end_define

begin_define
define|#
directive|define
name|u_select_other
value|3
end_define

begin_define
define|#
directive|define
name|u_pf
value|4
end_define

begin_define
define|#
directive|define
name|u_select
value|5
end_define

begin_define
define|#
directive|define
name|f_vs
value|1
end_define

begin_define
define|#
directive|define
name|f_cr
value|0
end_define

begin_define
define|#
directive|define
name|f_vr
value|1
end_define

begin_define
define|#
directive|define
name|f_wxyzv
value|6
end_define

begin_define
define|#
directive|define
name|LLCGBITS
parameter_list|(
name|Arg
parameter_list|,
name|Index
parameter_list|)
value|(((Arg)& llc_bitslice[(Index)].bs_mask)>> llc_bitslice[(Index)].bs_shift)
end_define

begin_define
define|#
directive|define
name|LLCSBITS
parameter_list|(
name|Arg
parameter_list|,
name|Index
parameter_list|,
name|Val
parameter_list|)
value|(Arg) |= (((Val)<< llc_bitslice[(Index)].bs_shift)& llc_bitslice[(Index)].bs_mask)
end_define

begin_define
define|#
directive|define
name|LLCCSBITS
parameter_list|(
name|Arg
parameter_list|,
name|Index
parameter_list|,
name|Val
parameter_list|)
value|(Arg) = (((Val)<< llc_bitslice[(Index)].bs_shift)& llc_bitslice[(Index)].bs_mask)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|bitslice
name|llc_bitslice
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LLC_CMD
value|0
end_define

begin_define
define|#
directive|define
name|LLC_RSP
value|1
end_define

begin_define
define|#
directive|define
name|LLC_MAXCMDRSP
value|2
end_define

begin_comment
comment|/*  * LLC events --- These events may either be frames received from the  *                remote LLC DSAP, request from the network layer user,  *                timer events from llc_timer(), or diagnostic events from  *                llc_input().  */
end_comment

begin_comment
comment|/* LLC frame types */
end_comment

begin_define
define|#
directive|define
name|LLCFT_INFO
value|0 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_RR
value|1 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_RNR
value|2 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_REJ
value|3 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_DM
value|4 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_SABME
value|5 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_DISC
value|6 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_UA
value|7 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_FRMR
value|8 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_UI
value|9 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_XID
value|10 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_TEST
value|11 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/* LLC2 timer events */
end_comment

begin_define
define|#
directive|define
name|LLC_ACK_TIMER_EXPIRED
value|12 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLC_P_TIMER_EXPIRED
value|13 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLC_REJ_TIMER_EXPIRED
value|14 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLC_BUSY_TIMER_EXPIRED
value|15 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/* LLC2 diagnostic events */
end_comment

begin_define
define|#
directive|define
name|LLC_INVALID_NR
value|16 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLC_INVALID_NS
value|17 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLC_BAD_PDU
value|18 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLC_LOCAL_BUSY_DETECTED
value|19 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLC_LOCAL_BUSY_CLEARED
value|20 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/* Network layer user requests */
end_comment

begin_comment
comment|/*  * NL_CONNECT_REQUEST --- The user has requested that a data link connection  *                        be established with a remote LLC DSAP.  */
end_comment

begin_define
define|#
directive|define
name|NL_CONNECT_REQUEST
value|21 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/*  * NL_CONNECT_RESPONSE --- The user has accepted the data link connection.  */
end_comment

begin_define
define|#
directive|define
name|NL_CONNECT_RESPONSE
value|22 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/*  * NL_RESET_REQUEST --- The user has requested that the data link with the  *                      remote LLC DSAP be reset.  */
end_comment

begin_define
define|#
directive|define
name|NL_RESET_REQUEST
value|23 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/*  * NL_RESET_RESPONSE --- The user has accepted the reset of the data link  *                       connection.  */
end_comment

begin_define
define|#
directive|define
name|NL_RESET_RESPONSE
value|24 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/*  * NL_DISCONNECT_REQUEST --- The user has requested that the data link  *                           connection with remote LLC DSAP be terminated.  */
end_comment

begin_define
define|#
directive|define
name|NL_DISCONNECT_REQUEST
value|25 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/*  * NL_DATA_REQUEST --- The user has requested that a data unit be sent ot the  *                     remote LLC DSAP.  */
end_comment

begin_define
define|#
directive|define
name|NL_DATA_REQUEST
value|26 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/*  * NL_INITIATE_PF_CYCLE --- The local LLC wants to initiate a P/F cycle.  */
end_comment

begin_define
define|#
directive|define
name|NL_INITIATE_PF_CYCLE
value|27 * LLC_MAXCMDRSP
end_define

begin_comment
comment|/*  * NL_LOCAL_BUSY_DETECTED --- The local entity has encountered a busy condition  */
end_comment

begin_define
define|#
directive|define
name|NL_LOCAL_BUSY_DETECTED
value|28 * LLC_MAXCMDRSP
end_define

begin_define
define|#
directive|define
name|LLCFT_NONE
value|255
end_define

begin_comment
comment|/* return message from state handlers */
end_comment

begin_comment
comment|/*  * LLC_CONNECT_INDICATION --- Inform the user that a connection has been  *                            requested by a remote LLC SSAP.  */
end_comment

begin_define
define|#
directive|define
name|LLC_CONNECT_INDICATION
value|1
end_define

begin_comment
comment|/*  * LLC_CONNECT_CONFIRM --- The connection service component indicates that the  *                         remote network entity has accepted the connection.  */
end_comment

begin_define
define|#
directive|define
name|LLC_CONNECT_CONFIRM
value|2
end_define

begin_comment
comment|/*  * LLC_DISCONNECT_INDICATION --- Inform the user that the remote network  *                               entity has intiated disconnection of the data  *                               link connection.  */
end_comment

begin_define
define|#
directive|define
name|LLC_DISCONNECT_INDICATION
value|3
end_define

begin_comment
comment|/*  * LLC_RESET_CONFIRM --- The connection service component indicates that the  *                       remote network entity has accepted the reset.  */
end_comment

begin_define
define|#
directive|define
name|LLC_RESET_CONFIRM
value|4
end_define

begin_comment
comment|/*  * LLC_RESET_INDICATION_REMOTE --- The remote network entity or remote peer  *                                 has initiated a reset of the data link  *                                 connection.  */
end_comment

begin_define
define|#
directive|define
name|LLC_RESET_INDICATION_REMOTE
value|5
end_define

begin_comment
comment|/*  * LLC_RESET_INDICATION_LOCAL --- The local LLC has determined that the data  *                                link connection is in need of  *                                reinitialization.  */
end_comment

begin_define
define|#
directive|define
name|LLC_RESET_INDICATION_LOCAL
value|6
end_define

begin_comment
comment|/*  * LLC_FRMR_RECEIVED --- The local connection service component has received a  *                       FRMR response PDU.  */
end_comment

begin_define
define|#
directive|define
name|LLC_FRMR_RECEIVED
value|7
end_define

begin_comment
comment|/*  * LLC_FRMR_SENT --- The local connection component has received an ivalid  *                   PDU, and has sent a FRMR response PDU.  */
end_comment

begin_define
define|#
directive|define
name|LLC_FRMR_SENT
value|8
end_define

begin_comment
comment|/*  * LLC_DATA_INDICATION --- The connection service component passes the data  *                         unit from the received I PDU to the user.  */
end_comment

begin_define
define|#
directive|define
name|LLC_DATA_INDICATION
value|9
end_define

begin_comment
comment|/*  * LLC_REMOTE_NOT_BUSY --- The remote LLC DSAP is no longer busy. The local  *                         connection service component will now accept a  *                         DATA_REQUEST.  */
end_comment

begin_define
define|#
directive|define
name|LLC_REMOTE_NOT_BUSY
value|10
end_define

begin_comment
comment|/*  * LLC_REMOTE_BUSY --- The remote LLC DSAP is busy. The local connection  *                     service component will not accept a DATA_REQUEST.  */
end_comment

begin_define
define|#
directive|define
name|LLC_REMOTE_BUSY
value|11
end_define

begin_comment
comment|/* Internal return code */
end_comment

begin_define
define|#
directive|define
name|LLC_PASSITON
value|255
end_define

begin_define
define|#
directive|define
name|INFORMATION_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|SUPERVISORY_CONTROL
value|0x02
end_define

begin_define
define|#
directive|define
name|UNUMBERED_CONTROL
value|0x03
end_define

begin_comment
comment|/*  * Other necessary definitions  */
end_comment

begin_define
define|#
directive|define
name|LLC_MAX_SEQUENCE
value|128
end_define

begin_define
define|#
directive|define
name|LLC_MAX_WINDOW
value|127
end_define

begin_define
define|#
directive|define
name|LLC_WINDOW_SIZE
value|7
end_define

begin_comment
comment|/*  * Don't we love this one? CCITT likes to suck on bits 8=)  */
end_comment

begin_define
define|#
directive|define
name|NLHDRSIZEGUESS
value|3
end_define

begin_comment
comment|/*  * LLC control block  */
end_comment

begin_struct
struct|struct
name|llc_linkcb
block|{
struct|struct
name|llccb_q
block|{
name|struct
name|llccb_q
modifier|*
name|q_forw
decl_stmt|;
comment|/* admin chain */
name|struct
name|llccb_q
modifier|*
name|q_backw
decl_stmt|;
block|}
name|llcl_q
struct|;
name|struct
name|npaidbentry
modifier|*
name|llcl_sapinfo
decl_stmt|;
comment|/* SAP information */
name|struct
name|sockaddr_dl
name|llcl_addr
decl_stmt|;
comment|/* link snpa address */
name|struct
name|rtentry
modifier|*
name|llcl_nlrt
decl_stmt|;
comment|/* layer 3 -> LLC */
name|struct
name|rtentry
modifier|*
name|llcl_llrt
decl_stmt|;
comment|/* LLC -> layer 3 */
name|struct
name|ifnet
modifier|*
name|llcl_if
decl_stmt|;
comment|/* our interface */
name|caddr_t
name|llcl_nlnext
decl_stmt|;
comment|/* cb for network layer */
name|struct
name|mbuf
modifier|*
name|llcl_writeqh
decl_stmt|;
comment|/* Write queue head */
name|struct
name|mbuf
modifier|*
name|llcl_writeqt
decl_stmt|;
comment|/* Write queue tail */
name|struct
name|mbuf
modifier|*
modifier|*
name|llcl_output_buffers
decl_stmt|;
name|short
name|llcl_timers
index|[
literal|6
index|]
decl_stmt|;
comment|/* timer array */
name|long
name|llcl_timerflags
decl_stmt|;
comment|/* flags signalling running timers */
name|int
argument_list|(
argument|*llcl_statehandler
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
name|llcl_P_flag
decl_stmt|;
name|int
name|llcl_F_flag
decl_stmt|;
name|int
name|llcl_S_flag
decl_stmt|;
name|int
name|llcl_DATA_flag
decl_stmt|;
name|int
name|llcl_REMOTE_BUSY_flag
decl_stmt|;
name|int
name|llcl_DACTION_flag
decl_stmt|;
comment|/* delayed action */
name|int
name|llcl_retry
decl_stmt|;
comment|/* 	 * The following components deal --- in one way or the other --- 	 * with the LLC2 window. Indicated by either [L] or [W] is the 	 * domain of the specific component: 	 * 	 *        [L]    The domain is 0--LLC_MAX_WINDOW          *        [W]    The domain is 0--llcl_window 	 */
name|short
name|llcl_vr
decl_stmt|;
comment|/* next to receive [L] */
name|short
name|llcl_vs
decl_stmt|;
comment|/* next to send [L] */
name|short
name|llcl_nr_received
decl_stmt|;
comment|/* next frame to b ack'd [L] */
name|short
name|llcl_freeslot
decl_stmt|;
comment|/* next free slot [W] */
name|short
name|llcl_projvs
decl_stmt|;
comment|/* V(S) associated with freeslot */
name|short
name|llcl_slotsfree
decl_stmt|;
comment|/* free slots [W] */
name|short
name|llcl_window
decl_stmt|;
comment|/* window size */
comment|/* 	 * In llcl_frmrinfo we jot down the last frmr info field, which we 	 * need to do as we need to be able to resend it in the ERROR state. 	 */
name|struct
name|frmrinfo
name|llcl_frmrinfo
decl_stmt|;
comment|/* last FRMR info field */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|llcl_frmr_pdu0
value|llcl_frmrinfo.rej_pdu_0
end_define

begin_define
define|#
directive|define
name|llcl_frmr_pdu1
value|llcl_frmrinfo.rej_pdu_1
end_define

begin_define
define|#
directive|define
name|llcl_frmr_control
value|llcl_frmrinfo.frmr_control
end_define

begin_define
define|#
directive|define
name|llcl_frmr_control_ext
value|llcl_frmrinfo.frmr_control_ext
end_define

begin_define
define|#
directive|define
name|llcl_frmr_cause
value|llcl_frmrinfo.frmr_cause
end_define

begin_define
define|#
directive|define
name|LQNEXT
parameter_list|(
name|l
parameter_list|)
value|(struct llc_linkcb *)((l)->llcl_q.q_forw)
end_define

begin_define
define|#
directive|define
name|LQEMPTY
value|(llccb_q.q_forw ==&llccb_q)
end_define

begin_define
define|#
directive|define
name|LQFIRST
value|(struct llc_linkcb *)(llccb_q.q_forw)
end_define

begin_define
define|#
directive|define
name|LQVALID
parameter_list|(
name|l
parameter_list|)
value|(!((struct llccb_q *)(l) ==&llccb_q))
end_define

begin_define
define|#
directive|define
name|LLC_ENQUEUE
parameter_list|(
name|l
parameter_list|,
name|m
parameter_list|)
value|if ((l)->llcl_writeqh == NULL) { \ 				(l)->llcl_writeqh = (m); \ 				(l)->llcl_writeqt = (m); \ 			} else { \ 				(l)->llcl_writeqt->m_nextpkt = (m); \ 				(l)->llcl_writeqt = (m); \ 			}
end_define

begin_define
define|#
directive|define
name|LLC_DEQUEUE
parameter_list|(
name|l
parameter_list|,
name|m
parameter_list|)
value|if ((l)->llcl_writeqh == NULL) \                                 (m) = NULL; \                           else { \ 				(m) = (l)->llcl_writeqh; \ 				(l)->llcl_writeqh = (l)->llcl_writeqh->m_nextpkt; \ 			}
end_define

begin_define
define|#
directive|define
name|LLC_SETFRAME
parameter_list|(
name|l
parameter_list|,
name|m
parameter_list|)
value|{ \ 			        if ((l)->llcl_slotsfree> 0) { \ 				        (l)->llcl_slotsfree--; \ 					(l)->llcl_output_buffers[(l)->llcl_freeslot] = (m); \ 					(l)->llcl_freeslot = ((l)->llcl_freeslot+1) % (l)->llcl_window; \ 					LLC_INC((l)->llcl_projvs); \ 				} \ 		           }
end_define

begin_comment
comment|/*  * handling of sockaddr_dl's  */
end_comment

begin_define
define|#
directive|define
name|LLADDRLEN
parameter_list|(
name|s
parameter_list|)
value|((s)->sdl_alen + (s)->sdl_nlen)
end_define

begin_define
define|#
directive|define
name|LLSAPADDR
parameter_list|(
name|s
parameter_list|)
value|((s)->sdl_data[LLADDRLEN(s)-1]& 0xff)
end_define

begin_define
define|#
directive|define
name|LLSAPLOC
parameter_list|(
name|s
parameter_list|,
define|if) ((s)->sdl_nlen + (if)->if_addrlen)
end_define

begin_struct
struct|struct
name|sdl_hdr
block|{
name|struct
name|sockaddr_dl
name|sdlhdr_dst
decl_stmt|;
name|struct
name|sockaddr_dl
name|sdlhdr_src
decl_stmt|;
name|long
name|sdlhdr_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LLC_GETHDR
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|{ \ 				struct mbuf *_m = (struct mbuf *) (m); \ 				if (_m) { \ 					M_PREPEND(_m, LLC_ISFRAMELEN, M_DONTWAIT); \ 					bzero(mtod(_m, caddr_t), LLC_ISFRAMELEN); \ 				} else { \ 					MGETHDR (_m, M_DONTWAIT, MT_HEADER); \ 					if (_m != NULL) { \ 						_m->m_pkthdr.len = _m->m_len = LLC_UFRAMELEN; \ 						_m->m_next = _m->m_act = NULL; \ 						bzero(mtod(_m, caddr_t), LLC_UFRAMELEN); \ 					} else return; \ 				} \ 				(m) = _m; \ 				(f) = mtod(m, struct llc *); \ 		      }
end_define

begin_define
define|#
directive|define
name|LLC_NEWSTATE
parameter_list|(
name|l
parameter_list|,
name|LLCstate
parameter_list|)
value|(l)->llcl_statehandler = llc_state_##LLCstate
end_define

begin_define
define|#
directive|define
name|LLC_STATEEQ
parameter_list|(
name|l
parameter_list|,
name|LLCstate
parameter_list|)
value|((l)->llcl_statehandler == llc_state_##LLCstate ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|LLC_ACK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|LLC_P_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|LLC_BUSY_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|LLC_REJ_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|LLC_AGE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|LLC_DACTION_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|LLC_TIMER_NOTRUNNING
value|0
end_define

begin_define
define|#
directive|define
name|LLC_TIMER_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|LLC_TIMER_EXPIRED
value|2
end_define

begin_define
define|#
directive|define
name|LLC_STARTTIMER
parameter_list|(
name|l
parameter_list|,
name|LLCtimer
parameter_list|)
value|{ \ 				 (l)->llcl_timers[LLC_##LLCtimer##_SHIFT] = llc_##LLCtimer##_timer; \ 				 (l)->llcl_timerflags |= (1<<LLC_##LLCtimer##_SHIFT); \ 				 }
end_define

begin_define
define|#
directive|define
name|LLC_STOPTIMER
parameter_list|(
name|l
parameter_list|,
name|LLCtimer
parameter_list|)
value|{ \ 				 (l)->llcl_timers[LLC_##LLCtimer##_SHIFT] = 0; \ 				 (l)->llcl_timerflags&= ~(1<<LLC_##LLCtimer##_SHIFT); \ 				 }
end_define

begin_define
define|#
directive|define
name|LLC_AGETIMER
parameter_list|(
name|l
parameter_list|,
name|LLCtimer
parameter_list|)
value|if ((l)->llcl_timers[LLC_##LLCtimer##_SHIFT]> 0) \ 	                                  (l)->llcl_timers[LLC_##LLCtimer##_SHIFT]--;
end_define

begin_define
define|#
directive|define
name|LLC_TIMERXPIRED
parameter_list|(
name|l
parameter_list|,
name|LLCtimer
parameter_list|)
define|\
value|(((l)->llcl_timerflags& (1<<LLC_##LLCtimer##_SHIFT)) ? \ 	 (((l)->llcl_timers[LLC_##LLCtimer##_SHIFT] == 0 ) ? \ 	  LLC_TIMER_EXPIRED : LLC_TIMER_RUNNING) : LLC_TIMER_NOTRUNNING)
end_define

begin_define
define|#
directive|define
name|FOR_ALL_LLC_TIMERS
parameter_list|(
name|t
parameter_list|)
value|for ((t) = LLC_ACK_SHIFT; (t)< LLC_AGE_SHIFT; (t)++)
end_define

begin_define
define|#
directive|define
name|LLC_SETFLAG
parameter_list|(
name|l
parameter_list|,
name|LLCflag
parameter_list|,
name|v
parameter_list|)
value|(l)->llcl_##LLCflag##_flag = (v)
end_define

begin_define
define|#
directive|define
name|LLC_GETFLAG
parameter_list|(
name|l
parameter_list|,
name|LLCflag
parameter_list|)
value|(l)->llcl_##LLCflag##_flag
end_define

begin_define
define|#
directive|define
name|LLC_RESETCOUNTER
parameter_list|(
name|l
parameter_list|)
value|{ \ 				      (l)->llcl_vs = (l)->llcl_vr = (l)->llcl_retry = 0; \ 				      llc_resetwindow((l)); \ 			      }
end_define

begin_comment
comment|/*  * LLC2 macro definitions  */
end_comment

begin_define
define|#
directive|define
name|LLC_START_ACK_TIMER
parameter_list|(
name|l
parameter_list|)
value|LLC_STARTTIMER((l), ACK)
end_define

begin_define
define|#
directive|define
name|LLC_STOP_ACK_TIMER
parameter_list|(
name|l
parameter_list|)
value|LLC_STOPTIMER((l), ACK)
end_define

begin_define
define|#
directive|define
name|LLC_START_REJ_TIMER
parameter_list|(
name|l
parameter_list|)
value|LLC_STARTTIMER((l), REJ)
end_define

begin_define
define|#
directive|define
name|LLC_STOP_REJ_TIMER
parameter_list|(
name|l
parameter_list|)
value|LLC_STOPTIMER((l), REJ)
end_define

begin_define
define|#
directive|define
name|LLC_START_P_TIMER
parameter_list|(
name|l
parameter_list|)
value|{ \ 				      LLC_STARTTIMER((l), P); \ 				      if (LLC_GETFLAG((l), P) == 0) \ 					      (l)->llcl_retry = 0; \ 				      LLC_SETFLAG((l), P, 1); \ 			     }
end_define

begin_define
define|#
directive|define
name|LLC_STOP_P_TIMER
parameter_list|(
name|l
parameter_list|)
value|{ \ 				      LLC_STOPTIMER((l), P); \ 				      LLC_SETFLAG((l), P, 0); \ 			    }
end_define

begin_define
define|#
directive|define
name|LLC_STOP_ALL_TIMERS
parameter_list|(
name|l
parameter_list|)
value|{ \ 				      LLC_STOPTIMER((l), ACK); \ 				      LLC_STOPTIMER((l), REJ); \ 				      LLC_STOPTIMER((l), BUSY); \ 				      LLC_STOPTIMER((l), P); \ 			    }
end_define

begin_define
define|#
directive|define
name|LLC_INC
parameter_list|(
name|i
parameter_list|)
value|(i) = ((i)+1) % LLC_MAX_SEQUENCE
end_define

begin_define
define|#
directive|define
name|LLC_NR_VALID
parameter_list|(
name|l
parameter_list|,
name|nr
parameter_list|)
value|((l)->llcl_vs< (l)->llcl_nr_received ? \ 	                             (((nr)>= (l)->llcl_nr_received) || \ 	                              ((nr)<= (l)->llcl_vs) ? 1 : 0) : \ 	                             (((nr)<= (l)->llcl_vs)&& \ 	                              ((nr)>= (l)->llcl_nr_received) ? 1 : 0))
end_define

begin_define
define|#
directive|define
name|LLC_UPDATE_P_FLAG
parameter_list|(
name|l
parameter_list|,
name|cr
parameter_list|,
name|pf
parameter_list|)
value|{ \ 			   if ((cr) == LLC_RSP&& (pf) == 1) { \ 			           LLC_SETFLAG((l), P, 0); \ 				   LLC_STOPTIMER((l), P); \ 			    } \ 			    }
end_define

begin_define
define|#
directive|define
name|LLC_UPDATE_NR_RECEIVED
parameter_list|(
name|l
parameter_list|,
name|nr
parameter_list|)
value|{ \ 			    while ((l)->llcl_nr_received != (nr)) { \ 				    struct mbuf *_m; \ 				    register short seq; \ 				    if (_m = (l)->llcl_output_buffers[seq = llc_seq2slot((l), (l)->llcl_nr_received)]) \ 					    m_freem(_m); \ 				    (l)->llcl_output_buffers[seq] = NULL; \ 				    LLC_INC((l)->llcl_nr_received); \ 				    (l)->llcl_slotsfree++; \ 			    } \ 			    (l)->llcl_retry = 0; \ 			    if ((l)->llcl_slotsfree< (l)->llcl_window) { \ 				    LLC_START_ACK_TIMER(l); \ 			    } else LLC_STOP_ACK_TIMER(l); \ 			    LLC_STARTTIMER((l), DACTION); \ 			    }
end_define

begin_define
define|#
directive|define
name|LLC_SET_REMOTE_BUSY
parameter_list|(
name|l
parameter_list|,
name|a
parameter_list|)
value|{ \ 			    if (LLC_GETFLAG((l), REMOTE_BUSY) == 0) { \ 				    LLC_SETFLAG((l), REMOTE_BUSY, 1); \ 				    LLC_STARTTIMER((l), BUSY); \ 				    (a) = LLC_REMOTE_BUSY; \ 			    } else { \ 				    (a) = 0; \ 			    } \ 			    }
end_define

begin_define
define|#
directive|define
name|LLC_CLEAR_REMOTE_BUSY
parameter_list|(
name|l
parameter_list|,
name|a
parameter_list|)
value|{ \ 			    if (LLC_GETFLAG((l), REMOTE_BUSY) == 1) { \ 				    LLC_SETFLAG((l), REMOTE_BUSY, 1); \ 				    LLC_STOPTIMER((l), BUSY); \ 				    if (LLC_STATEEQ((l), NORMAL) || \ 					LLC_STATEEQ((l), REJECT) || \ 					LLC_STATEEQ((l), BUSY)) \ 						llc_resend((l), LLC_CMD, 0); \ 				    (a) = LLC_REMOTE_NOT_BUSY; \ 			    } else { \ 				    (a) = 0; \ 			    } \ 			    }
end_define

begin_define
define|#
directive|define
name|LLC_DACKCMD
value|0x1
end_define

begin_define
define|#
directive|define
name|LLC_DACKCMDPOLL
value|0x2
end_define

begin_define
define|#
directive|define
name|LLC_DACKRSP
value|0x3
end_define

begin_define
define|#
directive|define
name|LLC_DACKRSPFINAL
value|0x4
end_define

begin_define
define|#
directive|define
name|LLC_SENDACKNOWLEDGE
parameter_list|(
name|l
parameter_list|,
name|cmd
parameter_list|,
name|pf
parameter_list|)
value|{ \ 			   if ((cmd) == LLC_CMD) { \ 				   LLC_SETFLAG((l), DACTION, ((pf) == 0 ? LLC_DACKCMD : LLC_DACKCMDPOLL)); \ 			   } else { \ 				   LLC_SETFLAG((l), DACTION, ((pf) == 0 ? LLC_DACKRSP : LLC_DACKRSPFINAL)); \ 			   } \ 		   }
end_define

begin_define
define|#
directive|define
name|LLC_FRMR_W
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|LLC_FRMR_X
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|LLC_FRMR_Y
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|LLC_FRMR_Z
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|LLC_FRMR_V
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|LLC_SETFRMR
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|,
name|cr
parameter_list|,
name|c
parameter_list|)
value|{ \ 			   if ((f)->llc_control& 0x3) { \ 				   (l)->llcl_frmr_pdu0 = (f)->llc_control; \ 				   (l)->llcl_frmr_pdu1 = 0; \ 			   } else { \ 				   (l)->llcl_frmr_pdu0 = (f)->llc_control; \ 				   (l)->llcl_frmr_pdu1 = (f)->llc_control_ext; \ 			   } \ 			   LLCCSBITS((l)->llcl_frmr_control, f_vs, (l)->llcl_vs); \ 			   LLCCSBITS((l)->llcl_frmr_control_ext, f_cr, (cr)); \ 			   LLCSBITS((l)->llcl_frmr_control_ext, f_vr, (l)->llcl_vr); \ 			   LLCCSBITS((l)->llcl_frmr_cause, f_wxyzv, (c)); \ 			}
end_define

begin_comment
comment|/*  * LLC tracing levels:  *     LLCTR_INTERESTING        interesting event, we might care to know about  *                              it, but then again, we might not ...  *     LLCTR_SHOULDKNOW         we probably should know about this event  *     LLCTR_URGENT             something has gone utterly wrong ...  */
end_comment

begin_define
define|#
directive|define
name|LLCTR_INTERESTING
value|1
end_define

begin_define
define|#
directive|define
name|LLCTR_SHOULDKNOW
value|2
end_define

begin_define
define|#
directive|define
name|LLCTR_URGENT
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LLCDEBUG
end_ifdef

begin_define
define|#
directive|define
name|LLC_TRACE
parameter_list|(
name|lp
parameter_list|,
name|l
parameter_list|,
name|msg
parameter_list|)
value|llc_trace((lp), (l), (msg))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LLCDEBUG */
end_comment

begin_define
define|#
directive|define
name|LLC_TRACE
parameter_list|(
name|lp
parameter_list|,
name|l
parameter_list|,
name|msg
parameter_list|)
end_define

begin_comment
comment|/* NOOP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLCDEBUG */
end_comment

begin_define
define|#
directive|define
name|LLC_N2_VALUE
value|15
end_define

begin_comment
comment|/* up to 15 retries */
end_comment

begin_define
define|#
directive|define
name|LLC_ACK_TIMER
value|10
end_define

begin_comment
comment|/*  5 secs */
end_comment

begin_define
define|#
directive|define
name|LLC_P_TIMER
value|4
end_define

begin_comment
comment|/*  2 secs */
end_comment

begin_define
define|#
directive|define
name|LLC_BUSY_TIMER
value|12
end_define

begin_comment
comment|/*  6 secs */
end_comment

begin_define
define|#
directive|define
name|LLC_REJ_TIMER
value|12
end_define

begin_comment
comment|/*  6 secs */
end_comment

begin_define
define|#
directive|define
name|LLC_AGE_TIMER
value|40
end_define

begin_comment
comment|/* 20 secs */
end_comment

begin_define
define|#
directive|define
name|LLC_DACTION_TIMER
value|2
end_define

begin_comment
comment|/*  1 secs */
end_comment

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
name|LLC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|llc_n2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|llc_ACK_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|llc_P_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|llc_REJ_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|llc_BUSY_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|llc_AGE_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|llc_DACTION_timer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|af_link_rts_init_done
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USES_AF_LINK_RTS
value|{ \ 	if (!af_link_rts_init_done) { \ 	       rn_inithead((void **)&rt_tables[AF_LINK], 32); \ 	       af_link_rts_init_done++; \ 	       } \ 	 }
end_define

begin_decl_stmt
name|struct
name|ifqueue
name|llcintrq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|llccb_q
name|llccb_q
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|frame_names
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
name|int
name|sdl_cmp
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
operator|,
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sdl_copy
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
operator|,
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sdl_swapaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
operator|,
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sdl_checkaddrif
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sdl_setaddrif
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_char
operator|,
name|u_char
operator|,
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sdl_sethdrif
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_char
operator|,
name|u_char
operator|*
operator|,
name|u_char
operator|,
name|u_char
operator|,
expr|struct
name|sdl_hdr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|npaidbentry
modifier|*
name|llc_setsapinfo
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|u_char
operator|,
name|u_char
operator|,
expr|struct
name|dllconfig
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|npaidbentry
modifier|*
name|llc_getsapinfo
name|__P
argument_list|(
operator|(
name|u_char
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|rtentry
modifier|*
name|npaidb_enrich
name|__P
argument_list|(
operator|(
name|short
operator|,
name|caddr_t
operator|,
expr|struct
name|sockaddr_dl
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|npaidb_destroy
name|__P
argument_list|(
operator|(
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|llc_seq2slot
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
name|short
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_ADM
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_CONN
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_RESET_WAIT
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_RESET_CHECK
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_SETUP
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_RESET
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_D_CONN
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_ERROR
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_NBRAcore
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_NORMAL
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_BUSY
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_REJECT
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_AWAIT
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_AWAIT_BUSY
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_state_AWAIT_REJECT
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_statehandler
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|llc_linkcb
modifier|*
name|llc_newlink
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr_dl
operator|*
operator|,
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|,
name|caddr_t
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_dellink
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_anytimersup
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|llc_getstatename
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|llc_link_dump
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|llc_trace
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|llc_resetwindow
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_decode
name|__P
argument_list|(
operator|(
expr|struct
name|llc
operator|*
operator|,
expr|struct
name|llc_linkcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|llc_timer
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|llcintr
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_input
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|u_char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|llc_ctlinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_output
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|llc_start
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_send
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_resend
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|llc_rawsend
name|__P
argument_list|(
operator|(
expr|struct
name|llc_linkcb
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|llc
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cons_rtrequest
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|rtentry
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x25_llcglue
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
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

