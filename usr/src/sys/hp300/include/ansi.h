begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ansi.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_H_
end_ifndef

begin_define
define|#
directive|define
name|_ANSI_H_
end_define

begin_comment
comment|/*  * Types which are fundamental to the implementation and may appear in  * more than one standard header are defined here.  Standard headers  * then use:  *	#ifdef	_BSD_SIZE_T_  *	typedef	_BSD_SIZE_T_ size_t;  *	#undef	_BSD_SIZE_T_  *	#endif  *  * Thanks, ANSI!  */
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
name|_BSD_VA_LIST_
value|char *
end_define

begin_comment
comment|/* va_list */
end_comment

begin_comment
comment|/*  * Runes (wchar_t) is declared to be an ``int'' instead of the more natural  * ``unsigned long'' or ``long''.  Two things are happening here.  It is not  * unsigned so that EOF (-1) can be naturally assigned to it and used.  Also,  * it looks like 10646 will be a 31 bit standard.  This means that if your  * ints cannot hold 32 bits, you will be in trouble.  The reason an int was  * chosen over a long is that the is*() and to*() routines take ints (says  * ANSI C), but they use _RUNE_T_ instead of int.  By changing it here, you  * lose a bit of ANSI conformance, but your programs will still work.  *      * Note that _WCHAR_T_ and _RUNE_T_ must be of the same type.  When wchar_t  * and rune_t are typedef'd, _WCHAR_T_ will be undef'd, but _RUNE_T remains  * defined for ctype.h.  */
end_comment

begin_define
define|#
directive|define
name|_BSD_WCHAR_T_
value|int
end_define

begin_comment
comment|/* wchar_t */
end_comment

begin_define
define|#
directive|define
name|_BSD_RUNE_T_
value|int
end_define

begin_comment
comment|/* rune_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ANSI_H_ */
end_comment

end_unit

