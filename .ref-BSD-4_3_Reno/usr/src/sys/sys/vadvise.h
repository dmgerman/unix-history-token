begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vadvise.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Parameters to vadvise() to tell system of particular paging  * behaviour:  *	VA_NORM		Normal strategy  *	VA_ANOM		Sampling page behaviour is not a win, don't bother  *			Suitable during GCs in LISP, or sequential or random  *			page referencing.  *	VA_SEQL		Sequential behaviour expected.  *	VA_FLUSH	Invalidate all page table entries.  */
end_comment

begin_define
define|#
directive|define
name|VA_NORM
value|0
end_define

begin_define
define|#
directive|define
name|VA_ANOM
value|1
end_define

begin_define
define|#
directive|define
name|VA_SEQL
value|2
end_define

begin_define
define|#
directive|define
name|VA_FLUSH
value|3
end_define

end_unit

