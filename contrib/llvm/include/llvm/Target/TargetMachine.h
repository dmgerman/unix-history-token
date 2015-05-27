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
file|<cassert>
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
name|InstrItineraryData
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCCodeGenInfo
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TargetFrameLowering
decl_stmt|;
name|class
name|TargetIntrinsicInfo
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetPassConfig
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|TargetSelectionDAGInfo
decl_stmt|;
name|class
name|TargetSubtargetInfo
decl_stmt|;
name|class
name|ScalarTargetTransformInfo
decl_stmt|;
name|class
name|VectorTargetTransformInfo
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|TargetLoweringObjectFile
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
comment|/// TargetMachine - Primary interface to the complete machine description for
comment|/// the target machine.  All target-specific information should be accessible
comment|/// through this interface.
comment|///
name|class
name|TargetMachine
block|{
name|TargetMachine
argument_list|(
argument|const TargetMachine&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetMachine
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|protected
label|:
comment|// Can only create subclasses.
name|TargetMachine
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TargetTriple
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|const TargetOptions&Options
argument_list|)
empty_stmt|;
comment|/// TheTarget - The Target that this machine was created for.
specifier|const
name|Target
modifier|&
name|TheTarget
decl_stmt|;
comment|/// TargetTriple, TargetCPU, TargetFS - Triple string, CPU name, and target
comment|/// feature strings the TargetMachine instance is created with.
name|std
operator|::
name|string
name|TargetTriple
expr_stmt|;
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
comment|/// CodeGenInfo - Low level target information such as relocation model.
comment|/// Non-const to allow resetting optimization level per-function.
name|MCCodeGenInfo
modifier|*
name|CodeGenInfo
decl_stmt|;
comment|/// AsmInfo - Contains target specific asm information.
comment|///
specifier|const
name|MCAsmInfo
modifier|*
name|AsmInfo
decl_stmt|;
name|unsigned
name|RequireStructuredCFG
range|:
literal|1
decl_stmt|;
name|public
label|:
name|mutable
name|TargetOptions
name|Options
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
name|StringRef
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
comment|/// getSubtargetImpl - virtual method implemented by subclasses that returns
comment|/// a reference to that target's TargetSubtargetInfo-derived member variable.
name|virtual
specifier|const
name|TargetSubtargetInfo
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
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
name|getSubtargetImpl
argument_list|()
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
comment|/// getSubtarget - This method returns a pointer to the specified type of
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
argument_list|()
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
argument_list|()
operator|)
return|;
block|}
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
argument|const Function *
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
argument_list|()
operator|)
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
comment|/// getMCAsmInfo - Return target specific asm information.
comment|///
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
comment|/// getIntrinsicInfo - If intrinsic information is available, return it.  If
comment|/// not, return null.
comment|///
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
comment|/// getRelocationModel - Returns the code generation relocation model. The
comment|/// choices are static, PIC, and dynamic-no-pic, and target default.
name|Reloc
operator|::
name|Model
name|getRelocationModel
argument_list|()
specifier|const
expr_stmt|;
comment|/// getCodeModel - Returns the code model. The choices are small, kernel,
comment|/// medium, large, and target default.
name|CodeModel
operator|::
name|Model
name|getCodeModel
argument_list|()
specifier|const
expr_stmt|;
comment|/// getTLSModel - Returns the TLS model which should be used for the given
comment|/// global variable.
name|TLSModel
operator|::
name|Model
name|getTLSModel
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
expr_stmt|;
comment|/// getOptLevel - Returns the optimization level: None, Less,
comment|/// Default, or Aggressive.
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
decl|const
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
comment|/// getAsmVerbosityDefault - Returns the default value of asm verbosity.
comment|///
name|bool
name|getAsmVerbosityDefault
argument_list|()
specifier|const
expr_stmt|;
comment|/// setAsmVerbosityDefault - Set the default value of asm verbosity. Default
comment|/// is false.
name|void
name|setAsmVerbosityDefault
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|/// getDataSections - Return true if data objects should be emitted into their
comment|/// own section, corresponds to -fdata-sections.
name|bool
name|getDataSections
argument_list|()
specifier|const
expr_stmt|;
comment|/// getFunctionSections - Return true if functions should be emitted into
comment|/// their own section, corresponding to -ffunction-sections.
name|bool
name|getFunctionSections
argument_list|()
specifier|const
expr_stmt|;
comment|/// setDataSections - Set if the data are emit into separate sections.
name|void
name|setDataSections
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|/// setFunctionSections - Set if the functions are emit into separate
comment|/// sections.
name|void
name|setFunctionSections
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|/// \brief Register analysis passes for this target with a pass manager.
name|virtual
name|void
name|addAnalysisPasses
parameter_list|(
name|PassManagerBase
modifier|&
parameter_list|)
block|{}
comment|/// CodeGenFileType - These enums are meant to be passed into
comment|/// addPassesToEmitFile to indicate what type of file to emit, and returned by
comment|/// it to indicate what type of file could actually be made.
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
comment|/// addPassesToEmitFile - Add passes to the specified pass manager to get the
comment|/// specified file emitted.  Typically this will involve several steps of code
comment|/// generation.  This method should return true if emission of this file type
comment|/// is not supported, or false on success.
name|virtual
name|bool
name|addPassesToEmitFile
parameter_list|(
name|PassManagerBase
modifier|&
parameter_list|,
name|formatted_raw_ostream
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
comment|/*StartAfter*/
init|=
name|nullptr
parameter_list|,
name|AnalysisID
comment|/*StopAfter*/
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// addPassesToEmitMC - Add passes to the specified pass manager to get
comment|/// machine code emitted with the MCJIT. This method returns true if machine
comment|/// code is not supported. It fills the MCContext Ctx pointer which can be
comment|/// used to build custom MCStreamer.
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
name|raw_ostream
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
argument_list|,
name|Mangler
operator|&
name|Mang
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// LLVMTargetMachine - This class describes a target machine that is
comment|/// implemented with the LLVM target-independent code generator.
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
argument|StringRef TargetTriple
argument_list|,
argument|StringRef CPU
argument_list|,
argument|StringRef FS
argument_list|,
argument|TargetOptions Options
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
comment|/// \brief Register analysis passes for this target with a pass manager.
comment|///
comment|/// This registers target independent analysis passes.
name|void
name|addAnalysisPasses
argument_list|(
argument|PassManagerBase&PM
argument_list|)
name|override
block|;
comment|/// createPassConfig - Create a pass configuration object to be used by
comment|/// addPassToEmitX methods for generating a pipeline of CodeGen passes.
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
comment|/// addPassesToEmitFile - Add passes to the specified pass manager to get the
comment|/// specified file emitted.  Typically this will involve several steps of code
comment|/// generation.
name|bool
name|addPassesToEmitFile
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|formatted_raw_ostream&Out
argument_list|,
argument|CodeGenFileType FileType
argument_list|,
argument|bool DisableVerify = true
argument_list|,
argument|AnalysisID StartAfter = nullptr
argument_list|,
argument|AnalysisID StopAfter = nullptr
argument_list|)
name|override
block|;
comment|/// addPassesToEmitMC - Add passes to the specified pass manager to get
comment|/// machine code emitted with the MCJIT. This method returns true if machine
comment|/// code is not supported. It fills the MCContext Ctx pointer which can be
comment|/// used to build custom MCStreamer.
comment|///
name|bool
name|addPassesToEmitMC
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|MCContext *&Ctx
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|bool DisableVerify = true
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

