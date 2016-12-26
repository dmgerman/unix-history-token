begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AffectedRangeManager.h - Format C++ code ---------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief AffectedRangeManager class manages affected ranges in the code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LIB_FORMAT_AFFECTEDRANGEMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_AFFECTEDRANGEMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
struct_decl|struct
name|FormatToken
struct_decl|;
name|class
name|AnnotatedLine
decl_stmt|;
name|class
name|AffectedRangeManager
block|{
name|public
label|:
name|AffectedRangeManager
argument_list|(
specifier|const
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
specifier|const
name|ArrayRef
operator|<
name|CharSourceRange
operator|>
name|Ranges
argument_list|)
operator|:
name|SourceMgr
argument_list|(
name|SourceMgr
argument_list|)
operator|,
name|Ranges
argument_list|(
argument|Ranges.begin()
argument_list|,
argument|Ranges.end()
argument_list|)
block|{}
comment|// Determines which lines are affected by the SourceRanges given as input.
comment|// Returns \c true if at least one line between I and E or one of their
comment|// children is affected.
name|bool
name|computeAffectedLines
argument_list|(
argument|SmallVectorImpl<AnnotatedLine *>::iterator I
argument_list|,
argument|SmallVectorImpl<AnnotatedLine *>::iterator E
argument_list|)
expr_stmt|;
comment|// Returns true if 'Range' intersects with one of the input ranges.
name|bool
name|affectsCharSourceRange
parameter_list|(
specifier|const
name|CharSourceRange
modifier|&
name|Range
parameter_list|)
function_decl|;
name|private
label|:
comment|// Returns true if the range from 'First' to 'Last' intersects with one of the
comment|// input ranges.
name|bool
name|affectsTokenRange
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|First
parameter_list|,
specifier|const
name|FormatToken
modifier|&
name|Last
parameter_list|,
name|bool
name|IncludeLeadingNewlines
parameter_list|)
function_decl|;
comment|// Returns true if one of the input ranges intersect the leading empty lines
comment|// before 'Tok'.
name|bool
name|affectsLeadingEmptyLines
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// Marks all lines between I and E as well as all their children as affected.
name|void
name|markAllAsAffected
argument_list|(
name|SmallVectorImpl
operator|<
name|AnnotatedLine
operator|*
operator|>
operator|::
name|iterator
name|I
argument_list|,
name|SmallVectorImpl
operator|<
name|AnnotatedLine
operator|*
operator|>
operator|::
name|iterator
name|E
argument_list|)
decl_stmt|;
comment|// Determines whether 'Line' is affected by the SourceRanges given as input.
comment|// Returns \c true if line or one if its children is affected.
name|bool
name|nonPPLineAffected
parameter_list|(
name|AnnotatedLine
modifier|*
name|Line
parameter_list|,
specifier|const
name|AnnotatedLine
modifier|*
name|PreviousLine
parameter_list|)
function_decl|;
specifier|const
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
specifier|const
name|SmallVector
operator|<
name|CharSourceRange
operator|,
literal|8
operator|>
name|Ranges
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace format
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LIB_FORMAT_AFFECTEDRANGEMANAGER_H
end_comment

end_unit

