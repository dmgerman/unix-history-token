begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PrecompiledPreamble.h - Build precompiled preambles ----*- C++ -*-===//
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
comment|// Helper class to build precompiled preamble.
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
name|LLVM_CLANG_FRONTEND_PRECOMPILED_PREAMBLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PRECOMPILED_PREAMBLE_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/Lexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/Preprocessor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MD5.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|vfs
block|{
name|class
name|FileSystem
decl_stmt|;
block|}
name|class
name|CompilerInstance
decl_stmt|;
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|DeclGroupRef
decl_stmt|;
name|class
name|PCHContainerOperations
decl_stmt|;
comment|/// A size of the preamble and a flag required by
comment|/// PreprocessorOptions::PrecompiledPreambleBytes.
struct|struct
name|PreambleBounds
block|{
name|PreambleBounds
argument_list|(
argument|unsigned Size
argument_list|,
argument|bool PreambleEndsAtStartOfLine
argument_list|)
block|:
name|Size
argument_list|(
name|Size
argument_list|)
operator|,
name|PreambleEndsAtStartOfLine
argument_list|(
argument|PreambleEndsAtStartOfLine
argument_list|)
block|{}
comment|/// \brief Size of the preamble in bytes.
name|unsigned
name|Size
expr_stmt|;
comment|/// \brief Whether the preamble ends at the start of a new line.
comment|///
comment|/// Used to inform the lexer as to whether it's starting at the beginning of
comment|/// a line after skipping the preamble.
name|bool
name|PreambleEndsAtStartOfLine
decl_stmt|;
block|}
struct|;
comment|/// \brief Runs lexer to compute suggested preamble bounds.
name|PreambleBounds
name|ComputePreambleBounds
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|,
name|unsigned
name|MaxLines
argument_list|)
decl_stmt|;
name|class
name|PreambleCallbacks
decl_stmt|;
comment|/// A class holding a PCH and all information to check whether it is valid to
comment|/// reuse the PCH for the subsequent runs. Use BuildPreamble to create PCH and
comment|/// CanReusePreamble + AddImplicitPreamble to make use of it.
name|class
name|PrecompiledPreamble
block|{
name|class
name|TempPCHFile
decl_stmt|;
struct_decl|struct
name|PreambleFileHash
struct_decl|;
name|public
label|:
comment|/// \brief Try to build PrecompiledPreamble for \p Invocation. See
comment|/// BuildPreambleError for possible error codes.
comment|///
comment|/// \param Invocation Original CompilerInvocation with options to compile the
comment|/// file.
comment|///
comment|/// \param MainFileBuffer Buffer with the contents of the main file.
comment|///
comment|/// \param Bounds Bounds of the preamble, result of calling
comment|/// ComputePreambleBounds.
comment|///
comment|/// \param Diagnostics Diagnostics engine to be used while building the
comment|/// preamble.
comment|///
comment|/// \param VFS An instance of vfs::FileSystem to be used for file
comment|/// accesses.
comment|///
comment|/// \param PCHContainerOps An instance of PCHContainerOperations.
comment|///
comment|/// \param Callbacks A set of callbacks to be executed when building
comment|/// the preamble.
specifier|static
name|llvm
operator|::
name|ErrorOr
operator|<
name|PrecompiledPreamble
operator|>
name|Build
argument_list|(
argument|const CompilerInvocation&Invocation
argument_list|,
argument|const llvm::MemoryBuffer *MainFileBuffer
argument_list|,
argument|PreambleBounds Bounds
argument_list|,
argument|DiagnosticsEngine&Diagnostics
argument_list|,
argument|IntrusiveRefCntPtr<vfs::FileSystem> VFS
argument_list|,
argument|std::shared_ptr<PCHContainerOperations> PCHContainerOps
argument_list|,
argument|PreambleCallbacks&Callbacks
argument_list|)
expr_stmt|;
name|PrecompiledPreamble
argument_list|(
name|PrecompiledPreamble
operator|&&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|PrecompiledPreamble
modifier|&
name|operator
init|=
operator|(
name|PrecompiledPreamble
operator|&&
operator|)
operator|=
expr|default
decl_stmt|;
comment|/// PreambleBounds used to build the preamble
name|PreambleBounds
name|getBounds
argument_list|()
specifier|const
expr_stmt|;
comment|/// Check whether PrecompiledPreamble can be reused for the new contents(\p
comment|/// MainFileBuffer) of the main file.
name|bool
name|CanReuse
argument_list|(
specifier|const
name|CompilerInvocation
operator|&
name|Invocation
argument_list|,
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|MainFileBuffer
argument_list|,
name|PreambleBounds
name|Bounds
argument_list|,
name|vfs
operator|::
name|FileSystem
operator|*
name|VFS
argument_list|)
decl|const
decl_stmt|;
comment|/// Changes options inside \p CI to use PCH from this preamble. Also remaps
comment|/// main file to \p MainFileBuffer.
name|void
name|AddImplicitPreamble
argument_list|(
name|CompilerInvocation
operator|&
name|CI
argument_list|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|MainFileBuffer
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|PrecompiledPreamble
argument_list|(
argument|TempPCHFile PCHFile
argument_list|,
argument|std::vector<char> PreambleBytes
argument_list|,
argument|bool PreambleEndsAtStartOfLine
argument_list|,
argument|llvm::StringMap<PreambleFileHash> FilesInPreamble
argument_list|)
empty_stmt|;
comment|/// A temp file that would be deleted on destructor call. If destructor is not
comment|/// called for any reason, the file will be deleted at static objects'
comment|/// destruction.
comment|/// An assertion will fire if two TempPCHFiles are created with the same name,
comment|/// so it's not intended to be used outside preamble-handling.
name|class
name|TempPCHFile
block|{
name|public
label|:
comment|// A main method used to construct TempPCHFile.
specifier|static
name|llvm
operator|::
name|ErrorOr
operator|<
name|TempPCHFile
operator|>
name|CreateNewPreamblePCHFile
argument_list|()
expr_stmt|;
comment|/// Call llvm::sys::fs::createTemporaryFile to create a new temporary file.
specifier|static
name|llvm
operator|::
name|ErrorOr
operator|<
name|TempPCHFile
operator|>
name|createInSystemTempDir
argument_list|(
argument|const Twine&Prefix
argument_list|,
argument|StringRef Suffix
argument_list|)
expr_stmt|;
comment|/// Create a new instance of TemporaryFile for file at \p Path. Use with
comment|/// extreme caution, there's an assertion checking that there's only a
comment|/// single instance of TempPCHFile alive for each path.
specifier|static
name|llvm
operator|::
name|ErrorOr
operator|<
name|TempPCHFile
operator|>
name|createFromCustomPath
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
expr_stmt|;
name|private
label|:
name|TempPCHFile
argument_list|(
argument|std::string FilePath
argument_list|)
empty_stmt|;
name|public
label|:
name|TempPCHFile
argument_list|(
name|TempPCHFile
operator|&&
name|Other
argument_list|)
expr_stmt|;
name|TempPCHFile
modifier|&
name|operator
init|=
operator|(
name|TempPCHFile
operator|&&
name|Other
operator|)
decl_stmt|;
name|TempPCHFile
argument_list|(
specifier|const
name|TempPCHFile
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
operator|~
name|TempPCHFile
argument_list|()
expr_stmt|;
comment|/// A path where temporary file is stored.
name|llvm
operator|::
name|StringRef
name|getFilePath
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|RemoveFileIfPresent
parameter_list|()
function_decl|;
name|private
label|:
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|FilePath
expr_stmt|;
block|}
empty_stmt|;
comment|/// Data used to determine if a file used in the preamble has been changed.
struct|struct
name|PreambleFileHash
block|{
comment|/// All files have size set.
name|off_t
name|Size
init|=
literal|0
decl_stmt|;
comment|/// Modification time is set for files that are on disk.  For memory
comment|/// buffers it is zero.
name|time_t
name|ModTime
init|=
literal|0
decl_stmt|;
comment|/// Memory buffers have MD5 instead of modification time.  We don't
comment|/// compute MD5 for on-disk files because we hope that modification time is
comment|/// enough to tell if the file was changed.
name|llvm
operator|::
name|MD5
operator|::
name|MD5Result
name|MD5
operator|=
block|{}
expr_stmt|;
specifier|static
name|PreambleFileHash
name|createForFile
parameter_list|(
name|off_t
name|Size
parameter_list|,
name|time_t
name|ModTime
parameter_list|)
function_decl|;
specifier|static
name|PreambleFileHash
name|createForMemoryBuffer
argument_list|(
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|)
decl_stmt|;
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|PreambleFileHash
operator|&
name|LHS
operator|,
specifier|const
name|PreambleFileHash
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Size
operator|==
name|RHS
operator|.
name|Size
operator|&&
name|LHS
operator|.
name|ModTime
operator|==
name|RHS
operator|.
name|ModTime
operator|&&
name|LHS
operator|.
name|MD5
operator|==
name|RHS
operator|.
name|MD5
return|;
block|}
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|PreambleFileHash
operator|&
name|LHS
operator|,
specifier|const
name|PreambleFileHash
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
block|}
struct|;
comment|/// Manages the lifetime of temporary file that stores a PCH.
name|TempPCHFile
name|PCHFile
decl_stmt|;
comment|/// Keeps track of the files that were used when computing the
comment|/// preamble, with both their buffer size and their modification time.
comment|///
comment|/// If any of the files have changed from one compile to the next,
comment|/// the preamble must be thrown away.
name|llvm
operator|::
name|StringMap
operator|<
name|PreambleFileHash
operator|>
name|FilesInPreamble
expr_stmt|;
comment|/// The contents of the file that was used to precompile the preamble. Only
comment|/// contains first PreambleBounds::Size bytes. Used to compare if the relevant
comment|/// part of the file has not changed, so that preamble can be reused.
name|std
operator|::
name|vector
operator|<
name|char
operator|>
name|PreambleBytes
expr_stmt|;
comment|/// See PreambleBounds::PreambleEndsAtStartOfLine
name|bool
name|PreambleEndsAtStartOfLine
decl_stmt|;
block|}
empty_stmt|;
comment|/// A set of callbacks to gather useful information while building a preamble.
name|class
name|PreambleCallbacks
block|{
name|public
label|:
name|virtual
operator|~
name|PreambleCallbacks
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Called after FrontendAction::Execute(), but before
comment|/// FrontendAction::EndSourceFile(). Can be used to transfer ownership of
comment|/// various CompilerInstance fields before they are destroyed.
name|virtual
name|void
name|AfterExecute
parameter_list|(
name|CompilerInstance
modifier|&
name|CI
parameter_list|)
function_decl|;
comment|/// Called after PCH has been emitted. \p Writer may be used to retrieve
comment|/// information about AST, serialized in PCH.
name|virtual
name|void
name|AfterPCHEmitted
parameter_list|(
name|ASTWriter
modifier|&
name|Writer
parameter_list|)
function_decl|;
comment|/// Called for each TopLevelDecl.
comment|/// NOTE: To allow more flexibility a custom ASTConsumer could probably be
comment|/// used instead, but having only this method allows a simpler API.
name|virtual
name|void
name|HandleTopLevelDecl
parameter_list|(
name|DeclGroupRef
name|DG
parameter_list|)
function_decl|;
comment|/// Called for each macro defined in the Preamble.
comment|/// NOTE: To allow more flexibility a custom PPCallbacks could probably be
comment|/// used instead, but having only this method allows a simpler API.
name|virtual
name|void
name|HandleMacroDefined
parameter_list|(
specifier|const
name|Token
modifier|&
name|MacroNameTok
parameter_list|,
specifier|const
name|MacroDirective
modifier|*
name|MD
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|enum
name|class
name|BuildPreambleError
block|{
name|PreambleIsEmpty
operator|=
literal|1
operator|,
name|CouldntCreateTempFile
operator|,
name|CouldntCreateTargetInfo
operator|,
name|CouldntCreateVFSOverlay
operator|,
name|BeginSourceFileFailed
operator|,
name|CouldntEmitPCH
block|}
empty_stmt|;
name|class
name|BuildPreambleErrorCategory
name|final
range|:
name|public
name|std
operator|::
name|error_category
block|{
name|public
operator|:
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
name|noexcept
name|override
block|;
name|std
operator|::
name|string
name|message
argument_list|(
argument|int condition
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
name|std
operator|::
name|error_code
name|make_error_code
argument_list|(
argument|BuildPreambleError Error
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
operator|>
expr|struct
name|is_error_code_enum
operator|<
name|clang
operator|::
name|BuildPreambleError
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

