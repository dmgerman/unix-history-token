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
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|InputSection
expr_stmt|;
comment|// Struct represents single entry of address area of gdb index.
name|template
operator|<
name|class
name|ELFT
operator|>
expr|struct
name|AddressEntry
block|{
name|InputSectionBase
operator|<
name|ELFT
operator|>
operator|*
name|Section
block|;
name|uint64_t
name|LowAddress
block|;
name|uint64_t
name|HighAddress
block|;
name|size_t
name|CuIndex
block|; }
expr_stmt|;
comment|// GdbIndexBuilder is a helper class used for extracting data required
comment|// for building .gdb_index section from objects.
name|template
operator|<
name|class
name|ELFT
operator|>
name|class
name|GdbIndexBuilder
operator|:
name|public
name|llvm
operator|::
name|LoadedObjectInfo
block|{
typedef|typedef
name|typename
name|ELFT
operator|::
name|uint
name|uintX_t
expr_stmt|;
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|DebugInfoSec
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|DWARFContext
operator|>
name|Dwarf
expr_stmt|;
name|public
label|:
name|GdbIndexBuilder
argument_list|(
name|InputSection
operator|<
name|ELFT
operator|>
operator|*
name|DebugInfoSec
argument_list|)
expr_stmt|;
comment|// Extracts the compilation units. Each first element of pair is a offset of a
comment|// CU in the .debug_info section and second is the length of that CU.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uintX_t
operator|,
name|uintX_t
operator|>>
name|readCUList
argument_list|()
expr_stmt|;
comment|// Extracts the vector of address area entries. Accepts global index of last
comment|// parsed CU.
name|std
operator|::
name|vector
operator|<
name|AddressEntry
operator|<
name|ELFT
operator|>>
name|readAddressArea
argument_list|(
argument|size_t CurrentCU
argument_list|)
expr_stmt|;
comment|// Method extracts public names and types. It returns list of name and
comment|// gnu_pub* kind pairs.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|,
name|uint8_t
operator|>>
name|readPubNamesAndTypes
argument_list|()
expr_stmt|;
name|private
label|:
comment|// Method returns section file offset as a load addres for DWARF parser. That
comment|// allows to find the target section index for address ranges.
name|uint64_t
name|getSectionLoadAddress
argument_list|(
specifier|const
name|llvm
operator|::
name|object
operator|::
name|SectionRef
operator|&
name|Sec
argument_list|)
decl|const
name|override
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|LoadedObjectInfo
operator|>
name|clone
argument_list|()
specifier|const
name|override
expr_stmt|;
block|}
empty_stmt|;
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
name|void
name|expand
parameter_list|()
function_decl|;
name|GdbSymbol
modifier|*
modifier|*
name|findSlot
parameter_list|(
name|uint32_t
name|Hash
parameter_list|,
name|size_t
name|Offset
parameter_list|)
function_decl|;
name|llvm
operator|::
name|BumpPtrAllocator
name|Alloc
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
comment|// Size keeps the amount of filled entries in Table.
name|size_t
name|Size
init|=
literal|0
decl_stmt|;
comment|// Initial size must be a power of 2.
specifier|static
specifier|const
name|int32_t
name|InitialSize
init|=
literal|1024
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace elf
end_comment

begin_comment
unit|}
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

