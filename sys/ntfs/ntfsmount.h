begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ntfsmount.h,v 1.3 1999/07/26 14:02:32 jdolecek Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Semen Ustimenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NTFS_MFLAG_CASEINS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NTFS_MFLAG_ALLNAMES
value|0x00000002
end_define

begin_struct
struct|struct
name|ntfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* block special device to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export information */
name|uid_t
name|uid
decl_stmt|;
comment|/* uid that owns ntfs files */
name|gid_t
name|gid
decl_stmt|;
comment|/* gid that owns ntfs files */
name|mode_t
name|mode
decl_stmt|;
comment|/* mask to be applied for ntfs perms */
name|u_long
name|flag
decl_stmt|;
comment|/* additional flags */
block|}
struct|;
end_struct

end_unit

