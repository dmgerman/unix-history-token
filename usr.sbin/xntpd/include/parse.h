begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/REPOSITORY/v3/include/parse.h,v 3.13 1994/01/25 19:04:21 kardel Exp  *  * parse.h,v 3.13 1994/01/25 19:04:21 kardel Exp  *  * Copyright (c) 1989,1990,1991,1992,1993,1994  * Frank Kardel Friedrich-Alexander Universitaet Erlangen-Nuernberg  *                                      * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
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
literal|"parse.h,v 3.13 1994/01/25 19:04:21 kardel Exp FAU"
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
name|STREAM
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

begin_function_decl
specifier|extern
name|int
name|splx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|splhigh
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|/* extern char *malloc();		XXX defined elsewhere */
end_comment

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
name|STREAM
argument_list|)
end_if

begin_include
include|#
directive|include
file|"sys/stream.h"
end_include

begin_include
include|#
directive|include
file|"sys/stropts.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
specifier|extern
name|int
name|printf
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

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
name|PARSEB_ANNOUNCE
value|0x0001
end_define

begin_comment
comment|/* switch time zone warning (DST switch) */
end_comment

begin_define
define|#
directive|define
name|PARSEB_POWERUP
value|0x0002
end_define

begin_comment
comment|/* no synchronisation */
end_comment

begin_define
define|#
directive|define
name|PARSEB_NOSYNC
value|0x0004
end_define

begin_comment
comment|/* timecode currently not confirmed */
end_comment

begin_define
define|#
directive|define
name|PARSEB_DST
value|0x0008
end_define

begin_comment
comment|/* DST in effect */
end_comment

begin_define
define|#
directive|define
name|PARSEB_UTC
value|0x0010
end_define

begin_comment
comment|/* UTC time */
end_comment

begin_define
define|#
directive|define
name|PARSEB_LEAP
value|0x0020
end_define

begin_comment
comment|/* LEAP warning (1 hour prior to occurence) */
end_comment

begin_define
define|#
directive|define
name|PARSEB_ALTERNATE
value|0x0040
end_define

begin_comment
comment|/* alternate antenna used */
end_comment

begin_define
define|#
directive|define
name|PARSEB_POSITION
value|0x0080
end_define

begin_comment
comment|/* position available */
end_comment

begin_define
define|#
directive|define
name|PARSEB_LEAPSECOND
value|0x0100
end_define

begin_comment
comment|/* actual leap second */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_LEAP
value|0x0200
end_define

begin_comment
comment|/* supports LEAP */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_ANTENNA
value|0x0400
end_define

begin_comment
comment|/* supports antenna information */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_PPS
value|0x0800
end_define

begin_comment
comment|/* supports PPS time stamping */
end_comment

begin_define
define|#
directive|define
name|PARSEB_S_POSITION
value|0x1000
end_define

begin_comment
comment|/* supports position information (GPS) */
end_comment

begin_define
define|#
directive|define
name|PARSEB_TIMECODE
value|0x2000
end_define

begin_comment
comment|/* valid time code sample */
end_comment

begin_define
define|#
directive|define
name|PARSEB_PPS
value|0x4000
end_define

begin_comment
comment|/* valid PPS sample */
end_comment

begin_define
define|#
directive|define
name|PARSE_TCINFO
value|(PARSEB_ANNOUNCE|PARSEB_POWERUP|PARSEB_NOSYNC|PARSEB_DST|\ 				 PARSEB_UTC|PARSEB_LEAP|PARSEB_ALTERNATE|PARSEB_S_LEAP|\ 				 PARSEB_S_LOCATION|PARSEB_TIMECODE)
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
name|PARSE_LEAP
parameter_list|(
name|x
parameter_list|)
value|(PARSE_SYNC(x)&& ((x)& PARSEB_LEAP))
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

begin_comment
comment|/*  * operation flags - some are also fudge flags  */
end_comment

begin_define
define|#
directive|define
name|PARSE_STAT_FLAGS
value|0x03
end_define

begin_comment
comment|/* interpreted by io module */
end_comment

begin_define
define|#
directive|define
name|PARSE_STAT_FILTER
value|0x01
end_define

begin_comment
comment|/* filter incoming data */
end_comment

begin_define
define|#
directive|define
name|PARSE_STAT_AVG
value|0x02
end_define

begin_comment
comment|/* 1:median average / 0: median point */
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

begin_typedef
typedef|typedef
union|union
name|timestamp
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
comment|/* timeval - usually kernel view */
name|l_fp
name|fp
decl_stmt|;
comment|/* fixed point - xntp view */
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
name|unsigned
name|LONG
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
name|LONG
name|parse_usecerror
decl_stmt|;
comment|/* sampled/filtered usec error */
name|LONG
name|parse_usecdisp
decl_stmt|;
comment|/* sampled usecdispersion */
name|unsigned
name|LONG
name|parse_state
decl_stmt|;
comment|/* current receiver state */
name|unsigned
name|short
name|parse_format
decl_stmt|;
comment|/* format code */
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
name|STREAM
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
name|PARSEIOC_SETSTAT
value|(('D'<<8) + 'S')
end_define

