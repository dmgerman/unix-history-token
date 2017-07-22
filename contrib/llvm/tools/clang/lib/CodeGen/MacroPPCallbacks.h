begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MacroPPCallbacks.h -------------------------------------*- C++ -*-===//
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
comment|//  This file defines implementation for the macro preprocessors callbacks.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"clang/Lex/PPCallbacks.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DIMacroFile
decl_stmt|;
name|class
name|DIMacroNode
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|MacroInfo
decl_stmt|;
name|class
name|CodeGenerator
decl_stmt|;
name|class
name|MacroPPCallbacks
range|:
name|public
name|PPCallbacks
block|{
comment|/// A pointer to code generator, where debug info generator can be found.
name|CodeGenerator
operator|*
name|Gen
block|;
comment|/// Preprocessor.
name|Preprocessor
operator|&
name|PP
block|;
comment|/// Location of recent included file, used for line number.
name|SourceLocation
name|LastHashLoc
block|;
comment|/// Counts current number of command line included files, which were entered
comment|/// and were not exited yet.
name|int
name|EnteredCommandLineIncludeFiles
operator|=
literal|0
block|;    enum
name|FileScopeStatus
block|{
name|NoScope
operator|=
literal|0
block|,
comment|// Scope is not initialized yet.
name|InitializedScope
block|,
comment|// Main file scope is initialized but not set yet.
name|BuiltinScope
block|,
comment|//<built-in> and<command line> file scopes.
name|CommandLineIncludeScope
block|,
comment|// Included file, from<command line> file, scope.
name|MainFileScope
comment|// Main file scope.
block|}
block|;
name|FileScopeStatus
name|Status
block|;
comment|/// Parent contains all entered files that were not exited yet according to
comment|/// the inclusion order.
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|DIMacroFile
operator|*
block|,
literal|4
operator|>
name|Scopes
block|;
comment|/// Get current DIMacroFile scope.
comment|/// \return current DIMacroFile scope or nullptr if there is no such scope.
name|llvm
operator|::
name|DIMacroFile
operator|*
name|getCurrentScope
argument_list|()
block|;
comment|/// Get current line location or invalid location.
comment|/// \param Loc current line location.
comment|/// \return current line location \p `Loc`, or invalid location if it's in a
comment|///         skipped file scope.
name|SourceLocation
name|getCorrectLocation
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|;
comment|/// Use the passed preprocessor to write the macro name and value from the
comment|/// given macro info and identifier info into the given \p `Name` and \p
comment|/// `Value` output streams.
comment|///
comment|/// \param II Identifier info, used to get the Macro name.
comment|/// \param MI Macro info, used to get the Macro argumets and values.
comment|/// \param PP Preprocessor.
comment|/// \param [out] Name Place holder for returned macro name and arguments.
comment|/// \param [out] Value Place holder for returned macro value.
specifier|static
name|void
name|writeMacroDefinition
argument_list|(
specifier|const
name|IdentifierInfo
operator|&
name|II
argument_list|,
specifier|const
name|MacroInfo
operator|&
name|MI
argument_list|,
name|Preprocessor
operator|&
name|PP
argument_list|,
name|raw_ostream
operator|&
name|Name
argument_list|,
name|raw_ostream
operator|&
name|Value
argument_list|)
block|;
comment|/// Update current file scope status to next file scope.
name|void
name|updateStatusToNextScope
argument_list|()
block|;
comment|/// Handle the case when entering a file.
comment|///
comment|/// \param Loc Indicates the new location.
name|void
name|FileEntered
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|;
comment|/// Handle the case when exiting a file.
comment|///
comment|/// \param Loc Indicates the new location.
name|void
name|FileExited
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|;
name|public
operator|:
name|MacroPPCallbacks
argument_list|(
name|CodeGenerator
operator|*
name|Gen
argument_list|,
name|Preprocessor
operator|&
name|PP
argument_list|)
block|;
comment|/// Callback invoked whenever a source file is entered or exited.
comment|///
comment|/// \param Loc Indicates the new location.
comment|/// \param PrevFID the file that was exited if \p Reason is ExitFile.
name|void
name|FileChanged
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|FileChangeReason Reason
argument_list|,
argument|SrcMgr::CharacteristicKind FileType
argument_list|,
argument|FileID PrevFID = FileID()
argument_list|)
name|override
block|;
comment|/// Callback invoked whenever a directive (#xxx) is processed.
name|void
name|InclusionDirective
argument_list|(
argument|SourceLocation HashLoc
argument_list|,
argument|const Token&IncludeTok
argument_list|,
argument|StringRef FileName
argument_list|,
argument|bool IsAngled
argument_list|,
argument|CharSourceRange FilenameRange
argument_list|,
argument|const FileEntry *File
argument_list|,
argument|StringRef SearchPath
argument_list|,
argument|StringRef RelativePath
argument_list|,
argument|const Module *Imported
argument_list|)
name|override
block|;
comment|/// Hook called whenever a macro definition is seen.
name|void
name|MacroDefined
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDirective *MD
argument_list|)
name|override
block|;
comment|/// Hook called whenever a macro \#undef is seen.
comment|///
comment|/// MD is released immediately following this callback.
name|void
name|MacroUndefined
argument_list|(
argument|const Token&MacroNameTok
argument_list|,
argument|const MacroDefinition&MD
argument_list|,
argument|const MacroDirective *Undef
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

end_unit

