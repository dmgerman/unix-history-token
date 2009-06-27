begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/ThreadLocal.h - Thread Local Data ------------*- C++ -*-===//
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
comment|// This file declares the llvm::sys::ThreadLocal class.
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
name|LLVM_SYSTEM_THREAD_LOCAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_THREAD_LOCAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/Threading.h"
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
name|namespace
name|sys
block|{
name|class
name|ThreadLocalImpl
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|public
label|:
name|ThreadLocalImpl
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|ThreadLocalImpl
argument_list|()
expr_stmt|;
name|void
name|setInstance
parameter_list|(
specifier|const
name|void
modifier|*
name|d
parameter_list|)
function_decl|;
specifier|const
name|void
modifier|*
name|getInstance
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|class
name|ThreadLocal
operator|:
name|public
name|ThreadLocalImpl
block|{
name|public
operator|:
name|ThreadLocal
argument_list|()
operator|:
name|ThreadLocalImpl
argument_list|()
block|{ }
name|T
operator|*
name|get
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|getInstance
argument_list|()
operator|)
return|;
block|}
name|void
name|set
argument_list|(
argument|T* d
argument_list|)
block|{
name|setInstance
argument_list|(
name|d
argument_list|)
block|; }
expr|}
block|;   }
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

