begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * %sccs.include.redist.c%  *  *	@(#)sel_subs.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * data structure for storing uid/grp selects (-U, -G non standard options)  */
end_comment

begin_define
define|#
directive|define
name|USR_TB_SZ
value|317
end_define

begin_comment
comment|/* user selection table size */
end_comment

begin_define
define|#
directive|define
name|GRP_TB_SZ
value|317
end_define

begin_comment
comment|/* user selection table size */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|usrt
block|{
name|uid_t
name|uid
decl_stmt|;
name|struct
name|usrt
modifier|*
name|fow
decl_stmt|;
comment|/* next uid */
block|}
name|USRT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|grpt
block|{
name|gid_t
name|gid
decl_stmt|;
name|struct
name|grpt
modifier|*
name|fow
decl_stmt|;
comment|/* next gid */
block|}
name|GRPT
typedef|;
end_typedef

begin_comment
comment|/*  * data structure for storing user supplied time ranges (-T option)  */
end_comment

begin_define
define|#
directive|define
name|ATOI2
parameter_list|(
name|s
parameter_list|)
value|((((s)[0] - '0') * 10) + ((s)[1] - '0'))
end_define

begin_typedef
typedef|typedef
struct|struct
name|time_rng
block|{
name|time_t
name|low_time
decl_stmt|;
comment|/* lower inclusive time limit */
name|time_t
name|high_time
decl_stmt|;
comment|/* higher inclusive time limit */
name|int
name|flgs
decl_stmt|;
comment|/* option flags */
define|#
directive|define
name|HASLOW
value|0x01
comment|/* has lower time limit */
define|#
directive|define
name|HASHIGH
value|0x02
comment|/* has higher time limit */
define|#
directive|define
name|CMPMTME
value|0x04
comment|/* compare file modification time */
define|#
directive|define
name|CMPCTME
value|0x08
comment|/* compare inode change time */
define|#
directive|define
name|CMPBOTH
value|(CMPMTME|CMPCTME)
comment|/* compare inode and mod time */
name|struct
name|time_rng
modifier|*
name|fow
decl_stmt|;
comment|/* next pattern */
block|}
name|TIME_RNG
typedef|;
end_typedef

end_unit

