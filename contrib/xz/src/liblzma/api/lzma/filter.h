begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/filter.h  * \brief       Common filter related types and functions  */
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
comment|/**  * \brief       Maximum number of filters in a chain  *  * A filter chain can have 1-4 filters, of which three are allowed to change  * the size of the data. Usually only one or two filters are needed.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTERS_MAX
value|4
end_define

begin_comment
comment|/**  * \brief       Filter options  *  * This structure is used to pass Filter ID and a pointer filter's  * options to liblzma. A few functions work with a single lzma_filter  * structure, while most functions expect a filter chain.  *  * A filter chain is indicated with an array of lzma_filter structures.  * The array is terminated with .id = LZMA_VLI_UNKNOWN. Thus, the filter  * array must have LZMA_FILTERS_MAX + 1 elements (that is, five) to  * be able to hold any arbitrary filter chain. This is important when  * using lzma_block_header_decode() from block.h, because too small  * array would make liblzma write past the end of the filters array.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/** 	 * \brief       Filter ID 	 * 	 * Use constants whose name begin with `LZMA_FILTER_' to specify 	 * different filters. In an array of lzma_filter structures, use 	 * LZMA_VLI_UNKNOWN to indicate end of filters. 	 * 	 * \note        This is not an enum, because on some systems enums 	 *              cannot be 64-bit. 	 */
name|lzma_vli
name|id
decl_stmt|;
comment|/** 	 * \brief       Pointer to filter-specific options structure 	 * 	 * If the filter doesn't need options, set this to NULL. If id is 	 * set to LZMA_VLI_UNKNOWN, options is ignored, and thus 	 * doesn't need be initialized. 	 */
name|void
modifier|*
name|options
decl_stmt|;
block|}
name|lzma_filter
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Test if the given Filter ID is supported for encoding  *  * Return true if the give Filter ID is supported for encoding by this  * liblzma build. Otherwise false is returned.  *  * There is no way to list which filters are available in this particular  * liblzma version and build. It would be useless, because the application  * couldn't know what kind of options the filter would need.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_bool
end_extern

