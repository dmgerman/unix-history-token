begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  *  *	@(#)conp.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|SLENG
value|250
end_define

begin_define
define|#
directive|define
name|SCHAR
value|1500
end_define

begin_struct
specifier|extern
struct|struct
name|ss
block|{
name|char
modifier|*
name|sp
decl_stmt|,
name|ic
decl_stmt|,
name|cc
decl_stmt|;
name|int
name|leng
decl_stmt|;
block|}
name|sent
index|[
name|SLENG
index|]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|ss
modifier|*
name|sentp
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern comma
operator|,
extern|j
operator|,
extern|i;
end_extern

begin_decl_stmt
specifier|extern
name|int
name|nsleng
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern question;
end_extern

begin_decl_stmt
name|int
name|must
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|be
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sav
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|prep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|aflg
decl_stmt|,
name|bflg
decl_stmt|,
name|subty
decl_stmt|,
name|verb
decl_stmt|,
name|verbty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iverb
decl_stmt|,
name|pverb
decl_stmt|,
name|done
decl_stmt|;
end_decl_stmt

end_unit

