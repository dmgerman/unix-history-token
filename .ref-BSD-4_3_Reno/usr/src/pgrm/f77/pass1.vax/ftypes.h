begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ftypes.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_comment
comment|/* variable types  * numeric assumptions:  *	int< reals< complexes  *	TYDREAL-TYREAL = TYDCOMPLEX-TYCOMPLEX  */
end_comment

begin_define
define|#
directive|define
name|TYUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TYADDR
value|1
end_define

begin_define
define|#
directive|define
name|TYSHORT
value|2
end_define

begin_define
define|#
directive|define
name|TYLONG
value|3
end_define

begin_define
define|#
directive|define
name|TYREAL
value|4
end_define

begin_define
define|#
directive|define
name|TYDREAL
value|5
end_define

begin_define
define|#
directive|define
name|TYCOMPLEX
value|6
end_define

begin_define
define|#
directive|define
name|TYDCOMPLEX
value|7
end_define

begin_define
define|#
directive|define
name|TYLOGICAL
value|8
end_define

begin_define
define|#
directive|define
name|TYCHAR
value|9
end_define

begin_define
define|#
directive|define
name|TYSUBR
value|10
end_define

begin_define
define|#
directive|define
name|TYERROR
value|11
end_define

begin_define
define|#
directive|define
name|NTYPES
value|(TYERROR+1)
end_define

begin_define
define|#
directive|define
name|TYBLANK
value|TYSUBR
end_define

begin_comment
comment|/* special defines for constants */
end_comment

begin_define
define|#
directive|define
name|TYBITSTR
value|TYUNKNOWN
end_define

begin_define
define|#
directive|define
name|TYHOLLERITH
value|TYSUBR
end_define

end_unit

