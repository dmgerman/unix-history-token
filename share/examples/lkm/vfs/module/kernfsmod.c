begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 05 Jun 93*/
end_comment

begin_comment
comment|/*  * kernfsmod.c  *  * 05 Jun 93	Terry Lambert		Original  *  * Copyright (c) 1993 Terrence R. Lambert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Terrence R. Lambert.  * 4. The name Terrence R. Lambert may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY TERRENCE R. LAMBERT ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE TERRENCE R. LAMBERT BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_define
define|#
directive|define
name|printf
value|I_HATE_ANSI
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|printf
end_undef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
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
file|<sys/mount.h>
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
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_comment
comment|/*  * This is the vfsops table from /sys/miscfs/kernfs/kernfs_vfsops.c  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|kernfs_vfsops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Currently, the mount system call is broken in the way it operates  * and the vfssw[] table does not have a character string identifier  * for the file system type; therefore, to remount a file system after  * it has been mounted in the first place, the offset into the table  * must be the same; this will be corrected in future patches, but  * not right now.  At the same time the fstab format will need to  * change to allow definition without mount of file systems.  *  * The flags field is a parameter to the init; this could be used to  * change the file system operation: for instance, in ISOFS, this  * could be used to enable/disable Rockridge extensions.  */
end_comment

begin_macro
name|MOD_VFS
argument_list|(
literal|"kernfs"
argument_list|,
argument|MOUNT_KERNFS
argument_list|,
literal|0
argument_list|,
argument|&kernfs_vfsops
argument_list|)
end_macro

begin_comment
comment|/*  * This function is called each time the module is loaded.   Technically,  * we could have made this "nosys" in the "DISPATCH" in "kernfsmod()",  * but it's a convenient place to kick a copyright out to the console.  */
end_comment

begin_function
specifier|static
name|int
name|kernfsmod_load
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
if|if
condition|(
name|cmd
operator|==
name|LKM_E_LOAD
condition|)
block|{
comment|/* print copyright on console*/
name|printf
argument_list|(
literal|"\nSample Loaded file system\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Copyright (c) 1990, 1992 Jan-Simon Pendry\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"All rights reserved.\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nLoader stub and module loader is\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Copyright (c) 1993\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Terrence R. Lambert\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"All rights reserved\n"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * External entry point; should generally match name of .o file.  The  * arguments are always the same for all loaded modules.  The "load",  * "unload", and "stat" functions in "DISPATCH" will be called under  * their respective circumstances unless their value is "nosys".  If  * called, they are called with the same arguments (cmd is included to  * allow the use of a single function, ver is included for version  * matching between modules and the kernel loader for the modules).  *  * Since we expect to link in the kernel and add external symbols to  * the kernel symbol name space in a future version, generally all  * functions used in the implementation of a particular module should  * be static unless they are expected to be seen in other modules or  * to resolve unresolved symbols alread existing in the kernel (the  * second case is not likely to ever occur).  *  * The entry point should return 0 unless it is refusing load (in which  * case it should return an errno from errno.h).  */
end_comment

begin_macro
name|kernfsmod
argument_list|(
argument|lkmtp
argument_list|,
argument|cmd
argument_list|,
argument|ver
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|lkm_table
modifier|*
name|lkmtp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cmd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ver
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|DISPATCH
argument_list|(
argument|lkmtp
argument_list|,
argument|cmd
argument_list|,
argument|ver
argument_list|,
argument|kernfsmod_load
argument_list|,
argument|nosys
argument_list|,
argument|nosys
argument_list|)
block|}
end_block

begin_comment
comment|/*  * EOF -- This file has not been truncated.  */
end_comment

end_unit

