begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)acct.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Accounting structures;  * these use a comp_t type which is a 3 bits base 8  * exponent, 13 bit fraction ``floating point'' number.  * Units are 1/AHZ seconds.  */
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
comment|/* Accounting command name */
name|comp_t
name|ac_utime
decl_stmt|;
comment|/* Accounting user time */
name|comp_t
name|ac_stime
decl_stmt|;
comment|/* Accounting system time */
name|comp_t
name|ac_etime
decl_stmt|;
comment|/* Accounting elapsed time */
name|time_t
name|ac_btime
decl_stmt|;
comment|/* Beginning time */
name|uid_t
name|ac_uid
decl_stmt|;
comment|/* Accounting user ID */
name|gid_t
name|ac_gid
decl_stmt|;
comment|/* Accounting group ID */
name|short
name|ac_mem
decl_stmt|;
comment|/* average memory usage */
name|comp_t
name|ac_io
decl_stmt|;
comment|/* number of disk IO blocks */
name|dev_t
name|ac_tty
decl_stmt|;
comment|/* control typewriter */
name|char
name|ac_flag
decl_stmt|;
comment|/* Accounting flag */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AFORK
value|0001
end_define

begin_comment
comment|/* has executed fork, but no exec */
end_comment

begin_define
define|#
directive|define
name|ASU
value|0002
end_define

begin_comment
comment|/* used super-user privileges */
end_comment

begin_define
define|#
directive|define
name|ACOMPAT
value|0004
end_define

begin_comment
comment|/* used compatibility mode */
end_comment

begin_define
define|#
directive|define
name|ACORE
value|0010
end_define

begin_comment
comment|/* dumped core */
end_comment

begin_define
define|#
directive|define
name|AXSIG
value|0020
end_define

begin_comment
comment|/* killed by a signal */
end_comment

begin_comment
comment|/*  * 1/AHZ is the granularity of the data encoded in the various  * comp_t fields.  This is not necessarily equal to hz.  */
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
name|acct
name|acctbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|inode
modifier|*
name|acctp
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

