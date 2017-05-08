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
comment|/// Some of the values are stored in bitfields.  Since this needs to be portable
comment|/// across compilers and architectures (big / little endian in particular) we
comment|/// can't use the actual structures below, but must instead do the shifting
comment|/// and masking ourselves.  The struct definitions are provided for reference.
struct|struct
name|DbiFlags
block|{
comment|///  uint16_t IncrementalLinking : 1; // True if linked incrementally
comment|///  uint16_t IsStripped : 1;         // True if private symbols were
comment|///  stripped.
comment|///  uint16_t HasCTypes : 1;          // True if linked with /debug:ctypes.
comment|///  uint16_t Reserved : 13;
specifier|static
specifier|const
name|uint16_t
name|FlagIncrementalMask
init|=
literal|0x0001
decl_stmt|;
specifier|static
specifier|const
name|uint16_t
name|FlagStrippedMask
init|=
literal|0x0002
decl_stmt|;
specifier|static
specifier|const
name|uint16_t
name|FlagHasCTypesMask
init|=
literal|0x0004
decl_stmt|;
block|}
struct|;
struct|struct
name|DbiBuildNo
block|{
comment|///  uint16_t MinorVersion : 8;
comment|///  uint16_t MajorVersion : 7;
comment|///  uint16_t NewVersionFormat : 1;
specifier|static
specifier|const
name|uint16_t
name|BuildMinorMask
init|=
literal|0x00FF
decl_stmt|;
specifier|static
specifier|const
name|uint16_t
name|BuildMinorShift
init|=
literal|0
decl_stmt|;
specifier|static
specifier|const
name|uint16_t
name|BuildMajorMask
init|=
literal|0x7F00
decl_stmt|;
specifier|static
specifier|const
name|uint16_t
name|BuildMajorShift
init|=
literal|8
decl_stmt|;
block|}
struct|;
comment|/// The fixed size header that appears at the beginning of the DBI Stream.
struct|struct
name|DbiStreamHeader
block|{
name|support
operator|::
name|little32_t
name|VersionSignature
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|VersionHeader
expr_stmt|;
comment|/// How "old" is this DBI Stream. Should match the age of the PDB InfoStream.
name|support
operator|::
name|ulittle32_t
name|Age
expr_stmt|;
comment|/// Global symbol stream #
name|support
operator|::
name|ulittle16_t
name|GlobalSymbolStreamIndex
expr_stmt|;
comment|/// See DbiBuildNo structure.
name|support
operator|::
name|ulittle16_t
name|BuildNumber
expr_stmt|;
comment|/// Public symbols stream #
name|support
operator|::
name|ulittle16_t
name|PublicSymbolStreamIndex
expr_stmt|;
comment|/// version of mspdbNNN.dll
name|support
operator|::
name|ulittle16_t
name|PdbDllVersion
expr_stmt|;
comment|/// Symbol records stream #
name|support
operator|::
name|ulittle16_t
name|SymRecordStreamIndex
expr_stmt|;
comment|/// rbld number of mspdbNNN.dll
name|support
operator|::
name|ulittle16_t
name|PdbDllRbld
expr_stmt|;
comment|/// Size of module info stream
name|support
operator|::
name|little32_t
name|ModiSubstreamSize
expr_stmt|;
comment|/// Size of sec. contrib stream
name|support
operator|::
name|little32_t
name|SecContrSubstreamSize
expr_stmt|;
comment|/// Size of sec. map substream
name|support
operator|::
name|little32_t
name|SectionMapSize
expr_stmt|;
comment|/// Size of file info substream
name|support
operator|::
name|little32_t
name|FileInfoSize
expr_stmt|;
comment|/// Size of type server map
name|support
operator|::
name|little32_t
name|TypeServerSize
expr_stmt|;
comment|/// Index of MFC Type Server
name|support
operator|::
name|ulittle32_t
name|MFCTypeServerIndex
expr_stmt|;
comment|/// Size of DbgHeader info
name|support
operator|::
name|little32_t
name|OptionalDbgHdrSize
expr_stmt|;
comment|/// Size of EC stream (what is EC?)
name|support
operator|::
name|little32_t
name|ECSubstreamSize
expr_stmt|;
comment|/// See DbiFlags enum.
name|support
operator|::
name|ulittle16_t
name|Flags
expr_stmt|;
comment|/// See PDB_MachineType enum.
name|support
operator|::
name|ulittle16_t
name|MachineType
expr_stmt|;
comment|/// Pad to 64 bytes
name|support
operator|::
name|ulittle32_t
name|Reserved
expr_stmt|;
block|}
struct|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|DbiStreamHeader
argument_list|)
operator|==
literal|64
argument_list|,
literal|"Invalid DbiStreamHeader size!"
argument_list|)
expr_stmt|;
struct|struct
name|SectionContribEntry
block|{
name|support
operator|::
name|ulittle16_t
name|Section
expr_stmt|;
name|char
name|Padding1
index|[
literal|2
index|]
decl_stmt|;
name|support
operator|::
name|little32_t
name|Offset
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
name|ModuleIndex
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
comment|/// The header preceeding the File Info Substream of the DBI stream.
struct|struct
name|FileInfoSubstreamHeader
block|{
comment|/// Total # of modules, should match number of records in the ModuleInfo
comment|/// substream.
name|support
operator|::
name|ulittle16_t
name|NumModules
expr_stmt|;
comment|/// Total # of source files. This value is not accurate because PDB actually
comment|/// supports more than 64k source files, so we ignore it and compute the value
comment|/// from other stream fields.
name|support
operator|::
name|ulittle16_t
name|NumSourceFiles
expr_stmt|;
comment|/// Following this header the File Info Substream is laid out as follows:
comment|///   ulittle16_t ModIndices[NumModules];
comment|///   ulittle16_t ModFileCounts[NumModules];
comment|///   ulittle32_t FileNameOffsets[NumSourceFiles];
comment|///   char Names[][NumSourceFiles];
comment|/// with the caveat that `NumSourceFiles` cannot be trusted, so
comment|/// it is computed by summing the `ModFileCounts` array.
block|}
struct|;
struct|struct
name|ModInfoFlags
block|{
comment|///  uint16_t fWritten : 1;   // True if DbiModuleDescriptor is dirty
comment|///  uint16_t fECEnabled : 1; // Is EC symbolic info present?  (What is EC?)
comment|///  uint16_t unused : 6;     // Reserved
comment|///  uint16_t iTSM : 8;       // Type Server Index for this module
specifier|static
specifier|const
name|uint16_t
name|HasECFlagMask
init|=
literal|0x2
decl_stmt|;
specifier|static
specifier|const
name|uint16_t
name|TypeServerIndexMask
init|=
literal|0xFF00
decl_stmt|;
specifier|static
specifier|const
name|uint16_t
name|TypeServerIndexShift
init|=
literal|8
decl_stmt|;
block|}
struct|;
comment|/// The header preceeding each entry in the Module Info substream of the DBI
comment|/// stream.  Corresponds to the type MODI in the reference implementation.
struct|struct
name|ModuleInfoHeader
block|{
comment|/// Currently opened module. This field is a pointer in the reference
comment|/// implementation, but that won't work on 64-bit systems, and anyway it
comment|/// doesn't make sense to read a pointer from a file. For now it is unused,
comment|/// so just ignore it.
name|support
operator|::
name|ulittle32_t
name|Mod
expr_stmt|;
comment|/// First section contribution of this module.
name|SectionContribEntry
name|SC
decl_stmt|;
comment|/// See ModInfoFlags definition.
name|support
operator|::
name|ulittle16_t
name|Flags
expr_stmt|;
comment|/// Stream Number of module debug info
name|support
operator|::
name|ulittle16_t
name|ModDiStream
expr_stmt|;
comment|/// Size of local symbol debug info in above stream
name|support
operator|::
name|ulittle32_t
name|SymBytes
expr_stmt|;
comment|/// Size of C11 line number info in above stream
name|support
operator|::
name|ulittle32_t
name|C11Bytes
expr_stmt|;
comment|/// Size of C13 line number info in above stream
name|support
operator|::
name|ulittle32_t
name|C13Bytes
expr_stmt|;
comment|/// Number of files contributing to this module
name|support
operator|::
name|ulittle16_t
name|NumFiles
expr_stmt|;
comment|/// Padding so the next field is 4-byte aligned.
name|char
name|Padding1
index|[
literal|2
index|]
decl_stmt|;
comment|/// Array of [0..NumFiles) DBI name buffer offsets.  In the reference
comment|/// implementation this field is a pointer.  But since you can't portably
comment|/// serialize a pointer, on 64-bit platforms they copy all the values except
comment|/// this one into the 32-bit version of the struct and use that for
comment|/// serialization.  Regardless, this field is unused, it is only there to
comment|/// store a pointer that can be accessed at runtime.
name|support
operator|::
name|ulittle32_t
name|FileNameOffs
expr_stmt|;
comment|/// Name Index for src file name
name|support
operator|::
name|ulittle32_t
name|SrcFileNameNI
expr_stmt|;
comment|/// Name Index for path to compiler PDB
name|support
operator|::
name|ulittle32_t
name|PdbFilePathNI
expr_stmt|;
comment|/// Following this header are two zero terminated strings.
comment|/// char ModuleName[];
comment|/// char ObjFileName[];
block|}
struct|;
comment|/// Defines a 128-bit unique identifier.  This maps to a GUID on Windows, but
comment|/// is abstracted here for the purposes of non-Windows platforms that don't have
comment|/// the GUID structure defined.
struct|struct
name|PDB_UniqueId
block|{
name|uint8_t
name|Guid
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|PDB_UniqueId
operator|&
name|LHS
operator|,
specifier|const
name|PDB_UniqueId
operator|&
name|RHS
operator|)
block|{
return|return
literal|0
operator|==
operator|::
name|memcmp
argument_list|(
name|LHS
operator|.
name|Guid
argument_list|,
name|RHS
operator|.
name|Guid
argument_list|,
sizeof|sizeof
argument_list|(
name|LHS
operator|.
name|Guid
argument_list|)
argument_list|)
return|;
block|}
comment|// The header preceeding the global TPI stream.
comment|// This corresponds to `HDR` in PDB/dbi/tpi.h.
struct|struct
name|TpiStreamHeader
block|{
struct|struct
name|EmbeddedBuf
block|{
name|support
operator|::
name|little32_t
name|Off
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Length
expr_stmt|;
block|}
struct|;
name|support
operator|::
name|ulittle32_t
name|Version
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|HeaderSize
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|TypeIndexBegin
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|TypeIndexEnd
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|TypeRecordBytes
expr_stmt|;
comment|// The following members correspond to `TpiHash` in PDB/dbi/tpi.h.
name|support
operator|::
name|ulittle16_t
name|HashStreamIndex
expr_stmt|;
name|support
operator|::
name|ulittle16_t
name|HashAuxStreamIndex
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|HashKeySize
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|NumHashBuckets
expr_stmt|;
name|EmbeddedBuf
name|HashValueBuffer
decl_stmt|;
name|EmbeddedBuf
name|IndexOffsetBuffer
decl_stmt|;
name|EmbeddedBuf
name|HashAdjBuffer
decl_stmt|;
block|}
struct|;
specifier|const
name|uint32_t
name|MinTpiHashBuckets
init|=
literal|0x1000
decl_stmt|;
specifier|const
name|uint32_t
name|MaxTpiHashBuckets
init|=
literal|0x40000
decl_stmt|;
comment|/// The header preceeding the global PDB Stream (Stream 1)
struct|struct
name|InfoStreamHeader
block|{
name|support
operator|::
name|ulittle32_t
name|Version
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Signature
expr_stmt|;
name|support
operator|::
name|ulittle32_t
name|Age
expr_stmt|;
name|PDB_UniqueId
name|Guid
decl_stmt|;
block|}
struct|;
comment|/// The header preceeding the /names stream.
struct|struct
name|PDBStringTableHeader
block|{
name|support
operator|::
name|ulittle32_t
name|Signature
expr_stmt|;
comment|// PDBStringTableSignature
name|support
operator|::
name|ulittle32_t
name|HashVersion
expr_stmt|;
comment|// 1 or 2
name|support
operator|::
name|ulittle32_t
name|ByteSize
expr_stmt|;
comment|// Number of bytes of names buffer.
block|}
struct|;
specifier|const
name|uint32_t
name|PDBStringTableSignature
init|=
literal|0xEFFEEFFE
decl_stmt|;
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

