begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)DEFS.h	5.1 (Berkeley) 5/30/85  */
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

