begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTUnit.h - ASTUnit utility ----------------------------*- C++ -*-===//
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
comment|// ASTUnit utility class.
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
name|LLVM_CLANG_FRONTEND_ASTUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_ASTUNIT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/ASTLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|class
name|ASTContext
decl_stmt|;
name|class
name|CompilerInvocation
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Diagnostic
decl_stmt|;
name|class
name|FileEntry
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|using
name|namespace
name|idx
decl_stmt|;
comment|/// \brief Utility class for loading a ASTContext from a PCH file.
comment|///
name|class
name|ASTUnit
block|{
name|FileManager
name|FileMgr
decl_stmt|;
name|SourceManager
name|SourceMgr
decl_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|HeaderSearch
operator|>
name|HeaderInfo
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|TargetInfo
operator|>
name|Target
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|Preprocessor
operator|>
name|PP
expr_stmt|;
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTContext
operator|>
name|Ctx
expr_stmt|;
comment|/// Optional owned invocation, just used to make the invocation used in
comment|/// LoadFromCommandLine available.
name|llvm
operator|::
name|OwningPtr
operator|<
name|CompilerInvocation
operator|>
name|Invocation
expr_stmt|;
comment|// OnlyLocalDecls - when true, walking this AST should only visit declarations
comment|// that come from the AST itself, not from included precompiled headers.
comment|// FIXME: This is temporary; eventually, CIndex will always do this.
name|bool
name|OnlyLocalDecls
decl_stmt|;
comment|/// Track whether the main file was loaded from an AST or not.
name|bool
name|MainFileIsAST
decl_stmt|;
comment|/// Track the top-level decls which appeared in an ASTUnit which was loaded
comment|/// from a source file.
comment|//
comment|// FIXME: This is just an optimization hack to avoid deserializing large parts
comment|// of a PCH file when using the Index library on an ASTUnit loaded from
comment|// source. In the long term we should make the Index library use efficient and
comment|// more scalable search mechanisms.
name|std
operator|::
name|vector
operator|<
name|Decl
operator|*
operator|>
name|TopLevelDecls
expr_stmt|;
comment|/// The name of the original source file used to generate this ASTUnit.
name|std
operator|::
name|string
name|OriginalSourceFile
expr_stmt|;
comment|// Critical optimization when using clang_getCursor().
name|ASTLocation
name|LastLoc
decl_stmt|;
comment|/// \brief The set of diagnostics produced when creating this
comment|/// translation unit.
name|llvm
operator|::
name|SmallVector
operator|<
name|StoredDiagnostic
operator|,
literal|4
operator|>
name|Diagnostics
expr_stmt|;
comment|/// \brief Temporary files that should be removed when the ASTUnit is
comment|/// destroyed.
name|llvm
operator|::
name|SmallVector
operator|<
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|,
literal|4
operator|>
name|TemporaryFiles
expr_stmt|;
comment|/// \brief Simple hack to allow us to assert that ASTUnit is not being
comment|/// used concurrently, which is not supported.
comment|///
comment|/// Clients should create instances of the ConcurrencyCheck class whenever
comment|/// using the ASTUnit in a way that isn't intended to be concurrent, which is
comment|/// just about any usage.
name|unsigned
name|int
name|ConcurrencyCheckValue
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|CheckLocked
init|=
literal|28573289
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|int
name|CheckUnlocked
init|=
literal|9803453
decl_stmt|;
name|ASTUnit
argument_list|(
specifier|const
name|ASTUnit
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|ASTUnit
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ASTUnit
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|class
name|ConcurrencyCheck
block|{
specifier|volatile
name|ASTUnit
modifier|&
name|Self
decl_stmt|;
name|public
label|:
name|explicit
name|ConcurrencyCheck
argument_list|(
name|ASTUnit
operator|&
name|Self
argument_list|)
operator|:
name|Self
argument_list|(
argument|Self
argument_list|)
block|{
name|assert
argument_list|(
name|Self
operator|.
name|ConcurrencyCheckValue
operator|==
name|CheckUnlocked
operator|&&
literal|"Concurrent access to ASTUnit!"
argument_list|)
block|;
name|Self
operator|.
name|ConcurrencyCheckValue
operator|=
name|CheckLocked
block|;     }
operator|~
name|ConcurrencyCheck
argument_list|()
block|{
name|Self
operator|.
name|ConcurrencyCheckValue
operator|=
name|CheckUnlocked
block|;     }
block|}
empty_stmt|;
name|friend
name|class
name|ConcurrencyCheck
decl_stmt|;
name|ASTUnit
argument_list|(
argument|bool MainFileIsAST
argument_list|)
empty_stmt|;
operator|~
name|ASTUnit
argument_list|()
expr_stmt|;
name|bool
name|isMainFileAST
argument_list|()
specifier|const
block|{
return|return
name|MainFileIsAST
return|;
block|}
specifier|const
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
name|SourceManager
modifier|&
name|getSourceManager
parameter_list|()
block|{
return|return
name|SourceMgr
return|;
block|}
specifier|const
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
return|return
operator|*
name|PP
operator|.
name|get
argument_list|()
return|;
block|}
name|Preprocessor
modifier|&
name|getPreprocessor
parameter_list|()
block|{
return|return
operator|*
name|PP
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|ASTContext
operator|&
name|getASTContext
argument_list|()
specifier|const
block|{
return|return
operator|*
name|Ctx
operator|.
name|get
argument_list|()
return|;
block|}
name|ASTContext
modifier|&
name|getASTContext
parameter_list|()
block|{
return|return
operator|*
name|Ctx
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
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
name|FileManager
modifier|&
name|getFileManager
parameter_list|()
block|{
return|return
name|FileMgr
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getOriginalSourceFileName
argument_list|()
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getPCHFileName
argument_list|()
expr_stmt|;
comment|/// \brief Add a temporary file that the ASTUnit depends on.
comment|///
comment|/// This file will be erased when the ASTUnit is destroyed.
name|void
name|addTemporaryFile
argument_list|(
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|&
name|TempFile
argument_list|)
block|{
name|TemporaryFiles
operator|.
name|push_back
argument_list|(
name|TempFile
argument_list|)
expr_stmt|;
block|}
name|bool
name|getOnlyLocalDecls
argument_list|()
specifier|const
block|{
return|return
name|OnlyLocalDecls
return|;
block|}
name|void
name|setLastASTLocation
parameter_list|(
name|ASTLocation
name|ALoc
parameter_list|)
block|{
name|LastLoc
operator|=
name|ALoc
expr_stmt|;
block|}
name|ASTLocation
name|getLastASTLocation
argument_list|()
specifier|const
block|{
return|return
name|LastLoc
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|Decl
operator|*
operator|>
operator|&
name|getTopLevelDecls
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|isMainFileAST
argument_list|()
operator|&&
literal|"Invalid call for AST based ASTUnit!"
argument_list|)
block|;
return|return
name|TopLevelDecls
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|Decl
operator|*
operator|>
operator|&
name|getTopLevelDecls
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isMainFileAST
argument_list|()
operator|&&
literal|"Invalid call for AST based ASTUnit!"
argument_list|)
block|;
return|return
name|TopLevelDecls
return|;
block|}
comment|// Retrieve the diagnostics associated with this AST
typedef|typedef
specifier|const
name|StoredDiagnostic
modifier|*
name|diag_iterator
typedef|;
name|diag_iterator
name|diag_begin
argument_list|()
specifier|const
block|{
return|return
name|Diagnostics
operator|.
name|begin
argument_list|()
return|;
block|}
name|diag_iterator
name|diag_end
argument_list|()
specifier|const
block|{
return|return
name|Diagnostics
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|diag_size
argument_list|()
specifier|const
block|{
return|return
name|Diagnostics
operator|.
name|size
argument_list|()
return|;
block|}
name|llvm
operator|::
name|SmallVector
operator|<
name|StoredDiagnostic
operator|,
literal|4
operator|>
operator|&
name|getDiagnostics
argument_list|()
block|{
return|return
name|Diagnostics
return|;
block|}
comment|/// \brief A mapping from a file name to the memory buffer that stores the
comment|/// remapped contents of that file.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
name|RemappedFile
expr_stmt|;
comment|/// \brief Create a ASTUnit from a PCH file.
comment|///
comment|/// \param Filename - The PCH file to load.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|///
comment|/// \returns - The initialized ASTUnit or null if the PCH failed to load.
specifier|static
name|ASTUnit
modifier|*
name|LoadFromPCHFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|bool
name|OnlyLocalDecls
operator|=
name|false
argument_list|,
name|RemappedFile
operator|*
name|RemappedFiles
operator|=
literal|0
argument_list|,
name|unsigned
name|NumRemappedFiles
operator|=
literal|0
argument_list|,
name|bool
name|CaptureDiagnostics
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// LoadFromCompilerInvocation - Create an ASTUnit from a source file, via a
comment|/// CompilerInvocation object.
comment|///
comment|/// \param CI - The compiler invocation to use; it must have exactly one input
comment|/// source file. The ASTUnit takes ownership of the CompilerInvocation object.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|//
comment|// FIXME: Move OnlyLocalDecls, UseBumpAllocator to setters on the ASTUnit, we
comment|// shouldn't need to specify them at construction time.
specifier|static
name|ASTUnit
modifier|*
name|LoadFromCompilerInvocation
parameter_list|(
name|CompilerInvocation
modifier|*
name|CI
parameter_list|,
name|Diagnostic
modifier|&
name|Diags
parameter_list|,
name|bool
name|OnlyLocalDecls
init|=
name|false
parameter_list|,
name|bool
name|CaptureDiagnostics
init|=
name|false
parameter_list|)
function_decl|;
comment|/// LoadFromCommandLine - Create an ASTUnit from a vector of command line
comment|/// arguments, which must specify exactly one source file.
comment|///
comment|/// \param ArgBegin - The beginning of the argument vector.
comment|///
comment|/// \param ArgEnd - The end of the argument vector.
comment|///
comment|/// \param Diags - The diagnostics engine to use for reporting errors; its
comment|/// lifetime is expected to extend past that of the returned ASTUnit.
comment|///
comment|/// \param ResourceFilesPath - The path to the compiler resource files.
comment|//
comment|// FIXME: Move OnlyLocalDecls, UseBumpAllocator to setters on the ASTUnit, we
comment|// shouldn't need to specify them at construction time.
specifier|static
name|ASTUnit
modifier|*
name|LoadFromCommandLine
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|ArgBegin
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|ArgEnd
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
name|llvm
operator|::
name|StringRef
name|ResourceFilesPath
argument_list|,
name|bool
name|OnlyLocalDecls
operator|=
name|false
argument_list|,
name|RemappedFile
operator|*
name|RemappedFiles
operator|=
literal|0
argument_list|,
name|unsigned
name|NumRemappedFiles
operator|=
literal|0
argument_list|,
name|bool
name|CaptureDiagnostics
operator|=
name|false
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

