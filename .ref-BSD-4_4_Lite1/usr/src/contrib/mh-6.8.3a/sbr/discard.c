begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* discard.c - discard output on a file pointer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|ident
index|[]
init|=
literal|"@(#)$Id: discard.c,v 1.7 1993/02/26 21:56:04 jromine Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5
end_ifndef

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYS5 */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NOIOCTLH
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOIOCTLH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS5 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_function
name|void
name|discard
parameter_list|(
name|io
parameter_list|)
name|FILE
modifier|*
name|io
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|POSIX
ifndef|#
directive|ifndef
name|SYS5
name|struct
name|sgttyb
name|sg
decl_stmt|;
else|#
directive|else
comment|/* SYS5 */
name|struct
name|termio
name|sg
decl_stmt|;
endif|#
directive|endif
comment|/* SYS5 */
endif|#
directive|endif
comment|/* POSIX */
if|if
condition|(
name|io
operator|==
name|NULL
condition|)
return|return;
ifdef|#
directive|ifdef
name|POSIX
name|tcflush
argument_list|(
name|fileno
argument_list|(
name|io
argument_list|)
argument_list|,
name|TCOFLUSH
argument_list|)
expr_stmt|;
else|#
directive|else
ifndef|#
directive|ifndef
name|SYS5
if|if
condition|(
name|ioctl
argument_list|(
name|fileno
argument_list|(
name|io
argument_list|)
argument_list|,
name|TIOCGETP
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|sg
argument_list|)
operator|!=
name|NOTOK
condition|)
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|fileno
argument_list|(
name|io
argument_list|)
argument_list|,
name|TIOCSETP
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|sg
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* SYS5 */
if|if
condition|(
name|ioctl
argument_list|(
name|fileno
argument_list|(
name|io
argument_list|)
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|sg
argument_list|)
operator|!=
name|NOTOK
condition|)
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|fileno
argument_list|(
name|io
argument_list|)
argument_list|,
name|TCSETA
argument_list|,
operator|&
name|sg
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SYS5 */
endif|#
directive|endif
comment|/* POSIX */
ifdef|#
directive|ifdef
name|_FSTDIO
name|fpurge
argument_list|(
name|io
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|io
operator|->
name|_ptr
operator|=
name|io
operator|->
name|_base
condition|)
name|io
operator|->
name|_cnt
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

