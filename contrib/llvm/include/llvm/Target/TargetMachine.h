begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetMachine.h - Target Information --------*- C++ -*-===//
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
comment|// This file defines the TargetMachine and LLVMTargetMachine classes.
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
name|LLVM_TARGET_TARGETMACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETMACHINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DataLayout.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MachineFunctionInitializer
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
name|class
name|PassManagerBuilder
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|TargetIntrinsicInfo
decl_stmt|;
name|class
name|TargetIRAnalysis
decl_stmt|;
name|class
name|TargetLoweringObjectFile
decl_stmt|;
name|class
name|TargetPassConfig
decl_stmt|;
name|class
name|TargetSubtargetInfo
decl_stmt|;
comment|// The old pass manager infrastructure is hidden in a legacy namespace now.
name|namespace
name|legacy
block|{
name|class
name|PassManagerBase
decl_stmt|;
block|}
name|using
name|legacy
operator|::
name|PassManagerBase
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// Primary interface to the complete machine description for the target
comment|/// machine.  All target-specific information should be accessible through this
comment|/// interface.
comment|///
name|class
name|TargetMachine
block|{
name|protected
label|:
comment|// Can only create subclasses.
name|TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef DataLayoutString
argument_list|,
argument|const Triple&TargetTriple
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|)
empty_stmt|;
comment|/// The Target that this machine was created for.
specifier|const
name|Target
modifier|&
name|TheTarget
decl_stmt|;
comment|/// DataLayout for the target: keep ABI type size and alignment.
comment|///
comment|/// The DataLayout is created based on the string representation provided
comment|/// during construction. It is kept here only to avoid reparsing the string
comment|/// but should not really be used during compilation, because it has an
comment|/// internal cache that is context specific.
specifier|const
name|DataLayout
name|DL
decl_stmt|;
comment|/// Triple string, CPU name, and target feature strings the TargetMachine
comment|/// instance is created with.
name|Triple
name|TargetTriple
decl_stmt|;
name|std
operator|::
name|string
name|TargetCPU
expr_stmt|;
name|std
operator|::
name|string
name|TargetFS
expr_stmt|;
name|Reloc
operator|::
name|Model
name|RM
operator|=
name|Reloc
operator|::
name|Static
expr_stmt|;
name|CodeModel
operator|::
name|Model
name|CMModel
operator|=
name|CodeModel
operator|::
name|Default
expr_stmt|;
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
operator|=
name|CodeGenOpt
operator|::
name|Default
expr_stmt|;
comment|/// Contains target specific asm information.
specifier|const
name|MCAsmInfo
modifier|*
name|AsmInfo
decl_stmt|;
specifier|const
name|MCRegisterInfo
modifier|*
name|MRI
decl_stmt|;
specifier|const
name|MCInstrInfo
modifier|*
name|MII
decl_stmt|;
specifier|const
name|MCSubtargetInfo
modifier|*
name|STI
decl_stmt|;
name|unsigned
name|RequireStructuredCFG
range|:
literal|1
decl_stmt|;
name|unsigned
name|O0WantsFastISel
range|:
literal|1
decl_stmt|;
name|public
label|:
specifier|const
name|TargetOptions
name|DefaultOptions
decl_stmt|;
name|mutable
name|TargetOptions
name|Options
decl_stmt|;
name|TargetMachine
argument_list|(
specifier|const
name|TargetMachine
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetMachine
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|virtual
operator|~
name|TargetMachine
argument_list|()
expr_stmt|;
specifier|const
name|Target
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|TheTarget
return|;
block|}
specifier|const
name|Triple
operator|&
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
name|StringRef
name|getTargetCPU
argument_list|()
specifier|const
block|{
return|return
name|TargetCPU
return|;
block|}
name|StringRef
name|getTargetFeatureString
argument_list|()
specifier|const
block|{
return|return
name|TargetFS
return|;
block|}
comment|/// Virtual method implemented by subclasses that returns a reference to that
comment|/// target's TargetSubtargetInfo-derived member variable.
name|virtual
specifier|const
name|TargetSubtargetInfo
modifier|*
name|getSubtargetImpl
argument_list|(
specifier|const
name|Function
operator|&
argument_list|)
decl|const
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|TargetLoweringObjectFile
operator|*
name|getObjFileLowering
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// This method returns a pointer to the specified type of
comment|/// TargetSubtargetInfo.  In debug builds, it verifies that the object being
comment|/// returned is of the correct type.
name|template
operator|<
name|typename
name|STC
operator|>
specifier|const
name|STC
operator|&
name|getSubtarget
argument_list|(
argument|const Function&F
argument_list|)
specifier|const
block|{
return|return
operator|*
name|static_cast
operator|<
specifier|const
name|STC
operator|*
operator|>
operator|(
name|getSubtargetImpl
argument_list|(
name|F
argument_list|)
operator|)
return|;
block|}
comment|/// Create a DataLayout.
specifier|const
name|DataLayout
name|createDataLayout
argument_list|()
specifier|const
block|{
return|return
name|DL
return|;
block|}
comment|/// Test if a DataLayout if compatible with the CodeGen for this target.
comment|///
comment|/// The LLVM Module owns a DataLayout that is used for the target independent
comment|/// optimizations and code generation. This hook provides a target specific
comment|/// check on the validity of this DataLayout.
name|bool
name|isCompatibleDataLayout
argument_list|(
specifier|const
name|DataLayout
operator|&
name|Candidate
argument_list|)
decl|const
block|{
return|return
name|DL
operator|==
name|Candidate
return|;
block|}
comment|/// Get the pointer size for this target.
comment|///
comment|/// This is the only time the DataLayout in the TargetMachine is used.
name|unsigned
name|getPointerSize
argument_list|()
specifier|const
block|{
return|return
name|DL
operator|.
name|getPointerSize
argument_list|()
return|;
block|}
comment|/// \brief Reset the target options based on the function's attributes.
comment|// FIXME: Remove TargetOptions that affect per-function code generation
comment|// from TargetMachine.
name|void
name|resetTargetOptions
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// Return target specific asm information.
specifier|const
name|MCAsmInfo
operator|*
name|getMCAsmInfo
argument_list|()
specifier|const
block|{
return|return
name|AsmInfo
return|;
block|}
specifier|const
name|MCRegisterInfo
operator|*
name|getMCRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|MRI
return|;
block|}
specifier|const
name|MCInstrInfo
operator|*
name|getMCInstrInfo
argument_list|()
specifier|const
block|{
return|return
name|MII
return|;
block|}
specifier|const
name|MCSubtargetInfo
operator|*
name|getMCSubtargetInfo
argument_list|()
specifier|const
block|{
return|return
name|STI
return|;
block|}
comment|/// If intrinsic information is available, return it.  If not, return null.
name|virtual
specifier|const
name|TargetIntrinsicInfo
operator|*
name|getIntrinsicInfo
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
name|bool
name|requiresStructuredCFG
argument_list|()
specifier|const
block|{
return|return
name|RequireStructuredCFG
return|;
block|}
name|void
name|setRequiresStructuredCFG
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|RequireStructuredCFG
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Returns the code generation relocation model. The choices are static, PIC,
comment|/// and dynamic-no-pic, and target default.
name|Reloc
operator|::
name|Model
name|getRelocationModel
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the code model. The choices are small, kernel, medium, large, and
comment|/// target default.
name|CodeModel
operator|::
name|Model
name|getCodeModel
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isPositionIndependent
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|shouldAssumeDSOLocal
argument_list|(
specifier|const
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns the TLS model which should be used for the given global variable.
name|TLSModel
operator|::
name|Model
name|getTLSModel
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
expr_stmt|;
comment|/// Returns the optimization level: None, Less, Default, or Aggressive.
name|CodeGenOpt
operator|::
name|Level
name|getOptLevel
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Overrides the optimization level.
name|void
name|setOptLevel
argument_list|(
name|CodeGenOpt
operator|::
name|Level
name|Level
argument_list|)
decl_stmt|;
name|void
name|setFastISel
parameter_list|(
name|bool
name|Enable
parameter_list|)
block|{
name|Options
operator|.
name|EnableFastISel
operator|=
name|Enable
expr_stmt|;
block|}
name|bool
name|getO0WantsFastISel
parameter_list|()
block|{
return|return
name|O0WantsFastISel
return|;
block|}
name|void
name|setO0WantsFastISel
parameter_list|(
name|bool
name|Enable
parameter_list|)
block|{
name|O0WantsFastISel
operator|=
name|Enable
expr_stmt|;
block|}
name|bool
name|shouldPrintMachineCode
argument_list|()
specifier|const
block|{
return|return
name|Options
operator|.
name|PrintMachineCode
return|;
block|}
name|bool
name|getUniqueSectionNames
argument_list|()
specifier|const
block|{
return|return
name|Options
operator|.
name|UniqueSectionNames
return|;
block|}
comment|/// Return true if data objects should be emitted into their own section,
comment|/// corresponds to -fdata-sections.
name|bool
name|getDataSections
argument_list|()
specifier|const
block|{
return|return
name|Options
operator|.
name|DataSections
return|;
block|}
comment|/// Return true if functions should be emitted into their own section,
comment|/// corresponding to -ffunction-sections.
name|bool
name|getFunctionSections
argument_list|()
specifier|const
block|{
return|return
name|Options
operator|.
name|FunctionSections
return|;
block|}
comment|/// \brief Get a \c TargetIRAnalysis appropriate for the target.
comment|///
comment|/// This is used to construct the new pass manager's target IR analysis pass,
comment|/// set up appropriately for this target machine. Even the old pass manager
comment|/// uses this to answer queries about the IR.
name|virtual
name|TargetIRAnalysis
name|getTargetIRAnalysis
parameter_list|()
function_decl|;
comment|/// Allow the target to modify the pass manager, e.g. by calling
comment|/// PassManagerBuilder::addExtension.
name|virtual
name|void
name|adjustPassManager
parameter_list|(
name|PassManagerBuilder
modifier|&
parameter_list|)
block|{}
comment|/// These enums are meant to be passed into addPassesToEmitFile to indicate
comment|/// what type of file to emit, and returned by it to indicate what type of
comment|/// file could actually be made.
enum|enum
name|CodeGenFileType
block|{
name|CGFT_AssemblyFile
block|,
name|CGFT_ObjectFile
block|,
name|CGFT_Null
comment|// Do not emit any output.
block|}
enum|;
comment|/// Add passes to the specified pass manager to get the specified file
comment|/// emitted.  Typically this will involve several steps of code generation.
comment|/// This method should return true if emission of this file type is not
comment|/// supported, or false on success.
name|virtual
name|bool
name|addPassesToEmitFile
parameter_list|(
name|PassManagerBase
modifier|&
parameter_list|,
name|raw_pwrite_stream
modifier|&
parameter_list|,
name|CodeGenFileType
parameter_list|,
name|bool
comment|/*DisableVerify*/
init|=
name|true
parameter_list|,
name|AnalysisID
comment|/*StartBefore*/
init|=
name|nullptr
parameter_list|,
name|AnalysisID
comment|/*StartAfter*/
init|=
name|nullptr
parameter_list|,
name|AnalysisID
comment|/*StopBefore*/
init|=
name|nullptr
parameter_list|,
name|AnalysisID
comment|/*StopAfter*/
init|=
name|nullptr
parameter_list|,
name|MachineFunctionInitializer
modifier|*
comment|/*MFInitializer*/
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// Add passes to the specified pass manager to get machine code emitted with
comment|/// the MCJIT. This method returns true if machine code is not supported. It
comment|/// fills the MCContext Ctx pointer which can be used to build custom
comment|/// MCStreamer.
comment|///
name|virtual
name|bool
name|addPassesToEmitMC
parameter_list|(
name|PassManagerBase
modifier|&
parameter_list|,
name|MCContext
modifier|*
modifier|&
parameter_list|,
name|raw_pwrite_stream
modifier|&
parameter_list|,
name|bool
comment|/*DisableVerify*/
init|=
name|true
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// True if subtarget inserts the final scheduling pass on its own.
comment|///
comment|/// Branch relaxation, which must happen after block placement, can
comment|/// on some targets (e.g. SystemZ) expose additional post-RA
comment|/// scheduling opportunities.
name|virtual
name|bool
name|targetSchedulesPostRAScheduling
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
empty_stmt|;
name|void
name|getNameWithPrefix
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Name
argument_list|,
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|Mangler
operator|&
name|Mang
argument_list|,
name|bool
name|MayAlwaysUsePrivate
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|getSymbol
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
comment|/// True if the target uses physical regs at Prolog/Epilog insertion
comment|/// time. If true (most machines), all vregs must be allocated before
comment|/// PEI. If false (virtual-register machines), then callee-save register
comment|/// spilling and scavenging are not needed or used.
name|virtual
name|bool
name|usesPhysRegsForPEI
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// This class describes a target machine that is implemented with the LLVM
comment|/// target-independent code generator.
comment|///
name|class
name|LLVMTargetMachine
range|:
name|public
name|TargetMachine
block|{
name|protected
operator|:
comment|// Can only create subclasses.
name|LLVMTargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef DataLayoutString
argument_list|,
argument|const Triple&TargetTriple
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|,
argument|Reloc::Model RM
argument_list|,
argument|CodeModel::Model CM
argument_list|,
argument|CodeGenOpt::Level OL
argument_list|)
block|;
name|void
name|initAsmInfo
argument_list|()
block|;
name|public
operator|:
comment|/// \brief Get a TargetIRAnalysis implementation for the target.
comment|///
comment|/// This analysis will produce a TTI result which uses the common code
comment|/// generator to answer queries about the IR.
name|TargetIRAnalysis
name|getTargetIRAnalysis
argument_list|()
name|override
block|;
comment|/// Create a pass configuration object to be used by addPassToEmitX methods
comment|/// for generating a pipeline of CodeGen passes.
name|virtual
name|TargetPassConfig
operator|*
name|createPassConfig
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
block|;
comment|/// Add passes to the specified pass manager to get the specified file
comment|/// emitted.  Typically this will involve several steps of code generation.
name|bool
name|addPassesToEmitFile
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|raw_pwrite_stream&Out
argument_list|,
argument|CodeGenFileType FileType
argument_list|,
argument|bool DisableVerify = true
argument_list|,
argument|AnalysisID StartBefore = nullptr
argument_list|,
argument|AnalysisID StartAfter = nullptr
argument_list|,
argument|AnalysisID StopBefore = nullptr
argument_list|,
argument|AnalysisID StopAfter = nullptr
argument_list|,
argument|MachineFunctionInitializer *MFInitializer = nullptr
argument_list|)
name|override
block|;
comment|/// Add passes to the specified pass manager to get machine code emitted with
comment|/// the MCJIT. This method returns true if machine code is not supported. It
comment|/// fills the MCContext Ctx pointer which can be used to build custom
comment|/// MCStreamer.
name|bool
name|addPassesToEmitMC
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|MCContext *&Ctx
argument_list|,
argument|raw_pwrite_stream&OS
argument_list|,
argument|bool DisableVerify = true
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
comment|// LLVM_TARGET_TARGETMACHINE_H
end_comment

end_unit

