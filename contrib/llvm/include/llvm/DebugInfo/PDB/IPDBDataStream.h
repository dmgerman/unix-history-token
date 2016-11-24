begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IPDBDataStream.h - base interface for child enumerator -*- C++ ---*-===//
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
name|LLVM_DEBUGINFO_PDB_IPDBDATASTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_IPDBDATASTREAM_H
end_define

begin_include
include|#
directive|include
file|"PDBTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
comment|/// IPDBDataStream defines an interface used to represent a stream consisting
comment|/// of a name and a series of records whose formats depend on the particular
comment|/// stream type.
name|class
name|IPDBDataStream
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|uint8_t
operator|,
literal|32
operator|>
name|RecordType
expr_stmt|;
name|virtual
operator|~
name|IPDBDataStream
argument_list|()
expr_stmt|;
name|virtual
name|uint32_t
name|getRecordCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|std
operator|::
name|string
name|getName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|llvm
operator|::
name|Optional
operator|<
name|RecordType
operator|>
name|getItemAtIndex
argument_list|(
argument|uint32_t Index
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|getNext
parameter_list|(
name|RecordType
modifier|&
name|Record
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|reset
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|IPDBDataStream
operator|*
name|clone
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