begin_define
define|#
directive|define
name|PARSEIOC_GETSTAT
value|(('D'<<8) + 'G')
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
comment|/*  * sizes  */
end_comment

begin_define
define|#
directive|define
name|PARSE_TCMAX
value|128
end_define

begin_comment
comment|/*  * ioctl structure  */
end_comment

begin_union
union|union
name|parsectl
block|{
struct|struct
name|parsestatus
block|{
name|unsigned
name|LONG
name|flags
decl_stmt|;
comment|/* new/old flags */
block|}
name|parsestatus
struct|;
struct|struct
name|parsegettc
block|{
name|unsigned
name|LONG
name|parse_state
decl_stmt|;
comment|/* last state */
name|unsigned
name|LONG
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
name|unsigned
name|LONG
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

begin_define
define|#
directive|define
name|PARSE_DELTA
value|16
end_define

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
name|int
name|parse_syncflags
decl_stmt|;
comment|/* possible sync events (START/END/character) */
comment|/*    * RS232 input parser information    */
name|unsigned
name|char
name|parse_startsym
index|[
literal|32
index|]
decl_stmt|;
comment|/* possible start packet values */
name|unsigned
name|char
name|parse_endsym
index|[
literal|32
index|]
decl_stmt|;
comment|/* possible end packet values */
name|unsigned
name|char
name|parse_syncsym
index|[
literal|32
index|]
decl_stmt|;
comment|/* sync characters */
name|struct
name|timeval
name|parse_timeout
decl_stmt|;
comment|/* max gap between characters (us) */
comment|/*    * PPS 'input' buffer    */
name|struct
name|timeval
name|parse_lastone
decl_stmt|;
comment|/* time stamp of last PPS 1 transition */
name|struct
name|timeval
name|parse_lastzero
decl_stmt|;
comment|/* time stamp of last PPS 0 transition */
comment|/*    * character input buffer    */
name|timestamp_t
name|parse_lastchar
decl_stmt|;
comment|/* time stamp of last received character */
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
name|unsigned
name|LONG
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
name|unsigned
name|LONG
name|parse_badformat
decl_stmt|;
comment|/* number of unparsable pakets */
comment|/*    * time stamp filtering    */
name|LONG
name|parse_delta
index|[
name|PARSE_DELTA
index|]
decl_stmt|;
comment|/* delta buffer */
name|int
name|parse_dindex
decl_stmt|;
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
name|LONG
name|day
decl_stmt|;
name|LONG
name|month
decl_stmt|;
name|LONG
name|year
decl_stmt|;
name|LONG
name|hour
decl_stmt|;
name|LONG
name|minute
decl_stmt|;
name|LONG
name|second
decl_stmt|;
name|LONG
name|usecond
decl_stmt|;
name|LONG
name|utcoffset
decl_stmt|;
comment|/* in seconds */
name|LONG
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
comment|/*  * clock formats specify routines to be called to  * convert the buffer into a struct clock.  * functions are called  *   fn(buffer, data, clock) -> CVT_NONE, CVT_FAIL, CVT_OK  *  * the private data pointer can be used to  * distingush between different formats of a common  * base type  */
end_comment

begin_define
define|#
directive|define
name|F_START
value|0x00000001
end_define

begin_comment
comment|/* start packet delimiter */
end_comment

begin_define
define|#
directive|define
name|F_END
value|0x00000002
end_define

begin_comment
comment|/* end packet delimiter */
end_comment

begin_define
define|#
directive|define
name|SYNC_TIMEOUT
value|0x00000004
end_define

begin_comment
comment|/* packet restart after timeout */
end_comment

begin_define
define|#
directive|define
name|SYNC_START
value|0x00000008
end_define

begin_comment
comment|/* packet start is sync event */
end_comment

begin_define
define|#
directive|define
name|SYNC_END
value|0x00000010
end_define

begin_comment
comment|/* packet end is sync event */
end_comment

begin_define
define|#
directive|define
name|SYNC_CHAR
value|0x00000020
end_define

begin_comment
comment|/* special character is sync event */
end_comment

begin_define
define|#
directive|define
name|SYNC_ONE
value|0x00000040
end_define

begin_comment
comment|/* PPS synchronize on 'ONE' transition */
end_comment

begin_define
define|#
directive|define
name|SYNC_ZERO
value|0x00000080
end_define

begin_comment
comment|/* PPS synchronize on 'ZERO' transition */
end_comment

begin_define
define|#
directive|define
name|SYNC_SYNTHESIZE
value|0x00000100
end_define

begin_comment
comment|/* generate intermediate time stamps */
end_comment

begin_define
define|#
directive|define
name|CVT_FIXEDONLY
value|0x00010000
end_define

begin_comment
comment|/* convert only in fixed configuration */
end_comment

begin_comment
comment|/*  * parser related return/error codes  */
end_comment

begin_define
define|#
directive|define
name|CVT_MASK
value|0x0000000F
end_define

begin_comment
comment|/* conversion exit code */
end_comment

begin_define
define|#
directive|define
name|CVT_NONE
value|0x00000001
end_define

begin_comment
comment|/* format not applicable */
end_comment

begin_define
define|#
directive|define
name|CVT_FAIL
value|0x00000002
end_define

begin_comment
comment|/* conversion failed - error code returned */
end_comment

begin_define
define|#
directive|define
name|CVT_OK
value|0x00000004
end_define

begin_comment
comment|/* conversion succeeded */
end_comment

begin_define
define|#
directive|define
name|CVT_BADFMT
value|0x00000010
end_define

begin_comment
comment|/* general format error - (unparsable) */
end_comment

begin_define
define|#
directive|define
name|CVT_BADDATE
value|0x00000020
end_define

begin_comment
comment|/* date field incorrect */
end_comment

begin_define
define|#
directive|define
name|CVT_BADTIME
value|0x00000040
end_define

begin_comment
comment|/* time field incorrect */
end_comment

begin_struct
struct|struct
name|clockformat
block|{
name|unsigned
name|LONG
function_decl|(
modifier|*
name|convert
function_decl|)
parameter_list|()
function_decl|;
comment|/* conversion routine */
name|void
function_decl|(
modifier|*
name|syncevt
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine for handling RS232 sync events (time stamps) */
name|unsigned
name|LONG
function_decl|(
modifier|*
name|syncpps
function_decl|)
parameter_list|()
function_decl|;
comment|/* PPS input routine */
name|unsigned
name|LONG
function_decl|(
modifier|*
name|synth
function_decl|)
parameter_list|()
function_decl|;
comment|/* time code synthesizer */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* local parameters */
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
name|LONG
name|flags
decl_stmt|;
comment|/* valid start symbols etc. */
name|struct
name|timeval
name|timeout
decl_stmt|;
comment|/* buffer restart after timeout (us) */
name|unsigned
name|char
name|startsym
decl_stmt|;
comment|/* start symbol */
name|unsigned
name|char
name|endsym
decl_stmt|;
comment|/* end symbol */
name|unsigned
name|char
name|syncsym
decl_stmt|;
comment|/* sync symbol */
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

begin_function_decl
specifier|extern
name|int
name|parse_ioinit
parameter_list|(
comment|/* parse_t *parseio */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|parse_ioend
parameter_list|(
comment|/* parse_t *parseio */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_ioread
parameter_list|(
comment|/* parse_t *parseio, char ch, timestamp_t *ctime */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_iopps
parameter_list|(
comment|/* parse_t *parseio, int status, struct timeval *ptime, parsetime_t *dtime */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|parse_iodone
parameter_list|(
comment|/* parse_t *parseio */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_getstat
parameter_list|(
comment|/* parsectl_t *dct, parse_t *parse */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_setstat
parameter_list|(
comment|/* parsectl_t *dct, parse_t *parse */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_timecode
parameter_list|(
comment|/* parsectl_t *dct, parse_t *parse */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_getfmt
parameter_list|(
comment|/* parsectl_t *dct, parse_t *parse */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_setfmt
parameter_list|(
comment|/* parsectl_t *dct, parse_t *parse */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_setcs
parameter_list|(
comment|/* parsectl_t *dct, parse_t *parse */
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|Strok
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
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
name|char
operator|*
operator|,
name|LONG
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
name|unsigned
name|LONG
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|LONG
name|updatetimeinfo
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|time_t
operator|,
name|unsigned
name|LONG
operator|,
name|unsigned
name|LONG
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
name|unsigned
name|LONG
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|LONG
name|pps_simple
name|P
argument_list|(
operator|(
name|parse_t
operator|*
operator|,
name|int
name|status
operator|,
name|timestamp_t
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
comment|/*  * History:  *  * parse.h,v  * Revision 3.13  1994/01/25  19:04:21  kardel  * 94/01/23 reconcilation  *  * Revision 3.12  1994/01/23  17:23:05  kardel  * 1994 reconcilation  *  * Revision 3.11  1993/11/11  11:20:18  kardel  * declaration fixes  *  * Revision 3.10  1993/11/01  19:59:48  kardel  * parse Solaris support (initial version)  *  * Revision 3.9  1993/10/06  00:14:57  kardel  * include fixes  *  * Revision 3.8  1993/10/05  23:15:41  kardel  * more STREAM protection  *  * Revision 3.7  1993/10/05  22:56:10  kardel  * STREAM must be defined for PARSESTREAMS  *  * Revision 3.6  1993/10/03  19:10:28  kardel  * restructured I/O handling  *  * Revision 3.5  1993/09/26  23:41:13  kardel  * new parse driver logic  *  * Revision 3.4  1993/09/01  21:46:31  kardel  * conditional cleanup  *  * Revision 3.3  1993/08/27  00:29:29  kardel  * compilation cleanup  *  * Revision 3.2  1993/07/09  11:37:05  kardel  * Initial restructured version + GPS support  *  * Revision 3.1  1993/07/06  09:59:12  kardel  * DCF77 driver goes generic...  *  */
end_comment

end_unit

