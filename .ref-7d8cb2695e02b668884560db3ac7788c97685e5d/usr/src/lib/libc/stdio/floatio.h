begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  *  *	@(#)floatio.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Floating point scanf/printf (input/output) definitions.  */
end_comment

begin_comment
comment|/* 11-bit exponent (VAX G floating point) is 308 decimal digits */
end_comment

begin_define
define|#
directive|define
name|MAXEXP
value|308
end_define

begin_comment
comment|/* 128 bit fraction takes up 39 decimal digits; max reasonable precision */
end_comment

begin_define
define|#
directive|define
name|MAXFRACT
value|39
end_define

end_unit

