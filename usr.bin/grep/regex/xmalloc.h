begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*   xmalloc.h - Simple malloc debugging library API    This software is released under a BSD-style license.   See the file LICENSE for details and copyright.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|_XMALLOC_H
value|1
end_define

begin_function_decl
name|void
modifier|*
name|xmalloc_impl
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xcalloc_impl
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfree_impl
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xrealloc_impl
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|new_size
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xmalloc_dump_leaks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xmalloc_configure
parameter_list|(
name|int
name|fail_after
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|XMALLOC_INTERNAL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DEBUGGING
end_ifdef

begin_comment
comment|/* Version 2.4 and later of GCC define a magical variable `__PRETTY_FUNCTION__'    which contains the name of the function currently being defined. #  define __XMALLOC_FUNCTION	 __PRETTY_FUNCTION__    This is broken in G++ before version 2.6.    C9x has a similar variable called __func__, but prefer the GCC one since    it demangles C++ function names.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
expr|\
operator|&&
name|__GNUC_MINOR__
operator|>=
operator|(
name|defined
name|__cplusplus
condition|?
literal|6
expr|:
literal|4
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|__XMALLOC_FUNCTION
value|__PRETTY_FUNCTION__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__XMALLOC_FUNCTION
value|((const char *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
name|__STDC_VERSION__
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
end_if

begin_define
define|#
directive|define
name|__XMALLOC_FUNCTION
value|__func__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__XMALLOC_FUNCTION
value|((const char *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|xmalloc
parameter_list|(
name|size
parameter_list|)
value|xmalloc_impl(size, __FILE__, __LINE__, \ 				   __XMALLOC_FUNCTION)
end_define

begin_define
define|#
directive|define
name|xcalloc
parameter_list|(
name|nmemb
parameter_list|,
name|size
parameter_list|)
value|xcalloc_impl(nmemb, size, __FILE__, __LINE__, \ 					  __XMALLOC_FUNCTION)
end_define

begin_define
define|#
directive|define
name|xfree
parameter_list|(
name|ptr
parameter_list|)
value|xfree_impl(ptr, __FILE__, __LINE__, __XMALLOC_FUNCTION)
end_define

begin_define
define|#
directive|define
name|xrealloc
parameter_list|(
name|ptr
parameter_list|,
name|new_size
parameter_list|)
value|xrealloc_impl(ptr, new_size, __FILE__, \ 					      __LINE__, __XMALLOC_FUNCTION)
end_define

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_undef
undef|#
directive|undef
name|calloc
end_undef

begin_undef
undef|#
directive|undef
name|free
end_undef

begin_undef
undef|#
directive|undef
name|realloc
end_undef

begin_define
define|#
directive|define
name|malloc
value|USE_XMALLOC_INSTEAD_OF_MALLOC
end_define

begin_define
define|#
directive|define
name|calloc
value|USE_XCALLOC_INSTEAD_OF_CALLOC
end_define

begin_define
define|#
directive|define
name|free
value|USE_XFREE_INSTEAD_OF_FREE
end_define

begin_define
define|#
directive|define
name|realloc
value|USE_XREALLOC_INSTEAD_OF_REALLOC
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !MALLOC_DEBUGGING */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|xmalloc
parameter_list|(
name|size
parameter_list|)
value|malloc(size)
end_define

begin_define
define|#
directive|define
name|xcalloc
parameter_list|(
name|nmemb
parameter_list|,
name|size
parameter_list|)
value|calloc(nmemb, size)
end_define

begin_define
define|#
directive|define
name|xfree
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
end_define

begin_define
define|#
directive|define
name|xrealloc
parameter_list|(
name|ptr
parameter_list|,
name|new_size
parameter_list|)
value|realloc(ptr, new_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MALLOC_DEBUGGING */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !XMALLOC_INTERNAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XMALLOC_H */
end_comment

begin_comment
comment|/* EOF */
end_comment

end_unit

