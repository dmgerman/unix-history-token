begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/index.h  * \brief       Handling of .xz Index and related information  */
end_comment

begin_comment
comment|/*  * Author: Lasse Collin  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  *  * See ../lzma.h for information about liblzma as a whole.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_H_INTERNAL
end_ifndef

begin_error
error|#
directive|error
error|Never include this file directly. Use<lzma.h> instead.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * \brief       Opaque data type to hold the Index(es) and other information  *  * lzma_index often holds just one .xz Index and possibly the Stream Flags  * of the same Stream and size of the Stream Padding field. However,  * multiple lzma_indexes can be concatenated with lzma_index_cat() and then  * there may be information about multiple Streams in the same lzma_index.  *  * Notes about thread safety: Only one thread may modify lzma_index at  * a time. All functions that take non-const pointer to lzma_index  * modify it. As long as no thread is modifying the lzma_index, getting  * information from the same lzma_index can be done from multiple threads  * at the same time with functions that take a const pointer to  * lzma_index or use lzma_index_iter. The same iterator must be used  * only by one thread at a time, of course, but there can be as many  * iterators for the same lzma_index as needed.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|lzma_index_s
name|lzma_index
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Iterator to get information about Blocks and Streams  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
struct|struct
block|{
comment|/** 		 * \brief       Pointer to Stream Flags 		 * 		 * This is NULL if Stream Flags have not been set for 		 * this Stream with lzma_index_stream_flags(). 		 */
specifier|const
name|lzma_stream_flags
modifier|*
name|flags
decl_stmt|;
specifier|const
name|void
modifier|*
name|reserved_ptr1
decl_stmt|;
specifier|const
name|void
modifier|*
name|reserved_ptr2
decl_stmt|;
specifier|const
name|void
modifier|*
name|reserved_ptr3
decl_stmt|;
comment|/** 		 * \brief       Stream number in the lzma_index 		 * 		 * The first Stream is 1. 		 */
name|lzma_vli
name|number
decl_stmt|;
comment|/** 		 * \brief       Number of Blocks in the Stream 		 * 		 * If this is zero, the block structure below has 		 * undefined values. 		 */
name|lzma_vli
name|block_count
decl_stmt|;
comment|/** 		 * \brief       Compressed start offset of this Stream 		 * 		 * The offset is relative to the beginning of the lzma_index 		 * (i.e. usually the beginning of the .xz file). 		 */
name|lzma_vli
name|compressed_offset
decl_stmt|;
comment|/** 		 * \brief       Uncompressed start offset of this Stream 		 * 		 * The offset is relative to the beginning of the lzma_index 		 * (i.e. usually the beginning of the .xz file). 		 */
name|lzma_vli
name|uncompressed_offset
decl_stmt|;
comment|/** 		 * \brief       Compressed size of this Stream 		 * 		 * This includes all headers except the possible 		 * Stream Padding after this Stream. 		 */
name|lzma_vli
name|compressed_size
decl_stmt|;
comment|/** 		 * \brief       Uncompressed size of this Stream 		 */
name|lzma_vli
name|uncompressed_size
decl_stmt|;
comment|/** 		 * \brief       Size of Stream Padding after this Stream 		 * 		 * If it hasn't been set with lzma_index_stream_padding(), 		 * this defaults to zero. Stream Padding is always 		 * a multiple of four bytes. 		 */
name|lzma_vli
name|padding
decl_stmt|;
name|lzma_vli
name|reserved_vli1
decl_stmt|;
name|lzma_vli
name|reserved_vli2
decl_stmt|;
name|lzma_vli
name|reserved_vli3
decl_stmt|;
name|lzma_vli
name|reserved_vli4
decl_stmt|;
block|}
name|stream
struct|;
struct|struct
block|{
comment|/** 		 * \brief       Block number in the file 		 * 		 * The first Block is 1. 		 */
name|lzma_vli
name|number_in_file
decl_stmt|;
comment|/** 		 * \brief       Compressed start offset of this Block 		 * 		 * This offset is relative to the beginning of the 		 * lzma_index (i.e. usually the beginning of the .xz file). 		 * Normally this is where you should seek in the .xz file 		 * to start decompressing this Block. 		 */
name|lzma_vli
name|compressed_file_offset
decl_stmt|;
comment|/** 		 * \brief       Uncompressed start offset of this Block 		 * 		 * This offset is relative to the beginning of the lzma_index 		 * (i.e. usually the beginning of the .xz file). 		 * 		 * When doing random-access reading, it is possible that 		 * the target offset is not exactly at Block boundary. One 		 * will need to compare the target offset against 		 * uncompressed_file_offset or uncompressed_stream_offset, 		 * and possibly decode and throw away some amount of data 		 * before reaching the target offset. 		 */
name|lzma_vli
name|uncompressed_file_offset
decl_stmt|;
comment|/** 		 * \brief       Block number in this Stream 		 * 		 * The first Block is 1. 		 */
name|lzma_vli
name|number_in_stream
decl_stmt|;
comment|/** 		 * \brief       Compressed start offset of this Block 		 * 		 * This offset is relative to the beginning of the Stream 		 * containing this Block. 		 */
name|lzma_vli
name|compressed_stream_offset
decl_stmt|;
comment|/** 		 * \brief       Uncompressed start offset of this Block 		 * 		 * This offset is relative to the beginning of the Stream 		 * containing this Block. 		 */
name|lzma_vli
name|uncompressed_stream_offset
decl_stmt|;
comment|/** 		 * \brief       Uncompressed size of this Block 		 * 		 * You should pass this to the Block decoder if you will 		 * decode this Block. It will allow the Block decoder to 		 * validate the uncompressed size. 		 */
name|lzma_vli
name|uncompressed_size
decl_stmt|;
comment|/** 		 * \brief       Unpadded size of this Block 		 * 		 * You should pass this to the Block decoder if you will 		 * decode this Block. It will allow the Block decoder to 		 * validate the unpadded size. 		 */
name|lzma_vli
name|unpadded_size
decl_stmt|;
comment|/** 		 * \brief       Total compressed size 		 * 		 * This includes all headers and padding in this Block. 		 * This is useful if you need to know how many bytes 		 * the Block decoder will actually read. 		 */
name|lzma_vli
name|total_size
decl_stmt|;
name|lzma_vli
name|reserved_vli1
decl_stmt|;
name|lzma_vli
name|reserved_vli2
decl_stmt|;
name|lzma_vli
name|reserved_vli3
decl_stmt|;
name|lzma_vli
name|reserved_vli4
decl_stmt|;
specifier|const
name|void
modifier|*
name|reserved_ptr1
decl_stmt|;
specifier|const
name|void
modifier|*
name|reserved_ptr2
decl_stmt|;
specifier|const
name|void
modifier|*
name|reserved_ptr3
decl_stmt|;
specifier|const
name|void
modifier|*
name|reserved_ptr4
decl_stmt|;
block|}
name|block
struct|;
comment|/* 	 * Internal data which is used to store the state of the iterator. 	 * The exact format may vary between liblzma versions, so don't 	 * touch these in any way. 	 */
union|union
block|{
specifier|const
name|void
modifier|*
name|p
decl_stmt|;
name|size_t
name|s
decl_stmt|;
name|lzma_vli
name|v
decl_stmt|;
block|}
name|internal
index|[
literal|6
index|]
union|;
block|}
name|lzma_index_iter
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Operation mode for lzma_index_iter_next()  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LZMA_INDEX_ITER_ANY
init|=
literal|0
block|,
comment|/**< 		 * \brief       Get the next Block or Stream 		 * 		 * Go to the next Block if the current Stream has at least 		 * one Block left. Otherwise go to the next Stream even if 		 * it has no Blocks. If the Stream has no Blocks 		 * (lzma_index_iter.stream.block_count == 0), 		 * lzma_index_iter.block will have undefined values. 		 */
name|LZMA_INDEX_ITER_STREAM
init|=
literal|1
block|,
comment|/**< 		 * \brief       Get the next Stream 		 * 		 * Go to the next Stream even if the current Stream has 		 * unread Blocks left. If the next Stream has at least one 		 * Block, the iterator will point to the first Block. 		 * If there are no Blocks, lzma_index_iter.block will have 		 * undefined values. 		 */
name|LZMA_INDEX_ITER_BLOCK
init|=
literal|2
block|,
comment|/**< 		 * \brief       Get the next Block 		 * 		 * Go to the next Block if the current Stream has at least 		 * one Block left. If the current Stream has no Blocks left, 		 * the next Stream with at least one Block is located and 		 * the iterator will be made to point to the first Block of 		 * that Stream. 		 */
name|LZMA_INDEX_ITER_NONEMPTY_BLOCK
init|=
literal|3
comment|/**< 		 * \brief       Get the next non-empty Block 		 * 		 * This is like LZMA_INDEX_ITER_BLOCK except that it will 		 * skip Blocks whose Uncompressed Size is zero. 		 */
block|}
name|lzma_index_iter_mode
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Calculate memory usage of lzma_index  *  * On disk, the size of the Index field depends on both the number of Records  * stored and how big values the Records store (due to variable-length integer  * encoding). When the Index is kept in lzma_index structure, the memory usage  * depends only on the number of Records/Blocks stored in the Index(es), and  * in case of concatenated lzma_indexes, the number of Streams. The size in  * RAM is almost always significantly bigger than in the encoded form on disk.  *  * This function calculates an approximate amount of memory needed hold  * the given number of Streams and Blocks in lzma_index structure. This  * value may vary between CPU architectures and also between liblzma versions  * if the internal implementation is modified.  */
end_comment

