begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)mvscanw.c	5.6 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * mvscanw, mvwscanw --   *	Implement the mvscanw commands.  Due to the variable number of  *	arguments, they cannot be macros.  Another sigh....  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|mvscanw
argument_list|(
argument|register int y
argument_list|,
argument|register int x
argument_list|,
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|mvscanw
argument_list|(
name|y
argument_list|,
name|x
argument_list|,
name|fmt
argument_list|,
name|va_alist
argument_list|)
specifier|register
name|int
name|y
operator|,
name|x
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|ret
decl_stmt|;
if|if
condition|(
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
operator|!=
name|OK
condition|)
return|return
operator|(
name|ERR
operator|)
return|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ret
operator|=
name|__sscans
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|mvwscanw
argument_list|(
argument|register WINDOW * win
argument_list|,
argument|register int y
argument_list|,
argument|register int x
argument_list|,
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|mvwscanw
argument_list|(
name|win
argument_list|,
name|y
argument_list|,
name|x
argument_list|,
name|fmt
argument_list|,
name|va_alist
argument_list|)
specifier|register
name|WINDOW
operator|*
name|win
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|ret
decl_stmt|;
if|if
condition|(
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
operator|!=
name|OK
condition|)
return|return
operator|(
name|ERR
operator|)
return|;
if|#
directive|if
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ret
operator|=
name|_sscans
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_block

end_unit

