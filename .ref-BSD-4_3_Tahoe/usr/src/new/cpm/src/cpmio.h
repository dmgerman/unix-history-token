begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cpmio.h	1.4	83/05/13	*/
end_comment

begin_define
define|#
directive|define
name|INTSIZE
value|32
end_define

begin_comment
comment|/* number of bits per integer on this particular machine */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fid
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|directory
block|{
name|char
name|status
decl_stmt|;
comment|/* status of this entry; equals 0xe5 if */
comment|/* free to use, otherwise contains the */
comment|/* user number (owner) (0 - 15)	*/
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* File name, padded with blanks */
name|char
name|ext
index|[
literal|3
index|]
decl_stmt|;
comment|/* file name extension, padded with blanks */
name|char
name|extno
decl_stmt|;
comment|/* extent number */
name|char
name|notused
index|[
literal|2
index|]
decl_stmt|;
comment|/* unused */
name|char
name|blkcnt
decl_stmt|;
comment|/* record count, number of 128 byte records */
comment|/* in this extent */
name|char
name|pointers
index|[
literal|16
index|]
decl_stmt|;
comment|/* pointers to the individual blocks */
block|}
modifier|*
name|dirbuf
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|,
name|cflag
decl_stmt|,
name|iflag
decl_stmt|,
name|tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|blksiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tracks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|seclth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sectrk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|skew
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|bitmap
decl_stmt|,
modifier|*
name|skewtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bm_size
decl_stmt|;
end_decl_stmt

end_unit

