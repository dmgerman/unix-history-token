begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/include/parse.h,v 4.5 1998/08/09 22:23:32 kardel RELEASE_19990228_A  *  * parse.h,v 4.5 1998/08/09 22:23:32 kardel RELEASE_19990228_A  *  * Copyright (C) 1989-1998 by Frank Kardel  * Friedrich-Alexander Universität Erlangen-Nürnberg, Germany  *                                      * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PARSE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PARSE_H__
end_define

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|lint
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|)
end_if

begin_decl_stmt
specifier|static
name|char
name|parsehrcsid
index|[]
init|=
literal|"parse.h,v 4.5 1998/08/09 22:23:32 kardel RELEASE_19990228_A"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"parse_conf.h"
end_include

begin_comment
comment|/*  * we use the following datastructures in two modes  * either in the NTP itself where we use NTP time stamps at some places  * or in the kernel, where only struct timeval will be used.  */
end_comment

begin_undef
undef|#
directive|undef
name|PARSEKERNEL
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PARSESTREAM
end_ifndef

begin_define
define|#
directive|define
name|PARSESTREAM
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
name|defined
argument_list|(
name|PARSESTREAM
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_STREAM_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|PARSEKERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PARSEKERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_decl_stmt
specifier|extern
name|caddr_t
name|kmem_alloc
name|P
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|caddr_t
name|kmem_free
name|P
argument_list|(
operator|(
name|caddr_t
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|splx
name|P
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|splhigh
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|splclock
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|_X_
parameter_list|)
value|(char *)kmem_alloc(_X_)
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|_X_
parameter_list|,
name|_Y_
parameter_list|)
value|kmem_free((caddr_t)_X_, _Y_)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/kmem.h>
end_include

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|_X_
parameter_list|)
value|(char *)kmem_alloc(_X_, KM_SLEEP)
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|_X_
parameter_list|,
name|_Y_
parameter_list|)
value|kmem_free((caddr_t)_X_, _Y_)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|_X_
parameter_list|)
value|malloc(_X_)
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|_X_
parameter_list|,
name|_Y_
parameter_list|)
value|free(_X_)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PARSESTREAM
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_STREAM_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* STREAM */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DD_PARSE
value|5
end_define

begin_define
define|#
directive|define
name|DD_RAWDCF
value|4
end_define

begin_define
define|#
directive|define
name|parseprintf
parameter_list|(
name|LEVEL
parameter_list|,
name|ARGS
parameter_list|)
value|if (debug> LEVEL) printf ARGS
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|parseprintf
parameter_list|(
name|LEVEL
parameter_list|,
name|ARGS
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PARSESTREAM */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|timercmp
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|timercmp
end_undef

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
name|timercmp
argument_list|)
end_if

begin_define
define|#
directive|define
name|timercmp
parameter_list|(
name|tvp
parameter_list|,
name|uvp
parameter_list|,
name|cmp
parameter_list|)
define|\
value|((tvp)->tv_sec cmp (uvp)->tv_sec || \ 	 ((tvp)->tv_sec == (uvp)->tv_sec&& (tvp)->tv_usec cmp (uvp)->tv_usec))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TIMES10
end_ifndef

