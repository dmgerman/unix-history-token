begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsAsmBackend.h - Mips Asm Backend  ------------------------------===//
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
comment|// This file defines the MipsAsmBackend class.
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSASMBACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSASMBACKEND_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/MipsFixupKinds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmBackend.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAssembler
decl_stmt|;
struct_decl|struct
name|MCFixupKindInfo
struct_decl|;
name|class
name|Target
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MipsAsmBackend
range|:
name|public
name|MCAsmBackend
block|{
name|Triple
operator|::
name|OSType
name|OSType
block|;
name|bool
name|IsLittle
block|;
comment|// Big or little endian
name|bool
name|Is64Bit
block|;
comment|// 32 or 64 bit words
name|public
operator|:
name|MipsAsmBackend
argument_list|(
argument|const Target&T
argument_list|,
argument|Triple::OSType OSType
argument_list|,
argument|bool IsLittle
argument_list|,
argument|bool Is64Bit
argument_list|)
operator|:
name|MCAsmBackend
argument_list|()
block|,
name|OSType
argument_list|(
name|OSType
argument_list|)
block|,
name|IsLittle
argument_list|(
name|IsLittle
argument_list|)
block|,
name|Is64Bit
argument_list|(
argument|Is64Bit
argument_list|)
block|{}
name|MCObjectWriter
operator|*
name|createObjectWriter
argument_list|(
argument|raw_pwrite_stream&OS
argument_list|)
specifier|const
name|override
block|;
name|void
name|applyFixup
argument_list|(
argument|const MCFixup&Fixup
argument_list|,
argument|char *Data
argument_list|,
argument|unsigned DataSize
argument_list|,
argument|uint64_t Value
argument_list|,
argument|bool IsPCRel
argument_list|,
argument|MCContext&Ctx
argument_list|)
specifier|const
name|override
block|;
name|Optional
operator|<
name|MCFixupKind
operator|>
name|getFixupKind
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCFixupKindInfo
operator|&
name|getFixupKindInfo
argument_list|(
argument|MCFixupKind Kind
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getNumFixupKinds
argument_list|()
specifier|const
name|override
block|{
return|return
name|Mips
operator|::
name|NumTargetFixupKinds
return|;
block|}
comment|/// @name Target Relaxation Interfaces
comment|/// @{
comment|/// MayNeedRelaxation - Check whether the given instruction may need
comment|/// relaxation.
comment|///
comment|/// \param Inst - The instruction to test.
name|bool
name|mayNeedRelaxation
argument_list|(
argument|const MCInst&Inst
argument_list|)
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
comment|/// fixupNeedsRelaxation - Target specific predicate for whether a given
comment|/// fixup requires the associated instruction to be relaxed.
name|bool
name|fixupNeedsRelaxation
argument_list|(
argument|const MCFixup&Fixup
argument_list|,
argument|uint64_t Value
argument_list|,
argument|const MCRelaxableFragment *DF
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|)
specifier|const
name|override
block|{
comment|// FIXME.
name|llvm_unreachable
argument_list|(
literal|"RelaxInstruction() unimplemented"
argument_list|)
block|;
return|return
name|false
return|;
block|}
comment|/// RelaxInstruction - Relax the instruction in the given fragment
comment|/// to the next wider instruction.
comment|///
comment|/// \param Inst - The instruction to relax, which may be the same
comment|/// as the output.
comment|/// \param [out] Res On return, the relaxed instruction.
name|void
name|relaxInstruction
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|,
argument|MCInst&Res
argument_list|)
specifier|const
name|override
block|{}
comment|/// @}
name|bool
name|writeNopData
argument_list|(
argument|uint64_t Count
argument_list|,
argument|MCObjectWriter *OW
argument_list|)
specifier|const
name|override
block|;  }
decl_stmt|;
comment|// class MipsAsmBackend
block|}
end_decl_stmt

begin_comment
comment|// namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

