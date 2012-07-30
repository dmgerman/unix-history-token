begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_test_utils.h ------------*- C++ -*-===//
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
comment|// This file is a part of AddressSanitizer, an address sanity checker.
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
name|ASAN_TEST_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_TEST_UTILS_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|__int8
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int16
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int8
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|int64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NOINLINE
value|__declspec(noinline)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// defined(_WIN32)
end_comment

begin_define
define|#
directive|define
name|NOINLINE
value|__attribute__((noinline))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(_WIN32)
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_feature
argument_list|)
end_if

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
name|__WORDSIZE
end_ifndef

begin_if
if|#
directive|if
name|__LP64__
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|__WORDSIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__WORDSIZE
value|32
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
comment|// Make the compiler think that something is going on there.
end_comment

begin_extern
extern|extern
literal|"C"
name|void
name|break_optimization
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_extern

begin_comment
comment|// This function returns its parameter but in such a way that compiler
end_comment

begin_comment
comment|// can not prove it.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|NOINLINE
specifier|static
name|T
name|Ident
argument_list|(
argument|T t
argument_list|)
block|{
name|T
name|ret
operator|=
name|t
block|;
name|break_optimization
argument_list|(
operator|&
name|ret
argument_list|)
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_TEST_UTILS_H
end_comment

end_unit

