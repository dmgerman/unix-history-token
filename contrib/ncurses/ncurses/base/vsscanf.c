begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This function is needed to support vwscanw  */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_VSSCANF
end_if

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: vsscanf.c,v 1.12 2000/12/10 02:43:28 tom Exp $"
argument_list|)
end_macro

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_IOREAD
argument_list|)
operator|&&
name|defined
argument_list|(
name|_NFILE
argument_list|)
end_if

begin_comment
comment|/*VARARGS2*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|vsscanf
argument_list|(
argument|const char *str
argument_list|,
argument|const char *format
argument_list|,
argument|va_list ap
argument_list|)
end_macro

begin_block
block|{
comment|/*      * This code should work on anything descended from AT&T SVr1.      */
name|FILE
name|strbuf
decl_stmt|;
name|strbuf
operator|.
name|_flag
operator|=
name|_IOREAD
expr_stmt|;
name|strbuf
operator|.
name|_ptr
operator|=
name|strbuf
operator|.
name|_base
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|str
expr_stmt|;
name|strbuf
operator|.
name|_cnt
operator|=
name|strlen
argument_list|(
name|str
argument_list|)
expr_stmt|;
name|strbuf
operator|.
name|_file
operator|=
name|_NFILE
expr_stmt|;
if|#
directive|if
name|HAVE_VFSCANF
return|return
operator|(
name|vfscanf
argument_list|(
operator|&
name|strbuf
argument_list|,
name|format
argument_list|,
name|ap
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|_doscan
argument_list|(
operator|&
name|strbuf
argument_list|,
name|format
argument_list|,
name|ap
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*VARARGS2*/
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|vsscanf
argument_list|(
argument|const char *str
argument_list|,
argument|const char *format
argument_list|,
argument|va_list ap
argument_list|)
end_macro

begin_block
block|{
comment|/*      * You don't have a native vsscanf(3), and you don't have System-V      * compatible stdio internals.  You're probably using a BSD      * older than 4.4 or a really old Linux.  You lose.  Upgrade      * to a current C library to win.      */
return|return
operator|-
literal|1
return|;
comment|/* not implemented */
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_vsscanf
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* quiet's gcc warning */
end_comment

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_vsscanf
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{ }
end_block

begin_comment
comment|/* nonempty for strict ANSI compilers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_VSSCANF */
end_comment

end_unit

