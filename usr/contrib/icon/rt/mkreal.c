begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * mkreal(r, d) - make a real number descriptor and associated heap block  *  for r and place it in *d.  */
end_comment

begin_macro
name|mkreal
argument_list|(
argument|r
argument_list|,
argument|d
argument_list|)
end_macro

begin_decl_stmt
name|double
name|r
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|descrip
modifier|*
name|d
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|struct
name|b_int
modifier|*
name|alcreal
parameter_list|()
function_decl|;
name|hneed
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|b_real
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|type
operator|=
name|D_REAL
expr_stmt|;
name|BLKLOC
argument_list|(
operator|*
name|d
argument_list|)
operator|=
operator|(
expr|union
name|block
operator|*
operator|)
name|alcreal
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

