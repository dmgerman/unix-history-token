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
comment|// Flags:
end_comment

begin_comment
comment|// * __STL_NO_BOOL: defined if the compiler doesn't have bool as a builtin
end_comment

begin_comment
comment|//   type.
end_comment

begin_comment
comment|// * __STL_HAS_WCHAR_T: defined if the compier has wchar_t as a builtin type.
end_comment

begin_comment
comment|// * __STL_NO_DRAND48: defined if the compiler doesn't have the drand48
end_comment

begin_comment
comment|//   function.
end_comment

begin_comment
comment|// * __STL_STATIC_TEMPLATE_MEMBER_BUG: defined if the compiler can't handle
end_comment

begin_comment
comment|//   static members of template classes.
end_comment

begin_comment
comment|// * __STL_CLASS_PARTIAL_SPECIALIZATION: defined if the compiler supports
end_comment

begin_comment
comment|//   partial specialization of template classes.
end_comment

begin_comment
comment|// * __STL_PARTIAL_SPECIALIZATION_SYNTAX: defined if the compiler
end_comment

begin_comment
comment|//   supports partial specialization syntax for full specialization of
end_comment

begin_comment
comment|//   class templates.  (Even if it doesn't actually support partial
end_comment

begin_comment
comment|//   specialization itself.)
end_comment

begin_comment
comment|// * __STL_FUNCTION_TMPL_PARTIAL_ORDER: defined if the compiler supports
end_comment

begin_comment
comment|//   partial ordering of function templates.  (a.k.a partial specialization
end_comment

begin_comment
comment|//   of function templates.)
end_comment

begin_comment
comment|// * __STL_MEMBER_TEMPLATES: defined if the compiler supports template
end_comment

begin_comment
comment|//   member functions of classes.
end_comment

begin_comment
comment|// * __STL_MEMBER_TEMPLATE_CLASSES: defined if the compiler supports
end_comment

begin_comment
comment|//   nested classes that are member templates of other classes.
end_comment

begin_comment
comment|// * __STL_EXPLICIT_FUNCTION_TMPL_ARGS: defined if the compiler
end_comment

begin_comment
comment|//   supports calling a function template by providing its template
end_comment

begin_comment
comment|//   arguments explicitly.
end_comment

begin_comment
comment|// * __STL_LIMITED_DEFAULT_TEMPLATES: defined if the compiler is unable
end_comment

begin_comment
comment|//   to handle default template parameters that depend on previous template
end_comment

begin_comment
comment|//   parameters.
end_comment

begin_comment
comment|// * __STL_NON_TYPE_TMPL_PARAM_BUG: defined if the compiler has trouble with
end_comment

begin_comment
comment|//   function template argument deduction for non-type template parameters.
end_comment

begin_comment
comment|// * __SGI_STL_NO_ARROW_OPERATOR: defined if the compiler is unable
end_comment

begin_comment
comment|//   to support the -> operator for iterators.
end_comment

begin_comment
comment|// * __STL_USE_EXCEPTIONS: defined if the compiler (in the current compilation
end_comment

begin_comment
comment|//   mode) supports exceptions.
end_comment

begin_comment
comment|// * __STL_USE_NAMESPACES: defined if the compiler has the necessary
end_comment

begin_comment
comment|//   support for namespaces.
end_comment

begin_comment
comment|// * __STL_NO_EXCEPTION_HEADER: defined if the compiler does not have a
end_comment

begin_comment
comment|//   standard-conforming header<exception>.
end_comment

begin_comment
comment|// * __STL_SGI_THREADS: defined if this is being compiled for an SGI IRIX
end_comment

begin_comment
comment|//   system in multithreaded mode, using native SGI threads instead of
end_comment

begin_comment
comment|//   pthreads.
end_comment

begin_comment
comment|// * __STL_WIN32THREADS: defined if this is being compiled on a WIN32
end_comment

