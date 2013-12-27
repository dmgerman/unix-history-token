begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Watchdog.h - Watchdog timer ----------------------------*- C++ -*-===//
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
comment|//  This file declares the llvm::sys::Watchdog class.
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
name|LLVM_SUPPORT_WATCHDOG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_WATCHDOG_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This class provides an abstraction for a timeout around an operation
comment|/// that must complete in a given amount of time. Failure to complete before
comment|/// the timeout is an unrecoverable situation and no mechanisms to attempt
comment|/// to handle it are provided.
name|class
name|Watchdog
block|{
name|public
label|:
name|Watchdog
argument_list|(
argument|unsigned int seconds
argument_list|)
empty_stmt|;
operator|~
name|Watchdog
argument_list|()
expr_stmt|;
name|private
label|:
comment|// Noncopyable.
name|Watchdog
argument_list|(
argument|const Watchdog&other
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|Watchdog
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Watchdog
operator|&
name|other
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

