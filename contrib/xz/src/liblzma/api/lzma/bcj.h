begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/bcj.h  * \brief       Branch/Call/Jump conversion filters  */
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
comment|/* Filter IDs for lzma_filter.id */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_X86
value|LZMA_VLI_C(0x04)
end_define

begin_comment
comment|/**< 	 * Filter for x86 binaries 	 */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_POWERPC
value|LZMA_VLI_C(0x05)
end_define

begin_comment
comment|/**< 	 * Filter for Big endian PowerPC binaries 	 */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_IA64
value|LZMA_VLI_C(0x06)
end_define

begin_comment
comment|/**< 	 * Filter for IA-64 (Itanium) binaries. 	 */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_ARM
value|LZMA_VLI_C(0x07)
end_define

begin_comment
comment|/**< 	 * Filter for ARM binaries. 	 */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_ARMTHUMB
value|LZMA_VLI_C(0x08)
end_define

begin_comment
comment|/**< 	 * Filter for ARM-Thumb binaries. 	 */
end_comment

begin_define
define|#
directive|define
name|LZMA_FILTER_SPARC
value|LZMA_VLI_C(0x09)
end_define

begin_comment
comment|/**< 	 * Filter for SPARC binaries. 	 */
end_comment

begin_comment
comment|/**  * \brief       Options for BCJ filters  *  * The BCJ filters never change the size of the data. Specifying options  * for them is optional: if pointer to options is NULL, default value is  * used. You probably never need to specify options to BCJ filters, so just  * set the options pointer to NULL and be happy.  *  * If options with non-default values have been specified when encoding,  * the same options must also be specified when decoding.  *  * \note        At the moment, none of the BCJ filters support  *              LZMA_SYNC_FLUSH. If LZMA_SYNC_FLUSH is specified,  *              LZMA_OPTIONS_ERROR will be returned. If there is need,  *              partial support for LZMA_SYNC_FLUSH can be added in future.  *              Partial means that flushing would be possible only at  *              offsets that are multiple of 2, 4, or 16 depending on  *              the filter, except x86 which cannot be made to support  *              LZMA_SYNC_FLUSH predictably.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/** 	 * \brief       Start offset for conversions 	 * 	 * This setting is useful only when the same filter is used 	 * _separately_ for multiple sections of the same executable file, 	 * and the sections contain cross-section branch/call/jump 	 * instructions. In that case it is beneficial to set the start 	 * offset of the non-first sections so that the relative addresses 	 * of the cross-section branch/call/jump instructions will use the 	 * same absolute addresses as in the first section. 	 * 	 * When the pointer to options is NULL, the default value (zero) 	 * is used. 	 */
name|uint32_t
name|start_offset
decl_stmt|;
block|}
name|lzma_options_bcj
typedef|;
end_typedef

end_unit

