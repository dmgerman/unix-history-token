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
name|struct
name|inode
modifier|*
name|rootdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to inode of root directory */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|runq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of linked list of running processes */
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
name|lbolt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time of day in 60th not in time */
end_comment

begin_decl_stmt
name|time_t
name|time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time in sec from 1970 */
end_comment

begin_decl_stmt
name|int
name|time64
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* microseconds since system was booted */
end_comment

begin_comment
comment|/*  * Nblkdev is the number of entries  * (rows) in the block switch. It is  * set in binit/bio.c by making  * a pass over the switch.  * Used in bounds checking on major  * device numbers.  */
end_comment

begin_decl_stmt
name|int
name|nblkdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Number of character switch entries.  * Set by cinit/tty.c  */
end_comment

begin_decl_stmt
name|int
name|nchrdev
decl_stmt|;
end_decl_stmt

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
name|daddr_t
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
name|daddr_t
name|rablock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block to be read ahead */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|regloc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* locs. of saved user registers (trap.c) */
end_comment

begin_decl_stmt
name|char
name|msgbuf
index|[
name|MSGBUFS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* saved "printf" characters */
end_comment

begin_decl_stmt
name|int
name|intstack
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack for interrupts */
end_comment

begin_decl_stmt
name|dev_t
name|rootdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device of the root */
end_comment

begin_decl_stmt
name|dev_t
name|swapdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swapping device */
end_comment

begin_decl_stmt
name|dev_t
name|pipedev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pipe device */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|icode
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* user init code */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|szicode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* its size */
end_comment

begin_function_decl
name|dev_t
name|getmdev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|daddr_t
name|bmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|ialloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|iget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|owner
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|maknode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|inode
modifier|*
name|namei
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|getblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|geteblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|bread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|buf
modifier|*
name|breada
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|filsys
modifier|*
name|getfs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|file
modifier|*
name|getf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|file
modifier|*
name|falloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uchar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|realaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|checkio
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Instrumentation  */
end_comment

begin_decl_stmt
name|int
name|dk_busy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_time
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_numb
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dk_wds
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|tk_nin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|tk_nout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure of the system-entry table  */
end_comment

begin_struct
specifier|extern
struct|struct
name|sysent
block|{
name|char
name|sy_narg
decl_stmt|;
comment|/* total number of arguments */
name|char
name|sy_nrarg
decl_stmt|;
comment|/* number of args in registers */
name|int
function_decl|(
modifier|*
name|sy_call
function_decl|)
parameter_list|()
function_decl|;
comment|/* handler */
block|}
name|sysent
index|[]
struct|;
end_struct

end_unit

