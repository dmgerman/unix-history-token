begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)utmp.h	8.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UTMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_UTMP_H_
end_define

begin_define
define|#
directive|define
name|_PATH_UTMP
value|"/var/run/utmp"
end_define

begin_define
define|#
directive|define
name|_PATH_WTMP
value|"/var/log/wtmp"
end_define

begin_define
define|#
directive|define
name|_PATH_LASTLOG
value|"/var/log/lastlog"
end_define

begin_define
define|#
directive|define
name|UT_NAMESIZE
value|8
end_define

begin_define
define|#
directive|define
name|UT_LINESIZE
value|8
end_define

begin_define
define|#
directive|define
name|UT_HOSTSIZE
value|16
end_define

begin_struct
struct|struct
name|lastlog
block|{
name|time_t
name|ll_time
decl_stmt|;
name|char
name|ll_line
index|[
name|UT_LINESIZE
index|]
decl_stmt|;
name|char
name|ll_host
index|[
name|UT_HOSTSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|utmp
block|{
name|char
name|ut_line
index|[
name|UT_LINESIZE
index|]
decl_stmt|;
name|char
name|ut_name
index|[
name|UT_NAMESIZE
index|]
decl_stmt|;
name|char
name|ut_host
index|[
name|UT_HOSTSIZE
index|]
decl_stmt|;
name|long
name|ut_time
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UTMP_H_ */
end_comment

end_unit

