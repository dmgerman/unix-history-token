begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	user.h	3.3	%H%	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../h/pcb.h"
end_include

begin_include
include|#
directive|include
file|"../h/dmap.h"
end_include

begin_include
include|#
directive|include
file|"../h/vtimes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FASTVAX
end_ifdef

begin_asm
asm|asm(".set U_ARG,120");
end_asm

begin_asm
asm|asm(".set U_QSAV,140");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/pcb.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmap.h>
end_include

begin_include
include|#
directive|include
file|<sys/vtimes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The user structure.  * One allocated per process.  * Contains all per process data  * that doesn't need to be referenced  * while the process is swapped.  * The user block is UPAGES*NBPG bytes  * long; resides at virtual user  * loc 0x80000000-UPAGES*NBPG; contains the system  * stack per user; is cross referenced  * with the proc structure for the  * same process.  */
end_comment

begin_define
define|#
directive|define
name|EXCLOSE
value|01
end_define

begin_struct
struct|struct
name|user
block|{
name|struct
name|pcb
name|u_pcb
decl_stmt|;
name|int
name|u_arg
index|[
literal|5
index|]
decl_stmt|;
comment|/* arguments to current system call */
name|label_t
name|u_qsav
decl_stmt|;
comment|/* for non-local gotos on interrupts */
name|char
name|u_segflg
decl_stmt|;
comment|/* 0:user D; 1:system; 2:user I */
name|char
name|u_error
decl_stmt|;
comment|/* return error code */
name|short
name|u_uid
decl_stmt|;
comment|/* effective user id */
name|short
name|u_gid
decl_stmt|;
comment|/* effective group id */
name|short
name|u_ruid
decl_stmt|;
comment|/* real user id */
name|short
name|u_rgid
decl_stmt|;
comment|/* real group id */
name|struct
name|proc
modifier|*
name|u_procp
decl_stmt|;
comment|/* pointer to proc structure */
name|int
modifier|*
name|u_ap
decl_stmt|;
comment|/* pointer to arglist */
union|union
block|{
comment|/* syscall return values */
struct|struct
block|{
name|int
name|R_val1
decl_stmt|;
name|int
name|R_val2
decl_stmt|;
block|}
name|u_rv
struct|;
define|#
directive|define
name|r_val1
value|u_rv.R_val1
define|#
directive|define
name|r_val2
value|u_rv.R_val2
name|off_t
name|r_off
decl_stmt|;
name|time_t
name|r_time
decl_stmt|;
block|}
name|u_r
union|;
name|caddr_t
name|u_base
decl_stmt|;
comment|/* base address for IO */
name|unsigned
name|int
name|u_count
decl_stmt|;
comment|/* bytes remaining for IO */
name|off_t
name|u_offset
decl_stmt|;
comment|/* offset in file for IO */
name|struct
name|inode
modifier|*
name|u_cdir
decl_stmt|;
comment|/* pointer to inode of current directory */
name|struct
name|inode
modifier|*
name|u_rdir
decl_stmt|;
comment|/* root directory of current process */
name|char
name|u_dbuf
index|[
name|DIRSIZ
index|]
decl_stmt|;
comment|/* current pathname component */
name|caddr_t
name|u_dirp
decl_stmt|;
comment|/* pathname pointer */
name|struct
name|direct
name|u_dent
decl_stmt|;
comment|/* current directory entry */
name|struct
name|inode
modifier|*
name|u_pdir
decl_stmt|;
comment|/* inode of parent directory of dirp */
name|struct
name|file
modifier|*
name|u_ofile
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* pointers to file structures of open files */
name|char
name|u_pofile
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* per-process flags of open files */
name|label_t
name|u_ssav
decl_stmt|;
comment|/* label variable for swapping */
name|int
function_decl|(
modifier|*
name|u_signal
index|[
name|NSIG
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* disposition of signals */
name|int
name|u_cfcode
decl_stmt|;
comment|/* ``code'' to trap when CM faulted */
name|int
modifier|*
name|u_ar0
decl_stmt|;
comment|/* address of users saved R0 */
struct|struct
name|uprof
block|{
comment|/* profile arguments */
name|short
modifier|*
name|pr_base
decl_stmt|;
comment|/* buffer base */
name|unsigned
name|pr_size
decl_stmt|;
comment|/* buffer size */
name|unsigned
name|pr_off
decl_stmt|;
comment|/* pc offset */
name|unsigned
name|pr_scale
decl_stmt|;
comment|/* pc scaling */
block|}
name|u_prof
struct|;
name|char
name|u_eosys
decl_stmt|;
comment|/* special action on end of syscall */
name|char
name|u_sep
decl_stmt|;
comment|/* flag for I and D separation */
name|struct
name|tty
modifier|*
name|u_ttyp
decl_stmt|;
comment|/* controlling tty pointer */
name|dev_t
name|u_ttyd
decl_stmt|;
comment|/* controlling tty dev */
struct|struct
block|{
comment|/* header of executable file */
name|int
name|ux_mag
decl_stmt|;
comment|/* magic number */
name|unsigned
name|ux_tsize
decl_stmt|;
comment|/* text size */
name|unsigned
name|ux_dsize
decl_stmt|;
comment|/* data size */
name|unsigned
name|ux_bsize
decl_stmt|;
comment|/* bss size */
name|unsigned
name|ux_ssize
decl_stmt|;
comment|/* symbol table size */
name|unsigned
name|ux_entloc
decl_stmt|;
comment|/* entry location */
name|unsigned
name|ux_unused
decl_stmt|;
name|unsigned
name|ux_relflg
decl_stmt|;
block|}
name|u_exdata
struct|;
name|char
name|u_comm
index|[
name|DIRSIZ
index|]
decl_stmt|;
name|time_t
name|u_start
decl_stmt|;
name|char
name|u_acflag
decl_stmt|;
name|short
name|u_fpflag
decl_stmt|;
comment|/* unused now, will be later */
name|short
name|u_cmask
decl_stmt|;
comment|/* mask for file creation */
name|size_t
name|u_tsize
decl_stmt|;
comment|/* text size (clicks) */
name|size_t
name|u_dsize
decl_stmt|;
comment|/* data size (clicks) */
name|size_t
name|u_ssize
decl_stmt|;
comment|/* stack size (clicks) */
name|struct
name|vtimes
name|u_vm
decl_stmt|;
comment|/* stats for this proc */
name|struct
name|vtimes
name|u_cvm
decl_stmt|;
comment|/* sum of stats for reaped children */
name|struct
name|dmap
name|u_dmap
decl_stmt|;
comment|/* disk map for data segment */
name|struct
name|dmap
name|u_smap
decl_stmt|;
comment|/* disk map for stack segment */
name|struct
name|dmap
name|u_cdmap
decl_stmt|,
name|u_csmap
decl_stmt|;
comment|/* shadows of u_dmap, u_smap, for 					   use of parent during fork */
name|time_t
name|u_outime
decl_stmt|;
comment|/* user time at last sample */
name|size_t
name|u_odsize
decl_stmt|,
name|u_ossize
decl_stmt|;
comment|/* for (clumsy) expansion swaps */
name|size_t
name|u_vrpages
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* number vread pages hanging on fd */
name|int
name|u_stack
index|[
literal|1
index|]
decl_stmt|;
comment|/* 					 * kernel stack per user 					 * extends from u + UPAGES*512 					 * backward not to reach here 					 */
block|}
struct|;
end_struct

begin_comment
comment|/* u_eosys values */
end_comment

begin_define
define|#
directive|define
name|JUSTRETURN
value|0
end_define

begin_define
define|#
directive|define
name|RESTARTSYS
value|1
end_define

begin_comment
comment|/* u_error codes */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|user
name|u
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|swaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|forkutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|xswaputl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|xswap2utl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|pushutl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|user
name|vfutl
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

