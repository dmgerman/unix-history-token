begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GdbIndex.h --------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
comment|//===-------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_ELF_GDB_INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_GDB_INDEX_H
end_define

begin_include
include|#
directive|include
file|"InputFiles.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/ELF.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/DWARF/DWARFContext.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|InputSection
decl_stmt|;
comment|// Struct represents single entry of address area of gdb index.
struct|struct
name|AddressEntry
block|{
name|InputSection
modifier|*
name|Section
decl_stmt|;
name|uint64_t
name|LowAddress
decl_stmt|;
name|uint64_t
name|HighAddress
decl_stmt|;
name|size_t
name|CuIndex
decl_stmt|;
block|}
struct|;
comment|// Element of GdbHashTab hash table.
struct|struct
name|GdbSymbol
block|{
name|GdbSymbol
argument_list|(
argument|uint32_t Hash
argument_list|,
argument|size_t Offset
argument_list|)
block|:
name|NameHash
argument_list|(
name|Hash
argument_list|)
operator|,
name|NameOffset
argument_list|(
argument|Offset
argument_list|)
block|{}
name|uint32_t
name|NameHash
expr_stmt|;
name|size_t
name|NameOffset
decl_stmt|;
name|size_t
name|CuVectorIndex
decl_stmt|;
block|}
struct|;
comment|// This class manages the hashed symbol table for the .gdb_index section.
comment|// The hash value for a table entry is computed by applying an iterative hash
comment|// function to the symbol's name.
name|class
name|GdbHashTab
name|final
block|{
name|public
label|:
name|std
operator|::
name|pair
operator|<
name|bool
operator|,
name|GdbSymbol
operator|*
operator|>
name|add
argument_list|(
argument|uint32_t Hash
argument_list|,
argument|size_t Offset
argument_list|)
expr_stmt|;
name|void
name|finalizeContents
parameter_list|()
function_decl|;
name|size_t
name|getCapacity
parameter_list|()
block|{
return|return
name|Table
operator|.
name|size
argument_list|()
return|;
block|}
name|GdbSymbol
modifier|*
name|getSymbol
parameter_list|(
name|size_t
name|I
parameter_list|)
block|{
return|return
name|Table
index|[
name|I
index|]
return|;
block|}
name|private
label|:
name|llvm
operator|::
name|DenseMap
operator|<
name|size_t
operator|,
name|GdbSymbol
operator|*
operator|>
name|Map
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|GdbSymbol
operator|*
operator|>
name|Table
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace elf
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

