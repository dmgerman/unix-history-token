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
file|"llvm/Target/TargetInstrItineraries.h"
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
name|Target
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|TargetSubtarget
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
name|TargetSelectionDAGInfo
decl_stmt|;
name|class
name|TargetFrameLowering
decl_stmt|;
name|class
name|JITCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|PassManagerBase
decl_stmt|;
name|class
name|PassManager
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|TargetELFWriterInfo
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|// Relocation model types.
name|namespace
name|Reloc
block|{
enum|enum
name|Model
block|{
name|Default
block|,
name|Static
block|,
name|PIC_
block|,
comment|// Cannot be named PIC due to collision with -DPIC
name|DynamicNoPIC
block|}
enum|;
block|}
comment|// Code model types.
name|namespace
name|CodeModel
block|{
enum|enum
name|Model
block|{
name|Default
block|,
name|Small
block|,
name|Kernel
block|,
name|Medium
block|,
name|Large
block|}
enum|;
block|}
comment|// Code generation optimization level.
name|namespace
name|CodeGenOpt
block|{
enum|enum
name|Level
block|{
name|None
block|,
comment|// -O0
name|Less
block|,
comment|// -O1
name|Default
block|,
comment|// -O2, -Os
name|Aggressive
comment|// -O3
block|}
enum|;
block|}
name|namespace
name|Sched
block|{
enum|enum
name|Preference
block|{
name|None
block|,
comment|// No preference
name|Latency
block|,
comment|// Scheduling for shortest total latency.
name|RegPressure
block|,
comment|// Scheduling for lowest register pressure.
name|Hybrid
block|,
comment|// Scheduling for both latency and register pressure.
name|ILP
comment|// Scheduling for ILP in low register pressure mode.
block|}
enum|;
block|}
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
specifier|const
name|TargetMachine
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetMachine
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses.
name|TargetMachine
argument_list|(
specifier|const
name|Target
operator|&
argument_list|)
expr_stmt|;
comment|/// getSubtargetImpl - virtual method implemented by subclasses that returns
comment|/// a reference to that target's TargetSubtarget-derived member variable.
name|virtual
specifier|const
name|TargetSubtarget
operator|*
name|getSubtargetImpl
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// TheTarget - The Target that this machine was created for.
specifier|const
name|Target
modifier|&
name|TheTarget
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
comment|// Interfaces to the major aspects of target machine information:
comment|// -- Instruction opcode and operand information
comment|// -- Pipelines and scheduling information
comment|// -- Stack frame information
comment|// -- Selection DAG lowering information
comment|//
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
name|TargetData
operator|*
name|getTargetData
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
comment|/// TargetSubtarget.  In debug builds, it verifies that the object being
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
comment|/// getELFWriterInfo - If this target supports an ELF writer, return
comment|/// information for it, otherwise return null.
comment|///
name|virtual
specifier|const
name|TargetELFWriterInfo
operator|*
name|getELFWriterInfo
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
comment|/// getRelocationModel - Returns the code generation relocation model. The
comment|/// choices are static, PIC, and dynamic-no-pic, and target default.
specifier|static
name|Reloc
operator|::
name|Model
name|getRelocationModel
argument_list|()
expr_stmt|;
comment|/// setRelocationModel - Sets the code generation relocation model.
comment|///
specifier|static
name|void
name|setRelocationModel
argument_list|(
name|Reloc
operator|::
name|Model
name|Model
argument_list|)
decl_stmt|;
comment|/// getCodeModel - Returns the code model. The choices are small, kernel,
comment|/// medium, large, and target default.
specifier|static
name|CodeModel
operator|::
name|Model
name|getCodeModel
argument_list|()
expr_stmt|;
comment|/// setCodeModel - Sets the code model.
comment|///
specifier|static
name|void
name|setCodeModel
argument_list|(
name|CodeModel
operator|::
name|Model
name|Model
argument_list|)
decl_stmt|;
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
comment|/// getEnableTailMergeDefault - the default setting for -enable-tail-merge
comment|/// on this target.  User flag overrides.
name|virtual
name|bool
name|getEnableTailMergeDefault
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// addPassesToEmitFile - Add passes to the specified pass manager to get the
comment|/// specified file emitted.  Typically this will involve several steps of code
comment|/// generation.  This method should return true if emission of this file type
comment|/// is not supported, or false on success.
name|virtual
name|bool
name|addPassesToEmitFile
argument_list|(
name|PassManagerBase
operator|&
argument_list|,
name|formatted_raw_ostream
operator|&
argument_list|,
name|CodeGenFileType
argument_list|,
name|CodeGenOpt
operator|::
name|Level
argument_list|,
name|bool
operator|=
name|true
argument_list|)
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
argument_list|(
name|PassManagerBase
operator|&
argument_list|,
name|JITCodeEmitter
operator|&
argument_list|,
name|CodeGenOpt
operator|::
name|Level
argument_list|,
name|bool
operator|=
name|true
argument_list|)
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
argument_list|(
name|PassManagerBase
operator|&
argument_list|,
name|MCContext
operator|*
operator|&
argument_list|,
name|raw_ostream
operator|&
argument_list|,
name|CodeGenOpt
operator|::
name|Level
argument_list|,
name|bool
operator|=
name|true
argument_list|)
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
name|std
operator|::
name|string
name|TargetTriple
block|;
name|protected
operator|:
comment|// Can only create subclasses.
name|LLVMTargetMachine
argument_list|(
specifier|const
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|TargetTriple
argument_list|)
block|;
name|private
operator|:
comment|/// addCommonCodeGenPasses - Add standard LLVM codegen passes used for
comment|/// both emitting to assembly files or machine code output.
comment|///
name|bool
name|addCommonCodeGenPasses
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|,
argument|bool DisableVerify
argument_list|,
argument|MCContext *&OutCtx
argument_list|)
block|;
name|virtual
name|void
name|setCodeModelForJIT
argument_list|()
block|;
name|virtual
name|void
name|setCodeModelForStatic
argument_list|()
block|;
name|public
operator|:
specifier|const
name|std
operator|::
name|string
operator|&
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
comment|/// addPassesToEmitFile - Add passes to the specified pass manager to get the
comment|/// specified file emitted.  Typically this will involve several steps of code
comment|/// generation.  If OptLevel is None, the code generator should emit code as
comment|/// fast as possible, though the generated code may be less efficient.
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
argument|CodeGenOpt::Level
argument_list|,
argument|bool DisableVerify = true
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
argument|CodeGenOpt::Level
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
argument|CodeGenOpt::Level OptLevel
argument_list|,
argument|bool DisableVerify = true
argument_list|)
block|;
comment|/// Target-Independent Code Generator Pass Configuration Options.
comment|/// addPreISelPasses - This method should add any "last minute" LLVM->LLVM
comment|/// passes (which are run just before instruction selector).
name|virtual
name|bool
name|addPreISel
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// addInstSelector - This method should install an instruction selector pass,
comment|/// which converts from LLVM code to machine instructions.
name|virtual
name|bool
name|addInstSelector
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// addPreRegAlloc - This method may be implemented by targets that want to
comment|/// run passes immediately before register allocation. This should return
comment|/// true if -print-machineinstrs should print after these passes.
name|virtual
name|bool
name|addPreRegAlloc
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// addPostRegAlloc - This method may be implemented by targets that want
comment|/// to run passes after register allocation but before prolog-epilog
comment|/// insertion.  This should return true if -print-machineinstrs should print
comment|/// after these passes.
name|virtual
name|bool
name|addPostRegAlloc
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// addPreSched2 - This method may be implemented by targets that want to
comment|/// run passes after prolog-epilog insertion and before the second instruction
comment|/// scheduling pass.  This should return true if -print-machineinstrs should
comment|/// print after these passes.
name|virtual
name|bool
name|addPreSched2
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// addPreEmitPass - This pass may be implemented by targets that want to run
comment|/// passes immediately before machine code is emitted.  This should return
comment|/// true if -print-machineinstrs should print out the code after the passes.
name|virtual
name|bool
name|addPreEmitPass
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// addCodeEmitter - This pass should be overridden by the target to add a
comment|/// code emitter, if supported.  If this is not supported, 'true' should be
comment|/// returned.
name|virtual
name|bool
name|addCodeEmitter
argument_list|(
argument|PassManagerBase&
argument_list|,
argument|CodeGenOpt::Level
argument_list|,
argument|JITCodeEmitter&
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// getEnableTailMergeDefault - the default setting for -enable-tail-merge
comment|/// on this target.  User flag overrides.
name|virtual
name|bool
name|getEnableTailMergeDefault
argument_list|()
specifier|const
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

