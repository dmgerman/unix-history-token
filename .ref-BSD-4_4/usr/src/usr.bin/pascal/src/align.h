begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)align.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*      *	alignment of various types in bytes.      *	sizes are found using sizeof( type ).      */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|A_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|A_INT
value|4
end_define

begin_define
define|#
directive|define
name|A_FLOAT
value|4
end_define

begin_define
define|#
directive|define
name|A_DOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|A_LONG
value|4
end_define

begin_define
define|#
directive|define
name|A_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|A_POINT
value|4
end_define

begin_define
define|#
directive|define
name|A_STRUCT
value|1
end_define

begin_define
define|#
directive|define
name|A_STACK
value|4
end_define

begin_define
define|#
directive|define
name|A_FILET
value|4
end_define

begin_define
define|#
directive|define
name|A_SET
value|4
end_define

begin_define
define|#
directive|define
name|A_MIN
value|1
end_define

begin_define
define|#
directive|define
name|A_MAX
value|4
end_define

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|A_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|A_INT
value|4
end_define

begin_define
define|#
directive|define
name|A_FLOAT
value|4
end_define

begin_define
define|#
directive|define
name|A_DOUBLE
value|4
end_define

begin_define
define|#
directive|define
name|A_LONG
value|4
end_define

begin_define
define|#
directive|define
name|A_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|A_POINT
value|4
end_define

begin_define
define|#
directive|define
name|A_STRUCT
value|4
end_define

begin_define
define|#
directive|define
name|A_STACK
value|4
end_define

begin_define
define|#
directive|define
name|A_FILET
value|4
end_define

begin_define
define|#
directive|define
name|A_SET
value|4
end_define

begin_define
define|#
directive|define
name|A_MIN
value|1
end_define

begin_define
define|#
directive|define
name|A_MAX
value|4
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_define
define|#
directive|define
name|A_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|A_INT
value|2
end_define

begin_define
define|#
directive|define
name|A_FLOAT
value|2
end_define

begin_define
define|#
directive|define
name|A_DOUBLE
value|2
end_define

begin_define
define|#
directive|define
name|A_LONG
value|2
end_define

begin_define
define|#
directive|define
name|A_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|A_POINT
value|2
end_define

begin_define
define|#
directive|define
name|A_STRUCT
value|2
end_define

begin_define
define|#
directive|define
name|A_STACK
value|2
end_define

begin_define
define|#
directive|define
name|A_FILET
value|2
end_define

begin_define
define|#
directive|define
name|A_SET
value|2
end_define

begin_define
define|#
directive|define
name|A_MIN
value|1
end_define

begin_define
define|#
directive|define
name|A_MAX
value|2
end_define

begin_endif
endif|#
directive|endif
endif|mc68000
end_endif

end_unit

