begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/DwarfAccelTable.h - Dwarf Accelerator Tables -*- C++ -*-==//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains support for writing dwarf accelerator tables.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFACCELTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFACCELTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DIE.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Format.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormattedStream.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// The dwarf accelerator tables are an indirect hash table optimized
end_comment

begin_comment
comment|// for null lookup rather than access to known data. They are output into
end_comment

begin_comment
comment|// an on-disk format that looks like this:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// .-------------.
end_comment

begin_comment
comment|// |  HEADER     |
end_comment

begin_comment
comment|// |-------------|
end_comment

begin_comment
comment|// |  BUCKETS    |
end_comment

begin_comment
comment|// |-------------|
end_comment

begin_comment
comment|// |  HASHES     |
end_comment

begin_comment
comment|// |-------------|
end_comment

begin_comment
comment|// |  OFFSETS    |
end_comment

begin_comment
comment|// |-------------|
end_comment

begin_comment
comment|// |  DATA       |
end_comment

begin_comment
comment|// `-------------'
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// where the header contains a magic number, version, type of hash function,
end_comment

begin_comment
comment|// the number of buckets, total number of hashes, and room for a special
end_comment

begin_comment
comment|// struct of data and the length of that struct.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The buckets contain an index (e.g. 6) into the hashes array. The hashes
end_comment

begin_comment
comment|// section contains all of the 32-bit hash values in contiguous memory, and
end_comment

begin_comment
comment|// the offsets contain the offset into the data area for the particular
end_comment

begin_comment
comment|// hash.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For a lookup example, we could hash a function name and take it modulo the
end_comment

begin_comment
comment|// number of buckets giving us our bucket. From there we take the bucket value
end_comment

begin_comment
comment|// as an index into the hashes table and look at each successive hash as long
end_comment

begin_comment
comment|// as the hash value is still the same modulo result (bucket value) as earlier.
end_comment

begin_comment
comment|// If we have a match we look at that same entry in the offsets table and
end_comment

