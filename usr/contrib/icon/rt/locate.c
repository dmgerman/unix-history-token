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
comment|/*  * locate - returns 1 if obj is in the hash chain which  *  starts at ep in some set, returns 0 if not there  *  (used only in diff.c and inter.c).  */
end_comment

begin_macro
name|locate
argument_list|(
argument|ep
argument_list|,
argument|obj
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|b_selem
modifier|*
name|ep
decl_stmt|,
modifier|*
name|obj
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|ep
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|ep
operator|->
name|hnum
operator|>
name|obj
operator|->
name|hnum
condition|)
return|return
literal|0
return|;
elseif|else
if|if
condition|(
operator|(
name|ep
operator|->
name|hnum
operator|==
name|obj
operator|->
name|hnum
operator|)
operator|&&
operator|(
name|equiv
argument_list|(
operator|&
name|ep
operator|->
name|setmem
argument_list|,
operator|&
name|obj
operator|->
name|setmem
argument_list|)
operator|)
condition|)
return|return
literal|1
return|;
name|ep
operator|=
operator|(
expr|struct
name|b_selem
operator|*
operator|)
name|BLKLOC
argument_list|(
name|ep
operator|->
name|sblink
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_block

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

