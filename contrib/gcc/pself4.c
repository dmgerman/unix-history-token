begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|p
init|=
literal|"#include<stdio.h>%cint main(void){char*p=%c%s%c;(void)printf(p,10,34,p,34,10);return 0;}%c"
decl_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
name|p
argument_list|,
literal|10
argument_list|,
literal|34
argument_list|,
name|p
argument_list|,
literal|34
argument_list|,
literal|10
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

