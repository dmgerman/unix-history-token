begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	conf2up2rp.c	4.2	11/9/80	*/
end_comment

begin_include
include|#
directive|include
file|"../conf/conf.c"
end_include

begin_comment
comment|/*  * ERNIE primary configuration with 2 rp's and 2 up's  *	root on up1  *	paging on up1 then also rp0 and up0  */
end_comment

begin_decl_stmt
name|dev_t
name|rootdev
init|=
name|makedev
argument_list|(
literal|2
argument_list|,
literal|8
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|pipedev
init|=
name|makedev
argument_list|(
literal|2
argument_list|,
literal|8
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|argdev
init|=
name|makedev
argument_list|(
literal|2
argument_list|,
literal|9
argument_list|)
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
literal|2
argument_list|,
literal|9
argument_list|)
block|,
literal|0
block|,
comment|/* up1b */
name|makedev
argument_list|(
literal|0
argument_list|,
literal|9
argument_list|)
block|,
literal|0
block|,
comment|/* rp1b */
name|makedev
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
block|,
literal|0
block|,
comment|/* up0b */
literal|0
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

end_unit

