begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*   * ARGO TP  *  * $Header: tp_timer.h,v 5.1 88/10/12 12:21:41 root Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_timer.h,v $  *	@(#)tp_timer.h	7.3 (Berkeley) %G% *  *  * ARGO TP  * The callout structures used by the tp timers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TP_CALLOUT__
end_ifndef

begin_define
define|#
directive|define
name|__TP_CALLOUT__
end_define

begin_comment
comment|/* C timers - one per tpcb, generally cancelled */
end_comment

begin_struct
struct|struct
name|Ccallout
block|{
name|int
name|c_time
decl_stmt|;
comment|/* incremental time */
name|int
name|c_active
decl_stmt|;
comment|/* this timer is active? */
block|}
struct|;
end_struct

begin_comment
comment|/* E timers - generally expire or there must be> 1 active per tpcb */
end_comment

begin_struct
struct|struct
name|Ecallout
block|{
name|int
name|c_time
decl_stmt|;
comment|/* incremental time */
name|int
name|c_func
decl_stmt|;
comment|/* function to call */
name|u_int
name|c_arg1
decl_stmt|;
comment|/* argument to routine */
name|u_int
name|c_arg2
decl_stmt|;
comment|/* argument to routine */
name|int
name|c_arg3
decl_stmt|;
comment|/* argument to routine */
name|struct
name|Ecallout
modifier|*
name|c_next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|__TP_CALLOUT__
end_endif

end_unit

