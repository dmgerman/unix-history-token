begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ed James.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)def.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.  *  * Copy permission is hereby granted provided that this notice is  * retained on all partial or complete copies.  *  * For more info on this and all of my stuff, mail edjames@berkeley.edu.  */
end_comment

begin_define
define|#
directive|define
name|AUTHOR_STR
value|"ATC - by Ed James"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PI
end_ifndef

begin_define
define|#
directive|define
name|PI
value|3.14159265358979323846
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOWFUEL
value|15
end_define

begin_define
define|#
directive|define
name|REALLOC
value|10
end_define

begin_define
define|#
directive|define
name|SGN
parameter_list|(
name|x
parameter_list|)
value|((x< 0) ? -1 : ((x> 0) ? 1 : 0))
end_define

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|x
parameter_list|)
value|((x< 0) ? -(x) : (x))
end_define

begin_define
define|#
directive|define
name|DIR_FROM_DXDY
parameter_list|(
name|dx
parameter_list|,
name|dy
parameter_list|)
value|((int) (atan2((double)(dy), (double)(dx)) \ 				* MAXDIR / (2 * PI) + 2.5 + MAXDIR) % MAXDIR)
end_define

begin_define
define|#
directive|define
name|MAXDIR
value|8
end_define

begin_define
define|#
directive|define
name|D_LEFT
value|1
end_define

begin_define
define|#
directive|define
name|D_RIGHT
value|2
end_define

begin_define
define|#
directive|define
name|D_UP
value|3
end_define

begin_define
define|#
directive|define
name|D_DOWN
value|4
end_define

begin_define
define|#
directive|define
name|T_NODEST
value|0
end_define

begin_define
define|#
directive|define
name|T_BEACON
value|1
end_define

begin_define
define|#
directive|define
name|T_EXIT
value|2
end_define

begin_define
define|#
directive|define
name|T_AIRPORT
value|3
end_define

begin_define
define|#
directive|define
name|S_NONE
value|0
end_define

begin_define
define|#
directive|define
name|S_GONE
value|1
end_define

begin_define
define|#
directive|define
name|S_MARKED
value|2
end_define

begin_define
define|#
directive|define
name|S_UNMARKED
value|3
end_define

begin_define
define|#
directive|define
name|S_IGNORED
value|4
end_define

begin_define
define|#
directive|define
name|INPUT_LINES
value|3
end_define

begin_define
define|#
directive|define
name|PLANE_COLS
value|20
end_define

end_unit

