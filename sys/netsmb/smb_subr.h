begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETSMB_SMB_SUBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETSMB_SMB_SUBR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"This file shouldn't be included from userland programs"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SMBTEMP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FB_CURRENT
end_define

begin_define
define|#
directive|define
name|SMBERROR
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: "format, __func__ ,## args)
end_define

begin_define
define|#
directive|define
name|SMBPANIC
parameter_list|(
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf("%s: "format, __func__ ,## args)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMB_SOCKET_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SMBSDEBUG
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
name|SMBSDEBUG
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

begin_ifdef
ifdef|#
directive|ifdef
name|SMB_IOD_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SMBIODEBUG
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
name|SMBIODEBUG
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

begin_ifdef
ifdef|#
directive|ifdef
name|SMB_SOCKETDATA_DEBUG
end_ifdef

begin_function_decl
name|void
name|m_dumpm
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|m_dumpm
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SMB_SIGMASK
parameter_list|(
name|set
parameter_list|)
define|\
value|(SIGISMEMBER(set, SIGINT) || SIGISMEMBER(set, SIGTERM) ||	\ 	 SIGISMEMBER(set, SIGHUP) || SIGISMEMBER(set, SIGKILL) ||	\ 	 SIGISMEMBER(set, SIGQUIT))
end_define

begin_define
define|#
directive|define
name|smb_suser
parameter_list|(
name|cred
parameter_list|)
value|suser_cred(cred, 0)
end_define

begin_comment
comment|/*  * Compatibility wrappers for simple locks  */
end_comment

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_define
define|#
directive|define
name|smb_slock
value|mtx
end_define

begin_define
define|#
directive|define
name|smb_sl_init
parameter_list|(
name|mtx
parameter_list|,
name|desc
parameter_list|)
value|mtx_init(mtx, desc, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|smb_sl_destroy
parameter_list|(
name|mtx
parameter_list|)
value|mtx_destroy(mtx)
end_define

begin_define
define|#
directive|define
name|smb_sl_lock
parameter_list|(
name|mtx
parameter_list|)
value|mtx_lock(mtx)
end_define

begin_define
define|#
directive|define
name|smb_sl_unlock
parameter_list|(
name|mtx
parameter_list|)
value|mtx_unlock(mtx)
end_define

begin_define
define|#
directive|define
name|SMB_STRFREE
parameter_list|(
name|p
parameter_list|)
value|do { if (p) smb_strfree(p); } while(0)
end_define

begin_comment
comment|/*  * The simple try/catch/finally interface.  * With GCC it is possible to allow more than one try/finally block per  * function, but we'll avoid it to maintain portability.  */
end_comment

begin_define
define|#
directive|define
name|itry
value|{						\ 				__label__ _finlab, _catchlab;		\ 				int _tval;				\  #define icatch(var)							\ 				goto _finlab;				\ 				(void)&&_catchlab;			\ 				_catchlab:				\ 				var = _tval;
end_define

begin_define
define|#
directive|define
name|ifinally
value|(void)&&_finlab;			\ 				_finlab:
end_define

begin_define
define|#
directive|define
name|iendtry
value|}
end_define

begin_define
define|#
directive|define
name|inocatch
define|\
value|goto _finlab;				\ 				(void)&&_catchlab;			\ 				_catchlab:				\  #define ithrow(t)	do {						\ 				if ((_tval = (int)(t)) != 0)		\ 					goto _catchlab;			\ 			} while (0)
end_define

begin_define
define|#
directive|define
name|ierror
parameter_list|(
name|t
parameter_list|,
name|e
parameter_list|)
value|do {						\ 				if (t) {				\ 					_tval = e;			\ 					goto _catchlab;			\ 				}					\ 			} while (0)
end_define

begin_typedef
typedef|typedef
name|u_int16_t
name|smb_unichar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|smb_unichar
modifier|*
name|smb_uniptr
typedef|;
end_typedef

begin_comment
comment|/*  * Crediantials of user/process being processing in the connection procedures  */
end_comment

begin_struct
struct|struct
name|smb_cred
block|{
name|struct
name|thread
modifier|*
name|scr_td
decl_stmt|;
name|struct
name|ucred
modifier|*
name|scr_cred
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|smb_unichar
name|smb_unieol
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|mbchain
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smb_vc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|smb_rq
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|smb_makescred
parameter_list|(
name|struct
name|smb_cred
modifier|*
name|scred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_proc_intr
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|smb_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|smb_memdup
parameter_list|(
specifier|const
name|void
modifier|*
name|umem
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|smb_strdupin
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|int
name|maxlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|smb_memdupin
parameter_list|(
name|void
modifier|*
name|umem
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_strtouni
parameter_list|(
name|u_int16_t
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_strfree
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smb_memfree
parameter_list|(
name|void
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|smb_zmalloc
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_encrypt
parameter_list|(
specifier|const
name|u_char
modifier|*
name|apwd
parameter_list|,
name|u_char
modifier|*
name|C8
parameter_list|,
name|u_char
modifier|*
name|RN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_ntencrypt
parameter_list|(
specifier|const
name|u_char
modifier|*
name|apwd
parameter_list|,
name|u_char
modifier|*
name|C8
parameter_list|,
name|u_char
modifier|*
name|RN
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_maperror
parameter_list|(
name|int
name|eclass
parameter_list|,
name|int
name|eno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_put_dmem
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|caseopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_put_dstring
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|struct
name|smb_vc
modifier|*
name|vcp
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|caseopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_put_string
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smb_put_asunistring
parameter_list|(
name|struct
name|smb_rq
modifier|*
name|rqp
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETSMB_SMB_SUBR_H_ */
end_comment

end_unit

