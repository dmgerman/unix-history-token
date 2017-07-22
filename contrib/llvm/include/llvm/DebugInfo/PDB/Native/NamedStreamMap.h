begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- NamedStreamMap.h - PDB Named Stream Map ------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_NATIVE_NAMEDSTREAMMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_NATIVE_NAMEDSTREAMMAP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/HashTable.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryStreamReader
decl_stmt|;
name|class
name|BinaryStreamWriter
decl_stmt|;
name|namespace
name|pdb
block|{
name|class
name|NamedStreamMap
block|{
name|friend
name|class
name|NamedStreamMapBuilder
decl_stmt|;
struct|struct
name|FinalizationInfo
block|{
name|uint32_t
name|StringDataBytes
init|=
literal|0
decl_stmt|;
name|uint32_t
name|SerializedLength
init|=
literal|0
decl_stmt|;
block|}
struct|;
name|public
label|:
name|NamedStreamMap
argument_list|()
expr_stmt|;
name|Error
name|load
parameter_list|(
name|BinaryStreamReader
modifier|&
name|Stream
parameter_list|)
function_decl|;
name|Error
name|commit
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|finalize
parameter_list|()
function_decl|;
name|uint32_t
name|size
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|get
argument_list|(
name|StringRef
name|Stream
argument_list|,
name|uint32_t
operator|&
name|StreamNo
argument_list|)
decl|const
decl_stmt|;
name|void
name|set
parameter_list|(
name|StringRef
name|Stream
parameter_list|,
name|uint32_t
name|StreamNo
parameter_list|)
function_decl|;
name|void
name|remove
parameter_list|(
name|StringRef
name|Stream
parameter_list|)
function_decl|;
specifier|const
name|StringMap
operator|<
name|uint32_t
operator|>
operator|&
name|getStringMap
argument_list|()
specifier|const
block|{
return|return
name|Mapping
return|;
block|}
name|iterator_range
operator|<
name|StringMapConstIterator
operator|<
name|uint32_t
operator|>>
name|entries
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Optional
operator|<
name|FinalizationInfo
operator|>
name|FinalizedInfo
expr_stmt|;
name|HashTable
name|FinalizedHashTable
decl_stmt|;
name|StringMap
operator|<
name|uint32_t
operator|>
name|Mapping
expr_stmt|;
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
comment|// LLVM_DEBUGINFO_PDB_NATIVE_NAMEDSTREAMMAP_H
end_comment

end_unit

