begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lib/ReaderWriter/Native/NativeFileFormat.h -------------------------===//
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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLD_READER_WRITER_NATIVE_NATIVE_FILE_FORMAT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_READER_WRITER_NATIVE_NATIVE_FILE_FORMAT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
comment|//
comment|// Overview:
comment|//
comment|// The number one design goal of this file format is enable the linker to
comment|// read object files into in-memory Atom objects extremely quickly.
comment|// The second design goal is to enable future modifications to the
comment|// Atom attribute model.
comment|//
comment|// The llvm native object file format is not like traditional object file
comment|// formats (e.g. ELF, COFF, mach-o).  There is no symbol table and no
comment|// sections.  Instead the file is essentially an array of archived Atoms.
comment|// It is *not* serialized Atoms which would require deserialization into
comment|// in memory objects.  Instead it is an array of read-only info about each
comment|// Atom.  The NativeReader bulk creates in-memory Atoms which just have
comment|// an ivar which points to the read-only info for that Atom. No additional
comment|// processing is done to construct the in-memory Atoms. All Atom attribute
comment|// getter methods are virtual calls which dig up the info they need from the
comment|// ivar data.
comment|//
comment|// To support the gradual evolution of Atom attributes, the Atom read-only
comment|// data is versioned. The NativeReader chooses which in-memory Atom class
comment|// to use based on the version. What this means is that if new attributes
comment|// are added (or changed) in the Atom model, a new native atom class and
comment|// read-only atom info struct needs to be defined.  Then, all the existing
comment|// native reader atom classes need to be modified to do their best effort
comment|// to map their old style read-only data to the new Atom model.  At some point
comment|// some classes to support old versions may be dropped.
comment|//
comment|//
comment|// Details:
comment|//
comment|// The native object file format consists of a header that specifies the
comment|// endianness of the file and the architecture along with a list of "chunks"
comment|// in the file.  A Chunk is simply a tagged range of the file.  There is
comment|// one chunk for the array of atom infos.  There is another chunk for the
comment|// string pool, and another for the content pool.
comment|//
comment|// It turns out there most atoms have very similar sets of attributes, only
comment|// the name and content attribute vary. To exploit this fact to reduce the file
comment|// size, the atom read-only info contains just the name and content info plus
comment|// a reference to which attribute set it uses.  The attribute sets are stored
comment|// in another chunk.
comment|//
comment|//
comment|// An entry in the NativeFileHeader that describes one chunk of the file.
comment|//
struct|struct
name|NativeChunk
block|{
name|uint32_t
name|signature
decl_stmt|;
name|uint32_t
name|fileOffset
decl_stmt|;
name|uint32_t
name|fileSize
decl_stmt|;
name|uint32_t
name|elementCount
decl_stmt|;
block|}
struct|;
comment|//
comment|// The header in a native object file
comment|//
struct|struct
name|NativeFileHeader
block|{
name|uint8_t
name|magic
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|endian
decl_stmt|;
name|uint32_t
name|architecture
decl_stmt|;
name|uint32_t
name|fileSize
decl_stmt|;
name|uint32_t
name|chunkCount
decl_stmt|;
comment|// NativeChunk chunks[]
block|}
struct|;
comment|//
comment|// Possible values for NativeChunk.signature field
comment|//
enum|enum
name|NativeChunkSignatures
block|{
name|NCS_DefinedAtomsV1
init|=
literal|1
block|,
name|NCS_AttributesArrayV1
init|=
literal|2
block|,
name|NCS_AbsoluteAttributesV1
init|=
literal|12
block|,
name|NCS_UndefinedAtomsV1
init|=
literal|3
block|,
name|NCS_SharedLibraryAtomsV1
init|=
literal|4
block|,
name|NCS_AbsoluteAtomsV1
init|=
literal|5
block|,
name|NCS_Strings
init|=
literal|6
block|,
name|NCS_ReferencesArrayV1
init|=
literal|7
block|,
name|NCS_ReferencesArrayV2
init|=
literal|8
block|,
name|NCS_TargetsTable
init|=
literal|9
block|,
name|NCS_AddendsTable
init|=
literal|10
block|,
name|NCS_Content
init|=
literal|11
block|, }
enum|;
comment|//
comment|// The 16-bytes at the start of a native object file
comment|//
define|#
directive|define
name|NATIVE_FILE_HEADER_MAGIC
value|"llvm nat obj v1 "
comment|//
comment|// Possible values for the NativeFileHeader.endian field
comment|//
enum|enum
block|{
name|NFH_BigEndian
init|=
literal|0x42696745
block|,
name|NFH_LittleEndian
init|=
literal|0x4574696c
block|}
enum|;
comment|//
comment|// Possible values for the NativeFileHeader.architecture field
comment|//
enum|enum
block|{
name|NFA_x86
init|=
literal|1
block|,
name|NFA_x86_64
init|=
literal|2
block|,
name|NFA_armv6
init|=
literal|3
block|,
name|NFA_armv7
init|=
literal|4
block|, }
enum|;
comment|//
comment|// The NCS_DefinedAtomsV1 chunk contains an array of these structs
comment|//
struct|struct
name|NativeDefinedAtomIvarsV1
block|{
name|uint32_t
name|nameOffset
decl_stmt|;
name|uint32_t
name|attributesOffset
decl_stmt|;
name|uint32_t
name|referencesStartIndex
decl_stmt|;
name|uint32_t
name|referencesCount
decl_stmt|;
name|uint32_t
name|contentOffset
decl_stmt|;
name|uint32_t
name|contentSize
decl_stmt|;
name|uint64_t
name|sectionSize
decl_stmt|;
block|}
struct|;
comment|//
comment|// The NCS_AttributesArrayV1 chunk contains an array of these structs
comment|//
struct|struct
name|NativeAtomAttributesV1
block|{
name|uint32_t
name|sectionNameOffset
decl_stmt|;
name|uint16_t
name|align2
decl_stmt|;
name|uint16_t
name|alignModulus
decl_stmt|;
name|uint8_t
name|scope
decl_stmt|;
name|uint8_t
name|interposable
decl_stmt|;
name|uint8_t
name|merge
decl_stmt|;
name|uint8_t
name|contentType
decl_stmt|;
name|uint8_t
name|sectionChoice
decl_stmt|;
name|uint8_t
name|deadStrip
decl_stmt|;
name|uint8_t
name|dynamicExport
decl_stmt|;
name|uint8_t
name|permissions
decl_stmt|;
name|uint8_t
name|alias
decl_stmt|;
name|uint8_t
name|codeModel
decl_stmt|;
block|}
struct|;
comment|//
comment|// The NCS_UndefinedAtomsV1 chunk contains an array of these structs
comment|//
struct|struct
name|NativeUndefinedAtomIvarsV1
block|{
name|uint32_t
name|nameOffset
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|fallbackNameOffset
decl_stmt|;
block|}
struct|;
comment|//
comment|// The NCS_SharedLibraryAtomsV1 chunk contains an array of these structs
comment|//
struct|struct
name|NativeSharedLibraryAtomIvarsV1
block|{
name|uint64_t
name|size
decl_stmt|;
name|uint32_t
name|nameOffset
decl_stmt|;
name|uint32_t
name|loadNameOffset
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
comment|//
comment|// The NCS_AbsoluteAtomsV1 chunk contains an array of these structs
comment|//
struct|struct
name|NativeAbsoluteAtomIvarsV1
block|{
name|uint32_t
name|nameOffset
decl_stmt|;
name|uint32_t
name|attributesOffset
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|uint64_t
name|value
decl_stmt|;
block|}
struct|;
comment|//
comment|// The NCS_ReferencesArrayV1 chunk contains an array of these structs
comment|//
struct|struct
name|NativeReferenceIvarsV1
block|{
enum|enum
block|{
name|noTarget
init|=
name|UINT16_MAX
block|}
enum|;
name|uint32_t
name|offsetInAtom
decl_stmt|;
name|uint16_t
name|kindValue
decl_stmt|;
name|uint8_t
name|kindNamespace
decl_stmt|;
name|uint8_t
name|kindArch
decl_stmt|;
name|uint16_t
name|targetIndex
decl_stmt|;
name|uint16_t
name|addendIndex
decl_stmt|;
block|}
struct|;
comment|//
comment|// The NCS_ReferencesArrayV2 chunk contains an array of these structs
comment|//
struct|struct
name|NativeReferenceIvarsV2
block|{
enum_decl|enum :
name|unsigned
block|{
name|noTarget
init|=
name|UINT32_MAX
block|}
enum_decl|;
name|uint64_t
name|offsetInAtom
decl_stmt|;
name|int64_t
name|addend
decl_stmt|;
name|uint16_t
name|kindValue
decl_stmt|;
name|uint8_t
name|kindNamespace
decl_stmt|;
name|uint8_t
name|kindArch
decl_stmt|;
name|uint32_t
name|targetIndex
decl_stmt|;
name|uint32_t
name|tag
decl_stmt|;
block|}
struct|;
comment|//
comment|// The NCS_TargetsTable chunk contains an array of uint32_t entries.
comment|// The C++ class Reference has a target() method that returns a
comment|// pointer to another Atom.  We can't have pointers in object files,
comment|// so instead  NativeReferenceIvarsV1 contains an index to the target.
comment|// The index is into this NCS_TargetsTable of uint32_t entries.
comment|// The values in this table are the index of the (target) atom in this file.
comment|// For DefinedAtoms the value is from 0 to NCS_DefinedAtomsV1.elementCount.
comment|// For UndefinedAtoms the value is from NCS_DefinedAtomsV1.elementCount to
comment|// NCS_DefinedAtomsV1.elementCount+NCS_UndefinedAtomsV1.elementCount.
comment|//
comment|//
comment|// The NCS_AddendsTable chunk contains an array of int64_t entries.
comment|// If we allocated space for addends directly in NativeReferenceIvarsV1
comment|// it would double the size of that struct.  But since addends are rare,
comment|// we instead just keep a pool of addends and have NativeReferenceIvarsV1
comment|// (if it needs an addend) just store the index (into the pool) of the
comment|// addend it needs.
comment|//
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_READER_WRITER_NATIVE_NATIVE_FILE_FORMAT_H
end_comment

end_unit

