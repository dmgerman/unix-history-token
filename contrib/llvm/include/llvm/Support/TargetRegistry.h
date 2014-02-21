begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Support/TargetRegistry.h - Target Registration ----------*- C++ -*-===//
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
comment|// This file exposes the TargetRegistry interface, which tools can use to access
end_comment

begin_comment
comment|// the appropriate target specific classes (TargetMachine, AsmPrinter, etc.)
end_comment

begin_comment
comment|// which have been registered.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Target specific class implementations should register themselves using the
end_comment

begin_comment
comment|// appropriate TargetRegistry interfaces.
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
name|LLVM_SUPPORT_TARGETREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TARGETREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Disassembler.h"
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
name|AsmPrinter
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|MCAssembler
decl_stmt|;
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCAsmParser
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCCodeGenInfo
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCDisassembler
decl_stmt|;
name|class
name|MCInstrAnalysis
decl_stmt|;
name|class
name|MCInstPrinter
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|MCSymbolizer
decl_stmt|;
name|class
name|MCRelocationInfo
decl_stmt|;
name|class
name|MCTargetAsmParser
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|MCTargetStreamer
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|MCStreamer
modifier|*
name|createAsmStreamer
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|MCTargetStreamer
modifier|*
name|TargetStreamer
parameter_list|,
name|formatted_raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|isVerboseAsm
parameter_list|,
name|bool
name|useLoc
parameter_list|,
name|bool
name|useCFI
parameter_list|,
name|bool
name|useDwarfDirectory
parameter_list|,
name|MCInstPrinter
modifier|*
name|InstPrint
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
parameter_list|,
name|MCAsmBackend
modifier|*
name|TAB
parameter_list|,
name|bool
name|ShowInst
parameter_list|)
function_decl|;
name|MCRelocationInfo
modifier|*
name|createMCRelocationInfo
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|MCSymbolizer
modifier|*
name|createMCSymbolizer
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|LLVMOpInfoCallback
name|GetOpInfo
parameter_list|,
name|LLVMSymbolLookupCallback
name|SymbolLookUp
parameter_list|,
name|void
modifier|*
name|DisInfo
parameter_list|,
name|MCContext
modifier|*
name|Ctx
parameter_list|,
name|MCRelocationInfo
modifier|*
name|RelInfo
parameter_list|)
function_decl|;
comment|/// Target - Wrapper for Target specific information.
comment|///
comment|/// For registration purposes, this is a POD type so that targets can be
comment|/// registered without the use of static constructors.
comment|///
comment|/// Targets should implement a single global instance of this class (which
comment|/// will be zero initialized), and pass that instance to the TargetRegistry as
comment|/// part of their initialization.
name|class
name|Target
block|{
name|public
label|:
name|friend
struct_decl|struct
name|TargetRegistry
struct_decl|;
typedef|typedef
name|unsigned
argument_list|(
operator|*
name|TripleMatchQualityFnTy
argument_list|)
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|TT
argument_list|)
expr_stmt|;
typedef|typedef
name|MCAsmInfo
modifier|*
function_decl|(
modifier|*
name|MCAsmInfoCtorFnTy
function_decl|)
parameter_list|(
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
name|StringRef
name|TT
parameter_list|)
function_decl|;
typedef|typedef
name|MCCodeGenInfo
operator|*
operator|(
operator|*
name|MCCodeGenInfoCtorFnTy
operator|)
operator|(
name|StringRef
name|TT
operator|,
name|Reloc
operator|::
name|Model
name|RM
operator|,
name|CodeModel
operator|::
name|Model
name|CM
operator|,
name|CodeGenOpt
operator|::
name|Level
name|OL
operator|)
expr_stmt|;
typedef|typedef
name|MCInstrInfo
modifier|*
function_decl|(
modifier|*
name|MCInstrInfoCtorFnTy
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
typedef|typedef
name|MCInstrAnalysis
modifier|*
function_decl|(
modifier|*
name|MCInstrAnalysisCtorFnTy
function_decl|)
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|*
name|Info
parameter_list|)
function_decl|;
typedef|typedef
name|MCRegisterInfo
modifier|*
function_decl|(
modifier|*
name|MCRegInfoCtorFnTy
function_decl|)
parameter_list|(
name|StringRef
name|TT
parameter_list|)
function_decl|;
typedef|typedef
name|MCSubtargetInfo
modifier|*
function_decl|(
modifier|*
name|MCSubtargetInfoCtorFnTy
function_decl|)
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|,
name|StringRef
name|Features
parameter_list|)
function_decl|;
typedef|typedef
name|TargetMachine
operator|*
operator|(
operator|*
name|TargetMachineCtorTy
operator|)
operator|(
specifier|const
name|Target
operator|&
name|T
operator|,
name|StringRef
name|TT
operator|,
name|StringRef
name|CPU
operator|,
name|StringRef
name|Features
operator|,
specifier|const
name|TargetOptions
operator|&
name|Options
operator|,
name|Reloc
operator|::
name|Model
name|RM
operator|,
name|CodeModel
operator|::
name|Model
name|CM
operator|,
name|CodeGenOpt
operator|::
name|Level
name|OL
operator|)
expr_stmt|;
typedef|typedef
name|AsmPrinter
modifier|*
function_decl|(
modifier|*
name|AsmPrinterCtorTy
function_decl|)
parameter_list|(
name|TargetMachine
modifier|&
name|TM
parameter_list|,
name|MCStreamer
modifier|&
name|Streamer
parameter_list|)
function_decl|;
typedef|typedef
name|MCAsmBackend
modifier|*
function_decl|(
modifier|*
name|MCAsmBackendCtorTy
function_decl|)
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
name|StringRef
name|TT
parameter_list|,
name|StringRef
name|CPU
parameter_list|)
function_decl|;
typedef|typedef
name|MCTargetAsmParser
modifier|*
function_decl|(
modifier|*
name|MCAsmParserCtorTy
function_decl|)
parameter_list|(
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|,
name|MCAsmParser
modifier|&
name|P
parameter_list|,
specifier|const
name|MCInstrInfo
modifier|&
name|MII
parameter_list|)
function_decl|;
typedef|typedef
name|MCDisassembler
modifier|*
function_decl|(
modifier|*
name|MCDisassemblerCtorTy
function_decl|)
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
typedef|typedef
name|MCInstPrinter
modifier|*
function_decl|(
modifier|*
name|MCInstPrinterCtorTy
function_decl|)
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
name|unsigned
name|SyntaxVariant
parameter_list|,
specifier|const
name|MCAsmInfo
modifier|&
name|MAI
parameter_list|,
specifier|const
name|MCInstrInfo
modifier|&
name|MII
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
typedef|typedef
name|MCCodeEmitter
modifier|*
function_decl|(
modifier|*
name|MCCodeEmitterCtorTy
function_decl|)
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|II
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
typedef|typedef
name|MCStreamer
modifier|*
function_decl|(
modifier|*
name|MCObjectStreamerCtorTy
function_decl|)
parameter_list|(
specifier|const
name|Target
modifier|&
name|T
parameter_list|,
name|StringRef
name|TT
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|MCAsmBackend
modifier|&
name|TAB
parameter_list|,
name|raw_ostream
modifier|&
name|_OS
parameter_list|,
name|MCCodeEmitter
modifier|*
name|_Emitter
parameter_list|,
name|bool
name|RelaxAll
parameter_list|,
name|bool
name|NoExecStack
parameter_list|)
function_decl|;
typedef|typedef
name|MCStreamer
modifier|*
function_decl|(
modifier|*
name|AsmStreamerCtorTy
function_decl|)
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|,
name|formatted_raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|isVerboseAsm
parameter_list|,
name|bool
name|useLoc
parameter_list|,
name|bool
name|useCFI
parameter_list|,
name|bool
name|useDwarfDirectory
parameter_list|,
name|MCInstPrinter
modifier|*
name|InstPrint
parameter_list|,
name|MCCodeEmitter
modifier|*
name|CE
parameter_list|,
name|MCAsmBackend
modifier|*
name|TAB
parameter_list|,
name|bool
name|ShowInst
parameter_list|)
function_decl|;
typedef|typedef
name|MCRelocationInfo
modifier|*
function_decl|(
modifier|*
name|MCRelocationInfoCtorTy
function_decl|)
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
typedef|typedef
name|MCSymbolizer
modifier|*
function_decl|(
modifier|*
name|MCSymbolizerCtorTy
function_decl|)
parameter_list|(
name|StringRef
name|TT
parameter_list|,
name|LLVMOpInfoCallback
name|GetOpInfo
parameter_list|,
name|LLVMSymbolLookupCallback
name|SymbolLookUp
parameter_list|,
name|void
modifier|*
name|DisInfo
parameter_list|,
name|MCContext
modifier|*
name|Ctx
parameter_list|,
name|MCRelocationInfo
modifier|*
name|RelInfo
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Next - The next registered target in the linked list, maintained by the
comment|/// TargetRegistry.
name|Target
modifier|*
name|Next
decl_stmt|;
comment|/// TripleMatchQualityFn - The target function for rating the match quality
comment|/// of a triple.
name|TripleMatchQualityFnTy
name|TripleMatchQualityFn
decl_stmt|;
comment|/// Name - The target name.
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|/// ShortDesc - A short description of the target.
specifier|const
name|char
modifier|*
name|ShortDesc
decl_stmt|;
comment|/// HasJIT - Whether this target supports the JIT.
name|bool
name|HasJIT
decl_stmt|;
comment|/// MCAsmInfoCtorFn - Constructor function for this target's MCAsmInfo, if
comment|/// registered.
name|MCAsmInfoCtorFnTy
name|MCAsmInfoCtorFn
decl_stmt|;
comment|/// MCCodeGenInfoCtorFn - Constructor function for this target's
comment|/// MCCodeGenInfo, if registered.
name|MCCodeGenInfoCtorFnTy
name|MCCodeGenInfoCtorFn
decl_stmt|;
comment|/// MCInstrInfoCtorFn - Constructor function for this target's MCInstrInfo,
comment|/// if registered.
name|MCInstrInfoCtorFnTy
name|MCInstrInfoCtorFn
decl_stmt|;
comment|/// MCInstrAnalysisCtorFn - Constructor function for this target's
comment|/// MCInstrAnalysis, if registered.
name|MCInstrAnalysisCtorFnTy
name|MCInstrAnalysisCtorFn
decl_stmt|;
comment|/// MCRegInfoCtorFn - Constructor function for this target's MCRegisterInfo,
comment|/// if registered.
name|MCRegInfoCtorFnTy
name|MCRegInfoCtorFn
decl_stmt|;
comment|/// MCSubtargetInfoCtorFn - Constructor function for this target's
comment|/// MCSubtargetInfo, if registered.
name|MCSubtargetInfoCtorFnTy
name|MCSubtargetInfoCtorFn
decl_stmt|;
comment|/// TargetMachineCtorFn - Construction function for this target's
comment|/// TargetMachine, if registered.
name|TargetMachineCtorTy
name|TargetMachineCtorFn
decl_stmt|;
comment|/// MCAsmBackendCtorFn - Construction function for this target's
comment|/// MCAsmBackend, if registered.
name|MCAsmBackendCtorTy
name|MCAsmBackendCtorFn
decl_stmt|;
comment|/// MCAsmParserCtorFn - Construction function for this target's
comment|/// MCTargetAsmParser, if registered.
name|MCAsmParserCtorTy
name|MCAsmParserCtorFn
decl_stmt|;
comment|/// AsmPrinterCtorFn - Construction function for this target's AsmPrinter,
comment|/// if registered.
name|AsmPrinterCtorTy
name|AsmPrinterCtorFn
decl_stmt|;
comment|/// MCDisassemblerCtorFn - Construction function for this target's
comment|/// MCDisassembler, if registered.
name|MCDisassemblerCtorTy
name|MCDisassemblerCtorFn
decl_stmt|;
comment|/// MCInstPrinterCtorFn - Construction function for this target's
comment|/// MCInstPrinter, if registered.
name|MCInstPrinterCtorTy
name|MCInstPrinterCtorFn
decl_stmt|;
comment|/// MCCodeEmitterCtorFn - Construction function for this target's
comment|/// CodeEmitter, if registered.
name|MCCodeEmitterCtorTy
name|MCCodeEmitterCtorFn
decl_stmt|;
comment|/// MCObjectStreamerCtorFn - Construction function for this target's
comment|/// MCObjectStreamer, if registered.
name|MCObjectStreamerCtorTy
name|MCObjectStreamerCtorFn
decl_stmt|;
comment|/// AsmStreamerCtorFn - Construction function for this target's
comment|/// AsmStreamer, if registered (default = llvm::createAsmStreamer).
name|AsmStreamerCtorTy
name|AsmStreamerCtorFn
decl_stmt|;
comment|/// MCRelocationInfoCtorFn - Construction function for this target's
comment|/// MCRelocationInfo, if registered (default = llvm::createMCRelocationInfo)
name|MCRelocationInfoCtorTy
name|MCRelocationInfoCtorFn
decl_stmt|;
comment|/// MCSymbolizerCtorFn - Construction function for this target's
comment|/// MCSymbolizer, if registered (default = llvm::createMCSymbolizer)
name|MCSymbolizerCtorTy
name|MCSymbolizerCtorFn
decl_stmt|;
name|public
label|:
name|Target
argument_list|()
operator|:
name|AsmStreamerCtorFn
argument_list|(
literal|0
argument_list|)
operator|,
name|MCRelocationInfoCtorFn
argument_list|(
literal|0
argument_list|)
operator|,
name|MCSymbolizerCtorFn
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// @name Target Information
comment|/// @{
comment|// getNext - Return the next registered target.
specifier|const
name|Target
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
comment|/// getName - Get the target name.
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// getShortDescription - Get a short description of the target.
specifier|const
name|char
operator|*
name|getShortDescription
argument_list|()
specifier|const
block|{
return|return
name|ShortDesc
return|;
block|}
comment|/// @}
comment|/// @name Feature Predicates
comment|/// @{
comment|/// hasJIT - Check if this targets supports the just-in-time compilation.
name|bool
name|hasJIT
argument_list|()
specifier|const
block|{
return|return
name|HasJIT
return|;
block|}
comment|/// hasTargetMachine - Check if this target supports code generation.
name|bool
name|hasTargetMachine
argument_list|()
specifier|const
block|{
return|return
name|TargetMachineCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// hasMCAsmBackend - Check if this target supports .o generation.
name|bool
name|hasMCAsmBackend
argument_list|()
specifier|const
block|{
return|return
name|MCAsmBackendCtorFn
operator|!=
literal|0
return|;
block|}
comment|/// @}
comment|/// @name Feature Constructors
comment|/// @{
comment|/// createMCAsmInfo - Create a MCAsmInfo implementation for the specified
comment|/// target triple.
comment|///
comment|/// \param Triple This argument is used to determine the target machine
comment|/// feature set; it should always be provided. Generally this should be
comment|/// either the target triple from the module, or the target triple of the
comment|/// host if that does not exist.
name|MCAsmInfo
modifier|*
name|createMCAsmInfo
argument_list|(
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|,
name|StringRef
name|Triple
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCAsmInfoCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCAsmInfoCtorFn
argument_list|(
name|MRI
argument_list|,
name|Triple
argument_list|)
return|;
block|}
comment|/// createMCCodeGenInfo - Create a MCCodeGenInfo implementation.
comment|///
name|MCCodeGenInfo
modifier|*
name|createMCCodeGenInfo
argument_list|(
name|StringRef
name|Triple
argument_list|,
name|Reloc
operator|::
name|Model
name|RM
argument_list|,
name|CodeModel
operator|::
name|Model
name|CM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OL
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCCodeGenInfoCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCCodeGenInfoCtorFn
argument_list|(
name|Triple
argument_list|,
name|RM
argument_list|,
name|CM
argument_list|,
name|OL
argument_list|)
return|;
block|}
comment|/// createMCInstrInfo - Create a MCInstrInfo implementation.
comment|///
name|MCInstrInfo
operator|*
name|createMCInstrInfo
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|MCInstrInfoCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCInstrInfoCtorFn
argument_list|()
return|;
block|}
comment|/// createMCInstrAnalysis - Create a MCInstrAnalysis implementation.
comment|///
name|MCInstrAnalysis
modifier|*
name|createMCInstrAnalysis
argument_list|(
specifier|const
name|MCInstrInfo
operator|*
name|Info
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCInstrAnalysisCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCInstrAnalysisCtorFn
argument_list|(
name|Info
argument_list|)
return|;
block|}
comment|/// createMCRegInfo - Create a MCRegisterInfo implementation.
comment|///
name|MCRegisterInfo
modifier|*
name|createMCRegInfo
argument_list|(
name|StringRef
name|Triple
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCRegInfoCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCRegInfoCtorFn
argument_list|(
name|Triple
argument_list|)
return|;
block|}
comment|/// createMCSubtargetInfo - Create a MCSubtargetInfo implementation.
comment|///
comment|/// \param Triple This argument is used to determine the target machine
comment|/// feature set; it should always be provided. Generally this should be
comment|/// either the target triple from the module, or the target triple of the
comment|/// host if that does not exist.
comment|/// \param CPU This specifies the name of the target CPU.
comment|/// \param Features This specifies the string representation of the
comment|/// additional target features.
name|MCSubtargetInfo
modifier|*
name|createMCSubtargetInfo
argument_list|(
name|StringRef
name|Triple
argument_list|,
name|StringRef
name|CPU
argument_list|,
name|StringRef
name|Features
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCSubtargetInfoCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCSubtargetInfoCtorFn
argument_list|(
name|Triple
argument_list|,
name|CPU
argument_list|,
name|Features
argument_list|)
return|;
block|}
comment|/// createTargetMachine - Create a target specific machine implementation
comment|/// for the specified \p Triple.
comment|///
comment|/// \param Triple This argument is used to determine the target machine
comment|/// feature set; it should always be provided. Generally this should be
comment|/// either the target triple from the module, or the target triple of the
comment|/// host if that does not exist.
name|TargetMachine
modifier|*
name|createTargetMachine
argument_list|(
name|StringRef
name|Triple
argument_list|,
name|StringRef
name|CPU
argument_list|,
name|StringRef
name|Features
argument_list|,
specifier|const
name|TargetOptions
operator|&
name|Options
argument_list|,
name|Reloc
operator|::
name|Model
name|RM
operator|=
name|Reloc
operator|::
name|Default
argument_list|,
name|CodeModel
operator|::
name|Model
name|CM
operator|=
name|CodeModel
operator|::
name|Default
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OL
operator|=
name|CodeGenOpt
operator|::
name|Default
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|TargetMachineCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|TargetMachineCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|Triple
argument_list|,
name|CPU
argument_list|,
name|Features
argument_list|,
name|Options
argument_list|,
name|RM
argument_list|,
name|CM
argument_list|,
name|OL
argument_list|)
return|;
block|}
comment|/// createMCAsmBackend - Create a target specific assembly parser.
comment|///
comment|/// \param Triple The target triple string.
name|MCAsmBackend
modifier|*
name|createMCAsmBackend
argument_list|(
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|,
name|StringRef
name|Triple
argument_list|,
name|StringRef
name|CPU
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCAsmBackendCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCAsmBackendCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|MRI
argument_list|,
name|Triple
argument_list|,
name|CPU
argument_list|)
return|;
block|}
comment|/// createMCAsmParser - Create a target specific assembly parser.
comment|///
comment|/// \param Parser The target independent parser implementation to use for
comment|/// parsing and lexing.
name|MCTargetAsmParser
modifier|*
name|createMCAsmParser
argument_list|(
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCAsmParser
operator|&
name|Parser
argument_list|,
specifier|const
name|MCInstrInfo
operator|&
name|MII
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCAsmParserCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCAsmParserCtorFn
argument_list|(
name|STI
argument_list|,
name|Parser
argument_list|,
name|MII
argument_list|)
return|;
block|}
comment|/// createAsmPrinter - Create a target specific assembly printer pass.  This
comment|/// takes ownership of the MCStreamer object.
name|AsmPrinter
modifier|*
name|createAsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|AsmPrinterCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|AsmPrinterCtorFn
argument_list|(
name|TM
argument_list|,
name|Streamer
argument_list|)
return|;
block|}
name|MCDisassembler
modifier|*
name|createMCDisassembler
argument_list|(
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCDisassemblerCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCDisassemblerCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|STI
argument_list|)
return|;
block|}
name|MCInstPrinter
modifier|*
name|createMCInstPrinter
argument_list|(
name|unsigned
name|SyntaxVariant
argument_list|,
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
specifier|const
name|MCInstrInfo
operator|&
name|MII
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCInstPrinterCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCInstPrinterCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|SyntaxVariant
argument_list|,
name|MAI
argument_list|,
name|MII
argument_list|,
name|MRI
argument_list|,
name|STI
argument_list|)
return|;
block|}
comment|/// createMCCodeEmitter - Create a target specific code emitter.
name|MCCodeEmitter
modifier|*
name|createMCCodeEmitter
argument_list|(
specifier|const
name|MCInstrInfo
operator|&
name|II
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCCodeEmitterCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCCodeEmitterCtorFn
argument_list|(
name|II
argument_list|,
name|MRI
argument_list|,
name|STI
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
comment|/// createMCObjectStreamer - Create a target specific MCStreamer.
comment|///
comment|/// \param TT The target triple.
comment|/// \param Ctx The target context.
comment|/// \param TAB The target assembler backend object. Takes ownership.
comment|/// \param _OS The stream object.
comment|/// \param _Emitter The target independent assembler object.Takes ownership.
comment|/// \param RelaxAll Relax all fixups?
comment|/// \param NoExecStack Mark file as not needing a executable stack.
name|MCStreamer
modifier|*
name|createMCObjectStreamer
argument_list|(
name|StringRef
name|TT
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|,
name|MCAsmBackend
operator|&
name|TAB
argument_list|,
name|raw_ostream
operator|&
name|_OS
argument_list|,
name|MCCodeEmitter
operator|*
name|_Emitter
argument_list|,
name|bool
name|RelaxAll
argument_list|,
name|bool
name|NoExecStack
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MCObjectStreamerCtorFn
condition|)
return|return
literal|0
return|;
return|return
name|MCObjectStreamerCtorFn
argument_list|(
operator|*
name|this
argument_list|,
name|TT
argument_list|,
name|Ctx
argument_list|,
name|TAB
argument_list|,
name|_OS
argument_list|,
name|_Emitter
argument_list|,
name|RelaxAll
argument_list|,
name|NoExecStack
argument_list|)
return|;
block|}
comment|/// createAsmStreamer - Create a target specific MCStreamer.
name|MCStreamer
modifier|*
name|createAsmStreamer
argument_list|(
name|MCContext
operator|&
name|Ctx
argument_list|,
name|formatted_raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|isVerboseAsm
argument_list|,
name|bool
name|useLoc
argument_list|,
name|bool
name|useCFI
argument_list|,
name|bool
name|useDwarfDirectory
argument_list|,
name|MCInstPrinter
operator|*
name|InstPrint
argument_list|,
name|MCCodeEmitter
operator|*
name|CE
argument_list|,
name|MCAsmBackend
operator|*
name|TAB
argument_list|,
name|bool
name|ShowInst
argument_list|)
decl|const
block|{
if|if
condition|(
name|AsmStreamerCtorFn
condition|)
return|return
name|AsmStreamerCtorFn
argument_list|(
name|Ctx
argument_list|,
name|OS
argument_list|,
name|isVerboseAsm
argument_list|,
name|useLoc
argument_list|,
name|useCFI
argument_list|,
name|useDwarfDirectory
argument_list|,
name|InstPrint
argument_list|,
name|CE
argument_list|,
name|TAB
argument_list|,
name|ShowInst
argument_list|)
return|;
return|return
name|llvm
operator|::
name|createAsmStreamer
argument_list|(
name|Ctx
argument_list|,
literal|0
argument_list|,
name|OS
argument_list|,
name|isVerboseAsm
argument_list|,
name|useLoc
argument_list|,
name|useCFI
argument_list|,
name|useDwarfDirectory
argument_list|,
name|InstPrint
argument_list|,
name|CE
argument_list|,
name|TAB
argument_list|,
name|ShowInst
argument_list|)
return|;
block|}
comment|/// createMCRelocationInfo - Create a target specific MCRelocationInfo.
comment|///
comment|/// \param TT The target triple.
comment|/// \param Ctx The target context.
name|MCRelocationInfo
modifier|*
name|createMCRelocationInfo
argument_list|(
name|StringRef
name|TT
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
decl|const
block|{
name|MCRelocationInfoCtorTy
name|Fn
init|=
name|MCRelocationInfoCtorFn
condition|?
name|MCRelocationInfoCtorFn
else|:
name|llvm
operator|::
name|createMCRelocationInfo
decl_stmt|;
return|return
name|Fn
argument_list|(
name|TT
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
comment|/// createMCSymbolizer - Create a target specific MCSymbolizer.
comment|///
comment|/// \param TT The target triple.
comment|/// \param GetOpInfo The function to get the symbolic information for operands.
comment|/// \param SymbolLookUp The function to lookup a symbol name.
comment|/// \param DisInfo The pointer to the block of symbolic information for above call
comment|/// back.
comment|/// \param Ctx The target context.
comment|/// \param RelInfo The relocation information for this target. Takes ownership.
name|MCSymbolizer
modifier|*
name|createMCSymbolizer
argument_list|(
name|StringRef
name|TT
argument_list|,
name|LLVMOpInfoCallback
name|GetOpInfo
argument_list|,
name|LLVMSymbolLookupCallback
name|SymbolLookUp
argument_list|,
name|void
operator|*
name|DisInfo
argument_list|,
name|MCContext
operator|*
name|Ctx
argument_list|,
name|MCRelocationInfo
operator|*
name|RelInfo
argument_list|)
decl|const
block|{
name|MCSymbolizerCtorTy
name|Fn
init|=
name|MCSymbolizerCtorFn
condition|?
name|MCSymbolizerCtorFn
else|:
name|llvm
operator|::
name|createMCSymbolizer
decl_stmt|;
return|return
name|Fn
argument_list|(
name|TT
argument_list|,
name|GetOpInfo
argument_list|,
name|SymbolLookUp
argument_list|,
name|DisInfo
argument_list|,
name|Ctx
argument_list|,
name|RelInfo
argument_list|)
return|;
block|}
comment|/// @}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// TargetRegistry - Generic interface to target specific features.
end_comment

begin_struct
struct|struct
name|TargetRegistry
block|{
name|class
name|iterator
block|{
specifier|const
name|Target
modifier|*
name|Current
decl_stmt|;
name|explicit
name|iterator
argument_list|(
name|Target
operator|*
name|T
argument_list|)
operator|:
name|Current
argument_list|(
argument|T
argument_list|)
block|{}
name|friend
expr|struct
name|TargetRegistry
expr_stmt|;
name|public
label|:
name|iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|I
argument_list|)
operator|:
name|Current
argument_list|(
argument|I.Current
argument_list|)
block|{}
name|iterator
argument_list|()
operator|:
name|Current
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|Current
operator|==
name|x
operator|.
name|Current
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
comment|// Iterator traversal: forward iteration only
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
name|Current
operator|&&
literal|"Cannot increment end iterator!"
argument_list|)
block|;
name|Current
operator|=
name|Current
operator|->
name|getNext
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
specifier|const
name|Target
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Current
operator|&&
literal|"Cannot dereference end iterator!"
argument_list|)
block|;
return|return
operator|*
name|Current
return|;
block|}
specifier|const
name|Target
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// printRegisteredTargetsForVersion - Print the registered targets
end_comment

begin_comment
comment|/// appropriately for inclusion in a tool's version output.
end_comment

begin_function_decl
specifier|static
name|void
name|printRegisteredTargetsForVersion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// @name Registry Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_function_decl
specifier|static
name|iterator
name|begin
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// lookupTarget - Lookup a target based on a target triple.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Triple - The triple to use for finding a target.
end_comment

begin_comment
comment|/// \param Error - On failure, an error string describing why no target was
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Target
modifier|*
name|lookupTarget
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Triple
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// lookupTarget - Lookup a target based on an architecture name
end_comment

begin_comment
comment|/// and a target triple.  If the architecture name is non-empty,
end_comment

begin_comment
comment|/// then the lookup is done by architecture.  Otherwise, the target
end_comment

begin_comment
comment|/// triple is used.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ArchName - The architecture to use for finding a target.
end_comment

begin_comment
comment|/// \param TheTriple - The triple to use for finding a target.  The
end_comment

begin_comment
comment|/// triple is updated with canonical architecture name if a lookup
end_comment

begin_comment
comment|/// by architecture is done.
end_comment

begin_comment
comment|/// \param Error - On failure, an error string describing why no target was
end_comment

begin_comment
comment|/// found.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Target
modifier|*
name|lookupTarget
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ArchName
argument_list|,
name|Triple
operator|&
name|TheTriple
argument_list|,
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getClosestTargetForJIT - Pick the best target that is compatible with
end_comment

begin_comment
comment|/// the current host.  If no close target can be found, this returns null
end_comment

begin_comment
comment|/// and sets the Error string to a reason.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maintained for compatibility through 2.6.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|Target
modifier|*
name|getClosestTargetForJIT
argument_list|(
name|std
operator|::
name|string
operator|&
name|Error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Target Registration
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// RegisterTarget - Register the given target. Attempts to register a
end_comment

begin_comment
comment|/// target which has already been registered will be ignored.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Name - The target name. This should be a static string.
end_comment

begin_comment
comment|/// @param ShortDesc - A short target description. This should be a static
end_comment

begin_comment
comment|/// string.
end_comment

begin_comment
comment|/// @param TQualityFn - The triple match quality computation function for
end_comment

begin_comment
comment|/// this target.
end_comment

begin_comment
comment|/// @param HasJIT - Whether the target supports JIT code
end_comment

begin_comment
comment|/// generation.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterTarget
argument_list|(
name|Target
operator|&
name|T
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|ShortDesc
argument_list|,
name|Target
operator|::
name|TripleMatchQualityFnTy
name|TQualityFn
argument_list|,
name|bool
name|HasJIT
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// RegisterMCAsmInfo - Register a MCAsmInfo implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a MCAsmInfo for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCAsmInfo
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCAsmInfoCtorFnTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCAsmInfoCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCCodeGenInfo - Register a MCCodeGenInfo implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a MCCodeGenInfo for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCCodeGenInfo
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCCodeGenInfoCtorFnTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCCodeGenInfoCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCInstrInfo - Register a MCInstrInfo implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a MCInstrInfo for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCInstrInfo
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCInstrInfoCtorFnTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCInstrInfoCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCInstrAnalysis - Register a MCInstrAnalysis implementation for
end_comment

begin_comment
comment|/// the given target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCInstrAnalysis
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCInstrAnalysisCtorFnTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCInstrAnalysisCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCRegInfo - Register a MCRegisterInfo implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a MCRegisterInfo for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCRegInfo
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCRegInfoCtorFnTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCRegInfoCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCSubtargetInfo - Register a MCSubtargetInfo implementation for
end_comment

begin_comment
comment|/// the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a MCSubtargetInfo for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCSubtargetInfo
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCSubtargetInfoCtorFnTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCSubtargetInfoCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterTargetMachine - Register a TargetMachine implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct a TargetMachine for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterTargetMachine
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|TargetMachineCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|TargetMachineCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCAsmBackend - Register a MCAsmBackend implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an AsmBackend for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCAsmBackend
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCAsmBackendCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCAsmBackendCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCAsmParser - Register a MCTargetAsmParser implementation for
end_comment

begin_comment
comment|/// the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCTargetAsmParser for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCAsmParser
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCAsmParserCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCAsmParserCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterAsmPrinter - Register an AsmPrinter implementation for the given
end_comment

begin_comment
comment|/// target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an AsmPrinter for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterAsmPrinter
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|AsmPrinterCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|AsmPrinterCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCDisassembler - Register a MCDisassembler implementation for
end_comment

begin_comment
comment|/// the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCDisassembler for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCDisassembler
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCDisassemblerCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCDisassemblerCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCInstPrinter - Register a MCInstPrinter implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCInstPrinter for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCInstPrinter
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCInstPrinterCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCInstPrinterCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCCodeEmitter - Register a MCCodeEmitter implementation for the
end_comment

begin_comment
comment|/// given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCCodeEmitter for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCCodeEmitter
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCCodeEmitterCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCCodeEmitterCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCObjectStreamer - Register a object code MCStreamer
end_comment

begin_comment
comment|/// implementation for the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCStreamer for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCObjectStreamer
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCObjectStreamerCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCObjectStreamerCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterAsmStreamer - Register an assembly MCStreamer implementation
end_comment

begin_comment
comment|/// for the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCStreamer for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterAsmStreamer
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|AsmStreamerCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|AsmStreamerCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCRelocationInfo - Register an MCRelocationInfo
end_comment

begin_comment
comment|/// implementation for the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCRelocationInfo for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCRelocationInfo
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCRelocationInfoCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCRelocationInfoCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RegisterMCSymbolizer - Register an MCSymbolizer
end_comment

begin_comment
comment|/// implementation for the given target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Clients are responsible for ensuring that registration doesn't occur
end_comment

begin_comment
comment|/// while another thread is attempting to access the registry. Typically
end_comment

begin_comment
comment|/// this is done by initializing all targets at program startup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param T - The target being registered.
end_comment

begin_comment
comment|/// @param Fn - A function to construct an MCSymbolizer for the target.
end_comment

begin_decl_stmt
specifier|static
name|void
name|RegisterMCSymbolizer
argument_list|(
name|Target
operator|&
name|T
argument_list|,
name|Target
operator|::
name|MCSymbolizerCtorTy
name|Fn
argument_list|)
block|{
name|T
operator|.
name|MCSymbolizerCtorFn
operator|=
name|Fn
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// RegisterTarget - Helper template for registering a target, for use in the
end_comment

begin_comment
comment|/// target's initialization function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Target TheFooTarget; // The global target instance.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTargetInfo() {
end_comment

begin_comment
comment|///   RegisterTarget<Triple::foo> X(TheFooTarget, "foo", "Foo description");
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|Triple
operator|::
name|ArchType
name|TargetArchType
operator|=
name|Triple
operator|::
name|UnknownArch
operator|,
name|bool
name|HasJIT
operator|=
name|false
operator|>
expr|struct
name|RegisterTarget
block|{
name|RegisterTarget
argument_list|(
argument|Target&T
argument_list|,
argument|const char *Name
argument_list|,
argument|const char *Desc
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterTarget
argument_list|(
name|T
argument_list|,
name|Name
argument_list|,
name|Desc
argument_list|,
operator|&
name|getTripleMatchQuality
argument_list|,
name|HasJIT
argument_list|)
block|;     }
specifier|static
name|unsigned
name|getTripleMatchQuality
argument_list|(
argument|const std::string&TT
argument_list|)
block|{
if|if
condition|(
name|Triple
argument_list|(
name|TT
argument_list|)
operator|.
name|getArch
argument_list|()
operator|==
name|TargetArchType
condition|)
return|return
literal|20
return|;
return|return
literal|0
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCAsmInfo - Helper template for registering a target assembly info
end_comment

begin_comment
comment|/// implementation.  This invokes the static "Create" method on the class to
end_comment

begin_comment
comment|/// actually do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCAsmInfo<FooMCAsmInfo> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCAsmInfoImpl
operator|>
expr|struct
name|RegisterMCAsmInfo
block|{
name|RegisterMCAsmInfo
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCAsmInfo
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCAsmInfo
operator|*
name|Allocator
argument_list|(
argument|const MCRegisterInfo&
comment|/*MRI*/
argument_list|,
argument|StringRef TT
argument_list|)
block|{
return|return
name|new
name|MCAsmInfoImpl
argument_list|(
name|TT
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCAsmInfoFn - Helper template for registering a target assembly info
end_comment

begin_comment
comment|/// implementation.  This invokes the specified function to do the
end_comment

begin_comment
comment|/// construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCAsmInfoFn X(TheFooTarget, TheFunction);
end_comment

begin_comment
comment|/// }
end_comment

begin_struct
struct|struct
name|RegisterMCAsmInfoFn
block|{
name|RegisterMCAsmInfoFn
argument_list|(
argument|Target&T
argument_list|,
argument|Target::MCAsmInfoCtorFnTy Fn
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCAsmInfo
argument_list|(
name|T
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// RegisterMCCodeGenInfo - Helper template for registering a target codegen info
end_comment

begin_comment
comment|/// implementation.  This invokes the static "Create" method on the class
end_comment

begin_comment
comment|/// to actually do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCCodeGenInfo<FooMCCodeGenInfo> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCCodeGenInfoImpl
operator|>
expr|struct
name|RegisterMCCodeGenInfo
block|{
name|RegisterMCCodeGenInfo
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCCodeGenInfo
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCCodeGenInfo
operator|*
name|Allocator
argument_list|(
argument|StringRef
comment|/*TT*/
argument_list|,
argument|Reloc::Model
comment|/*RM*/
argument_list|,
argument|CodeModel::Model
comment|/*CM*/
argument_list|,
argument|CodeGenOpt::Level
comment|/*OL*/
argument_list|)
block|{
return|return
name|new
name|MCCodeGenInfoImpl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCCodeGenInfoFn - Helper template for registering a target codegen
end_comment

begin_comment
comment|/// info implementation.  This invokes the specified function to do the
end_comment

begin_comment
comment|/// construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCCodeGenInfoFn X(TheFooTarget, TheFunction);
end_comment

begin_comment
comment|/// }
end_comment

begin_struct
struct|struct
name|RegisterMCCodeGenInfoFn
block|{
name|RegisterMCCodeGenInfoFn
argument_list|(
argument|Target&T
argument_list|,
argument|Target::MCCodeGenInfoCtorFnTy Fn
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCCodeGenInfo
argument_list|(
name|T
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// RegisterMCInstrInfo - Helper template for registering a target instruction
end_comment

begin_comment
comment|/// info implementation.  This invokes the static "Create" method on the class
end_comment

begin_comment
comment|/// to actually do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCInstrInfo<FooMCInstrInfo> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCInstrInfoImpl
operator|>
expr|struct
name|RegisterMCInstrInfo
block|{
name|RegisterMCInstrInfo
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCInstrInfo
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCInstrInfo
operator|*
name|Allocator
argument_list|()
block|{
return|return
name|new
name|MCInstrInfoImpl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCInstrInfoFn - Helper template for registering a target
end_comment

begin_comment
comment|/// instruction info implementation.  This invokes the specified function to
end_comment

begin_comment
comment|/// do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCInstrInfoFn X(TheFooTarget, TheFunction);
end_comment

begin_comment
comment|/// }
end_comment

begin_struct
struct|struct
name|RegisterMCInstrInfoFn
block|{
name|RegisterMCInstrInfoFn
argument_list|(
argument|Target&T
argument_list|,
argument|Target::MCInstrInfoCtorFnTy Fn
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCInstrInfo
argument_list|(
name|T
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// RegisterMCInstrAnalysis - Helper template for registering a target
end_comment

begin_comment
comment|/// instruction analyzer implementation.  This invokes the static "Create"
end_comment

begin_comment
comment|/// method on the class to actually do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCInstrAnalysis<FooMCInstrAnalysis> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCInstrAnalysisImpl
operator|>
expr|struct
name|RegisterMCInstrAnalysis
block|{
name|RegisterMCInstrAnalysis
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCInstrAnalysis
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCInstrAnalysis
operator|*
name|Allocator
argument_list|(
argument|const MCInstrInfo *Info
argument_list|)
block|{
return|return
name|new
name|MCInstrAnalysisImpl
argument_list|(
name|Info
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCInstrAnalysisFn - Helper template for registering a target
end_comment

begin_comment
comment|/// instruction analyzer implementation.  This invokes the specified function
end_comment

begin_comment
comment|/// to do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCInstrAnalysisFn X(TheFooTarget, TheFunction);
end_comment

begin_comment
comment|/// }
end_comment

begin_struct
struct|struct
name|RegisterMCInstrAnalysisFn
block|{
name|RegisterMCInstrAnalysisFn
argument_list|(
argument|Target&T
argument_list|,
argument|Target::MCInstrAnalysisCtorFnTy Fn
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCInstrAnalysis
argument_list|(
name|T
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// RegisterMCRegInfo - Helper template for registering a target register info
end_comment

begin_comment
comment|/// implementation.  This invokes the static "Create" method on the class to
end_comment

begin_comment
comment|/// actually do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCRegInfo<FooMCRegInfo> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCRegisterInfoImpl
operator|>
expr|struct
name|RegisterMCRegInfo
block|{
name|RegisterMCRegInfo
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCRegInfo
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCRegisterInfo
operator|*
name|Allocator
argument_list|(
argument|StringRef
comment|/*TT*/
argument_list|)
block|{
return|return
name|new
name|MCRegisterInfoImpl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCRegInfoFn - Helper template for registering a target register
end_comment

begin_comment
comment|/// info implementation.  This invokes the specified function to do the
end_comment

begin_comment
comment|/// construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCRegInfoFn X(TheFooTarget, TheFunction);
end_comment

begin_comment
comment|/// }
end_comment

begin_struct
struct|struct
name|RegisterMCRegInfoFn
block|{
name|RegisterMCRegInfoFn
argument_list|(
argument|Target&T
argument_list|,
argument|Target::MCRegInfoCtorFnTy Fn
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCRegInfo
argument_list|(
name|T
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// RegisterMCSubtargetInfo - Helper template for registering a target
end_comment

begin_comment
comment|/// subtarget info implementation.  This invokes the static "Create" method
end_comment

begin_comment
comment|/// on the class to actually do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCSubtargetInfo<FooMCSubtargetInfo> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCSubtargetInfoImpl
operator|>
expr|struct
name|RegisterMCSubtargetInfo
block|{
name|RegisterMCSubtargetInfo
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCSubtargetInfo
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCSubtargetInfo
operator|*
name|Allocator
argument_list|(
argument|StringRef
comment|/*TT*/
argument_list|,
argument|StringRef
comment|/*CPU*/
argument_list|,
argument|StringRef
comment|/*FS*/
argument_list|)
block|{
return|return
name|new
name|MCSubtargetInfoImpl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCSubtargetInfoFn - Helper template for registering a target
end_comment

begin_comment
comment|/// subtarget info implementation.  This invokes the specified function to
end_comment

begin_comment
comment|/// do the construction.  Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCSubtargetInfoFn X(TheFooTarget, TheFunction);
end_comment

begin_comment
comment|/// }
end_comment

begin_struct
struct|struct
name|RegisterMCSubtargetInfoFn
block|{
name|RegisterMCSubtargetInfoFn
argument_list|(
argument|Target&T
argument_list|,
argument|Target::MCSubtargetInfoCtorFnTy Fn
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCSubtargetInfo
argument_list|(
name|T
argument_list|,
name|Fn
argument_list|)
expr_stmt|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// RegisterTargetMachine - Helper template for registering a target machine
end_comment

begin_comment
comment|/// implementation, for use in the target machine initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooTarget() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterTargetMachine<FooTargetMachine> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TargetMachineImpl
operator|>
expr|struct
name|RegisterTargetMachine
block|{
name|RegisterTargetMachine
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterTargetMachine
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|TargetMachine
operator|*
name|Allocator
argument_list|(
argument|const Target&T
argument_list|,
argument|StringRef TT
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
block|{
return|return
name|new
name|TargetMachineImpl
argument_list|(
name|T
argument_list|,
name|TT
argument_list|,
name|CPU
argument_list|,
name|FS
argument_list|,
name|Options
argument_list|,
name|RM
argument_list|,
name|CM
argument_list|,
name|OL
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCAsmBackend - Helper template for registering a target specific
end_comment

begin_comment
comment|/// assembler backend. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooMCAsmBackend() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCAsmBackend<FooAsmLexer> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCAsmBackendImpl
operator|>
expr|struct
name|RegisterMCAsmBackend
block|{
name|RegisterMCAsmBackend
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCAsmBackend
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCAsmBackend
operator|*
name|Allocator
argument_list|(
argument|const Target&T
argument_list|,
argument|const MCRegisterInfo&MRI
argument_list|,
argument|StringRef Triple
argument_list|,
argument|StringRef CPU
argument_list|)
block|{
return|return
name|new
name|MCAsmBackendImpl
argument_list|(
name|T
argument_list|,
name|MRI
argument_list|,
name|Triple
argument_list|,
name|CPU
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCAsmParser - Helper template for registering a target specific
end_comment

begin_comment
comment|/// assembly parser, for use in the target machine initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooMCAsmParser() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCAsmParser<FooAsmParser> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCAsmParserImpl
operator|>
expr|struct
name|RegisterMCAsmParser
block|{
name|RegisterMCAsmParser
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCAsmParser
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCTargetAsmParser
operator|*
name|Allocator
argument_list|(
argument|MCSubtargetInfo&STI
argument_list|,
argument|MCAsmParser&P
argument_list|,
argument|const MCInstrInfo&MII
argument_list|)
block|{
return|return
name|new
name|MCAsmParserImpl
argument_list|(
name|STI
argument_list|,
name|P
argument_list|,
name|MII
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterAsmPrinter - Helper template for registering a target specific
end_comment

begin_comment
comment|/// assembly printer, for use in the target machine initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooAsmPrinter() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterAsmPrinter<FooAsmPrinter> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|AsmPrinterImpl
operator|>
expr|struct
name|RegisterAsmPrinter
block|{
name|RegisterAsmPrinter
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterAsmPrinter
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|AsmPrinter
operator|*
name|Allocator
argument_list|(
argument|TargetMachine&TM
argument_list|,
argument|MCStreamer&Streamer
argument_list|)
block|{
return|return
name|new
name|AsmPrinterImpl
argument_list|(
name|TM
argument_list|,
name|Streamer
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// RegisterMCCodeEmitter - Helper template for registering a target specific
end_comment

begin_comment
comment|/// machine code emitter, for use in the target initialization
end_comment

begin_comment
comment|/// function. Usage:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// extern "C" void LLVMInitializeFooMCCodeEmitter() {
end_comment

begin_comment
comment|///   extern Target TheFooTarget;
end_comment

begin_comment
comment|///   RegisterMCCodeEmitter<FooCodeEmitter> X(TheFooTarget);
end_comment

begin_comment
comment|/// }
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|MCCodeEmitterImpl
operator|>
expr|struct
name|RegisterMCCodeEmitter
block|{
name|RegisterMCCodeEmitter
argument_list|(
argument|Target&T
argument_list|)
block|{
name|TargetRegistry
operator|::
name|RegisterMCCodeEmitter
argument_list|(
name|T
argument_list|,
operator|&
name|Allocator
argument_list|)
block|;     }
name|private
operator|:
specifier|static
name|MCCodeEmitter
operator|*
name|Allocator
argument_list|(
argument|const MCInstrInfo&
comment|/*II*/
argument_list|,
argument|const MCRegisterInfo&
comment|/*MRI*/
argument_list|,
argument|const MCSubtargetInfo&
comment|/*STI*/
argument_list|,
argument|MCContext&
comment|/*Ctx*/
argument_list|)
block|{
return|return
name|new
name|MCCodeEmitterImpl
argument_list|()
return|;
block|}
end_expr_stmt

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

end_unit

