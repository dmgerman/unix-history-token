begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)setline.c	5.3 (Berkeley) 6/20/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PACKSIZE
value|64
end_define

begin_define
define|#
directive|define
name|SNDFILE
value|'S'
end_define

begin_define
define|#
directive|define
name|RCVFILE
value|'R'
end_define

begin_define
define|#
directive|define
name|RESET
value|'X'
end_define

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  *	optimize line setting for sending or receiving files  *  *	return code - none  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|setupline
argument_list|(
argument|type
argument_list|)
end_macro

begin_decl_stmt
name|char
name|type
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|USG
specifier|static
name|struct
name|termio
name|tbuf
decl_stmt|,
name|sbuf
decl_stmt|;
specifier|static
name|int
name|set
init|=
literal|0
decl_stmt|;
name|DEBUG
argument_list|(
literal|2
argument_list|,
literal|"setline - %c\n"
argument_list|,
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|IsTcpIp
condition|)
return|return;
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|SNDFILE
case|:
break|break;
case|case
name|RCVFILE
case|:
name|ioctl
argument_list|(
name|Ifn
argument_list|,
name|TCGETA
argument_list|,
operator|&
name|tbuf
argument_list|)
expr_stmt|;
name|sbuf
operator|=
name|tbuf
expr_stmt|;
name|tbuf
operator|.
name|c_cc
index|[
name|VMIN
index|]
operator|=
name|PACKSIZE
expr_stmt|;
name|ioctl
argument_list|(
name|Ifn
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|tbuf
argument_list|)
expr_stmt|;
name|set
operator|++
expr_stmt|;
break|break;
case|case
name|RESET
case|:
if|if
condition|(
name|set
operator|==
literal|0
condition|)
break|break;
name|set
operator|=
literal|0
expr_stmt|;
name|ioctl
argument_list|(
name|Ifn
argument_list|,
name|TCSETAW
argument_list|,
operator|&
name|sbuf
argument_list|)
expr_stmt|;
break|break;
block|}
endif|#
directive|endif
block|}
end_block

end_unit

