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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|__has_cpp_attribute
end_ifndef

begin_define
define|#
directive|define
name|__has_cpp_attribute
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
comment|///  * 1900: Microsoft Visual Studio 2015 / 14.0
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
comment|// We require at least MSVC 2015.
end_comment

begin_if
if|#
directive|if
operator|!
name|LLVM_MSC_PREREQ
argument_list|(
literal|1900
argument_list|)
end_if

begin_error
error|#
directive|error
error|LLVM requires at least MSVC 2015.
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

begin_comment
comment|/// \brief Does the compiler support ref-qualifiers for *this?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sadly, this is separate from just rvalue reference support because GCC
end_comment

begin_comment
comment|/// and MSVC implemented this later than everything else.
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
comment|/// Expands to '&' if ref-qualifiers for *this are supported.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can be used to provide lvalue/rvalue overrides of member functions.
end_comment

begin_comment
comment|/// The rvalue override should be guarded by LLVM_HAS_RVALUE_REFERENCE_THIS
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
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_PREFETCH
parameter_list|(
name|addr
parameter_list|,
name|rw
parameter_list|,
name|locality
parameter_list|)
value|__builtin_prefetch(addr, rw, locality)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_PREFETCH
parameter_list|(
name|addr
parameter_list|,
name|rw
parameter_list|,
name|locality
parameter_list|)
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

begin_comment
comment|/// LLVM_NODISCARD - Warn if a type or return value is discarded.
end_comment

