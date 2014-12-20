begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  ntp_types.h - defines how int32 and u_int32 are treated.  *  * New style: Make sure C99 fixed width integer types are available:  * intN_t and uintN_t   * Old style: defines how int32 and u_int32 are treated.  *  For 64 bit systems like the DEC Alpha, they have to be defined  *  as int and u_int.  *  For 32 bit systems, define them as long and u_long  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_INTTYPES_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_STDINT_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED_LOCAL
end_ifndef

begin_define
define|#
directive|define
name|UNUSED_LOCAL
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UINT32_T
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT32
end_ifndef

begin_typedef
typedef|typedef
name|int32_t
name|int32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT32
end_ifndef

begin_typedef
typedef|typedef
name|uint32_t
name|u_int32
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UINT32_MAX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|U_INT32_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|U_INT32_MAX
value|UINT32_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
operator|(
name|SIZEOF_INT
operator|==
literal|4
operator|)
end_elif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_INT32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|int32
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
name|int32
typedef|;
end_typedef

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_U_INT32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|u_int32
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|u_int32
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UINT_MAX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|U_INT32_MAX
argument_list|)
end_if

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
comment|/* SIZEOF_INT != 4 */
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_INT32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|int32
argument_list|)
end_if

begin_typedef
typedef|typedef
name|long
name|int32
typedef|;
end_typedef

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_U_INT32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|u_int32
argument_list|)
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_int32
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ULONG_MAX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|U_INT32_MAX
argument_list|)
end_if

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
comment|/* SIZEOF_LONG != 4 */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_UINT32_T&& SIZEOF_INT != 4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|U_INT32_MAX
end_ifndef

begin_define
define|#
directive|define
name|U_INT32_MAX
value|0xffffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ugly dance to find out if we have 64bit integer type.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_INT64
argument_list|)
end_if

begin_comment
comment|/* assume best for now, fix if frustrated later. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT64
end_define

begin_define
define|#
directive|define
name|HAVE_U_INT64
end_define

begin_comment
comment|/* now check the cascade. Feel free to add things. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INT64_MAX
end_ifdef

begin_typedef
typedef|typedef
name|int64_t
name|int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|u_int64
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_LONG
operator|==
literal|8
end_elif

begin_typedef
typedef|typedef
name|long
name|int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_int64
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_LONG_LONG
operator|==
literal|8
end_elif

begin_typedef
typedef|typedef
name|long
name|long
name|int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|u_int64
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no 64bit scalar, give it up. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_INT64
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_U_INT64
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * and here the trouble starts: We need a representation with more than  * 64 bits. If a scalar of that size is not available, we need a struct  * that holds the value in split representation.  *  * To ease the usage a bit, we alwys use a union that is in processor  * byte order and might or might not contain a 64bit scalar.  */
end_comment

begin_if
if|#
directive|if
name|SIZEOF_SHORT
operator|!=
literal|2
end_if

begin_error
error|#
directive|error
error|short is not 2 bytes -- what is 16 bit integer on this target?
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
union|union
block|{
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
struct|struct
block|{
name|int16_t
name|hh
decl_stmt|;
name|uint16_t
name|hl
decl_stmt|;
name|uint16_t
name|lh
decl_stmt|;
name|uint16_t
name|ll
decl_stmt|;
block|}
name|w_s
struct|;
struct|struct
block|{
name|uint16_t
name|hh
decl_stmt|;
name|uint16_t
name|hl
decl_stmt|;
name|uint16_t
name|lh
decl_stmt|;
name|uint16_t
name|ll
decl_stmt|;
block|}
name|W_s
struct|;
struct|struct
block|{
name|int32
name|hi
decl_stmt|;
name|u_int32
name|lo
decl_stmt|;
block|}
name|d_s
struct|;
struct|struct
block|{
name|u_int32
name|hi
decl_stmt|;
name|u_int32
name|lo
decl_stmt|;
block|}
name|D_s
struct|;
else|#
directive|else
struct|struct
block|{
name|uint16_t
name|ll
decl_stmt|;
name|uint16_t
name|lh
decl_stmt|;
name|uint16_t
name|hl
decl_stmt|;
name|int16_t
name|hh
decl_stmt|;
block|}
name|w_s
struct|;
struct|struct
block|{
name|uint16_t
name|ll
decl_stmt|;
name|uint16_t
name|lh
decl_stmt|;
name|uint16_t
name|hl
decl_stmt|;
name|uint16_t
name|hh
decl_stmt|;
block|}
name|W_s
struct|;
struct|struct
block|{
name|u_int32
name|lo
decl_stmt|;
name|int32
name|hi
decl_stmt|;
block|}
name|d_s
struct|;
struct|struct
block|{
name|u_int32
name|lo
decl_stmt|;
name|u_int32
name|hi
decl_stmt|;
block|}
name|D_s
struct|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_INT64
name|int64
name|q_s
decl_stmt|;
comment|/*   signed quad scalar */
name|u_int64
name|Q_s
decl_stmt|;
comment|/* unsigned quad scalar */
endif|#
directive|endif
block|}
name|vint64
typedef|;
end_typedef

