begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ContinuationIndenter.h - Format C++ code ---------------*- C++ -*-===//
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
comment|/// \brief This file implements an indenter that manages the indentation of
end_comment

begin_comment
comment|/// continuations.
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
name|LLVM_CLANG_LIB_FORMAT_CONTINUATIONINDENTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_CONTINUATIONINDENTER_H
end_define

begin_include
include|#
directive|include
file|"Encoding.h"
end_include

begin_include
include|#
directive|include
file|"FormatToken.h"
end_include

begin_include
include|#
directive|include
file|"clang/Format/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Regex.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SourceManager
decl_stmt|;
name|namespace
name|format
block|{
name|class
name|AnnotatedLine
decl_stmt|;
struct_decl|struct
name|FormatToken
struct_decl|;
struct_decl|struct
name|LineState
struct_decl|;
struct_decl|struct
name|ParenState
struct_decl|;
name|class
name|WhitespaceManager
decl_stmt|;
name|class
name|ContinuationIndenter
block|{
name|public
label|:
comment|/// \brief Constructs a \c ContinuationIndenter to format \p Line starting in
comment|/// column \p FirstIndent.
name|ContinuationIndenter
argument_list|(
argument|const FormatStyle&Style
argument_list|,
argument|const AdditionalKeywords&Keywords
argument_list|,
argument|const SourceManager&SourceMgr
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|,
argument|encoding::Encoding Encoding
argument_list|,
argument|bool BinPackInconclusiveFunctions
argument_list|)
empty_stmt|;
comment|/// \brief Get the initial state, i.e. the state after placing \p Line's
comment|/// first token at \p FirstIndent.
name|LineState
name|getInitialState
parameter_list|(
name|unsigned
name|FirstIndent
parameter_list|,
specifier|const
name|AnnotatedLine
modifier|*
name|Line
parameter_list|,
name|bool
name|DryRun
parameter_list|)
function_decl|;
comment|// FIXME: canBreak and mustBreak aren't strictly indentation-related. Find a
comment|// better home.
comment|/// \brief Returns \c true, if a line break after \p State is allowed.
name|bool
name|canBreak
parameter_list|(
specifier|const
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
comment|/// \brief Returns \c true, if a line break after \p State is mandatory.
name|bool
name|mustBreak
parameter_list|(
specifier|const
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
comment|/// \brief Appends the next token to \p State and updates information
comment|/// necessary for indentation.
comment|///
comment|/// Puts the token on the current line if \p Newline is \c false and adds a
comment|/// line break and necessary indentation otherwise.
comment|///
comment|/// If \p DryRun is \c false, also creates and stores the required
comment|/// \c Replacement.
name|unsigned
name|addTokenToState
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|Newline
parameter_list|,
name|bool
name|DryRun
parameter_list|,
name|unsigned
name|ExtraSpaces
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Get the column limit for this line. This is the style's column
comment|/// limit, potentially reduced for preprocessor definitions.
name|unsigned
name|getColumnLimit
argument_list|(
specifier|const
name|LineState
operator|&
name|State
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// \brief Mark the next token as consumed in \p State and modify its stacks
comment|/// accordingly.
name|unsigned
name|moveStateToNextToken
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|DryRun
parameter_list|,
name|bool
name|Newline
parameter_list|)
function_decl|;
comment|/// \brief Update 'State' according to the next token's fake left parentheses.
name|void
name|moveStatePastFakeLParens
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|Newline
parameter_list|)
function_decl|;
comment|/// \brief Update 'State' according to the next token's fake r_parens.
name|void
name|moveStatePastFakeRParens
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
comment|/// \brief Update 'State' according to the next token being one of "(<{[".
name|void
name|moveStatePastScopeOpener
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|Newline
parameter_list|)
function_decl|;
comment|/// \brief Update 'State' according to the next token being one of ")>}]".
name|void
name|moveStatePastScopeCloser
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
comment|/// \brief Update 'State' with the next token opening a nested block.
name|void
name|moveStateToNewBlock
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
comment|/// \brief If the current token sticks out over the end of the line, break
comment|/// it if possible.
comment|///
comment|/// \returns An extra penalty if a token was broken, otherwise 0.
comment|///
comment|/// The returned penalty will cover the cost of the additional line breaks and
comment|/// column limit violation in all lines except for the last one. The penalty
comment|/// for the column limit violation in the last line (and in single line
comment|/// tokens) is handled in \c addNextStateToQueue.
name|unsigned
name|breakProtrudingToken
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|Current
parameter_list|,
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|DryRun
parameter_list|)
function_decl|;
comment|/// \brief Appends the next token to \p State and updates information
comment|/// necessary for indentation.
comment|///
comment|/// Puts the token on the current line.
comment|///
comment|/// If \p DryRun is \c false, also creates and stores the required
comment|/// \c Replacement.
name|void
name|addTokenOnCurrentLine
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|DryRun
parameter_list|,
name|unsigned
name|ExtraSpaces
parameter_list|)
function_decl|;
comment|/// \brief Appends the next token to \p State and updates information
comment|/// necessary for indentation.
comment|///
comment|/// Adds a line break and necessary indentation.
comment|///
comment|/// If \p DryRun is \c false, also creates and stores the required
comment|/// \c Replacement.
name|unsigned
name|addTokenOnNewLine
parameter_list|(
name|LineState
modifier|&
name|State
parameter_list|,
name|bool
name|DryRun
parameter_list|)
function_decl|;
comment|/// \brief Calculate the new column for a line wrap before the next token.
name|unsigned
name|getNewLineColumn
parameter_list|(
specifier|const
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
comment|/// \brief Adds a multiline token to the \p State.
comment|///
comment|/// \returns Extra penalty for the first line of the literal: last line is
comment|/// handled in \c addNextStateToQueue, and the penalty for other lines doesn't
comment|/// matter, as we don't change them.
name|unsigned
name|addMultilineToken
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|Current
parameter_list|,
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
comment|/// \brief Returns \c true if the next token starts a multiline string
comment|/// literal.
comment|///
comment|/// This includes implicitly concatenated strings, strings that will be broken
comment|/// by clang-format and string literals with escaped newlines.
name|bool
name|nextIsMultilineString
parameter_list|(
specifier|const
name|LineState
modifier|&
name|State
parameter_list|)
function_decl|;
name|FormatStyle
name|Style
decl_stmt|;
specifier|const
name|AdditionalKeywords
modifier|&
name|Keywords
decl_stmt|;
specifier|const
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|WhitespaceManager
modifier|&
name|Whitespaces
decl_stmt|;
name|encoding
operator|::
name|Encoding
name|Encoding
expr_stmt|;
name|bool
name|BinPackInconclusiveFunctions
decl_stmt|;
name|llvm
operator|::
name|Regex
name|CommentPragmasRegex
expr_stmt|;
block|}
empty_stmt|;
struct|struct
name|ParenState
block|{
name|ParenState
argument_list|(
argument|unsigned Indent
argument_list|,
argument|unsigned LastSpace
argument_list|,
argument|bool AvoidBinPacking
argument_list|,
argument|bool NoLineBreak
argument_list|)
block|:
name|Indent
argument_list|(
name|Indent
argument_list|)
operator|,
name|LastSpace
argument_list|(
name|LastSpace
argument_list|)
operator|,
name|NestedBlockIndent
argument_list|(
name|Indent
argument_list|)
operator|,
name|BreakBeforeClosingBrace
argument_list|(
name|false
argument_list|)
operator|,
name|AvoidBinPacking
argument_list|(
name|AvoidBinPacking
argument_list|)
operator|,
name|BreakBeforeParameter
argument_list|(
name|false
argument_list|)
operator|,
name|NoLineBreak
argument_list|(
name|NoLineBreak
argument_list|)
operator|,
name|NoLineBreakInOperand
argument_list|(
name|false
argument_list|)
operator|,
name|LastOperatorWrapped
argument_list|(
name|true
argument_list|)
operator|,
name|ContainsLineBreak
argument_list|(
name|false
argument_list|)
operator|,
name|ContainsUnwrappedBuilder
argument_list|(
name|false
argument_list|)
operator|,
name|AlignColons
argument_list|(
name|true
argument_list|)
operator|,
name|ObjCSelectorNameFound
argument_list|(
name|false
argument_list|)
operator|,
name|HasMultipleNestedBlocks
argument_list|(
name|false
argument_list|)
operator|,
name|NestedBlockInlined
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief The position to which a specific parenthesis level needs to be
comment|/// indented.
name|unsigned
name|Indent
expr_stmt|;
comment|/// \brief The position of the last space on each level.
comment|///
comment|/// Used e.g. to break like:
comment|/// functionCall(Parameter, otherCall(
comment|///                             OtherParameter));
name|unsigned
name|LastSpace
decl_stmt|;
comment|/// \brief If a block relative to this parenthesis level gets wrapped, indent
comment|/// it this much.
name|unsigned
name|NestedBlockIndent
decl_stmt|;
comment|/// \brief The position the first "<<" operator encountered on each level.
comment|///
comment|/// Used to align "<<" operators. 0 if no such operator has been encountered
comment|/// on a level.
name|unsigned
name|FirstLessLess
init|=
literal|0
decl_stmt|;
comment|/// \brief The column of a \c ? in a conditional expression;
name|unsigned
name|QuestionColumn
init|=
literal|0
decl_stmt|;
comment|/// \brief The position of the colon in an ObjC method declaration/call.
name|unsigned
name|ColonPos
init|=
literal|0
decl_stmt|;
comment|/// \brief The start of the most recent function in a builder-type call.
name|unsigned
name|StartOfFunctionCall
init|=
literal|0
decl_stmt|;
comment|/// \brief Contains the start of array subscript expressions, so that they
comment|/// can be aligned.
name|unsigned
name|StartOfArraySubscripts
init|=
literal|0
decl_stmt|;
comment|/// \brief If a nested name specifier was broken over multiple lines, this
comment|/// contains the start column of the second line. Otherwise 0.
name|unsigned
name|NestedNameSpecifierContinuation
init|=
literal|0
decl_stmt|;
comment|/// \brief If a call expression was broken over multiple lines, this
comment|/// contains the start column of the second line. Otherwise 0.
name|unsigned
name|CallContinuation
init|=
literal|0
decl_stmt|;
comment|/// \brief The column of the first variable name in a variable declaration.
comment|///
comment|/// Used to align further variables if necessary.
name|unsigned
name|VariablePos
init|=
literal|0
decl_stmt|;
comment|/// \brief Whether a newline needs to be inserted before the block's closing
comment|/// brace.
comment|///
comment|/// We only want to insert a newline before the closing brace if there also
comment|/// was a newline after the beginning left brace.
name|bool
name|BreakBeforeClosingBrace
range|:
literal|1
decl_stmt|;
comment|/// \brief Avoid bin packing, i.e. multiple parameters/elements on multiple
comment|/// lines, in this context.
name|bool
name|AvoidBinPacking
range|:
literal|1
decl_stmt|;
comment|/// \brief Break after the next comma (or all the commas in this context if
comment|/// \c AvoidBinPacking is \c true).
name|bool
name|BreakBeforeParameter
range|:
literal|1
decl_stmt|;
comment|/// \brief Line breaking in this context would break a formatting rule.
name|bool
name|NoLineBreak
range|:
literal|1
decl_stmt|;
comment|/// \brief Same as \c NoLineBreak, but is restricted until the end of the
comment|/// operand (including the next ",").
name|bool
name|NoLineBreakInOperand
range|:
literal|1
decl_stmt|;
comment|/// \brief True if the last binary operator on this level was wrapped to the
comment|/// next line.
name|bool
name|LastOperatorWrapped
range|:
literal|1
decl_stmt|;
comment|/// \brief \c true if this \c ParenState already contains a line-break.
comment|///
comment|/// The first line break in a certain \c ParenState causes extra penalty so
comment|/// that clang-format prefers similar breaks, i.e. breaks in the same
comment|/// parenthesis.
name|bool
name|ContainsLineBreak
range|:
literal|1
decl_stmt|;
comment|/// \brief \c true if this \c ParenState contains multiple segments of a
comment|/// builder-type call on one line.
name|bool
name|ContainsUnwrappedBuilder
range|:
literal|1
decl_stmt|;
comment|/// \brief \c true if the colons of the curren ObjC method expression should
comment|/// be aligned.
comment|///
comment|/// Not considered for memoization as it will always have the same value at
comment|/// the same token.
name|bool
name|AlignColons
range|:
literal|1
decl_stmt|;
comment|/// \brief \c true if at least one selector name was found in the current
comment|/// ObjC method expression.
comment|///
comment|/// Not considered for memoization as it will always have the same value at
comment|/// the same token.
name|bool
name|ObjCSelectorNameFound
range|:
literal|1
decl_stmt|;
comment|/// \brief \c true if there are multiple nested blocks inside these parens.
comment|///
comment|/// Not considered for memoization as it will always have the same value at
comment|/// the same token.
name|bool
name|HasMultipleNestedBlocks
range|:
literal|1
decl_stmt|;
comment|// \brief The start of a nested block (e.g. lambda introducer in C++ or
comment|// "function" in JavaScript) is not wrapped to a new line.
name|bool
name|NestedBlockInlined
range|:
literal|1
decl_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ParenState
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|Indent
operator|!=
name|Other
operator|.
name|Indent
condition|)
return|return
name|Indent
operator|<
name|Other
operator|.
name|Indent
return|;
if|if
condition|(
name|LastSpace
operator|!=
name|Other
operator|.
name|LastSpace
condition|)
return|return
name|LastSpace
operator|<
name|Other
operator|.
name|LastSpace
return|;
if|if
condition|(
name|NestedBlockIndent
operator|!=
name|Other
operator|.
name|NestedBlockIndent
condition|)
return|return
name|NestedBlockIndent
operator|<
name|Other
operator|.
name|NestedBlockIndent
return|;
if|if
condition|(
name|FirstLessLess
operator|!=
name|Other
operator|.
name|FirstLessLess
condition|)
return|return
name|FirstLessLess
operator|<
name|Other
operator|.
name|FirstLessLess
return|;
if|if
condition|(
name|BreakBeforeClosingBrace
operator|!=
name|Other
operator|.
name|BreakBeforeClosingBrace
condition|)
return|return
name|BreakBeforeClosingBrace
return|;
if|if
condition|(
name|QuestionColumn
operator|!=
name|Other
operator|.
name|QuestionColumn
condition|)
return|return
name|QuestionColumn
operator|<
name|Other
operator|.
name|QuestionColumn
return|;
if|if
condition|(
name|AvoidBinPacking
operator|!=
name|Other
operator|.
name|AvoidBinPacking
condition|)
return|return
name|AvoidBinPacking
return|;
if|if
condition|(
name|BreakBeforeParameter
operator|!=
name|Other
operator|.
name|BreakBeforeParameter
condition|)
return|return
name|BreakBeforeParameter
return|;
if|if
condition|(
name|NoLineBreak
operator|!=
name|Other
operator|.
name|NoLineBreak
condition|)
return|return
name|NoLineBreak
return|;
if|if
condition|(
name|LastOperatorWrapped
operator|!=
name|Other
operator|.
name|LastOperatorWrapped
condition|)
return|return
name|LastOperatorWrapped
return|;
if|if
condition|(
name|ColonPos
operator|!=
name|Other
operator|.
name|ColonPos
condition|)
return|return
name|ColonPos
operator|<
name|Other
operator|.
name|ColonPos
return|;
if|if
condition|(
name|StartOfFunctionCall
operator|!=
name|Other
operator|.
name|StartOfFunctionCall
condition|)
return|return
name|StartOfFunctionCall
operator|<
name|Other
operator|.
name|StartOfFunctionCall
return|;
if|if
condition|(
name|StartOfArraySubscripts
operator|!=
name|Other
operator|.
name|StartOfArraySubscripts
condition|)
return|return
name|StartOfArraySubscripts
operator|<
name|Other
operator|.
name|StartOfArraySubscripts
return|;
if|if
condition|(
name|CallContinuation
operator|!=
name|Other
operator|.
name|CallContinuation
condition|)
return|return
name|CallContinuation
operator|<
name|Other
operator|.
name|CallContinuation
return|;
if|if
condition|(
name|VariablePos
operator|!=
name|Other
operator|.
name|VariablePos
condition|)
return|return
name|VariablePos
operator|<
name|Other
operator|.
name|VariablePos
return|;
if|if
condition|(
name|ContainsLineBreak
operator|!=
name|Other
operator|.
name|ContainsLineBreak
condition|)
return|return
name|ContainsLineBreak
return|;
if|if
condition|(
name|ContainsUnwrappedBuilder
operator|!=
name|Other
operator|.
name|ContainsUnwrappedBuilder
condition|)
return|return
name|ContainsUnwrappedBuilder
return|;
if|if
condition|(
name|NestedBlockInlined
operator|!=
name|Other
operator|.
name|NestedBlockInlined
condition|)
return|return
name|NestedBlockInlined
return|;
return|return
name|false
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief The current state when indenting a unwrapped line.
comment|///
comment|/// As the indenting tries different combinations this is copied by value.
struct|struct
name|LineState
block|{
comment|/// \brief The number of used columns in the current line.
name|unsigned
name|Column
decl_stmt|;
comment|/// \brief The token that needs to be next formatted.
name|FormatToken
modifier|*
name|NextToken
decl_stmt|;
comment|/// \brief \c true if this line contains a continued for-loop section.
name|bool
name|LineContainsContinuedForLoopSection
decl_stmt|;
comment|/// \brief The \c NestingLevel at the start of this line.
name|unsigned
name|StartOfLineLevel
decl_stmt|;
comment|/// \brief The lowest \c NestingLevel on the current line.
name|unsigned
name|LowestLevelOnLine
decl_stmt|;
comment|/// \brief The start column of the string literal, if we're in a string
comment|/// literal sequence, 0 otherwise.
name|unsigned
name|StartOfStringLiteral
decl_stmt|;
comment|/// \brief A stack keeping track of properties applying to parenthesis
comment|/// levels.
name|std
operator|::
name|vector
operator|<
name|ParenState
operator|>
name|Stack
expr_stmt|;
comment|/// \brief Ignore the stack of \c ParenStates for state comparison.
comment|///
comment|/// In long and deeply nested unwrapped lines, the current algorithm can
comment|/// be insufficient for finding the best formatting with a reasonable amount
comment|/// of time and memory. Setting this flag will effectively lead to the
comment|/// algorithm not analyzing some combinations. However, these combinations
comment|/// rarely contain the optimal solution: In short, accepting a higher
comment|/// penalty early would need to lead to different values in the \c
comment|/// ParenState stack (in an otherwise identical state) and these different
comment|/// values would need to lead to a significant amount of avoided penalty
comment|/// later.
comment|///
comment|/// FIXME: Come up with a better algorithm instead.
name|bool
name|IgnoreStackForComparison
decl_stmt|;
comment|/// \brief The indent of the first token.
name|unsigned
name|FirstIndent
decl_stmt|;
comment|/// \brief The line that is being formatted.
comment|///
comment|/// Does not need to be considered for memoization because it doesn't change.
specifier|const
name|AnnotatedLine
modifier|*
name|Line
decl_stmt|;
comment|/// \brief Comparison operator to be able to used \c LineState in \c map.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LineState
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|NextToken
operator|!=
name|Other
operator|.
name|NextToken
condition|)
return|return
name|NextToken
operator|<
name|Other
operator|.
name|NextToken
return|;
if|if
condition|(
name|Column
operator|!=
name|Other
operator|.
name|Column
condition|)
return|return
name|Column
operator|<
name|Other
operator|.
name|Column
return|;
if|if
condition|(
name|LineContainsContinuedForLoopSection
operator|!=
name|Other
operator|.
name|LineContainsContinuedForLoopSection
condition|)
return|return
name|LineContainsContinuedForLoopSection
return|;
if|if
condition|(
name|StartOfLineLevel
operator|!=
name|Other
operator|.
name|StartOfLineLevel
condition|)
return|return
name|StartOfLineLevel
operator|<
name|Other
operator|.
name|StartOfLineLevel
return|;
if|if
condition|(
name|LowestLevelOnLine
operator|!=
name|Other
operator|.
name|LowestLevelOnLine
condition|)
return|return
name|LowestLevelOnLine
operator|<
name|Other
operator|.
name|LowestLevelOnLine
return|;
if|if
condition|(
name|StartOfStringLiteral
operator|!=
name|Other
operator|.
name|StartOfStringLiteral
condition|)
return|return
name|StartOfStringLiteral
operator|<
name|Other
operator|.
name|StartOfStringLiteral
return|;
if|if
condition|(
name|IgnoreStackForComparison
operator|||
name|Other
operator|.
name|IgnoreStackForComparison
condition|)
return|return
name|false
return|;
return|return
name|Stack
operator|<
name|Other
operator|.
name|Stack
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace format
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

