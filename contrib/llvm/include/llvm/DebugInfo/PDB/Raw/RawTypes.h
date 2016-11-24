begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RawTypes.h -----------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_RAWTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_RAWTYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
comment|// This struct is defined as "SO" in langapi/include/pdb.h.
struct|struct
name|SectionOffset
block|{
name|support
operator|::
name|ulittle32_t
name|Off
expr_stmt|;
name|support
operator|::
name|ulittle16_t
name|Isect
expr_stmt|;
name|char
name|Padding
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
comment|// This is HRFile.
struct|struct
name|PSHashRecord
block|{
name|support
operator|::
name|ulittle32_t
name|Off
expr_stmt|;
comment|// Offset in the symbol record stream
name|support
operator|::
name|ulittle32_t
name|CRef
expr_stmt|;
block|}
struct|;
comment|// This struct is defined as `SC` in include/dbicommon.h
struct|struct
name|SectionContrib
block|{
name|support
operator|::
name|ulittle16_t
name|ISect
expr_stmt|;
name|char
name|Padding
index|[
literal|2
index|]
decl_stmt|;
name|support
operator|::
name|little32_t
name|Off
expr_stmt|;
name|support
operator|::
name|little32_t
name|Size
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Characteristics
expr_stmt|;
name|support
operator|::
name|ulittle16_t
name|Imod
expr_stmt|;
name|char
name|Padding2
index|[
literal|2
index|]
decl_stmt|;
name|support
operator|::
name|ulittle32_t
name|DataCrc
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|RelocCrc
expr_stmt|;
block|}
struct|;
comment|// This struct is defined as `SC2` in include/dbicommon.h
struct|struct
name|SectionContrib2
block|{
comment|// To guarantee SectionContrib2 is standard layout, we cannot use inheritance.
name|SectionContrib
name|Base
decl_stmt|;
name|support
operator|::
name|ulittle32_t
name|ISectCoff
expr_stmt|;
block|}
struct|;
comment|// This corresponds to the `OMFSegMap` structure.
struct|struct
name|SecMapHeader
block|{
name|support
operator|::
name|ulittle16_t
name|SecCount
expr_stmt|;
comment|// Number of segment descriptors in table
name|support
operator|::
name|ulittle16_t
name|SecCountLog
expr_stmt|;
comment|// Number of logical segment descriptors
block|}
struct|;
comment|// This corresponds to the `OMFSegMapDesc` structure.  The definition is not
comment|// present in the reference implementation, but the layout is derived from
comment|// code that accesses the fields.
struct|struct
name|SecMapEntry
block|{
name|support
operator|::
name|ulittle16_t
name|Flags
expr_stmt|;
comment|// Descriptor flags.  See OMFSegDescFlags
name|support
operator|::
name|ulittle16_t
name|Ovl
expr_stmt|;
comment|// Logical overlay number.
name|support
operator|::
name|ulittle16_t
name|Group
expr_stmt|;
comment|// Group index into descriptor array.
name|support
operator|::
name|ulittle16_t
name|Frame
expr_stmt|;
name|support
operator|::
name|ulittle16_t
name|SecName
expr_stmt|;
comment|// Byte index of the segment or group name
comment|// in the sstSegName table, or 0xFFFF.
name|support
operator|::
name|ulittle16_t
name|ClassName
expr_stmt|;
comment|// Byte index of the class name in the
comment|// sstSegName table, or 0xFFFF.
name|support
operator|::
name|ulittle32_t
name|Offset
expr_stmt|;
comment|// Byte offset of the logical segment
comment|// within the specified physical segment.
comment|// If group is set in flags, offset is the
comment|// offset of the group.
name|support
operator|::
name|ulittle32_t
name|SecByteLength
expr_stmt|;
comment|// Byte count of the segment or group.
block|}
struct|;
comment|// Used for serialized hash table in TPI stream.
comment|// In the reference, it is an array of TI and cbOff pair.
struct|struct
name|TypeIndexOffset
block|{
name|codeview
operator|::
name|TypeIndex
name|Type
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Offset
expr_stmt|;
block|}
struct|;
block|}
comment|// namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

