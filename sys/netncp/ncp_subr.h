begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCP_SUBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCP_SUBR_H_
end_define

begin_define
define|#
directive|define
name|NCP_TIMER_TICK
value|2*hz
end_define

begin_comment
comment|/* 1sec */
end_comment

begin_define
define|#
directive|define
name|NCP_SIGMASK
parameter_list|(
name|set
parameter_list|)
define|\
value|(SIGISMEMBER(set, SIGINT) || SIGISMEMBER(set, SIGTERM) ||	\ 	 SIGISMEMBER(set, SIGHUP) || SIGISMEMBER(set, SIGKILL) ||	\ 	 SIGISMEMBER(set, SIGQUIT))
end_define

begin_define
define|#
directive|define
name|NCP_PRINT
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("FATAL: %s: "format, __func__ ,## args)
end_define

begin_define
define|#
directive|define
name|nwfs_printf
value|NCP_PRINT
end_define

begin_comment
comment|/* Maybe this should panic, but I dont like that */
end_comment

begin_define
define|#
directive|define
name|NCPFATAL
value|NCP_PRINT
end_define

begin_define
define|#
directive|define
name|NCPERROR
value|NCP_PRINT
end_define

begin_comment
comment|/* socket debugging */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCP_SOCKET_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NCPSDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: "format, __func__ ,## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCPSDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCP calls debug */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCP_NCP_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NCPNDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: "format, __func__ ,## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCPNDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCP data dump */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NCP_DATA_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NCPDDEBUG
parameter_list|(
name|m
parameter_list|)
value|m_dumpm(m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCPDDEBUG
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FS VOPS debug */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NWFS_VOPS_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NCPVODEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: "format, __func__ ,## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCPVODEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FS VNOPS debug */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NWFS_VNOPS_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|NCPVNDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: "format, __func__ ,## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCPVNDEBUG
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|checkbad
parameter_list|(
name|fn
parameter_list|)
value|{error=(fn);if(error) goto bad;}
end_define

begin_define
define|#
directive|define
name|ncp_suser
parameter_list|(
name|cred
parameter_list|)
value|suser_cred(cred, 0)
end_define

begin_define
define|#
directive|define
name|ncp_isowner
parameter_list|(
name|conn
parameter_list|,
name|cred
parameter_list|)
value|((cred)->cr_uid == (conn)->nc_owner->cr_uid)
end_define

begin_struct_decl
struct_decl|struct
name|ncp_conn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nwmount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nwnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ncp_nlstables
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ncp_open_info
block|{
name|u_int32_t
name|origfh
decl_stmt|;
name|ncp_fh
name|fh
decl_stmt|;
name|u_int8_t
name|action
decl_stmt|;
name|struct
name|nw_entry_info
name|fattr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|ncp_debuglevel
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ncp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_done
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_chkintr
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ncp_str_dup
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ncp_crypt.c */
end_comment

begin_function_decl
name|void
name|nw_keyhash
parameter_list|(
specifier|const
name|u_char
modifier|*
name|key
parameter_list|,
specifier|const
name|u_char
modifier|*
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|,
name|u_char
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nw_encrypt
parameter_list|(
specifier|const
name|u_char
modifier|*
name|fra
parameter_list|,
specifier|const
name|u_char
modifier|*
name|buf
parameter_list|,
name|u_char
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_sign
parameter_list|(
specifier|const
name|u_int32_t
modifier|*
name|state
parameter_list|,
specifier|const
name|char
modifier|*
name|x
parameter_list|,
name|u_int32_t
modifier|*
name|ostate
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NCP_SUBR_H_ */
end_comment

end_unit

