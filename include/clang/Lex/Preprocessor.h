begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Preprocessor.h - C Language Family Preprocessor --------*- C++ -*-===//
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
comment|/// \brief Defines the clang::Preprocessor interface.
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
name|LLVM_CLANG_LEX_PREPROCESSOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PREPROCESSOR_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Builtins.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/Lexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/MacroInfo.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/ModuleMap.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PPCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PTHLexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/TokenLexer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/TinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Registry.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|template
operator|<
name|unsigned
name|InternalLen
operator|>
name|class
name|SmallString
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SourceManager
decl_stmt|;
name|class
name|ExternalPreprocessorSource
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|MemoryBufferCache
decl_stmt|;
name|class
name|PragmaNamespace
decl_stmt|;
name|class
name|PragmaHandler
decl_stmt|;
name|class
name|CommentHandler
decl_stmt|;
name|class
name|ScratchBuffer
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|PPCallbacks
decl_stmt|;
name|class
name|CodeCompletionHandler
decl_stmt|;
name|class
name|DirectoryLookup
decl_stmt|;
name|class
name|PreprocessingRecord
decl_stmt|;
name|class
name|ModuleLoader
decl_stmt|;
name|class
name|PTHManager
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
comment|/// \brief Stores token information for comparing actual tokens with
comment|/// predefined values.  Only handles simple tokens and identifiers.
name|class
name|TokenValue
block|{
name|tok
operator|::
name|TokenKind
name|Kind
expr_stmt|;
name|IdentifierInfo
modifier|*
name|II
decl_stmt|;
name|public
label|:
name|TokenValue
argument_list|(
argument|tok::TokenKind Kind
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|II
argument_list|(
argument|nullptr
argument_list|)
block|{
name|assert
argument_list|(
name|Kind
operator|!=
name|tok
operator|::
name|raw_identifier
operator|&&
literal|"Raw identifiers are not supported."
argument_list|)
block|;
name|assert
argument_list|(
name|Kind
operator|!=
name|tok
operator|::
name|identifier
operator|&&
literal|"Identifiers should be created by TokenValue(IdentifierInfo *)"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|tok
operator|::
name|isLiteral
argument_list|(
name|Kind
argument_list|)
operator|&&
literal|"Literals are not supported."
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|tok
operator|::
name|isAnnotation
argument_list|(
name|Kind
argument_list|)
operator|&&
literal|"Annotations are not supported."
argument_list|)
block|;   }
name|TokenValue
argument_list|(
name|IdentifierInfo
operator|*
name|II
argument_list|)
operator|:
name|Kind
argument_list|(
name|tok
operator|::
name|identifier
argument_list|)
operator|,
name|II
argument_list|(
argument|II
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Token
operator|&
name|Tok
operator|)
specifier|const
block|{
return|return
name|Tok
operator|.
name|getKind
argument_list|()
operator|==
name|Kind
operator|&&
operator|(
operator|!
name|II
operator|||
name|II
operator|==
name|Tok
operator|.
name|getIdentifierInfo
argument_list|()
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Context in which macro name is used.
enum|enum
name|MacroUse
block|{
name|MU_Other
init|=
literal|0
block|,
comment|// other than #define or #undef
name|MU_Define
init|=
literal|1
block|,
comment|// macro name specified in #define
name|MU_Undef
init|=
literal|2
comment|// macro name specified in #undef
block|}
enum|;
comment|/// \brief Engages in a tight little dance with the lexer to efficiently
comment|/// preprocess tokens.
comment|///
comment|/// Lexers know only about tokens within a single source file, and don't
comment|/// know anything about preprocessor-level issues like the \#include stack,
comment|/// token expansion, etc.
name|class
name|Preprocessor
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|PreprocessorOptions
operator|>
name|PPOpts
expr_stmt|;
name|DiagnosticsEngine
modifier|*
name|Diags
decl_stmt|;
name|LangOptions
modifier|&
name|LangOpts
decl_stmt|;
specifier|const
name|TargetInfo
modifier|*
name|Target
decl_stmt|;
specifier|const
name|TargetInfo
modifier|*
name|AuxTarget
decl_stmt|;
name|FileManager
modifier|&
name|FileMgr
decl_stmt|;
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|MemoryBufferCache
modifier|&
name|PCMCache
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ScratchBuffer
operator|>
name|ScratchBuf
expr_stmt|;
name|HeaderSearch
modifier|&
name|HeaderInfo
decl_stmt|;
name|ModuleLoader
modifier|&
name|TheModuleLoader
decl_stmt|;
comment|/// \brief External source of macros.
name|ExternalPreprocessorSource
modifier|*
name|ExternalSource
decl_stmt|;
comment|/// An optional PTHManager object used for getting tokens from
comment|/// a token cache rather than lexing the original source file.
name|std
operator|::
name|unique_ptr
operator|<
name|PTHManager
operator|>
name|PTH
expr_stmt|;
comment|/// A BumpPtrAllocator object used to quickly allocate and release
comment|/// objects internal to the Preprocessor.
name|llvm
operator|::
name|BumpPtrAllocator
name|BP
expr_stmt|;
comment|/// Identifiers for builtin macros and other builtins.
name|IdentifierInfo
modifier|*
name|Ident__LINE__
decl_stmt|,
modifier|*
name|Ident__FILE__
decl_stmt|;
comment|// __LINE__, __FILE__
name|IdentifierInfo
modifier|*
name|Ident__DATE__
decl_stmt|,
modifier|*
name|Ident__TIME__
decl_stmt|;
comment|// __DATE__, __TIME__
name|IdentifierInfo
modifier|*
name|Ident__INCLUDE_LEVEL__
decl_stmt|;
comment|// __INCLUDE_LEVEL__
name|IdentifierInfo
modifier|*
name|Ident__BASE_FILE__
decl_stmt|;
comment|// __BASE_FILE__
name|IdentifierInfo
modifier|*
name|Ident__TIMESTAMP__
decl_stmt|;
comment|// __TIMESTAMP__
name|IdentifierInfo
modifier|*
name|Ident__COUNTER__
decl_stmt|;
comment|// __COUNTER__
name|IdentifierInfo
modifier|*
name|Ident_Pragma
decl_stmt|,
modifier|*
name|Ident__pragma
decl_stmt|;
comment|// _Pragma, __pragma
name|IdentifierInfo
modifier|*
name|Ident__identifier
decl_stmt|;
comment|// __identifier
name|IdentifierInfo
modifier|*
name|Ident__VA_ARGS__
decl_stmt|;
comment|// __VA_ARGS__
name|IdentifierInfo
modifier|*
name|Ident__has_feature
decl_stmt|;
comment|// __has_feature
name|IdentifierInfo
modifier|*
name|Ident__has_extension
decl_stmt|;
comment|// __has_extension
name|IdentifierInfo
modifier|*
name|Ident__has_builtin
decl_stmt|;
comment|// __has_builtin
name|IdentifierInfo
modifier|*
name|Ident__has_attribute
decl_stmt|;
comment|// __has_attribute
name|IdentifierInfo
modifier|*
name|Ident__has_include
decl_stmt|;
comment|// __has_include
name|IdentifierInfo
modifier|*
name|Ident__has_include_next
decl_stmt|;
comment|// __has_include_next
name|IdentifierInfo
modifier|*
name|Ident__has_warning
decl_stmt|;
comment|// __has_warning
name|IdentifierInfo
modifier|*
name|Ident__is_identifier
decl_stmt|;
comment|// __is_identifier
name|IdentifierInfo
modifier|*
name|Ident__building_module
decl_stmt|;
comment|// __building_module
name|IdentifierInfo
modifier|*
name|Ident__MODULE__
decl_stmt|;
comment|// __MODULE__
name|IdentifierInfo
modifier|*
name|Ident__has_cpp_attribute
decl_stmt|;
comment|// __has_cpp_attribute
name|IdentifierInfo
modifier|*
name|Ident__has_declspec
decl_stmt|;
comment|// __has_declspec_attribute
name|SourceLocation
name|DATELoc
decl_stmt|,
name|TIMELoc
decl_stmt|;
name|unsigned
name|CounterValue
decl_stmt|;
comment|// Next __COUNTER__ value.
enum|enum
block|{
comment|/// \brief Maximum depth of \#includes.
name|MaxAllowedIncludeStackDepth
init|=
literal|200
block|}
enum|;
comment|// State that is set before the preprocessor begins.
name|bool
name|KeepComments
range|:
literal|1
decl_stmt|;
name|bool
name|KeepMacroComments
range|:
literal|1
decl_stmt|;
name|bool
name|SuppressIncludeNotFoundError
range|:
literal|1
decl_stmt|;
comment|// State that changes while the preprocessor runs:
name|bool
name|InMacroArgs
range|:
literal|1
decl_stmt|;
comment|// True if parsing fn macro invocation args.
comment|/// Whether the preprocessor owns the header search object.
name|bool
name|OwnsHeaderSearch
range|:
literal|1
decl_stmt|;
comment|/// True if macro expansion is disabled.
name|bool
name|DisableMacroExpansion
range|:
literal|1
decl_stmt|;
comment|/// Temporarily disables DisableMacroExpansion (i.e. enables expansion)
comment|/// when parsing preprocessor directives.
name|bool
name|MacroExpansionInDirectivesOverride
range|:
literal|1
decl_stmt|;
name|class
name|ResetMacroExpansionHelper
decl_stmt|;
comment|/// \brief Whether we have already loaded macros from the external source.
name|mutable
name|bool
name|ReadMacrosFromExternalSource
range|:
literal|1
decl_stmt|;
comment|/// \brief True if pragmas are enabled.
name|bool
name|PragmasEnabled
range|:
literal|1
decl_stmt|;
comment|/// \brief True if the current build action is a preprocessing action.
name|bool
name|PreprocessedOutput
range|:
literal|1
decl_stmt|;
comment|/// \brief True if we are currently preprocessing a #if or #elif directive
name|bool
name|ParsingIfOrElifDirective
decl_stmt|;
comment|/// \brief True if we are pre-expanding macro arguments.
name|bool
name|InMacroArgPreExpansion
decl_stmt|;
comment|/// \brief Mapping/lookup information for all identifiers in
comment|/// the program, including program keywords.
name|mutable
name|IdentifierTable
name|Identifiers
decl_stmt|;
comment|/// \brief This table contains all the selectors in the program.
comment|///
comment|/// Unlike IdentifierTable above, this table *isn't* populated by the
comment|/// preprocessor. It is declared/expanded here because its role/lifetime is
comment|/// conceptually similar to the IdentifierTable. In addition, the current
comment|/// control flow (in clang::ParseAST()), make it convenient to put here.
comment|///
comment|/// FIXME: Make sure the lifetime of Identifiers/Selectors *isn't* tied to
comment|/// the lifetime of the preprocessor.
name|SelectorTable
name|Selectors
decl_stmt|;
comment|/// \brief Information about builtins.
name|Builtin
operator|::
name|Context
name|BuiltinInfo
expr_stmt|;
comment|/// \brief Tracks all of the pragmas that the client registered
comment|/// with this preprocessor.
name|std
operator|::
name|unique_ptr
operator|<
name|PragmaNamespace
operator|>
name|PragmaHandlers
expr_stmt|;
comment|/// \brief Pragma handlers of the original source is stored here during the
comment|/// parsing of a model file.
name|std
operator|::
name|unique_ptr
operator|<
name|PragmaNamespace
operator|>
name|PragmaHandlersBackup
expr_stmt|;
comment|/// \brief Tracks all of the comment handlers that the client registered
comment|/// with this preprocessor.
name|std
operator|::
name|vector
operator|<
name|CommentHandler
operator|*
operator|>
name|CommentHandlers
expr_stmt|;
comment|/// \brief True if we want to ignore EOF token and continue later on (thus
comment|/// avoid tearing the Lexer and etc. down).
name|bool
name|IncrementalProcessing
decl_stmt|;
comment|/// The kind of translation unit we are processing.
name|TranslationUnitKind
name|TUKind
decl_stmt|;
comment|/// \brief The code-completion handler.
name|CodeCompletionHandler
modifier|*
name|CodeComplete
decl_stmt|;
comment|/// \brief The file that we're performing code-completion for, if any.
specifier|const
name|FileEntry
modifier|*
name|CodeCompletionFile
decl_stmt|;
comment|/// \brief The offset in file for the code-completion point.
name|unsigned
name|CodeCompletionOffset
decl_stmt|;
comment|/// \brief The location for the code-completion point. This gets instantiated
comment|/// when the CodeCompletionFile gets \#include'ed for preprocessing.
name|SourceLocation
name|CodeCompletionLoc
decl_stmt|;
comment|/// \brief The start location for the file of the code-completion point.
comment|///
comment|/// This gets instantiated when the CodeCompletionFile gets \#include'ed
comment|/// for preprocessing.
name|SourceLocation
name|CodeCompletionFileLoc
decl_stmt|;
comment|/// \brief The source location of the \c import contextual keyword we just
comment|/// lexed, if any.
name|SourceLocation
name|ModuleImportLoc
decl_stmt|;
comment|/// \brief The module import path that we're currently processing.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SourceLocation
operator|>
operator|,
literal|2
operator|>
name|ModuleImportPath
expr_stmt|;
comment|/// \brief Whether the last token we lexed was an '@'.
name|bool
name|LastTokenWasAt
decl_stmt|;
comment|/// \brief Whether the module import expects an identifier next. Otherwise,
comment|/// it expects a '.' or ';'.
name|bool
name|ModuleImportExpectsIdentifier
decl_stmt|;
comment|/// \brief The source location of the currently-active
comment|/// \#pragma clang arc_cf_code_audited begin.
name|SourceLocation
name|PragmaARCCFCodeAuditedLoc
decl_stmt|;
comment|/// \brief The source location of the currently-active
comment|/// \#pragma clang assume_nonnull begin.
name|SourceLocation
name|PragmaAssumeNonNullLoc
decl_stmt|;
comment|/// \brief True if we hit the code-completion point.
name|bool
name|CodeCompletionReached
decl_stmt|;
comment|/// \brief The code completion token containing the information
comment|/// on the stem that is to be code completed.
name|IdentifierInfo
modifier|*
name|CodeCompletionII
decl_stmt|;
comment|/// \brief The directory that the main file should be considered to occupy,
comment|/// if it does not correspond to a real file (as happens when building a
comment|/// module).
specifier|const
name|DirectoryEntry
modifier|*
name|MainFileDir
decl_stmt|;
comment|/// \brief The number of bytes that we will initially skip when entering the
comment|/// main file, along with a flag that indicates whether skipping this number
comment|/// of bytes will place the lexer at the start of a line.
comment|///
comment|/// This is used when loading a precompiled preamble.
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|bool
operator|>
name|SkipMainFilePreamble
expr_stmt|;
name|class
name|PreambleConditionalStackStore
block|{
enum|enum
name|State
block|{
name|Off
init|=
literal|0
block|,
name|Recording
init|=
literal|1
block|,
name|Replaying
init|=
literal|2
block|,     }
enum|;
name|public
label|:
name|PreambleConditionalStackStore
argument_list|()
operator|:
name|ConditionalStackState
argument_list|(
argument|Off
argument_list|)
block|{}
name|void
name|startRecording
argument_list|()
block|{
name|ConditionalStackState
operator|=
name|Recording
block|; }
name|void
name|startReplaying
argument_list|()
block|{
name|ConditionalStackState
operator|=
name|Replaying
block|; }
name|bool
name|isRecording
argument_list|()
specifier|const
block|{
return|return
name|ConditionalStackState
operator|==
name|Recording
return|;
block|}
name|bool
name|isReplaying
argument_list|()
specifier|const
block|{
return|return
name|ConditionalStackState
operator|==
name|Replaying
return|;
block|}
name|ArrayRef
operator|<
name|PPConditionalInfo
operator|>
name|getStack
argument_list|()
specifier|const
block|{
return|return
name|ConditionalStack
return|;
block|}
name|void
name|doneReplaying
parameter_list|()
block|{
name|ConditionalStack
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ConditionalStackState
operator|=
name|Off
expr_stmt|;
block|}
name|void
name|setStack
argument_list|(
name|ArrayRef
operator|<
name|PPConditionalInfo
operator|>
name|s
argument_list|)
block|{
if|if
condition|(
operator|!
name|isRecording
argument_list|()
operator|&&
operator|!
name|isReplaying
argument_list|()
condition|)
return|return;
name|ConditionalStack
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ConditionalStack
operator|.
name|append
argument_list|(
name|s
operator|.
name|begin
argument_list|()
argument_list|,
name|s
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|bool
name|hasRecordedPreamble
argument_list|()
specifier|const
block|{
return|return
operator|!
name|ConditionalStack
operator|.
name|empty
argument_list|()
return|;
block|}
name|private
label|:
name|SmallVector
operator|<
name|PPConditionalInfo
operator|,
literal|4
operator|>
name|ConditionalStack
expr_stmt|;
name|State
name|ConditionalStackState
decl_stmt|;
block|}
name|PreambleConditionalStack
expr_stmt|;
comment|/// \brief The current top of the stack that we're lexing from if
comment|/// not expanding a macro and we are lexing directly from source code.
comment|///
comment|/// Only one of CurLexer, CurPTHLexer, or CurTokenLexer will be non-null.
name|std
operator|::
name|unique_ptr
operator|<
name|Lexer
operator|>
name|CurLexer
expr_stmt|;
comment|/// \brief The current top of stack that we're lexing from if
comment|/// not expanding from a macro and we are lexing from a PTH cache.
comment|///
comment|/// Only one of CurLexer, CurPTHLexer, or CurTokenLexer will be non-null.
name|std
operator|::
name|unique_ptr
operator|<
name|PTHLexer
operator|>
name|CurPTHLexer
expr_stmt|;
comment|/// \brief The current top of the stack what we're lexing from
comment|/// if not expanding a macro.
comment|///
comment|/// This is an alias for either CurLexer or  CurPTHLexer.
name|PreprocessorLexer
modifier|*
name|CurPPLexer
decl_stmt|;
comment|/// \brief Used to find the current FileEntry, if CurLexer is non-null
comment|/// and if applicable.
comment|///
comment|/// This allows us to implement \#include_next and find directory-specific
comment|/// properties.
specifier|const
name|DirectoryLookup
modifier|*
name|CurDirLookup
decl_stmt|;
comment|/// \brief The current macro we are expanding, if we are expanding a macro.
comment|///
comment|/// One of CurLexer and CurTokenLexer must be null.
name|std
operator|::
name|unique_ptr
operator|<
name|TokenLexer
operator|>
name|CurTokenLexer
expr_stmt|;
comment|/// \brief The kind of lexer we're currently working with.
enum|enum
name|CurLexerKind
block|{
name|CLK_Lexer
block|,
name|CLK_PTHLexer
block|,
name|CLK_TokenLexer
block|,
name|CLK_CachingLexer
block|,
name|CLK_LexAfterModuleImport
block|}
name|CurLexerKind
enum|;
comment|/// \brief If the current lexer is for a submodule that is being built, this
comment|/// is that submodule.
name|Module
modifier|*
name|CurLexerSubmodule
decl_stmt|;
comment|/// \brief Keeps track of the stack of files currently
comment|/// \#included, and macros currently being expanded from, not counting
comment|/// CurLexer/CurTokenLexer.
struct|struct
name|IncludeStackInfo
block|{
name|enum
name|CurLexerKind
name|CurLexerKind
decl_stmt|;
name|Module
modifier|*
name|TheSubmodule
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Lexer
operator|>
name|TheLexer
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|PTHLexer
operator|>
name|ThePTHLexer
expr_stmt|;
name|PreprocessorLexer
modifier|*
name|ThePPLexer
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|TokenLexer
operator|>
name|TheTokenLexer
expr_stmt|;
specifier|const
name|DirectoryLookup
modifier|*
name|TheDirLookup
decl_stmt|;
comment|// The following constructors are completely useless copies of the default
comment|// versions, only needed to pacify MSVC.
name|IncludeStackInfo
argument_list|(
argument|enum CurLexerKind CurLexerKind
argument_list|,
argument|Module *TheSubmodule
argument_list|,
argument|std::unique_ptr<Lexer>&&TheLexer
argument_list|,
argument|std::unique_ptr<PTHLexer>&&ThePTHLexer
argument_list|,
argument|PreprocessorLexer *ThePPLexer
argument_list|,
argument|std::unique_ptr<TokenLexer>&&TheTokenLexer
argument_list|,
argument|const DirectoryLookup *TheDirLookup
argument_list|)
block|:
name|CurLexerKind
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|CurLexerKind
argument_list|)
argument_list|)
operator|,
name|TheSubmodule
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|TheSubmodule
argument_list|)
argument_list|)
operator|,
name|TheLexer
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|TheLexer
argument_list|)
argument_list|)
operator|,
name|ThePTHLexer
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|ThePTHLexer
argument_list|)
argument_list|)
operator|,
name|ThePPLexer
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|ThePPLexer
argument_list|)
argument_list|)
operator|,
name|TheTokenLexer
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|TheTokenLexer
argument_list|)
argument_list|)
operator|,
name|TheDirLookup
argument_list|(
argument|std::move(TheDirLookup)
argument_list|)
block|{}
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|IncludeStackInfo
operator|>
name|IncludeMacroStack
expr_stmt|;
comment|/// \brief Actions invoked when some preprocessor activity is
comment|/// encountered (e.g. a file is \#included, etc).
name|std
operator|::
name|unique_ptr
operator|<
name|PPCallbacks
operator|>
name|Callbacks
expr_stmt|;
struct|struct
name|MacroExpandsInfo
block|{
name|Token
name|Tok
decl_stmt|;
name|MacroDefinition
name|MD
decl_stmt|;
name|SourceRange
name|Range
decl_stmt|;
name|MacroExpandsInfo
argument_list|(
argument|Token Tok
argument_list|,
argument|MacroDefinition MD
argument_list|,
argument|SourceRange Range
argument_list|)
block|:
name|Tok
argument_list|(
name|Tok
argument_list|)
operator|,
name|MD
argument_list|(
name|MD
argument_list|)
operator|,
name|Range
argument_list|(
argument|Range
argument_list|)
block|{ }
block|}
struct|;
name|SmallVector
operator|<
name|MacroExpandsInfo
operator|,
literal|2
operator|>
name|DelayedMacroExpandsCallbacks
expr_stmt|;
comment|/// Information about a name that has been used to define a module macro.
struct|struct
name|ModuleMacroInfo
block|{
name|ModuleMacroInfo
argument_list|(
name|MacroDirective
operator|*
name|MD
argument_list|)
operator|:
name|MD
argument_list|(
name|MD
argument_list|)
operator|,
name|ActiveModuleMacrosGeneration
argument_list|(
literal|0
argument_list|)
operator|,
name|IsAmbiguous
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// The most recent macro directive for this identifier.
name|MacroDirective
operator|*
name|MD
expr_stmt|;
comment|/// The active module macros for this identifier.
name|llvm
operator|::
name|TinyPtrVector
operator|<
name|ModuleMacro
operator|*
operator|>
name|ActiveModuleMacros
expr_stmt|;
comment|/// The generation number at which we last updated ActiveModuleMacros.
comment|/// \see Preprocessor::VisibleModules.
name|unsigned
name|ActiveModuleMacrosGeneration
decl_stmt|;
comment|/// Whether this macro name is ambiguous.
name|bool
name|IsAmbiguous
decl_stmt|;
comment|/// The module macros that are overridden by this macro.
name|llvm
operator|::
name|TinyPtrVector
operator|<
name|ModuleMacro
operator|*
operator|>
name|OverriddenMacros
expr_stmt|;
block|}
struct|;
comment|/// The state of a macro for an identifier.
name|class
name|MacroState
block|{
name|mutable
name|llvm
operator|::
name|PointerUnion
operator|<
name|MacroDirective
operator|*
operator|,
name|ModuleMacroInfo
operator|*
operator|>
name|State
expr_stmt|;
name|ModuleMacroInfo
modifier|*
name|getModuleInfo
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl|const
block|{
if|if
condition|(
name|II
operator|->
name|isOutOfDate
argument_list|()
condition|)
name|PP
operator|.
name|updateOutOfDateIdentifier
argument_list|(
name|const_cast
operator|<
name|IdentifierInfo
operator|&
operator|>
operator|(
operator|*
name|II
operator|)
argument_list|)
expr_stmt|;
comment|// FIXME: Find a spare bit on IdentifierInfo and store a
comment|//        HasModuleMacros flag.
if|if
condition|(
operator|!
name|II
operator|->
name|hasMacroDefinition
argument_list|()
operator|||
operator|(
operator|!
name|PP
operator|.
name|getLangOpts
argument_list|()
operator|.
name|Modules
operator|&&
operator|!
name|PP
operator|.
name|getLangOpts
argument_list|()
operator|.
name|ModulesLocalVisibility
operator|)
operator|||
operator|!
name|PP
operator|.
name|CurSubmoduleState
operator|->
name|VisibleModules
operator|.
name|getGeneration
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|auto
operator|*
name|Info
operator|=
name|State
operator|.
name|dyn_cast
operator|<
name|ModuleMacroInfo
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|Info
condition|)
block|{
name|Info
operator|=
name|new
argument_list|(
argument|PP.getPreprocessorAllocator()
argument_list|)
name|ModuleMacroInfo
argument_list|(
name|State
operator|.
name|get
operator|<
name|MacroDirective
operator|*
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
name|State
operator|=
name|Info
expr_stmt|;
block|}
if|if
condition|(
name|PP
operator|.
name|CurSubmoduleState
operator|->
name|VisibleModules
operator|.
name|getGeneration
argument_list|()
operator|!=
name|Info
operator|->
name|ActiveModuleMacrosGeneration
condition|)
name|PP
operator|.
name|updateModuleMacroInfo
argument_list|(
name|II
argument_list|,
operator|*
name|Info
argument_list|)
expr_stmt|;
return|return
name|Info
return|;
block|}
name|public
label|:
name|MacroState
argument_list|()
operator|:
name|MacroState
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|MacroState
argument_list|(
name|MacroDirective
operator|*
name|MD
argument_list|)
operator|:
name|State
argument_list|(
argument|MD
argument_list|)
block|{}
name|MacroState
argument_list|(
argument|MacroState&&O
argument_list|)
name|noexcept
operator|:
name|State
argument_list|(
argument|O.State
argument_list|)
block|{
name|O
operator|.
name|State
operator|=
operator|(
name|MacroDirective
operator|*
operator|)
name|nullptr
block|;     }
name|MacroState
operator|&
name|operator
operator|=
operator|(
name|MacroState
operator|&&
name|O
operator|)
name|noexcept
block|{
name|auto
name|S
operator|=
name|O
operator|.
name|State
block|;
name|O
operator|.
name|State
operator|=
operator|(
name|MacroDirective
operator|*
operator|)
name|nullptr
block|;
name|State
operator|=
name|S
block|;
return|return
operator|*
name|this
return|;
block|}
operator|~
name|MacroState
argument_list|()
block|{
if|if
condition|(
name|auto
operator|*
name|Info
operator|=
name|State
operator|.
name|dyn_cast
operator|<
name|ModuleMacroInfo
operator|*
operator|>
operator|(
operator|)
condition|)
name|Info
operator|->
expr|~
name|ModuleMacroInfo
argument_list|()
expr_stmt|;
block|}
name|MacroDirective
operator|*
name|getLatest
argument_list|()
specifier|const
block|{
if|if
condition|(
name|auto
operator|*
name|Info
operator|=
name|State
operator|.
name|dyn_cast
operator|<
name|ModuleMacroInfo
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|Info
operator|->
name|MD
return|;
return|return
name|State
operator|.
name|get
operator|<
name|MacroDirective
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setLatest
parameter_list|(
name|MacroDirective
modifier|*
name|MD
parameter_list|)
block|{
if|if
condition|(
name|auto
operator|*
name|Info
operator|=
name|State
operator|.
name|dyn_cast
operator|<
name|ModuleMacroInfo
operator|*
operator|>
operator|(
operator|)
condition|)
name|Info
operator|->
name|MD
operator|=
name|MD
expr_stmt|;
else|else
name|State
operator|=
name|MD
expr_stmt|;
block|}
name|bool
name|isAmbiguous
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl|const
block|{
name|auto
operator|*
name|Info
operator|=
name|getModuleInfo
argument_list|(
name|PP
argument_list|,
name|II
argument_list|)
expr_stmt|;
return|return
name|Info
condition|?
name|Info
operator|->
name|IsAmbiguous
else|:
name|false
return|;
block|}
name|ArrayRef
operator|<
name|ModuleMacro
operator|*
operator|>
name|getActiveModuleMacros
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|const IdentifierInfo *II
argument_list|)
specifier|const
block|{
if|if
condition|(
name|auto
operator|*
name|Info
operator|=
name|getModuleInfo
argument_list|(
name|PP
argument_list|,
name|II
argument_list|)
condition|)
return|return
name|Info
operator|->
name|ActiveModuleMacros
return|;
return|return
name|None
return|;
block|}
name|MacroDirective
operator|::
name|DefInfo
name|findDirectiveAtLoc
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|SourceManager&SourceMgr
argument_list|)
specifier|const
block|{
comment|// FIXME: Incorporate module macros into the result of this.
if|if
condition|(
name|auto
operator|*
name|Latest
operator|=
name|getLatest
argument_list|()
condition|)
return|return
name|Latest
operator|->
name|findDirectiveAtLoc
argument_list|(
name|Loc
argument_list|,
name|SourceMgr
argument_list|)
return|;
return|return
name|MacroDirective
operator|::
name|DefInfo
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|void
name|overrideActiveModuleMacros
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
if|if
condition|(
name|auto
operator|*
name|Info
operator|=
name|getModuleInfo
argument_list|(
name|PP
argument_list|,
name|II
argument_list|)
condition|)
block|{
name|Info
operator|->
name|OverriddenMacros
operator|.
name|insert
argument_list|(
name|Info
operator|->
name|OverriddenMacros
operator|.
name|end
argument_list|()
argument_list|,
name|Info
operator|->
name|ActiveModuleMacros
operator|.
name|begin
argument_list|()
argument_list|,
name|Info
operator|->
name|ActiveModuleMacros
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|Info
operator|->
name|ActiveModuleMacros
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Info
operator|->
name|IsAmbiguous
operator|=
name|false
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
name|ArrayRef
operator|<
name|ModuleMacro
operator|*
operator|>
name|getOverriddenMacros
argument_list|()
specifier|const
block|{
if|if
condition|(
name|auto
operator|*
name|Info
operator|=
name|State
operator|.
name|dyn_cast
operator|<
name|ModuleMacroInfo
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|Info
operator|->
name|OverriddenMacros
return|;
end_expr_stmt

begin_return
return|return
name|None
return|;
end_return

begin_macro
unit|}     void
name|setOverriddenMacros
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|ArrayRef<ModuleMacro *> Overrides
argument_list|)
end_macro

begin_block
block|{
name|auto
operator|*
name|Info
operator|=
name|State
operator|.
name|dyn_cast
operator|<
name|ModuleMacroInfo
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|Info
condition|)
block|{
if|if
condition|(
name|Overrides
operator|.
name|empty
argument_list|()
condition|)
return|return;
name|Info
operator|=
name|new
argument_list|(
argument|PP.getPreprocessorAllocator()
argument_list|)
name|ModuleMacroInfo
argument_list|(
name|State
operator|.
name|get
operator|<
name|MacroDirective
operator|*
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
name|State
operator|=
name|Info
expr_stmt|;
block|}
name|Info
operator|->
name|OverriddenMacros
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Info
operator|->
name|OverriddenMacros
operator|.
name|insert
argument_list|(
name|Info
operator|->
name|OverriddenMacros
operator|.
name|end
argument_list|()
argument_list|,
name|Overrides
operator|.
name|begin
argument_list|()
argument_list|,
name|Overrides
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|Info
operator|->
name|ActiveModuleMacrosGeneration
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_comment
unit|};
comment|/// For each IdentifierInfo that was associated with a macro, we
end_comment

begin_comment
comment|/// keep a mapping to the history of all macro definitions and #undefs in
end_comment

begin_comment
comment|/// the reverse order (the latest one is in the head of the list).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This mapping lives within the \p CurSubmoduleState.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|,
name|MacroState
operator|>
name|MacroMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|SubmoduleState
struct_decl|;
end_struct_decl

begin_comment
comment|/// \brief Information about a submodule that we're currently building.
end_comment

begin_struct
struct|struct
name|BuildingSubmoduleInfo
block|{
name|BuildingSubmoduleInfo
argument_list|(
argument|Module *M
argument_list|,
argument|SourceLocation ImportLoc
argument_list|,
argument|bool IsPragma
argument_list|,
argument|SubmoduleState *OuterSubmoduleState
argument_list|,
argument|unsigned OuterPendingModuleMacroNames
argument_list|)
block|:
name|M
argument_list|(
name|M
argument_list|)
operator|,
name|ImportLoc
argument_list|(
name|ImportLoc
argument_list|)
operator|,
name|IsPragma
argument_list|(
name|IsPragma
argument_list|)
operator|,
name|OuterSubmoduleState
argument_list|(
name|OuterSubmoduleState
argument_list|)
operator|,
name|OuterPendingModuleMacroNames
argument_list|(
argument|OuterPendingModuleMacroNames
argument_list|)
block|{}
comment|/// The module that we are building.
name|Module
operator|*
name|M
expr_stmt|;
comment|/// The location at which the module was included.
name|SourceLocation
name|ImportLoc
decl_stmt|;
comment|/// Whether we entered this submodule via a pragma.
name|bool
name|IsPragma
decl_stmt|;
comment|/// The previous SubmoduleState.
name|SubmoduleState
modifier|*
name|OuterSubmoduleState
decl_stmt|;
comment|/// The number of pending module macro names when we started building this.
name|unsigned
name|OuterPendingModuleMacroNames
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SmallVector
operator|<
name|BuildingSubmoduleInfo
operator|,
literal|8
operator|>
name|BuildingSubmoduleStack
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Information about a submodule's preprocessor state.
end_comment

begin_struct
struct|struct
name|SubmoduleState
block|{
comment|/// The macros for the submodule.
name|MacroMap
name|Macros
decl_stmt|;
comment|/// The set of modules that are visible within the submodule.
name|VisibleModuleSet
name|VisibleModules
decl_stmt|;
comment|// FIXME: CounterValue?
comment|// FIXME: PragmaPushMacroInfo?
block|}
struct|;
end_struct

begin_expr_stmt
name|std
operator|::
name|map
operator|<
name|Module
operator|*
operator|,
name|SubmoduleState
operator|>
name|Submodules
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The preprocessor state for preprocessing outside of any submodule.
end_comment

begin_decl_stmt
name|SubmoduleState
name|NullSubmoduleState
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The current submodule state. Will be \p NullSubmoduleState if we're not
end_comment

begin_comment
comment|/// in a submodule.
end_comment

begin_decl_stmt
name|SubmoduleState
modifier|*
name|CurSubmoduleState
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The set of known macros exported from modules.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|FoldingSet
operator|<
name|ModuleMacro
operator|>
name|ModuleMacros
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The names of potential module macros that we've not yet processed.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|SmallVector
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|,
literal|32
operator|>
name|PendingModuleMacroNames
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The list of module macros, for each identifier, that are not overridden by
end_comment

begin_comment
comment|/// any other module macro.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|,
name|llvm
operator|::
name|TinyPtrVector
operator|<
name|ModuleMacro
operator|*
operator|>>
name|LeafModuleMacros
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Macros that we want to warn because they are not used at the end
end_comment

begin_comment
comment|/// of the translation unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We store just their SourceLocations instead of
end_comment

begin_comment
comment|/// something like MacroInfo*. The benefit of this is that when we are
end_comment

begin_comment
comment|/// deserializing from PCH, we don't need to deserialize identifier& macros
end_comment

begin_comment
comment|/// just so that we can report that they are unused, we just warn using
end_comment

begin_comment
comment|/// the SourceLocations of this set (that will be filled by the ASTReader).
end_comment

begin_comment
comment|/// We are using SmallPtrSet instead of a vector for faster removal.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|SourceLocation
operator|,
literal|32
operator|>
name|WarnUnusedMacroLocsTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|WarnUnusedMacroLocsTy
name|WarnUnusedMacroLocs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief A "freelist" of MacroArg objects that can be
end_comment

begin_comment
comment|/// reused for quick allocation.
end_comment

begin_decl_stmt
name|MacroArgs
modifier|*
name|MacroArgCache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|MacroArgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// For each IdentifierInfo used in a \#pragma push_macro directive,
end_comment

begin_comment
comment|/// we keep a MacroInfo stack used to restore the previous macro value.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|std
operator|::
name|vector
operator|<
name|MacroInfo
operator|*
operator|>
expr|>
name|PragmaPushMacroInfo
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Various statistics we track for performance analysis.
end_comment

begin_decl_stmt
name|unsigned
name|NumDirectives
decl_stmt|,
name|NumDefined
decl_stmt|,
name|NumUndefined
decl_stmt|,
name|NumPragma
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|NumIf
decl_stmt|,
name|NumElse
decl_stmt|,
name|NumEndif
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|NumEnteredSourceFiles
decl_stmt|,
name|MaxIncludeStackDepth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|NumMacroExpanded
decl_stmt|,
name|NumFnMacroExpanded
decl_stmt|,
name|NumBuiltinMacroExpanded
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|NumFastMacroExpanded
decl_stmt|,
name|NumTokenPaste
decl_stmt|,
name|NumFastTokenPaste
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|NumSkipped
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The predefined macros that preprocessor should use from the
end_comment

begin_comment
comment|/// command line etc.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|Predefines
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief The file ID for the preprocessor predefines.
end_comment

begin_decl_stmt
name|FileID
name|PredefinesFileID
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \{
end_comment

begin_comment
comment|/// \brief Cache of macro expanders to reduce malloc traffic.
end_comment

begin_enum
enum|enum
block|{
name|TokenLexerCacheSize
init|=
literal|8
block|}
enum|;
end_enum

begin_decl_stmt
name|unsigned
name|NumCachedTokenLexers
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|TokenLexer
operator|>
name|TokenLexerCache
index|[
name|TokenLexerCacheSize
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \}
end_comment

begin_comment
comment|/// \brief Keeps macro expanded tokens for TokenLexers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// Works like a stack; a TokenLexer adds the macro expanded tokens that is
end_comment

begin_comment
comment|/// going to lex in the cache and when it finishes the tokens are removed
end_comment

begin_comment
comment|/// from the end of the cache.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|Token
operator|,
literal|16
operator|>
name|MacroExpandedTokens
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|TokenLexer
operator|*
operator|,
name|size_t
operator|>
expr|>
name|MacroExpandingLexersStack
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A record of the macro definitions and expansions that
end_comment

begin_comment
comment|/// occurred during preprocessing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is an optional side structure that can be enabled with
end_comment

begin_comment
comment|/// \c createPreprocessingRecord() prior to preprocessing.
end_comment

begin_decl_stmt
name|PreprocessingRecord
modifier|*
name|Record
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Cached tokens state.
end_comment

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|Token
operator|,
literal|1
operator|>
name|CachedTokensTy
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Cached tokens are stored here when we do backtracking or
end_comment

begin_comment
comment|/// lookahead. They are "lexed" by the CachingLex() method.
end_comment

begin_decl_stmt
name|CachedTokensTy
name|CachedTokens
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief The position of the cached token that CachingLex() should
end_comment

begin_comment
comment|/// "lex" next.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If it points beyond the CachedTokens vector, it means that a normal
end_comment

begin_comment
comment|/// Lex() should be invoked.
end_comment

begin_expr_stmt
name|CachedTokensTy
operator|::
name|size_type
name|CachedLexPos
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Stack of backtrack positions, allowing nested backtracks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EnableBacktrackAtThisPos() method pushes a position to
end_comment

begin_comment
comment|/// indicate where CachedLexPos should be set when the BackTrack() method is
end_comment

begin_comment
comment|/// invoked (at which point the last position is popped).
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CachedTokensTy
operator|::
name|size_type
operator|>
name|BacktrackPositions
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|MacroInfoChain
block|{
name|MacroInfo
name|MI
decl_stmt|;
name|MacroInfoChain
modifier|*
name|Next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// MacroInfos are managed as a chain for easy disposal.  This is the head
end_comment

begin_comment
comment|/// of that list.
end_comment

begin_decl_stmt
name|MacroInfoChain
modifier|*
name|MIChainHead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|updateOutOfDateIdentifier
argument_list|(
name|IdentifierInfo
operator|&
name|II
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|Preprocessor
argument_list|(
argument|std::shared_ptr<PreprocessorOptions> PPOpts
argument_list|,
argument|DiagnosticsEngine&diags
argument_list|,
argument|LangOptions&opts
argument_list|,
argument|SourceManager&SM
argument_list|,
argument|MemoryBufferCache&PCMCache
argument_list|,
argument|HeaderSearch&Headers
argument_list|,
argument|ModuleLoader&TheModuleLoader
argument_list|,
argument|IdentifierInfoLookup *IILookup = nullptr
argument_list|,
argument|bool OwnsHeaderSearch = false
argument_list|,
argument|TranslationUnitKind TUKind = TU_Complete
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|Preprocessor
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Initialize the preprocessor using information about the target.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Target is owned by the caller and must remain valid for the
end_comment

begin_comment
comment|/// lifetime of the preprocessor.
end_comment

begin_comment
comment|/// \param AuxTarget is owned by the caller and must remain valid for
end_comment

begin_comment
comment|/// the lifetime of the preprocessor.
end_comment

begin_function_decl
name|void
name|Initialize
parameter_list|(
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|,
specifier|const
name|TargetInfo
modifier|*
name|AuxTarget
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Initialize the preprocessor to parse a model file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To parse model files the preprocessor of the original source is reused to
end_comment

begin_comment
comment|/// preserver the identifier table. However to avoid some duplicate
end_comment

begin_comment
comment|/// information in the preprocessor some cleanup is needed before it is used
end_comment

begin_comment
comment|/// to parse model files. This method does that cleanup.
end_comment

begin_function_decl
name|void
name|InitializeForModelFile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Cleanup after model file parsing
end_comment

begin_function_decl
name|void
name|FinalizeForModelFile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the preprocessor options used to initialize this
end_comment

begin_comment
comment|/// preprocessor.
end_comment

begin_expr_stmt
name|PreprocessorOptions
operator|&
name|getPreprocessorOpts
argument_list|()
specifier|const
block|{
return|return
operator|*
name|PPOpts
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DiagnosticsEngine
operator|&
name|getDiagnostics
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Diags
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDiagnostics
parameter_list|(
name|DiagnosticsEngine
modifier|&
name|D
parameter_list|)
block|{
name|Diags
operator|=
operator|&
name|D
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|TargetInfo
operator|&
name|getTargetInfo
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Target
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|TargetInfo
operator|*
name|getAuxTargetInfo
argument_list|()
specifier|const
block|{
return|return
name|AuxTarget
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|FileManager
operator|&
name|getFileManager
argument_list|()
specifier|const
block|{
return|return
name|FileMgr
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|MemoryBufferCache
operator|&
name|getPCMCache
argument_list|()
specifier|const
block|{
return|return
name|PCMCache
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|HeaderSearch
operator|&
name|getHeaderSearchInfo
argument_list|()
specifier|const
block|{
return|return
name|HeaderInfo
return|;
block|}
end_expr_stmt

begin_function
name|IdentifierTable
modifier|&
name|getIdentifierTable
parameter_list|()
block|{
return|return
name|Identifiers
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|IdentifierTable
operator|&
name|getIdentifierTable
argument_list|()
specifier|const
block|{
return|return
name|Identifiers
return|;
block|}
end_expr_stmt

begin_function
name|SelectorTable
modifier|&
name|getSelectorTable
parameter_list|()
block|{
return|return
name|Selectors
return|;
block|}
end_function

begin_expr_stmt
name|Builtin
operator|::
name|Context
operator|&
name|getBuiltinInfo
argument_list|()
block|{
return|return
name|BuiltinInfo
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|getPreprocessorAllocator
argument_list|()
block|{
return|return
name|BP
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setPTHManager
parameter_list|(
name|PTHManager
modifier|*
name|pm
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|PTHManager
modifier|*
name|getPTHManager
parameter_list|()
block|{
return|return
name|PTH
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|setExternalSource
parameter_list|(
name|ExternalPreprocessorSource
modifier|*
name|Source
parameter_list|)
block|{
name|ExternalSource
operator|=
name|Source
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ExternalPreprocessorSource
operator|*
name|getExternalSource
argument_list|()
specifier|const
block|{
return|return
name|ExternalSource
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the module loader associated with this preprocessor.
end_comment

begin_expr_stmt
name|ModuleLoader
operator|&
name|getModuleLoader
argument_list|()
specifier|const
block|{
return|return
name|TheModuleLoader
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hadModuleLoaderFatalFailure
argument_list|()
specifier|const
block|{
return|return
name|TheModuleLoader
operator|.
name|HadFatalFailure
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief True if we are currently preprocessing a #if or #elif directive
end_comment

begin_expr_stmt
name|bool
name|isParsingIfOrElifDirective
argument_list|()
specifier|const
block|{
return|return
name|ParsingIfOrElifDirective
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Control whether the preprocessor retains comments in output.
end_comment

begin_function
name|void
name|SetCommentRetentionState
parameter_list|(
name|bool
name|KeepComments
parameter_list|,
name|bool
name|KeepMacroComments
parameter_list|)
block|{
name|this
operator|->
name|KeepComments
operator|=
name|KeepComments
operator||
name|KeepMacroComments
expr_stmt|;
name|this
operator|->
name|KeepMacroComments
operator|=
name|KeepMacroComments
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getCommentRetentionState
argument_list|()
specifier|const
block|{
return|return
name|KeepComments
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPragmasEnabled
parameter_list|(
name|bool
name|Enabled
parameter_list|)
block|{
name|PragmasEnabled
operator|=
name|Enabled
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|getPragmasEnabled
argument_list|()
specifier|const
block|{
return|return
name|PragmasEnabled
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetSuppressIncludeNotFoundError
parameter_list|(
name|bool
name|Suppress
parameter_list|)
block|{
name|SuppressIncludeNotFoundError
operator|=
name|Suppress
expr_stmt|;
block|}
end_function

begin_function
name|bool
name|GetSuppressIncludeNotFoundError
parameter_list|()
block|{
return|return
name|SuppressIncludeNotFoundError
return|;
block|}
end_function

begin_comment
comment|/// Sets whether the preprocessor is responsible for producing output or if
end_comment

begin_comment
comment|/// it is producing tokens to be consumed by Parse and Sema.
end_comment

begin_function
name|void
name|setPreprocessedOutput
parameter_list|(
name|bool
name|IsPreprocessedOutput
parameter_list|)
block|{
name|PreprocessedOutput
operator|=
name|IsPreprocessedOutput
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Returns true if the preprocessor is responsible for generating output,
end_comment

begin_comment
comment|/// false if it is producing tokens to be consumed by Parse and Sema.
end_comment

begin_expr_stmt
name|bool
name|isPreprocessedOutput
argument_list|()
specifier|const
block|{
return|return
name|PreprocessedOutput
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return true if we are lexing directly from the specified lexer.
end_comment

begin_decl_stmt
name|bool
name|isCurrentLexer
argument_list|(
specifier|const
name|PreprocessorLexer
operator|*
name|L
argument_list|)
decl|const
block|{
return|return
name|CurPPLexer
operator|==
name|L
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the current lexer being lexed from.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this ignores any potentially active macro expansions and _Pragma
end_comment

begin_comment
comment|/// expansions going on at the time.
end_comment

begin_expr_stmt
name|PreprocessorLexer
operator|*
name|getCurrentLexer
argument_list|()
specifier|const
block|{
return|return
name|CurPPLexer
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the current file lexer being lexed from.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this ignores any potentially active macro expansions and _Pragma
end_comment

begin_comment
comment|/// expansions going on at the time.
end_comment

begin_expr_stmt
name|PreprocessorLexer
operator|*
name|getCurrentFileLexer
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return the submodule owning the file being lexed. This may not be
end_comment

begin_comment
comment|/// the current module if we have changed modules since entering the file.
end_comment

begin_expr_stmt
name|Module
operator|*
name|getCurrentLexerSubmodule
argument_list|()
specifier|const
block|{
return|return
name|CurLexerSubmodule
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the FileID for the preprocessor predefines.
end_comment

begin_expr_stmt
name|FileID
name|getPredefinesFileID
argument_list|()
specifier|const
block|{
return|return
name|PredefinesFileID
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \{
end_comment

begin_comment
comment|/// \brief Accessors for preprocessor callbacks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this class takes ownership of any PPCallbacks object given to
end_comment

begin_comment
comment|/// it.
end_comment

begin_expr_stmt
name|PPCallbacks
operator|*
name|getPPCallbacks
argument_list|()
specifier|const
block|{
return|return
name|Callbacks
operator|.
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|addPPCallbacks
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|PPCallbacks
operator|>
name|C
argument_list|)
block|{
if|if
condition|(
name|Callbacks
condition|)
name|C
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|PPChainedCallbacks
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|C
argument_list|)
operator|,
name|std
operator|::
name|move
argument_list|(
name|Callbacks
argument_list|)
operator|)
expr_stmt|;
name|Callbacks
operator|=
name|std
operator|::
name|move
argument_list|(
name|C
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \}
end_comment

begin_function
name|bool
name|isMacroDefined
parameter_list|(
name|StringRef
name|Id
parameter_list|)
block|{
return|return
name|isMacroDefined
argument_list|(
operator|&
name|Identifiers
operator|.
name|get
argument_list|(
name|Id
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|bool
name|isMacroDefined
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
return|return
name|II
operator|->
name|hasMacroDefinition
argument_list|()
operator|&&
operator|(
operator|!
name|getLangOpts
argument_list|()
operator|.
name|Modules
operator|||
operator|(
name|bool
operator|)
name|getMacroDefinition
argument_list|(
name|II
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether II is defined as a macro within the module M,
end_comment

begin_comment
comment|/// if that is a module that we've already preprocessed. Does not check for
end_comment

begin_comment
comment|/// macros imported into M.
end_comment

begin_function
name|bool
name|isMacroDefinedInLocalModule
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|Module
modifier|*
name|M
parameter_list|)
block|{
if|if
condition|(
operator|!
name|II
operator|->
name|hasMacroDefinition
argument_list|()
condition|)
return|return
name|false
return|;
name|auto
name|I
init|=
name|Submodules
operator|.
name|find
argument_list|(
name|M
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|Submodules
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
name|auto
name|J
init|=
name|I
operator|->
name|second
operator|.
name|Macros
operator|.
name|find
argument_list|(
name|II
argument_list|)
decl_stmt|;
if|if
condition|(
name|J
operator|==
name|I
operator|->
name|second
operator|.
name|Macros
operator|.
name|end
argument_list|()
condition|)
return|return
name|false
return|;
name|auto
operator|*
name|MD
operator|=
name|J
operator|->
name|second
operator|.
name|getLatest
argument_list|()
expr_stmt|;
return|return
name|MD
operator|&&
name|MD
operator|->
name|isDefined
argument_list|()
return|;
block|}
end_function

begin_function
name|MacroDefinition
name|getMacroDefinition
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
if|if
condition|(
operator|!
name|II
operator|->
name|hasMacroDefinition
argument_list|()
condition|)
return|return
name|MacroDefinition
argument_list|()
return|;
name|MacroState
modifier|&
name|S
init|=
name|CurSubmoduleState
operator|->
name|Macros
index|[
name|II
index|]
decl_stmt|;
name|auto
operator|*
name|MD
operator|=
name|S
operator|.
name|getLatest
argument_list|()
expr_stmt|;
while|while
condition|(
name|MD
operator|&&
name|isa
operator|<
name|VisibilityMacroDirective
operator|>
operator|(
name|MD
operator|)
condition|)
name|MD
operator|=
name|MD
operator|->
name|getPrevious
argument_list|()
expr_stmt|;
return|return
name|MacroDefinition
argument_list|(
name|dyn_cast_or_null
operator|<
name|DefMacroDirective
operator|>
operator|(
name|MD
operator|)
argument_list|,
name|S
operator|.
name|getActiveModuleMacros
argument_list|(
operator|*
name|this
argument_list|,
name|II
argument_list|)
argument_list|,
name|S
operator|.
name|isAmbiguous
argument_list|(
operator|*
name|this
argument_list|,
name|II
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|MacroDefinition
name|getMacroDefinitionAtLoc
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{
if|if
condition|(
operator|!
name|II
operator|->
name|hadMacroDefinition
argument_list|()
condition|)
return|return
name|MacroDefinition
argument_list|()
return|;
name|MacroState
modifier|&
name|S
init|=
name|CurSubmoduleState
operator|->
name|Macros
index|[
name|II
index|]
decl_stmt|;
name|MacroDirective
operator|::
name|DefInfo
name|DI
expr_stmt|;
if|if
condition|(
name|auto
operator|*
name|MD
operator|=
name|S
operator|.
name|getLatest
argument_list|()
condition|)
name|DI
operator|=
name|MD
operator|->
name|findDirectiveAtLoc
argument_list|(
name|Loc
argument_list|,
name|getSourceManager
argument_list|()
argument_list|)
expr_stmt|;
comment|// FIXME: Compute the set of active module macros at the specified location.
return|return
name|MacroDefinition
argument_list|(
name|DI
operator|.
name|getDirective
argument_list|()
argument_list|,
name|S
operator|.
name|getActiveModuleMacros
argument_list|(
operator|*
name|this
argument_list|,
name|II
argument_list|)
argument_list|,
name|S
operator|.
name|isAmbiguous
argument_list|(
operator|*
name|this
argument_list|,
name|II
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Given an identifier, return its latest non-imported MacroDirective
end_comment

begin_comment
comment|/// if it is \#define'd and not \#undef'd, or null if it isn't \#define'd.
end_comment

begin_decl_stmt
name|MacroDirective
modifier|*
name|getLocalMacroDirective
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|II
operator|->
name|hasMacroDefinition
argument_list|()
condition|)
return|return
name|nullptr
return|;
name|auto
operator|*
name|MD
operator|=
name|getLocalMacroDirectiveHistory
argument_list|(
name|II
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|MD
operator|||
name|MD
operator|->
name|getDefinition
argument_list|()
operator|.
name|isUndefined
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|MD
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|MacroInfo
modifier|*
name|getMacroInfo
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|Preprocessor
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMacroInfo
argument_list|(
name|II
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|MacroInfo
modifier|*
name|getMacroInfo
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
if|if
condition|(
operator|!
name|II
operator|->
name|hasMacroDefinition
argument_list|()
condition|)
return|return
name|nullptr
return|;
if|if
condition|(
name|auto
name|MD
init|=
name|getMacroDefinition
argument_list|(
name|II
argument_list|)
condition|)
return|return
name|MD
operator|.
name|getMacroInfo
argument_list|()
return|;
return|return
name|nullptr
return|;
block|}
end_function

begin_comment
comment|/// \brief Given an identifier, return the latest non-imported macro
end_comment

begin_comment
comment|/// directive for that identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// One can iterate over all previous macro directives from the most recent
end_comment

begin_comment
comment|/// one.
end_comment

begin_decl_stmt
name|MacroDirective
modifier|*
name|getLocalMacroDirectiveHistory
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Add a directive to the macro directive history for this identifier.
end_comment

begin_function_decl
name|void
name|appendMacroDirective
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|DefMacroDirective
modifier|*
name|appendDefMacroDirective
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|MacroInfo
modifier|*
name|MI
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|DefMacroDirective
modifier|*
name|MD
init|=
name|AllocateDefMacroDirective
argument_list|(
name|MI
argument_list|,
name|Loc
argument_list|)
decl_stmt|;
name|appendMacroDirective
argument_list|(
name|II
argument_list|,
name|MD
argument_list|)
expr_stmt|;
return|return
name|MD
return|;
block|}
end_function

begin_function
name|DefMacroDirective
modifier|*
name|appendDefMacroDirective
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|MacroInfo
modifier|*
name|MI
parameter_list|)
block|{
return|return
name|appendDefMacroDirective
argument_list|(
name|II
argument_list|,
name|MI
argument_list|,
name|MI
operator|->
name|getDefinitionLoc
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Set a MacroDirective that was loaded from a PCH file.
end_comment

begin_function_decl
name|void
name|setLoadedMacroDirective
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|MacroDirective
modifier|*
name|ED
parameter_list|,
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Register an exported macro for a module and identifier.
end_comment

begin_decl_stmt
name|ModuleMacro
modifier|*
name|addModuleMacro
argument_list|(
name|Module
operator|*
name|Mod
argument_list|,
name|IdentifierInfo
operator|*
name|II
argument_list|,
name|MacroInfo
operator|*
name|Macro
argument_list|,
name|ArrayRef
operator|<
name|ModuleMacro
operator|*
operator|>
name|Overrides
argument_list|,
name|bool
operator|&
name|IsNew
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|ModuleMacro
modifier|*
name|getModuleMacro
parameter_list|(
name|Module
modifier|*
name|Mod
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the list of leaf (non-overridden) module macros for a name.
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
name|ModuleMacro
operator|*
operator|>
name|getLeafModuleMacros
argument_list|(
argument|const IdentifierInfo *II
argument_list|)
specifier|const
block|{
if|if
condition|(
name|II
operator|->
name|isOutOfDate
argument_list|()
condition|)
name|updateOutOfDateIdentifier
argument_list|(
name|const_cast
operator|<
name|IdentifierInfo
operator|&
operator|>
operator|(
operator|*
name|II
operator|)
argument_list|)
expr_stmt|;
name|auto
name|I
operator|=
name|LeafModuleMacros
operator|.
name|find
argument_list|(
name|II
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|I
operator|!=
name|LeafModuleMacros
operator|.
name|end
argument_list|()
condition|)
return|return
name|I
operator|->
name|second
return|;
end_if

begin_return
return|return
name|None
return|;
end_return

begin_comment
unit|}
comment|/// \{
end_comment

begin_comment
comment|/// Iterators for the macro history table. Currently defined macros have
end_comment

begin_comment
comment|/// IdentifierInfo::hasMacroDefinition() set and an empty
end_comment

begin_comment
comment|/// MacroInfo::getUndefLoc() at the head of the list.
end_comment

begin_expr_stmt
unit|typedef
name|MacroMap
operator|::
name|const_iterator
name|macro_iterator
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|macro_iterator
name|macro_begin
argument_list|(
name|bool
name|IncludeExternalMacros
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|macro_iterator
name|macro_end
argument_list|(
name|bool
name|IncludeExternalMacros
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|iterator_range
operator|<
name|macro_iterator
operator|>
name|macros
argument_list|(
argument|bool IncludeExternalMacros = true
argument_list|)
specifier|const
block|{
return|return
name|llvm
operator|::
name|make_range
argument_list|(
name|macro_begin
argument_list|(
name|IncludeExternalMacros
argument_list|)
argument_list|,
name|macro_end
argument_list|(
name|IncludeExternalMacros
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \}
end_comment

begin_comment
comment|/// \brief Return the name of the macro defined before \p Loc that has
end_comment

begin_comment
comment|/// spelling \p Tokens.  If there are multiple macros with same spelling,
end_comment

begin_comment
comment|/// return the last one defined.
end_comment

begin_decl_stmt
name|StringRef
name|getLastMacroWithSpelling
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|ArrayRef
operator|<
name|TokenValue
operator|>
name|Tokens
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|std
operator|::
name|string
operator|&
name|getPredefines
argument_list|()
specifier|const
block|{
return|return
name|Predefines
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the predefines for this Preprocessor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These predefines are automatically injected when parsing the main file.
end_comment

begin_function
name|void
name|setPredefines
parameter_list|(
specifier|const
name|char
modifier|*
name|P
parameter_list|)
block|{
name|Predefines
operator|=
name|P
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setPredefines
parameter_list|(
name|StringRef
name|P
parameter_list|)
block|{
name|Predefines
operator|=
name|P
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Return information about the specified preprocessor
end_comment

begin_comment
comment|/// identifier token.
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|getIdentifierInfo
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
block|{
return|return
operator|&
name|Identifiers
operator|.
name|get
argument_list|(
name|Name
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Add the specified pragma handler to this preprocessor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p Namespace is non-null, then it is a token required to exist on the
end_comment

begin_comment
comment|/// pragma line before the pragma string starts, e.g. "STDC" or "GCC".
end_comment

begin_function_decl
name|void
name|AddPragmaHandler
parameter_list|(
name|StringRef
name|Namespace
parameter_list|,
name|PragmaHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|AddPragmaHandler
parameter_list|(
name|PragmaHandler
modifier|*
name|Handler
parameter_list|)
block|{
name|AddPragmaHandler
argument_list|(
name|StringRef
argument_list|()
argument_list|,
name|Handler
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Remove the specific pragma handler from this preprocessor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p Namespace is non-null, then it should be the namespace that
end_comment

begin_comment
comment|/// \p Handler was added to. It is an error to remove a handler that
end_comment

begin_comment
comment|/// has not been registered.
end_comment

begin_function_decl
name|void
name|RemovePragmaHandler
parameter_list|(
name|StringRef
name|Namespace
parameter_list|,
name|PragmaHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|RemovePragmaHandler
parameter_list|(
name|PragmaHandler
modifier|*
name|Handler
parameter_list|)
block|{
name|RemovePragmaHandler
argument_list|(
name|StringRef
argument_list|()
argument_list|,
name|Handler
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Install empty handlers for all pragmas (making them ignored).
end_comment

begin_function_decl
name|void
name|IgnorePragmas
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add the specified comment handler to the preprocessor.
end_comment

begin_function_decl
name|void
name|addCommentHandler
parameter_list|(
name|CommentHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Remove the specified comment handler.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It is an error to remove a handler that has not been registered.
end_comment

begin_function_decl
name|void
name|removeCommentHandler
parameter_list|(
name|CommentHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Set the code completion handler to the given object.
end_comment

begin_function
name|void
name|setCodeCompletionHandler
parameter_list|(
name|CodeCompletionHandler
modifier|&
name|Handler
parameter_list|)
block|{
name|CodeComplete
operator|=
operator|&
name|Handler
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the current code-completion handler.
end_comment

begin_expr_stmt
name|CodeCompletionHandler
operator|*
name|getCodeCompletionHandler
argument_list|()
specifier|const
block|{
return|return
name|CodeComplete
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Clear out the code completion handler.
end_comment

begin_function
name|void
name|clearCodeCompletionHandler
parameter_list|()
block|{
name|CodeComplete
operator|=
name|nullptr
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Hook used by the lexer to invoke the "natural language" code
end_comment

begin_comment
comment|/// completion point.
end_comment

begin_function_decl
name|void
name|CodeCompleteNaturalLanguage
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Set the code completion token for filtering purposes.
end_comment

begin_function
name|void
name|setCodeCompletionIdentifierInfo
parameter_list|(
name|IdentifierInfo
modifier|*
name|Filter
parameter_list|)
block|{
name|CodeCompletionII
operator|=
name|Filter
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Get the code completion token for filtering purposes.
end_comment

begin_function
name|StringRef
name|getCodeCompletionFilter
parameter_list|()
block|{
if|if
condition|(
name|CodeCompletionII
condition|)
return|return
name|CodeCompletionII
operator|->
name|getName
argument_list|()
return|;
return|return
block|{}
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the preprocessing record, or NULL if there is no
end_comment

begin_comment
comment|/// preprocessing record.
end_comment

begin_expr_stmt
name|PreprocessingRecord
operator|*
name|getPreprocessingRecord
argument_list|()
specifier|const
block|{
return|return
name|Record
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Create a new preprocessing record, which will keep track of
end_comment

begin_comment
comment|/// all macro expansions, macro definitions, etc.
end_comment

begin_function_decl
name|void
name|createPreprocessingRecord
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Enter the specified FileID as the main source file,
end_comment

begin_comment
comment|/// which implicitly adds the builtin defines etc.
end_comment

begin_function_decl
name|void
name|EnterMainSourceFile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Inform the preprocessor callbacks that processing is complete.
end_comment

begin_function_decl
name|void
name|EndSourceFile
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add a source file to the top of the include stack and
end_comment

begin_comment
comment|/// start lexing tokens from it instead of the current buffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Emits a diagnostic, doesn't enter the file, and returns true on error.
end_comment

begin_function_decl
name|bool
name|EnterSourceFile
parameter_list|(
name|FileID
name|CurFileID
parameter_list|,
specifier|const
name|DirectoryLookup
modifier|*
name|Dir
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add a Macro to the top of the include stack and start lexing
end_comment

begin_comment
comment|/// tokens from it instead of the current buffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Args specifies the tokens input to a function-like macro.
end_comment

begin_comment
comment|/// \param ILEnd specifies the location of the ')' for a function-like macro
end_comment

begin_comment
comment|/// or the identifier for an object-like macro.
end_comment

begin_function_decl
name|void
name|EnterMacro
parameter_list|(
name|Token
modifier|&
name|Identifier
parameter_list|,
name|SourceLocation
name|ILEnd
parameter_list|,
name|MacroInfo
modifier|*
name|Macro
parameter_list|,
name|MacroArgs
modifier|*
name|Args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add a "macro" context to the top of the include stack,
end_comment

begin_comment
comment|/// which will cause the lexer to start returning the specified tokens.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p DisableMacroExpansion is true, tokens lexed from the token stream
end_comment

begin_comment
comment|/// will not be subject to further macro expansion. Otherwise, these tokens
end_comment

begin_comment
comment|/// will be re-macro-expanded when/if expansion is enabled.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If \p OwnsTokens is false, this method assumes that the specified stream
end_comment

begin_comment
comment|/// of tokens has a permanent owner somewhere, so they do not need to be
end_comment

begin_comment
comment|/// copied. If it is true, it assumes the array of tokens is allocated with
end_comment

begin_comment
comment|/// \c new[] and the Preprocessor will delete[] it.
end_comment

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|EnterTokenStream
parameter_list|(
specifier|const
name|Token
modifier|*
name|Toks
parameter_list|,
name|unsigned
name|NumToks
parameter_list|,
name|bool
name|DisableMacroExpansion
parameter_list|,
name|bool
name|OwnsTokens
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|void
name|EnterTokenStream
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|Token
index|[]
operator|>
name|Toks
argument_list|,
name|unsigned
name|NumToks
argument_list|,
name|bool
name|DisableMacroExpansion
argument_list|)
block|{
name|EnterTokenStream
argument_list|(
name|Toks
operator|.
name|release
argument_list|()
argument_list|,
name|NumToks
argument_list|,
name|DisableMacroExpansion
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|EnterTokenStream
argument_list|(
name|ArrayRef
operator|<
name|Token
operator|>
name|Toks
argument_list|,
name|bool
name|DisableMacroExpansion
argument_list|)
block|{
name|EnterTokenStream
argument_list|(
name|Toks
operator|.
name|data
argument_list|()
argument_list|,
name|Toks
operator|.
name|size
argument_list|()
argument_list|,
name|DisableMacroExpansion
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Pop the current lexer/macro exp off the top of the lexer stack.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This should only be used in situations where the current state of the
end_comment

begin_comment
comment|/// top-of-stack lexer is known.
end_comment

begin_function_decl
name|void
name|RemoveTopOfLexerStack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// From the point that this method is called, and until
end_comment

begin_comment
comment|/// CommitBacktrackedTokens() or Backtrack() is called, the Preprocessor
end_comment

begin_comment
comment|/// keeps track of the lexed tokens so that a subsequent Backtrack() call will
end_comment

begin_comment
comment|/// make the Preprocessor re-lex the same tokens.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Nested backtracks are allowed, meaning that EnableBacktrackAtThisPos can
end_comment

begin_comment
comment|/// be called multiple times and CommitBacktrackedTokens/Backtrack calls will
end_comment

begin_comment
comment|/// be combined with the EnableBacktrackAtThisPos calls in reverse order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: *DO NOT* forget to call either CommitBacktrackedTokens or Backtrack
end_comment

begin_comment
comment|/// at some point after EnableBacktrackAtThisPos. If you don't, caching of
end_comment

begin_comment
comment|/// tokens will continue indefinitely.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|EnableBacktrackAtThisPos
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Disable the last EnableBacktrackAtThisPos call.
end_comment

begin_function_decl
name|void
name|CommitBacktrackedTokens
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|CachedTokensRange
block|{
name|CachedTokensTy
operator|::
name|size_type
name|Begin
operator|,
name|End
expr_stmt|;
block|}
struct|;
end_struct

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief A range of cached tokens that should be erased after lexing
end_comment

begin_comment
comment|/// when backtracking requires the erasure of such cached tokens.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|CachedTokensRange
operator|>
name|CachedTokenRangeToErase
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Returns the range of cached tokens that were lexed since
end_comment

begin_comment
comment|/// EnableBacktrackAtThisPos() was previously called.
end_comment

begin_function_decl
name|CachedTokensRange
name|LastCachedTokenRange
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Erase the range of cached tokens that were lexed since
end_comment

begin_comment
comment|/// EnableBacktrackAtThisPos() was previously called.
end_comment

begin_function_decl
name|void
name|EraseCachedTokens
parameter_list|(
name|CachedTokensRange
name|TokenRange
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Make Preprocessor re-lex the tokens that were lexed since
end_comment

begin_comment
comment|/// EnableBacktrackAtThisPos() was previously called.
end_comment

begin_function_decl
name|void
name|Backtrack
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief True if EnableBacktrackAtThisPos() was called and
end_comment

begin_comment
comment|/// caching of tokens is on.
end_comment

begin_expr_stmt
name|bool
name|isBacktrackEnabled
argument_list|()
specifier|const
block|{
return|return
operator|!
name|BacktrackPositions
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Lex the next token for this preprocessor.
end_comment

begin_function_decl
name|void
name|Lex
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|LexAfterModuleImport
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makeModuleVisible
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|SourceLocation
name|getModuleImportLoc
argument_list|(
name|Module
operator|*
name|M
argument_list|)
decl|const
block|{
return|return
name|CurSubmoduleState
operator|->
name|VisibleModules
operator|.
name|getImportLoc
argument_list|(
name|M
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Lex a string literal, which may be the concatenation of multiple
end_comment

begin_comment
comment|/// string literals and may even come from macro expansion.
end_comment

begin_comment
comment|/// \returns true on success, false if a error diagnostic has been generated.
end_comment

begin_decl_stmt
name|bool
name|LexStringLiteral
argument_list|(
name|Token
operator|&
name|Result
argument_list|,
name|std
operator|::
name|string
operator|&
name|String
argument_list|,
specifier|const
name|char
operator|*
name|DiagnosticTag
argument_list|,
name|bool
name|AllowMacroExpansion
argument_list|)
block|{
if|if
condition|(
name|AllowMacroExpansion
condition|)
name|Lex
argument_list|(
name|Result
argument_list|)
expr_stmt|;
else|else
name|LexUnexpandedToken
argument_list|(
name|Result
argument_list|)
expr_stmt|;
return|return
name|FinishLexStringLiteral
argument_list|(
name|Result
argument_list|,
name|String
argument_list|,
name|DiagnosticTag
argument_list|,
name|AllowMacroExpansion
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Complete the lexing of a string literal where the first token has
end_comment

begin_comment
comment|/// already been lexed (see LexStringLiteral).
end_comment

begin_decl_stmt
name|bool
name|FinishLexStringLiteral
argument_list|(
name|Token
operator|&
name|Result
argument_list|,
name|std
operator|::
name|string
operator|&
name|String
argument_list|,
specifier|const
name|char
operator|*
name|DiagnosticTag
argument_list|,
name|bool
name|AllowMacroExpansion
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Lex a token.  If it's a comment, keep lexing until we get
end_comment

begin_comment
comment|/// something not a comment.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is useful in -E -C mode where comments would foul up preprocessor
end_comment

begin_comment
comment|/// directive handling.
end_comment

begin_function
name|void
name|LexNonComment
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
block|{
do|do
name|Lex
argument_list|(
name|Result
argument_list|)
expr_stmt|;
do|while
condition|(
name|Result
operator|.
name|getKind
argument_list|()
operator|==
name|tok
operator|::
name|comment
condition|)
do|;
block|}
end_function

begin_comment
comment|/// \brief Just like Lex, but disables macro expansion of identifier tokens.
end_comment

begin_function
name|void
name|LexUnexpandedToken
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
block|{
comment|// Disable macro expansion.
name|bool
name|OldVal
init|=
name|DisableMacroExpansion
decl_stmt|;
name|DisableMacroExpansion
operator|=
name|true
expr_stmt|;
comment|// Lex the token.
name|Lex
argument_list|(
name|Result
argument_list|)
expr_stmt|;
comment|// Reenable it.
name|DisableMacroExpansion
operator|=
name|OldVal
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Like LexNonComment, but this disables macro expansion of
end_comment

begin_comment
comment|/// identifier tokens.
end_comment

begin_function
name|void
name|LexUnexpandedNonComment
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
block|{
do|do
name|LexUnexpandedToken
argument_list|(
name|Result
argument_list|)
expr_stmt|;
do|while
condition|(
name|Result
operator|.
name|getKind
argument_list|()
operator|==
name|tok
operator|::
name|comment
condition|)
do|;
block|}
end_function

begin_comment
comment|/// \brief Parses a simple integer literal to get its numeric value.  Floating
end_comment

begin_comment
comment|/// point literals and user defined literals are rejected.  Used primarily to
end_comment

begin_comment
comment|/// handle pragmas that accept integer arguments.
end_comment

begin_function_decl
name|bool
name|parseSimpleIntegerLiteral
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
name|uint64_t
modifier|&
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Disables macro expansion everywhere except for preprocessor directives.
end_comment

begin_function
name|void
name|SetMacroExpansionOnlyInDirectives
parameter_list|()
block|{
name|DisableMacroExpansion
operator|=
name|true
expr_stmt|;
name|MacroExpansionInDirectivesOverride
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Peeks ahead N tokens and returns that token without consuming any
end_comment

begin_comment
comment|/// tokens.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// LookAhead(0) returns the next token that would be returned by Lex(),
end_comment

begin_comment
comment|/// LookAhead(1) returns the token after it, etc.  This returns normal
end_comment

begin_comment
comment|/// tokens after phase 5.  As such, it is equivalent to using
end_comment

begin_comment
comment|/// 'Lex', not 'LexUnexpandedToken'.
end_comment

begin_function
specifier|const
name|Token
modifier|&
name|LookAhead
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
if|if
condition|(
name|CachedLexPos
operator|+
name|N
operator|<
name|CachedTokens
operator|.
name|size
argument_list|()
condition|)
return|return
name|CachedTokens
index|[
name|CachedLexPos
operator|+
name|N
index|]
return|;
else|else
return|return
name|PeekAhead
argument_list|(
name|N
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief When backtracking is enabled and tokens are cached,
end_comment

begin_comment
comment|/// this allows to revert a specific number of tokens.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the number of tokens being reverted should be up to the last
end_comment

begin_comment
comment|/// backtrack position, not more.
end_comment

begin_function
name|void
name|RevertCachedTokens
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|isBacktrackEnabled
argument_list|()
operator|&&
literal|"Should only be called when tokens are cached for backtracking"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|signed
argument_list|(
name|CachedLexPos
argument_list|)
operator|-
name|signed
argument_list|(
name|N
argument_list|)
operator|>=
name|signed
argument_list|(
name|BacktrackPositions
operator|.
name|back
argument_list|()
argument_list|)
operator|&&
literal|"Should revert tokens up to the last backtrack position, not more"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|signed
argument_list|(
name|CachedLexPos
argument_list|)
operator|-
name|signed
argument_list|(
name|N
argument_list|)
operator|>=
literal|0
operator|&&
literal|"Corrupted backtrack positions ?"
argument_list|)
expr_stmt|;
name|CachedLexPos
operator|-=
name|N
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Enters a token in the token stream to be lexed next.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If BackTrack() is called afterwards, the token will remain at the
end_comment

begin_comment
comment|/// insertion point.
end_comment

begin_function
name|void
name|EnterToken
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
block|{
name|EnterCachingLexMode
argument_list|()
expr_stmt|;
name|CachedTokens
operator|.
name|insert
argument_list|(
name|CachedTokens
operator|.
name|begin
argument_list|()
operator|+
name|CachedLexPos
argument_list|,
name|Tok
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// We notify the Preprocessor that if it is caching tokens (because
end_comment

begin_comment
comment|/// backtrack is enabled) it should replace the most recent cached tokens
end_comment

begin_comment
comment|/// with the given annotation token. This function has no effect if
end_comment

begin_comment
comment|/// backtracking is not enabled.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the use of this function is just for optimization, so that the
end_comment

begin_comment
comment|/// cached tokens doesn't get re-parsed and re-resolved after a backtrack is
end_comment

begin_comment
comment|/// invoked.
end_comment

begin_function
name|void
name|AnnotateCachedTokens
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
block|{
name|assert
argument_list|(
name|Tok
operator|.
name|isAnnotation
argument_list|()
operator|&&
literal|"Expected annotation token"
argument_list|)
expr_stmt|;
if|if
condition|(
name|CachedLexPos
operator|!=
literal|0
operator|&&
name|isBacktrackEnabled
argument_list|()
condition|)
name|AnnotatePreviousCachedTokens
argument_list|(
name|Tok
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Get the location of the last cached token, suitable for setting the end
end_comment

begin_comment
comment|/// location of an annotation token.
end_comment

begin_expr_stmt
name|SourceLocation
name|getLastCachedTokenLocation
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|CachedLexPos
operator|!=
literal|0
argument_list|)
block|;
return|return
name|CachedTokens
index|[
name|CachedLexPos
operator|-
literal|1
index|]
operator|.
name|getLastLoc
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Whether \p Tok is the most recent token (`CachedLexPos - 1`) in
end_comment

begin_comment
comment|/// CachedTokens.
end_comment

begin_decl_stmt
name|bool
name|IsPreviousCachedToken
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Replace token in `CachedLexPos - 1` in CachedTokens by the tokens
end_comment

begin_comment
comment|/// in \p NewToks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Useful when a token needs to be split in smaller ones and CachedTokens
end_comment

begin_comment
comment|/// most recent token must to be updated to reflect that.
end_comment

begin_decl_stmt
name|void
name|ReplacePreviousCachedToken
argument_list|(
name|ArrayRef
operator|<
name|Token
operator|>
name|NewToks
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Replace the last token with an annotation token.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Like AnnotateCachedTokens(), this routine replaces an
end_comment

begin_comment
comment|/// already-parsed (and resolved) token with an annotation
end_comment

begin_comment
comment|/// token. However, this routine only replaces the last token with
end_comment

begin_comment
comment|/// the annotation token; it does not affect any other cached
end_comment

begin_comment
comment|/// tokens. This function has no effect if backtracking is not
end_comment

begin_comment
comment|/// enabled.
end_comment

begin_function
name|void
name|ReplaceLastTokenWithAnnotation
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
block|{
name|assert
argument_list|(
name|Tok
operator|.
name|isAnnotation
argument_list|()
operator|&&
literal|"Expected annotation token"
argument_list|)
expr_stmt|;
if|if
condition|(
name|CachedLexPos
operator|!=
literal|0
operator|&&
name|isBacktrackEnabled
argument_list|()
condition|)
name|CachedTokens
index|[
name|CachedLexPos
operator|-
literal|1
index|]
operator|=
name|Tok
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Enter an annotation token into the token stream.
end_comment

begin_decl_stmt
name|void
name|EnterAnnotationToken
argument_list|(
name|SourceRange
name|Range
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|void
operator|*
name|AnnotationVal
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Update the current token to represent the provided
end_comment

begin_comment
comment|/// identifier, in order to cache an action performed by typo correction.
end_comment

begin_function
name|void
name|TypoCorrectToken
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
block|{
name|assert
argument_list|(
name|Tok
operator|.
name|getIdentifierInfo
argument_list|()
operator|&&
literal|"Expected identifier token"
argument_list|)
expr_stmt|;
if|if
condition|(
name|CachedLexPos
operator|!=
literal|0
operator|&&
name|isBacktrackEnabled
argument_list|()
condition|)
name|CachedTokens
index|[
name|CachedLexPos
operator|-
literal|1
index|]
operator|=
name|Tok
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Recompute the current lexer kind based on the CurLexer/CurPTHLexer/
end_comment

begin_comment
comment|/// CurTokenLexer pointers.
end_comment

begin_function_decl
name|void
name|recomputeCurLexerKind
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns true if incremental processing is enabled
end_comment

begin_expr_stmt
name|bool
name|isIncrementalProcessingEnabled
argument_list|()
specifier|const
block|{
return|return
name|IncrementalProcessing
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Enables the incremental processing
end_comment

begin_function
name|void
name|enableIncrementalProcessing
parameter_list|(
name|bool
name|value
init|=
name|true
parameter_list|)
block|{
name|IncrementalProcessing
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Specify the point at which code-completion will be performed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param File the file in which code completion should occur. If
end_comment

begin_comment
comment|/// this file is included multiple times, code-completion will
end_comment

begin_comment
comment|/// perform completion the first time it is included. If NULL, this
end_comment

begin_comment
comment|/// function clears out the code-completion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Line the line at which code completion should occur
end_comment

begin_comment
comment|/// (1-based).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Column the column at which code completion should occur
end_comment

begin_comment
comment|/// (1-based).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
name|bool
name|SetCodeCompletionPoint
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|File
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Column
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine if we are performing code completion.
end_comment

begin_expr_stmt
name|bool
name|isCodeCompletionEnabled
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionFile
operator|!=
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the location of the code-completion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns an invalid location if code-completion is not enabled or the file
end_comment

begin_comment
comment|/// containing the code-completion point has not been lexed yet.
end_comment

begin_expr_stmt
name|SourceLocation
name|getCodeCompletionLoc
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the start location of the file of code-completion point.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns an invalid location if code-completion is not enabled or the file
end_comment

begin_comment
comment|/// containing the code-completion point has not been lexed yet.
end_comment

begin_expr_stmt
name|SourceLocation
name|getCodeCompletionFileLoc
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionFileLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if code-completion is enabled and we have hit the
end_comment

begin_comment
comment|/// code-completion point.
end_comment

begin_expr_stmt
name|bool
name|isCodeCompletionReached
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionReached
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Note that we hit the code-completion point.
end_comment

begin_function
name|void
name|setCodeCompletionReached
parameter_list|()
block|{
name|assert
argument_list|(
name|isCodeCompletionEnabled
argument_list|()
operator|&&
literal|"Code-completion not enabled!"
argument_list|)
expr_stmt|;
name|CodeCompletionReached
operator|=
name|true
expr_stmt|;
comment|// Silence any diagnostics that occur after we hit the code-completion.
name|getDiagnostics
argument_list|()
operator|.
name|setSuppressAllDiagnostics
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief The location of the currently-active \#pragma clang
end_comment

begin_comment
comment|/// arc_cf_code_audited begin.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns an invalid location if there is no such pragma active.
end_comment

begin_expr_stmt
name|SourceLocation
name|getPragmaARCCFCodeAuditedLoc
argument_list|()
specifier|const
block|{
return|return
name|PragmaARCCFCodeAuditedLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the location of the currently-active \#pragma clang
end_comment

begin_comment
comment|/// arc_cf_code_audited begin.  An invalid location ends the pragma.
end_comment

begin_function
name|void
name|setPragmaARCCFCodeAuditedLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|PragmaARCCFCodeAuditedLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief The location of the currently-active \#pragma clang
end_comment

begin_comment
comment|/// assume_nonnull begin.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns an invalid location if there is no such pragma active.
end_comment

begin_expr_stmt
name|SourceLocation
name|getPragmaAssumeNonNullLoc
argument_list|()
specifier|const
block|{
return|return
name|PragmaAssumeNonNullLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the location of the currently-active \#pragma clang
end_comment

begin_comment
comment|/// assume_nonnull begin.  An invalid location ends the pragma.
end_comment

begin_function
name|void
name|setPragmaAssumeNonNullLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|PragmaAssumeNonNullLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Set the directory in which the main file should be considered
end_comment

begin_comment
comment|/// to have been found, if it is not a real file.
end_comment

begin_function
name|void
name|setMainFileDir
parameter_list|(
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
parameter_list|)
block|{
name|MainFileDir
operator|=
name|Dir
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Instruct the preprocessor to skip part of the main source file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Bytes The number of bytes in the preamble to skip.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param StartOfLine Whether skipping these bytes puts the lexer at the
end_comment

begin_comment
comment|/// start of a line.
end_comment

begin_function
name|void
name|setSkipMainFilePreamble
parameter_list|(
name|unsigned
name|Bytes
parameter_list|,
name|bool
name|StartOfLine
parameter_list|)
block|{
name|SkipMainFilePreamble
operator|.
name|first
operator|=
name|Bytes
expr_stmt|;
name|SkipMainFilePreamble
operator|.
name|second
operator|=
name|StartOfLine
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Forwarding function for diagnostics.  This emits a diagnostic at
end_comment

begin_comment
comment|/// the specified Token's location, translating the token's start
end_comment

begin_comment
comment|/// position in the current buffer into a SourcePosition object for rendering.
end_comment

begin_decl_stmt
name|DiagnosticBuilder
name|Diag
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|unsigned
name|DiagID
argument_list|)
decl|const
block|{
return|return
name|Diags
operator|->
name|Report
argument_list|(
name|Loc
argument_list|,
name|DiagID
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|DiagnosticBuilder
name|Diag
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|,
name|unsigned
name|DiagID
argument_list|)
decl|const
block|{
return|return
name|Diags
operator|->
name|Report
argument_list|(
name|Tok
operator|.
name|getLocation
argument_list|()
argument_list|,
name|DiagID
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the 'spelling' of the token at the given
end_comment

begin_comment
comment|/// location; does not go up to the spelling location or down to the
end_comment

begin_comment
comment|/// expansion location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param buffer A buffer which will be used only if the token requires
end_comment

begin_comment
comment|///   "cleaning", e.g. if it contains trigraphs or escaped newlines
end_comment

begin_comment
comment|/// \param invalid If non-null, will be set \c true if an error occurs.
end_comment

begin_decl_stmt
name|StringRef
name|getSpelling
argument_list|(
name|SourceLocation
name|loc
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|buffer
argument_list|,
name|bool
operator|*
name|invalid
operator|=
name|nullptr
argument_list|)
decl|const
block|{
return|return
name|Lexer
operator|::
name|getSpelling
argument_list|(
name|loc
argument_list|,
name|buffer
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|,
name|invalid
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Return the 'spelling' of the Tok token.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The spelling of a token is the characters used to represent the token in
end_comment

begin_comment
comment|/// the source file after trigraph expansion and escaped-newline folding.  In
end_comment

begin_comment
comment|/// particular, this wants to get the true, uncanonicalized, spelling of
end_comment

begin_comment
comment|/// things like digraphs, UCNs, etc.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Invalid If non-null, will be set \c true if an error occurs.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getSpelling
argument_list|(
argument|const Token&Tok
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
specifier|const
block|{
return|return
name|Lexer
operator|::
name|getSpelling
argument_list|(
name|Tok
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|,
name|Invalid
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Get the spelling of a token into a preallocated buffer, instead
end_comment

begin_comment
comment|/// of as an std::string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The caller is required to allocate enough space for the token, which is
end_comment

begin_comment
comment|/// guaranteed to be at least Tok.getLength() bytes long. The length of the
end_comment

begin_comment
comment|/// actual result is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this method may do two possible things: it may either fill in
end_comment

begin_comment
comment|/// the buffer specified with characters, or it may *change the input pointer*
end_comment

begin_comment
comment|/// to point to a constant buffer with the data already in it (avoiding a
end_comment

begin_comment
comment|/// copy).  The caller is not allowed to modify the returned buffer pointer
end_comment

begin_comment
comment|/// if an internal buffer is returned.
end_comment

begin_decl_stmt
name|unsigned
name|getSpelling
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|,
specifier|const
name|char
operator|*
operator|&
name|Buffer
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
block|{
return|return
name|Lexer
operator|::
name|getSpelling
argument_list|(
name|Tok
argument_list|,
name|Buffer
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|,
name|Invalid
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Get the spelling of a token into a SmallVector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the returned StringRef may not point to the
end_comment

begin_comment
comment|/// supplied buffer if a copy can be avoided.
end_comment

begin_decl_stmt
name|StringRef
name|getSpelling
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Buffer
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Relex the token at the specified location.
end_comment

begin_comment
comment|/// \returns true if there was a failure, false on success.
end_comment

begin_function
name|bool
name|getRawToken
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Token
modifier|&
name|Result
parameter_list|,
name|bool
name|IgnoreWhiteSpace
init|=
name|false
parameter_list|)
block|{
return|return
name|Lexer
operator|::
name|getRawToken
argument_list|(
name|Loc
argument_list|,
name|Result
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|,
name|IgnoreWhiteSpace
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Given a Token \p Tok that is a numeric constant with length 1,
end_comment

begin_comment
comment|/// return the character.
end_comment

begin_decl_stmt
name|char
name|getSpellingOfSingleCharacterNumericConstant
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Tok
operator|.
name|is
argument_list|(
name|tok
operator|::
name|numeric_constant
argument_list|)
operator|&&
name|Tok
operator|.
name|getLength
argument_list|()
operator|==
literal|1
operator|&&
literal|"Called on unsupported token"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|Tok
operator|.
name|needsCleaning
argument_list|()
operator|&&
literal|"Token can't need cleaning with length 1"
argument_list|)
expr_stmt|;
comment|// If the token is carrying a literal data pointer, just use it.
if|if
condition|(
specifier|const
name|char
modifier|*
name|D
init|=
name|Tok
operator|.
name|getLiteralData
argument_list|()
condition|)
return|return
operator|*
name|D
return|;
comment|// Otherwise, fall back on getCharacterData, which is slower, but always
comment|// works.
return|return
operator|*
name|SourceMgr
operator|.
name|getCharacterData
argument_list|(
name|Tok
operator|.
name|getLocation
argument_list|()
argument_list|,
name|Invalid
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the name of the immediate macro expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine starts from a source location, and finds the name of the
end_comment

begin_comment
comment|/// macro responsible for its immediate expansion. It looks through any
end_comment

begin_comment
comment|/// intervening macro argument expansions to compute this. It returns a
end_comment

begin_comment
comment|/// StringRef that refers to the SourceManager-owned buffer of the source
end_comment

begin_comment
comment|/// where that macro name is spelled. Thus, the result shouldn't out-live
end_comment

begin_comment
comment|/// the SourceManager.
end_comment

begin_function
name|StringRef
name|getImmediateMacroName
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
return|return
name|Lexer
operator|::
name|getImmediateMacroName
argument_list|(
name|Loc
argument_list|,
name|SourceMgr
argument_list|,
name|getLangOpts
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Plop the specified string into a scratch buffer and set the
end_comment

begin_comment
comment|/// specified token's location and length to it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If specified, the source location provides a location of the expansion
end_comment

begin_comment
comment|/// point of the token.
end_comment

begin_function_decl
name|void
name|CreateString
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|Token
modifier|&
name|Tok
parameter_list|,
name|SourceLocation
name|ExpansionLocStart
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|SourceLocation
name|ExpansionLocEnd
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Computes the source location just past the end of the
end_comment

begin_comment
comment|/// token at this source location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine can be used to produce a source location that
end_comment

begin_comment
comment|/// points just past the end of the token referenced by \p Loc, and
end_comment

begin_comment
comment|/// is generally used when a diagnostic needs to point just after a
end_comment

begin_comment
comment|/// token where it expected something different that it received. If
end_comment

begin_comment
comment|/// the returned source location would not be meaningful (e.g., if
end_comment

begin_comment
comment|/// it points into a macro), this routine returns an invalid
end_comment

begin_comment
comment|/// source location.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Offset an offset from the end of the token, where the source
end_comment

begin_comment
comment|/// location should refer to. The default offset (0) produces a source
end_comment

begin_comment
comment|/// location pointing just past the end of the token; an offset of 1 produces
end_comment

begin_comment
comment|/// a source location pointing to the last character in the token, etc.
end_comment

begin_function
name|SourceLocation
name|getLocForEndOfToken
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|Offset
init|=
literal|0
parameter_list|)
block|{
return|return
name|Lexer
operator|::
name|getLocForEndOfToken
argument_list|(
name|Loc
argument_list|,
name|Offset
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns true if the given MacroID location points at the first
end_comment

begin_comment
comment|/// token of the macro expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param MacroBegin If non-null and function returns true, it is set to
end_comment

begin_comment
comment|/// begin location of the macro.
end_comment

begin_decl_stmt
name|bool
name|isAtStartOfMacroExpansion
argument_list|(
name|SourceLocation
name|loc
argument_list|,
name|SourceLocation
operator|*
name|MacroBegin
operator|=
name|nullptr
argument_list|)
decl|const
block|{
return|return
name|Lexer
operator|::
name|isAtStartOfMacroExpansion
argument_list|(
name|loc
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|,
name|MacroBegin
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns true if the given MacroID location points at the last
end_comment

begin_comment
comment|/// token of the macro expansion.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param MacroEnd If non-null and function returns true, it is set to
end_comment

begin_comment
comment|/// end location of the macro.
end_comment

begin_decl_stmt
name|bool
name|isAtEndOfMacroExpansion
argument_list|(
name|SourceLocation
name|loc
argument_list|,
name|SourceLocation
operator|*
name|MacroEnd
operator|=
name|nullptr
argument_list|)
decl|const
block|{
return|return
name|Lexer
operator|::
name|isAtEndOfMacroExpansion
argument_list|(
name|loc
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|,
name|MacroEnd
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Print the token to stderr, used for debugging.
end_comment

begin_decl_stmt
name|void
name|DumpToken
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|,
name|bool
name|DumpFlags
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DumpLocation
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DumpMacro
argument_list|(
specifier|const
name|MacroInfo
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|dumpMacroInfo
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Given a location that specifies the start of a
end_comment

begin_comment
comment|/// token, return a new location that specifies a character within the token.
end_comment

begin_decl_stmt
name|SourceLocation
name|AdvanceToTokenCharacter
argument_list|(
name|SourceLocation
name|TokStart
argument_list|,
name|unsigned
name|Char
argument_list|)
decl|const
block|{
return|return
name|Lexer
operator|::
name|AdvanceToTokenCharacter
argument_list|(
name|TokStart
argument_list|,
name|Char
argument_list|,
name|SourceMgr
argument_list|,
name|LangOpts
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Increment the counters for the number of token paste operations
end_comment

begin_comment
comment|/// performed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If fast was specified, this is a 'fast paste' case we handled.
end_comment

begin_function
name|void
name|IncrementPasteCounter
parameter_list|(
name|bool
name|isFast
parameter_list|)
block|{
if|if
condition|(
name|isFast
condition|)
operator|++
name|NumFastTokenPaste
expr_stmt|;
else|else
operator|++
name|NumTokenPaste
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|PrintStats
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|size_t
name|getTotalMemory
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// When the macro expander pastes together a comment (/##/) in Microsoft
end_comment

begin_comment
comment|/// mode, this method handles updating the current state, returning the
end_comment

begin_comment
comment|/// token on the next source line.
end_comment

begin_function_decl
name|void
name|HandleMicrosoftCommentPaste
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Preprocessor callback methods.  These are invoked by a lexer as various
end_comment

begin_comment
comment|// directives and events are found.
end_comment

begin_comment
comment|/// Given a tok::raw_identifier token, look up the
end_comment

begin_comment
comment|/// identifier information for the token and install it into the token,
end_comment

begin_comment
comment|/// updating the token kind accordingly.
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|LookUpIdentifierInfo
argument_list|(
name|Token
operator|&
name|Identifier
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|unsigned
operator|>
name|PoisonReasons
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Specifies the reason for poisoning an identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If that identifier is accessed while poisoned, then this reason will be
end_comment

begin_comment
comment|/// used instead of the default "poisoned" diagnostic.
end_comment

begin_function_decl
name|void
name|SetPoisonReason
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Display reason for poisoned identifier.
end_comment

begin_function_decl
name|void
name|HandlePoisonedIdentifier
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|MaybeHandlePoisonedIdentifier
parameter_list|(
name|Token
modifier|&
name|Identifier
parameter_list|)
block|{
if|if
condition|(
name|IdentifierInfo
modifier|*
name|II
init|=
name|Identifier
operator|.
name|getIdentifierInfo
argument_list|()
condition|)
block|{
if|if
condition|(
name|II
operator|->
name|isPoisoned
argument_list|()
condition|)
block|{
name|HandlePoisonedIdentifier
argument_list|(
name|Identifier
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Identifiers used for SEH handling in Borland. These are only
end_comment

begin_comment
comment|/// allowed in particular circumstances
end_comment

begin_comment
comment|// __except block
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|Ident__exception_code
decl_stmt|,
modifier|*
name|Ident___exception_code
decl_stmt|,
modifier|*
name|Ident_GetExceptionCode
decl_stmt|;
end_decl_stmt

begin_comment
comment|// __except filter expression
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|Ident__exception_info
decl_stmt|,
modifier|*
name|Ident___exception_info
decl_stmt|,
modifier|*
name|Ident_GetExceptionInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// __finally
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|Ident__abnormal_termination
decl_stmt|,
modifier|*
name|Ident___abnormal_termination
decl_stmt|,
modifier|*
name|Ident_AbnormalTermination
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|getCurLexerEndPos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|diagnoseMissingHeaderInUmbrellaDir
parameter_list|(
specifier|const
name|Module
modifier|&
name|Mod
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_function_decl
name|void
name|PoisonSEHIdentifiers
parameter_list|(
name|bool
name|Poison
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Borland
end_comment

begin_comment
comment|/// \brief Callback invoked when the lexer reads an identifier and has
end_comment

begin_comment
comment|/// filled in the tokens IdentifierInfo member.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback potentially macro expands it or turns it into a named
end_comment

begin_comment
comment|/// token (like 'for').
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if we actually computed a token, false if we need to
end_comment

begin_comment
comment|/// lex again.
end_comment

begin_function_decl
name|bool
name|HandleIdentifier
parameter_list|(
name|Token
modifier|&
name|Identifier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Callback invoked when the lexer hits the end of the current file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This either returns the EOF token and returns true, or
end_comment

begin_comment
comment|/// pops a level off the include stack and returns false, at which point the
end_comment

begin_comment
comment|/// client should call lex again.
end_comment

begin_function_decl
name|bool
name|HandleEndOfFile
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
name|bool
name|isEndOfMacro
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Callback invoked when the current TokenLexer hits the end of its
end_comment

begin_comment
comment|/// token stream.
end_comment

begin_function_decl
name|bool
name|HandleEndOfTokenLexer
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Callback invoked when the lexer sees a # token at the start of a
end_comment

begin_comment
comment|/// line.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This consumes the directive, modifies the lexer/preprocessor state, and
end_comment

begin_comment
comment|/// advances the lexer(s) so that the next token read is the correct one.
end_comment

begin_function_decl
name|void
name|HandleDirective
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Ensure that the next token is a tok::eod token.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If not, emit a diagnostic and consume up until the eod.
end_comment

begin_comment
comment|/// If \p EnableMacros is true, then we consider macros that expand to zero
end_comment

begin_comment
comment|/// tokens as being ok.
end_comment

begin_function_decl
name|void
name|CheckEndOfDirective
parameter_list|(
specifier|const
name|char
modifier|*
name|Directive
parameter_list|,
name|bool
name|EnableMacros
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read and discard all tokens remaining on the current line until
end_comment

begin_comment
comment|/// the tok::eod token is found.
end_comment

begin_function_decl
name|void
name|DiscardUntilEndOfDirective
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns true if the preprocessor has seen a use of
end_comment

begin_comment
comment|/// __DATE__ or __TIME__ in the file so far.
end_comment

begin_expr_stmt
name|bool
name|SawDateOrTime
argument_list|()
specifier|const
block|{
return|return
name|DATELoc
operator|!=
name|SourceLocation
argument_list|()
operator|||
name|TIMELoc
operator|!=
name|SourceLocation
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getCounterValue
argument_list|()
specifier|const
block|{
return|return
name|CounterValue
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCounterValue
parameter_list|(
name|unsigned
name|V
parameter_list|)
block|{
name|CounterValue
operator|=
name|V
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieves the module that we're currently building, if any.
end_comment

begin_function_decl
name|Module
modifier|*
name|getCurrentModule
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Allocate a new MacroInfo object with the provided SourceLocation.
end_comment

begin_function_decl
name|MacroInfo
modifier|*
name|AllocateMacroInfo
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Turn the specified lexer token into a fully checked and spelled
end_comment

begin_comment
comment|/// filename, e.g. as an operand of \#include.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The caller is expected to provide a buffer that is large enough to hold
end_comment

begin_comment
comment|/// the spelling of the filename, but is also expected to handle the case
end_comment

begin_comment
comment|/// when this method decides to use a different buffer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if the input filename was in<>'s or false if it was
end_comment

begin_comment
comment|/// in ""'s.
end_comment

begin_function_decl
name|bool
name|GetIncludeFilenameSpelling
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
modifier|&
name|Filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Given a "foo" or \<foo> reference, look up the indicated file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns null on failure.  \p isAngled indicates whether the file
end_comment

begin_comment
comment|/// reference is for system \#include's or not (i.e. using<> instead of "").
end_comment

begin_decl_stmt
specifier|const
name|FileEntry
modifier|*
name|LookupFile
argument_list|(
name|SourceLocation
name|FilenameLoc
argument_list|,
name|StringRef
name|Filename
argument_list|,
name|bool
name|isAngled
argument_list|,
specifier|const
name|DirectoryLookup
operator|*
name|FromDir
argument_list|,
specifier|const
name|FileEntry
operator|*
name|FromFile
argument_list|,
specifier|const
name|DirectoryLookup
operator|*
operator|&
name|CurDir
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|SearchPath
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|RelativePath
argument_list|,
name|ModuleMap
operator|::
name|KnownHeader
operator|*
name|SuggestedModule
argument_list|,
name|bool
operator|*
name|IsMapped
argument_list|,
name|bool
name|SkipCache
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get the DirectoryLookup structure used to find the current
end_comment

begin_comment
comment|/// FileEntry, if CurLexer is non-null and if applicable.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This allows us to implement \#include_next and find directory-specific
end_comment

begin_comment
comment|/// properties.
end_comment

begin_function
specifier|const
name|DirectoryLookup
modifier|*
name|GetCurDirLookup
parameter_list|()
block|{
return|return
name|CurDirLookup
return|;
block|}
end_function

begin_comment
comment|/// \brief Return true if we're in the top-level file, not in a \#include.
end_comment

begin_expr_stmt
name|bool
name|isInPrimaryFile
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return true if we're in the main file (specifically, if we are 0
end_comment

begin_comment
comment|/// (zero) levels deep \#include. This is used by the lexer to determine if
end_comment

begin_comment
comment|/// it needs to generate errors about unterminated \#if directives.
end_comment

begin_expr_stmt
name|bool
name|isInMainFile
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Handle cases where the \#include name is expanded
end_comment

begin_comment
comment|/// from a macro as multiple tokens, which need to be glued together.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This occurs for code like:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///    \#define FOO<x/y.h>
end_comment

begin_comment
comment|///    \#include FOO
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// because in this case, "<x/y.h>" is returned as 7 tokens, not one.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code concatenates and consumes tokens up to the '>' token.  It
end_comment

begin_comment
comment|/// returns false if the> was found, otherwise it returns true if it finds
end_comment

begin_comment
comment|/// and consumes the EOD marker.
end_comment

begin_decl_stmt
name|bool
name|ConcatenateIncludeName
argument_list|(
name|SmallString
operator|<
literal|128
operator|>
operator|&
name|FilenameBuffer
argument_list|,
name|SourceLocation
operator|&
name|End
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Lex an on-off-switch (C99 6.10.6p2) and verify that it is
end_comment

begin_comment
comment|/// followed by EOD.  Return true if the token is not a valid on-off-switch.
end_comment

begin_decl_stmt
name|bool
name|LexOnOffSwitch
argument_list|(
name|tok
operator|::
name|OnOffSwitch
operator|&
name|OOS
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|CheckMacroName
parameter_list|(
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
name|MacroUse
name|isDefineUndef
parameter_list|,
name|bool
modifier|*
name|ShadowFlag
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EnterSubmodule
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
name|SourceLocation
name|ImportLoc
parameter_list|,
name|bool
name|ForPragma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Module
modifier|*
name|LeaveSubmodule
parameter_list|(
name|bool
name|ForPragma
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_function
name|void
name|PushIncludeMacroStack
parameter_list|()
block|{
name|assert
argument_list|(
name|CurLexerKind
operator|!=
name|CLK_CachingLexer
operator|&&
literal|"cannot push a caching lexer"
argument_list|)
expr_stmt|;
name|IncludeMacroStack
operator|.
name|emplace_back
argument_list|(
name|CurLexerKind
argument_list|,
name|CurLexerSubmodule
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|CurLexer
argument_list|)
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|CurPTHLexer
argument_list|)
argument_list|,
name|CurPPLexer
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|CurTokenLexer
argument_list|)
argument_list|,
name|CurDirLookup
argument_list|)
expr_stmt|;
name|CurPPLexer
operator|=
name|nullptr
expr_stmt|;
block|}
end_function

begin_function
name|void
name|PopIncludeMacroStack
parameter_list|()
block|{
name|CurLexer
operator|=
name|std
operator|::
name|move
argument_list|(
name|IncludeMacroStack
operator|.
name|back
argument_list|()
operator|.
name|TheLexer
argument_list|)
expr_stmt|;
name|CurPTHLexer
operator|=
name|std
operator|::
name|move
argument_list|(
name|IncludeMacroStack
operator|.
name|back
argument_list|()
operator|.
name|ThePTHLexer
argument_list|)
expr_stmt|;
name|CurPPLexer
operator|=
name|IncludeMacroStack
operator|.
name|back
argument_list|()
operator|.
name|ThePPLexer
expr_stmt|;
name|CurTokenLexer
operator|=
name|std
operator|::
name|move
argument_list|(
name|IncludeMacroStack
operator|.
name|back
argument_list|()
operator|.
name|TheTokenLexer
argument_list|)
expr_stmt|;
name|CurDirLookup
operator|=
name|IncludeMacroStack
operator|.
name|back
argument_list|()
operator|.
name|TheDirLookup
expr_stmt|;
name|CurLexerSubmodule
operator|=
name|IncludeMacroStack
operator|.
name|back
argument_list|()
operator|.
name|TheSubmodule
expr_stmt|;
name|CurLexerKind
operator|=
name|IncludeMacroStack
operator|.
name|back
argument_list|()
operator|.
name|CurLexerKind
expr_stmt|;
name|IncludeMacroStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|PropagateLineStartLeadingSpaceInfo
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Determine whether we need to create module macros for #defines in the
end_comment

begin_comment
comment|/// current context.
end_comment

begin_expr_stmt
name|bool
name|needModuleMacros
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Update the set of active module macros and ambiguity flag for a module
end_comment

begin_comment
comment|/// macro name.
end_comment

begin_function_decl
name|void
name|updateModuleMacroInfo
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|ModuleMacroInfo
modifier|&
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DefMacroDirective
modifier|*
name|AllocateDefMacroDirective
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UndefMacroDirective
modifier|*
name|AllocateUndefMacroDirective
parameter_list|(
name|SourceLocation
name|UndefLoc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|VisibilityMacroDirective
modifier|*
name|AllocateVisibilityMacroDirective
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|isPublic
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Lex and validate a macro name, which occurs after a
end_comment

begin_comment
comment|/// \#define or \#undef.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param MacroNameTok Token that represents the name defined or undefined.
end_comment

begin_comment
comment|/// \param IsDefineUndef Kind if preprocessor directive.
end_comment

begin_comment
comment|/// \param ShadowFlag Points to flag that is set if macro name shadows
end_comment

begin_comment
comment|///                   a keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This emits a diagnostic, sets the token kind to eod,
end_comment

begin_comment
comment|/// and discards the rest of the macro line if the macro name is invalid.
end_comment

begin_function_decl
name|void
name|ReadMacroName
parameter_list|(
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
name|MacroUse
name|IsDefineUndef
init|=
name|MU_Other
parameter_list|,
name|bool
modifier|*
name|ShadowFlag
init|=
name|nullptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// The ( starting an argument list of a macro definition has just been read.
end_comment

begin_comment
comment|/// Lex the rest of the arguments and the closing ), updating \p MI with
end_comment

begin_comment
comment|/// what we learn and saving in \p LastTok the last token read.
end_comment

begin_comment
comment|/// Return true if an error occurs parsing the arg list.
end_comment

begin_function_decl
name|bool
name|ReadMacroDefinitionArgList
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|,
name|Token
modifier|&
name|LastTok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// We just read a \#if or related directive and decided that the
end_comment

begin_comment
comment|/// subsequent tokens are in the \#if'd out portion of the
end_comment

begin_comment
comment|/// file.  Lex the rest of the file, until we see an \#endif.  If \p
end_comment

begin_comment
comment|/// FoundNonSkipPortion is true, then we have already emitted code for part of
end_comment

begin_comment
comment|/// this \#if directive, so \#else/\#elif blocks should never be entered. If
end_comment

begin_comment
comment|/// \p FoundElse is false, then \#else directives are ok, if not, then we have
end_comment

begin_comment
comment|/// already seen one so a \#else directive is a duplicate.  When this returns,
end_comment

begin_comment
comment|/// the caller can lex the first valid token.
end_comment

begin_function_decl
name|void
name|SkipExcludedConditionalBlock
parameter_list|(
name|SourceLocation
name|IfTokenLoc
parameter_list|,
name|bool
name|FoundNonSkipPortion
parameter_list|,
name|bool
name|FoundElse
parameter_list|,
name|SourceLocation
name|ElseLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief A fast PTH version of SkipExcludedConditionalBlock.
end_comment

begin_function_decl
name|void
name|PTHSkipExcludedConditionalBlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Evaluate an integer constant expression that may occur after a
end_comment

begin_comment
comment|/// \#if or \#elif directive and return it as a bool.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If the expression is equivalent to "!defined(X)" return X in IfNDefMacro.
end_comment

begin_function_decl
name|bool
name|EvaluateDirectiveExpression
parameter_list|(
name|IdentifierInfo
modifier|*
modifier|&
name|IfNDefMacro
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Install the standard preprocessor pragmas:
end_comment

begin_comment
comment|/// \#pragma GCC poison/system_header/dependency and \#pragma once.
end_comment

begin_function_decl
name|void
name|RegisterBuiltinPragmas
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Register builtin macros such as __LINE__ with the identifier table.
end_comment

begin_function_decl
name|void
name|RegisterBuiltinMacros
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// If an identifier token is read that is to be expanded as a macro, handle
end_comment

begin_comment
comment|/// it and return the next token as 'Tok'.  If we lexed a token, return true;
end_comment

begin_comment
comment|/// otherwise the caller should lex again.
end_comment

begin_function_decl
name|bool
name|HandleMacroExpandedIdentifier
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
specifier|const
name|MacroDefinition
modifier|&
name|MD
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Cache macro expanded tokens for TokenLexers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// Works like a stack; a TokenLexer adds the macro expanded tokens that is
end_comment

begin_comment
comment|/// going to lex in the cache and when it finishes the tokens are removed
end_comment

begin_comment
comment|/// from the end of the cache.
end_comment

begin_decl_stmt
name|Token
modifier|*
name|cacheMacroExpandedTokens
argument_list|(
name|TokenLexer
operator|*
name|tokLexer
argument_list|,
name|ArrayRef
operator|<
name|Token
operator|>
name|tokens
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|removeCachedMacroExpandedTokensOfLastLexer
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|friend
name|void
name|TokenLexer
operator|::
name|ExpandFunctionArguments
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Determine whether the next preprocessor token to be
end_comment

begin_comment
comment|/// lexed is a '('.  If so, consume the token and return true, if not, this
end_comment

begin_comment
comment|/// method should have no observable side-effect on the lexed tokens.
end_comment

begin_function_decl
name|bool
name|isNextPPTokenLParen
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// After reading "MACRO(", this method is invoked to read all of the formal
end_comment

begin_comment
comment|/// arguments specified for the macro invocation.  Returns null on error.
end_comment

begin_function_decl
name|MacroArgs
modifier|*
name|ReadFunctionLikeMacroArgs
parameter_list|(
name|Token
modifier|&
name|MacroName
parameter_list|,
name|MacroInfo
modifier|*
name|MI
parameter_list|,
name|SourceLocation
modifier|&
name|ExpansionEnd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If an identifier token is read that is to be expanded
end_comment

begin_comment
comment|/// as a builtin macro, handle it and return the next token as 'Tok'.
end_comment

begin_function_decl
name|void
name|ExpandBuiltinMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read a \c _Pragma directive, slice it up, process it, then
end_comment

begin_comment
comment|/// return the first token after the directive.
end_comment

begin_comment
comment|/// This assumes that the \c _Pragma token has just been read into \p Tok.
end_comment

begin_function_decl
name|void
name|Handle_Pragma
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Like Handle_Pragma except the pragma text is not enclosed within
end_comment

begin_comment
comment|/// a string literal.
end_comment

begin_function_decl
name|void
name|HandleMicrosoft__pragma
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add a lexer to the top of the include stack and
end_comment

begin_comment
comment|/// start lexing tokens from it instead of the current buffer.
end_comment

begin_function_decl
name|void
name|EnterSourceFileWithLexer
parameter_list|(
name|Lexer
modifier|*
name|TheLexer
parameter_list|,
specifier|const
name|DirectoryLookup
modifier|*
name|Dir
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add a lexer to the top of the include stack and
end_comment

begin_comment
comment|/// start getting tokens from it using the PTH cache.
end_comment

begin_function_decl
name|void
name|EnterSourceFileWithPTH
parameter_list|(
name|PTHLexer
modifier|*
name|PL
parameter_list|,
specifier|const
name|DirectoryLookup
modifier|*
name|Dir
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Set the FileID for the preprocessor predefines.
end_comment

begin_function
name|void
name|setPredefinesFileID
parameter_list|(
name|FileID
name|FID
parameter_list|)
block|{
name|assert
argument_list|(
name|PredefinesFileID
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"PredefinesFileID already set!"
argument_list|)
expr_stmt|;
name|PredefinesFileID
operator|=
name|FID
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns true if we are lexing from a file and not a
end_comment

begin_comment
comment|/// pragma or a macro.
end_comment

begin_function
specifier|static
name|bool
name|IsFileLexer
parameter_list|(
specifier|const
name|Lexer
modifier|*
name|L
parameter_list|,
specifier|const
name|PreprocessorLexer
modifier|*
name|P
parameter_list|)
block|{
return|return
name|L
condition|?
operator|!
name|L
operator|->
name|isPragmaLexer
argument_list|()
else|:
name|P
operator|!=
name|nullptr
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|IsFileLexer
parameter_list|(
specifier|const
name|IncludeStackInfo
modifier|&
name|I
parameter_list|)
block|{
return|return
name|IsFileLexer
argument_list|(
name|I
operator|.
name|TheLexer
operator|.
name|get
argument_list|()
argument_list|,
name|I
operator|.
name|ThePPLexer
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|IsFileLexer
argument_list|()
specifier|const
block|{
return|return
name|IsFileLexer
argument_list|(
name|CurLexer
operator|.
name|get
argument_list|()
argument_list|,
name|CurPPLexer
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Caching stuff.
end_comment

begin_function_decl
name|void
name|CachingLex
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|InCachingLexMode
argument_list|()
specifier|const
block|{
comment|// If the Lexer pointers are 0 and IncludeMacroStack is empty, it means
comment|// that we are past EOF, not that we are in CachingLex mode.
return|return
operator|!
name|CurPPLexer
operator|&&
operator|!
name|CurTokenLexer
operator|&&
operator|!
name|CurPTHLexer
operator|&&
operator|!
name|IncludeMacroStack
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|EnterCachingLexMode
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|ExitCachingLexMode
parameter_list|()
block|{
if|if
condition|(
name|InCachingLexMode
argument_list|()
condition|)
name|RemoveTopOfLexerStack
argument_list|()
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|const
name|Token
modifier|&
name|PeekAhead
parameter_list|(
name|unsigned
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AnnotatePreviousCachedTokens
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// Handle*Directive - implement the various preprocessor directives.  These
end_comment

begin_comment
comment|/// should side-effect the current preprocessor object so that the next call
end_comment

begin_comment
comment|/// to Lex() will return the appropriate token next.
end_comment

begin_function_decl
name|void
name|HandleLineDirective
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleDigitDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleUserDiagnosticDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
name|bool
name|isWarning
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleIdentSCCSDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleMacroPublicDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleMacroPrivateDirective
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// File inclusion.
end_comment

begin_function_decl
name|void
name|HandleIncludeDirective
parameter_list|(
name|SourceLocation
name|HashLoc
parameter_list|,
name|Token
modifier|&
name|Tok
parameter_list|,
specifier|const
name|DirectoryLookup
modifier|*
name|LookupFrom
init|=
name|nullptr
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|LookupFromFile
init|=
name|nullptr
parameter_list|,
name|bool
name|isImport
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleIncludeNextDirective
parameter_list|(
name|SourceLocation
name|HashLoc
parameter_list|,
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleIncludeMacrosDirective
parameter_list|(
name|SourceLocation
name|HashLoc
parameter_list|,
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleImportDirective
parameter_list|(
name|SourceLocation
name|HashLoc
parameter_list|,
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleMicrosoftImportDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|// Module inclusion testing.
end_comment

begin_comment
comment|/// \brief Find the module that owns the source or header file that
end_comment

begin_comment
comment|/// \p Loc points to. If the location is in a file that was included
end_comment

begin_comment
comment|/// into a module, or is outside any module, returns nullptr.
end_comment

begin_function_decl
name|Module
modifier|*
name|getModuleForLocation
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief We want to produce a diagnostic at location IncLoc concerning a
end_comment

begin_comment
comment|/// missing module import.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IncLoc The location at which the missing import was detected.
end_comment

begin_comment
comment|/// \param M The desired module.
end_comment

begin_comment
comment|/// \param MLoc A location within the desired module at which some desired
end_comment

begin_comment
comment|///        effect occurred (eg, where a desired entity was declared).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return A file that can be #included to import a module containing MLoc.
end_comment

begin_comment
comment|///         Null if no such file could be determined or if a #include is not
end_comment

begin_comment
comment|///         appropriate.
end_comment

begin_function_decl
specifier|const
name|FileEntry
modifier|*
name|getModuleHeaderToIncludeForDiagnostics
parameter_list|(
name|SourceLocation
name|IncLoc
parameter_list|,
name|Module
modifier|*
name|M
parameter_list|,
name|SourceLocation
name|MLoc
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|bool
name|isRecordingPreamble
argument_list|()
specifier|const
block|{
return|return
name|PreambleConditionalStack
operator|.
name|isRecording
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasRecordedPreamble
argument_list|()
specifier|const
block|{
return|return
name|PreambleConditionalStack
operator|.
name|hasRecordedPreamble
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ArrayRef
operator|<
name|PPConditionalInfo
operator|>
name|getPreambleConditionalStack
argument_list|()
specifier|const
block|{
return|return
name|PreambleConditionalStack
operator|.
name|getStack
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setRecordedPreambleConditionalStack
argument_list|(
name|ArrayRef
operator|<
name|PPConditionalInfo
operator|>
name|s
argument_list|)
block|{
name|PreambleConditionalStack
operator|.
name|setStack
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setReplayablePreambleConditionalStack
argument_list|(
name|ArrayRef
operator|<
name|PPConditionalInfo
operator|>
name|s
argument_list|)
block|{
name|PreambleConditionalStack
operator|.
name|startReplaying
argument_list|()
expr_stmt|;
name|PreambleConditionalStack
operator|.
name|setStack
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Macro handling.
end_comment

begin_function_decl
name|void
name|HandleDefineDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
name|bool
name|ImmediatelyAfterTopLevelIfndef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleUndefDirective
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Conditional Inclusion.
end_comment

begin_function_decl
name|void
name|HandleIfdefDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
name|bool
name|isIfndef
parameter_list|,
name|bool
name|ReadAnyTokensBeforeDirective
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleIfDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
name|bool
name|ReadAnyTokensBeforeDirective
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleEndifDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleElseDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandleElifDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Pragmas.
end_comment

begin_function_decl
name|void
name|HandlePragmaDirective
parameter_list|(
name|SourceLocation
name|IntroducerLoc
parameter_list|,
name|PragmaIntroducerKind
name|Introducer
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_function_decl
name|void
name|HandlePragmaOnce
parameter_list|(
name|Token
modifier|&
name|OnceTok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandlePragmaMark
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandlePragmaPoison
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandlePragmaSystemHeader
parameter_list|(
name|Token
modifier|&
name|SysHeaderTok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandlePragmaDependency
parameter_list|(
name|Token
modifier|&
name|DependencyTok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandlePragmaPushMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandlePragmaPopMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HandlePragmaIncludeAlias
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|IdentifierInfo
modifier|*
name|ParsePragmaPushOrPopMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Return true and store the first token only if any CommentHandler
end_comment

begin_comment
comment|// has inserted some tokens and getCommentRetentionState() is false.
end_comment

begin_function_decl
name|bool
name|HandleComment
parameter_list|(
name|Token
modifier|&
name|Token
parameter_list|,
name|SourceRange
name|Comment
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief A macro is used, update information about macros that need unused
end_comment

begin_comment
comment|/// warnings.
end_comment

begin_function_decl
name|void
name|markMacroAsUsed
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// \brief Abstract base class that describes a handler that will receive
end_comment

begin_comment
comment|/// source ranges for each of the comments encountered in the source file.
end_comment

begin_decl_stmt
name|class
name|CommentHandler
block|{
name|public
label|:
name|virtual
operator|~
name|CommentHandler
argument_list|()
expr_stmt|;
comment|// The handler shall return true if it has pushed any tokens
comment|// to be read using e.g. EnterToken or EnterTokenStream.
name|virtual
name|bool
name|HandleComment
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|SourceRange
name|Comment
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Registry of pragma handlers added by plugins
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|Registry
operator|<
name|PragmaHandler
operator|>
name|PragmaHandlerRegistry
expr_stmt|;
end_typedef

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

