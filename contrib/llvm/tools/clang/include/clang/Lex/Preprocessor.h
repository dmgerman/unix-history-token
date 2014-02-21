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
comment|//
end_comment

begin_comment
comment|//  This file defines the Preprocessor interface.
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
file|"clang/Lex/PTHManager.h"
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
file|"llvm/ADT/OwningPtr.h"
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
file|"llvm/Support/Allocator.h"
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
literal|0
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
comment|/// Preprocessor - This object engages in a tight little dance with the lexer to
comment|/// efficiently preprocess tokens.  Lexers know only about tokens within a
comment|/// single source file, and don't know anything about preprocessor-level issues
comment|/// like the \#include stack, token expansion, etc.
comment|///
name|class
name|Preprocessor
range|:
name|public
name|RefCountedBase
operator|<
name|Preprocessor
operator|>
block|{
name|IntrusiveRefCntPtr
operator|<
name|PreprocessorOptions
operator|>
name|PPOpts
block|;
name|DiagnosticsEngine
operator|*
name|Diags
block|;
name|LangOptions
operator|&
name|LangOpts
block|;
specifier|const
name|TargetInfo
operator|*
name|Target
block|;
name|FileManager
operator|&
name|FileMgr
block|;
name|SourceManager
operator|&
name|SourceMgr
block|;
name|ScratchBuffer
operator|*
name|ScratchBuf
block|;
name|HeaderSearch
operator|&
name|HeaderInfo
block|;
name|ModuleLoader
operator|&
name|TheModuleLoader
block|;
comment|/// \brief External source of macros.
name|ExternalPreprocessorSource
operator|*
name|ExternalSource
block|;
comment|/// PTH - An optional PTHManager object used for getting tokens from
comment|///  a token cache rather than lexing the original source file.
name|OwningPtr
operator|<
name|PTHManager
operator|>
name|PTH
block|;
comment|/// BP - A BumpPtrAllocator object used to quickly allocate and release
comment|///  objects internal to the Preprocessor.
name|llvm
operator|::
name|BumpPtrAllocator
name|BP
block|;
comment|/// Identifiers for builtin macros and other builtins.
name|IdentifierInfo
operator|*
name|Ident__LINE__
block|,
operator|*
name|Ident__FILE__
block|;
comment|// __LINE__, __FILE__
name|IdentifierInfo
operator|*
name|Ident__DATE__
block|,
operator|*
name|Ident__TIME__
block|;
comment|// __DATE__, __TIME__
name|IdentifierInfo
operator|*
name|Ident__INCLUDE_LEVEL__
block|;
comment|// __INCLUDE_LEVEL__
name|IdentifierInfo
operator|*
name|Ident__BASE_FILE__
block|;
comment|// __BASE_FILE__
name|IdentifierInfo
operator|*
name|Ident__TIMESTAMP__
block|;
comment|// __TIMESTAMP__
name|IdentifierInfo
operator|*
name|Ident__COUNTER__
block|;
comment|// __COUNTER__
name|IdentifierInfo
operator|*
name|Ident_Pragma
block|,
operator|*
name|Ident__pragma
block|;
comment|// _Pragma, __pragma
name|IdentifierInfo
operator|*
name|Ident__VA_ARGS__
block|;
comment|// __VA_ARGS__
name|IdentifierInfo
operator|*
name|Ident__has_feature
block|;
comment|// __has_feature
name|IdentifierInfo
operator|*
name|Ident__has_extension
block|;
comment|// __has_extension
name|IdentifierInfo
operator|*
name|Ident__has_builtin
block|;
comment|// __has_builtin
name|IdentifierInfo
operator|*
name|Ident__has_attribute
block|;
comment|// __has_attribute
name|IdentifierInfo
operator|*
name|Ident__has_include
block|;
comment|// __has_include
name|IdentifierInfo
operator|*
name|Ident__has_include_next
block|;
comment|// __has_include_next
name|IdentifierInfo
operator|*
name|Ident__has_warning
block|;
comment|// __has_warning
name|IdentifierInfo
operator|*
name|Ident__building_module
block|;
comment|// __building_module
name|IdentifierInfo
operator|*
name|Ident__MODULE__
block|;
comment|// __MODULE__
name|SourceLocation
name|DATELoc
block|,
name|TIMELoc
block|;
name|unsigned
name|CounterValue
block|;
comment|// Next __COUNTER__ value.
block|enum
block|{
comment|/// MaxIncludeStackDepth - Maximum depth of \#includes.
name|MaxAllowedIncludeStackDepth
operator|=
literal|200
block|}
block|;
comment|// State that is set before the preprocessor begins.
name|bool
name|KeepComments
operator|:
literal|1
block|;
name|bool
name|KeepMacroComments
operator|:
literal|1
block|;
name|bool
name|SuppressIncludeNotFoundError
operator|:
literal|1
block|;
comment|// State that changes while the preprocessor runs:
name|bool
name|InMacroArgs
operator|:
literal|1
block|;
comment|// True if parsing fn macro invocation args.
comment|/// Whether the preprocessor owns the header search object.
name|bool
name|OwnsHeaderSearch
operator|:
literal|1
block|;
comment|/// DisableMacroExpansion - True if macro expansion is disabled.
name|bool
name|DisableMacroExpansion
operator|:
literal|1
block|;
comment|/// MacroExpansionInDirectivesOverride - Temporarily disables
comment|/// DisableMacroExpansion (i.e. enables expansion) when parsing preprocessor
comment|/// directives.
name|bool
name|MacroExpansionInDirectivesOverride
operator|:
literal|1
block|;
name|class
name|ResetMacroExpansionHelper
block|;
comment|/// \brief Whether we have already loaded macros from the external source.
name|mutable
name|bool
name|ReadMacrosFromExternalSource
operator|:
literal|1
block|;
comment|/// \brief True if pragmas are enabled.
name|bool
name|PragmasEnabled
operator|:
literal|1
block|;
comment|/// \brief True if the current build action is a preprocessing action.
name|bool
name|PreprocessedOutput
operator|:
literal|1
block|;
comment|/// \brief True if we are currently preprocessing a #if or #elif directive
name|bool
name|ParsingIfOrElifDirective
block|;
comment|/// \brief True if we are pre-expanding macro arguments.
name|bool
name|InMacroArgPreExpansion
block|;
comment|/// Identifiers - This is mapping/lookup information for all identifiers in
comment|/// the program, including program keywords.
name|mutable
name|IdentifierTable
name|Identifiers
block|;
comment|/// Selectors - This table contains all the selectors in the program. Unlike
comment|/// IdentifierTable above, this table *isn't* populated by the preprocessor.
comment|/// It is declared/expanded here because it's role/lifetime is
comment|/// conceptually similar the IdentifierTable. In addition, the current control
comment|/// flow (in clang::ParseAST()), make it convenient to put here.
comment|/// FIXME: Make sure the lifetime of Identifiers/Selectors *isn't* tied to
comment|/// the lifetime of the preprocessor.
name|SelectorTable
name|Selectors
block|;
comment|/// BuiltinInfo - Information about builtins.
name|Builtin
operator|::
name|Context
name|BuiltinInfo
block|;
comment|/// PragmaHandlers - This tracks all of the pragmas that the client registered
comment|/// with this preprocessor.
name|PragmaNamespace
operator|*
name|PragmaHandlers
block|;
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
block|;
comment|/// \brief True if we want to ignore EOF token and continue later on (thus
comment|/// avoid tearing the Lexer and etc. down).
name|bool
name|IncrementalProcessing
block|;
comment|/// \brief The code-completion handler.
name|CodeCompletionHandler
operator|*
name|CodeComplete
block|;
comment|/// \brief The file that we're performing code-completion for, if any.
specifier|const
name|FileEntry
operator|*
name|CodeCompletionFile
block|;
comment|/// \brief The offset in file for the code-completion point.
name|unsigned
name|CodeCompletionOffset
block|;
comment|/// \brief The location for the code-completion point. This gets instantiated
comment|/// when the CodeCompletionFile gets \#include'ed for preprocessing.
name|SourceLocation
name|CodeCompletionLoc
block|;
comment|/// \brief The start location for the file of the code-completion point.
comment|///
comment|/// This gets instantiated when the CodeCompletionFile gets \#include'ed
comment|/// for preprocessing.
name|SourceLocation
name|CodeCompletionFileLoc
block|;
comment|/// \brief The source location of the 'import' contextual keyword we just
comment|/// lexed, if any.
name|SourceLocation
name|ModuleImportLoc
block|;
comment|/// \brief The module import path that we're currently processing.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
block|,
name|SourceLocation
operator|>
block|,
literal|2
operator|>
name|ModuleImportPath
block|;
comment|/// \brief Whether the last token we lexed was an '@'.
name|bool
name|LastTokenWasAt
block|;
comment|/// \brief Whether the module import expectes an identifier next. Otherwise,
comment|/// it expects a '.' or ';'.
name|bool
name|ModuleImportExpectsIdentifier
block|;
comment|/// \brief The source location of the currently-active
comment|/// #pragma clang arc_cf_code_audited begin.
name|SourceLocation
name|PragmaARCCFCodeAuditedLoc
block|;
comment|/// \brief True if we hit the code-completion point.
name|bool
name|CodeCompletionReached
block|;
comment|/// \brief The number of bytes that we will initially skip when entering the
comment|/// main file, which is used when loading a precompiled preamble, along
comment|/// with a flag that indicates whether skipping this number of bytes will
comment|/// place the lexer at the start of a line.
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|bool
operator|>
name|SkipMainFilePreamble
block|;
comment|/// CurLexer - This is the current top of the stack that we're lexing from if
comment|/// not expanding a macro and we are lexing directly from source code.
comment|///  Only one of CurLexer, CurPTHLexer, or CurTokenLexer will be non-null.
name|OwningPtr
operator|<
name|Lexer
operator|>
name|CurLexer
block|;
comment|/// CurPTHLexer - This is the current top of stack that we're lexing from if
comment|///  not expanding from a macro and we are lexing from a PTH cache.
comment|///  Only one of CurLexer, CurPTHLexer, or CurTokenLexer will be non-null.
name|OwningPtr
operator|<
name|PTHLexer
operator|>
name|CurPTHLexer
block|;
comment|/// CurPPLexer - This is the current top of the stack what we're lexing from
comment|///  if not expanding a macro.  This is an alias for either CurLexer or
comment|///  CurPTHLexer.
name|PreprocessorLexer
operator|*
name|CurPPLexer
block|;
comment|/// CurLookup - The DirectoryLookup structure used to find the current
comment|/// FileEntry, if CurLexer is non-null and if applicable.  This allows us to
comment|/// implement \#include_next and find directory-specific properties.
specifier|const
name|DirectoryLookup
operator|*
name|CurDirLookup
block|;
comment|/// CurTokenLexer - This is the current macro we are expanding, if we are
comment|/// expanding a macro.  One of CurLexer and CurTokenLexer must be null.
name|OwningPtr
operator|<
name|TokenLexer
operator|>
name|CurTokenLexer
block|;
comment|/// \brief The kind of lexer we're currently working with.
block|enum
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
block|;
comment|/// IncludeMacroStack - This keeps track of the stack of files currently
comment|/// \#included, and macros currently being expanded from, not counting
comment|/// CurLexer/CurTokenLexer.
block|struct
name|IncludeStackInfo
block|{     enum
name|CurLexerKind
name|CurLexerKind
block|;
name|Lexer
operator|*
name|TheLexer
block|;
name|PTHLexer
operator|*
name|ThePTHLexer
block|;
name|PreprocessorLexer
operator|*
name|ThePPLexer
block|;
name|TokenLexer
operator|*
name|TheTokenLexer
block|;
specifier|const
name|DirectoryLookup
operator|*
name|TheDirLookup
block|;
name|IncludeStackInfo
argument_list|(
argument|enum CurLexerKind K
argument_list|,
argument|Lexer *L
argument_list|,
argument|PTHLexer* P
argument_list|,
argument|PreprocessorLexer* PPL
argument_list|,
argument|TokenLexer* TL
argument_list|,
argument|const DirectoryLookup *D
argument_list|)
operator|:
name|CurLexerKind
argument_list|(
name|K
argument_list|)
block|,
name|TheLexer
argument_list|(
name|L
argument_list|)
block|,
name|ThePTHLexer
argument_list|(
name|P
argument_list|)
block|,
name|ThePPLexer
argument_list|(
name|PPL
argument_list|)
block|,
name|TheTokenLexer
argument_list|(
name|TL
argument_list|)
block|,
name|TheDirLookup
argument_list|(
argument|D
argument_list|)
block|{}
block|}
block|;
name|std
operator|::
name|vector
operator|<
name|IncludeStackInfo
operator|>
name|IncludeMacroStack
block|;
comment|/// Callbacks - These are actions invoked when some preprocessor activity is
comment|/// encountered (e.g. a file is \#included, etc).
name|PPCallbacks
operator|*
name|Callbacks
block|;    struct
name|MacroExpandsInfo
block|{
name|Token
name|Tok
block|;
name|MacroDirective
operator|*
name|MD
block|;
name|SourceRange
name|Range
block|;
name|MacroExpandsInfo
argument_list|(
argument|Token Tok
argument_list|,
argument|MacroDirective *MD
argument_list|,
argument|SourceRange Range
argument_list|)
operator|:
name|Tok
argument_list|(
name|Tok
argument_list|)
block|,
name|MD
argument_list|(
name|MD
argument_list|)
block|,
name|Range
argument_list|(
argument|Range
argument_list|)
block|{ }
block|}
block|;
name|SmallVector
operator|<
name|MacroExpandsInfo
block|,
literal|2
operator|>
name|DelayedMacroExpandsCallbacks
block|;
comment|/// Macros - For each IdentifierInfo that was associated with a macro, we
comment|/// keep a mapping to the history of all macro definitions and #undefs in
comment|/// the reverse order (the latest one is in the head of the list).
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|IdentifierInfo
operator|*
block|,
name|MacroDirective
operator|*
operator|>
name|Macros
block|;
name|friend
name|class
name|ASTReader
block|;
comment|/// \brief Macros that we want to warn because they are not used at the end
comment|/// of the translation unit; we store just their SourceLocations instead
comment|/// something like MacroInfo*. The benefit of this is that when we are
comment|/// deserializing from PCH, we don't need to deserialize identifier& macros
comment|/// just so that we can report that they are unused, we just warn using
comment|/// the SourceLocations of this set (that will be filled by the ASTReader).
comment|/// We are using SmallPtrSet instead of a vector for faster removal.
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
name|WarnUnusedMacroLocsTy
name|WarnUnusedMacroLocs
decl_stmt|;
comment|/// MacroArgCache - This is a "freelist" of MacroArg objects that can be
comment|/// reused for quick allocation.
name|MacroArgs
modifier|*
name|MacroArgCache
decl_stmt|;
name|friend
name|class
name|MacroArgs
decl_stmt|;
comment|/// PragmaPushMacroInfo - For each IdentifierInfo used in a #pragma
comment|/// push_macro directive, we keep a MacroInfo stack used to restore
comment|/// previous macro value.
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
comment|// Various statistics we track for performance analysis.
name|unsigned
name|NumDirectives
decl_stmt|,
name|NumIncluded
decl_stmt|,
name|NumDefined
decl_stmt|,
name|NumUndefined
decl_stmt|,
name|NumPragma
decl_stmt|;
name|unsigned
name|NumIf
decl_stmt|,
name|NumElse
decl_stmt|,
name|NumEndif
decl_stmt|;
name|unsigned
name|NumEnteredSourceFiles
decl_stmt|,
name|MaxIncludeStackDepth
decl_stmt|;
name|unsigned
name|NumMacroExpanded
decl_stmt|,
name|NumFnMacroExpanded
decl_stmt|,
name|NumBuiltinMacroExpanded
decl_stmt|;
name|unsigned
name|NumFastMacroExpanded
decl_stmt|,
name|NumTokenPaste
decl_stmt|,
name|NumFastTokenPaste
decl_stmt|;
name|unsigned
name|NumSkipped
decl_stmt|;
comment|/// Predefines - This string is the predefined macros that preprocessor
comment|/// should use from the command line etc.
name|std
operator|::
name|string
name|Predefines
expr_stmt|;
comment|/// \brief The file ID for the preprocessor predefines.
name|FileID
name|PredefinesFileID
decl_stmt|;
comment|/// TokenLexerCache - Cache macro expanders to reduce malloc traffic.
enum|enum
block|{
name|TokenLexerCacheSize
init|=
literal|8
block|}
enum|;
name|unsigned
name|NumCachedTokenLexers
decl_stmt|;
name|TokenLexer
modifier|*
name|TokenLexerCache
index|[
name|TokenLexerCacheSize
index|]
decl_stmt|;
comment|/// \brief Keeps macro expanded tokens for TokenLexers.
comment|//
comment|/// Works like a stack; a TokenLexer adds the macro expanded tokens that is
comment|/// going to lex in the cache and when it finishes the tokens are removed
comment|/// from the end of the cache.
name|SmallVector
operator|<
name|Token
operator|,
literal|16
operator|>
name|MacroExpandedTokens
expr_stmt|;
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
comment|/// \brief A record of the macro definitions and expansions that
comment|/// occurred during preprocessing.
comment|///
comment|/// This is an optional side structure that can be enabled with
comment|/// \c createPreprocessingRecord() prior to preprocessing.
name|PreprocessingRecord
modifier|*
name|Record
decl_stmt|;
name|private
label|:
comment|// Cached tokens state.
typedef|typedef
name|SmallVector
operator|<
name|Token
operator|,
literal|1
operator|>
name|CachedTokensTy
expr_stmt|;
comment|/// CachedTokens - Cached tokens are stored here when we do backtracking or
comment|/// lookahead. They are "lexed" by the CachingLex() method.
name|CachedTokensTy
name|CachedTokens
decl_stmt|;
comment|/// CachedLexPos - The position of the cached token that CachingLex() should
comment|/// "lex" next. If it points beyond the CachedTokens vector, it means that
comment|/// a normal Lex() should be invoked.
name|CachedTokensTy
operator|::
name|size_type
name|CachedLexPos
expr_stmt|;
comment|/// BacktrackPositions - Stack of backtrack positions, allowing nested
comment|/// backtracks. The EnableBacktrackAtThisPos() method pushes a position to
comment|/// indicate where CachedLexPos should be set when the BackTrack() method is
comment|/// invoked (at which point the last position is popped).
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
name|MacroInfoChain
modifier|*
name|Prev
decl_stmt|;
block|}
struct|;
comment|/// MacroInfos are managed as a chain for easy disposal.  This is the head
comment|/// of that list.
name|MacroInfoChain
modifier|*
name|MIChainHead
decl_stmt|;
comment|/// MICache - A "freelist" of MacroInfo objects that can be reused for quick
comment|/// allocation.
name|MacroInfoChain
modifier|*
name|MICache
decl_stmt|;
struct|struct
name|DeserializedMacroInfoChain
block|{
name|MacroInfo
name|MI
decl_stmt|;
name|unsigned
name|OwningModuleID
decl_stmt|;
comment|// MUST be immediately after the MacroInfo object
comment|// so it can be accessed by MacroInfo::getOwningModuleID().
name|DeserializedMacroInfoChain
modifier|*
name|Next
decl_stmt|;
block|}
struct|;
name|DeserializedMacroInfoChain
modifier|*
name|DeserialMIChainHead
decl_stmt|;
name|public
label|:
name|Preprocessor
argument_list|(
argument|IntrusiveRefCntPtr<PreprocessorOptions> PPOpts
argument_list|,
argument|DiagnosticsEngine&diags
argument_list|,
argument|LangOptions&opts
argument_list|,
argument|const TargetInfo *target
argument_list|,
argument|SourceManager&SM
argument_list|,
argument|HeaderSearch&Headers
argument_list|,
argument|ModuleLoader&TheModuleLoader
argument_list|,
argument|IdentifierInfoLookup *IILookup =
literal|0
argument_list|,
argument|bool OwnsHeaderSearch = false
argument_list|,
argument|bool DelayInitialization = false
argument_list|,
argument|bool IncrProcessing = false
argument_list|)
empty_stmt|;
operator|~
name|Preprocessor
argument_list|()
expr_stmt|;
comment|/// \brief Initialize the preprocessor, if the constructor did not already
comment|/// perform the initialization.
comment|///
comment|/// \param Target Information about the target.
name|void
name|Initialize
parameter_list|(
specifier|const
name|TargetInfo
modifier|&
name|Target
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the preprocessor options used to initialize this
comment|/// preprocessor.
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
name|IdentifierTable
modifier|&
name|getIdentifierTable
parameter_list|()
block|{
return|return
name|Identifiers
return|;
block|}
name|SelectorTable
modifier|&
name|getSelectorTable
parameter_list|()
block|{
return|return
name|Selectors
return|;
block|}
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
name|void
name|setPTHManager
parameter_list|(
name|PTHManager
modifier|*
name|pm
parameter_list|)
function_decl|;
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
comment|/// \brief Retrieve the module loader associated with this preprocessor.
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
comment|/// \brief True if we are currently preprocessing a #if or #elif directive
name|bool
name|isParsingIfOrElifDirective
argument_list|()
specifier|const
block|{
return|return
name|ParsingIfOrElifDirective
return|;
block|}
comment|/// SetCommentRetentionState - Control whether or not the preprocessor retains
comment|/// comments in output.
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
name|bool
name|getCommentRetentionState
argument_list|()
specifier|const
block|{
return|return
name|KeepComments
return|;
block|}
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
name|bool
name|getPragmasEnabled
argument_list|()
specifier|const
block|{
return|return
name|PragmasEnabled
return|;
block|}
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
name|bool
name|GetSuppressIncludeNotFoundError
parameter_list|()
block|{
return|return
name|SuppressIncludeNotFoundError
return|;
block|}
comment|/// Sets whether the preprocessor is responsible for producing output or if
comment|/// it is producing tokens to be consumed by Parse and Sema.
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
comment|/// Returns true if the preprocessor is responsible for generating output,
comment|/// false if it is producing tokens to be consumed by Parse and Sema.
name|bool
name|isPreprocessedOutput
argument_list|()
specifier|const
block|{
return|return
name|PreprocessedOutput
return|;
block|}
comment|/// isCurrentLexer - Return true if we are lexing directly from the specified
comment|/// lexer.
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
comment|/// getCurrentLexer - Return the current lexer being lexed from.  Note
comment|/// that this ignores any potentially active macro expansions and _Pragma
comment|/// expansions going on at the time.
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
comment|/// getCurrentFileLexer - Return the current file lexer being lexed from.
comment|/// Note that this ignores any potentially active macro expansions and _Pragma
comment|/// expansions going on at the time.
name|PreprocessorLexer
operator|*
name|getCurrentFileLexer
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the file ID for the preprocessor predefines.
name|FileID
name|getPredefinesFileID
argument_list|()
specifier|const
block|{
return|return
name|PredefinesFileID
return|;
block|}
comment|/// getPPCallbacks/addPPCallbacks - Accessors for preprocessor callbacks.
comment|/// Note that this class takes ownership of any PPCallbacks object given to
comment|/// it.
name|PPCallbacks
operator|*
name|getPPCallbacks
argument_list|()
specifier|const
block|{
return|return
name|Callbacks
return|;
block|}
name|void
name|addPPCallbacks
parameter_list|(
name|PPCallbacks
modifier|*
name|C
parameter_list|)
block|{
if|if
condition|(
name|Callbacks
condition|)
name|C
operator|=
name|new
name|PPChainedCallbacks
argument_list|(
name|C
argument_list|,
name|Callbacks
argument_list|)
expr_stmt|;
name|Callbacks
operator|=
name|C
expr_stmt|;
block|}
comment|/// \brief Given an identifier, return its latest MacroDirective if it is
comment|// \#defined or null if it isn't \#define'd.
name|MacroDirective
modifier|*
name|getMacroDirective
argument_list|(
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
literal|0
return|;
name|MacroDirective
modifier|*
name|MD
init|=
name|getMacroDirectiveHistory
argument_list|(
name|II
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|MD
operator|->
name|isDefined
argument_list|()
operator|&&
literal|"Macro is undefined!"
argument_list|)
expr_stmt|;
return|return
name|MD
return|;
block|}
specifier|const
name|MacroInfo
modifier|*
name|getMacroInfo
argument_list|(
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
name|MacroInfo
modifier|*
name|getMacroInfo
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
if|if
condition|(
name|MacroDirective
modifier|*
name|MD
init|=
name|getMacroDirective
argument_list|(
name|II
argument_list|)
condition|)
return|return
name|MD
operator|->
name|getMacroInfo
argument_list|()
return|;
return|return
literal|0
return|;
block|}
comment|/// \brief Given an identifier, return the (probably #undef'd) MacroInfo
comment|/// representing the most recent macro definition. One can iterate over all
comment|/// previous macro definitions from it. This method should only be called for
comment|/// identifiers that hadMacroDefinition().
name|MacroDirective
modifier|*
name|getMacroDirectiveHistory
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Add a directive to the macro directive history for this identifier.
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
parameter_list|,
name|bool
name|isImported
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
argument_list|,
name|isImported
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
argument_list|,
name|false
argument_list|)
return|;
block|}
comment|/// \brief Set a MacroDirective that was loaded from a PCH file.
name|void
name|setLoadedMacroDirective
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
comment|/// macro_iterator/macro_begin/macro_end - This allows you to walk the macro
comment|/// history table. Currently defined macros have
comment|/// IdentifierInfo::hasMacroDefinition() set and an empty
comment|/// MacroInfo::getUndefLoc() at the head of the list.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|,
name|MacroDirective
operator|*
operator|>
operator|::
name|const_iterator
name|macro_iterator
expr_stmt|;
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
comment|/// \brief Return the name of the macro defined before \p Loc that has
comment|/// spelling \p Tokens.  If there are multiple macros with same spelling,
comment|/// return the last one defined.
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
comment|/// setPredefines - Set the predefines for this Preprocessor.  These
comment|/// predefines are automatically injected when parsing the main file.
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
name|void
name|setPredefines
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|P
argument_list|)
block|{
name|Predefines
operator|=
name|P
expr_stmt|;
block|}
comment|/// Return information about the specified preprocessor
comment|/// identifier token.
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
comment|/// AddPragmaHandler - Add the specified pragma handler to the preprocessor.
comment|/// If 'Namespace' is non-null, then it is a token required to exist on the
comment|/// pragma line before the pragma string starts, e.g. "STDC" or "GCC".
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
comment|/// RemovePragmaHandler - Remove the specific pragma handler from
comment|/// the preprocessor. If \p Namespace is non-null, then it should
comment|/// be the namespace that \p Handler was added to. It is an error
comment|/// to remove a handler that has not been registered.
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
comment|/// \brief Add the specified comment handler to the preprocessor.
name|void
name|addCommentHandler
parameter_list|(
name|CommentHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
comment|/// \brief Remove the specified comment handler.
comment|///
comment|/// It is an error to remove a handler that has not been registered.
name|void
name|removeCommentHandler
parameter_list|(
name|CommentHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
comment|/// \brief Set the code completion handler to the given object.
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
comment|/// \brief Retrieve the current code-completion handler.
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
comment|/// \brief Clear out the code completion handler.
name|void
name|clearCodeCompletionHandler
parameter_list|()
block|{
name|CodeComplete
operator|=
literal|0
expr_stmt|;
block|}
comment|/// \brief Hook used by the lexer to invoke the "natural language" code
comment|/// completion point.
name|void
name|CodeCompleteNaturalLanguage
parameter_list|()
function_decl|;
comment|/// \brief Retrieve the preprocessing record, or NULL if there is no
comment|/// preprocessing record.
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
comment|/// \brief Create a new preprocessing record, which will keep track of
comment|/// all macro expansions, macro definitions, etc.
name|void
name|createPreprocessingRecord
parameter_list|()
function_decl|;
comment|/// EnterMainSourceFile - Enter the specified FileID as the main source file,
comment|/// which implicitly adds the builtin defines etc.
name|void
name|EnterMainSourceFile
parameter_list|()
function_decl|;
comment|/// EndSourceFile - Inform the preprocessor callbacks that processing is
comment|/// complete.
name|void
name|EndSourceFile
parameter_list|()
function_decl|;
comment|/// EnterSourceFile - Add a source file to the top of the include stack and
comment|/// start lexing tokens from it instead of the current buffer.  Emit an error
comment|/// and don't enter the file on error.
name|void
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
comment|/// EnterMacro - Add a Macro to the top of the include stack and start lexing
comment|/// tokens from it instead of the current buffer.  Args specifies the
comment|/// tokens input to a function-like macro.
comment|///
comment|/// ILEnd specifies the location of the ')' for a function-like macro or the
comment|/// identifier for an object-like macro.
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
comment|/// EnterTokenStream - Add a "macro" context to the top of the include stack,
comment|/// which will cause the lexer to start returning the specified tokens.
comment|///
comment|/// If DisableMacroExpansion is true, tokens lexed from the token stream will
comment|/// not be subject to further macro expansion.  Otherwise, these tokens will
comment|/// be re-macro-expanded when/if expansion is enabled.
comment|///
comment|/// If OwnsTokens is false, this method assumes that the specified stream of
comment|/// tokens has a permanent owner somewhere, so they do not need to be copied.
comment|/// If it is true, it assumes the array of tokens is allocated with new[] and
comment|/// must be freed.
comment|///
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
comment|/// RemoveTopOfLexerStack - Pop the current lexer/macro exp off the top of the
comment|/// lexer stack.  This should only be used in situations where the current
comment|/// state of the top-of-stack lexer is known.
name|void
name|RemoveTopOfLexerStack
parameter_list|()
function_decl|;
comment|/// EnableBacktrackAtThisPos - From the point that this method is called, and
comment|/// until CommitBacktrackedTokens() or Backtrack() is called, the Preprocessor
comment|/// keeps track of the lexed tokens so that a subsequent Backtrack() call will
comment|/// make the Preprocessor re-lex the same tokens.
comment|///
comment|/// Nested backtracks are allowed, meaning that EnableBacktrackAtThisPos can
comment|/// be called multiple times and CommitBacktrackedTokens/Backtrack calls will
comment|/// be combined with the EnableBacktrackAtThisPos calls in reverse order.
comment|///
comment|/// NOTE: *DO NOT* forget to call either CommitBacktrackedTokens or Backtrack
comment|/// at some point after EnableBacktrackAtThisPos. If you don't, caching of
comment|/// tokens will continue indefinitely.
comment|///
name|void
name|EnableBacktrackAtThisPos
parameter_list|()
function_decl|;
comment|/// CommitBacktrackedTokens - Disable the last EnableBacktrackAtThisPos call.
name|void
name|CommitBacktrackedTokens
parameter_list|()
function_decl|;
comment|/// Backtrack - Make Preprocessor re-lex the tokens that were lexed since
comment|/// EnableBacktrackAtThisPos() was previously called.
name|void
name|Backtrack
parameter_list|()
function_decl|;
comment|/// isBacktrackEnabled - True if EnableBacktrackAtThisPos() was called and
comment|/// caching of tokens is on.
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
comment|/// Lex - Lex the next token for this preprocessor.
name|void
name|Lex
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
name|void
name|LexAfterModuleImport
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
comment|/// \brief Lex a string literal, which may be the concatenation of multiple
comment|/// string literals and may even come from macro expansion.
comment|/// \returns true on success, false if a error diagnostic has been generated.
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
comment|/// \brief Complete the lexing of a string literal where the first token has
comment|/// already been lexed (see LexStringLiteral).
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
comment|/// LexNonComment - Lex a token.  If it's a comment, keep lexing until we get
comment|/// something not a comment.  This is useful in -E -C mode where comments
comment|/// would foul up preprocessor directive handling.
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
comment|/// LexUnexpandedToken - This is just like Lex, but this disables macro
comment|/// expansion of identifier tokens.
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
comment|/// LexUnexpandedNonComment - Like LexNonComment, but this disables macro
comment|/// expansion of identifier tokens.
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
comment|/// Disables macro expansion everywhere except for preprocessor directives.
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
comment|/// LookAhead - This peeks ahead N tokens and returns that token without
comment|/// consuming any tokens.  LookAhead(0) returns the next token that would be
comment|/// returned by Lex(), LookAhead(1) returns the token after it, etc.  This
comment|/// returns normal tokens after phase 5.  As such, it is equivalent to using
comment|/// 'Lex', not 'LexUnexpandedToken'.
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
comment|/// RevertCachedTokens - When backtracking is enabled and tokens are cached,
comment|/// this allows to revert a specific number of tokens.
comment|/// Note that the number of tokens being reverted should be up to the last
comment|/// backtrack position, not more.
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
comment|/// EnterToken - Enters a token in the token stream to be lexed next. If
comment|/// BackTrack() is called afterwards, the token will remain at the insertion
comment|/// point.
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
comment|/// AnnotateCachedTokens - We notify the Preprocessor that if it is caching
comment|/// tokens (because backtrack is enabled) it should replace the most recent
comment|/// cached tokens with the given annotation token. This function has no effect
comment|/// if backtracking is not enabled.
comment|///
comment|/// Note that the use of this function is just for optimization; so that the
comment|/// cached tokens doesn't get re-parsed and re-resolved after a backtrack is
comment|/// invoked.
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
comment|/// Get the location of the last cached token, suitable for setting the end
comment|/// location of an annotation token.
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
name|getLocation
argument_list|()
return|;
block|}
comment|/// \brief Replace the last token with an annotation token.
comment|///
comment|/// Like AnnotateCachedTokens(), this routine replaces an
comment|/// already-parsed (and resolved) token with an annotation
comment|/// token. However, this routine only replaces the last token with
comment|/// the annotation token; it does not affect any other cached
comment|/// tokens. This function has no effect if backtracking is not
comment|/// enabled.
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
comment|/// TypoCorrectToken - Update the current token to represent the provided
comment|/// identifier, in order to cache an action performed by typo correction.
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
comment|/// \brief Recompute the current lexer kind based on the CurLexer/CurPTHLexer/
comment|/// CurTokenLexer pointers.
name|void
name|recomputeCurLexerKind
parameter_list|()
function_decl|;
comment|/// \brief Returns true if incremental processing is enabled
name|bool
name|isIncrementalProcessingEnabled
argument_list|()
specifier|const
block|{
return|return
name|IncrementalProcessing
return|;
block|}
comment|/// \brief Enables the incremental processing
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
comment|/// \brief Specify the point at which code-completion will be performed.
comment|///
comment|/// \param File the file in which code completion should occur. If
comment|/// this file is included multiple times, code-completion will
comment|/// perform completion the first time it is included. If NULL, this
comment|/// function clears out the code-completion point.
comment|///
comment|/// \param Line the line at which code completion should occur
comment|/// (1-based).
comment|///
comment|/// \param Column the column at which code completion should occur
comment|/// (1-based).
comment|///
comment|/// \returns true if an error occurred, false otherwise.
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
comment|/// \brief Determine if we are performing code completion.
name|bool
name|isCodeCompletionEnabled
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionFile
operator|!=
literal|0
return|;
block|}
comment|/// \brief Returns the location of the code-completion point.
comment|/// Returns an invalid location if code-completion is not enabled or the file
comment|/// containing the code-completion point has not been lexed yet.
name|SourceLocation
name|getCodeCompletionLoc
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionLoc
return|;
block|}
comment|/// \brief Returns the start location of the file of code-completion point.
comment|/// Returns an invalid location if code-completion is not enabled or the file
comment|/// containing the code-completion point has not been lexed yet.
name|SourceLocation
name|getCodeCompletionFileLoc
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionFileLoc
return|;
block|}
comment|/// \brief Returns true if code-completion is enabled and we have hit the
comment|/// code-completion point.
name|bool
name|isCodeCompletionReached
argument_list|()
specifier|const
block|{
return|return
name|CodeCompletionReached
return|;
block|}
comment|/// \brief Note that we hit the code-completion point.
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
comment|/// \brief The location of the currently-active \#pragma clang
comment|/// arc_cf_code_audited begin.  Returns an invalid location if there
comment|/// is no such pragma active.
name|SourceLocation
name|getPragmaARCCFCodeAuditedLoc
argument_list|()
specifier|const
block|{
return|return
name|PragmaARCCFCodeAuditedLoc
return|;
block|}
comment|/// \brief Set the location of the currently-active \#pragma clang
comment|/// arc_cf_code_audited begin.  An invalid location ends the pragma.
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
comment|/// \brief Instruct the preprocessor to skip part of the main source file.
comment|///
comment|/// \param Bytes The number of bytes in the preamble to skip.
comment|///
comment|/// \param StartOfLine Whether skipping these bytes puts the lexer at the
comment|/// start of a line.
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
comment|/// Diag - Forwarding function for diagnostics.  This emits a diagnostic at
comment|/// the specified Token's location, translating the token's start
comment|/// position in the current buffer into a SourcePosition object for rendering.
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
comment|/// getSpelling() - Return the 'spelling' of the token at the given
comment|/// location; does not go up to the spelling location or down to the
comment|/// expansion location.
comment|///
comment|/// \param buffer A buffer which will be used only if the token requires
comment|///   "cleaning", e.g. if it contains trigraphs or escaped newlines
comment|/// \param invalid If non-null, will be set \c true if an error occurs.
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
literal|0
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
comment|/// getSpelling() - Return the 'spelling' of the Tok token.  The spelling of a
comment|/// token is the characters used to represent the token in the source file
comment|/// after trigraph expansion and escaped-newline folding.  In particular, this
comment|/// wants to get the true, uncanonicalized, spelling of things like digraphs
comment|/// UCNs, etc.
comment|///
comment|/// \param Invalid If non-null, will be set \c true if an error occurs.
name|std
operator|::
name|string
name|getSpelling
argument_list|(
argument|const Token&Tok
argument_list|,
argument|bool *Invalid =
literal|0
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
comment|/// getSpelling - This method is used to get the spelling of a token into a
comment|/// preallocated buffer, instead of as an std::string.  The caller is required
comment|/// to allocate enough space for the token, which is guaranteed to be at least
comment|/// Tok.getLength() bytes long.  The length of the actual result is returned.
comment|///
comment|/// Note that this method may do two possible things: it may either fill in
comment|/// the buffer specified with characters, or it may *change the input pointer*
comment|/// to point to a constant buffer with the data already in it (avoiding a
comment|/// copy).  The caller is not allowed to modify the returned buffer pointer
comment|/// if an internal buffer is returned.
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
literal|0
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
comment|/// getSpelling - This method is used to get the spelling of a token into a
comment|/// SmallVector. Note that the returned StringRef may not point to the
comment|/// supplied buffer if a copy can be avoided.
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Relex the token at the specified location.
comment|/// \returns true if there was a failure, false on success.
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
comment|/// getSpellingOfSingleCharacterNumericConstant - Tok is a numeric constant
comment|/// with length 1, return the character.
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
literal|0
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
comment|/// \brief Retrieve the name of the immediate macro expansion.
comment|///
comment|/// This routine starts from a source location, and finds the name of the macro
comment|/// responsible for its immediate expansion. It looks through any intervening
comment|/// macro argument expansions to compute this. It returns a StringRef which
comment|/// refers to the SourceManager-owned buffer of the source where that macro
comment|/// name is spelled. Thus, the result shouldn't out-live the SourceManager.
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
comment|/// CreateString - Plop the specified string into a scratch buffer and set the
comment|/// specified token's location and length to it.  If specified, the source
comment|/// location provides a location of the expansion point of the token.
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
comment|/// \brief Computes the source location just past the end of the
comment|/// token at this source location.
comment|///
comment|/// This routine can be used to produce a source location that
comment|/// points just past the end of the token referenced by \p Loc, and
comment|/// is generally used when a diagnostic needs to point just after a
comment|/// token where it expected something different that it received. If
comment|/// the returned source location would not be meaningful (e.g., if
comment|/// it points into a macro), this routine returns an invalid
comment|/// source location.
comment|///
comment|/// \param Offset an offset from the end of the token, where the source
comment|/// location should refer to. The default offset (0) produces a source
comment|/// location pointing just past the end of the token; an offset of 1 produces
comment|/// a source location pointing to the last character in the token, etc.
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
comment|/// \brief Returns true if the given MacroID location points at the first
comment|/// token of the macro expansion.
comment|///
comment|/// \param MacroBegin If non-null and function returns true, it is set to
comment|/// begin location of the macro.
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
literal|0
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
comment|/// \brief Returns true if the given MacroID location points at the last
comment|/// token of the macro expansion.
comment|///
comment|/// \param MacroEnd If non-null and function returns true, it is set to
comment|/// end location of the macro.
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
literal|0
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
comment|/// DumpToken - Print the token to stderr, used for debugging.
comment|///
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
name|void
name|DumpLocation
argument_list|(
name|SourceLocation
name|Loc
argument_list|)
decl|const
decl_stmt|;
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
comment|/// AdvanceToTokenCharacter - Given a location that specifies the start of a
comment|/// token, return a new location that specifies a character within the token.
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
comment|/// IncrementPasteCounter - Increment the counters for the number of token
comment|/// paste operations performed.  If fast was specified, this is a 'fast paste'
comment|/// case we handled.
comment|///
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
name|void
name|PrintStats
parameter_list|()
function_decl|;
name|size_t
name|getTotalMemory
argument_list|()
specifier|const
expr_stmt|;
comment|/// HandleMicrosoftCommentPaste - When the macro expander pastes together a
comment|/// comment (/##/) in microsoft mode, this method handles updating the current
comment|/// state, returning the token on the next source line.
name|void
name|HandleMicrosoftCommentPaste
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Preprocessor callback methods.  These are invoked by a lexer as various
comment|// directives and events are found.
comment|/// LookUpIdentifierInfo - Given a tok::raw_identifier token, look up the
comment|/// identifier information for the token and install it into the token,
comment|/// updating the token kind accordingly.
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
name|private
label|:
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
name|public
label|:
comment|// SetPoisonReason - Call this function to indicate the reason for
comment|// poisoning an identifier. If that identifier is accessed while
comment|// poisoned, then this reason will be used instead of the default
comment|// "poisoned" diagnostic.
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
comment|// HandlePoisonedIdentifier - Display reason for poisoned
comment|// identifier.
name|void
name|HandlePoisonedIdentifier
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
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
name|private
label|:
comment|/// Identifiers used for SEH handling in Borland. These are only
comment|/// allowed in particular circumstances
comment|// __except block
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
comment|// __except filter expression
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
comment|// __finally
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
name|public
label|:
name|void
name|PoisonSEHIdentifiers
parameter_list|(
name|bool
name|Poison
init|=
name|true
parameter_list|)
function_decl|;
comment|// Borland
comment|/// HandleIdentifier - This callback is invoked when the lexer reads an
comment|/// identifier and has filled in the tokens IdentifierInfo member.  This
comment|/// callback potentially macro expands it or turns it into a named token (like
comment|/// 'for').
comment|///
comment|/// \returns true if we actually computed a token, false if we need to
comment|/// lex again.
name|bool
name|HandleIdentifier
parameter_list|(
name|Token
modifier|&
name|Identifier
parameter_list|)
function_decl|;
comment|/// HandleEndOfFile - This callback is invoked when the lexer hits the end of
comment|/// the current file.  This either returns the EOF token and returns true, or
comment|/// pops a level off the include stack and returns false, at which point the
comment|/// client should call lex again.
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
comment|/// HandleEndOfTokenLexer - This callback is invoked when the current
comment|/// TokenLexer hits the end of its token stream.
name|bool
name|HandleEndOfTokenLexer
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
comment|/// HandleDirective - This callback is invoked when the lexer sees a # token
comment|/// at the start of a line.  This consumes the directive, modifies the
comment|/// lexer/preprocessor state, and advances the lexer(s) so that the next token
comment|/// read is the correct one.
name|void
name|HandleDirective
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
comment|/// CheckEndOfDirective - Ensure that the next token is a tok::eod token.  If
comment|/// not, emit a diagnostic and consume up until the eod.  If EnableMacros is
comment|/// true, then we consider macros that expand to zero tokens as being ok.
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
comment|/// DiscardUntilEndOfDirective - Read and discard all tokens remaining on the
comment|/// current line until the tok::eod token is found.
name|void
name|DiscardUntilEndOfDirective
parameter_list|()
function_decl|;
comment|/// SawDateOrTime - This returns true if the preprocessor has seen a use of
comment|/// __DATE__ or __TIME__ in the file so far.
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
name|unsigned
name|getCounterValue
argument_list|()
specifier|const
block|{
return|return
name|CounterValue
return|;
block|}
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
comment|/// \brief Retrieves the module that we're currently building, if any.
name|Module
modifier|*
name|getCurrentModule
parameter_list|()
function_decl|;
comment|/// \brief Allocate a new MacroInfo object with the provided SourceLocation.
name|MacroInfo
modifier|*
name|AllocateMacroInfo
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
function_decl|;
comment|/// \brief Allocate a new MacroInfo object loaded from an AST file.
name|MacroInfo
modifier|*
name|AllocateDeserializedMacroInfo
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|unsigned
name|SubModuleID
parameter_list|)
function_decl|;
comment|/// \brief Turn the specified lexer token into a fully checked and spelled
comment|/// filename, e.g. as an operand of \#include.
comment|///
comment|/// The caller is expected to provide a buffer that is large enough to hold
comment|/// the spelling of the filename, but is also expected to handle the case
comment|/// when this method decides to use a different buffer.
comment|///
comment|/// \returns true if the input filename was in<>'s or false if it was
comment|/// in ""'s.
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
comment|/// \brief Given a "foo" or \<foo> reference, look up the indicated file.
comment|///
comment|/// Returns null on failure.  \p isAngled indicates whether the file
comment|/// reference is for system \#include's or not (i.e. using<> instead of "").
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
name|SkipCache
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// GetCurLookup - The DirectoryLookup structure used to find the current
comment|/// FileEntry, if CurLexer is non-null and if applicable.  This allows us to
comment|/// implement \#include_next and find directory-specific properties.
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
comment|/// \brief Return true if we're in the top-level file, not in a \#include.
name|bool
name|isInPrimaryFile
argument_list|()
specifier|const
expr_stmt|;
comment|/// ConcatenateIncludeName - Handle cases where the \#include name is expanded
comment|/// from a macro as multiple tokens, which need to be glued together.  This
comment|/// occurs for code like:
comment|/// \code
comment|///    \#define FOO<x/y.h>
comment|///    \#include FOO
comment|/// \endcode
comment|/// because in this case, "<x/y.h>" is returned as 7 tokens, not one.
comment|///
comment|/// This code concatenates and consumes tokens up to the '>' token.  It
comment|/// returns false if the> was found, otherwise it returns true if it finds
comment|/// and consumes the EOD marker.
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
comment|/// LexOnOffSwitch - Lex an on-off-switch (C99 6.10.6p2) and verify that it is
comment|/// followed by EOD.  Return true if the token is not a valid on-off-switch.
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
name|private
label|:
name|void
name|PushIncludeMacroStack
parameter_list|()
block|{
name|IncludeMacroStack
operator|.
name|push_back
argument_list|(
name|IncludeStackInfo
argument_list|(
name|CurLexerKind
argument_list|,
name|CurLexer
operator|.
name|take
argument_list|()
argument_list|,
name|CurPTHLexer
operator|.
name|take
argument_list|()
argument_list|,
name|CurPPLexer
argument_list|,
name|CurTokenLexer
operator|.
name|take
argument_list|()
argument_list|,
name|CurDirLookup
argument_list|)
argument_list|)
expr_stmt|;
name|CurPPLexer
operator|=
literal|0
expr_stmt|;
block|}
name|void
name|PopIncludeMacroStack
parameter_list|()
block|{
name|CurLexer
operator|.
name|reset
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
operator|.
name|reset
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
operator|.
name|reset
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
name|void
name|PropagateLineStartLeadingSpaceInfo
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
comment|/// \brief Allocate a new MacroInfo object.
name|MacroInfo
modifier|*
name|AllocateMacroInfo
parameter_list|()
function_decl|;
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
parameter_list|,
name|bool
name|isImported
parameter_list|)
function_decl|;
name|UndefMacroDirective
modifier|*
name|AllocateUndefMacroDirective
parameter_list|(
name|SourceLocation
name|UndefLoc
parameter_list|)
function_decl|;
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
comment|/// \brief Release the specified MacroInfo for re-use.
comment|///
comment|/// This memory will  be reused for allocating new MacroInfo objects.
name|void
name|ReleaseMacroInfo
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// ReadMacroName - Lex and validate a macro name, which occurs after a
comment|/// \#define or \#undef.  This emits a diagnostic, sets the token kind to eod,
comment|/// and discards the rest of the macro line if the macro name is invalid.
name|void
name|ReadMacroName
parameter_list|(
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
name|char
name|isDefineUndef
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// ReadMacroDefinitionArgList - The ( starting an argument list of a macro
comment|/// definition has just been read.  Lex the rest of the arguments and the
comment|/// closing ), updating MI with what we learn and saving in LastTok the
comment|/// last token read.
comment|/// Return true if an error occurs parsing the arg list.
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
comment|/// We just read a \#if or related directive and decided that the
comment|/// subsequent tokens are in the \#if'd out portion of the
comment|/// file.  Lex the rest of the file, until we see an \#endif.  If \p
comment|/// FoundNonSkipPortion is true, then we have already emitted code for part of
comment|/// this \#if directive, so \#else/\#elif blocks should never be entered. If
comment|/// \p FoundElse is false, then \#else directives are ok, if not, then we have
comment|/// already seen one so a \#else directive is a duplicate.  When this returns,
comment|/// the caller can lex the first valid token.
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
comment|/// \brief A fast PTH version of SkipExcludedConditionalBlock.
name|void
name|PTHSkipExcludedConditionalBlock
parameter_list|()
function_decl|;
comment|/// EvaluateDirectiveExpression - Evaluate an integer constant expression that
comment|/// may occur after a #if or #elif directive and return it as a bool.  If the
comment|/// expression is equivalent to "!defined(X)" return X in IfNDefMacro.
name|bool
name|EvaluateDirectiveExpression
parameter_list|(
name|IdentifierInfo
modifier|*
modifier|&
name|IfNDefMacro
parameter_list|)
function_decl|;
comment|/// RegisterBuiltinPragmas - Install the standard preprocessor pragmas:
comment|/// \#pragma GCC poison/system_header/dependency and \#pragma once.
name|void
name|RegisterBuiltinPragmas
parameter_list|()
function_decl|;
comment|/// \brief Register builtin macros such as __LINE__ with the identifier table.
name|void
name|RegisterBuiltinMacros
parameter_list|()
function_decl|;
comment|/// HandleMacroExpandedIdentifier - If an identifier token is read that is to
comment|/// be expanded as a macro, handle it and return the next token as 'Tok'.  If
comment|/// we lexed a token, return true; otherwise the caller should lex again.
name|bool
name|HandleMacroExpandedIdentifier
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
comment|/// \brief Cache macro expanded tokens for TokenLexers.
comment|//
comment|/// Works like a stack; a TokenLexer adds the macro expanded tokens that is
comment|/// going to lex in the cache and when it finishes the tokens are removed
comment|/// from the end of the cache.
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
name|void
name|removeCachedMacroExpandedTokensOfLastLexer
parameter_list|()
function_decl|;
name|friend
name|void
name|TokenLexer
operator|::
name|ExpandFunctionArguments
argument_list|()
expr_stmt|;
comment|/// isNextPPTokenLParen - Determine whether the next preprocessor token to be
comment|/// lexed is a '('.  If so, consume the token and return true, if not, this
comment|/// method should have no observable side-effect on the lexed tokens.
name|bool
name|isNextPPTokenLParen
parameter_list|()
function_decl|;
comment|/// ReadFunctionLikeMacroArgs - After reading "MACRO(", this method is
comment|/// invoked to read all of the formal arguments specified for the macro
comment|/// invocation.  This returns null on error.
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
comment|/// ExpandBuiltinMacro - If an identifier token is read that is to be expanded
comment|/// as a builtin macro, handle it and return the next token as 'Tok'.
name|void
name|ExpandBuiltinMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|/// Handle_Pragma - Read a _Pragma directive, slice it up, process it, then
comment|/// return the first token after the directive.  The _Pragma token has just
comment|/// been read into 'Tok'.
name|void
name|Handle_Pragma
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|/// HandleMicrosoft__pragma - Like Handle_Pragma except the pragma text
comment|/// is not enclosed within a string literal.
name|void
name|HandleMicrosoft__pragma
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|/// EnterSourceFileWithLexer - Add a lexer to the top of the include stack and
comment|/// start lexing tokens from it instead of the current buffer.
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
comment|/// EnterSourceFileWithPTH - Add a lexer to the top of the include stack and
comment|/// start getting tokens from it using the PTH cache.
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
comment|/// \brief Set the file ID for the preprocessor predefines.
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
comment|/// IsFileLexer - Returns true if we are lexing from a file and not a
comment|///  pragma or a macro.
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
literal|0
return|;
block|}
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
argument_list|,
name|I
operator|.
name|ThePPLexer
argument_list|)
return|;
block|}
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
comment|//===--------------------------------------------------------------------===//
comment|// Caching stuff.
name|void
name|CachingLex
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
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
name|void
name|EnterCachingLexMode
parameter_list|()
function_decl|;
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
specifier|const
name|Token
modifier|&
name|PeekAhead
parameter_list|(
name|unsigned
name|N
parameter_list|)
function_decl|;
name|void
name|AnnotatePreviousCachedTokens
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|/// Handle*Directive - implement the various preprocessor directives.  These
comment|/// should side-effect the current preprocessor object so that the next call
comment|/// to Lex() will return the appropriate token next.
name|void
name|HandleLineDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandleDigitDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
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
name|void
name|HandleIdentSCCSDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandleMacroPublicDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandleMacroPrivateDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// File inclusion.
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
literal|0
parameter_list|,
name|bool
name|isImport
init|=
name|false
parameter_list|)
function_decl|;
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
name|void
name|HandleMicrosoftImportDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// Module inclusion testing.
comment|/// \brief Find the module for the source or header file that \p FilenameLoc
comment|/// points to.
name|Module
modifier|*
name|getModuleForLocation
parameter_list|(
name|SourceLocation
name|FilenameLoc
parameter_list|)
function_decl|;
comment|/// \brief Verify that a private header is included only from within its
comment|/// module.
name|bool
name|violatesPrivateInclude
argument_list|(
name|Module
operator|*
name|RequestingModule
argument_list|,
specifier|const
name|FileEntry
operator|*
name|IncFileEnt
argument_list|,
name|ModuleMap
operator|::
name|ModuleHeaderRole
name|Role
argument_list|,
name|Module
operator|*
name|RequestedModule
argument_list|)
decl_stmt|;
comment|/// \brief Verify that a module includes headers only from modules that it
comment|/// has declared that it uses.
name|bool
name|violatesUseDeclarations
parameter_list|(
name|Module
modifier|*
name|RequestingModule
parameter_list|,
name|Module
modifier|*
name|RequestedModule
parameter_list|)
function_decl|;
comment|/// \brief Verify that it is legal for the source file that \p FilenameLoc
comment|/// points to to include the file \p Filename.
comment|///
comment|/// Tries to reuse \p IncFileEnt.
name|void
name|verifyModuleInclude
parameter_list|(
name|SourceLocation
name|FilenameLoc
parameter_list|,
name|StringRef
name|Filename
parameter_list|,
specifier|const
name|FileEntry
modifier|*
name|IncFileEnt
parameter_list|)
function_decl|;
comment|// Macro handling.
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
name|void
name|HandleUndefDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// Conditional Inclusion.
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
name|void
name|HandleEndifDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandleElseDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandleElifDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// Pragmas.
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
name|public
label|:
name|void
name|HandlePragmaOnce
parameter_list|(
name|Token
modifier|&
name|OnceTok
parameter_list|)
function_decl|;
name|void
name|HandlePragmaMark
parameter_list|()
function_decl|;
name|void
name|HandlePragmaPoison
parameter_list|(
name|Token
modifier|&
name|PoisonTok
parameter_list|)
function_decl|;
name|void
name|HandlePragmaSystemHeader
parameter_list|(
name|Token
modifier|&
name|SysHeaderTok
parameter_list|)
function_decl|;
name|void
name|HandlePragmaDependency
parameter_list|(
name|Token
modifier|&
name|DependencyTok
parameter_list|)
function_decl|;
name|void
name|HandlePragmaPushMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandlePragmaPopMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandlePragmaIncludeAlias
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|IdentifierInfo
modifier|*
name|ParsePragmaPushOrPopMacro
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// Return true and store the first token only if any CommentHandler
comment|// has inserted some tokens and getCommentRetentionState() is false.
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
comment|/// \brief A macro is used, update information about macros that need unused
comment|/// warnings.
name|void
name|markMacroAsUsed
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

