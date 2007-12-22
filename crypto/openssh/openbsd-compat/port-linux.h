begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: port-linux.h,v 1.1 2006/04/22 11:26:08 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2006 Damien Miller<djm@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PORT_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|_PORT_LINUX_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_SELINUX
end_ifdef

begin_function_decl
name|void
name|ssh_selinux_setup_pty
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_selinux_setup_exec_context
parameter_list|(
name|char
modifier|*
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
comment|/* ! _PORT_LINUX_H */
end_comment

end_unit

