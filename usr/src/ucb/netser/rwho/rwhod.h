begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	rwhod.h	4.3	82/12/24	*/
end_comment

begin_struct
struct|struct
name|whod
block|{
name|int
name|wd_sendtime
decl_stmt|;
name|int
name|wd_recvtime
decl_stmt|;
name|char
name|wd_hostname
index|[
literal|32
index|]
decl_stmt|;
name|int
name|wd_loadav
index|[
literal|3
index|]
decl_stmt|;
name|int
name|wd_boottime
decl_stmt|;
struct|struct
name|whoent
block|{
name|struct
name|utmp
name|we_utmp
decl_stmt|;
name|int
name|we_idle
decl_stmt|;
block|}
name|wd_we
index|[
literal|1024
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|whoent
argument_list|)
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RWHODIR
value|"/usr/spool/rwho"
end_define

begin_comment
comment|/* where data is stored */
end_comment

end_unit

