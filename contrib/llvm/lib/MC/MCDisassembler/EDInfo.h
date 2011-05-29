begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- EDInfo.h - LLVM Enhanced Disassembler -------------------*- C++ -*-===//
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
name|LLVM_EDINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EDINFO_H
end_define

begin_enum
enum|enum
block|{
name|EDIS_MAX_OPERANDS
init|=
literal|13
block|,
name|EDIS_MAX_SYNTAXES
init|=
literal|2
block|}
enum|;
end_enum

begin_enum
enum|enum
name|OperandTypes
block|{
name|kOperandTypeNone
block|,
name|kOperandTypeImmediate
block|,
name|kOperandTypeRegister
block|,
name|kOperandTypeX86Memory
block|,
name|kOperandTypeX86EffectiveAddress
block|,
name|kOperandTypeX86PCRelative
block|,
name|kOperandTypeARMBranchTarget
block|,
name|kOperandTypeARMSoReg
block|,
name|kOperandTypeARMSoImm
block|,
name|kOperandTypeARMSoImm2Part
block|,
name|kOperandTypeARMPredicate
block|,
name|kOperandTypeARMAddrMode2
block|,
name|kOperandTypeARMAddrMode2Offset
block|,
name|kOperandTypeARMAddrMode3
block|,
name|kOperandTypeARMAddrMode3Offset
block|,
name|kOperandTypeARMAddrMode4
block|,
name|kOperandTypeARMAddrMode5
block|,
name|kOperandTypeARMAddrMode6
block|,
name|kOperandTypeARMAddrMode6Offset
block|,
name|kOperandTypeARMAddrMode7
block|,
name|kOperandTypeARMAddrModePC
block|,
name|kOperandTypeARMRegisterList
block|,
name|kOperandTypeARMTBAddrMode
block|,
name|kOperandTypeThumbITMask
block|,
name|kOperandTypeThumbAddrModeS1
block|,
name|kOperandTypeThumbAddrModeS2
block|,
name|kOperandTypeThumbAddrModeS4
block|,
name|kOperandTypeThumbAddrModeRR
block|,
name|kOperandTypeThumbAddrModeSP
block|,
name|kOperandTypeThumb2SoReg
block|,
name|kOperandTypeThumb2SoImm
block|,
name|kOperandTypeThumb2AddrModeImm8
block|,
name|kOperandTypeThumb2AddrModeImm8Offset
block|,
name|kOperandTypeThumb2AddrModeImm12
block|,
name|kOperandTypeThumb2AddrModeSoReg
block|,
name|kOperandTypeThumb2AddrModeImm8s4
block|,
name|kOperandTypeThumb2AddrModeImm8s4Offset
block|,
name|kOperandTypeThumb2AddrModeReg
block|}
enum|;
end_enum

begin_enum
enum|enum
name|OperandFlags
block|{
name|kOperandFlagSource
init|=
literal|0x1
block|,
name|kOperandFlagTarget
init|=
literal|0x2
block|}
enum|;
end_enum

begin_enum
enum|enum
name|InstructionTypes
block|{
name|kInstructionTypeNone
block|,
name|kInstructionTypeMove
block|,
name|kInstructionTypeBranch
block|,
name|kInstructionTypePush
block|,
name|kInstructionTypePop
block|,
name|kInstructionTypeCall
block|,
name|kInstructionTypeReturn
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