begin_comment
comment|//   compiler in multithreaded mode.
end_comment

begin_comment
comment|// * __STL_LONG_LONG if the compiler has long long and unsigned long long
end_comment

begin_comment
comment|//   types.  (They're not in the C++ standard, but they are expected to be
end_comment

begin_comment
comment|//   included in the forthcoming C9X standard.)
end_comment

begin_comment
comment|// User-settable macros that control compilation:
end_comment

begin_comment
comment|// * __STL_USE_SGI_ALLOCATORS: if defined, then the STL will use older
end_comment

begin_comment
comment|//   SGI-style allocators, instead of standard-conforming allocators,
end_comment

begin_comment
comment|//   even if the compiler supports all of the language features needed
end_comment

begin_comment
comment|//   for standard-conforming allocators.
end_comment

begin_comment
comment|// * __STL_NO_NAMESPACES: if defined, don't put the library in namespace
end_comment

begin_comment
comment|//   std, even if the compiler supports namespaces.
end_comment

begin_comment
comment|// * __STL_ASSERTIONS: if defined, then enable runtime checking through the
end_comment

begin_comment
comment|//   __stl_assert macro.
end_comment

begin_comment
comment|// * _PTHREADS: if defined, use Posix threads for multithreading support.
end_comment

begin_comment
comment|// * _NOTHREADS: if defined, don't use any multithreading support.
end_comment

begin_comment
comment|// Other macros defined by this file:
end_comment

begin_comment
comment|// * bool, true, and false, if __STL_NO_BOOL is defined.
end_comment

begin_comment
comment|// * typename, as a null macro if it's not already a keyword.
end_comment

begin_comment
comment|// * explicit, as a null macro if it's not already a keyword.
end_comment

begin_comment
comment|// * namespace-related macros (__STD, __STL_BEGIN_NAMESPACE, etc.)
end_comment

begin_comment
comment|// * exception-related macros (__STL_TRY, __STL_UNWIND, etc.)
end_comment

begin_comment
comment|// * __stl_assert, either as a test or as a null macro, depending on
end_comment

begin_comment
comment|//   whether or not __STL_ASSERTIONS is defined.
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

begin_ifdef
ifdef|#
directive|ifdef
name|_SOLTHREADS
end_ifdef

begin_define
define|#
directive|define
name|__STL_SOLTHREADS
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
name|__STL_NO_BOOL
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
name|_WCHAR_T_IS_KEYWORD
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_HAS_WCHAR_T
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

begin_define
define|#
directive|define
name|__STL_MEMBER_TEMPLATE_CLASSES
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
name|_MEMBER_TEMPLATE_KEYWORD
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_MEMBER_TEMPLATE_KEYWORD
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
literal|730
operator|)
operator|&&
name|defined
argument_list|(
name|_MIPS_SIM
argument_list|)
operator|&&
name|_MIPS_SIM
operator|!=
name|_ABIO32
end_if

begin_define
define|#
directive|define
name|__STL_MEMBER_TEMPLATE_KEYWORD
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
name|__STL_HAS_NAMESPACES
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
operator|<
literal|721
operator|)
end_if

begin_define
define|#
directive|define
name|__STL_NO_EXCEPTION_HEADER
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LONGLONG
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SGIAPI
argument_list|)
operator|&&
name|_SGIAPI
end_if

begin_define
define|#
directive|define
name|__STL_LONG_LONG
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

begin_define
define|#
directive|define
name|__STL_HAS_WCHAR_T
end_define

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
name|__STL_MEMBER_TEMPLATES
end_define

begin_define
define|#
directive|define
name|__STL_MEMBER_TEMPLATE_CLASSES
end_define

begin_define
define|#
directive|define
name|__STL_EXPLICIT_FUNCTION_TMPL_ARGS
end_define

begin_define
define|#
directive|define
name|__STL_HAS_NAMESPACES
end_define

