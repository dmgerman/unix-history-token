begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vtimes.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Structure returned by vtimes() and in vwait().  * In vtimes() two of these are returned, one for the process itself  * and one for all its children.  In vwait() these are combined  * by adding componentwise (except for maxrss, which is max'ed).  */
end_comment

begin_struct
struct|struct
name|vtimes
block|{
name|int
name|vm_utime
decl_stmt|;
comment|/* user time (60'ths) */
name|int
name|vm_stime
decl_stmt|;
comment|/* system time (60'ths) */
comment|/* divide next two by utime+stime to get averages */
name|unsigned
name|vm_idsrss
decl_stmt|;
comment|/* integral of d+s rss */
name|unsigned
name|vm_ixrss
decl_stmt|;
comment|/* integral of text rss */
name|int
name|vm_maxrss
decl_stmt|;
comment|/* maximum rss */
name|int
name|vm_majflt
decl_stmt|;
comment|/* major page faults */
name|int
name|vm_minflt
decl_stmt|;
comment|/* minor page faults */
name|int
name|vm_nswap
decl_stmt|;
comment|/* number of swaps */
name|int
name|vm_inblk
decl_stmt|;
comment|/* block reads */
name|int
name|vm_oublk
decl_stmt|;
comment|/* block writes */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

end_unit

