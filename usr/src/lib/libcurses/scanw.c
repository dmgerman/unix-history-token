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
literal|"@(#)scanw.c	5.6 (Berkeley) %G%"
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

begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_include
include|#
directive|include
file|"stdarg.h"
end_include

begin_comment
comment|/*  *	This routine implements a scanf on the standard screen.  */
end_comment

begin_macro
name|scanw
argument_list|(
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|_sscans
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine implements a scanf on the given window.  */
end_comment

begin_macro
name|wscanw
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|args
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

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|_sscans
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*  *	Internal routine to read from a string, and its data structure.  */
end_comment

begin_struct
struct|struct
name|strinfo
block|{
name|char
modifier|*
name|addr
decl_stmt|;
comment|/* address */
name|int
name|len
decl_stmt|;
comment|/* remaining bytes */
block|}
struct|;
end_struct

begin_function
specifier|static
name|int
name|_winread
parameter_list|(
name|cookie
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
name|char
modifier|*
name|cookie
decl_stmt|,
decl|*
name|buf
decl_stmt|;
end_function

begin_decl_stmt
name|reg
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|struct
name|strinfo
modifier|*
name|s
init|=
operator|(
expr|struct
name|strinfo
operator|*
operator|)
name|cookie
decl_stmt|;
if|if
condition|(
name|n
operator|>
name|s
operator|->
name|len
condition|)
name|n
operator|=
name|s
operator|->
name|len
expr_stmt|;
name|bcopy
argument_list|(
name|s
operator|->
name|addr
argument_list|,
name|buf
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|s
operator|->
name|len
operator|-=
name|n
expr_stmt|;
name|s
operator|->
name|addr
operator|+=
name|n
expr_stmt|;
return|return
name|n
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine actually executes the scanf from the window.  *	SHOULD IMPLEMENT VSSCANF  */
end_comment

begin_macro
name|_sscans
argument_list|(
argument|win
argument_list|,
argument|fmt
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

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|FILE
modifier|*
name|f
decl_stmt|;
name|struct
name|strinfo
name|s
decl_stmt|;
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|f
operator|=
name|fropen
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|s
argument_list|,
name|_winread
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
name|ERR
return|;
if|if
condition|(
name|wgetstr
argument_list|(
name|win
argument_list|,
name|buf
argument_list|)
operator|==
name|ERR
condition|)
block|{
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
name|ERR
return|;
block|}
name|s
operator|.
name|addr
operator|=
name|buf
expr_stmt|;
name|s
operator|.
name|len
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|ret
operator|=
name|__svfscanf
argument_list|(
name|f
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
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

end_unit