begin_define
define|#
directive|define
name|__STL_NO_NAMESPACES
end_define

begin_define
define|#
directive|define
name|__SGI_STL_USE_AUTO_PTR_CONVERSIONS
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
name|__linux__
argument_list|)
end_if

begin_comment
comment|/* glibc pre 2.0 is very buggy. We have to disable thread for it.         It should be upgraded to glibc 2.0 or later. */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STRICT_ANSI__
end_ifdef

begin_comment
comment|/* Work around a bug in the glibc 2.0.x pthread.h.  */
end_comment

begin_define
define|#
directive|define
name|sigset_t
value|__sigset_t
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|__STRICT_ANSI__
end_ifndef

begin_define
define|#
directive|define
name|__STL_LONG_LONG
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
name|__STL_NO_BOOL
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
name|__STL_MEMBER_TEMPLATE_CLASSES
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
name|__STL_HAS_NAMESPACES
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
name|__MINGW32__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_NO_DRAND48
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
name|__CYGWIN__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_NO_DRAND48
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

begin_comment
comment|/* 1000 is version 4.0, 1100 is 5.0, 1200 is 6.0. */
end_comment

begin_define
define|#
directive|define
name|__STL_NEED_EXPLICIT
end_define

begin_define
define|#
directive|define
name|__STL_NO_BOOL
end_define

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

begin_define
define|#
directive|define
name|__STL_DONT_USE_BOOL_TYPEDEF
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

begin_if
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1200
end_if

begin_define
define|#
directive|define
name|__STL_PARTIAL_SPECIALIZATION_SYNTAX
end_define

begin_define
define|#
directive|define
name|__STL_HAS_NAMESPACES
end_define

begin_define
define|#
directive|define
name|__STL_NO_NAMESPACES
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
name|__STL_NO_BOOL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STL_DONT_USE_BOOL_TYPEDEF
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
name|__STL_MEMBER_TEMPLATE_KEYWORD
end_ifdef

begin_define
define|#
directive|define
name|__STL_TEMPLATE
value|template
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STL_TEMPLATE
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STL_CLASS_PARTIAL_SPECIALIZATION
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__STL_PARTIAL_SPECIALIZATION_SYNTAX
argument_list|)
end_if

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
comment|// Use standard-conforming allocators if we have the necessary language
end_comment

begin_comment
comment|// features.  __STL_USE_SGI_ALLOCATORS is a hook so that users can
end_comment

begin_comment
comment|// disable new-style allocators, and continue to use the same kind of
end_comment

begin_comment
comment|// allocators as before, without having to edit library headers.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STL_CLASS_PARTIAL_SPECIALIZATION
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|__STL_MEMBER_TEMPLATES
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|__STL_MEMBER_TEMPLATE_CLASSES
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__STL_NO_BOOL
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__STL_NON_TYPE_TMPL_PARAM_BUG
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__STL_LIMITED_DEFAULT_TEMPLATES
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__STL_USE_SGI_ALLOCATORS
argument_list|)
end_if

begin_define
define|#
directive|define
name|__STL_USE_STD_ALLOCATORS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__STL_DEFAULT_ALLOCATOR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_USE_STD_ALLOCATORS
end_ifdef

begin_define
define|#
directive|define
name|__STL_DEFAULT_ALLOCATOR
parameter_list|(
name|T
parameter_list|)
value|allocator<T>
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STL_DEFAULT_ALLOCATOR
parameter_list|(
name|T
parameter_list|)
value|alloc
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
name|__STL_HAS_NAMESPACES
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

begin_define
define|#
directive|define
name|__STL_USE_NAMESPACES
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

begin_undef
undef|#
directive|undef
name|__STL_USE_NAMESPACES
end_undef

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
name|__STL_THROW
parameter_list|(
name|x
parameter_list|)
value|throw x
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
name|__STL_THROW
parameter_list|(
name|x
parameter_list|)
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

