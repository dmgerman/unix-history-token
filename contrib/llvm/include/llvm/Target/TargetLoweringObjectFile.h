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

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|GlobalValue
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
block|;
name|TargetLoweringObjectFile
argument_list|(
argument|const TargetLoweringObjectFile&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|TargetLoweringObjectFile
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
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
name|TargetLoweringObjectFile
argument_list|()
operator|:
name|MCObjectFileInfo
argument_list|()
block|,
name|Ctx
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|TargetLoweringObjectFile
argument_list|()
block|;
comment|/// Initialize - this method must be called before any actual lowering is
comment|/// done.  This specifies the current context for codegen, and gives the
comment|/// lowering implementations a chance to set up their default sections.
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
argument|const TargetMachine&TM
argument_list|,
argument|const MCSymbol *Sym
argument_list|)
specifier|const
block|;
comment|/// emitModuleFlags - Emit the module flags that the platform cares about.
name|virtual
name|void
name|emitModuleFlags
argument_list|(
argument|MCStreamer&
argument_list|,
argument|ArrayRef<Module::ModuleFlagEntry>
argument_list|,
argument|Mangler *
argument_list|,
argument|const TargetMachine&
argument_list|)
specifier|const
block|{   }
comment|/// shouldEmitUsedDirectiveFor - This hook allows targets to selectively
comment|/// decide not to emit the UsedDirective for some symbols in llvm.used.
comment|/// FIXME: REMOVE this (rdar://7071300)
name|virtual
name|bool
name|shouldEmitUsedDirectiveFor
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *
argument_list|)
specifier|const
block|{
return|return
name|GV
operator|!=
literal|0
return|;
block|}
comment|/// getSectionForConstant - Given a constant with the SectionKind, return a
comment|/// section that it should be placed in.
name|virtual
specifier|const
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|SectionKind Kind
argument_list|)
specifier|const
block|;
comment|/// getKindForGlobal - Classify the specified global variable into a set of
comment|/// target independent categories embodied in SectionKind.
specifier|static
name|SectionKind
name|getKindForGlobal
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|)
block|;
comment|/// SectionForGlobal - This method computes the appropriate section to emit
comment|/// the specified global variable or function definition.  This should not
comment|/// be passed external (or available externally) globals.
specifier|const
name|MCSection
operator|*
name|SectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// SectionForGlobal - This method computes the appropriate section to emit
comment|/// the specified global variable or function definition.  This should not
comment|/// be passed external (or available externally) globals.
specifier|const
name|MCSection
operator|*
name|SectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|{
return|return
name|SectionForGlobal
argument_list|(
name|GV
argument_list|,
name|getKindForGlobal
argument_list|(
name|GV
argument_list|,
name|TM
argument_list|)
argument_list|,
name|Mang
argument_list|,
name|TM
argument_list|)
return|;
block|}
comment|/// getExplicitSectionGlobal - Targets should implement this method to assign
comment|/// a section to globals with an explicit section specfied.  The
comment|/// implementation of this method can assume that GV->hasSection() is true.
name|virtual
specifier|const
name|MCSection
operator|*
name|getExplicitSectionGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// getSpecialCasedSectionGlobals - Allow the target to completely override
comment|/// section assignment of a global.
name|virtual
specifier|const
name|MCSection
operator|*
name|getSpecialCasedSectionGlobals
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|SectionKind Kind
argument_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// getTTypeGlobalReference - Return an MCExpr to use for a reference
comment|/// to the specified global variable from exception handling information.
comment|///
name|virtual
specifier|const
name|MCExpr
operator|*
name|getTTypeGlobalReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|,
argument|unsigned Encoding
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
specifier|const
block|;
comment|/// Return the MCSymbol for the specified global value.  This symbol is the
comment|/// main label that is the address of the global
name|MCSymbol
operator|*
name|getSymbol
argument_list|(
argument|Mangler&M
argument_list|,
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
comment|// getCFIPersonalitySymbol - The symbol that gets passed to .cfi_personality.
name|virtual
name|MCSymbol
operator|*
name|getCFIPersonalitySymbol
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|MachineModuleInfo *MMI
argument_list|)
specifier|const
block|;
comment|///
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
specifier|const
name|MCSection
operator|*
name|getStaticCtorSection
argument_list|(
argument|unsigned Priority =
literal|65535
argument_list|)
specifier|const
block|{
operator|(
name|void
operator|)
name|Priority
block|;
return|return
name|StaticCtorSection
return|;
block|}
name|virtual
specifier|const
name|MCSection
operator|*
name|getStaticDtorSection
argument_list|(
argument|unsigned Priority =
literal|65535
argument_list|)
specifier|const
block|{
operator|(
name|void
operator|)
name|Priority
block|;
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
name|protected
operator|:
name|virtual
specifier|const
name|MCSection
operator|*
name|SelectSectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler *Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
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

end_unit

