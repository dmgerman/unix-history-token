begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|FLAG
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_data[0]
end_define

begin_define
define|#
directive|define
name|ISEMPTY
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_top == (bp)->b_bot)
end_define

begin_define
define|#
directive|define
name|RESET
parameter_list|(
name|bp
parameter_list|)
value|(bp)->b_top = (bp)->b_bot = (bp)->b_data
end_define

begin_define
define|#
directive|define
name|QEMPTY
parameter_list|(
name|qp
parameter_list|)
value|((qp)->b_next == (struct buf *)qp)
end_define

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_top - (bp)->b_bot)
end_define

begin_define
define|#
directive|define
name|GETCHAR
parameter_list|(
name|bp
parameter_list|)
value|(*(bp)->b_bot++& 0377)
end_define

begin_define
define|#
directive|define
name|PUTCHAR
parameter_list|(
name|c
parameter_list|,
name|bp
parameter_list|)
value|*(bp)->b_top++ = c
end_define

begin_define
define|#
directive|define
name|UNGETC
parameter_list|(
name|c
parameter_list|,
name|bp
parameter_list|)
value|*--(bp)->b_bot = c
end_define

begin_define
define|#
directive|define
name|BUFCOPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|bcopy((f)->b_bot, (t)->b_top, SIZE(f)); (t)->b_top+=SIZE(f);
end_define

begin_define
define|#
directive|define
name|STRTOBUF
parameter_list|(
name|s
parameter_list|,
name|bp
parameter_list|)
value|{ register char *sp=s; register int l=strlen(s); \ 			bcopy(s, (bp)->b_top, l); (bp)->b_top += l;}
end_define

begin_struct
struct|struct
name|bufhd
block|{
comment|/* buffer header; b_prev and b_next must be first */
name|struct
name|buf
modifier|*
name|b_prev
decl_stmt|,
modifier|*
name|b_next
decl_stmt|;
name|short
name|b_count
decl_stmt|;
comment|/* total number of bytes of data queued */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|buf
block|{
name|struct
name|buf
modifier|*
name|b_prev
decl_stmt|,
modifier|*
name|b_next
decl_stmt|;
comment|/* previous and next buffers */
name|char
modifier|*
name|b_bot
decl_stmt|;
comment|/* start of useful data */
name|char
modifier|*
name|b_top
decl_stmt|;
comment|/* current position in data */
name|char
name|b_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* usually more than 1 byte */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|buf
modifier|*
name|getbuf
argument_list|()
decl_stmt|,
modifier|*
name|FillBuf
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

