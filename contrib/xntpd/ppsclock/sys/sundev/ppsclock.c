begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"@(#) $Header: ppsclock.c,v 1.5 92/08/20 19:46:35 leres Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66.  *  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  * 4. The name of the University may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* ppsclock streams module */
end_comment

begin_define
define|#
directive|define
name|PPSCLOCKLED
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/stream.h>
end_include

begin_include
include|#
directive|include
file|<sys/stropts.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/ttycom.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/ppsclock.h>
end_include

begin_include
include|#
directive|include
file|<sundev/zsreg.h>
end_include

begin_include
include|#
directive|include
file|<sundev/zscom.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PPSCLOCKLED
end_ifdef

begin_include
include|#
directive|include
file|<sun4c/auxio.h>
end_include

begin_comment
comment|/* In case these aren't defined by auxio.h */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LED_ON
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LED_OFF
argument_list|)
end_if

begin_define
define|#
directive|define
name|LED_ON
value|*(u_char *)AUXIO_REG = AUX_MBO|AUX_EJECT|AUX_LED
end_define

begin_define
define|#
directive|define
name|LED_OFF
value|*(u_char *)AUXIO_REG = AUX_MBO|AUX_EJECT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ppsclockled
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ppsclock_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppsclock_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppsclock_wput
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ppsclock_intr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|module_info
name|stm_info
init|=
block|{
literal|0x434c
block|,
comment|/* module id number (??) */
name|PPSCLOCKSTR
block|,
comment|/* module name */
literal|0
block|,
comment|/* minimum packet size */
name|INFPSZ
block|,
comment|/* infinite maximum packet size */
name|STRHIGH
block|,
comment|/* hi-water mark */
name|STRLOW
block|,
comment|/* lo-water mark */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|qinit
name|ppsclock_rinit
init|=
block|{
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|ppsclock_wput
block|,
comment|/* put procedure */
name|NULL
block|,
comment|/* service procedure */
name|ppsclock_open
block|,
comment|/* called on startup */
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|ppsclock_close
block|,
comment|/* called on finish */
name|NULL
block|,
comment|/* for 3bnet only */
operator|&
name|stm_info
block|,
comment|/* module information structure */
name|NULL
comment|/* module statistics structure */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|qinit
name|ppsclock_winit
init|=
block|{
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|ppsclock_wput
block|,
comment|/* put procedure */
name|NULL
block|,
comment|/* service procedure */
name|ppsclock_open
block|,
comment|/* called on startup */
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|ppsclock_close
block|,
comment|/* called on finish */
name|NULL
block|,
comment|/* for 3bnet only */
operator|&
name|stm_info
block|,
comment|/* module information structure */
name|NULL
comment|/* module statistics structure */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|streamtab
name|ppsclockinfo
init|=
block|{
operator|&
name|ppsclock_rinit
block|,
comment|/* qinit for read side */
operator|&
name|ppsclock_winit
block|,
comment|/* qinit for write side */
name|NULL
block|,
comment|/* mux qinit for read */
name|NULL
block|,
comment|/* mux qinit for write */
name|NULL
comment|/* list of modules to be pushed */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ppsclockev
name|ppsclockev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|zsops
modifier|*
name|ppssavedzsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|zsops
name|ppszsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|zscom
modifier|*
name|ppssavedzscom
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OPENPROMS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|zsaline
modifier|*
name|zsaline
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|struct
name|zsaline
name|zsaline
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PPS_SYNC
end_ifdef

begin_comment
comment|/*  * The hardpps() routine is called at every pps interrupt in order to  * discipline the cpu clock oscillator. It requires corresponding kernel  * support.  */
end_comment

begin_extern
extern|extern hardpps(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* pps signal processor */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the real kernel time */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPS_SYNC */
end_comment

begin_comment
comment|/*  * open CLOCK STREAMS module  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|ppsclock_open
parameter_list|(
name|q
parameter_list|,
name|dev
parameter_list|,
name|flag
parameter_list|,
name|sflag
parameter_list|)
specifier|register
name|queue_t
modifier|*
name|q
decl_stmt|;
specifier|register
name|dev_t
name|dev
decl_stmt|;
specifier|register
name|int
name|flag
decl_stmt|;
specifier|register
name|int
name|sflag
decl_stmt|;
block|{
specifier|register
name|struct
name|zsaline
modifier|*
name|za
decl_stmt|;
specifier|register
name|struct
name|zscom
modifier|*
name|zs
decl_stmt|;
comment|/* We must be called with MODOPEN. */
if|if
condition|(
name|sflag
operator|!=
name|MODOPEN
condition|)
return|return
operator|(
name|OPENFAIL
operator|)
return|;
comment|/* Hook up our external status interrupt handler */
if|if
condition|(
name|ppssavedzsops
operator|==
name|NULL
condition|)
block|{
name|za
operator|=
operator|&
name|zsaline
index|[
name|minor
argument_list|(
name|dev
argument_list|)
operator|&
literal|0x7f
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|zs
operator|=
name|za
operator|->
name|za_common
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|OPENFAIL
operator|)
return|;
name|ppssavedzsops
operator|=
name|zs
operator|->
name|zs_ops
expr_stmt|;
name|ppszsops
operator|=
operator|*
name|ppssavedzsops
expr_stmt|;
name|ppszsops
operator|.
name|zsop_xsint
operator|=
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|ppsclock_intr
expr_stmt|;
name|zsopinit
argument_list|(
name|zs
argument_list|,
operator|&
name|ppszsops
argument_list|)
expr_stmt|;
name|ppssavedzscom
operator|=
name|zs
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ppsclock_close
parameter_list|(
name|q
parameter_list|)
specifier|register
name|queue_t
modifier|*
name|q
decl_stmt|;
block|{
comment|/* Flush outstanding packets */
name|flushq
argument_list|(
name|WR
argument_list|(
name|q
argument_list|)
argument_list|,
name|FLUSHALL
argument_list|)
expr_stmt|;
comment|/* Unhook our external status interrupt handler */
if|if
condition|(
name|ppssavedzsops
condition|)
block|{
name|zsopinit
argument_list|(
name|ppssavedzscom
argument_list|,
name|ppssavedzsops
argument_list|)
expr_stmt|;
name|ppssavedzscom
operator|=
name|NULL
expr_stmt|;
name|ppssavedzsops
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Read and write put procedure. Note that we can only get ioctl  * messages in the "write" case.  */
end_comment

begin_function
name|void
name|ppsclock_wput
parameter_list|(
name|q
parameter_list|,
name|mp
parameter_list|)
specifier|register
name|queue_t
modifier|*
name|q
decl_stmt|;
specifier|register
name|mblk_t
modifier|*
name|mp
decl_stmt|;
block|{
specifier|register
name|struct
name|iocblk
modifier|*
name|iocp
decl_stmt|;
specifier|register
name|mblk_t
modifier|*
name|datap
decl_stmt|;
switch|switch
condition|(
name|mp
operator|->
name|b_datap
operator|->
name|db_type
condition|)
block|{
case|case
name|M_FLUSH
case|:
if|if
condition|(
operator|*
name|mp
operator|->
name|b_rptr
operator|&
name|FLUSHW
condition|)
name|flushq
argument_list|(
name|q
argument_list|,
name|FLUSHDATA
argument_list|)
expr_stmt|;
name|putnext
argument_list|(
name|q
argument_list|,
name|mp
argument_list|)
expr_stmt|;
break|break;
case|case
name|M_IOCTL
case|:
name|iocp
operator|=
operator|(
expr|struct
name|iocblk
operator|*
operator|)
name|mp
operator|->
name|b_rptr
expr_stmt|;
if|if
condition|(
name|iocp
operator|->
name|ioc_cmd
operator|==
name|CIOGETEV
condition|)
block|{
name|datap
operator|=
name|allocb
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ppsclockev
argument_list|)
argument_list|,
name|BPRI_HI
argument_list|)
expr_stmt|;
if|if
condition|(
name|datap
operator|==
name|NULL
condition|)
block|{
name|mp
operator|->
name|b_datap
operator|->
name|db_type
operator|=
name|M_IOCNAK
expr_stmt|;
name|iocp
operator|->
name|ioc_error
operator|=
name|ENOMEM
expr_stmt|;
name|qreply
argument_list|(
name|q
argument_list|,
name|mp
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|mp
operator|->
name|b_cont
condition|)
name|panic
argument_list|(
literal|"ppsclock b_cont not null"
argument_list|)
expr_stmt|;
name|mp
operator|->
name|b_cont
operator|=
name|datap
expr_stmt|;
operator|*
operator|(
expr|struct
name|ppsclockev
operator|*
operator|)
name|datap
operator|->
name|b_wptr
operator|=
name|ppsclockev
expr_stmt|;
name|datap
operator|->
name|b_wptr
operator|+=
sizeof|sizeof
argument_list|(
expr|struct
name|ppsclockev
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
operator|*
name|datap
operator|->
name|b_wptr
argument_list|)
expr_stmt|;
name|mp
operator|->
name|b_datap
operator|->
name|db_type
operator|=
name|M_IOCACK
expr_stmt|;
name|iocp
operator|->
name|ioc_count
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|ppsclockev
argument_list|)
expr_stmt|;
name|qreply
argument_list|(
name|q
argument_list|,
name|mp
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* fall through */
default|default:
name|putnext
argument_list|(
name|q
argument_list|,
name|mp
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|ppsclock_intr
parameter_list|(
name|zs
parameter_list|)
specifier|register
name|struct
name|zscom
modifier|*
name|zs
decl_stmt|;
block|{
specifier|register
name|struct
name|zsaline
modifier|*
name|za
init|=
operator|(
expr|struct
name|zsaline
operator|*
operator|)
name|zs
operator|->
name|zs_priv
decl_stmt|;
specifier|register
name|struct
name|zscc_device
modifier|*
name|zsaddr
init|=
name|zs
operator|->
name|zs_addr
decl_stmt|;
specifier|register
name|u_char
name|s0
decl_stmt|;
specifier|register
name|struct
name|timeval
modifier|*
name|tvp
init|=
operator|&
name|ppsclockev
operator|.
name|tv
decl_stmt|;
ifdef|#
directive|ifdef
name|PPS_SYNC
name|long
name|usec
decl_stmt|;
endif|#
directive|endif
comment|/* PPS_SYNC */
comment|/* 	 * This code captures a timestamp at the designated transition of 	 * the PPS signal. If the PPS_SYNC option has been configured in 	 * the kernel, the code provides a pointer to the timestamp, as 	 * well as the hardware counter value at the capture. 	 */
name|s0
operator|=
name|zsaddr
operator|->
name|zscc_control
expr_stmt|;
if|if
condition|(
operator|(
name|s0
operator|^
name|za
operator|->
name|za_rr0
operator|)
operator|&
name|ZSRR0_CD
condition|)
block|{
if|if
condition|(
operator|(
name|s0
operator|&
name|ZSRR0_CD
operator|)
operator|!=
literal|0
condition|)
block|{
ifdef|#
directive|ifdef
name|PPS_SYNC
name|usec
operator|=
name|time
operator|.
name|tv_usec
expr_stmt|;
endif|#
directive|endif
comment|/* PPS_SYNC */
ifdef|#
directive|ifdef
name|PPSCLOCKLED
if|if
condition|(
name|ppsclockled
condition|)
block|{
name|LED_OFF
expr_stmt|;
name|uniqtime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
name|LED_ON
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|/* PPSCLOCKLED */
name|uniqtime
argument_list|(
name|tvp
argument_list|)
expr_stmt|;
operator|++
name|ppsclockev
operator|.
name|serial
expr_stmt|;
ifdef|#
directive|ifdef
name|PPS_SYNC
name|usec
operator|=
name|tvp
operator|->
name|tv_usec
operator|-
name|usec
expr_stmt|;
if|if
condition|(
name|usec
operator|<
literal|0
condition|)
name|usec
operator|+=
literal|1000000
expr_stmt|;
name|hardpps
argument_list|(
name|tvp
argument_list|,
name|usec
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* PPS_SYNC */
block|}
name|za
operator|->
name|za_rr0
operator|=
name|s0
expr_stmt|;
name|zsaddr
operator|->
name|zscc_control
operator|=
name|ZSWR0_RESET_STATUS
expr_stmt|;
return|return;
block|}
comment|/* Call real external status interrupt routine */
call|(
name|void
call|)
argument_list|(
operator|*
name|ppssavedzsops
operator|->
name|zsop_xsint
argument_list|)
argument_list|(
name|zs
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

