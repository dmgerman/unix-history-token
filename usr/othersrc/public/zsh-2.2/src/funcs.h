begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct_decl
struct_decl|struct
name|asgment
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|utmp
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"builtin.pro"
end_include

begin_include
include|#
directive|include
file|"cond.pro"
end_include

begin_include
include|#
directive|include
file|"exec.pro"
end_include

begin_include
include|#
directive|include
file|"glob.pro"
end_include

begin_include
include|#
directive|include
file|"hist.pro"
end_include

begin_include
include|#
directive|include
file|"init.pro"
end_include

begin_include
include|#
directive|include
file|"jobs.pro"
end_include

begin_include
include|#
directive|include
file|"lex.pro"
end_include

begin_include
include|#
directive|include
file|"loop.pro"
end_include

begin_include
include|#
directive|include
file|"math.pro"
end_include

begin_include
include|#
directive|include
file|"mem.pro"
end_include

begin_include
include|#
directive|include
file|"params.pro"
end_include

begin_include
include|#
directive|include
file|"parse.pro"
end_include

begin_include
include|#
directive|include
file|"subst.pro"
end_include

begin_include
include|#
directive|include
file|"table.pro"
end_include

begin_include
include|#
directive|include
file|"text.pro"
end_include

begin_include
include|#
directive|include
file|"utils.pro"
end_include

begin_include
include|#
directive|include
file|"watch.pro"
end_include

begin_include
include|#
directive|include
file|"zle_hist.pro"
end_include

begin_include
include|#
directive|include
file|"zle_main.pro"
end_include

begin_include
include|#
directive|include
file|"zle_misc.pro"
end_include

begin_include
include|#
directive|include
file|"zle_move.pro"
end_include

begin_include
include|#
directive|include
file|"zle_refresh.pro"
end_include

begin_include
include|#
directive|include
file|"zle_tricky.pro"
end_include

begin_include
include|#
directive|include
file|"zle_utils.pro"
end_include

begin_include
include|#
directive|include
file|"zle_vi.pro"
end_include

begin_include
include|#
directive|include
file|"zle_word.pro"
end_include

begin_decl_stmt
name|char
modifier|*
name|mktemp
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_STDLIB
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|malloc
name|DCLPROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|realloc
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|calloc
name|DCLPROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|ttyname
name|DCLPROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|PC
decl_stmt|,
modifier|*
name|BC
decl_stmt|,
modifier|*
name|UP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|ospeed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tgetent
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
name|bp
operator|,
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tgetnum
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tgetflag
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
name|id
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tgetstr
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
name|id
operator|,
name|char
operator|*
operator|*
name|area
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tgoto
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
name|cm
operator|,
name|int
name|destcol
operator|,
name|int
name|destline
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tputs
name|DCLPROTO
argument_list|(
operator|(
name|char
operator|*
name|cp
operator|,
name|int
name|affcnt
operator|,
name|int
argument_list|(
operator|*
name|outc
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

