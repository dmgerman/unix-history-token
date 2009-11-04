begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/SlowOperationInformer.h - Keep user informed *- C++ -*-===//
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
comment|// This file defines a simple object which can be used to let the user know what
end_comment

begin_comment
comment|// is going on when a slow operation is happening, and gives them the ability to
end_comment

begin_comment
comment|// cancel it.  Potentially slow operations can stack allocate one of these
end_comment

begin_comment
comment|// objects, and periodically call the "progress" method to update the progress
end_comment

begin_comment
comment|// bar.  If the operation takes more than 1 second to complete, the progress bar
end_comment

begin_comment
comment|// is automatically shown and updated.  As such, the slow operation should not
end_comment

begin_comment
comment|// print stuff to the screen, and should not be confused if an extra line
end_comment

begin_comment
comment|// appears on the screen (ie, the cursor should be at the start of the line).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the user presses CTRL-C during the operation, the next invocation of the
end_comment

begin_comment
comment|// progress method return true indicating that the operation was cancelled.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Because SlowOperationInformers fiddle around with signals, they cannot be
end_comment

begin_comment
comment|// nested, and interact poorly with threads.  The SIGALRM handler is set back to
end_comment

begin_comment
comment|// SIGDFL, but the SIGINT signal handler is restored when the
end_comment

begin_comment
comment|// SlowOperationInformer is destroyed.
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
name|LLVM_SUPPORT_SLOW_OPERATION_INFORMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SLOW_OPERATION_INFORMER_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SlowOperationInformer
block|{
name|std
operator|::
name|string
name|OperationName
expr_stmt|;
name|unsigned
name|LastPrintAmount
decl_stmt|;
name|SlowOperationInformer
argument_list|(
specifier|const
name|SlowOperationInformer
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|SlowOperationInformer
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|SlowOperationInformer
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
expr_stmt|;
operator|~
name|SlowOperationInformer
argument_list|()
expr_stmt|;
comment|/// progress - Clients should periodically call this method when they can
comment|/// handle cancellation.  The Amount variable should indicate how far
comment|/// along the operation is, given in 1/10ths of a percent (in other words,
comment|/// Amount should range from 0 to 1000).  If the user cancels the operation,
comment|/// this returns true, false otherwise.
name|bool
name|progress
parameter_list|(
name|unsigned
name|Amount
parameter_list|)
function_decl|;
comment|/// progress - Same as the method above, but this performs the division for
comment|/// you, and helps you avoid overflow if you are dealing with largish
comment|/// numbers.
name|bool
name|progress
parameter_list|(
name|unsigned
name|Current
parameter_list|,
name|unsigned
name|Maximum
parameter_list|)
block|{
name|assert
argument_list|(
name|Maximum
operator|!=
literal|0
operator|&&
literal|"Shouldn't be doing work if there is nothing to do!"
argument_list|)
expr_stmt|;
return|return
name|progress
argument_list|(
name|Current
operator|*
name|uint64_t
argument_list|(
literal|1000UL
argument_list|)
operator|/
name|Maximum
argument_list|)
return|;
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
comment|/* SLOW_OPERATION_INFORMER_H */
end_comment

end_unit

