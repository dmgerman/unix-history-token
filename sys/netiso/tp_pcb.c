begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_pcb.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*********************************************************** 				Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_pcb.c,v $  *  *  * This is the initialization and cleanup stuff -  * for the tp machine in general as well as  for the individual pcbs.  * tp_init() is called at system startup.  tp_attach() and tp_getref() are  * called when a socket is created.  tp_detach() and tp_freeref()  * are called during the closing stage and/or when the reference timer  * goes off.  * tp_soisdisconnecting() and tp_soisdisconnected() are tp-specific  * versions of soisconnect*  * and are called (obviously) during the closing phase.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<netiso/argo_debug.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_param.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_timer.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_ip.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_stat.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_tpdu.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_trace.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_meas.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_seq.h>
end_include

begin_include
include|#
directive|include
file|<netiso/tp_clnp.h>
end_include

begin_comment
comment|/* ticks are in units of:  * 500 nano-fortnights ;-) or  * 500 ms or  * 1/2 second  */
end_comment

begin_decl_stmt
name|struct
name|tp_conn_param
name|tp_conn_param
index|[]
init|=
block|{
comment|/* ISO_CLNS: TP4 CONNECTION LESS */
block|{
name|TP_NRETRANS
block|,
comment|/* short p_Nretrans;  */
literal|20
block|,
comment|/* 10 sec */
comment|/* short p_dr_ticks;  */
literal|20
block|,
comment|/* 10 sec */
comment|/* short p_cc_ticks; */
literal|20
block|,
comment|/* 10 sec */
comment|/* short p_dt_ticks; */
literal|40
block|,
comment|/* 20 sec */
comment|/* short p_x_ticks;	 */
literal|80
block|,
comment|/* 40 sec */
comment|/* short p_cr_ticks;*/
literal|240
block|,
comment|/* 2 min */
comment|/* short p_keepalive_ticks;*/
literal|10
block|,
comment|/* 5 sec */
comment|/* short p_sendack_ticks;  */
literal|600
block|,
comment|/* 5 min */
comment|/* short p_ref_ticks;	*/
literal|360
block|,
comment|/* 3 min */
comment|/* short p_inact_ticks;	*/
operator|(
name|short
operator|)
literal|100
block|,
comment|/* short p_lcdtfract */
operator|(
name|short
operator|)
name|TP_SOCKBUFSIZE
block|,
comment|/* short p_winsize */
name|TP_TPDUSIZE
block|,
comment|/* u_char p_tpdusize */
name|TPACK_WINDOW
block|,
comment|/* 4 bits p_ack_strat */
name|TPRX_USE_CW
operator||
name|TPRX_FASTSTART
block|,
comment|/* 4 bits p_rx_strat*/
name|TP_CLASS_4
operator||
name|TP_CLASS_0
block|,
comment|/* 5 bits p_class */
literal|1
block|,
comment|/* 1 bit xtd format */
literal|1
block|,
comment|/* 1 bit xpd service */
literal|1
block|,
comment|/* 1 bit use_checksum */
literal|0
block|,
comment|/* 1 bit use net xpd */
literal|0
block|,
comment|/* 1 bit use rcc */
literal|0
block|,
comment|/* 1 bit use efc */
literal|1
block|,
comment|/* no disc indications */
literal|0
block|,
comment|/* don't change params */
name|ISO_CLNS
block|,
comment|/* p_netservice */
block|}
block|,
comment|/* IN_CLNS: TP4 CONNECTION LESS */
block|{
name|TP_NRETRANS
block|,
comment|/* short p_Nretrans;  */
literal|20
block|,
comment|/* 10 sec */
comment|/* short p_dr_ticks;  */
literal|20
block|,
comment|/* 10 sec */
comment|/* short p_cc_ticks; */
literal|20
block|,
comment|/* 10 sec */
comment|/* short p_dt_ticks; */
literal|40
block|,
comment|/* 20 sec */
comment|/* short p_x_ticks;	 */
literal|80
block|,
comment|/* 40 sec */
comment|/* short p_cr_ticks;*/
literal|240
block|,
comment|/* 2 min */
comment|/* short p_keepalive_ticks;*/
literal|10
block|,
comment|/* 5 sec */
comment|/* short p_sendack_ticks;  */
literal|600
block|,
comment|/* 5 min */
comment|/* short p_ref_ticks;	*/
literal|360
block|,
comment|/* 3 min */
comment|/* short p_inact_ticks;	*/
operator|(
name|short
operator|)
literal|100
block|,
comment|/* short p_lcdtfract */
operator|(
name|short
operator|)
name|TP_SOCKBUFSIZE
block|,
comment|/* short p_winsize */
name|TP_TPDUSIZE
block|,
comment|/* u_char p_tpdusize */
name|TPACK_WINDOW
block|,
comment|/* 4 bits p_ack_strat */
name|TPRX_USE_CW
operator||
name|TPRX_FASTSTART
block|,
comment|/* 4 bits p_rx_strat*/
name|TP_CLASS_4
block|,
comment|/* 5 bits p_class */
literal|1
block|,
comment|/* 1 bit xtd format */
literal|1
block|,
comment|/* 1 bit xpd service */
literal|1
block|,
comment|/* 1 bit use_checksum */
literal|0
block|,
comment|/* 1 bit use net xpd */
literal|0
block|,
comment|/* 1 bit use rcc */
literal|0
block|,
comment|/* 1 bit use efc */
literal|1
block|,
comment|/* no disc indications */
literal|0
block|,
comment|/* don't change params */
name|IN_CLNS
block|,
comment|/* p_netservice */
block|}
block|,
comment|/* ISO_CONS: TP0 CONNECTION MODE */
block|{
name|TP_NRETRANS
block|,
comment|/* short p_Nretrans;  */
literal|0
block|,
comment|/* n/a */
comment|/* short p_dr_ticks; */
literal|40
block|,
comment|/* 20 sec */
comment|/* short p_cc_ticks; */
literal|0
block|,
comment|/* n/a */
comment|/* short p_dt_ticks; */
literal|0
block|,
comment|/* n/a */
comment|/* short p_x_ticks;	*/
literal|360
block|,
comment|/* 3  min */
comment|/* short p_cr_ticks;*/
literal|0
block|,
comment|/* n/a */
comment|/* short p_keepalive_ticks;*/
literal|0
block|,
comment|/* n/a */
comment|/* short p_sendack_ticks; */
literal|600
block|,
comment|/* for cr/cc to clear */
comment|/* short p_ref_ticks;	*/
literal|0
block|,
comment|/* n/a */
comment|/* short p_inact_ticks;	*/
comment|/* Use tp4 defaults just in case the user changes ONLY 		 * the class 		 */
operator|(
name|short
operator|)
literal|100
block|,
comment|/* short p_lcdtfract */
operator|(
name|short
operator|)
name|TP0_SOCKBUFSIZE
block|,
comment|/* short p_winsize */
name|TP0_TPDUSIZE
block|,
comment|/* 8 bits p_tpdusize */
literal|0
block|,
comment|/* 4 bits p_ack_strat */
literal|0
block|,
comment|/* 4 bits p_rx_strat*/
name|TP_CLASS_0
block|,
comment|/* 5 bits p_class */
literal|0
block|,
comment|/* 1 bit xtd format */
literal|0
block|,
comment|/* 1 bit xpd service */
literal|0
block|,
comment|/* 1 bit use_checksum */
literal|0
block|,
comment|/* 1 bit use net xpd */
literal|0
block|,
comment|/* 1 bit use rcc */
literal|0
block|,
comment|/* 1 bit use efc */
literal|0
block|,
comment|/* no disc indications */
literal|0
block|,
comment|/* don't change params */
name|ISO_CONS
block|,
comment|/* p_netservice */
block|}
block|,
comment|/* ISO_COSNS: TP4 CONNECTION LESS SERVICE over CONSNS */
block|{
name|TP_NRETRANS
block|,
comment|/* short p_Nretrans;  */
literal|40
block|,
comment|/* 20 sec */
comment|/* short p_dr_ticks;  */
literal|40
block|,
comment|/* 20 sec */
comment|/* short p_cc_ticks; */
literal|80
block|,
comment|/* 40 sec */
comment|/* short p_dt_ticks; */
literal|120
block|,
comment|/* 1 min */
comment|/* short p_x_ticks;	 */
literal|360
block|,
comment|/* 3 min */
comment|/* short p_cr_ticks;*/
literal|360
block|,
comment|/* 3 min */
comment|/* short p_keepalive_ticks;*/
literal|20
block|,
comment|/* 10 sec */
comment|/* short p_sendack_ticks;  */
literal|600
block|,
comment|/* 5 min */
comment|/* short p_ref_ticks;	*/
literal|480
block|,
comment|/* 4 min */
comment|/* short p_inact_ticks;	*/
operator|(
name|short
operator|)
literal|100
block|,
comment|/* short p_lcdtfract */
operator|(
name|short
operator|)
name|TP0_SOCKBUFSIZE
block|,
comment|/* short p_winsize */
name|TP0_TPDUSIZE
block|,
comment|/* u_char p_tpdusize */
name|TPACK_WINDOW
block|,
comment|/* 4 bits p_ack_strat */
name|TPRX_USE_CW
block|,
comment|/* No fast start */
comment|/* 4 bits p_rx_strat*/
name|TP_CLASS_4
operator||
name|TP_CLASS_0
block|,
comment|/* 5 bits p_class */
literal|0
block|,
comment|/* 1 bit xtd format */
literal|1
block|,
comment|/* 1 bit xpd service */
literal|1
block|,
comment|/* 1 bit use_checksum */
literal|0
block|,
comment|/* 1 bit use net xpd */
literal|0
block|,
comment|/* 1 bit use rcc */
literal|0
block|,
comment|/* 1 bit use efc */
literal|0
block|,
comment|/* no disc indications */
literal|0
block|,
comment|/* don't change params */
name|ISO_COSNS
block|,
comment|/* p_netservice */
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_function_decl
name|int
name|in_putnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_getnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_cmpnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_putsufx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_getsufx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_recycle_tsuffix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpip_mtu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbbind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|in_pcbconnect
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX these are now declared as returning void in<netinet/in_pcb.h>. */
end_comment

begin_endif
unit|int 	in_pcbdisconnect(); int 	in_pcbdetach();
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|in_pcballoc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpip_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpip_output_dg
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|inpcb
name|tp_inpcb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISO
end_ifdef

begin_function_decl
name|int
name|iso_putnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_getnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_cmpnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_putsufx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_getsufx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_recycle_tsuffix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpclnp_mtu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcbbind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcbconnect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcbdisconnect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcbdetach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcballoc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpclnp_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpclnp_output_dg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_nlctloutput
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|isopcb
name|tp_isopcb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TPCONS
end_ifdef

begin_function_decl
name|int
name|iso_putnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_getnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_cmpnetaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_putsufx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_getsufx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_recycle_tsuffix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcbbind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpcons_pcbconnect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpclnp_mtu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcbdisconnect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcbdetach
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iso_pcballoc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tpcons_output
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|isopcb
name|tp_isopcb
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TPCONS */
end_comment

begin_decl_stmt
name|struct
name|nl_protosw
name|nl_protosw
index|[]
init|=
block|{
comment|/* ISO_CLNS */
ifdef|#
directive|ifdef
name|ISO
block|{
name|AF_ISO
block|,
name|iso_putnetaddr
block|,
name|iso_getnetaddr
block|,
name|iso_cmpnetaddr
block|,
name|iso_putsufx
block|,
name|iso_getsufx
block|,
name|iso_recycle_tsuffix
block|,
name|tpclnp_mtu
block|,
name|iso_pcbbind
block|,
name|iso_pcbconnect
block|,
name|iso_pcbdisconnect
block|,
name|iso_pcbdetach
block|,
name|iso_pcballoc
block|,
name|tpclnp_output
block|,
name|tpclnp_output_dg
block|,
name|iso_nlctloutput
block|,
operator|(
name|caddr_t
operator|)
operator|&
name|tp_isopcb
block|, 		}
block|,
else|#
directive|else
block|{
literal|0
block|}
block|,
endif|#
directive|endif
comment|/* ISO */
comment|/* IN_CLNS */
ifdef|#
directive|ifdef
name|INET
block|{
name|AF_INET
block|,
name|in_putnetaddr
block|,
name|in_getnetaddr
block|,
name|in_cmpnetaddr
block|,
name|in_putsufx
block|,
name|in_getsufx
block|,
name|in_recycle_tsuffix
block|,
name|tpip_mtu
block|,
name|in_pcbbind
block|,
name|in_pcbconnect
block|,
name|in_pcbdisconnect
block|,
name|in_pcbdetach
block|,
name|in_pcballoc
block|,
name|tpip_output
block|,
name|tpip_output_dg
block|,
comment|/* nl_ctloutput */
name|NULL
block|,
operator|(
name|caddr_t
operator|)
operator|&
name|tp_inpcb
block|, 		}
block|,
else|#
directive|else
block|{
literal|0
block|}
block|,
endif|#
directive|endif
comment|/* INET */
comment|/* ISO_CONS */
if|#
directive|if
name|defined
argument_list|(
name|ISO
argument_list|)
operator|&&
name|defined
argument_list|(
name|TPCONS
argument_list|)
block|{
name|AF_ISO
block|,
name|iso_putnetaddr
block|,
name|iso_getnetaddr
block|,
name|iso_cmpnetaddr
block|,
name|iso_putsufx
block|,
name|iso_getsufx
block|,
name|iso_recycle_tsuffix
block|,
name|tpclnp_mtu
block|,
name|iso_pcbbind
block|,
name|tpcons_pcbconnect
block|,
name|iso_pcbdisconnect
block|,
name|iso_pcbdetach
block|,
name|iso_pcballoc
block|,
name|tpcons_output
block|,
name|tpcons_output
block|,
name|iso_nlctloutput
block|,
operator|(
name|caddr_t
operator|)
operator|&
name|tp_isopcb
block|, 		}
block|,
else|#
directive|else
block|{
literal|0
block|}
block|,
endif|#
directive|endif
comment|/* ISO_CONS */
comment|/* End of protosw marker */
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|tp_sendspace
init|=
literal|1024
operator|*
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|tp_recvspace
init|=
literal|1024
operator|*
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * NAME:  tp_init()  *  * CALLED FROM:  *  autoconf through the protosw structure  *  * FUNCTION:  *  initialize tp machine  *  * RETURNS:  Nada  *  * SIDE EFFECTS:  *  * NOTES:  */
end_comment

begin_function
name|int
name|tp_init
parameter_list|()
block|{
specifier|static
name|int
name|init_done
init|=
literal|0
decl_stmt|;
name|void
name|tp_timerinit
parameter_list|()
function_decl|;
if|if
condition|(
name|init_done
operator|++
condition|)
return|return
literal|0
return|;
comment|/* FOR INET */
name|tp_inpcb
operator|.
name|inp_next
operator|=
name|tp_inpcb
operator|.
name|inp_prev
operator|=
operator|&
name|tp_inpcb
expr_stmt|;
comment|/* FOR ISO */
name|tp_isopcb
operator|.
name|isop_next
operator|=
name|tp_isopcb
operator|.
name|isop_prev
operator|=
operator|&
name|tp_isopcb
expr_stmt|;
name|tp_start_win
operator|=
literal|2
expr_stmt|;
name|tp_timerinit
argument_list|()
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|tp_stat
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_stat
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * NAME: 	tp_soisdisconnecting()  *  * CALLED FROM:  *  tp.trans  *  * FUNCTION and ARGUMENTS:  *  Set state of the socket (so) to reflect that fact that we're disconnectING  *  * RETURNS: 	Nada  *  * SIDE EFFECTS:  *  * NOTES:  *  This differs from the regular soisdisconnecting() in that the latter  *  also sets the SS_CANTRECVMORE and SS_CANTSENDMORE flags.  *  We don't want to set those flags because those flags will cause  *  a SIGPIPE to be delivered in sosend() and we don't like that.  *  If anyone else is sleeping on this socket, wake 'em up.  */
end_comment

begin_function
name|void
name|tp_soisdisconnecting
parameter_list|(
name|so
parameter_list|)
specifier|register
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
block|{
name|soisdisconnecting
argument_list|(
name|so
argument_list|)
expr_stmt|;
name|so
operator|->
name|so_state
operator|&=
operator|~
name|SS_CANTSENDMORE
expr_stmt|;
name|IFPERF
argument_list|(
name|sototpcb
argument_list|(
name|so
argument_list|)
argument_list|)
specifier|register
expr|struct
name|tp_pcb
operator|*
name|tpcb
operator|=
name|sototpcb
argument_list|(
name|so
argument_list|)
expr_stmt|;
name|u_int
name|fsufx
decl_stmt|,
name|lsufx
decl_stmt|;
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|tpcb
operator|->
name|tp_fsuffix
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|fsufx
argument_list|,
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|tpcb
operator|->
name|tp_lsuffix
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|lsufx
argument_list|,
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
argument_list|)
expr_stmt|;
name|tpmeas
argument_list|(
name|tpcb
operator|->
name|tp_lref
argument_list|,
name|TPtime_close
argument_list|,
operator|&
name|time
argument_list|,
name|fsufx
argument_list|,
name|lsufx
argument_list|,
name|tpcb
operator|->
name|tp_fref
argument_list|)
expr_stmt|;
name|tpcb
operator|->
name|tp_perf_on
operator|=
literal|0
expr_stmt|;
comment|/* turn perf off */
name|ENDPERF
block|}
end_function

begin_comment
comment|/*  * NAME: tp_soisdisconnected()  *  * CALLED FROM:  *	tp.trans  *  * FUNCTION and ARGUMENTS:  *  Set state of the socket (so) to reflect that fact that we're disconnectED  *  Set the state of the reference structure to closed, and  *  recycle the suffix.  *  Start a reference timer.  *  * RETURNS:	Nada  *  * SIDE EFFECTS:  *  * NOTES:  *  This differs from the regular soisdisconnected() in that the latter  *  also sets the SS_CANTRECVMORE and SS_CANTSENDMORE flags.  *  We don't want to set those flags because those flags will cause  *  a SIGPIPE to be delivered in sosend() and we don't like that.  *  If anyone else is sleeping on this socket, wake 'em up.  */
end_comment

begin_function
name|void
name|tp_soisdisconnected
parameter_list|(
name|tpcb
parameter_list|)
specifier|register
name|struct
name|tp_pcb
modifier|*
name|tpcb
decl_stmt|;
block|{
specifier|register
name|struct
name|socket
modifier|*
name|so
init|=
name|tpcb
operator|->
name|tp_sock
decl_stmt|;
name|soisdisconnecting
argument_list|(
name|so
argument_list|)
expr_stmt|;
name|so
operator|->
name|so_state
operator|&=
operator|~
name|SS_CANTSENDMORE
expr_stmt|;
name|IFPERF
argument_list|(
name|tpcb
argument_list|)
specifier|register
expr|struct
name|tp_pcb
operator|*
name|ttpcb
operator|=
name|sototpcb
argument_list|(
name|so
argument_list|)
expr_stmt|;
name|u_int
name|fsufx
decl_stmt|,
name|lsufx
decl_stmt|;
comment|/* CHOKE */
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|ttpcb
operator|->
name|tp_fsuffix
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|fsufx
argument_list|,
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|ttpcb
operator|->
name|tp_lsuffix
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|lsufx
argument_list|,
sizeof|sizeof
argument_list|(
name|u_int
argument_list|)
argument_list|)
expr_stmt|;
name|tpmeas
argument_list|(
name|ttpcb
operator|->
name|tp_lref
argument_list|,
name|TPtime_close
argument_list|,
operator|&
name|time
argument_list|,
operator|&
name|lsufx
argument_list|,
operator|&
name|fsufx
argument_list|,
name|ttpcb
operator|->
name|tp_fref
argument_list|)
expr_stmt|;
name|tpcb
operator|->
name|tp_perf_on
operator|=
literal|0
expr_stmt|;
comment|/* turn perf off */
name|ENDPERF
name|tpcb
operator|->
name|tp_refstate
init|=
name|REF_FROZEN
decl_stmt|;
name|tp_recycle_tsuffix
argument_list|(
name|tpcb
argument_list|)
expr_stmt|;
name|tp_etimeout
argument_list|(
name|tpcb
argument_list|,
name|TM_reference
argument_list|,
operator|(
name|int
operator|)
name|tpcb
operator|->
name|tp_refer_ticks
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * NAME:	tp_freeref()  *  * CALLED FROM:  *  tp.trans when the reference timer goes off, and  *  from tp_attach() and tp_detach() when a tpcb is partially set up but not  *  set up enough to have a ref timer set for it, and it's discarded  *  due to some sort of error or an early close()  *  * FUNCTION and ARGUMENTS:  *  Frees the reference represented by (r) for re-use.  *  * RETURNS: Nothing  *  * SIDE EFFECTS:  *  * NOTES:	better be called at clock priority !!!!!  */
end_comment

begin_function
name|void
name|tp_freeref
parameter_list|(
name|n
parameter_list|)
name|RefNum
name|n
decl_stmt|;
block|{
specifier|register
name|struct
name|tp_ref
modifier|*
name|r
init|=
name|tp_ref
operator|+
name|n
decl_stmt|;
specifier|register
name|struct
name|tp_pcb
modifier|*
name|tpcb
decl_stmt|;
name|tpcb
operator|=
name|r
operator|->
name|tpr_pcb
expr_stmt|;
name|IFDEBUG
argument_list|(
argument|D_TIMER
argument_list|)
name|printf
argument_list|(
literal|"tp_freeref called for ref %d pcb %x maxrefopen %d\n"
argument_list|,
name|n
argument_list|,
name|tpcb
argument_list|,
name|tp_refinfo
operator|.
name|tpr_maxopen
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|IFTRACE
argument_list|(
name|D_TIMER
argument_list|)
name|tptrace
argument_list|(
name|TPPTmisc
argument_list|,
literal|"tp_freeref ref maxrefopen pcb"
argument_list|,
name|n
argument_list|,
name|tp_refinfo
operator|.
name|tpr_maxopen
argument_list|,
name|tpcb
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|ENDTRACE
if|if
condition|(
name|tpcb
operator|==
literal|0
condition|)
return|return;
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
name|printf
argument_list|(
literal|"tp_freeref: CLEARING tpr_pcb 0x%x\n"
argument_list|,
name|tpcb
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|r
operator|->
name|tpr_pcb
init|=
operator|(
expr|struct
name|tp_pcb
operator|*
operator|)
literal|0
decl_stmt|;
name|tpcb
operator|->
name|tp_refstate
operator|=
name|REF_FREE
expr_stmt|;
for|for
control|(
name|r
operator|=
name|tp_ref
operator|+
name|tp_refinfo
operator|.
name|tpr_maxopen
init|;
name|r
operator|>
name|tp_ref
condition|;
name|r
operator|--
control|)
if|if
condition|(
name|r
operator|->
name|tpr_pcb
condition|)
break|break;
name|tp_refinfo
operator|.
name|tpr_maxopen
operator|=
name|r
operator|-
name|tp_ref
expr_stmt|;
name|tp_refinfo
operator|.
name|tpr_numopen
operator|--
expr_stmt|;
name|IFDEBUG
argument_list|(
argument|D_TIMER
argument_list|)
name|printf
argument_list|(
literal|"tp_freeref ends w/ maxrefopen %d\n"
argument_list|,
name|tp_refinfo
operator|.
name|tpr_maxopen
argument_list|)
expr_stmt|;
name|ENDDEBUG
block|}
end_function

begin_comment
comment|/*  * NAME:  tp_getref()  *  * CALLED FROM:  *  tp_attach()  *  * FUNCTION and ARGUMENTS:  *  obtains the next free reference and allocates the appropriate  *  ref structure, links that structure to (tpcb)  *  * RETURN VALUE:  *	a reference number  *  or TP_ENOREF  *  * SIDE EFFECTS:  *  * NOTES:  */
end_comment

begin_function
name|u_long
name|tp_getref
parameter_list|(
name|tpcb
parameter_list|)
specifier|register
name|struct
name|tp_pcb
modifier|*
name|tpcb
decl_stmt|;
block|{
specifier|register
name|struct
name|tp_ref
modifier|*
name|r
decl_stmt|,
modifier|*
name|rlim
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|caddr_t
name|obase
decl_stmt|;
name|unsigned
name|size
decl_stmt|;
if|if
condition|(
operator|++
name|tp_refinfo
operator|.
name|tpr_numopen
operator|<
name|tp_refinfo
operator|.
name|tpr_size
condition|)
for|for
control|(
name|r
operator|=
name|tp_refinfo
operator|.
name|tpr_base
operator|,
name|rlim
operator|=
name|r
operator|+
name|tp_refinfo
operator|.
name|tpr_size
init|;
operator|++
name|r
operator|<
name|rlim
condition|;
control|)
comment|/* tp_ref[0] is never used */
if|if
condition|(
name|r
operator|->
name|tpr_pcb
operator|==
literal|0
condition|)
goto|goto
name|got_one
goto|;
comment|/* else have to allocate more space */
name|obase
operator|=
operator|(
name|caddr_t
operator|)
name|tp_refinfo
operator|.
name|tpr_base
expr_stmt|;
name|size
operator|=
name|tp_refinfo
operator|.
name|tpr_size
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|tp_ref
argument_list|)
expr_stmt|;
name|r
operator|=
operator|(
expr|struct
name|tp_ref
operator|*
operator|)
name|malloc
argument_list|(
name|size
operator|+
name|size
argument_list|,
name|M_PCB
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|==
literal|0
condition|)
return|return
operator|(
operator|--
name|tp_refinfo
operator|.
name|tpr_numopen
operator|,
name|TP_ENOREF
operator|)
return|;
name|tp_refinfo
operator|.
name|tpr_base
operator|=
name|tp_ref
operator|=
name|r
expr_stmt|;
name|tp_refinfo
operator|.
name|tpr_size
operator|*=
literal|2
expr_stmt|;
name|bcopy
argument_list|(
name|obase
argument_list|,
operator|(
name|caddr_t
operator|)
name|r
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|obase
argument_list|,
name|M_PCB
argument_list|)
expr_stmt|;
name|r
operator|=
operator|(
expr|struct
name|tp_ref
operator|*
operator|)
operator|(
name|size
operator|+
operator|(
name|caddr_t
operator|)
name|r
operator|)
expr_stmt|;
name|bzero
argument_list|(
operator|(
name|caddr_t
operator|)
name|r
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|got_one
label|:
name|r
operator|->
name|tpr_pcb
operator|=
name|tpcb
expr_stmt|;
name|tpcb
operator|->
name|tp_refstate
operator|=
name|REF_OPENING
expr_stmt|;
name|i
operator|=
name|r
operator|-
name|tp_refinfo
operator|.
name|tpr_base
expr_stmt|;
if|if
condition|(
name|tp_refinfo
operator|.
name|tpr_maxopen
operator|<
name|i
condition|)
name|tp_refinfo
operator|.
name|tpr_maxopen
operator|=
name|i
expr_stmt|;
return|return
operator|(
name|u_long
operator|)
name|i
return|;
block|}
end_function

begin_comment
comment|/*  * NAME: tp_set_npcb()  *  * CALLED FROM:  *	tp_attach(), tp_route_to()  *  * FUNCTION and ARGUMENTS:  *  given a tpcb, allocate an appropriate lower-lever npcb, freeing  *  any old ones that might need re-assigning.  */
end_comment

begin_expr_stmt
name|tp_set_npcb
argument_list|(
name|tpcb
argument_list|)
specifier|register
expr|struct
name|tp_pcb
operator|*
name|tpcb
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|struct
name|socket
modifier|*
name|so
init|=
name|tpcb
operator|->
name|tp_sock
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
name|tpcb
operator|->
name|tp_nlproto
operator|&&
name|tpcb
operator|->
name|tp_npcb
condition|)
block|{
name|short
name|so_state
init|=
name|so
operator|->
name|so_state
decl_stmt|;
name|so
operator|->
name|so_state
operator|&=
operator|~
name|SS_NOFDREF
expr_stmt|;
name|tpcb
operator|->
name|tp_nlproto
operator|->
name|nlp_pcbdetach
argument_list|(
name|tpcb
operator|->
name|tp_npcb
argument_list|)
expr_stmt|;
name|so
operator|->
name|so_state
operator|=
name|so_state
expr_stmt|;
block|}
name|tpcb
operator|->
name|tp_nlproto
operator|=
operator|&
name|nl_protosw
index|[
name|tpcb
operator|->
name|tp_netservice
index|]
expr_stmt|;
comment|/* xx_pcballoc sets so_pcb */
name|error
operator|=
name|tpcb
operator|->
name|tp_nlproto
operator|->
name|nlp_pcballoc
argument_list|(
name|so
argument_list|,
name|tpcb
operator|->
name|tp_nlproto
operator|->
name|nlp_pcblist
argument_list|)
expr_stmt|;
name|tpcb
operator|->
name|tp_npcb
operator|=
name|so
operator|->
name|so_pcb
expr_stmt|;
name|so
operator|->
name|so_pcb
operator|=
operator|(
name|caddr_t
operator|)
name|tpcb
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * NAME: tp_attach()  *  * CALLED FROM:  *	tp_usrreq, PRU_ATTACH  *  * FUNCTION and ARGUMENTS:  *  given a socket (so) and a protocol family (dom), allocate a tpcb  *  and ref structure, initialize everything in the structures that  *  needs to be initialized.  *  * RETURN VALUE:  *  0 ok  *  EINVAL if DEBUG(X) in is on and a disaster has occurred  *  ENOPROTOOPT if TP hasn't been configured or if the  *   socket wasn't created with tp as its protocol  *  EISCONN if this socket is already part of a connection  *  ETOOMANYREFS if ran out of tp reference numbers.  *  E* whatever error is returned from soreserve()  *    for from the network-layer pcb allocation routine  *  * SIDE EFFECTS:  *  * NOTES:  */
end_comment

begin_macro
name|tp_attach
argument_list|(
argument|so
argument_list|,
argument|protocol
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|protocol
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|tp_pcb
modifier|*
name|tpcb
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|int
name|dom
init|=
name|so
operator|->
name|so_proto
operator|->
name|pr_domain
operator|->
name|dom_family
decl_stmt|;
name|u_long
name|lref
decl_stmt|;
specifier|extern
name|struct
name|tp_conn_param
name|tp_conn_param
index|[]
decl_stmt|;
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
name|printf
argument_list|(
literal|"tp_attach:dom 0x%x so 0x%x "
argument_list|,
name|dom
argument_list|,
name|so
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|IFTRACE
parameter_list|(
name|D_CONN
parameter_list|)
function_decl|tptrace
parameter_list|(
name|TPPTmisc
parameter_list|,
function_decl|"tp_attach:dom so"
operator|,
function_decl|dom
operator|,
function_decl|so
operator|,
function_decl|0
operator|,
function_decl|0
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|ENDTRACE
end_macro

begin_if
if|if
condition|(
name|so
operator|->
name|so_pcb
operator|!=
name|NULL
condition|)
block|{
return|return
name|EISCONN
return|;
comment|/* socket already part of a connection*/
block|}
end_if

begin_if
if|if
condition|(
name|so
operator|->
name|so_snd
operator|.
name|sb_hiwat
operator|==
literal|0
operator|||
name|so
operator|->
name|so_rcv
operator|.
name|sb_hiwat
operator|==
literal|0
condition|)
name|error
operator|=
name|soreserve
argument_list|(
name|so
argument_list|,
name|tp_sendspace
argument_list|,
name|tp_recvspace
argument_list|)
expr_stmt|;
end_if

begin_comment
comment|/* later an ioctl will allow reallocation IF still in closed state */
end_comment

begin_if
if|if
condition|(
name|error
condition|)
goto|goto
name|bad2
goto|;
end_if

begin_expr_stmt
name|MALLOC
argument_list|(
name|tpcb
argument_list|,
expr|struct
name|tp_pcb
operator|*
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|tpcb
argument_list|)
argument_list|,
name|M_PCB
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|tpcb
operator|==
name|NULL
condition|)
block|{
name|error
operator|=
name|ENOBUFS
expr_stmt|;
goto|goto
name|bad2
goto|;
block|}
end_if

begin_expr_stmt
name|bzero
argument_list|(
operator|(
name|caddr_t
operator|)
name|tpcb
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_pcb
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|(
operator|(
name|lref
operator|=
name|tp_getref
argument_list|(
name|tpcb
argument_list|)
operator|)
operator|&
name|TP_ENOREF
operator|)
operator|!=
literal|0
condition|)
block|{
name|error
operator|=
name|ETOOMANYREFS
expr_stmt|;
goto|goto
name|bad3
goto|;
block|}
end_if

begin_expr_stmt
name|tpcb
operator|->
name|tp_lref
operator|=
name|lref
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_sock
operator|=
name|so
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_domain
operator|=
name|dom
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_rhiwat
operator|=
name|so
operator|->
name|so_rcv
operator|.
name|sb_hiwat
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* tpcb->tp_proto = protocol; someday maybe? */
end_comment

begin_if
if|if
condition|(
name|protocol
operator|&&
name|protocol
operator|<
name|ISOPROTO_TP4
condition|)
block|{
name|tpcb
operator|->
name|tp_netservice
operator|=
name|ISO_CONS
expr_stmt|;
name|tpcb
operator|->
name|tp_snduna
operator|=
operator|(
name|SeqNum
operator|)
operator|-
literal|1
expr_stmt|;
comment|/* kludge so the pseudo-ack from the CR/CC 								 * will generate correct fake-ack values 								 */
block|}
else|else
block|{
name|tpcb
operator|->
name|tp_netservice
operator|=
operator|(
name|dom
operator|==
name|AF_INET
operator|)
condition|?
name|IN_CLNS
else|:
name|ISO_CLNS
expr_stmt|;
comment|/* the default */
block|}
end_if

begin_expr_stmt
name|tpcb
operator|->
name|_tp_param
operator|=
name|tp_conn_param
index|[
name|tpcb
operator|->
name|tp_netservice
index|]
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_state
operator|=
name|TP_CLOSED
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_vers
operator|=
name|TP_VERSION
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_notdetached
operator|=
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Spec says default is 128 octets, 			* that is, if the tpdusize argument never appears, use 128. 			* As the initiator, we will always "propose" the 2048 			* size, that is, we will put this argument in the CR 			* always, but accept what the other side sends on the CC. 			* If the initiator sends us something larger on a CR, 			* we'll respond w/ this. 			* Our maximum is 4096.  See tp_chksum.c comments. 			*/
end_comment

begin_expr_stmt
name|tpcb
operator|->
name|tp_cong_win
operator|=
name|tpcb
operator|->
name|tp_l_tpdusize
operator|=
literal|1
operator|<<
name|tpcb
operator|->
name|tp_tpdusize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_seqmask
operator|=
name|TP_NML_FMT_MASK
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_seqbit
operator|=
name|TP_NML_FMT_BIT
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|tpcb
operator|->
name|tp_seqhalf
operator|=
name|tpcb
operator|->
name|tp_seqbit
operator|>>
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* attach to a network-layer protoswitch */
end_comment

begin_if
if|if
condition|(
name|error
operator|=
name|tp_set_npcb
argument_list|(
name|tpcb
argument_list|)
condition|)
goto|goto
name|bad4
goto|;
end_if

begin_expr_stmt
name|ASSERT
argument_list|(
name|tpcb
operator|->
name|tp_nlproto
operator|->
name|nlp_afamily
operator|==
name|tpcb
operator|->
name|tp_domain
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* nothing to do for iso case */
end_comment

begin_if
if|if
condition|(
name|dom
operator|==
name|AF_INET
condition|)
name|sotoinpcb
argument_list|(
name|so
argument_list|)
operator|->
name|inp_ppcb
operator|=
operator|(
name|caddr_t
operator|)
name|tpcb
expr_stmt|;
end_if

begin_return
return|return
literal|0
return|;
end_return

begin_label
name|bad4
label|:
end_label

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"BAD4 in tp_attach, so 0x%x\n"
argument_list|,
name|so
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ENDDEBUG
name|tp_freeref
parameter_list|(
name|tpcb
operator|->
name|tp_lref
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|bad3
label|:
end_label

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"BAD3 in tp_attach, so 0x%x\n"
argument_list|,
name|so
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ENDDEBUG
name|free
argument_list|(
operator|(
name|caddr_t
operator|)
name|tpcb
argument_list|,
name|M_PCB
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* never a cluster  */
end_comment

begin_label
name|bad2
label|:
end_label

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"BAD2 in tp_attach, so 0x%x\n"
argument_list|,
name|so
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ENDDEBUG
name|so
operator|->
name|so_pcb
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*bad:*/
end_comment

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"BAD in tp_attach, so 0x%x\n"
argument_list|,
name|so
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ENDDEBUG
end_macro

begin_return
return|return
name|error
return|;
end_return

begin_comment
unit|}
comment|/*  * NAME:  tp_detach()  *  * CALLED FROM:  *	tp.trans, on behalf of a user close request  *  and when the reference timer goes off  * (if the disconnect  was initiated by the protocol entity  * rather than by the user)  *  * FUNCTION and ARGUMENTS:  *  remove the tpcb structure from the list of active or  *  partially active connections, recycle all the mbufs  *  associated with the pcb, ref structure, sockbufs, etc.  *  Only free the ref structure if you know that a ref timer  *  wasn't set for this tpcb.  *  * RETURNS:  Nada  *  * SIDE EFFECTS:  *  * NOTES:  *  tp_soisdisconnected() was already when this is called  */
end_comment

begin_expr_stmt
unit|void
name|tp_detach
argument_list|(
name|tpcb
argument_list|)
specifier|register
expr|struct
name|tp_pcb
operator|*
name|tpcb
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|void
name|tp_freeref
argument_list|()
decl_stmt|,
name|tp_rsyflush
argument_list|()
decl_stmt|;
specifier|register
name|struct
name|socket
modifier|*
name|so
init|=
name|tpcb
operator|->
name|tp_sock
decl_stmt|;
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
name|printf
argument_list|(
literal|"tp_detach(tpcb 0x%x, so 0x%x)\n"
argument_list|,
name|tpcb
argument_list|,
name|so
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|IFTRACE
parameter_list|(
name|D_CONN
parameter_list|)
function_decl|tptraceTPCB
parameter_list|(
name|TPPTmisc
parameter_list|,
function_decl|"tp_detach tpcb so lsufx"
operator|,
function_decl|tpcb
operator|,
function_decl|so
operator|,
function_decl|*
parameter_list|(
name|u_short
modifier|*
parameter_list|)
parameter_list|(
name|tpcb
operator|->
name|tp_lsuffix
parameter_list|)
operator|,
function_decl|0
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|ENDTRACE
name|IFDEBUG
parameter_list|(
name|D_CONN
parameter_list|)
function_decl|printf
parameter_list|(
function_decl|"so_snd at 0x%x so_rcv at 0x%x\n"
operator|,
function_decl|&so->so_snd
operator|,
function_decl|&so->so_rcv
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|dump_mbuf
argument_list|(
name|so
operator|->
name|so_snd
operator|.
name|sb_mb
argument_list|,
literal|"so_snd at detach "
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"about to call LL detach, nlproto 0x%x, nl_detach 0x%x\n"
argument_list|,
name|tpcb
operator|->
name|tp_nlproto
argument_list|,
name|tpcb
operator|->
name|tp_nlproto
operator|->
name|nlp_pcbdetach
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ENDDEBUG
end_macro

begin_if
if|if
condition|(
name|tpcb
operator|->
name|tp_Xsnd
operator|.
name|sb_mb
condition|)
block|{
name|printf
argument_list|(
literal|"Unsent Xdata on detach; would panic"
argument_list|)
expr_stmt|;
name|sbflush
argument_list|(
operator|&
name|tpcb
operator|->
name|tp_Xsnd
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|tpcb
operator|->
name|tp_ucddata
condition|)
name|m_freem
argument_list|(
name|tpcb
operator|->
name|tp_ucddata
argument_list|)
expr_stmt|;
end_if

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"reassembly info cnt %d rsyq 0x%x\n"
argument_list|,
name|tpcb
operator|->
name|tp_rsycnt
argument_list|,
name|tpcb
operator|->
name|tp_rsyq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ENDDEBUG
end_macro

begin_if
if|if
condition|(
name|tpcb
operator|->
name|tp_rsyq
condition|)
name|tp_rsyflush
argument_list|(
name|tpcb
argument_list|)
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|tpcb
operator|->
name|tp_next
condition|)
block|{
name|remque
argument_list|(
name|tpcb
argument_list|)
expr_stmt|;
name|tpcb
operator|->
name|tp_next
operator|=
name|tpcb
operator|->
name|tp_prev
operator|=
literal|0
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|tpcb
operator|->
name|tp_notdetached
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"calling (...nlproto->...)(0x%x, so 0x%x)\n"
argument_list|,
name|tpcb
operator|->
name|tp_npcb
argument_list|,
name|so
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"so 0x%x so_head 0x%x,  qlen %d q0len %d qlimit %d\n"
argument_list|,
name|so
argument_list|,
name|so
operator|->
name|so_head
argument_list|,
name|so
operator|->
name|so_q0len
argument_list|,
name|so
operator|->
name|so_qlen
argument_list|,
name|so
operator|->
name|so_qlimit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ENDDEBUG
function_decl|(
name|tpcb
operator|->
name|tp_nlproto
operator|->
name|nlp_pcbdetach
function_decl|)
parameter_list|(
name|tpcb
operator|->
name|tp_npcb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* does an so->so_pcb = 0; sofree(so) */
end_comment

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"after xxx_pcbdetach\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ENDDEBUG
end_macro

begin_if
if|if
condition|(
name|tpcb
operator|->
name|tp_state
operator|==
name|TP_LISTENING
condition|)
block|{
specifier|register
name|struct
name|tp_pcb
modifier|*
modifier|*
name|tt
decl_stmt|;
for|for
control|(
name|tt
operator|=
operator|&
name|tp_listeners
init|;
operator|*
name|tt
condition|;
name|tt
operator|=
operator|&
operator|(
operator|(
operator|*
name|tt
operator|)
operator|->
name|tp_nextlisten
operator|)
control|)
if|if
condition|(
operator|*
name|tt
operator|==
name|tpcb
condition|)
break|break;
if|if
condition|(
operator|*
name|tt
condition|)
operator|*
name|tt
operator|=
name|tpcb
operator|->
name|tp_nextlisten
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"tp_detach from listen: should panic\n"
argument_list|)
expr_stmt|;
block|}
end_if

begin_if
if|if
condition|(
name|tpcb
operator|->
name|tp_refstate
operator|==
name|REF_OPENING
condition|)
block|{
comment|/* no connection existed here so no reference timer will be called */
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
name|printf
argument_list|(
literal|"SETTING ref %d to REF_FREE\n"
argument_list|,
name|tpcb
operator|->
name|tp_lref
argument_list|)
expr_stmt|;
name|ENDDEBUG
name|tp_freeref
parameter_list|(
name|tpcb
operator|->
name|tp_lref
parameter_list|)
function_decl|;
block|}
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|TP_PERF_MEAS
end_ifdef

begin_comment
comment|/* 	 * Get rid of the cluster mbuf allocated for performance measurements, if 	 * there is one.  Note that tpcb->tp_perf_on says nothing about whether or 	 * not a cluster mbuf was allocated, so you have to check for a pointer 	 * to one (that is, we need the TP_PERF_MEASs around the following section 	 * of code, not the IFPERFs) 	 */
end_comment

begin_if
if|if
condition|(
name|tpcb
operator|->
name|tp_p_mbuf
condition|)
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|m
init|=
name|tpcb
operator|->
name|tp_p_mbuf
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|n
decl_stmt|;
name|IFDEBUG
argument_list|(
argument|D_PERF_MEAS
argument_list|)
name|printf
argument_list|(
literal|"freeing tp_p_meas 0x%x  "
argument_list|,
name|tpcb
operator|->
name|tp_p_meas
argument_list|)
expr_stmt|;
name|ENDDEBUG
do|do
block|{
name|MFREE
argument_list|(
name|m
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|m
operator|=
name|n
expr_stmt|;
block|}
do|while
condition|(
name|n
condition|)
do|;
name|tpcb
operator|->
name|tp_p_meas
operator|=
literal|0
expr_stmt|;
name|tpcb
operator|->
name|tp_p_mbuf
operator|=
literal|0
expr_stmt|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TP_PERF_MEAS */
end_comment

begin_macro
name|IFDEBUG
argument_list|(
argument|D_CONN
argument_list|)
end_macro

begin_expr_stmt
name|printf
argument_list|(
literal|"end of detach, NOT single, tpcb 0x%x\n"
argument_list|,
name|tpcb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ENDDEBUG
end_expr_stmt

begin_comment
comment|/* free((caddr_t)tpcb, M_PCB); WHere to put this ? */
end_comment

begin_macro
unit|}  struct
name|que
end_macro

begin_block
block|{
name|struct
name|tp_pcb
modifier|*
name|next
decl_stmt|;
name|struct
name|tp_pcb
modifier|*
name|prev
decl_stmt|;
block|}
end_block

begin_expr_stmt
name|tp_bound_pcbs
operator|=
block|{
operator|(
expr|struct
name|tp_pcb
operator|*
operator|)
operator|&
name|tp_bound_pcbs
block|,
operator|(
expr|struct
name|tp_pcb
operator|*
operator|)
operator|&
name|tp_bound_pcbs
block|}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|u_short
name|tp_unique
decl_stmt|;
end_decl_stmt

begin_macro
name|tp_tselinuse
argument_list|(
argument|tlen
argument_list|,
argument|tsel
argument_list|,
argument|siso
argument_list|,
argument|reuseaddr
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|tsel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|sockaddr_iso
modifier|*
name|siso
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|tp_pcb
modifier|*
name|b
init|=
name|tp_bound_pcbs
operator|.
name|next
decl_stmt|,
modifier|*
name|l
init|=
name|tp_listeners
decl_stmt|;
specifier|register
name|struct
name|tp_pcb
modifier|*
name|t
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|b
operator|!=
operator|(
expr|struct
name|tp_pcb
operator|*
operator|)
operator|&
name|tp_bound_pcbs
condition|)
block|{
name|t
operator|=
name|b
expr_stmt|;
name|b
operator|=
name|t
operator|->
name|tp_next
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|l
condition|)
block|{
name|t
operator|=
name|l
expr_stmt|;
name|l
operator|=
name|t
operator|->
name|tp_nextlisten
expr_stmt|;
block|}
else|else
break|break;
if|if
condition|(
name|tlen
operator|==
name|t
operator|->
name|tp_lsuffixlen
operator|&&
name|bcmp
argument_list|(
name|tsel
argument_list|,
name|t
operator|->
name|tp_lsuffix
argument_list|,
name|tlen
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|t
operator|->
name|tp_flags
operator|&
name|TPF_GENERAL_ADDR
condition|)
block|{
if|if
condition|(
name|siso
operator|==
literal|0
operator|||
name|reuseaddr
operator|==
literal|0
condition|)
return|return
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|siso
condition|)
block|{
if|if
condition|(
name|siso
operator|->
name|siso_family
operator|==
name|t
operator|->
name|tp_domain
operator|&&
name|t
operator|->
name|tp_nlproto
operator|->
name|nlp_cmpnetaddr
argument_list|(
name|t
operator|->
name|tp_npcb
argument_list|,
name|siso
argument_list|,
name|TP_LOCAL
argument_list|)
condition|)
return|return
literal|1
return|;
block|}
elseif|else
if|if
condition|(
name|reuseaddr
operator|==
literal|0
condition|)
return|return
literal|1
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_block

begin_expr_stmt
name|tp_pcbbind
argument_list|(
name|tpcb
argument_list|,
name|nam
argument_list|)
specifier|register
expr|struct
name|tp_pcb
operator|*
name|tpcb
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|struct
name|mbuf
modifier|*
name|nam
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|sockaddr_iso
modifier|*
name|siso
init|=
literal|0
decl_stmt|;
name|int
name|tlen
init|=
literal|0
decl_stmt|,
name|wrapped
init|=
literal|0
decl_stmt|;
name|caddr_t
name|tsel
decl_stmt|;
name|u_short
name|tutil
decl_stmt|;
if|if
condition|(
name|tpcb
operator|->
name|tp_state
operator|!=
name|TP_CLOSED
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
if|if
condition|(
name|nam
condition|)
block|{
name|siso
operator|=
name|mtod
argument_list|(
name|nam
argument_list|,
expr|struct
name|sockaddr_iso
operator|*
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|siso
operator|->
name|siso_family
condition|)
block|{
default|default:
return|return
operator|(
name|EAFNOSUPPORT
operator|)
return|;
ifdef|#
directive|ifdef
name|ISO
case|case
name|AF_ISO
case|:
name|tlen
operator|=
name|siso
operator|->
name|siso_tlen
expr_stmt|;
name|tsel
operator|=
name|TSEL
argument_list|(
name|siso
argument_list|)
expr_stmt|;
if|if
condition|(
name|siso
operator|->
name|siso_nlen
operator|==
literal|0
condition|)
name|siso
operator|=
literal|0
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
name|tsel
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|tutil
expr_stmt|;
if|if
condition|(
name|tutil
operator|=
operator|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
name|siso
operator|)
operator|->
name|sin_port
condition|)
block|{
name|tlen
operator|=
literal|2
expr_stmt|;
block|}
if|if
condition|(
operator|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
name|siso
operator|)
operator|->
name|sin_addr
operator|.
name|s_addr
operator|==
literal|0
condition|)
name|siso
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
block|}
if|if
condition|(
name|tpcb
operator|->
name|tp_lsuffixlen
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|tlen
condition|)
block|{
if|if
condition|(
name|tp_tselinuse
argument_list|(
name|tlen
argument_list|,
name|tsel
argument_list|,
name|siso
argument_list|,
name|tpcb
operator|->
name|tp_sock
operator|->
name|so_options
operator|&
name|SO_REUSEADDR
argument_list|)
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
else|else
block|{
for|for
control|(
name|tsel
operator|=
operator|(
name|caddr_t
operator|)
operator|&
name|tutil
operator|,
name|tlen
operator|=
literal|2
init|;
condition|;
control|)
block|{
if|if
condition|(
name|tp_unique
operator|++
operator|<
name|ISO_PORT_RESERVED
operator|||
name|tp_unique
operator|>
name|ISO_PORT_USERRESERVED
condition|)
block|{
if|if
condition|(
name|wrapped
operator|++
condition|)
return|return
name|ESRCH
return|;
name|tp_unique
operator|=
name|ISO_PORT_RESERVED
expr_stmt|;
block|}
name|tutil
operator|=
name|htons
argument_list|(
name|tp_unique
argument_list|)
expr_stmt|;
if|if
condition|(
name|tp_tselinuse
argument_list|(
name|tlen
argument_list|,
name|tsel
argument_list|,
name|siso
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
if|if
condition|(
name|siso
condition|)
switch|switch
condition|(
name|siso
operator|->
name|siso_family
condition|)
block|{
ifdef|#
directive|ifdef
name|ISO
case|case
name|AF_ISO
case|:
name|bcopy
argument_list|(
name|tsel
argument_list|,
name|TSEL
argument_list|(
name|siso
argument_list|)
argument_list|,
name|tlen
argument_list|)
expr_stmt|;
name|siso
operator|->
name|siso_tlen
operator|=
name|tlen
expr_stmt|;
break|break;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|INET
case|case
name|AF_INET
case|:
operator|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
name|siso
operator|)
operator|->
name|sin_port
operator|=
name|tutil
expr_stmt|;
endif|#
directive|endif
block|}
block|}
name|bcopy
argument_list|(
name|tsel
argument_list|,
name|tpcb
operator|->
name|tp_lsuffix
argument_list|,
operator|(
name|tpcb
operator|->
name|tp_lsuffixlen
operator|=
name|tlen
operator|)
argument_list|)
expr_stmt|;
name|insque
argument_list|(
name|tpcb
argument_list|,
operator|&
name|tp_bound_pcbs
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|tlen
operator|||
name|siso
operator|==
literal|0
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
if|if
condition|(
name|siso
operator|==
literal|0
condition|)
block|{
name|tpcb
operator|->
name|tp_flags
operator||=
name|TPF_GENERAL_ADDR
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
name|tpcb
operator|->
name|tp_nlproto
operator|->
name|nlp_pcbbind
argument_list|(
name|tpcb
operator|->
name|tp_npcb
argument_list|,
name|nam
argument_list|)
return|;
block|}
end_block

end_unit

