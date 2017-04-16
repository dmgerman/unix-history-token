begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/thread.h - Wrapper for<thread> ------------*- C++ -*-===//
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
comment|// This header is a wrapper for<thread> that works around problems with the
end_comment

begin_comment
comment|// MSVC headers when exceptions are disabled. It also provides llvm::thread,
end_comment

begin_comment
comment|// which is either a typedef of std::thread or a replacement that calls the
end_comment

begin_comment
comment|// function synchronously depending on the value of LLVM_ENABLE_THREADS.
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
name|LLVM_SUPPORT_THREAD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_THREAD_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_if
if|#
directive|if
name|LLVM_ENABLE_THREADS
end_if

begin_include
include|#
directive|include
file|<thread>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
typedef|typedef
name|std
operator|::
name|thread
name|thread
expr_stmt|;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|// !LLVM_ENABLE_THREADS
end_comment

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct|struct
name|thread
block|{
name|thread
argument_list|()
block|{}
name|thread
argument_list|(
argument|thread&&other
argument_list|)
block|{}
name|template
operator|<
name|class
name|Function
operator|,
name|class
operator|...
name|Args
operator|>
name|explicit
name|thread
argument_list|(
argument|Function&&f
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|f
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|args
operator|)
operator|...
argument_list|)
block|;   }
name|thread
argument_list|(
specifier|const
name|thread
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|join
parameter_list|()
block|{}
specifier|static
name|unsigned
name|hardware_concurrency
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
empty_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ENABLE_THREADS
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

