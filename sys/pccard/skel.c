begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Loadable kernel module skeleton driver  * 11 July 1995 Andrew McRae  *  *-------------------------------------------------------------------------  *  * Copyright (c) 1995 Andrew McRae.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<pccard/card.h>
end_include

begin_include
include|#
directive|include
file|<pccard/driver.h>
end_include

begin_include
include|#
directive|include
file|<pccard/slot.h>
end_include

begin_comment
comment|/*  *	This defines the lkm_misc module use by modload  *	to define the module name.  */
end_comment

begin_macro
name|MOD_MISC
argument_list|(
literal|"skel"
argument_list|)
end_macro

begin_function_decl
specifier|static
name|int
name|skelinit
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* init device */
end_comment

begin_function_decl
specifier|static
name|void
name|skelunload
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disable driver */
end_comment

begin_function_decl
specifier|static
name|int
name|skelintr
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Interrupt handler */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|pccard_device
name|skel_info
init|=
block|{
literal|"skel"
block|,
name|skelinit
block|,
name|skelunload
block|,
name|skelintr
block|,
literal|0
block|,
comment|/* Attributes - presently unused */
operator|&
name|net_imask
comment|/* Interrupt mask for device */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|opened
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rather minimal device state... */
end_comment

begin_comment
comment|/*  *	Module handler that processes loads and unloads.  *	Once the module is loaded, the add driver routine is called  *	to register the driver.  *	If an unload is requested the remove driver routine is  *	called to deregister the driver before unloading.  */
end_comment

begin_function
specifier|static
name|int
name|skel_handle
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|struct
name|lkm_misc
modifier|*
name|args
init|=
name|lkmtp
operator|->
name|private
operator|.
name|lkm_misc
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
comment|/* default = success*/
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|LKM_E_LOAD
case|:
comment|/* 		 * Don't load twice! (lkmexists() is exported by kern_lkm.c) 		 */
if|if
condition|(
name|lkmexists
argument_list|(
name|lkmtp
argument_list|)
condition|)
return|return
operator|(
name|EEXIST
operator|)
return|;
comment|/*  *	Now register the driver  */
name|pccard_add_driver
argument_list|(
operator|&
name|skel_info
argument_list|)
expr_stmt|;
break|break;
comment|/* Success*/
comment|/*  *	Attempt to deregister the driver.  */
case|case
name|LKM_E_UNLOAD
case|:
name|pccard_remove_driver
argument_list|(
operator|&
name|skel_info
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
comment|/*  * External entry point; should generally match name of .o file.  The  * arguments are always the same for all loaded modules.  The "load",  * "unload", and "stat" functions in "DISPATCH" will be called under  * their respective circumstances unless their value is "nosys".  If  * called, they are called with the same arguments (cmd is included to  * allow the use of a single function, ver is included for version  * matching between modules and the kernel loader for the modules).  *  * Since we expect to link in the kernel and add external symbols to  * the kernel symbol name space in a future version, generally all  * functions used in the implementation of a particular module should  * be static unless they are expected to be seen in other modules or  * to resolve unresolved symbols alread existing in the kernel (the  * second case is not likely to ever occur).  *  * The entry point should return 0 unless it is refusing load (in which  * case it should return an errno from errno.h).  */
end_comment

begin_function
name|int
name|lkm_skel
parameter_list|(
name|lkmtp
parameter_list|,
name|cmd
parameter_list|,
name|ver
parameter_list|)
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|ver
decl_stmt|;
block|{
name|DISPATCH
argument_list|(
argument|lkmtp
argument_list|,
argument|cmd
argument_list|,
argument|ver
argument_list|,
argument|skel_handle
argument_list|,
argument|skel_handle
argument_list|,
argument|nosys
argument_list|)
block|}
end_function

begin_comment
comment|/*  *	Skeleton driver entry points for PCCARD configuration.  */
end_comment

begin_comment
comment|/*  *	Initialize the device.  */
end_comment

begin_function
specifier|static
name|int
name|skelinit
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
name|devi
parameter_list|)
block|{
if|if
condition|(
operator|(
literal|1
operator|<<
name|devi
operator|->
name|unit
operator|)
operator|&
name|opened
condition|)
return|return
operator|(
name|EBUSY
operator|)
return|;
name|opened
operator||=
literal|1
operator|<<
name|devi
operator|->
name|unit
expr_stmt|;
name|printf
argument_list|(
literal|"skel%d: init\n"
argument_list|,
name|devi
operator|->
name|unit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"iomem = 0x%x, iobase = 0x%x\n"
argument_list|,
name|devi
operator|->
name|memory
argument_list|,
name|devi
operator|->
name|ioaddr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *	The device entry is being removed. Shut it down,  *	and turn off interrupts etc. Not called unless  *	the device was successfully installed.  */
end_comment

begin_function
specifier|static
name|void
name|skelunload
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
name|devi
parameter_list|)
block|{
name|printf
argument_list|(
literal|"skel%d: unload\n"
argument_list|,
name|devi
operator|->
name|unit
argument_list|)
expr_stmt|;
name|opened
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|devi
operator|->
name|unit
operator|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  *	Interrupt handler.  *	Returns true if the interrupt is for us.  */
end_comment

begin_function
specifier|static
name|int
name|skelintr
parameter_list|(
name|struct
name|pccard_devinfo
modifier|*
name|devi
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

