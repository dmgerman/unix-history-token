begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SGIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SGIO_H_
end_define

begin_comment
comment|/* SGI dsreq.h clone derived from the man page.  * On SGI this header is in usr/include/sys.  */
end_comment

begin_comment
comment|/*   * Contributed by HD Associates (hd@world.std.com).  * Copyright (c) 1992, 1993 HD Associates  *  * Berkeley style copyright.  I've just snarfed it out of stdio.h:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

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

begin_typedef
typedef|typedef
struct|struct
name|dsreq
block|{
name|u_long
name|ds_flags
decl_stmt|;
name|u_long
name|ds_time
decl_stmt|;
name|u_long
name|ds_private
decl_stmt|;
name|caddr_t
name|ds_cmdbuf
decl_stmt|;
name|u_char
name|ds_cmdlen
decl_stmt|;
name|caddr_t
name|ds_databuf
decl_stmt|;
name|u_long
name|ds_datalen
decl_stmt|;
name|caddr_t
name|ds_sensebuf
decl_stmt|;
name|u_char
name|ds_senselen
decl_stmt|;
name|u_char
name|ds_ret
decl_stmt|;
name|u_char
name|ds_status
decl_stmt|;
name|u_char
name|ds_msg
decl_stmt|;
name|u_char
name|ds_cmdsent
decl_stmt|;
name|u_long
name|ds_datasent
decl_stmt|;
name|u_char
name|ds_sensesent
decl_stmt|;
block|}
name|dsreq_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DS_ENTER
value|_IOWR('d', 1, struct dsreq)
end_define

begin_define
define|#
directive|define
name|DS_DISCONNECT
value|_IOW('d', 2, int)
end_define

begin_define
define|#
directive|define
name|DS_SYNC
value|_IOW('d', 3, int)
end_define

begin_define
define|#
directive|define
name|DS_TARGET
value|_IOW('d', 4, int)
end_define

begin_comment
comment|/* Data transfer:  */
end_comment

begin_define
define|#
directive|define
name|DSRQ_READ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DSRQ_WRITE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DSRQ_IOV
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DSRQ_BUF
value|0x00000008
end_define

begin_comment
comment|/* devscsi options:  */
end_comment

begin_define
define|#
directive|define
name|DSRQ_ASYNC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DSRQ_SENSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DSRQ_TARGET
value|0x00000040
end_define

begin_comment
comment|/* select options:  */
end_comment

begin_define
define|#
directive|define
name|DSRQ_SELATN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DSRQ_DISC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DSRQ_SYNXFR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DSRQ_SELMSG
value|0x00000400
end_define

begin_comment
comment|/* progress/continuation callbacs:  */
end_comment

begin_define
define|#
directive|define
name|DSRQ_CALL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DSRQ_ACKH
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DSRQ_ATNH
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DSRQ_ABORT
value|0x00004000
end_define

begin_comment
comment|/* Host options (non-portable):  */
end_comment

begin_define
define|#
directive|define
name|DSRQ_TRACE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DSRQ_PRINT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DSRQ_CTRL1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DSRQ_CTRL2
value|0x00040000
end_define

begin_comment
comment|/* Additional flags:  */
end_comment

begin_define
define|#
directive|define
name|DSRQ_MIXRDWR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DSRT_OK
value|0
end_define

begin_define
define|#
directive|define
name|DSRT_DEVSCSI
value|1
end_define

begin_define
define|#
directive|define
name|DSRT_MULT
value|2
end_define

begin_define
define|#
directive|define
name|DSRT_CANCEL
value|3
end_define

begin_define
define|#
directive|define
name|DSRT_REVCODE
value|4
end_define

begin_define
define|#
directive|define
name|DSRT_AGAIN
value|5
end_define

begin_define
define|#
directive|define
name|DSRT_UNIMPL
value|6
end_define

begin_define
define|#
directive|define
name|DSRT_HOST
value|7
end_define

begin_define
define|#
directive|define
name|DSRT_NOSEL
value|8
end_define

begin_define
define|#
directive|define
name|DSRT_SHORT
value|9
end_define

begin_define
define|#
directive|define
name|DSRT_SENSE
value|10
end_define

begin_define
define|#
directive|define
name|DSRT_NOSENSE
value|11
end_define

begin_define
define|#
directive|define
name|DSRT_TIMEOUT
value|12
end_define

begin_define
define|#
directive|define
name|DSRT_LONG
value|13
end_define

begin_define
define|#
directive|define
name|DSRT_PROTO
value|14
end_define

begin_define
define|#
directive|define
name|DSRT_EBSY
value|15
end_define

begin_define
define|#
directive|define
name|DSRT_REJECT
value|16
end_define

begin_define
define|#
directive|define
name|DSRT_PARITY
value|17
end_define

begin_define
define|#
directive|define
name|DSRT_MEMORY
value|18
end_define

begin_define
define|#
directive|define
name|DSRT_CMDO
value|19
end_define

begin_define
define|#
directive|define
name|DSRT_STAI
value|20
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BRAINDEAD
end_ifdef

begin_comment
comment|/* BUG: This does not belong here,  * but I don't want to break my code; it will be moved out  * in the near future.  */
end_comment

begin_define
define|#
directive|define
name|CMDBUF
parameter_list|(
name|DS
parameter_list|)
value|(DS)->ds_cmdbuf
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
comment|/* _SYS_SGIO_H_ */
end_comment

end_unit

