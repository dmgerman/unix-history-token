begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * SHA1 internal definitions  * Copyright (c) 2003-2005, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHA1_I_H
end_ifndef

begin_define
define|#
directive|define
name|SHA1_I_H
end_define

begin_struct
struct|struct
name|SHA1Context
block|{
name|u32
name|state
index|[
literal|5
index|]
decl_stmt|;
name|u32
name|count
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|buffer
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|SHA1Init
parameter_list|(
name|struct
name|SHA1Context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA1Update
parameter_list|(
name|struct
name|SHA1Context
modifier|*
name|context
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|u32
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA1Final
parameter_list|(
name|unsigned
name|char
name|digest
index|[
literal|20
index|]
parameter_list|,
name|struct
name|SHA1Context
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA1Transform
parameter_list|(
name|u32
name|state
index|[
literal|5
index|]
parameter_list|,
specifier|const
name|unsigned
name|char
name|buffer
index|[
literal|64
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHA1_I_H */
end_comment

end_unit

