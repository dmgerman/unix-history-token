begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)acct.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Accounting structures; these use a comp_t type which is a 3 bits base 8  * exponent, 13 bit fraction ``floating point'' number.  Units are 1/AHZ  * seconds.  */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|comp_t
typedef|;
end_typedef

begin_struct
struct|struct
name|acct
block|{
name|char
name|ac_comm
index|[
literal|10
index|]
decl_stmt|;
comment|/* command name */
name|comp_t
name|ac_utime
decl_stmt|;
comment|/* user time */
name|comp_t
name|ac_stime
decl_stmt|;
comment|/* system time */
name|comp_t
name|ac_etime
decl_stmt|;
comment|/* elapsed time */
name|time_t
name|ac_btime
decl_stmt|;
comment|/* starting time */
name|uid_t
name|ac_uid
decl_stmt|;
comment|/* user id */
name|gid_t
name|ac_gid
decl_stmt|;
comment|/* group id */
name|short
name|ac_mem
decl_stmt|;
comment|/* average memory usage */
name|comp_t
name|ac_io
decl_stmt|;
comment|/* count of IO blocks */
name|dev_t
name|ac_tty
decl_stmt|;
comment|/* controlling tty */
define|#
directive|define
name|AFORK
value|0x01
comment|/* forked but not execed */
define|#
directive|define
name|ASU
value|0x02
comment|/* used super-user permissions */
define|#
directive|define
name|ACOMPAT
value|0x04
comment|/* used compatibility mode */
define|#
directive|define
name|ACORE
value|0x08
comment|/* dumped core */
define|#
directive|define
name|AXSIG
value|0x10
comment|/* killed by a signal */
name|char
name|ac_flag
decl_stmt|;
comment|/* accounting flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * 1/AHZ is the granularity of the data encoded in the comp_t fields.  * This is not necessarily equal to hz.  */
end_comment

begin_define
define|#
directive|define
name|AHZ
value|64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|acctp
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

