begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)argo_debug.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_ARGO_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_ARGO_DEBUG_H_
end_define

begin_comment
comment|/***************************************************************** 				Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/argo_debug.h,v $  */
end_comment

begin_define
define|#
directive|define
name|dump_buf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|Dump_buf((caddr_t)(a), (int)(b))
end_define

begin_comment
comment|/***********************************************  * Lint stuff  **********************************************/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_comment
comment|/*  * lint can't handle the flaky vacuous definitions  * of IFDEBUG, ENDDEBUG, etc.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(lint) */
end_comment

begin_comment
comment|/***********************************************  * DEBUG ON:  **********************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARGO_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|ARGO_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARGO_DEBUG
end_ifdef

begin_comment
comment|/*     #ifndef TPPT     #define TPPT     #endif TPPT      #ifndef TP_PERF_MEAS     #define TP_PERF_MEAS     #endif TP_PERF_MEAS */
end_comment

begin_decl_stmt
name|unsigned
name|char
name|argo_debug
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFDEBUG
parameter_list|(
name|ascii
parameter_list|)
define|\
value|if(argo_debug[ascii]) {
end_define

begin_define
define|#
directive|define
name|ENDDEBUG
value|; }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_comment
comment|/***********************************************  * DEBUG OFF:  **********************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STAR
end_ifndef

begin_define
define|#
directive|define
name|STAR
value|*
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STAR */
end_comment

begin_define
define|#
directive|define
name|IFDEBUG
parameter_list|(
name|ascii
parameter_list|)
end_define

begin_comment
comment|//*beginning of comment*/STAR
end_comment

begin_define
define|#
directive|define
name|ENDDEBUG
value|STAR
comment|/*end of comment*/
value|/
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_comment
comment|/***********************************************  * ASSERT  **********************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ARGO_DEBUG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|phrase
parameter_list|)
define|\
value|if( !(phrase) ) printf("ASSERTION NOT VALID at line %d file %s\n",__LINE__,__FILE__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|phrase
parameter_list|)
end_define

begin_comment
comment|/* phrase */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|phrase
parameter_list|)
end_define

begin_comment
comment|/* phrase */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_comment
comment|/***********************************************  * CLNP DEBUG OPTIONS  **********************************************/
end_comment

begin_define
define|#
directive|define
name|D_INPUT
value|'\1'
end_define

begin_comment
comment|/* clnp input */
end_comment

begin_define
define|#
directive|define
name|D_OUTPUT
value|'\2'
end_define

begin_comment
comment|/* clnp output */
end_comment

begin_define
define|#
directive|define
name|D_ROUTE
value|'\3'
end_define

begin_comment
comment|/* clnp routing */
end_comment

begin_define
define|#
directive|define
name|D_CTLINPUT
value|'\4'
end_define

begin_comment
comment|/* clnp control input */
end_comment

begin_define
define|#
directive|define
name|D_CTLOUTPUT
value|'\5'
end_define

begin_comment
comment|/* clnp control output */
end_comment

begin_define
define|#
directive|define
name|D_OPTIONS
value|'\6'
end_define

begin_comment
comment|/* clnp options */
end_comment

begin_define
define|#
directive|define
name|D_IOCTL
value|'\7'
end_define

begin_comment
comment|/* iso ioctls */
end_comment

begin_define
define|#
directive|define
name|D_ETHER
value|'\10'
end_define

begin_comment
comment|/* clnp over ethernet */
end_comment

begin_define
define|#
directive|define
name|D_TOKEN
value|'\11'
end_define

begin_comment
comment|/* clnp over token ring */
end_comment

begin_define
define|#
directive|define
name|D_ADCOM
value|'\12'
end_define

begin_comment
comment|/* clnp over the adcom */
end_comment

begin_define
define|#
directive|define
name|D_ISO
value|'\13'
end_define

begin_comment
comment|/* iso address family */
end_comment

begin_define
define|#
directive|define
name|D_FORWARD
value|'\14'
end_define

begin_comment
comment|/* clnp forwarding */
end_comment

