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
name|MB_VERSION
value|2
end_define

begin_comment
comment|/* Used to check library and kernel are the same. */
end_comment

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

begin_define
define|#
directive|define
name|MBS_UID_DEFINED
value|0x00000001
end_define

begin_comment
comment|/* uid field should be matched */
end_comment

begin_define
define|#
directive|define
name|MBS_GID_DEFINED
value|0x00000002
end_define

begin_comment
comment|/* gid field should be matched */
end_comment

begin_define
define|#
directive|define
name|MBS_PRISON_DEFINED
value|0x00000004
end_define

begin_comment
comment|/* prison field should be matched */
end_comment

begin_define
define|#
directive|define
name|MBS_ALL_FLAGS
value|(MBS_UID_DEFINED | MBS_GID_DEFINED | MBS_PRISON_DEFINED)
end_define

begin_struct
struct|struct
name|mac_bsdextended_subject
block|{
name|int
name|mbs_flags
decl_stmt|;
name|int
name|mbs_neg
decl_stmt|;
name|uid_t
name|mbs_uid_min
decl_stmt|;
name|uid_t
name|mbs_uid_max
decl_stmt|;
name|gid_t
name|mbs_gid_min
decl_stmt|;
name|gid_t
name|mbs_gid_max
decl_stmt|;
name|int
name|mbs_prison
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MBO_UID_DEFINED
value|0x00000001
end_define

begin_comment
comment|/* uid field should be matched */
end_comment

begin_define
define|#
directive|define
name|MBO_GID_DEFINED
value|0x00000002
end_define

begin_comment
comment|/* gid field should be matched */
end_comment

begin_define
define|#
directive|define
name|MBO_FSID_DEFINED
value|0x00000004
end_define

begin_comment
comment|/* fsid field should be matched */
end_comment

begin_define
define|#
directive|define
name|MBO_SUID
value|0x00000008
end_define

begin_comment
comment|/* object must be suid */
end_comment

begin_define
define|#
directive|define
name|MBO_SGID
value|0x00000010
end_define

begin_comment
comment|/* object must be sgid */
end_comment

begin_define
define|#
directive|define
name|MBO_UID_SUBJECT
value|0x00000020
end_define

begin_comment
comment|/* uid must match subject */
end_comment

begin_define
define|#
directive|define
name|MBO_GID_SUBJECT
value|0x00000040
end_define

begin_comment
comment|/* gid must match subject */
end_comment

begin_define
define|#
directive|define
name|MBO_TYPE_DEFINED
value|0x00000080
end_define

begin_comment
comment|/* object type should be matched */
end_comment

begin_define
define|#
directive|define
name|MBO_ALL_FLAGS
value|(MBO_UID_DEFINED | MBO_GID_DEFINED | MBO_FSID_DEFINED | \ 	    MBO_SUID | MBO_SGID | MBO_UID_SUBJECT | MBO_GID_SUBJECT | \ 	    MBO_TYPE_DEFINED)
end_define

begin_define
define|#
directive|define
name|MBO_TYPE_REG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MBO_TYPE_DIR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MBO_TYPE_BLK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MBO_TYPE_CHR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MBO_TYPE_LNK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MBO_TYPE_SOCK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MBO_TYPE_FIFO
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MBO_ALL_TYPE
value|(MBO_TYPE_REG | MBO_TYPE_DIR | MBO_TYPE_BLK | \ 	    MBO_TYPE_CHR | MBO_TYPE_LNK | MBO_TYPE_SOCK | MBO_TYPE_FIFO)
end_define

begin_struct
struct|struct
name|mac_bsdextended_object
block|{
name|int
name|mbo_flags
decl_stmt|;
name|int
name|mbo_neg
decl_stmt|;
name|uid_t
name|mbo_uid_min
decl_stmt|;
name|uid_t
name|mbo_uid_max
decl_stmt|;
name|gid_t
name|mbo_gid_min
decl_stmt|;
name|gid_t
name|mbo_gid_max
decl_stmt|;
name|struct
name|fsid
name|mbo_fsid
decl_stmt|;
name|int
name|mbo_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_bsdextended_rule
block|{
name|struct
name|mac_bsdextended_subject
name|mbr_subject
decl_stmt|;
name|struct
name|mac_bsdextended_object
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

