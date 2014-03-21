begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PPConditionalDirectiveRecord.h - Preprocessing Directives-*- C++ -*-=//
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
comment|//  This file defines the PPConditionalDirectiveRecord class, which maintains
end_comment

begin_comment
comment|//  a record of conditional directive regions.
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
name|LLVM_CLANG_LEX_PPCONDITIONALDIRECTIVERECORD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PPCONDITIONALDIRECTIVERECORD_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PPCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Records preprocessor conditional directive regions and allows
comment|/// querying in which region source locations belong to.
name|class
name|PPConditionalDirectiveRecord
range|:
name|public
name|PPCallbacks
block|{
name|SourceManager
operator|&
name|SourceMgr
block|;
name|SmallVector
operator|<
name|SourceLocation
block|,
literal|6
operator|>
name|CondDirectiveStack
block|;
name|class
name|CondDirectiveLoc
block|{
name|SourceLocation
name|Loc
block|;
name|SourceLocation
name|RegionLoc
block|;
name|public
operator|:
name|CondDirectiveLoc
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation RegionLoc
argument_list|)
operator|:
name|Loc
argument_list|(
name|Loc
argument_list|)
block|,
name|RegionLoc
argument_list|(
argument|RegionLoc
argument_list|)
block|{}
name|SourceLocation
name|getLoc
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|SourceLocation
name|getRegionLoc
argument_list|()
specifier|const
block|{
return|return
name|RegionLoc
return|;
block|}
name|class
name|Comp
block|{
name|SourceManager
operator|&
name|SM
block|;
name|public
operator|:
name|explicit
name|Comp
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
operator|:
name|SM
argument_list|(
argument|SM
argument_list|)
block|{}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|CondDirectiveLoc
operator|&
name|LHS
expr|,
specifier|const
name|CondDirectiveLoc
operator|&
name|RHS
operator|)
block|{
return|return
name|SM
operator|.
name|isBeforeInTranslationUnit
argument_list|(
name|LHS
operator|.
name|getLoc
argument_list|()
argument_list|,
name|RHS
operator|.
name|getLoc
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|CondDirectiveLoc
operator|&
name|LHS
expr|,
name|SourceLocation
name|RHS
operator|)
block|{
return|return
name|SM
operator|.
name|isBeforeInTranslationUnit
argument_list|(
name|LHS
operator|.
name|getLoc
argument_list|()
argument_list|,
name|RHS
argument_list|)
return|;
block|}
name|bool
name|operator
argument_list|()
operator|(
name|SourceLocation
name|LHS
expr|,
specifier|const
name|CondDirectiveLoc
operator|&
name|RHS
operator|)
block|{
return|return
name|SM
operator|.
name|isBeforeInTranslationUnit
argument_list|(
name|LHS
argument_list|,
name|RHS
operator|.
name|getLoc
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;   }
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CondDirectiveLoc
operator|>
name|CondDirectiveLocsTy
expr_stmt|;
comment|/// \brief The locations of conditional directives in source order.
name|CondDirectiveLocsTy
name|CondDirectiveLocs
block|;
name|void
name|addCondDirectiveLoc
argument_list|(
argument|CondDirectiveLoc DirLoc
argument_list|)
block|;
name|public
operator|:
comment|/// \brief Construct a new preprocessing record.
name|explicit
name|PPConditionalDirectiveRecord
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
block|;
name|size_t
name|getTotalMemory
argument_list|()
specifier|const
block|;
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
return|;
block|}
comment|/// \brief Returns true if the given range intersects with a conditional
comment|/// directive. if a \#if/\#endif block is fully contained within the range,
comment|/// this function will return false.
name|bool
name|rangeIntersectsConditionalDirective
argument_list|(
argument|SourceRange Range
argument_list|)
specifier|const
block|;
comment|/// \brief Returns true if the given locations are in different regions,
comment|/// separated by conditional directive blocks.
name|bool
name|areInDifferentConditionalDirectiveRegion
argument_list|(
argument|SourceLocation LHS
argument_list|,
argument|SourceLocation RHS
argument_list|)
specifier|const
block|{
return|return
name|findConditionalDirectiveRegionLoc
argument_list|(
name|LHS
argument_list|)
operator|!=
name|findConditionalDirectiveRegionLoc
argument_list|(
name|RHS
argument_list|)
return|;
block|}
name|SourceLocation
name|findConditionalDirectiveRegionLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
specifier|const
block|;
name|private
operator|:
name|virtual
name|void
name|If
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceRange ConditionRange
argument_list|,
argument|bool ConditionValue
argument_list|)
block|;
name|virtual
name|void
name|Elif
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceRange ConditionRange
argument_list|,
argument|bool ConditionValue
argument_list|,
argument|SourceLocation IfLoc
argument_list|)
block|;
name|virtual
name|void
name|Ifdef
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDirective *MD
argument_list|)
block|;
name|virtual
name|void
name|Ifndef
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDirective *MD
argument_list|)
block|;
name|virtual
name|void
name|Else
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation IfLoc
argument_list|)
block|;
name|virtual
name|void
name|Endif
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation IfLoc
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LEX_PPCONDITIONALDIRECTIVERECORD_H
end_comment

end_unit

