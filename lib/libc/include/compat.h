begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Hudson River Trading LLC  * Written by: John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This file defines compatibility symbol versions for old system calls.  It  * is included in all generated system call files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBC_COMPAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIBC_COMPAT_H__
end_define

begin_define
define|#
directive|define
name|__sym_compat
parameter_list|(
name|sym
parameter_list|,
name|impl
parameter_list|,
name|verid
parameter_list|)
define|\
value|.symver impl, sym@verid
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_COMPAT7
end_ifndef

begin_expr_stmt
name|__sym_compat
argument_list|(
name|__semctl
argument_list|,
name|freebsd7___semctl
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|msgctl
argument_list|,
name|freebsd7_msgctl
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|shmctl
argument_list|,
name|freebsd7_shmctl
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__sym_compat
argument_list|(
name|nfstat
argument_list|,
name|freebsd11_nfstat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|nlstat
argument_list|,
name|freebsd11_nlstat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|nstat
argument_list|,
name|freebsd11_nstat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|fhstat
argument_list|,
name|freebsd11_fhstat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|fstat
argument_list|,
name|freebsd11_fstat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|fstatat
argument_list|,
name|freebsd11_fstatat
argument_list|,
name|FBSD_1
literal|.1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|lstat
argument_list|,
name|freebsd11_lstat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|stat
argument_list|,
name|freebsd11_stat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|getdents
argument_list|,
name|freebsd11_getdents
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|getdirentries
argument_list|,
name|freebsd11_getdirentries
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|getfsstat
argument_list|,
name|freebsd11_getfsstat
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|fhstatfs
argument_list|,
name|freebsd11_fhstatfs
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|fstatfs
argument_list|,
name|freebsd11_fstatfs
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|statfs
argument_list|,
name|freebsd11_statfs
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|mknod
argument_list|,
name|freebsd11_mknod
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|mknodat
argument_list|,
name|freebsd11_mknodat
argument_list|,
name|FBSD_1
literal|.1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|kevent
argument_list|,
name|freebsd11_kevent
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|__sym_compat
end_undef

begin_define
define|#
directive|define
name|__weak_reference
parameter_list|(
name|sym
parameter_list|,
name|alias
parameter_list|)
define|\
value|.weak	alias;.equ	alias,sym
end_define

begin_macro
name|__weak_reference
argument_list|(
argument|__sys_fcntl
argument_list|,
argument|__fcntl_compat
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|__weak_reference
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIBC_COMPAT_H__ */
end_comment

end_unit

