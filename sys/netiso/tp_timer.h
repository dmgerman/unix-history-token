begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_timer.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_TIMER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_TIMER_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_timer.h,v $  *  * ARGO TP  * The callout structures used by the tp timers.  */
end_comment

begin_define
define|#
directive|define
name|SET_DELACK
parameter_list|(
name|t
parameter_list|)
value|{\     (t)->tp_flags |= TPF_DELACK; \     if ((t)->tp_fasttimeo == 0)\ 		{ (t)->tp_fasttimeo = tp_ftimeolist; tp_ftimeolist = (t); } }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ARGO_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TP_DEBUG_TIMERS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TP_DEBUG_TIMERS
end_ifndef

begin_define
define|#
directive|define
name|tp_ctimeout
parameter_list|(
name|tpcb
parameter_list|,
name|which
parameter_list|,
name|timo
parameter_list|)
value|((tpcb)->tp_timer[which] = (timo))
end_define

begin_define
define|#
directive|define
name|tp_cuntimeout
parameter_list|(
name|tpcb
parameter_list|,
name|which
parameter_list|)
value|((tpcb)->tp_timer[which] = 0)
end_define

begin_define
define|#
directive|define
name|tp_etimeout
value|tp_ctimeout
end_define

begin_define
define|#
directive|define
name|tp_euntimeout
value|tp_cuntimeout
end_define

begin_define
define|#
directive|define
name|tp_ctimeout_MIN
parameter_list|(
name|p
parameter_list|,
name|w
parameter_list|,
name|t
parameter_list|)
define|\
value|{ if((p)->tp_timer[w]> (t)) (p)->tp_timer[w] = (t);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TP_DEBUG_TIMERS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

