begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************ 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_define
define|#
directive|define
name|MERGED
end_define

begin_define
define|#
directive|define
name|IBMRTPC
end_define

begin_define
define|#
directive|define
name|CLNPECHO
end_define

begin_comment
comment|/* #define TP_PERF_MEAS */
end_comment

begin_define
define|#
directive|define
name|CONS
end_define

begin_define
define|#
directive|define
name|TPPT
end_define

begin_define
define|#
directive|define
name|ARGO_TP
end_define

begin_define
define|#
directive|define
name|ARGO_DEBUG
end_define

begin_define
define|#
directive|define
name|ISO
end_define

begin_define
define|#
directive|define
name|RDB
end_define

begin_define
define|#
directive|define
name|SHOW_LOAD
end_define

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_define
define|#
directive|define
name|INET
end_define

begin_define
define|#
directive|define
name|MAXUSERS
value|32
end_define

begin_define
define|#
directive|define
name|DST
value|1
end_define

begin_define
define|#
directive|define
name|TIMEZONE
value|360
end_define

begin_comment
comment|/*   * ARGO TP  *  * $Header: tp_sizes.c,v 5.1 88/10/12 12:21:03 root Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_sizes.c,v $  *	@(#)tp_sizes.c	7.3 (Berkeley) %G% *  *  *  * This is the initialization and cleanup stuff -   * for the tp machine in general as well as  for the individual pcbs.  * tp_init() is called at system startup.  tp_attach() and tp_getref() are  * called when a socket is created.  tp_detach() and tp_freeref()  * are called during the closing stage and/or when the reference timer   * goes off.   * tp_soisdisconnecting() and tp_soisdisconnected() are tp-specific   * versions of soisconnect*  * and are called (obviously) during the closing phase.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: tp_sizes.c,v 5.1 88/10/12 12:21:03 root Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"argoxtwentyfive.h"
end_include

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"socketvar.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"tp_param.h"
end_include

begin_include
include|#
directive|include
file|"tp_stat.h"
end_include

begin_include
include|#
directive|include
file|"tp_pcb.h"
end_include

begin_include
include|#
directive|include
file|"tp_tpdu.h"
end_include

begin_include
include|#
directive|include
file|"tp_trace.h"
end_include

begin_include
include|#
directive|include
file|"tp_meas.h"
end_include

begin_include
include|#
directive|include
file|"tp_seq.h"
end_include

begin_include
include|#
directive|include
file|"tp_clnp.h"
end_include

begin_include
include|#
directive|include
file|"iso_errno.h"
end_include

begin_include
include|#
directive|include
file|"cons.h"
end_include

begin_undef
undef|#
directive|undef
name|IncStat
end_undef

begin_include
include|#
directive|include
file|"cons_pcb.h"
end_include

begin_define
define|#
directive|define
name|DUP
parameter_list|(
name|x
parameter_list|)
value|x, x
end_define

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|P
parameter_list|)
value|printf("  Size of %s: 0x%x %d\n", "P", DUP(sizeof(struct P)))
end_define

begin_define
define|#
directive|define
name|OFF
parameter_list|(
name|P
parameter_list|,
name|Q
parameter_list|)
value|printf("\toffset of %s in %s: 0x%x %d\n", "P", "Q", \ 		DUP(_offsetof(struct Q, P)))
end_define

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"TP struct sizes:\n"
argument_list|)
expr_stmt|;
name|SIZE
argument_list|(
name|tp_pcb
argument_list|)
expr_stmt|;
define|#
directive|define
name|O
parameter_list|(
name|y
parameter_list|)
value|OFF(tp_
comment|/**/
value|y,tp_pcb);
name|O
argument_list|(
argument|state
argument_list|)
name|O
argument_list|(
argument|retrans
argument_list|)
name|O
argument_list|(
argument|snduna
argument_list|)
name|O
argument_list|(
argument|lref
argument_list|)
name|O
argument_list|(
argument|fref
argument_list|)
name|O
argument_list|(
argument|fsuffix
argument_list|)
name|O
argument_list|(
argument|fsuffixlen
argument_list|)
name|O
argument_list|(
argument|lsuffix
argument_list|)
name|O
argument_list|(
argument|lsuffixlen
argument_list|)
name|O
argument_list|(
argument|Xsnd
argument_list|)
name|O
argument_list|(
argument|Xuna
argument_list|)
name|SIZE
argument_list|(
name|tp_ref
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|O
define|#
directive|define
name|O
parameter_list|(
name|y
parameter_list|)
value|OFF(tpr_
comment|/**/
value|y,tp_ref);
name|O
argument_list|(
argument|pcb
argument_list|)
name|O
argument_list|(
argument|calltodo
argument_list|)
name|SIZE
argument_list|(
name|tp_stat
argument_list|)
expr_stmt|;
name|SIZE
argument_list|(
name|tp_param
argument_list|)
expr_stmt|;
name|SIZE
argument_list|(
name|tp_conn_param
argument_list|)
expr_stmt|;
name|SIZE
argument_list|(
name|tp_rtc
argument_list|)
expr_stmt|;
name|SIZE
argument_list|(
name|nl_protosw
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|O
define|#
directive|define
name|O
parameter_list|(
name|y
parameter_list|)
value|OFF(so_
comment|/**/
value|y,socket);
name|printf
argument_list|(
literal|"socket struct sizes:\n"
argument_list|)
expr_stmt|;
name|SIZE
argument_list|(
name|socket
argument_list|)
expr_stmt|;
name|O
argument_list|(
argument|timeo
argument_list|)
name|O
argument_list|(
argument|rcv
argument_list|)
name|O
argument_list|(
argument|snd
argument_list|)
name|O
argument_list|(
argument|tpcb
argument_list|)
name|O
argument_list|(
argument|pcb
argument_list|)
name|O
argument_list|(
argument|qlen
argument_list|)
name|O
argument_list|(
argument|error
argument_list|)
name|O
argument_list|(
argument|state
argument_list|)
name|SIZE
argument_list|(
name|sockbuf
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|O
define|#
directive|define
name|O
parameter_list|(
name|y
parameter_list|)
value|OFF(sb_
comment|/**/
value|y,sockbuf);
name|O
argument_list|(
argument|flags
argument_list|)
name|O
argument_list|(
argument|cc
argument_list|)
name|O
argument_list|(
argument|mb
argument_list|)
name|O
argument_list|(
argument|mbcnt
argument_list|)
name|SIZE
argument_list|(
name|isopcb
argument_list|)
expr_stmt|;
name|SIZE
argument_list|(
name|cons_pcb
argument_list|)
expr_stmt|;
name|OFF
argument_list|(
name|co_state
argument_list|,
name|cons_pcb
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

