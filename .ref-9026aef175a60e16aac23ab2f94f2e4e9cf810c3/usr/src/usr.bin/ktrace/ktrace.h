begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ktrace.h	8.1 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|DEF_POINTS
value|(KTRFAC_SYSCALL | KTRFAC_SYSRET | KTRFAC_NAMEI | \ 		  KTRFAC_GENIO | KTRFAC_PSIG)
end_define

begin_define
define|#
directive|define
name|ALL_POINTS
value|(DEF_POINTS | KTRFAC_CSW)
end_define

begin_define
define|#
directive|define
name|DEF_TRACEFILE
value|"ktrace.out"
end_define

end_unit

