begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various tty state structures.  * Each is an array, subscripted by one of "OFF" or "ON".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCSLTC
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ltchars
name|ls
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIOCSLTC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TIOCGETC
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|tchars
name|tc
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BRLUNIX
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|sg_brl
name|sg
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|termio
name|sg
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYSV */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|sg
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BRLUNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

end_unit

