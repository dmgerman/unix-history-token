begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ex - a text editor  * Bill Joy UCB June 1977  */
end_comment

begin_define
define|#
directive|define
name|ESIZE
value|128
end_define

begin_define
define|#
directive|define
name|NBRA
value|9
end_define

begin_define
define|#
directive|define
name|STAR
value|1
end_define

begin_define
define|#
directive|define
name|CBRA
value|1
end_define

begin_define
define|#
directive|define
name|CCHR
value|2
end_define

begin_define
define|#
directive|define
name|CDOT
value|4
end_define

begin_define
define|#
directive|define
name|CCL
value|6
end_define

begin_define
define|#
directive|define
name|NCCL
value|8
end_define

begin_define
define|#
directive|define
name|CDOL
value|10
end_define

begin_define
define|#
directive|define
name|CEOF
value|11
end_define

begin_define
define|#
directive|define
name|CKET
value|12
end_define

begin_define
define|#
directive|define
name|CBRC
value|14
end_define

begin_define
define|#
directive|define
name|CLET
value|15
end_define

begin_define
define|#
directive|define
name|savere
parameter_list|(
name|a
parameter_list|)
value|copy(a,&re, sizeof re)
end_define

begin_define
define|#
directive|define
name|resre
parameter_list|(
name|a
parameter_list|)
value|copy(&re, a, sizeof re)
end_define

begin_struct
struct|struct
name|savre
block|{
name|char
name|sexpbuf
index|[
name|ESIZE
operator|+
literal|4
index|]
decl_stmt|;
name|char
name|snbra
decl_stmt|;
name|char
name|scircfl
decl_stmt|;
name|char
modifier|*
name|sbraslist
index|[
name|NBRA
index|]
decl_stmt|;
name|char
modifier|*
name|sbraelist
index|[
name|NBRA
index|]
decl_stmt|;
block|}
name|re
struct|,
name|scanre
struct|,
name|subre
struct|;
end_struct

begin_decl_stmt
name|char
name|rhsbuf
index|[
name|LBSIZE
operator|/
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|loc1
decl_stmt|,
modifier|*
name|loc2
decl_stmt|,
modifier|*
name|locs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|linebp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|circfl
value|re.scircfl
end_define

begin_define
define|#
directive|define
name|expbuf
value|re.sexpbuf
end_define

begin_define
define|#
directive|define
name|nbra
value|re.snbra
end_define

begin_define
define|#
directive|define
name|braslist
value|re.sbraslist
end_define

begin_define
define|#
directive|define
name|braelist
value|re.sbraelist
end_define

end_unit

