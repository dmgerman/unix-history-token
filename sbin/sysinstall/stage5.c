begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: stage5.c,v 1.4 1994/11/02 06:19:50 jkh Exp $  *  */
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
literal|" You are now done with the first phase of the installation.  We will, for now, dump you rather unceremoniously into a shell where you can then ftp, SLIP, DOS floppy or carrier pigeon the bindist over.  This will NOT be so unfriendly in the BETA installation, and will lead instead to a menu offering you various helpful ways of getting the bindist.  This is all we had time for in the ALPHA, however.  Sorry! Thank you for your patience!"
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|stage5
parameter_list|()
block|{
name|dialog_msgbox
argument_list|(
name|TITLE
argument_list|,
name|msg
argument_list|,
name|strheight
argument_list|(
name|msg
argument_list|)
operator|+
literal|4
argument_list|,
name|strwidth
argument_list|(
name|msg
argument_list|)
operator|+
literal|4
argument_list|,
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
block|}
end_function

end_unit

