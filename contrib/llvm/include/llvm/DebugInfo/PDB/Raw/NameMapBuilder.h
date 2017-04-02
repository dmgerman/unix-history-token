begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NameMapBuilder.h - PDB Name Map Builder ------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBNAMEMAPBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBNAMEMAPBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|msf
block|{
name|class
name|StreamWriter
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
name|class
name|NameMap
decl_stmt|;
name|class
name|NameMapBuilder
block|{
name|public
label|:
name|NameMapBuilder
argument_list|()
expr_stmt|;
name|void
name|addMapping
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint32_t
name|Mapping
parameter_list|)
function_decl|;
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|NameMap
operator|>>
name|build
argument_list|()
expr_stmt|;
name|Error
name|commit
argument_list|(
name|msf
operator|::
name|StreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|calculateSerializedLength
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|StringMap
operator|<
name|uint32_t
operator|>
name|Map
expr_stmt|;
name|uint32_t
name|StringDataBytes
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_DEBUGINFO_PDB_RAW_PDBNAMEMAPBUILDER_H
end_comment

end_unit

