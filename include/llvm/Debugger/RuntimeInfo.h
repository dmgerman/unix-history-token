begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RuntimeInfo.h - Information about running program --------*- C++ -*-===//
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
comment|// This file defines classes that capture various pieces of information about
end_comment

begin_comment
comment|// the currently executing, but stopped, program.  One instance of this object
end_comment

begin_comment
comment|// is created every time a program is stopped, and destroyed every time it
end_comment

begin_comment
comment|// starts running again.  This object's main goal is to make access to runtime
end_comment

begin_comment
comment|// information easy and efficient, by caching information as requested.
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
name|LLVM_DEBUGGER_RUNTIMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGGER_RUNTIMEINFO_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ProgramInfo
decl_stmt|;
name|class
name|RuntimeInfo
decl_stmt|;
name|class
name|InferiorProcess
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|SourceFileInfo
decl_stmt|;
comment|/// StackFrame - One instance of this structure is created for each stack
comment|/// frame that is active in the program.
comment|///
name|class
name|StackFrame
block|{
name|RuntimeInfo
modifier|&
name|RI
decl_stmt|;
name|void
modifier|*
name|FrameID
decl_stmt|;
specifier|const
name|GlobalVariable
modifier|*
name|FunctionDesc
decl_stmt|;
comment|/// LineNo, ColNo, FileInfo - This information indicates WHERE in the source
comment|/// code for the program the stack frame is located.
name|unsigned
name|LineNo
decl_stmt|,
name|ColNo
decl_stmt|;
specifier|const
name|SourceFileInfo
modifier|*
name|SourceInfo
decl_stmt|;
name|public
label|:
name|StackFrame
argument_list|(
name|RuntimeInfo
operator|&
name|RI
argument_list|,
name|void
operator|*
name|ParentFrameID
argument_list|)
expr_stmt|;
name|StackFrame
modifier|&
name|operator
init|=
operator|(
specifier|const
name|StackFrame
operator|&
name|RHS
operator|)
block|{
name|FrameID
operator|=
name|RHS
operator|.
name|FrameID
block|;
name|FunctionDesc
operator|=
name|RHS
operator|.
name|FunctionDesc
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// getFrameID - return the low-level opaque frame ID of this stack frame.
comment|///
name|void
operator|*
name|getFrameID
argument_list|()
specifier|const
block|{
return|return
name|FrameID
return|;
block|}
comment|/// getFunctionDesc - Return the descriptor for the function that contains
comment|/// this stack frame, or null if it is unknown.
comment|///
specifier|const
name|GlobalVariable
modifier|*
name|getFunctionDesc
parameter_list|()
function_decl|;
comment|/// getSourceLocation - Return the source location that this stack frame is
comment|/// sitting at.
name|void
name|getSourceLocation
parameter_list|(
name|unsigned
modifier|&
name|LineNo
parameter_list|,
name|unsigned
modifier|&
name|ColNo
parameter_list|,
specifier|const
name|SourceFileInfo
modifier|*
modifier|&
name|SourceInfo
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// RuntimeInfo - This class collects information about the currently running
comment|/// process.  It is created whenever the program stops execution for the
comment|/// debugger, and destroyed whenver execution continues.
name|class
name|RuntimeInfo
block|{
comment|/// ProgInfo - This object contains static information about the program.
comment|///
name|ProgramInfo
modifier|*
name|ProgInfo
decl_stmt|;
comment|/// IP - This object contains information about the actual inferior process
comment|/// that we are communicating with and aggregating information from.
specifier|const
name|InferiorProcess
modifier|&
name|IP
decl_stmt|;
comment|/// CallStack - This caches information about the current stack trace of the
comment|/// program.  This is lazily computed as needed.
name|std
operator|::
name|vector
operator|<
name|StackFrame
operator|>
name|CallStack
expr_stmt|;
comment|/// CurrentFrame - The user can traverse the stack frame with the
comment|/// up/down/frame family of commands.  This index indicates the current
comment|/// stack frame.
name|unsigned
name|CurrentFrame
decl_stmt|;
name|public
label|:
name|RuntimeInfo
argument_list|(
name|ProgramInfo
operator|*
name|PI
argument_list|,
specifier|const
name|InferiorProcess
operator|&
name|ip
argument_list|)
operator|:
name|ProgInfo
argument_list|(
name|PI
argument_list|)
operator|,
name|IP
argument_list|(
name|ip
argument_list|)
operator|,
name|CurrentFrame
argument_list|(
literal|0
argument_list|)
block|{
comment|// Make sure that the top of stack has been materialized.  If this throws
comment|// an exception, something is seriously wrong and the RuntimeInfo object
comment|// would be unusable anyway.
name|getStackFrame
argument_list|(
literal|0
argument_list|)
block|;     }
name|ProgramInfo
operator|&
name|getProgramInfo
argument_list|()
block|{
return|return
operator|*
name|ProgInfo
return|;
block|}
specifier|const
name|InferiorProcess
operator|&
name|getInferiorProcess
argument_list|()
specifier|const
block|{
return|return
name|IP
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Methods for inspecting the call stack of the program.
comment|//
comment|/// getStackFrame - Materialize the specified stack frame and return it.  If
comment|/// the specified ID is off of the bottom of the stack, throw an exception
comment|/// indicating the problem.
name|StackFrame
modifier|&
name|getStackFrame
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
if|if
condition|(
name|ID
operator|>=
name|CallStack
operator|.
name|size
argument_list|()
condition|)
name|materializeFrame
argument_list|(
name|ID
argument_list|)
expr_stmt|;
return|return
name|CallStack
index|[
name|ID
index|]
return|;
block|}
comment|/// getCurrentFrame - Return the current stack frame object that the user is
comment|/// inspecting.
name|StackFrame
modifier|&
name|getCurrentFrame
parameter_list|()
block|{
name|assert
argument_list|(
name|CallStack
operator|.
name|size
argument_list|()
operator|>
name|CurrentFrame
operator|&&
literal|"Must have materialized frame before making it current!"
argument_list|)
expr_stmt|;
return|return
name|CallStack
index|[
name|CurrentFrame
index|]
return|;
block|}
comment|/// getCurrentFrameIdx - Return the current frame the user is inspecting.
comment|///
name|unsigned
name|getCurrentFrameIdx
argument_list|()
specifier|const
block|{
return|return
name|CurrentFrame
return|;
block|}
comment|/// setCurrentFrameIdx - Set the current frame index to the specified value.
comment|/// Note that the specified frame must have been materialized with
comment|/// getStackFrame before it can be made current.
name|void
name|setCurrentFrameIdx
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|CallStack
operator|.
name|size
argument_list|()
operator|&&
literal|"Must materialize frame before making it current!"
argument_list|)
expr_stmt|;
name|CurrentFrame
operator|=
name|Idx
expr_stmt|;
block|}
name|private
label|:
comment|/// materializeFrame - Create and process all frames up to and including the
comment|/// specified frame number.  This throws an exception if the specified frame
comment|/// ID is nonexistant.
name|void
name|materializeFrame
parameter_list|(
name|unsigned
name|ID
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

