begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002 Robert N. M. Watson  * Copyright (c) 2001-2004 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson for the TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SECURITY_MAC_BSDEXTENDED_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SECURITY_MAC_BSDEXTENDED_H
end_define

begin_define
define|#
directive|define
name|MBI_UID_DEFINED
value|0x00000001
end_define

begin_comment
comment|/* uid field should be used */
end_comment

begin_define
define|#
directive|define
name|MBI_GID_DEFINED
value|0x00000002
end_define

begin_comment
comment|/* gid field should be used */
end_comment

begin_define
define|#
directive|define
name|MBI_NEGATED
value|0x00000004
end_define

begin_comment
comment|/* negate uid/gid matches */
end_comment

begin_define
define|#
directive|define
name|MBI_BITS
value|(MBI_UID_DEFINED | MBI_GID_DEFINED | MBI_NEGATED)
end_define

begin_comment
comment|/*  * Rights that can be represented in mbr_mode.  These have the same values  * as the V* rights in vnode.h, but in order to avoid sharing user and  * kernel constants, we define them here.  That will also improve ABI  * stability if the in-kernel values change.  */
end_comment

begin_define
define|#
directive|define
name|MBI_EXEC
value|000100
end_define

begin_define
define|#
directive|define
name|MBI_WRITE
value|000200
end_define

begin_define
define|#
directive|define
name|MBI_READ
value|000400
end_define

begin_define
define|#
directive|define
name|MBI_ADMIN
value|010000
end_define

begin_define
define|#
directive|define
name|MBI_STAT
value|020000
end_define

begin_define
define|#
directive|define
name|MBI_APPEND
value|040000
end_define

begin_define
define|#
directive|define
name|MBI_ALLPERM
value|(MBI_EXEC | MBI_WRITE | MBI_READ | MBI_ADMIN | \ 			    MBI_STAT | MBI_APPEND)
end_define

begin_struct
struct|struct
name|mac_bsdextended_identity
block|{
name|int
name|mbi_flags
decl_stmt|;
name|uid_t
name|mbi_uid
decl_stmt|;
name|gid_t
name|mbi_gid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_bsdextended_rule
block|{
name|struct
name|mac_bsdextended_identity
name|mbr_subject
decl_stmt|;
name|struct
name|mac_bsdextended_identity
name|mbr_object
decl_stmt|;
name|mode_t
name|mbr_mode
decl_stmt|;
comment|/* maximum access */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SECURITY_MAC_BSDEXTENDED_H */
end_comment

end_unit

