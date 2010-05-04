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
comment|/// EndOfMainFile - This callback is invoked when the end of the main file is
comment|/// reach, no subsequent callbacks will be made.
name|virtual
name|void
name|EndOfMainFile
parameter_list|()
block|{   }
comment|/// Ident - This callback is invoked when a #ident or #sccs directive is read.
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
name|Id
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
name|IdentifierInfo
modifier|*
name|II
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
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|)
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
name|MacroExpands
argument_list|(
argument|const Token&Id
argument_list|,
argument|const MacroInfo* MI
argument_list|)
block|{
name|First
operator|->
name|MacroExpands
argument_list|(
name|Id
argument_list|,
name|MI
argument_list|)
block|;
name|Second
operator|->
name|MacroExpands
argument_list|(
name|Id
argument_list|,
name|MI
argument_list|)
block|;   }
name|virtual
name|void
name|MacroDefined
argument_list|(
argument|const IdentifierInfo *II
argument_list|,
argument|const MacroInfo *MI
argument_list|)
block|{
name|First
operator|->
name|MacroDefined
argument_list|(
name|II
argument_list|,
name|MI
argument_list|)
block|;
name|Second
operator|->
name|MacroDefined
argument_list|(
name|II
argument_list|,
name|MI
argument_list|)
block|;   }
name|virtual
name|void
name|MacroUndefined
argument_list|(
argument|const IdentifierInfo *II
argument_list|,
argument|const MacroInfo *MI
argument_list|)
block|{
name|First
operator|->
name|MacroUndefined
argument_list|(
name|II
argument_list|,
name|MI
argument_list|)
block|;
name|Second
operator|->
name|MacroUndefined
argument_list|(
name|II
argument_list|,
name|MI
argument_list|)
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

