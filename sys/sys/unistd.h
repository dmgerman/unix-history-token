begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)unistd.h	8.2 (Berkeley) 1/7/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UNISTD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UNISTD_H_
end_define

begin_comment
comment|/* compile-time symbolic constants */
end_comment

begin_define
define|#
directive|define
name|_POSIX_JOB_CONTROL
end_define

begin_comment
comment|/* implementation supports job control */
end_comment

begin_comment
comment|/*  * This feature does not work for root according to POSIX 1003.1.  * We use the saved IDs in seteuid/setegid, which are not currently  * part of the POSIX 1003.1 specification.  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_SAVED_IDS
end_define

begin_comment
comment|/* saved set-user-ID and set-group-ID */
end_comment

begin_define
define|#
directive|define
name|_POSIX_VERSION
value|198808L
end_define

begin_define
define|#
directive|define
name|_POSIX2_VERSION
value|199212L
end_define

begin_comment
comment|/* execution-time symbolic constants */
end_comment

begin_comment
comment|/* chown requires appropriate privileges */
end_comment

begin_define
define|#
directive|define
name|_POSIX_CHOWN_RESTRICTED
value|1
end_define

begin_comment
comment|/* too-long path components generate errors */
end_comment

begin_define
define|#
directive|define
name|_POSIX_NO_TRUNC
value|1
end_define

begin_comment
comment|/* may disable terminal special characters */
end_comment

begin_define
define|#
directive|define
name|_POSIX_VDISABLE
value|0xff
end_define

begin_comment
comment|/* access function */
end_comment

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_comment
comment|/* test for existence of file */
end_comment

begin_define
define|#
directive|define
name|X_OK
value|0x01
end_define

begin_comment
comment|/* test for execute or search permission */
end_comment

begin_define
define|#
directive|define
name|W_OK
value|0x02
end_define

begin_comment
comment|/* test for write permission */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|0x04
end_define

begin_comment
comment|/* test for read permission */
end_comment

begin_comment
comment|/* whence values for lseek(2) */
end_comment

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* set file offset to offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* set file offset to current plus offset */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* set file offset to EOF plus offset */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* whence values for lseek(2); renamed by POSIX 1003.1 */
end_comment

begin_define
define|#
directive|define
name|L_SET
value|SEEK_SET
end_define

begin_define
define|#
directive|define
name|L_INCR
value|SEEK_CUR
end_define

begin_define
define|#
directive|define
name|L_XTND
value|SEEK_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* configurable pathname variables */
end_comment

begin_define
define|#
directive|define
name|_PC_LINK_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_PC_MAX_CANON
value|2
end_define

begin_define
define|#
directive|define
name|_PC_MAX_INPUT
value|3
end_define

begin_define
define|#
directive|define
name|_PC_NAME_MAX
value|4
end_define

begin_define
define|#
directive|define
name|_PC_PATH_MAX
value|5
end_define

begin_define
define|#
directive|define
name|_PC_PIPE_BUF
value|6
end_define

begin_define
define|#
directive|define
name|_PC_CHOWN_RESTRICTED
value|7
end_define

begin_define
define|#
directive|define
name|_PC_NO_TRUNC
value|8
end_define

begin_define
define|#
directive|define
name|_PC_VDISABLE
value|9
end_define

begin_comment
comment|/* configurable system variables */
end_comment

begin_define
define|#
directive|define
name|_SC_ARG_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_SC_CHILD_MAX
value|2
end_define

begin_define
define|#
directive|define
name|_SC_CLK_TCK
value|3
end_define

begin_define
define|#
directive|define
name|_SC_NGROUPS_MAX
value|4
end_define

begin_define
define|#
directive|define
name|_SC_OPEN_MAX
value|5
end_define

begin_define
define|#
directive|define
name|_SC_JOB_CONTROL
value|6
end_define

begin_define
define|#
directive|define
name|_SC_SAVED_IDS
value|7
end_define

begin_define
define|#
directive|define
name|_SC_VERSION
value|8
end_define

begin_define
define|#
directive|define
name|_SC_BC_BASE_MAX
value|9
end_define

begin_define
define|#
directive|define
name|_SC_BC_DIM_MAX
value|10
end_define

begin_define
define|#
directive|define
name|_SC_BC_SCALE_MAX
value|11
end_define

begin_define
define|#
directive|define
name|_SC_BC_STRING_MAX
value|12
end_define

begin_define
define|#
directive|define
name|_SC_COLL_WEIGHTS_MAX
value|13
end_define

begin_define
define|#
directive|define
name|_SC_EXPR_NEST_MAX
value|14
end_define

begin_define
define|#
directive|define
name|_SC_LINE_MAX
value|15
end_define

begin_define
define|#
directive|define
name|_SC_RE_DUP_MAX
value|16
end_define

begin_define
define|#
directive|define
name|_SC_2_VERSION
value|17
end_define

begin_define
define|#
directive|define
name|_SC_2_C_BIND
value|18
end_define

begin_define
define|#
directive|define
name|_SC_2_C_DEV
value|19
end_define

begin_define
define|#
directive|define
name|_SC_2_CHAR_TERM
value|20
end_define

begin_define
define|#
directive|define
name|_SC_2_FORT_DEV
value|21
end_define

begin_define
define|#
directive|define
name|_SC_2_FORT_RUN
value|22
end_define

begin_define
define|#
directive|define
name|_SC_2_LOCALEDEF
value|23
end_define

begin_define
define|#
directive|define
name|_SC_2_SW_DEV
value|24
end_define

begin_define
define|#
directive|define
name|_SC_2_UPE
value|25
end_define

begin_define
define|#
directive|define
name|_SC_STREAM_MAX
value|26
end_define

begin_define
define|#
directive|define
name|_SC_TZNAME_MAX
value|27
end_define

begin_comment
comment|/* configurable system strings */
end_comment

begin_define
define|#
directive|define
name|_CS_PATH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_UNISTD_H_ */
end_comment

end_unit

