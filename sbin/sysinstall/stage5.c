begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: stage5.c,v 1.16.2.1 1994/11/21 03:12:20 phk Exp $  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|msg
index|[]
init|=
literal|" You are now done with the initial phase of the installation that gets FreeBSD onto your hard disk.  At this point, we need to go on to use FTP, NFS, Tape, CD or DOS floppies to get a bindist onto your system so that it's actually usable.  Select Yes to proceed with this phase, or No to simply drop into a shell."
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|stage5
parameter_list|()
block|{
name|int
name|exec_sh
init|=
literal|1
decl_stmt|;
name|setenv
argument_list|(
literal|"PATH"
argument_list|,
literal|"/stand"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|exec_sh
operator|=
name|dialog_yesno
argument_list|(
literal|"End of initial installation"
argument_list|,
name|msg
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|end_dialog
argument_list|()
expr_stmt|;
name|dialog_active
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|exec_sh
condition|)
name|exec
argument_list|(
literal|2
argument_list|,
literal|"/stand/sh"
argument_list|,
literal|"/stand/-sh"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|exec
argument_list|(
literal|3
argument_list|,
literal|"/stand/bininst"
argument_list|,
literal|"/stand/-bininst"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dialog_active
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function

end_unit

