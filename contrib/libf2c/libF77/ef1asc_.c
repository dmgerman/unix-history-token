begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* EFL support routine to copy string b to string a */
end_comment

begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_define
define|#
directive|define
name|M
value|( (long) (sizeof(long) - 1) )
end_define

begin_define
define|#
directive|define
name|EVEN
parameter_list|(
name|x
parameter_list|)
value|( ( (x)+ M)& (~M) )
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_function_decl
specifier|extern
name|VOID
name|s_copy
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|G77_ef1asc_0
argument_list|(
argument|a
argument_list|,
argument|la
argument_list|,
argument|b
argument_list|,
argument|lb
argument_list|)
end_macro

begin_decl_stmt
name|ftnint
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ftnlen
modifier|*
name|la
decl_stmt|,
modifier|*
name|lb
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|s_copy
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|ftnlen
parameter_list|,
name|ftnlen
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|G77_ef1asc_0
parameter_list|(
name|ftnint
modifier|*
name|a
parameter_list|,
name|ftnlen
modifier|*
name|la
parameter_list|,
name|ftnint
modifier|*
name|b
parameter_list|,
name|ftnlen
modifier|*
name|lb
parameter_list|)
endif|#
directive|endif
block|{
name|s_copy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|a
argument_list|,
operator|(
name|char
operator|*
operator|)
name|b
argument_list|,
name|EVEN
argument_list|(
operator|*
name|la
argument_list|)
argument_list|,
operator|*
name|lb
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* ignored return value */
block|}
end_function

end_unit

