begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SETS
end_ifdef

begin_comment
comment|/*  * member(S,x) - returns x if x is a member of set S otherwise fails.  */
end_comment

begin_macro
name|Xmember
argument_list|(
argument|nargs
argument_list|,
argument|arg2
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
name|arg2
decl_stmt|,
name|arg1
decl_stmt|,
name|arg0
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|res
decl_stmt|;
specifier|extern
name|struct
name|descrip
modifier|*
name|memb
parameter_list|()
function_decl|;
name|DeRef
argument_list|(
argument|arg1
argument_list|)
name|DeRef
argument_list|(
argument|arg2
argument_list|)
if|if
condition|(
name|QUAL
argument_list|(
name|arg1
argument_list|)
operator|||
name|TYPE
argument_list|(
name|arg1
argument_list|)
operator|!=
name|T_SET
condition|)
name|runerr
argument_list|(
literal|119
argument_list|,
operator|&
name|arg1
argument_list|)
expr_stmt|;
comment|/* S is not a set  */
comment|/* If arg2 is a member of set arg1 then "res" will have the     * value 1 otherwise it will have the value 0.     */
name|memb
argument_list|(
name|BLKLOC
argument_list|(
name|arg1
argument_list|)
argument_list|,
operator|&
name|arg2
argument_list|,
name|hash
argument_list|(
operator|&
name|arg2
argument_list|)
argument_list|,
operator|&
name|res
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|==
literal|1
condition|)
block|{
comment|/* It is a member. */
name|arg0
operator|=
name|arg2
expr_stmt|;
comment|/* Return the member if it is in arg1. */
return|return;
block|}
name|fail
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|member
argument_list|,
literal|2
argument_list|)
end_macro

begin_else
else|#
directive|else
else|SETS
end_else

begin_decl_stmt
name|char
name|junk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prevent null object file */
end_comment

begin_endif
endif|#
directive|endif
endif|SETS
end_endif

end_unit

