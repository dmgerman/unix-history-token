begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various tty state structures.  * Each is an array, subscripted by one of "OFF" or "ON".  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SGTTY
argument_list|)
operator|||
name|defined
argument_list|(
name|BRLUNIX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

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
comment|/* BRLUNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIO
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOS
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD386
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|termios
name|sg
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VDSUSP
end_ifndef

begin_define
define|#
directive|define
name|VDSUSP
value|VSUSP
end_define

begin_comment
comment|/* non-Posixism in Irix3.3, may exist in others */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSVR4
end_ifdef

begin_undef
undef|#
directive|undef
name|TIOCSLTC
end_undef

begin_comment
comment|/* don't let BSD emulation mislead us */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
name|SYSV
end_ifdef

begin_undef
undef|#
directive|undef
name|TIOCGETC
end_undef

begin_comment
comment|/* not appropriate for System V */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNIX */
end_comment

end_unit

