begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ntfs_vfsops.h,v 1.4 1999/10/10 14:20:33 jdolecek Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Semen Ustimenko (semenu@FreeBSD.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|VG_DONTLOADIN
value|0x0001
end_define

begin_comment
comment|/* Tells ntfs_vgetex to do not call */
end_comment

begin_comment
comment|/* ntfs_loadntnode() on ntnode, even if */
end_comment

begin_comment
comment|/* ntnode not loaded */
end_comment

begin_define
define|#
directive|define
name|VG_DONTVALIDFN
value|0x0002
end_define

begin_comment
comment|/* Tells ntfs_vgetex to do not validate */
end_comment

begin_comment
comment|/* fnode */
end_comment

begin_define
define|#
directive|define
name|VG_EXT
value|0x0004
end_define

begin_comment
comment|/* This is not main record */
end_comment

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ntfsmount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ntfs_vgetex
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|u_int32_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ntfs_calccfree
parameter_list|(
name|struct
name|ntfsmount
modifier|*
parameter_list|,
name|cn_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

