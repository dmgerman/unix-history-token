begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* flex integer type definitions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXINT_H
end_ifndef

begin_define
define|#
directive|define
name|FLEXINT_H
end_define

begin_comment
comment|/* C99 systems have<inttypes.h>. Non-C99 systems may or may not. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
operator|)
end_if

begin_comment
comment|/* C99 says to define __STDC_LIMIT_MACROS before including stdint.h,  * if you want the limit (max/min) macros for int types.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC_LIMIT_MACROS
end_ifndef

begin_define
define|#
directive|define
name|__STDC_LIMIT_MACROS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_typedef
typedef|typedef
name|int8_t
name|flex_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|flex_uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|flex_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|flex_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|flex_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|flex_uint32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|signed
name|char
name|flex_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int
name|flex_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|flex_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|flex_uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|flex_uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|flex_uint32_t
typedef|;
end_typedef

begin_comment
comment|/* Limits of integral types. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT8_MIN
end_ifndef

begin_define
define|#
directive|define
name|INT8_MIN
value|(-128)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT16_MIN
end_ifndef

begin_define
define|#
directive|define
name|INT16_MIN
value|(-32767-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT32_MIN
end_ifndef

begin_define
define|#
directive|define
name|INT32_MIN
value|(-2147483647-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT8_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT8_MAX
value|(127)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT16_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT16_MAX
value|(32767)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT32_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT32_MAX
value|(2147483647)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT8_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT8_MAX
value|(255U)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT16_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT16_MAX
value|(65535U)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UINT32_MAX
end_ifndef

begin_define
define|#
directive|define
name|UINT32_MAX
value|(4294967295U)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! C99 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! FLEXINT_H */
end_comment

end_unit

