begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)resource.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Process priority specifications to get/setpriority.  */
end_comment

begin_define
define|#
directive|define
name|PRIO_MIN
value|-20
end_define

begin_define
define|#
directive|define
name|PRIO_MAX
value|20
end_define

begin_define
define|#
directive|define
name|PRIO_PROCESS
value|0
end_define

begin_define
define|#
directive|define
name|PRIO_PGRP
value|1
end_define

begin_define
define|#
directive|define
name|PRIO_USER
value|2
end_define

begin_comment
comment|/*  * Resource utilization information.  */
end_comment

begin_define
define|#
directive|define
name|RUSAGE_SELF
value|0
end_define

begin_define
define|#
directive|define
name|RUSAGE_CHILDREN
value|-1
end_define

begin_struct
struct|struct
name|rusage
block|{
name|struct
name|timeval
name|ru_utime
decl_stmt|;
comment|/* user time used */
name|struct
name|timeval
name|ru_stime
decl_stmt|;
comment|/* system time used */
name|long
name|ru_maxrss
decl_stmt|;
define|#
directive|define
name|ru_first
value|ru_ixrss
name|long
name|ru_ixrss
decl_stmt|;
comment|/* integral shared memory size */
name|long
name|ru_idrss
decl_stmt|;
comment|/* integral unshared data " */
name|long
name|ru_isrss
decl_stmt|;
comment|/* integral unshared stack " */
name|long
name|ru_minflt
decl_stmt|;
comment|/* page reclaims */
name|long
name|ru_majflt
decl_stmt|;
comment|/* page faults */
name|long
name|ru_nswap
decl_stmt|;
comment|/* swaps */
name|long
name|ru_inblock
decl_stmt|;
comment|/* block input operations */
name|long
name|ru_oublock
decl_stmt|;
comment|/* block output operations */
name|long
name|ru_msgsnd
decl_stmt|;
comment|/* messages sent */
name|long
name|ru_msgrcv
decl_stmt|;
comment|/* messages received */
name|long
name|ru_nsignals
decl_stmt|;
comment|/* signals received */
name|long
name|ru_nvcsw
decl_stmt|;
comment|/* voluntary context switches */
name|long
name|ru_nivcsw
decl_stmt|;
comment|/* involuntary " */
define|#
directive|define
name|ru_last
value|ru_nivcsw
block|}
struct|;
end_struct

begin_comment
comment|/*  * Resource limits  */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_CPU
value|0
end_define

begin_comment
comment|/* cpu time in milliseconds */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_FSIZE
value|1
end_define

begin_comment
comment|/* maximum file size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_DATA
value|2
end_define

begin_comment
comment|/* data size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_STACK
value|3
end_define

begin_comment
comment|/* stack size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_CORE
value|4
end_define

begin_comment
comment|/* core file size */
end_comment

begin_define
define|#
directive|define
name|RLIMIT_RSS
value|5
end_define

begin_comment
comment|/* resident set size */
end_comment

begin_define
define|#
directive|define
name|RLIM_NLIMITS
value|6
end_define

begin_comment
comment|/* number of resource limits */
end_comment

begin_define
define|#
directive|define
name|RLIM_INFINITY
value|0x7fffffff
end_define

begin_struct
struct|struct
name|rlimit
block|{
name|int
name|rlim_cur
decl_stmt|;
comment|/* current (soft) limit */
name|int
name|rlim_max
decl_stmt|;
comment|/* maximum value for rlim_cur */
block|}
struct|;
end_struct

end_unit

