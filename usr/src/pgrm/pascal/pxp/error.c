begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)error.c	5.2 (Berkeley) 12/4/87"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * pi - Pascal interpreter code translator  *  * Charles Haley, Bill Joy UCB  * Version 1.2 January 1979  *  *  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"yy.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PXP
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|errout
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|errpfx
init|=
literal|'E'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Panic is called when impossible  * (supposedly, anyways) situations  * are encountered. #ifdef PI  * Panic messages should be short  * as they do not go to the message  * file. #endif  */
end_comment

begin_macro
name|panic
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Snark (%s) line=%d yyline=%d\n"
argument_list|,
name|s
argument_list|,
name|line
argument_list|,
name|yyline
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PXP
name|Perror
argument_list|(
literal|"Snark in pxp"
argument_list|,
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PI
name|Perror
argument_list|(
literal|"Snark in pi"
argument_list|,
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pexit
argument_list|(
name|DIED
argument_list|)
expr_stmt|;
block|}
end_block

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|errfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Error is called for  * semantic errors and  * prints the error and  * a line number.  */
end_comment

begin_macro
name|error
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|,
argument|a4
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|PI
name|char
name|buf
index|[
literal|256
index|]
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PXP
comment|/* 	int ofout; */
endif|#
directive|endif
if|if
condition|(
name|errpfx
operator|==
literal|'w'
operator|&&
name|opt
argument_list|(
literal|'w'
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|errpfx
operator|==
literal|'E'
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|PXP
comment|/* 	flush(); 	ofout = fout[0]; 	fout[0] = errout; */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PI
name|Enocascade
operator|=
literal|0
expr_stmt|;
name|geterr
argument_list|(
name|a1
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|a1
operator|=
name|buf
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|line
operator|<
literal|0
condition|)
name|line
operator|=
operator|-
name|line
expr_stmt|;
name|yySsync
argument_list|()
expr_stmt|;
name|yysetfile
argument_list|(
name|filename
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PI
if|if
condition|(
name|errpfx
operator|==
literal|' '
condition|)
block|{
name|printf
argument_list|(
literal|"  "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|line
init|;
name|i
operator|>=
literal|10
condition|;
name|i
operator|/=
literal|10
control|)
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"... "
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|Enoline
condition|)
name|printf
argument_list|(
literal|"  %c - "
argument_list|,
name|errpfx
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%c %d - "
argument_list|,
name|errpfx
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|)
expr_stmt|;
if|if
condition|(
name|errpfx
operator|==
literal|'E'
condition|)
ifdef|#
directive|ifdef
name|PI
name|eflg
operator|++
operator|,
name|cgenflg
operator|++
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PXP
name|eflg
operator|++
expr_stmt|;
endif|#
directive|endif
name|errpfx
operator|=
literal|'E'
expr_stmt|;
ifdef|#
directive|ifdef
name|PI
if|if
condition|(
name|Eholdnl
condition|)
name|Eholdnl
operator|=
literal|0
expr_stmt|;
else|else
endif|#
directive|endif
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PXP
comment|/* 	flush(); 	fout[0] = ofout; */
endif|#
directive|endif
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|PI
end_ifdef

begin_macro
name|cerror
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|,
argument|a4
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|Enocascade
condition|)
return|return;
name|setpfx
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|error
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

