begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)profile.h	7.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|static void _mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|asm(".text; .globl mcount; mcount: pushl 16(fp); calls $1,__mcount; rsb");
end_define

end_unit

