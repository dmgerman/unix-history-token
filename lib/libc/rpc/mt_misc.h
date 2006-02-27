begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 12006 The FreeBSD Project. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MT_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|_MT_MISC_H
end_define

begin_comment
comment|/* Take these locks out of the application namespace. */
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
name|tsd_lock
value|__tsd_lock
end_define

begin_define
define|#
directive|define
name|xprtlist_lock
value|__xprtlist_lock
end_define

begin_decl_stmt
specifier|extern
name|pthread_rwlock_t
name|svc_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_rwlock_t
name|svc_fd_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_rwlock_t
name|rpcbaddr_cache_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|authdes_ops_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|svcauthdesstats_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|authnone_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|authsvc_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|clnt_fd_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|clntraw_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|dupreq_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|loopnconf_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|ops_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|proglst_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|rpcsoc_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|svcraw_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|tsd_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|xprtlist_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

