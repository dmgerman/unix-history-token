begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryStreamArray.h - Array backed by an arbitrary stream *- C++ -*-===//
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
name|LLVM_SUPPORT_BINARYSTREAMARRAY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYSTREAMARRAY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_comment
comment|/// Lightweight arrays that are backed by an arbitrary BinaryStream.  This file
end_comment

begin_comment
comment|/// provides two different array implementations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     VarStreamArray - Arrays of variable length records.  The user specifies
end_comment

begin_comment
comment|///       an Extractor type that can extract a record from a given offset and
end_comment

begin_comment
comment|///       return the number of bytes consumed by the record.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///     FixedStreamArray - Arrays of fixed length records.  This is similar in
end_comment

begin_comment
comment|///       spirit to ArrayRef<T>, but since it is backed by a BinaryStream, the
end_comment

begin_comment
comment|///       elements of the array need not be laid out in contiguous memory.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// VarStreamArrayExtractor is intended to be specialized to provide customized
comment|/// extraction logic.  On input it receives a BinaryStreamRef pointing to the
comment|/// beginning of the next record, but where the length of the record is not yet
comment|/// known.  Upon completion, it should return an appropriate Error instance if
comment|/// a record could not be extracted, or if one could be extracted it should
comment|/// return success and set Len to the number of bytes this record occupied in
comment|/// the underlying stream, and it should fill out the fields of the value type
comment|/// Item appropriately to represent the current record.
comment|///
comment|/// You can specialize this template for your own custom value types to avoid
comment|/// having to specify a second template argument to VarStreamArray (documented
comment|/// below).
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|VarStreamArrayExtractor
block|{
comment|// Method intentionally deleted.  You must provide an explicit specialization
comment|// with the following method implemented.
name|Error
name|operator
argument_list|()
operator|(
name|BinaryStreamRef
name|Stream
operator|,
name|uint32_t
operator|&
name|Len
operator|,
name|T
operator|&
name|Item
operator|)
specifier|const
operator|=
name|delete
block|; }
expr_stmt|;
comment|/// VarStreamArray represents an array of variable length records backed by a
comment|/// stream.  This could be a contiguous sequence of bytes in memory, it could
comment|/// be a file on disk, or it could be a PDB stream where bytes are stored as
comment|/// discontiguous blocks in a file.  Usually it is desirable to treat arrays
comment|/// as contiguous blocks of memory, but doing so with large PDB files, for
comment|/// example, could mean allocating huge amounts of memory just to allow
comment|/// re-ordering of stream data to be contiguous before iterating over it.  By
comment|/// abstracting this out, we need not duplicate this memory, and we can
comment|/// iterate over arrays in arbitrarily formatted streams.  Elements are parsed
comment|/// lazily on iteration, so there is no upfront cost associated with building
comment|/// or copying a VarStreamArray, no matter how large it may be.
comment|///
comment|/// You create a VarStreamArray by specifying a ValueType and an Extractor type.
comment|/// If you do not specify an Extractor type, you are expected to specialize
comment|/// VarStreamArrayExtractor<T> for your ValueType.
comment|///
comment|/// By default an Extractor is default constructed in the class, but in some
comment|/// cases you might find it useful for an Extractor to maintain state across
comment|/// extractions.  In this case you can provide your own Extractor through a
comment|/// secondary constructor.  The following examples show various ways of
comment|/// creating a VarStreamArray.
comment|///
comment|///       // Will use VarStreamArrayExtractor<MyType> as the extractor.
comment|///       VarStreamArray<MyType> MyTypeArray;
comment|///
comment|///       // Will use a default-constructed MyExtractor as the extractor.
comment|///       VarStreamArray<MyType, MyExtractor> MyTypeArray2;
comment|///
comment|///       // Will use the specific instance of MyExtractor provided.
comment|///       // MyExtractor need not be default-constructible in this case.
comment|///       MyExtractor E(SomeContext);
comment|///       VarStreamArray<MyType, MyExtractor> MyTypeArray3(E);
comment|///
name|template
operator|<
name|typename
name|ValueType
operator|,
name|typename
name|Extractor
operator|>
name|class
name|VarStreamArrayIterator
expr_stmt|;
name|template
operator|<
name|typename
name|ValueType
operator|,
name|typename
name|Extractor
operator|=
name|VarStreamArrayExtractor
operator|<
name|ValueType
operator|>>
name|class
name|VarStreamArray
block|{
name|friend
name|class
name|VarStreamArrayIterator
operator|<
name|ValueType
block|,
name|Extractor
operator|>
block|;
name|public
operator|:
typedef|typedef
name|VarStreamArrayIterator
operator|<
name|ValueType
operator|,
name|Extractor
operator|>
name|Iterator
expr_stmt|;
name|VarStreamArray
argument_list|()
operator|=
block|default
expr_stmt|;
name|explicit
name|VarStreamArray
argument_list|(
specifier|const
name|Extractor
operator|&
name|E
argument_list|)
operator|:
name|E
argument_list|(
argument|E
argument_list|)
block|{}
name|explicit
name|VarStreamArray
argument_list|(
argument|BinaryStreamRef Stream
argument_list|)
operator|:
name|Stream
argument_list|(
argument|Stream
argument_list|)
block|{}
name|VarStreamArray
argument_list|(
argument|BinaryStreamRef Stream
argument_list|,
argument|const Extractor&E
argument_list|)
operator|:
name|Stream
argument_list|(
name|Stream
argument_list|)
operator|,
name|E
argument_list|(
argument|E
argument_list|)
block|{}
name|Iterator
name|begin
argument_list|(
argument|bool *HadError = nullptr
argument_list|)
specifier|const
block|{
return|return
name|Iterator
argument_list|(
operator|*
name|this
argument_list|,
name|E
argument_list|,
name|HadError
argument_list|)
return|;
block|}
name|bool
name|valid
argument_list|()
specifier|const
block|{
return|return
name|Stream
operator|.
name|valid
argument_list|()
return|;
block|}
name|Iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Iterator
argument_list|(
name|E
argument_list|)
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Stream
operator|.
name|getLength
argument_list|()
operator|==
literal|0
return|;
block|}
comment|/// \brief given an offset into the array's underlying stream, return an
comment|/// iterator to the record at that offset.  This is considered unsafe
comment|/// since the behavior is undefined if \p Offset does not refer to the
comment|/// beginning of a valid record.
name|Iterator
name|at
argument_list|(
name|uint32_t
name|Offset
argument_list|)
decl|const
block|{
return|return
name|Iterator
argument_list|(
operator|*
name|this
argument_list|,
name|E
argument_list|,
name|Offset
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
specifier|const
name|Extractor
operator|&
name|getExtractor
argument_list|()
specifier|const
block|{
return|return
name|E
return|;
block|}
name|Extractor
modifier|&
name|getExtractor
parameter_list|()
block|{
return|return
name|E
return|;
block|}
name|BinaryStreamRef
name|getUnderlyingStream
argument_list|()
specifier|const
block|{
return|return
name|Stream
return|;
block|}
name|void
name|setUnderlyingStream
parameter_list|(
name|BinaryStreamRef
name|S
parameter_list|)
block|{
name|Stream
operator|=
name|S
expr_stmt|;
block|}
name|private
label|:
name|BinaryStreamRef
name|Stream
decl_stmt|;
name|Extractor
name|E
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ValueType
operator|,
name|typename
name|Extractor
operator|>
name|class
name|VarStreamArrayIterator
operator|:
name|public
name|iterator_facade_base
operator|<
name|VarStreamArrayIterator
operator|<
name|ValueType
operator|,
name|Extractor
operator|>
operator|,
name|std
operator|::
name|forward_iterator_tag
operator|,
name|ValueType
operator|>
block|{
typedef|typedef
name|VarStreamArrayIterator
operator|<
name|ValueType
operator|,
name|Extractor
operator|>
name|IterType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|VarStreamArray
operator|<
name|ValueType
operator|,
name|Extractor
operator|>
name|ArrayType
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|VarStreamArrayIterator
argument_list|(
specifier|const
name|ArrayType
operator|&
name|Array
argument_list|,
specifier|const
name|Extractor
operator|&
name|E
argument_list|,
name|bool
operator|*
name|HadError
argument_list|)
operator|:
name|VarStreamArrayIterator
argument_list|(
argument|Array
argument_list|,
argument|E
argument_list|,
literal|0
argument_list|,
argument|HadError
argument_list|)
block|{}
name|VarStreamArrayIterator
argument_list|(
argument|const ArrayType&Array
argument_list|,
argument|const Extractor&E
argument_list|,
argument|uint32_t Offset
argument_list|,
argument|bool *HadError
argument_list|)
operator|:
name|IterRef
argument_list|(
name|Array
operator|.
name|Stream
operator|.
name|drop_front
argument_list|(
name|Offset
argument_list|)
argument_list|)
operator|,
name|Extract
argument_list|(
name|E
argument_list|)
operator|,
name|Array
argument_list|(
operator|&
name|Array
argument_list|)
operator|,
name|AbsOffset
argument_list|(
name|Offset
argument_list|)
operator|,
name|HadError
argument_list|(
argument|HadError
argument_list|)
block|{
if|if
condition|(
name|IterRef
operator|.
name|getLength
argument_list|()
operator|==
literal|0
condition|)
name|moveToEnd
argument_list|()
expr_stmt|;
else|else
block|{
name|auto
name|EC
init|=
name|Extract
argument_list|(
name|IterRef
argument_list|,
name|ThisLen
argument_list|,
name|ThisValue
argument_list|)
decl_stmt|;
if|if
condition|(
name|EC
condition|)
block|{
name|consumeError
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|EC
argument_list|)
argument_list|)
expr_stmt|;
name|markError
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}   }
name|VarStreamArrayIterator
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|VarStreamArrayIterator
argument_list|(
specifier|const
name|Extractor
operator|&
name|E
argument_list|)
operator|:
name|Extract
argument_list|(
argument|E
argument_list|)
block|{}
operator|~
name|VarStreamArrayIterator
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|IterType
operator|&
name|R
operator|)
specifier|const
block|{
if|if
condition|(
name|Array
operator|&&
name|R
operator|.
name|Array
condition|)
block|{
comment|// Both have a valid array, make sure they're same.
name|assert
argument_list|(
name|Array
operator|==
name|R
operator|.
name|Array
argument_list|)
expr_stmt|;
return|return
name|IterRef
operator|==
name|R
operator|.
name|IterRef
return|;
block|}
end_expr_stmt

begin_comment
comment|// Both iterators are at the end.
end_comment

begin_if
if|if
condition|(
operator|!
name|Array
operator|&&
operator|!
name|R
operator|.
name|Array
condition|)
return|return
name|true
return|;
end_if

begin_comment
comment|// One is not at the end and one is.
end_comment

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}    const
name|ValueType
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Array
operator|&&
operator|!
name|HasError
argument_list|)
block|;
return|return
name|ThisValue
return|;
block|}
end_expr_stmt

