begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
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

begin_define
define|#
directive|define
name|TP_PERF_MEAS
end_define

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
comment|/*   * ARGO TP  *  * $Header: tp_sizes.c,v 5.1 88/10/12 12:21:03 root Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_sizes.c,v $  *  *  * This is the initialization and cleanup stuff -   * for the tp machine in general as well as  for the individual pcbs.  * tp_init() is called at system startup.  tp_attach() and tp_getref() are  * called when a socket is created.  tp_detach() and tp_freeref()  * are called during the closing stage and/or when the reference timer   * goes off.   * tp_soisdisconnecting() and tp_soisdisconnected() are tp-specific   * versions of soisconnect*  * and are called (obviously) during the closing phase.  *  */
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
file|"../netiso/tp_param.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_timer.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_ip.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_stat.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_pcb.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_tpdu.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_trace.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_meas.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_seq.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/tp_clnp.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/iso_errno.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/cons.h"
end_include

begin_include
include|#
directive|include
file|"../netiso/cons_pcb.h"
end_include

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"TP struct sizes:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"tpcb 0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_pcb
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_pcb
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"aux 0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_pcb_aux
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_pcb_aux
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"ref 0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_ref
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_ref
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"tp_stat  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_stat
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_stat
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"tp_param  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_param
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_param
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"tp_conn_param  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_conn_param
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_conn_param
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"tp_rtc  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_rtc
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_rtc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"nl_protosw  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|nl_protosw
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|nl_protosw
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TP_PERF_MEAS
name|printf
argument_list|(
literal|"\tpmeas 0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_pmeas
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tp_pmeas
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"perf meas NOT configured\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TP_PERF_MEAS
name|printf
argument_list|(
literal|"ISO struct sizes:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"socket  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|socket
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|socket
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of so_timeo 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_timeo
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_timeo
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of so_rcv 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_rcv
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_rcv
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of so_snd 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_snd
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_snd
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of sb_flags in sockbuf 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|sockbuf
argument_list|,
name|sb_flags
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|sockbuf
argument_list|,
name|sb_flags
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of sb_cc in sockbuf 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|sockbuf
argument_list|,
name|sb_cc
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|sockbuf
argument_list|,
name|sb_cc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of so_qlen in sockbuf 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_qlen
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_qlen
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of so_error in sockbuf 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_error
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_error
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of so_state in sockbuf 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_state
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|socket
argument_list|,
name|so_state
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"SIZE OF isopcb  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|isopcb
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|isopcb
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"SIZE OF cons_pcb  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|cons_pcb
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|cons_pcb
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of co_state in cons_pcb 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|cons_pcb
argument_list|,
name|co_state
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|cons_pcb
argument_list|,
name|co_state
argument_list|)
argument_list|)
expr_stmt|;
include|#
directive|include
file|"../h/types.h"
include|#
directive|include
file|"../h/ioctl.h"
include|#
directive|include
file|"../h/tty.h"
name|printf
argument_list|(
literal|"SIZE OF tty  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tty
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|tty
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of t_outq in tty 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|tty
argument_list|,
name|t_outq
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|tty
argument_list|,
name|t_outq
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of t_canq in tty 0 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of t_rawq in tty 0 0\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"SIZE OF clist  0x%x %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|clist
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|clist
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\t offset of c_cf in clist 0x%x %d\n"
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|clist
argument_list|,
name|c_cf
argument_list|)
argument_list|,
name|_offsetof
argument_list|(
expr|struct
name|clist
argument_list|,
name|c_cf
argument_list|)
argument_list|)
expr_stmt|;
block|{
name|unsigned
name|x
decl_stmt|;
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"x"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

