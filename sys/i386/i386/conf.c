begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) UNIX System Laboratories, Inc.  All or some portions  * of this file are derived from material licensed to the  * University of California by American Telephone and Telegraph Co.  * or UNIX System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)conf.c	5.8 (Berkeley) 5/12/91  *	$Id: conf.c,v 1.115 1995/12/14 09:52:37 phk Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_define
define|#
directive|define
name|NUMCDEV
value|96
end_define

begin_define
define|#
directive|define
name|NUMBDEV
value|32
end_define

begin_decl_stmt
name|struct
name|bdevsw
modifier|*
name|bdevsw
index|[
name|NUMBDEV
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nblkdev
init|=
name|NUMBDEV
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cdevsw
modifier|*
name|cdevsw
index|[
name|NUMCDEV
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nchrdev
init|=
name|NUMCDEV
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The routines below are total "BULLSHIT" and will be trashed  */
end_comment

begin_comment
comment|/*  * Swapdev is a fake device implemented  * in sw.c used only internally to get to swstrategy.  * It cannot be provided to the users, because the  * swstrategy routine munches the b_dev and b_blkno entries  * before calling the appropriate driver.  This would horribly  * confuse, e.g. the hashing routines. Instead, /dev/drum is  * provided as a character (raw) device.  */
end_comment

begin_decl_stmt
name|dev_t
name|swapdev
init|=
name|makedev
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routine that identifies /dev/mem and /dev/kmem.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_function
name|int
name|iskmemdev
parameter_list|(
name|dev
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
block|{
return|return
operator|(
name|major
argument_list|(
name|dev
argument_list|)
operator|==
literal|2
operator|&&
operator|(
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|0
operator|||
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|iszerodev
parameter_list|(
name|dev
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
block|{
return|return
operator|(
name|major
argument_list|(
name|dev
argument_list|)
operator|==
literal|2
operator|&&
name|minor
argument_list|(
name|dev
argument_list|)
operator|==
literal|12
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Routine to determine if a device is a disk.  *  * A minimal stub routine can always return 0.  */
end_comment

begin_function
name|int
name|isdisk
parameter_list|(
name|dev
parameter_list|,
name|type
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|int
name|type
decl_stmt|;
block|{
switch|switch
condition|(
name|major
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|15
case|:
comment|/* VBLK: vn, VCHR: cd */
return|return
operator|(
literal|1
operator|)
return|;
case|case
literal|0
case|:
comment|/* wd */
case|case
literal|2
case|:
comment|/* fd */
case|case
literal|4
case|:
comment|/* sd */
case|case
literal|6
case|:
comment|/* cd */
case|case
literal|7
case|:
comment|/* mcd */
case|case
literal|16
case|:
comment|/* scd */
case|case
literal|17
case|:
comment|/* matcd */
case|case
literal|18
case|:
comment|/* ata */
case|case
literal|19
case|:
comment|/* wcd */
case|case
literal|20
case|:
comment|/* od */
if|if
condition|(
name|type
operator|==
name|VBLK
condition|)
return|return
operator|(
literal|1
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|3
case|:
comment|/* wd */
case|case
literal|9
case|:
comment|/* fd */
case|case
literal|13
case|:
comment|/* sd */
case|case
literal|29
case|:
comment|/* mcd */
case|case
literal|43
case|:
comment|/* vn */
case|case
literal|45
case|:
comment|/* scd */
case|case
literal|46
case|:
comment|/* matcd */
case|case
literal|69
case|:
comment|/* wcd */
case|case
literal|70
case|:
comment|/* od */
if|if
condition|(
name|type
operator|==
name|VCHR
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* fall through */
default|default:
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* NOTREACHED */
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|NEW_STUFF_JRE
end_ifndef

begin_comment
comment|/*  * Routine to convert from character to block device number.  *  * A minimal stub routine can always return NODEV.  */
end_comment

begin_function
name|dev_t
name|chrtoblk
parameter_list|(
name|dev
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
block|{
name|int
name|blkmaj
decl_stmt|;
switch|switch
condition|(
name|major
argument_list|(
name|dev
argument_list|)
condition|)
block|{
case|case
literal|3
case|:
name|blkmaj
operator|=
literal|0
expr_stmt|;
break|break;
comment|/* wd */
case|case
literal|9
case|:
name|blkmaj
operator|=
literal|2
expr_stmt|;
break|break;
comment|/* fd */
case|case
literal|10
case|:
name|blkmaj
operator|=
literal|3
expr_stmt|;
break|break;
comment|/* wt */
case|case
literal|13
case|:
name|blkmaj
operator|=
literal|4
expr_stmt|;
break|break;
comment|/* sd */
case|case
literal|14
case|:
name|blkmaj
operator|=
literal|5
expr_stmt|;
break|break;
comment|/* st */
case|case
literal|15
case|:
name|blkmaj
operator|=
literal|6
expr_stmt|;
break|break;
comment|/* cd */
case|case
literal|29
case|:
name|blkmaj
operator|=
literal|7
expr_stmt|;
break|break;
comment|/* mcd */
case|case
literal|43
case|:
name|blkmaj
operator|=
literal|15
expr_stmt|;
break|break;
comment|/* vn */
case|case
literal|45
case|:
name|blkmaj
operator|=
literal|16
expr_stmt|;
break|break;
comment|/* scd */
case|case
literal|46
case|:
name|blkmaj
operator|=
literal|17
expr_stmt|;
break|break;
comment|/* matcd */
case|case
literal|69
case|:
name|blkmaj
operator|=
literal|19
expr_stmt|;
break|break;
comment|/* wcd */
case|case
literal|70
case|:
name|blkmaj
operator|=
literal|20
expr_stmt|;
break|break;
comment|/* od */
default|default:
return|return
operator|(
name|NODEV
operator|)
return|;
block|}
return|return
operator|(
name|makedev
argument_list|(
name|blkmaj
argument_list|,
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NEW_STUFF_JRE */
end_comment

begin_comment
comment|/*===============================================*/
end_comment

begin_comment
comment|/*  * Routine to convert from character to block device number.  *  * A minimal stub routine can always return NODEV.  */
end_comment

begin_function
name|dev_t
name|chrtoblk
parameter_list|(
name|dev_t
name|dev
parameter_list|)
block|{
name|int
name|blkmaj
decl_stmt|;
name|struct
name|bdevsw
modifier|*
name|bd
decl_stmt|;
name|bd
operator|=
name|cdevsw
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
operator|->
name|d_bdev
expr_stmt|;
if|if
condition|(
name|bd
condition|)
return|return
operator|(
name|makedev
argument_list|(
name|bd
operator|->
name|d_maj
argument_list|,
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|NODEV
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEW_STUFF_JRE */
end_comment

end_unit

