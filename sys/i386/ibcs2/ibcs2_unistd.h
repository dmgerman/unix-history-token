begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ibcs2_unistd.h,v 1.2 1994/10/26 02:53:11 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_UNISTD_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_UNISTD_H
end_define

begin_define
define|#
directive|define
name|IBCS2_R_OK
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_W_OK
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_X_OK
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_F_OK
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_F_ULOCK
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_F_LOCK
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_F_TLOCK
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_F_TEST
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_SEEK_END
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_ARG_MAX
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_CHILD_MAX
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_CLK_TCK
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_NGROUPS_MAX
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_OPEN_MAX
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_JOB_CONTROL
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_SAVED_IDS
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_VERSION
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_PASS_MAX
value|8
end_define

begin_define
define|#
directive|define
name|IBCS2_SC_XOPEN_VERSION
value|9
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_LINK_MAX
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_MAX_CANON
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_MAX_INPUT
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_NAME_MAX
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_PATH_MAX
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_PIPE_BUF
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_CHOWN_RESTRICTED
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_NO_TRUNC
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_PC_VDISABLE
value|8
end_define

begin_define
define|#
directive|define
name|IBCS2_STDIN_FILENO
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_STDOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_UNISTD_H */
end_comment

end_unit

