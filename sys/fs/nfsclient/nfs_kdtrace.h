begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Robert N. M. Watson  * All rights reserved.  *  * This software was developed at the University of Cambridge Computer  * Laboratory with support from a grant from Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCL_NFS_KDTRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCL_NFS_KDTRACE_H_
end_define

begin_comment
comment|/*  * Definitions for NFS access cache probes.  */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_accesscache_flush_done_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_accesscache_get_hit_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_accesscache_get_miss_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_accesscache_load_done_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Definitions for NFS attribute cache probes.  */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_attrcache_flush_done_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_attrcache_get_hit_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_attrcache_get_miss_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|nfscl_attrcache_load_done_id
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KDTRACE_HOOKS
end_ifdef

begin_include
include|#
directive|include
file|<sys/dtrace_bsd.h>
end_include

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_FLUSH_DONE
parameter_list|(
name|vp
parameter_list|)
value|do {			\ 	if (dtrace_nfscl_accesscache_flush_done_probe != NULL)		\ 		(dtrace_nfscl_accesscache_flush_done_probe)(		\ 		    nfscl_accesscache_flush_done_id, (vp));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_GET_HIT
parameter_list|(
name|vp
parameter_list|,
name|uid
parameter_list|,
name|mode
parameter_list|)
value|do {		\ 	if (dtrace_nfscl_accesscache_get_hit_probe != NULL)		\ 		(dtrace_nfscl_accesscache_get_hit_probe)(		\ 		    nfscl_accesscache_get_hit_id, (vp), (uid),		\ 		    (mode));						\ } while (0)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_GET_MISS
parameter_list|(
name|vp
parameter_list|,
name|uid
parameter_list|,
name|mode
parameter_list|)
value|do {		\ 	if (dtrace_nfscl_accesscache_get_miss_probe != NULL)		\ 		(dtrace_nfscl_accesscache_get_miss_probe)(		\ 		    nfscl_accesscache_get_miss_id, (vp), (uid),		\ 		    (mode));						\ } while (0)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_LOAD_DONE
parameter_list|(
name|vp
parameter_list|,
name|uid
parameter_list|,
name|rmode
parameter_list|,
name|error
parameter_list|)
value|do {	\ 	if (dtrace_nfscl_accesscache_load_done_probe != NULL)		\ 		(dtrace_nfscl_accesscache_load_done_probe)(		\ 		    nfscl_accesscache_load_done_id, (vp), (uid),	\ 		    (rmode), (error));					\ } while (0)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_FLUSH_DONE
parameter_list|(
name|vp
parameter_list|)
value|do {			\ 	if (dtrace_nfscl_attrcache_flush_done_probe != NULL)		\ 		(dtrace_nfscl_attrcache_flush_done_probe)(		\ 		    nfscl_attrcache_flush_done_id, (vp));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_GET_HIT
parameter_list|(
name|vp
parameter_list|,
name|vap
parameter_list|)
value|do {			\ 	if (dtrace_nfscl_attrcache_get_hit_probe != NULL)		\ 		(dtrace_nfscl_attrcache_get_hit_probe)(			\ 		    nfscl_attrcache_get_hit_id, (vp), (vap));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_GET_MISS
parameter_list|(
name|vp
parameter_list|)
value|do {			\ 	if (dtrace_nfscl_attrcache_get_miss_probe != NULL)		\ 		(dtrace_nfscl_attrcache_get_miss_probe)(		\ 			    nfscl_attrcache_get_miss_id, (vp));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_LOAD_DONE
parameter_list|(
name|vp
parameter_list|,
name|vap
parameter_list|,
name|error
parameter_list|)
value|do {		\ 	if (dtrace_nfscl_attrcache_load_done_probe != NULL)		\ 		(dtrace_nfscl_attrcache_load_done_probe)(		\ 		    nfscl_attrcache_load_done_id, (vp), (vap),		\ 		    (error));						\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KDTRACE_HOOKS */
end_comment

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_FLUSH_DONE
parameter_list|(
name|vp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_GET_HIT
parameter_list|(
name|vp
parameter_list|,
name|uid
parameter_list|,
name|mode
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_GET_MISS
parameter_list|(
name|vp
parameter_list|,
name|uid
parameter_list|,
name|mode
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ACCESSCACHE_LOAD_DONE
parameter_list|(
name|vp
parameter_list|,
name|uid
parameter_list|,
name|rmode
parameter_list|,
name|error
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_FLUSH_DONE
parameter_list|(
name|vp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_GET_HIT
parameter_list|(
name|vp
parameter_list|,
name|vap
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_GET_MISS
parameter_list|(
name|vp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KDTRACE_NFS_ATTRCACHE_LOAD_DONE
parameter_list|(
name|vp
parameter_list|,
name|vap
parameter_list|,
name|error
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KDTRACE_HOOKS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NFSCL_NFS_KDTRACE_H_ */
end_comment

end_unit