begin_define
define|#
directive|define
name|TIMES10
parameter_list|(
name|_X_
parameter_list|)
value|(((_X_)<< 3) + ((_X_)<< 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * state flags  */
end_comment

begin_define
define|#
directive|define
name|PARSEB_POWERUP
value|0x00000001
end_define

begin_comment
comment|/* no synchronisation */
end_comment

begin_define
define|#
directive|define
name|PARSEB_NOSYNC
value|0x00000002
end_define

begin_comment
comment|/* timecode currently not confirmed */
end_comment

begin_comment
comment|/*  * time zone information  */
end_comment

begin_define
define|#
directive|define
name|PARSEB_ANNOUNCE
value|0x00000010
end_define

begin_comment
comment|/* switch time zone warning (DST switch) */
end_comment

begin_define
define|#
directive|define
name|PARSEB_DST
value|0x00000020
end_define

begin_comment
comment|/* DST in effect */
end_comment

begin_define
define|#
directive|define
name|PARSEB_UTC
value|0x00000040
end_define

begin_comment
comment|/* UTC time */
end_comment

begin_comment
comment|/*  * leap information  */
end_comment

begin_define
define|#
directive|define
name|PARSEB_LEAPDEL
value|0x00000100
end_define

begin_comment
comment|/* LEAP deletion warning */
end_comment

begin_define
define|#
directive|define
name|PARSEB_LEAPADD
value|0x00000200
end_define

begin_comment
comment|/* LEAP addition warning */
end_comment

begin_define
define|#
directive|define
name|PARSEB_LEAPS
value|0x00000300
end_define

begin_comment
comment|/* LEAP warnings */
end_comment

begin_define
define|#
directive|define
name|PARSEB_LEAPSECOND
value|0x00000400
end_define

begin_comment
comment|/* actual leap second */
end_comment

begin_comment
comment|/*  * optional status information  */
end_comment

begin_define
define|#
directive|define
name|PARSEB_ALTERNATE
value|0x00001000
end_define

begin_comment
comment|/* alternate antenna used */
end_comment

begin_define
define|#
directive|define
name|PARSEB_POSITION
value|0x00002000
end_define

begin_comment
comment|/* position available */
end_comment

begin_define
define|#
directive|define
name|PARSEB_MESSAGE
value|0x00004000
end_define

begin_comment
comment|/* addtitional message data */
end_comment

begin_comment
comment|/*  * feature information  */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_LEAP
value|0x00010000
end_define

begin_comment
comment|/* supports LEAP */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_ANTENNA
value|0x00020000
end_define

begin_comment
comment|/* supports antenna information */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_PPS
value|0x00040000
end_define

begin_comment
comment|/* supports PPS time stamping */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_POSITION
value|0x00080000
end_define

begin_comment
comment|/* supports position information (GPS) */
end_comment

begin_comment
comment|/*  * time stamp availability  */
end_comment

begin_define
define|#
directive|define
name|PARSEB_TIMECODE
value|0x10000000
end_define

begin_comment
comment|/* valid time code sample */
end_comment

begin_define
define|#
directive|define
name|PARSEB_PPS
value|0x20000000
end_define

begin_comment
comment|/* valid PPS sample */
end_comment

begin_define
define|#
directive|define
name|PARSE_TCINFO
value|(PARSEB_ANNOUNCE|PARSEB_POWERUP|PARSEB_NOSYNC|PARSEB_DST|\ 				 PARSEB_UTC|PARSEB_LEAPS|PARSEB_ALTERNATE|PARSEB_S_LEAP|\ 				 PARSEB_S_LOCATION|PARSEB_TIMECODE|PARSEB_MESSAGE)
end_define

begin_define
define|#
directive|define
name|PARSE_POWERUP
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_POWERUP)
end_define

begin_define
define|#
directive|define
name|PARSE_NOSYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& (PARSEB_POWERUP|PARSEB_NOSYNC)) == PARSEB_NOSYNC)
end_define

begin_define
define|#
directive|define
name|PARSE_SYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& (PARSEB_POWERUP|PARSEB_NOSYNC)) == 0)
end_define

begin_define
define|#
directive|define
name|PARSE_ANNOUNCE
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_ANNOUNCE)
end_define

begin_define
define|#
directive|define
name|PARSE_DST
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_DST)
end_define

begin_define
define|#
directive|define
name|PARSE_UTC
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_UTC)
end_define

begin_define
define|#
directive|define
name|PARSE_LEAPADD
parameter_list|(
name|x
parameter_list|)
value|(PARSE_SYNC(x)&& (((x)& PARSEB_LEAPS) == PARSEB_LEAPADD))
end_define

begin_define
define|#
directive|define
name|PARSE_LEAPDEL
parameter_list|(
name|x
parameter_list|)
value|(PARSE_SYNC(x)&& (((x)& PARSEB_LEAPS) == PARSEB_LEAPDEL))
end_define

begin_define
define|#
directive|define
name|PARSE_ALTERNATE
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_ALTERNATE)
end_define

begin_define
define|#
directive|define
name|PARSE_LEAPSECOND
parameter_list|(
name|x
parameter_list|)
value|(PARSE_SYNC(x)&& ((x)& PARSEB_LEAP_SECOND))
end_define

begin_define
define|#
directive|define
name|PARSE_S_LEAP
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_S_LEAP)
end_define

begin_define
define|#
directive|define
name|PARSE_S_ANTENNA
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_S_ANTENNA)
end_define

begin_define
define|#
directive|define
name|PARSE_S_PPS
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_S_PPS)
end_define

begin_define
define|#
directive|define
name|PARSE_S_POSITION
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_S_POSITION)
end_define

begin_define
define|#
directive|define
name|PARSE_TIMECODE
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_TIMECODE)
end_define

