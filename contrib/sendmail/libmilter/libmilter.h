begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
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
literal|"@(#)$Id: libmilter.h,v 8.32 2001/11/29 02:21:02 ca Exp $"
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

begin_include
include|#
directive|include
file|"libmilter/milter.h"
end_include

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

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* version info */
end_comment

begin_define
define|#
directive|define
name|MILTER_PRODUCT_NAME
value|"libmilter"
end_define

begin_define
define|#
directive|define
name|MILTER_VERSION
value|100
end_define

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
value|printf
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBMILTER_H */
end_comment

end_unit

