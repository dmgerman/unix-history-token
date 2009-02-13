begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SELECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SELECT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sigset.h>
end_include

begin_include
include|#
directive|include
file|<sys/_timeval.h>
end_include

begin_include
include|#
directive|include
file|<sys/timespec.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|long
name|__fd_mask
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_typedef
typedef|typedef
name|__fd_mask
name|fd_mask
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIGSET_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_SIGSET_T_DECLARED
end_define

begin_typedef
typedef|typedef
name|__sigset_t
name|sigset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Select uses bit masks of file descriptors in longs.  These macros  * manipulate such bit fields (the filesystem macros use chars).  * FD_SETSIZE may be defined by the user, but the default here should  * be enough for most uses.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|FD_SETSIZE
value|1024U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_NFDBITS
value|(sizeof(__fd_mask) * 8)
end_define

begin_comment
comment|/* bits per mask */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|NFDBITS
value|_NFDBITS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_howmany
end_ifndef

begin_define
define|#
directive|define
name|_howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) + ((y) - 1)) / (y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|__fd_mask
name|__fds_bits
index|[
name|_howmany
argument_list|(
name|FD_SETSIZE
argument_list|,
name|_NFDBITS
argument_list|)
index|]
decl_stmt|;
block|}
name|fd_set
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|fds_bits
value|__fds_bits
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__fdset_mask
parameter_list|(
name|n
parameter_list|)
value|((__fd_mask)1<< ((n) % _NFDBITS))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->__fds_bits[(n)/_NFDBITS]&= ~__fdset_mask(n))
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|FD_COPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|(void)(*(t) = *(f))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|(((p)->__fds_bits[(n)/_NFDBITS]& __fdset_mask(n)) != 0)
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->__fds_bits[(n)/_NFDBITS] |= __fdset_mask(n))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|do {					\ 	fd_set *_p;					\ 	__size_t _n;					\ 							\ 	_p = (p);					\ 	_n = _howmany(FD_SETSIZE, _NFDBITS);		\ 	while (_n> 0)					\ 		_p->__fds_bits[--_n] = 0;		\ } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
name|int
name|pselect
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
name|__restrict
parameter_list|,
name|fd_set
modifier|*
name|__restrict
parameter_list|,
name|fd_set
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|sigset_t
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_SELECT_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_SELECT_DECLARED
end_define

begin_comment
comment|/* XXX missing restrict type-qualifier */
end_comment

begin_function_decl
name|int
name|select
parameter_list|(
name|int
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|fd_set
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SELECT_H_ */
end_comment

end_unit

