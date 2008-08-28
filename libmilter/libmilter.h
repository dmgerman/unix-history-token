begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2003, 2006 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_comment
comment|/* **  LIBMILTER.H -- include file for mail filter library functions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBMILTER_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBMILTER_H
value|1
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_DEFINE
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
value|= x
end_define

begin_macro
name|SM_IDSTR
argument_list|(
argument|MilterlId
argument_list|,
literal|"@(#)$Id: libmilter.h,v 8.74 2006/12/19 18:19:52 ca Exp $"
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _DEFINE */
end_comment

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEFINE */
end_comment

begin_include
include|#
directive|include
file|"sm/tailq.h"
end_include

begin_define
define|#
directive|define
name|NOT_SENDMAIL
value|1
end_define

begin_define
define|#
directive|define
name|_SOCK_ADDR
value|union bigsockaddr
end_define

begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SM_ASSERT
end_ifdef

begin_undef
undef|#
directive|undef
name|SM_ASSERT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SM_ASSERT
end_ifndef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_define
define|#
directive|define
name|SM_ASSERT
parameter_list|(
name|x
parameter_list|)
value|assert(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"libmilter/milter.h"
end_include

begin_define
define|#
directive|define
name|MAX_MACROS_ENTRIES
value|7
end_define

begin_comment
comment|/* max size of macro pointer array */
end_comment

begin_typedef
typedef|typedef
name|SM_TAILQ_HEAD
argument_list|(
argument_list|,
argument|smfi_str
argument_list|)
name|smfi_hd_T
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|smfi_str
name|smfi_str_S
typedef|;
end_typedef

begin_comment
comment|/* **  Context for one milter session. ** **  Notes: **	There is a 1-1 correlation between a sendmail SMTP server process, **	an SMTP session, and an milter context. Due to the nature of SMTP **	session handling in sendmail 8, this libmilter implementation deals **	only with a single SMTP session per MTA - libmilter connection. ** **	There is no "global" context for libmilter, global variables are **	just that (they are not "collected" in a context). ** **  Implementation hint: **  macros are stored in mac_buf[] as sequence of: **  macro_name \0 macro_value **  (just as read from the MTA) **  mac_ptr is a list of pointers into mac_buf to the beginning of each **  entry, i.e., macro_name, macro_value, ... */
end_comment

begin_struct
struct|struct
name|smfi_str
block|{
name|sthread_t
name|ctx_id
decl_stmt|;
comment|/* thread id */
name|socket_t
name|ctx_sd
decl_stmt|;
comment|/* socket descriptor */
name|int
name|ctx_dbg
decl_stmt|;
comment|/* debug level */
name|time_t
name|ctx_timeout
decl_stmt|;
comment|/* timeout */
name|int
name|ctx_state
decl_stmt|;
comment|/* state */
name|smfiDesc_ptr
name|ctx_smfi
decl_stmt|;
comment|/* filter description */
name|int
name|ctx_prot_vers
decl_stmt|;
comment|/* libmilter protocol version */
name|unsigned
name|long
name|ctx_aflags
decl_stmt|;
comment|/* milter action flags */
name|unsigned
name|long
name|ctx_pflags
decl_stmt|;
comment|/* milter protocol flags */
comment|/* 	**  milter protocol flags that are sent to the MTA; 	**  this is the same as ctx_pflags except for those flags that 	**  are not offered by the MTA but emulated in libmilter. 	*/
name|unsigned
name|long
name|ctx_pflags2mta
decl_stmt|;
comment|/* 	**  milter protocol version that is sent to the MTA; 	**  this is the same as ctx_prot_vers unless the 	**  MTA protocol version (ctx_mta_prot_vers) is smaller 	**  but still "acceptable". 	*/
name|int
name|ctx_prot_vers2mta
decl_stmt|;
name|char
modifier|*
modifier|*
name|ctx_mac_ptr
index|[
name|MAX_MACROS_ENTRIES
index|]
decl_stmt|;
name|char
modifier|*
name|ctx_mac_buf
index|[
name|MAX_MACROS_ENTRIES
index|]
decl_stmt|;
name|char
modifier|*
name|ctx_mac_list
index|[
name|MAX_MACROS_ENTRIES
index|]
decl_stmt|;
name|char
modifier|*
name|ctx_reply
decl_stmt|;
comment|/* reply code */
name|void
modifier|*
name|ctx_privdata
decl_stmt|;
comment|/* private data */
name|int
name|ctx_mta_prot_vers
decl_stmt|;
comment|/* MTA protocol version */
name|unsigned
name|long
name|ctx_mta_pflags
decl_stmt|;
comment|/* MTA protocol flags */
name|unsigned
name|long
name|ctx_mta_aflags
decl_stmt|;
comment|/* MTA action flags */
if|#
directive|if
name|_FFR_THREAD_MONITOR
name|time_t
name|ctx_start
decl_stmt|;
comment|/* start time of thread */
name|SM_TAILQ_ENTRY
argument_list|(
argument|smfi_str
argument_list|)
name|ctx_mon_link
expr_stmt|;
endif|#
directive|endif
comment|/* _FFR_THREAD_MONITOR */
if|#
directive|if
name|_FFR_WORKERS_POOL
name|long
name|ctx_sid
decl_stmt|;
comment|/* session identifier */
name|int
name|ctx_wstate
decl_stmt|;
comment|/* state of the session (worker pool) */
name|int
name|ctx_wait
decl_stmt|;
comment|/* elapsed time waiting for sm cmd */
name|SM_TAILQ_ENTRY
argument_list|(
argument|smfi_str
argument_list|)
name|ctx_link
expr_stmt|;
endif|#
directive|endif
comment|/* _FFR_WORKERS_POOL */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ValidSocket
parameter_list|(
name|sd
parameter_list|)
value|((sd)>= 0)
end_define

begin_define
define|#
directive|define
name|INVALID_SOCKET
value|(-1)
end_define

begin_define
define|#
directive|define
name|closesocket
value|close
end_define

begin_define
define|#
directive|define
name|MI_SOCK_READ
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|)
value|read(s, b, l)
end_define

begin_define
define|#
directive|define
name|MI_SOCK_READ_FAIL
parameter_list|(
name|x
parameter_list|)
value|((x)< 0)
end_define

begin_define
define|#
directive|define
name|MI_SOCK_WRITE
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|,
name|l
parameter_list|)
value|write(s, b, l)
end_define

