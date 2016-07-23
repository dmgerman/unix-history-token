begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IPDBSourceFile.h - base interface for a PDB source file --*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_IPDBSOURCEFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_IPDBSOURCEFILE_H
end_define

begin_include
include|#
directive|include
file|"PDBTypes.h"
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
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|pdb
block|{
comment|/// IPDBSourceFile defines an interface used to represent source files whose
comment|/// information are stored in the PDB.
name|class
name|IPDBSourceFile
block|{
name|public
label|:
name|virtual
operator|~
name|IPDBSourceFile
argument_list|()
expr_stmt|;
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|int
name|Indent
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|std
operator|::
name|string
name|getFileName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getUniqueId
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|getChecksum
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|PDB_Checksum
name|getChecksumType
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBEnumChildren
operator|<
name|PDBSymbolCompiland
operator|>>
name|getCompilands
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

