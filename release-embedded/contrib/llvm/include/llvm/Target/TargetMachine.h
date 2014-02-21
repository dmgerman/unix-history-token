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
name|JITCodeEmitter
decl_stmt|;
name|class
name|GlobalValue
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
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetIntrinsicInfo
decl_stmt|;
name|class
name|TargetJITInfo
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
name|MCRelaxAll
range|:
literal|1
decl_stmt|;
name|unsigned
name|MCNoExecStack
range|:
literal|1
decl_stmt|;
name|unsigned
name|MCSaveTempLabels
range|:
literal|1
decl_stmt|;
name|unsigned
name|MCUseLoc
range|:
literal|1
decl_stmt|;
name|unsigned
name|MCUseCFI
range|:
literal|1
decl_stmt|;
name|unsigned
name|MCUseDwarfDirectory
range|:
literal|1
decl_stmt|;
name|public
label|:
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
name|StringRef
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
specifier|const
name|StringRef
name|getTargetCPU
argument_list|()
specifier|const
block|{
return|return
name|TargetCPU
return|;
block|}
specifier|const
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
literal|0
return|;
block|}
name|mutable
name|TargetOptions
name|Options
decl_stmt|;
comment|/// \brief Reset the target options based on the function's attributes.
name|void
name|resetTargetOptions
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
decl|const
decl_stmt|;
comment|// Interfaces to the major aspects of target machine information:
comment|//
comment|// -- Instruction opcode and operand information
comment|// -- Pipelines and scheduling information
comment|// -- Stack frame information
comment|// -- Selection DAG lowering information
comment|//
comment|// N.B. These objects may change during compilation. It's not safe to cache
comment|// them between functions.
name|virtual
specifier|const
name|TargetInstrInfo
operator|*
name|getInstrInfo
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
specifier|const
name|TargetFrameLowering
operator|*
name|getFrameLowering
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
specifier|const
name|TargetLowering
operator|*
name|getTargetLowering
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
specifier|const
name|TargetSelectionDAGInfo
operator|*
name|getSelectionDAGInfo
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|virtual
specifier|const
name|DataLayout
operator|*
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
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
comment|/// getRegisterInfo - If register information is available, return it.  If
comment|/// not, return null.  This is kept separate from RegInfo until RegInfo has
comment|/// details of graph coloring register allocation removed from it.
comment|///
name|virtual
specifier|const
name|TargetRegisterInfo
operator|*
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
literal|0
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
literal|0
return|;
block|}
comment|/// getJITInfo - If this target supports a JIT, return information for it,
comment|/// otherwise return null.
comment|///
name|virtual
name|TargetJITInfo
modifier|*
name|getJITInfo
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|/// getInstrItineraryData - Returns instruction itinerary data for the target
comment|/// or specific subtarget.
comment|///
name|virtual
specifier|const
name|InstrItineraryData
operator|*
name|getInstrItineraryData
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// hasMCRelaxAll - Check whether all machine code instructions should be
comment|/// relaxed.
name|bool
name|hasMCRelaxAll
argument_list|()
specifier|const
block|{
return|return
name|MCRelaxAll
return|;
block|}
comment|/// setMCRelaxAll - Set whether all machine code instructions should be
comment|/// relaxed.
name|void
name|setMCRelaxAll
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|MCRelaxAll
operator|=
name|Value
expr_stmt|;
block|}
comment|/// hasMCSaveTempLabels - Check whether temporary labels will be preserved
comment|/// (i.e., not treated as temporary).
name|bool
name|hasMCSaveTempLabels
argument_list|()
specifier|const
block|{
return|return
name|MCSaveTempLabels
return|;
block|}
comment|/// setMCSaveTempLabels - Set whether temporary labels will be preserved
comment|/// (i.e., not treated as temporary).
name|void
name|setMCSaveTempLabels
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|MCSaveTempLabels
operator|=
name|Value
expr_stmt|;
block|}
comment|/// hasMCNoExecStack - Check whether an executable stack is not needed.
name|bool
name|hasMCNoExecStack
argument_list|()
specifier|const
block|{
return|return
name|MCNoExecStack
return|;
block|}
comment|/// setMCNoExecStack - Set whether an executabel stack is not needed.
name|void
name|setMCNoExecStack
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|MCNoExecStack
operator|=
name|Value
expr_stmt|;
block|}
comment|/// hasMCUseLoc - Check whether we should use dwarf's .loc directive.
name|bool
name|hasMCUseLoc
argument_list|()
specifier|const
block|{
return|return
name|MCUseLoc
return|;
block|}
comment|/// setMCUseLoc - Set whether all we should use dwarf's .loc directive.
name|void
name|setMCUseLoc
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|MCUseLoc
operator|=
name|Value
expr_stmt|;
block|}
comment|/// hasMCUseCFI - Check whether we should use dwarf's .cfi_* directives.
name|bool
name|hasMCUseCFI
argument_list|()
specifier|const
block|{
return|return
name|MCUseCFI
return|;
block|}
comment|/// setMCUseCFI - Set whether all we should use dwarf's .cfi_* directives.
name|void
name|setMCUseCFI
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|MCUseCFI
operator|=
name|Value
expr_stmt|;
block|}
comment|/// hasMCUseDwarfDirectory - Check whether we should use .file directives with
comment|/// explicit directories.
name|bool
name|hasMCUseDwarfDirectory
argument_list|()
specifier|const
block|{
return|return
name|MCUseDwarfDirectory
return|;
block|}
comment|/// setMCUseDwarfDirectory - Set whether all we should use .file directives
comment|/// with explicit directories.
name|void
name|setMCUseDwarfDirectory
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|MCUseDwarfDirectory
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
specifier|static
name|bool
name|getAsmVerbosityDefault
parameter_list|()
function_decl|;
comment|/// setAsmVerbosityDefault - Set the default value of asm verbosity. Default
comment|/// is false.
specifier|static
name|void
name|setAsmVerbosityDefault
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|/// getDataSections - Return true if data objects should be emitted into their
comment|/// own section, corresponds to -fdata-sections.
specifier|static
name|bool
name|getDataSections
parameter_list|()
function_decl|;
comment|/// getFunctionSections - Return true if functions should be emitted into
comment|/// their own section, corresponding to -ffunction-sections.
specifier|static
name|bool
name|getFunctionSections
parameter_list|()
function_decl|;
comment|/// setDataSections - Set if the data are emit into separate sections.
specifier|static
name|void
name|setDataSections
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|/// setFunctionSections - Set if the functions are emit into separate
comment|/// sections.
specifier|static
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
literal|0
parameter_list|,
name|AnalysisID
comment|/*StopAfter*/
init|=
literal|0
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// addPassesToEmitMachineCode - Add passes to the specified pass manager to
comment|/// get machine code emitted.  This uses a JITCodeEmitter object to handle
comment|/// actually outputting the machine code and resolving things like the address
comment|/// of functions.  This method returns true if machine code emission is
comment|/// not supported.
comment|///
name|virtual
name|bool
name|addPassesToEmitMachineCode
parameter_list|(
name|PassManagerBase
modifier|&
parameter_list|,
name|JITCodeEmitter
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
name|virtual
name|void
name|addAnalysisPasses
argument_list|(
name|PassManagerBase
operator|&
name|PM
argument_list|)
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
name|virtual
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
argument|AnalysisID StartAfter =
literal|0
argument_list|,
argument|AnalysisID StopAfter =
literal|0
argument_list|)
block|;
comment|/// addPassesToEmitMachineCode - Add passes to the specified pass manager to
comment|/// get machine code emitted.  This uses a JITCodeEmitter object to handle
comment|/// actually outputting the machine code and resolving things like the address
comment|/// of functions.  This method returns true if machine code emission is
comment|/// not supported.
comment|///
name|virtual
name|bool
name|addPassesToEmitMachineCode
argument_list|(
argument|PassManagerBase&PM
argument_list|,
argument|JITCodeEmitter&MCE
argument_list|,
argument|bool DisableVerify = true
argument_list|)
block|;
comment|/// addPassesToEmitMC - Add passes to the specified pass manager to get
comment|/// machine code emitted with the MCJIT. This method returns true if machine
comment|/// code is not supported. It fills the MCContext Ctx pointer which can be
comment|/// used to build custom MCStreamer.
comment|///
name|virtual
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
block|;
comment|/// addCodeEmitter - This pass should be overridden by the target to add a
comment|/// code emitter, if supported.  If this is not supported, 'true' should be
comment|/// returned.
name|virtual
name|bool
name|addCodeEmitter
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|JITCodeEmitter&
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