begin_extern
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_index_memusage
argument_list|(
argument|lzma_vli streams
argument_list|,
argument|lzma_vli blocks
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Calculate the memory usage of an existing lzma_index  *  * This is a shorthand for lzma_index_memusage(lzma_index_stream_count(i),  * lzma_index_block_count(i)).  */
end_comment

begin_extern
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_index_memused
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Allocate and initialize a new lzma_index structure  *  * \return      On success, a pointer to an empty initialized lzma_index is  *              returned. If allocation fails, NULL is returned.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_index *
end_extern

begin_macro
unit|)
name|lzma_index_init
argument_list|(
argument|const lzma_allocator *allocator
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Deallocate lzma_index  *  * If i is NULL, this does nothing.  */
end_comment

begin_extern
extern|extern LZMA_API(void
end_extern

begin_macro
unit|)
name|lzma_index_end
argument_list|(
argument|lzma_index *i
argument_list|,
argument|const lzma_allocator *allocator
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Add a new Block to lzma_index  *  * \param       i                 Pointer to a lzma_index structure  * \param       allocator         Pointer to lzma_allocator, or NULL to  *                                use malloc()  * \param       unpadded_size     Unpadded Size of a Block. This can be  *                                calculated with lzma_block_unpadded_size()  *                                after encoding or decoding the Block.  * \param       uncompressed_size Uncompressed Size of a Block. This can be  *                                taken directly from lzma_block structure  *                                after encoding or decoding the Block.  *  * Appending a new Block does not invalidate iterators. For example,  * if an iterator was pointing to the end of the lzma_index, after  * lzma_index_append() it is possible to read the next Block with  * an existing iterator.  *  * \return      - LZMA_OK  *              - LZMA_MEM_ERROR  *              - LZMA_DATA_ERROR: Compressed or uncompressed size of the  *                Stream or size of the Index field would grow too big.  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_append
argument_list|(
argument|lzma_index *i
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|lzma_vli unpadded_size
argument_list|,
argument|lzma_vli uncompressed_size
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Set the Stream Flags  *  * Set the Stream Flags of the last (and typically the only) Stream  * in lzma_index. This can be useful when reading information from the  * lzma_index, because to decode Blocks, knowing the integrity check type  * is needed.  *  * The given Stream Flags are copied into internal preallocated structure  * in the lzma_index, thus the caller doesn't need to keep the *stream_flags  * available after calling this function.  *  * \return      - LZMA_OK  *              - LZMA_OPTIONS_ERROR: Unsupported stream_flags->version.  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_stream_flags
argument_list|(
argument|lzma_index *i
argument_list|,
argument|const lzma_stream_flags *stream_flags
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the types of integrity Checks  *  * If lzma_index_stream_flags() is used to set the Stream Flags for  * every Stream, lzma_index_checks() can be used to get a bitmask to  * indicate which Check types have been used. It can be useful e.g. if  * showing the Check types to the user.  *  * The bitmask is 1<< check_id, e.g. CRC32 is 1<< 1 and SHA-256 is 1<< 10.  */
end_comment

begin_extern
extern|extern LZMA_API(uint32_t
end_extern

begin_macro
unit|)
name|lzma_index_checks
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Set the amount of Stream Padding  *  * Set the amount of Stream Padding of the last (and typically the only)  * Stream in the lzma_index. This is needed when planning to do random-access  * reading within multiple concatenated Streams.  *  * By default, the amount of Stream Padding is assumed to be zero bytes.  *  * \return      - LZMA_OK  *              - LZMA_DATA_ERROR: The file size would grow too big.  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_stream_padding
argument_list|(
argument|lzma_index *i
argument_list|,
argument|lzma_vli stream_padding
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the number of Streams  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_index_stream_count
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the number of Blocks  *  * This returns the total number of Blocks in lzma_index. To get number  * of Blocks in individual Streams, use lzma_index_iter.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_index_block_count
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the size of the Index field as bytes  *  * This is needed to verify the Backward Size field in the Stream Footer.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_index_size
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the total size of the Stream  *  * If multiple lzma_indexes have been combined, this works as if the Blocks  * were in a single Stream. This is useful if you are going to combine  * Blocks from multiple Streams into a single new Stream.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_index_stream_size
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the total size of the Blocks  *  * This doesn't include the Stream Header, Stream Footer, Stream Padding,  * or Index fields.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_index_total_size
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the total size of the file  *  * When no lzma_indexes have been combined with lzma_index_cat() and there is  * no Stream Padding, this function is identical to lzma_index_stream_size().  * If multiple lzma_indexes have been combined, this includes also the headers  * of each separate Stream and the possible Stream Padding fields.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_index_file_size
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Get the uncompressed size of the file  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_vli
end_extern

begin_macro
unit|)
name|lzma_index_uncompressed_size
argument_list|(
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Initialize an iterator  *  * \param       iter    Pointer to a lzma_index_iter structure  * \param       i       lzma_index to which the iterator will be associated  *  * This function associates the iterator with the given lzma_index, and calls  * lzma_index_iter_rewind() on the iterator.  *  * This function doesn't allocate any memory, thus there is no  * lzma_index_iter_end(). The iterator is valid as long as the  * associated lzma_index is valid, that is, until lzma_index_end() or  * using it as source in lzma_index_cat(). Specifically, lzma_index doesn't  * become invalid if new Blocks are added to it with lzma_index_append() or  * if it is used as the destination in lzma_index_cat().  *  * It is safe to make copies of an initialized lzma_index_iter, for example,  * to easily restart reading at some particular position.  */
end_comment

begin_extern
extern|extern LZMA_API(void
end_extern

begin_macro
unit|)
name|lzma_index_iter_init
argument_list|(
argument|lzma_index_iter *iter
argument_list|,
argument|const lzma_index *i
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Rewind the iterator  *  * Rewind the iterator so that next call to lzma_index_iter_next() will  * return the first Block or Stream.  */
end_comment

begin_extern
extern|extern LZMA_API(void
end_extern

begin_macro
unit|)
name|lzma_index_iter_rewind
argument_list|(
argument|lzma_index_iter *iter
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Get the next Block or Stream  *  * \param       iter    Iterator initialized with lzma_index_iter_init()  * \param       mode    Specify what kind of information the caller wants  *                      to get. See lzma_index_iter_mode for details.  *  * \return      If next Block or Stream matching the mode was found, *iter  *              is updated and this function returns false. If no Block or  *              Stream matching the mode is found, *iter is not modified  *              and this function returns true. If mode is set to an unknown  *              value, *iter is not modified and this function returns true.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_bool
end_extern

begin_macro
unit|)
name|lzma_index_iter_next
argument_list|(
argument|lzma_index_iter *iter
argument_list|,
argument|lzma_index_iter_mode mode
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Locate a Block  *  * If it is possible to seek in the .xz file, it is possible to parse  * the Index field(s) and use lzma_index_iter_locate() to do random-access  * reading with granularity of Block size.  *  * \param       iter    Iterator that was earlier initialized with  *                      lzma_index_iter_init().  * \param       target  Uncompressed target offset which the caller would  *                      like to locate from the Stream  *  * If the target is smaller than the uncompressed size of the Stream (can be  * checked with lzma_index_uncompressed_size()):  *  - Information about the Stream and Block containing the requested  *    uncompressed offset is stored into *iter.  *  - Internal state of the iterator is adjusted so that  *    lzma_index_iter_next() can be used to read subsequent Blocks or Streams.  *  - This function returns false.  *  * If target is greater than the uncompressed size of the Stream, *iter  * is not modified, and this function returns true.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_bool
end_extern

begin_macro
unit|)
name|lzma_index_iter_locate
argument_list|(
argument|lzma_index_iter *iter
argument_list|,
argument|lzma_vli target
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Concatenate lzma_indexes  *  * Concatenating lzma_indexes is useful when doing random-access reading in  * multi-Stream .xz file, or when combining multiple Streams into single  * Stream.  *  * \param       dest      lzma_index after which src is appended  * \param       src       lzma_index to be appended after dest. If this  *                        function succeeds, the memory allocated for src  *                        is freed or moved to be part of dest, and all  *                        iterators pointing to src will become invalid.  * \param       allocator Custom memory allocator; can be NULL to use  *                        malloc() and free().  *  * \return      - LZMA_OK: lzma_indexes were concatenated successfully.  *                src is now a dangling pointer.  *              - LZMA_DATA_ERROR: *dest would grow too big.  *              - LZMA_MEM_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_cat
argument_list|(
argument|lzma_index *dest
argument_list|,
argument|lzma_index *src
argument_list|,
argument|const lzma_allocator *allocator
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Duplicate lzma_index  *  * \return      A copy of the lzma_index, or NULL if memory allocation failed.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_index *
end_extern

begin_macro
unit|)
name|lzma_index_dup
argument_list|(
argument|const lzma_index *i
argument_list|,
argument|const lzma_allocator *allocator
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Initialize .xz Index encoder  *  * \param       strm        Pointer to properly prepared lzma_stream  * \param       i           Pointer to lzma_index which should be encoded.  *  * The valid `action' values for lzma_code() are LZMA_RUN and LZMA_FINISH.  * It is enough to use only one of them (you can choose freely; use LZMA_RUN  * to support liblzma versions older than 5.0.0).  *  * \return      - LZMA_OK: Initialization succeeded, continue with lzma_code().  *              - LZMA_MEM_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_encoder
argument_list|(
argument|lzma_stream *strm
argument_list|,
argument|const lzma_index *i
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Initialize .xz Index decoder  *  * \param       strm        Pointer to properly prepared lzma_stream  * \param       i           The decoded Index will be made available via  *                          this pointer. Initially this function will  *                          set *i to NULL (the old value is ignored). If  *                          decoding succeeds (lzma_code() returns  *                          LZMA_STREAM_END), *i will be set to point  *                          to a new lzma_index, which the application  *                          has to later free with lzma_index_end().  * \param       memlimit    How much memory the resulting lzma_index is  *                          allowed to require.  *  * The valid `action' values for lzma_code() are LZMA_RUN and LZMA_FINISH.  * It is enough to use only one of them (you can choose freely; use LZMA_RUN  * to support liblzma versions older than 5.0.0).  *  * \return      - LZMA_OK: Initialization succeeded, continue with lzma_code().  *              - LZMA_MEM_ERROR  *              - LZMA_MEMLIMIT_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_decoder
argument_list|(
argument|lzma_stream *strm
argument_list|,
argument|lzma_index **i
argument_list|,
argument|uint64_t memlimit
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Single-call .xz Index encoder  *  * \param       i         lzma_index to be encoded  * \param       out       Beginning of the output buffer  * \param       out_pos   The next byte will be written to out[*out_pos].  *                        *out_pos is updated only if encoding succeeds.  * \param       out_size  Size of the out buffer; the first byte into  *                        which no data is written to is out[out_size].  *  * \return      - LZMA_OK: Encoding was successful.  *              - LZMA_BUF_ERROR: Output buffer is too small. Use  *                lzma_index_size() to find out how much output  *                space is needed.  *              - LZMA_PROG_ERROR  *  * \note        This function doesn't take allocator argument since all  *              the internal data is allocated on stack.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_buffer_encode
argument_list|(
argument|const lzma_index *i
argument_list|,
argument|uint8_t *out
argument_list|,
argument|size_t *out_pos
argument_list|,
argument|size_t out_size
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Single-call .xz Index decoder  *  * \param       i           If decoding succeeds, *i will point to a new  *                          lzma_index, which the application has to  *                          later free with lzma_index_end(). If an error  *                          occurs, *i will be NULL. The old value of *i  *                          is always ignored and thus doesn't need to be  *                          initialized by the caller.  * \param       memlimit    Pointer to how much memory the resulting  *                          lzma_index is allowed to require. The value  *                          pointed by this pointer is modified if and only  *                          if LZMA_MEMLIMIT_ERROR is returned.  * \param       allocator   Pointer to lzma_allocator, or NULL to use malloc()  * \param       in          Beginning of the input buffer  * \param       in_pos      The next byte will be read from in[*in_pos].  *                          *in_pos is updated only if decoding succeeds.  * \param       in_size     Size of the input buffer; the first byte that  *                          won't be read is in[in_size].  *  * \return      - LZMA_OK: Decoding was successful.  *              - LZMA_MEM_ERROR  *              - LZMA_MEMLIMIT_ERROR: Memory usage limit was reached.  *                The minimum required memlimit value was stored to *memlimit.  *              - LZMA_DATA_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_buffer_decode
argument_list|(
argument|lzma_index **i
argument_list|,
argument|uint64_t *memlimit
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t *in_pos
argument_list|,
argument|size_t in_size
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

end_unit

