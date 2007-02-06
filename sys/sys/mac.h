begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002 Robert N. M. Watson  * Copyright (c) 2001-2005 Networks Associates Technology, Inc.  * Copyright (c) 2005-2006 SPARTA, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * This software was enhanced by SPARTA ISSO under SPAWAR contract  * N66001-04-C-6019 ("SEFOS").  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Userland interface for Mandatory Access Control.  Loosely based on the  * POSIX.1e API.  More information may be found at:  *  * http://www.TrustedBSD.org/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MAC_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_MAC
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_MAC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MAC framework-related constants and limits.  */
end_comment

begin_define
define|#
directive|define
name|MAC_MAX_POLICY_NAME
value|32
end_define

begin_define
define|#
directive|define
name|MAC_MAX_LABEL_ELEMENT_NAME
value|32
end_define

begin_define
define|#
directive|define
name|MAC_MAX_LABEL_ELEMENT_DATA
value|4096
end_define

begin_define
define|#
directive|define
name|MAC_MAX_LABEL_BUF_LEN
value|8192
end_define

begin_comment
comment|/*  * struct mac is the data structure used to carry MAC labels in system calls  * and ioctls between userspace and the kernel.  */
end_comment

begin_struct
struct|struct
name|mac
block|{
name|size_t
name|m_buflen
decl_stmt|;
name|char
modifier|*
name|m_string
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mac
modifier|*
name|mac_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * Location of the userland MAC framework configuration file.  mac.conf  * set defaults for MAC-aware applications.  */
end_comment

begin_define
define|#
directive|define
name|MAC_CONFFILE
value|"/etc/mac.conf"
end_define

begin_comment
comment|/*  * Extended non-POSIX.1e interfaces that offer additional services available  * from the userland and kernel MAC frameworks.  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|int
name|mac_execve
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|envv
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_free
parameter_list|(
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_from_text
parameter_list|(
name|mac_t
modifier|*
name|_label
parameter_list|,
specifier|const
name|char
modifier|*
name|_text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_get_fd
parameter_list|(
name|int
name|_fd
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_get_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_get_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_get_peer
parameter_list|(
name|int
name|_fd
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_get_pid
parameter_list|(
name|pid_t
name|_pid
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_get_proc
parameter_list|(
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_is_present
parameter_list|(
specifier|const
name|char
modifier|*
name|_policyname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_prepare
parameter_list|(
name|mac_t
modifier|*
name|_label
parameter_list|,
specifier|const
name|char
modifier|*
name|_elements
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_prepare_file_label
parameter_list|(
name|mac_t
modifier|*
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_prepare_ifnet_label
parameter_list|(
name|mac_t
modifier|*
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_prepare_process_label
parameter_list|(
name|mac_t
modifier|*
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_prepare_type
parameter_list|(
name|mac_t
modifier|*
name|_label
parameter_list|,
specifier|const
name|char
modifier|*
name|_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_set_fd
parameter_list|(
name|int
name|_fildes
parameter_list|,
specifier|const
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_set_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_set_link
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_set_proc
parameter_list|(
specifier|const
name|mac_t
name|_label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_syscall
parameter_list|(
specifier|const
name|char
modifier|*
name|_policyname
parameter_list|,
name|int
name|_call
parameter_list|,
name|void
modifier|*
name|_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_to_text
parameter_list|(
name|mac_t
name|mac
parameter_list|,
name|char
modifier|*
modifier|*
name|_text
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
comment|/* !_SYS_MAC_H_ */
end_comment

end_unit

