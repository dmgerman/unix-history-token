begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last attempt in the `sysinstall' line, the next  * generation being slated to essentially a complete rewrite.  *  * $Id: media_strategy.c,v 1.1 1995/05/17 14:39:53 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkbad.h>
end_include

begin_define
define|#
directive|define
name|MSDOSFS
end_define

begin_define
define|#
directive|define
name|CD9660
end_define

begin_define
define|#
directive|define
name|NFS
end_define

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_undef
undef|#
directive|undef
name|MSDOSFS
end_undef

begin_undef
undef|#
directive|undef
name|CD9660
end_undef

begin_undef
undef|#
directive|undef
name|NFS
end_undef

begin_function
name|int
name|genericGetDist
parameter_list|(
name|char
modifier|*
name|dist
parameter_list|,
name|char
modifier|*
name|source
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Various media "strategy" routines */
end_comment

begin_function
name|Boolean
name|mediaInitCDROM
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
name|struct
name|iso_args
name|args
decl_stmt|;
name|struct
name|stat
name|sb
decl_stmt|;
if|if
condition|(
name|Mkdir
argument_list|(
literal|"/mnt/cdrom"
argument_list|,
name|NULL
argument_list|)
condition|)
return|return
name|FALSE
return|;
name|args
operator|.
name|fspec
operator|=
name|dev
operator|->
name|devname
expr_stmt|;
if|if
condition|(
name|mount
argument_list|(
name|MOUNT_CD9660
argument_list|,
literal|"/mnt/cdrom"
argument_list|,
literal|0
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|args
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|msgConfirm
argument_list|(
literal|"Error mounting %s on /mnt/cdrom: %s\n"
argument_list|,
name|dev
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
comment|/* Do a very simple check to see if this looks roughly like a 2.0.5 CDROM        Unfortunately FreeBSD won't let us read the ``label'' AFAIK, which is one        sure way of telling the disc version :-( */
if|if
condition|(
name|stat
argument_list|(
literal|"/mnt/cdrom/dists"
argument_list|,
operator|&
name|sb
argument_list|)
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|ENOENT
condition|)
block|{
name|msgConfirm
argument_list|(
literal|"Couldn't locate the directory `dists' on the cdrom\n\ Is this a 2.0.5 CDROM?\n"
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
else|else
block|{
name|msgConfirm
argument_list|(
literal|"Couldn't stat directory %s: %s"
argument_list|,
literal|"/mnt/cdrom/dists"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|Boolean
name|mediaGetCDROM
parameter_list|(
name|char
modifier|*
name|dist
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|void
name|mediaCloseCDROM
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function
name|Boolean
name|mediaInitFloppy
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|Boolean
name|mediaGetFloppy
parameter_list|(
name|char
modifier|*
name|dist
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|void
name|mediaCloseFloppy
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function
name|Boolean
name|mediaInitTape
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|Boolean
name|mediaGetTape
parameter_list|(
name|char
modifier|*
name|dist
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|void
name|mediaCloseTape
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
return|return;
block|}
end_function

begin_function
name|Boolean
name|mediaInitNetwork
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|Boolean
name|mediaGetNetwork
parameter_list|(
name|char
modifier|*
name|dist
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|void
name|mediaCloseNetwork
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{ }
end_function

begin_function
name|Boolean
name|mediaInitUFS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_function
name|Boolean
name|mediaGetUFS
parameter_list|(
name|char
modifier|*
name|dist
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* UFS has no close routine since this is handled at the device level */
end_comment

end_unit

