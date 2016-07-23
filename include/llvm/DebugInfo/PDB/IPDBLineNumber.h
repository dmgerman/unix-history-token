begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IPDBLineNumber.h - base interface for PDB line no. info ---*- C++-*-===//
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
name|LLVM_DEBUGINFO_PDB_IPDBLINENUMBER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_IPDBLINENUMBER_H
end_define

begin_include
include|#
directive|include
file|"PDBTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|IPDBLineNumber
block|{
name|public
label|:
name|virtual
operator|~
name|IPDBLineNumber
argument_list|()
expr_stmt|;
name|virtual
name|uint32_t
name|getLineNumber
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getLineNumberEnd
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getColumnNumber
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getColumnNumberEnd
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getAddressSection
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getAddressOffset
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getRelativeVirtualAddress
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint64_t
name|getVirtualAddress
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getLength
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getSourceFileId
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getCompilandId
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|isStatement
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

