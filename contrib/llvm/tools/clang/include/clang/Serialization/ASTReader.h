begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTReader.h - AST File Reader --------------------------*- C++ -*-===//
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
comment|//  This file defines the ASTReader class, which reads AST files.
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
name|LLVM_CLANG_SERIALIZATION_ASTREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_ASTREADER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileSystemOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Version.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/ExternalPreprocessorSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/HeaderSearch.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PreprocessingRecord.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/ExternalSemaSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/IdentifierResolver.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ContinuousRangeMap.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/Module.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ModuleFileExtension.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ModuleManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/TinyPtrVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Timer.h"
end_include

begin_include
include|#
directive|include
file|<deque>
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
file|<utility>
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
name|BitstreamCursor
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|APInt
decl_stmt|;
name|class
name|APSInt
decl_stmt|;
name|class
name|APFloat
decl_stmt|;
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
name|HeaderSearchOptions
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|AddrLabelExpr
decl_stmt|;
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTIdentifierIterator
decl_stmt|;
name|class
name|ASTUnit
decl_stmt|;
comment|// FIXME: Layering violation and egregious hack.
name|class
name|Attr
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|DefMacroDirective
decl_stmt|;
name|class
name|DiagnosticOptions
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXCtorInitializer
decl_stmt|;
name|class
name|GlobalModuleIndex
decl_stmt|;
name|class
name|GotoStmt
decl_stmt|;
name|class
name|MacroDefinition
decl_stmt|;
name|class
name|MacroDirective
decl_stmt|;
name|class
name|ModuleMacro
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|OpaqueValueExpr
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|SwitchCase
decl_stmt|;
name|class
name|ASTDeserializationListener
decl_stmt|;
name|class
name|ASTWriter
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|ASTDeclReader
decl_stmt|;
name|class
name|ASTStmtReader
decl_stmt|;
name|class
name|ASTRecordReader
decl_stmt|;
name|class
name|TypeLocReader
decl_stmt|;
struct_decl|struct
name|HeaderFileInfo
struct_decl|;
name|class
name|VersionTuple
decl_stmt|;
name|class
name|TargetOptions
decl_stmt|;
name|class
name|LazyASTUnresolvedSet
decl_stmt|;
comment|/// \brief Abstract interface for callback invocations by the ASTReader.
comment|///
comment|/// While reading an AST file, the ASTReader will call the methods of the
comment|/// listener to pass on specific information. Some of the listener methods can
comment|/// return true to indicate to the ASTReader that the information (and
comment|/// consequently the AST file) is invalid.
name|class
name|ASTReaderListener
block|{
name|public
label|:
name|virtual
operator|~
name|ASTReaderListener
argument_list|()
expr_stmt|;
comment|/// \brief Receives the full Clang version information.
comment|///
comment|/// \returns true to indicate that the version is invalid. Subclasses should
comment|/// generally defer to this implementation.
name|virtual
name|bool
name|ReadFullVersionInformation
parameter_list|(
name|StringRef
name|FullVersion
parameter_list|)
block|{
return|return
name|FullVersion
operator|!=
name|getClangFullRepositoryVersion
argument_list|()
return|;
block|}
name|virtual
name|void
name|ReadModuleName
parameter_list|(
name|StringRef
name|ModuleName
parameter_list|)
block|{}
name|virtual
name|void
name|ReadModuleMapFile
parameter_list|(
name|StringRef
name|ModuleMapPath
parameter_list|)
block|{}
comment|/// \brief Receives the language options.
comment|///
comment|/// \returns true to indicate the options are invalid or false otherwise.
name|virtual
name|bool
name|ReadLanguageOptions
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|bool
name|AllowCompatibleDifferences
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the target options.
comment|///
comment|/// \returns true to indicate the target options are invalid, or false
comment|/// otherwise.
name|virtual
name|bool
name|ReadTargetOptions
parameter_list|(
specifier|const
name|TargetOptions
modifier|&
name|TargetOpts
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|bool
name|AllowCompatibleDifferences
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the diagnostic options.
comment|///
comment|/// \returns true to indicate the diagnostic options are invalid, or false
comment|/// otherwise.
name|virtual
name|bool
name|ReadDiagnosticOptions
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticOptions
operator|>
name|DiagOpts
argument_list|,
name|bool
name|Complain
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the file system options.
comment|///
comment|/// \returns true to indicate the file system options are invalid, or false
comment|/// otherwise.
name|virtual
name|bool
name|ReadFileSystemOptions
parameter_list|(
specifier|const
name|FileSystemOptions
modifier|&
name|FSOpts
parameter_list|,
name|bool
name|Complain
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the header search options.
comment|///
comment|/// \returns true to indicate the header search options are invalid, or false
comment|/// otherwise.
name|virtual
name|bool
name|ReadHeaderSearchOptions
parameter_list|(
specifier|const
name|HeaderSearchOptions
modifier|&
name|HSOpts
parameter_list|,
name|StringRef
name|SpecificModuleCachePath
parameter_list|,
name|bool
name|Complain
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the preprocessor options.
comment|///
comment|/// \param SuggestedPredefines Can be filled in with the set of predefines
comment|/// that are suggested by the preprocessor options. Typically only used when
comment|/// loading a precompiled header.
comment|///
comment|/// \returns true to indicate the preprocessor options are invalid, or false
comment|/// otherwise.
name|virtual
name|bool
name|ReadPreprocessorOptions
argument_list|(
specifier|const
name|PreprocessorOptions
operator|&
name|PPOpts
argument_list|,
name|bool
name|Complain
argument_list|,
name|std
operator|::
name|string
operator|&
name|SuggestedPredefines
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives __COUNTER__ value.
name|virtual
name|void
name|ReadCounter
argument_list|(
specifier|const
name|serialization
operator|::
name|ModuleFile
operator|&
name|M
argument_list|,
name|unsigned
name|Value
argument_list|)
block|{}
comment|/// This is called for each AST file loaded.
name|virtual
name|void
name|visitModuleFile
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|serialization
operator|::
name|ModuleKind
name|Kind
argument_list|)
block|{}
comment|/// \brief Returns true if this \c ASTReaderListener wants to receive the
comment|/// input files of the AST file via \c visitInputFile, false otherwise.
name|virtual
name|bool
name|needsInputFileVisitation
parameter_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Returns true if this \c ASTReaderListener wants to receive the
comment|/// system input files of the AST file via \c visitInputFile, false otherwise.
name|virtual
name|bool
name|needsSystemInputFileVisitation
parameter_list|()
block|{
return|return
name|false
return|;
block|}
comment|/// \brief if \c needsInputFileVisitation returns true, this is called for
comment|/// each non-system input file of the AST File. If
comment|/// \c needsSystemInputFileVisitation is true, then it is called for all
comment|/// system input files as well.
comment|///
comment|/// \returns true to continue receiving the next input file, false to stop.
name|virtual
name|bool
name|visitInputFile
parameter_list|(
name|StringRef
name|Filename
parameter_list|,
name|bool
name|isSystem
parameter_list|,
name|bool
name|isOverridden
parameter_list|,
name|bool
name|isExplicitModule
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Returns true if this \c ASTReaderListener wants to receive the
comment|/// imports of the AST file via \c visitImport, false otherwise.
name|virtual
name|bool
name|needsImportVisitation
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief If needsImportVisitation returns \c true, this is called for each
comment|/// AST file imported by this AST file.
name|virtual
name|void
name|visitImport
parameter_list|(
name|StringRef
name|Filename
parameter_list|)
block|{}
comment|/// Indicates that a particular module file extension has been read.
name|virtual
name|void
name|readModuleFileExtension
parameter_list|(
specifier|const
name|ModuleFileExtensionMetadata
modifier|&
name|Metadata
parameter_list|)
block|{}
block|}
empty_stmt|;
comment|/// \brief Simple wrapper class for chaining listeners.
name|class
name|ChainedASTReaderListener
range|:
name|public
name|ASTReaderListener
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|First
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|Second
block|;
name|public
operator|:
comment|/// Takes ownership of \p First and \p Second.
name|ChainedASTReaderListener
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|First
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|Second
argument_list|)
operator|:
name|First
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|First
argument_list|)
argument_list|)
block|,
name|Second
argument_list|(
argument|std::move(Second)
argument_list|)
block|{}
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|takeFirst
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|First
argument_list|)
return|;
block|}
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|takeSecond
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|Second
argument_list|)
return|;
block|}
name|bool
name|ReadFullVersionInformation
argument_list|(
argument|StringRef FullVersion
argument_list|)
name|override
block|;
name|void
name|ReadModuleName
argument_list|(
argument|StringRef ModuleName
argument_list|)
name|override
block|;
name|void
name|ReadModuleMapFile
argument_list|(
argument|StringRef ModuleMapPath
argument_list|)
name|override
block|;
name|bool
name|ReadLanguageOptions
argument_list|(
argument|const LangOptions&LangOpts
argument_list|,
argument|bool Complain
argument_list|,
argument|bool AllowCompatibleDifferences
argument_list|)
name|override
block|;
name|bool
name|ReadTargetOptions
argument_list|(
argument|const TargetOptions&TargetOpts
argument_list|,
argument|bool Complain
argument_list|,
argument|bool AllowCompatibleDifferences
argument_list|)
name|override
block|;
name|bool
name|ReadDiagnosticOptions
argument_list|(
argument|IntrusiveRefCntPtr<DiagnosticOptions> DiagOpts
argument_list|,
argument|bool Complain
argument_list|)
name|override
block|;
name|bool
name|ReadFileSystemOptions
argument_list|(
argument|const FileSystemOptions&FSOpts
argument_list|,
argument|bool Complain
argument_list|)
name|override
block|;
name|bool
name|ReadHeaderSearchOptions
argument_list|(
argument|const HeaderSearchOptions&HSOpts
argument_list|,
argument|StringRef SpecificModuleCachePath
argument_list|,
argument|bool Complain
argument_list|)
name|override
block|;
name|bool
name|ReadPreprocessorOptions
argument_list|(
argument|const PreprocessorOptions&PPOpts
argument_list|,
argument|bool Complain
argument_list|,
argument|std::string&SuggestedPredefines
argument_list|)
name|override
block|;
name|void
name|ReadCounter
argument_list|(
argument|const serialization::ModuleFile&M
argument_list|,
argument|unsigned Value
argument_list|)
name|override
block|;
name|bool
name|needsInputFileVisitation
argument_list|()
name|override
block|;
name|bool
name|needsSystemInputFileVisitation
argument_list|()
name|override
block|;
name|void
name|visitModuleFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|serialization::ModuleKind Kind
argument_list|)
name|override
block|;
name|bool
name|visitInputFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|bool isSystem
argument_list|,
argument|bool isOverridden
argument_list|,
argument|bool isExplicitModule
argument_list|)
name|override
block|;
name|void
name|readModuleFileExtension
argument_list|(
argument|const ModuleFileExtensionMetadata&Metadata
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// \brief ASTReaderListener implementation to validate the information of
comment|/// the PCH file against an initialized Preprocessor.
name|class
name|PCHValidator
range|:
name|public
name|ASTReaderListener
block|{
name|Preprocessor
operator|&
name|PP
block|;
name|ASTReader
operator|&
name|Reader
block|;
name|public
operator|:
name|PCHValidator
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|ASTReader
operator|&
name|Reader
argument_list|)
operator|:
name|PP
argument_list|(
name|PP
argument_list|)
block|,
name|Reader
argument_list|(
argument|Reader
argument_list|)
block|{}
name|bool
name|ReadLanguageOptions
argument_list|(
argument|const LangOptions&LangOpts
argument_list|,
argument|bool Complain
argument_list|,
argument|bool AllowCompatibleDifferences
argument_list|)
name|override
block|;
name|bool
name|ReadTargetOptions
argument_list|(
argument|const TargetOptions&TargetOpts
argument_list|,
argument|bool Complain
argument_list|,
argument|bool AllowCompatibleDifferences
argument_list|)
name|override
block|;
name|bool
name|ReadDiagnosticOptions
argument_list|(
argument|IntrusiveRefCntPtr<DiagnosticOptions> DiagOpts
argument_list|,
argument|bool Complain
argument_list|)
name|override
block|;
name|bool
name|ReadPreprocessorOptions
argument_list|(
argument|const PreprocessorOptions&PPOpts
argument_list|,
argument|bool Complain
argument_list|,
argument|std::string&SuggestedPredefines
argument_list|)
name|override
block|;
name|bool
name|ReadHeaderSearchOptions
argument_list|(
argument|const HeaderSearchOptions&HSOpts
argument_list|,
argument|StringRef SpecificModuleCachePath
argument_list|,
argument|bool Complain
argument_list|)
name|override
block|;
name|void
name|ReadCounter
argument_list|(
argument|const serialization::ModuleFile&M
argument_list|,
argument|unsigned Value
argument_list|)
name|override
block|;
name|private
operator|:
name|void
name|Error
argument_list|(
specifier|const
name|char
operator|*
name|Msg
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief ASTReaderListenter implementation to set SuggestedPredefines of
comment|/// ASTReader which is required to use a pch file. This is the replacement
comment|/// of PCHValidator or SimplePCHValidator when using a pch file without
comment|/// validating it.
name|class
name|SimpleASTReaderListener
range|:
name|public
name|ASTReaderListener
block|{
name|Preprocessor
operator|&
name|PP
block|;
name|public
operator|:
name|SimpleASTReaderListener
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|)
operator|:
name|PP
argument_list|(
argument|PP
argument_list|)
block|{}
name|bool
name|ReadPreprocessorOptions
argument_list|(
argument|const PreprocessorOptions&PPOpts
argument_list|,
argument|bool Complain
argument_list|,
argument|std::string&SuggestedPredefines
argument_list|)
name|override
block|; }
decl_stmt|;
name|namespace
name|serialization
block|{
name|class
name|ReadMethodPoolVisitor
decl_stmt|;
name|namespace
name|reader
block|{
name|class
name|ASTIdentifierLookupTrait
decl_stmt|;
comment|/// \brief The on-disk hash table(s) used for DeclContext name lookup.
struct_decl|struct
name|DeclContextLookupTable
struct_decl|;
block|}
block|}
comment|// end namespace serialization
comment|/// \brief Reads an AST files chain containing the contents of a translation
comment|/// unit.
comment|///
comment|/// The ASTReader class reads bitstreams (produced by the ASTWriter
comment|/// class) containing the serialized representation of a given
comment|/// abstract syntax tree and its supporting data structures. An
comment|/// instance of the ASTReader can be attached to an ASTContext object,
comment|/// which will provide access to the contents of the AST files.
comment|///
comment|/// The AST reader provides lazy de-serialization of declarations, as
comment|/// required when traversing the AST. Only those AST nodes that are
comment|/// actually required will be de-serialized.
name|class
name|ASTReader
range|:
name|public
name|ExternalPreprocessorSource
decl_stmt|,
name|public
name|ExternalPreprocessingRecordSource
decl_stmt|,
name|public
name|ExternalHeaderFileInfoSource
decl_stmt|,
name|public
name|ExternalSemaSource
decl_stmt|,
name|public
name|IdentifierInfoLookup
decl_stmt|,
name|public
name|ExternalSLocEntrySource
block|{
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|RecordData
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|uint64_t
operator|>
name|RecordDataImpl
expr_stmt|;
comment|/// \brief The result of reading the control block of an AST file, which
comment|/// can fail for various reasons.
enum|enum
name|ASTReadResult
block|{
comment|/// \brief The control block was read successfully. Aside from failures,
comment|/// the AST file is safe to read into the current context.
name|Success
block|,
comment|/// \brief The AST file itself appears corrupted.
name|Failure
block|,
comment|/// \brief The AST file was missing.
name|Missing
block|,
comment|/// \brief The AST file is out-of-date relative to its input files,
comment|/// and needs to be regenerated.
name|OutOfDate
block|,
comment|/// \brief The AST file was written by a different version of Clang.
name|VersionMismatch
block|,
comment|/// \brief The AST file was writtten with a different language/target
comment|/// configuration.
name|ConfigurationMismatch
block|,
comment|/// \brief The AST file has errors.
name|HadErrors
block|}
enum|;
comment|/// \brief Types of AST files.
name|friend
name|class
name|PCHValidator
decl_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTStmtReader
decl_stmt|;
name|friend
name|class
name|ASTIdentifierIterator
decl_stmt|;
name|friend
name|class
name|serialization
operator|::
name|reader
operator|::
name|ASTIdentifierLookupTrait
expr_stmt|;
name|friend
name|class
name|TypeLocReader
decl_stmt|;
name|friend
name|class
name|ASTRecordReader
decl_stmt|;
name|friend
name|class
name|ASTWriter
decl_stmt|;
name|friend
name|class
name|ASTUnit
decl_stmt|;
comment|// ASTUnit needs to remap source locations.
name|friend
name|class
name|serialization
operator|::
name|ReadMethodPoolVisitor
expr_stmt|;
typedef|typedef
name|serialization
operator|::
name|ModuleFile
name|ModuleFile
expr_stmt|;
typedef|typedef
name|serialization
operator|::
name|ModuleKind
name|ModuleKind
expr_stmt|;
typedef|typedef
name|serialization
operator|::
name|ModuleManager
name|ModuleManager
expr_stmt|;
typedef|typedef
name|ModuleManager
operator|::
name|ModuleIterator
name|ModuleIterator
expr_stmt|;
typedef|typedef
name|ModuleManager
operator|::
name|ModuleConstIterator
name|ModuleConstIterator
expr_stmt|;
typedef|typedef
name|ModuleManager
operator|::
name|ModuleReverseIterator
name|ModuleReverseIterator
expr_stmt|;
name|private
label|:
comment|/// \brief The receiver of some callbacks invoked by ASTReader.
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|Listener
expr_stmt|;
comment|/// \brief The receiver of deserialization events.
name|ASTDeserializationListener
modifier|*
name|DeserializationListener
init|=
name|nullptr
decl_stmt|;
name|bool
name|OwnsDeserializationListener
init|=
name|false
decl_stmt|;
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|FileManager
modifier|&
name|FileMgr
decl_stmt|;
specifier|const
name|PCHContainerReader
modifier|&
name|PCHContainerRdr
decl_stmt|;
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
comment|/// \brief The semantic analysis object that will be processing the
comment|/// AST files and the translation unit that uses it.
name|Sema
modifier|*
name|SemaObj
init|=
name|nullptr
decl_stmt|;
comment|/// \brief The preprocessor that will be loading the source file.
name|Preprocessor
modifier|&
name|PP
decl_stmt|;
comment|/// \brief The AST context into which we'll read the AST files.
name|ASTContext
modifier|&
name|Context
decl_stmt|;
comment|/// \brief The AST consumer.
name|ASTConsumer
modifier|*
name|Consumer
init|=
name|nullptr
decl_stmt|;
comment|/// \brief The module manager which manages modules and their dependencies
name|ModuleManager
name|ModuleMgr
decl_stmt|;
comment|/// The cache that manages memory buffers for PCM files.
name|MemoryBufferCache
modifier|&
name|PCMCache
decl_stmt|;
comment|/// \brief A dummy identifier resolver used to merge TU-scope declarations in
comment|/// C, for the cases where we don't have a Sema object to provide a real
comment|/// identifier resolver.
name|IdentifierResolver
name|DummyIdResolver
decl_stmt|;
comment|/// A mapping from extension block names to module file extensions.
name|llvm
operator|::
name|StringMap
operator|<
name|std
operator|::
name|shared_ptr
operator|<
name|ModuleFileExtension
operator|>>
name|ModuleFileExtensions
expr_stmt|;
comment|/// \brief A timer used to track the time spent deserializing.
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|Timer
operator|>
name|ReadTimer
expr_stmt|;
comment|/// \brief The location where the module file will be considered as
comment|/// imported from. For non-module AST types it should be invalid.
name|SourceLocation
name|CurrentImportLoc
decl_stmt|;
comment|/// \brief The global module index, if loaded.
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalModuleIndex
operator|>
name|GlobalIndex
expr_stmt|;
comment|/// \brief A map of global bit offsets to the module that stores entities
comment|/// at those bit offsets.
name|ContinuousRangeMap
operator|<
name|uint64_t
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalBitOffsetsMap
expr_stmt|;
comment|/// \brief A map of negated SLocEntryIDs to the modules containing them.
name|ContinuousRangeMap
operator|<
name|unsigned
operator|,
name|ModuleFile
operator|*
operator|,
literal|64
operator|>
name|GlobalSLocEntryMap
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|unsigned
operator|,
name|ModuleFile
operator|*
operator|,
literal|64
operator|>
name|GlobalSLocOffsetMapType
expr_stmt|;
comment|/// \brief A map of reversed (SourceManager::MaxLoadedOffset - SLocOffset)
comment|/// SourceLocation offsets to the modules containing them.
name|GlobalSLocOffsetMapType
name|GlobalSLocOffsetMap
decl_stmt|;
comment|/// \brief Types that have already been loaded from the chain.
comment|///
comment|/// When the pointer at index I is non-NULL, the type with
comment|/// ID = (I + 1)<< FastQual::Width has already been loaded
name|std
operator|::
name|vector
operator|<
name|QualType
operator|>
name|TypesLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|TypeID
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalTypeMapType
expr_stmt|;
comment|/// \brief Mapping from global type IDs to the module in which the
comment|/// type resides along with the offset that should be added to the
comment|/// global type ID to produce a local ID.
name|GlobalTypeMapType
name|GlobalTypeMap
decl_stmt|;
comment|/// \brief Declarations that have already been loaded from the chain.
comment|///
comment|/// When the pointer at index I is non-NULL, the declaration with ID
comment|/// = I + 1 has already been loaded.
name|std
operator|::
name|vector
operator|<
name|Decl
operator|*
operator|>
name|DeclsLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalDeclMapType
expr_stmt|;
comment|/// \brief Mapping from global declaration IDs to the module in which the
comment|/// declaration resides.
name|GlobalDeclMapType
name|GlobalDeclMap
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ModuleFile
operator|*
operator|,
name|uint64_t
operator|>
name|FileOffset
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|FileOffset
operator|,
literal|2
operator|>
name|FileOffsetsTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|FileOffsetsTy
operator|>
name|DeclUpdateOffsetsMap
expr_stmt|;
comment|/// \brief Declarations that have modifications residing in a later file
comment|/// in the chain.
name|DeclUpdateOffsetsMap
name|DeclUpdateOffsets
decl_stmt|;
comment|/// \brief Declaration updates for already-loaded declarations that we need
comment|/// to apply once we finish processing an import.
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|serialization
operator|::
name|GlobalDeclID
operator|,
name|Decl
operator|*
operator|>
operator|,
literal|16
operator|>
name|PendingUpdateRecords
expr_stmt|;
name|enum
name|class
name|PendingFakeDefinitionKind
block|{
name|NotFake
operator|,
name|Fake
operator|,
name|FakeLoaded
block|}
empty_stmt|;
comment|/// \brief The DefinitionData pointers that we faked up for class definitions
comment|/// that we needed but hadn't loaded yet.
name|llvm
operator|::
name|DenseMap
operator|<
name|void
operator|*
operator|,
name|PendingFakeDefinitionKind
operator|>
name|PendingFakeDefinitionData
expr_stmt|;
comment|/// \brief Exception specification updates that have been loaded but not yet
comment|/// propagated across the relevant redeclaration chain. The map key is the
comment|/// canonical declaration (used only for deduplication) and the value is a
comment|/// declaration that has an exception specification.
name|llvm
operator|::
name|SmallMapVector
operator|<
name|Decl
operator|*
operator|,
name|FunctionDecl
operator|*
operator|,
literal|4
operator|>
name|PendingExceptionSpecUpdates
expr_stmt|;
comment|/// \brief Declarations that have been imported and have typedef names for
comment|/// linkage purposes.
name|llvm
operator|::
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
name|DeclContext
operator|*
operator|,
name|IdentifierInfo
operator|*
operator|>
operator|,
name|NamedDecl
operator|*
operator|>
name|ImportedTypedefNamesForLinkage
expr_stmt|;
comment|/// \brief Mergeable declaration contexts that have anonymous declarations
comment|/// within them, and those anonymous declarations.
name|llvm
operator|::
name|DenseMap
operator|<
name|DeclContext
operator|*
operator|,
name|llvm
operator|::
name|SmallVector
operator|<
name|NamedDecl
operator|*
operator|,
literal|2
operator|>>
name|AnonymousDeclarationsForMerging
expr_stmt|;
struct|struct
name|FileDeclsInfo
block|{
name|ModuleFile
modifier|*
name|Mod
decl_stmt|;
name|ArrayRef
operator|<
name|serialization
operator|::
name|LocalDeclID
operator|>
name|Decls
expr_stmt|;
name|FileDeclsInfo
argument_list|()
operator|:
name|Mod
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|FileDeclsInfo
argument_list|(
name|ModuleFile
operator|*
name|Mod
argument_list|,
name|ArrayRef
operator|<
name|serialization
operator|::
name|LocalDeclID
operator|>
name|Decls
argument_list|)
operator|:
name|Mod
argument_list|(
name|Mod
argument_list|)
operator|,
name|Decls
argument_list|(
argument|Decls
argument_list|)
block|{}
block|}
struct|;
comment|/// \brief Map from a FileID to the file-level declarations that it contains.
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
name|FileDeclsInfo
operator|>
name|FileDeclIDs
expr_stmt|;
comment|/// \brief An array of lexical contents of a declaration context, as a sequence of
comment|/// Decl::Kind, DeclID pairs.
typedef|typedef
name|ArrayRef
operator|<
name|llvm
operator|::
name|support
operator|::
name|unaligned_uint32_t
operator|>
name|LexicalContents
expr_stmt|;
comment|/// \brief Map from a DeclContext to its lexical contents.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|ModuleFile
operator|*
operator|,
name|LexicalContents
operator|>>
name|LexicalDecls
expr_stmt|;
comment|/// \brief Map from the TU to its lexical contents from each module file.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|ModuleFile
operator|*
operator|,
name|LexicalContents
operator|>>
name|TULexicalDecls
expr_stmt|;
comment|/// \brief Map from a DeclContext to its lookup tables.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
name|serialization
operator|::
name|reader
operator|::
name|DeclContextLookupTable
operator|>
name|Lookups
expr_stmt|;
comment|// Updates for visible decls can occur for other contexts than just the
comment|// TU, and when we read those update records, the actual context may not
comment|// be available yet, so have this pending map using the ID as a key. It
comment|// will be realized when the context is actually loaded.
struct|struct
name|PendingVisibleUpdate
block|{
name|ModuleFile
modifier|*
name|Mod
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|Data
decl_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|PendingVisibleUpdate
operator|,
literal|1
operator|>
name|DeclContextVisibleUpdates
expr_stmt|;
comment|/// \brief Updates to the visible declarations of declaration contexts that
comment|/// haven't been loaded yet.
name|llvm
operator|::
name|DenseMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|DeclContextVisibleUpdates
operator|>
name|PendingVisibleUpdates
expr_stmt|;
comment|/// \brief The set of C++ or Objective-C classes that have forward
comment|/// declarations that have not yet been linked to their definitions.
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|Decl
operator|*
operator|,
literal|4
operator|>
name|PendingDefinitions
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|MapVector
operator|<
name|Decl
operator|*
operator|,
name|uint64_t
operator|,
name|llvm
operator|::
name|SmallDenseMap
operator|<
name|Decl
operator|*
operator|,
name|unsigned
operator|,
literal|4
operator|>
operator|,
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|Decl
operator|*
operator|,
name|uint64_t
operator|>
operator|,
literal|4
operator|>
expr|>
name|PendingBodiesMap
expr_stmt|;
comment|/// \brief Functions or methods that have bodies that will be attached.
name|PendingBodiesMap
name|PendingBodies
decl_stmt|;
comment|/// \brief Definitions for which we have added merged definitions but not yet
comment|/// performed deduplication.
name|llvm
operator|::
name|SetVector
operator|<
name|NamedDecl
operator|*
operator|>
name|PendingMergedDefinitionsToDeduplicate
expr_stmt|;
comment|/// \brief Read the record that describes the lexical contents of a DC.
name|bool
name|ReadLexicalDeclContextStorage
argument_list|(
name|ModuleFile
operator|&
name|M
argument_list|,
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|,
name|uint64_t
name|Offset
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|)
decl_stmt|;
comment|/// \brief Read the record that describes the visible contents of a DC.
name|bool
name|ReadVisibleDeclContextStorage
argument_list|(
name|ModuleFile
operator|&
name|M
argument_list|,
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|,
name|uint64_t
name|Offset
argument_list|,
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief A vector containing identifiers that have already been
comment|/// loaded.
comment|///
comment|/// If the pointer at index I is non-NULL, then it refers to the
comment|/// IdentifierInfo for the identifier with ID=I+1 that has already
comment|/// been loaded.
name|std
operator|::
name|vector
operator|<
name|IdentifierInfo
operator|*
operator|>
name|IdentifiersLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|IdentID
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalIdentifierMapType
expr_stmt|;
comment|/// \brief Mapping from global identifier IDs to the module in which the
comment|/// identifier resides along with the offset that should be added to the
comment|/// global identifier ID to produce a local ID.
name|GlobalIdentifierMapType
name|GlobalIdentifierMap
decl_stmt|;
comment|/// \brief A vector containing macros that have already been
comment|/// loaded.
comment|///
comment|/// If the pointer at index I is non-NULL, then it refers to the
comment|/// MacroInfo for the identifier with ID=I+1 that has already
comment|/// been loaded.
name|std
operator|::
name|vector
operator|<
name|MacroInfo
operator|*
operator|>
name|MacrosLoaded
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
operator|,
name|serialization
operator|::
name|SubmoduleID
operator|>
name|LoadedMacroInfo
expr_stmt|;
comment|/// \brief A set of #undef directives that we have loaded; used to
comment|/// deduplicate the same #undef information coming from multiple module
comment|/// files.
name|llvm
operator|::
name|DenseSet
operator|<
name|LoadedMacroInfo
operator|>
name|LoadedUndefs
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|MacroID
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalMacroMapType
expr_stmt|;
comment|/// \brief Mapping from global macro IDs to the module in which the
comment|/// macro resides along with the offset that should be added to the
comment|/// global macro ID to produce a local ID.
name|GlobalMacroMapType
name|GlobalMacroMap
decl_stmt|;
comment|/// \brief A vector containing submodules that have already been loaded.
comment|///
comment|/// This vector is indexed by the Submodule ID (-1). NULL submodule entries
comment|/// indicate that the particular submodule ID has not yet been loaded.
name|SmallVector
operator|<
name|Module
operator|*
operator|,
literal|2
operator|>
name|SubmodulesLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|SubmoduleID
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalSubmoduleMapType
expr_stmt|;
comment|/// \brief Mapping from global submodule IDs to the module file in which the
comment|/// submodule resides along with the offset that should be added to the
comment|/// global submodule ID to produce a local ID.
name|GlobalSubmoduleMapType
name|GlobalSubmoduleMap
decl_stmt|;
comment|/// \brief A set of hidden declarations.
typedef|typedef
name|SmallVector
operator|<
name|Decl
operator|*
operator|,
literal|2
operator|>
name|HiddenNames
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|Module
operator|*
operator|,
name|HiddenNames
operator|>
name|HiddenNamesMapType
expr_stmt|;
comment|/// \brief A mapping from each of the hidden submodules to the deserialized
comment|/// declarations in that submodule that could be made visible.
name|HiddenNamesMapType
name|HiddenNamesMap
decl_stmt|;
comment|/// \brief A module import, export, or conflict that hasn't yet been resolved.
struct|struct
name|UnresolvedModuleRef
block|{
comment|/// \brief The file in which this module resides.
name|ModuleFile
modifier|*
name|File
decl_stmt|;
comment|/// \brief The module that is importing or exporting.
name|Module
modifier|*
name|Mod
decl_stmt|;
comment|/// \brief The kind of module reference.
enum|enum
block|{
name|Import
block|,
name|Export
block|,
name|Conflict
block|}
name|Kind
enum|;
comment|/// \brief The local ID of the module that is being exported.
name|unsigned
name|ID
decl_stmt|;
comment|/// \brief Whether this is a wildcard export.
name|unsigned
name|IsWildcard
range|:
literal|1
decl_stmt|;
comment|/// \brief String data.
name|StringRef
name|String
decl_stmt|;
block|}
struct|;
comment|/// \brief The set of module imports and exports that still need to be
comment|/// resolved.
name|SmallVector
operator|<
name|UnresolvedModuleRef
operator|,
literal|2
operator|>
name|UnresolvedModuleRefs
expr_stmt|;
comment|/// \brief A vector containing selectors that have already been loaded.
comment|///
comment|/// This vector is indexed by the Selector ID (-1). NULL selector
comment|/// entries indicate that the particular selector ID has not yet
comment|/// been loaded.
name|SmallVector
operator|<
name|Selector
operator|,
literal|16
operator|>
name|SelectorsLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|SelectorID
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalSelectorMapType
expr_stmt|;
comment|/// \brief Mapping from global selector IDs to the module in which the
comment|/// global selector ID to produce a local ID.
name|GlobalSelectorMapType
name|GlobalSelectorMap
decl_stmt|;
comment|/// \brief The generation number of the last time we loaded data from the
comment|/// global method pool for this selector.
name|llvm
operator|::
name|DenseMap
operator|<
name|Selector
operator|,
name|unsigned
operator|>
name|SelectorGeneration
expr_stmt|;
comment|/// Whether a selector is out of date. We mark a selector as out of date
comment|/// if we load another module after the method pool entry was pulled in.
name|llvm
operator|::
name|DenseMap
operator|<
name|Selector
operator|,
name|bool
operator|>
name|SelectorOutOfDate
expr_stmt|;
struct|struct
name|PendingMacroInfo
block|{
name|ModuleFile
modifier|*
name|M
decl_stmt|;
name|uint64_t
name|MacroDirectivesOffset
decl_stmt|;
name|PendingMacroInfo
argument_list|(
argument|ModuleFile *M
argument_list|,
argument|uint64_t MacroDirectivesOffset
argument_list|)
block|:
name|M
argument_list|(
name|M
argument_list|)
operator|,
name|MacroDirectivesOffset
argument_list|(
argument|MacroDirectivesOffset
argument_list|)
block|{}
block|}
struct|;
typedef|typedef
name|llvm
operator|::
name|MapVector
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SmallVector
operator|<
name|PendingMacroInfo
operator|,
literal|2
operator|>
expr|>
name|PendingMacroIDsMap
expr_stmt|;
comment|/// \brief Mapping from identifiers that have a macro history to the global
comment|/// IDs have not yet been deserialized to the global IDs of those macros.
name|PendingMacroIDsMap
name|PendingMacroIDs
decl_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|unsigned
operator|,
name|ModuleFile
operator|*
operator|,
literal|4
operator|>
name|GlobalPreprocessedEntityMapType
expr_stmt|;
comment|/// \brief Mapping from global preprocessing entity IDs to the module in
comment|/// which the preprocessed entity resides along with the offset that should be
comment|/// added to the global preprocessing entity ID to produce a local ID.
name|GlobalPreprocessedEntityMapType
name|GlobalPreprocessedEntityMap
decl_stmt|;
comment|/// \name CodeGen-relevant special data
comment|/// \brief Fields containing data that is relevant to CodeGen.
comment|//@{
comment|/// \brief The IDs of all declarations that fulfill the criteria of
comment|/// "interesting" decls.
comment|///
comment|/// This contains the data loaded from all EAGERLY_DESERIALIZED_DECLS blocks
comment|/// in the chain. The referenced declarations are deserialized and passed to
comment|/// the consumer eagerly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|EagerlyDeserializedDecls
expr_stmt|;
comment|/// \brief The IDs of all tentative definitions stored in the chain.
comment|///
comment|/// Sema keeps track of all tentative definitions in a TU because it has to
comment|/// complete them and pass them on to CodeGen. Thus, tentative definitions in
comment|/// the PCH chain must be eagerly deserialized.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|TentativeDefinitions
expr_stmt|;
comment|/// \brief The IDs of all CXXRecordDecls stored in the chain whose VTables are
comment|/// used.
comment|///
comment|/// CodeGen has to emit VTables for these records, so they have to be eagerly
comment|/// deserialized.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|VTableUses
expr_stmt|;
comment|/// \brief A snapshot of the pending instantiations in the chain.
comment|///
comment|/// This record tracks the instantiations that Sema has to perform at the
comment|/// end of the TU. It consists of a pair of values for every pending
comment|/// instantiation where the first value is the ID of the decl and the second
comment|/// is the instantiation location.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|PendingInstantiations
expr_stmt|;
comment|//@}
comment|/// \name DiagnosticsEngine-relevant special data
comment|/// \brief Fields containing data that is used for generating diagnostics
comment|//@{
comment|/// \brief A snapshot of Sema's unused file-scoped variable tracking, for
comment|/// generating warnings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|UnusedFileScopedDecls
expr_stmt|;
comment|/// \brief A list of all the delegating constructors we've seen, to diagnose
comment|/// cycles.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|DelegatingCtorDecls
expr_stmt|;
comment|/// \brief Method selectors used in a @selector expression. Used for
comment|/// implementation of -Wselector.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|ReferencedSelectorsData
expr_stmt|;
comment|/// \brief A snapshot of Sema's weak undeclared identifier tracking, for
comment|/// generating warnings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|WeakUndeclaredIdentifiers
expr_stmt|;
comment|/// \brief The IDs of type aliases for ext_vectors that exist in the chain.
comment|///
comment|/// Used by Sema for finding sugared names for ext_vectors in diagnostics.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|ExtVectorDecls
expr_stmt|;
comment|//@}
comment|/// \name Sema-relevant special data
comment|/// \brief Fields containing data that is used for semantic analysis
comment|//@{
comment|/// \brief The IDs of all potentially unused typedef names in the chain.
comment|///
comment|/// Sema tracks these to emit warnings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|UnusedLocalTypedefNameCandidates
expr_stmt|;
comment|/// \brief Our current depth in #pragma cuda force_host_device begin/end
comment|/// macros.
name|unsigned
name|ForceCUDAHostDeviceDepth
init|=
literal|0
decl_stmt|;
comment|/// \brief The IDs of the declarations Sema stores directly.
comment|///
comment|/// Sema tracks a few important decls, such as namespace std, directly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|SemaDeclRefs
expr_stmt|;
comment|/// \brief The IDs of the types ASTContext stores directly.
comment|///
comment|/// The AST context tracks a few important types, such as va_list, directly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|SpecialTypes
expr_stmt|;
comment|/// \brief The IDs of CUDA-specific declarations ASTContext stores directly.
comment|///
comment|/// The AST context tracks a few important decls, currently cudaConfigureCall,
comment|/// directly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|2
operator|>
name|CUDASpecialDeclRefs
expr_stmt|;
comment|/// \brief The floating point pragma option settings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|FPPragmaOptions
expr_stmt|;
comment|/// \brief The pragma clang optimize location (if the pragma state is "off").
name|SourceLocation
name|OptimizeOffPragmaLocation
decl_stmt|;
comment|/// \brief The PragmaMSStructKind pragma ms_struct state if set, or -1.
name|int
name|PragmaMSStructState
init|=
operator|-
literal|1
decl_stmt|;
comment|/// \brief The PragmaMSPointersToMembersKind pragma pointers_to_members state.
name|int
name|PragmaMSPointersToMembersState
init|=
operator|-
literal|1
decl_stmt|;
name|SourceLocation
name|PointersToMembersPragmaLocation
decl_stmt|;
comment|/// \brief The pragma pack state.
name|Optional
operator|<
name|unsigned
operator|>
name|PragmaPackCurrentValue
expr_stmt|;
name|SourceLocation
name|PragmaPackCurrentLocation
decl_stmt|;
struct|struct
name|PragmaPackStackEntry
block|{
name|unsigned
name|Value
decl_stmt|;
name|SourceLocation
name|Location
decl_stmt|;
name|StringRef
name|SlotLabel
decl_stmt|;
block|}
struct|;
name|llvm
operator|::
name|SmallVector
operator|<
name|PragmaPackStackEntry
operator|,
literal|2
operator|>
name|PragmaPackStack
expr_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|2
operator|>
name|PragmaPackStrings
expr_stmt|;
comment|/// \brief The OpenCL extension settings.
name|OpenCLOptions
name|OpenCLExtensions
decl_stmt|;
comment|/// \brief Extensions required by an OpenCL type.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>>
name|OpenCLTypeExtMap
expr_stmt|;
comment|/// \brief Extensions required by an OpenCL declaration.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|std
operator|::
name|set
operator|<
name|std
operator|::
name|string
operator|>>
name|OpenCLDeclExtMap
expr_stmt|;
comment|/// \brief A list of the namespaces we've seen.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|KnownNamespaces
expr_stmt|;
comment|/// \brief A list of undefined decls with internal linkage followed by the
comment|/// SourceLocation of a matching ODR-use.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|8
operator|>
name|UndefinedButUsed
expr_stmt|;
comment|/// \brief Delete expressions to analyze at the end of translation unit.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|8
operator|>
name|DelayedDeleteExprs
expr_stmt|;
comment|// \brief A list of late parsed template function data.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|LateParsedTemplates
expr_stmt|;
name|public
label|:
struct|struct
name|ImportedSubmodule
block|{
name|serialization
operator|::
name|SubmoduleID
name|ID
expr_stmt|;
name|SourceLocation
name|ImportLoc
decl_stmt|;
name|ImportedSubmodule
argument_list|(
argument|serialization::SubmoduleID ID
argument_list|,
argument|SourceLocation ImportLoc
argument_list|)
block|:
name|ID
argument_list|(
name|ID
argument_list|)
operator|,
name|ImportLoc
argument_list|(
argument|ImportLoc
argument_list|)
block|{}
block|}
struct|;
name|private
label|:
comment|/// \brief A list of modules that were imported by precompiled headers or
comment|/// any other non-module AST file.
name|SmallVector
operator|<
name|ImportedSubmodule
operator|,
literal|2
operator|>
name|ImportedModules
expr_stmt|;
comment|//@}
comment|/// \brief The directory that the PCH we are reading is stored in.
name|std
operator|::
name|string
name|CurrentDir
expr_stmt|;
comment|/// \brief The system include root to be used when loading the
comment|/// precompiled header.
name|std
operator|::
name|string
name|isysroot
expr_stmt|;
comment|/// \brief Whether to disable the normal validation performed on precompiled
comment|/// headers when they are loaded.
name|bool
name|DisableValidation
decl_stmt|;
comment|/// \brief Whether to accept an AST file with compiler errors.
name|bool
name|AllowASTWithCompilerErrors
decl_stmt|;
comment|/// \brief Whether to accept an AST file that has a different configuration
comment|/// from the current compiler instance.
name|bool
name|AllowConfigurationMismatch
decl_stmt|;
comment|/// \brief Whether validate system input files.
name|bool
name|ValidateSystemInputs
decl_stmt|;
comment|/// \brief Whether we are allowed to use the global module index.
name|bool
name|UseGlobalIndex
decl_stmt|;
comment|/// \brief Whether we have tried loading the global module index yet.
name|bool
name|TriedLoadingGlobalIndex
init|=
name|false
decl_stmt|;
comment|///\brief Whether we are currently processing update records.
name|bool
name|ProcessingUpdateRecords
init|=
name|false
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|SwitchCase
operator|*
operator|>
name|SwitchCaseMapTy
expr_stmt|;
comment|/// \brief Mapping from switch-case IDs in the chain to switch-case statements
comment|///
comment|/// Statements usually don't have IDs, but switch cases need them, so that the
comment|/// switch statement can refer to them.
name|SwitchCaseMapTy
name|SwitchCaseStmts
decl_stmt|;
name|SwitchCaseMapTy
modifier|*
name|CurrSwitchCaseStmts
decl_stmt|;
comment|/// \brief The number of source location entries de-serialized from
comment|/// the PCH file.
name|unsigned
name|NumSLocEntriesRead
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of source location entries in the chain.
name|unsigned
name|TotalNumSLocEntries
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of statements (and expressions) de-serialized
comment|/// from the chain.
name|unsigned
name|NumStatementsRead
init|=
literal|0
decl_stmt|;
comment|/// \brief The total number of statements (and expressions) stored
comment|/// in the chain.
name|unsigned
name|TotalNumStatements
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of macros de-serialized from the chain.
name|unsigned
name|NumMacrosRead
init|=
literal|0
decl_stmt|;
comment|/// \brief The total number of macros stored in the chain.
name|unsigned
name|TotalNumMacros
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of lookups into identifier tables.
name|unsigned
name|NumIdentifierLookups
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of lookups into identifier tables that succeed.
name|unsigned
name|NumIdentifierLookupHits
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of selectors that have been read.
name|unsigned
name|NumSelectorsRead
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of method pool entries that have been read.
name|unsigned
name|NumMethodPoolEntriesRead
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of times we have looked up a selector in the method
comment|/// pool.
name|unsigned
name|NumMethodPoolLookups
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of times we have looked up a selector in the method
comment|/// pool and found something.
name|unsigned
name|NumMethodPoolHits
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of times we have looked up a selector in the method
comment|/// pool within a specific module.
name|unsigned
name|NumMethodPoolTableLookups
init|=
literal|0
decl_stmt|;
comment|/// \brief The number of times we have looked up a selector in the method
comment|/// pool within a specific module and found something.
name|unsigned
name|NumMethodPoolTableHits
init|=
literal|0
decl_stmt|;
comment|/// \brief The total number of method pool entries in the selector table.
name|unsigned
name|TotalNumMethodPoolEntries
init|=
literal|0
decl_stmt|;
comment|/// Number of lexical decl contexts read/total.
name|unsigned
name|NumLexicalDeclContextsRead
init|=
literal|0
decl_stmt|,
name|TotalLexicalDeclContexts
init|=
literal|0
decl_stmt|;
comment|/// Number of visible decl contexts read/total.
name|unsigned
name|NumVisibleDeclContextsRead
init|=
literal|0
decl_stmt|,
name|TotalVisibleDeclContexts
init|=
literal|0
decl_stmt|;
comment|/// Total size of modules, in bits, currently loaded
name|uint64_t
name|TotalModulesSizeInBits
init|=
literal|0
decl_stmt|;
comment|/// \brief Number of Decl/types that are currently deserializing.
name|unsigned
name|NumCurrentElementsDeserializing
init|=
literal|0
decl_stmt|;
comment|/// \brief Set true while we are in the process of passing deserialized
comment|/// "interesting" decls to consumer inside FinishedDeserializing().
comment|/// This is used as a guard to avoid recursively repeating the process of
comment|/// passing decls to consumer.
name|bool
name|PassingDeclsToConsumer
init|=
name|false
decl_stmt|;
comment|/// \brief The set of identifiers that were read while the AST reader was
comment|/// (recursively) loading declarations.
comment|///
comment|/// The declarations on the identifier chain for these identifiers will be
comment|/// loaded once the recursive loading has completed.
name|llvm
operator|::
name|MapVector
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SmallVector
operator|<
name|uint32_t
operator|,
literal|4
operator|>
expr|>
name|PendingIdentifierInfos
expr_stmt|;
comment|/// \brief The set of lookup results that we have faked in order to support
comment|/// merging of partially deserialized decls but that we have not yet removed.
name|llvm
operator|::
name|SmallMapVector
operator|<
name|IdentifierInfo
operator|*
operator|,
name|SmallVector
operator|<
name|NamedDecl
operator|*
operator|,
literal|2
operator|>
operator|,
literal|16
operator|>
name|PendingFakeLookupResults
expr_stmt|;
comment|/// \brief The generation number of each identifier, which keeps track of
comment|/// the last time we loaded information about this identifier.
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|unsigned
operator|>
name|IdentifierGeneration
expr_stmt|;
name|class
name|InterestingDecl
block|{
name|Decl
modifier|*
name|D
decl_stmt|;
name|bool
name|DeclHasPendingBody
decl_stmt|;
name|public
label|:
name|InterestingDecl
argument_list|(
argument|Decl *D
argument_list|,
argument|bool HasBody
argument_list|)
block|:
name|D
argument_list|(
name|D
argument_list|)
operator|,
name|DeclHasPendingBody
argument_list|(
argument|HasBody
argument_list|)
block|{}
name|Decl
operator|*
name|getDecl
argument_list|()
block|{
return|return
name|D
return|;
block|}
comment|/// Whether the declaration has a pending body.
name|bool
name|hasPendingBody
parameter_list|()
block|{
return|return
name|DeclHasPendingBody
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Contains declarations and definitions that could be
comment|/// "interesting" to the ASTConsumer, when we get that AST consumer.
comment|///
comment|/// "Interesting" declarations are those that have data that may
comment|/// need to be emitted, such as inline function definitions or
comment|/// Objective-C protocols.
name|std
operator|::
name|deque
operator|<
name|InterestingDecl
operator|>
name|PotentiallyInterestingDecls
expr_stmt|;
comment|/// \brief The list of redeclaration chains that still need to be
comment|/// reconstructed, and the local offset to the corresponding list
comment|/// of redeclarations.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|Decl
operator|*
operator|,
name|uint64_t
operator|>
operator|,
literal|16
operator|>
name|PendingDeclChains
expr_stmt|;
comment|/// \brief The list of canonical declarations whose redeclaration chains
comment|/// need to be marked as incomplete once we're done deserializing things.
name|SmallVector
operator|<
name|Decl
operator|*
operator|,
literal|16
operator|>
name|PendingIncompleteDeclChains
expr_stmt|;
comment|/// \brief The Decl IDs for the Sema/Lexical DeclContext of a Decl that has
comment|/// been loaded but its DeclContext was not set yet.
struct|struct
name|PendingDeclContextInfo
block|{
name|Decl
modifier|*
name|D
decl_stmt|;
name|serialization
operator|::
name|GlobalDeclID
name|SemaDC
expr_stmt|;
name|serialization
operator|::
name|GlobalDeclID
name|LexicalDC
expr_stmt|;
block|}
struct|;
comment|/// \brief The set of Decls that have been loaded but their DeclContexts are
comment|/// not set yet.
comment|///
comment|/// The DeclContexts for these Decls will be set once recursive loading has
comment|/// been completed.
name|std
operator|::
name|deque
operator|<
name|PendingDeclContextInfo
operator|>
name|PendingDeclContextInfos
expr_stmt|;
comment|/// \brief The set of NamedDecls that have been loaded, but are members of a
comment|/// context that has been merged into another context where the corresponding
comment|/// declaration is either missing or has not yet been loaded.
comment|///
comment|/// We will check whether the corresponding declaration is in fact missing
comment|/// once recursing loading has been completed.
name|llvm
operator|::
name|SmallVector
operator|<
name|NamedDecl
operator|*
operator|,
literal|16
operator|>
name|PendingOdrMergeChecks
expr_stmt|;
comment|/// \brief Record definitions in which we found an ODR violation.
name|llvm
operator|::
name|SmallDenseMap
operator|<
name|CXXRecordDecl
operator|*
operator|,
name|llvm
operator|::
name|TinyPtrVector
operator|<
name|CXXRecordDecl
operator|*
operator|>
operator|,
literal|2
operator|>
name|PendingOdrMergeFailures
expr_stmt|;
comment|/// \brief DeclContexts in which we have diagnosed an ODR violation.
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|DeclContext
operator|*
operator|,
literal|2
operator|>
name|DiagnosedOdrMergeFailures
expr_stmt|;
comment|/// \brief The set of Objective-C categories that have been deserialized
comment|/// since the last time the declaration chains were linked.
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|ObjCCategoryDecl
operator|*
operator|,
literal|16
operator|>
name|CategoriesDeserialized
expr_stmt|;
comment|/// \brief The set of Objective-C class definitions that have already been
comment|/// loaded, for which we will need to check for categories whenever a new
comment|/// module is loaded.
name|SmallVector
operator|<
name|ObjCInterfaceDecl
operator|*
operator|,
literal|16
operator|>
name|ObjCClassesLoaded
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|Decl
operator|*
operator|,
name|SmallVector
operator|<
name|serialization
operator|::
name|DeclID
operator|,
literal|2
operator|>
expr|>
name|KeyDeclsMap
expr_stmt|;
comment|/// \brief A mapping from canonical declarations to the set of global
comment|/// declaration IDs for key declaration that have been merged with that
comment|/// canonical declaration. A key declaration is a formerly-canonical
comment|/// declaration whose module did not import any other key declaration for that
comment|/// entity. These are the IDs that we use as keys when finding redecl chains.
name|KeyDeclsMap
name|KeyDecls
decl_stmt|;
comment|/// \brief A mapping from DeclContexts to the semantic DeclContext that we
comment|/// are treating as the definition of the entity. This is used, for instance,
comment|/// when merging implicit instantiations of class templates across modules.
name|llvm
operator|::
name|DenseMap
operator|<
name|DeclContext
operator|*
operator|,
name|DeclContext
operator|*
operator|>
name|MergedDeclContexts
expr_stmt|;
comment|/// \brief A mapping from canonical declarations of enums to their canonical
comment|/// definitions. Only populated when using modules in C++.
name|llvm
operator|::
name|DenseMap
operator|<
name|EnumDecl
operator|*
operator|,
name|EnumDecl
operator|*
operator|>
name|EnumDefinitions
expr_stmt|;
comment|/// \brief When reading a Stmt tree, Stmt operands are placed in this stack.
name|SmallVector
operator|<
name|Stmt
operator|*
operator|,
literal|16
operator|>
name|StmtStack
expr_stmt|;
comment|/// \brief What kind of records we are reading.
enum|enum
name|ReadingKind
block|{
name|Read_None
block|,
name|Read_Decl
block|,
name|Read_Type
block|,
name|Read_Stmt
block|}
enum|;
comment|/// \brief What kind of records we are reading.
name|ReadingKind
name|ReadingKind
init|=
name|Read_None
decl_stmt|;
comment|/// \brief RAII object to change the reading kind.
name|class
name|ReadingKindTracker
block|{
name|ASTReader
modifier|&
name|Reader
decl_stmt|;
name|enum
name|ReadingKind
name|PrevKind
decl_stmt|;
name|ReadingKindTracker
argument_list|(
specifier|const
name|ReadingKindTracker
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ReadingKindTracker
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|ReadingKindTracker
argument_list|(
argument|enum ReadingKind newKind
argument_list|,
argument|ASTReader&reader
argument_list|)
block|:
name|Reader
argument_list|(
name|reader
argument_list|)
operator|,
name|PrevKind
argument_list|(
argument|Reader.ReadingKind
argument_list|)
block|{
name|Reader
operator|.
name|ReadingKind
operator|=
name|newKind
block|;     }
operator|~
name|ReadingKindTracker
argument_list|()
block|{
name|Reader
operator|.
name|ReadingKind
operator|=
name|PrevKind
block|; }
block|}
empty_stmt|;
comment|/// \brief RAII object to mark the start of processing updates.
name|class
name|ProcessingUpdatesRAIIObj
block|{
name|ASTReader
modifier|&
name|Reader
decl_stmt|;
name|bool
name|PrevState
decl_stmt|;
name|ProcessingUpdatesRAIIObj
argument_list|(
specifier|const
name|ProcessingUpdatesRAIIObj
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ProcessingUpdatesRAIIObj
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|public
label|:
name|ProcessingUpdatesRAIIObj
argument_list|(
name|ASTReader
operator|&
name|reader
argument_list|)
operator|:
name|Reader
argument_list|(
name|reader
argument_list|)
operator|,
name|PrevState
argument_list|(
argument|Reader.ProcessingUpdateRecords
argument_list|)
block|{
name|Reader
operator|.
name|ProcessingUpdateRecords
operator|=
name|true
block|;     }
operator|~
name|ProcessingUpdatesRAIIObj
argument_list|()
block|{
name|Reader
operator|.
name|ProcessingUpdateRecords
operator|=
name|PrevState
block|; }
block|}
empty_stmt|;
comment|/// \brief Suggested contents of the predefines buffer, after this
comment|/// PCH file has been processed.
comment|///
comment|/// In most cases, this string will be empty, because the predefines
comment|/// buffer computed to build the PCH file will be identical to the
comment|/// predefines buffer computed from the command line. However, when
comment|/// there are differences that the PCH reader can work around, this
comment|/// predefines buffer may contain additional definitions.
name|std
operator|::
name|string
name|SuggestedPredefines
expr_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|bool
operator|>
name|BodySource
expr_stmt|;
comment|/// \brief Reads a statement from the specified cursor.
name|Stmt
modifier|*
name|ReadStmtFromStream
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|)
function_decl|;
struct|struct
name|InputFileInfo
block|{
name|std
operator|::
name|string
name|Filename
expr_stmt|;
name|off_t
name|StoredSize
decl_stmt|;
name|time_t
name|StoredTime
decl_stmt|;
name|bool
name|Overridden
decl_stmt|;
name|bool
name|Transient
decl_stmt|;
block|}
struct|;
comment|/// \brief Reads the stored information about an input file.
name|InputFileInfo
name|readInputFileInfo
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the file entry and 'overridden' bit for an input
comment|/// file in the given module file.
name|serialization
operator|::
name|InputFile
name|getInputFile
argument_list|(
argument|ModuleFile&F
argument_list|,
argument|unsigned ID
argument_list|,
argument|bool Complain = true
argument_list|)
expr_stmt|;
name|public
label|:
name|void
name|ResolveImportedPath
argument_list|(
name|ModuleFile
operator|&
name|M
argument_list|,
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
decl_stmt|;
specifier|static
name|void
name|ResolveImportedPath
argument_list|(
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|StringRef
name|Prefix
argument_list|)
decl_stmt|;
comment|/// \brief Returns the first key declaration for the given declaration. This
comment|/// is one that is formerly-canonical (or still canonical) and whose module
comment|/// did not import any other key declaration of the entity.
name|Decl
modifier|*
name|getKeyDeclaration
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|D
operator|=
name|D
operator|->
name|getCanonicalDecl
argument_list|()
expr_stmt|;
if|if
condition|(
name|D
operator|->
name|isFromASTFile
argument_list|()
condition|)
return|return
name|D
return|;
name|auto
name|I
init|=
name|KeyDecls
operator|.
name|find
argument_list|(
name|D
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|KeyDecls
operator|.
name|end
argument_list|()
operator|||
name|I
operator|->
name|second
operator|.
name|empty
argument_list|()
condition|)
return|return
name|D
return|;
return|return
name|GetExistingDecl
argument_list|(
name|I
operator|->
name|second
index|[
literal|0
index|]
argument_list|)
return|;
block|}
specifier|const
name|Decl
modifier|*
name|getKeyDeclaration
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|getKeyDeclaration
argument_list|(
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|D
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Run a callback on each imported key declaration of \p D.
name|template
operator|<
name|typename
name|Fn
operator|>
name|void
name|forEachImportedKeyDecl
argument_list|(
argument|const Decl *D
argument_list|,
argument|Fn Visit
argument_list|)
block|{
name|D
operator|=
name|D
operator|->
name|getCanonicalDecl
argument_list|()
block|;
if|if
condition|(
name|D
operator|->
name|isFromASTFile
argument_list|()
condition|)
name|Visit
argument_list|(
name|D
argument_list|)
expr_stmt|;
name|auto
name|It
operator|=
name|KeyDecls
operator|.
name|find
argument_list|(
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|D
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|It
operator|!=
name|KeyDecls
operator|.
name|end
argument_list|()
condition|)
for|for
control|(
name|auto
name|ID
range|:
name|It
operator|->
name|second
control|)
name|Visit
argument_list|(
name|GetExistingDecl
argument_list|(
name|ID
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Get the loaded lookup tables for \p Primary, if any.
specifier|const
name|serialization
operator|::
name|reader
operator|::
name|DeclContextLookupTable
operator|*
name|getLoadedLookupTables
argument_list|(
argument|DeclContext *Primary
argument_list|)
specifier|const
expr_stmt|;
name|private
label|:
struct|struct
name|ImportedModule
block|{
name|ModuleFile
modifier|*
name|Mod
decl_stmt|;
name|ModuleFile
modifier|*
name|ImportedBy
decl_stmt|;
name|SourceLocation
name|ImportLoc
decl_stmt|;
name|ImportedModule
argument_list|(
argument|ModuleFile *Mod
argument_list|,
argument|ModuleFile *ImportedBy
argument_list|,
argument|SourceLocation ImportLoc
argument_list|)
block|:
name|Mod
argument_list|(
name|Mod
argument_list|)
operator|,
name|ImportedBy
argument_list|(
name|ImportedBy
argument_list|)
operator|,
name|ImportLoc
argument_list|(
argument|ImportLoc
argument_list|)
block|{ }
block|}
struct|;
name|ASTReadResult
name|ReadASTCore
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|ModuleKind
name|Type
argument_list|,
name|SourceLocation
name|ImportLoc
argument_list|,
name|ModuleFile
operator|*
name|ImportedBy
argument_list|,
name|SmallVectorImpl
operator|<
name|ImportedModule
operator|>
operator|&
name|Loaded
argument_list|,
name|off_t
name|ExpectedSize
argument_list|,
name|time_t
name|ExpectedModTime
argument_list|,
name|ASTFileSignature
name|ExpectedSignature
argument_list|,
name|unsigned
name|ClientLoadCapabilities
argument_list|)
decl_stmt|;
name|ASTReadResult
name|ReadControlBlock
argument_list|(
name|ModuleFile
operator|&
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|ImportedModule
operator|>
operator|&
name|Loaded
argument_list|,
specifier|const
name|ModuleFile
operator|*
name|ImportedBy
argument_list|,
name|unsigned
name|ClientLoadCapabilities
argument_list|)
decl_stmt|;
specifier|static
name|ASTReadResult
name|ReadOptionsBlock
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Stream
argument_list|,
name|unsigned
name|ClientLoadCapabilities
argument_list|,
name|bool
name|AllowCompatibleConfigurationMismatch
argument_list|,
name|ASTReaderListener
operator|&
name|Listener
argument_list|,
name|std
operator|::
name|string
operator|&
name|SuggestedPredefines
argument_list|)
decl_stmt|;
comment|/// Read the unhashed control block.
comment|///
comment|/// This has no effect on \c F.Stream, instead creating a fresh cursor from
comment|/// \c F.Data and reading ahead.
name|ASTReadResult
name|readUnhashedControlBlock
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|bool
name|WasImportedBy
parameter_list|,
name|unsigned
name|ClientLoadCapabilities
parameter_list|)
function_decl|;
specifier|static
name|ASTReadResult
name|readUnhashedControlBlockImpl
argument_list|(
name|ModuleFile
operator|*
name|F
argument_list|,
name|llvm
operator|::
name|StringRef
name|StreamData
argument_list|,
name|unsigned
name|ClientLoadCapabilities
argument_list|,
name|bool
name|AllowCompatibleConfigurationMismatch
argument_list|,
name|ASTReaderListener
operator|*
name|Listener
argument_list|,
name|bool
name|ValidateDiagnosticOptions
argument_list|)
decl_stmt|;
name|ASTReadResult
name|ReadASTBlock
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|unsigned
name|ClientLoadCapabilities
parameter_list|)
function_decl|;
name|ASTReadResult
name|ReadExtensionBlock
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|)
function_decl|;
name|void
name|ReadModuleOffsetMap
argument_list|(
name|ModuleFile
operator|&
name|F
argument_list|)
decl|const
decl_stmt|;
name|bool
name|ParseLineTable
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|)
function_decl|;
name|bool
name|ReadSourceManagerBlock
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|)
function_decl|;
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|SLocCursorForID
argument_list|(
argument|int ID
argument_list|)
expr_stmt|;
name|SourceLocation
name|getImportLocation
parameter_list|(
name|ModuleFile
modifier|*
name|F
parameter_list|)
function_decl|;
name|ASTReadResult
name|ReadModuleMapFileBlock
parameter_list|(
name|RecordData
modifier|&
name|Record
parameter_list|,
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|ModuleFile
modifier|*
name|ImportedBy
parameter_list|,
name|unsigned
name|ClientLoadCapabilities
parameter_list|)
function_decl|;
name|ASTReadResult
name|ReadSubmoduleBlock
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|unsigned
name|ClientLoadCapabilities
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ParseLanguageOptions
parameter_list|(
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|ASTReaderListener
modifier|&
name|Listener
parameter_list|,
name|bool
name|AllowCompatibleDifferences
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ParseTargetOptions
parameter_list|(
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|ASTReaderListener
modifier|&
name|Listener
parameter_list|,
name|bool
name|AllowCompatibleDifferences
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ParseDiagnosticOptions
parameter_list|(
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|ASTReaderListener
modifier|&
name|Listener
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ParseFileSystemOptions
parameter_list|(
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|ASTReaderListener
modifier|&
name|Listener
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ParseHeaderSearchOptions
parameter_list|(
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|bool
name|Complain
parameter_list|,
name|ASTReaderListener
modifier|&
name|Listener
parameter_list|)
function_decl|;
specifier|static
name|bool
name|ParsePreprocessorOptions
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|bool
name|Complain
argument_list|,
name|ASTReaderListener
operator|&
name|Listener
argument_list|,
name|std
operator|::
name|string
operator|&
name|SuggestedPredefines
argument_list|)
decl_stmt|;
struct|struct
name|RecordLocation
block|{
name|RecordLocation
argument_list|(
argument|ModuleFile *M
argument_list|,
argument|uint64_t O
argument_list|)
block|:
name|F
argument_list|(
name|M
argument_list|)
operator|,
name|Offset
argument_list|(
argument|O
argument_list|)
block|{}
name|ModuleFile
operator|*
name|F
expr_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
block|}
struct|;
name|QualType
name|readTypeRecord
parameter_list|(
name|unsigned
name|Index
parameter_list|)
function_decl|;
name|void
name|readExceptionSpec
argument_list|(
name|ModuleFile
operator|&
name|ModuleFile
argument_list|,
name|SmallVectorImpl
operator|<
name|QualType
operator|>
operator|&
name|ExceptionStorage
argument_list|,
name|FunctionProtoType
operator|::
name|ExceptionSpecInfo
operator|&
name|ESI
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Index
argument_list|)
decl_stmt|;
name|RecordLocation
name|TypeCursorForIndex
parameter_list|(
name|unsigned
name|Index
parameter_list|)
function_decl|;
name|void
name|LoadedDecl
parameter_list|(
name|unsigned
name|Index
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|Decl
modifier|*
name|ReadDeclRecord
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
name|void
name|markIncompleteDeclChain
parameter_list|(
name|Decl
modifier|*
name|Canon
parameter_list|)
function_decl|;
comment|/// \brief Returns the most recent declaration of a declaration (which must be
comment|/// of a redeclarable kind) that is either local or has already been loaded
comment|/// merged into its redecl chain.
name|Decl
modifier|*
name|getMostRecentExistingDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|RecordLocation
name|DeclCursorForID
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|,
name|SourceLocation
operator|&
name|Location
argument_list|)
decl_stmt|;
name|void
name|loadDeclUpdateRecords
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|,
name|Decl
operator|*
name|D
argument_list|)
decl_stmt|;
name|void
name|loadPendingDeclChain
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|uint64_t
name|LocalOffset
parameter_list|)
function_decl|;
name|void
name|loadObjCCategories
argument_list|(
name|serialization
operator|::
name|GlobalDeclID
name|ID
argument_list|,
name|ObjCInterfaceDecl
operator|*
name|D
argument_list|,
name|unsigned
name|PreviousGeneration
operator|=
literal|0
argument_list|)
decl_stmt|;
name|RecordLocation
name|getLocalBitOffset
parameter_list|(
name|uint64_t
name|GlobalOffset
parameter_list|)
function_decl|;
name|uint64_t
name|getGlobalBitOffset
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
name|uint32_t
name|LocalOffset
parameter_list|)
function_decl|;
comment|/// \brief Returns the first preprocessed entity ID that begins or ends after
comment|/// \arg Loc.
name|serialization
operator|::
name|PreprocessedEntityID
name|findPreprocessedEntity
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|bool EndsAfter
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Find the next module that contains entities and return the ID
comment|/// of the first entry.
comment|///
comment|/// \param SLocMapI points at a chunk of a module that contains no
comment|/// preprocessed entities or the entities it contains are not the
comment|/// ones we are looking for.
name|serialization
operator|::
name|PreprocessedEntityID
name|findNextPreprocessedEntity
argument_list|(
argument|GlobalSLocOffsetMapType::const_iterator SLocMapI
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Returns (ModuleFile, Local index) pair for \p GlobalIndex of a
comment|/// preprocessed entity.
name|std
operator|::
name|pair
operator|<
name|ModuleFile
operator|*
operator|,
name|unsigned
operator|>
name|getModulePreprocessedEntity
argument_list|(
argument|unsigned GlobalIndex
argument_list|)
expr_stmt|;
comment|/// \brief Returns (begin, end) pair for the preprocessed entities of a
comment|/// particular module.
name|llvm
operator|::
name|iterator_range
operator|<
name|PreprocessingRecord
operator|::
name|iterator
operator|>
name|getModulePreprocessedEntities
argument_list|(
argument|ModuleFile&Mod
argument_list|)
specifier|const
expr_stmt|;
name|public
label|:
name|class
name|ModuleDeclIterator
range|:
name|public
name|llvm
operator|::
name|iterator_adaptor_base
operator|<
name|ModuleDeclIterator
decl_stmt|, const
name|serialization
decl|::
name|LocalDeclID
modifier|*
decl_stmt|,
name|std
decl|::
name|random_access_iterator_tag
decl_stmt|, const
name|Decl
modifier|*
decl_stmt|,
name|ptrdiff_t
decl_stmt|,             const
name|Decl
modifier|*
decl_stmt|, const
name|Decl
modifier|*
decl|>
block|{
name|ASTReader
modifier|*
name|Reader
decl_stmt|;
name|ModuleFile
modifier|*
name|Mod
decl_stmt|;
name|public
label|:
name|ModuleDeclIterator
argument_list|()
operator|:
name|iterator_adaptor_base
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Reader
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Mod
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|ModuleDeclIterator
argument_list|(
name|ASTReader
operator|*
name|Reader
argument_list|,
name|ModuleFile
operator|*
name|Mod
argument_list|,
specifier|const
name|serialization
operator|::
name|LocalDeclID
operator|*
name|Pos
argument_list|)
operator|:
name|iterator_adaptor_base
argument_list|(
name|Pos
argument_list|)
operator|,
name|Reader
argument_list|(
name|Reader
argument_list|)
operator|,
name|Mod
argument_list|(
argument|Mod
argument_list|)
block|{}
name|value_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Reader
operator|->
name|GetDecl
argument_list|(
name|Reader
operator|->
name|getGlobalDeclID
argument_list|(
operator|*
name|Mod
argument_list|,
operator|*
name|I
argument_list|)
argument_list|)
return|;
block|}
name|value_type
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|*
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ModuleDeclIterator
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Reader
operator|==
name|RHS
operator|.
name|Reader
operator|&&
name|Mod
operator|==
name|RHS
operator|.
name|Mod
argument_list|)
block|;
return|return
name|I
operator|==
name|RHS
operator|.
name|I
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|llvm
operator|::
name|iterator_range
operator|<
name|ModuleDeclIterator
operator|>
name|getModuleFileLevelDecls
argument_list|(
name|ModuleFile
operator|&
name|Mod
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|PassInterestingDeclsToConsumer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PassInterestingDeclToConsumer
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|finishPendingActions
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|diagnoseOdrViolations
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pushExternalDeclIntoScope
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|addPendingDeclContextInfo
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|serialization
operator|::
name|GlobalDeclID
name|SemaDC
argument_list|,
name|serialization
operator|::
name|GlobalDeclID
name|LexicalDC
argument_list|)
block|{
name|assert
argument_list|(
name|D
argument_list|)
expr_stmt|;
name|PendingDeclContextInfo
name|Info
init|=
block|{
name|D
block|,
name|SemaDC
block|,
name|LexicalDC
block|}
decl_stmt|;
name|PendingDeclContextInfos
operator|.
name|push_back
argument_list|(
name|Info
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Produce an error diagnostic and return true.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine should only be used for fatal errors that have to
end_comment

begin_comment
comment|/// do with non-routine failures (e.g., corrupted AST file).
end_comment

begin_decl_stmt
name|void
name|Error
argument_list|(
name|StringRef
name|Msg
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|Error
parameter_list|(
name|unsigned
name|DiagID
parameter_list|,
name|StringRef
name|Arg1
init|=
name|StringRef
argument_list|()
parameter_list|,
name|StringRef
name|Arg2
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|const;
end_function_decl

begin_expr_stmt
name|ASTReader
argument_list|(
specifier|const
name|ASTReader
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|ASTReader
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Load the AST file and validate its contents against the given
end_comment

begin_comment
comment|/// Preprocessor.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PP the preprocessor associated with the context in which this
end_comment

begin_comment
comment|/// precompiled header will be loaded.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Context the AST context that this precompiled header will be
end_comment

begin_comment
comment|/// loaded into.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param PCHContainerRdr the PCHContainerOperations to use for loading and
end_comment

begin_comment
comment|/// creating modules.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Extensions the list of module file extensions that can be loaded
end_comment

begin_comment
comment|/// from the AST files.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param isysroot If non-NULL, the system include path specified by the
end_comment

begin_comment
comment|/// user. This is only used with relocatable PCH files. If non-NULL,
end_comment

begin_comment
comment|/// a relocatable PCH file will use the default path "/".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DisableValidation If true, the AST reader will suppress most
end_comment

begin_comment
comment|/// of its regular consistency checking, allowing the use of precompiled
end_comment

begin_comment
comment|/// headers that cannot be determined to be compatible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AllowASTWithCompilerErrors If true, the AST reader will accept an
end_comment

begin_comment
comment|/// AST file the was created out of an AST with compiler errors,
end_comment

begin_comment
comment|/// otherwise it will reject it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AllowConfigurationMismatch If true, the AST reader will not check
end_comment

begin_comment
comment|/// for configuration differences between the AST file and the invocation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ValidateSystemInputs If true, the AST reader will validate
end_comment

begin_comment
comment|/// system input files in addition to user input files. This is only
end_comment

begin_comment
comment|/// meaningful if \p DisableValidation is false.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param UseGlobalIndex If true, the AST reader will try to load and use
end_comment

begin_comment
comment|/// the global module index.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ReadTimer If non-null, a timer used to track the time spent
end_comment

begin_comment
comment|/// deserializing.
end_comment

begin_macro
name|ASTReader
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|ASTContext&Context
argument_list|,
argument|const PCHContainerReader&PCHContainerRdr
argument_list|,
argument|ArrayRef<std::shared_ptr<ModuleFileExtension>> Extensions
argument_list|,
argument|StringRef isysroot =
literal|""
argument_list|,
argument|bool DisableValidation = false
argument_list|,
argument|bool AllowASTWithCompilerErrors = false
argument_list|,
argument|bool AllowConfigurationMismatch = false
argument_list|,
argument|bool ValidateSystemInputs = false
argument_list|,
argument|bool UseGlobalIndex = true
argument_list|,
argument|std::unique_ptr<llvm::Timer> ReadTimer = {}
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|ASTReader
argument_list|()
name|override
expr_stmt|;
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
name|DiagnosticsEngine
operator|&
name|getDiags
argument_list|()
specifier|const
block|{
return|return
name|Diags
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Flags that indicate what kind of AST loading failures the client
end_comment

begin_comment
comment|/// of the AST reader can directly handle.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When a client states that it can handle a particular kind of failure,
end_comment

begin_comment
comment|/// the AST reader will not emit errors when producing that kind of failure.
end_comment

begin_enum
enum|enum
name|LoadFailureCapabilities
block|{
comment|/// \brief The client can't handle any AST loading failures.
name|ARR_None
init|=
literal|0
block|,
comment|/// \brief The client can handle an AST file that cannot load because it
comment|/// is missing.
name|ARR_Missing
init|=
literal|0x1
block|,
comment|/// \brief The client can handle an AST file that cannot load because it
comment|/// is out-of-date relative to its input files.
name|ARR_OutOfDate
init|=
literal|0x2
block|,
comment|/// \brief The client can handle an AST file that cannot load because it
comment|/// was built with a different version of Clang.
name|ARR_VersionMismatch
init|=
literal|0x4
block|,
comment|/// \brief The client can handle an AST file that cannot load because it's
comment|/// compiled configuration doesn't match that of the context it was
comment|/// loaded into.
name|ARR_ConfigurationMismatch
init|=
literal|0x8
block|}
enum|;
end_enum

begin_comment
comment|/// \brief Load the AST file designated by the given file name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param FileName The name of the AST file to load.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Type The kind of AST being loaded, e.g., PCH, module, main file,
end_comment

begin_comment
comment|/// or preamble.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ImportLoc the location where the module file will be considered as
end_comment

begin_comment
comment|/// imported from. For non-module AST types it should be invalid.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ClientLoadCapabilities The set of client load-failure
end_comment

begin_comment
comment|/// capabilities, represented as a bitset of the enumerators of
end_comment

begin_comment
comment|/// LoadFailureCapabilities.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Imported optional out-parameter to append the list of modules
end_comment

begin_comment
comment|/// that were imported by precompiled headers or any other non-module AST file
end_comment

begin_decl_stmt
name|ASTReadResult
name|ReadAST
argument_list|(
name|StringRef
name|FileName
argument_list|,
name|ModuleKind
name|Type
argument_list|,
name|SourceLocation
name|ImportLoc
argument_list|,
name|unsigned
name|ClientLoadCapabilities
argument_list|,
name|SmallVectorImpl
operator|<
name|ImportedSubmodule
operator|>
operator|*
name|Imported
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Make the entities in the given module and any of its (non-explicit)
end_comment

begin_comment
comment|/// submodules visible to name lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Mod The module whose names should be made visible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NameVisibility The level of visibility to give the names in the
end_comment

begin_comment
comment|/// module.  Visibility can only be increased over time.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ImportLoc The location at which the import occurs.
end_comment

begin_decl_stmt
name|void
name|makeModuleVisible
argument_list|(
name|Module
operator|*
name|Mod
argument_list|,
name|Module
operator|::
name|NameVisibilityKind
name|NameVisibility
argument_list|,
name|SourceLocation
name|ImportLoc
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Make the names within this set of hidden names visible.
end_comment

begin_function_decl
name|void
name|makeNamesVisible
parameter_list|(
specifier|const
name|HiddenNames
modifier|&
name|Names
parameter_list|,
name|Module
modifier|*
name|Owner
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Note that MergedDef is a redefinition of the canonical definition
end_comment

begin_comment
comment|/// Def, so Def should be visible whenever MergedDef is.
end_comment

begin_function_decl
name|void
name|mergeDefinitionVisibility
parameter_list|(
name|NamedDecl
modifier|*
name|Def
parameter_list|,
name|NamedDecl
modifier|*
name|MergedDef
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Take the AST callbacks listener.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|takeListener
argument_list|()
block|{
return|return
name|std
operator|::
name|move
argument_list|(
name|Listener
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the AST callbacks listener.
end_comment

begin_decl_stmt
name|void
name|setListener
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|Listener
argument_list|)
block|{
name|this
operator|->
name|Listener
operator|=
name|std
operator|::
name|move
argument_list|(
name|Listener
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Add an AST callback listener.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Takes ownership of \p L.
end_comment

begin_decl_stmt
name|void
name|addListener
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|L
argument_list|)
block|{
if|if
condition|(
name|Listener
condition|)
name|L
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|ChainedASTReaderListener
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|L
argument_list|)
operator|,
name|std
operator|::
name|move
argument_list|(
name|Listener
argument_list|)
operator|)
expr_stmt|;
name|Listener
operator|=
name|std
operator|::
name|move
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// RAII object to temporarily add an AST callback listener.
end_comment

begin_decl_stmt
name|class
name|ListenerScope
block|{
name|ASTReader
modifier|&
name|Reader
decl_stmt|;
name|bool
name|Chained
decl_stmt|;
name|public
label|:
name|ListenerScope
argument_list|(
name|ASTReader
operator|&
name|Reader
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|ASTReaderListener
operator|>
name|L
argument_list|)
operator|:
name|Reader
argument_list|(
name|Reader
argument_list|)
operator|,
name|Chained
argument_list|(
argument|false
argument_list|)
block|{
name|auto
name|Old
operator|=
name|Reader
operator|.
name|takeListener
argument_list|()
block|;
if|if
condition|(
name|Old
condition|)
block|{
name|Chained
operator|=
name|true
expr_stmt|;
name|L
operator|=
name|llvm
operator|::
name|make_unique
operator|<
name|ChainedASTReaderListener
operator|>
operator|(
name|std
operator|::
name|move
argument_list|(
name|L
argument_list|)
operator|,
name|std
operator|::
name|move
argument_list|(
name|Old
argument_list|)
operator|)
expr_stmt|;
block|}
name|Reader
operator|.
name|setListener
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|L
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|~
name|ListenerScope
argument_list|()
block|{
name|auto
name|New
operator|=
name|Reader
operator|.
name|takeListener
argument_list|()
block|;
if|if
condition|(
name|Chained
condition|)
name|Reader
operator|.
name|setListener
argument_list|(
name|static_cast
operator|<
name|ChainedASTReaderListener
operator|*
operator|>
operator|(
name|New
operator|.
name|get
argument_list|()
operator|)
operator|->
name|takeSecond
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Set the AST deserialization listener.
end_comment

begin_function_decl
name|void
name|setDeserializationListener
parameter_list|(
name|ASTDeserializationListener
modifier|*
name|Listener
parameter_list|,
name|bool
name|TakeOwnership
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether this AST reader has a global index.
end_comment

begin_expr_stmt
name|bool
name|hasGlobalIndex
argument_list|()
specifier|const
block|{
return|return
operator|(
name|bool
operator|)
name|GlobalIndex
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return global module index.
end_comment

begin_function
name|GlobalModuleIndex
modifier|*
name|getGlobalIndex
parameter_list|()
block|{
return|return
name|GlobalIndex
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Reset reader for a reload try.
end_comment

begin_function
name|void
name|resetForReload
parameter_list|()
block|{
name|TriedLoadingGlobalIndex
operator|=
name|false
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Attempts to load the global index.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if loading the global index has failed for any reason.
end_comment

begin_function_decl
name|bool
name|loadGlobalIndex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether we tried to load the global index, but failed,
end_comment

begin_comment
comment|/// e.g., because it is out-of-date or does not exist.
end_comment

begin_expr_stmt
name|bool
name|isGlobalIndexUnavailable
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Initializes the ASTContext
end_comment

begin_function_decl
name|void
name|InitializeContext
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Update the state of Sema after loading some additional modules.
end_comment

begin_function_decl
name|void
name|UpdateSema
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Add in-memory (virtual file) buffer.
end_comment

begin_decl_stmt
name|void
name|addInMemoryBuffer
argument_list|(
name|StringRef
operator|&
name|FileName
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
argument_list|)
block|{
name|ModuleMgr
operator|.
name|addInMemoryBuffer
argument_list|(
name|FileName
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Buffer
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Finalizes the AST reader's state before writing an AST file to
end_comment

begin_comment
comment|/// disk.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operation may undo temporary state in the AST that should not be
end_comment

begin_comment
comment|/// emitted.
end_comment

begin_function_decl
name|void
name|finalizeForWriting
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the module manager.
end_comment

begin_function
name|ModuleManager
modifier|&
name|getModuleManager
parameter_list|()
block|{
return|return
name|ModuleMgr
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the preprocessor.
end_comment

begin_expr_stmt
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
return|return
name|PP
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the name of the original source file name for the primary
end_comment

begin_comment
comment|/// module file.
end_comment

begin_function
name|StringRef
name|getOriginalSourceFile
parameter_list|()
block|{
return|return
name|ModuleMgr
operator|.
name|getPrimaryModule
argument_list|()
operator|.
name|OriginalSourceFileName
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the name of the original source file name directly from
end_comment

begin_comment
comment|/// the AST file, without actually loading the AST file.
end_comment

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|getOriginalSourceFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ASTFileName
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
specifier|const
name|PCHContainerReader
operator|&
name|PCHContainerRdr
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read the control block for the named AST file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function_decl
specifier|static
name|bool
name|readASTFileControlBlock
parameter_list|(
name|StringRef
name|Filename
parameter_list|,
name|FileManager
modifier|&
name|FileMgr
parameter_list|,
specifier|const
name|PCHContainerReader
modifier|&
name|PCHContainerRdr
parameter_list|,
name|bool
name|FindModuleFileExtensions
parameter_list|,
name|ASTReaderListener
modifier|&
name|Listener
parameter_list|,
name|bool
name|ValidateDiagnosticOptions
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether the given AST file is acceptable to load into a
end_comment

begin_comment
comment|/// translation unit with the given language and target options.
end_comment

begin_function_decl
specifier|static
name|bool
name|isAcceptableASTFile
parameter_list|(
name|StringRef
name|Filename
parameter_list|,
name|FileManager
modifier|&
name|FileMgr
parameter_list|,
specifier|const
name|PCHContainerReader
modifier|&
name|PCHContainerRdr
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|,
specifier|const
name|TargetOptions
modifier|&
name|TargetOpts
parameter_list|,
specifier|const
name|PreprocessorOptions
modifier|&
name|PPOpts
parameter_list|,
name|StringRef
name|ExistingModuleCachePath
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns the suggested contents of the predefines buffer,
end_comment

begin_comment
comment|/// which contains a (typically-empty) subset of the predefines
end_comment

begin_comment
comment|/// build prior to including the precompiled header.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|string
operator|&
name|getSuggestedPredefines
argument_list|()
block|{
return|return
name|SuggestedPredefines
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Read a preallocated preprocessed entity from the external source.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns null if an error occurred that prevented the preprocessed
end_comment

begin_comment
comment|/// entity from being loaded.
end_comment

begin_decl_stmt
name|PreprocessedEntity
modifier|*
name|ReadPreprocessedEntity
argument_list|(
name|unsigned
name|Index
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns a pair of [Begin, End) indices of preallocated
end_comment

begin_comment
comment|/// preprocessed entities that \p Range encompasses.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|findPreprocessedEntitiesInRange
argument_list|(
argument|SourceRange Range
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Optionally returns true or false if the preallocated preprocessed
end_comment

begin_comment
comment|/// entity with index \p Index came from file \p FID.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|bool
operator|>
name|isPreprocessedEntityInFileID
argument_list|(
argument|unsigned Index
argument_list|,
argument|FileID FID
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read the header file information for the given file entry.
end_comment

begin_decl_stmt
name|HeaderFileInfo
name|GetHeaderFileInfo
argument_list|(
specifier|const
name|FileEntry
operator|*
name|FE
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ReadPragmaDiagnosticMappings
parameter_list|(
name|DiagnosticsEngine
modifier|&
name|Diag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns the number of source locations found in the chain.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumSLocs
argument_list|()
specifier|const
block|{
return|return
name|TotalNumSLocEntries
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the number of identifiers found in the chain.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumIdentifiers
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|IdentifiersLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the number of macros found in the chain.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumMacros
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|MacrosLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the number of types found in the chain.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumTypes
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|TypesLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the number of declarations found in the chain.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumDecls
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|DeclsLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the number of submodules known.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumSubmodules
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|SubmodulesLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the number of selectors found in the chain.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumSelectors
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|SelectorsLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the number of preprocessed entities known to the AST
end_comment

begin_comment
comment|/// reader.
end_comment

begin_expr_stmt
name|unsigned
name|getTotalNumPreprocessedEntities
argument_list|()
specifier|const
block|{
name|unsigned
name|Result
operator|=
literal|0
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|M
range|:
name|ModuleMgr
control|)
name|Result
operator|+=
name|M
operator|.
name|NumPreprocessedEntities
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Result
return|;
end_return

begin_comment
unit|}
comment|/// \brief Reads a TemplateArgumentLocInfo appropriate for the
end_comment

begin_comment
comment|/// given TemplateArgument kind.
end_comment

begin_macro
unit|TemplateArgumentLocInfo
name|GetTemplateArgumentLocInfo
argument_list|(
argument|ModuleFile&F
argument_list|,
argument|TemplateArgument::ArgKind Kind
argument_list|,
argument|const RecordData&Record
argument_list|,
argument|unsigned&Idx
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Reads a TemplateArgumentLoc.
end_comment

begin_function_decl
name|TemplateArgumentLoc
name|ReadTemplateArgumentLoc
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|ASTTemplateArgumentListInfo
modifier|*
name|ReadASTTemplateArgumentListInfo
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Reads a declarator info from the given record.
end_comment

begin_function_decl
name|TypeSourceInfo
modifier|*
name|GetTypeSourceInfo
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Resolve a type ID into a type, potentially building a new
end_comment

begin_comment
comment|/// type.
end_comment

begin_decl_stmt
name|QualType
name|GetType
argument_list|(
name|serialization
operator|::
name|TypeID
name|ID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Resolve a local type ID within a given AST file into a type.
end_comment

begin_function_decl
name|QualType
name|getLocalType
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|unsigned
name|LocalID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Map a local type ID within a given AST file into a global type ID.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|TypeID
name|getGlobalTypeID
argument_list|(
argument|ModuleFile&F
argument_list|,
argument|unsigned LocalID
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read a type from the current position in the given record, which
end_comment

begin_comment
comment|/// was read from the given AST file.
end_comment

begin_function
name|QualType
name|readType
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
if|if
condition|(
name|Idx
operator|>=
name|Record
operator|.
name|size
argument_list|()
condition|)
return|return
name|QualType
argument_list|()
return|;
return|return
name|getLocalType
argument_list|(
name|F
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Map from a local declaration ID within a given module to a
end_comment

begin_comment
comment|/// global declaration ID.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|DeclID
name|getGlobalDeclID
argument_list|(
argument|ModuleFile&F
argument_list|,
argument|serialization::LocalDeclID LocalID
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns true if global DeclID \p ID originated from module \p M.
end_comment

begin_decl_stmt
name|bool
name|isDeclIDFromModule
argument_list|(
name|serialization
operator|::
name|GlobalDeclID
name|ID
argument_list|,
name|ModuleFile
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the module file that owns the given declaration, or NULL
end_comment

begin_comment
comment|/// if the declaration is not from a module file.
end_comment

begin_function_decl
name|ModuleFile
modifier|*
name|getOwningModuleFile
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get the best name we know for the module that owns the given
end_comment

begin_comment
comment|/// declaration, or an empty string if the declaration is not from a module.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getOwningModuleNameForDiagnostic
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Returns the source location for the decl \p ID.
end_comment

begin_decl_stmt
name|SourceLocation
name|getSourceLocationForDeclID
argument_list|(
name|serialization
operator|::
name|GlobalDeclID
name|ID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Resolve a declaration ID into a declaration, potentially
end_comment

begin_comment
comment|/// building a new declaration.
end_comment

begin_decl_stmt
name|Decl
modifier|*
name|GetDecl
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Decl
modifier|*
name|GetExternalDecl
argument_list|(
name|uint32_t
name|ID
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Resolve a declaration ID into a declaration. Return 0 if it's not
end_comment

begin_comment
comment|/// been loaded yet.
end_comment

begin_decl_stmt
name|Decl
modifier|*
name|GetExistingDecl
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Reads a declaration with the given local ID in the given module.
end_comment

begin_function
name|Decl
modifier|*
name|GetLocalDecl
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|uint32_t
name|LocalID
parameter_list|)
block|{
return|return
name|GetDecl
argument_list|(
name|getGlobalDeclID
argument_list|(
name|F
argument_list|,
name|LocalID
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Reads a declaration with the given local ID in the given module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The requested declaration, casted to the given return type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|GetLocalDeclAs
argument_list|(
argument|ModuleFile&F
argument_list|,
argument|uint32_t LocalID
argument_list|)
block|{
return|return
name|cast_or_null
operator|<
name|T
operator|>
operator|(
name|GetLocalDecl
argument_list|(
name|F
argument_list|,
name|LocalID
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Map a global declaration ID into the declaration ID used to
end_comment

begin_comment
comment|/// refer to this declaration within the given module fule.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the global ID of the given declaration as known in the given
end_comment

begin_comment
comment|/// module file.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|DeclID
name|mapGlobalIDToModuleFileGlobalID
argument_list|(
argument|ModuleFile&M
argument_list|,
argument|serialization::DeclID GlobalID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Reads a declaration ID from the given position in a record in the
end_comment

begin_comment
comment|/// given module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The declaration ID read from the record, adjusted to a global ID.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|DeclID
name|ReadDeclID
argument_list|(
name|ModuleFile
operator|&
name|F
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Reads a declaration from the given position in a record in the
end_comment

begin_comment
comment|/// given module.
end_comment

begin_function
name|Decl
modifier|*
name|ReadDecl
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|R
parameter_list|,
name|unsigned
modifier|&
name|I
parameter_list|)
block|{
return|return
name|GetDecl
argument_list|(
name|ReadDeclID
argument_list|(
name|F
argument_list|,
name|R
argument_list|,
name|I
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Reads a declaration from the given position in a record in the
end_comment

begin_comment
comment|/// given module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns The declaration read from this location, casted to the given
end_comment

begin_comment
comment|/// result type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|ReadDeclAs
argument_list|(
argument|ModuleFile&F
argument_list|,
argument|const RecordData&R
argument_list|,
argument|unsigned&I
argument_list|)
block|{
return|return
name|cast_or_null
operator|<
name|T
operator|>
operator|(
name|GetDecl
argument_list|(
name|ReadDeclID
argument_list|(
name|F
argument_list|,
name|R
argument_list|,
name|I
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief If any redeclarations of \p D have been imported since it was
end_comment

begin_comment
comment|/// last checked, this digs out those redeclarations and adds them to the
end_comment

begin_comment
comment|/// redeclaration chain for \p D.
end_comment

begin_decl_stmt
name|void
name|CompleteRedeclChain
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CXXBaseSpecifier
modifier|*
name|GetExternalCXXBaseSpecifiers
argument_list|(
name|uint64_t
name|Offset
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Resolve the offset of a statement into a statement.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operation will read a new statement from the external
end_comment

begin_comment
comment|/// source each time it is called, and is meant to be used via a
end_comment

begin_comment
comment|/// LazyOffsetPtr (which is used by Decls for the body of functions, etc).
end_comment

begin_decl_stmt
name|Stmt
modifier|*
name|GetExternalDeclStmt
argument_list|(
name|uint64_t
name|Offset
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ReadBlockAbbrevs - Enter a subblock of the specified BlockID with the
end_comment

begin_comment
comment|/// specified cursor.  Read the abbreviations that are at the top of the block
end_comment

begin_comment
comment|/// and then leave the cursor pointing into the block.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|ReadBlockAbbrevs
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|,
name|unsigned
name|BlockID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Finds all the visible declarations with a given name.
end_comment

begin_comment
comment|/// The current implementation of this method just loads the entire
end_comment

begin_comment
comment|/// lookup table as unmaterialized references.
end_comment

begin_decl_stmt
name|bool
name|FindExternalVisibleDeclsByName
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
name|DeclarationName
name|Name
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Read all of the declarations lexically stored in a
end_comment

begin_comment
comment|/// declaration context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param DC The declaration context whose declarations will be
end_comment

begin_comment
comment|/// read.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IsKindWeWant A predicate indicating which declaration kinds
end_comment

begin_comment
comment|/// we are interested in.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Decls Vector that will contain the declarations loaded
end_comment

begin_comment
comment|/// from the external source. The caller is responsible for merging
end_comment

begin_comment
comment|/// these declarations with any declarations already stored in the
end_comment

begin_comment
comment|/// declaration context.
end_comment

begin_decl_stmt
name|void
name|FindExternalLexicalDecls
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|bool
argument_list|(
name|Decl
operator|::
name|Kind
argument_list|)
operator|>
name|IsKindWeWant
argument_list|,
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get the decls that are contained in a file in the Offset/Length
end_comment

begin_comment
comment|/// range. \p Length can be 0 to indicate a point at \p Offset instead of
end_comment

begin_comment
comment|/// a range.
end_comment

begin_decl_stmt
name|void
name|FindFileRegionDecls
argument_list|(
name|FileID
name|File
argument_list|,
name|unsigned
name|Offset
argument_list|,
name|unsigned
name|Length
argument_list|,
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Notify ASTReader that we started deserialization of
end_comment

begin_comment
comment|/// a decl or type so until FinishedDeserializing is called there may be
end_comment

begin_comment
comment|/// decls that are initializing. Must be paired with FinishedDeserializing.
end_comment

begin_expr_stmt
name|void
name|StartedDeserializing
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Notify ASTReader that we finished the deserialization of
end_comment

begin_comment
comment|/// a decl or type. Must be paired with StartedDeserializing.
end_comment

begin_expr_stmt
name|void
name|FinishedDeserializing
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Function that will be invoked when we begin parsing a new
end_comment

begin_comment
comment|/// translation unit involving this external AST source.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function will provide all of the external definitions to
end_comment

begin_comment
comment|/// the ASTConsumer.
end_comment

begin_decl_stmt
name|void
name|StartTranslationUnit
argument_list|(
name|ASTConsumer
operator|*
name|Consumer
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Print some statistics about AST usage.
end_comment

begin_expr_stmt
name|void
name|PrintStats
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Dump information about the AST reader to standard error.
end_comment

begin_function_decl
name|void
name|dump
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Return the amount of memory used by memory buffers, breaking down
end_comment

begin_comment
comment|/// by heap-backed versus mmap'ed memory.
end_comment

begin_decl_stmt
name|void
name|getMemoryBufferSizes
argument_list|(
name|MemoryBufferSizes
operator|&
name|sizes
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Initialize the semantic source with the Sema instance
end_comment

begin_comment
comment|/// being used to perform semantic analysis on the abstract syntax
end_comment

begin_comment
comment|/// tree.
end_comment

begin_decl_stmt
name|void
name|InitializeSema
argument_list|(
name|Sema
operator|&
name|S
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Inform the semantic consumer that Sema is no longer available.
end_comment

begin_function
name|void
name|ForgetSema
parameter_list|()
function|override
block|{
name|SemaObj
operator|=
name|nullptr
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the IdentifierInfo for the named identifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine builds a new IdentifierInfo for the given identifier. If any
end_comment

begin_comment
comment|/// declarations with this name are visible from translation unit scope, their
end_comment

begin_comment
comment|/// declarations will be deserialized and introduced into the declaration
end_comment

begin_comment
comment|/// chain of the identifier.
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|get
argument_list|(
name|StringRef
name|Name
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve an iterator into the set of all identifiers
end_comment

begin_comment
comment|/// in all loaded AST files.
end_comment

begin_expr_stmt
name|IdentifierIterator
operator|*
name|getIdentifiers
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Load the contents of the global method pool for a given
end_comment

begin_comment
comment|/// selector.
end_comment

begin_decl_stmt
name|void
name|ReadMethodPool
argument_list|(
name|Selector
name|Sel
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Load the contents of the global method pool for a given
end_comment

begin_comment
comment|/// selector if necessary.
end_comment

begin_decl_stmt
name|void
name|updateOutOfDateSelector
argument_list|(
name|Selector
name|Sel
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Load the set of namespaces that are known to the external source,
end_comment

begin_comment
comment|/// which will be used during typo correction.
end_comment

begin_decl_stmt
name|void
name|ReadKnownNamespaces
argument_list|(
name|SmallVectorImpl
operator|<
name|NamespaceDecl
operator|*
operator|>
operator|&
name|Namespaces
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadUndefinedButUsed
argument_list|(
name|llvm
operator|::
name|MapVector
operator|<
name|NamedDecl
operator|*
argument_list|,
name|SourceLocation
operator|>
operator|&
name|Undefined
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadMismatchingDeleteExpressions
argument_list|(
name|llvm
operator|::
name|MapVector
operator|<
name|FieldDecl
operator|*
argument_list|,
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|SourceLocation
argument_list|,
name|bool
operator|>
argument_list|,
literal|4
operator|>>
operator|&
name|Exprs
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadTentativeDefinitions
argument_list|(
name|SmallVectorImpl
operator|<
name|VarDecl
operator|*
operator|>
operator|&
name|TentativeDefs
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadUnusedFileScopedDecls
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|DeclaratorDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadDelegatingConstructors
argument_list|(
name|SmallVectorImpl
operator|<
name|CXXConstructorDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadExtVectorDecls
argument_list|(
name|SmallVectorImpl
operator|<
name|TypedefNameDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadUnusedLocalTypedefNameCandidates
argument_list|(
name|llvm
operator|::
name|SmallSetVector
operator|<
specifier|const
name|TypedefNameDecl
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|Decls
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadReferencedSelectors
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|Selector
argument_list|,
name|SourceLocation
operator|>
expr|>
operator|&
name|Sels
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadWeakUndeclaredIdentifiers
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
argument_list|,
name|WeakInfo
operator|>
expr|>
operator|&
name|WI
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadUsedVTables
argument_list|(
name|SmallVectorImpl
operator|<
name|ExternalVTableUse
operator|>
operator|&
name|VTables
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadPendingInstantiations
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|ValueDecl
operator|*
argument_list|,
name|SourceLocation
operator|>
expr|>
operator|&
name|Pending
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ReadLateParsedTemplates
argument_list|(
name|llvm
operator|::
name|MapVector
operator|<
specifier|const
name|FunctionDecl
operator|*
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|LateParsedTemplate
operator|>>
operator|&
name|LPTMap
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Load a selector from disk, registering its ID if it exists.
end_comment

begin_function_decl
name|void
name|LoadSelector
parameter_list|(
name|Selector
name|Sel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetIdentifierInfo
parameter_list|(
name|unsigned
name|ID
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|SetGloballyVisibleDecls
argument_list|(
name|IdentifierInfo
operator|*
name|II
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|uint32_t
operator|>
operator|&
name|DeclIDs
argument_list|,
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|*
name|Decls
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Report a diagnostic.
end_comment

begin_decl_stmt
name|DiagnosticBuilder
name|Diag
argument_list|(
name|unsigned
name|DiagID
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Report a diagnostic.
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|DecodeIdentifierInfo
argument_list|(
name|serialization
operator|::
name|IdentifierID
name|ID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|IdentifierInfo
modifier|*
name|GetIdentifierInfo
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
return|return
name|DecodeIdentifierInfo
argument_list|(
name|getGlobalIdentifierID
argument_list|(
name|M
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|GetIdentifier
argument_list|(
name|serialization
operator|::
name|IdentifierID
name|ID
argument_list|)
name|override
block|{
comment|// Note that we are loading an identifier.
name|Deserializing
name|AnIdentifier
parameter_list|(
name|this
parameter_list|)
function_decl|;
return|return
name|DecodeIdentifierInfo
argument_list|(
name|ID
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
name|IdentifierInfo
modifier|*
name|getLocalIdentifier
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
name|unsigned
name|LocalID
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|serialization
operator|::
name|IdentifierID
name|getGlobalIdentifierID
argument_list|(
argument|ModuleFile&M
argument_list|,
argument|unsigned LocalID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|resolvePendingMacro
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
specifier|const
name|PendingMacroInfo
modifier|&
name|PMInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the macro with the given ID.
end_comment

begin_decl_stmt
name|MacroInfo
modifier|*
name|getMacro
argument_list|(
name|serialization
operator|::
name|MacroID
name|ID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the global macro ID corresponding to the given local
end_comment

begin_comment
comment|/// ID within the given module file.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|MacroID
name|getGlobalMacroID
argument_list|(
argument|ModuleFile&M
argument_list|,
argument|unsigned LocalID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read the source location entry with index ID.
end_comment

begin_decl_stmt
name|bool
name|ReadSLocEntry
argument_list|(
name|int
name|ID
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the module import location and module name for the
end_comment

begin_comment
comment|/// given source manager entry ID.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|SourceLocation
operator|,
name|StringRef
operator|>
name|getModuleImportLoc
argument_list|(
argument|int ID
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the global submodule ID given a module and its local ID
end_comment

begin_comment
comment|/// number.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|SubmoduleID
name|getGlobalSubmoduleID
argument_list|(
argument|ModuleFile&M
argument_list|,
argument|unsigned LocalID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the submodule that corresponds to a global submodule ID.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|Module
modifier|*
name|getSubmodule
argument_list|(
name|serialization
operator|::
name|SubmoduleID
name|GlobalID
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the module that corresponds to the given module ID.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note: overrides method in ExternalASTSource
end_comment

begin_decl_stmt
name|Module
modifier|*
name|getModule
argument_list|(
name|unsigned
name|ID
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the module file with a given local ID within the specified
end_comment

begin_comment
comment|/// ModuleFile.
end_comment

begin_function_decl
name|ModuleFile
modifier|*
name|getLocalModuleFile
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Get an ID for the given module file.
end_comment

begin_function_decl
name|unsigned
name|getModuleFileID
parameter_list|(
name|ModuleFile
modifier|*
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Return a descriptor for the corresponding module.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|Optional
operator|<
name|ASTSourceDescriptor
operator|>
name|getSourceDescriptor
argument_list|(
argument|unsigned ID
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ExtKind
name|hasExternalDefinitions
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve a selector from the given module with its local ID
end_comment

begin_comment
comment|/// number.
end_comment

begin_function_decl
name|Selector
name|getLocalSelector
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
name|unsigned
name|LocalID
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|Selector
name|DecodeSelector
argument_list|(
name|serialization
operator|::
name|SelectorID
name|Idx
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Selector
name|GetExternalSelector
argument_list|(
name|serialization
operator|::
name|SelectorID
name|ID
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|uint32_t
name|GetNumExternalSelectors
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_function
name|Selector
name|ReadSelector
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
return|return
name|getLocalSelector
argument_list|(
name|M
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Retrieve the global selector ID that corresponds to this
end_comment

begin_comment
comment|/// the local selector ID in a given module.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|SelectorID
name|getGlobalSelectorID
argument_list|(
argument|ModuleFile&F
argument_list|,
argument|unsigned LocalID
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read a declaration name.
end_comment

begin_function_decl
name|DeclarationName
name|ReadDeclarationName
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReadDeclarationNameLoc
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|DeclarationNameLoc
modifier|&
name|DNLoc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReadDeclarationNameInfo
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReadQualifierInfo
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|QualifierInfo
modifier|&
name|Info
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NestedNameSpecifier
modifier|*
name|ReadNestedNameSpecifier
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NestedNameSpecifierLoc
name|ReadNestedNameSpecifierLoc
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read a template name.
end_comment

begin_function_decl
name|TemplateName
name|ReadTemplateName
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read a template argument.
end_comment

begin_function_decl
name|TemplateArgument
name|ReadTemplateArgument
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|,
name|bool
name|Canonicalize
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read a template parameter list.
end_comment

begin_function_decl
name|TemplateParameterList
modifier|*
name|ReadTemplateParameterList
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read a template argument array.
end_comment

begin_decl_stmt
name|void
name|ReadTemplateArgumentList
argument_list|(
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|TemplArgs
argument_list|,
name|ModuleFile
operator|&
name|F
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|,
name|bool
name|Canonicalize
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Read a UnresolvedSet structure.
end_comment

begin_function_decl
name|void
name|ReadUnresolvedSet
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|LazyASTUnresolvedSet
modifier|&
name|Set
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read a C++ base specifier.
end_comment

begin_function_decl
name|CXXBaseSpecifier
name|ReadCXXBaseSpecifier
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read a CXXCtorInitializer array.
end_comment

begin_function_decl
name|CXXCtorInitializer
modifier|*
modifier|*
name|ReadCXXCtorInitializers
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read the contents of a CXXCtorInitializer array.
end_comment

begin_decl_stmt
name|CXXCtorInitializer
modifier|*
modifier|*
name|GetExternalCXXCtorInitializers
argument_list|(
name|uint64_t
name|Offset
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Read a source location from raw form and return it in its
end_comment

begin_comment
comment|/// originating module file's source location space.
end_comment

begin_decl_stmt
name|SourceLocation
name|ReadUntranslatedSourceLocation
argument_list|(
name|uint32_t
name|Raw
argument_list|)
decl|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
operator|(
name|Raw
operator|>>
literal|1
operator|)
operator||
operator|(
name|Raw
operator|<<
literal|31
operator|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Read a source location from raw form.
end_comment

begin_decl_stmt
name|SourceLocation
name|ReadSourceLocation
argument_list|(
name|ModuleFile
operator|&
name|ModuleFile
argument_list|,
name|uint32_t
name|Raw
argument_list|)
decl|const
block|{
name|SourceLocation
name|Loc
init|=
name|ReadUntranslatedSourceLocation
argument_list|(
name|Raw
argument_list|)
decl_stmt|;
return|return
name|TranslateSourceLocation
argument_list|(
name|ModuleFile
argument_list|,
name|Loc
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Translate a source location from another module file's source
end_comment

begin_comment
comment|/// location space into ours.
end_comment

begin_decl_stmt
name|SourceLocation
name|TranslateSourceLocation
argument_list|(
name|ModuleFile
operator|&
name|ModuleFile
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|ModuleFile
operator|.
name|ModuleOffsetMap
operator|.
name|empty
argument_list|()
condition|)
name|ReadModuleOffsetMap
argument_list|(
name|ModuleFile
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|ModuleFile
operator|.
name|SLocRemap
operator|.
name|find
argument_list|(
name|Loc
operator|.
name|getOffset
argument_list|()
argument_list|)
operator|!=
name|ModuleFile
operator|.
name|SLocRemap
operator|.
name|end
argument_list|()
operator|&&
literal|"Cannot find offset to remap."
argument_list|)
expr_stmt|;
name|int
name|Remap
init|=
name|ModuleFile
operator|.
name|SLocRemap
operator|.
name|find
argument_list|(
name|Loc
operator|.
name|getOffset
argument_list|()
argument_list|)
operator|->
name|second
decl_stmt|;
return|return
name|Loc
operator|.
name|getLocWithOffset
argument_list|(
name|Remap
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Read a source location.
end_comment

begin_function
name|SourceLocation
name|ReadSourceLocation
parameter_list|(
name|ModuleFile
modifier|&
name|ModuleFile
parameter_list|,
specifier|const
name|RecordDataImpl
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
return|return
name|ReadSourceLocation
argument_list|(
name|ModuleFile
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Read a source range.
end_comment

begin_function_decl
name|SourceRange
name|ReadSourceRange
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read an integral value
end_comment

begin_expr_stmt
name|llvm
operator|::
name|APInt
name|ReadAPInt
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read a signed integral value
end_comment

begin_expr_stmt
name|llvm
operator|::
name|APSInt
name|ReadAPSInt
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read a floating-point value
end_comment

begin_expr_stmt
name|llvm
operator|::
name|APFloat
name|ReadAPFloat
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
specifier|const
name|llvm
operator|::
name|fltSemantics
operator|&
name|Sem
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// \brief Read a string
end_comment

begin_expr_stmt
specifier|static
name|std
operator|::
name|string
name|ReadString
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// \brief Read a path
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|ReadPath
argument_list|(
name|ModuleFile
operator|&
name|F
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Read a version tuple.
end_comment

begin_function_decl
specifier|static
name|VersionTuple
name|ReadVersionTuple
parameter_list|(
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CXXTemporary
modifier|*
name|ReadCXXTemporary
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Reads attributes from the current stream position.
end_comment

begin_function_decl
name|void
name|ReadAttributes
parameter_list|(
name|ASTRecordReader
modifier|&
name|Record
parameter_list|,
name|AttrVec
modifier|&
name|Attrs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Reads a statement.
end_comment

begin_function_decl
name|Stmt
modifier|*
name|ReadStmt
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Reads an expression.
end_comment

begin_function_decl
name|Expr
modifier|*
name|ReadExpr
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Reads a sub-statement operand during statement reading.
end_comment

begin_function
name|Stmt
modifier|*
name|ReadSubStmt
parameter_list|()
block|{
name|assert
argument_list|(
name|ReadingKind
operator|==
name|Read_Stmt
operator|&&
literal|"Should be called only during statement reading!"
argument_list|)
expr_stmt|;
comment|// Subexpressions are stored from last to first, so the next Stmt we need
comment|// is at the back of the stack.
name|assert
argument_list|(
operator|!
name|StmtStack
operator|.
name|empty
argument_list|()
operator|&&
literal|"Read too many sub-statements!"
argument_list|)
expr_stmt|;
return|return
name|StmtStack
operator|.
name|pop_back_val
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Reads a sub-expression operand during statement reading.
end_comment

begin_function_decl
name|Expr
modifier|*
name|ReadSubExpr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Reads a token out of a record.
end_comment

begin_function_decl
name|Token
name|ReadToken
parameter_list|(
name|ModuleFile
modifier|&
name|M
parameter_list|,
specifier|const
name|RecordDataImpl
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Reads the macro record located at the given offset.
end_comment

begin_function_decl
name|MacroInfo
modifier|*
name|ReadMacroRecord
parameter_list|(
name|ModuleFile
modifier|&
name|F
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine the global preprocessed entity ID that corresponds to
end_comment

begin_comment
comment|/// the given local ID within the given module.
end_comment

begin_expr_stmt
name|serialization
operator|::
name|PreprocessedEntityID
name|getGlobalPreprocessedEntityID
argument_list|(
argument|ModuleFile&M
argument_list|,
argument|unsigned LocalID
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Add a macro to deserialize its macro directive history.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param II The name of the macro.
end_comment

begin_comment
comment|/// \param M The module file.
end_comment

begin_comment
comment|/// \param MacroDirectivesOffset Offset of the serialized macro directive
end_comment

begin_comment
comment|/// history.
end_comment

begin_function_decl
name|void
name|addPendingMacro
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|ModuleFile
modifier|*
name|M
parameter_list|,
name|uint64_t
name|MacroDirectivesOffset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Read the set of macros defined by this external macro source.
end_comment

begin_expr_stmt
name|void
name|ReadDefinedMacros
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Update an out-of-date identifier.
end_comment

begin_decl_stmt
name|void
name|updateOutOfDateIdentifier
argument_list|(
name|IdentifierInfo
operator|&
name|II
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Note that this identifier is up-to-date.
end_comment

begin_function_decl
name|void
name|markIdentifierUpToDate
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Load all external visible decls in the given DeclContext.
end_comment

begin_decl_stmt
name|void
name|completeVisibleDeclsMap
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the AST context that this AST reader supplements.
end_comment

begin_function
name|ASTContext
modifier|&
name|getContext
parameter_list|()
block|{
return|return
name|Context
return|;
block|}
end_function

begin_comment
comment|// \brief Contains the IDs for declarations that were requested before we have
end_comment

begin_comment
comment|// access to a Sema object.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|PreloadedDeclIDs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the semantic analysis object used to analyze the
end_comment

begin_comment
comment|/// translation unit in which the precompiled header is being
end_comment

begin_comment
comment|/// imported.
end_comment

begin_function
name|Sema
modifier|*
name|getSema
parameter_list|()
block|{
return|return
name|SemaObj
return|;
block|}
end_function

begin_comment
comment|/// \brief Get the identifier resolver used for name lookup / updates
end_comment

begin_comment
comment|/// in the translation unit scope. We have one of these even if we don't
end_comment

begin_comment
comment|/// have a Sema object.
end_comment

begin_function_decl
name|IdentifierResolver
modifier|&
name|getIdResolver
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the identifier table associated with the
end_comment

begin_comment
comment|/// preprocessor.
end_comment

begin_function_decl
name|IdentifierTable
modifier|&
name|getIdentifierTable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Record that the given ID maps to the given switch-case
end_comment

begin_comment
comment|/// statement.
end_comment

begin_function_decl
name|void
name|RecordSwitchCaseID
parameter_list|(
name|SwitchCase
modifier|*
name|SC
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Retrieve the switch-case statement with the given ID.
end_comment

begin_function_decl
name|SwitchCase
modifier|*
name|getSwitchCaseWithID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ClearSwitchCaseIDs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Cursors for comments blocks.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|BitstreamCursor
operator|,
name|serialization
operator|::
name|ModuleFile
operator|*
operator|>
operator|,
literal|8
operator|>
name|CommentsCursors
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Loads comments ranges.
end_comment

begin_expr_stmt
name|void
name|ReadComments
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Visit all the input files of the given module file.
end_comment

begin_decl_stmt
name|void
name|visitInputFiles
argument_list|(
name|serialization
operator|::
name|ModuleFile
operator|&
name|MF
argument_list|,
name|bool
name|IncludeSystem
argument_list|,
name|bool
name|Complain
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
argument|const serialization::InputFile&IF
argument_list|,
argument|bool isSystem
argument_list|)
operator|>
name|Visitor
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|bool
name|isProcessingUpdateRecords
parameter_list|()
block|{
return|return
name|ProcessingUpdateRecords
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief An object for streaming information from a record.
end_comment

begin_decl_stmt
name|class
name|ASTRecordReader
block|{
typedef|typedef
name|serialization
operator|::
name|ModuleFile
name|ModuleFile
expr_stmt|;
name|ASTReader
modifier|*
name|Reader
decl_stmt|;
name|ModuleFile
modifier|*
name|F
decl_stmt|;
name|unsigned
name|Idx
init|=
literal|0
decl_stmt|;
name|ASTReader
operator|::
name|RecordData
name|Record
expr_stmt|;
typedef|typedef
name|ASTReader
operator|::
name|RecordData
name|RecordData
expr_stmt|;
typedef|typedef
name|ASTReader
operator|::
name|RecordDataImpl
name|RecordDataImpl
expr_stmt|;
name|public
label|:
comment|/// Construct an ASTRecordReader that uses the default encoding scheme.
name|ASTRecordReader
argument_list|(
name|ASTReader
operator|&
name|Reader
argument_list|,
name|ModuleFile
operator|&
name|F
argument_list|)
operator|:
name|Reader
argument_list|(
operator|&
name|Reader
argument_list|)
operator|,
name|F
argument_list|(
argument|&F
argument_list|)
block|{}
comment|/// \brief Reads a record with id AbbrevID from Cursor, resetting the
comment|/// internal state.
name|unsigned
name|readRecord
argument_list|(
argument|llvm::BitstreamCursor&Cursor
argument_list|,
argument|unsigned AbbrevID
argument_list|)
expr_stmt|;
comment|/// \brief Is this a module file for a module (rather than a PCH or similar).
name|bool
name|isModule
argument_list|()
specifier|const
block|{
return|return
name|F
operator|->
name|isModule
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the AST context that this AST reader supplements.
name|ASTContext
modifier|&
name|getContext
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|getContext
argument_list|()
return|;
block|}
comment|/// \brief The current position in this record.
name|unsigned
name|getIdx
argument_list|()
specifier|const
block|{
return|return
name|Idx
return|;
block|}
comment|/// \brief The length of this record.
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Record
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief An arbitrary index in this record.
specifier|const
name|uint64_t
modifier|&
name|operator
function|[]
parameter_list|(
name|size_t
name|N
parameter_list|)
block|{
return|return
name|Record
index|[
name|N
index|]
return|;
block|}
comment|/// \brief The last element in this record.
specifier|const
name|uint64_t
operator|&
name|back
argument_list|()
specifier|const
block|{
return|return
name|Record
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// \brief Returns the current value in this record, and advances to the
comment|/// next value.
specifier|const
name|uint64_t
modifier|&
name|readInt
parameter_list|()
block|{
return|return
name|Record
index|[
name|Idx
operator|++
index|]
return|;
block|}
comment|/// \brief Returns the current value in this record, without advancing.
specifier|const
name|uint64_t
modifier|&
name|peekInt
parameter_list|()
block|{
return|return
name|Record
index|[
name|Idx
index|]
return|;
block|}
comment|/// \brief Skips the specified number of values.
name|void
name|skipInts
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|Idx
operator|+=
name|N
expr_stmt|;
block|}
comment|/// \brief Retrieve the global submodule ID its local ID number.
name|serialization
operator|::
name|SubmoduleID
name|getGlobalSubmoduleID
argument_list|(
argument|unsigned LocalID
argument_list|)
block|{
return|return
name|Reader
operator|->
name|getGlobalSubmoduleID
argument_list|(
operator|*
name|F
argument_list|,
name|LocalID
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the submodule that corresponds to a global submodule ID.
name|Module
modifier|*
name|getSubmodule
argument_list|(
name|serialization
operator|::
name|SubmoduleID
name|GlobalID
argument_list|)
block|{
return|return
name|Reader
operator|->
name|getSubmodule
argument_list|(
name|GlobalID
argument_list|)
return|;
block|}
comment|/// \brief Read the record that describes the lexical contents of a DC.
name|bool
name|readLexicalDeclContextStorage
parameter_list|(
name|uint64_t
name|Offset
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|ReadLexicalDeclContextStorage
argument_list|(
operator|*
name|F
argument_list|,
name|F
operator|->
name|DeclsCursor
argument_list|,
name|Offset
argument_list|,
name|DC
argument_list|)
return|;
block|}
comment|/// \brief Read the record that describes the visible contents of a DC.
name|bool
name|readVisibleDeclContextStorage
argument_list|(
name|uint64_t
name|Offset
argument_list|,
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
block|{
return|return
name|Reader
operator|->
name|ReadVisibleDeclContextStorage
argument_list|(
operator|*
name|F
argument_list|,
name|F
operator|->
name|DeclsCursor
argument_list|,
name|Offset
argument_list|,
name|ID
argument_list|)
return|;
block|}
name|void
name|readExceptionSpec
argument_list|(
name|SmallVectorImpl
operator|<
name|QualType
operator|>
operator|&
name|ExceptionStorage
argument_list|,
name|FunctionProtoType
operator|::
name|ExceptionSpecInfo
operator|&
name|ESI
argument_list|)
block|{
return|return
name|Reader
operator|->
name|readExceptionSpec
argument_list|(
operator|*
name|F
argument_list|,
name|ExceptionStorage
argument_list|,
name|ESI
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Get the global offset corresponding to a local offset.
name|uint64_t
name|getGlobalBitOffset
parameter_list|(
name|uint32_t
name|LocalOffset
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|getGlobalBitOffset
argument_list|(
operator|*
name|F
argument_list|,
name|LocalOffset
argument_list|)
return|;
block|}
comment|/// \brief Reads a statement.
name|Stmt
modifier|*
name|readStmt
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadStmt
argument_list|(
operator|*
name|F
argument_list|)
return|;
block|}
comment|/// \brief Reads an expression.
name|Expr
modifier|*
name|readExpr
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadExpr
argument_list|(
operator|*
name|F
argument_list|)
return|;
block|}
comment|/// \brief Reads a sub-statement operand during statement reading.
name|Stmt
modifier|*
name|readSubStmt
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadSubStmt
argument_list|()
return|;
block|}
comment|/// \brief Reads a sub-expression operand during statement reading.
name|Expr
modifier|*
name|readSubExpr
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadSubExpr
argument_list|()
return|;
block|}
comment|/// \brief Reads a declaration with the given local ID in the given module.
comment|///
comment|/// \returns The requested declaration, casted to the given return type.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|GetLocalDeclAs
argument_list|(
argument|uint32_t LocalID
argument_list|)
block|{
return|return
name|cast_or_null
operator|<
name|T
operator|>
operator|(
name|Reader
operator|->
name|GetLocalDecl
argument_list|(
operator|*
name|F
argument_list|,
name|LocalID
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Reads a TemplateArgumentLocInfo appropriate for the
comment|/// given TemplateArgument kind, advancing Idx.
name|TemplateArgumentLocInfo
name|getTemplateArgumentLocInfo
argument_list|(
name|TemplateArgument
operator|::
name|ArgKind
name|Kind
argument_list|)
block|{
return|return
name|Reader
operator|->
name|GetTemplateArgumentLocInfo
argument_list|(
operator|*
name|F
argument_list|,
name|Kind
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Reads a TemplateArgumentLoc, advancing Idx.
name|TemplateArgumentLoc
name|readTemplateArgumentLoc
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadTemplateArgumentLoc
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
specifier|const
name|ASTTemplateArgumentListInfo
modifier|*
name|readASTTemplateArgumentListInfo
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadASTTemplateArgumentListInfo
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Reads a declarator info from the given record, advancing Idx.
name|TypeSourceInfo
modifier|*
name|getTypeSourceInfo
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|GetTypeSourceInfo
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Map a local type ID within a given AST file to a global type ID.
name|serialization
operator|::
name|TypeID
name|getGlobalTypeID
argument_list|(
argument|unsigned LocalID
argument_list|)
specifier|const
block|{
return|return
name|Reader
operator|->
name|getGlobalTypeID
argument_list|(
operator|*
name|F
argument_list|,
name|LocalID
argument_list|)
return|;
block|}
comment|/// \brief Read a type from the current position in the record.
name|QualType
name|readType
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|readType
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Reads a declaration ID from the given position in this record.
comment|///
comment|/// \returns The declaration ID read from the record, adjusted to a global ID.
name|serialization
operator|::
name|DeclID
name|readDeclID
argument_list|()
block|{
return|return
name|Reader
operator|->
name|ReadDeclID
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Reads a declaration from the given position in a record in the
comment|/// given module, advancing Idx.
name|Decl
modifier|*
name|readDecl
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadDecl
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Reads a declaration from the given position in the record,
comment|/// advancing Idx.
comment|///
comment|/// \returns The declaration read from this location, casted to the given
comment|/// result type.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|readDeclAs
argument_list|()
block|{
return|return
name|Reader
operator|->
name|ReadDeclAs
operator|<
name|T
operator|>
operator|(
operator|*
name|F
operator|,
name|Record
operator|,
name|Idx
operator|)
return|;
block|}
name|IdentifierInfo
modifier|*
name|getIdentifierInfo
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|GetIdentifierInfo
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a selector from the Record, advancing Idx.
name|Selector
name|readSelector
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadSelector
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a declaration name, advancing Idx.
name|DeclarationName
name|readDeclarationName
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadDeclarationName
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
name|void
name|readDeclarationNameLoc
parameter_list|(
name|DeclarationNameLoc
modifier|&
name|DNLoc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|ReadDeclarationNameLoc
argument_list|(
operator|*
name|F
argument_list|,
name|DNLoc
argument_list|,
name|Name
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
name|void
name|readDeclarationNameInfo
parameter_list|(
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|ReadDeclarationNameInfo
argument_list|(
operator|*
name|F
argument_list|,
name|NameInfo
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
name|void
name|readQualifierInfo
parameter_list|(
name|QualifierInfo
modifier|&
name|Info
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|ReadQualifierInfo
argument_list|(
operator|*
name|F
argument_list|,
name|Info
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
name|NestedNameSpecifier
modifier|*
name|readNestedNameSpecifier
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadNestedNameSpecifier
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
name|NestedNameSpecifierLoc
name|readNestedNameSpecifierLoc
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadNestedNameSpecifierLoc
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a template name, advancing Idx.
name|TemplateName
name|readTemplateName
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadTemplateName
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a template argument, advancing Idx.
name|TemplateArgument
name|readTemplateArgument
parameter_list|(
name|bool
name|Canonicalize
init|=
name|false
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|ReadTemplateArgument
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|,
name|Canonicalize
argument_list|)
return|;
block|}
comment|/// \brief Read a template parameter list, advancing Idx.
name|TemplateParameterList
modifier|*
name|readTemplateParameterList
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadTemplateParameterList
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a template argument array, advancing Idx.
name|void
name|readTemplateArgumentList
argument_list|(
name|SmallVectorImpl
operator|<
name|TemplateArgument
operator|>
operator|&
name|TemplArgs
argument_list|,
name|bool
name|Canonicalize
operator|=
name|false
argument_list|)
block|{
return|return
name|Reader
operator|->
name|ReadTemplateArgumentList
argument_list|(
name|TemplArgs
argument_list|,
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|,
name|Canonicalize
argument_list|)
return|;
block|}
comment|/// \brief Read a UnresolvedSet structure, advancing Idx.
name|void
name|readUnresolvedSet
parameter_list|(
name|LazyASTUnresolvedSet
modifier|&
name|Set
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|ReadUnresolvedSet
argument_list|(
operator|*
name|F
argument_list|,
name|Set
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a C++ base specifier, advancing Idx.
name|CXXBaseSpecifier
name|readCXXBaseSpecifier
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadCXXBaseSpecifier
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a CXXCtorInitializer array, advancing Idx.
name|CXXCtorInitializer
modifier|*
modifier|*
name|readCXXCtorInitializers
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadCXXCtorInitializers
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
name|CXXTemporary
modifier|*
name|readCXXTemporary
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadCXXTemporary
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a source location, advancing Idx.
name|SourceLocation
name|readSourceLocation
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadSourceLocation
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a source range, advancing Idx.
name|SourceRange
name|readSourceRange
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadSourceRange
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read an integral value, advancing Idx.
name|llvm
operator|::
name|APInt
name|readAPInt
argument_list|()
block|{
return|return
name|Reader
operator|->
name|ReadAPInt
argument_list|(
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a signed integral value, advancing Idx.
name|llvm
operator|::
name|APSInt
name|readAPSInt
argument_list|()
block|{
return|return
name|Reader
operator|->
name|ReadAPSInt
argument_list|(
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a floating-point value, advancing Idx.
name|llvm
operator|::
name|APFloat
name|readAPFloat
argument_list|(
argument|const llvm::fltSemantics&Sem
argument_list|)
block|{
return|return
name|Reader
operator|->
name|ReadAPFloat
argument_list|(
name|Record
argument_list|,
name|Sem
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a string, advancing Idx.
name|std
operator|::
name|string
name|readString
argument_list|()
block|{
return|return
name|Reader
operator|->
name|ReadString
argument_list|(
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a path, advancing Idx.
name|std
operator|::
name|string
name|readPath
argument_list|()
block|{
return|return
name|Reader
operator|->
name|ReadPath
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Read a version tuple, advancing Idx.
name|VersionTuple
name|readVersionTuple
parameter_list|()
block|{
return|return
name|ASTReader
operator|::
name|ReadVersionTuple
argument_list|(
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
comment|/// \brief Reads attributes from the current stream position, advancing Idx.
name|void
name|readAttributes
parameter_list|(
name|AttrVec
modifier|&
name|Attrs
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|ReadAttributes
argument_list|(
operator|*
name|this
argument_list|,
name|Attrs
argument_list|)
return|;
block|}
comment|/// \brief Reads a token out of a record, advancing Idx.
name|Token
name|readToken
parameter_list|()
block|{
return|return
name|Reader
operator|->
name|ReadToken
argument_list|(
operator|*
name|F
argument_list|,
name|Record
argument_list|,
name|Idx
argument_list|)
return|;
block|}
name|void
name|recordSwitchCaseID
parameter_list|(
name|SwitchCase
modifier|*
name|SC
parameter_list|,
name|unsigned
name|ID
parameter_list|)
block|{
name|Reader
operator|->
name|RecordSwitchCaseID
argument_list|(
name|SC
argument_list|,
name|ID
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the switch-case statement with the given ID.
name|SwitchCase
modifier|*
name|getSwitchCaseWithID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
return|return
name|Reader
operator|->
name|getSwitchCaseWithID
argument_list|(
name|ID
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Helper class that saves the current stream position and
end_comment

begin_comment
comment|/// then restores it when destroyed.
end_comment

begin_struct
struct|struct
name|SavedStreamPosition
block|{
name|explicit
name|SavedStreamPosition
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|)
range|:
name|Cursor
argument_list|(
name|Cursor
argument_list|)
decl_stmt|,
name|Offset
argument_list|(
name|Cursor
operator|.
name|GetCurrentBitNo
argument_list|()
argument_list|)
block|{ }
operator|~
name|SavedStreamPosition
argument_list|()
block|{
name|Cursor
operator|.
name|JumpToBit
argument_list|(
name|Offset
argument_list|)
block|;   }
name|private
operator|:
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
expr_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
specifier|inline
name|void
name|PCHValidator
operator|::
name|Error
argument_list|(
argument|const char *Msg
argument_list|)
block|{
name|Reader
operator|.
name|Error
argument_list|(
name|Msg
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

