begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../sys/param.h"
end_include

begin_include
include|#
directive|include
file|"../sys/conf.h"
end_include

begin_decl_stmt
name|dev_t
name|rootdev
init|=
name|makedev
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|argdev
init|=
name|makedev
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|dumpdev
init|=
name|makedev
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|swdevt
name|swdevt
index|[]
init|=
block|{
block|{
name|makedev
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* hk0b */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

