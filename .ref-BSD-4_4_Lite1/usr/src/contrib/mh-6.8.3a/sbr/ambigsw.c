begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ambigsw.c - report an ambiguous switch */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|ambigsw
parameter_list|(
name|arg
parameter_list|,
name|swp
parameter_list|)
specifier|register
name|char
modifier|*
name|arg
decl_stmt|;
specifier|register
name|struct
name|swit
modifier|*
name|swp
decl_stmt|;
block|{
name|advise
argument_list|(
name|NULLCP
argument_list|,
literal|"-%s ambiguous.  It matches"
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|printsw
argument_list|(
name|arg
argument_list|,
name|swp
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

