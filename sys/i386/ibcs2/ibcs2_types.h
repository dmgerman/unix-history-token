begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ibcs2_types.h,v 1.5 1995/08/14 01:11:54 mycroft Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_TYPES_H
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ibcs2_uchar_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ibcs2_ulong_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|ibcs2_caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ibcs2_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ibcs2_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ibcs2_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ibcs2_pid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_TYPES_H */
end_comment

end_unit

