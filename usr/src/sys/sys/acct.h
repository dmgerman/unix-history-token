begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	acct.h	3.2	%G%	*/
end_comment

begin_comment
comment|/*  * Accounting structures  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|comp_t
typedef|;
end_typedef

begin_comment
comment|/* "floating pt": 3 bits base 8 exp, 13 bits fraction */
end_comment

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
name|short
name|ac_uid
decl_stmt|;
comment|/* Accounting user ID */
name|short
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

begin_decl_stmt
specifier|extern
name|struct
name|acct
name|acctbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|inode
modifier|*
name|acctp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inode of accounting file */
end_comment

begin_define
define|#
directive|define
name|AFORK
value|01
end_define

begin_comment
comment|/* has executed fork, but no exec */
end_comment

begin_define
define|#
directive|define
name|ASU
value|02
end_define

begin_comment
comment|/* used super-user privileges */
end_comment

end_unit

