begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JIT.h - Abstract Execution Engine Interface -------------*- C++ -*-===//
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
comment|// Common functionality for JITEventListener implementations
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
name|EVENT_LISTENER_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EVENT_LISTENER_COMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ValueHandle.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|jitprofiling
block|{
name|class
name|FilenameCache
block|{
comment|// Holds the filename of each Scope, so that we can pass a null-terminated
comment|// string into oprofile.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|std
operator|::
name|string
operator|>
name|Filenames
expr_stmt|;
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|std
operator|::
name|string
operator|>
name|Paths
expr_stmt|;
name|public
label|:
specifier|const
name|char
modifier|*
name|getFilename
parameter_list|(
name|MDNode
modifier|*
name|Scope
parameter_list|)
block|{
name|assert
argument_list|(
name|Scope
operator|->
name|isResolved
argument_list|()
operator|&&
literal|"Expected Scope to be resolved"
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
operator|&
name|Filename
operator|=
name|Filenames
index|[
name|Scope
index|]
expr_stmt|;
if|if
condition|(
name|Filename
operator|.
name|empty
argument_list|()
condition|)
block|{
name|DIScope
name|DIScope
argument_list|(
name|Scope
argument_list|)
decl_stmt|;
name|Filename
operator|=
name|DIScope
operator|.
name|getFilename
argument_list|()
expr_stmt|;
block|}
return|return
name|Filename
operator|.
name|c_str
argument_list|()
return|;
block|}
specifier|const
name|char
modifier|*
name|getFullPath
parameter_list|(
name|MDNode
modifier|*
name|Scope
parameter_list|)
block|{
name|assert
argument_list|(
name|Scope
operator|->
name|isResolved
argument_list|()
operator|&&
literal|"Expected Scope to be resolved"
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
operator|&
name|P
operator|=
name|Paths
index|[
name|Scope
index|]
expr_stmt|;
if|if
condition|(
name|P
operator|.
name|empty
argument_list|()
condition|)
block|{
name|DIScope
name|DIScope
argument_list|(
name|Scope
argument_list|)
decl_stmt|;
name|StringRef
name|DirName
init|=
name|DIScope
operator|.
name|getDirectory
argument_list|()
decl_stmt|;
name|StringRef
name|FileName
init|=
name|DIScope
operator|.
name|getFilename
argument_list|()
decl_stmt|;
name|SmallString
operator|<
literal|256
operator|>
name|FullPath
expr_stmt|;
if|if
condition|(
name|DirName
operator|!=
literal|"."
operator|&&
name|DirName
operator|!=
literal|""
condition|)
block|{
name|FullPath
operator|=
name|DirName
expr_stmt|;
block|}
if|if
condition|(
name|FileName
operator|!=
literal|""
condition|)
block|{
name|sys
operator|::
name|path
operator|::
name|append
argument_list|(
name|FullPath
argument_list|,
name|FileName
argument_list|)
expr_stmt|;
block|}
name|P
operator|=
name|FullPath
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
return|return
name|P
operator|.
name|c_str
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// namespace jitprofiling
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//EVENT_LISTENER_COMMON_H
end_comment

end_unit

