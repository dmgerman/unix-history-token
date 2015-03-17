begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- UnwrappedLineFormatter.h - Format C++ code -------------*- C++ -*-===//
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
comment|/// \brief Implements a combinartorial exploration of all the different
end_comment

begin_comment
comment|/// linebreaks unwrapped lines can be formatted in.
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
name|LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEFORMATTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEFORMATTER_H
end_define

begin_include
include|#
directive|include
file|"ContinuationIndenter.h"
end_include

begin_include
include|#
directive|include
file|"clang/Format/Format.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<queue>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
name|class
name|ContinuationIndenter
decl_stmt|;
name|class
name|WhitespaceManager
decl_stmt|;
name|class
name|UnwrappedLineFormatter
block|{
name|public
label|:
name|UnwrappedLineFormatter
argument_list|(
name|ContinuationIndenter
operator|*
name|Indenter
argument_list|,
name|WhitespaceManager
operator|*
name|Whitespaces
argument_list|,
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|)
operator|:
name|Indenter
argument_list|(
name|Indenter
argument_list|)
operator|,
name|Whitespaces
argument_list|(
name|Whitespaces
argument_list|)
operator|,
name|Style
argument_list|(
argument|Style
argument_list|)
block|{}
name|unsigned
name|format
argument_list|(
argument|const SmallVectorImpl<AnnotatedLine *>&Lines
argument_list|,
argument|bool DryRun
argument_list|,
argument|int AdditionalIndent =
literal|0
argument_list|,
argument|bool FixBadIndentation = false
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// \brief Formats an \c AnnotatedLine and returns the penalty.
comment|///
comment|/// If \p DryRun is \c false, directly applies the changes.
name|unsigned
name|format
parameter_list|(
specifier|const
name|AnnotatedLine
modifier|&
name|Line
parameter_list|,
name|unsigned
name|FirstIndent
parameter_list|,
name|bool
name|DryRun
parameter_list|)
function_decl|;
comment|/// \brief An edge in the solution space from \c Previous->State to \c State,
comment|/// inserting a newline dependent on the \c NewLine.
struct|struct
name|StateNode
block|{
name|StateNode
argument_list|(
argument|const LineState&State
argument_list|,
argument|bool NewLine
argument_list|,
argument|StateNode *Previous
argument_list|)
block|:
name|State
argument_list|(
name|State
argument_list|)
operator|,
name|NewLine
argument_list|(
name|NewLine
argument_list|)
operator|,
name|Previous
argument_list|(
argument|Previous
argument_list|)
block|{}
name|LineState
name|State
expr_stmt|;
name|bool
name|NewLine
decl_stmt|;
name|StateNode
modifier|*
name|Previous
decl_stmt|;
block|}
struct|;
comment|/// \brief A pair of<penalty, count> that is used to prioritize the BFS on.
comment|///
comment|/// In case of equal penalties, we want to prefer states that were inserted
comment|/// first. During state generation we make sure that we insert states first
comment|/// that break the line as late as possible.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|OrderedPenalty
expr_stmt|;
comment|/// \brief An item in the prioritized BFS search queue. The \c StateNode's
comment|/// \c State has the given \c OrderedPenalty.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|OrderedPenalty
operator|,
name|StateNode
operator|*
operator|>
name|QueueItem
expr_stmt|;
comment|/// \brief The BFS queue type.
typedef|typedef
name|std
operator|::
name|priority_queue
operator|<
name|QueueItem
operator|,
name|std
operator|::
name|vector
operator|<
name|QueueItem
operator|>
operator|,
name|std
operator|::
name|greater
operator|<
name|QueueItem
operator|>
expr|>
name|QueueType
expr_stmt|;
comment|/// \brief Get the offset of the line relatively to the level.
comment|///
comment|/// For example, 'public:' labels in classes are offset by 1 or 2
comment|/// characters to the left from their level.
name|int
name|getIndentOffset
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|RootToken
parameter_list|)
block|{
if|if
condition|(
name|Style
operator|.
name|Language
operator|==
name|FormatStyle
operator|::
name|LK_Java
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|RootToken
operator|.
name|isAccessSpecifier
argument_list|(
name|false
argument_list|)
operator|||
name|RootToken
operator|.
name|isObjCAccessSpecifier
argument_list|()
condition|)
return|return
name|Style
operator|.
name|AccessModifierOffset
return|;
return|return
literal|0
return|;
block|}
comment|/// \brief Add a new line and the required indent before the first Token
comment|/// of the \c UnwrappedLine if there was no structural parsing error.
name|void
name|formatFirstToken
parameter_list|(
name|FormatToken
modifier|&
name|RootToken
parameter_list|,
specifier|const
name|AnnotatedLine
modifier|*
name|PreviousLine
parameter_list|,
name|unsigned
name|IndentLevel
parameter_list|,
name|unsigned
name|Indent
parameter_list|,
name|bool
name|InPPDirective
parameter_list|)
function_decl|;
comment|/// \brief Get the indent of \p Level from \p IndentForLevel.
comment|///
comment|/// \p IndentForLevel must contain the indent for the level \c l
comment|/// at \p IndentForLevel[l], or a value< 0 if the indent for
comment|/// that level is unknown.
name|unsigned
name|getIndent
argument_list|(
name|ArrayRef
operator|<
name|int
operator|>
name|IndentForLevel
argument_list|,
name|unsigned
name|Level
argument_list|)
decl_stmt|;
name|void
name|join
parameter_list|(
name|AnnotatedLine
modifier|&
name|A
parameter_list|,
specifier|const
name|AnnotatedLine
modifier|&
name|B
parameter_list|)
function_decl|;
name|unsigned
name|getColumnLimit
argument_list|(
name|bool
name|InPPDirective
argument_list|)
decl|const
block|{
comment|// In preprocessor directives reserve two chars for trailing " \"
return|return
name|Style
operator|.
name|ColumnLimit
operator|-
operator|(
name|InPPDirective
condition|?
literal|2
else|:
literal|0
operator|)
return|;
block|}
struct|struct
name|CompareLineStatePointers
block|{
name|bool
name|operator
argument_list|()
operator|(
name|LineState
operator|*
name|obj1
operator|,
name|LineState
operator|*
name|obj2
operator|)
specifier|const
block|{
return|return
operator|*
name|obj1
operator|<
operator|*
name|obj2
return|;
block|}
block|}
struct|;
comment|/// \brief Analyze the entire solution space starting from \p InitialState.
comment|///
comment|/// This implements a variant of Dijkstra's algorithm on the graph that spans
comment|/// the solution space (\c LineStates are the nodes). The algorithm tries to
comment|/// find the shortest path (the one with lowest penalty) from \p InitialState
comment|/// to a state where all tokens are placed. Returns the penalty.
comment|///
comment|/// If \p DryRun is \c false, directly applies the changes.
name|unsigned
name|analyzeSolutionSpace
parameter_list|(
name|LineState
modifier|&
name|InitialState
parameter_list|,
name|bool
name|DryRun
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|reconstructPath
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|StateNode
modifier|*
name|Current
parameter_list|)
function_decl|;
comment|/// \brief Add the following state to the analysis queue \c Queue.
comment|///
comment|/// Assume the current state is \p PreviousNode and has been reached with a
comment|/// penalty of \p Penalty. Insert a line break if \p NewLine is \c true.
name|void
name|addNextStateToQueue
parameter_list|(
name|unsigned
name|Penalty
parameter_list|,
name|StateNode
modifier|*
name|PreviousNode
parameter_list|,
name|bool
name|NewLine
parameter_list|,
name|unsigned
modifier|*
name|Count
parameter_list|,
name|QueueType
modifier|*
name|Queue
parameter_list|)
function_decl|;
comment|/// \brief If the \p State's next token is an r_brace closing a nested block,
comment|/// format the nested block before it.
comment|///
comment|/// Returns \c true if all children could be placed successfully and adapts
comment|/// \p Penalty as well as \p State. If \p DryRun is false, also directly
comment|/// creates changes using \c Whitespaces.
comment|///
comment|/// The crucial idea here is that children always get formatted upon
comment|/// encountering the closing brace right after the nested block. Now, if we
comment|/// are currently trying to keep the "}" on the same line (i.e. \p NewLine is
comment|/// \c false), the entire block has to be kept on the same line (which is only
comment|/// possible if it fits on the line, only contains a single statement, etc.
comment|///
comment|/// If \p NewLine is true, we format the nested block on separate lines, i.e.
comment|/// break after the "{", format all lines with correct indentation and the put
comment|/// the closing "}" on yet another new line.
comment|///
comment|/// This enables us to keep the simple structure of the
comment|/// \c UnwrappedLineFormatter, where we only have two options for each token:
comment|/// break or don't break.
name|bool
name|formatChildren
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|NewLine
parameter_list|,
name|bool
name|DryRun
parameter_list|,
name|unsigned
modifier|&
name|Penalty
parameter_list|)
function_decl|;
name|ContinuationIndenter
modifier|*
name|Indenter
decl_stmt|;
name|WhitespaceManager
modifier|*
name|Whitespaces
decl_stmt|;
name|FormatStyle
name|Style
decl_stmt|;
name|llvm
operator|::
name|SpecificBumpPtrAllocator
operator|<
name|StateNode
operator|>
name|Allocator
expr_stmt|;
comment|// Cache to store the penalty of formatting a vector of AnnotatedLines
comment|// starting from a specific additional offset. Improves performance if there
comment|// are many nested blocks.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|SmallVectorImpl
operator|<
name|AnnotatedLine
operator|*
operator|>
operator|*
operator|,
name|unsigned
operator|>
operator|,
name|unsigned
operator|>
name|PenaltyCache
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace format
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
comment|// LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEFORMATTER_H
end_comment

end_unit

