begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)wwterminfo.c	3.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TERMINFO
end_ifdef

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/*  * Terminfo support  *  * Written by Brian Buhrow  *  * Subsequently modified by Edward Wang  */
end_comment

begin_comment
comment|/*  * Initialize the working terminfo directory  */
end_comment

begin_macro
name|wwterminfoinit
argument_list|()
end_macro

begin_block
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|char
name|buf
index|[
literal|2048
index|]
decl_stmt|;
comment|/* make the directory */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|wwterminfopath
argument_list|,
literal|"%swwinXXXXXX"
argument_list|,
name|_PATH_TMP
argument_list|)
expr_stmt|;
name|mktemp
argument_list|(
name|wwterminfopath
argument_list|)
expr_stmt|;
if|if
condition|(
name|mkdir
argument_list|(
name|wwterminfopath
argument_list|,
literal|0755
argument_list|)
operator|<
literal|0
operator|||
name|chmod
argument_list|(
name|wwterminfopath
argument_list|,
literal|00755
argument_list|)
operator|<
literal|0
condition|)
block|{
name|wwerrno
operator|=
name|WWE_SYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
operator|(
name|void
operator|)
name|setenv
argument_list|(
literal|"TERMINFO"
argument_list|,
name|wwterminfopath
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* make a termcap entry and turn it into terminfo */
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s/cap"
argument_list|,
name|wwterminfopath
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|buf
argument_list|,
literal|"w"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|wwerrno
operator|=
name|WWE_SYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%sco#%d:li#%d:%s\n"
argument_list|,
name|WWT_TERMCAP
argument_list|,
name|wwncol
argument_list|,
name|wwnrow
argument_list|,
name|wwwintermcap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"cd %s; %s cap>info 2>/dev/null; %s info>/dev/null 2>&1"
argument_list|,
name|wwterminfopath
argument_list|,
name|_PATH_CAPTOINFO
argument_list|,
name|_PATH_TIC
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|system
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/*  * Delete the working terminfo directory at shutdown  */
end_comment

begin_macro
name|wwterminfoend
argument_list|()
end_macro

begin_block
block|{
switch|switch
condition|(
name|vfork
argument_list|()
condition|)
block|{
case|case
operator|-
literal|1
case|:
comment|/* can't really do (or say) anything about errors */
return|return
operator|-
literal|1
return|;
case|case
literal|0
case|:
name|execl
argument_list|(
name|_PATH_RM
argument_list|,
name|_PATH_RM
argument_list|,
literal|"-rf"
argument_list|,
name|wwterminfopath
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
default|default:
return|return
literal|0
return|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMINFO */
end_comment

end_unit

