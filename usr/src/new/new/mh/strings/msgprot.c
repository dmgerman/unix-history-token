begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Every NEW message will be created with this protection.  When a  * message is filed it retains its protection, so this only applies  * to messages coming in through inc.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|msgprot
init|=
literal|"0664"
decl_stmt|;
end_decl_stmt

end_unit

