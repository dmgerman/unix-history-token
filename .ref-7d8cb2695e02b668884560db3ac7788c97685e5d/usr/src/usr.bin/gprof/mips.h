begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley. Modified by Ralph Campbell for mips.  *  * %sccs.include.redist.c%  *  *	@(#)mips.h	5.1 (Berkeley) %G%  *  * From: @(#)sparc.h	5.1 (Berkeley) 7/8/92  */
end_comment

begin_comment
comment|/*  * offset (in bytes) of the code from the entry address of a routine.  * (see asgnsamples for use and explanation.)  */
end_comment

begin_define
define|#
directive|define
name|OFFSET_OF_CODE
value|0
end_define

begin_define
define|#
directive|define
name|UNITS_TO_CODE
value|(OFFSET_OF_CODE / sizeof(UNIT))
end_define

begin_enum
enum|enum
name|opermodes
block|{
name|dummy
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|opermodes
name|operandenum
typedef|;
end_typedef

end_unit

