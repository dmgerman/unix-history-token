begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_define
define|#
directive|define
name|bswap16
parameter_list|(
name|x
parameter_list|)
value|(uint16_t) \ 	((x>> 8) | (x<< 8))
end_define

begin_define
define|#
directive|define
name|bswap32
parameter_list|(
name|x
parameter_list|)
value|(uint32_t) \ 	((x>> 24) | ((x>> 8)& 0xff00) | ((x<< 8)& 0xff0000) | (x<< 24))
end_define

begin_define
define|#
directive|define
name|bswap64
parameter_list|(
name|x
parameter_list|)
value|(uint64_t) \ 	((x>> 56) | ((x>> 40)& 0xff00) | ((x>> 24)& 0xff0000) | \ 	((x>> 8)& 0xff000000) | ((x<< 8)& ((uint64_t)0xff<< 32)) | \ 	((x<< 24)& ((uint64_t)0xff<< 40)) | \ 	((x<< 40)& ((uint64_t)0xff<< 48)) | ((x<< 56)))
end_define

begin_comment
comment|/*  * Host to big endian, host to little endian, big endian to host, and little  * endian to host byte order functions as detailed in byteorder(9).  */
end_comment

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|htobe16
parameter_list|(
name|x
parameter_list|)
value|bswap16((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|htobe32
parameter_list|(
name|x
parameter_list|)
value|bswap32((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htobe64
parameter_list|(
name|x
parameter_list|)
value|bswap64((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|htole16
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|htole32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htole64
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|be16toh
parameter_list|(
name|x
parameter_list|)
value|bswap16((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|be32toh
parameter_list|(
name|x
parameter_list|)
value|bswap32((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|be64toh
parameter_list|(
name|x
parameter_list|)
value|bswap64((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|le16toh
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|le32toh
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|le64toh
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BYTE_ORDER != _LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|htobe16
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|htobe32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htobe64
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|htole16
parameter_list|(
name|x
parameter_list|)
value|bswap16((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|htole32
parameter_list|(
name|x
parameter_list|)
value|bswap32((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htole64
parameter_list|(
name|x
parameter_list|)
value|bswap64((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|be16toh
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|be32toh
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|be64toh
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|le16toh
parameter_list|(
name|x
parameter_list|)
value|bswap16((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|le32toh
parameter_list|(
name|x
parameter_list|)
value|bswap32((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|le64toh
parameter_list|(
name|x
parameter_list|)
value|bswap64((uint64_t)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BYTE_ORDER == _LITTLE_ENDIAN */
end_comment

end_unit

