begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  some definitions */
end_comment

begin_define
define|#
directive|define
name|HOSTNAMESIZE
value|32
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_define
define|#
directive|define
name|COMMANDSIZE
value|450
end_define

begin_define
define|#
directive|define
name|PATHSIZE
value|100
end_define

begin_define
define|#
directive|define
name|BIDCMD
value|"dbid"
end_define

begin_comment
comment|/* some basic functions */
end_comment

begin_define
define|#
directive|define
name|new
parameter_list|(
name|q
parameter_list|)
value|((q *)malloc(sizeof(q)))
end_define

begin_define
define|#
directive|define
name|swab
parameter_list|(
name|a
parameter_list|)
value|((a&0xff)<<8 | (a&0xff00)>>8)
end_define

begin_comment
comment|/*  *	the hosts to use  */
end_comment

begin_struct
struct|struct
name|hostdef
block|{
name|char
name|h_name
index|[
name|HOSTNAMESIZE
index|]
decl_stmt|;
comment|/* name of this host */
name|char
name|h_user
index|[
name|HOSTNAMESIZE
index|]
decl_stmt|;
comment|/* name of account to use */
name|char
name|h_dir
index|[
name|PATHSIZE
index|]
decl_stmt|;
comment|/* the directory to use */
name|double
name|h_weight
decl_stmt|;
comment|/* the weighting for this node */
name|struct
name|hostdef
modifier|*
name|h_next
decl_stmt|;
comment|/* next one */
block|}
struct|;
end_struct

end_unit

