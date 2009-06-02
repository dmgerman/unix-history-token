begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IA64.h - Top-level interface for IA64 representation ------*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the IA64
end_comment

begin_comment
comment|// target library, as used by the LLVM JIT.
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
name|TARGET_IA64_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_IA64_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IA64TargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// createIA64DAGToDAGInstructionSelector - This pass converts an LLVM
comment|/// function into IA64 machine code in a sane, DAG->DAG transform.
comment|///
name|FunctionPass
modifier|*
name|createIA64DAGToDAGInstructionSelector
parameter_list|(
name|IA64TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|/// createIA64BundlingPass - This pass adds stop bits and bundles
comment|/// instructions.
comment|///
name|FunctionPass
modifier|*
name|createIA64BundlingPass
parameter_list|(
name|IA64TargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
comment|/// createIA64CodePrinterPass - Returns a pass that prints the IA64
comment|/// assembly code for a MachineFunction to the given output stream,
comment|/// using the given target machine description.  This should work
comment|/// regardless of whether the function is in SSA form.
comment|///
name|FunctionPass
modifier|*
name|createIA64CodePrinterPass
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
name|IA64TargetMachine
operator|&
name|tm
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|,
name|bool
name|verbose
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Defines symbolic names for IA64 registers.  This defines a mapping from
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
file|"IA64GenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the IA64 instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"IA64GenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

