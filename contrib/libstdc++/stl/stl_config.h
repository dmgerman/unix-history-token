begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  * Copyright (c) 1997  * Silicon Graphics  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STL_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|__STL_CONFIG_H
end_define

begin_comment
comment|// What this file does.
end_comment

begin_comment
comment|//  (1)  Defines bool, true, and false if the compiler doesn't do so already.
end_comment

begin_comment
comment|//  (2)  Defines __STL_NO_DRAND48 if the compiler's standard library does
end_comment

begin_comment
comment|//       not support the drand48() function.
end_comment

begin_comment
comment|//  (3)  Defines __STL_STATIC_TEMPLATE_MEMBER_BUG if the compiler can't
end_comment

begin_comment
comment|//       handle static members of template classes.
end_comment

begin_comment
comment|//  (4)  Defines 'typename' as a null macro if the compiler does not support
end_comment

begin_comment
comment|//       the typename keyword.
end_comment

begin_comment
comment|//  (5)  Defines __STL_CLASS_PARTIAL_SPECIALIZATION if the compiler
end_comment

begin_comment
comment|//       supports partial specialization of class templates.
end_comment

begin_comment
comment|//  (6)  Defines __STL_FUNCTION_TMPL_PARTIAL_ORDER if the compiler supports
end_comment

begin_comment
comment|//       partial ordering of function templates (a.k.a partial specialization
end_comment

begin_comment
comment|//       of function templates.
end_comment

begin_comment
comment|//  (7)  Defines __STL_EXPLICIT_FUNCTION_TMPL_ARGS if the compiler
end_comment

begin_comment
comment|//       supports calling a function template by providing its template
end_comment

begin_comment
comment|//       arguments explicitly.
end_comment

begin_comment
comment|//  (8)  Defines __STL_MEMBER_TEMPLATES if the compiler supports
end_comment

begin_comment
comment|//       template members of classes.
end_comment

begin_comment
comment|//  (9)  Defines 'explicit' as a null macro if the compiler does not support
end_comment

begin_comment
comment|//       the explicit keyword.
end_comment

begin_comment
comment|//  (10) Defines __STL_LIMITED_DEFAULT_TEMPLATES if the compiler is
end_comment

begin_comment
comment|//       unable to handle default template parameters that depend on
end_comment

begin_comment
comment|//       previous template parameters.
end_comment

begin_comment
comment|//  (11) Defines __STL_NON_TYPE_TMPL_PARAM_BUG if the compiler has
end_comment

begin_comment
comment|//       trouble performing function template argument deduction for
end_comment

begin_comment
comment|//       non-type template parameters.
end_comment

begin_comment
comment|//  (12) Defines __SGI_STL_NO_ARROW_OPERATOR if the compiler is unable
end_comment

begin_comment
comment|//       to support the -> operator for iterators.
end_comment

begin_comment
comment|//  (13) Defines __STL_USE_EXCEPTIONS if the compiler (in the current
end_comment

begin_comment
comment|//       compilation mode) supports exceptions.
end_comment

begin_comment
comment|//  (14) Define __STL_USE_NAMESPACES if we're putting the STL into a
end_comment

begin_comment
comment|//       namespace.
end_comment

begin_comment
comment|//  (15) Defines __STL_SGI_THREADS if this is being compiled on an SGI
end_comment

begin_comment
comment|//       compiler, and if the user hasn't selected pthreads or no threads
end_comment

begin_comment
comment|//       instead.
end_comment

begin_comment
comment|//  (16) Defines __STL_WIN32THREADS if this is being compiled on a
end_comment

begin_comment
comment|//       WIN32 compiler in multithreaded mode.
end_comment

begin_comment
comment|//  (17) Define namespace-related macros (__STD, __STL_BEGIN_NAMESPACE, etc.)
end_comment

begin_comment
comment|//       apropriately.
end_comment

begin_comment
comment|//  (18) Define exception-related macros (__STL_TRY, __STL_UNWIND, etc.)
end_comment

