begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * MD5 internal definitions  * Copyright (c) 2003-2005, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MD5_I_H
end_ifndef

begin_define
define|#
directive|define
name|MD5_I_H
end_define

begin_struct
struct|struct
name|MD5Context
block|{
name|u32
name|buf
index|[
literal|4
index|]
decl_stmt|;
name|u32
name|bits
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|in
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|MD5Init
parameter_list|(
name|struct
name|MD5Context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Update
parameter_list|(
name|struct
name|MD5Context
modifier|*
name|context
parameter_list|,
name|unsigned
name|char
specifier|const
modifier|*
name|buf
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MD5Final
parameter_list|(
name|unsigned
name|char
name|digest
index|[
literal|16
index|]
parameter_list|,
name|struct
name|MD5Context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MD5_I_H */
end_comment

end_unit