begin_define
define|#
directive|define
name|PARSE_PPS
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_PPS)
end_define

begin_define
define|#
directive|define
name|PARSE_POSITION
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_POSITION)
end_define

begin_define
define|#
directive|define
name|PARSE_MESSAGE
parameter_list|(
name|x
parameter_list|)
value|((x)& PARSEB_MESSAGE)
end_define

begin_comment
comment|/*  * operation flags - lower nibble contains fudge flags  */
end_comment

begin_define
define|#
directive|define
name|PARSE_STATISTICS
value|0x08
end_define

begin_comment
comment|/* enable statistics */
end_comment

begin_define
define|#
directive|define
name|PARSE_LEAP_DELETE
value|0x04
end_define

begin_comment
comment|/* delete leap */
end_comment

begin_define
define|#
directive|define
name|PARSE_FIXED_FMT
value|0x10
end_define

begin_comment
comment|/* fixed format */
end_comment

begin_define
define|#
directive|define
name|PARSE_PPSCLOCK
value|0x20
end_define

begin_comment
comment|/* try to get PPS time stamp via ppsclock ioctl */
end_comment

begin_comment
comment|/*  * size of buffers  */
end_comment

begin_define
define|#
directive|define
name|PARSE_TCMAX
value|400
end_define

begin_comment
comment|/* maximum addition data size */
end_comment

begin_typedef
typedef|typedef
union|union
name|timestamp
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
comment|/* timeval - kernel view */
name|l_fp
name|fp
decl_stmt|;
comment|/* fixed point - ntp view */
block|}
name|timestamp_t
typedef|;
end_typedef

begin_comment
comment|/*  * standard time stamp structure  */
end_comment

