begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Userland/kernel interface for Extended File System Attributes  *  * This code from the FreeBSD POSIX.1e implementation.  While the syscalls  * are fully implemented, invoking the VFS vnops and VFS calls as necessary,  * no file systems shipped with this version of FreeBSD implement these  * calls.  Extensions to UFS/FFS to support extended attributes are  * available from the POSIX.1e implementation page, or possibly in a more  * recent version of FreeBSD.  *  * The POSIX.1e implementation page may be reached at:  *   http://www.watson.org/fbsd-hardening/posix1e/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EXTATTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EXTATTR_H_
end_define

begin_define
define|#
directive|define
name|EXTATTR_MAXNAMELEN
value|NAME_MAX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|int
name|extattrctl
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|int
name|cmd
parameter_list|,
name|char
modifier|*
name|attrname
parameter_list|,
name|caddr_t
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_set_file
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|attrname
parameter_list|,
name|struct
name|iovec
modifier|*
name|iovp
parameter_list|,
name|u_int
name|iovcnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_get_file
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|attrname
parameter_list|,
name|struct
name|iovec
modifier|*
name|iovp
parameter_list|,
name|u_int
name|iovcnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_delete_file
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|attrname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_EXTATTR_H_ */
end_comment

end_unit

