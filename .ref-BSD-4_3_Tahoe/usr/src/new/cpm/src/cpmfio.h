begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cpmfio.h	1.5	83/05/13	*/
end_comment

begin_define
define|#
directive|define
name|C_NFILE
value|5
end_define

begin_comment
comment|/* max number of concurrently open cp/m files */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|c_iobuf
block|{
name|int
name|c_cnt
decl_stmt|;
comment|/* bytes left in buffer */
name|int
name|c_blk
decl_stmt|;
comment|/* block number within the current extent */
comment|/* (starting at 0) */
name|int
name|c_seccnt
decl_stmt|;
comment|/* number of physical sectors left in */
comment|/* the current extent */
name|int
name|c_ext
decl_stmt|;
comment|/* current extent's directory index */
name|int
name|c_extno
decl_stmt|;
comment|/* extent number within current file */
name|char
modifier|*
name|c_buf
decl_stmt|;
comment|/* next character position */
name|char
modifier|*
name|c_base
decl_stmt|;
comment|/* location of buffer */
name|short
name|c_flag
decl_stmt|;
comment|/* access mode (READ or WRITE) */
name|struct
name|directory
modifier|*
name|c_dirp
decl_stmt|;
comment|/* pointer to the current */
comment|/* extent's directory entry */
block|}
name|C_FILE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|C_FILE
name|c_iob
index|[
name|C_NFILE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|c_getc
parameter_list|(
name|p
parameter_list|)
value|(--(p)->c_cnt>=0 ? *(p)->c_buf++&0377 : c_fillbuf(p))
end_define

begin_define
define|#
directive|define
name|c_putc
parameter_list|(
name|x
parameter_list|,
name|p
parameter_list|)
value|(--(p)->c_cnt>=0 ? ((int)(*(p)->c_buf++=(unsigned)(x))) : c_flsbuf((unsigned)(x), p))
end_define

begin_decl_stmt
name|C_FILE
modifier|*
name|c_open
argument_list|()
decl_stmt|,
modifier|*
name|c_creat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|READ
value|0x01
end_define

begin_define
define|#
directive|define
name|WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|RW
value|0x03
end_define

begin_define
define|#
directive|define
name|MODFLG
value|0x08
end_define

begin_define
define|#
directive|define
name|BINARY
value|0x10
end_define

end_unit

