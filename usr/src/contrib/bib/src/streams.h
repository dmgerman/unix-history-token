begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)streams.h	1.2	%G%  */
end_comment

begin_decl_stmt
name|long
name|int
name|nextrecord
argument_list|()
decl_stmt|,
name|recsize
argument_list|()
decl_stmt|,
name|nextline
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|maxstr
value|256
end_define

begin_define
define|#
directive|define
name|pos
parameter_list|(
name|x
parameter_list|)
value|fseek(stream,x,0)
end_define

end_unit

