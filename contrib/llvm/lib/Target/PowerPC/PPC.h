begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPC.h - Top-level interface for PowerPC Target ----------*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// PowerPC back-end.
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
name|LLVM_TARGET_POWERPC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_POWERPC_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// GCC #defines PPC on Linux but we use it as our namespace name
end_comment

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|class
name|JITCodeEmitter
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetAsmBackend
decl_stmt|;
name|FunctionPass
modifier|*
name|createPPCBranchSelectionPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCISelDag
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createPPCJITCodeEmitterPass
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|,
name|JITCodeEmitter
modifier|&
name|MCE
parameter_list|)
function_decl|;
name|MCCodeEmitter
modifier|*
name|createPPCMCCodeEmitter
parameter_list|(
specifier|const
name|Target
modifier|&
parameter_list|,
name|TargetMachine
modifier|&
name|TM
parameter_list|,
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|TargetAsmBackend
modifier|*
name|createPPCAsmBackend
argument_list|(
specifier|const
name|Target
operator|&
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
decl_stmt|;
name|void
name|LowerPPCMachineInstrToMCInst
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|MCInst
modifier|&
name|OutMI
parameter_list|,
name|AsmPrinter
modifier|&
name|AP
parameter_list|)
function_decl|;
specifier|extern
name|Target
name|ThePPC32Target
decl_stmt|;
specifier|extern
name|Target
name|ThePPC64Target
decl_stmt|;
name|namespace
name|PPCII
block|{
comment|/// Target Operand Flag enum.
enum|enum
name|TOF
block|{
comment|//===------------------------------------------------------------------===//
comment|// PPC Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
comment|/// MO_DARWIN_STUB - On a symbol operand "FOO", this indicates that the
comment|/// reference is actually to the "FOO$stub" symbol.  This is used for calls
comment|/// and jumps to external functions on Tiger and earlier.
name|MO_DARWIN_STUB
init|=
literal|1
block|,
comment|/// MO_LO16, MO_HA16 - lo16(symbol) and ha16(symbol)
name|MO_LO16
init|=
literal|4
block|,
name|MO_HA16
init|=
literal|8
block|,
comment|/// MO_PIC_FLAG - If this bit is set, the symbol reference is relative to
comment|/// the function's picbase, e.g. lo16(symbol-picbase).
name|MO_PIC_FLAG
init|=
literal|16
block|,
comment|/// MO_NLP_FLAG - If this bit is set, the symbol reference is actually to
comment|/// the non_lazy_ptr for the global, e.g. lo16(symbol$non_lazy_ptr-picbase).
name|MO_NLP_FLAG
init|=
literal|32
block|,
comment|/// MO_NLP_HIDDEN_FLAG - If this bit is set, the symbol reference is to a
comment|/// symbol with hidden visibility.  This causes a different kind of
comment|/// non-lazy-pointer to be generated.
name|MO_NLP_HIDDEN_FLAG
init|=
literal|64
block|}
enum|;
block|}
comment|// end namespace PPCII
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_comment
comment|// Defines symbolic names for PowerPC registers.  This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"PPCGenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the PowerPC instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"PPCGenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

