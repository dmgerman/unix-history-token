begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)SYS.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|<machine/machAsmDefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
value|LEAF(x); li v0,SYS_ ## x; syscall; bne a3,zero,err; \ 			j ra; err: j _cerror; END(x);
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|LEAF(x); li v0,SYS_ ## y; syscall; bne a3,zero,err; \ 			j ra; err: j _cerror; END(x);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RSYSCALL
parameter_list|(
name|x
parameter_list|)
value|LEAF(x); li v0,SYS_
comment|/**/
value|x; syscall; bne a3,zero,err; \ 			j ra; err: j _cerror; END(x);
end_define

begin_define
define|#
directive|define
name|PSEUDO
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|LEAF(x); li v0,SYS_
comment|/**/
value|y; syscall; bne a3,zero,err; \ 			j ra; err: j _cerror; END(x);
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

