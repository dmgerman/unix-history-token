begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Used to dissect integer device code  * into major (driver designation) and  * minor (driver parameter) parts.  */
end_comment

begin_struct
struct|struct
block|{
name|char
name|d_minor
decl_stmt|;
name|char
name|d_major
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Declaration of block device  * switch. Each entry (row) is  * the only link between the  * main unix code and the driver.  * The initialization of the  * device switches is in the  * file conf.c.  */
end_comment

begin_struct
struct|struct
name|bdevsw
block|{
name|int
function_decl|(
modifier|*
name|d_open
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_close
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_strategy
function_decl|)
parameter_list|()
function_decl|;
name|int
modifier|*
name|d_tab
decl_stmt|;
block|}
name|bdevsw
index|[]
struct|;
end_struct

begin_comment
comment|/*  * Nblkdev is the number of entries  * (rows) in the block switch. It is  * set in binit/bio.c by making  * a pass over the switch.  * Used in bounds checking on major  * device numbers.  */
end_comment

begin_decl_stmt
name|int
name|nblkdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Character device switch.  */
end_comment

begin_struct
struct|struct
name|cdevsw
block|{
name|int
function_decl|(
modifier|*
name|d_open
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_close
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_read
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_write
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|d_sgtty
function_decl|)
parameter_list|()
function_decl|;
block|}
name|cdevsw
index|[]
struct|;
end_struct

begin_comment
comment|/*  * Number of character switch entries.  * Set by cinit/tty.c  */
end_comment

begin_decl_stmt
name|int
name|nchrdev
decl_stmt|;
end_decl_stmt

end_unit

