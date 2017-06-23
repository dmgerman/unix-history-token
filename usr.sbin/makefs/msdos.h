begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: msdos.h,v 1.3 2015/10/16 16:40:02 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2013 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|denode
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|msdosfsmount
modifier|*
name|msdosfs_mount
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msdosfs_root
parameter_list|(
name|struct
name|msdosfsmount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|denode
modifier|*
name|msdosfs_mkfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|denode
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|denode
modifier|*
name|msdosfs_mkdire
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|denode
modifier|*
parameter_list|,
name|fsnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

