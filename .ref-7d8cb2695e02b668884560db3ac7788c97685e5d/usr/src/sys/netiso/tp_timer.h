begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tp_timer.h	7.8 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*   * ARGO TP  *  * $Header: tp_timer.h,v 5.1 88/10/12 12:21:41 root Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_timer.h,v $  *  * ARGO TP  * The callout structures used by the tp timers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TP_TIMER__
end_ifndef

begin_define
define|#
directive|define
name|__TP_TIMER__
end_define

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

begin_comment
comment|/* __TP_TIMER__ */
end_comment

end_unit

