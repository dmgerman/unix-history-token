begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_HPUX_ADJTIME
end_ifdef

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

begin_comment
comment|/*  * Revision history  *  * 9 Jul 94	David L. Mills, Unibergity of Delabunch  *		Implemented variable threshold to limit age of  *		corrections; reformatted code for readability.  */
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

begin_comment
comment|/*  * The following paramters are appropriate for an NTP adjustment  * interval of one second.  */
end_comment

begin_define
define|#
directive|define
name|ADJ_THRESH
value|200
end_define

begin_comment
comment|/* initial threshold */
end_comment

begin_define
define|#
directive|define
name|ADJ_DELTA
value|4
end_define

begin_comment
comment|/* threshold decrement */
end_comment

begin_decl_stmt
specifier|static
name|long
name|adjthresh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* adjustment threshold */
end_comment

begin_decl_stmt
specifier|static
name|long
name|saveup
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* corrections accumulator */
end_comment

begin_comment
comment|/*  * clear_adjtime - reset accumulator and threshold variables  */
end_comment

begin_function
name|void
name|_clear_adjtime
parameter_list|(
name|void
parameter_list|)
block|{
name|saveup
operator|=
literal|0
expr_stmt|;
name|adjthresh
operator|=
name|ADJ_THRESH
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * adjtime - hp-ux copout of the standard Unix adjtime() system call  */
end_comment

begin_function
name|int
name|adjtime
parameter_list|(
specifier|register
name|struct
name|timeval
modifier|*
name|delta
parameter_list|,
specifier|register
name|struct
name|timeval
modifier|*
name|olddelta
parameter_list|)
block|{
name|struct
name|timeval
name|newdelta
decl_stmt|;
comment|/* 	 * Corrections greater than one second are done immediately. 	 */
if|if
condition|(
name|delta
operator|->
name|tv_sec
condition|)
block|{
name|adjthresh
operator|=
name|ADJ_THRESH
expr_stmt|;
name|saveup
operator|=
literal|0
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
comment|/* 	 * Corrections less than one second are accumulated until 	 * tripping a threshold, which is initially set at ADJ_THESH and 	 * reduced in ADJ_DELTA steps to zero. The idea here is to 	 * introduce large corrections quickly, while making sure that 	 * small corrections are introduced without excessive delay. The 	 * idea comes from the ARPAnet routing update algorithm. 	 */
name|saveup
operator|+=
name|delta
operator|->
name|tv_usec
expr_stmt|;
if|if
condition|(
name|abs
argument_list|(
name|saveup
argument_list|)
operator|>=
name|adjthresh
condition|)
block|{
name|adjthresh
operator|=
name|ADJ_THRESH
expr_stmt|;
name|newdelta
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|newdelta
operator|.
name|tv_usec
operator|=
name|saveup
expr_stmt|;
name|saveup
operator|=
literal|0
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
else|else
block|{
name|adjthresh
operator|-=
name|ADJ_DELTA
expr_stmt|;
block|}
comment|/* 	 * While nobody uses it, return the residual before correction, 	 * as per Unix convention. 	 */
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
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * _adjtime - does the actual work  */
end_comment

begin_function
name|int
name|_adjtime
parameter_list|(
specifier|register
name|struct
name|timeval
modifier|*
name|delta
parameter_list|,
specifier|register
name|struct
name|timeval
modifier|*
name|olddelta
parameter_list|)
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
comment|/* 	 * Get the key to the adjtime message queue (note that we must 	 * get it every time because the queue might have been removed 	 * and recreated) 	 */
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
comment|/* 	 * Tickle adjtimed and snatch residual, if indicated. Lots of 	 * fanatic error checking here. 	 */
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
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not NEED_HPUX_ADJTIME */
end_comment

begin_decl_stmt
name|int
name|adjtime_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NEED_HPUX_ADJTIME */
end_comment

end_unit

