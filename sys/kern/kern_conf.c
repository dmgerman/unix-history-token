begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Parts Copyright (c) 1995 Terrence R. Lambert  * Copyright (c) 1995 Julian R. Elischer  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY Julian R. Elischer ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: kern_conf.c,v 1.8 1995/12/21 20:09:39 julian Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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
comment|/*  * Routine to determine if a device is a disk.  *  * KLUDGE XXX add flags to cdevsw entries for disks XXX  * A minimal stub routine can always return 0.  */
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
name|struct
name|bdevsw
modifier|*
name|bd
decl_stmt|;
name|struct
name|cdevsw
modifier|*
name|cd
decl_stmt|;
if|if
condition|(
name|cd
operator|=
name|cdevsw
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
condition|)
block|{
if|if
condition|(
operator|(
name|bd
operator|=
name|cd
operator|->
name|d_bdev
operator|)
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
block|}
return|return
operator|(
name|NODEV
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * (re)place an entry in the bdevsw or cdevsw table  * return the slot used in major(*descrip)  */
end_comment

begin_define
define|#
directive|define
name|ADDENTRY
parameter_list|(
name|TTYPE
parameter_list|,
name|NXXXDEV
parameter_list|)
define|\
value|int TTYPE##_add(dev_t *descrip,						\ 		struct TTYPE *newentry,					\ 		struct TTYPE **oldentry)				\ {									\ 	int i ;								\ 	if ( (int)*descrip == -1) {
comment|/* auto (0 is valid) */
value|\
comment|/*							\ 		 * Search the table looking for a slot...		\ 		 */
value|\ 		for (i = 0; i< NXXXDEV; i++)				\ 			if (TTYPE[i] == NULL)				\ 				break;
comment|/* found one! */
value|\
comment|/* out of allocable slots? */
value|\ 		if (i == NXXXDEV) {					\ 			return ENFILE;					\ 		}							\ 	} else {
comment|/* assign */
value|\ 		i = major(*descrip);					\ 		if (i< 0 || i>= NXXXDEV) {				\ 			return EINVAL;					\ 		}							\ 	}								\ 									\
comment|/* maybe save old */
value|\         if (oldentry) {							\ 		*oldentry = TTYPE[i];					\ 	}								\ 	newentry->d_maj = i;						\
comment|/* replace with new */
value|\ 	TTYPE[i] = newentry;						\ 									\
comment|/* done!  let them know where we put it */
value|\ 	*descrip = makedev(i,0);					\ 	return 0;							\ } \  ADDENTRY(bdevsw, nblkdev)
end_define

begin_macro
name|ADDENTRY
argument_list|(
argument|cdevsw
argument_list|,
argument|nchrdev
argument_list|)
end_macro

end_unit

