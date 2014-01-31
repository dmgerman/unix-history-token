begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: ssh-sandbox.h,v 1.1 2011/06/23 09:34:13 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_struct_decl
struct_decl|struct
name|monitor
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ssh_sandbox
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ssh_sandbox
modifier|*
name|ssh_sandbox_init
parameter_list|(
name|struct
name|monitor
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_sandbox_child
parameter_list|(
name|struct
name|ssh_sandbox
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_sandbox_parent_finish
parameter_list|(
name|struct
name|ssh_sandbox
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_sandbox_parent_preauth
parameter_list|(
name|struct
name|ssh_sandbox
modifier|*
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

