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

begin_comment
comment|// The VISIBILITY_HIDDEN macro, used for marking classes with the GCC-specific
end_comment

begin_comment
comment|// visibility("hidden") attribute.
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
name|VISIBILITY_HIDDEN
value|__attribute__ ((visibility("hidden")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VISIBILITY_HIDDEN
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
name|ATTRIBUTE_USED
value|__attribute__((__used__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_USED
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
name|ATTRIBUTE_UNUSED
value|__attribute__((__unused__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED
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
name|ATTRIBUTE_READNONE
value|__attribute__((__const__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_READNONE
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
name|ATTRIBUTE_READONLY
value|__attribute__((__pure__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_READONLY
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
comment|// DISABLE_INLINE - On compilers where we have a directive to do so, mark a
end_comment

begin_comment
comment|// method "not for inlining".
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
name|DISABLE_INLINE
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
name|DISABLE_INLINE
value|__declspec(noinline)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DISABLE_INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ALWAYS_INLINE - On compilers where we have a directive to do so, mark a
end_comment

begin_comment
comment|// method "always inline" because it is performance sensitive.
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
name|ALWAYS_INLINE
value|__attribute__((always_inline))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// TODO: No idea how to do this with MSVC.
end_comment

begin_define
define|#
directive|define
name|ALWAYS_INLINE
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
name|NORETURN
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
name|NORETURN
value|__declspec(noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NORETURN
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