begin_define
define|#
directive|define
name|thread_create
parameter_list|(
name|ptid
parameter_list|,
name|wr
parameter_list|,
name|arg
parameter_list|)
value|pthread_create(ptid, NULL, wr, arg)
end_define

begin_define
define|#
directive|define
name|sthread_get_id
parameter_list|()
value|pthread_self()
end_define

begin_typedef
typedef|typedef
name|pthread_mutex_t
name|smutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|smutex_init
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_init(mp, NULL) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_destroy
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_destroy(mp) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_lock
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_lock(mp) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_unlock
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_unlock(mp) == 0)
end_define

begin_define
define|#
directive|define
name|smutex_trylock
parameter_list|(
name|mp
parameter_list|)
value|(pthread_mutex_trylock(mp) == 0)
end_define

begin_if
if|#
directive|if
name|_FFR_WORKERS_POOL
end_if

begin_comment
comment|/* SM_CONF_POLL shall be defined with _FFR_WORKERS_POOL */
end_comment

begin_if
if|#
directive|if
operator|!
name|SM_CONF_POLL
end_if

begin_define
define|#
directive|define
name|SM_CONF_POLL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_POLL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_WORKERS_POOL */
end_comment

begin_typedef
typedef|typedef
name|pthread_cond_t
name|scond_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|scond_init
parameter_list|(
name|cp
parameter_list|)
value|pthread_cond_init(cp, NULL)
end_define

begin_define
define|#
directive|define
name|scond_destroy
parameter_list|(
name|cp
parameter_list|)
value|pthread_cond_destroy(cp)
end_define

begin_define
define|#
directive|define
name|scond_wait
parameter_list|(
name|cp
parameter_list|,
name|mp
parameter_list|)
value|pthread_cond_wait(cp, mp)
end_define

begin_define
define|#
directive|define
name|scond_signal
parameter_list|(
name|cp
parameter_list|)
value|pthread_cond_signal(cp)
end_define

