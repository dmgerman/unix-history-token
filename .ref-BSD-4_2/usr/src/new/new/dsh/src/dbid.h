begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	a bid from a machine  */
end_comment

begin_define
define|#
directive|define
name|NOBID
value|-1.0
end_define

begin_struct
struct|struct
name|bidmsg
block|{
name|double
name|bm_bid
decl_stmt|;
comment|/* highest is best */
name|char
name|bm_host
index|[
name|HOSTNAMESIZE
index|]
decl_stmt|;
name|char
name|bm_dir
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* the directory to use */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	the bids  */
end_comment

begin_struct
struct|struct
name|bid
block|{
name|struct
name|hostdef
modifier|*
name|b_host
decl_stmt|;
name|struct
name|bid
modifier|*
name|b_next
decl_stmt|;
name|double
name|b_bid
decl_stmt|;
block|}
struct|;
end_struct

end_unit