begin_comment
comment|/* variant int 64 */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|ntp_u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|ntp_u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
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
name|uint16_t
name|associd_t
typedef|;
end_typedef

begin_comment
comment|/* association ID */
end_comment

begin_define
define|#
directive|define
name|ASSOCID_MAX
value|USHRT_MAX
end_define

begin_typedef
typedef|typedef
name|u_int32
name|keyid_t
typedef|;
end_typedef

begin_comment
comment|/* cryptographic key ID */
end_comment

begin_define
define|#
directive|define
name|KEYID_T_MAX
value|(0xffffffff)
end_define

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
comment|/*  * Cloning malloc()'s behavior of always returning pointers suitably  * aligned for the strictest alignment requirement of any type is not  * easy to do portably, as the maximum alignment required is not  * exposed.  Use the size of a union of the types known to represent the  * strictest alignment on some platform.  */
end_comment

begin_typedef
typedef|typedef
union|union
name|max_alignment_tag
block|{
name|double
name|d
decl_stmt|;
block|}
name|max_alignment
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXALIGN
value|sizeof(max_alignment)
end_define

begin_define
define|#
directive|define
name|ALIGN_UNITS
parameter_list|(
name|sz
parameter_list|)
value|(((sz) + MAXALIGN - 1) / MAXALIGN)
end_define

begin_define
define|#
directive|define
name|ALIGNED_SIZE
parameter_list|(
name|sz
parameter_list|)
value|(MAXALIGN * ALIGN_UNITS(sz))
end_define

begin_define
define|#
directive|define
name|INC_ALIGNED_PTR
parameter_list|(
name|b
parameter_list|,
name|m
parameter_list|)
value|((void *)aligned_ptr((void *)(b), m))
end_define

begin_function
specifier|static
specifier|inline
name|max_alignment
modifier|*
name|aligned_ptr
parameter_list|(
name|max_alignment
modifier|*
name|base
parameter_list|,
name|size_t
name|minsize
parameter_list|)
block|{
return|return
name|base
operator|+
name|ALIGN_UNITS
argument_list|(
operator|(
name|minsize
operator|<
literal|1
operator|)
condition|?
literal|1
else|:
name|minsize
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Macro to use in otherwise-empty source files to comply with ANSI C  * requirement that each translation unit (source file) contain some  * declaration.  This has commonly been done by declaring an unused  * global variable of type int or char.  An extern reference to exit()  * serves the same purpose without bloat.  */
end_comment

begin_define
define|#
directive|define
name|NONEMPTY_TRANSLATION_UNIT
value|extern void exit(int);
end_define

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
comment|/*  * On Unix open() works for tty (serial) devices just fine, while on  * Windows refclock serial devices are opened using CreateFile, a lower  * level than the CRT-provided descriptors, because the C runtime lacks  * tty APIs.  For refclocks which wish to use open() as well as or   * instead of refclock_open(), tty_open() is equivalent to open() on  * Unix and  implemented in the Windows port similarly to  * refclock_open().  * Similarly, the termios emulation in the Windows code needs to know  * about serial ports being closed, while the Posix systems do not.  */
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

begin_define
define|#
directive|define
name|closeserial
parameter_list|(
name|fd
parameter_list|)
value|close(fd)
end_define

begin_define
define|#
directive|define
name|closesocket
parameter_list|(
name|fd
parameter_list|)
value|close(fd)
end_define

begin_typedef
typedef|typedef
name|int
name|SOCKET
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INVALID_SOCKET
value|(-1)
end_define

begin_define
define|#
directive|define
name|SOCKET_ERROR
value|(-1)
end_define

begin_define
define|#
directive|define
name|socket_errno
parameter_list|()
value|(errno)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYS_WINNT follows */
end_comment

begin_define
define|#
directive|define
name|socket_errno
parameter_list|()
value|(errno = WSAGetLastError())
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

