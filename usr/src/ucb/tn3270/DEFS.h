begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright 1984, 1985 by the Regents of the University of  *	California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

begin_comment
comment|/* DEFS.h 4.2 83/06/27 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl _
comment|/**/
value|x; .align 2; _
comment|/**/
value|x: .word 0; \ 			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl x; .align 2; x: .word 0; \ 			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl _
comment|/**/
value|x; .align 2; _
comment|/**/
value|x: .word 0
end_define

begin_define
define|#
directive|define
name|ASENTRY
parameter_list|(
name|x
parameter_list|)
value|.globl x; .align 2; x: .word 0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

