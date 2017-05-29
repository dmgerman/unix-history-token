begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBTypeServerHandler.h -----------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_PDB_PDBTYPESERVERHANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDBTYPESERVERHANDLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeServerHandler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/NativeSession.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBTypes.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|NativeSession
decl_stmt|;
name|class
name|PDBTypeServerHandler
range|:
name|public
name|codeview
operator|::
name|TypeServerHandler
block|{
name|public
operator|:
name|PDBTypeServerHandler
argument_list|(
argument|bool RevisitAlways = false
argument_list|)
block|;
name|void
name|addSearchPath
argument_list|(
argument|StringRef Path
argument_list|)
block|;
name|Expected
operator|<
name|bool
operator|>
name|handle
argument_list|(
argument|codeview::TypeServer2Record&TS
argument_list|,
argument|codeview::TypeVisitorCallbacks&Callbacks
argument_list|)
name|override
block|;
name|private
operator|:
name|Expected
operator|<
name|bool
operator|>
name|handleInternal
argument_list|(
name|PDBFile
operator|&
name|File
argument_list|,
name|codeview
operator|::
name|TypeVisitorCallbacks
operator|&
name|Callbacks
argument_list|)
block|;
name|bool
name|RevisitAlways
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|NativeSession
operator|>
name|Session
block|;
name|StringSet
operator|<
operator|>
name|SearchPaths
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

