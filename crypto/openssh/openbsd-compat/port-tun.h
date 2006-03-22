begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Reyk Floeter<reyk@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PORT_TUN_H
end_ifndef

begin_define
define|#
directive|define
name|_PORT_TUN_H
end_define

begin_include
include|#
directive|include
file|"channels.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SSH_TUN_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|SSH_TUN_FREEBSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|CUSTOM_SYS_TUN_OPEN
end_define

begin_function_decl
name|int
name|sys_tun_open
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SSH_TUN_COMPAT_AF
argument_list|)
operator|||
name|defined
argument_list|(
name|SSH_TUN_PREPEND_AF
argument_list|)
end_if

begin_define
define|#
directive|define
name|SSH_TUN_FILTER
end_define

begin_function_decl
name|int
name|sys_tun_infilter
parameter_list|(
name|struct
name|Channel
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|sys_tun_outfilter
parameter_list|(
name|struct
name|Channel
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
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

end_unit

