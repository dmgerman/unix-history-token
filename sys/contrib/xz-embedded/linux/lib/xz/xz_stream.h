begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for handling the .xz file format  *  * Author: Lasse Collin<lasse.collin@tukaani.org>  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XZ_STREAM_H
end_ifndef

begin_define
define|#
directive|define
name|XZ_STREAM_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|&&
operator|!
name|XZ_INTERNAL_CRC32
end_if

begin_include
include|#
directive|include
file|<linux/crc32.h>
end_include

begin_undef
undef|#
directive|undef
name|crc32
end_undef

begin_define
define|#
directive|define
name|xz_crc32
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|,
name|crc
parameter_list|)
define|\
value|(~crc32_le(~(uint32_t)(crc), buf, size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * See the .xz file format specification at  * http://tukaani.org/xz/xz-file-format.txt  * to understand the container format.  */
end_comment

begin_define
define|#
directive|define
name|STREAM_HEADER_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|HEADER_MAGIC
value|"\3757zXZ"
end_define

begin_define
define|#
directive|define
name|HEADER_MAGIC_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|FOOTER_MAGIC
value|"YZ"
end_define

begin_define
define|#
directive|define
name|FOOTER_MAGIC_SIZE
value|2
end_define

begin_comment
comment|/*  * Variable-length integer can hold a 63-bit unsigned integer or a special  * value indicating that the value is unknown.  *  * Experimental: vli_type can be defined to uint32_t to save a few bytes  * in code size (no effect on speed). Doing so limits the uncompressed and  * compressed size of the file to less than 256 MiB and may also weaken  * error detection slightly.  */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|vli_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VLI_MAX
value|((vli_type)-1 / 2)
end_define

begin_define
define|#
directive|define
name|VLI_UNKNOWN
value|((vli_type)-1)
end_define

begin_comment
comment|/* Maximum encoded size of a VLI */
end_comment

begin_define
define|#
directive|define
name|VLI_BYTES_MAX
value|(sizeof(vli_type) * 8 / 7)
end_define

begin_comment
comment|/* Integrity Check types */
end_comment

begin_enum
enum|enum
name|xz_check
block|{
name|XZ_CHECK_NONE
init|=
literal|0
block|,
name|XZ_CHECK_CRC32
init|=
literal|1
block|,
name|XZ_CHECK_CRC64
init|=
literal|4
block|,
name|XZ_CHECK_SHA256
init|=
literal|10
block|}
enum|;
end_enum

begin_comment
comment|/* Maximum possible Check ID */
end_comment

begin_define
define|#
directive|define
name|XZ_CHECK_MAX
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