begin_if
if|#
directive|if
name|__cplusplus
operator|>
literal|201402L
operator|&&
name|__has_cpp_attribute
argument_list|(
name|nodiscard
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_NODISCARD
value|[[nodiscard]]
end_define

begin_elif
elif|#
directive|elif
operator|!
name|__cplusplus
end_elif

begin_comment
comment|// Workaround for llvm.org/PR23435, since clang 3.6 and below emit a spurious
end_comment

begin_comment
comment|// error when __has_cpp_attribute is given a scoped attribute in C mode.
end_comment

begin_define
define|#
directive|define
name|LLVM_NODISCARD
end_define

begin_elif
elif|#
directive|elif
name|__has_cpp_attribute
argument_list|(
name|clang
operator|::
name|warn_unused_result
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_NODISCARD
value|[[clang::warn_unused_result]]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_NODISCARD
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
value|__attribute__((always_inline))
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
name|LLVM_ATTRIBUTE_RETURNS_NONNULL
value|_Ret_notnull_
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
comment|/// \macro LLVM_ATTRIBUTE_RETURNS_NOALIAS Used to mark a function as returning a
end_comment

begin_comment
comment|/// pointer that does not alias any other valid pointer.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_RETURNS_NOALIAS
value|__attribute__((__malloc__))
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
name|LLVM_ATTRIBUTE_RETURNS_NOALIAS
value|__declspec(restrict)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_RETURNS_NOALIAS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// LLVM_FALLTHROUGH - Mark fallthrough cases in switch statements.
end_comment

begin_if
if|#
directive|if
name|__cplusplus
operator|>
literal|201402L
operator|&&
name|__has_cpp_attribute
argument_list|(
name|fallthrough
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_FALLTHROUGH
value|[[fallthrough]]
end_define

begin_elif
elif|#
directive|elif
name|__has_cpp_attribute
argument_list|(
name|gnu
operator|::
name|fallthrough
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_FALLTHROUGH
value|[[gnu::fallthrough]]
end_define

begin_elif
elif|#
directive|elif
operator|!
name|__cplusplus
end_elif

begin_comment
comment|// Workaround for llvm.org/PR23435, since clang 3.6 and below emit a spurious
end_comment

begin_comment
comment|// error when __has_cpp_attribute is given a scoped attribute in C mode.
end_comment

begin_define
define|#
directive|define
name|LLVM_FALLTHROUGH
end_define

begin_elif
elif|#
directive|elif
name|__has_cpp_attribute
argument_list|(
name|clang
operator|::
name|fallthrough
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_FALLTHROUGH
value|[[clang::fallthrough]]
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_FALLTHROUGH
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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_comment
comment|// The __debugbreak intrinsic is supported by MSVC, does not require forward
end_comment

begin_comment
comment|// declarations involving platform-specific typedefs (unlike RaiseException),
end_comment

begin_comment
comment|// results in a call to vectored exception handlers, and encodes to a short
end_comment

begin_comment
comment|// instruction that still causes the trapping behavior we want.
end_comment

begin_define
define|#
directive|define
name|LLVM_BUILTIN_TRAP
value|__debugbreak()
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
comment|/// LLVM_BUILTIN_DEBUGTRAP - On compilers which support it, expands to
end_comment

begin_comment
comment|/// an expression which causes the program to break while running
end_comment

begin_comment
comment|/// under a debugger.
end_comment

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_debugtrap
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_BUILTIN_DEBUGTRAP
value|__builtin_debugtrap()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_comment
comment|// The __debugbreak intrinsic is supported by MSVC and breaks while
end_comment

begin_comment
comment|// running under the debugger, and also supports invoking a debugger
end_comment

begin_comment
comment|// when the OS is configured appropriately.
end_comment

begin_define
define|#
directive|define
name|LLVM_BUILTIN_DEBUGTRAP
value|__debugbreak()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Just continue execution when built with compilers that have no
end_comment

begin_comment
comment|// support. This is a debugging aid and not intended to force the
end_comment

begin_comment
comment|// program to abort if encountered.
end_comment

begin_define
define|#
directive|define
name|LLVM_BUILTIN_DEBUGTRAP
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
comment|/// \macro LLVM_ALIGNAS
end_comment

begin_comment
comment|/// \brief Used to specify a minimum alignment for a structure or variable.
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|&&
operator|!
name|__has_feature
argument_list|(
name|cxx_alignas
argument_list|)
operator|&&
operator|!
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
name|LLVM_ALIGNAS
parameter_list|(
name|x
parameter_list|)
value|__attribute__((aligned(x)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ALIGNAS
parameter_list|(
name|x
parameter_list|)
value|alignas(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_PACKED
end_comment

begin_comment
comment|/// \brief Used to specify a packed structure.
end_comment

begin_comment
comment|/// LLVM_PACKED(
end_comment

begin_comment
comment|///    struct A {
end_comment

begin_comment
comment|///      int i;
end_comment

begin_comment
comment|///      int j;
end_comment

begin_comment
comment|///      int k;
end_comment

begin_comment
comment|///      long long l;
end_comment

begin_comment
comment|///   });
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// LLVM_PACKED_START
end_comment

begin_comment
comment|/// struct B {
end_comment

begin_comment
comment|///   int i;
end_comment

begin_comment
comment|///   int j;
end_comment

begin_comment
comment|///   int k;
end_comment

begin_comment
comment|///   long long l;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// LLVM_PACKED_END
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|LLVM_PACKED
parameter_list|(
name|d
parameter_list|)
value|__pragma(pack(push, 1)) d __pragma(pack(pop))
end_define

begin_define
define|#
directive|define
name|LLVM_PACKED_START
value|__pragma(pack(push, 1))
end_define

begin_define
define|#
directive|define
name|LLVM_PACKED_END
value|__pragma(pack(pop))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_PACKED
parameter_list|(
name|d
parameter_list|)
value|d __attribute__((packed))
end_define

begin_define
define|#
directive|define
name|LLVM_PACKED_START
value|_Pragma("pack(push, 1)")
end_define

begin_define
define|#
directive|define
name|LLVM_PACKED_END
value|_Pragma("pack(pop)")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_PTR_SIZE
end_comment

begin_comment
comment|/// \brief A constant integer equivalent to the value of sizeof(void*).
end_comment

begin_comment
comment|/// Generally used in combination with LLVM_ALIGNAS or when doing computation in
end_comment

begin_comment
comment|/// the preprocessor.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SIZEOF_POINTER__
end_ifdef

begin_define
define|#
directive|define
name|LLVM_PTR_SIZE
value|__SIZEOF_POINTER__
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_PTR_SIZE
value|8
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_PTR_SIZE
value|4
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_error
error|#
directive|error
literal|"could not determine LLVM_PTR_SIZE as a constant int for MSVC"
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_PTR_SIZE
value|sizeof(void *)
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

begin_include
include|#
directive|include
file|<sanitizer/asan_interface.h>
end_include

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

begin_define
define|#
directive|define
name|__asan_poison_memory_region
parameter_list|(
name|p
parameter_list|,
name|size
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__asan_unpoison_memory_region
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
comment|/// \macro LLVM_THREAD_SANITIZER_BUILD
end_comment

begin_comment
comment|/// \brief Whether LLVM itself is built with ThreadSanitizer instrumentation.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|thread_sanitizer
argument_list|)
operator|||
name|defined
argument_list|(
name|__SANITIZE_THREAD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_THREAD_SANITIZER_BUILD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_THREAD_SANITIZER_BUILD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LLVM_THREAD_SANITIZER_BUILD
end_if

begin_comment
comment|// Thread Sanitizer is a tool that finds races in code.
end_comment

begin_comment
comment|// See http://code.google.com/p/data-race-test/wiki/DynamicAnnotations .
end_comment

begin_comment
comment|// tsan detects these exact functions by name.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|void
name|AnnotateHappensAfter
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
specifier|volatile
name|void
modifier|*
name|cv
parameter_list|)
function_decl|;
name|void
name|AnnotateHappensBefore
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
specifier|volatile
name|void
modifier|*
name|cv
parameter_list|)
function_decl|;
name|void
name|AnnotateIgnoreWritesBegin
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
name|void
name|AnnotateIgnoreWritesEnd
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This marker is used to define a happens-before arc. The race detector will
end_comment

begin_comment
comment|// infer an arc from the begin to the end when they share the same pointer
end_comment

begin_comment
comment|// argument.
end_comment

begin_define
define|#
directive|define
name|TsanHappensBefore
parameter_list|(
name|cv
parameter_list|)
value|AnnotateHappensBefore(__FILE__, __LINE__, cv)
end_define

begin_comment
comment|// This marker defines the destination of a happens-before arc.
end_comment

begin_define
define|#
directive|define
name|TsanHappensAfter
parameter_list|(
name|cv
parameter_list|)
value|AnnotateHappensAfter(__FILE__, __LINE__, cv)
end_define

begin_comment
comment|// Ignore any races on writes between here and the next TsanIgnoreWritesEnd.
end_comment

begin_define
define|#
directive|define
name|TsanIgnoreWritesBegin
parameter_list|()
value|AnnotateIgnoreWritesBegin(__FILE__, __LINE__)
end_define

begin_comment
comment|// Resume checking for racy writes.
end_comment

begin_define
define|#
directive|define
name|TsanIgnoreWritesEnd
parameter_list|()
value|AnnotateIgnoreWritesEnd(__FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TsanHappensBefore
parameter_list|(
name|cv
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TsanHappensAfter
parameter_list|(
name|cv
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TsanIgnoreWritesBegin
parameter_list|()
end_define

begin_define
define|#
directive|define
name|TsanIgnoreWritesEnd
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_NO_SANITIZE
end_comment

begin_comment
comment|/// \brief Disable a particular sanitizer for a function.
end_comment

begin_if
if|#
directive|if
name|__has_attribute
argument_list|(
name|no_sanitize
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_NO_SANITIZE
parameter_list|(
name|KIND
parameter_list|)
value|__attribute__((no_sanitize(KIND)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_NO_SANITIZE
parameter_list|(
name|KIND
parameter_list|)
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
comment|/// Note that you should also surround dump() functions with
end_comment

begin_comment
comment|/// `#if !defined(NDEBUG) || defined(LLVM_ENABLE_DUMP)` so they do always
end_comment

begin_comment
comment|/// get stripped in release builds.
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

begin_comment
comment|/// \macro LLVM_PRETTY_FUNCTION
end_comment

begin_comment
comment|/// \brief Gets a user-friendly looking function signature for the current scope
end_comment

begin_comment
comment|/// using the best available method on each platform.  The exact format of the
end_comment

begin_comment
comment|/// resulting string is implementation specific and non-portable, so this should
end_comment

begin_comment
comment|/// only be used, for example, for logging or diagnostics.
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
name|LLVM_PRETTY_FUNCTION
value|__FUNCSIG__
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_PRETTY_FUNCTION
value|__PRETTY_FUNCTION__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_PRETTY_FUNCTION
value|__func__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_THREAD_LOCAL
end_comment

begin_comment
comment|/// \brief A thread-local storage specifier which can be used with globals,
end_comment

begin_comment
comment|/// extern globals, and static globals.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is essentially an extremely restricted analog to C++11's thread_local
end_comment

begin_comment
comment|/// support, and uses that when available. However, it falls back on
end_comment

begin_comment
comment|/// platform-specific or vendor-provided extensions when necessary. These
end_comment

begin_comment
comment|/// extensions don't support many of the C++11 thread_local's features. You
end_comment

begin_comment
comment|/// should only use this for PODs that you can statically initialize to
end_comment

begin_comment
comment|/// some constant value. In almost all circumstances this is most appropriate
end_comment

begin_comment
comment|/// for use with a pointer, integer, or small aggregation of pointers and
end_comment

begin_comment
comment|/// integers.
end_comment

begin_if
if|#
directive|if
name|LLVM_ENABLE_THREADS
end_if

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_thread_local
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_THREAD_LOCAL
value|thread_local
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_elif

begin_comment
comment|// MSVC supports this with a __declspec.
end_comment

begin_define
define|#
directive|define
name|LLVM_THREAD_LOCAL
value|__declspec(thread)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Clang, GCC, and other compatible compilers used __thread prior to C++11 and
end_comment

begin_comment
comment|// we only need the restricted functionality that provides.
end_comment

begin_define
define|#
directive|define
name|LLVM_THREAD_LOCAL
value|__thread
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|// !LLVM_ENABLE_THREADS
end_comment

begin_comment
comment|// If threading is disabled entirely, this compiles to nothing and you get
end_comment

begin_comment
comment|// a normal global variable.
end_comment

begin_define
define|#
directive|define
name|LLVM_THREAD_LOCAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// \macro LLVM_ENABLE_EXCEPTIONS
end_comment

begin_comment
comment|/// \brief Whether LLVM is built with exception support.
end_comment

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_exceptions
argument_list|)
end_if

begin_define
define|#
directive|define
name|LLVM_ENABLE_EXCEPTIONS
value|1
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
name|__EXCEPTIONS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_ENABLE_EXCEPTIONS
value|1
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|_CPPUNWIND
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LLVM_ENABLE_EXCEPTIONS
value|1
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

