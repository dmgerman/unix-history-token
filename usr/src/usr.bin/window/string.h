begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)string.h	3.8 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|STR_DEBUG
end_define

begin_function_decl
name|char
modifier|*
name|str_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_ncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|str_itoa
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|str_cmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcmp(a, b)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|STR_DEBUG
end_ifdef

begin_struct
struct|struct
name|string
block|{
name|struct
name|string
modifier|*
name|s_forw
decl_stmt|;
name|struct
name|string
modifier|*
name|s_back
decl_stmt|;
name|char
name|s_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|string
name|str_head
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|str_offset
value|((unsigned)str_head.s_data - (unsigned)&str_head)
end_define

begin_define
define|#
directive|define
name|str_stos
parameter_list|(
name|s
parameter_list|)
value|((struct string *)((unsigned)(s) - str_offset))
end_define

begin_function_decl
name|char
modifier|*
name|str_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str_free
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|str_free
parameter_list|(
name|s
parameter_list|)
value|free(s)
end_define

begin_define
define|#
directive|define
name|str_alloc
parameter_list|(
name|s
parameter_list|)
value|malloc(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

