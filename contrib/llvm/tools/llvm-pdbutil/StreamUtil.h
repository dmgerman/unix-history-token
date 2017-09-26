begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Streamutil.h - PDB stream utilities ----------------------*- C++ -*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_STREAMUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_STREAMUTIL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|PDBFile
decl_stmt|;
name|enum
name|class
name|StreamPurpose
block|{
name|NamedStream
operator|,
name|ModuleStream
operator|,
name|Other
block|}
empty_stmt|;
name|void
name|discoverStreamPurposes
argument_list|(
name|PDBFile
operator|&
name|File
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Purposes
argument_list|)
decl_stmt|;
name|void
name|discoverStreamPurposes
argument_list|(
name|PDBFile
operator|&
name|File
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|StreamPurpose
argument_list|,
name|std
operator|::
name|string
operator|>>
operator|&
name|Purposes
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

