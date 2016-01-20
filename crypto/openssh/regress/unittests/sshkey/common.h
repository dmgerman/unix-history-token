begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	$OpenBSD: common.h,v 1.1 2014/06/24 01:14:18 djm Exp $ */
end_comment

begin_comment
comment|/*  * Helpers for key API tests  *  * Placed in the public domain  */
end_comment

begin_comment
comment|/* Load a binary file into a buffer */
end_comment

begin_function_decl
name|struct
name|sshbuf
modifier|*
name|load_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Load a text file into a buffer */
end_comment

begin_function_decl
name|struct
name|sshbuf
modifier|*
name|load_text_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Load a bignum from a file */
end_comment

begin_function_decl
name|BIGNUM
modifier|*
name|load_bignum
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

end_unit

