begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bootparam.h,v 1.3 1998/01/05 19:19:41 perry Exp $	*/
end_comment

begin_function_decl
name|int
name|bp_whoami
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bp_getfile
parameter_list|(
name|int
name|sock
parameter_list|,
name|char
modifier|*
name|key
parameter_list|,
name|struct
name|in_addr
modifier|*
name|addrp
parameter_list|,
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

end_unit

