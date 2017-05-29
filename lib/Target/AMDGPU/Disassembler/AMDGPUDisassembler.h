begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUDisassembler.hpp - Disassembler for AMDGPU ISA ---*- C++ -*--===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This file contains declaration for AMDGPU ISA disassembler
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
name|LLVM_LIB_TARGET_AMDGPU_DISASSEMBLER_AMDGPUDISASSEMBLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_DISASSEMBLER_AMDGPUDISASSEMBLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDisassembler/MCDisassembler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDisassembler/MCRelocationInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDisassembler/MCSymbolizer.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCOperand
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|Twine
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// AMDGPUDisassembler
comment|//===----------------------------------------------------------------------===//
name|class
name|AMDGPUDisassembler
range|:
name|public
name|MCDisassembler
block|{
name|private
operator|:
name|mutable
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Bytes
block|;
name|mutable
name|uint32_t
name|Literal
block|;
name|mutable
name|bool
name|HasLiteral
block|;
name|public
operator|:
name|AMDGPUDisassembler
argument_list|(
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
operator|:
name|MCDisassembler
argument_list|(
argument|STI
argument_list|,
argument|Ctx
argument_list|)
block|{}
operator|~
name|AMDGPUDisassembler
argument_list|()
name|override
operator|=
expr|default
block|;
name|DecodeStatus
name|getInstruction
argument_list|(
argument|MCInst&MI
argument_list|,
argument|uint64_t&Size
argument_list|,
argument|ArrayRef<uint8_t> Bytes
argument_list|,
argument|uint64_t Address
argument_list|,
argument|raw_ostream&WS
argument_list|,
argument|raw_ostream&CS
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|getRegClassName
argument_list|(
argument|unsigned RegClassID
argument_list|)
specifier|const
block|;
name|MCOperand
name|createRegOperand
argument_list|(
argument|unsigned int RegId
argument_list|)
specifier|const
block|;
name|MCOperand
name|createRegOperand
argument_list|(
argument|unsigned RegClassID
argument_list|,
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|createSRegOperand
argument_list|(
argument|unsigned SRegClassID
argument_list|,
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|errOperand
argument_list|(
argument|unsigned V
argument_list|,
argument|const Twine& ErrMsg
argument_list|)
specifier|const
block|;
name|DecodeStatus
name|tryDecodeInst
argument_list|(
argument|const uint8_t* Table
argument_list|,
argument|MCInst&MI
argument_list|,
argument|uint64_t Inst
argument_list|,
argument|uint64_t Address
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VGPR_32
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VS_32
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VS_64
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VSrc16
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VSrcV216
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VReg_64
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VReg_96
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_VReg_128
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_SReg_32
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_SReg_32_XM0_XEXEC
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_SReg_64
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_SReg_64_XEXEC
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_SReg_128
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_SReg_256
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeOperand_SReg_512
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;    enum
name|OpWidthTy
block|{
name|OPW32
block|,
name|OPW64
block|,
name|OPW128
block|,
name|OPW16
block|,
name|OPWV216
block|,
name|OPW_LAST_
block|,
name|OPW_FIRST_
operator|=
name|OPW32
block|}
block|;
name|unsigned
name|getVgprClassId
argument_list|(
argument|const OpWidthTy Width
argument_list|)
specifier|const
block|;
name|unsigned
name|getSgprClassId
argument_list|(
argument|const OpWidthTy Width
argument_list|)
specifier|const
block|;
name|unsigned
name|getTtmpClassId
argument_list|(
argument|const OpWidthTy Width
argument_list|)
specifier|const
block|;
specifier|static
name|MCOperand
name|decodeIntImmed
argument_list|(
argument|unsigned Imm
argument_list|)
block|;
specifier|static
name|MCOperand
name|decodeFPImmed
argument_list|(
argument|OpWidthTy Width
argument_list|,
argument|unsigned Imm
argument_list|)
block|;
name|MCOperand
name|decodeLiteralConstant
argument_list|()
specifier|const
block|;
name|MCOperand
name|decodeSrcOp
argument_list|(
argument|const OpWidthTy Width
argument_list|,
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeSpecialReg32
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeSpecialReg64
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeSDWA9Src
argument_list|(
argument|const OpWidthTy Width
argument_list|,
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeSDWA9Src16
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeSDWA9Src32
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
name|MCOperand
name|decodeSDWA9VopcDst
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// AMDGPUSymbolizer
comment|//===----------------------------------------------------------------------===//
name|class
name|AMDGPUSymbolizer
range|:
name|public
name|MCSymbolizer
block|{
name|private
operator|:
name|void
operator|*
name|DisInfo
block|;
name|public
operator|:
name|AMDGPUSymbolizer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|MCRelocationInfo
operator|>
operator|&&
name|RelInfo
argument_list|,
name|void
operator|*
name|disInfo
argument_list|)
operator|:
name|MCSymbolizer
argument_list|(
name|Ctx
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|RelInfo
argument_list|)
argument_list|)
block|,
name|DisInfo
argument_list|(
argument|disInfo
argument_list|)
block|{}
name|bool
name|tryAddingSymbolicOperand
argument_list|(
argument|MCInst&Inst
argument_list|,
argument|raw_ostream&cStream
argument_list|,
argument|int64_t Value
argument_list|,
argument|uint64_t Address
argument_list|,
argument|bool IsBranch
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|uint64_t InstSize
argument_list|)
name|override
block|;
name|void
name|tryAddingPcLoadReferenceComment
argument_list|(
argument|raw_ostream&cStream
argument_list|,
argument|int64_t Value
argument_list|,
argument|uint64_t Address
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_DISASSEMBLER_AMDGPUDISASSEMBLER_H
end_comment

end_unit

