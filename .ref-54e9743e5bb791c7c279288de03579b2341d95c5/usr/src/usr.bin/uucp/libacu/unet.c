begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)unet.c	8.1 (Berkeley) %G%"
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
file|"condevs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNETTCP
end_ifdef

begin_comment
comment|/*  *	unetopn -- make UNET (tcp-ip) connection  *  *	return codes:  *>0 - file number - ok  *		FAIL - failed  */
end_comment

begin_comment
comment|/* Default port of uucico server */
end_comment

begin_define
define|#
directive|define
name|DFLTPORT
value|33
end_define

begin_expr_stmt
name|unetopn
argument_list|(
name|flds
argument_list|)
specifier|register
name|char
operator|*
name|flds
index|[]
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|ret
decl_stmt|,
name|port
decl_stmt|;
name|int
name|unetcls
parameter_list|()
function_decl|;
name|port
operator|=
name|atoi
argument_list|(
name|flds
index|[
name|F_PHONE
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|port
operator|<=
literal|0
operator|||
name|port
operator|>
literal|255
condition|)
name|port
operator|=
name|DFLTPORT
expr_stmt|;
name|DEBUG
argument_list|(
literal|4
argument_list|,
literal|"unetopn host %s, "
argument_list|,
name|flds
index|[
name|F_NAME
index|]
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
literal|4
argument_list|,
literal|"port %d\n"
argument_list|,
name|port
argument_list|)
expr_stmt|;
if|if
condition|(
name|setjmp
argument_list|(
name|Sjbuf
argument_list|)
condition|)
block|{
name|logent
argument_list|(
literal|"tcpopen"
argument_list|,
literal|"TIMEOUT"
argument_list|)
expr_stmt|;
name|endhnent
argument_list|()
expr_stmt|;
comment|/* see below */
return|return
name|CF_DIAL
return|;
block|}
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|alarmtr
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|ret
operator|=
name|tcpopen
argument_list|(
name|flds
index|[
name|F_NAME
index|]
argument_list|,
name|port
argument_list|,
literal|0
argument_list|,
name|TO_ACTIVE
argument_list|,
literal|"rw"
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|endhnent
argument_list|()
expr_stmt|;
comment|/* wave magic wand at 3com and incant "eat it, bruce" */
if|if
condition|(
name|ret
operator|<
literal|0
condition|)
block|{
name|DEBUG
argument_list|(
literal|5
argument_list|,
literal|"tcpopen failed: errno %d\n"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
name|logent
argument_list|(
literal|"tcpopen"
argument_list|,
name|_FAILED
argument_list|)
expr_stmt|;
return|return
name|CF_DIAL
return|;
block|}
name|CU_end
operator|=
name|unetcls
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

begin_comment
comment|/*  * unetcls -- close UNET connection.  */
end_comment

begin_expr_stmt
name|unetcls
argument_list|(
name|fd
argument_list|)
specifier|register
name|int
name|fd
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|DEBUG
argument_list|(
literal|4
argument_list|,
literal|"UNET CLOSE called\n"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|>
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|notdef
comment|/* disable this until a timeout is put in */
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|UIOCCLOSE
argument_list|,
name|STBNULL
argument_list|)
condition|)
name|logent
argument_list|(
literal|"UNET CLOSE"
argument_list|,
name|_FAILED
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|notdef
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|DEBUG
argument_list|(
literal|4
argument_list|,
literal|"closed fd %d\n"
argument_list|,
name|fd
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
endif|UNETTCP
end_endif

end_unit

