begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: $  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_decl_stmt
name|int
name|mode
init|=
name|MODE_INTER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|BGFiledes
index|[
literal|2
index|]
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|modem
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tun_in
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tun_out
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|netfd
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dstsystem
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|randinit
parameter_list|()
block|{
specifier|static
name|int
name|initdone
decl_stmt|;
if|if
condition|(
operator|!
name|initdone
condition|)
block|{
name|initdone
operator|=
literal|1
expr_stmt|;
name|srandomdev
argument_list|()
expr_stmt|;
block|}
block|}
end_function

end_unit