begin_define
define|#
directive|define
name|scond_broadcast
parameter_list|(
name|cp
parameter_list|)
value|pthread_cond_broadcast(cp)
end_define

begin_define
define|#
directive|define
name|scond_timedwait
parameter_list|(
name|cp
parameter_list|,
name|mp
parameter_list|,
name|to
parameter_list|)
define|\
value|do								\ 	{								\ 		struct timespec timeout;				\ 		struct timeval now;					\ 		gettimeofday(&now, NULL);				\ 		timeout.tv_sec = now.tv_sec + to;			\ 		timeout.tv_nsec = now.tv_usec / 1000;			\ 		r = pthread_cond_timedwait(cp,mp,&timeout);		\ 		if (r != 0&& r != ETIMEDOUT)				\ 			smi_log(SMI_LOG_ERR,				\ 				"pthread_cond_timedwait error %d", r);	\ 	} while (0)
end_define

begin_if
if|#
directive|if
name|SM_CONF_POLL
end_if

begin_include
include|#
directive|include
file|<poll.h>
end_include

begin_define
define|#
directive|define
name|MI_POLLSELECT
value|"poll"
end_define

begin_define
define|#
directive|define
name|MI_POLL_RD_FLAGS
value|(POLLIN | POLLPRI)
end_define

begin_define
define|#
directive|define
name|MI_POLL_WR_FLAGS
value|(POLLOUT)
end_define

begin_define
define|#
directive|define
name|MI_MS
parameter_list|(
name|timeout
parameter_list|)
value|(((timeout)->tv_sec * 1000) + (timeout)->tv_usec)
end_define

begin_define
define|#
directive|define
name|FD_RD_VAR
parameter_list|(
name|rds
parameter_list|,
name|excs
parameter_list|)
value|struct pollfd rds
end_define

begin_define
define|#
directive|define
name|FD_WR_VAR
parameter_list|(
name|wrs
parameter_list|)
value|struct pollfd wrs
end_define

begin_define
define|#
directive|define
name|FD_RD_INIT
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|)
define|\
value|(rds).fd = (sd);			\ 		(rds).events = MI_POLL_RD_FLAGS;	\ 		(rds).revents = 0
end_define

begin_define
define|#
directive|define
name|FD_WR_INIT
parameter_list|(
name|sd
parameter_list|,
name|wrs
parameter_list|)
define|\
value|(wrs).fd = (sd);			\ 		(wrs).events = MI_POLL_WR_FLAGS;	\ 		(wrs).revents = 0
end_define

begin_define
define|#
directive|define
name|FD_IS_RD_EXC
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|)
define|\
value|(((rds).revents& (POLLERR | POLLHUP | POLLNVAL)) != 0)
end_define

begin_define
define|#
directive|define
name|FD_IS_WR_RDY
parameter_list|(
name|sd
parameter_list|,
name|wrs
parameter_list|)
define|\
value|(((wrs).revents& MI_POLL_WR_FLAGS) != 0)
end_define

begin_define
define|#
directive|define
name|FD_IS_RD_RDY
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|)
define|\
value|(((rds).revents& MI_POLL_RD_FLAGS) != 0)
end_define

begin_define
define|#
directive|define
name|FD_WR_READY
parameter_list|(
name|sd
parameter_list|,
name|excs
parameter_list|,
name|timeout
parameter_list|)
define|\
value|poll(&(wrs), 1, MI_MS(timeout))
end_define

begin_define
define|#
directive|define
name|FD_RD_READY
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|,
name|timeout
parameter_list|)
define|\
value|poll(&(rds), 1, MI_MS(timeout))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_CONF_POLL */
end_comment

begin_include
include|#
directive|include
file|<sm/fdset.h>
end_include

begin_define
define|#
directive|define
name|MI_POLLSELECT
value|"select"
end_define

begin_define
define|#
directive|define
name|FD_RD_VAR
parameter_list|(
name|rds
parameter_list|,
name|excs
parameter_list|)
value|fd_set rds, excs
end_define

begin_define
define|#
directive|define
name|FD_WR_VAR
parameter_list|(
name|wrs
parameter_list|)
value|fd_set wrs
end_define

