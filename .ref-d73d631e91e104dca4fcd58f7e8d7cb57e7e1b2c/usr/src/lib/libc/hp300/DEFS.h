begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)DEFS.h	5.1 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ENTRY
parameter_list|(
name|x
parameter_list|)
define|\
value|.globl _
comment|/**/
value|x; .even; _
comment|/**/
value|x:; .data; PROF
comment|/**/
value|x:; .long 0; .text; \ 	link a6,#0; lea PROF
comment|/**/
value|x,a0; jsr mcount; unlk a6
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
define|\
value|.globl _
comment|/**/
value|x; .even; _
comment|/**/
value|x:; .data; PROF
comment|/**/
value|x:; .long 0; .text; \ 	lea PROF
comment|/**/
value|x,a0; jsr mcount
end_define

begin_endif
endif|#
directive|endif
end_endif

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
define|\
value|.globl _
comment|/**/
value|x; .even; _
comment|/**/
value|x:
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

