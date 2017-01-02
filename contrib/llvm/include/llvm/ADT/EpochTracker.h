begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/EpochTracker.h - ADT epoch tracking --------------*- C++ -*-==//
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
comment|// This file defines the DebugEpochBase and DebugEpochBase::HandleBase classes.
end_comment

begin_comment
comment|// These can be used to write iterators that are fail-fast when LLVM is built
end_comment

begin_comment
comment|// with asserts enabled.
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
name|LLVM_ADT_EPOCH_TRACKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_EPOCH_TRACKER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/abi-breaking.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Config/llvm-config.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
comment|/// \brief A base class for data structure classes wishing to make iterators
comment|/// ("handles") pointing into themselves fail-fast.  When building without
comment|/// asserts, this class is empty and does nothing.
comment|///
comment|/// DebugEpochBase does not by itself track handles pointing into itself.  The
comment|/// expectation is that routines touching the handles will poll on
comment|/// isHandleInSync at appropriate points to assert that the handle they're using
comment|/// is still valid.
comment|///
name|class
name|DebugEpochBase
block|{
name|uint64_t
name|Epoch
decl_stmt|;
name|public
label|:
name|DebugEpochBase
argument_list|()
operator|:
name|Epoch
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief Calling incrementEpoch invalidates all handles pointing into the
comment|/// calling instance.
name|void
name|incrementEpoch
argument_list|()
block|{
operator|++
name|Epoch
block|; }
comment|/// \brief The destructor calls incrementEpoch to make use-after-free bugs
comment|/// more likely to crash deterministically.
operator|~
name|DebugEpochBase
argument_list|()
block|{
name|incrementEpoch
argument_list|()
block|; }
comment|/// \brief A base class for iterator classes ("handles") that wish to poll for
comment|/// iterator invalidating modifications in the underlying data structure.
comment|/// When LLVM is built without asserts, this class is empty and does nothing.
comment|///
comment|/// HandleBase does not track the parent data structure by itself.  It expects
comment|/// the routines modifying the data structure to call incrementEpoch when they
comment|/// make an iterator-invalidating modification.
comment|///
name|class
name|HandleBase
block|{
specifier|const
name|uint64_t
operator|*
name|EpochAddress
block|;
name|uint64_t
name|EpochAtCreation
block|;
name|public
operator|:
name|HandleBase
argument_list|()
operator|:
name|EpochAddress
argument_list|(
name|nullptr
argument_list|)
block|,
name|EpochAtCreation
argument_list|(
argument|UINT64_MAX
argument_list|)
block|{}
name|explicit
name|HandleBase
argument_list|(
specifier|const
name|DebugEpochBase
operator|*
name|Parent
argument_list|)
operator|:
name|EpochAddress
argument_list|(
operator|&
name|Parent
operator|->
name|Epoch
argument_list|)
block|,
name|EpochAtCreation
argument_list|(
argument|Parent->Epoch
argument_list|)
block|{}
comment|/// \brief Returns true if the DebugEpochBase this Handle is linked to has
comment|/// not called incrementEpoch on itself since the creation of this
comment|/// HandleBase instance.
name|bool
name|isHandleInSync
argument_list|()
specifier|const
block|{
return|return
operator|*
name|EpochAddress
operator|==
name|EpochAtCreation
return|;
block|}
comment|/// \brief Returns a pointer to the epoch word stored in the data structure
comment|/// this handle points into.  Can be used to check if two iterators point
comment|/// into the same data structure.
specifier|const
name|void
operator|*
name|getEpochAddress
argument_list|()
specifier|const
block|{
return|return
name|EpochAddress
return|;
block|}
expr|}
block|; }
expr_stmt|;
else|#
directive|else
name|class
name|DebugEpochBase
block|{
name|public
label|:
name|void
name|incrementEpoch
parameter_list|()
block|{}
name|class
name|HandleBase
block|{
name|public
label|:
name|HandleBase
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|HandleBase
parameter_list|(
specifier|const
name|DebugEpochBase
modifier|*
parameter_list|)
block|{}
name|bool
name|isHandleInSync
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
specifier|const
name|void
operator|*
name|getEpochAddress
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
block|}
empty_stmt|;
block|}
empty_stmt|;
endif|#
directive|endif
comment|// LLVM_ENABLE_ABI_BREAKING_CHECKS
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

