begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|h_sccsid
index|[]
init|=
literal|"@(#)hyr_sym.h	2.1 Hyperchannel Routing Daemon 82/11/29"
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
name|s_flags
decl_stmt|;
name|char
name|s_name
index|[
literal|32
index|]
decl_stmt|;
name|long
name|s_lastok
decl_stmt|;
name|long
name|s_fulladdr
decl_stmt|;
name|unsigned
name|short
name|s_dst
decl_stmt|;
name|unsigned
name|short
name|s_ctl
decl_stmt|;
name|unsigned
name|short
name|s_access
decl_stmt|;
name|unsigned
name|short
name|s_ngate
decl_stmt|;
name|struct
name|sym
modifier|*
name|s_next
decl_stmt|;
name|struct
name|sym
modifier|*
name|s_gate
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

