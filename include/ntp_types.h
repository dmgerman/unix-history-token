begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  ntp_types.h - defines how int32 and u_int32 are treated.  *  For 64 bit systems like the DEC Alpha, they have to be defined  *  as int and u_int.  *  For 32 bit systems, define them as long and u_long  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_TYPES_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is another naming conflict.  * On NetBSD for MAC the macro "mac" is defined as 1  * this is fun for us as a packet structure contains an  * optional "mac" member - severe confusion results 8-)  * As we hopefully do not have to rely on that macro we  * just undefine that.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mac
end_ifdef

begin_undef
undef|#
directive|undef
name|mac
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * used to quiet compiler warnings  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_ARG
end_ifndef

begin_define
define|#
directive|define
name|UNUSED_ARG
parameter_list|(
name|arg
parameter_list|)
value|((void)(arg))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * COUNTOF(array) - size of array in elements  */
end_comment

begin_define
define|#
directive|define
name|COUNTOF
parameter_list|(
name|arr
parameter_list|)
value|(sizeof(arr) / sizeof((arr)[0]))
end_define

begin_comment
comment|/*  * VMS DECC (v4.1), {u_char,u_short,u_long} are only in SOCKET.H,  *			and u_int isn't defined anywhere  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<socket.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_comment
comment|/*  * Note: VMS DECC has  long == int  (even on __alpha),  *	 so the distinction below doesn't matter  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_if
if|#
directive|if
operator|(
name|SIZEOF_INT
operator|==
literal|4
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|int32
end_ifndef

begin_define
define|#
directive|define
name|int32
value|int
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INT32_MIN
end_ifndef

begin_define
define|#
directive|define
name|INT32_MIN
value|INT_MIN
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
value|INT_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|u_int32
end_ifndef

begin_define
define|#
directive|define
name|u_int32
value|unsigned int
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|U_INT32_MAX
end_ifndef

begin_define
define|#
directive|define
name|U_INT32_MAX
value|UINT_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not sizeof(int) == 4 */
end_comment

begin_if
if|#
directive|if
operator|(
name|SIZEOF_LONG
operator|==
literal|4
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|int32
end_ifndef

begin_define
define|#
directive|define
name|int32
value|long
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INT32_MIN
end_ifndef

begin_define
define|#
directive|define
name|INT32_MIN
value|LONG_MIN
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
value|LONG_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|u_int32
end_ifndef

begin_define
define|#
directive|define
name|u_int32
value|unsigned long
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|U_INT32_MAX
end_ifndef

begin_define
define|#
directive|define
name|U_INT32_MAX
value|ULONG_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not sizeof(long) == 4 */
end_comment

begin_include
include|#
directive|include
file|"Bletch: what's 32 bits on this machine?"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not sizeof(long) == 4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not sizeof(int) == 4 */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|ntp_u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|ntp_u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32
name|ntp_u_int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ntp_uint64_t
block|{
name|u_int32
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|ntp_uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|associd_t
typedef|;
end_typedef

begin_comment
comment|/* association ID */
end_comment

begin_typedef
typedef|typedef
name|u_int32
name|keyid_t
typedef|;
end_typedef

begin_comment
comment|/* cryptographic key ID */
end_comment

begin_typedef
typedef|typedef
name|u_int32
name|tstamp_t
typedef|;
end_typedef

begin_comment
comment|/* NTP seconds timestamp */
end_comment

begin_comment
comment|/*  * On Unix struct sock_timeval is equivalent to struct timeval.  * On Windows built with 64-bit time_t, sock_timeval.tv_sec is a long  * as required by Windows' socket() interface timeout argument, while  * timeval.tv_sec is time_t for the more common use as a UTC time   * within NTP.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_define
define|#
directive|define
name|sock_timeval
value|timeval
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On Unix open() works for tty (serial) devices just fine, while on  * Windows refclock serial devices are opened using CreateFile, a lower  * level than the CRT-provided descriptors, because the C runtime lacks  * tty APIs.  For refclocks which wish to use open() as well as or   * instead of refclock_open(), tty_open() is equivalent to open() on  * Unix and  implemented in the Windows port similarly to  * refclock_open().  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_define
define|#
directive|define
name|tty_open
parameter_list|(
name|f
parameter_list|,
name|a
parameter_list|,
name|m
parameter_list|)
value|open(f, a, m)
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
comment|/* NTP_TYPES_H */
end_comment

end_unit

