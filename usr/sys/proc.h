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
name|p_sig
decl_stmt|;
comment|/* signal number sent to this process */
name|char
name|p_uid
decl_stmt|;
comment|/* user id, used to direct tty signals */
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
comment|/* nice for scheduling */
name|int
name|p_ttyp
decl_stmt|;
comment|/* controlling tty */
name|int
name|p_pid
decl_stmt|;
comment|/* unique process id */
name|int
name|p_ppid
decl_stmt|;
comment|/* process id of parent */
name|int
name|p_addr
decl_stmt|;
comment|/* address of swappable image */
name|int
name|p_size
decl_stmt|;
comment|/* size of swappable image (*64 bytes) */
name|int
name|p_wchan
decl_stmt|;
comment|/* event process is awaiting */
name|int
modifier|*
name|p_textp
decl_stmt|;
comment|/* pointer to text structure */
block|}
name|proc
index|[
name|NPROC
index|]
struct|;
end_struct

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
comment|/* sleeping on high priority */
end_comment

begin_define
define|#
directive|define
name|SWAIT
value|2
end_define

begin_comment
comment|/* sleeping on low priority */
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

end_unit