begin_define
define|#
directive|define
name|FD_RD_INIT
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|)
define|\
value|FD_ZERO(&(rds));			\ 		FD_SET((unsigned int) (sd),&(rds));	\ 		FD_ZERO(&(excs));			\ 		FD_SET((unsigned int) (sd),&(excs))
end_define

begin_define
define|#
directive|define
name|FD_WR_INIT
parameter_list|(
name|sd
parameter_list|,
name|wrs
parameter_list|)
define|\
value|FD_ZERO(&(wrs));			\ 		FD_SET((unsigned int) (sd),&(wrs))
end_define

begin_define
define|#
directive|define
name|FD_IS_RD_EXC
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|)
value|FD_ISSET(sd,&(excs))
end_define

begin_define
define|#
directive|define
name|FD_IS_WR_RDY
parameter_list|(
name|sd
parameter_list|,
name|wrs
parameter_list|)
value|FD_ISSET((sd),&(wrs))
end_define

begin_define
define|#
directive|define
name|FD_IS_RD_RDY
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|)
value|FD_ISSET((sd),&(rds))
end_define

begin_define
define|#
directive|define
name|FD_WR_READY
parameter_list|(
name|sd
parameter_list|,
name|wrs
parameter_list|,
name|timeout
parameter_list|)
define|\
value|select((sd) + 1, NULL,&(wrs), NULL, (timeout))
end_define

begin_define
define|#
directive|define
name|FD_RD_READY
parameter_list|(
name|sd
parameter_list|,
name|rds
parameter_list|,
name|excs
parameter_list|,
name|timeout
parameter_list|)
define|\
value|select((sd) + 1,&(rds), NULL,&(excs), (timeout))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_CONF_POLL */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* some defaults */
end_comment

begin_define
define|#
directive|define
name|MI_TIMEOUT
value|7210
end_define

begin_comment
comment|/* default timeout for read/write */
end_comment

begin_define
define|#
directive|define
name|MI_CHK_TIME
value|5
end_define

begin_comment
comment|/* checking whether to terminate */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MI_SOMAXCONN
end_ifndef

begin_if
if|#
directive|if
name|SOMAXCONN
operator|>
literal|20
end_if

begin_define
define|#
directive|define
name|MI_SOMAXCONN
value|SOMAXCONN
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SOMAXCONN */
end_comment

begin_define
define|#
directive|define
name|MI_SOMAXCONN
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOMAXCONN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MI_SOMAXCONN */
end_comment

begin_comment
comment|/* maximum number of repeated failures in mi_listener() */
end_comment

begin_define
define|#
directive|define
name|MAX_FAILS_M
value|16
end_define

begin_comment
comment|/* malloc() */
end_comment

begin_define
define|#
directive|define
name|MAX_FAILS_T
value|16
end_define

begin_comment
comment|/* thread creation */
end_comment

begin_define
define|#
directive|define
name|MAX_FAILS_A
value|16
end_define

begin_comment
comment|/* accept() */
end_comment

begin_define
define|#
directive|define
name|MAX_FAILS_S
value|16
end_define

begin_comment
comment|/* select() */
end_comment

begin_comment
comment|/* internal "commands", i.e., error codes */
end_comment

begin_define
define|#
directive|define
name|SMFIC_TIMEOUT
value|((char) 1)
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|SMFIC_SELECT
value|((char) 2)
end_define

begin_comment
comment|/* select error */
end_comment

begin_define
define|#
directive|define
name|SMFIC_MALLOC
value|((char) 3)
end_define

begin_comment
comment|/* malloc error */
end_comment

begin_define
define|#
directive|define
name|SMFIC_RECVERR
value|((char) 4)
end_define

begin_comment
comment|/* recv() error */
end_comment

begin_define
define|#
directive|define
name|SMFIC_EOF
value|((char) 5)
end_define

begin_comment
comment|/* eof */
end_comment

begin_define
define|#
directive|define
name|SMFIC_UNKNERR
value|((char) 6)
end_define

begin_comment
comment|/* unknown error */
end_comment

begin_define
define|#
directive|define
name|SMFIC_TOOBIG
value|((char) 7)
end_define

begin_comment
comment|/* body chunk too big */
end_comment

begin_define
define|#
directive|define
name|SMFIC_VALIDCMD
value|' '
end_define

