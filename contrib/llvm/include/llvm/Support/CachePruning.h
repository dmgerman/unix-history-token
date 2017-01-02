begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- CachePruning.h - Helper to manage the pruning of a cache dir -*- C++ -*-=//
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
comment|// This file implements pruning of a directory intended for cache storage, using
end_comment

begin_comment
comment|// various policies.
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
name|LLVM_SUPPORT_CACHE_PRUNING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_CACHE_PRUNING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<chrono>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Handle pruning a directory provided a path and some options to control what
comment|/// to prune.
name|class
name|CachePruning
block|{
name|public
label|:
comment|/// Prepare to prune \p Path.
name|CachePruning
argument_list|(
argument|StringRef Path
argument_list|)
block|:
name|Path
argument_list|(
argument|Path
argument_list|)
block|{}
comment|/// Define the pruning interval. This is intended to be used to avoid scanning
comment|/// the directory too often. It does not impact the decision of which file to
comment|/// prune. A value of 0 forces the scan to occurs.
name|CachePruning
modifier|&
name|setPruningInterval
argument_list|(
name|std
operator|::
name|chrono
operator|::
name|seconds
name|PruningInterval
argument_list|)
block|{
name|Interval
operator|=
name|PruningInterval
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Define the expiration for a file. When a file hasn't been accessed for
comment|/// \p ExpireAfter seconds, it is removed from the cache. A value of 0 disable
comment|/// the expiration-based pruning.
name|CachePruning
modifier|&
name|setEntryExpiration
argument_list|(
name|std
operator|::
name|chrono
operator|::
name|seconds
name|ExpireAfter
argument_list|)
block|{
name|Expiration
operator|=
name|ExpireAfter
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Define the maximum size for the cache directory, in terms of percentage of
comment|/// the available space on the the disk. Set to 100 to indicate no limit, 50
comment|/// to indicate that the cache size will not be left over half the
comment|/// available disk space. A value over 100 will be reduced to 100. A value of
comment|/// 0 disable the size-based pruning.
name|CachePruning
modifier|&
name|setMaxSize
parameter_list|(
name|unsigned
name|Percentage
parameter_list|)
block|{
name|PercentageOfAvailableSpace
operator|=
name|std
operator|::
name|min
argument_list|(
literal|100u
argument_list|,
name|Percentage
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Peform pruning using the supplied options, returns true if pruning
comment|/// occured, i.e. if PruningInterval was expired.
name|bool
name|prune
parameter_list|()
function_decl|;
name|private
label|:
comment|// Options that matches the setters above.
name|std
operator|::
name|string
name|Path
expr_stmt|;
name|std
operator|::
name|chrono
operator|::
name|seconds
name|Expiration
operator|=
name|std
operator|::
name|chrono
operator|::
name|seconds
operator|::
name|zero
argument_list|()
expr_stmt|;
name|std
operator|::
name|chrono
operator|::
name|seconds
name|Interval
operator|=
name|std
operator|::
name|chrono
operator|::
name|seconds
operator|::
name|zero
argument_list|()
expr_stmt|;
name|unsigned
name|PercentageOfAvailableSpace
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

