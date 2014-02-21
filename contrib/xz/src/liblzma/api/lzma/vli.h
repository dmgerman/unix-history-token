begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/vli.h  * \brief       Variable-length integer handling  *  * In the .xz format, most integers are encoded in a variable-length  * representation, which is sometimes called little endian base-128 encoding.  * This saves space when smaller values are more likely than bigger values.  *  * The encoding scheme encodes seven bits to every byte, using minimum  * number of bytes required to represent the given value. Encodings that use  * non-minimum number of bytes are invalid, thus every integer has exactly  * one encoded representation. The maximum number of bits in a VLI is 63,  * thus the vli argument must be less than or equal to UINT64_MAX / 2. You  * should use LZMA_VLI_MAX for clarity.  */
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
comment|/**  * \brief       Maximum supported value of a variable-length integer  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VLI_MAX
value|(UINT64_MAX / 2)
end_define

begin_comment
comment|/**  * \brief       VLI value to denote that the value is unknown  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VLI_UNKNOWN
value|UINT64_MAX
end_define

begin_comment
comment|/**  * \brief       Maximum supported encoded length of variable length integers  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VLI_BYTES_MAX
value|9
end_define

begin_comment
comment|/**  * \brief       VLI constant suffix  */
end_comment

begin_define
define|#
directive|define
name|LZMA_VLI_C
parameter_list|(
name|n
parameter_list|)
value|UINT64_C(n)
end_define

begin_comment
comment|/**  * \brief       Variable-length integer type  *  * Valid VLI values are in the range [0, LZMA_VLI_MAX]. Unknown value is  * indicated with LZMA_VLI_UNKNOWN, which is the maximum value of the  * underlaying integer type.  *  * lzma_vli will be uint64_t for the foreseeable future. If a bigger size  * is needed in the future, it is guaranteed that 2 * LZMA_VLI_MAX will  * not overflow lzma_vli. This simplifies integer overflow detection.  */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|lzma_vli
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Validate a variable-length integer  *  * This is useful to test that application has given acceptable values  * for example in the uncompressed_size and compressed_size variables.  *  * \return      True if the integer is representable as VLI or if it  *              indicates unknown value.  */
end_comment

begin_define
define|#
directive|define
name|lzma_vli_is_valid
parameter_list|(
name|vli
parameter_list|)
define|\
value|((vli)<= LZMA_VLI_MAX || (vli) == LZMA_VLI_UNKNOWN)
end_define

begin_comment
comment|/**  * \brief       Encode a variable-length integer  *  * This function has two modes: single-call and multi-call. Single-call mode  * encodes the whole integer at once; it is an error if the output buffer is  * too small. Multi-call mode saves the position in *vli_pos, and thus it is  * possible to continue encoding if the buffer becomes full before the whole  * integer has been encoded.  *  * \param       vli       Integer to be encoded  * \param       vli_pos   How many VLI-encoded bytes have already been written  *                        out. When starting to encode a new integer in  *                        multi-call mode, *vli_pos must be set to zero.  *                        To use single-call encoding, set vli_pos to NULL.  * \param       out       Beginning of the output buffer  * \param       out_pos   The next byte will be written to out[*out_pos].  * \param       out_size  Size of the out buffer; the first byte into  *                        which no data is written to is out[out_size].  *  * \return      Slightly different return values are used in multi-call and  *              single-call modes.  *  *              Single-call (vli_pos == NULL):  *              - LZMA_OK: Integer successfully encoded.  *              - LZMA_PROG_ERROR: Arguments are not sane. This can be due  *                to too little output space; single-call mode doesn't use  *                LZMA_BUF_ERROR, since the application should have checked  *                the encoded size with lzma_vli_size().  *  *              Multi-call (vli_pos != NULL):  *              - LZMA_OK: So far all OK, but the integer is not  *                completely written out yet.  *              - LZMA_STREAM_END: Integer successfully encoded.  *              - LZMA_BUF_ERROR: No output space was provided.  *              - LZMA_PROG_ERROR: Arguments are not sane.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_vli_encode
argument_list|(
argument|lzma_vli vli
argument_list|,
argument|size_t *vli_pos
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
comment|/**  * \brief       Decode a variable-length integer  *  * Like lzma_vli_encode(), this function has single-call and multi-call modes.  *  * \param       vli       Pointer to decoded integer. The decoder will  *                        initialize it to zero when *vli_pos == 0, so  *                        application isn't required to initialize *vli.  * \param       vli_pos   How many bytes have already been decoded. When  *                        starting to decode a new integer in multi-call  *                        mode, *vli_pos must be initialized to zero. To  *                        use single-call decoding, set vli_pos to NULL.  * \param       in        Beginning of the input buffer  * \param       in_pos    The next byte will be read from in[*in_pos].  * \param       in_size   Size of the input buffer; the first byte that  *                        won't be read is in[in_size].  *  * \return      Slightly different return values are used in multi-call and  *              single-call modes.  *  *              Single-call (vli_pos == NULL):  *              - LZMA_OK: Integer successfully decoded.  *              - LZMA_DATA_ERROR: Integer is corrupt. This includes hitting  *                the end of the input buffer before the whole integer was  *                decoded; providing no input at all will use LZMA_DATA_ERROR.  *              - LZMA_PROG_ERROR: Arguments are not sane.  *  *              Multi-call (vli_pos != NULL):  *              - LZMA_OK: So far all OK, but the integer is not  *                completely decoded yet.  *              - LZMA_STREAM_END: Integer successfully decoded.  *              - LZMA_DATA_ERROR: Integer is corrupt.  *              - LZMA_BUF_ERROR: No input was provided.  *              - LZMA_PROG_ERROR: Arguments are not sane.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_vli_decode
argument_list|(
argument|lzma_vli *vli
argument_list|,
argument|size_t *vli_pos
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

begin_comment
comment|/**  * \brief       Get the number of bytes required to encode a VLI  *  * \return      Number of bytes on success (1-9). If vli isn't valid,  *              zero is returned.  */
end_comment

begin_extern
extern|extern LZMA_API(uint32_t
end_extern

begin_macro
unit|)
name|lzma_vli_size
argument_list|(
argument|lzma_vli vli
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

end_unit

