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
file|"MCTargetDesc/X86MCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

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
name|MachineCodeEmitter
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSubtargetInfo
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
name|class
name|raw_ostream
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
comment|/// createGlobalBaseRegPass - This pass initializes a global base
comment|/// register for PIC on x86-32.
name|FunctionPass
modifier|*
name|createGlobalBaseRegPass
parameter_list|()
function_decl|;
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
name|createX86MCCodeEmitter
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|MCII
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
comment|/// createX86MachObjectWriter - Construct an X86 Mach-O object writer.
name|MCObjectWriter
modifier|*
name|createX86MachObjectWriter
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
parameter_list|,
name|uint32_t
name|CPUType
parameter_list|,
name|uint32_t
name|CPUSubtype
parameter_list|)
function_decl|;
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

