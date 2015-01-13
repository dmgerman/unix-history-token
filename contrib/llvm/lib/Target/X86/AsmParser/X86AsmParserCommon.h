begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86AsmParserCommon.h - Common functions for X86AsmParser ---------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|X86_ASM_PARSER_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|X86_ASM_PARSER_COMMON_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
specifier|inline
name|bool
name|isImmSExti16i8Value
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
operator|(
operator|(
name|Value
operator|<=
literal|0x000000000000007FULL
operator|)
operator|||
operator|(
literal|0x000000000000FF80ULL
operator|<=
name|Value
operator|&&
name|Value
operator|<=
literal|0x000000000000FFFFULL
operator|)
operator|||
operator|(
literal|0xFFFFFFFFFFFFFF80ULL
operator|<=
name|Value
operator|&&
name|Value
operator|<=
literal|0xFFFFFFFFFFFFFFFFULL
operator|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|isImmSExti32i8Value
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
operator|(
operator|(
name|Value
operator|<=
literal|0x000000000000007FULL
operator|)
operator|||
operator|(
literal|0x00000000FFFFFF80ULL
operator|<=
name|Value
operator|&&
name|Value
operator|<=
literal|0x00000000FFFFFFFFULL
operator|)
operator|||
operator|(
literal|0xFFFFFFFFFFFFFF80ULL
operator|<=
name|Value
operator|&&
name|Value
operator|<=
literal|0xFFFFFFFFFFFFFFFFULL
operator|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|isImmZExtu32u8Value
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
operator|(
name|Value
operator|<=
literal|0x00000000000000FFULL
operator|)
return|;
block|}
specifier|inline
name|bool
name|isImmSExti64i8Value
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
operator|(
operator|(
name|Value
operator|<=
literal|0x000000000000007FULL
operator|)
operator|||
operator|(
literal|0xFFFFFFFFFFFFFF80ULL
operator|<=
name|Value
operator|&&
name|Value
operator|<=
literal|0xFFFFFFFFFFFFFFFFULL
operator|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|isImmSExti64i32Value
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
block|{
return|return
operator|(
operator|(
name|Value
operator|<=
literal|0x000000007FFFFFFFULL
operator|)
operator|||
operator|(
literal|0xFFFFFFFF80000000ULL
operator|<=
name|Value
operator|&&
name|Value
operator|<=
literal|0xFFFFFFFFFFFFFFFFULL
operator|)
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// X86_ASM_PARSER_COMMON_H
end_comment

end_unit

