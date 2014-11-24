begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/LineEditor/LineEditor.h - line editor --------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LINEEDITOR_LINEEDITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LINEEDITOR_LINEEDITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cstdio>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|LineEditor
block|{
name|public
label|:
comment|/// Create a LineEditor object.
comment|///
comment|/// \param ProgName The name of the current program. Used to form a default
comment|/// prompt.
comment|/// \param HistoryPath Path to the file in which to store history data, if
comment|/// possible.
comment|/// \param In The input stream used by the editor.
comment|/// \param Out The output stream used by the editor.
comment|/// \param Err The error stream used by the editor.
name|LineEditor
argument_list|(
argument|StringRef ProgName
argument_list|,
argument|StringRef HistoryPath =
literal|""
argument_list|,
argument|FILE *In = stdin
argument_list|,
argument|FILE *Out = stdout
argument_list|,
argument|FILE *Err = stderr
argument_list|)
empty_stmt|;
operator|~
name|LineEditor
argument_list|()
expr_stmt|;
comment|/// Reads a line.
comment|///
comment|/// \return The line, or llvm::Optional<std::string>() on EOF.
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|readLine
argument_list|()
specifier|const
expr_stmt|;
name|void
name|saveHistory
parameter_list|()
function_decl|;
name|void
name|loadHistory
parameter_list|()
function_decl|;
specifier|static
name|std
operator|::
name|string
name|getDefaultHistoryPath
argument_list|(
argument|StringRef ProgName
argument_list|)
expr_stmt|;
comment|/// The action to perform upon a completion request.
struct|struct
name|CompletionAction
block|{
enum|enum
name|ActionKind
block|{
comment|/// Insert Text at the cursor position.
name|AK_Insert
block|,
comment|/// Show Completions, or beep if the list is empty.
name|AK_ShowCompletions
block|}
enum|;
name|ActionKind
name|Kind
decl_stmt|;
comment|/// The text to insert.
name|std
operator|::
name|string
name|Text
expr_stmt|;
comment|/// The list of completions to show.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Completions
expr_stmt|;
block|}
struct|;
comment|/// A possible completion at a given cursor position.
struct|struct
name|Completion
block|{
name|Completion
argument_list|()
block|{}
name|Completion
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|TypedText
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|DisplayText
argument_list|)
operator|:
name|TypedText
argument_list|(
name|TypedText
argument_list|)
operator|,
name|DisplayText
argument_list|(
argument|DisplayText
argument_list|)
block|{}
comment|/// The text to insert. If the user has already input some of the
comment|/// completion, this should only include the rest of the text.
name|std
operator|::
name|string
name|TypedText
expr_stmt|;
comment|/// A description of this completion. This may be the completion itself, or
comment|/// maybe a summary of its type or arguments.
name|std
operator|::
name|string
name|DisplayText
expr_stmt|;
block|}
struct|;
comment|/// Set the completer for this LineEditor. A completer is a function object
comment|/// which takes arguments of type StringRef (the string to complete) and
comment|/// size_t (the zero-based cursor position in the StringRef) and returns a
comment|/// CompletionAction.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|setCompleter
argument_list|(
argument|T Comp
argument_list|)
block|{
name|Completer
operator|.
name|reset
argument_list|(
argument|new CompleterModel<T>(Comp)
argument_list|)
block|;   }
comment|/// Set the completer for this LineEditor to the given list completer.
comment|/// A list completer is a function object which takes arguments of type
comment|/// StringRef (the string to complete) and size_t (the zero-based cursor
comment|/// position in the StringRef) and returns a std::vector<Completion>.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|setListCompleter
argument_list|(
argument|T Comp
argument_list|)
block|{
name|Completer
operator|.
name|reset
argument_list|(
argument|new ListCompleterModel<T>(Comp)
argument_list|)
block|;   }
comment|/// Use the current completer to produce a CompletionAction for the given
comment|/// completion request. If the current completer is a list completer, this
comment|/// will return an AK_Insert CompletionAction if each completion has a common
comment|/// prefix, or an AK_ShowCompletions CompletionAction otherwise.
comment|///
comment|/// \param Buffer The string to complete
comment|/// \param Pos The zero-based cursor position in the StringRef
name|CompletionAction
name|getCompletionAction
argument_list|(
argument|StringRef Buffer
argument_list|,
argument|size_t Pos
argument_list|)
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getPrompt
argument_list|()
specifier|const
block|{
return|return
name|Prompt
return|;
block|}
name|void
name|setPrompt
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|P
argument_list|)
block|{
name|Prompt
operator|=
name|P
expr_stmt|;
block|}
comment|// Public so callbacks in LineEditor.cpp can use it.
struct_decl|struct
name|InternalData
struct_decl|;
name|private
label|:
name|std
operator|::
name|string
name|Prompt
expr_stmt|;
name|std
operator|::
name|string
name|HistoryPath
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|InternalData
operator|>
name|Data
expr_stmt|;
struct|struct
name|CompleterConcept
block|{
name|virtual
operator|~
name|CompleterConcept
argument_list|()
expr_stmt|;
name|virtual
name|CompletionAction
name|complete
argument_list|(
name|StringRef
name|Buffer
argument_list|,
name|size_t
name|Pos
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
struct|;
name|struct
name|ListCompleterConcept
range|:
name|CompleterConcept
block|{
operator|~
name|ListCompleterConcept
argument_list|()
block|;
name|CompletionAction
name|complete
argument_list|(
argument|StringRef Buffer
argument_list|,
argument|size_t Pos
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|std
operator|::
name|string
name|getCommonPrefix
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|Completion
operator|>
operator|&
name|Comps
argument_list|)
block|;
name|virtual
name|std
operator|::
name|vector
operator|<
name|Completion
operator|>
name|getCompletions
argument_list|(
argument|StringRef Buffer
argument_list|,
argument|size_t Pos
argument_list|)
specifier|const
operator|=
literal|0
block|;   }
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|CompleterModel
operator|:
name|CompleterConcept
block|{
name|CompleterModel
argument_list|(
argument|T Value
argument_list|)
operator|:
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
name|CompletionAction
name|complete
argument_list|(
argument|StringRef Buffer
argument_list|,
argument|size_t Pos
argument_list|)
specifier|const
name|override
block|{
return|return
name|Value
argument_list|(
name|Buffer
argument_list|,
name|Pos
argument_list|)
return|;
block|}
name|T
name|Value
block|;   }
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|ListCompleterModel
operator|:
name|ListCompleterConcept
block|{
name|ListCompleterModel
argument_list|(
argument|T Value
argument_list|)
operator|:
name|Value
argument_list|(
argument|Value
argument_list|)
block|{}
name|std
operator|::
name|vector
operator|<
name|Completion
operator|>
name|getCompletions
argument_list|(
argument|StringRef Buffer
argument_list|,
argument|size_t Pos
argument_list|)
specifier|const
name|override
block|{
return|return
name|Value
argument_list|(
name|Buffer
argument_list|,
name|Pos
argument_list|)
return|;
block|}
name|T
name|Value
block|;   }
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|CompleterConcept
operator|>
name|Completer
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

