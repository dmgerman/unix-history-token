begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Random set of variables  * used by more than one  * routine.  */
end_comment

begin_decl_stmt
name|char
name|canonb
index|[
name|CANBSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for erase and kill (#@) */
end_comment

begin_decl_stmt
name|int
name|coremap
index|[
name|CMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space for core allocation */
end_comment

begin_decl_stmt
name|int
name|swapmap
index|[
name|SMAPSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* space for swap allocation */
end_comment

begin_decl_stmt
name|int
modifier|*
name|rootdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to inode of root directory */
end_comment

begin_decl_stmt
name|int
name|cputype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of cpu =40, 45, or 70 */
end_comment

begin_decl_stmt
name|int
name|execnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of processes in exec */
end_comment

begin_decl_stmt
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of day in 60th not in time */
end_comment

begin_decl_stmt
name|int
name|time
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time in sec from 1970 */
end_comment

begin_decl_stmt
name|int
name|tout
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of day of next sleep */
end_comment

begin_comment
comment|/*  * The callout structure is for  * a routine arranging  * to be called by the clock interrupt  * (clock.c) with a specified argument,  * in a specified amount of time.  * Used, for example, to time tab  * delays on teletypes.  */
end_comment

begin_struct
struct|struct
name|callo
block|{
name|int
name|c_time
decl_stmt|;
comment|/* incremental time */
name|int
name|c_arg
decl_stmt|;
comment|/* argument to routine */
name|int
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine */
block|}
name|callout
index|[
name|NCALL
index|]
struct|;
end_struct

begin_comment
comment|/*  * Mount structure.  * One allocated on every mount.  * Used to find the super block.  */
end_comment

begin_struct
struct|struct
name|mount
block|{
name|int
name|m_dev
decl_stmt|;
comment|/* device mounted */
name|int
modifier|*
name|m_bufp
decl_stmt|;
comment|/* pointer to superblock */
name|int
modifier|*
name|m_inodp
decl_stmt|;
comment|/* pointer to mounted on inode */
block|}
name|mount
index|[
name|NMOUNT
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|mpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generic for unique process id's */
end_comment

begin_decl_stmt
name|char
name|runin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scheduling flag */
end_comment

begin_decl_stmt
name|char
name|runout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scheduling flag */
end_comment

begin_decl_stmt
name|char
name|runrun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scheduling flag */
end_comment

begin_decl_stmt
name|char
name|curpri
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* more scheduling */
end_comment

begin_decl_stmt
name|int
name|maxmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* actual max memory per process */
end_comment

begin_decl_stmt
name|int
modifier|*
name|lks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to clock device */
end_comment

begin_decl_stmt
name|int
name|rootdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dev of root see conf.c */
end_comment

begin_decl_stmt
name|int
name|swapdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dev of swap see conf.c */
end_comment

begin_decl_stmt
name|int
name|swplo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block number of swap space */
end_comment

begin_decl_stmt
name|int
name|nswap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of swap space */
end_comment

begin_decl_stmt
name|int
name|updlock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock for sync */
end_comment

begin_decl_stmt
name|int
name|rablock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block to be read ahead */
end_comment

begin_decl_stmt
name|char
name|regloc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* locs. of saved user registers (trap.c) */
end_comment

end_unit

