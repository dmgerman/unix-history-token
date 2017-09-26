begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PDBContext.h --------------------------------------------*- C++ -*-===//
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
comment|//===----------------------------------------------------------------------===/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_PDB_PDBCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_PDBCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DIContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/IPDBSession.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
name|object
block|{
name|class
name|COFFObjectFile
decl_stmt|;
block|}
comment|// end namespace object
name|namespace
name|pdb
block|{
comment|/// PDBContext
comment|/// This data structure is the top level entity that deals with PDB debug
comment|/// information parsing.  This data structure exists only when there is a
comment|/// need for a transparent interface to different debug information formats
comment|/// (e.g. PDB and DWARF).  More control and power over the debug information
comment|/// access can be had by using the PDB interfaces directly.
name|class
name|PDBContext
range|:
name|public
name|DIContext
block|{
name|public
operator|:
name|PDBContext
argument_list|(
specifier|const
name|object
operator|::
name|COFFObjectFile
operator|&
name|Object
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBSession
operator|>
name|PDBSession
argument_list|)
block|;
name|PDBContext
argument_list|(
name|PDBContext
operator|&
argument_list|)
operator|=
name|delete
block|;
name|PDBContext
operator|&
name|operator
operator|=
operator|(
name|PDBContext
operator|&
operator|)
operator|=
name|delete
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DIContext *DICtx
argument_list|)
block|{
return|return
name|DICtx
operator|->
name|getKind
argument_list|()
operator|==
name|CK_PDB
return|;
block|}
name|void
name|dump
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|DIDumpOptions DIDumpOpts
argument_list|)
name|override
block|;
name|DILineInfo
name|getLineInfoForAddress
argument_list|(
argument|uint64_t Address
argument_list|,
argument|DILineInfoSpecifier Specifier = DILineInfoSpecifier()
argument_list|)
name|override
block|;
name|DILineInfoTable
name|getLineInfoForAddressRange
argument_list|(
argument|uint64_t Address
argument_list|,
argument|uint64_t Size
argument_list|,
argument|DILineInfoSpecifier Specifier = DILineInfoSpecifier()
argument_list|)
name|override
block|;
name|DIInliningInfo
name|getInliningInfoForAddress
argument_list|(
argument|uint64_t Address
argument_list|,
argument|DILineInfoSpecifier Specifier = DILineInfoSpecifier()
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|getFunctionName
argument_list|(
argument|uint64_t Address
argument_list|,
argument|DINameKind NameKind
argument_list|)
specifier|const
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|IPDBSession
operator|>
name|Session
block|;   }
decl_stmt|;
block|}
comment|// end namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_PDBCONTEXT_H
end_comment

end_unit

