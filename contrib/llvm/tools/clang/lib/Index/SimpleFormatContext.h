begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SimpleFormatContext.h ----------------------------------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \brief Defines a utility class for use of clang-format in libclang
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
name|LLVM_CLANG_SIMPLE_FORM_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SIMPLE_FORM_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/DiagnosticOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Rewrite/Core/Rewriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Path.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|index
block|{
comment|/// \brief A small class to be used by libclang clients to format
comment|/// a declaration string in memory. This object is instantiated once
comment|/// and used each time a formatting is needed.
name|class
name|SimpleFormatContext
block|{
name|public
label|:
name|SimpleFormatContext
argument_list|(
argument|LangOptions Options
argument_list|)
block|:
name|DiagOpts
argument_list|(
argument|new DiagnosticOptions()
argument_list|)
operator|,
name|Diagnostics
argument_list|(
argument|new DiagnosticsEngine(new DiagnosticIDs,                                           DiagOpts.getPtr())
argument_list|)
operator|,
name|Files
argument_list|(
operator|(
name|FileSystemOptions
argument_list|()
operator|)
argument_list|)
operator|,
name|Sources
argument_list|(
operator|*
name|Diagnostics
argument_list|,
name|Files
argument_list|)
operator|,
name|Rewrite
argument_list|(
argument|Sources
argument_list|,
argument|Options
argument_list|)
block|{
name|Diagnostics
operator|->
name|setClient
argument_list|(
argument|new IgnoringDiagConsumer
argument_list|,
argument|true
argument_list|)
block|;   }
operator|~
name|SimpleFormatContext
argument_list|()
block|{ }
name|FileID
name|createInMemoryFile
argument_list|(
argument|StringRef Name
argument_list|,
argument|StringRef Content
argument_list|)
block|{
specifier|const
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Source
operator|=
name|llvm
operator|::
name|MemoryBuffer
operator|::
name|getMemBuffer
argument_list|(
name|Content
argument_list|)
block|;
specifier|const
name|FileEntry
operator|*
name|Entry
operator|=
name|Files
operator|.
name|getVirtualFile
argument_list|(
name|Name
argument_list|,
name|Source
operator|->
name|getBufferSize
argument_list|()
argument_list|,
literal|0
argument_list|)
block|;
name|Sources
operator|.
name|overrideFileContents
argument_list|(
name|Entry
argument_list|,
name|Source
argument_list|,
name|true
argument_list|)
block|;
name|assert
argument_list|(
name|Entry
operator|!=
name|NULL
argument_list|)
block|;
return|return
name|Sources
operator|.
name|createFileID
argument_list|(
name|Entry
argument_list|,
name|SourceLocation
argument_list|()
argument_list|,
name|SrcMgr
operator|::
name|C_User
argument_list|)
return|;
block|}
name|std
operator|::
name|string
name|getRewrittenText
argument_list|(
argument|FileID ID
argument_list|)
block|{
name|std
operator|::
name|string
name|Result
block|;
name|llvm
operator|::
name|raw_string_ostream
name|OS
argument_list|(
name|Result
argument_list|)
block|;
name|Rewrite
operator|.
name|getEditBuffer
argument_list|(
name|ID
argument_list|)
operator|.
name|write
argument_list|(
name|OS
argument_list|)
block|;
name|OS
operator|.
name|flush
argument_list|()
block|;
return|return
name|Result
return|;
block|}
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticOptions
operator|>
name|DiagOpts
expr_stmt|;
name|IntrusiveRefCntPtr
operator|<
name|DiagnosticsEngine
operator|>
name|Diagnostics
expr_stmt|;
name|FileManager
name|Files
decl_stmt|;
name|SourceManager
name|Sources
decl_stmt|;
name|Rewriter
name|Rewrite
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace index
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

