begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * psout: structure output by 'ps -r'.  * Most fields are copies of the proc (p_...) or user (u_...)  * structures for the given process, see<sys/user.h>&<sys/proc.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|makedev
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|psout
block|{
name|dev_t
name|o_ttyd
decl_stmt|;
comment|/* u_ttyd */
name|short
name|o_pid
decl_stmt|;
comment|/* p_pid */
name|char
name|o_tty
index|[
literal|2
index|]
decl_stmt|;
comment|/* 1st 2 chars of tty name with 'tty' stripped, if present */
name|char
name|o_flag
decl_stmt|;
comment|/* p_flag */
name|char
name|o_stat
decl_stmt|;
comment|/* p_stat */
name|short
name|o_uid
decl_stmt|;
comment|/* p_uid */
name|char
name|o_uname
index|[
literal|9
index|]
decl_stmt|;
comment|/* login name of process owner */
name|short
name|o_ppid
decl_stmt|;
comment|/* p_ppid */
name|char
name|o_cpu
decl_stmt|;
comment|/* p_cpu */
name|float
name|o_pctcpu
decl_stmt|;
comment|/* ??? */
name|char
name|o_pri
decl_stmt|;
comment|/* p_pri */
name|char
name|o_nice
decl_stmt|;
comment|/* p_nice */
name|short
name|o_addr0
decl_stmt|;
comment|/* p_addr[0] */
name|short
name|o_size
decl_stmt|;
comment|/* p_size */
name|caddr_t
name|o_wchan
decl_stmt|;
comment|/* p_wchan */
name|time_t
name|o_utime
decl_stmt|;
comment|/* u_utime */
name|time_t
name|o_stime
decl_stmt|;
comment|/* u_stime */
name|time_t
name|o_cutime
decl_stmt|;
comment|/* u_cutime */
name|time_t
name|o_cstime
decl_stmt|;
comment|/* u_cstime */
name|short
name|int
name|o_pgrp
decl_stmt|;
comment|/* p_pgrp */
name|size_t
name|o_dsize
decl_stmt|;
comment|/* p_dsize */
name|size_t
name|o_ssize
decl_stmt|;
comment|/* p_ssize */
name|size_t
name|o_rssize
decl_stmt|;
comment|/* p_rssize */
name|char
name|o_time
decl_stmt|;
comment|/* p_time */
name|char
name|o_slptime
decl_stmt|;
comment|/* p_slptime */
name|unsigned
name|o_stksize
decl_stmt|;
comment|/* computed - size of stack */
name|int
name|o_minorflt
decl_stmt|;
comment|/* u_minorflt */
name|int
name|o_majorflt
decl_stmt|;
comment|/* u_majorflt */
name|short
name|o_aveflt
decl_stmt|;
comment|/* p_aveflt */
name|char
modifier|*
name|o_text
decl_stmt|;
comment|/* p_textp */
name|size_t
name|o_swrss
decl_stmt|;
comment|/* p_swrss */
name|size_t
name|o_xsize
decl_stmt|;
comment|/* xp_size from text.h */
name|short
name|o_xrssize
decl_stmt|;
comment|/* xp_rssize from text.h */
name|int
name|o_sigs
decl_stmt|;
comment|/* sum of SIGINT& SIGQUIT, if == 2 proc is ignoring both.*/
name|char
name|o_comm
index|[
literal|15
index|]
decl_stmt|;
comment|/* u_comm */
name|char
name|o_args
index|[
literal|128
index|]
decl_stmt|;
comment|/* best guess at args to process */
block|}
struct|;
end_struct

end_unit

