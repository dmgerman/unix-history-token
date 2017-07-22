begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugLoc.h - Debug Location Information ------------------*- C++ -*-===//
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
comment|// This file defines a number of light weight data structures used
end_comment

begin_comment
comment|// to describe and track debug location information.
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
name|LLVM_IR_DEBUGLOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DEBUGLOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/TrackingMDRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLVMContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DILocation
decl_stmt|;
comment|/// \brief A debug info location.
comment|///
comment|/// This class is a wrapper around a tracking reference to an \a DILocation
comment|/// pointer.
comment|///
comment|/// To avoid extra includes, \a DebugLoc doubles the \a DILocation API with a
comment|/// one based on relatively opaque \a MDNode pointers.
name|class
name|DebugLoc
block|{
name|TrackingMDNodeRef
name|Loc
decl_stmt|;
name|public
label|:
name|DebugLoc
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief Construct from an \a DILocation.
name|DebugLoc
argument_list|(
specifier|const
name|DILocation
operator|*
name|L
argument_list|)
expr_stmt|;
comment|/// \brief Construct from an \a MDNode.
comment|///
comment|/// Note: if \c N is not an \a DILocation, a verifier check will fail, and
comment|/// accessors will crash.  However, construction from other nodes is
comment|/// supported in order to handle forward references when reading textual
comment|/// IR.
name|explicit
name|DebugLoc
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// \brief Get the underlying \a DILocation.
comment|///
comment|/// \pre !*this or \c isa<DILocation>(getAsMDNode()).
comment|/// @{
name|DILocation
operator|*
name|get
argument_list|()
specifier|const
expr_stmt|;
name|operator
name|DILocation
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
name|DILocation
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
name|DILocation
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|get
argument_list|()
return|;
block|}
comment|/// @}
comment|/// \brief Check for null.
comment|///
comment|/// Check for null in a way that is safe with broken debug info.  Unlike
comment|/// the conversion to \c DILocation, this doesn't require that \c Loc is of
comment|/// the right type.  Important for cases like \a llvm::StripDebugInfo() and
comment|/// \a Instruction::hasMetadata().
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Check whether this has a trivial destructor.
name|bool
name|hasTrivialDestructor
argument_list|()
specifier|const
block|{
return|return
name|Loc
operator|.
name|hasTrivialDestructor
argument_list|()
return|;
block|}
comment|/// \brief Create a new DebugLoc.
comment|///
comment|/// Create a new DebugLoc at the specified line/col and scope/inline.  This
comment|/// forwards to \a DILocation::get().
comment|///
comment|/// If \c !Scope, returns a default-constructed \a DebugLoc.
comment|///
comment|/// FIXME: Remove this.  Users should use DILocation::get().
specifier|static
name|DebugLoc
name|get
parameter_list|(
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Col
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Scope
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|InlinedAt
init|=
name|nullptr
parameter_list|)
function_decl|;
enum|enum
block|{
name|ReplaceLastInlinedAt
init|=
name|true
block|}
enum|;
comment|/// Rebuild the entire inlined-at chain for this instruction so that the top of
comment|/// the chain now is inlined-at the new call site.
comment|/// \param   InlinedAt    The new outermost inlined-at in the chain.
comment|/// \param   ReplaceLast  Replace the last location in the inlined-at chain.
specifier|static
name|DebugLoc
name|appendInlinedAt
argument_list|(
name|DebugLoc
name|DL
argument_list|,
name|DILocation
operator|*
name|InlinedAt
argument_list|,
name|LLVMContext
operator|&
name|Ctx
argument_list|,
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
argument_list|,
name|MDNode
operator|*
operator|>
operator|&
name|Cache
argument_list|,
name|bool
name|ReplaceLast
operator|=
name|false
argument_list|)
decl_stmt|;
name|unsigned
name|getLine
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getCol
argument_list|()
specifier|const
expr_stmt|;
name|MDNode
operator|*
name|getScope
argument_list|()
specifier|const
expr_stmt|;
name|DILocation
operator|*
name|getInlinedAt
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Get the fully inlined-at scope for a DebugLoc.
comment|///
comment|/// Gets the inlined-at scope for a DebugLoc.
name|MDNode
operator|*
name|getInlinedAtScope
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Find the debug info location for the start of the function.
comment|///
comment|/// Walk up the scope chain of given debug loc and find line number info
comment|/// for the function.
comment|///
comment|/// FIXME: Remove this.  Users should use DILocation/DILocalScope API to
comment|/// find the subprogram, and then DILocation::get().
name|DebugLoc
name|getFnDebugLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Return \c this as a bar \a MDNode.
name|MDNode
operator|*
name|getAsMDNode
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DebugLoc
operator|&
name|DL
operator|)
specifier|const
block|{
return|return
name|Loc
operator|==
name|DL
operator|.
name|Loc
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|DebugLoc
operator|&
name|DL
operator|)
specifier|const
block|{
return|return
name|Loc
operator|!=
name|DL
operator|.
name|Loc
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief prints source location /path/to/file.exe:line:col @[inlined at]
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_SUPPORT_DEBUGLOC_H */
end_comment

end_unit

