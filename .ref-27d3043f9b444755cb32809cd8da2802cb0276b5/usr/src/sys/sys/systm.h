begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	systm.h	4.1	%G%	*/
end_comment

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
name|cpusid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cpu SID register */
end_comment

begin_decl_stmt
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system version */
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
name|time_t
name|bootime
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* time at which booted */
end_comment

begin_decl_stmt
name|int
name|hand
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current index into coremap used by daemon */
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
comment|/*  * Number of character switch entries.  * Set by cinit/prim.c  */
end_comment

begin_decl_stmt
name|int
name|nchrdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nswdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of swap devices */
end_comment

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
name|int
name|runrun
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scheduling flag */
end_comment

begin_decl_stmt
name|char
name|kmapwnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel map want flag */
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
name|physmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical memory on this CPU */
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
name|argdev
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|int
name|printsw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug print switch */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|coresw
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* switch to force action on core dumps */
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
name|unsigned
name|max
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|min
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|memall
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
name|int
name|vmemall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|swblk_t
name|vtod
parameter_list|()
function_decl|;
end_function_decl

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

begin_decl_stmt
name|char
name|vmmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* poor name! */
end_comment

begin_decl_stmt
name|int
name|mcr
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memory controller registers */
end_comment

begin_decl_stmt
name|int
name|umbabeg
decl_stmt|,
name|umbaend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where sensitive vm begins/ends */
end_comment

begin_decl_stmt
name|int
name|noproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no one is running just now */
end_comment

end_unit

