begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)types.h	7.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X3J11_H_
end_ifndef

begin_define
define|#
directive|define
name|_X3J11_H_
end_define

begin_comment
comment|/*  * Types which are fundamental to the implementation and may appear in  * more than one standard header are defined here.  Standard headers  * then use:  *	#ifdef	_SIZE_T_  *	typedef	_SIZE_T_ size_t;  *	#undef	_SIZE_T_  *	#endif  *  * Thanks, ANSI!  */
end_comment

begin_define
define|#
directive|define
name|_PTRDIFF_T_
value|int
end_define

begin_comment
comment|/* ptr1 - ptr2 */
end_comment

begin_define
define|#
directive|define
name|_VA_LIST_
value|char *
end_define

begin_comment
comment|/* va_list */
end_comment

begin_define
define|#
directive|define
name|_WCHAR_T_
value|unsigned short
end_define

begin_comment
comment|/* wchar_t */
end_comment

begin_define
define|#
directive|define
name|_SIZE_T_
value|unsigned int
end_define

begin_comment
comment|/* sizeof() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _X3J11_H_ */
end_comment

end_unit

