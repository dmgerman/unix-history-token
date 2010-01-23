begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/DebugLoc.h - Debug Location Information ----------*- C++ -*-===//
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
name|LLVM_DEBUGLOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGLOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MDNode
decl_stmt|;
comment|/// DebugLoc - Debug location id. This is carried by SDNode and MachineInstr
comment|/// to index into a vector of unique debug location tuples.
name|class
name|DebugLoc
block|{
name|unsigned
name|Idx
decl_stmt|;
name|public
label|:
name|DebugLoc
argument_list|()
operator|:
name|Idx
argument_list|(
argument|~
literal|0U
argument_list|)
block|{}
comment|// Defaults to invalid.
specifier|static
name|DebugLoc
name|getUnknownLoc
argument_list|()
block|{
name|DebugLoc
name|L
block|;
name|L
operator|.
name|Idx
operator|=
operator|~
literal|0U
block|;
return|return
name|L
return|;
block|}
specifier|static
name|DebugLoc
name|get
parameter_list|(
name|unsigned
name|idx
parameter_list|)
block|{
name|DebugLoc
name|L
decl_stmt|;
name|L
operator|.
name|Idx
operator|=
name|idx
expr_stmt|;
return|return
name|L
return|;
block|}
name|unsigned
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Idx
return|;
block|}
comment|/// isUnknown - Return true if there is no debug info for the SDNode /
comment|/// MachineInstr.
name|bool
name|isUnknown
argument_list|()
specifier|const
block|{
return|return
name|Idx
operator|==
operator|~
literal|0U
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
name|Idx
operator|==
name|DL
operator|.
name|Idx
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
operator|!
operator|(
operator|*
name|this
operator|==
name|DL
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// DebugLocTracker - This class tracks debug location information.
comment|///
struct|struct
name|DebugLocTracker
block|{
comment|/// DebugLocations - A vector of unique DebugLocTuple's.
comment|///
name|std
operator|::
name|vector
operator|<
name|MDNode
operator|*
operator|>
name|DebugLocations
expr_stmt|;
comment|/// DebugIdMap - This maps DebugLocTuple's to indices into the
comment|/// DebugLocations vector.
name|DenseMap
operator|<
name|MDNode
operator|*
operator|,
name|unsigned
operator|>
name|DebugIdMap
expr_stmt|;
name|DebugLocTracker
argument_list|()
block|{}
block|}
struct|;
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
comment|/* LLVM_DEBUGLOC_H */
end_comment

end_unit

