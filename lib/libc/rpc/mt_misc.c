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
file|"un-namespace.h"
end_include

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
comment|/* protects authdes cache (svcauth_des.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|authdes_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERBEROS
end_ifdef

begin_comment
comment|/* auth_kerb.c serialization */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|authkerb_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* protects kerb stats list */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|svcauthkerbstats_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERBEROS */
end_comment

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
comment|/* domainname and domain_fd (getdname.c) and default_domain (rpcdname.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|dname_lock
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
comment|/* protects first_time and hostname (key_call.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|keyserv_lock
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* serializes rpc_trace() (rpc_trace.c) */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|libnsl_trace_lock
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
comment|/* protects ``port'' static in bindresvport() */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|portnum_lock
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
comment|/* protects TSD key creation */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|tsd_lock
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

begin_comment
comment|/* serializes calls to public key routines */
end_comment

begin_decl_stmt
name|pthread_mutex_t
name|serialize_pkey
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

begin_function
name|struct
name|rpc_createerr
modifier|*
name|__rpc_createerr
parameter_list|()
block|{
specifier|static
name|thread_key_t
name|rce_key
init|=
literal|0
decl_stmt|;
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
operator|(
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
operator|)
operator|!=
literal|0
condition|)
block|{
name|mutex_lock
argument_list|(
operator|&
name|tsd_lock
argument_list|)
expr_stmt|;
if|if
condition|(
name|thr_keycreate
argument_list|(
operator|&
name|rce_key
argument_list|,
name|free
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|mutex_unlock
argument_list|(
operator|&
name|tsd_lock
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|rpc_createerr
operator|)
return|;
block|}
name|mutex_unlock
argument_list|(
operator|&
name|tsd_lock
argument_list|)
expr_stmt|;
block|}
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

