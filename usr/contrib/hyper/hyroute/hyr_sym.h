begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|h_rcsid
index|[]
init|=
literal|"$Header: hyr_sym.h,v 2.3 84/01/29 18:25:05 steveg Exp $$Locker:  $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sym
block|{
name|int
name|sym_flags
decl_stmt|;
name|char
name|sym_name
index|[
literal|32
index|]
decl_stmt|;
name|char
name|sym_nickname
index|[
literal|32
index|]
decl_stmt|;
name|long
name|sym_lastok
decl_stmt|;
name|struct
name|in_addr
name|sym_inaddr
decl_stmt|;
name|unsigned
name|short
name|sym_dst
decl_stmt|;
name|unsigned
name|short
name|sym_ctl
decl_stmt|;
name|unsigned
name|short
name|sym_access
decl_stmt|;
name|unsigned
name|short
name|sym_ngate
decl_stmt|;
name|struct
name|sym
modifier|*
name|sym_next
decl_stmt|;
name|struct
name|sym
modifier|*
name|sym_gate
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HS_DIR
value|0x01
end_define

begin_define
define|#
directive|define
name|HS_INDIR
value|0x02
end_define

begin_define
define|#
directive|define
name|HS_GATE
value|0x04
end_define

begin_define
define|#
directive|define
name|HS_LOOP
value|0x08
end_define

begin_define
define|#
directive|define
name|HS_RLOOP
value|0x10
end_define

begin_decl_stmt
specifier|extern
name|struct
name|sym
modifier|*
name|curgate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sym
modifier|*
name|sym_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lex_error
decl_stmt|;
end_decl_stmt

end_unit

