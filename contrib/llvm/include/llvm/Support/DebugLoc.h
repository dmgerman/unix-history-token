begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/Support/DebugLoc.h - Debug Location Information --*- C++ -*-===//
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
name|LLVM_SUPPORT_DEBUGLOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_DEBUGLOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
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
expr|struct
name|DenseMapInfo
expr_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// DebugLoc - Debug location id.  This is carried by Instruction, SDNode,
comment|/// and MachineInstr to compactly encode file/line/scope information for an
comment|/// operation.
name|class
name|DebugLoc
block|{
name|friend
block|struct
name|DenseMapInfo
operator|<
name|DebugLoc
operator|>
expr_stmt|;
comment|/// getEmptyKey() - A private constructor that returns an unknown that is
comment|/// not equal to the tombstone key or DebugLoc().
specifier|static
name|DebugLoc
name|getEmptyKey
parameter_list|()
block|{
name|DebugLoc
name|DL
decl_stmt|;
name|DL
operator|.
name|LineCol
operator|=
literal|1
expr_stmt|;
return|return
name|DL
return|;
block|}
comment|/// getTombstoneKey() - A private constructor that returns an unknown that
comment|/// is not equal to the empty key or DebugLoc().
specifier|static
name|DebugLoc
name|getTombstoneKey
parameter_list|()
block|{
name|DebugLoc
name|DL
decl_stmt|;
name|DL
operator|.
name|LineCol
operator|=
literal|2
expr_stmt|;
return|return
name|DL
return|;
block|}
comment|/// LineCol - This 32-bit value encodes the line and column number for the
comment|/// location, encoded as 24-bits for line and 8 bits for col.  A value of 0
comment|/// for either means unknown.
name|uint32_t
name|LineCol
decl_stmt|;
comment|/// ScopeIdx - This is an opaque ID# for Scope/InlinedAt information,
comment|/// decoded by LLVMContext.  0 is unknown.
name|int
name|ScopeIdx
decl_stmt|;
name|public
label|:
name|DebugLoc
argument_list|()
operator|:
name|LineCol
argument_list|(
literal|0
argument_list|)
operator|,
name|ScopeIdx
argument_list|(
literal|0
argument_list|)
block|{}
comment|// Defaults to unknown.
comment|/// get - Get a new DebugLoc that corresponds to the specified line/col
comment|/// scope/inline location.
specifier|static
name|DebugLoc
name|get
argument_list|(
argument|unsigned Line
argument_list|,
argument|unsigned Col
argument_list|,
argument|MDNode *Scope
argument_list|,
argument|MDNode *InlinedAt =
literal|0
argument_list|)
expr_stmt|;
comment|/// getFromDILocation - Translate the DILocation quad into a DebugLoc.
specifier|static
name|DebugLoc
name|getFromDILocation
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// getFromDILexicalBlock - Translate the DILexicalBlock into a DebugLoc.
specifier|static
name|DebugLoc
name|getFromDILexicalBlock
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// isUnknown - Return true if this is an unknown location.
name|bool
name|isUnknown
argument_list|()
specifier|const
block|{
return|return
name|ScopeIdx
operator|==
literal|0
return|;
block|}
name|unsigned
name|getLine
argument_list|()
specifier|const
block|{
return|return
operator|(
name|LineCol
operator|<<
literal|8
operator|)
operator|>>
literal|8
return|;
comment|// Mask out column.
block|}
name|unsigned
name|getCol
argument_list|()
specifier|const
block|{
return|return
name|LineCol
operator|>>
literal|24
return|;
block|}
comment|/// getScope - This returns the scope pointer for this DebugLoc, or null if
comment|/// invalid.
name|MDNode
modifier|*
name|getScope
argument_list|(
specifier|const
name|LLVMContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// getInlinedAt - This returns the InlinedAt pointer for this DebugLoc, or
comment|/// null if invalid or not present.
name|MDNode
modifier|*
name|getInlinedAt
argument_list|(
specifier|const
name|LLVMContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// getScopeAndInlinedAt - Return both the Scope and the InlinedAt values.
name|void
name|getScopeAndInlinedAt
argument_list|(
name|MDNode
operator|*
operator|&
name|Scope
argument_list|,
name|MDNode
operator|*
operator|&
name|IA
argument_list|,
specifier|const
name|LLVMContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
comment|/// getAsMDNode - This method converts the compressed DebugLoc node into a
comment|/// DILocation compatible MDNode.
name|MDNode
modifier|*
name|getAsMDNode
argument_list|(
specifier|const
name|LLVMContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
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
name|LineCol
operator|==
name|DL
operator|.
name|LineCol
operator|&&
name|ScopeIdx
operator|==
name|DL
operator|.
name|ScopeIdx
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
name|void
name|dump
argument_list|(
specifier|const
name|LLVMContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|DebugLoc
operator|>
block|{
specifier|static
name|DebugLoc
name|getEmptyKey
argument_list|()
block|{
return|return
name|DebugLoc
operator|::
name|getEmptyKey
argument_list|()
return|;
block|}
specifier|static
name|DebugLoc
name|getTombstoneKey
argument_list|()
block|{
return|return
name|DebugLoc
operator|::
name|getTombstoneKey
argument_list|()
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
specifier|const
name|DebugLoc
operator|&
name|Key
argument_list|)
block|;
specifier|static
name|bool
name|isEqual
argument_list|(
argument|DebugLoc LHS
argument_list|,
argument|DebugLoc RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_comment
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

