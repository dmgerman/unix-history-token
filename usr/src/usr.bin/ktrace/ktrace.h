begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ktrace.h	1.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktrace.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|ALL_POINTS
value|(KTRFAC_SYSCALL | KTRFAC_SYSRET | KTRFAC_NAMEI | \ 		  KTRFAC_GENIO | KTRFAC_PSIG)
end_define

begin_define
define|#
directive|define
name|DEF_TRACEFILE
value|"ktrace.out"
end_define

end_unit

