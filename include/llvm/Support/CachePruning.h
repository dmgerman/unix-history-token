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
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|Expected
expr_stmt|;
comment|/// Policy for the pruneCache() function. A default constructed
comment|/// CachePruningPolicy provides a reasonable default policy.
struct|struct
name|CachePruningPolicy
block|{
comment|/// The pruning interval. This is intended to be used to avoid scanning the
comment|/// directory too often. It does not impact the decision of which file to
comment|/// prune. A value of 0 forces the scan to occur.
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
argument_list|(
literal|1200
argument_list|)
expr_stmt|;
comment|/// The expiration for a file. When a file hasn't been accessed for Expiration
comment|/// seconds, it is removed from the cache. A value of 0 disables the
comment|/// expiration-based pruning.
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
name|hours
argument_list|(
literal|7
operator|*
literal|24
argument_list|)
expr_stmt|;
comment|// 1w
comment|/// The maximum size for the cache directory, in terms of percentage of the
comment|/// available space on the the disk. Set to 100 to indicate no limit, 50 to
comment|/// indicate that the cache size will not be left over half the available disk
comment|/// space. A value over 100 will be reduced to 100. A value of 0 disables the
comment|/// percentage size-based pruning.
name|unsigned
name|MaxSizePercentageOfAvailableSpace
init|=
literal|75
decl_stmt|;
comment|/// The maximum size for the cache directory in bytes. A value over the amount
comment|/// of available space on the disk will be reduced to the amount of available
comment|/// space. A value of 0 disables the absolute size-based pruning.
name|uint64_t
name|MaxSizeBytes
init|=
literal|0
decl_stmt|;
block|}
struct|;
comment|/// Parse the given string as a cache pruning policy. Defaults are taken from a
comment|/// default constructed CachePruningPolicy object.
comment|/// For example: "prune_interval=30s:prune_after=24h:cache_size=50%"
comment|/// which means a pruning interval of 30 seconds, expiration time of 24 hours
comment|/// and maximum cache size of 50% of available disk space.
name|Expected
operator|<
name|CachePruningPolicy
operator|>
name|parseCachePruningPolicy
argument_list|(
argument|StringRef PolicyStr
argument_list|)
expr_stmt|;
comment|/// Peform pruning using the supplied policy, returns true if pruning
comment|/// occured, i.e. if Policy.Interval was expired.
comment|///
comment|/// As a safeguard against data loss if the user specifies the wrong directory
comment|/// as their cache directory, this function will ignore files not matching the
comment|/// pattern "llvmcache-*".
name|bool
name|pruneCache
parameter_list|(
name|StringRef
name|Path
parameter_list|,
name|CachePruningPolicy
name|Policy
parameter_list|)
function_decl|;
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

