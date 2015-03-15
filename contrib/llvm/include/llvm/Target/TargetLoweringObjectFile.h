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
name|ConstantExpr
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
specifier|const
name|DataLayout
operator|*
name|DL
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
name|nullptr
argument_list|)
block|,
name|DL
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|virtual
operator|~
name|TargetLoweringObjectFile
argument_list|()
block|;
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
argument|const TargetMachine&TM
argument_list|,
argument|const MCSymbol *Sym
argument_list|)
specifier|const
block|;
comment|/// Extract the dependent library name from a linker option string. Returns
comment|/// StringRef() if the option does not specify a library.
name|virtual
name|StringRef
name|getDepLibFromLinkerOpt
argument_list|(
argument|StringRef LinkerOption
argument_list|)
specifier|const
block|{
return|return
name|StringRef
argument_list|()
return|;
block|}
comment|/// Emit the module flags that the platform cares about.
name|virtual
name|void
name|emitModuleFlags
argument_list|(
argument|MCStreamer&Streamer
argument_list|,
argument|ArrayRef<Module::ModuleFlagEntry> Flags
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|{}
comment|/// Given a constant with the SectionKind, return a section that it should be
comment|/// placed in.
name|virtual
specifier|const
name|MCSection
operator|*
name|getSectionForConstant
argument_list|(
argument|SectionKind Kind
argument_list|,
argument|const Constant *C
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
comment|/// This method computes the appropriate section to emit the specified global
comment|/// variable or function definition. This should not be passed external (or
comment|/// available externally) globals.
specifier|const
name|MCSection
operator|*
name|SectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|;
comment|/// This method computes the appropriate section to emit the specified global
comment|/// variable or function definition. This should not be passed external (or
comment|/// available externally) globals.
specifier|const
name|MCSection
operator|*
name|SectionForGlobal
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|Mangler&Mang
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
comment|/// Targets should implement this method to assign a section to globals with
comment|/// an explicit section specfied. The implementation of this method can
comment|/// assume that GV->hasSection() is true.
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
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// Allow the target to completely override section assignment of a global.
name|virtual
specifier|const
name|MCSection
operator|*
name|getSpecialCasedSectionGlobals
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|SectionKind Kind
argument_list|,
argument|Mangler&Mang
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
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
argument|Mangler&Mang
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
argument|Mangler&Mang
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
argument|Mangler&Mang
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
specifier|const
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
specifier|const
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
name|getExecutableRelativeSymbol
argument_list|(
argument|const ConstantExpr *CE
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
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
argument|Mangler&Mang
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

end_unit

