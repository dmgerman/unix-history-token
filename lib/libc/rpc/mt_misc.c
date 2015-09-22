begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: mt_misc.c,v 1.1 2000/06/02 23:11:11 fvdl Exp $	*/
end_comment

begin_comment
comment|/* #pragma ident	"@(#)mt_misc.c	1.24	93/04/29 SMI" */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|"reentrant.h"
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"mt_misc.h"
end_include

begin_comment
comment|/* Take these objects out of the application namespace. */
end_comment

begin_define
define|#
directive|define
name|svc_lock
value|__svc_lock
end_define

begin_define
define|#
directive|define
name|svc_fd_lock
value|__svc_fd_lock
end_define

begin_define
define|#
directive|define
name|rpcbaddr_cache_lock
value|__rpcbaddr_cache_lock
end_define

begin_define
define|#
directive|define
name|authdes_ops_lock
value|__authdes_ops_lock
end_define

begin_define
define|#
directive|define
name|authnone_lock
value|__authnone_lock
end_define

begin_define
define|#
directive|define
name|authsvc_lock
value|__authsvc_lock
end_define

begin_define
define|#
directive|define
name|clnt_fd_lock
value|__clnt_fd_lock
end_define

begin_define
define|#
directive|define
name|clntraw_lock
value|__clntraw_lock
end_define

begin_define
define|#
directive|define
name|dupreq_lock
value|__dupreq_lock
end_define

begin_define
define|#
directive|define
name|loopnconf_lock
value|__loopnconf_lock
end_define

begin_define
define|#
directive|define
name|ops_lock
value|__ops_lock
end_define

begin_define
define|#
directive|define
name|proglst_lock
value|__proglst_lock
end_define

begin_define
define|#
directive|define
name|rpcsoc_lock
value|__rpcsoc_lock
end_define

begin_define
define|#
directive|define
name|svcraw_lock
value|__svcraw_lock
end_define

begin_define
define|#
directive|define
name|xprtlist_lock
value|__xprtlist_lock
end_define

begin_comment
comment|/* protects the services list (svc.c) */
end_comment

begin_decl_stmt
name|pthread_rwlock_t
name|svc_lock
init|=
name|PTHREAD_RWLOCK_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protects svc_fdset and the xports[] array */
end_comment

begin_decl_stmt
name|pthread_rwlock_t
name|svc_fd_lock
init|=
name|PTHREAD_RWLOCK_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protects the RPCBIND address cache */
end_comment

begin_decl_stmt
name|pthread_rwlock_t
name|rpcbaddr_cache_lock
init|=
name|PTHREAD_RWLOCK_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* serializes authdes ops initializations */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|authdes_ops_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protects des stats list */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|svcauthdesstats_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* auth_none.c serialization */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|authnone_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protects the Auths list (svc_auth.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|authsvc_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protects client-side fd lock array */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|clnt_fd_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* clnt_raw.c serialization */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|clntraw_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dupreq variables (svc_dg.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|dupreq_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* loopnconf (rpcb_clnt.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|loopnconf_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* serializes ops initializations */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|ops_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protects proglst list (svc_simple.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|proglst_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* serializes clnt_com_create() (rpc_soc.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|rpcsoc_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* svc_raw.c serialization */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|svcraw_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* xprtlist (svc_generic.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|xprtlist_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|rpc_createerr
end_undef

begin_decl_stmt
name|struct
name|rpc_createerr
name|rpc_createerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|thread_key_t
name|rce_key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|once_t
name|rce_once
init|=
name|ONCE_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|rce_key_error
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|rce_key_init
parameter_list|(
name|void
parameter_list|)
block|{
name|rce_key_error
operator|=
name|thr_keycreate
argument_list|(
operator|&
name|rce_key
argument_list|,
name|free
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|struct
name|rpc_createerr
modifier|*
name|__rpc_createerr
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|rpc_createerr
modifier|*
name|rce_addr
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|thr_main
argument_list|()
condition|)
return|return
operator|(
operator|&
name|rpc_createerr
operator|)
return|;
if|if
condition|(
name|thr_once
argument_list|(
operator|&
name|rce_once
argument_list|,
name|rce_key_init
argument_list|)
operator|!=
literal|0
operator|||
name|rce_key_error
operator|!=
literal|0
condition|)
return|return
operator|(
operator|&
name|rpc_createerr
operator|)
return|;
name|rce_addr
operator|=
operator|(
expr|struct
name|rpc_createerr
operator|*
operator|)
name|thr_getspecific
argument_list|(
name|rce_key
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rce_addr
condition|)
block|{
name|rce_addr
operator|=
operator|(
expr|struct
name|rpc_createerr
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|rpc_createerr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|thr_setspecific
argument_list|(
name|rce_key
argument_list|,
operator|(
name|void
operator|*
operator|)
name|rce_addr
argument_list|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|rce_addr
condition|)
name|free
argument_list|(
name|rce_addr
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|rpc_createerr
operator|)
return|;
block|}
name|memset
argument_list|(
name|rce_addr
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|rpc_createerr
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|rce_addr
operator|)
return|;
block|}
return|return
operator|(
name|rce_addr
operator|)
return|;
block|}
end_function

end_unit

