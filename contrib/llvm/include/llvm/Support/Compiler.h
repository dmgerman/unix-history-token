begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Compiler.h - Compiler abstraction support --*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines several macros, based on the current compiler.  This allows
end_comment

begin_comment
comment|// use of compiler-specific features in a way that remains portable.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_COMPILER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_COMPILER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__has_extension
end_ifndef

begin_define
define|#
directive|define
name|__has_extension
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__has_attribute
end_ifndef

begin_define
define|#
directive|define
name|__has_attribute
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__has_builtin
end_ifndef

begin_define
define|#
directive|define
name|__has_builtin
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_GNUC_PREREQ
end_comment

begin_comment
comment|/// \brief Extend the default __GNUC_PREREQ even if glibc's features.h isn't
end_comment

begin_comment
comment|/// available.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_GNUC_PREREQ
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC_MINOR__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC_PATCHLEVEL__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_GNUC_PREREQ
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|,
name|patch
parameter_list|)
define|\
value|((__GNUC__<< 20) + (__GNUC_MINOR__<< 10) + __GNUC_PATCHLEVEL__>= \      ((maj)<< 20) + ((min)<< 10) + (patch))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC_MINOR__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_GNUC_PREREQ
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|,
name|patch
parameter_list|)
define|\
value|((__GNUC__<< 20) + (__GNUC_MINOR__<< 10)>= ((maj)<< 20) + ((min)<< 10))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_GNUC_PREREQ
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|,
name|patch
parameter_list|)
value|0
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
comment|/// \macro LLVM_MSC_PREREQ
end_comment

begin_comment
comment|/// \brief Is the compiler MSVC of at least the specified version?
end_comment

begin_comment
comment|/// The common \param version values to check for are:
end_comment

begin_comment
comment|///  * 1700: Microsoft Visual Studio 2012 / 11.0
end_comment

begin_comment
comment|///  * 1800: Microsoft Visual Studio 2013 / 12.0
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|LLVM_MSC_PREREQ
parameter_list|(
name|version
parameter_list|)
value|(_MSC_VER>= (version))
end_define

begin_comment
comment|// We require at least MSVC 2012.
end_comment

begin_if
if|#
directive|if
operator|!
name|LLVM_MSC_PREREQ
argument_list|(
literal|1700
argument_list|)
end_if

