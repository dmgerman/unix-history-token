begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)syslimits.h	7.4 (Berkeley) 2/4/91  *	$Id: syslimits.h,v 1.3 1993/11/07 17:53:05 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSLIMITS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSLIMITS_H_
value|1
end_define

begin_define
define|#
directive|define
name|ARG_MAX
value|32768
end_define

begin_comment
comment|/* max bytes for an exec function */
end_comment

begin_define
define|#
directive|define
name|CHILD_MAX
value|40
end_define

begin_comment
comment|/* max simultaneous processes */
end_comment

begin_define
define|#
directive|define
name|LINK_MAX
value|32767
end_define

begin_comment
comment|/* max file link count */
end_comment

begin_define
define|#
directive|define
name|MAX_CANON
value|255
end_define

begin_comment
comment|/* max bytes in terminal canonical input line */
end_comment

begin_define
define|#
directive|define
name|MAX_INPUT
value|255
end_define

begin_comment
comment|/* max bytes in terminal input */
end_comment

begin_define
define|#
directive|define
name|NAME_MAX
value|255
end_define

begin_comment
comment|/* max number of bytes in a file name */
end_comment

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|16
end_define

begin_comment
comment|/* max number of supplemental group id's */
end_comment

begin_define
define|#
directive|define
name|OPEN_MAX
value|64
end_define

begin_comment
comment|/* max open files per process */
end_comment

begin_define
define|#
directive|define
name|PATH_MAX
value|1024
end_define

begin_comment
comment|/* max number of bytes in pathname */
end_comment

begin_define
define|#
directive|define
name|PIPE_BUF
value|512
end_define

begin_comment
comment|/* max number of bytes for atomic pipe writes */
end_comment

begin_define
define|#
directive|define
name|BC_BASE_MAX
value|99
end_define

begin_comment
comment|/* max ibase/obase values allowed by bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_DIM_MAX
value|2048
end_define

begin_comment
comment|/* max array elements allowed by bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_SCALE_MAX
value|99
end_define

begin_comment
comment|/* max scale value allowed by bc(1) */
end_comment

begin_define
define|#
directive|define
name|BC_STRING_MAX
value|1000
end_define

begin_comment
comment|/* max const string length allowed by bc(1) */
end_comment

begin_define
define|#
directive|define
name|EQUIV_CLASS_MAX
value|2
end_define

begin_comment
comment|/* max weights for order keyword; see locale */
end_comment

begin_define
define|#
directive|define
name|EXPR_NEST_MAX
value|32
end_define

begin_comment
comment|/* max expressions nested in expr(1) */
end_comment

begin_define
define|#
directive|define
name|LINE_MAX
value|2048
end_define

begin_comment
comment|/* max length in bytes of an input line */
end_comment

begin_define
define|#
directive|define
name|RE_DUP_MAX
value|255
end_define

begin_comment
comment|/* max repeated RE's using interval notation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SYSLIMITS_H_ */
end_comment

end_unit

