begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- call_apsr.h - Helpers for ARM EABI floating point tests -----------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
comment|// This file declares helpers for ARM EABI floating point tests for the
end_comment

begin_comment
comment|// compiler_rt library.
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
name|CALL_APSR_H
end_ifndef

begin_define
define|#
directive|define
name|CALL_APSR_H
end_define

begin_if
if|#
directive|if
name|__BYTE_ORDER__
operator|!=
name|__ORDER_LITTLE_ENDIAN__
end_if

begin_error
error|#
directive|error
error|big endian support not implemented
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_union
union|union
name|cpsr
block|{
struct|struct
block|{
name|uint32_t
name|filler
range|:
literal|28
decl_stmt|;
name|uint32_t
name|v
range|:
literal|1
decl_stmt|;
name|uint32_t
name|c
range|:
literal|1
decl_stmt|;
name|uint32_t
name|z
range|:
literal|1
decl_stmt|;
name|uint32_t
name|n
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|uint32_t
name|value
decl_stmt|;
block|}
union|;
end_union

begin_extern
extern|extern __attribute__((pcs(
literal|"aapcs"
end_extern

begin_decl_stmt
unit|)))
name|uint32_t
name|call_apsr_f
argument_list|(
name|float
name|a
argument_list|,
name|float
name|b
argument_list|,
name|__attribute__
argument_list|(
argument|(pcs(
literal|"aapcs"
argument|))
argument_list|)
name|void
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|(
name|float
argument_list|,
name|float
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __attribute__((pcs(
literal|"aapcs"
end_extern

begin_decl_stmt
unit|)))
name|uint32_t
name|call_apsr_d
argument_list|(
name|double
name|a
argument_list|,
name|double
name|b
argument_list|,
name|__attribute__
argument_list|(
argument|(pcs(
literal|"aapcs"
argument|))
argument_list|)
name|void
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|(
name|double
argument_list|,
name|double
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CALL_APSR_H
end_comment

end_unit

