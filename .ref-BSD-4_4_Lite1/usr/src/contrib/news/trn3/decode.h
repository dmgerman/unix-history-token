begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: decode.h,v 3.0 1991/11/22 04:12:25 davison Trn $  */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|decode_fp
name|INIT
parameter_list|(
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|EXT
name|char
name|decode_fname
index|[
name|MAXFILENAME
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|char
name|decode_dest
index|[
name|MAXFILENAME
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|decode_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|decode_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|decode_end
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uud_start
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uudecode
name|_
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unship_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unship
name|_
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UUDECODE
value|0
end_define

begin_define
define|#
directive|define
name|UNSHIP
value|1
end_define

end_unit

