begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)vmsystm.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Miscellaneous virtual memory subsystem variables and structures.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|freemem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* remaining blocks of free memory */
end_comment

begin_decl_stmt
name|int
name|avefree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* moving average of remaining free blocks */
end_comment

begin_decl_stmt
name|int
name|avefree30
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 30 sec (avefree is 5 sec) moving average */
end_comment

begin_decl_stmt
name|int
name|deficit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* estimate of needs of new swapped in procs */
end_comment

begin_decl_stmt
name|int
name|nscan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of scans in last second */
end_comment

begin_decl_stmt
name|int
name|multprog
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current multiprogramming degree */
end_comment

begin_decl_stmt
name|int
name|desscan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* desired pages scanned per second */
end_comment

begin_comment
comment|/* writable copies of tunables */
end_comment

begin_decl_stmt
name|int
name|maxpgio
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max paging i/o per sec before start swaps */
end_comment

begin_decl_stmt
name|int
name|maxslp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max sleep time before very swappable */
end_comment

begin_decl_stmt
name|int
name|lotsfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max free before clock freezes */
end_comment

begin_decl_stmt
name|int
name|minfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* minimum free pages before swapping begins */
end_comment

begin_decl_stmt
name|int
name|desfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no of pages to try to keep free via daemon */
end_comment

begin_decl_stmt
name|int
name|saferss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no pages not to steal; decays with slptime */
end_comment

begin_decl_stmt
name|int
name|slowscan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* slowest scan rate, clusters/second */
end_comment

begin_decl_stmt
name|int
name|fastscan
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fastest scan rate, clusters/second */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Fork/vfork accounting.  */
end_comment

begin_struct
struct|struct
name|forkstat
block|{
name|int
name|cntfork
decl_stmt|;
name|int
name|cntvfork
decl_stmt|;
name|int
name|sizfork
decl_stmt|;
name|int
name|sizvfork
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|forkstat
name|forkstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Swap kind accounting.  */
end_comment

begin_struct
struct|struct
name|swptstat
block|{
name|int
name|pteasy
decl_stmt|;
comment|/* easy pt swaps */
name|int
name|ptexpand
decl_stmt|;
comment|/* pt expansion swaps */
name|int
name|ptshrink
decl_stmt|;
comment|/* pt shrinking swaps */
name|int
name|ptpack
decl_stmt|;
comment|/* pt swaps involving spte copying */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|swptstat
name|swptstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

