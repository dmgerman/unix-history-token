begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2001 by Solar Designer. See LICENSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PASSWDQC_H
end_ifndef

begin_define
define|#
directive|define
name|_PASSWDQC_H
end_define

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|min
index|[
literal|5
index|]
decl_stmt|,
name|max
decl_stmt|;
name|int
name|passphrase_words
decl_stmt|;
name|int
name|match_length
decl_stmt|;
name|int
name|similar_deny
decl_stmt|;
name|int
name|random_bits
decl_stmt|;
block|}
name|passwdqc_params_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
name|_passwdqc_wordset_4k
index|[
literal|0x1000
index|]
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|_passwdqc_check
parameter_list|(
name|passwdqc_params_t
modifier|*
name|params
parameter_list|,
name|char
modifier|*
name|newpass
parameter_list|,
name|char
modifier|*
name|oldpass
parameter_list|,
name|struct
name|passwd
modifier|*
name|pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_passwdqc_random
parameter_list|(
name|passwdqc_params_t
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