begin_define
define|#
directive|define
name|D_DUMPOUT
value|'\15'
end_define

begin_comment
comment|/* dump clnp outgoing packets */
end_comment

begin_define
define|#
directive|define
name|D_DUMPIN
value|'\16'
end_define

begin_comment
comment|/* dump clnp input packets */
end_comment

begin_define
define|#
directive|define
name|D_DISCARD
value|'\17'
end_define

begin_comment
comment|/* debug clnp packet discard/er function */
end_comment

begin_define
define|#
directive|define
name|D_FRAG
value|'\20'
end_define

begin_comment
comment|/* clnp fragmentation */
end_comment

begin_define
define|#
directive|define
name|D_REASS
value|'\21'
end_define

begin_comment
comment|/* clnp reassembly */
end_comment

begin_function_decl
name|char
modifier|*
name|clnp_iso_addrp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/***********************************************  * ESIS DEBUG OPTIONS  **********************************************/
end_comment

begin_define
define|#
directive|define
name|D_ESISOUTPUT
value|'\30'
end_define

begin_define
define|#
directive|define
name|D_ESISINPUT
value|'\31'
end_define

begin_define
define|#
directive|define
name|D_SNPA
value|'\32'
end_define

begin_comment
comment|/***********************************************  * ISIS DEBUG OPTIONS  **********************************************/
end_comment

begin_define
define|#
directive|define
name|D_ISISOUTPUT
value|'\40'
end_define

begin_define
define|#
directive|define
name|D_ISISINPUT
value|'\41'
end_define

begin_comment
comment|/***********************************************  * EON DEBUG OPTION  **********************************************/
end_comment

begin_define
define|#
directive|define
name|D_EON
value|'\57'
end_define

begin_comment
comment|/***********************************************  * CONS DEBUG OPTIONS  **********************************************/
end_comment

begin_define
define|#
directive|define
name|D_ECNWORK
value|'\60'
end_define

begin_define
define|#
directive|define
name|D_ECNOUT
value|'\61'
end_define

begin_define
define|#
directive|define
name|D_ECNFIN
value|'\62'
end_define

begin_define
define|#
directive|define
name|D_ECNDWN
value|'\63'
end_define

begin_define
define|#
directive|define
name|D_ECNUTIL
value|'\64'
end_define

begin_define
define|#
directive|define
name|D_INCOMING
value|'\70'
end_define

begin_define
define|#
directive|define
name|D_CDATA
value|'\71'
end_define

begin_define
define|#
directive|define
name|D_CFIND
value|'\72'
end_define

begin_define
define|#
directive|define
name|D_CDUMP_REQ
value|'\73'
end_define

begin_define
define|#
directive|define
name|D_CADDR
value|'\74'
end_define

begin_define
define|#
directive|define
name|D_CCONS
value|'\75'
end_define

begin_define
define|#
directive|define
name|D_CCONN
value|'\76'
end_define

begin_comment
comment|/***********************************************  * TP DEBUG OPTIONS  **********************************************/
end_comment

begin_define
define|#
directive|define
name|D_SETPARAMS
value|'\137'
end_define

begin_define
define|#
directive|define
name|D_RTT
value|'\140'
end_define

begin_define
define|#
directive|define
name|D_ACKRECV
value|'\141'
end_define

begin_define
define|#
directive|define
name|D_ACKSEND
value|'\142'
end_define

begin_define
define|#
directive|define
name|D_CONN
value|'\143'
end_define

begin_define
define|#
directive|define
name|D_CREDIT
value|'\144'
end_define

begin_define
define|#
directive|define
name|D_DATA
value|'\145'
end_define

begin_define
define|#
directive|define
name|D_DRIVER
value|'\146'
end_define

begin_define
define|#
directive|define
name|D_EMIT
value|'\147'
end_define

begin_define
define|#
directive|define
name|D_ERROR_EMIT
value|'\150'
end_define

begin_define
define|#
directive|define
name|D_TPINPUT
value|'\151'
end_define

