begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $OpenBSD: stand.h,v 1.2 1999/10/04 21:46:30 espie Exp $ */
end_comment

begin_comment
comment|/* provided to cater for BSD idiosyncrasies */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__unix__
argument_list|)
operator|||
name|defined
argument_list|(
name|unix
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_4
argument_list|)
end_if

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|set_program_name
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warn
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|warnx
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

