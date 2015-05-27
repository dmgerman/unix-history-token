begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LockFileManager.h - File-level locking utility ---------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_LOCKFILEMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_LOCKFILEMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_comment
comment|// for std::pair
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Class that manages the creation of a lock file to aid
comment|/// implicit coordination between different processes.
comment|///
comment|/// The implicit coordination works by creating a ".lock" file alongside
comment|/// the file that we're coordinating for, using the atomicity of the file
comment|/// system to ensure that only a single process can create that ".lock" file.
comment|/// When the lock file is removed, the owning process has finished the
comment|/// operation.
name|class
name|LockFileManager
block|{
name|public
label|:
comment|/// \brief Describes the state of a lock file.
enum|enum
name|LockFileState
block|{
comment|/// \brief The lock file has been created and is owned by this instance
comment|/// of the object.
name|LFS_Owned
block|,
comment|/// \brief The lock file already exists and is owned by some other
comment|/// instance.
name|LFS_Shared
block|,
comment|/// \brief An error occurred while trying to create or find the lock
comment|/// file.
name|LFS_Error
block|}
enum|;
comment|/// \brief Describes the result of waiting for the owner to release the lock.
enum|enum
name|WaitForUnlockResult
block|{
comment|/// \brief The lock was released successfully.
name|Res_Success
block|,
comment|/// \brief Owner died while holding the lock.
name|Res_OwnerDied
block|,
comment|/// \brief Reached timeout while waiting for the owner to release the lock.
name|Res_Timeout
block|}
enum|;
name|private
label|:
name|SmallString
operator|<
literal|128
operator|>
name|FileName
expr_stmt|;
name|SmallString
operator|<
literal|128
operator|>
name|LockFileName
expr_stmt|;
name|SmallString
operator|<
literal|128
operator|>
name|UniqueLockFileName
expr_stmt|;
name|Optional
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|int
operator|>
expr|>
name|Owner
expr_stmt|;
name|Optional
operator|<
name|std
operator|::
name|error_code
operator|>
name|Error
expr_stmt|;
name|LockFileManager
argument_list|(
argument|const LockFileManager&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|LockFileManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LockFileManager
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
specifier|static
name|Optional
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|int
operator|>
expr|>
name|readLockFile
argument_list|(
argument|StringRef LockFileName
argument_list|)
expr_stmt|;
specifier|static
name|bool
name|processStillExecuting
parameter_list|(
name|StringRef
name|Hostname
parameter_list|,
name|int
name|PID
parameter_list|)
function_decl|;
name|public
label|:
name|LockFileManager
argument_list|(
argument|StringRef FileName
argument_list|)
empty_stmt|;
operator|~
name|LockFileManager
argument_list|()
expr_stmt|;
comment|/// \brief Determine the state of the lock file.
name|LockFileState
name|getState
argument_list|()
specifier|const
expr_stmt|;
name|operator
name|LockFileState
argument_list|()
specifier|const
block|{
return|return
name|getState
argument_list|()
return|;
block|}
comment|/// \brief For a shared lock, wait until the owner releases the lock.
name|WaitForUnlockResult
name|waitForUnlock
parameter_list|()
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

begin_comment
comment|// LLVM_SUPPORT_LOCKFILEMANAGER_H
end_comment

end_unit

