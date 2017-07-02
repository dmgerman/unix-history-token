begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMAsmBackend.h - ARM Assembler Backend -----------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_ARMASMBACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMASMBACKEND_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/ARMFixupKinds.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/ARMMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmBackend.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSubtargetInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TargetRegistry.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ARMAsmBackend
range|:
name|public
name|MCAsmBackend
block|{
specifier|const
name|MCSubtargetInfo
operator|*
name|STI
block|;
name|bool
name|isThumbMode
block|;
comment|// Currently emitting Thumb code.
name|bool
name|IsLittleEndian
block|;
comment|// Big or little endian.
name|public
operator|:
name|ARMAsmBackend
argument_list|(
argument|const Target&T
argument_list|,
argument|const Triple&TT
argument_list|,
argument|bool IsLittle
argument_list|)
operator|:
name|MCAsmBackend
argument_list|()
block|,
name|STI
argument_list|(
name|ARM_MC
operator|::
name|createARMMCSubtargetInfo
argument_list|(
name|TT
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|)
argument_list|)
block|,
name|isThumbMode
argument_list|(
name|TT
operator|.
name|getArchName
argument_list|()
operator|.
name|startswith
argument_list|(
literal|"thumb"
argument_list|)
argument_list|)
block|,
name|IsLittleEndian
argument_list|(
argument|IsLittle
argument_list|)
block|{}
operator|~
name|ARMAsmBackend
argument_list|()
name|override
block|{
name|delete
name|STI
block|; }
name|unsigned
name|getNumFixupKinds
argument_list|()
specifier|const
name|override
block|{
return|return
name|ARM
operator|::
name|NumTargetFixupKinds
return|;
block|}
name|bool
name|hasNOP
argument_list|()
specifier|const
block|{
return|return
name|STI
operator|->
name|getFeatureBits
argument_list|()
index|[
name|ARM
operator|::
name|HasV6T2Ops
index|]
return|;
block|}
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
name|bool
name|shouldForceRelocation
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|const MCValue&Target
argument_list|)
name|override
block|;
name|unsigned
name|adjustFixupValue
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|const MCValue&Target
argument_list|,
argument|uint64_t Value
argument_list|,
argument|bool IsPCRel
argument_list|,
argument|MCContext&Ctx
argument_list|,
argument|bool IsLittleEndian
argument_list|,
argument|bool IsResolved
argument_list|)
specifier|const
block|;
name|void
name|applyFixup
argument_list|(
argument|const MCAssembler&Asm
argument_list|,
argument|const MCFixup&Fixup
argument_list|,
argument|const MCValue&Target
argument_list|,
argument|MutableArrayRef<char> Data
argument_list|,
argument|uint64_t Value
argument_list|,
argument|bool IsPCRel
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getRelaxedOpcode
argument_list|(
argument|unsigned Op
argument_list|)
specifier|const
block|;
name|bool
name|mayNeedRelaxation
argument_list|(
argument|const MCInst&Inst
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|char
operator|*
name|reasonForFixupRelaxation
argument_list|(
argument|const MCFixup&Fixup
argument_list|,
argument|uint64_t Value
argument_list|)
specifier|const
block|;
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
block|;
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
block|;
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
name|handleAssemblerFlag
argument_list|(
argument|MCAssemblerFlag Flag
argument_list|)
name|override
block|;
name|unsigned
name|getPointerSize
argument_list|()
specifier|const
block|{
return|return
literal|4
return|;
block|}
name|bool
name|isThumb
argument_list|()
specifier|const
block|{
return|return
name|isThumbMode
return|;
block|}
name|void
name|setIsThumb
argument_list|(
argument|bool it
argument_list|)
block|{
name|isThumbMode
operator|=
name|it
block|; }
name|bool
name|isLittle
argument_list|()
specifier|const
block|{
return|return
name|IsLittleEndian
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

