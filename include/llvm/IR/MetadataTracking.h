begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/IR/MetadataTracking.h - Metadata tracking ---------------------===//
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
comment|// Low-level functions to enable tracking of metadata that could RAUW.
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
name|LLVM_IR_METADATATRACKING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_METADATATRACKING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Metadata
decl_stmt|;
name|class
name|MetadataAsValue
decl_stmt|;
comment|/// \brief API for tracking metadata references through RAUW and deletion.
comment|///
comment|/// Shared API for updating \a Metadata pointers in subclasses that support
comment|/// RAUW.
comment|///
comment|/// This API is not meant to be used directly.  See \a TrackingMDRef for a
comment|/// user-friendly tracking reference.
name|class
name|MetadataTracking
block|{
name|public
label|:
comment|/// \brief Track the reference to metadata.
comment|///
comment|/// Register \c MD with \c *MD, if the subclass supports tracking.  If \c *MD
comment|/// gets RAUW'ed, \c MD will be updated to the new address.  If \c *MD gets
comment|/// deleted, \c MD will be set to \c nullptr.
comment|///
comment|/// If tracking isn't supported, \c *MD will not change.
comment|///
comment|/// \return true iff tracking is supported by \c MD.
specifier|static
name|bool
name|track
parameter_list|(
name|Metadata
modifier|*
modifier|&
name|MD
parameter_list|)
block|{
return|return
name|track
argument_list|(
operator|&
name|MD
argument_list|,
operator|*
name|MD
argument_list|,
name|static_cast
operator|<
name|Metadata
operator|*
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Track the reference to metadata for \a Metadata.
comment|///
comment|/// As \a track(Metadata*&), but with support for calling back to \c Owner to
comment|/// tell it that its operand changed.  This could trigger \c Owner being
comment|/// re-uniqued.
specifier|static
name|bool
name|track
parameter_list|(
name|void
modifier|*
name|Ref
parameter_list|,
name|Metadata
modifier|&
name|MD
parameter_list|,
name|Metadata
modifier|&
name|Owner
parameter_list|)
block|{
return|return
name|track
argument_list|(
name|Ref
argument_list|,
name|MD
argument_list|,
operator|&
name|Owner
argument_list|)
return|;
block|}
comment|/// \brief Track the reference to metadata for \a MetadataAsValue.
comment|///
comment|/// As \a track(Metadata*&), but with support for calling back to \c Owner to
comment|/// tell it that its operand changed.  This could trigger \c Owner being
comment|/// re-uniqued.
specifier|static
name|bool
name|track
parameter_list|(
name|void
modifier|*
name|Ref
parameter_list|,
name|Metadata
modifier|&
name|MD
parameter_list|,
name|MetadataAsValue
modifier|&
name|Owner
parameter_list|)
block|{
return|return
name|track
argument_list|(
name|Ref
argument_list|,
name|MD
argument_list|,
operator|&
name|Owner
argument_list|)
return|;
block|}
comment|/// \brief Stop tracking a reference to metadata.
comment|///
comment|/// Stops \c *MD from tracking \c MD.
specifier|static
name|void
name|untrack
parameter_list|(
name|Metadata
modifier|*
modifier|&
name|MD
parameter_list|)
block|{
name|untrack
argument_list|(
operator|&
name|MD
argument_list|,
operator|*
name|MD
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|untrack
parameter_list|(
name|void
modifier|*
name|Ref
parameter_list|,
name|Metadata
modifier|&
name|MD
parameter_list|)
function_decl|;
comment|/// \brief Move tracking from one reference to another.
comment|///
comment|/// Semantically equivalent to \c untrack(MD) followed by \c track(New),
comment|/// except that ownership callbacks are maintained.
comment|///
comment|/// Note: it is an error if \c *MD does not equal \c New.
comment|///
comment|/// \return true iff tracking is supported by \c MD.
specifier|static
name|bool
name|retrack
parameter_list|(
name|Metadata
modifier|*
modifier|&
name|MD
parameter_list|,
name|Metadata
modifier|*
modifier|&
name|New
parameter_list|)
block|{
return|return
name|retrack
argument_list|(
operator|&
name|MD
argument_list|,
operator|*
name|MD
argument_list|,
operator|&
name|New
argument_list|)
return|;
block|}
specifier|static
name|bool
name|retrack
parameter_list|(
name|void
modifier|*
name|Ref
parameter_list|,
name|Metadata
modifier|&
name|MD
parameter_list|,
name|void
modifier|*
name|New
parameter_list|)
function_decl|;
comment|/// \brief Check whether metadata is replaceable.
specifier|static
name|bool
name|isReplaceable
parameter_list|(
specifier|const
name|Metadata
modifier|&
name|MD
parameter_list|)
function_decl|;
typedef|typedef
name|PointerUnion
operator|<
name|MetadataAsValue
operator|*
operator|,
name|Metadata
operator|*
operator|>
name|OwnerTy
expr_stmt|;
name|private
label|:
comment|/// \brief Track a reference to metadata for an owner.
comment|///
comment|/// Generalized version of tracking.
specifier|static
name|bool
name|track
parameter_list|(
name|void
modifier|*
name|Ref
parameter_list|,
name|Metadata
modifier|&
name|MD
parameter_list|,
name|OwnerTy
name|Owner
parameter_list|)
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

end_unit

