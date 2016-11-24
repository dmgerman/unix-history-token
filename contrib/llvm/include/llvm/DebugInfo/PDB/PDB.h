begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDB.h - base header file for creating a PDB reader -------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_PDB_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDB_H
end_define

begin_include
include|#
directive|include
file|"PDBTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|namespace
name|pdb
block|{
name|Error
name|loadDataForPDB
argument_list|(
name|PDB_ReaderType
name|Type
argument_list|,
name|StringRef
name|Path
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBSession
operator|>
operator|&
name|Session
argument_list|)
decl_stmt|;
name|Error
name|loadDataForEXE
argument_list|(
name|PDB_ReaderType
name|Type
argument_list|,
name|StringRef
name|Path
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBSession
operator|>
operator|&
name|Session
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