begin_function
name|ValueType
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
name|assert
argument_list|(
name|Array
operator|&&
operator|!
name|HasError
argument_list|)
expr_stmt|;
return|return
name|ThisValue
return|;
block|}
end_function

begin_expr_stmt
name|IterType
operator|&
name|operator
operator|+=
operator|(
name|unsigned
name|N
operator|)
block|{
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|<
name|N
condition|;
operator|++
name|I
control|)
block|{
comment|// We are done with the current record, discard it so that we are
comment|// positioned at the next record.
name|AbsOffset
operator|+=
name|ThisLen
expr_stmt|;
name|IterRef
operator|=
name|IterRef
operator|.
name|drop_front
argument_list|(
name|ThisLen
argument_list|)
expr_stmt|;
if|if
condition|(
name|IterRef
operator|.
name|getLength
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// There is nothing after the current record, we must make this an end
comment|// iterator.
name|moveToEnd
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
comment|// There is some data after the current record.
name|auto
name|EC
init|=
name|Extract
argument_list|(
name|IterRef
argument_list|,
name|ThisLen
argument_list|,
name|ThisValue
argument_list|)
decl_stmt|;
if|if
condition|(
name|EC
condition|)
block|{
name|consumeError
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|EC
argument_list|)
argument_list|)
expr_stmt|;
name|markError
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|ThisLen
operator|==
literal|0
condition|)
block|{
comment|// An empty record? Make this an end iterator.
name|moveToEnd
argument_list|()
expr_stmt|;
block|}
block|}
end_else

