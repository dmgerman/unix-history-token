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

begin_if
if|#
directive|if
operator|(
name|__GNUC__
operator|>=
literal|4
operator|)
operator|&&
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
operator|(
name|__GNUC__
operator|>=
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|1
operator|)
operator|)
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
operator|(
name|__GNUC__
operator|>=
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|1
operator|)
operator|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|// aka 'ATTRIBUTE_CONST' but following LLVM Conventions.
end_comment

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_READNONE
value|__attribute__((__const__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_READNONE
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

begin_comment
comment|// aka 'ATTRIBUTE_PURE' but following LLVM Conventions.
end_comment

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_READONLY
value|__attribute__((__pure__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLVM_ATTRIBUTE_READONLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__GNUC__
operator|>=
literal|4
operator|)
end_if

begin_define
define|#
directive|define
name|BUILTIN_EXPECT
parameter_list|(
name|EXPR
parameter_list|,
name|VALUE
parameter_list|)
value|__builtin_expect((EXPR), (VALUE))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUILTIN_EXPECT
parameter_list|(
name|EXPR
parameter_list|,
name|VALUE
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
comment|// LLVM_ATTRIBUTE_NOINLINE - On compilers where we have a directive to do so,
end_comment

begin_comment
comment|// mark a method "not for inlining".
end_comment

begin_if
if|#
directive|if
operator|(
name|__GNUC__
operator|>
literal|3
operator|||
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|4
operator|)
operator|)
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
comment|// LLVM_ATTRIBUTE_ALWAYS_INLINE - On compilers where we have a directive to do
end_comment

begin_comment
comment|// so, mark a method "always inline" because it is performance sensitive. GCC
end_comment

begin_comment
comment|// 3.4 supported this but is buggy in various cases and produces unimplemented
end_comment

begin_comment
comment|// errors, just use it in GCC 4.0 and later.
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|3
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
comment|// LLVM_BUILTIN_UNREACHABLE - On compilers which support it, expands
end_comment

begin_comment
comment|// to an expression which states that it is undefined behavior for the
end_comment

begin_comment
comment|// compiler to reach this point.  Otherwise is not defined.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|||
operator|(
name|__GNUC__
operator|>
literal|4
operator|)
expr|\
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|5
operator|)
end_if

begin_define
define|#
directive|define
name|LLVM_BUILTIN_UNREACHABLE
value|__builtin_unreachable()
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