begin_macro
unit|)
name|lzma_filter_encoder_is_supported
argument_list|(
argument|lzma_vli id
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Test if the given Filter ID is supported for decoding  *  * Return true if the give Filter ID is supported for decoding by this  * liblzma build. Otherwise false is returned.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_bool
end_extern

begin_macro
unit|)
name|lzma_filter_decoder_is_supported
argument_list|(
argument|lzma_vli id
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Copy the filters array  *  * Copy the Filter IDs and filter-specific options from src to dest.  * Up to LZMA_FILTERS_MAX filters are copied, plus the terminating  * .id == LZMA_VLI_UNKNOWN. Thus, dest should have at least  * LZMA_FILTERS_MAX + 1 elements space unless the caller knows that  * src is smaller than that.  *  * Unless the filter-specific options is NULL, the Filter ID has to be  * supported by liblzma, because liblzma needs to know the size of every  * filter-specific options structure. The filter-specific options are not  * validated. If options is NULL, any unsupported Filter IDs are copied  * without returning an error.  *  * Old filter-specific options in dest are not freed, so dest doesn't  * need to be initialized by the caller in any way.  *  * If an error occurs, memory possibly already allocated by this function  * is always freed.  *  * \return      - LZMA_OK  *              - LZMA_MEM_ERROR  *              - LZMA_OPTIONS_ERROR: Unsupported Filter ID and its options  *                is not NULL.  *              - LZMA_PROG_ERROR: src or dest is NULL.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filters_copy
argument_list|(
argument|const lzma_filter *src
argument_list|,
argument|lzma_filter *dest
argument_list|,
argument|const lzma_allocator *allocator
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Calculate approximate memory requirements for raw encoder  *  * This function can be used to calculate the memory requirements for  * Block and Stream encoders too because Block and Stream encoders don't  * need significantly more memory than raw encoder.  *  * \param       filters     Array of filters terminated with  *                          .id == LZMA_VLI_UNKNOWN.  *  * \return      Number of bytes of memory required for the given  *              filter chain when encoding. If an error occurs,  *              for example due to unsupported filter chain,  *              UINT64_MAX is returned.  */
end_comment

begin_extern
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_raw_encoder_memusage
argument_list|(
argument|const lzma_filter *filters
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Calculate approximate memory requirements for raw decoder  *  * This function can be used to calculate the memory requirements for  * Block and Stream decoders too because Block and Stream decoders don't  * need significantly more memory than raw decoder.  *  * \param       filters     Array of filters terminated with  *                          .id == LZMA_VLI_UNKNOWN.  *  * \return      Number of bytes of memory required for the given  *              filter chain when decoding. If an error occurs,  *              for example due to unsupported filter chain,  *              UINT64_MAX is returned.  */
end_comment

begin_extern
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_raw_decoder_memusage
argument_list|(
argument|const lzma_filter *filters
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Initialize raw encoder  *  * This function may be useful when implementing custom file formats.  *  * \param       strm    Pointer to properly prepared lzma_stream  * \param       filters Array of lzma_filter structures. The end of the  *                      array must be marked with .id = LZMA_VLI_UNKNOWN.  *  * The `action' with lzma_code() can be LZMA_RUN, LZMA_SYNC_FLUSH (if the  * filter chain supports it), or LZMA_FINISH.  *  * \return      - LZMA_OK  *              - LZMA_MEM_ERROR  *              - LZMA_OPTIONS_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_raw_encoder
argument_list|(
argument|lzma_stream *strm
argument_list|,
argument|const lzma_filter *filters
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Initialize raw decoder  *  * The initialization of raw decoder goes similarly to raw encoder.  *  * The `action' with lzma_code() can be LZMA_RUN or LZMA_FINISH. Using  * LZMA_FINISH is not required, it is supported just for convenience.  *  * \return      - LZMA_OK  *              - LZMA_MEM_ERROR  *              - LZMA_OPTIONS_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_raw_decoder
argument_list|(
argument|lzma_stream *strm
argument_list|,
argument|const lzma_filter *filters
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Update the filter chain in the encoder  *  * This function is for advanced users only. This function has two slightly  * different purposes:  *  *  - After LZMA_FULL_FLUSH when using Stream encoder: Set a new filter  *    chain, which will be used starting from the next Block.  *  *  - After LZMA_SYNC_FLUSH using Raw, Block, or Stream encoder: Change  *    the filter-specific options in the middle of encoding. The actual  *    filters in the chain (Filter IDs) cannot be changed. In the future,  *    it might become possible to change the filter options without  *    using LZMA_SYNC_FLUSH.  *  * While rarely useful, this function may be called also when no data has  * been compressed yet. In that case, this function will behave as if  * LZMA_FULL_FLUSH (Stream encoder) or LZMA_SYNC_FLUSH (Raw or Block  * encoder) had been used right before calling this function.  *  * \return      - LZMA_OK  *              - LZMA_MEM_ERROR  *              - LZMA_MEMLIMIT_ERROR  *              - LZMA_OPTIONS_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filters_update
argument_list|(
argument|lzma_stream *strm
argument_list|,
argument|const lzma_filter *filters
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Single-call raw encoder  *  * \param       filters     Array of lzma_filter structures. The end of the  *                          array must be marked with .id = LZMA_VLI_UNKNOWN.  * \param       allocator   lzma_allocator for custom allocator functions.  *                          Set to NULL to use malloc() and free().  * \param       in          Beginning of the input buffer  * \param       in_size     Size of the input buffer  * \param       out         Beginning of the output buffer  * \param       out_pos     The next byte will be written to out[*out_pos].  *                          *out_pos is updated only if encoding succeeds.  * \param       out_size    Size of the out buffer; the first byte into  *                          which no data is written to is out[out_size].  *  * \return      - LZMA_OK: Encoding was successful.  *              - LZMA_BUF_ERROR: Not enough output buffer space.  *              - LZMA_OPTIONS_ERROR  *              - LZMA_MEM_ERROR  *              - LZMA_DATA_ERROR  *              - LZMA_PROG_ERROR  *  * \note        There is no function to calculate how big output buffer  *              would surely be big enough. (lzma_stream_buffer_bound()  *              works only for lzma_stream_buffer_encode(); raw encoder  *              won't necessarily meet that bound.)  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_raw_buffer_encode
argument_list|(
argument|const lzma_filter *filters
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t in_size
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
comment|/**  * \brief       Single-call raw decoder  *  * \param       filters     Array of lzma_filter structures. The end of the  *                          array must be marked with .id = LZMA_VLI_UNKNOWN.  * \param       allocator   lzma_allocator for custom allocator functions.  *                          Set to NULL to use malloc() and free().  * \param       in          Beginning of the input buffer  * \param       in_pos      The next byte will be read from in[*in_pos].  *                          *in_pos is updated only if decoding succeeds.  * \param       in_size     Size of the input buffer; the first byte that  *                          won't be read is in[in_size].  * \param       out         Beginning of the output buffer  * \param       out_pos     The next byte will be written to out[*out_pos].  *                          *out_pos is updated only if encoding succeeds.  * \param       out_size    Size of the out buffer; the first byte into  *                          which no data is written to is out[out_size].  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_raw_buffer_decode
argument_list|(
argument|const lzma_filter *filters
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *in
argument_list|,
argument|size_t *in_pos
argument_list|,
argument|size_t in_size
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
comment|/**  * \brief       Get the size of the Filter Properties field  *  * This function may be useful when implementing custom file formats  * using the raw encoder and decoder.  *  * \param       size    Pointer to uint32_t to hold the size of the properties  * \param       filter  Filter ID and options (the size of the properties may  *                      vary depending on the options)  *  * \return      - LZMA_OK  *              - LZMA_OPTIONS_ERROR  *              - LZMA_PROG_ERROR  *  * \note        This function validates the Filter ID, but does not  *              necessarily validate the options. Thus, it is possible  *              that this returns LZMA_OK while the following call to  *              lzma_properties_encode() returns LZMA_OPTIONS_ERROR.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_properties_size
argument_list|(
argument|uint32_t *size
argument_list|,
argument|const lzma_filter *filter
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Encode the Filter Properties field  *  * \param       filter  Filter ID and options  * \param       props   Buffer to hold the encoded options. The size of  *                      buffer must have been already determined with  *                      lzma_properties_size().  *  * \return      - LZMA_OK  *              - LZMA_OPTIONS_ERROR  *              - LZMA_PROG_ERROR  *  * \note        Even this function won't validate more options than actually  *              necessary. Thus, it is possible that encoding the properties  *              succeeds but using the same options to initialize the encoder  *              will fail.  *  * \note        If lzma_properties_size() indicated that the size  *              of the Filter Properties field is zero, calling  *              lzma_properties_encode() is not required, but it  *              won't do any harm either.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_properties_encode
argument_list|(
argument|const lzma_filter *filter
argument_list|,
argument|uint8_t *props
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Decode the Filter Properties field  *  * \param       filter      filter->id must have been set to the correct  *                          Filter ID. filter->options doesn't need to be  *                          initialized (it's not freed by this function). The  *                          decoded options will be stored to filter->options.  *                          filter->options is set to NULL if there are no  *                          properties or if an error occurs.  * \param       allocator   Custom memory allocator used to allocate the  *                          options. Set to NULL to use the default malloc(),  *                          and in case of an error, also free().  * \param       props       Input buffer containing the properties.  * \param       props_size  Size of the properties. This must be the exact  *                          size; giving too much or too little input will  *                          return LZMA_OPTIONS_ERROR.  *  * \return      - LZMA_OK  *              - LZMA_OPTIONS_ERROR  *              - LZMA_MEM_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_properties_decode
argument_list|(
argument|lzma_filter *filter
argument_list|,
argument|const lzma_allocator *allocator
argument_list|,
argument|const uint8_t *props
argument_list|,
argument|size_t props_size
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Calculate encoded size of a Filter Flags field  *  * Knowing the size of Filter Flags is useful to know when allocating  * memory to hold the encoded Filter Flags.  *  * \param       size    Pointer to integer to hold the calculated size  * \param       filter  Filter ID and associated options whose encoded  *                      size is to be calculated  *  * \return      - LZMA_OK: *size set successfully. Note that this doesn't  *                guarantee that filter->options is valid, thus  *                lzma_filter_flags_encode() may still fail.  *              - LZMA_OPTIONS_ERROR: Unknown Filter ID or unsupported options.  *              - LZMA_PROG_ERROR: Invalid options  *  * \note        If you need to calculate size of List of Filter Flags,  *              you need to loop over every lzma_filter entry.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filter_flags_size
argument_list|(
argument|uint32_t *size
argument_list|,
argument|const lzma_filter *filter
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Encode Filter Flags into given buffer  *  * In contrast to some functions, this doesn't allocate the needed buffer.  * This is due to how this function is used internally by liblzma.  *  * \param       filter      Filter ID and options to be encoded  * \param       out         Beginning of the output buffer  * \param       out_pos     out[*out_pos] is the next write position. This  *                          is updated by the encoder.  * \param       out_size    out[out_size] is the first byte to not write.  *  * \return      - LZMA_OK: Encoding was successful.  *              - LZMA_OPTIONS_ERROR: Invalid or unsupported options.  *              - LZMA_PROG_ERROR: Invalid options or not enough output  *                buffer space (you should have checked it with  *                lzma_filter_flags_size()).  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filter_flags_encode
argument_list|(
argument|const lzma_filter *filter
argument_list|,
argument|uint8_t *out
argument_list|,
argument|size_t *out_pos
argument_list|,
argument|size_t out_size
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Decode Filter Flags from given buffer  *  * The decoded result is stored into *filter. The old value of  * filter->options is not free()d.  *  * \return      - LZMA_OK  *              - LZMA_OPTIONS_ERROR  *              - LZMA_MEM_ERROR  *              - LZMA_PROG_ERROR  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_filter_flags_decode
argument_list|(
argument|lzma_filter *filter
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

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

end_unit

