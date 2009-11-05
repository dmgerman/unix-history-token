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
file|"clang/Lex/Lexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PTHLexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PPCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/TokenLexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PTHManager.h"
end_include

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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
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
name|clang
block|{
name|class
name|SourceManager
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
name|DirectoryLookup
decl_stmt|;
comment|/// Preprocessor - This object engages in a tight little dance with the lexer to
comment|/// efficiently preprocess tokens.  Lexers know only about tokens within a
comment|/// single source file, and don't know anything about preprocessor-level issues
comment|/// like the #include stack, token expansion, etc.
comment|///
name|class
name|Preprocessor
block|{
name|Diagnostic
modifier|*
name|Diags
decl_stmt|;
name|LangOptions
name|Features
decl_stmt|;
name|TargetInfo
modifier|&
name|Target
decl_stmt|;
name|FileManager
modifier|&
name|FileMgr
decl_stmt|;
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|ScratchBuffer
modifier|*
name|ScratchBuf
decl_stmt|;
name|HeaderSearch
modifier|&
name|HeaderInfo
decl_stmt|;
comment|/// PTH - An optional PTHManager object used for getting tokens from
comment|///  a token cache rather than lexing the original source file.
name|llvm
operator|::
name|OwningPtr
operator|<
name|PTHManager
operator|>
name|PTH
expr_stmt|;
comment|/// BP - A BumpPtrAllocator object used to quickly allocate and release
comment|///  objects internal to the Preprocessor.
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
name|Ident__VA_ARGS__
decl_stmt|;
comment|// _Pragma, __VA_ARGS__
name|IdentifierInfo
modifier|*
name|Ident__has_feature
decl_stmt|;
comment|// __has_feature
name|IdentifierInfo
modifier|*
name|Ident__has_builtin
decl_stmt|;
comment|// __has_builtin
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
comment|/// MaxIncludeStackDepth - Maximum depth of #includes.
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
comment|// State that changes while the preprocessor runs:
name|bool
name|DisableMacroExpansion
range|:
literal|1
decl_stmt|;
comment|// True if macro expansion is disabled.
name|bool
name|InMacroArgs
range|:
literal|1
decl_stmt|;
comment|// True if parsing fn macro invocation args.
comment|/// Identifiers - This is mapping/lookup information for all identifiers in
comment|/// the program, including program keywords.
name|mutable
name|IdentifierTable
name|Identifiers
decl_stmt|;
comment|/// Selectors - This table contains all the selectors in the program. Unlike
comment|/// IdentifierTable above, this table *isn't* populated by the preprocessor.
comment|/// It is declared/instantiated here because it's role/lifetime is
comment|/// conceptually similar the IdentifierTable. In addition, the current control
comment|/// flow (in clang::ParseAST()), make it convenient to put here.
comment|/// FIXME: Make sure the lifetime of Identifiers/Selectors *isn't* tied to
comment|/// the lifetime fo the preprocessor.
name|SelectorTable
name|Selectors
decl_stmt|;
comment|/// BuiltinInfo - Information about builtins.
name|Builtin
operator|::
name|Context
name|BuiltinInfo
expr_stmt|;
comment|/// PragmaHandlers - This tracks all of the pragmas that the client registered
comment|/// with this preprocessor.
name|PragmaNamespace
modifier|*
name|PragmaHandlers
decl_stmt|;
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
comment|/// CurLexer - This is the current top of the stack that we're lexing from if
comment|/// not expanding a macro and we are lexing directly from source code.
comment|///  Only one of CurLexer, CurPTHLexer, or CurTokenLexer will be non-null.
name|llvm
operator|::
name|OwningPtr
operator|<
name|Lexer
operator|>
name|CurLexer
expr_stmt|;
comment|/// CurPTHLexer - This is the current top of stack that we're lexing from if
comment|///  not expanding from a macro and we are lexing from a PTH cache.
comment|///  Only one of CurLexer, CurPTHLexer, or CurTokenLexer will be non-null.
name|llvm
operator|::
name|OwningPtr
operator|<
name|PTHLexer
operator|>
name|CurPTHLexer
expr_stmt|;
comment|/// CurPPLexer - This is the current top of the stack what we're lexing from
comment|///  if not expanding a macro.  This is an alias for either CurLexer or
comment|///  CurPTHLexer.
name|PreprocessorLexer
modifier|*
name|CurPPLexer
decl_stmt|;
comment|/// CurLookup - The DirectoryLookup structure used to find the current
comment|/// FileEntry, if CurLexer is non-null and if applicable.  This allows us to
comment|/// implement #include_next and find directory-specific properties.
specifier|const
name|DirectoryLookup
modifier|*
name|CurDirLookup
decl_stmt|;
comment|/// CurTokenLexer - This is the current macro we are expanding, if we are
comment|/// expanding a macro.  One of CurLexer and CurTokenLexer must be null.
name|llvm
operator|::
name|OwningPtr
operator|<
name|TokenLexer
operator|>
name|CurTokenLexer
expr_stmt|;
comment|/// IncludeMacroStack - This keeps track of the stack of files currently
comment|/// #included, and macros currently being expanded from, not counting
comment|/// CurLexer/CurTokenLexer.
struct|struct
name|IncludeStackInfo
block|{
name|Lexer
modifier|*
name|TheLexer
decl_stmt|;
name|PTHLexer
modifier|*
name|ThePTHLexer
decl_stmt|;
name|PreprocessorLexer
modifier|*
name|ThePPLexer
decl_stmt|;
name|TokenLexer
modifier|*
name|TheTokenLexer
decl_stmt|;
specifier|const
name|DirectoryLookup
modifier|*
name|TheDirLookup
decl_stmt|;
name|IncludeStackInfo
argument_list|(
name|Lexer
operator|*
name|L
argument_list|,
name|PTHLexer
operator|*
name|P
argument_list|,
name|PreprocessorLexer
operator|*
name|PPL
argument_list|,
name|TokenLexer
operator|*
name|TL
argument_list|,
specifier|const
name|DirectoryLookup
operator|*
name|D
argument_list|)
operator|:
name|TheLexer
argument_list|(
name|L
argument_list|)
operator|,
name|ThePTHLexer
argument_list|(
name|P
argument_list|)
operator|,
name|ThePPLexer
argument_list|(
name|PPL
argument_list|)
operator|,
name|TheTokenLexer
argument_list|(
name|TL
argument_list|)
operator|,
name|TheDirLookup
argument_list|(
argument|D
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
comment|/// Callbacks - These are actions invoked when some preprocessor activity is
comment|/// encountered (e.g. a file is #included, etc).
name|PPCallbacks
modifier|*
name|Callbacks
decl_stmt|;
comment|/// Macros - For each IdentifierInfo with 'HasMacro' set, we keep a mapping
comment|/// to the actual definition of the macro.
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|MacroInfo
operator|*
operator|>
name|Macros
expr_stmt|;
comment|/// MICache - A "freelist" of MacroInfo objects that can be reused for quick
comment|///  allocation.
name|std
operator|::
name|vector
operator|<
name|MacroInfo
operator|*
operator|>
name|MICache
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
name|private
label|:
comment|// Cached tokens state.
typedef|typedef
name|llvm
operator|::
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
name|public
label|:
name|Preprocessor
argument_list|(
name|Diagnostic
operator|&
name|diags
argument_list|,
specifier|const
name|LangOptions
operator|&
name|opts
argument_list|,
name|TargetInfo
operator|&
name|target
argument_list|,
name|SourceManager
operator|&
name|SM
argument_list|,
name|HeaderSearch
operator|&
name|Headers
argument_list|,
name|IdentifierInfoLookup
operator|*
name|IILookup
operator|=
literal|0
argument_list|)
expr_stmt|;
operator|~
name|Preprocessor
argument_list|()
expr_stmt|;
name|Diagnostic
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
name|Diagnostic
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
name|getLangOptions
argument_list|()
specifier|const
block|{
return|return
name|Features
return|;
block|}
name|TargetInfo
operator|&
name|getTargetInfo
argument_list|()
specifier|const
block|{
return|return
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
comment|/// getCurrentFileLexer - Return the current file lexer being lexed from.  Note
comment|/// that this ignores any potentially active macro expansions and _Pragma
comment|/// expansions going on at the time.
name|PreprocessorLexer
operator|*
name|getCurrentFileLexer
argument_list|()
specifier|const
expr_stmt|;
comment|/// getPPCallbacks/setPPCallbacks - Accessors for preprocessor callbacks.
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
name|setPPCallbacks
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
comment|/// getMacroInfo - Given an identifier, return the MacroInfo it is #defined to
comment|/// or null if it isn't #define'd.
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
name|II
operator|->
name|hasMacroDefinition
argument_list|()
condition|?
name|Macros
operator|.
name|find
argument_list|(
name|II
argument_list|)
operator|->
name|second
else|:
literal|0
return|;
block|}
comment|/// setMacroInfo - Specify a macro for this identifier.
comment|///
name|void
name|setMacroInfo
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// macro_iterator/macro_begin/macro_end - This allows you to walk the current
comment|/// state of the macro table.  This visits every currently-defined macro.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|MacroInfo
operator|*
operator|>
operator|::
name|const_iterator
name|macro_iterator
expr_stmt|;
name|macro_iterator
name|macro_begin
argument_list|()
specifier|const
block|{
return|return
name|Macros
operator|.
name|begin
argument_list|()
return|;
block|}
name|macro_iterator
name|macro_end
argument_list|()
specifier|const
block|{
return|return
name|Macros
operator|.
name|end
argument_list|()
return|;
block|}
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
comment|/// getIdentifierInfo - Return information about the specified preprocessor
comment|/// identifier token.  The version of this method that takes two character
comment|/// pointers is preferred unless the identifier is already available as a
comment|/// string (this avoids allocation and copying of memory to construct an
comment|/// std::string).
name|IdentifierInfo
modifier|*
name|getIdentifierInfo
argument_list|(
name|llvm
operator|::
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
specifier|const
name|char
modifier|*
name|Namespace
parameter_list|,
name|PragmaHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
comment|/// RemovePragmaHandler - Remove the specific pragma handler from
comment|/// the preprocessor. If \arg Namespace is non-null, then it should
comment|/// be the namespace that \arg Handler was added to. It is an error
comment|/// to remove a handler that has not been registered.
name|void
name|RemovePragmaHandler
parameter_list|(
specifier|const
name|char
modifier|*
name|Namespace
parameter_list|,
name|PragmaHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
comment|/// \brief Add the specified comment handler to the preprocessor.
name|void
name|AddCommentHandler
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
name|RemoveCommentHandler
parameter_list|(
name|CommentHandler
modifier|*
name|Handler
parameter_list|)
function_decl|;
comment|/// EnterMainSourceFile - Enter the specified FileID as the main source file,
comment|/// which implicitly adds the builtin defines etc.
name|void
name|EnterMainSourceFile
parameter_list|()
function_decl|;
comment|/// EnterSourceFile - Add a source file to the top of the include stack and
comment|/// start lexing tokens from it instead of the current buffer.  If isMainFile
comment|/// is true, this is the main file for the translation unit.
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
comment|/// Lex - To lex a token from the preprocessor, just pull a token from the
comment|/// current lexer or macro object.
name|void
name|Lex
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
block|{
if|if
condition|(
name|CurLexer
condition|)
name|CurLexer
operator|->
name|Lex
argument_list|(
name|Result
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|CurPTHLexer
condition|)
name|CurPTHLexer
operator|->
name|Lex
argument_list|(
name|Result
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|CurTokenLexer
condition|)
name|CurTokenLexer
operator|->
name|Lex
argument_list|(
name|Result
argument_list|)
expr_stmt|;
else|else
name|CachingLex
argument_list|(
name|Result
argument_list|)
expr_stmt|;
block|}
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
comment|/// Diag - Forwarding function for diagnostics.  This emits a diagnostic at
comment|/// the specified Token's location, translating the token's start
comment|/// position in the current buffer into a SourcePosition object for rendering.
name|DiagnosticBuilder
name|Diag
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
block|{
return|return
name|Diags
operator|->
name|Report
argument_list|(
name|FullSourceLoc
argument_list|(
name|Loc
argument_list|,
name|getSourceManager
argument_list|()
argument_list|)
argument_list|,
name|DiagID
argument_list|)
return|;
block|}
name|DiagnosticBuilder
name|Diag
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
block|{
return|return
name|Diags
operator|->
name|Report
argument_list|(
name|FullSourceLoc
argument_list|(
name|Tok
operator|.
name|getLocation
argument_list|()
argument_list|,
name|getSourceManager
argument_list|()
argument_list|)
argument_list|,
name|DiagID
argument_list|)
return|;
block|}
comment|/// getSpelling() - Return the 'spelling' of the Tok token.  The spelling of a
comment|/// token is the characters used to represent the token in the source file
comment|/// after trigraph expansion and escaped-newline folding.  In particular, this
comment|/// wants to get the true, uncanonicalized, spelling of things like digraphs
comment|/// UCNs, etc.
name|std
operator|::
name|string
name|getSpelling
argument_list|(
argument|const Token&Tok
argument_list|)
specifier|const
expr_stmt|;
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
argument_list|)
decl|const
decl_stmt|;
comment|/// getSpellingOfSingleCharacterNumericConstant - Tok is a numeric constant
comment|/// with length 1, return the character.
name|char
name|getSpellingOfSingleCharacterNumericConstant
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
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
argument_list|)
return|;
block|}
comment|/// CreateString - Plop the specified string into a scratch buffer and set the
comment|/// specified token's location and length to it.  If specified, the source
comment|/// location provides a location of the instantiation point of the token.
name|void
name|CreateString
parameter_list|(
specifier|const
name|char
modifier|*
name|Buf
parameter_list|,
name|unsigned
name|Len
parameter_list|,
name|Token
modifier|&
name|Tok
parameter_list|,
name|SourceLocation
name|SourceLoc
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
name|SourceLocation
name|getLocForEndOfToken
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
function_decl|;
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
parameter_list|(
name|SourceLocation
name|TokStart
parameter_list|,
name|unsigned
name|Char
parameter_list|)
function_decl|;
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
comment|/// LookUpIdentifierInfo - Given a tok::identifier token, look up the
comment|/// identifier information for the token and install it into the token.
name|IdentifierInfo
modifier|*
name|LookUpIdentifierInfo
argument_list|(
name|Token
operator|&
name|Identifier
argument_list|,
specifier|const
name|char
operator|*
name|BufPtr
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// HandleIdentifier - This callback is invoked when the lexer reads an
comment|/// identifier and has filled in the tokens IdentifierInfo member.  This
comment|/// callback potentially macro expands it or turns it into a named token (like
comment|/// 'for').
name|void
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
comment|/// CheckEndOfDirective - Ensure that the next token is a tok::eom token.  If
comment|/// not, emit a diagnostic and consume up until the eom.  If EnableMacros is
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
comment|/// current line until the tok::eom token is found.
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
comment|/// AllocateMacroInfo - Allocate a new MacroInfo object with the provide
comment|///  SourceLocation.
name|MacroInfo
modifier|*
name|AllocateMacroInfo
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
function_decl|;
comment|/// GetIncludeFilenameSpelling - Turn the specified lexer token into a fully
comment|/// checked and spelled filename, e.g. as an operand of #include. This returns
comment|/// true if the input filename was in<>'s or false if it were in ""'s.  The
comment|/// caller is expected to provide a buffer that is large enough to hold the
comment|/// spelling of the filename, but is also expected to handle the case when
comment|/// this method decides to use a different buffer.
name|bool
name|GetIncludeFilenameSpelling
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|&
name|BufStart
parameter_list|,
specifier|const
name|char
modifier|*
modifier|&
name|BufEnd
parameter_list|)
function_decl|;
comment|/// LookupFile - Given a "foo" or<foo> reference, look up the indicated file,
comment|/// return null on failure.  isAngled indicates whether the file reference is
comment|/// for system #include's or not (i.e. using<> instead of "").
specifier|const
name|FileEntry
modifier|*
name|LookupFile
parameter_list|(
specifier|const
name|char
modifier|*
name|FilenameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|FilenameEnd
parameter_list|,
name|bool
name|isAngled
parameter_list|,
specifier|const
name|DirectoryLookup
modifier|*
name|FromDir
parameter_list|,
specifier|const
name|DirectoryLookup
modifier|*
modifier|&
name|CurDir
parameter_list|)
function_decl|;
comment|/// GetCurLookup - The DirectoryLookup structure used to find the current
comment|/// FileEntry, if CurLexer is non-null and if applicable.  This allows us to
comment|/// implement #include_next and find directory-specific properties.
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
comment|/// isInPrimaryFile - Return true if we're in the top-level file, not in a
comment|/// #include.
name|bool
name|isInPrimaryFile
argument_list|()
specifier|const
expr_stmt|;
comment|/// ConcatenateIncludeName - Handle cases where the #include name is expanded
comment|/// from a macro as multiple tokens, which need to be glued together.  This
comment|/// occurs for code like:
comment|///    #define FOO<a/b.h>
comment|///    #include FOO
comment|/// because in this case, "<a/b.h>" is returned as 7 tokens, not one.
comment|///
comment|/// This code concatenates and consumes tokens up to the '>' token.  It returns
comment|/// false if the> was found, otherwise it returns true if it finds and consumes
comment|/// the EOM marker.
name|bool
name|ConcatenateIncludeName
argument_list|(
name|llvm
operator|::
name|SmallVector
operator|<
name|char
argument_list|,
literal|128
operator|>
operator|&
name|FilenameBuffer
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
name|IncludeMacroStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
comment|/// ReleaseMacroInfo - Release the specified MacroInfo.  This memory will
comment|///  be reused for allocating new MacroInfo objects.
name|void
name|ReleaseMacroInfo
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// ReadMacroName - Lex and validate a macro name, which occurs after a
comment|/// #define or #undef.  This emits a diagnostic, sets the token kind to eom,
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
comment|/// closing ), updating MI with what we learn.  Return true if an error occurs
comment|/// parsing the arg list.
name|bool
name|ReadMacroDefinitionArgList
parameter_list|(
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// SkipExcludedConditionalBlock - We just read a #if or related directive and
comment|/// decided that the subsequent tokens are in the #if'd out portion of the
comment|/// file.  Lex the rest of the file, until we see an #endif.  If
comment|/// FoundNonSkipPortion is true, then we have already emitted code for part of
comment|/// this #if directive, so #else/#elif blocks should never be entered. If
comment|/// FoundElse is false, then #else directives are ok, if not, then we have
comment|/// already seen one so a #else directive is a duplicate.  When this returns,
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
parameter_list|)
function_decl|;
comment|/// PTHSkipExcludedConditionalBlock - A fast PTH version of
comment|///  SkipExcludedConditionalBlock.
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
comment|/// #pragma GCC poison/system_header/dependency and #pragma once.
name|void
name|RegisterBuiltinPragmas
parameter_list|()
function_decl|;
comment|/// RegisterBuiltinMacros - Register builtin macros, such as __LINE__ with the
comment|/// identifier table.
name|void
name|RegisterBuiltinMacros
parameter_list|()
function_decl|;
comment|/// HandleMacroExpandedIdentifier - If an identifier token is read that is to
comment|/// be expanded as a macro, handle it and return the next token as 'Tok'.  If
comment|/// the macro should not be expanded return true, otherwise return false.
name|bool
name|HandleMacroExpandedIdentifier
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|,
name|MacroInfo
modifier|*
name|MI
parameter_list|)
function_decl|;
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
name|InstantiationEnd
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
return|return
name|CurPPLexer
operator|==
literal|0
operator|&&
name|CurTokenLexer
operator|==
literal|0
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
comment|// File inclusion.
name|void
name|HandleIncludeDirective
parameter_list|(
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
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandleIncludeMacrosDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|HandleImportDirective
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// Macro handling.
name|void
name|HandleDefineDirective
parameter_list|(
name|Token
modifier|&
name|Tok
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
comment|// HandleAssertDirective(Token&Tok);
comment|// HandleUnassertDirective(Token&Tok);
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
parameter_list|()
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
name|HandlePragmaComment
parameter_list|(
name|Token
modifier|&
name|CommentTok
parameter_list|)
function_decl|;
name|void
name|HandleComment
parameter_list|(
name|SourceRange
name|Comment
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Abstract base class that describes a handler that will receive
comment|/// source ranges for each of the comments encountered in the source file.
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
name|virtual
name|void
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
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

