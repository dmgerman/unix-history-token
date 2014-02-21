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
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CanonicalType.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/CodeCompleteOptions.h"
end_include

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
file|"llvm/Support/Allocator.h"
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
name|class
name|Decl
decl_stmt|;
comment|/// \brief Default priority values for code-completion results based
comment|/// on their kind.
enum|enum
block|{
comment|/// \brief Priority for the next initialization in a constructor initializer
comment|/// list.
name|CCP_NextInitializer
init|=
literal|7
block|,
comment|/// \brief Priority for an enumeration constant inside a switch whose
comment|/// condition is of the enumeration type.
name|CCP_EnumInCase
init|=
literal|7
block|,
comment|/// \brief Priority for a send-to-super completion.
name|CCP_SuperCompletion
init|=
literal|20
block|,
comment|/// \brief Priority for a declaration that is in the local scope.
name|CCP_LocalDeclaration
init|=
literal|34
block|,
comment|/// \brief Priority for a member declaration found from the current
comment|/// method or member function.
name|CCP_MemberDeclaration
init|=
literal|35
block|,
comment|/// \brief Priority for a language keyword (that isn't any of the other
comment|/// categories).
name|CCP_Keyword
init|=
literal|40
block|,
comment|/// \brief Priority for a code pattern.
name|CCP_CodePattern
init|=
literal|40
block|,
comment|/// \brief Priority for a non-type declaration.
name|CCP_Declaration
init|=
literal|50
block|,
comment|/// \brief Priority for a type.
name|CCP_Type
init|=
name|CCP_Declaration
block|,
comment|/// \brief Priority for a constant value (e.g., enumerator).
name|CCP_Constant
init|=
literal|65
block|,
comment|/// \brief Priority for a preprocessor macro.
name|CCP_Macro
init|=
literal|70
block|,
comment|/// \brief Priority for a nested-name-specifier.
name|CCP_NestedNameSpecifier
init|=
literal|75
block|,
comment|/// \brief Priority for a result that isn't likely to be what the user wants,
comment|/// but is included for completeness.
name|CCP_Unlikely
init|=
literal|80
block|,
comment|/// \brief Priority for the Objective-C "_cmd" implicit parameter.
name|CCP_ObjC_cmd
init|=
name|CCP_Unlikely
block|}
enum|;
comment|/// \brief Priority value deltas that are added to code-completion results
comment|/// based on the context of the result.
enum|enum
block|{
comment|/// \brief The result is in a base class.
name|CCD_InBaseClass
init|=
literal|2
block|,
comment|/// \brief The result is a C++ non-static member function whose qualifiers
comment|/// exactly match the object type on which the member function can be called.
name|CCD_ObjectQualifierMatch
init|=
operator|-
literal|1
block|,
comment|/// \brief The selector of the given message exactly matches the selector
comment|/// of the current method, which might imply that some kind of delegation
comment|/// is occurring.
name|CCD_SelectorMatch
init|=
operator|-
literal|3
block|,
comment|/// \brief Adjustment to the "bool" type in Objective-C, where the typedef
comment|/// "BOOL" is preferred.
name|CCD_bool_in_ObjC
init|=
literal|1
block|,
comment|/// \brief Adjustment for KVC code pattern priorities when it doesn't look
comment|/// like the
name|CCD_ProbablyNotObjCCollection
init|=
literal|15
block|,
comment|/// \brief An Objective-C method being used as a property.
name|CCD_MethodAsProperty
init|=
literal|2
block|}
enum|;
comment|/// \brief Priority value factors by which we will divide or multiply the
comment|/// priority of a code-completion result.
enum|enum
block|{
comment|/// \brief Divide by this factor when a code-completion result's type exactly
comment|/// matches the type we expect.
name|CCF_ExactTypeMatch
init|=
literal|4
block|,
comment|/// \brief Divide by this factor when a code-completion result's type is
comment|/// similar to the type we expect (e.g., both arithmetic types, both
comment|/// Objective-C object pointer types).
name|CCF_SimilarTypeMatch
init|=
literal|2
block|}
enum|;
comment|/// \brief A simplified classification of types used when determining
comment|/// "similar" types for code completion.
enum|enum
name|SimplifiedTypeClass
block|{
name|STC_Arithmetic
block|,
name|STC_Array
block|,
name|STC_Block
block|,
name|STC_Function
block|,
name|STC_ObjectiveC
block|,
name|STC_Other
block|,
name|STC_Pointer
block|,
name|STC_Record
block|,
name|STC_Void
block|}
enum|;
comment|/// \brief Determine the simplified type class of the given canonical type.
name|SimplifiedTypeClass
name|getSimplifiedTypeClass
parameter_list|(
name|CanQualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Determine the type that this declaration will have if it is used
comment|/// as a type or in an expression.
name|QualType
name|getDeclUsageType
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
specifier|const
name|NamedDecl
modifier|*
name|ND
parameter_list|)
function_decl|;
comment|/// \brief Determine the priority to be given to a macro code completion result
comment|/// with the given name.
comment|///
comment|/// \param MacroName The name of the macro.
comment|///
comment|/// \param LangOpts Options describing the current language dialect.
comment|///
comment|/// \param PreferredTypeIsPointer Whether the preferred type for the context
comment|/// of this macro is a pointer type.
name|unsigned
name|getMacroUsagePriority
parameter_list|(
name|StringRef
name|MacroName
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
name|bool
name|PreferredTypeIsPointer
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Determine the libclang cursor kind associated with the given
comment|/// declaration.
name|CXCursorKind
name|getCursorKindForDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
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
comment|/// \brief The context in which code completion occurred, so that the
comment|/// code-completion consumer can process the results accordingly.
name|class
name|CodeCompletionContext
block|{
name|public
label|:
enum|enum
name|Kind
block|{
comment|/// \brief An unspecified code-completion context.
name|CCC_Other
block|,
comment|/// \brief An unspecified code-completion context where we should also add
comment|/// macro completions.
name|CCC_OtherWithMacros
block|,
comment|/// \brief Code completion occurred within a "top-level" completion context,
comment|/// e.g., at namespace or global scope.
name|CCC_TopLevel
block|,
comment|/// \brief Code completion occurred within an Objective-C interface,
comment|/// protocol, or category interface.
name|CCC_ObjCInterface
block|,
comment|/// \brief Code completion occurred within an Objective-C implementation
comment|/// or category implementation.
name|CCC_ObjCImplementation
block|,
comment|/// \brief Code completion occurred within the instance variable list of
comment|/// an Objective-C interface, implementation, or category implementation.
name|CCC_ObjCIvarList
block|,
comment|/// \brief Code completion occurred within a class, struct, or union.
name|CCC_ClassStructUnion
block|,
comment|/// \brief Code completion occurred where a statement (or declaration) is
comment|/// expected in a function, method, or block.
name|CCC_Statement
block|,
comment|/// \brief Code completion occurred where an expression is expected.
name|CCC_Expression
block|,
comment|/// \brief Code completion occurred where an Objective-C message receiver
comment|/// is expected.
name|CCC_ObjCMessageReceiver
block|,
comment|/// \brief Code completion occurred on the right-hand side of a member
comment|/// access expression using the dot operator.
comment|///
comment|/// The results of this completion are the members of the type being
comment|/// accessed. The type itself is available via
comment|/// \c CodeCompletionContext::getType().
name|CCC_DotMemberAccess
block|,
comment|/// \brief Code completion occurred on the right-hand side of a member
comment|/// access expression using the arrow operator.
comment|///
comment|/// The results of this completion are the members of the type being
comment|/// accessed. The type itself is available via
comment|/// \c CodeCompletionContext::getType().
name|CCC_ArrowMemberAccess
block|,
comment|/// \brief Code completion occurred on the right-hand side of an Objective-C
comment|/// property access expression.
comment|///
comment|/// The results of this completion are the members of the type being
comment|/// accessed. The type itself is available via
comment|/// \c CodeCompletionContext::getType().
name|CCC_ObjCPropertyAccess
block|,
comment|/// \brief Code completion occurred after the "enum" keyword, to indicate
comment|/// an enumeration name.
name|CCC_EnumTag
block|,
comment|/// \brief Code completion occurred after the "union" keyword, to indicate
comment|/// a union name.
name|CCC_UnionTag
block|,
comment|/// \brief Code completion occurred after the "struct" or "class" keyword,
comment|/// to indicate a struct or class name.
name|CCC_ClassOrStructTag
block|,
comment|/// \brief Code completion occurred where a protocol name is expected.
name|CCC_ObjCProtocolName
block|,
comment|/// \brief Code completion occurred where a namespace or namespace alias
comment|/// is expected.
name|CCC_Namespace
block|,
comment|/// \brief Code completion occurred where a type name is expected.
name|CCC_Type
block|,
comment|/// \brief Code completion occurred where a new name is expected.
name|CCC_Name
block|,
comment|/// \brief Code completion occurred where a new name is expected and a
comment|/// qualified name is permissible.
name|CCC_PotentiallyQualifiedName
block|,
comment|/// \brief Code completion occurred where an macro is being defined.
name|CCC_MacroName
block|,
comment|/// \brief Code completion occurred where a macro name is expected
comment|/// (without any arguments, in the case of a function-like macro).
name|CCC_MacroNameUse
block|,
comment|/// \brief Code completion occurred within a preprocessor expression.
name|CCC_PreprocessorExpression
block|,
comment|/// \brief Code completion occurred where a preprocessor directive is
comment|/// expected.
name|CCC_PreprocessorDirective
block|,
comment|/// \brief Code completion occurred in a context where natural language is
comment|/// expected, e.g., a comment or string literal.
comment|///
comment|/// This context usually implies that no completions should be added,
comment|/// unless they come from an appropriate natural-language dictionary.
name|CCC_NaturalLanguage
block|,
comment|/// \brief Code completion for a selector, as in an \@selector expression.
name|CCC_SelectorName
block|,
comment|/// \brief Code completion within a type-qualifier list.
name|CCC_TypeQualifiers
block|,
comment|/// \brief Code completion in a parenthesized expression, which means that
comment|/// we may also have types here in C and Objective-C (as well as in C++).
name|CCC_ParenthesizedExpression
block|,
comment|/// \brief Code completion where an Objective-C instance message is
comment|/// expected.
name|CCC_ObjCInstanceMessage
block|,
comment|/// \brief Code completion where an Objective-C class message is expected.
name|CCC_ObjCClassMessage
block|,
comment|/// \brief Code completion where the name of an Objective-C class is
comment|/// expected.
name|CCC_ObjCInterfaceName
block|,
comment|/// \brief Code completion where an Objective-C category name is expected.
name|CCC_ObjCCategoryName
block|,
comment|/// \brief An unknown context, in which we are recovering from a parsing
comment|/// error and don't know which completions we should give.
name|CCC_Recovery
block|}
enum|;
name|private
label|:
name|enum
name|Kind
name|Kind
decl_stmt|;
comment|/// \brief The type that would prefer to see at this point (e.g., the type
comment|/// of an initializer or function parameter).
name|QualType
name|PreferredType
decl_stmt|;
comment|/// \brief The type of the base object in a member access expression.
name|QualType
name|BaseType
decl_stmt|;
comment|/// \brief The identifiers for Objective-C selector parts.
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|SelIdents
expr_stmt|;
name|public
label|:
comment|/// \brief Construct a new code-completion context of the given kind.
name|CodeCompletionContext
argument_list|(
argument|enum Kind Kind
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|SelIdents
argument_list|(
argument|None
argument_list|)
block|{ }
comment|/// \brief Construct a new code-completion context of the given kind.
name|CodeCompletionContext
argument_list|(
argument|enum Kind Kind
argument_list|,
argument|QualType T
argument_list|,
argument|ArrayRef<IdentifierInfo *> SelIdents = None
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|SelIdents
argument_list|(
argument|SelIdents
argument_list|)
block|{
if|if
condition|(
name|Kind
operator|==
name|CCC_DotMemberAccess
operator|||
name|Kind
operator|==
name|CCC_ArrowMemberAccess
operator|||
name|Kind
operator|==
name|CCC_ObjCPropertyAccess
operator|||
name|Kind
operator|==
name|CCC_ObjCClassMessage
operator|||
name|Kind
operator|==
name|CCC_ObjCInstanceMessage
condition|)
name|BaseType
operator|=
name|T
expr_stmt|;
else|else
name|PreferredType
operator|=
name|T
expr_stmt|;
block|}
comment|/// \brief Retrieve the kind of code-completion context.
block|enum
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// \brief Retrieve the type that this expression would prefer to have, e.g.,
comment|/// if the expression is a variable initializer or a function argument, the
comment|/// type of the corresponding variable or function parameter.
name|QualType
name|getPreferredType
argument_list|()
specifier|const
block|{
return|return
name|PreferredType
return|;
block|}
comment|/// \brief Retrieve the type of the base object in a member-access
comment|/// expression.
name|QualType
name|getBaseType
argument_list|()
specifier|const
block|{
return|return
name|BaseType
return|;
block|}
comment|/// \brief Retrieve the Objective-C selector identifiers.
name|ArrayRef
operator|<
name|IdentifierInfo
operator|*
operator|>
name|getSelIdents
argument_list|()
specifier|const
block|{
return|return
name|SelIdents
return|;
block|}
comment|/// \brief Determines whether we want C++ constructors as results within this
comment|/// context.
name|bool
name|wantConstructorResults
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
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
comment|/// \brief A piece of text that describes the type of an entity or, for
comment|/// functions and methods, the return type.
name|CK_ResultType
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
block|,
comment|/// \brief A colon (':').
name|CK_Colon
block|,
comment|/// \brief A semicolon (';').
name|CK_SemiColon
block|,
comment|/// \brief An '=' sign.
name|CK_Equal
block|,
comment|/// \brief Horizontal whitespace (' ').
name|CK_HorizontalSpace
block|,
comment|/// \brief Vertical whitespace ('\\n' or '\\r\\n', depending on the
comment|/// platform).
name|CK_VerticalSpace
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
name|explicit
name|Chunk
argument_list|(
argument|ChunkKind Kind
argument_list|,
argument|const char *Text =
literal|""
argument_list|)
expr_stmt|;
comment|/// \brief Create a new text chunk.
specifier|static
name|Chunk
name|CreateText
parameter_list|(
specifier|const
name|char
modifier|*
name|Text
parameter_list|)
function_decl|;
comment|/// \brief Create a new optional chunk.
specifier|static
name|Chunk
name|CreateOptional
parameter_list|(
name|CodeCompletionString
modifier|*
name|Optional
parameter_list|)
function_decl|;
comment|/// \brief Create a new placeholder chunk.
specifier|static
name|Chunk
name|CreatePlaceholder
parameter_list|(
specifier|const
name|char
modifier|*
name|Placeholder
parameter_list|)
function_decl|;
comment|/// \brief Create a new informative chunk.
specifier|static
name|Chunk
name|CreateInformative
parameter_list|(
specifier|const
name|char
modifier|*
name|Informative
parameter_list|)
function_decl|;
comment|/// \brief Create a new result type chunk.
specifier|static
name|Chunk
name|CreateResultType
parameter_list|(
specifier|const
name|char
modifier|*
name|ResultType
parameter_list|)
function_decl|;
comment|/// \brief Create a new current-parameter chunk.
specifier|static
name|Chunk
name|CreateCurrentParameter
parameter_list|(
specifier|const
name|char
modifier|*
name|CurrentParameter
parameter_list|)
function_decl|;
block|}
struct|;
name|private
label|:
comment|/// \brief The number of chunks stored in this string.
name|unsigned
name|NumChunks
range|:
literal|16
decl_stmt|;
comment|/// \brief The number of annotations for this code-completion result.
name|unsigned
name|NumAnnotations
range|:
literal|16
decl_stmt|;
comment|/// \brief The priority of this code-completion string.
name|unsigned
name|Priority
range|:
literal|16
decl_stmt|;
comment|/// \brief The availability of this code-completion result.
name|unsigned
name|Availability
range|:
literal|2
decl_stmt|;
comment|/// \brief The name of the parent context.
name|StringRef
name|ParentName
decl_stmt|;
comment|/// \brief A brief documentation comment attached to the declaration of
comment|/// entity being completed by this result.
specifier|const
name|char
modifier|*
name|BriefComment
decl_stmt|;
name|CodeCompletionString
argument_list|(
argument|const CodeCompletionString&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CodeCompletionString
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|CodeCompletionString
argument_list|(
argument|const Chunk *Chunks
argument_list|,
argument|unsigned NumChunks
argument_list|,
argument|unsigned Priority
argument_list|,
argument|CXAvailabilityKind Availability
argument_list|,
argument|const char **Annotations
argument_list|,
argument|unsigned NumAnnotations
argument_list|,
argument|StringRef ParentName
argument_list|,
argument|const char *BriefComment
argument_list|)
empty_stmt|;
operator|~
name|CodeCompletionString
argument_list|()
block|{ }
name|friend
name|class
name|CodeCompletionBuilder
expr_stmt|;
name|friend
name|class
name|CodeCompletionResult
decl_stmt|;
name|public
label|:
typedef|typedef
specifier|const
name|Chunk
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|Chunk
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
operator|+
name|NumChunks
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|NumChunks
operator|==
literal|0
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumChunks
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
name|begin
argument_list|()
index|[
name|I
index|]
return|;
block|}
comment|/// \brief Returns the text in the TypedText chunk.
specifier|const
name|char
operator|*
name|getTypedText
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the priority of this code completion result.
name|unsigned
name|getPriority
argument_list|()
specifier|const
block|{
return|return
name|Priority
return|;
block|}
comment|/// \brief Retrieve the availability of this code completion result.
name|unsigned
name|getAvailability
argument_list|()
specifier|const
block|{
return|return
name|Availability
return|;
block|}
comment|/// \brief Retrieve the number of annotations for this code completion result.
name|unsigned
name|getAnnotationCount
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Retrieve the annotation string specified by \c AnnotationNr.
specifier|const
name|char
modifier|*
name|getAnnotation
argument_list|(
name|unsigned
name|AnnotationNr
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Retrieve the name of the parent context.
name|StringRef
name|getParentContextName
argument_list|()
specifier|const
block|{
return|return
name|ParentName
return|;
block|}
specifier|const
name|char
operator|*
name|getBriefComment
argument_list|()
specifier|const
block|{
return|return
name|BriefComment
return|;
block|}
comment|/// \brief Retrieve a string representation of the code completion string,
comment|/// which is mainly useful for debugging.
name|std
operator|::
name|string
name|getAsString
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief An allocator used specifically for the purpose of code completion.
name|class
name|CodeCompletionAllocator
range|:
name|public
name|llvm
operator|::
name|BumpPtrAllocator
block|{
name|public
operator|:
comment|/// \brief Copy the given string into this allocator.
specifier|const
name|char
operator|*
name|CopyString
argument_list|(
argument|StringRef String
argument_list|)
block|;
comment|/// \brief Copy the given string into this allocator.
specifier|const
name|char
operator|*
name|CopyString
argument_list|(
argument|Twine String
argument_list|)
block|;
comment|// \brief Copy the given string into this allocator.
specifier|const
name|char
operator|*
name|CopyString
argument_list|(
argument|const char *String
argument_list|)
block|{
return|return
name|CopyString
argument_list|(
name|StringRef
argument_list|(
name|String
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Copy the given string into this allocator.
specifier|const
name|char
operator|*
name|CopyString
argument_list|(
argument|const std::string&String
argument_list|)
block|{
return|return
name|CopyString
argument_list|(
name|StringRef
argument_list|(
name|String
argument_list|)
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// \brief Allocator for a cached set of global code completions.
name|class
name|GlobalCodeCompletionAllocator
operator|:
name|public
name|CodeCompletionAllocator
block|,
name|public
name|RefCountedBase
operator|<
name|GlobalCodeCompletionAllocator
operator|>
block|{  }
block|;
name|class
name|CodeCompletionTUInfo
block|{
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
block|,
name|StringRef
operator|>
name|ParentNames
block|;
name|IntrusiveRefCntPtr
operator|<
name|GlobalCodeCompletionAllocator
operator|>
name|AllocatorRef
block|;
name|public
operator|:
name|explicit
name|CodeCompletionTUInfo
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|GlobalCodeCompletionAllocator
operator|>
name|Allocator
argument_list|)
operator|:
name|AllocatorRef
argument_list|(
argument|Allocator
argument_list|)
block|{ }
name|IntrusiveRefCntPtr
operator|<
name|GlobalCodeCompletionAllocator
operator|>
name|getAllocatorRef
argument_list|()
specifier|const
block|{
return|return
name|AllocatorRef
return|;
block|}
name|CodeCompletionAllocator
operator|&
name|getAllocator
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|AllocatorRef
argument_list|)
block|;
return|return
operator|*
name|AllocatorRef
return|;
block|}
name|StringRef
name|getParentName
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|)
block|; }
block|;  }
comment|// end namespace clang
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|CodeCompletionString
operator|::
name|Chunk
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;   }
block|; }
name|namespace
name|clang
block|{
comment|/// \brief A builder class used to construct new code-completion strings.
name|class
name|CodeCompletionBuilder
block|{
name|public
operator|:
typedef|typedef
name|CodeCompletionString
operator|::
name|Chunk
name|Chunk
expr_stmt|;
name|private
operator|:
name|CodeCompletionAllocator
operator|&
name|Allocator
block|;
name|CodeCompletionTUInfo
operator|&
name|CCTUInfo
block|;
name|unsigned
name|Priority
block|;
name|CXAvailabilityKind
name|Availability
block|;
name|StringRef
name|ParentName
block|;
specifier|const
name|char
operator|*
name|BriefComment
block|;
comment|/// \brief The chunks stored in this string.
name|SmallVector
operator|<
name|Chunk
block|,
literal|4
operator|>
name|Chunks
block|;
name|SmallVector
operator|<
specifier|const
name|char
operator|*
block|,
literal|2
operator|>
name|Annotations
block|;
name|public
operator|:
name|CodeCompletionBuilder
argument_list|(
name|CodeCompletionAllocator
operator|&
name|Allocator
argument_list|,
name|CodeCompletionTUInfo
operator|&
name|CCTUInfo
argument_list|)
operator|:
name|Allocator
argument_list|(
name|Allocator
argument_list|)
block|,
name|CCTUInfo
argument_list|(
name|CCTUInfo
argument_list|)
block|,
name|Priority
argument_list|(
literal|0
argument_list|)
block|,
name|Availability
argument_list|(
name|CXAvailability_Available
argument_list|)
block|,
name|BriefComment
argument_list|(
argument|NULL
argument_list|)
block|{ }
name|CodeCompletionBuilder
argument_list|(
argument|CodeCompletionAllocator&Allocator
argument_list|,
argument|CodeCompletionTUInfo&CCTUInfo
argument_list|,
argument|unsigned Priority
argument_list|,
argument|CXAvailabilityKind Availability
argument_list|)
operator|:
name|Allocator
argument_list|(
name|Allocator
argument_list|)
block|,
name|CCTUInfo
argument_list|(
name|CCTUInfo
argument_list|)
block|,
name|Priority
argument_list|(
name|Priority
argument_list|)
block|,
name|Availability
argument_list|(
name|Availability
argument_list|)
block|,
name|BriefComment
argument_list|(
argument|NULL
argument_list|)
block|{ }
comment|/// \brief Retrieve the allocator into which the code completion
comment|/// strings should be allocated.
name|CodeCompletionAllocator
operator|&
name|getAllocator
argument_list|()
specifier|const
block|{
return|return
name|Allocator
return|;
block|}
name|CodeCompletionTUInfo
operator|&
name|getCodeCompletionTUInfo
argument_list|()
specifier|const
block|{
return|return
name|CCTUInfo
return|;
block|}
comment|/// \brief Take the resulting completion string.
comment|///
comment|/// This operation can only be performed once.
name|CodeCompletionString
operator|*
name|TakeString
argument_list|()
block|;
comment|/// \brief Add a new typed-text chunk.
name|void
name|AddTypedTextChunk
argument_list|(
specifier|const
name|char
operator|*
name|Text
argument_list|)
block|;
comment|/// \brief Add a new text chunk.
name|void
name|AddTextChunk
argument_list|(
specifier|const
name|char
operator|*
name|Text
argument_list|)
block|;
comment|/// \brief Add a new optional chunk.
name|void
name|AddOptionalChunk
argument_list|(
name|CodeCompletionString
operator|*
name|Optional
argument_list|)
block|;
comment|/// \brief Add a new placeholder chunk.
name|void
name|AddPlaceholderChunk
argument_list|(
specifier|const
name|char
operator|*
name|Placeholder
argument_list|)
block|;
comment|/// \brief Add a new informative chunk.
name|void
name|AddInformativeChunk
argument_list|(
specifier|const
name|char
operator|*
name|Text
argument_list|)
block|;
comment|/// \brief Add a new result-type chunk.
name|void
name|AddResultTypeChunk
argument_list|(
specifier|const
name|char
operator|*
name|ResultType
argument_list|)
block|;
comment|/// \brief Add a new current-parameter chunk.
name|void
name|AddCurrentParameterChunk
argument_list|(
specifier|const
name|char
operator|*
name|CurrentParameter
argument_list|)
block|;
comment|/// \brief Add a new chunk.
name|void
name|AddChunk
argument_list|(
argument|CodeCompletionString::ChunkKind CK
argument_list|,
argument|const char *Text =
literal|""
argument_list|)
block|;
name|void
name|AddAnnotation
argument_list|(
argument|const char *A
argument_list|)
block|{
name|Annotations
operator|.
name|push_back
argument_list|(
name|A
argument_list|)
block|; }
comment|/// \brief Add the parent context information to this code completion.
name|void
name|addParentContext
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|)
block|;
specifier|const
name|char
operator|*
name|getBriefComment
argument_list|()
specifier|const
block|{
return|return
name|BriefComment
return|;
block|}
name|void
name|addBriefComment
argument_list|(
argument|StringRef Comment
argument_list|)
block|;
name|StringRef
name|getParentName
argument_list|()
specifier|const
block|{
return|return
name|ParentName
return|;
block|}
expr|}
block|;
comment|/// \brief Captures a result of code completion.
name|class
name|CodeCompletionResult
block|{
name|public
operator|:
comment|/// \brief Describes the kind of result generated.
expr|enum
name|ResultKind
block|{
name|RK_Declaration
operator|=
literal|0
block|,
comment|///< Refers to a declaration
name|RK_Keyword
block|,
comment|///< Refers to a keyword or symbol.
name|RK_Macro
block|,
comment|///< Refers to a macro
name|RK_Pattern
comment|///< Refers to a precomputed pattern.
block|}
block|;
comment|/// \brief When Kind == RK_Declaration or RK_Pattern, the declaration we are
comment|/// referring to. In the latter case, the declaration might be NULL.
specifier|const
name|NamedDecl
operator|*
name|Declaration
block|;
expr|union
block|{
comment|/// \brief When Kind == RK_Keyword, the string representing the keyword
comment|/// or symbol's spelling.
specifier|const
name|char
operator|*
name|Keyword
block|;
comment|/// \brief When Kind == RK_Pattern, the code-completion string that
comment|/// describes the completion text to insert.
name|CodeCompletionString
operator|*
name|Pattern
block|;
comment|/// \brief When Kind == RK_Macro, the identifier that refers to a macro.
specifier|const
name|IdentifierInfo
operator|*
name|Macro
block|;   }
block|;
comment|/// \brief The priority of this particular code-completion result.
name|unsigned
name|Priority
block|;
comment|/// \brief Specifies which parameter (of a function, Objective-C method,
comment|/// macro, etc.) we should start with when formatting the result.
name|unsigned
name|StartParameter
block|;
comment|/// \brief The kind of result stored here.
name|ResultKind
name|Kind
block|;
comment|/// \brief The cursor kind that describes this result.
name|CXCursorKind
name|CursorKind
block|;
comment|/// \brief The availability of this result.
name|CXAvailabilityKind
name|Availability
block|;
comment|/// \brief Whether this result is hidden by another name.
name|bool
name|Hidden
operator|:
literal|1
block|;
comment|/// \brief Whether this result was found via lookup into a base class.
name|bool
name|QualifierIsInformative
operator|:
literal|1
block|;
comment|/// \brief Whether this declaration is the beginning of a
comment|/// nested-name-specifier and, therefore, should be followed by '::'.
name|bool
name|StartsNestedNameSpecifier
operator|:
literal|1
block|;
comment|/// \brief Whether all parameters (of a function, Objective-C
comment|/// method, etc.) should be considered "informative".
name|bool
name|AllParametersAreInformative
operator|:
literal|1
block|;
comment|/// \brief Whether we're completing a declaration of the given entity,
comment|/// rather than a use of that entity.
name|bool
name|DeclaringEntity
operator|:
literal|1
block|;
comment|/// \brief If the result should have a nested-name-specifier, this is it.
comment|/// When \c QualifierIsInformative, the nested-name-specifier is
comment|/// informative rather than required.
name|NestedNameSpecifier
operator|*
name|Qualifier
block|;
comment|/// \brief Build a result that refers to a declaration.
name|CodeCompletionResult
argument_list|(
argument|const NamedDecl *Declaration
argument_list|,
argument|unsigned Priority
argument_list|,
argument|NestedNameSpecifier *Qualifier =
literal|0
argument_list|,
argument|bool QualifierIsInformative = false
argument_list|,
argument|bool Accessible = true
argument_list|)
operator|:
name|Declaration
argument_list|(
name|Declaration
argument_list|)
block|,
name|Priority
argument_list|(
name|Priority
argument_list|)
block|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
block|,
name|Kind
argument_list|(
name|RK_Declaration
argument_list|)
block|,
name|Availability
argument_list|(
name|CXAvailability_Available
argument_list|)
block|,
name|Hidden
argument_list|(
name|false
argument_list|)
block|,
name|QualifierIsInformative
argument_list|(
name|QualifierIsInformative
argument_list|)
block|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
block|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
block|,
name|DeclaringEntity
argument_list|(
name|false
argument_list|)
block|,
name|Qualifier
argument_list|(
argument|Qualifier
argument_list|)
block|{
name|computeCursorKindAndAvailability
argument_list|(
name|Accessible
argument_list|)
block|;   }
comment|/// \brief Build a result that refers to a keyword or symbol.
name|CodeCompletionResult
argument_list|(
argument|const char *Keyword
argument_list|,
argument|unsigned Priority = CCP_Keyword
argument_list|)
operator|:
name|Declaration
argument_list|(
literal|0
argument_list|)
block|,
name|Keyword
argument_list|(
name|Keyword
argument_list|)
block|,
name|Priority
argument_list|(
name|Priority
argument_list|)
block|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
block|,
name|Kind
argument_list|(
name|RK_Keyword
argument_list|)
block|,
name|CursorKind
argument_list|(
name|CXCursor_NotImplemented
argument_list|)
block|,
name|Availability
argument_list|(
name|CXAvailability_Available
argument_list|)
block|,
name|Hidden
argument_list|(
name|false
argument_list|)
block|,
name|QualifierIsInformative
argument_list|(
literal|0
argument_list|)
block|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
block|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
block|,
name|DeclaringEntity
argument_list|(
name|false
argument_list|)
block|,
name|Qualifier
argument_list|(
literal|0
argument_list|)
block|{   }
comment|/// \brief Build a result that refers to a macro.
name|CodeCompletionResult
argument_list|(
argument|const IdentifierInfo *Macro
argument_list|,
argument|unsigned Priority = CCP_Macro
argument_list|)
operator|:
name|Declaration
argument_list|(
literal|0
argument_list|)
block|,
name|Macro
argument_list|(
name|Macro
argument_list|)
block|,
name|Priority
argument_list|(
name|Priority
argument_list|)
block|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
block|,
name|Kind
argument_list|(
name|RK_Macro
argument_list|)
block|,
name|CursorKind
argument_list|(
name|CXCursor_MacroDefinition
argument_list|)
block|,
name|Availability
argument_list|(
name|CXAvailability_Available
argument_list|)
block|,
name|Hidden
argument_list|(
name|false
argument_list|)
block|,
name|QualifierIsInformative
argument_list|(
literal|0
argument_list|)
block|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
block|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
block|,
name|DeclaringEntity
argument_list|(
name|false
argument_list|)
block|,
name|Qualifier
argument_list|(
literal|0
argument_list|)
block|{   }
comment|/// \brief Build a result that refers to a pattern.
name|CodeCompletionResult
argument_list|(
argument|CodeCompletionString *Pattern
argument_list|,
argument|unsigned Priority = CCP_CodePattern
argument_list|,
argument|CXCursorKind CursorKind = CXCursor_NotImplemented
argument_list|,
argument|CXAvailabilityKind Availability = CXAvailability_Available
argument_list|,
argument|const NamedDecl *D =
literal|0
argument_list|)
operator|:
name|Declaration
argument_list|(
name|D
argument_list|)
block|,
name|Pattern
argument_list|(
name|Pattern
argument_list|)
block|,
name|Priority
argument_list|(
name|Priority
argument_list|)
block|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
block|,
name|Kind
argument_list|(
name|RK_Pattern
argument_list|)
block|,
name|CursorKind
argument_list|(
name|CursorKind
argument_list|)
block|,
name|Availability
argument_list|(
name|Availability
argument_list|)
block|,
name|Hidden
argument_list|(
name|false
argument_list|)
block|,
name|QualifierIsInformative
argument_list|(
literal|0
argument_list|)
block|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
block|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
block|,
name|DeclaringEntity
argument_list|(
name|false
argument_list|)
block|,
name|Qualifier
argument_list|(
literal|0
argument_list|)
block|{   }
comment|/// \brief Build a result that refers to a pattern with an associated
comment|/// declaration.
name|CodeCompletionResult
argument_list|(
argument|CodeCompletionString *Pattern
argument_list|,
argument|NamedDecl *D
argument_list|,
argument|unsigned Priority
argument_list|)
operator|:
name|Declaration
argument_list|(
name|D
argument_list|)
block|,
name|Pattern
argument_list|(
name|Pattern
argument_list|)
block|,
name|Priority
argument_list|(
name|Priority
argument_list|)
block|,
name|StartParameter
argument_list|(
literal|0
argument_list|)
block|,
name|Kind
argument_list|(
name|RK_Pattern
argument_list|)
block|,
name|Availability
argument_list|(
name|CXAvailability_Available
argument_list|)
block|,
name|Hidden
argument_list|(
name|false
argument_list|)
block|,
name|QualifierIsInformative
argument_list|(
name|false
argument_list|)
block|,
name|StartsNestedNameSpecifier
argument_list|(
name|false
argument_list|)
block|,
name|AllParametersAreInformative
argument_list|(
name|false
argument_list|)
block|,
name|DeclaringEntity
argument_list|(
name|false
argument_list|)
block|,
name|Qualifier
argument_list|(
literal|0
argument_list|)
block|{
name|computeCursorKindAndAvailability
argument_list|()
block|;   }
comment|/// \brief Retrieve the declaration stored in this result.
specifier|const
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
comment|///
comment|/// \param S The semantic analysis that created the result.
comment|///
comment|/// \param Allocator The allocator that will be used to allocate the
comment|/// string itself.
name|CodeCompletionString
operator|*
name|CreateCodeCompletionString
argument_list|(
argument|Sema&S
argument_list|,
argument|CodeCompletionAllocator&Allocator
argument_list|,
argument|CodeCompletionTUInfo&CCTUInfo
argument_list|,
argument|bool IncludeBriefComments
argument_list|)
block|;
name|CodeCompletionString
operator|*
name|CreateCodeCompletionString
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|Preprocessor&PP
argument_list|,
argument|CodeCompletionAllocator&Allocator
argument_list|,
argument|CodeCompletionTUInfo&CCTUInfo
argument_list|,
argument|bool IncludeBriefComments
argument_list|)
block|;
name|private
operator|:
name|void
name|computeCursorKindAndAvailability
argument_list|(
argument|bool Accessible = true
argument_list|)
block|; }
block|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|CodeCompletionResult
operator|&
name|X
expr|,
specifier|const
name|CodeCompletionResult
operator|&
name|Y
operator|)
block|;
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|CodeCompletionResult
operator|&
name|X
expr|,
specifier|const
name|CodeCompletionResult
operator|&
name|Y
operator|)
block|{
return|return
name|Y
operator|<
name|X
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|CodeCompletionResult
operator|&
name|X
expr|,
specifier|const
name|CodeCompletionResult
operator|&
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|Y
operator|<
name|X
operator|)
return|;
block|}
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|CodeCompletionResult
operator|&
name|X
expr|,
specifier|const
name|CodeCompletionResult
operator|&
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|X
operator|<
name|Y
operator|)
return|;
block|}
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
expr|,
specifier|const
name|CodeCompletionString
operator|&
name|CCS
operator|)
block|;
comment|/// \brief Abstract interface for a consumer of code-completion
comment|/// information.
name|class
name|CodeCompleteConsumer
block|{
name|protected
operator|:
specifier|const
name|CodeCompleteOptions
name|CodeCompleteOpts
block|;
comment|/// \brief Whether the output format for the code-completion consumer is
comment|/// binary.
name|bool
name|OutputIsBinary
block|;
name|public
operator|:
name|class
name|OverloadCandidate
block|{
name|public
operator|:
comment|/// \brief Describes the type of overload candidate.
expr|enum
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
block|;
name|private
operator|:
comment|/// \brief The kind of overload candidate.
name|CandidateKind
name|Kind
block|;
expr|union
block|{
comment|/// \brief The function overload candidate, available when
comment|/// Kind == CK_Function.
name|FunctionDecl
operator|*
name|Function
block|;
comment|/// \brief The function template overload candidate, available when
comment|/// Kind == CK_FunctionTemplate.
name|FunctionTemplateDecl
operator|*
name|FunctionTemplate
block|;
comment|/// \brief The function type that describes the entity being called,
comment|/// when Kind == CK_FunctionType.
specifier|const
name|FunctionType
operator|*
name|Type
block|;     }
block|;
name|public
operator|:
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
block|,
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
block|,
name|FunctionTemplate
argument_list|(
argument|FunctionTemplateDecl
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
block|,
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
block|;
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
block|;
comment|/// \brief Create a new code-completion string that describes the function
comment|/// signature of this overload candidate.
name|CodeCompletionString
operator|*
name|CreateSignatureString
argument_list|(
argument|unsigned CurrentArg
argument_list|,
argument|Sema&S
argument_list|,
argument|CodeCompletionAllocator&Allocator
argument_list|,
argument|CodeCompletionTUInfo&CCTUInfo
argument_list|)
specifier|const
block|;   }
block|;
name|CodeCompleteConsumer
argument_list|(
argument|const CodeCompleteOptions&CodeCompleteOpts
argument_list|,
argument|bool OutputIsBinary
argument_list|)
operator|:
name|CodeCompleteOpts
argument_list|(
name|CodeCompleteOpts
argument_list|)
block|,
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
name|CodeCompleteOpts
operator|.
name|IncludeMacros
return|;
block|}
comment|/// \brief Whether the code-completion consumer wants to see code patterns.
name|bool
name|includeCodePatterns
argument_list|()
specifier|const
block|{
return|return
name|CodeCompleteOpts
operator|.
name|IncludeCodePatterns
return|;
block|}
comment|/// \brief Whether to include global (top-level) declaration results.
name|bool
name|includeGlobals
argument_list|()
specifier|const
block|{
return|return
name|CodeCompleteOpts
operator|.
name|IncludeGlobals
return|;
block|}
comment|/// \brief Whether to include brief documentation comments within the set of
comment|/// code completions returned.
name|bool
name|includeBriefComments
argument_list|()
specifier|const
block|{
return|return
name|CodeCompleteOpts
operator|.
name|IncludeBriefComments
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
block|;
comment|/// \name Code-completion callbacks
comment|//@{
comment|/// \brief Process the finalized code-completion results.
name|virtual
name|void
name|ProcessCodeCompleteResults
argument_list|(
argument|Sema&S
argument_list|,
argument|CodeCompletionContext Context
argument_list|,
argument|CodeCompletionResult *Results
argument_list|,
argument|unsigned NumResults
argument_list|)
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
argument_list|(
argument|Sema&S
argument_list|,
argument|unsigned CurrentArg
argument_list|,
argument|OverloadCandidate *Candidates
argument_list|,
argument|unsigned NumCandidates
argument_list|)
block|{ }
comment|//@}
comment|/// \brief Retrieve the allocator that will be used to allocate
comment|/// code completion strings.
name|virtual
name|CodeCompletionAllocator
operator|&
name|getAllocator
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|CodeCompletionTUInfo
operator|&
name|getCodeCompletionTUInfo
argument_list|()
operator|=
literal|0
block|; }
block|;
comment|/// \brief A simple code-completion consumer that prints the results it
comment|/// receives in a simple format.
name|class
name|PrintingCodeCompleteConsumer
operator|:
name|public
name|CodeCompleteConsumer
block|{
comment|/// \brief The raw output stream.
name|raw_ostream
operator|&
name|OS
block|;
name|CodeCompletionTUInfo
name|CCTUInfo
block|;
name|public
operator|:
comment|/// \brief Create a new printing code-completion consumer that prints its
comment|/// results to the given raw output stream.
name|PrintingCodeCompleteConsumer
argument_list|(
specifier|const
name|CodeCompleteOptions
operator|&
name|CodeCompleteOpts
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|CodeCompleteConsumer
argument_list|(
name|CodeCompleteOpts
argument_list|,
name|false
argument_list|)
block|,
name|OS
argument_list|(
name|OS
argument_list|)
block|,
name|CCTUInfo
argument_list|(
argument|new GlobalCodeCompletionAllocator
argument_list|)
block|{}
comment|/// \brief Prints the finalized code-completion results.
name|virtual
name|void
name|ProcessCodeCompleteResults
argument_list|(
argument|Sema&S
argument_list|,
argument|CodeCompletionContext Context
argument_list|,
argument|CodeCompletionResult *Results
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
block|;
name|virtual
name|CodeCompletionAllocator
operator|&
name|getAllocator
argument_list|()
block|{
return|return
name|CCTUInfo
operator|.
name|getAllocator
argument_list|()
return|;
block|}
name|virtual
name|CodeCompletionTUInfo
operator|&
name|getCodeCompletionTUInfo
argument_list|()
block|{
return|return
name|CCTUInfo
return|;
block|}
expr|}
block|;  }
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

