begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)timerreg.h	7.4 (Berkeley) %G%  *  * from: $Header: timerreg.h,v 1.7 92/11/26 03:05:09 leres Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Sun-4c counter/timer registers.  The timers are implemented within  * the cache chip (!).  The counter and limit fields below could be  * defined as:  *  *	struct {  *		u_int	t_limit:1,	// limit reached  *			t_usec:21,	// counter value in microseconds  *			t_mbz:10;	// always zero  *	};  *  * but this is more trouble than it is worth.  *  * These timers work in a rather peculiar fashion.  Most clock counters  * run to 0 (as, e.g., on the VAX, where the ICR counts up to 0 from a  * large unsigned number).  On the Sun-4c, it counts up to a limit.  But  * for some reason, when it reaches the limit, it resets to 1, not 0.  * Thus, if the limit is set to 4, the counter counts like this:  *  *	1, 2, 3, 1, 2, 3, ...  *  * and if we want to divide by N we must set the limit register to N+1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|timer
block|{
name|int
name|t_counter
decl_stmt|;
comment|/* counter reg */
name|int
name|t_limit
decl_stmt|;
comment|/* limit reg */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|timerreg
block|{
name|struct
name|timer
name|t_c10
decl_stmt|;
comment|/* counter that interrupts at ipl 10 */
name|struct
name|timer
name|t_c14
decl_stmt|;
comment|/* counter that interrupts at ipl 14 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TMR_LIMIT
value|0x80000000
end_define

begin_comment
comment|/* counter reached its limit */
end_comment

begin_define
define|#
directive|define
name|TMR_SHIFT
value|10
end_define

begin_comment
comment|/* shift to obtain microseconds */
end_comment

begin_define
define|#
directive|define
name|TMR_MASK
value|0x1fffff
end_define

begin_comment
comment|/* 21 bits */
end_comment

begin_comment
comment|/* Compute a limit that causes the timer to fire every n microseconds. */
end_comment

begin_define
define|#
directive|define
name|tmr_ustolim
parameter_list|(
name|n
parameter_list|)
value|(((n) + 1)<< TMR_SHIFT)
end_define

begin_include
include|#
directive|include
file|<sparc/sparc/vaddrs.h>
end_include

begin_define
define|#
directive|define
name|TIMERREG
value|((volatile struct timerreg *)TIMERREG_VA)
end_define

end_unit

