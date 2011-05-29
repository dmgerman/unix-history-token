begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ JITDwarfEmitter.h - Write dwarf tables into memory ------------===//
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
comment|// This file defines a JITDwarfEmitter object that is used by the JIT to
end_comment

begin_comment
comment|// write dwarf tables to memory.
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
name|LLVM_EXECUTION_ENGINE_JIT_DWARFEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTION_ENGINE_JIT_DWARFEMITTER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|JITCodeEmitter
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineMove
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|TargetFrameLowering
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|JITDwarfEmitter
block|{
specifier|const
name|TargetData
modifier|*
name|TD
decl_stmt|;
name|JITCodeEmitter
modifier|*
name|JCE
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|*
name|RI
decl_stmt|;
specifier|const
name|TargetFrameLowering
modifier|*
name|TFI
decl_stmt|;
name|MachineModuleInfo
modifier|*
name|MMI
decl_stmt|;
name|JIT
modifier|&
name|Jit
decl_stmt|;
name|bool
name|stackGrowthDirection
decl_stmt|;
name|unsigned
name|char
modifier|*
name|EmitExceptionTable
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|,
name|unsigned
name|char
operator|*
name|StartFunction
argument_list|,
name|unsigned
name|char
operator|*
name|EndFunction
argument_list|)
decl|const
decl_stmt|;
name|void
name|EmitFrameMoves
argument_list|(
name|intptr_t
name|BaseLabelPtr
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineMove
operator|>
operator|&
name|Moves
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|char
modifier|*
name|EmitCommonEHFrame
argument_list|(
specifier|const
name|Function
operator|*
name|Personality
argument_list|)
decl|const
decl_stmt|;
name|unsigned
name|char
modifier|*
name|EmitEHFrame
argument_list|(
specifier|const
name|Function
operator|*
name|Personality
argument_list|,
name|unsigned
name|char
operator|*
name|StartBufferPtr
argument_list|,
name|unsigned
name|char
operator|*
name|StartFunction
argument_list|,
name|unsigned
name|char
operator|*
name|EndFunction
argument_list|,
name|unsigned
name|char
operator|*
name|ExceptionTable
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|JITDwarfEmitter
argument_list|(
name|JIT
operator|&
name|jit
argument_list|)
expr_stmt|;
name|unsigned
name|char
modifier|*
name|EmitDwarfTable
parameter_list|(
name|MachineFunction
modifier|&
name|F
parameter_list|,
name|JITCodeEmitter
modifier|&
name|JCE
parameter_list|,
name|unsigned
name|char
modifier|*
name|StartFunction
parameter_list|,
name|unsigned
name|char
modifier|*
name|EndFunction
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|&
name|EHFramePtr
parameter_list|)
function_decl|;
name|void
name|setModuleInfo
parameter_list|(
name|MachineModuleInfo
modifier|*
name|Info
parameter_list|)
block|{
name|MMI
operator|=
name|Info
expr_stmt|;
block|}
block|}
empty_stmt|;
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
comment|// LLVM_EXECUTION_ENGINE_JIT_DWARFEMITTER_H
end_comment

end_unit

