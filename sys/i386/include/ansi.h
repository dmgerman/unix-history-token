begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ansi.h	8.2 (Berkeley) 1/4/94  * $Id: ansi.h,v 1.13 1997/05/08 13:45:43 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ANSI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ANSI_H_
end_define

begin_comment
comment|/*  * Types which are fundamental to the implementation and must be declared  * in more than one standard header are defined here.  Standard headers  * then use:  *	#ifdef	_BSD_SIZE_T_  *	typedef	_BSD_SIZE_T_ size_t;  *	#undef	_BSD_SIZE_T_  *	#endif  */
end_comment

begin_define
define|#
directive|define
name|_BSD_CLOCK_T_
value|unsigned long
end_define

begin_comment
comment|/* clock() */
end_comment

begin_define
define|#
directive|define
name|_BSD_PTRDIFF_T_
value|int
end_define

begin_comment
comment|/* ptr1 - ptr2 */
end_comment

begin_define
define|#
directive|define
name|_BSD_RUNE_T_
value|_BSD_CT_RUNE_T_
end_define

begin_comment
comment|/* rune_t (see below) */
end_comment

begin_define
define|#
directive|define
name|_BSD_SIZE_T_
value|unsigned int
end_define

begin_comment
comment|/* sizeof() */
end_comment

begin_define
define|#
directive|define
name|_BSD_SSIZE_T_
value|int
end_define

begin_comment
comment|/* byte count or error */
end_comment

begin_define
define|#
directive|define
name|_BSD_TIME_T_
value|long
end_define

begin_comment
comment|/* time() */
end_comment

begin_define
define|#
directive|define
name|_BSD_WCHAR_T_
value|_BSD_CT_RUNE_T_
end_define

begin_comment
comment|/* wchar_t (see below) */
end_comment

begin_define
define|#
directive|define
name|_BSD_CLOCKID_T_
value|int
end_define

begin_define
define|#
directive|define
name|_BSD_TIMER_T_
value|int
end_define

begin_define
define|#
directive|define
name|_BSD_UINT8_T_
value|unsigned char
end_define

begin_define
define|#
directive|define
name|_BSD_UINT16_T_
value|unsigned short
end_define

begin_define
define|#
directive|define
name|_BSD_UINT32_T_
value|unsigned int
end_define

begin_comment
comment|/*  * Types which are fundamental to the implementation and must be used  * in more than one standard header although they are only declared in  * one (perhaps nonstandard) header are defined here.  Standard headers  * use _BSD_XXX_T_ without undef'ing it.  */
end_comment

begin_define
define|#
directive|define
name|_BSD_CT_RUNE_T_
value|int
end_define

begin_comment
comment|/* arg type for ctype funcs */
end_comment

begin_define
define|#
directive|define
name|_BSD_OFF_T_
value|long long
end_define

begin_comment
comment|/* file offset */
end_comment

begin_define
define|#
directive|define
name|_BSD_PID_T_
value|int
end_define

begin_comment
comment|/* process [group] */
end_comment

begin_define
define|#
directive|define
name|_BSD_VA_LIST_
value|char *
end_define

begin_comment
comment|/* va_list */
end_comment

begin_comment
comment|/*  * The rune type is declared to be an ``int'' instead of the more natural  * ``unsigned long'' or ``long''.  Two things are happening here.  It is not  * unsigned so that EOF (-1) can be naturally assigned to it and used.  Also,  * it looks like 10646 will be a 31 bit standard.  This means that if your  * ints cannot hold 32 bits, you will be in trouble.  The reason an int was  * chosen over a long is that the is*() and to*() routines take ints (says  * ANSI C), but they use _BSD_CT_RUNE_T_ instead of int.  By changing it  * here, you lose a bit of ANSI conformance, but your programs will still  * work.  */
end_comment

begin_comment
comment|/*  * Frequencies of the clock ticks reported by clock() and times().  They  * are the same as stathz for bogus historical reasons.  They should be  * 1e6 because clock() and times() are implemented using getrusage() and  * there is no good reason why they should be less accurate.  There is  * the bad reason that (broken) programs might not like clock_t or  * CLOCKS_PER_SEC being ``double'' (``unsigned long'' is not large enough  * to hold the required 24 hours worth of ticks if the frequency is  * 1000000ul, and ``unsigned long long'' would be nonstandard).  */
end_comment

begin_define
define|#
directive|define
name|_BSD_CLK_TCK_
value|128
end_define

begin_define
define|#
directive|define
name|_BSD_CLOCKS_PER_SEC_
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ANSI_H_ */
end_comment

end_unit

