begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Mike Barcroft<mike@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STRINGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_STRINGS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|<=
literal|200112
name|int
name|bcmp
argument_list|(
specifier|const
name|void
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LEGACY */
end_comment

begin_function_decl
name|void
name|bcopy
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LEGACY */
end_comment

begin_function_decl
name|void
name|bzero
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LEGACY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_decl_stmt
name|int
name|ffs
argument_list|(
name|int
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
name|int
name|ffsl
argument_list|(
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ffsll
argument_list|(
name|long
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fls
argument_list|(
name|int
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flsl
argument_list|(
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flsll
argument_list|(
name|long
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|<=
literal|200112
end_if

begin_decl_stmt
name|char
modifier|*
name|index
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LEGACY */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rindex
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LEGACY */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|strcasecmp
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|strncasecmp
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|size_t
argument_list|)
name|__pure
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STRINGS_H_ */
end_comment

end_unit