begin_define
define|#
directive|define
name|D_INDICATION
value|'\152'
end_define

begin_define
define|#
directive|define
name|D_CHKSUM
value|'\153'
end_define

begin_define
define|#
directive|define
name|D_RENEG
value|'\154'
end_define

begin_define
define|#
directive|define
name|D_PERF_MEAS
value|'\155'
end_define

begin_define
define|#
directive|define
name|D_MBUF_MEAS
value|'\156'
end_define

begin_define
define|#
directive|define
name|D_RTC
value|'\157'
end_define

begin_define
define|#
directive|define
name|D_SB
value|'\160'
end_define

begin_define
define|#
directive|define
name|D_DISASTER_CHECK
value|'\161'
end_define

begin_define
define|#
directive|define
name|D_REQUEST
value|'\162'
end_define

begin_define
define|#
directive|define
name|D_STASH
value|'\163'
end_define

begin_define
define|#
directive|define
name|D_NEWSOCK
value|'\164'
end_define

begin_define
define|#
directive|define
name|D_TIMER
value|'\165'
end_define

begin_define
define|#
directive|define
name|D_TPIOCTL
value|'\166'
end_define

begin_define
define|#
directive|define
name|D_SIZE_CHECK
value|'\167'
end_define

begin_define
define|#
directive|define
name|D_2ER
value|'\170'
end_define

begin_define
define|#
directive|define
name|D_DISASTER_CHECK_W
value|'\171'
end_define

begin_define
define|#
directive|define
name|D_XPD
value|'\172'
end_define

begin_define
define|#
directive|define
name|D_SYSCALL
value|'\173'
end_define

begin_define
define|#
directive|define
name|D_DROP
value|'\174'
end_define

begin_define
define|#
directive|define
name|D_ZDREF
value|'\175'
end_define

begin_define
define|#
directive|define
name|D_TPISO
value|'\176'
end_define

begin_define
define|#
directive|define
name|D_QUENCH
value|'\177'
end_define

begin_function_decl
name|void
name|dump_mbuf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/***********************************************  * New mbuf types for debugging w/ netstat -m  * This messes up 4.4 malloc for now. need bigger  * mbtypes array for now.  **********************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|TPMT_DATA
value|0x21
end_define

begin_define
define|#
directive|define
name|TPMT_RCVRTC
value|0x42
end_define

begin_define
define|#
directive|define
name|TPMT_SNDRTC
value|0x41
end_define

begin_define
define|#
directive|define
name|TPMT_TPHDR
value|0x22
end_define

begin_define
define|#
directive|define
name|TPMT_IPHDR
value|0x32
end_define

begin_define
define|#
directive|define
name|TPMT_SONAME
value|0x28
end_define

begin_define
define|#
directive|define
name|TPMT_EOT
value|0x40
end_define

begin_define
define|#
directive|define
name|TPMT_XPD
value|0x44
end_define

begin_define
define|#
directive|define
name|TPMT_PCB
value|0x23
end_define

begin_define
define|#
directive|define
name|TPMT_PERF
value|0x45
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_define
define|#
directive|define
name|TPMT_DATA
value|MT_DATA
end_define

begin_define
define|#
directive|define
name|TPMT_RCVRTC
value|MT_DATA
end_define

begin_define
define|#
directive|define
name|TPMT_SNDRTC
value|MT_DATA
end_define

begin_define
define|#
directive|define
name|TPMT_IPHDR
value|MT_HEADER
end_define

begin_define
define|#
directive|define
name|TPMT_TPHDR
value|MT_HEADER
end_define

begin_define
define|#
directive|define
name|TPMT_SONAME
value|MT_SONAME
end_define

begin_comment
comment|/* MT_EOT and MT_XPD are defined in tp_param.h */
end_comment

begin_define
define|#
directive|define
name|TPMT_XPD
value|MT_OOBDATA
end_define

begin_define
define|#
directive|define
name|TPMT_PCB
value|MT_PCB
end_define

begin_define
define|#
directive|define
name|TPMT_PERF
value|MT_PCB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARGO_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