begin_error
error|#
directive|error
error|LLVM requires at least MSVC 2012.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_MSC_PREREQ
parameter_list|(
name|version
parameter_list|)
value|0
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
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|||
name|LLVM_MSC_PREREQ
argument_list|(
literal|1900
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_NOEXCEPT
value|noexcept
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_NOEXCEPT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Does the compiler support r-value reference *this?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sadly, this is separate from just r-value reference support because GCC
end_comment

begin_comment
comment|/// implemented this later than everything else.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_rvalue_references
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|8
operator|,
literal|1
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_HAS_RVALUE_REFERENCE_THIS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_HAS_RVALUE_REFERENCE_THIS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_HAS_VARIADIC_TEMPLATES
end_comment

begin_comment
comment|/// \brief Does this compiler support variadic templates.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implies LLVM_HAS_RVALUE_REFERENCES and the existence of std::forward.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_variadic_templates
argument_list|)
operator|||
name|LLVM_MSC_PREREQ
argument_list|(
literal|1800
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_HAS_VARIADIC_TEMPLATES
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_HAS_VARIADIC_TEMPLATES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// Expands to '&' if r-value references are supported.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can be used to provide l-value/r-value overrides of member functions.
end_comment

begin_comment
comment|/// The r-value override should be guarded by LLVM_HAS_RVALUE_REFERENCE_THIS
end_comment

begin_if
if|#
directive|if
name|LLVM_HAS_RVALUE_REFERENCE_THIS
end_if

begin_define
define|#
directive|define
name|LLVM_LVALUE_FUNCTION
value|&
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_LVALUE_FUNCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_DELETED_FUNCTION - Expands to = delete if the compiler supports it.
end_comment

begin_comment
comment|/// Use to mark functions as uncallable. Member functions with this should
end_comment

begin_comment
comment|/// be declared private so that some behavior is kept in C++03 mode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// class DontCopy {
end_comment

begin_comment
comment|/// private:
end_comment

begin_comment
comment|///   DontCopy(const DontCopy&) LLVM_DELETED_FUNCTION;
end_comment

begin_comment
comment|///   DontCopy&operator =(const DontCopy&) LLVM_DELETED_FUNCTION;
end_comment

begin_comment
comment|/// public:
end_comment

begin_comment
comment|///   ...
end_comment

begin_comment
comment|/// };
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_deleted_functions
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__GXX_EXPERIMENTAL_CXX0X__
argument_list|)
operator|||
name|LLVM_MSC_PREREQ
argument_list|(
literal|1800
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_DELETED_FUNCTION
value|= delete
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_DELETED_FUNCTION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_constexpr
argument_list|)
operator|||
name|defined
argument_list|(
name|__GXX_EXPERIMENTAL_CXX0X__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_CONSTEXPR
value|constexpr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_CONSTEXPR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_LIBRARY_VISIBILITY - If a class marked with this attribute is linked
end_comment

begin_comment
comment|/// into a shared library, then the class should be private to the library and
end_comment

begin_comment
comment|/// not accessible from outside it.  Can also be used to mark variables and
end_comment

begin_comment
comment|/// functions, making them private to any shared library they are linked into.
end_comment

begin_comment
comment|/// On PE/COFF targets, library visibility is the default, so this isn't needed.
end_comment

begin_if
if|#
directive|if
operator|(
name|__has_attribute
argument_list|(
name|visibility
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
operator|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_LIBRARY_VISIBILITY
value|__attribute__ ((visibility("hidden")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_LIBRARY_VISIBILITY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|sentinel
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|3
operator|,
literal|0
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_END_WITH_NULL
value|__attribute__((sentinel))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_END_WITH_NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|used
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|3
operator|,
literal|1
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_USED
value|__attribute__((__used__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_USED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|warn_unused_result
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|3
operator|,
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_UNUSED_RESULT
value|__attribute__((__warn_unused_result__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_UNUSED_RESULT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Some compilers warn about unused functions. When a function is sometimes
end_comment

begin_comment
comment|// used or not depending on build settings (e.g. a function only called from
end_comment

begin_comment
comment|// within "assert"), this attribute can be used to suppress such warnings.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// However, it shouldn't be used for unused *variables*, as those have a much
end_comment

begin_comment
comment|// more portable solution:
end_comment

begin_comment
comment|//   (void)unused_var_name;
end_comment

begin_comment
comment|// Prefer cast-to-void wherever it is sufficient.
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|unused
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|3
operator|,
literal|1
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_UNUSED
value|__attribute__((__unused__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FIXME: Provide this for PE/COFF targets.
end_comment

begin_if
if|#
directive|if
operator|(
name|__has_attribute
argument_list|(
name|weak
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
operator|)
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_WEAK
value|__attribute__((__weak__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_WEAK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Prior to clang 3.2, clang did not accept any spelling of
end_comment

begin_comment
comment|// __has_attribute(const), so assume it is supported.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|// aka 'CONST' but following LLVM Conventions.
end_comment

begin_define
define|#
directive|define
name|LLVM_READNONE
value|__attribute__((__const__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_READNONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|pure
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|// aka 'PURE' but following LLVM Conventions.
end_comment

begin_define
define|#
directive|define
name|LLVM_READONLY
value|__attribute__((__pure__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_READONLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_expect
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_LIKELY
parameter_list|(
name|EXPR
parameter_list|)
value|__builtin_expect((bool)(EXPR), true)
end_define

begin_define
define|#
directive|define
name|LLVM_UNLIKELY
parameter_list|(
name|EXPR
parameter_list|)
value|__builtin_expect((bool)(EXPR), false)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_LIKELY
parameter_list|(
name|EXPR
parameter_list|)
value|(EXPR)
end_define

begin_define
define|#
directive|define
name|LLVM_UNLIKELY
parameter_list|(
name|EXPR
parameter_list|)
value|(EXPR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// C++ doesn't support 'extern template' of template specializations.  GCC does,
end_comment

begin_comment
comment|// but requires __extension__ before it.  In the header, use this:
end_comment

begin_comment
comment|//   EXTERN_TEMPLATE_INSTANTIATION(class foo<bar>);
end_comment

begin_comment
comment|// in the .cpp file, use this:
end_comment

begin_comment
comment|//   TEMPLATE_INSTANTIATION(class foo<bar>);
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|EXTERN_TEMPLATE_INSTANTIATION
parameter_list|(
name|X
parameter_list|)
value|__extension__ extern template X
end_define

begin_define
define|#
directive|define
name|TEMPLATE_INSTANTIATION
parameter_list|(
name|X
parameter_list|)
value|template X
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN_TEMPLATE_INSTANTIATION
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TEMPLATE_INSTANTIATION
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_ATTRIBUTE_NOINLINE - On compilers where we have a directive to do so,
end_comment

begin_comment
comment|/// mark a method "not for inlining".
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|noinline
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|3
operator|,
literal|4
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_NOINLINE
value|__attribute__((noinline))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_NOINLINE
value|__declspec(noinline)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_NOINLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_ATTRIBUTE_ALWAYS_INLINE - On compilers where we have a directive to do
end_comment

begin_comment
comment|/// so, mark a method "always inline" because it is performance sensitive. GCC
end_comment

begin_comment
comment|/// 3.4 supported this but is buggy in various cases and produces unimplemented
end_comment

begin_comment
comment|/// errors, just use it in GCC 4.0 and later.
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|always_inline
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|0
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
value|inline __attribute__((always_inline))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
value|__forceinline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_ALWAYS_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_NORETURN
value|__attribute__((noreturn))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_NORETURN
value|__declspec(noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_NORETURN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|returns_nonnull
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|9
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_RETURNS_NONNULL
value|__attribute__((returns_nonnull))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_RETURNS_NONNULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_EXTENSION - Support compilers where we have a keyword to suppress
end_comment

begin_comment
comment|/// pedantic diagnostics.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|LLVM_EXTENSION
value|__extension__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_EXTENSION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ATTRIBUTE_DEPRECATED(decl, "message")
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|attribute_deprecated_with_message
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_DEPRECATED
parameter_list|(
name|decl
parameter_list|,
name|message
parameter_list|)
define|\
value|decl __attribute__((deprecated(message)))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_DEPRECATED
parameter_list|(
name|decl
parameter_list|,
name|message
parameter_list|)
define|\
value|decl __attribute__((deprecated))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_DEPRECATED
parameter_list|(
name|decl
parameter_list|,
name|message
parameter_list|)
define|\
value|__declspec(deprecated(message)) decl
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_DEPRECATED
parameter_list|(
name|decl
parameter_list|,
name|message
parameter_list|)
define|\
value|decl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_BUILTIN_UNREACHABLE - On compilers which support it, expands
end_comment

begin_comment
comment|/// to an expression which states that it is undefined behavior for the
end_comment

begin_comment
comment|/// compiler to reach this point.  Otherwise is not defined.
end_comment

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_unreachable
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|5
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_BUILTIN_UNREACHABLE
value|__builtin_unreachable()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_BUILTIN_UNREACHABLE
value|__assume(false)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_BUILTIN_TRAP - On compilers which support it, expands to an expression
end_comment

begin_comment
comment|/// which causes the program to exit abnormally.
end_comment

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_trap
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|3
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_BUILTIN_TRAP
value|__builtin_trap()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_BUILTIN_TRAP
value|*(volatile int*)0x11 = 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_ASSUME_ALIGNED
end_comment

begin_comment
comment|/// \brief Returns a pointer with an assumed alignment.
end_comment

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_assume_aligned
argument_list|)
operator|||
name|LLVM_GNUC_PREREQ
argument_list|(
literal|4
operator|,
literal|7
operator|,
literal|0
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ASSUME_ALIGNED
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|__builtin_assume_aligned(p, a)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_BUILTIN_UNREACHABLE
argument_list|)
end_elif

begin_comment
comment|// As of today, clang does not support __builtin_assume_aligned.
end_comment

begin_define
define|#
directive|define
name|LLVM_ASSUME_ALIGNED
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
define|\
value|(((uintptr_t(p) % (a)) == 0) ? (p) : (LLVM_BUILTIN_UNREACHABLE, (p)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ASSUME_ALIGNED
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|(p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_FUNCTION_NAME
end_comment

begin_comment
comment|/// \brief Expands to __func__ on compilers which support it.  Otherwise,
end_comment

begin_comment
comment|/// expands to a compiler-dependent replacement.
end_comment

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
name|LLVM_FUNCTION_NAME
value|__FUNCTION__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_FUNCTION_NAME
value|__func__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_MEMORY_SANITIZER_BUILD
end_comment

begin_comment
comment|/// \brief Whether LLVM itself is built with MemorySanitizer instrumentation.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|memory_sanitizer
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_MEMORY_SANITIZER_BUILD
value|1
end_define

begin_include
include|#
directive|include
file|<sanitizer/msan_interface.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_MEMORY_SANITIZER_BUILD
value|0
end_define

begin_define
define|#
directive|define
name|__msan_allocated_memory
parameter_list|(
name|p
parameter_list|,
name|size
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__msan_unpoison
parameter_list|(
name|p
parameter_list|,
name|size
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_ADDRESS_SANITIZER_BUILD
end_comment

begin_comment
comment|/// \brief Whether LLVM itself is built with AddressSanitizer instrumentation.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|address_sanitizer
argument_list|)
operator|||
name|defined
argument_list|(
name|__SANITIZE_ADDRESS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ADDRESS_SANITIZER_BUILD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ADDRESS_SANITIZER_BUILD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_IS_UNALIGNED_ACCESS_FAST
end_comment

begin_comment
comment|/// \brief Is unaligned memory access fast on the host machine.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Don't specialize on alignment for platforms where unaligned memory accesses
end_comment

begin_comment
comment|/// generates the same code as aligned memory accesses for common types.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_AMD64
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|_X86_
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_IS_UNALIGNED_ACCESS_FAST
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_IS_UNALIGNED_ACCESS_FAST
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_EXPLICIT
end_comment

begin_comment
comment|/// \brief Expands to explicit on compilers which support explicit conversion
end_comment

begin_comment
comment|/// operators. Otherwise expands to nothing.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_explicit_conversions
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__GXX_EXPERIMENTAL_CXX0X__
argument_list|)
operator|||
name|LLVM_MSC_PREREQ
argument_list|(
literal|1800
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_EXPLICIT
value|explicit
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_EXPLICIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Does the compiler support generalized initializers (using braced
end_comment

begin_comment
comment|/// lists and std::initializer_list).  While clang may claim it supports general
end_comment

begin_comment
comment|/// initializers, if we're using MSVC's headers, we might not have a usable
end_comment

begin_comment
comment|/// std::initializer list type from the STL.  Disable this for now.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_generalized_initializers
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_HAS_INITIALIZER_LISTS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_HAS_INITIALIZER_LISTS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \brief Mark debug helper function definitions like dump() that should not be
end_comment

begin_comment
comment|/// stripped from debug builds.
end_comment

begin_comment
comment|// FIXME: Move this to a private config.h as it's not usable in public headers.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|LLVM_ENABLE_DUMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_DUMP_METHOD
value|LLVM_ATTRIBUTE_NOINLINE LLVM_ATTRIBUTE_USED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_DUMP_METHOD
value|LLVM_ATTRIBUTE_NOINLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

