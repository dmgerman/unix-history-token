begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is in the public domain.  *  * $FreeBSD$  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|fwmethod
function_decl|)
parameter_list|(
name|int
name|dev_fd
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
name|ich
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|fwmethod
name|dvrecv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fwmethod
name|dvsend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fwmethod
name|mpegtsrecv
decl_stmt|;
end_decl_stmt

end_unit

