begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetLoweringObjectFile.h - Object Info ----*- C++ -*-===//
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
comment|// This file implements classes used to handle lowerings specific to common
end_comment

begin_comment
comment|// object file formats.
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
name|LLVM_TARGET_TARGETLOWERINGOBJECTFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETLOWERINGOBJECTFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCObjectFileInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCSymbolRefExpr
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetLoweringObjectFile
range|:
name|public
name|MCObjectFileInfo
block|{
name|MCContext
operator|*
name|Ctx
operator|=
name|nullptr
block|;
comment|/// Name-mangler for global names.
name|Mangler
operator|*
name|Mang
operator|=
name|nullptr
block|;
name|protected
operator|:
name|bool
name|SupportIndirectSymViaGOTPCRel
operator|=
name|false
block|;
name|bool
name|SupportGOTPCRelWithOffset
operator|=
name|true
block|;
comment|/// This section contains the static constructor pointer list.
name|MCSection
operator|*
name|StaticCtorSection
block|;
comment|/// This section contains the static destructor pointer list.
name|MCSection
operator|*
name|StaticDtorSection
block|;
name|public
operator|:
name|TargetLoweringObjectFile
argument_list|()
operator|=
expr|default
block|;
name|TargetLoweringObjectFile
argument_list|(
specifier|const
name|TargetLoweringObjectFile
operator|&
argument_list|)
operator|=
name|delete
block|;
name|TargetLoweringObjectFile
operator|&
name|operator
operator|=
operator|(
specifier|const
name|TargetLoweringObjectFile
operator|&
operator|)
operator|=
name|delete
block|;
name|virtual
operator|~
name|TargetLoweringObjectFile
argument_list|()
block|;
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Ctx
return|;
block|}
name|Mangler
operator|&
name|getMangler
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Mang
return|;
block|}
comment|/// This method must be called before any actual lowering is done.  This
comment|/// specifies the current context for codegen, and gives the lowering
comment|/// implementations a chance to set up their default sections.
name|virtual
name|void
name|Initialize
argument_list|(
name|MCContext
operator|&
name|ctx
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
name|virtual
name|void
name|emitPersonalityValue
argument_list|(
argument|MCStreamer&Streamer
argument_list|,
argument|const DataLayout&TM
argument_list|,
argument|const MCSymbol *Sym
argument_list|)
specifier|const
block|;
comment|/// Emit the module flags that the platform cares about.
name|virtual
name|void
name|emitModuleFlags
argument_list|(
argument|MCStreamer&Streamer
argument_list|,
argument|ArrayRef<Module::ModuleFlagEntry> Flags
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|{}
comment|/// Given a constant with the SectionKind, return a section that it should be
comment|/// placed in.
name|virtual
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|const DataLayout&DL
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const Constant *C
argument_list|,
argument|unsigned&Align
argument_list|)
specifier|const
block|;
comment|/// Classify the specified global variable into a set of target independent
comment|/// categories embodied in SectionKind.
specifier|static
name|SectionKind
name|getKindForGlobal
argument_list|(
specifier|const
name|GlobalObject
operator|*
name|GO
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// This method computes the appropriate section to emit the specified global
comment|/// variable or function definition. This should not be passed external (or
comment|/// available externally) globals.
name|MCSection
operator|*
name|SectionForGlobal
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// This method computes the appropriate section to emit the specified global
comment|/// variable or function definition. This should not be passed external (or
comment|/// available externally) globals.
name|MCSection
operator|*
name|SectionForGlobal
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|{
return|return
name|SectionForGlobal
argument_list|(
name|GO
argument_list|,
name|getKindForGlobal
argument_list|(
name|GO
argument_list|,
name|TM
argument_list|)
argument_list|,
name|TM
argument_list|)
return|;
block|}
name|virtual
name|void
name|getNameWithPrefix
argument_list|(
argument|SmallVectorImpl<char>&OutName
argument_list|,
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|virtual
name|MCSection
operator|*
name|getSectionForJumpTable
argument_list|(
argument|const Function&F
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|shouldPutJumpTableInFunctionSection
argument_list|(
argument|bool UsesLabelDifference
argument_list|,
argument|const Function&F
argument_list|)
specifier|const
block|;
comment|/// Targets should implement this method to assign a section to globals with
comment|/// an explicit section specfied. The implementation of this method can
comment|/// assume that GO->hasSection() is true.
name|virtual
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// Return an MCExpr to use for a reference to the specified global variable
comment|/// from exception handling information.
name|virtual
specifier|const
name|MCExpr
operator|*
name|getTTypeGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
block|;
comment|/// Return the MCSymbol for a private symbol with global value name as its
comment|/// base, with the specified suffix.
name|MCSymbol
operator|*
name|getSymbolWithGlobalValueBase
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|StringRef Suffix
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|// The symbol that gets passed to .cfi_personality.
name|virtual
name|MCSymbol
operator|*
name|getCFIPersonalitySymbol
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|const TargetMachine&TM
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|)
specifier|const
block|;
specifier|const
name|MCExpr
operator|*
name|getTTypeReference
argument_list|(
argument|const MCSymbolRefExpr *Sym
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
block|;
name|virtual
name|MCSection
operator|*
name|getStaticCtorSection
argument_list|(
argument|unsigned Priority
argument_list|,
argument|const MCSymbol *KeySym
argument_list|)
specifier|const
block|{
return|return
name|StaticCtorSection
return|;
block|}
name|virtual
name|MCSection
operator|*
name|getStaticDtorSection
argument_list|(
argument|unsigned Priority
argument_list|,
argument|const MCSymbol *KeySym
argument_list|)
specifier|const
block|{
return|return
name|StaticDtorSection
return|;
block|}
comment|/// \brief Create a symbol reference to describe the given TLS variable when
comment|/// emitting the address in debug info.
name|virtual
specifier|const
name|MCExpr
operator|*
name|getDebugThreadLocalSymbol
argument_list|(
argument|const MCSymbol *Sym
argument_list|)
specifier|const
block|;
name|virtual
specifier|const
name|MCExpr
operator|*
name|lowerRelativeReference
argument_list|(
argument|const GlobalValue *LHS
argument_list|,
argument|const GlobalValue *RHS
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// \brief Target supports replacing a data "PC"-relative access to a symbol
comment|/// through another symbol, by accessing the later via a GOT entry instead?
name|bool
name|supportIndirectSymViaGOTPCRel
argument_list|()
specifier|const
block|{
return|return
name|SupportIndirectSymViaGOTPCRel
return|;
block|}
comment|/// \brief Target GOT "PC"-relative relocation supports encoding an additional
comment|/// binary expression with an offset?
name|bool
name|supportGOTPCRelWithOffset
argument_list|()
specifier|const
block|{
return|return
name|SupportGOTPCRelWithOffset
return|;
block|}
comment|/// \brief Get the target specific PC relative GOT entry relocation
name|virtual
specifier|const
name|MCExpr
operator|*
name|getIndirectSymViaGOTPCRel
argument_list|(
argument|const MCSymbol *Sym
argument_list|,
argument|const MCValue&MV
argument_list|,
argument|int64_t Offset
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|void
name|emitLinkerFlagsForGlobal
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|{}
name|protected
operator|:
name|virtual
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalObject *GO
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
operator|=
literal|0
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
comment|// LLVM_TARGET_TARGETLOWERINGOBJECTFILE_H
end_comment

end_unit

