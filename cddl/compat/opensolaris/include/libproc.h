begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008 John Birrell<jb@freebsd.org>  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_LIBPROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_LIBPROC_H_
end_define

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_define
define|#
directive|define
name|ps_prochandle
value|proc_handle
end_define

begin_define
define|#
directive|define
name|Lmid_t
value|int
end_define

begin_define
define|#
directive|define
name|PR_RLC
value|0x0001
end_define

begin_define
define|#
directive|define
name|PR_KLC
value|0x0002
end_define

begin_define
define|#
directive|define
name|PGRAB_RDONLY
value|O_RDONLY
end_define

begin_define
define|#
directive|define
name|PGRAB_FORCE
value|0
end_define

begin_empty
empty|#include_next<libproc.h>
end_empty

begin_endif
endif|#
directive|endif
end_endif

end_unit

