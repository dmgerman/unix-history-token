begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/conf.h"
end_include

begin_comment
comment|/*  * 3 hp drives  *	root on hp0a  *	paging on hp?b  */
end_comment

begin_decl_stmt
name|dev_t
name|rootdev
init|=
name|makedev
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|pipedev
init|=
name|makedev
argument_list|(
literal|0
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
literal|0
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
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dumplo
init|=
literal|33440
operator|-
literal|10
operator|*
literal|2048
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Nswap is the basic number of blocks of swap per  * swap device, and is multiplied by nswdev after  * nswdev is determined at boot.  */
end_comment

begin_decl_stmt
name|int
name|nswap
init|=
literal|33440
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|swdevt
name|swdevt
index|[]
init|=
block|{
name|makedev
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
block|,
literal|0
block|,
comment|/* hp0b */
name|makedev
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
block|,
literal|0
block|,
comment|/* hp1b */
name|makedev
argument_list|(
literal|0
argument_list|,
literal|17
argument_list|)
block|,
literal|0
block|,
comment|/* hp2b */
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

