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
literal|"@(#)scanw.c	5.8 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * scanw and friends  *  */
end_comment

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

begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine implements a scanf on the standard screen.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|scanw
argument_list|(
argument|const char *fmt
argument_list|,
argument|...
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|scanw
argument_list|(
argument|fmt
argument_list|,
argument|va_alist
argument_list|)
end_macro

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
name|ret
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine implements a scanf on the given window.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_macro
name|wscanw
argument_list|(
argument|WINDOW *win
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

begin_macro
name|wscanw
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|va_alist
argument_list|)
end_macro

begin_decl_stmt
name|WINDOW
modifier|*
name|win
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
name|ret
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine actually executes the scanf from the window.  *	THIS SHOULD BE RENAMED vwscanw AND EXPORTED  */
end_comment

begin_macro
name|_sscans
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_decl_stmt
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|va_list
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
return|return
name|wgetstr
argument_list|(
name|win
argument_list|,
name|buf
argument_list|)
operator|==
name|OK
condition|?
name|vsscanf
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
else|:
name|ERR
return|;
block|}
end_block

end_unit

