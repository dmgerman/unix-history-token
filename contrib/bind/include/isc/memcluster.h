begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MEMCLUSTER_H
end_ifndef

begin_define
define|#
directive|define
name|MEMCLUSTER_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|meminit
value|__meminit
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MEMCLUSTER_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|memget
parameter_list|(
name|s
parameter_list|)
value|__memget_debug(s, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|memput
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|__memput_debug(p, s, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*MEMCLUSTER_DEBUG*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MEMCLUSTER_RECORD
end_ifdef

begin_define
define|#
directive|define
name|memget
parameter_list|(
name|s
parameter_list|)
value|__memget_record(s, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|memput
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|__memput_record(p, s, __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*MEMCLUSTER_RECORD*/
end_comment

begin_define
define|#
directive|define
name|memget
value|__memget
end_define

begin_define
define|#
directive|define
name|memput
value|__memput
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MEMCLUSTER_RECORD*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MEMCLUSTER_DEBUG*/
end_comment

begin_define
define|#
directive|define
name|memstats
value|__memstats
end_define

begin_define
define|#
directive|define
name|memactive
value|__memactive
end_define

begin_function_decl
name|int
name|meminit
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|__memget
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__memput
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|__memget_debug
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__memput_debug
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|__memget_record
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__memput_record
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memstats
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memactive
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
comment|/* MEMCLUSTER_H */
end_comment

end_unit

