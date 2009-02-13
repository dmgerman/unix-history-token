begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp4-dev/kernel/sys/parsestreams.h,v 4.5 2005/06/25 10:52:47 kardel RELEASE_20050625_A  *  * parsestreams.h,v 4.5 2005/06/25 10:52:47 kardel RELEASE_20050625_A  *  * Copyright (c) 1995-2005 by Frank Kardel<kardel<AT> ntp.org>  * Copyright (c) 1989-1994 by Frank Kardel, Friedrich-Alexander Universität Erlangen-Nürnberg, Germany  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"parsestreams.h,v 4.5 2005/06/25 10:52:47 kardel RELEASE_20050625_A"
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

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_NEED_BOPS
end_ifndef

begin_define
define|#
directive|define
name|NTP_NEED_BOPS
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
comment|/*  * History:  *  * parsestreams.h,v  * Revision 4.5  2005/06/25 10:52:47  kardel  * fix version id / add version log  *  * Revision 4.4  1998/06/14 21:09:32  kardel  * Sun acc cleanup  *  * Revision 4.3  1998/06/13 18:14:32  kardel  * make mem*() to b*() mapping magic work on Solaris too  *  * Revision 4.2  1998/06/13 15:16:22  kardel  * fix mem*() to b*() function macro emulation  *  * Revision 4.1  1998/06/13 11:50:37  kardel  * STREAM macro gone in favor of HAVE_SYS_STREAM_H  *  * Revision 4.0  1998/04/10 19:51:30  kardel  * Start 4.0 release version numbering  *  * Revision 1.2  1998/04/10 19:27:42  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  */
end_comment

end_unit