begin_expr_stmt
unit|}     return
operator|*
name|this
expr_stmt|;
end_expr_stmt

begin_macro
unit|}    uint32_t
name|offset
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|AbsOffset
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|getRecordLength
argument_list|()
specifier|const
block|{
return|return
name|ThisLen
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_function
name|void
name|moveToEnd
parameter_list|()
block|{
name|Array
operator|=
name|nullptr
expr_stmt|;
name|ThisLen
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|markError
parameter_list|()
block|{
name|moveToEnd
argument_list|()
expr_stmt|;
name|HasError
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|HadError
operator|!=
name|nullptr
condition|)
operator|*
name|HadError
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|ValueType
name|ThisValue
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BinaryStreamRef
name|IterRef
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Extractor
name|Extract
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|ArrayType
modifier|*
name|Array
block|{
name|nullptr
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|uint32_t
name|ThisLen
block|{
literal|0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|uint32_t
name|AbsOffset
block|{
literal|0
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|bool
name|HasError
block|{
name|false
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|bool
modifier|*
name|HadError
block|{
name|nullptr
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|FixedStreamArrayIterator
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// FixedStreamArray is similar to VarStreamArray, except with each record
end_comment

begin_comment
comment|/// having a fixed-length.  As with VarStreamArray, there is no upfront
end_comment

begin_comment
comment|/// cost associated with building or copying a FixedStreamArray, as the
end_comment

begin_comment
comment|/// memory for each element is not read from the backing stream until that
end_comment

begin_comment
comment|/// element is iterated.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|FixedStreamArray
block|{
name|friend
name|class
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
block|;
name|public
operator|:
typedef|typedef
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
name|Iterator
expr_stmt|;
name|FixedStreamArray
argument_list|()
operator|=
block|default
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_macro
name|FixedStreamArray
argument_list|(
argument|BinaryStreamRef Stream
argument_list|)
end_macro

begin_macro
unit|:
name|Stream
argument_list|(
argument|Stream
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
name|Stream
operator|.
name|getLength
argument_list|()
operator|%
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FixedStreamArray
operator|<
name|T
operator|>
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Stream
operator|==
name|Other
operator|.
name|Stream
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|FixedStreamArray
operator|<
name|T
operator|>
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|Other
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|FixedStreamArray
modifier|&
name|operator
init|=
operator|(
specifier|const
name|FixedStreamArray
operator|&
operator|)
operator|=
expr|default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|T
modifier|&
name|operator
index|[]
argument_list|(
name|uint32_t
name|Index
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|uint32_t
name|Off
init|=
name|Index
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
decl_stmt|;
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
expr_stmt|;
if|if
condition|(
name|auto
name|EC
init|=
name|Stream
operator|.
name|readBytes
argument_list|(
name|Off
argument_list|,
sizeof|sizeof
argument_list|(
name|T
argument_list|)
argument_list|,
name|Data
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|false
operator|&&
literal|"Unexpected failure reading from stream"
argument_list|)
expr_stmt|;
comment|// This should never happen since we asserted that the stream length was
comment|// an exact multiple of the element size.
name|consumeError
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|EC
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|assert
argument_list|(
name|llvm
operator|::
name|alignmentAdjustment
argument_list|(
name|Data
operator|.
name|data
argument_list|()
argument_list|,
name|alignof
argument_list|(
name|T
argument_list|)
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|Data
operator|.
name|data
argument_list|()
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|uint32_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|Stream
operator|.
name|getLength
argument_list|()
operator|/
sizeof|sizeof
argument_list|(
name|T
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
name|begin
argument_list|()
specifier|const
block|{
return|return
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|(
operator|*
name|this
operator|,
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
name|end
argument_list|()
specifier|const
block|{
return|return
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|(
operator|*
name|this
operator|,
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|BinaryStreamRef
name|getUnderlyingStream
argument_list|()
specifier|const
block|{
return|return
name|Stream
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|BinaryStreamRef
name|Stream
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|FixedStreamArrayIterator
operator|:
name|public
name|iterator_facade_base
operator|<
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|,
name|std
operator|::
name|random_access_iterator_tag
operator|,
specifier|const
name|T
operator|>
block|{
name|public
operator|:
name|FixedStreamArrayIterator
argument_list|(
argument|const FixedStreamArray<T>&Array
argument_list|,
argument|uint32_t Index
argument_list|)
operator|:
name|Array
argument_list|(
name|Array
argument_list|)
block|,
name|Index
argument_list|(
argument|Index
argument_list|)
block|{}
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|&
name|Other
operator|)
block|{
name|Array
operator|=
name|Other
operator|.
name|Array
block|;
name|Index
operator|=
name|Other
operator|.
name|Index
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Array
index|[
name|Index
index|]
return|;
block|}
end_expr_stmt

begin_function
specifier|const
name|T
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
return|return
name|Array
index|[
name|Index
index|]
return|;
block|}
end_function

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|&
name|R
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Array
operator|==
name|R
operator|.
name|Array
argument_list|)
block|;
return|return
operator|(
name|Index
operator|==
name|R
operator|.
name|Index
operator|)
operator|&&
operator|(
name|Array
operator|==
name|R
operator|.
name|Array
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|&
name|operator
operator|+=
operator|(
name|std
operator|::
name|ptrdiff_t
name|N
operator|)
block|{
name|Index
operator|+=
name|N
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|&
name|operator
operator|-=
operator|(
name|std
operator|::
name|ptrdiff_t
name|N
operator|)
block|{
name|assert
argument_list|(
name|std
operator|::
name|ptrdiff_t
argument_list|(
name|Index
argument_list|)
operator|>=
name|N
argument_list|)
block|;
name|Index
operator|-=
name|N
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|ptrdiff_t
name|operator
operator|-
operator|(
specifier|const
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|&
name|R
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Array
operator|==
name|R
operator|.
name|Array
argument_list|)
block|;
name|assert
argument_list|(
name|Index
operator|>=
name|R
operator|.
name|Index
argument_list|)
block|;
return|return
name|Index
operator|-
name|R
operator|.
name|Index
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|FixedStreamArrayIterator
operator|<
name|T
operator|>
operator|&
name|RHS
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Array
operator|==
name|RHS
operator|.
name|Array
argument_list|)
block|;
return|return
name|Index
operator|<
name|RHS
operator|.
name|Index
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|FixedStreamArray
operator|<
name|T
operator|>
name|Array
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|Index
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_BINARYSTREAMARRAY_H
end_comment

end_unit

