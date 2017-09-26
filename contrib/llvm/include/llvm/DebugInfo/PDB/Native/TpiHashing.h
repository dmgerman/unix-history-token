begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TpiHashing.h ---------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_TPIHASHING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_TPIHASHING_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|Expected
operator|<
name|uint32_t
operator|>
name|hashTypeRecord
argument_list|(
specifier|const
name|llvm
operator|::
name|codeview
operator|::
name|CVType
operator|&
name|Type
argument_list|)
expr_stmt|;
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
comment|// LLVM_DEBUGINFO_PDB_TPIHASHING_H
end_comment

end_unit

