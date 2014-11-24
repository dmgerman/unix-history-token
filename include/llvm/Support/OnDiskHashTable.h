begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OnDiskHashTable.h - On-Disk Hash Table Implementation --*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines facilities for reading and writing on-disk hash tables.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_ON_DISK_HASH_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ON_DISK_HASH_TABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/EndianStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Host.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Generates an on disk hash table.
comment|///
comment|/// This needs an \c Info that handles storing values into the hash table's
comment|/// payload and computes the hash for a given key. This should provide the
comment|/// following interface:
comment|///
comment|/// \code
comment|/// class ExampleInfo {
comment|/// public:
comment|///   typedef ExampleKey key_type;   // Must be copy constructible
comment|///   typedef ExampleKey&key_type_ref;
comment|///   typedef ExampleData data_type; // Must be copy constructible
comment|///   typedef ExampleData&data_type_ref;
comment|///   typedef uint32_t hash_value_type; // The type the hash function returns.
comment|///   typedef uint32_t offset_type; // The type for offsets into the table.
comment|///
comment|///   /// Calculate the hash for Key
comment|///   static hash_value_type ComputeHash(key_type_ref Key);
comment|///   /// Return the lengths, in bytes, of the given Key/Data pair.
comment|///   static std::pair<offset_type, offset_type>
comment|///   EmitKeyDataLength(raw_ostream&Out, key_type_ref Key, data_type_ref Data);
comment|///   /// Write Key to Out.  KeyLen is the length from EmitKeyDataLength.
comment|///   static void EmitKey(raw_ostream&Out, key_type_ref Key,
comment|///                       offset_type KeyLen);
comment|///   /// Write Data to Out.  DataLen is the length from EmitKeyDataLength.
comment|///   static void EmitData(raw_ostream&Out, key_type_ref Key,
comment|///                        data_type_ref Data, offset_type DataLen);
comment|/// };
comment|/// \endcode
name|template
operator|<
name|typename
name|Info
operator|>
name|class
name|OnDiskChainedHashTableGenerator
block|{
comment|/// \brief A single item in the hash table.
name|class
name|Item
block|{
name|public
operator|:
name|typename
name|Info
operator|::
name|key_type
name|Key
block|;
name|typename
name|Info
operator|::
name|data_type
name|Data
block|;
name|Item
operator|*
name|Next
block|;
specifier|const
name|typename
name|Info
operator|::
name|hash_value_type
name|Hash
block|;
name|Item
argument_list|(
argument|typename Info::key_type_ref Key
argument_list|,
argument|typename Info::data_type_ref Data
argument_list|,
argument|Info&InfoObj
argument_list|)
operator|:
name|Key
argument_list|(
name|Key
argument_list|)
block|,
name|Data
argument_list|(
name|Data
argument_list|)
block|,
name|Next
argument_list|(
name|nullptr
argument_list|)
block|,
name|Hash
argument_list|(
argument|InfoObj.ComputeHash(Key)
argument_list|)
block|{}
block|}
block|;
typedef|typedef
name|typename
name|Info
operator|::
name|offset_type
name|offset_type
expr_stmt|;
name|offset_type
name|NumBuckets
expr_stmt|;
name|offset_type
name|NumEntries
decl_stmt|;
name|llvm
operator|::
name|SpecificBumpPtrAllocator
operator|<
name|Item
operator|>
name|BA
expr_stmt|;
comment|/// \brief A linked list of values in a particular hash bucket.
name|class
name|Bucket
block|{
name|public
label|:
name|offset_type
name|Off
decl_stmt|;
name|Item
modifier|*
name|Head
decl_stmt|;
name|unsigned
name|Length
decl_stmt|;
name|Bucket
argument_list|()
block|{}
block|}
empty_stmt|;
name|Bucket
modifier|*
name|Buckets
decl_stmt|;
name|private
label|:
comment|/// \brief Insert an item into the appropriate hash bucket.
name|void
name|insert
parameter_list|(
name|Bucket
modifier|*
name|Buckets
parameter_list|,
name|size_t
name|Size
parameter_list|,
name|Item
modifier|*
name|E
parameter_list|)
block|{
name|Bucket
modifier|&
name|B
init|=
name|Buckets
index|[
name|E
operator|->
name|Hash
operator|&
operator|(
name|Size
operator|-
literal|1
operator|)
index|]
decl_stmt|;
name|E
operator|->
name|Next
operator|=
name|B
operator|.
name|Head
expr_stmt|;
operator|++
name|B
operator|.
name|Length
expr_stmt|;
name|B
operator|.
name|Head
operator|=
name|E
expr_stmt|;
block|}
comment|/// \brief Resize the hash table, moving the old entries into the new buckets.
name|void
name|resize
parameter_list|(
name|size_t
name|NewSize
parameter_list|)
block|{
name|Bucket
modifier|*
name|NewBuckets
init|=
operator|(
name|Bucket
operator|*
operator|)
name|std
operator|::
name|calloc
argument_list|(
name|NewSize
argument_list|,
sizeof|sizeof
argument_list|(
name|Bucket
argument_list|)
argument_list|)
decl_stmt|;
comment|// Populate NewBuckets with the old entries.
for|for
control|(
name|size_t
name|I
init|=
literal|0
init|;
name|I
operator|<
name|NumBuckets
condition|;
operator|++
name|I
control|)
for|for
control|(
name|Item
modifier|*
name|E
init|=
name|Buckets
index|[
name|I
index|]
operator|.
name|Head
init|;
name|E
condition|;
control|)
block|{
name|Item
modifier|*
name|N
init|=
name|E
operator|->
name|Next
decl_stmt|;
name|E
operator|->
name|Next
operator|=
name|nullptr
expr_stmt|;
name|insert
argument_list|(
name|NewBuckets
argument_list|,
name|NewSize
argument_list|,
name|E
argument_list|)
expr_stmt|;
name|E
operator|=
name|N
expr_stmt|;
block|}
name|free
argument_list|(
name|Buckets
argument_list|)
expr_stmt|;
name|NumBuckets
operator|=
name|NewSize
expr_stmt|;
name|Buckets
operator|=
name|NewBuckets
expr_stmt|;
block|}
name|public
label|:
comment|/// \brief Insert an entry into the table.
name|void
name|insert
argument_list|(
name|typename
name|Info
operator|::
name|key_type_ref
name|Key
argument_list|,
name|typename
name|Info
operator|::
name|data_type_ref
name|Data
argument_list|)
block|{
name|Info
name|InfoObj
decl_stmt|;
name|insert
argument_list|(
name|Key
argument_list|,
name|Data
argument_list|,
name|InfoObj
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Insert an entry into the table.
comment|///
comment|/// Uses the provided Info instead of a stack allocated one.
name|void
name|insert
argument_list|(
name|typename
name|Info
operator|::
name|key_type_ref
name|Key
argument_list|,
name|typename
name|Info
operator|::
name|data_type_ref
name|Data
argument_list|,
name|Info
operator|&
name|InfoObj
argument_list|)
block|{
operator|++
name|NumEntries
expr_stmt|;
if|if
condition|(
literal|4
operator|*
name|NumEntries
operator|>=
literal|3
operator|*
name|NumBuckets
condition|)
name|resize
argument_list|(
name|NumBuckets
operator|*
literal|2
argument_list|)
expr_stmt|;
name|insert
argument_list|(
name|Buckets
argument_list|,
name|NumBuckets
argument_list|,
name|new
argument_list|(
argument|BA.Allocate()
argument_list|)
name|Item
argument_list|(
name|Key
argument_list|,
name|Data
argument_list|,
name|InfoObj
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Emit the table to Out, which must not be at offset 0.
name|offset_type
name|Emit
parameter_list|(
name|raw_ostream
modifier|&
name|Out
parameter_list|)
block|{
name|Info
name|InfoObj
decl_stmt|;
return|return
name|Emit
argument_list|(
name|Out
argument_list|,
name|InfoObj
argument_list|)
return|;
block|}
comment|/// \brief Emit the table to Out, which must not be at offset 0.
comment|///
comment|/// Uses the provided Info instead of a stack allocated one.
name|offset_type
name|Emit
parameter_list|(
name|raw_ostream
modifier|&
name|Out
parameter_list|,
name|Info
modifier|&
name|InfoObj
parameter_list|)
block|{
name|using
name|namespace
name|llvm
operator|::
name|support
expr_stmt|;
name|endian
operator|::
name|Writer
operator|<
name|little
operator|>
name|LE
argument_list|(
name|Out
argument_list|)
expr_stmt|;
comment|// Emit the payload of the table.
for|for
control|(
name|offset_type
name|I
init|=
literal|0
init|;
name|I
operator|<
name|NumBuckets
condition|;
operator|++
name|I
control|)
block|{
name|Bucket
modifier|&
name|B
init|=
name|Buckets
index|[
name|I
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|B
operator|.
name|Head
condition|)
continue|continue;
comment|// Store the offset for the data of this bucket.
name|B
operator|.
name|Off
operator|=
name|Out
operator|.
name|tell
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|B
operator|.
name|Off
operator|&&
literal|"Cannot write a bucket at offset 0. Please add padding."
argument_list|)
expr_stmt|;
comment|// Write out the number of items in the bucket.
name|LE
operator|.
name|write
operator|<
name|uint16_t
operator|>
operator|(
name|B
operator|.
name|Length
operator|)
expr_stmt|;
name|assert
argument_list|(
name|B
operator|.
name|Length
operator|!=
literal|0
operator|&&
literal|"Bucket has a head but zero length?"
argument_list|)
expr_stmt|;
comment|// Write out the entries in the bucket.
for|for
control|(
name|Item
modifier|*
name|I
init|=
name|B
operator|.
name|Head
init|;
name|I
condition|;
name|I
operator|=
name|I
operator|->
name|Next
control|)
block|{
name|LE
operator|.
name|write
operator|<
name|typename
name|Info
operator|::
name|hash_value_type
operator|>
operator|(
name|I
operator|->
name|Hash
operator|)
expr_stmt|;
specifier|const
name|std
operator|::
name|pair
operator|<
name|offset_type
operator|,
name|offset_type
operator|>
operator|&
name|Len
operator|=
name|InfoObj
operator|.
name|EmitKeyDataLength
argument_list|(
name|Out
argument_list|,
name|I
operator|->
name|Key
argument_list|,
name|I
operator|->
name|Data
argument_list|)
expr_stmt|;
name|InfoObj
operator|.
name|EmitKey
argument_list|(
name|Out
argument_list|,
name|I
operator|->
name|Key
argument_list|,
name|Len
operator|.
name|first
argument_list|)
expr_stmt|;
name|InfoObj
operator|.
name|EmitData
argument_list|(
name|Out
argument_list|,
name|I
operator|->
name|Key
argument_list|,
name|I
operator|->
name|Data
argument_list|,
name|Len
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
block|}
comment|// Pad with zeros so that we can start the hashtable at an aligned address.
name|offset_type
name|TableOff
init|=
name|Out
operator|.
name|tell
argument_list|()
decl_stmt|;
name|uint64_t
name|N
init|=
name|llvm
operator|::
name|OffsetToAlignment
argument_list|(
name|TableOff
argument_list|,
name|alignOf
operator|<
name|offset_type
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
name|TableOff
operator|+=
name|N
expr_stmt|;
while|while
condition|(
name|N
operator|--
condition|)
name|LE
operator|.
name|write
operator|<
name|uint8_t
operator|>
operator|(
literal|0
operator|)
expr_stmt|;
comment|// Emit the hashtable itself.
name|LE
operator|.
name|write
operator|<
name|offset_type
operator|>
operator|(
name|NumBuckets
operator|)
expr_stmt|;
name|LE
operator|.
name|write
operator|<
name|offset_type
operator|>
operator|(
name|NumEntries
operator|)
expr_stmt|;
for|for
control|(
name|offset_type
name|I
init|=
literal|0
init|;
name|I
operator|<
name|NumBuckets
condition|;
operator|++
name|I
control|)
name|LE
operator|.
name|write
operator|<
name|offset_type
operator|>
operator|(
name|Buckets
index|[
name|I
index|]
operator|.
name|Off
operator|)
expr_stmt|;
return|return
name|TableOff
return|;
block|}
name|OnDiskChainedHashTableGenerator
argument_list|()
block|{
name|NumEntries
operator|=
literal|0
expr_stmt|;
name|NumBuckets
operator|=
literal|64
expr_stmt|;
comment|// Note that we do not need to run the constructors of the individual
comment|// Bucket objects since 'calloc' returns bytes that are all 0.
name|Buckets
operator|=
operator|(
name|Bucket
operator|*
operator|)
name|std
operator|::
name|calloc
argument_list|(
name|NumBuckets
argument_list|,
sizeof|sizeof
argument_list|(
name|Bucket
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|~
name|OnDiskChainedHashTableGenerator
argument_list|()
block|{
name|std
operator|::
name|free
argument_list|(
name|Buckets
argument_list|)
block|; }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Provides lookup on an on disk hash table.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This needs an \c Info that handles reading values from the hash table's
end_comment

begin_comment
comment|/// payload and computes the hash for a given key. This should provide the
end_comment

begin_comment
comment|/// following interface:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// class ExampleLookupInfo {
end_comment

begin_comment
comment|/// public:
end_comment

begin_comment
comment|///   typedef ExampleData data_type;
end_comment

begin_comment
comment|///   typedef ExampleInternalKey internal_key_type; // The stored key type.
end_comment

begin_comment
comment|///   typedef ExampleKey external_key_type; // The type to pass to find().
end_comment

begin_comment
comment|///   typedef uint32_t hash_value_type; // The type the hash function returns.
end_comment

begin_comment
comment|///   typedef uint32_t offset_type; // The type for offsets into the table.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   /// Compare two keys for equality.
end_comment

begin_comment
comment|///   static bool EqualKey(internal_key_type&Key1, internal_key_type&Key2);
end_comment

begin_comment
comment|///   /// Calculate the hash for the given key.
end_comment

begin_comment
comment|///   static hash_value_type ComputeHash(internal_key_type&IKey);
end_comment

begin_comment
comment|///   /// Translate from the semantic type of a key in the hash table to the
end_comment

begin_comment
comment|///   /// type that is actually stored and used for hashing and comparisons.
end_comment

begin_comment
comment|///   /// The internal and external types are often the same, in which case this
end_comment

begin_comment
comment|///   /// can simply return the passed in value.
end_comment

begin_comment
comment|///   static const internal_key_type&GetInternalKey(external_key_type&EKey);
end_comment

begin_comment
comment|///   /// Read the key and data length from Buffer, leaving it pointing at the
end_comment

begin_comment
comment|///   /// following byte.
end_comment

begin_comment
comment|///   static std::pair<offset_type, offset_type>
end_comment

begin_comment
comment|///   ReadKeyDataLength(const unsigned char *&Buffer);
end_comment

begin_comment
comment|///   /// Read the key from Buffer, given the KeyLen as reported from
end_comment

begin_comment
comment|///   /// ReadKeyDataLength.
end_comment

begin_comment
comment|///   const internal_key_type&ReadKey(const unsigned char *Buffer,
end_comment

begin_comment
comment|///                                    offset_type KeyLen);
end_comment

begin_comment
comment|///   /// Read the data for Key from Buffer, given the DataLen as reported from
end_comment

begin_comment
comment|///   /// ReadKeyDataLength.
end_comment

begin_comment
comment|///   data_type ReadData(StringRef Key, const unsigned char *Buffer,
end_comment

begin_comment
comment|///                      offset_type DataLen);
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Info
operator|>
name|class
name|OnDiskChainedHashTable
block|{
specifier|const
name|typename
name|Info
operator|::
name|offset_type
name|NumBuckets
block|;
specifier|const
name|typename
name|Info
operator|::
name|offset_type
name|NumEntries
block|;
specifier|const
name|unsigned
name|char
operator|*
specifier|const
name|Buckets
block|;
specifier|const
name|unsigned
name|char
operator|*
specifier|const
name|Base
block|;
name|Info
name|InfoObj
block|;
name|public
operator|:
typedef|typedef
name|typename
name|Info
operator|::
name|internal_key_type
name|internal_key_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Info
operator|::
name|external_key_type
name|external_key_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Info
operator|::
name|data_type
name|data_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Info
operator|::
name|hash_value_type
name|hash_value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Info
operator|::
name|offset_type
name|offset_type
expr_stmt|;
end_typedef

begin_macro
name|OnDiskChainedHashTable
argument_list|(
argument|offset_type NumBuckets
argument_list|,
argument|offset_type NumEntries
argument_list|,
argument|const unsigned char *Buckets
argument_list|,
argument|const unsigned char *Base
argument_list|,
argument|const Info&InfoObj = Info()
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|NumBuckets
argument_list|(
name|NumBuckets
argument_list|)
operator|,
name|NumEntries
argument_list|(
name|NumEntries
argument_list|)
operator|,
name|Buckets
argument_list|(
name|Buckets
argument_list|)
operator|,
name|Base
argument_list|(
name|Base
argument_list|)
operator|,
name|InfoObj
argument_list|(
argument|InfoObj
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Buckets
operator|)
operator|&
literal|0x3
operator|)
operator|==
literal|0
operator|&&
literal|"'buckets' must have a 4-byte alignment"
argument_list|)
block|;   }
name|offset_type
name|getNumBuckets
argument_list|()
specifier|const
block|{
return|return
name|NumBuckets
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|offset_type
name|getNumEntries
argument_list|()
specifier|const
block|{
return|return
name|NumEntries
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|unsigned
name|char
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|Base
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|unsigned
name|char
operator|*
name|getBuckets
argument_list|()
specifier|const
block|{
return|return
name|Buckets
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|NumEntries
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|class
name|iterator
block|{
name|internal_key_type
name|Key
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
specifier|const
name|Data
decl_stmt|;
specifier|const
name|offset_type
name|Len
decl_stmt|;
name|Info
modifier|*
name|InfoObj
decl_stmt|;
name|public
label|:
name|iterator
argument_list|()
operator|:
name|Data
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Len
argument_list|(
literal|0
argument_list|)
block|{}
name|iterator
argument_list|(
argument|const internal_key_type K
argument_list|,
argument|const unsigned char *D
argument_list|,
argument|offset_type L
argument_list|,
argument|Info *InfoObj
argument_list|)
operator|:
name|Key
argument_list|(
name|K
argument_list|)
operator|,
name|Data
argument_list|(
name|D
argument_list|)
operator|,
name|Len
argument_list|(
name|L
argument_list|)
operator|,
name|InfoObj
argument_list|(
argument|InfoObj
argument_list|)
block|{}
name|data_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|InfoObj
operator|->
name|ReadData
argument_list|(
name|Key
argument_list|,
name|Data
argument_list|,
name|Len
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|X
operator|.
name|Data
operator|==
name|Data
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|X
operator|.
name|Data
operator|!=
name|Data
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Look up the stored data for a particular key.
end_comment

begin_function
name|iterator
name|find
parameter_list|(
specifier|const
name|external_key_type
modifier|&
name|EKey
parameter_list|,
name|Info
modifier|*
name|InfoPtr
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
operator|!
name|InfoPtr
condition|)
name|InfoPtr
operator|=
operator|&
name|InfoObj
expr_stmt|;
name|using
name|namespace
name|llvm
operator|::
name|support
expr_stmt|;
specifier|const
name|internal_key_type
modifier|&
name|IKey
init|=
name|InfoObj
operator|.
name|GetInternalKey
argument_list|(
name|EKey
argument_list|)
decl_stmt|;
name|hash_value_type
name|KeyHash
init|=
name|InfoObj
operator|.
name|ComputeHash
argument_list|(
name|IKey
argument_list|)
decl_stmt|;
comment|// Each bucket is just an offset into the hash table file.
name|offset_type
name|Idx
init|=
name|KeyHash
operator|&
operator|(
name|NumBuckets
operator|-
literal|1
operator|)
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|Bucket
init|=
name|Buckets
operator|+
sizeof|sizeof
argument_list|(
name|offset_type
argument_list|)
operator|*
name|Idx
decl_stmt|;
name|offset_type
name|Offset
init|=
name|endian
operator|::
name|readNext
operator|<
name|offset_type
decl_stmt|,
name|little
decl_stmt|,
name|aligned
decl|>
argument_list|(
name|Bucket
argument_list|)
decl_stmt|;
if|if
condition|(
name|Offset
operator|==
literal|0
condition|)
return|return
name|iterator
argument_list|()
return|;
comment|// Empty bucket.
specifier|const
name|unsigned
name|char
modifier|*
name|Items
init|=
name|Base
operator|+
name|Offset
decl_stmt|;
comment|// 'Items' starts with a 16-bit unsigned integer representing the
comment|// number of items in this bucket.
name|unsigned
name|Len
init|=
name|endian
operator|::
name|readNext
operator|<
name|uint16_t
decl_stmt|,
name|little
decl_stmt|,
name|unaligned
decl|>
argument_list|(
name|Items
argument_list|)
decl_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|Len
condition|;
operator|++
name|i
control|)
block|{
comment|// Read the hash.
name|hash_value_type
name|ItemHash
init|=
name|endian
operator|::
name|readNext
operator|<
name|hash_value_type
decl_stmt|,
name|little
decl_stmt|,
name|unaligned
decl|>
argument_list|(
name|Items
argument_list|)
decl_stmt|;
comment|// Determine the length of the key and the data.
specifier|const
name|std
operator|::
name|pair
operator|<
name|offset_type
operator|,
name|offset_type
operator|>
operator|&
name|L
operator|=
name|Info
operator|::
name|ReadKeyDataLength
argument_list|(
name|Items
argument_list|)
expr_stmt|;
name|offset_type
name|ItemLen
init|=
name|L
operator|.
name|first
operator|+
name|L
operator|.
name|second
decl_stmt|;
comment|// Compare the hashes.  If they are not the same, skip the entry entirely.
if|if
condition|(
name|ItemHash
operator|!=
name|KeyHash
condition|)
block|{
name|Items
operator|+=
name|ItemLen
expr_stmt|;
continue|continue;
block|}
comment|// Read the key.
specifier|const
name|internal_key_type
modifier|&
name|X
init|=
name|InfoPtr
operator|->
name|ReadKey
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
specifier|const
operator|)
name|Items
argument_list|,
name|L
operator|.
name|first
argument_list|)
decl_stmt|;
comment|// If the key doesn't match just skip reading the value.
if|if
condition|(
operator|!
name|InfoPtr
operator|->
name|EqualKey
argument_list|(
name|X
argument_list|,
name|IKey
argument_list|)
condition|)
block|{
name|Items
operator|+=
name|ItemLen
expr_stmt|;
continue|continue;
block|}
comment|// The key matches!
return|return
name|iterator
argument_list|(
name|X
argument_list|,
name|Items
operator|+
name|L
operator|.
name|first
argument_list|,
name|L
operator|.
name|second
argument_list|,
name|InfoPtr
argument_list|)
return|;
block|}
return|return
name|iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|Info
modifier|&
name|getInfoObj
parameter_list|()
block|{
return|return
name|InfoObj
return|;
block|}
end_function

begin_comment
comment|/// \brief Create the hash table.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Buckets is the beginning of the hash table itself, which follows
end_comment

begin_comment
comment|/// the payload of entire structure. This is the value returned by
end_comment

begin_comment
comment|/// OnDiskHashTableGenerator::Emit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base is the point from which all offsets into the structure are
end_comment

begin_comment
comment|/// based. This is offset 0 in the stream that was used when Emitting the
end_comment

begin_comment
comment|/// table.
end_comment

begin_function
specifier|static
name|OnDiskChainedHashTable
modifier|*
name|Create
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|Buckets
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
specifier|const
name|Base
parameter_list|,
specifier|const
name|Info
modifier|&
name|InfoObj
init|=
name|Info
argument_list|()
parameter_list|)
block|{
name|using
name|namespace
name|llvm
operator|::
name|support
expr_stmt|;
name|assert
argument_list|(
name|Buckets
operator|>
name|Base
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Buckets
operator|)
operator|&
literal|0x3
operator|)
operator|==
literal|0
operator|&&
literal|"buckets should be 4-byte aligned."
argument_list|)
expr_stmt|;
name|offset_type
name|NumBuckets
init|=
name|endian
operator|::
name|readNext
operator|<
name|offset_type
decl_stmt|,
name|little
decl_stmt|,
name|aligned
decl|>
argument_list|(
name|Buckets
argument_list|)
decl_stmt|;
name|offset_type
name|NumEntries
init|=
name|endian
operator|::
name|readNext
operator|<
name|offset_type
decl_stmt|,
name|little
decl_stmt|,
name|aligned
decl|>
argument_list|(
name|Buckets
argument_list|)
decl_stmt|;
return|return
name|new
name|OnDiskChainedHashTable
operator|<
name|Info
operator|>
operator|(
name|NumBuckets
operator|,
name|NumEntries
operator|,
name|Buckets
operator|,
name|Base
operator|,
name|InfoObj
operator|)
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Provides lookup and iteration over an on disk hash table.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \copydetails llvm::OnDiskChainedHashTable
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Info
operator|>
name|class
name|OnDiskIterableChainedHashTable
operator|:
name|public
name|OnDiskChainedHashTable
operator|<
name|Info
operator|>
block|{
specifier|const
name|unsigned
name|char
operator|*
name|Payload
block|;
name|public
operator|:
typedef|typedef
name|OnDiskChainedHashTable
operator|<
name|Info
operator|>
name|base_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|base_type
operator|::
name|internal_key_type
name|internal_key_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_type
operator|::
name|external_key_type
name|external_key_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_type
operator|::
name|data_type
name|data_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_type
operator|::
name|hash_value_type
name|hash_value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_type
operator|::
name|offset_type
name|offset_type
expr_stmt|;
end_typedef

begin_macro
name|OnDiskIterableChainedHashTable
argument_list|(
argument|offset_type NumBuckets
argument_list|,
argument|offset_type NumEntries
argument_list|,
argument|const unsigned char *Buckets
argument_list|,
argument|const unsigned char *Payload
argument_list|,
argument|const unsigned char *Base
argument_list|,
argument|const Info&InfoObj = Info()
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|base_type
argument_list|(
name|NumBuckets
argument_list|,
name|NumEntries
argument_list|,
name|Buckets
argument_list|,
name|Base
argument_list|,
name|InfoObj
argument_list|)
operator|,
name|Payload
argument_list|(
argument|Payload
argument_list|)
block|{}
comment|/// \brief Iterates over all of the keys in the table.
name|class
name|key_iterator
block|{
specifier|const
name|unsigned
name|char
operator|*
name|Ptr
block|;
name|offset_type
name|NumItemsInBucketLeft
block|;
name|offset_type
name|NumEntriesLeft
block|;
name|Info
operator|*
name|InfoObj
block|;
name|public
operator|:
typedef|typedef
name|external_key_type
name|value_type
typedef|;
name|key_iterator
argument_list|(
argument|const unsigned char *const Ptr
argument_list|,
argument|offset_type NumEntries
argument_list|,
argument|Info *InfoObj
argument_list|)
operator|:
name|Ptr
argument_list|(
name|Ptr
argument_list|)
operator|,
name|NumItemsInBucketLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|NumEntriesLeft
argument_list|(
name|NumEntries
argument_list|)
operator|,
name|InfoObj
argument_list|(
argument|InfoObj
argument_list|)
block|{}
name|key_iterator
argument_list|()
operator|:
name|Ptr
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumItemsInBucketLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|NumEntriesLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|InfoObj
argument_list|(
literal|0
argument_list|)
block|{}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|key_iterator
operator|&
name|X
operator|,
specifier|const
name|key_iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|NumEntriesLeft
operator|==
name|Y
operator|.
name|NumEntriesLeft
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|key_iterator
operator|&
name|X
operator|,
specifier|const
name|key_iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|NumEntriesLeft
operator|!=
name|Y
operator|.
name|NumEntriesLeft
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|key_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|using
name|namespace
name|llvm
operator|::
name|support
block|;
if|if
condition|(
operator|!
name|NumItemsInBucketLeft
condition|)
block|{
comment|// 'Items' starts with a 16-bit unsigned integer representing the
comment|// number of items in this bucket.
name|NumItemsInBucketLeft
operator|=
name|endian
operator|::
name|readNext
operator|<
name|uint16_t
operator|,
name|little
operator|,
name|unaligned
operator|>
operator|(
name|Ptr
operator|)
expr_stmt|;
block|}
name|Ptr
operator|+=
sizeof|sizeof
argument_list|(
name|hash_value_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Skip the hash.
end_comment

begin_comment
comment|// Determine the length of the key and the data.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|pair
operator|<
name|offset_type
operator|,
name|offset_type
operator|>
operator|&
name|L
operator|=
name|Info
operator|::
name|ReadKeyDataLength
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Ptr
operator|+=
name|L
operator|.
name|first
operator|+
name|L
operator|.
name|second
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
name|NumItemsInBucketLeft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|--
name|NumItemsInBucketLeft
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
name|NumEntriesLeft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|--
name|NumEntriesLeft
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}     key_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|key_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|value_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
specifier|const
name|unsigned
name|char
operator|*
name|LocalPtr
operator|=
name|Ptr
block|;
if|if
condition|(
operator|!
name|NumItemsInBucketLeft
condition|)
name|LocalPtr
operator|+=
literal|2
expr_stmt|;
comment|// number of items in bucket
name|LocalPtr
operator|+=
sizeof|sizeof
argument_list|(
name|hash_value_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Skip the hash.
end_comment

begin_comment
comment|// Determine the length of the key and the data.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|pair
operator|<
name|offset_type
operator|,
name|offset_type
operator|>
operator|&
name|L
operator|=
name|Info
operator|::
name|ReadKeyDataLength
argument_list|(
name|LocalPtr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Read the key.
end_comment

begin_decl_stmt
specifier|const
name|internal_key_type
modifier|&
name|Key
init|=
name|InfoObj
operator|->
name|ReadKey
argument_list|(
name|LocalPtr
argument_list|,
name|L
operator|.
name|first
argument_list|)
decl_stmt|;
end_decl_stmt

begin_return
return|return
name|InfoObj
operator|->
name|GetExternalKey
argument_list|(
name|Key
argument_list|)
return|;
end_return

begin_empty_stmt
unit|}   }
empty_stmt|;
end_empty_stmt

begin_function
name|key_iterator
name|key_begin
parameter_list|()
block|{
return|return
name|key_iterator
argument_list|(
name|Payload
argument_list|,
name|this
operator|->
name|getNumEntries
argument_list|()
argument_list|,
operator|&
name|this
operator|->
name|getInfoObj
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|key_iterator
name|key_end
parameter_list|()
block|{
return|return
name|key_iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|iterator_range
operator|<
name|key_iterator
operator|>
name|keys
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|key_begin
argument_list|()
argument_list|,
name|key_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Iterates over all the entries in the table, returning the data.
end_comment

begin_decl_stmt
name|class
name|data_iterator
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|Ptr
decl_stmt|;
name|offset_type
name|NumItemsInBucketLeft
decl_stmt|;
name|offset_type
name|NumEntriesLeft
decl_stmt|;
name|Info
modifier|*
name|InfoObj
decl_stmt|;
name|public
label|:
typedef|typedef
name|data_type
name|value_type
typedef|;
name|data_iterator
argument_list|(
argument|const unsigned char *const Ptr
argument_list|,
argument|offset_type NumEntries
argument_list|,
argument|Info *InfoObj
argument_list|)
block|:
name|Ptr
argument_list|(
name|Ptr
argument_list|)
operator|,
name|NumItemsInBucketLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|NumEntriesLeft
argument_list|(
name|NumEntries
argument_list|)
operator|,
name|InfoObj
argument_list|(
argument|InfoObj
argument_list|)
block|{}
name|data_iterator
argument_list|()
operator|:
name|Ptr
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumItemsInBucketLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|NumEntriesLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|InfoObj
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|data_iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|X
operator|.
name|NumEntriesLeft
operator|==
name|NumEntriesLeft
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|data_iterator
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|X
operator|.
name|NumEntriesLeft
operator|!=
name|NumEntriesLeft
return|;
block|}
name|data_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|using
name|namespace
name|llvm
operator|::
name|support
block|;
if|if
condition|(
operator|!
name|NumItemsInBucketLeft
condition|)
block|{
comment|// 'Items' starts with a 16-bit unsigned integer representing the
comment|// number of items in this bucket.
name|NumItemsInBucketLeft
operator|=
name|endian
operator|::
name|readNext
operator|<
name|uint16_t
operator|,
name|little
operator|,
name|unaligned
operator|>
operator|(
name|Ptr
operator|)
expr_stmt|;
block|}
name|Ptr
operator|+=
sizeof|sizeof
argument_list|(
name|hash_value_type
argument_list|)
expr_stmt|;
comment|// Skip the hash.
comment|// Determine the length of the key and the data.
specifier|const
name|std
operator|::
name|pair
operator|<
name|offset_type
operator|,
name|offset_type
operator|>
operator|&
name|L
operator|=
name|Info
operator|::
name|ReadKeyDataLength
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
name|Ptr
operator|+=
name|L
operator|.
name|first
operator|+
name|L
operator|.
name|second
expr_stmt|;
name|assert
argument_list|(
name|NumItemsInBucketLeft
argument_list|)
expr_stmt|;
operator|--
name|NumItemsInBucketLeft
expr_stmt|;
name|assert
argument_list|(
name|NumEntriesLeft
argument_list|)
expr_stmt|;
operator|--
name|NumEntriesLeft
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|data_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|data_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|value_type
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
specifier|const
name|unsigned
name|char
operator|*
name|LocalPtr
operator|=
name|Ptr
block|;
if|if
condition|(
operator|!
name|NumItemsInBucketLeft
condition|)
name|LocalPtr
operator|+=
literal|2
expr_stmt|;
comment|// number of items in bucket
name|LocalPtr
operator|+=
sizeof|sizeof
argument_list|(
name|hash_value_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Skip the hash.
end_comment

begin_comment
comment|// Determine the length of the key and the data.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|pair
operator|<
name|offset_type
operator|,
name|offset_type
operator|>
operator|&
name|L
operator|=
name|Info
operator|::
name|ReadKeyDataLength
argument_list|(
name|LocalPtr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Read the key.
end_comment

begin_decl_stmt
specifier|const
name|internal_key_type
modifier|&
name|Key
init|=
name|InfoObj
operator|->
name|ReadKey
argument_list|(
name|LocalPtr
argument_list|,
name|L
operator|.
name|first
argument_list|)
decl_stmt|;
end_decl_stmt

begin_return
return|return
name|InfoObj
operator|->
name|ReadData
argument_list|(
name|Key
argument_list|,
name|LocalPtr
operator|+
name|L
operator|.
name|first
argument_list|,
name|L
operator|.
name|second
argument_list|)
return|;
end_return

begin_empty_stmt
unit|}   }
empty_stmt|;
end_empty_stmt

begin_function
name|data_iterator
name|data_begin
parameter_list|()
block|{
return|return
name|data_iterator
argument_list|(
name|Payload
argument_list|,
name|this
operator|->
name|getNumEntries
argument_list|()
argument_list|,
operator|&
name|this
operator|->
name|getInfoObj
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|data_iterator
name|data_end
parameter_list|()
block|{
return|return
name|data_iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|iterator_range
operator|<
name|data_iterator
operator|>
name|data
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|data_begin
argument_list|()
argument_list|,
name|data_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Create the hash table.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Buckets is the beginning of the hash table itself, which follows
end_comment

begin_comment
comment|/// the payload of entire structure. This is the value returned by
end_comment

begin_comment
comment|/// OnDiskHashTableGenerator::Emit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Payload is the beginning of the data contained in the table.  This
end_comment

begin_comment
comment|/// is Base plus any padding or header data that was stored, ie, the offset
end_comment

begin_comment
comment|/// that the stream was at when calling Emit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base is the point from which all offsets into the structure are
end_comment

begin_comment
comment|/// based. This is offset 0 in the stream that was used when Emitting the
end_comment

begin_comment
comment|/// table.
end_comment

begin_function
specifier|static
name|OnDiskIterableChainedHashTable
modifier|*
name|Create
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|Buckets
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
specifier|const
name|Payload
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
specifier|const
name|Base
parameter_list|,
specifier|const
name|Info
modifier|&
name|InfoObj
init|=
name|Info
argument_list|()
parameter_list|)
block|{
name|using
name|namespace
name|llvm
operator|::
name|support
expr_stmt|;
name|assert
argument_list|(
name|Buckets
operator|>
name|Base
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Buckets
operator|)
operator|&
literal|0x3
operator|)
operator|==
literal|0
operator|&&
literal|"buckets should be 4-byte aligned."
argument_list|)
expr_stmt|;
name|offset_type
name|NumBuckets
init|=
name|endian
operator|::
name|readNext
operator|<
name|offset_type
decl_stmt|,
name|little
decl_stmt|,
name|aligned
decl|>
argument_list|(
name|Buckets
argument_list|)
decl_stmt|;
name|offset_type
name|NumEntries
init|=
name|endian
operator|::
name|readNext
operator|<
name|offset_type
decl_stmt|,
name|little
decl_stmt|,
name|aligned
decl|>
argument_list|(
name|Buckets
argument_list|)
decl_stmt|;
return|return
name|new
name|OnDiskIterableChainedHashTable
operator|<
name|Info
operator|>
operator|(
name|NumBuckets
operator|,
name|NumEntries
operator|,
name|Buckets
operator|,
name|Payload
operator|,
name|Base
operator|,
name|InfoObj
operator|)
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_ON_DISK_HASH_TABLE_H
end_comment

end_unit

