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
comment|/*  * addmem - add a new set element block in the correct spot in  *  the bucket chain.  */
end_comment

begin_macro
name|addmem
argument_list|(
argument|ps
argument_list|,
argument|pe
argument_list|,
argument|pl
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|descrip
modifier|*
name|pl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|b_set
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|b_selem
modifier|*
name|pe
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ps
operator|->
name|setsize
operator|++
expr_stmt|;
if|if
condition|(
operator|!
name|NULLDESC
argument_list|(
operator|*
name|pl
argument_list|)
condition|)
block|{
name|BLKLOC
argument_list|(
name|pe
operator|->
name|sblink
argument_list|)
operator|=
name|BLKLOC
argument_list|(
operator|*
name|pl
argument_list|)
expr_stmt|;
name|pe
operator|->
name|sblink
operator|.
name|type
operator|=
name|D_SELEM
expr_stmt|;
block|}
name|BLKLOC
argument_list|(
operator|*
name|pl
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|pe
expr_stmt|;
name|pl
operator|->
name|type
operator|=
name|D_SELEM
expr_stmt|;
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

