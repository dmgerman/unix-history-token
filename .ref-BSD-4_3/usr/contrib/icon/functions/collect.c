begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/rt.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AZ
end_ifdef

begin_comment
comment|/*  * collect(i) - explicit call to garbage collector.  */
end_comment

begin_macro
name|Xcollect
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
name|defshort
argument_list|(
operator|&
name|arg1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|gcollect
argument_list|(
name|INTVAL
argument_list|(
name|arg1
argument_list|)
argument_list|)
expr_stmt|;
name|arg0
operator|=
name|nulldesc
expr_stmt|;
block|}
end_block

begin_macro
name|Procblock
argument_list|(
argument|collect
argument_list|,
literal|1
argument_list|)
end_macro

begin_else
else|#
directive|else
else|AZ
end_else

begin_decl_stmt
name|char
name|junk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prevent empty object module */
end_comment

begin_endif
endif|#
directive|endif
endif|AZ
end_endif

end_unit

