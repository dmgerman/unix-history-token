begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|char
name|p_sig
decl_stmt|;
name|char
name|p_ndis
decl_stmt|;
name|char
name|p_cook
decl_stmt|;
name|int
name|p_ttyp
decl_stmt|;
name|int
name|p_pid
decl_stmt|;
name|int
name|p_ppid
decl_stmt|;
name|int
name|p_addr
decl_stmt|;
name|int
name|p_size
decl_stmt|;
name|int
name|p_wchan
decl_stmt|;
name|int
modifier|*
name|p_textp
decl_stmt|;
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

begin_define
define|#
directive|define
name|SWAIT
value|2
end_define

begin_define
define|#
directive|define
name|SRUN
value|3
end_define

begin_define
define|#
directive|define
name|SIDL
value|4
end_define

begin_define
define|#
directive|define
name|SZOMB
value|5
end_define

begin_comment
comment|/* flag codes */
end_comment

begin_define
define|#
directive|define
name|SLOAD
value|01
end_define

begin_define
define|#
directive|define
name|SSYS
value|02
end_define

begin_define
define|#
directive|define
name|SLOCK
value|04
end_define

begin_define
define|#
directive|define
name|SSWAP
value|010
end_define

end_unit