begin_comment
comment|/* first valid command */
end_comment

begin_comment
comment|/* hack */
end_comment

begin_define
define|#
directive|define
name|smi_log
value|syslog
end_define

begin_define
define|#
directive|define
name|sm_dprintf
value|(void) printf
end_define

begin_define
define|#
directive|define
name|milter_ret
value|int
end_define

begin_define
define|#
directive|define
name|SMI_LOG_ERR
value|LOG_ERR
end_define

begin_define
define|#
directive|define
name|SMI_LOG_FATAL
value|LOG_ERR
end_define

begin_define
define|#
directive|define
name|SMI_LOG_WARN
value|LOG_WARNING
end_define

begin_define
define|#
directive|define
name|SMI_LOG_INFO
value|LOG_INFO
end_define

begin_define
define|#
directive|define
name|SMI_LOG_DEBUG
value|LOG_DEBUG
end_define

begin_comment
comment|/* stop? */
end_comment

begin_define
define|#
directive|define
name|MILTER_CONT
value|0
end_define

begin_define
define|#
directive|define
name|MILTER_STOP
value|1
end_define

begin_define
define|#
directive|define
name|MILTER_ABRT
value|2
end_define

begin_comment
comment|/* functions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mi_handle_session
name|__P
argument_list|(
operator|(
name|SMFICTX_PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_engine
name|__P
argument_list|(
operator|(
name|SMFICTX_PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_listener
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|smfiDesc_ptr
operator|,
name|time_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mi_clr_macros
name|__P
argument_list|(
operator|(
name|SMFICTX_PTR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_stop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_control_startup
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mi_stop_milters
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
name|void
name|mi_clean_signals
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hostent
modifier|*
name|mi_gethostbyname
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_inet_pton
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mi_closener
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_opensocket
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|bool
operator|,
name|smfiDesc_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* communication functions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mi_rd_cmd
name|__P
argument_list|(
operator|(
name|socket_t
operator|,
expr|struct
name|timeval
operator|*
operator|,
name|char
operator|*
operator|,
name|size_t
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_wr_cmd
name|__P
argument_list|(
operator|(
name|socket_t
operator|,
expr|struct
name|timeval
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|mi_sendok
name|__P
argument_list|(
operator|(
name|SMFICTX_PTR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|_FFR_THREAD_MONITOR
end_if

begin_decl_stmt
specifier|extern
name|bool
name|Monitor
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MI_MONITOR_INIT
parameter_list|()
value|mi_monitor_init()
end_define

begin_define
define|#
directive|define
name|MI_MONITOR_BEGIN
parameter_list|(
name|ctx
parameter_list|,
name|cmd
parameter_list|)
define|\
value|do						\ 	{						\ 		if (Monitor)				\ 			mi_monitor_work_begin(ctx, cmd);\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|MI_MONITOR_END
parameter_list|(
name|ctx
parameter_list|,
name|cmd
parameter_list|)
define|\
value|do						\ 	{						\ 		if (Monitor)				\ 			mi_monitor_work_end(ctx, cmd);	\ 	} while (0)
end_define

begin_decl_stmt
name|int
name|mi_monitor_init
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
name|mi_monitor_work_begin
name|__P
argument_list|(
operator|(
name|SMFICTX_PTR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mi_monitor_work_end
name|__P
argument_list|(
operator|(
name|SMFICTX_PTR
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _FFR_THREAD_MONITOR */
end_comment

begin_define
define|#
directive|define
name|MI_MONITOR_INIT
parameter_list|()
value|MI_SUCCESS
end_define

begin_define
define|#
directive|define
name|MI_MONITOR_BEGIN
parameter_list|(
name|ctx
parameter_list|,
name|cmd
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MI_MONITOR_END
parameter_list|(
name|ctx
parameter_list|,
name|cmd
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_THREAD_MONITOR */
end_comment

begin_if
if|#
directive|if
name|_FFR_WORKERS_POOL
end_if

begin_decl_stmt
specifier|extern
name|int
name|mi_pool_manager_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_pool_controller_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mi_start_session
name|__P
argument_list|(
operator|(
name|SMFICTX_PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FFR_WORKERS_POOL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _LIBMILTER_H */
end_comment

end_unit

