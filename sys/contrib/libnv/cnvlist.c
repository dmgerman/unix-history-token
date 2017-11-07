begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Adam Starak<starak.adam@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/cnv.h>
end_include

begin_include
include|#
directive|include
file|<sys/nv.h>
end_include

begin_include
include|#
directive|include
file|"nv_impl.h"
end_include

begin_include
include|#
directive|include
file|"nvlist_impl.h"
end_include

begin_include
include|#
directive|include
file|"nvpair_impl.h"
end_include

begin_function
specifier|const
name|char
modifier|*
name|cnvlist_name
parameter_list|(
name|void
modifier|*
name|cookiep
parameter_list|)
block|{
return|return
operator|(
name|nvpair_name
argument_list|(
name|cookiep
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|cnvlist_type
parameter_list|(
name|void
modifier|*
name|cookiep
parameter_list|)
block|{
return|return
operator|(
name|nvpair_type
argument_list|(
name|cookiep
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CNVLIST_GET
parameter_list|(
name|ftype
parameter_list|,
name|type
parameter_list|,
name|NVTYPE
parameter_list|)
define|\
value|ftype									\ cnvlist_get_##type(void *cookiep)					\ {									\ 									\ 	if (nvpair_type(cookiep) != NV_TYPE_##NVTYPE) {			\ 		nvlist_report_missing(NV_TYPE_##NVTYPE,			\ 		    nvpair_name(cookiep));				\ 	}								\         return (nvpair_get_##type(cookiep));				\ }
end_define

begin_macro
name|CNVLIST_GET
argument_list|(
argument|bool
argument_list|,
argument|bool
argument_list|,
argument|BOOL
argument_list|)
end_macro

begin_macro
name|CNVLIST_GET
argument_list|(
argument|uint64_t
argument_list|,
argument|number
argument_list|,
argument|NUMBER
argument_list|)
end_macro

begin_macro
name|CNVLIST_GET
argument_list|(
argument|const char *
argument_list|,
argument|string
argument_list|,
argument|STRING
argument_list|)
end_macro

begin_macro
name|CNVLIST_GET
argument_list|(
argument|const nvlist_t *
argument_list|,
argument|nvlist
argument_list|,
argument|NVLIST
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_macro
name|CNVLIST_GET
argument_list|(
argument|int
argument_list|,
argument|descriptor
argument_list|,
argument|DESCRIPTOR
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CNVLIST_GET
end_undef

begin_define
define|#
directive|define
name|CNVLIST_GET_ARRAY
parameter_list|(
name|ftype
parameter_list|,
name|type
parameter_list|,
name|NVTYPE
parameter_list|)
define|\
value|ftype									\ cnvlist_get_##type(void *cookiep, size_t *nitemsp)			\ {									\ 									\ 	if (nvpair_type(cookiep) != NV_TYPE_##NVTYPE) {			\ 		nvlist_report_missing(NV_TYPE_##NVTYPE,			\ 		    nvpair_name(cookiep));				\ 	}								\ 	return (nvpair_get_##type(cookiep, nitemsp));			\ }
end_define

begin_macro
name|CNVLIST_GET_ARRAY
argument_list|(
argument|const bool *
argument_list|,
argument|bool_array
argument_list|,
argument|BOOL_ARRAY
argument_list|)
end_macro

begin_macro
name|CNVLIST_GET_ARRAY
argument_list|(
argument|const uint64_t *
argument_list|,
argument|number_array
argument_list|,
argument|NUMBER_ARRAY
argument_list|)
end_macro

begin_macro
name|CNVLIST_GET_ARRAY
argument_list|(
argument|const char * const *
argument_list|,
argument|string_array
argument_list|,
argument|STRING_ARRAY
argument_list|)
end_macro

begin_macro
name|CNVLIST_GET_ARRAY
argument_list|(
argument|const nvlist_t * const *
argument_list|,
argument|nvlist_array
argument_list|,
argument|NVLIST_ARRAY
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_macro
name|CNVLIST_GET_ARRAY
argument_list|(
argument|const int *
argument_list|,
argument|descriptor_array
argument_list|,
argument|DESCRIPTOR_ARRAY
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CNVLIST_GET_ARRAY
end_undef

begin_function
specifier|const
name|void
modifier|*
name|cnvlist_get_binary
parameter_list|(
name|void
modifier|*
name|cookiep
parameter_list|,
name|size_t
modifier|*
name|sizep
parameter_list|)
block|{
if|if
condition|(
name|nvpair_type
argument_list|(
name|cookiep
argument_list|)
operator|!=
name|NV_TYPE_BINARY
condition|)
name|nvlist_report_missing
argument_list|(
name|NV_TYPE_BINARY
argument_list|,
name|nvpair_name
argument_list|(
name|cookiep
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|nvpair_get_binary
argument_list|(
name|cookiep
argument_list|,
name|sizep
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|CNVLIST_TAKE
parameter_list|(
name|ftype
parameter_list|,
name|type
parameter_list|,
name|NVTYPE
parameter_list|)
define|\
value|ftype									\ cnvlist_take_##type(nvlist_t *nvl, void *cookiep)			\ {									\ 	ftype value;							\ 									\ 	if (nvpair_type(cookiep) != NV_TYPE_##NVTYPE) {			\ 		nvlist_report_missing(NV_TYPE_##NVTYPE,			\ 		    nvpair_name(cookiep));				\ 	}								\ 	value = (ftype)(intptr_t)nvpair_get_##type(cookiep);		\ 	nvlist_remove_nvpair(nvl, cookiep);				\ 	nvpair_free_structure(cookiep);					\ 	return (value);							\ }
end_define

begin_macro
name|CNVLIST_TAKE
argument_list|(
argument|bool
argument_list|,
argument|bool
argument_list|,
argument|BOOL
argument_list|)
end_macro

begin_macro
name|CNVLIST_TAKE
argument_list|(
argument|uint64_t
argument_list|,
argument|number
argument_list|,
argument|NUMBER
argument_list|)
end_macro

begin_macro
name|CNVLIST_TAKE
argument_list|(
argument|char *
argument_list|,
argument|string
argument_list|,
argument|STRING
argument_list|)
end_macro

begin_macro
name|CNVLIST_TAKE
argument_list|(
argument|nvlist_t *
argument_list|,
argument|nvlist
argument_list|,
argument|NVLIST
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_macro
name|CNVLIST_TAKE
argument_list|(
argument|int
argument_list|,
argument|descriptor
argument_list|,
argument|DESCRIPTOR
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CNVLIST_TAKE
end_undef

begin_define
define|#
directive|define
name|CNVLIST_TAKE_ARRAY
parameter_list|(
name|ftype
parameter_list|,
name|type
parameter_list|,
name|NVTYPE
parameter_list|)
define|\
value|ftype									\ cnvlist_take_##type(nvlist_t *nvl, void *cookiep, size_t *nitemsp)	\ {									\ 	ftype value;							\ 									\ 	if (nvpair_type(cookiep) != NV_TYPE_##NVTYPE) {			\ 		nvlist_report_missing(NV_TYPE_##NVTYPE,			\ 		    nvpair_name(cookiep));				\ 	}								\ 	value = (ftype)(intptr_t)nvpair_get_##type(cookiep, nitemsp);	\ 	nvlist_remove_nvpair(nvl, cookiep);				\ 	nvpair_free_structure(cookiep);					\ 	return (value);							\ }
end_define

begin_macro
name|CNVLIST_TAKE_ARRAY
argument_list|(
argument|bool *
argument_list|,
argument|bool_array
argument_list|,
argument|BOOL_ARRAY
argument_list|)
end_macro

begin_macro
name|CNVLIST_TAKE_ARRAY
argument_list|(
argument|uint64_t *
argument_list|,
argument|number_array
argument_list|,
argument|NUMBER_ARRAY
argument_list|)
end_macro

begin_macro
name|CNVLIST_TAKE_ARRAY
argument_list|(
argument|char **
argument_list|,
argument|string_array
argument_list|,
argument|STRING_ARRAY
argument_list|)
end_macro

begin_macro
name|CNVLIST_TAKE_ARRAY
argument_list|(
argument|nvlist_t **
argument_list|,
argument|nvlist_array
argument_list|,
argument|NVLIST_ARRAY
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_expr_stmt
name|CNVLIST_TAKE_ARRAY
argument_list|(
name|int
operator|*
argument_list|,
name|descriptor_array
argument_list|,
name|DESCRIPTOR_ARRAY
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CNVLIST_TAKE_ARRAY
end_undef

begin_function
name|void
modifier|*
name|cnvlist_take_binary
parameter_list|(
name|nvlist_t
modifier|*
name|nvl
parameter_list|,
name|void
modifier|*
name|cookiep
parameter_list|,
name|size_t
modifier|*
name|sizep
parameter_list|)
block|{
name|void
modifier|*
name|value
decl_stmt|;
if|if
condition|(
name|nvpair_type
argument_list|(
name|cookiep
argument_list|)
operator|!=
name|NV_TYPE_BINARY
condition|)
name|nvlist_report_missing
argument_list|(
name|NV_TYPE_BINARY
argument_list|,
name|nvpair_name
argument_list|(
name|cookiep
argument_list|)
argument_list|)
expr_stmt|;
name|value
operator|=
operator|(
name|void
operator|*
operator|)
operator|(
name|intptr_t
operator|)
name|nvpair_get_binary
argument_list|(
name|cookiep
argument_list|,
name|sizep
argument_list|)
expr_stmt|;
name|nvlist_remove_nvpair
argument_list|(
name|nvl
argument_list|,
name|cookiep
argument_list|)
expr_stmt|;
name|nvpair_free_structure
argument_list|(
name|cookiep
argument_list|)
expr_stmt|;
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
name|CNVLIST_FREE
parameter_list|(
name|type
parameter_list|)
define|\
value|void									\ cnvlist_free_##type(nvlist_t *nvl, void *cookiep)			\ {									\ 									\ 	nvlist_free_nvpair(nvl, cookiep);				\ }
end_define

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|bool
argument_list|)
end_macro

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|number
argument_list|)
end_macro

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|string
argument_list|)
end_macro

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|nvlist
argument_list|)
end_macro

begin_expr_stmt
name|CNVLIST_FREE
argument_list|(
name|binary
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|bool_array
argument_list|)
end_macro

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|number_array
argument_list|)
end_macro

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|string_array
argument_list|)
end_macro

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|nvlist_array
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|descriptor
argument_list|)
end_macro

begin_macro
name|CNVLIST_FREE
argument_list|(
argument|descriptor_array
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CNVLIST_FREE
end_undef

end_unit

