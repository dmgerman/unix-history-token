begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	user.h	4.24	82/12/17	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../machine/pcb.h"
end_include

begin_include
include|#
directive|include
file|"../h/dmap.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<resource.h>
end_include

begin_comment
comment|/*  * Per process structure containing data that  * isn't needed in core when the process is swapped out.  */
end_comment

begin_define
define|#
directive|define
name|SHSIZE
value|32
end_define

begin_struct
struct|struct
name|user
block|{
name|struct
name|pcb
name|u_pcb
decl_stmt|;
name|struct
name|proc
modifier|*
name|u_procp
decl_stmt|;
comment|/* pointer to proc structure */
name|int
modifier|*
name|u_ar0
decl_stmt|;
comment|/* address of users saved R0 */
name|char
name|u_comm
index|[
name|MAXNAMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* syscall parameters, results and catches */
name|int
name|u_arg
index|[
literal|8
index|]
decl_stmt|;
comment|/* arguments to current system call */
name|int
modifier|*
name|u_ap
decl_stmt|;
comment|/* pointer to arglist */
name|label_t
name|u_qsave
decl_stmt|;
comment|/* for non-local gotos on interrupts */
name|char
name|u_error
decl_stmt|;
comment|/* return error code */
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
name|char
name|u_eosys
decl_stmt|;
comment|/* special action on end of syscall */
comment|/* 1.1 - processes and protection */
name|short
name|u_uid
decl_stmt|;
comment|/* effective user id */
name|short
name|u_gid
decl_stmt|;
comment|/* effective group id */
name|int
name|u_groups
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* groups, 0 terminated */
name|short
name|u_ruid
decl_stmt|;
comment|/* real user id */
name|short
name|u_rgid
decl_stmt|;
comment|/* real group id */
comment|/* 1.2 - memory management */
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
name|label_t
name|u_ssave
decl_stmt|;
comment|/* label variable for swapping */
name|size_t
name|u_odsize
decl_stmt|,
name|u_ossize
decl_stmt|;
comment|/* for (clumsy) expansion swaps */
name|time_t
name|u_outime
decl_stmt|;
comment|/* user time at last sample */
comment|/* 1.3 - signal management */
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
name|long
name|u_sigmask
index|[
name|NSIG
index|]
decl_stmt|;
comment|/* signals to be blocked */
name|int
name|u_code
decl_stmt|;
comment|/* ``code'' to trap */
name|caddr_t
name|u_sigstack
decl_stmt|;
comment|/* 0 means no sigstack */
name|int
name|u_onsigstack
decl_stmt|;
comment|/* 1.4 - descriptor management */
name|struct
name|file
modifier|*
name|u_ofile
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* file structures for open files */
name|char
name|u_pofile
index|[
name|NOFILE
index|]
decl_stmt|;
comment|/* per-process flags of open files */
define|#
directive|define
name|UF_EXCLOSE
value|0x1
comment|/* auto-close on exec */
define|#
directive|define
name|UF_SHLOCK
value|0x2
comment|/* shared lock present */
define|#
directive|define
name|UF_EXLOCK
value|0x4
comment|/* exclusive lock present */
define|#
directive|define
name|UF_MAPPED
value|0x8
name|struct
name|inode
modifier|*
name|u_cdir
decl_stmt|;
comment|/* current directory */
name|struct
name|inode
modifier|*
name|u_rdir
decl_stmt|;
comment|/* root directory of current process */
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
name|short
name|u_cmask
decl_stmt|;
comment|/* mask for file creation */
comment|/* 1.5 - timing and statistics */
name|struct
name|rusage
name|u_ru
decl_stmt|;
comment|/* stats for this proc */
name|struct
name|rusage
name|u_cru
decl_stmt|;
comment|/* sum of stats for reaped children */
name|struct
name|itimerval
name|u_timer
index|[
literal|3
index|]
decl_stmt|;
name|int
name|u_XXX
index|[
literal|3
index|]
decl_stmt|;
name|time_t
name|u_start
decl_stmt|;
name|short
name|u_acflag
decl_stmt|;
comment|/* 1.6 - resource controls */
name|struct
name|rlimit
name|u_rlimit
index|[
name|RLIM_NLIMITS
index|]
decl_stmt|;
name|struct
name|quota
modifier|*
name|u_quota
decl_stmt|;
comment|/* user's quota structure */
name|int
name|u_qflags
decl_stmt|;
comment|/* per process quota flags */
comment|/* BEGIN TRASH */
name|char
name|u_segflg
decl_stmt|;
comment|/* 0:user D; 1:system; 2:user I */
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
union|union
block|{
struct|struct
block|{
comment|/* header of executable file */
name|int
name|Ux_mag
decl_stmt|;
comment|/* magic number */
name|unsigned
name|Ux_tsize
decl_stmt|;
comment|/* text size */
name|unsigned
name|Ux_dsize
decl_stmt|;
comment|/* data size */
name|unsigned
name|Ux_bsize
decl_stmt|;
comment|/* bss size */
name|unsigned
name|Ux_ssize
decl_stmt|;
comment|/* symbol table size */
name|unsigned
name|Ux_entloc
decl_stmt|;
comment|/* entry location */
name|unsigned
name|Ux_unused
decl_stmt|;
name|unsigned
name|Ux_relflg
decl_stmt|;
block|}
name|Ux_A
struct|;
name|char
name|ux_shell
index|[
name|SHSIZE
index|]
decl_stmt|;
comment|/* #! and name of interpreter */
block|}
name|u_exdata
union|;
define|#
directive|define
name|ux_mag
value|Ux_A.Ux_mag
define|#
directive|define
name|ux_tsize
value|Ux_A.Ux_tsize
define|#
directive|define
name|ux_dsize
value|Ux_A.Ux_dsize
define|#
directive|define
name|ux_bsize
value|Ux_A.Ux_bsize
define|#
directive|define
name|ux_ssize
value|Ux_A.Ux_ssize
define|#
directive|define
name|ux_entloc
value|Ux_A.Ux_entloc
define|#
directive|define
name|ux_unused
value|Ux_A.Ux_unused
define|#
directive|define
name|ux_relflg
value|Ux_A.Ux_relflg
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
comment|/* END TRASH */
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
name|int
name|u_stack
index|[
literal|1
index|]
decl_stmt|;
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

begin_define
define|#
directive|define
name|SIMULATERTI
value|2
end_define

begin_define
define|#
directive|define
name|REALLYRETURN
value|3
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

