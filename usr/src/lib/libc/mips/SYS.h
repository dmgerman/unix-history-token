begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)SYS.h	5.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/syscall.h>
end_include

begin_include
include|#
directive|include
file|"DEFS.h"
end_include

begin_comment
comment|/* vax/tahoe compat */
end_comment

begin_define
define|#
directive|define
name|ret
end_define

begin_define
define|#
directive|define
name|r0
value|v0
end_define

begin_define
define|#
directive|define
name|r1
value|v1
end_define

begin_define
define|#
directive|define
name|SYSCALL
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

end_unit

