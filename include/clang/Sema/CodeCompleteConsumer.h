begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- CodeCompleteConsumer.h - Code Completion Interface ----*- C++ -*-===//
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
comment|//  This file defines the CodeCompleteConsumer class.
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
name|LLVM_CLANG_SEMA_CODECOMPLETECONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_CODECOMPLETECONSUMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|FunctionTemplateDecl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|Sema
decl_stmt|;
comment|/// \brief A "string" used to describe how code completion can
comment|/// be performed for an entity.
comment|///
comment|/// A code completion string typically shows how a particular entity can be
comment|/// used. For example, the code completion string for a function would show
comment|/// the syntax to call it, including the parentheses, placeholders for the
comment|/// arguments, etc.
name|class
name|CodeCompletionString
block|{
name|public
label|:
comment|/// \brief The different kinds of "chunks" that can occur within a code
comment|/// completion string.
enum|enum
name|ChunkKind
block|{
comment|/// \brief The piece of text that the user is expected to type to
comment|/// match the code-completion string, typically a keyword or the name of a
comment|/// declarator or macro.
name|CK_TypedText
block|,
comment|/// \brief A piece of text that should be placed in the buffer, e.g.,
comment|/// parentheses or a comma in a function call.
name|CK_Text
block|,
comment|/// \brief A code completion string that is entirely optional. For example,
comment|/// an optional code completion string that describes the default arguments
comment|/// in a function call.
name|CK_Optional
block|,
comment|/// \brief A string that acts as a placeholder for, e.g., a function
comment|/// call argument.
name|CK_Placeholder
block|,
comment|/// \brief A piece of text that describes something about the result but
comment|/// should not be inserted into the buffer.
name|CK_Informative
block|,
comment|/// \brief A piece of text that describes the parameter that corresponds
comment|/// to the code-completion location within a function call, message send,
comment|/// macro invocation, etc.
name|CK_CurrentParameter
block|,
comment|/// \brief A left parenthesis ('(').
name|CK_LeftParen
block|,
comment|/// \brief A right parenthesis (')').
name|CK_RightParen
block|,
comment|/// \brief A left bracket ('[').
name|CK_LeftBracket
block|,
comment|/// \brief A right bracket (']').
name|CK_RightBracket
block|,
comment|/// \brief A left brace ('{').
name|CK_LeftBrace
block|,
comment|/// \brief A right brace ('}').
name|CK_RightBrace
block|,
comment|/// \brief A left angle bracket ('<').
name|CK_LeftAngle
block|,
comment|/// \brief A right angle bracket ('>').
name|CK_RightAngle
block|,
comment|/// \brief A comma separator (',').
name|CK_Comma
block|}
enum|;
comment|/// \brief One piece of the code completion string.
struct|struct
name|Chunk
block|{
comment|/// \brief The kind of data stored in this piece of the code completion
comment|/// string.
name|ChunkKind
name|Kind
decl_stmt|;
union|union
block|{
comment|/// \brief The text string associated with a CK_Text, CK_Placeholder,
comment|/// CK_Informative, or CK_Comma chunk.
comment|/// The string is owned by the chunk and will be deallocated
comment|/// (with delete[]) when the chunk is destroyed.
specifier|const
name|char
modifier|*
name|Text
decl_stmt|;
comment|/// \brief The code completion string associated with a CK_Optional chunk.
comment|/// The optional code completion string is owned by the chunk, and will
comment|/// be deallocated (with delete) when the chunk is destroyed.
name|CodeCompletionString
modifier|*
name|Optional
decl_stmt|;
block|}
union|;
name|Chunk
argument_list|()
operator|:
name|Kind
argument_list|(
name|CK_Text
argument_list|)
operator|,
name|Text
argument_list|(
literal|0
argument_list|)
block|{ }
name|Chunk
argument_list|(
argument|ChunkKind Kind
argument_list|,
argument|llvm::StringRef Text =
literal|""
argument_list|)
expr_stmt|;
comment|/// \brief Create a new text chunk.
specifier|static
name|Chunk
name|CreateText
argument_list|(
name|llvm
operator|::
name|StringRef
name|Text
argument_list|)
decl_stmt|;
comment|/// \brief Create a new optional chunk.
specifier|static
name|Chunk
name|CreateOptional
argument_list|(
name|std
operator|::
name|auto_ptr
operator|<
name|CodeCompletionString
operator|>
name|Optional
argument_list|)
decl_stmt|;
comment|/// \brief Create a new placeholder chunk.
specifier|static
name|Chunk
name|CreatePlaceholder
argument_list|(
name|llvm
operator|::
name|StringRef
name|Placeholder
argument_list|)
decl_stmt|;
comment|/// \brief Create a new informative chunk.
specifier|static
name|Chunk
name|CreateInformative
argument_list|(
name|llvm
operator|::
name|StringRef
name|Informative
argument_list|)
decl_stmt|;
comment|/// \brief Create a new current-parameter chunk.
specifier|static
name|Chunk
name|CreateCurrentParameter
argument_list|(
name|llvm
operator|::
name|StringRef
name|CurrentParameter
argument_list|)
decl_stmt|;
comment|/// \brief Clone the given chunk.
name|Chunk
name|Clone
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Destroy this chunk, deallocating any memory it owns.
name|void
name|Destroy
parameter_list|()
function_decl|;
block|}
struct|;
name|private
label|:
comment|/// \brief The chunks stored in this string.
name|llvm
operator|::
name|SmallVector
operator|<
name|Chunk
operator|,
literal|4
operator|>
name|Chunks
expr_stmt|;
name|CodeCompletionString
argument_list|(
specifier|const
name|CodeCompletionString
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|CodeCompletionString
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CodeCompletionString
operator|&
operator|)
decl_stmt|;
comment|// DITTO
name|public
label|:
name|CodeCompletionString
argument_list|()
block|{ }
operator|~
name|CodeCompletionString
argument_list|()
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|Chunk
operator|,
literal|4
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Chunks
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Chunks
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Chunks
operator|.
name|empty
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Chunks
operator|.
name|size
argument_list|()
return|;
block|}
name|Chunk
modifier|&
name|operator
function|[]
parameter_list|(
name|unsigned
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|<
name|size
argument_list|()
operator|&&
literal|"Chunk index out-of-range"
argument_list|)
expr_stmt|;
return|return
name|Chunks
index|[
name|I
index|]
return|;
block|}
specifier|const
name|Chunk
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|I
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|I
operator|<
name|size
argument_list|()
operator|&&
literal|"Chunk index out-of-range"
argument_list|)
expr_stmt|;
return|return
name|Chunks
index|[
name|I
index|]
return|;
block|}
comment|/// \brief Add a new typed-text chunk.
comment|/// The text string will be copied.
name|void
name|AddTypedTextChunk
argument_list|(
name|llvm
operator|::
name|StringRef
name|Text
argument_list|)
block|{
name|Chunks
operator|.
name|push_back
argument_list|(
name|Chunk
argument_list|(
name|CK_TypedText
argument_list|,
name|Text
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new text chunk.
comment|/// The text string will be copied.
name|void
name|AddTextChunk
argument_list|(
name|llvm
operator|::
name|StringRef
name|Text
argument_list|)
block|{
name|Chunks
operator|.
name|push_back
argument_list|(
name|Chunk
operator|::
name|CreateText
argument_list|(
name|Text
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new optional chunk.
name|void
name|AddOptionalChunk
argument_list|(
name|std
operator|::
name|auto_ptr
operator|<
name|CodeCompletionString
operator|>
name|Optional
argument_list|)
block|{
name|Chunks
operator|.
name|push_back
argument_list|(
name|Chunk
operator|::
name|CreateOptional
argument_list|(
name|Optional
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new placeholder chunk.
comment|/// The placeholder text will be copied.
name|void
name|AddPlaceholderChunk
argument_list|(
name|llvm
operator|::
name|StringRef
name|Placeholder
argument_list|)
block|{
name|Chunks
operator|.
name|push_back
argument_list|(
name|Chunk
operator|::
name|CreatePlaceholder
argument_list|(
name|Placeholder
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new informative chunk.
comment|/// The text will be copied.
name|void
name|AddInformativeChunk
argument_list|(
name|llvm
operator|::
name|StringRef
name|Text
argument_list|)
block|{
name|Chunks
operator|.
name|push_back
argument_list|(
name|Chunk
operator|::
name|CreateInformative
argument_list|(
name|Text
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new current-parameter chunk.
comment|/// The text will be copied.
name|void
name|AddCurrentParameterChunk
argument_list|(
name|llvm
operator|::
name|StringRef
name|CurrentParameter
argument_list|)
block|{
name|Chunks
operator|.
name|push_back
argument_list|(
name|Chunk
operator|::
name|CreateCurrentParameter
argument_list|(
name|CurrentParameter
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new chunk.
name|void
name|AddChunk
parameter_list|(
name|Chunk
name|C
parameter_list|)
block|{
name|Chunks
operator|.
name|push_back
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Returns the text in the TypedText chunk.
specifier|const
name|char
operator|*
name|getTypedText
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve a string representation of the code completion string,
comment|/// which is mainly useful for debugging.
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Clone this code-completion string.
name|CodeCompletionString
operator|*
name|Clone
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Serialize this code-completion string to the given stream.
name|void
name|Serialize
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Deserialize a code-completion string from the given string.
specifier|static
name|CodeCompletionString
modifier|*
name|Deserialize
parameter_list|(
specifier|const
name|char
modifier|*
modifier|&
name|Str
parameter_list|,
specifier|const
name|char
modifier|*
name|StrEnd
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|llvm
operator|::
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|CodeCompletionString
operator|&
name|CCS
operator|)
expr_stmt|;
comment|/// \brief Abstract interface for a consumer of code-completion
comment|/// information.
name|class
name|CodeCompleteConsumer
block|{
name|protected
label|:
comment|/// \brief Whether to include macros in the code-completion results.
name|bool
name|IncludeMacros
decl_stmt|;
comment|/// \brief Whether the output format for the code-completion consumer is
comment|/// binary.
name|bool
name|OutputIsBinary
decl_stmt|;
name|public
label|:
comment|/// \brief Captures a result of code completion.
struct|struct
name|Result
block|{
comment|/// \brief Describes the kind of result generated.
enum|enum
name|ResultKind
block|{
name|RK_Declaration
init|=
literal|0
block|,
comment|//< Refers to a declaration
name|RK_Keyword
block|,
comment|//< Refers to a keyword or symbol.
name|RK_Macro
block|,
comment|//< Refers to a macro
name|RK_Pattern
comment|//< Refers to a precomputed pattern.
block|}
enum|;
comment|/// \brief The kind of result stored here.
name|ResultKind
name|Kind
decl_stmt|;
union|union
block|{
comment|/// \brief When Kind == RK_Declaration, the declaration we are referring
comment|/// to.
name|NamedDecl
modifier|*
name|Declaration
decl_stmt|;
comment|/// \brief When Kind == RK_Keyword, the string representing the keyword
comment|/// or symbol's spelling.
specifier|const
name|char
modifier|*
name|Keyword
decl_stmt|;
comment|/// \brief When Kind == RK_Pattern, the code-completion string that
comment|/// describes the completion text to insert.
name|CodeCompletionString
modifier|*
name|Pattern
decl_stmt|;
comment|/// \brief When Kind == RK_Macro, the identifier that refers to a macro.
name|IdentifierInfo
modifier|*
name|Macro
decl_stmt|;
block|}
union|;
comment|/// \brief Describes how good this result is, with zero being the best
comment|/// result and progressively higher numbers representing poorer results.
name|unsigned
name|Rank
decl_stmt|;
comment|/// \brief Specifiers which parameter (of a function, Objective-C method,
comment|/// macro, etc.) we should start with when formatting the result.
name|unsigned
name|StartParameter
decl_stmt|;
comment|/// \brief Whether this result is hidden by another name.
name|bool
name|Hidden
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this result was found via lookup into a base class.
name|bool
name|QualifierIsInformative
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this declaration is the beginning of a
comment|/// nested-name-specifier and, therefore, should be followed by '::'.
name|bool
name|StartsNestedNameSpecifier
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether all parameters (of a function, Objective-C
comment|/// method, etc.) should be considered "informative".
name|bool
name|AllParametersAreInformative
range|:
literal|1
decl_stmt|;
comment|/// \brief If the result should have a nested-name-specifier, this is it.
comment|/// When \c QualifierIsInformative, the nested-name-specifier is
comment|/// informative rather than required.
name|NestedNameSpecifier
modifier|*
name|Qualifier
decl_stmt|;
comment|/// \brief Build a result that refers to a declaration.
name|Result
argument_list|(
argument|NamedDecl *Declaration
argument_list|,
argument|unsigned Rank
argument_list|,
argument|NestedNameSpecifier *Qualifier =
literal|0
argument_list|,
argument|bool QualifierIsInformative = false
argument_list|)
block|:
name|Kind
argument_list|(
name|RK_Declaration
argument_list|)
operator|,
name|Declaration
argument_list|(
name|Declaration
argument_list|)
operator|,
name|Rank
argument_list|(
name|Rank
argument_list|)
operator|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
operator|,
name|Hidden
argument_list|(
name|false
argument_list|)
operator|,
name|QualifierIsInformative
argument_list|(
name|QualifierIsInformative
argument_list|)
operator|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
operator|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
operator|,
name|Qualifier
argument_list|(
argument|Qualifier
argument_list|)
block|{ }
comment|/// \brief Build a result that refers to a keyword or symbol.
name|Result
argument_list|(
argument|const char *Keyword
argument_list|,
argument|unsigned Rank
argument_list|)
operator|:
name|Kind
argument_list|(
name|RK_Keyword
argument_list|)
operator|,
name|Keyword
argument_list|(
name|Keyword
argument_list|)
operator|,
name|Rank
argument_list|(
name|Rank
argument_list|)
operator|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
operator|,
name|Hidden
argument_list|(
name|false
argument_list|)
operator|,
name|QualifierIsInformative
argument_list|(
literal|0
argument_list|)
operator|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
operator|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
operator|,
name|Qualifier
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Build a result that refers to a macro.
name|Result
argument_list|(
argument|IdentifierInfo *Macro
argument_list|,
argument|unsigned Rank
argument_list|)
operator|:
name|Kind
argument_list|(
name|RK_Macro
argument_list|)
operator|,
name|Macro
argument_list|(
name|Macro
argument_list|)
operator|,
name|Rank
argument_list|(
name|Rank
argument_list|)
operator|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
operator|,
name|Hidden
argument_list|(
name|false
argument_list|)
operator|,
name|QualifierIsInformative
argument_list|(
literal|0
argument_list|)
operator|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
operator|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
operator|,
name|Qualifier
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Build a result that refers to a pattern.
name|Result
argument_list|(
argument|CodeCompletionString *Pattern
argument_list|,
argument|unsigned Rank
argument_list|)
operator|:
name|Kind
argument_list|(
name|RK_Pattern
argument_list|)
operator|,
name|Pattern
argument_list|(
name|Pattern
argument_list|)
operator|,
name|Rank
argument_list|(
name|Rank
argument_list|)
operator|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
operator|,
name|Hidden
argument_list|(
name|false
argument_list|)
operator|,
name|QualifierIsInformative
argument_list|(
literal|0
argument_list|)
operator|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
operator|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
operator|,
name|Qualifier
argument_list|(
literal|0
argument_list|)
block|{ }
comment|/// \brief Retrieve the declaration stored in this result.
name|NamedDecl
operator|*
name|getDeclaration
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|RK_Declaration
operator|&&
literal|"Not a declaration result"
argument_list|)
block|;
return|return
name|Declaration
return|;
block|}
comment|/// \brief Retrieve the keyword stored in this result.
specifier|const
name|char
operator|*
name|getKeyword
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|RK_Keyword
operator|&&
literal|"Not a keyword result"
argument_list|)
block|;
return|return
name|Keyword
return|;
block|}
comment|/// \brief Create a new code-completion string that describes how to insert
comment|/// this result into a program.
name|CodeCompletionString
modifier|*
name|CreateCodeCompletionString
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|)
function_decl|;
name|void
name|Destroy
parameter_list|()
function_decl|;
block|}
struct|;
name|class
name|OverloadCandidate
block|{
name|public
label|:
comment|/// \brief Describes the type of overload candidate.
enum|enum
name|CandidateKind
block|{
comment|/// \brief The candidate is a function declaration.
name|CK_Function
block|,
comment|/// \brief The candidate is a function template.
name|CK_FunctionTemplate
block|,
comment|/// \brief The "candidate" is actually a variable, expression, or block
comment|/// for which we only have a function prototype.
name|CK_FunctionType
block|}
enum|;
name|private
label|:
comment|/// \brief The kind of overload candidate.
name|CandidateKind
name|Kind
decl_stmt|;
union|union
block|{
comment|/// \brief The function overload candidate, available when
comment|/// Kind == CK_Function.
name|FunctionDecl
modifier|*
name|Function
decl_stmt|;
comment|/// \brief The function template overload candidate, available when
comment|/// Kind == CK_FunctionTemplate.
name|FunctionTemplateDecl
modifier|*
name|FunctionTemplate
decl_stmt|;
comment|/// \brief The function type that describes the entity being called,
comment|/// when Kind == CK_FunctionType.
specifier|const
name|FunctionType
modifier|*
name|Type
decl_stmt|;
block|}
union|;
name|public
label|:
name|OverloadCandidate
argument_list|(
name|FunctionDecl
operator|*
name|Function
argument_list|)
operator|:
name|Kind
argument_list|(
name|CK_Function
argument_list|)
operator|,
name|Function
argument_list|(
argument|Function
argument_list|)
block|{ }
name|OverloadCandidate
argument_list|(
name|FunctionTemplateDecl
operator|*
name|FunctionTemplateDecl
argument_list|)
operator|:
name|Kind
argument_list|(
name|CK_FunctionTemplate
argument_list|)
operator|,
name|FunctionTemplate
argument_list|(
argument|FunctionTemplate
argument_list|)
block|{ }
name|OverloadCandidate
argument_list|(
specifier|const
name|FunctionType
operator|*
name|Type
argument_list|)
operator|:
name|Kind
argument_list|(
name|CK_FunctionType
argument_list|)
operator|,
name|Type
argument_list|(
argument|Type
argument_list|)
block|{ }
comment|/// \brief Determine the kind of overload candidate.
name|CandidateKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Retrieve the function overload candidate or the templated
comment|/// function declaration for a function template.
name|FunctionDecl
operator|*
name|getFunction
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the function template overload candidate.
name|FunctionTemplateDecl
operator|*
name|getFunctionTemplate
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getKind
argument_list|()
operator|==
name|CK_FunctionTemplate
operator|&&
literal|"Not a function template"
argument_list|)
block|;
return|return
name|FunctionTemplate
return|;
block|}
comment|/// \brief Retrieve the function type of the entity, regardless of how the
comment|/// function is stored.
specifier|const
name|FunctionType
operator|*
name|getFunctionType
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Create a new code-completion string that describes the function
comment|/// signature of this overload candidate.
name|CodeCompletionString
modifier|*
name|CreateSignatureString
argument_list|(
name|unsigned
name|CurrentArg
argument_list|,
name|Sema
operator|&
name|S
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
name|CodeCompleteConsumer
argument_list|()
operator|:
name|IncludeMacros
argument_list|(
name|false
argument_list|)
operator|,
name|OutputIsBinary
argument_list|(
argument|false
argument_list|)
block|{ }
name|CodeCompleteConsumer
argument_list|(
argument|bool IncludeMacros
argument_list|,
argument|bool OutputIsBinary
argument_list|)
operator|:
name|IncludeMacros
argument_list|(
name|IncludeMacros
argument_list|)
operator|,
name|OutputIsBinary
argument_list|(
argument|OutputIsBinary
argument_list|)
block|{ }
comment|/// \brief Whether the code-completion consumer wants to see macros.
name|bool
name|includeMacros
argument_list|()
specifier|const
block|{
return|return
name|IncludeMacros
return|;
block|}
comment|/// \brief Determine whether the output of this consumer is binary.
name|bool
name|isOutputBinary
argument_list|()
specifier|const
block|{
return|return
name|OutputIsBinary
return|;
block|}
comment|/// \brief Deregisters and destroys this code-completion consumer.
name|virtual
operator|~
name|CodeCompleteConsumer
argument_list|()
expr_stmt|;
comment|/// \name Code-completion callbacks
comment|//@{
comment|/// \brief Process the finalized code-completion results.
name|virtual
name|void
name|ProcessCodeCompleteResults
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|Result
modifier|*
name|Results
parameter_list|,
name|unsigned
name|NumResults
parameter_list|)
block|{ }
comment|/// \param S the semantic-analyzer object for which code-completion is being
comment|/// done.
comment|///
comment|/// \param CurrentArg the index of the current argument.
comment|///
comment|/// \param Candidates an array of overload candidates.
comment|///
comment|/// \param NumCandidates the number of overload candidates
name|virtual
name|void
name|ProcessOverloadCandidates
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|,
name|unsigned
name|CurrentArg
parameter_list|,
name|OverloadCandidate
modifier|*
name|Candidates
parameter_list|,
name|unsigned
name|NumCandidates
parameter_list|)
block|{ }
comment|//@}
block|}
empty_stmt|;
comment|/// \brief A simple code-completion consumer that prints the results it
comment|/// receives in a simple format.
name|class
name|PrintingCodeCompleteConsumer
range|:
name|public
name|CodeCompleteConsumer
block|{
comment|/// \brief The raw output stream.
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
comment|/// \brief Create a new printing code-completion consumer that prints its
comment|/// results to the given raw output stream.
name|PrintingCodeCompleteConsumer
argument_list|(
argument|bool IncludeMacros
argument_list|,
argument|llvm::raw_ostream&OS
argument_list|)
operator|:
name|CodeCompleteConsumer
argument_list|(
name|IncludeMacros
argument_list|,
name|false
argument_list|)
block|,
name|OS
argument_list|(
argument|OS
argument_list|)
block|{ }
comment|/// \brief Prints the finalized code-completion results.
name|virtual
name|void
name|ProcessCodeCompleteResults
argument_list|(
argument|Sema&S
argument_list|,
argument|Result *Results
argument_list|,
argument|unsigned NumResults
argument_list|)
block|;
name|virtual
name|void
name|ProcessOverloadCandidates
argument_list|(
argument|Sema&S
argument_list|,
argument|unsigned CurrentArg
argument_list|,
argument|OverloadCandidate *Candidates
argument_list|,
argument|unsigned NumCandidates
argument_list|)
block|;   }
decl_stmt|;
comment|/// \brief A code-completion consumer that prints the results it receives
comment|/// in a format that is parsable by the CIndex library.
name|class
name|CIndexCodeCompleteConsumer
range|:
name|public
name|CodeCompleteConsumer
block|{
comment|/// \brief The raw output stream.
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
comment|/// \brief Create a new CIndex code-completion consumer that prints its
comment|/// results to the given raw output stream in a format readable to the CIndex
comment|/// library.
name|CIndexCodeCompleteConsumer
argument_list|(
argument|bool IncludeMacros
argument_list|,
argument|llvm::raw_ostream&OS
argument_list|)
operator|:
name|CodeCompleteConsumer
argument_list|(
name|IncludeMacros
argument_list|,
name|true
argument_list|)
block|,
name|OS
argument_list|(
argument|OS
argument_list|)
block|{ }
comment|/// \brief Prints the finalized code-completion results.
name|virtual
name|void
name|ProcessCodeCompleteResults
argument_list|(
argument|Sema&S
argument_list|,
argument|Result *Results
argument_list|,
argument|unsigned NumResults
argument_list|)
block|;
name|virtual
name|void
name|ProcessOverloadCandidates
argument_list|(
argument|Sema&S
argument_list|,
argument|unsigned CurrentArg
argument_list|,
argument|OverloadCandidate *Candidates
argument_list|,
argument|unsigned NumCandidates
argument_list|)
block|;   }
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
comment|// LLVM_CLANG_SEMA_CODECOMPLETECONSUMER_H
end_comment

end_unit

