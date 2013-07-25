begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * SHA-256 internal definitions  * Copyright (c) 2003-2011, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHA256_I_H
end_ifndef

begin_define
define|#
directive|define
name|SHA256_I_H
end_define

begin_define
define|#
directive|define
name|SHA256_BLOCK_SIZE
value|64
end_define

begin_struct
struct|struct
name|sha256_state
block|{
name|u64
name|length
decl_stmt|;
name|u32
name|state
index|[
literal|8
index|]
decl_stmt|,
name|curlen
decl_stmt|;
name|u8
name|buf
index|[
name|SHA256_BLOCK_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|sha256_init
parameter_list|(
name|struct
name|sha256_state
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sha256_process
parameter_list|(
name|struct
name|sha256_state
modifier|*
name|md
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|in
parameter_list|,
name|unsigned
name|long
name|inlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sha256_done
parameter_list|(
name|struct
name|sha256_state
modifier|*
name|md
parameter_list|,
name|unsigned
name|char
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHA256_I_H */
end_comment

end_unit

