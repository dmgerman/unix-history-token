begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Instrumentation/DebugIR.h - Interface ----*- C++ -*-===//
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
comment|// This file defines the interface of the DebugIR pass. For most users,
end_comment

begin_comment
comment|// including Instrumentation.h and calling createDebugIRPass() is sufficient and
end_comment

begin_comment
comment|// there is no need to include this file.
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
name|LLVM_TRANSFORMS_INSTRUMENTATION_DEBUGIR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_INSTRUMENTATION_DEBUGIR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DebugIR
range|:
name|public
name|llvm
operator|::
name|ModulePass
block|{
comment|/// If true, write a source file to disk.
name|bool
name|WriteSourceToDisk
block|;
comment|/// Hide certain (non-essential) debug information (only relevant if
comment|/// createSource is true.
name|bool
name|HideDebugIntrinsics
block|;
name|bool
name|HideDebugMetadata
block|;
comment|/// The location of the source file.
name|std
operator|::
name|string
name|Directory
block|;
name|std
operator|::
name|string
name|Filename
block|;
comment|/// True if a temporary file name was generated.
name|bool
name|GeneratedPath
block|;
comment|/// True if the file name was read from the Module.
name|bool
name|ParsedPath
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"DebugIR"
return|;
block|}
comment|/// Generate a file on disk to be displayed in a debugger. If Filename and
comment|/// Directory are empty, a temporary path will be generated.
name|DebugIR
argument_list|(
argument|bool HideDebugIntrinsics
argument_list|,
argument|bool HideDebugMetadata
argument_list|,
argument|llvm::StringRef Directory
argument_list|,
argument|llvm::StringRef Filename
argument_list|)
operator|:
name|ModulePass
argument_list|(
name|ID
argument_list|)
block|,
name|WriteSourceToDisk
argument_list|(
name|true
argument_list|)
block|,
name|HideDebugIntrinsics
argument_list|(
name|HideDebugIntrinsics
argument_list|)
block|,
name|HideDebugMetadata
argument_list|(
name|HideDebugMetadata
argument_list|)
block|,
name|Directory
argument_list|(
name|Directory
argument_list|)
block|,
name|Filename
argument_list|(
name|Filename
argument_list|)
block|,
name|GeneratedPath
argument_list|(
name|false
argument_list|)
block|,
name|ParsedPath
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// Modify input in-place; do not generate additional files, and do not hide
comment|/// any debug intrinsics/metadata that might be present.
name|DebugIR
argument_list|()
operator|:
name|ModulePass
argument_list|(
name|ID
argument_list|)
block|,
name|WriteSourceToDisk
argument_list|(
name|false
argument_list|)
block|,
name|HideDebugIntrinsics
argument_list|(
name|false
argument_list|)
block|,
name|HideDebugMetadata
argument_list|(
name|false
argument_list|)
block|,
name|GeneratedPath
argument_list|(
name|false
argument_list|)
block|,
name|ParsedPath
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// Run pass on M and set Path to the source file path in the output module.
name|bool
name|runOnModule
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|,
name|std
operator|::
name|string
operator|&
name|Path
argument_list|)
block|;
name|bool
name|runOnModule
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
comment|/// Returns the concatenated Directory + Filename, without error checking
name|std
operator|::
name|string
name|getPath
argument_list|()
block|;
comment|/// Attempts to read source information from debug information in M, and if
comment|/// that fails, from M's identifier. Returns true on success, false otherwise.
name|bool
name|getSourceInfo
argument_list|(
specifier|const
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|)
block|;
comment|/// Replace the extension of Filename with NewExtension, and return true if
comment|/// successful. Return false if extension could not be found or Filename is
comment|/// empty.
name|bool
name|updateExtension
argument_list|(
argument|llvm::StringRef NewExtension
argument_list|)
block|;
comment|/// Generate a temporary filename and open an fd
name|void
name|generateFilename
argument_list|(
name|llvm
operator|::
name|OwningPtr
operator|<
name|int
operator|>
operator|&
name|fd
argument_list|)
block|;
comment|/// Creates DWARF CU/Subroutine metadata
name|void
name|createDebugInfo
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|,
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|Module
operator|>
operator|&
name|DisplayM
argument_list|)
block|;
comment|/// Returns true if either Directory or Filename is missing, false otherwise.
name|bool
name|isMissingPath
argument_list|()
block|;
comment|/// Write M to disk, optionally passing in an fd to an open file which is
comment|/// closed by this function after writing. If no fd is specified, a new file
comment|/// is opened, written, and closed.
name|void
name|writeDebugBitcode
argument_list|(
specifier|const
name|llvm
operator|::
name|Module
operator|*
name|M
argument_list|,
name|int
operator|*
name|fd
operator|=
literal|0
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TRANSFORMS_INSTRUMENTATION_DEBUGIR_H
end_comment

end_unit

