begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PPCallbacks.h - Callbacks for Preprocessor actions -----*- C++ -*-===//
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
comment|//  This file defines the PPCallbacks interface.
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
name|LLVM_CLANG_LEX_PPCALLBACKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PPCALLBACKS_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/DirectoryLookup.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|SourceLocation
decl_stmt|;
name|class
name|Token
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|MacroInfo
decl_stmt|;
comment|/// PPCallbacks - This interface provides a way to observe the actions of the
comment|/// preprocessor as it does its thing.  Clients can define their hooks here to
comment|/// implement preprocessor level tools.
name|class
name|PPCallbacks
block|{
name|public
label|:
name|virtual
operator|~
name|PPCallbacks
argument_list|()
expr_stmt|;
enum|enum
name|FileChangeReason
block|{
name|EnterFile
block|,
name|ExitFile
block|,
name|SystemHeaderPragma
block|,
name|RenameFile
block|}
enum|;
comment|/// FileChanged - This callback is invoked whenever a source file is
comment|/// entered or exited.  The SourceLocation indicates the new location, and
comment|/// EnteringFile indicates whether this is because we are entering a new
comment|/// #include'd file (when true) or whether we're exiting one because we ran
comment|/// off the end (when false).
name|virtual
name|void
name|FileChanged
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|FileChangeReason
name|Reason
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileType
argument_list|)
block|{   }
comment|/// FileSkipped - This callback is invoked whenever a source file is
comment|/// skipped as the result of header guard optimization.  ParentFile
comment|/// is the file that #includes the skipped file.  FilenameTok is the
comment|/// token in ParentFile that indicates the skipped file.
name|virtual
name|void
name|FileSkipped
argument_list|(
specifier|const
name|FileEntry
operator|&
name|ParentFile
argument_list|,
specifier|const
name|Token
operator|&
name|FilenameTok
argument_list|,
name|SrcMgr
operator|::
name|CharacteristicKind
name|FileType
argument_list|)
block|{   }
comment|/// \brief This callback is invoked whenever an inclusion directive of
comment|/// any kind (\c #include, \c #import, etc.) has been processed, regardless
comment|/// of whether the inclusion will actually result in an inclusion.
comment|///
comment|/// \param HashLoc The location of the '#' that starts the inclusion
comment|/// directive.
comment|///
comment|/// \param IncludeTok The token that indicates the kind of inclusion
comment|/// directive, e.g., 'include' or 'import'.
comment|///
comment|/// \param FileName The name of the file being included, as written in the
comment|/// source code.
comment|///
comment|/// \param IsAngled Whether the file name was enclosed in angle brackets;
comment|/// otherwise, it was enclosed in quotes.
comment|///
comment|/// \param File The actual file that may be included by this inclusion
comment|/// directive.
comment|///
comment|/// \param EndLoc The location of the last token within the inclusion
comment|/// directive.
comment|///
comment|/// \param SearchPath Contains the search path which was used to find the file
comment|/// in the file system. If the file was found via an absolute include path,
comment|/// SearchPath will be empty. For framework includes, the SearchPath and
comment|/// RelativePath will be split up. For example, if an include of "Some/Some.h"
comment|/// is found via the framework path
comment|/// "path/to/Frameworks/Some.framework/Headers/Some.h", SearchPath will be
comment|/// "path/to/Frameworks/Some.framework/Headers" and RelativePath will be
comment|/// "Some.h".
comment|///
comment|/// \param RelativePath The path relative to SearchPath, at which the include
comment|/// file was found. This is equal to FileName except for framework includes.
name|virtual
name|void
name|InclusionDirective
argument_list|(
name|SourceLocation
name|HashLoc
argument_list|,
specifier|const
name|Token
operator|&
name|IncludeTok
argument_list|,
name|llvm
operator|::
name|StringRef
name|FileName
argument_list|,
name|bool
name|IsAngled
argument_list|,
specifier|const
name|FileEntry
operator|*
name|File
argument_list|,
name|SourceLocation
name|EndLoc
argument_list|,
name|llvm
operator|::
name|StringRef
name|SearchPath
argument_list|,
name|llvm
operator|::
name|StringRef
name|RelativePath
argument_list|)
block|{   }
comment|/// EndOfMainFile - This callback is invoked when the end of the main file is
comment|/// reach, no subsequent callbacks will be made.
name|virtual
name|void
name|EndOfMainFile
parameter_list|()
block|{   }
comment|/// Ident - This callback is invoked when a #ident or #sccs directive is read.
comment|/// \param Loc The location of the directive.
comment|/// \param str The text of the directive.
comment|///
name|virtual
name|void
name|Ident
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
block|{   }
comment|/// PragmaComment - This callback is invoked when a #pragma comment directive
comment|/// is read.
comment|///
name|virtual
name|void
name|PragmaComment
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|IdentifierInfo
operator|*
name|Kind
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
block|{   }
comment|/// PragmaMessage - This callback is invoked when a #pragma message directive
comment|/// is read.
comment|/// \param Loc The location of the message directive.
comment|/// \param str The text of the message directive.
comment|///
name|virtual
name|void
name|PragmaMessage
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|llvm
operator|::
name|StringRef
name|Str
argument_list|)
block|{   }
comment|/// MacroExpands - This is called by
comment|/// Preprocessor::HandleMacroExpandedIdentifier when a macro invocation is
comment|/// found.
name|virtual
name|void
name|MacroExpands
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|)
block|{   }
comment|/// MacroDefined - This hook is called whenever a macro definition is seen.
name|virtual
name|void
name|MacroDefined
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|)
block|{   }
comment|/// MacroUndefined - This hook is called whenever a macro #undef is seen.
comment|/// MI is released immediately following this callback.
name|virtual
name|void
name|MacroUndefined
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|)
block|{   }
comment|/// If -- This hook is called whenever an #if is seen.
comment|/// \param Range The SourceRange of the expression being tested.
comment|// FIXME: better to pass in a list (or tree!) of Tokens.
name|virtual
name|void
name|If
parameter_list|(
name|SourceRange
name|Range
parameter_list|)
block|{   }
comment|/// Elif -- This hook is called whenever an #elif is seen.
comment|/// \param Range The SourceRange of the expression being tested.
comment|// FIXME: better to pass in a list (or tree!) of Tokens.
name|virtual
name|void
name|Elif
parameter_list|(
name|SourceRange
name|Range
parameter_list|)
block|{   }
comment|/// Ifdef -- This hook is called whenever an #ifdef is seen.
comment|/// \param Loc The location of the token being tested.
comment|/// \param II Information on the token being tested.
name|virtual
name|void
name|Ifdef
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|)
block|{   }
comment|/// Ifndef -- This hook is called whenever an #ifndef is seen.
comment|/// \param Loc The location of the token being tested.
comment|/// \param II Information on the token being tested.
name|virtual
name|void
name|Ifndef
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|)
block|{   }
comment|/// Else -- This hook is called whenever an #else is seen.
name|virtual
name|void
name|Else
parameter_list|()
block|{   }
comment|/// Endif -- This hook is called whenever an #endif is seen.
name|virtual
name|void
name|Endif
parameter_list|()
block|{   }
block|}
empty_stmt|;
comment|/// PPChainedCallbacks - Simple wrapper class for chaining callbacks.
name|class
name|PPChainedCallbacks
range|:
name|public
name|PPCallbacks
block|{
name|PPCallbacks
operator|*
name|First
block|,
operator|*
name|Second
block|;
name|public
operator|:
name|PPChainedCallbacks
argument_list|(
name|PPCallbacks
operator|*
name|_First
argument_list|,
name|PPCallbacks
operator|*
name|_Second
argument_list|)
operator|:
name|First
argument_list|(
name|_First
argument_list|)
block|,
name|Second
argument_list|(
argument|_Second
argument_list|)
block|{}
operator|~
name|PPChainedCallbacks
argument_list|()
block|{
name|delete
name|Second
block|;
name|delete
name|First
block|;   }
name|virtual
name|void
name|FileChanged
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|FileChangeReason Reason
argument_list|,
argument|SrcMgr::CharacteristicKind FileType
argument_list|)
block|{
name|First
operator|->
name|FileChanged
argument_list|(
name|Loc
argument_list|,
name|Reason
argument_list|,
name|FileType
argument_list|)
block|;
name|Second
operator|->
name|FileChanged
argument_list|(
name|Loc
argument_list|,
name|Reason
argument_list|,
name|FileType
argument_list|)
block|;   }
name|virtual
name|void
name|FileSkipped
argument_list|(
argument|const FileEntry&ParentFile
argument_list|,
argument|const Token&FilenameTok
argument_list|,
argument|SrcMgr::CharacteristicKind FileType
argument_list|)
block|{
name|First
operator|->
name|FileSkipped
argument_list|(
name|ParentFile
argument_list|,
name|FilenameTok
argument_list|,
name|FileType
argument_list|)
block|;
name|Second
operator|->
name|FileSkipped
argument_list|(
name|ParentFile
argument_list|,
name|FilenameTok
argument_list|,
name|FileType
argument_list|)
block|;   }
name|virtual
name|void
name|InclusionDirective
argument_list|(
argument|SourceLocation HashLoc
argument_list|,
argument|const Token&IncludeTok
argument_list|,
argument|llvm::StringRef FileName
argument_list|,
argument|bool IsAngled
argument_list|,
argument|const FileEntry *File
argument_list|,
argument|SourceLocation EndLoc
argument_list|,
argument|llvm::StringRef SearchPath
argument_list|,
argument|llvm::StringRef RelativePath
argument_list|)
block|{
name|First
operator|->
name|InclusionDirective
argument_list|(
name|HashLoc
argument_list|,
name|IncludeTok
argument_list|,
name|FileName
argument_list|,
name|IsAngled
argument_list|,
name|File
argument_list|,
name|EndLoc
argument_list|,
name|SearchPath
argument_list|,
name|RelativePath
argument_list|)
block|;
name|Second
operator|->
name|InclusionDirective
argument_list|(
name|HashLoc
argument_list|,
name|IncludeTok
argument_list|,
name|FileName
argument_list|,
name|IsAngled
argument_list|,
name|File
argument_list|,
name|EndLoc
argument_list|,
name|SearchPath
argument_list|,
name|RelativePath
argument_list|)
block|;   }
name|virtual
name|void
name|EndOfMainFile
argument_list|()
block|{
name|First
operator|->
name|EndOfMainFile
argument_list|()
block|;
name|Second
operator|->
name|EndOfMainFile
argument_list|()
block|;   }
name|virtual
name|void
name|Ident
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const std::string&str
argument_list|)
block|{
name|First
operator|->
name|Ident
argument_list|(
name|Loc
argument_list|,
name|str
argument_list|)
block|;
name|Second
operator|->
name|Ident
argument_list|(
name|Loc
argument_list|,
name|str
argument_list|)
block|;   }
name|virtual
name|void
name|PragmaComment
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const IdentifierInfo *Kind
argument_list|,
argument|const std::string&Str
argument_list|)
block|{
name|First
operator|->
name|PragmaComment
argument_list|(
name|Loc
argument_list|,
name|Kind
argument_list|,
name|Str
argument_list|)
block|;
name|Second
operator|->
name|PragmaComment
argument_list|(
name|Loc
argument_list|,
name|Kind
argument_list|,
name|Str
argument_list|)
block|;   }
name|virtual
name|void
name|PragmaMessage
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|llvm::StringRef Str
argument_list|)
block|{
name|First
operator|->
name|PragmaMessage
argument_list|(
name|Loc
argument_list|,
name|Str
argument_list|)
block|;
name|Second
operator|->
name|PragmaMessage
argument_list|(
name|Loc
argument_list|,
name|Str
argument_list|)
block|;   }
name|virtual
name|void
name|MacroExpands
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroInfo* MI
argument_list|)
block|{
name|First
operator|->
name|MacroExpands
argument_list|(
name|MacroNameTok
argument_list|,
name|MI
argument_list|)
block|;
name|Second
operator|->
name|MacroExpands
argument_list|(
name|MacroNameTok
argument_list|,
name|MI
argument_list|)
block|;   }
name|virtual
name|void
name|MacroDefined
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroInfo *MI
argument_list|)
block|{
name|First
operator|->
name|MacroDefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MI
argument_list|)
block|;
name|Second
operator|->
name|MacroDefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MI
argument_list|)
block|;   }
name|virtual
name|void
name|MacroUndefined
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroInfo *MI
argument_list|)
block|{
name|First
operator|->
name|MacroUndefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MI
argument_list|)
block|;
name|Second
operator|->
name|MacroUndefined
argument_list|(
name|MacroNameTok
argument_list|,
name|MI
argument_list|)
block|;   }
comment|/// If -- This hook is called whenever an #if is seen.
name|virtual
name|void
name|If
argument_list|(
argument|SourceRange Range
argument_list|)
block|{
name|First
operator|->
name|If
argument_list|(
name|Range
argument_list|)
block|;
name|Second
operator|->
name|If
argument_list|(
name|Range
argument_list|)
block|;   }
comment|/// Elif -- This hook is called whenever an #if is seen.
name|virtual
name|void
name|Elif
argument_list|(
argument|SourceRange Range
argument_list|)
block|{
name|First
operator|->
name|Elif
argument_list|(
name|Range
argument_list|)
block|;
name|Second
operator|->
name|Elif
argument_list|(
name|Range
argument_list|)
block|;   }
comment|/// Ifdef -- This hook is called whenever an #ifdef is seen.
name|virtual
name|void
name|Ifdef
argument_list|(
argument|const Token&MacroNameTok
argument_list|)
block|{
name|First
operator|->
name|Ifdef
argument_list|(
name|MacroNameTok
argument_list|)
block|;
name|Second
operator|->
name|Ifdef
argument_list|(
name|MacroNameTok
argument_list|)
block|;   }
comment|/// Ifndef -- This hook is called whenever an #ifndef is seen.
name|virtual
name|void
name|Ifndef
argument_list|(
argument|const Token&MacroNameTok
argument_list|)
block|{
name|First
operator|->
name|Ifndef
argument_list|(
name|MacroNameTok
argument_list|)
block|;
name|Second
operator|->
name|Ifndef
argument_list|(
name|MacroNameTok
argument_list|)
block|;   }
comment|/// Else -- This hook is called whenever an #else is seen.
name|virtual
name|void
name|Else
argument_list|()
block|{
name|First
operator|->
name|Else
argument_list|()
block|;
name|Second
operator|->
name|Else
argument_list|()
block|;   }
comment|/// Endif -- This hook is called whenever an #endif is seen.
name|virtual
name|void
name|Endif
argument_list|()
block|{
name|First
operator|->
name|Endif
argument_list|()
block|;
name|Second
operator|->
name|Endif
argument_list|()
block|;   }
block|}
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

end_unit

