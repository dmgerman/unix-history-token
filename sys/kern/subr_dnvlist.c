begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/nv.h>
end_include

begin_include
include|#
directive|include
file|<sys/nv_impl.h>
end_include

begin_include
include|#
directive|include
file|<sys/dnv.h>
end_include

begin_define
define|#
directive|define
name|DNVLIST_GET
parameter_list|(
name|ftype
parameter_list|,
name|type
parameter_list|)
define|\
value|ftype									\ dnvlist_get_##type(const nvlist_t *nvl, const char *name, ftype defval)	\ {									\ 									\ 	if (nvlist_exists_##type(nvl, name))				\ 		return (nvlist_get_##type(nvl, name));			\ 	else								\ 		return (defval);					\ }
end_define

begin_macro
name|DNVLIST_GET
argument_list|(
argument|bool
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|DNVLIST_GET
argument_list|(
argument|uint64_t
argument_list|,
argument|number
argument_list|)
end_macro

begin_macro
name|DNVLIST_GET
argument_list|(
argument|const char *
argument_list|,
argument|string
argument_list|)
end_macro

begin_macro
name|DNVLIST_GET
argument_list|(
argument|const nvlist_t *
argument_list|,
argument|nvlist
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_macro
name|DNVLIST_GET
argument_list|(
argument|int
argument_list|,
argument|descriptor
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|DNVLIST_GET
end_undef

begin_function
specifier|const
name|void
modifier|*
name|dnvlist_get_binary
parameter_list|(
specifier|const
name|nvlist_t
modifier|*
name|nvl
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|sizep
parameter_list|,
specifier|const
name|void
modifier|*
name|defval
parameter_list|,
name|size_t
name|defsize
parameter_list|)
block|{
specifier|const
name|void
modifier|*
name|value
decl_stmt|;
if|if
condition|(
name|nvlist_exists_binary
argument_list|(
name|nvl
argument_list|,
name|name
argument_list|)
condition|)
name|value
operator|=
name|nvlist_get_binary
argument_list|(
name|nvl
argument_list|,
name|name
argument_list|,
name|sizep
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|sizep
operator|!=
name|NULL
condition|)
operator|*
name|sizep
operator|=
name|defsize
expr_stmt|;
name|value
operator|=
name|defval
expr_stmt|;
block|}
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|DNVLIST_TAKE
parameter_list|(
name|ftype
parameter_list|,
name|type
parameter_list|)
define|\
value|ftype									\ dnvlist_take_##type(nvlist_t *nvl, const char *name, ftype defval)	\ {									\ 									\ 	if (nvlist_exists_##type(nvl, name))				\ 		return (nvlist_take_##type(nvl, name));			\ 	else								\ 		return (defval);					\ }
end_define

begin_macro
name|DNVLIST_TAKE
argument_list|(
argument|bool
argument_list|,
argument|bool
argument_list|)
end_macro

begin_macro
name|DNVLIST_TAKE
argument_list|(
argument|uint64_t
argument_list|,
argument|number
argument_list|)
end_macro

begin_macro
name|DNVLIST_TAKE
argument_list|(
argument|char *
argument_list|,
argument|string
argument_list|)
end_macro

begin_macro
name|DNVLIST_TAKE
argument_list|(
argument|nvlist_t *
argument_list|,
argument|nvlist
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_macro
name|DNVLIST_TAKE
argument_list|(
argument|int
argument_list|,
argument|descriptor
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|DNVLIST_TAKE
end_undef

begin_function
name|void
modifier|*
name|dnvlist_take_binary
parameter_list|(
name|nvlist_t
modifier|*
name|nvl
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|sizep
parameter_list|,
name|void
modifier|*
name|defval
parameter_list|,
name|size_t
name|defsize
parameter_list|)
block|{
name|void
modifier|*
name|value
decl_stmt|;
if|if
condition|(
name|nvlist_exists_binary
argument_list|(
name|nvl
argument_list|,
name|name
argument_list|)
condition|)
name|value
operator|=
name|nvlist_take_binary
argument_list|(
name|nvl
argument_list|,
name|name
argument_list|,
name|sizep
argument_list|)
expr_stmt|;
else|else
block|{
if|if
condition|(
name|sizep
operator|!=
name|NULL
condition|)
operator|*
name|sizep
operator|=
name|defsize
expr_stmt|;
name|value
operator|=
name|defval
expr_stmt|;
block|}
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

end_unit

