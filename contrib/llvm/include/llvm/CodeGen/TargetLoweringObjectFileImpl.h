begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/TargetLoweringObjectFileImpl.h - Object Info -*- C++ -*-==//
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
name|LLVM_CODEGEN_TARGETLOWERINGOBJECTFILEIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_TARGETLOWERINGOBJECTFILEIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/SectionKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLoweringObjectFile.h"
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
name|MCAsmInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSectionMachO
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetLoweringObjectFileELF
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|bool
name|UseInitArray
block|;
name|public
operator|:
name|virtual
operator|~
name|TargetLoweringObjectFileELF
argument_list|()
block|{}
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
name|override
block|;
comment|/// Given a constant with the SectionKind, return a section that it should be
comment|/// placed in.
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
name|override
block|;
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
name|override
block|;
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
name|override
block|;
comment|/// Return an MCExpr to use for a reference to the specified type info global
comment|/// variable from exception handling information.
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
name|override
block|;
comment|// The symbol that gets passed to .cfi_personality.
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
name|override
block|;
name|void
name|InitializeELF
argument_list|(
argument|bool UseInitArray_
argument_list|)
block|;
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
name|override
block|;
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
name|override
block|; }
decl_stmt|;
name|class
name|TargetLoweringObjectFileMachO
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|public
operator|:
name|virtual
operator|~
name|TargetLoweringObjectFileMachO
argument_list|()
block|{}
comment|/// Extract the dependent library name from a linker option string. Returns
comment|/// StringRef() if the option does not specify a library.
name|StringRef
name|getDepLibFromLinkerOpt
argument_list|(
argument|StringRef LinkerOption
argument_list|)
specifier|const
name|override
block|;
comment|/// Emit the module flags that specify the garbage collection information.
name|void
name|emitModuleFlags
argument_list|(
argument|MCStreamer&Streamer
argument_list|,
argument|ArrayRef<Module::ModuleFlagEntry> ModuleFlags
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
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
name|override
block|;
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
name|override
block|;
comment|/// The mach-o version of this method defaults to returning a stub reference.
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
name|override
block|;
comment|// The symbol that gets passed to .cfi_personality.
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
name|override
block|; }
decl_stmt|;
name|class
name|TargetLoweringObjectFileCOFF
range|:
name|public
name|TargetLoweringObjectFile
block|{
name|public
operator|:
name|virtual
operator|~
name|TargetLoweringObjectFileCOFF
argument_list|()
block|{}
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
name|override
block|;
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
name|override
block|;
comment|/// Extract the dependent library name from a linker option string. Returns
comment|/// StringRef() if the option does not specify a library.
name|StringRef
name|getDepLibFromLinkerOpt
argument_list|(
argument|StringRef LinkerOption
argument_list|)
specifier|const
name|override
block|;
comment|/// Emit Obj-C garbage collection and linker options. Only linker option
comment|/// emission is implemented for COFF.
name|void
name|emitModuleFlags
argument_list|(
argument|MCStreamer&Streamer
argument_list|,
argument|ArrayRef<Module::ModuleFlagEntry> ModuleFlags
argument_list|,
argument|Mangler&Mang
argument_list|,
argument|const TargetMachine&TM
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
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

end_unit

