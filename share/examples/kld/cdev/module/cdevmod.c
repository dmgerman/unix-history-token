begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 08 Nov 1998*/
end_comment

begin_comment
comment|/*  * cdevmod.c - a sample kld module implementing a character device driver.  *  * 08 Nov 1998  Rajesh Vaidheeswarran  *  * Copyright (c) 1998 Rajesh Vaidheeswarran  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Rajesh Vaidheeswarran.  * 4. The name Rajesh Vaidheeswarran may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY RAJESH VAIDHEESWARRAN ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE RAJESH VAIDHEESWARRAN BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1993 Terrence R. Lambert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY TERRENCE R. LAMBERT ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|"cdev.h"
end_include

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|32
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|my_devsw
init|=
block|{
comment|/* open */
name|mydev_open
block|,
comment|/* close */
name|mydev_close
block|,
comment|/* read */
name|mydev_read
block|,
comment|/* write */
name|mydev_write
block|,
comment|/* ioctl */
name|mydev_ioctl
block|,
comment|/* poll */
name|nopoll
block|,
comment|/* mmap */
name|nommap
block|,
comment|/* strategy */
name|nostrategy
block|,
comment|/* name */
literal|"cdev"
block|,
comment|/* maj */
name|CDEV_MAJOR
block|,
comment|/* dump */
name|nodump
block|,
comment|/* psize */
name|nopsize
block|,
comment|/* flags */
name|D_TTY
block|,
comment|/* bmaj */
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Used as the variable that is the reference to our device  * in devfs... we must keep this variable sane until we   * call kldunload.  */
end_comment

begin_decl_stmt
specifier|static
name|dev_t
name|sdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This function is called each time the module is loaded or unloaded.  * Since we are a miscellaneous module, we have to provide whatever  * code is necessary to patch ourselves into the area we are being  * loaded to change.  *  * The stat information is basically common to all modules, so there  * is no real issue involved with stat; we will leave it lkm_nullcmd(),  * since we don't have to do anything about it.  */
end_comment

begin_function
specifier|static
name|int
name|cdev_load
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|MOD_LOAD
case|:
comment|/* Do any initialization that you should do with the kernel */
comment|/* if we make it to here, print copyright on console*/
name|printf
argument_list|(
literal|"\nSample Loaded kld character device driver\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Copyright (c) 1998\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Rajesh Vaidheeswarran\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"All rights reserved\n"
argument_list|)
expr_stmt|;
name|sdev
operator|=
name|make_dev
argument_list|(
operator|&
name|my_devsw
argument_list|,
literal|0
argument_list|,
name|UID_ROOT
argument_list|,
name|GID_WHEEL
argument_list|,
literal|0600
argument_list|,
literal|"cdev"
argument_list|)
expr_stmt|;
break|break;
comment|/* Success*/
case|case
name|MOD_UNLOAD
case|:
name|printf
argument_list|(
literal|"Unloaded kld character device driver\n"
argument_list|)
expr_stmt|;
name|destroy_dev
argument_list|(
name|sdev
argument_list|)
expr_stmt|;
break|break;
comment|/* Success*/
default|default:
comment|/* we only understand load/unload*/
name|err
operator|=
name|EINVAL
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Now declare the module to the system */
end_comment

begin_expr_stmt
name|DEV_MODULE
argument_list|(
name|cdev
argument_list|,
name|cdev_load
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

