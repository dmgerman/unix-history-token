begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/kernel/sys/parsestreams.h,v 4.4 1998/06/14 21:09:32 kardel RELEASE_19990228_A  *  * parsestreams.h,v 4.4 1998/06/14 21:09:32 kardel RELEASE_19990228_A  *  * Copyright (c) 1989-1998 by Frank Kardel  * Friedrich-Alexander Universität Erlangen-Nürnberg, Germany  *                                     * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  */
end_comment

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
name|sysparsehrcsid
index|[]
init|=
literal|"parsestreams.h,v 4.4 1998/06/14 21:09:32 kardel RELEASE_19990228_A"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TERMIOS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ppsclock.h>
end_include

begin_define
define|#
directive|define
name|NTP_NEED_BOPS
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PARSESTREAM
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_STREAM_H
argument_list|)
end_if

begin_comment
comment|/*  * Sorry, but in SunOS 4.x AND Solaris 2.x kernels there are no  * mem* operations. I don't want them - bcopy, bzero  * are fine in the kernel  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRING_H
end_undef

begin_comment
comment|/* don't include that at kernel level - prototype mismatch in Solaris 2.6 */
end_comment

begin_include
include|#
directive|include
file|"ntp_string.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|parsestream
comment|/* parse module local data */
block|{
name|queue_t
modifier|*
name|parse_queue
decl_stmt|;
comment|/* read stream for this channel */
name|queue_t
modifier|*
name|parse_dqueue
decl_stmt|;
comment|/* driver queue entry (PPS support) */
name|unsigned
name|long
name|parse_status
decl_stmt|;
comment|/* operation flags */
name|void
modifier|*
name|parse_data
decl_stmt|;
comment|/* local data space (PPS support) */
name|parse_t
name|parse_io
decl_stmt|;
comment|/* io structure */
name|struct
name|ppsclockev
name|parse_ppsclockev
decl_stmt|;
comment|/* copy of last pps event */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|parsestream
name|parsestream_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PARSE_ENABLE
value|0x0001
end_define

begin_comment
comment|/*--------------- debugging support ---------------------------------*/
end_comment

begin_define
define|#
directive|define
name|DD_OPEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DD_CLOSE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DD_RPUT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DD_WPUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DD_RSVC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DD_PARSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DD_INSTALL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DD_ISR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DD_RAWDCF
value|0x00000100
end_define

begin_decl_stmt
specifier|extern
name|int
name|parsedebug
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_PARSE
end_ifdef

begin_define
define|#
directive|define
name|parseprintf
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|if ((X)& parsedebug) printf Y
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|parseprintf
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
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
comment|/*  * parsestreams.h,v  * Revision 4.4  1998/06/14 21:09:32  kardel  * Sun acc cleanup  *  * Revision 4.3  1998/06/13 18:14:32  kardel  * make mem*() to b*() mapping magic work on Solaris too  *  * Revision 4.2  1998/06/13 15:16:22  kardel  * fix mem*() to b*() function macro emulation  *  * Revision 4.1  1998/06/13 11:50:37  kardel  * STREAM macro gone in favor of HAVE_SYS_STREAM_H  *  * Revision 4.0  1998/04/10 19:51:30  kardel  * Start 4.0 release version numbering  *  * Revision 1.2  1998/04/10 19:27:42  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  */
end_comment

end_unit