begin_comment
comment|// grab the offset in the data for our final match.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|DwarfAccelTable
block|{
specifier|static
name|uint32_t
name|HashDJB
parameter_list|(
name|StringRef
name|Str
parameter_list|)
block|{
name|uint32_t
name|h
init|=
literal|5381
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Str
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|h
operator|=
operator|(
operator|(
name|h
operator|<<
literal|5
operator|)
operator|+
name|h
operator|)
operator|+
name|Str
index|[
name|i
index|]
expr_stmt|;
return|return
name|h
return|;
block|}
comment|// Helper function to compute the number of buckets needed based on
comment|// the number of unique hashes.
name|void
name|ComputeBucketCount
parameter_list|(
name|void
parameter_list|)
function_decl|;
struct|struct
name|TableHeader
block|{
name|uint32_t
name|magic
decl_stmt|;
comment|// 'HASH' magic value to allow endian detection
name|uint16_t
name|version
decl_stmt|;
comment|// Version number.
name|uint16_t
name|hash_function
decl_stmt|;
comment|// The hash function enumeration that was used.
name|uint32_t
name|bucket_count
decl_stmt|;
comment|// The number of buckets in this hash table.
name|uint32_t
name|hashes_count
decl_stmt|;
comment|// The total number of unique hash values
comment|// and hash data offsets in this table.
name|uint32_t
name|header_data_len
decl_stmt|;
comment|// The bytes to skip to get to the hash
comment|// indexes (buckets) for correct alignment.
comment|// Also written to disk is the implementation specific header data.
specifier|static
specifier|const
name|uint32_t
name|MagicHash
init|=
literal|0x48415348
decl_stmt|;
name|TableHeader
argument_list|(
argument|uint32_t data_len
argument_list|)
block|:
name|magic
argument_list|(
name|MagicHash
argument_list|)
operator|,
name|version
argument_list|(
literal|1
argument_list|)
operator|,
name|hash_function
argument_list|(
name|dwarf
operator|::
name|DW_hash_function_djb
argument_list|)
operator|,
name|bucket_count
argument_list|(
literal|0
argument_list|)
operator|,
name|hashes_count
argument_list|(
literal|0
argument_list|)
operator|,
name|header_data_len
argument_list|(
argument|data_len
argument_list|)
block|{}
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
block|{
name|O
operator|<<
literal|"Magic: "
operator|<<
name|format
argument_list|(
literal|"0x%x"
argument_list|,
name|magic
argument_list|)
operator|<<
literal|"\n"
operator|<<
literal|"Version: "
operator|<<
name|version
operator|<<
literal|"\n"
operator|<<
literal|"Hash Function: "
operator|<<
name|hash_function
operator|<<
literal|"\n"
operator|<<
literal|"Bucket Count: "
operator|<<
name|bucket_count
operator|<<
literal|"\n"
operator|<<
literal|"Header Data Length: "
operator|<<
name|header_data_len
operator|<<
literal|"\n"
block|;     }
name|void
name|dump
argument_list|()
block|{
name|print
argument_list|(
name|dbgs
argument_list|()
argument_list|)
block|; }
endif|#
directive|endif
block|}
struct|;
name|public
label|:
comment|// The HeaderData describes the form of each set of data. In general this
comment|// is as a list of atoms (atom_count) where each atom contains a type
comment|// (AtomType type) of data, and an encoding form (form). In the case of
comment|// data that is referenced via DW_FORM_ref_* the die_offset_base is
comment|// used to describe the offset for all forms in the list of atoms.
comment|// This also serves as a public interface of sorts.
comment|// When written to disk this will have the form:
comment|//
comment|// uint32_t die_offset_base
comment|// uint32_t atom_count
comment|// atom_count Atoms
comment|// Make these public so that they can be used as a general interface to
comment|// the class.
struct|struct
name|Atom
block|{
name|uint16_t
name|type
decl_stmt|;
comment|// enum AtomType
name|uint16_t
name|form
decl_stmt|;
comment|// DWARF DW_FORM_ defines
name|constexpr
name|Atom
argument_list|(
argument|uint16_t type
argument_list|,
argument|uint16_t form
argument_list|)
block|:
name|type
argument_list|(
name|type
argument_list|)
operator|,
name|form
argument_list|(
argument|form
argument_list|)
block|{}
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
block|{
name|O
operator|<<
literal|"Type: "
operator|<<
name|dwarf
operator|::
name|AtomTypeString
argument_list|(
name|type
argument_list|)
operator|<<
literal|"\n"
operator|<<
literal|"Form: "
operator|<<
name|dwarf
operator|::
name|FormEncodingString
argument_list|(
name|form
argument_list|)
operator|<<
literal|"\n"
block|;     }
name|void
name|dump
argument_list|()
block|{
name|print
argument_list|(
name|dbgs
argument_list|()
argument_list|)
block|; }
endif|#
directive|endif
block|}
struct|;
name|private
label|:
struct|struct
name|TableHeaderData
block|{
name|uint32_t
name|die_offset_base
decl_stmt|;
name|SmallVector
operator|<
name|Atom
operator|,
literal|3
operator|>
name|Atoms
expr_stmt|;
name|TableHeaderData
argument_list|(
argument|ArrayRef<Atom> AtomList
argument_list|,
argument|uint32_t offset =
literal|0
argument_list|)
block|:
name|die_offset_base
argument_list|(
name|offset
argument_list|)
operator|,
name|Atoms
argument_list|(
argument|AtomList.begin()
argument_list|,
argument|AtomList.end()
argument_list|)
block|{}
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
block|{
name|O
operator|<<
literal|"die_offset_base: "
operator|<<
name|die_offset_base
operator|<<
literal|"\n"
block|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Atoms
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
name|Atoms
index|[
name|i
index|]
operator|.
name|print
argument_list|(
name|O
argument_list|)
expr_stmt|;
block|}
name|void
name|dump
parameter_list|()
block|{
name|print
argument_list|(
name|dbgs
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
struct|;
comment|// The data itself consists of a str_offset, a count of the DIEs in the
comment|// hash and the offsets to the DIEs themselves.
comment|// On disk each data section is ended with a 0 KeyType as the end of the
comment|// hash chain.
comment|// On output this looks like:
comment|// uint32_t str_offset
comment|// uint32_t hash_data_count
comment|// HashData[hash_data_count]
name|public
label|:
struct|struct
name|HashDataContents
block|{
specifier|const
name|DIE
modifier|*
name|Die
decl_stmt|;
comment|// Offsets
name|char
name|Flags
decl_stmt|;
comment|// Specific flags to output
name|HashDataContents
argument_list|(
argument|const DIE *D
argument_list|,
argument|char Flags
argument_list|)
block|:
name|Die
argument_list|(
name|D
argument_list|)
operator|,
name|Flags
argument_list|(
argument|Flags
argument_list|)
block|{}
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
block|{
name|O
operator|<<
literal|"  Offset: "
operator|<<
name|Die
operator|->
name|getOffset
argument_list|()
operator|<<
literal|"\n"
block|;
name|O
operator|<<
literal|"  Tag: "
operator|<<
name|dwarf
operator|::
name|TagString
argument_list|(
name|Die
operator|->
name|getTag
argument_list|()
argument_list|)
operator|<<
literal|"\n"
block|;
name|O
operator|<<
literal|"  Flags: "
operator|<<
name|Flags
operator|<<
literal|"\n"
block|;     }
endif|#
directive|endif
block|}
struct|;
name|private
label|:
comment|// String Data
struct|struct
name|DataArray
block|{
name|DwarfStringPoolEntryRef
name|Name
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|HashDataContents
operator|*
operator|>
name|Values
expr_stmt|;
block|}
struct|;
name|friend
struct_decl|struct
name|HashData
struct_decl|;
struct|struct
name|HashData
block|{
name|StringRef
name|Str
decl_stmt|;
name|uint32_t
name|HashValue
decl_stmt|;
name|MCSymbol
modifier|*
name|Sym
decl_stmt|;
name|DwarfAccelTable
operator|::
name|DataArray
operator|&
name|Data
expr_stmt|;
comment|// offsets
name|HashData
argument_list|(
argument|StringRef S
argument_list|,
argument|DwarfAccelTable::DataArray&Data
argument_list|)
block|:
name|Str
argument_list|(
name|S
argument_list|)
operator|,
name|Data
argument_list|(
argument|Data
argument_list|)
block|{
name|HashValue
operator|=
name|DwarfAccelTable
operator|::
name|HashDJB
argument_list|(
name|S
argument_list|)
block|;     }
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
block|{
name|O
operator|<<
literal|"Name: "
operator|<<
name|Str
operator|<<
literal|"\n"
block|;
name|O
operator|<<
literal|"  Hash Value: "
operator|<<
name|format
argument_list|(
literal|"0x%x"
argument_list|,
name|HashValue
argument_list|)
operator|<<
literal|"\n"
block|;
name|O
operator|<<
literal|"  Symbol: "
block|;
if|if
condition|(
name|Sym
condition|)
name|O
operator|<<
operator|*
name|Sym
expr_stmt|;
else|else
name|O
operator|<<
literal|"<none>"
expr_stmt|;
name|O
operator|<<
literal|"\n"
expr_stmt|;
for|for
control|(
name|HashDataContents
modifier|*
name|C
range|:
name|Data
operator|.
name|Values
control|)
block|{
name|O
operator|<<
literal|"  Offset: "
operator|<<
name|C
operator|->
name|Die
operator|->
name|getOffset
argument_list|()
operator|<<
literal|"\n"
expr_stmt|;
name|O
operator|<<
literal|"  Tag: "
operator|<<
name|dwarf
operator|::
name|TagString
argument_list|(
name|C
operator|->
name|Die
operator|->
name|getTag
argument_list|()
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
name|O
operator|<<
literal|"  Flags: "
operator|<<
name|C
operator|->
name|Flags
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
name|void
name|dump
argument_list|()
block|{
name|print
argument_list|(
name|dbgs
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
empty_stmt|;
name|DwarfAccelTable
argument_list|(
specifier|const
name|DwarfAccelTable
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|DwarfAccelTable
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|// Internal Functions
name|void
name|EmitHeader
parameter_list|(
name|AsmPrinter
modifier|*
parameter_list|)
function_decl|;
name|void
name|EmitBuckets
parameter_list|(
name|AsmPrinter
modifier|*
parameter_list|)
function_decl|;
name|void
name|EmitHashes
parameter_list|(
name|AsmPrinter
modifier|*
parameter_list|)
function_decl|;
name|void
name|emitOffsets
parameter_list|(
name|AsmPrinter
modifier|*
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
parameter_list|)
function_decl|;
name|void
name|EmitData
parameter_list|(
name|AsmPrinter
modifier|*
parameter_list|,
name|DwarfDebug
modifier|*
name|D
parameter_list|)
function_decl|;
comment|// Allocator for HashData and HashDataContents.
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
comment|// Output Variables
name|TableHeader
name|Header
decl_stmt|;
name|TableHeaderData
name|HeaderData
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|HashData
operator|*
operator|>
name|Data
expr_stmt|;
typedef|typedef
name|StringMap
operator|<
name|DataArray
operator|,
name|BumpPtrAllocator
operator|&
operator|>
name|StringEntries
expr_stmt|;
name|StringEntries
name|Entries
decl_stmt|;
comment|// Buckets/Hashes/Offsets
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|HashData
operator|*
operator|>
name|HashList
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|HashList
operator|>
name|BucketList
expr_stmt|;
name|BucketList
name|Buckets
decl_stmt|;
name|HashList
name|Hashes
decl_stmt|;
comment|// Public Implementation
name|public
label|:
name|DwarfAccelTable
argument_list|(
name|ArrayRef
operator|<
name|DwarfAccelTable
operator|::
name|Atom
operator|>
argument_list|)
expr_stmt|;
name|void
name|AddName
parameter_list|(
name|DwarfStringPoolEntryRef
name|Name
parameter_list|,
specifier|const
name|DIE
modifier|*
name|Die
parameter_list|,
name|char
name|Flags
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|FinalizeTable
parameter_list|(
name|AsmPrinter
modifier|*
parameter_list|,
name|StringRef
parameter_list|)
function_decl|;
name|void
name|emit
parameter_list|(
name|AsmPrinter
modifier|*
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
parameter_list|,
name|DwarfDebug
modifier|*
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|print
parameter_list|(
name|raw_ostream
modifier|&
name|O
parameter_list|)
function_decl|;
name|void
name|dump
parameter_list|()
block|{
name|print
argument_list|(
name|dbgs
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

