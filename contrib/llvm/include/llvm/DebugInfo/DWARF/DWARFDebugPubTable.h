begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugPubTable.h -------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGPUBTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFDEBUGPUBTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// Represents structure for holding and parsing .debug_pub* tables.
name|class
name|DWARFDebugPubTable
block|{
name|public
label|:
struct|struct
name|Entry
block|{
comment|/// Section offset from the beginning of the compilation unit.
name|uint32_t
name|SecOffset
decl_stmt|;
comment|/// An entry of the various gnu_pub* debug sections.
name|dwarf
operator|::
name|PubIndexEntryDescriptor
name|Descriptor
expr_stmt|;
comment|/// The name of the object as given by the DW_AT_name attribute of the
comment|/// referenced DIE.
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
block|}
struct|;
comment|/// Each table consists of sets of variable length entries. Each set describes
comment|/// the names of global objects and functions, or global types, respectively,
comment|/// whose definitions are represented by debugging information entries owned
comment|/// by a single compilation unit.
struct|struct
name|Set
block|{
comment|/// The total length of the entries for that set, not including the length
comment|/// field itself.
name|uint32_t
name|Length
decl_stmt|;
comment|/// This number is specific to the name lookup table and is independent of
comment|/// the DWARF version number.
name|uint16_t
name|Version
decl_stmt|;
comment|/// The offset from the beginning of the .debug_info section of the
comment|/// compilation unit header referenced by the set.
name|uint32_t
name|Offset
decl_stmt|;
comment|/// The size in bytes of the contents of the .debug_info section generated
comment|/// to represent that compilation unit.
name|uint32_t
name|Size
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|Entries
expr_stmt|;
block|}
struct|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|Set
operator|>
name|Sets
expr_stmt|;
comment|/// gnu styled tables contains additional information.
comment|/// This flag determines whether or not section we parse is debug_gnu* table.
name|bool
name|GnuStyle
decl_stmt|;
name|public
label|:
name|DWARFDebugPubTable
argument_list|(
argument|StringRef Data
argument_list|,
argument|bool LittleEndian
argument_list|,
argument|bool GnuStyle
argument_list|)
empty_stmt|;
name|void
name|dump
argument_list|(
name|StringRef
name|Name
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|ArrayRef
operator|<
name|Set
operator|>
name|getData
argument_list|()
block|{
return|return
name|Sets
return|;
block|}
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
comment|// LLVM_DEBUGINFO_DWARF_DWARFDEBUGPUBTABLE_H
end_comment

end_unit