begin_comment
comment|//       appropriately.
end_comment

begin_comment
comment|//  (19) Defines __stl_assert either as a test or as a null macro,
end_comment

begin_comment
comment|//       depending on whether or not __STL_ASSERTIONS is defined.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PTHREADS
end_ifdef

begin_define
define|#
directive|define
name|__STL_PTHREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sgi
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_BOOL
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_NEED_BOOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_TYPENAME_IS_KEYWORD
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_NEED_TYPENAME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_PARTIAL_SPECIALIZATION_OF_CLASS_TEMPLATES
end_ifdef

begin_define
define|#
directive|define
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MEMBER_TEMPLATES
end_ifdef

begin_define
define|#
directive|define
name|__STL_MEMBER_TEMPLATES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_EXPLICIT_IS_KEYWORD
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_NEED_EXPLICIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__EXCEPTIONS
end_ifdef

begin_define
define|#
directive|define
name|__STL_USE_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|_COMPILER_VERSION
operator|>=
literal|721
operator|)
operator|&&
name|defined
argument_list|(
name|_NAMESPACES
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_USE_NAMESPACES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_NOTHREADS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STL_PTHREADS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_SGI_THREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|8
operator|)
end_if

begin_define
define|#
directive|define
name|__STL_STATIC_TEMPLATE_MEMBER_BUG
end_define

begin_define
define|#
directive|define
name|__STL_NEED_TYPENAME
end_define

begin_define
define|#
directive|define
name|__STL_NEED_EXPLICIT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_define

begin_define
define|#
directive|define
name|__STL_FUNCTION_TMPL_PARTIAL_ORDER
end_define

begin_define
define|#
directive|define
name|__STL_EXPLICIT_FUNCTION_TMPL_ARGS
end_define

