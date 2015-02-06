begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/index_hash.h  * \brief       Validate Index by using a hash function  *  * Hashing makes it possible to use constant amount of memory to validate  * Index of arbitrary size.  */
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
comment|/**  * \brief       Opaque data type to hold the Index hash  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|lzma_index_hash_s
name|lzma_index_hash
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Allocate and initialize a new lzma_index_hash structure  *  * If index_hash is NULL, a new lzma_index_hash structure is allocated,  * initialized, and a pointer to it returned. If allocation fails, NULL  * is returned.  *  * If index_hash is non-NULL, it is reinitialized and the same pointer  * returned. In this case, return value cannot be NULL or a different  * pointer than the index_hash that was given as an argument.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_index_hash *
end_extern

begin_macro
unit|)
name|lzma_index_hash_init
argument_list|(
argument|lzma_index_hash *index_hash
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
comment|/**  * \brief       Deallocate lzma_index_hash structure  */
end_comment

begin_extern
extern|extern LZMA_API(void
end_extern

begin_macro
unit|)
name|lzma_index_hash_end
argument_list|(
argument|lzma_index_hash *index_hash
argument_list|,
argument|const lzma_allocator *allocator
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Add a new Record to an Index hash  *  * \param       index             Pointer to a lzma_index_hash structure  * \param       unpadded_size     Unpadded Size of a Block  * \param       uncompressed_size Uncompressed Size of a Block  *  * \return      - LZMA_OK  *              - LZMA_DATA_ERROR: Compressed or uncompressed size of the  *                Stream or size of the Index field would grow too big.  *              - LZMA_PROG_ERROR: Invalid arguments or this function is being  *                used when lzma_index_hash_decode() has already been used.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_hash_append
argument_list|(
argument|lzma_index_hash *index_hash
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
comment|/**  * \brief       Decode and validate the Index field  *  * After telling the sizes of all Blocks with lzma_index_hash_append(),  * the actual Index field is decoded with this function. Specifically,  * once decoding of the Index field has been started, no more Records  * can be added using lzma_index_hash_append().  *  * This function doesn't use lzma_stream structure to pass the input data.  * Instead, the input buffer is specified using three arguments. This is  * because it matches better the internal APIs of liblzma.  *  * \param       index_hash      Pointer to a lzma_index_hash structure  * \param       in              Pointer to the beginning of the input buffer  * \param       in_pos          in[*in_pos] is the next byte to process  * \param       in_size         in[in_size] is the first byte not to process  *  * \return      - LZMA_OK: So far good, but more input is needed.  *              - LZMA_STREAM_END: Index decoded successfully and it matches  *                the Records given with lzma_index_hash_append().  *              - LZMA_DATA_ERROR: Index is corrupt or doesn't match the  *                information given with lzma_index_hash_append().  *              - LZMA_BUF_ERROR: Cannot progress because *in_pos>= in_size.  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_index_hash_decode
argument_list|(
argument|lzma_index_hash *index_hash
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t *in_pos
argument_list|,
argument|size_t in_size
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
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
name|lzma_index_hash_size
argument_list|(
argument|const lzma_index_hash *index_hash
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

end_unit

