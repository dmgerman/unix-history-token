begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)sprite.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * sprite.h --  *  * Common constants and type declarations for Sprite.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPRITE
end_ifndef

begin_define
define|#
directive|define
name|_SPRITE
end_define

begin_comment
comment|/*  * A boolean type is defined as an integer, not an enum. This allows a  * boolean argument to be an expression that isn't strictly 0 or 1 valued.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|Boolean
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FALSE */
end_comment

begin_comment
comment|/*  * Functions that must return a status can return a ReturnStatus to  * indicate success or type of failure.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ReturnStatus
typedef|;
end_typedef

begin_comment
comment|/*  * The following statuses overlap with the first 2 generic statuses  * defined in status.h:  *  * SUCCESS			There was no error.  * FAILURE			There was a general error.  */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FAILURE
value|0x00000001
end_define

begin_comment
comment|/*  * A nil pointer must be something that will cause an exception if  * referenced.  There are two nils: the kernels nil and the nil used  * by user processes.  */
end_comment

begin_define
define|#
directive|define
name|NIL
value|~0
end_define

begin_define
define|#
directive|define
name|USER_NIL
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NULL */
end_comment

begin_comment
comment|/*  * An address is just a pointer in C.  It is defined as a character pointer  * so that address arithmetic will work properly, a byte at a time.  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|Address
typedef|;
end_typedef

begin_comment
comment|/*  * ClientData is an uninterpreted word.  It is defined as an int so that  * kdbx will not interpret client data as a string.  Unlike an "Address",  * client data will generally not be used in arithmetic.  * But we don't have kdbx anymore so we define it as void (christos)  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|ClientData
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SPRITE */
end_comment

end_unit

