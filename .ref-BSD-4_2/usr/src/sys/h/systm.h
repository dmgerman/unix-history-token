begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	systm.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * Random set of variables  * used by more than one  * routine.  */
end_comment

begin_decl_stmt
name|int
name|hand
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current index into coremap used by daemon */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|version
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system version */
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
name|int
name|rasize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of block in rablock */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|intstack
index|[]
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
name|dumpdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* device to take dumps on */
end_comment

begin_decl_stmt
name|long
name|dumplo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset into dumpdev */
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

begin_comment
comment|/* device for argument lists */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|daddr_t
name|bmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|calloc
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

begin_decl_stmt
name|int
name|uchar
argument_list|()
decl_stmt|,
name|schar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|vmemall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|wmemall
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
name|int
name|sy_narg
decl_stmt|;
comment|/* total number of arguments */
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
name|int
name|noproc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* no one is running just now */
end_comment

begin_decl_stmt
name|char
modifier|*
name|panicstr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|wantin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|boothowto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reboot flags, from console subsystem */
end_comment

begin_decl_stmt
name|int
name|selwait
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|vmmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* poor name! */
end_comment

begin_comment
comment|/* casts to keep lint happy */
end_comment

begin_define
define|#
directive|define
name|insque
parameter_list|(
name|q
parameter_list|,
name|p
parameter_list|)
value|_insque((caddr_t)q,(caddr_t)p)
end_define

begin_define
define|#
directive|define
name|remque
parameter_list|(
name|q
parameter_list|)
value|_remque((caddr_t)q)
end_define

begin_define
define|#
directive|define
name|queue
parameter_list|(
name|q
parameter_list|,
name|p
parameter_list|)
value|_queue((caddr_t)q,(caddr_t)p)
end_define

begin_define
define|#
directive|define
name|dequeue
parameter_list|(
name|q
parameter_list|)
value|_dequeue((caddr_t)q)
end_define

end_unit

