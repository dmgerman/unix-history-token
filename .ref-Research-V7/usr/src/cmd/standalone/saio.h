begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * header file for standalone package  */
end_comment

begin_comment
comment|/*  * io block: includes an  * inode, cells for the use of seek, etc,  * and a buffer.  */
end_comment

begin_struct
struct|struct
name|iob
block|{
name|char
name|i_flgs
decl_stmt|;
name|struct
name|inode
name|i_ino
decl_stmt|;
name|int
name|i_unit
decl_stmt|;
name|daddr_t
name|i_boff
decl_stmt|;
name|daddr_t
name|i_cyloff
decl_stmt|;
name|off_t
name|i_offset
decl_stmt|;
name|daddr_t
name|i_bn
decl_stmt|;
name|char
modifier|*
name|i_ma
decl_stmt|;
name|int
name|i_cc
decl_stmt|;
name|char
name|i_buf
index|[
literal|512
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|F_READ
value|01
end_define

begin_define
define|#
directive|define
name|F_WRITE
value|02
end_define

begin_define
define|#
directive|define
name|F_ALLOC
value|04
end_define

begin_define
define|#
directive|define
name|F_FILE
value|010
end_define

begin_comment
comment|/*  * dev switch  */
end_comment

begin_struct
struct|struct
name|devsw
block|{
name|char
modifier|*
name|dv_name
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dv_strategy
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_open
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|dv_close
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|devsw
name|devsw
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * request codes. Must be the same a F_XXX above  */
end_comment

begin_define
define|#
directive|define
name|READ
value|1
end_define

begin_define
define|#
directive|define
name|WRITE
value|2
end_define

begin_define
define|#
directive|define
name|NBUFS
value|4
end_define

begin_decl_stmt
name|char
name|b
index|[
name|NBUFS
index|]
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|blknos
index|[
name|NBUFS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFILES
value|4
end_define

begin_decl_stmt
name|struct
name|iob
name|iob
index|[
name|NFILES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Set to which 32Kw segment the code is physically running in.  * Must be set by the users main (or there abouts).  */
end_comment

begin_decl_stmt
name|int
name|segflag
decl_stmt|;
end_decl_stmt

end_unit

