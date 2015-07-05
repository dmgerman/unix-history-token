begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/ThreadLocal.h - Thread Local Data ------------*- C++ -*-===//
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
name|LLVM_SUPPORT_THREADLOCAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_THREADLOCAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Threading.h"
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
comment|// ThreadLocalImpl - Common base class of all ThreadLocal instantiations.
comment|// YOU SHOULD NEVER USE THIS DIRECTLY.
name|class
name|ThreadLocalImpl
block|{
typedef|typedef
name|uint64_t
name|ThreadLocalDataTy
typedef|;
comment|/// \brief Platform-specific thread local data.
comment|///
comment|/// This is embedded in the class and we avoid malloc'ing/free'ing it,
comment|/// to make this class more safe for use along with CrashRecoveryContext.
union|union
block|{
name|char
name|data
index|[
sizeof|sizeof
argument_list|(
name|ThreadLocalDataTy
argument_list|)
index|]
decl_stmt|;
name|ThreadLocalDataTy
name|align_data
decl_stmt|;
block|}
union|;
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
name|void
modifier|*
name|getInstance
parameter_list|()
function_decl|;
name|void
name|removeInstance
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// ThreadLocal - A class used to abstract thread-local storage.  It holds,
comment|/// for each thread, a pointer a single object of type T.
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
comment|/// get - Fetches a pointer to the object associated with the current
comment|/// thread.  If no object has yet been associated, it returns NULL;
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
comment|// set - Associates a pointer to an object with the current thread.
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
comment|// erase - Removes the pointer associated with the current thread.
name|void
name|erase
argument_list|()
block|{
name|removeInstance
argument_list|()
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

