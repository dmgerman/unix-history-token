begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)saerrno.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just like unix */
end_comment

begin_comment
comment|/* error codes */
end_comment

begin_define
define|#
directive|define
name|EADAPT
value|1
end_define

begin_comment
comment|/* bad adaptor */
end_comment

begin_define
define|#
directive|define
name|ECTLR
value|2
end_define

begin_comment
comment|/* bad controller */
end_comment

begin_define
define|#
directive|define
name|EUNIT
value|3
end_define

begin_comment
comment|/* bad drive */
end_comment

begin_define
define|#
directive|define
name|EPART
value|4
end_define

begin_comment
comment|/* bad partition */
end_comment

begin_define
define|#
directive|define
name|ERDLAB
value|5
end_define

begin_comment
comment|/* can't read disk label */
end_comment

begin_define
define|#
directive|define
name|EUNLAB
value|6
end_define

begin_comment
comment|/* unlabeled disk */
end_comment

begin_define
define|#
directive|define
name|ENXIO
value|7
end_define

begin_comment
comment|/* bad device specification */
end_comment

begin_define
define|#
directive|define
name|EBADF
value|8
end_define

begin_comment
comment|/* bad file descriptor */
end_comment

begin_define
define|#
directive|define
name|EOFFSET
value|9
end_define

begin_comment
comment|/* relative seek not supported */
end_comment

begin_define
define|#
directive|define
name|ESRCH
value|10
end_define

begin_comment
comment|/* directory search for file failed */
end_comment

begin_define
define|#
directive|define
name|EIO
value|11
end_define

begin_comment
comment|/* generic error */
end_comment

begin_define
define|#
directive|define
name|ECMD
value|12
end_define

begin_comment
comment|/* undefined driver command */
end_comment

begin_define
define|#
directive|define
name|EBSE
value|13
end_define

begin_comment
comment|/* bad sector error */
end_comment

begin_define
define|#
directive|define
name|EWCK
value|14
end_define

begin_comment
comment|/* write check error */
end_comment

begin_define
define|#
directive|define
name|EECC
value|15
end_define

begin_comment
comment|/* uncorrectable ecc error */
end_comment

begin_define
define|#
directive|define
name|EHER
value|16
end_define

begin_comment
comment|/* hard error */
end_comment

end_unit

