begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFGdbIndex.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFGDBINDEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFGDBINDEX_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|class
name|DWARFGdbIndex
block|{
name|uint32_t
name|Version
decl_stmt|;
name|uint32_t
name|CuListOffset
decl_stmt|;
name|uint32_t
name|AddressAreaOffset
decl_stmt|;
name|uint32_t
name|SymbolTableOffset
decl_stmt|;
name|uint32_t
name|ConstantPoolOffset
decl_stmt|;
struct|struct
name|CompUnitEntry
block|{
name|uint64_t
name|Offset
decl_stmt|;
comment|/// Offset of a CU in the .debug_info section.
name|uint64_t
name|Length
decl_stmt|;
comment|/// Length of that CU.
block|}
struct|;
name|SmallVector
operator|<
name|CompUnitEntry
operator|,
literal|0
operator|>
name|CuList
expr_stmt|;
struct|struct
name|AddressEntry
block|{
name|uint64_t
name|LowAddress
decl_stmt|;
comment|/// The low address.
name|uint64_t
name|HighAddress
decl_stmt|;
comment|/// The high address.
name|uint32_t
name|CuIndex
decl_stmt|;
comment|/// The CU index.
block|}
struct|;
name|SmallVector
operator|<
name|AddressEntry
operator|,
literal|0
operator|>
name|AddressArea
expr_stmt|;
struct|struct
name|SymTableEntry
block|{
name|uint32_t
name|NameOffset
decl_stmt|;
comment|/// Offset of the symbol's name in the constant pool.
name|uint32_t
name|VecOffset
decl_stmt|;
comment|/// Offset of the CU vector in the constant pool.
block|}
struct|;
name|SmallVector
operator|<
name|SymTableEntry
operator|,
literal|0
operator|>
name|SymbolTable
expr_stmt|;
comment|/// Each value is CU index + attributes.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|SmallVector
operator|<
name|uint32_t
operator|,
literal|0
operator|>>
operator|,
literal|0
operator|>
name|ConstantPoolVectors
expr_stmt|;
name|StringRef
name|ConstantPoolStrings
decl_stmt|;
name|uint32_t
name|StringPoolOffset
decl_stmt|;
name|void
name|dumpCUList
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dumpAddressArea
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dumpSymbolTable
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dumpConstantPool
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|bool
name|parseImpl
parameter_list|(
name|DataExtractor
name|Data
parameter_list|)
function_decl|;
name|public
label|:
name|void
name|dump
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|parse
parameter_list|(
name|DataExtractor
name|Data
parameter_list|)
function_decl|;
name|bool
name|HasContent
init|=
name|false
decl_stmt|;
name|bool
name|HasError
init|=
name|false
decl_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_DEBUGINFO_DWARF_DWARFGDBINDEX_H
end_comment

end_unit

