begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRAsmBackend.h - AVR Asm Backend  --------------------------------===//
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
comment|// \file The AVR assembly backend implementation.
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
name|LLVM_AVR_ASM_BACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_ASM_BACKEND_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/AVRFixupKinds.h"
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
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|Target
decl_stmt|;
struct_decl|struct
name|MCFixupKindInfo
struct_decl|;
comment|/// Utilities for manipulating generated AVR machine code.
name|class
name|AVRAsmBackend
range|:
name|public
name|MCAsmBackend
block|{
name|public
operator|:
name|AVRAsmBackend
argument_list|(
argument|Triple::OSType OSType
argument_list|)
operator|:
name|MCAsmBackend
argument_list|()
block|,
name|OSType
argument_list|(
argument|OSType
argument_list|)
block|{}
name|void
name|adjustFixupValue
argument_list|(
argument|const MCFixup&Fixup
argument_list|,
argument|uint64_t&Value
argument_list|,
argument|MCContext *Ctx = nullptr
argument_list|)
specifier|const
block|;
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
name|AVR
operator|::
name|NumTargetFixupKinds
return|;
block|}
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
name|llvm_unreachable
argument_list|(
literal|"RelaxInstruction() unimplemented"
argument_list|)
block|;
return|return
name|false
return|;
block|}
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
name|bool
name|writeNopData
argument_list|(
argument|uint64_t Count
argument_list|,
argument|MCObjectWriter *OW
argument_list|)
specifier|const
name|override
block|;
name|void
name|processFixupValue
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCAsmLayout&Layout
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|const MCFragment *DF
argument_list|,
argument|const MCValue&Target
argument_list|,
argument|uint64_t&Value
argument_list|,
argument|bool&IsResolved
argument_list|)
name|override
block|;
name|private
operator|:
name|Triple
operator|::
name|OSType
name|OSType
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
comment|// LLVM_AVR_ASM_BACKEND_H
end_comment

end_unit

