begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  * Copyright (c) 1983, 1995-1997 Eric P. Allman.  All rights reserved.  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: signal.h,v 1.16 2001/07/20 19:48:21 gshapiro Exp $  */
end_comment

begin_comment
comment|/* **  SIGNAL.H -- libsm (and sendmail) signal facilities **		Extracted from sendmail/conf.h and focusing **		on signal configuration. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_SIGNAL_H
end_ifndef

begin_define
define|#
directive|define
name|SM_SIGNAL_H
value|1
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sm/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sm/conf.h>
end_include

begin_comment
comment|/* **  Critical signal sections */
end_comment

begin_define
define|#
directive|define
name|PEND_SIGHUP
value|0x0001
end_define

begin_define
define|#
directive|define
name|PEND_SIGINT
value|0x0002
end_define

begin_define
define|#
directive|define
name|PEND_SIGTERM
value|0x0004
end_define

begin_define
define|#
directive|define
name|PEND_SIGUSR1
value|0x0008
end_define

begin_define
define|#
directive|define
name|ENTER_CRITICAL
parameter_list|()
value|InCriticalSection++
end_define

begin_define
define|#
directive|define
name|LEAVE_CRITICAL
parameter_list|()
define|\
value|do									\ {									\ 	if (InCriticalSection> 0)					\ 		InCriticalSection--;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|CHECK_CRITICAL
parameter_list|(
name|sig
parameter_list|)
define|\
value|do									\ {									\ 	if (InCriticalSection> 0&& (sig) != 0)			\ 	{								\ 		pend_signal((sig));					\ 		return SIGFUNC_RETURN;					\ 	}								\ } while (0)
end_define

begin_comment
comment|/* variables */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
specifier|volatile
name|InCriticalSection
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*>0 if in critical section */
end_comment

begin_decl_stmt
specifier|extern
name|int
specifier|volatile
name|PendingSignal
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pending signal to resend */
end_comment

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|pend_signal
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reset signal in case System V semantics */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS5SIGNALS
end_ifdef

begin_define
define|#
directive|define
name|FIX_SYSV_SIGNAL
parameter_list|(
name|sig
parameter_list|,
name|handler
parameter_list|)
define|\
value|{									\ 	if ((sig) != 0)							\ 		(void) sm_signal((sig), (handler));			\ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYS5SIGNALS */
end_comment

begin_define
define|#
directive|define
name|FIX_SYSV_SIGNAL
parameter_list|(
name|sig
parameter_list|,
name|handler
parameter_list|)
value|{
comment|/* EMPTY */
value|}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS5SIGNALS */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sm_allsignals
name|__P
argument_list|(
operator|(
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_blocksignal
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sm_releasesignal
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sigfunc_t
name|sm_signal
name|__P
argument_list|(
operator|(
name|int
operator|,
name|sigfunc_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SIGFUNC_DECL
name|sm_signal_noop
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_SIGNAL_H */
end_comment

end_unit

