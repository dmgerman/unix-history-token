begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_comment
comment|/*  * get(x) - get an element from end of list x.  * Synonym for pop(x).  */
end_comment

begin_extern
extern|extern Xpop(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|b_iproc
name|Bget
init|=
block|{
name|T_PROC
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|b_proc
argument_list|)
block|,
name|EntryPoint
argument_list|(
name|Xpop
argument_list|)
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
block|{
literal|3
block|,
literal|"get"
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

