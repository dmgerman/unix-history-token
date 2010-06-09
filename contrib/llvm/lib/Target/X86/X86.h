begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- X86.h - Top-level interface for X86 representation ------*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the x86
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
name|TARGET_X86_H
end_ifndef

begin_define
define|#
directive|define
name|TARGET_X86_H
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
name|FunctionPass
decl_stmt|;
name|class
name|JITCodeEmitter
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|TargetAsmBackend
decl_stmt|;
name|class
name|X86TargetMachine
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
comment|/// createX86ISelDag - This pass converts a legalized DAG into a
comment|/// X86-specific DAG, ready for instruction scheduling.
comment|///
name|FunctionPass
modifier|*
name|createX86ISelDag
argument_list|(
name|X86TargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
comment|/// createX86FloatingPointStackifierPass - This function returns a pass which
comment|/// converts floating point register references and pseudo instructions into
comment|/// floating point stack references and physical instructions.
comment|///
name|FunctionPass
modifier|*
name|createX86FloatingPointStackifierPass
parameter_list|()
function_decl|;
comment|/// createSSEDomainFixPass - This pass twiddles SSE opcodes to prevent domain
comment|/// crossings.
name|FunctionPass
modifier|*
name|createSSEDomainFixPass
parameter_list|()
function_decl|;
comment|/// createX87FPRegKillInserterPass - This function returns a pass which
comment|/// inserts FP_REG_KILL instructions where needed.
comment|///
name|FunctionPass
modifier|*
name|createX87FPRegKillInserterPass
parameter_list|()
function_decl|;
comment|/// createX86CodeEmitterPass - Return a pass that emits the collected X86 code
comment|/// to the specified MCE object.
name|FunctionPass
modifier|*
name|createX86JITCodeEmitterPass
parameter_list|(
name|X86TargetMachine
modifier|&
name|TM
parameter_list|,
name|JITCodeEmitter
modifier|&
name|JCE
parameter_list|)
function_decl|;
name|MCCodeEmitter
modifier|*
name|createX86_32MCCodeEmitter
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
name|MCCodeEmitter
modifier|*
name|createX86_64MCCodeEmitter
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
name|createX86_32AsmBackend
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
name|TargetAsmBackend
modifier|*
name|createX86_64AsmBackend
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
comment|/// createX86EmitCodeToMemory - Returns a pass that converts a register
comment|/// allocated function into raw machine code in a dynamically
comment|/// allocated chunk of memory.
comment|///
name|FunctionPass
modifier|*
name|createEmitX86CodeToMemory
parameter_list|()
function_decl|;
comment|/// createX86MaxStackAlignmentHeuristicPass - This function returns a pass
comment|/// which determines whether the frame pointer register should be
comment|/// reserved in case dynamic stack alignment is later required.
comment|///
name|FunctionPass
modifier|*
name|createX86MaxStackAlignmentHeuristicPass
parameter_list|()
function_decl|;
specifier|extern
name|Target
name|TheX86_32Target
decl_stmt|,
name|TheX86_64Target
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_comment
comment|// Defines symbolic names for X86 registers.  This defines a mapping from
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
file|"X86GenRegisterNames.inc"
end_include

begin_comment
comment|// Defines symbolic names for the X86 instructions.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|"X86GenInstrNames.inc"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

