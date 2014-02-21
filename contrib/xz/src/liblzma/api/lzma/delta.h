begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/delta.h  * \brief       Delta filter  */
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
comment|/**  * \brief       Filter ID  *  * Filter ID of the Delta filter. This is used as lzma_filter.id.  */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_DELTA
value|LZMA_VLI_C(0x03)
end_define

begin_comment
comment|/**  * \brief       Type of the delta calculation  *  * Currently only byte-wise delta is supported. Other possible types could  * be, for example, delta of 16/32/64-bit little/big endian integers, but  * these are not currently planned since byte-wise delta is almost as good.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LZMA_DELTA_TYPE_BYTE
block|}
name|lzma_delta_type
typedef|;
end_typedef

begin_comment
comment|/**  * \brief       Options for the Delta filter  *  * These options are needed by both encoder and decoder.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/** For now, this must always be LZMA_DELTA_TYPE_BYTE. */
name|lzma_delta_type
name|type
decl_stmt|;
comment|/** 	 * \brief       Delta distance 	 * 	 * With the only currently supported type, LZMA_DELTA_TYPE_BYTE, 	 * the distance is as bytes. 	 * 	 * Examples: 	 *  - 16-bit stereo audio: distance = 4 bytes 	 *  - 24-bit RGB image data: distance = 3 bytes 	 */
name|uint32_t
name|dist
decl_stmt|;
define|#
directive|define
name|LZMA_DELTA_DIST_MIN
value|1
define|#
directive|define
name|LZMA_DELTA_DIST_MAX
value|256
comment|/* 	 * Reserved space to allow possible future extensions without 	 * breaking the ABI. You should not touch these, because the names 	 * of these variables may change. These are and will never be used 	 * when type is LZMA_DELTA_TYPE_BYTE, so it is safe to leave these 	 * uninitialized. 	 */
name|uint32_t
name|reserved_int1
decl_stmt|;
name|uint32_t
name|reserved_int2
decl_stmt|;
name|uint32_t
name|reserved_int3
decl_stmt|;
name|uint32_t
name|reserved_int4
decl_stmt|;
name|void
modifier|*
name|reserved_ptr1
decl_stmt|;
name|void
modifier|*
name|reserved_ptr2
decl_stmt|;
block|}
name|lzma_options_delta
typedef|;
end_typedef

end_unit

