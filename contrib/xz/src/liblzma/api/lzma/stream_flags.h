begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/stream_flags.h  * \brief       .xz Stream Header and Stream Footer encoder and decoder  */
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
comment|/**  * \brief       Size of Stream Header and Stream Footer  *  * Stream Header and Stream Footer have the same size and they are not  * going to change even if a newer version of the .xz file format is  * developed in future.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_STREAM_HEADER_SIZE
value|12
end_define

begin_comment
comment|/**  * \brief       Options for encoding/decoding Stream Header and Stream Footer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/** 	 * \brief       Stream Flags format version 	 * 	 * To prevent API and ABI breakages if new features are needed in 	 * Stream Header or Stream Footer, a version number is used to 	 * indicate which fields in this structure are in use. For now, 	 * version must always be zero. With non-zero version, the 	 * lzma_stream_header_encode() and lzma_stream_footer_encode() 	 * will return LZMA_OPTIONS_ERROR. 	 * 	 * lzma_stream_header_decode() and lzma_stream_footer_decode() 	 * will always set this to the lowest value that supports all the 	 * features indicated by the Stream Flags field. The application 	 * must check that the version number set by the decoding functions 	 * is supported by the application. Otherwise it is possible that 	 * the application will decode the Stream incorrectly. 	 */
name|uint32_t
name|version
decl_stmt|;
comment|/** 	 * \brief       Backward Size 	 * 	 * Backward Size must be a multiple of four bytes. In this Stream 	 * format version, Backward Size is the size of the Index field. 	 * 	 * Backward Size isn't actually part of the Stream Flags field, but 	 * it is convenient to include in this structure anyway. Backward 	 * Size is present only in the Stream Footer. There is no need to 	 * initialize backward_size when encoding Stream Header. 	 * 	 * lzma_stream_header_decode() always sets backward_size to 	 * LZMA_VLI_UNKNOWN so that it is convenient to use 	 * lzma_stream_flags_compare() when both Stream Header and Stream 	 * Footer have been decoded. 	 */
name|lzma_vli
name|backward_size
decl_stmt|;
define|#
directive|define
name|LZMA_BACKWARD_SIZE_MIN
value|4
define|#
directive|define
name|LZMA_BACKWARD_SIZE_MAX
value|(LZMA_VLI_C(1)<< 34)
comment|/** 	 * \brief       Check ID 	 * 	 * This indicates the type of the integrity check calculated from 	 * uncompressed data. 	 */
name|lzma_check
name|check
decl_stmt|;
comment|/* 	 * Reserved space to allow possible future extensions without 	 * breaking the ABI. You should not touch these, because the 	 * names of these variables may change. 	 * 	 * (We will never be able to use all of these since Stream Flags 	 * is just two bytes plus Backward Size of four bytes. But it's 	 * nice to have the proper types when they are needed.) 	 */
name|lzma_reserved_enum
name|reserved_enum1
decl_stmt|;
name|lzma_reserved_enum
name|reserved_enum2
decl_stmt|;
name|lzma_reserved_enum
name|reserved_enum3
decl_stmt|;
name|lzma_reserved_enum
name|reserved_enum4
decl_stmt|;
name|lzma_bool
name|reserved_bool1
decl_stmt|;
name|lzma_bool
name|reserved_bool2
decl_stmt|;
name|lzma_bool
name|reserved_bool3
decl_stmt|;
name|lzma_bool
name|reserved_bool4
decl_stmt|;
name|lzma_bool
name|reserved_bool5
decl_stmt|;
name|lzma_bool
name|reserved_bool6
decl_stmt|;
name|lzma_bool
name|reserved_bool7
decl_stmt|;
name|lzma_bool
name|reserved_bool8
decl_stmt|;
name|uint32_t
name|reserved_int1
decl_stmt|;
name|uint32_t
name|reserved_int2
decl_stmt|;
block|}
name|lzma_stream_flags
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Encode Stream Header  *  * \param       options     Stream Header options to be encoded.  *                          options->backward_size is ignored and doesn't  *                          need to be initialized.  * \param       out         Beginning of the output buffer of  *                          LZMA_STREAM_HEADER_SIZE bytes.  *  * \return      - LZMA_OK: Encoding was successful.  *              - LZMA_OPTIONS_ERROR: options->version is not supported by  *                this liblzma version.  *              - LZMA_PROG_ERROR: Invalid options.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_header_encode
argument_list|(
argument|const lzma_stream_flags *options
argument_list|,
argument|uint8_t *out
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Encode Stream Footer  *  * \param       options     Stream Footer options to be encoded.  * \param       out         Beginning of the output buffer of  *                          LZMA_STREAM_HEADER_SIZE bytes.  *  * \return      - LZMA_OK: Encoding was successful.  *              - LZMA_OPTIONS_ERROR: options->version is not supported by  *                this liblzma version.  *              - LZMA_PROG_ERROR: Invalid options.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_footer_encode
argument_list|(
argument|const lzma_stream_flags *options
argument_list|,
argument|uint8_t *out
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Decode Stream Header  *  * \param       options     Target for the decoded Stream Header options.  * \param       in          Beginning of the input buffer of  *                          LZMA_STREAM_HEADER_SIZE bytes.  *  * options->backward_size is always set to LZMA_VLI_UNKNOWN. This is to  * help comparing Stream Flags from Stream Header and Stream Footer with  * lzma_stream_flags_compare().  *  * \return      - LZMA_OK: Decoding was successful.  *              - LZMA_FORMAT_ERROR: Magic bytes don't match, thus the given  *                buffer cannot be Stream Header.  *              - LZMA_DATA_ERROR: CRC32 doesn't match, thus the header  *                is corrupt.  *              - LZMA_OPTIONS_ERROR: Unsupported options are present  *                in the header.  *  * \note        When decoding .xz files that contain multiple Streams, it may  *              make sense to print "file format not recognized" only if  *              decoding of the Stream Header of the _first_ Stream gives  *              LZMA_FORMAT_ERROR. If non-first Stream Header gives  *              LZMA_FORMAT_ERROR, the message used for LZMA_DATA_ERROR is  *              probably more appropriate.  *  *              For example, Stream decoder in liblzma uses LZMA_DATA_ERROR if  *              LZMA_FORMAT_ERROR is returned by lzma_stream_header_decode()  *              when decoding non-first Stream.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_header_decode
argument_list|(
argument|lzma_stream_flags *options
argument_list|,
argument|const uint8_t *in
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Decode Stream Footer  *  * \param       options     Target for the decoded Stream Header options.  * \param       in          Beginning of the input buffer of  *                          LZMA_STREAM_HEADER_SIZE bytes.  *  * \return      - LZMA_OK: Decoding was successful.  *              - LZMA_FORMAT_ERROR: Magic bytes don't match, thus the given  *                buffer cannot be Stream Footer.  *              - LZMA_DATA_ERROR: CRC32 doesn't match, thus the Stream Footer  *                is corrupt.  *              - LZMA_OPTIONS_ERROR: Unsupported options are present  *                in Stream Footer.  *  * \note        If Stream Header was already decoded successfully, but  *              decoding Stream Footer returns LZMA_FORMAT_ERROR, the  *              application should probably report some other error message  *              than "file format not recognized", since the file more likely  *              is corrupt (possibly truncated). Stream decoder in liblzma  *              uses LZMA_DATA_ERROR in this situation.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_footer_decode
argument_list|(
argument|lzma_stream_flags *options
argument_list|,
argument|const uint8_t *in
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_warn_unused_result
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**  * \brief       Compare two lzma_stream_flags structures  *  * backward_size values are compared only if both are not  * LZMA_VLI_UNKNOWN.  *  * \return      - LZMA_OK: Both are equal. If either had backward_size set  *                to LZMA_VLI_UNKNOWN, backward_size values were not  *                compared or validated.  *              - LZMA_DATA_ERROR: The structures differ.  *              - LZMA_OPTIONS_ERROR: version in either structure is greater  *                than the maximum supported version (currently zero).  *              - LZMA_PROG_ERROR: Invalid value, e.g. invalid check or  *                backward_size.  */
end_comment

begin_extern
extern|extern LZMA_API(lzma_ret
end_extern

begin_macro
unit|)
name|lzma_stream_flags_compare
argument_list|(
argument|const lzma_stream_flags *a
argument_list|,
argument|const lzma_stream_flags *b
argument_list|)
end_macro

begin_decl_stmt
name|lzma_nothrow
name|lzma_attr_pure
decl_stmt|;
end_decl_stmt

end_unit

