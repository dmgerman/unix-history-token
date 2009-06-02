begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InferiorProcess.h - Represent the program being debugged -*- C++ -*-===//
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
comment|// This file defines the InferiorProcess class, which is used to represent,
end_comment

begin_comment
comment|// inspect, and manipulate a process under the control of the LLVM debugger.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is an abstract class which should allow various different types of
end_comment

begin_comment
comment|// implementations.  Initially we implement a unix specific debugger backend
end_comment

begin_comment
comment|// that does not require code generator support, but we could eventually use
end_comment

begin_comment
comment|// code generator support with ptrace, support windows based targets, supported
end_comment

begin_comment
comment|// remote targets, etc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the inferior process unexpectedly dies, an attempt to communicate with it
end_comment

begin_comment
comment|// will cause an InferiorProcessDead exception to be thrown, indicating the exit
end_comment

begin_comment
comment|// code of the process.  When this occurs, no methods on the InferiorProcess
end_comment

begin_comment
comment|// class should be called except for the destructor.
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
name|LLVM_DEBUGGER_INFERIORPROCESS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGGER_INFERIORPROCESS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
comment|/// InferiorProcessDead exception - This class is thrown by methods that
comment|/// communicate with the interior process if the process unexpectedly exits or
comment|/// dies.  The instance variable indicates what the exit code of the process
comment|/// was, or -1 if unknown.
name|class
name|InferiorProcessDead
block|{
name|int
name|ExitCode
decl_stmt|;
name|public
label|:
name|InferiorProcessDead
argument_list|(
argument|int EC
argument_list|)
block|:
name|ExitCode
argument_list|(
argument|EC
argument_list|)
block|{}
name|int
name|getExitCode
argument_list|()
specifier|const
block|{
return|return
name|ExitCode
return|;
block|}
block|}
empty_stmt|;
comment|/// InferiorProcess class - This class represents the process being debugged
comment|/// by the debugger.  Objects of this class should not be stack allocated,
comment|/// because the destructor can throw exceptions.
comment|///
name|class
name|InferiorProcess
block|{
name|Module
modifier|*
name|M
decl_stmt|;
name|protected
label|:
name|InferiorProcess
argument_list|(
name|Module
operator|*
name|m
argument_list|)
operator|:
name|M
argument_list|(
argument|m
argument_list|)
block|{}
name|public
operator|:
comment|/// create - Create an inferior process of the specified module, and
comment|/// stop it at the first opportunity.  If there is a problem starting the
comment|/// program (for example, it has no main), throw an exception.
specifier|static
name|InferiorProcess
operator|*
name|create
argument_list|(
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Arguments
argument_list|,
specifier|const
name|char
operator|*
specifier|const
operator|*
name|envp
argument_list|)
expr_stmt|;
comment|// InferiorProcess destructor - Kill the current process.  If something
comment|// terrible happens, we throw an exception from the destructor.
name|virtual
operator|~
name|InferiorProcess
argument_list|()
block|{}
comment|//===------------------------------------------------------------------===//
comment|// Status methods - These methods return information about the currently
comment|// stopped process.
comment|//
comment|/// getStatus - Return a status message that is specific to the current type
comment|/// of inferior process that is created.  This can return things like the
comment|/// PID of the inferior or other potentially interesting things.
name|virtual
name|std
operator|::
name|string
name|getStatus
argument_list|()
specifier|const
block|{
return|return
literal|""
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Methods for inspecting the call stack.
comment|//
comment|/// getPreviousFrame - Given the descriptor for the current stack frame,
comment|/// return the descriptor for the caller frame.  This returns null when it
comment|/// runs out of frames.  If Frame is null, the initial frame should be
comment|/// returned.
name|virtual
name|void
modifier|*
name|getPreviousFrame
argument_list|(
name|void
operator|*
name|Frame
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getSubprogramDesc - Return the subprogram descriptor for the current
comment|/// stack frame.
name|virtual
specifier|const
name|GlobalVariable
modifier|*
name|getSubprogramDesc
argument_list|(
name|void
operator|*
name|Frame
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// getFrameLocation - This method returns the source location where each
comment|/// stack frame is stopped.
name|virtual
name|void
name|getFrameLocation
argument_list|(
name|void
operator|*
name|Frame
argument_list|,
name|unsigned
operator|&
name|LineNo
argument_list|,
name|unsigned
operator|&
name|ColNo
argument_list|,
specifier|const
name|GlobalVariable
operator|*
operator|&
name|SourceDesc
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Methods for manipulating breakpoints.
comment|//
comment|/// addBreakpoint - This method adds a breakpoint at the specified line,
comment|/// column, and source file, and returns a unique identifier for it.
comment|///
comment|/// It is up to the debugger to determine whether or not there is actually a
comment|/// stop-point that corresponds with the specified location.
name|virtual
name|unsigned
name|addBreakpoint
parameter_list|(
name|unsigned
name|LineNo
parameter_list|,
name|unsigned
name|ColNo
parameter_list|,
specifier|const
name|GlobalVariable
modifier|*
name|SourceDesc
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// removeBreakpoint - This deletes the breakpoint with the specified ID
comment|/// number.
name|virtual
name|void
name|removeBreakpoint
parameter_list|(
name|unsigned
name|ID
parameter_list|)
init|=
literal|0
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// Execution methods - These methods cause the program to continue execution
comment|// by some amount.  If the program successfully stops, this returns.
comment|// Otherwise, if the program unexpectedly terminates, an InferiorProcessDead
comment|// exception is thrown.
comment|//
comment|/// stepProgram - Implement the 'step' command, continuing execution until
comment|/// the next possible stop point.
name|virtual
name|void
name|stepProgram
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// finishProgram - Implement the 'finish' command, continuing execution
comment|/// until the current function returns.
name|virtual
name|void
name|finishProgram
parameter_list|(
name|void
modifier|*
name|Frame
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// contProgram - Implement the 'cont' command, continuing execution until
comment|/// a breakpoint is encountered.
name|virtual
name|void
name|contProgram
parameter_list|()
init|=
literal|0
function_decl|;
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

end_unit

