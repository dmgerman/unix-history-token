begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: dev_net.h,v 1.3 1997/03/15 18:12:14 is Exp $	*/
end_comment

begin_function_decl
name|int
name|net_open
parameter_list|(
name|struct
name|open_file
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|net_close
parameter_list|(
name|struct
name|open_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|net_ioctl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|net_strategy
parameter_list|()
function_decl|;
end_function_decl

end_unit

