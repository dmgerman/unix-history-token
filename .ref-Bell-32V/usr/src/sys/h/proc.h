begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * One structure allocated per active  * process. It contains all data needed  * about the process while the  * process may be swapped out.  * Other per process data (user.h)  * is swapped with the process.  */
end_comment

begin_struct
struct|struct
name|proc
block|{
name|char
name|p_stat
decl_stmt|;
name|char
name|p_flag
decl_stmt|;
name|char
name|p_pri
decl_stmt|;
comment|/* priority, negative is high */
name|char
name|p_time
decl_stmt|;
comment|/* resident time for scheduling */
name|char
name|p_cpu
decl_stmt|;
comment|/* cpu usage for scheduling */
name|char
name|p_nice
decl_stmt|;
comment|/* nice for cpu usage */
name|short
name|p_sig
decl_stmt|;
comment|/* signals pending to this process */
name|short
name|p_uid
decl_stmt|;
comment|/* user id, used to direct tty signals */
name|short
name|p_pgrp
decl_stmt|;
comment|/* name of process group leader */
name|short
name|p_pid
decl_stmt|;
comment|/* unique process id */
name|short
name|p_ppid
decl_stmt|;
comment|/* process id of parent */
name|short
name|p_addr
index|[
name|UPAGES
index|]
decl_stmt|;
comment|/* page table entries of u-area */
name|short
name|p_size
decl_stmt|;
comment|/* size of swappable image (clicks) */
name|short
name|p_swaddr
decl_stmt|;
comment|/* disk address when swapped */
name|short
name|p_swsize
decl_stmt|;
comment|/* number of clicks already swapped */
name|short
name|p_tsize
decl_stmt|;
comment|/* size of text (used by exec/swapin) */
name|caddr_t
name|p_wchan
decl_stmt|;
comment|/* event process is awaiting */
name|struct
name|text
modifier|*
name|p_textp
decl_stmt|;
comment|/* pointer to text structure */
name|struct
name|proc
modifier|*
name|p_link
decl_stmt|;
comment|/* linked list of running processes */
name|int
name|p_clktim
decl_stmt|;
comment|/* time to alarm clock signal */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|proc
name|proc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the proc table itself */
end_comment

begin_comment
comment|/* stat codes */
end_comment

begin_define
define|#
directive|define
name|SSLEEP
value|1
end_define

begin_comment
comment|/* awaiting an event */
end_comment

begin_define
define|#
directive|define
name|SWAIT
value|2
end_define

begin_comment
comment|/* (abandoned state) */
end_comment

begin_define
define|#
directive|define
name|SRUN
value|3
end_define

begin_comment
comment|/* running */
end_comment

begin_define
define|#
directive|define
name|SIDL
value|4
end_define

begin_comment
comment|/* intermediate state in process creation */
end_comment

begin_define
define|#
directive|define
name|SZOMB
value|5
end_define

begin_comment
comment|/* intermediate state in process termination */
end_comment

begin_define
define|#
directive|define
name|SSTOP
value|6
end_define

begin_comment
comment|/* process being traced */
end_comment

begin_comment
comment|/* flag codes */
end_comment

begin_define
define|#
directive|define
name|SLOAD
value|01
end_define

begin_comment
comment|/* in core */
end_comment

begin_define
define|#
directive|define
name|SSYS
value|02
end_define

begin_comment
comment|/* scheduling process */
end_comment

begin_define
define|#
directive|define
name|SLOCK
value|04
end_define

begin_comment
comment|/* process cannot be swapped */
end_comment

begin_define
define|#
directive|define
name|SSWAP
value|010
end_define

begin_comment
comment|/* process is being swapped out */
end_comment

begin_define
define|#
directive|define
name|STRC
value|020
end_define

begin_comment
comment|/* process is being traced */
end_comment

begin_define
define|#
directive|define
name|SWTED
value|040
end_define

begin_comment
comment|/* another tracing flag */
end_comment

begin_define
define|#
directive|define
name|SULOCK
value|0100
end_define

begin_comment
comment|/* user settable lock in core */
end_comment

begin_define
define|#
directive|define
name|SSPART
value|0200
end_define

begin_comment
comment|/* process is partially swapped out */
end_comment

begin_comment
comment|/*  * parallel proc structure  * to replace part with times  * to be passed to parent process  * in ZOMBIE state.  */
end_comment

begin_struct
struct|struct
name|xproc
block|{
name|char
name|xp_stat
decl_stmt|;
name|char
name|xp_flag
decl_stmt|;
name|char
name|xp_pri
decl_stmt|;
comment|/* priority, negative is high */
name|char
name|xp_time
decl_stmt|;
comment|/* resident time for scheduling */
name|char
name|xp_cpu
decl_stmt|;
comment|/* cpu usage for scheduling */
name|char
name|xp_nice
decl_stmt|;
comment|/* nice for cpu usage */
name|short
name|xp_sig
decl_stmt|;
comment|/* signals pending to this process */
name|short
name|xp_uid
decl_stmt|;
comment|/* user id, used to direct tty signals */
name|short
name|xp_pgrp
decl_stmt|;
comment|/* name of process group leader */
name|short
name|xp_pid
decl_stmt|;
comment|/* unique process id */
name|short
name|xp_ppid
decl_stmt|;
comment|/* process id of parent */
name|short
name|xp_xstat
decl_stmt|;
comment|/* Exit status for wait */
name|time_t
name|xp_utime
decl_stmt|;
comment|/* user time, this proc */
name|time_t
name|xp_stime
decl_stmt|;
comment|/* system time, this proc */
block|}
struct|;
end_struct

end_unit

