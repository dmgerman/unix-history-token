begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: clockvar.h,v 1.1 1998/01/29 15:06:19 pefo Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: clockvar.h,v 1.1 1995/06/28 02:44:59 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  * Adopted for r4400: Per Fogelstrom  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	JNPR: clockvar.h,v 1.3 2006/08/07 05:38:57 katta  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for "cpu-independent" clock handling for the mips arc arch.  */
end_comment

begin_comment
comment|/*  * clocktime structure:  *  * structure passed to TOY clocks when setting them.  broken out this  * way, so that the time_t -> field conversion can be shared.  */
end_comment

begin_struct
struct|struct
name|tod_time
block|{
name|int
name|year
decl_stmt|;
comment|/* year - 1900 */
name|int
name|mon
decl_stmt|;
comment|/* month (1 - 12) */
name|int
name|day
decl_stmt|;
comment|/* day (1 - 31) */
name|int
name|hour
decl_stmt|;
comment|/* hour (0 - 23) */
name|int
name|min
decl_stmt|;
comment|/* minute (0 - 59) */
name|int
name|sec
decl_stmt|;
comment|/* second (0 - 59) */
name|int
name|dow
decl_stmt|;
comment|/* day of week (0 - 6; 0 = Sunday) */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|clockinitted
decl_stmt|;
end_decl_stmt

end_unit