begin_define
define|#
directive|define
name|__STL_MEMBER_TEMPLATES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* glibc pre 2.0 is very buggy. We have to disable thread for it.        It should be upgraded to glibc 2.0 or later. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_NOTHREADS
argument_list|)
operator|&&
name|__GLIBC__
operator|>=
literal|2
operator|&&
name|defined
argument_list|(
name|_G_USING_THUNKS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_PTHREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__EXCEPTIONS
end_ifdef

begin_define
define|#
directive|define
name|__STL_USE_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SUNPRO_CC
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_NEED_BOOL
end_define

begin_define
define|#
directive|define
name|__STL_NEED_TYPENAME
end_define

begin_define
define|#
directive|define
name|__STL_NEED_EXPLICIT
end_define

begin_define
define|#
directive|define
name|__STL_USE_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__COMO__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_MEMBER_TEMPLATES
end_define

begin_define
define|#
directive|define
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_define

begin_define
define|#
directive|define
name|__STL_USE_EXCEPTIONS
end_define

begin_define
define|#
directive|define
name|__STL_USE_NAMESPACES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_if
if|#
directive|if
name|_MSC_VER
operator|>
literal|1000
end_if

begin_include
include|#
directive|include
file|<yvals.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STL_NEED_BOOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__STL_NO_DRAND48
end_define

begin_define
define|#
directive|define
name|__STL_NEED_TYPENAME
end_define

begin_if
if|#
directive|if
name|_MSC_VER
operator|<
literal|1100
end_if

begin_define
define|#
directive|define
name|__STL_NEED_EXPLICIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__STL_NON_TYPE_TMPL_PARAM_BUG
end_define

begin_define
define|#
directive|define
name|__SGI_STL_NO_ARROW_OPERATOR
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_CPPUNWIND
end_ifdef

begin_define
define|#
directive|define
name|__STL_USE_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MT
end_ifdef

begin_define
define|#
directive|define
name|__STL_WIN32THREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_NO_DRAND48
end_define

begin_define
define|#
directive|define
name|__STL_NEED_TYPENAME
end_define

begin_define
define|#
directive|define
name|__STL_LIMITED_DEFAULT_TEMPLATES
end_define

begin_define
define|#
directive|define
name|__SGI_STL_NO_ARROW_OPERATOR
end_define

begin_define
define|#
directive|define
name|__STL_NON_TYPE_TMPL_PARAM_BUG
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_CPPUNWIND
end_ifdef

begin_define
define|#
directive|define
name|__STL_USE_EXCEPTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__MT__
end_ifdef

begin_define
define|#
directive|define
name|__STL_WIN32THREADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STL_NEED_BOOL
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_NEED_TYPENAME
end_ifdef

begin_define
define|#
directive|define
name|typename
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_NEED_EXPLICIT
end_ifdef

begin_define
define|#
directive|define
name|explicit
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_EXPLICIT_FUNCTION_TMPL_ARGS
end_ifdef

begin_define
define|#
directive|define
name|__STL_NULL_TMPL_ARGS
value|<>
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STL_NULL_TMPL_ARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_ifdef

begin_define
define|#
directive|define
name|__STL_TEMPLATE_NULL
value|template<>
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STL_TEMPLATE_NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __STL_NO_NAMESPACES is a hook so that users can disable namespaces
end_comment

begin_comment
comment|// without having to edit library headers.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STL_USE_NAMESPACES
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STL_NO_NAMESPACES
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STD
value|std
end_define

begin_define
define|#
directive|define
name|__STL_BEGIN_NAMESPACE
value|namespace std {
end_define

begin_define
define|#
directive|define
name|__STL_END_NAMESPACE
value|}
end_define

begin_define
define|#
directive|define
name|__STL_USE_NAMESPACE_FOR_RELOPS
end_define

begin_define
define|#
directive|define
name|__STL_BEGIN_RELOPS_NAMESPACE
value|namespace std {
end_define

begin_define
define|#
directive|define
name|__STL_END_RELOPS_NAMESPACE
value|}
end_define

begin_define
define|#
directive|define
name|__STD_RELOPS
value|std
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STD
end_define

begin_define
define|#
directive|define
name|__STL_BEGIN_NAMESPACE
end_define

begin_define
define|#
directive|define
name|__STL_END_NAMESPACE
end_define

begin_undef
undef|#
directive|undef
name|__STL_USE_NAMESPACE_FOR_RELOPS
end_undef

begin_define
define|#
directive|define
name|__STL_BEGIN_RELOPS_NAMESPACE
end_define

begin_define
define|#
directive|define
name|__STL_END_RELOPS_NAMESPACE
end_define

begin_define
define|#
directive|define
name|__STD_RELOPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_USE_EXCEPTIONS
end_ifdef

begin_define
define|#
directive|define
name|__STL_TRY
value|try
end_define

begin_define
define|#
directive|define
name|__STL_CATCH_ALL
value|catch(...)
end_define

begin_define
define|#
directive|define
name|__STL_RETHROW
value|throw
end_define

begin_define
define|#
directive|define
name|__STL_NOTHROW
value|throw()
end_define

begin_define
define|#
directive|define
name|__STL_UNWIND
parameter_list|(
name|action
parameter_list|)
value|catch(...) { action; throw; }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STL_TRY
end_define

begin_define
define|#
directive|define
name|__STL_CATCH_ALL
value|if (false)
end_define

begin_define
define|#
directive|define
name|__STL_RETHROW
end_define

begin_define
define|#
directive|define
name|__STL_NOTHROW
end_define

begin_define
define|#
directive|define
name|__STL_UNWIND
parameter_list|(
name|action
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_ASSERTIONS
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|__stl_assert
parameter_list|(
name|expr
parameter_list|)
define|\
value|if (!(expr)) { fprintf(stderr, "%s:%d STL assertion failure: %s\n", \ 			  __FILE__, __LINE__, # expr); abort(); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__stl_assert
parameter_list|(
name|expr
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_CONFIG_H */
end_comment

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

