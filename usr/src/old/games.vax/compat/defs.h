begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 	defs.h	4.1	82/05/12  */
end_comment

begin_define
define|#
directive|define
name|EMTS
value|0210
end_define

begin_define
define|#
directive|define
name|TRAPS
value|0211
end_define

begin_define
define|#
directive|define
name|SETD
value|0170011
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|sigvals
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|psl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|regs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
modifier|*
name|pc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|wordspace
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|bytespace
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|memsiz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|incompat
decl_stmt|;
end_decl_stmt

end_unit

