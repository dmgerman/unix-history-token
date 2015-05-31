begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 Mark Heily<mark@heily.com>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_COMMON_H
end_define

begin_if
if|#
directive|if
name|HAVE_ERR_H
end_if

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|err
parameter_list|(
name|rc
parameter_list|,
name|msg
parameter_list|,
modifier|...
parameter_list|)
value|do { perror(msg); exit(rc); } while (0)
end_define

begin_define
define|#
directive|define
name|errx
parameter_list|(
name|rc
parameter_list|,
name|msg
parameter_list|,
modifier|...
parameter_list|)
value|do { puts(msg); exit(rc); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cur_test_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vnode_fd
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|kevent_to_str
parameter_list|(
name|struct
name|kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kevent
modifier|*
name|kevent_get
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kevent_cmp
parameter_list|(
name|struct
name|kevent
modifier|*
parameter_list|,
name|struct
name|kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kevent_add
parameter_list|(
name|int
name|kqfd
parameter_list|,
name|struct
name|kevent
modifier|*
name|kev
parameter_list|,
name|uintptr_t
name|ident
parameter_list|,
name|short
name|filter
parameter_list|,
name|u_short
name|flags
parameter_list|,
name|u_int
name|fflags
parameter_list|,
name|intptr_t
name|data
parameter_list|,
name|void
modifier|*
name|udata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DEPRECATED: */
end_comment

begin_define
define|#
directive|define
name|KEV_CMP
parameter_list|(
name|kev
parameter_list|,
name|_ident
parameter_list|,
name|_filter
parameter_list|,
name|_flags
parameter_list|)
value|do {                 \     if (kev.ident != (_ident) ||                                \             kev.filter != (_filter) ||                          \             kev.flags != (_flags)) \         err(1, "kevent mismatch: got [%d,%d,%d] but expecting [%d,%d,%d]", \                 (int)_ident, (int)_filter, (int)_flags,\                 (int)kev.ident, kev.filter, kev.flags);\ } while (0);
end_define

begin_comment
comment|/* Checks if any events are pending, which is an error. */
end_comment

begin_function_decl
specifier|extern
name|void
name|test_no_kevents
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|test_begin
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|success
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMMON_H */
end_comment

end_unit

