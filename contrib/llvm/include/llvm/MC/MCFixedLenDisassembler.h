begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCFixedLenDisassembler.h - Decoder driver -------*- C++ -*-===//
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
comment|// Fixed length disassembler decoder state machine driver.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MCFIXEDLENDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCFIXEDLENDISASSEMBLER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|MCD
block|{
comment|// Disassembler state machine opcodes.
enum|enum
name|DecoderOps
block|{
name|OPC_ExtractField
init|=
literal|1
block|,
comment|// OPC_ExtractField(uint8_t Start, uint8_t Len)
name|OPC_FilterValue
block|,
comment|// OPC_FilterValue(uleb128 Val, uint16_t NumToSkip)
name|OPC_CheckField
block|,
comment|// OPC_CheckField(uint8_t Start, uint8_t Len,
comment|//                uleb128 Val, uint16_t NumToSkip)
name|OPC_CheckPredicate
block|,
comment|// OPC_CheckPredicate(uleb128 PIdx, uint16_t NumToSkip)
name|OPC_Decode
block|,
comment|// OPC_Decode(uleb128 Opcode, uleb128 DIdx)
name|OPC_SoftFail
block|,
comment|// OPC_SoftFail(uleb128 PMask, uleb128 NMask)
name|OPC_Fail
comment|// OPC_Fail()
block|}
enum|;
block|}
comment|// namespace MCDecode
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

