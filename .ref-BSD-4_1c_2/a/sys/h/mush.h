begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mush.h	Melb 4.1	82/07/16	*/
end_comment

begin_comment
comment|/*  * MUSH  *  *	format of messages sent from the system to the mush daemon (pid 3)  */
end_comment

begin_define
define|#
directive|define
name|MUSHPID
value|3
end_define

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
name|d_s
block|{
name|char
name|D_req
decl_stmt|;
name|char
name|D_info
decl_stmt|;
name|short
name|D_uid
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|short
name|D_sdat
decl_stmt|;
name|short
name|D_xdat
decl_stmt|;
block|}
name|d_us
struct|;
name|long
name|D_ldat
decl_stmt|;
name|float
name|D_fdat
decl_stmt|;
block|}
name|d_u
union|;
block|}
name|d_s
struct|;
name|char
name|d_c
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|d_s
argument_list|)
index|]
decl_stmt|;
block|}
name|data_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|d_req
value|d_s.D_req
end_define

begin_define
define|#
directive|define
name|d_info
value|d_s.D_info
end_define

begin_define
define|#
directive|define
name|d_uid
value|d_s.D_uid
end_define

begin_define
define|#
directive|define
name|d_sdat
value|d_s.d_u.d_us.D_sdat
end_define

begin_define
define|#
directive|define
name|d_xdat
value|d_s.d_u.d_us.D_xdat
end_define

begin_define
define|#
directive|define
name|d_ldat
value|d_s.d_u.D_ldat
end_define

begin_define
define|#
directive|define
name|d_fdat
value|d_s.d_u.D_fdat
end_define

begin_define
define|#
directive|define
name|DATA_T
value|data_t
end_define

begin_comment
comment|/*  * MUSH messages (D_req values) - to MUSH from kernel  */
end_comment

begin_define
define|#
directive|define
name|MM_PROC1
value|1
end_define

begin_comment
comment|/* first process created for uid */
end_comment

begin_define
define|#
directive|define
name|MM_PROCX
value|2
end_define

begin_comment
comment|/* last process for uid exited */
end_comment

begin_define
define|#
directive|define
name|MM_LOGIN
value|3
end_define

begin_comment
comment|/* additional login for uid */
end_comment

begin_define
define|#
directive|define
name|MM_LOGOUT
value|4
end_define

begin_comment
comment|/* user login proc exited (not last proc) */
end_comment

begin_define
define|#
directive|define
name|MM_ATJOB
value|5
end_define

begin_comment
comment|/* at job has started for uid */
end_comment

begin_define
define|#
directive|define
name|MM_NOCPU
value|6
end_define

begin_comment
comment|/* user isn't getting any cpu time */
end_comment

begin_comment
comment|/*  * nb: the preceding msgs are ignored if they concern uid 0  *	the ones that follow are not  */
end_comment

begin_define
define|#
directive|define
name|MM_NEWCLASS
value|9
end_define

begin_comment
comment|/* current class has (might have) altered */
end_comment

end_unit

