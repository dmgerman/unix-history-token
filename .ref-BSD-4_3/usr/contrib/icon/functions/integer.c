begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * integer(x) - convert x to integer.  */
end_comment

begin_macro
name|Xinteger
argument_list|(
argument|nargs
argument_list|,
argument|arg1
argument_list|,
argument|arg0
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nargs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|descrip
name|arg1
decl_stmt|,
name|arg0
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|long
name|l
decl_stmt|;
switch|switch
condition|(
name|cvint
argument_list|(
operator|&
name|arg1
argument_list|,
operator|&
name|l
argument_list|)
condition|)
block|{
case|case
name|T_INTEGER
case|:
ifdef|#
directive|ifdef
name|LONGS
case|case
name|T_LONGINT
case|:
endif|#
directive|endif
endif|LONGS
name|mkint
argument_list|(
name|l
argument_list|,
operator|&
name|arg0
argument_list|)
expr_stmt|;
break|break;
default|default:
name|fail
argument_list|()
expr_stmt|;
block|}
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|integer
argument_list|,
literal|1
argument_list|)
end_macro

end_unit

