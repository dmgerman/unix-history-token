begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2001 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Developed by the TrustedBSD Project.  * Support for extended filesystem attributes.  */
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

begin_comment
comment|/*  * Defined name spaces for extended attributes.  Numeric constants are passed  * via system calls, but a user-friendly string is also defined.  */
end_comment

begin_define
define|#
directive|define
name|EXTATTR_NAMESPACE_EMPTY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EXTATTR_NAMESPACE_EMPTY_STRING
value|"empty"
end_define

begin_define
define|#
directive|define
name|EXTATTR_NAMESPACE_USER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EXTATTR_NAMESPACE_USER_STRING
value|"user"
end_define

begin_define
define|#
directive|define
name|EXTATTR_NAMESPACE_SYSTEM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EXTATTR_NAMESPACE_SYSTEM_STRING
value|"system"
end_define

begin_comment
comment|/*  * The following macro is designed to initialize an array that maps  * extended-attribute namespace values to their names, e.g.:  *  * char *extattr_namespace_names[] = EXTATTR_NAMESPACE_NAMES;  */
end_comment

begin_define
define|#
directive|define
name|EXTATTR_NAMESPACE_NAMES
value|{ \ 	EXTATTR_NAMESPACE_EMPTY_STRING, \ 	EXTATTR_NAMESPACE_USER_STRING, \ 	EXTATTR_NAMESPACE_SYSTEM_STRING }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|EXTATTR_MAXNAMELEN
value|NAME_MAX
end_define

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|extattr_check_cred
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|accmode_t
name|accmode
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|extattrctl
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_cmd
parameter_list|,
specifier|const
name|char
modifier|*
name|_filename
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_delete_fd
parameter_list|(
name|int
name|_fd
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_delete_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_delete_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|extattr_get_fd
parameter_list|(
name|int
name|_fd
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|extattr_get_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|extattr_get_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|extattr_list_fd
parameter_list|(
name|int
name|_fd
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|extattr_list_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|extattr_list_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_set_fd
parameter_list|(
name|int
name|_fd
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|,
specifier|const
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_set_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|,
specifier|const
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_set_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|_attrname
parameter_list|,
specifier|const
name|void
modifier|*
name|_data
parameter_list|,
name|size_t
name|_nbytes
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_SYS_EXTATTR_H_ */
end_comment

end_unit

