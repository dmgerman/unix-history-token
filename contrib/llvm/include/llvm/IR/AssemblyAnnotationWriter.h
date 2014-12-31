begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AssemblyAnnotationWriter.h - Annotation .ll files -------*- C++ -*-===//
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
comment|// Clients of the assembly writer can use this interface to add their own
end_comment

begin_comment
comment|// special-purpose annotations to LLVM assembly language printouts.  Note that
end_comment

begin_comment
comment|// the assembly parser won't be able to parse these, in general, so
end_comment

begin_comment
comment|// implementations are advised to print stuff as LLVM comments.
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
name|LLVM_IR_ASMANNOTATIONWRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_ASMANNOTATIONWRITER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
name|class
name|AssemblyAnnotationWriter
block|{
name|public
label|:
name|virtual
operator|~
name|AssemblyAnnotationWriter
argument_list|()
expr_stmt|;
comment|/// emitFunctionAnnot - This may be implemented to emit a string right before
comment|/// the start of a function.
name|virtual
name|void
name|emitFunctionAnnot
parameter_list|(
specifier|const
name|Function
modifier|*
parameter_list|,
name|formatted_raw_ostream
modifier|&
parameter_list|)
block|{}
comment|/// emitBasicBlockStartAnnot - This may be implemented to emit a string right
comment|/// after the basic block label, but before the first instruction in the
comment|/// block.
name|virtual
name|void
name|emitBasicBlockStartAnnot
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
parameter_list|,
name|formatted_raw_ostream
modifier|&
parameter_list|)
block|{   }
comment|/// emitBasicBlockEndAnnot - This may be implemented to emit a string right
comment|/// after the basic block.
name|virtual
name|void
name|emitBasicBlockEndAnnot
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
parameter_list|,
name|formatted_raw_ostream
modifier|&
parameter_list|)
block|{   }
comment|/// emitInstructionAnnot - This may be implemented to emit a string right
comment|/// before an instruction is emitted.
name|virtual
name|void
name|emitInstructionAnnot
parameter_list|(
specifier|const
name|Instruction
modifier|*
parameter_list|,
name|formatted_raw_ostream
modifier|&
parameter_list|)
block|{}
comment|/// printInfoComment - This may be implemented to emit a comment to the
comment|/// right of an instruction or global value.
name|virtual
name|void
name|printInfoComment
parameter_list|(
specifier|const
name|Value
modifier|&
parameter_list|,
name|formatted_raw_ostream
modifier|&
parameter_list|)
block|{}
block|}
empty_stmt|;
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

