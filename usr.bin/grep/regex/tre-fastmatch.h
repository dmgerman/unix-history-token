begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRE_FASTMATCH_H
end_ifndef

begin_define
define|#
directive|define
name|TRE_FASTMATCH_H
value|1
end_define

begin_include
include|#
directive|include
file|<fastmatch.h>
end_include

begin_include
include|#
directive|include
file|<hashtable.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|"hashtable.h"
end_include

begin_function_decl
name|int
name|tre_compile_literal
parameter_list|(
name|fastmatch_t
modifier|*
name|preg
parameter_list|,
specifier|const
name|tre_char_t
modifier|*
name|regex
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tre_compile_fast
parameter_list|(
name|fastmatch_t
modifier|*
name|preg
parameter_list|,
specifier|const
name|tre_char_t
modifier|*
name|regex
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tre_match_fast
parameter_list|(
specifier|const
name|fastmatch_t
modifier|*
name|fg
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|tre_str_type_t
name|type
parameter_list|,
name|int
name|nmatch
parameter_list|,
name|regmatch_t
name|pmatch
index|[]
parameter_list|,
name|int
name|eflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tre_free_fast
parameter_list|(
name|fastmatch_t
modifier|*
name|preg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRE_FASTMATCH_H */
end_comment

end_unit

