begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/* (c) Copyright Tai Jin, 1988.  All Rights Reserved.                    */
end_comment

begin_comment
comment|/*     Hewlett-Packard Laboratories.                                     */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/* Permission is hereby granted for unlimited modification, use, and     */
end_comment

begin_comment
comment|/* distribution.  This software is made available with no warranty of    */
end_comment

begin_comment
comment|/* any kind, express or implied.  This copyright notice must remain      */
end_comment

begin_comment
comment|/* intact in all versions of this software.                              */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/* The author would appreciate it if any bug fixes and enhancements were */
end_comment

begin_comment
comment|/* to be sent back to him for incorporation into future versions of this */
end_comment

begin_comment
comment|/* software.  Please send changes to tai@iag.hp.com or ken@sdd.hp.com.   */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|RCSid
index|[]
init|=
literal|"adjtime.c,v 3.1 1993/07/06 01:04:42 jbj Exp"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<sys/msg.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"adjtime.h"
end_include

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|x
parameter_list|)
value|((x)< 0 ? -(x) : (x))
end_define

begin_decl_stmt
specifier|static
name|LONG
name|adjthresh
init|=
literal|400L
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|LONG
name|saveup
decl_stmt|;
end_decl_stmt

begin_macro
name|_clear_adjtime
argument_list|()
end_macro

begin_block
block|{
name|saveup
operator|=
literal|0L
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|adjtime
argument_list|(
name|delta
argument_list|,
name|olddelta
argument_list|)
specifier|register
expr|struct
name|timeval
operator|*
name|delta
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|struct
name|timeval
modifier|*
name|olddelta
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|timeval
name|newdelta
decl_stmt|;
comment|/* If they are giving us seconds, ignore up to current threshold saved */
if|if
condition|(
name|delta
operator|->
name|tv_sec
condition|)
block|{
name|saveup
operator|=
literal|0L
expr_stmt|;
return|return
operator|(
name|_adjtime
argument_list|(
name|delta
argument_list|,
name|olddelta
argument_list|)
operator|)
return|;
block|}
comment|/* add in, needs check for overflow ? */
name|saveup
operator|+=
name|delta
operator|->
name|tv_usec
expr_stmt|;
comment|/* Broke the threshold, call adjtime() */
if|if
condition|(
name|abs
argument_list|(
name|saveup
argument_list|)
operator|>
name|adjthresh
condition|)
block|{
name|newdelta
operator|.
name|tv_sec
operator|=
literal|0L
expr_stmt|;
name|newdelta
operator|.
name|tv_usec
operator|=
name|saveup
expr_stmt|;
name|saveup
operator|=
literal|0L
expr_stmt|;
return|return
operator|(
name|_adjtime
argument_list|(
operator|&
name|newdelta
argument_list|,
name|olddelta
argument_list|)
operator|)
return|;
block|}
if|if
condition|(
name|olddelta
condition|)
name|olddelta
operator|->
name|tv_sec
operator|=
name|olddelta
operator|->
name|tv_usec
operator|=
literal|0L
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|_adjtime
argument_list|(
name|delta
argument_list|,
name|olddelta
argument_list|)
specifier|register
expr|struct
name|timeval
operator|*
name|delta
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|struct
name|timeval
modifier|*
name|olddelta
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|mqid
decl_stmt|;
name|MsgBuf
name|msg
decl_stmt|;
specifier|register
name|MsgBuf
modifier|*
name|msgp
init|=
operator|&
name|msg
decl_stmt|;
comment|/*      * get the key to the adjtime message queue      * (note that we must get it every time because the queue might have been      *  removed and recreated)      */
if|if
condition|(
operator|(
name|mqid
operator|=
name|msgget
argument_list|(
name|KEY
argument_list|,
literal|0
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|msgp
operator|->
name|msgb
operator|.
name|mtype
operator|=
name|CLIENT
expr_stmt|;
name|msgp
operator|->
name|msgb
operator|.
name|tv
operator|=
operator|*
name|delta
expr_stmt|;
if|if
condition|(
name|olddelta
condition|)
name|msgp
operator|->
name|msgb
operator|.
name|code
operator|=
name|DELTA2
expr_stmt|;
else|else
name|msgp
operator|->
name|msgb
operator|.
name|code
operator|=
name|DELTA1
expr_stmt|;
if|if
condition|(
name|msgsnd
argument_list|(
name|mqid
argument_list|,
operator|&
name|msgp
operator|->
name|msgp
argument_list|,
name|MSGSIZE
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|olddelta
condition|)
block|{
if|if
condition|(
name|msgrcv
argument_list|(
name|mqid
argument_list|,
operator|&
name|msgp
operator|->
name|msgp
argument_list|,
name|MSGSIZE
argument_list|,
name|SERVER
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|olddelta
operator|=
name|msgp
operator|->
name|msgb
operator|.
name|tv
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

