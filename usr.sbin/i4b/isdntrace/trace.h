begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Copyright (c) 1996, 2000 Hellmuth Michaelis. All rights reserved.  *  *   Copyright (c) 1996 Gary Jennejohn.  All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the distribution.  *   3. Neither the name of the author nor the names of any co-contributors  *      may be used to endorse or promote products derived from this software  *      without specific prior written permission.  *   4. Altered versions must be plainly marked as such, and must not be  *      misrepresented as being the original software and/or documentation.  *     *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  *   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  *   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  *   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  *   SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	trace.h - header file for isdn trace  *	------------------------------------  *  *	$Id: trace.h,v 1.12 2000/02/14 16:25:22 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Mon Feb 14 14:43:40 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/i4b_trace.h>
end_include

begin_include
include|#
directive|include
file|"pcause_1tr6.h"
end_include

begin_comment
comment|/* obsolete german national ISDN */
end_comment

begin_include
include|#
directive|include
file|"pcause_q850.h"
end_include

begin_define
define|#
directive|define
name|I4BTRC_DEVICE
value|"/dev/i4btrc"
end_define

begin_comment
comment|/* trace device file */
end_comment

begin_define
define|#
directive|define
name|TRACE_FILE_NAME
value|"isdntrace"
end_define

begin_comment
comment|/* default output filename */
end_comment

begin_define
define|#
directive|define
name|BIN_FILE_NAME
value|"isdntracebin"
end_define

begin_comment
comment|/* default binary filename */
end_comment

begin_define
define|#
directive|define
name|BSIZE
value|4096
end_define

begin_comment
comment|/* read buffer size	*/
end_comment

begin_define
define|#
directive|define
name|NCOLS
value|80
end_define

begin_comment
comment|/* screen width		*/
end_comment

begin_define
define|#
directive|define
name|RxUDEF
value|0
end_define

begin_comment
comment|/* analyze mode, default unit for receiver side */
end_comment

begin_define
define|#
directive|define
name|TxUDEF
value|1
end_define

begin_comment
comment|/* analyze mode, default unit for transmitter side */
end_comment

begin_function_decl
name|int
name|decode_lapd
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|int
name|n
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|is_te
parameter_list|,
name|int
name|raw
parameter_list|,
name|int
name|printit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_q931
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|off
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|raw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_unknownl3
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|off
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|raw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|decode_1tr6
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|off
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|raw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|print_error
parameter_list|(
name|int
name|prot
parameter_list|,
name|unsigned
name|char
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|q931_facility
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_q931cause
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_q931address
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_q931bc
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_q931high_compat
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|q932_facility
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_q931user_user
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_q931notification
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|p_q931redir
parameter_list|(
name|char
modifier|*
name|pbuf
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* EOF */
end_comment

end_unit