begin_struct
struct|struct
name|parsetime
block|{
name|u_long
name|parse_status
decl_stmt|;
comment|/* data status - CVT_OK, CVT_NONE, CVT_FAIL ... */
name|timestamp_t
name|parse_time
decl_stmt|;
comment|/* PARSE timestamp */
name|timestamp_t
name|parse_stime
decl_stmt|;
comment|/* telegram sample timestamp */
name|timestamp_t
name|parse_ptime
decl_stmt|;
comment|/* PPS time stamp */
name|long
name|parse_usecerror
decl_stmt|;
comment|/* sampled usec error */
name|u_long
name|parse_state
decl_stmt|;
comment|/* current receiver state */
name|unsigned
name|short
name|parse_format
decl_stmt|;
comment|/* format code */
name|unsigned
name|short
name|parse_msglen
decl_stmt|;
comment|/* length of message */
name|unsigned
name|char
name|parse_msg
index|[
name|PARSE_TCMAX
index|]
decl_stmt|;
comment|/* original messages */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|parsetime
name|parsetime_t
typedef|;
end_typedef

begin_comment
comment|/*---------- STREAMS interface ----------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STREAM_H
end_ifdef

begin_comment
comment|/*  * ioctls  */
end_comment

begin_define
define|#
directive|define
name|PARSEIOC_ENABLE
value|(('D'<<8) + 'E')
end_define

begin_define
define|#
directive|define
name|PARSEIOC_DISABLE
value|(('D'<<8) + 'D')
end_define

begin_define
define|#
directive|define
name|PARSEIOC_SETFMT
value|(('D'<<8) + 'f')
end_define

begin_define
define|#
directive|define
name|PARSEIOC_GETFMT
value|(('D'<<8) + 'F')
end_define

begin_define
define|#
directive|define
name|PARSEIOC_SETCS
value|(('D'<<8) + 'C')
end_define

begin_define
define|#
directive|define
name|PARSEIOC_TIMECODE
value|(('D'<<8) + 'T')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*------ IO handling flags (sorry) ------*/
end_comment

begin_define
define|#
directive|define
name|PARSE_IO_CSIZE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PARSE_IO_CS5
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PARSE_IO_CS6
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PARSE_IO_CS7
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PARSE_IO_CS8
value|0x00000003
end_define

begin_comment
comment|/*  * ioctl structure  */
end_comment

begin_union
union|union
name|parsectl
block|{
struct|struct
name|parsegettc
block|{
name|u_long
name|parse_state
decl_stmt|;
comment|/* last state */
name|u_long
name|parse_badformat
decl_stmt|;
comment|/* number of bad packets since last query */
name|unsigned
name|short
name|parse_format
decl_stmt|;
comment|/* last decoded format */
name|unsigned
name|short
name|parse_count
decl_stmt|;
comment|/* count of valid time code bytes */
name|char
name|parse_buffer
index|[
name|PARSE_TCMAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* timecode buffer */
block|}
name|parsegettc
struct|;
struct|struct
name|parseformat
block|{
name|unsigned
name|short
name|parse_format
decl_stmt|;
comment|/* number of examined format */
name|unsigned
name|short
name|parse_count
decl_stmt|;
comment|/* count of valid string bytes */
name|char
name|parse_buffer
index|[
name|PARSE_TCMAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* format code string */
block|}
name|parseformat
struct|;
struct|struct
name|parsesetcs
block|{
name|u_long
name|parse_cs
decl_stmt|;
comment|/* character size (needed for stripping) */
block|}
name|parsesetcs
struct|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|parsectl
name|parsectl_t
typedef|;
end_typedef

begin_comment
comment|/*------ for conversion routines --------*/
end_comment

begin_struct
struct|struct
name|parse
comment|/* parse module local data */
block|{
name|int
name|parse_flags
decl_stmt|;
comment|/* operation and current status flags */
name|int
name|parse_ioflags
decl_stmt|;
comment|/* io handling flags (5-8 Bit control currently) */
comment|/*    * private data - fixed format only    */
name|unsigned
name|short
name|parse_plen
decl_stmt|;
comment|/* length of private data */
name|void
modifier|*
name|parse_pdata
decl_stmt|;
comment|/* private data pointer */
comment|/*    * time code input buffer (from RS232 or PPS)    */
name|unsigned
name|short
name|parse_index
decl_stmt|;
comment|/* current buffer index */
name|char
modifier|*
name|parse_data
decl_stmt|;
comment|/* data buffer */
name|unsigned
name|short
name|parse_dsize
decl_stmt|;
comment|/* size of data buffer */
name|unsigned
name|short
name|parse_lformat
decl_stmt|;
comment|/* last format used */
name|u_long
name|parse_lstate
decl_stmt|;
comment|/* last state code */
name|char
modifier|*
name|parse_ldata
decl_stmt|;
comment|/* last data buffer */
name|unsigned
name|short
name|parse_ldsize
decl_stmt|;
comment|/* last data buffer length */
name|u_long
name|parse_badformat
decl_stmt|;
comment|/* number of unparsable pakets */
name|timestamp_t
name|parse_lastchar
decl_stmt|;
comment|/* last time a character was received */
name|parsetime_t
name|parse_dtime
decl_stmt|;
comment|/* external data prototype */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|parse
name|parse_t
typedef|;
end_typedef

begin_struct
struct|struct
name|clocktime
comment|/* clock time broken up from time code */
block|{
name|long
name|day
decl_stmt|;
name|long
name|month
decl_stmt|;
name|long
name|year
decl_stmt|;
name|long
name|hour
decl_stmt|;
name|long
name|minute
decl_stmt|;
name|long
name|second
decl_stmt|;
name|long
name|usecond
decl_stmt|;
name|long
name|utcoffset
decl_stmt|;
comment|/* in seconds */
name|time_t
name|utctime
decl_stmt|;
comment|/* the actual time - alternative to date/time */
name|u_long
name|flags
decl_stmt|;
comment|/* current clock status */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|clocktime
name|clocktime_t
typedef|;
end_typedef

begin_comment
comment|/*  * parser related return/error codes  */
end_comment

begin_define
define|#
directive|define
name|CVT_MASK
value|(unsigned)0x0000000F
end_define

begin_comment
comment|/* conversion exit code */
end_comment

begin_define
define|#
directive|define
name|CVT_NONE
value|(unsigned)0x00000001
end_define

begin_comment
comment|/* format not applicable */
end_comment

begin_define
define|#
directive|define
name|CVT_FAIL
value|(unsigned)0x00000002
end_define

begin_comment
comment|/* conversion failed - error code returned */
end_comment

begin_define
define|#
directive|define
name|CVT_OK
value|(unsigned)0x00000004
end_define

begin_comment
comment|/* conversion succeeded */
end_comment

begin_define
define|#
directive|define
name|CVT_SKIP
value|(unsigned)0x00000008
end_define

begin_comment
comment|/* conversion succeeded */
end_comment

begin_define
define|#
directive|define
name|CVT_ADDITIONAL
value|(unsigned)0x00000010
end_define

begin_comment
comment|/* additional data is available */
end_comment

begin_define
define|#
directive|define
name|CVT_BADFMT
value|(unsigned)0x00000100
end_define

begin_comment
comment|/* general format error - (unparsable) */
end_comment

begin_define
define|#
directive|define
name|CVT_BADDATE
value|(unsigned)0x00000200
end_define

begin_comment
comment|/* date field incorrect */
end_comment

begin_define
define|#
directive|define
name|CVT_BADTIME
value|(unsigned)0x00000400
end_define

begin_comment
comment|/* time field incorrect */
end_comment

begin_comment
comment|/*  * return codes used by special input parsers  */
end_comment

begin_define
define|#
directive|define
name|PARSE_INP_SKIP
value|0x00
end_define

begin_comment
comment|/* discard data - may have been consumed */
end_comment

begin_define
define|#
directive|define
name|PARSE_INP_TIME
value|0x01
end_define

begin_comment
comment|/* time code assembled */
end_comment

begin_define
define|#
directive|define
name|PARSE_INP_PARSE
value|0x02
end_define

begin_comment
comment|/* parse data using normal algorithm */
end_comment

begin_define
define|#
directive|define
name|PARSE_INP_DATA
value|0x04
end_define

begin_comment
comment|/* additional data to pass up */
end_comment

begin_define
define|#
directive|define
name|PARSE_INP_SYNTH
value|0x08
end_define

begin_comment
comment|/* just pass up synthesized time */
end_comment

begin_comment
comment|/*  * PPS edge info  */
end_comment

begin_define
define|#
directive|define
name|SYNC_ZERO
value|0x00
end_define

begin_define
define|#
directive|define
name|SYNC_ONE
value|0x01
end_define

begin_struct
struct|struct
name|clockformat
block|{
comment|/* special input protocol - implies fixed format */
name|u_long
argument_list|(
argument|*input
argument_list|)
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|unsigned
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* conversion routine */
name|u_long
argument_list|(
argument|*convert
argument_list|)
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|format
operator|*
operator|,
name|clocktime_t
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* routine for handling RS232 sync events (time stamps) */
comment|/* PPS input routine */
name|u_long
argument_list|(
argument|*syncpps
argument_list|)
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* time code synthesizer */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* local parameters */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* clock format name */
name|unsigned
name|short
name|length
decl_stmt|;
comment|/* maximum length of data packet */
name|unsigned
name|short
name|plen
decl_stmt|;
comment|/* length of private data - implies fixed format */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|clockformat
name|clockformat_t
typedef|;
end_typedef

begin_comment
comment|/*  * parse interface  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|parse_ioinit
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|parse_ioend
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_ioread
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|unsigned
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_iopps
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|parse_iodone
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_timecode
name|P
argument_list|(
operator|(
name|parsectl_t
operator|*
operator|,
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_getfmt
name|P
argument_list|(
operator|(
name|parsectl_t
operator|*
operator|,
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_setfmt
name|P
argument_list|(
operator|(
name|parsectl_t
operator|*
operator|,
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_setcs
name|P
argument_list|(
operator|(
name|parsectl_t
operator|*
operator|,
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|parse_restart
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|parse_addchar
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|parse_end
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Strok
name|P
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|,
specifier|const
name|unsigned
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Stoi
name|P
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|,
name|long
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|parse_to_unixtime
name|P
argument_list|(
operator|(
name|clocktime_t
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|updatetimeinfo
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|syn_simple
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|timestamp_t
operator|*
operator|,
expr|struct
name|format
operator|*
operator|,
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|pps_simple
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|pps_one
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|pps_zero
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|int
operator|,
name|timestamp_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_timedout
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|timestamp_t
operator|*
operator|,
expr|struct
name|timeval
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * History:  *  * parse.h,v  * Revision 4.5  1998/08/09 22:23:32  kardel  * 4.0.73e2 adjustments  *  * Revision 4.4  1998/06/14 21:09:27  kardel  * Sun acc cleanup  *  * Revision 4.3  1998/06/13 11:49:25  kardel  * STREAM macro gone in favor of HAVE_SYS_STREAM_H  *  * Revision 4.2  1998/06/12 15:14:25  kardel  * fixed prototypes  *  * Revision 4.1  1998/05/24 10:07:59  kardel  * removed old data structure cruft (new input model)  * new PARSE_INP* macros for input handling  * removed old SYNC_* macros from old input model  * (struct clockformat): removed old parse functions in favor of the  * new input model  * updated prototypes  *  * form V3 3.31 - log info deleted 1998/04/11 kardel  */
end_comment

end_unit

