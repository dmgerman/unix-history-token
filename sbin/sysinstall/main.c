begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dkuug.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: main.c,v 1.9 1994/10/29 10:01:34 phk Exp $  *  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_comment
comment|/* only in main.c */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_decl_stmt
name|jmp_buf
name|jmp_restart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * XXX: utils: Mkdir must do "-p".  * XXX: stage2: do mkdir for msdos-mounts.  * XXX: label: Import dos-slice.  * XXX: mbr: edit geometry  */
end_comment

begin_function_decl
specifier|extern
name|int
name|alloc_memory
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
comment|/* Are we running as init? */
if|if
condition|(
name|getpid
argument_list|()
operator|==
literal|1
condition|)
block|{
name|close
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|open
argument_list|(
literal|"/dev/console"
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|dup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|close
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|dup
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"sysinstall running as init\n\r"
argument_list|)
expr_stmt|;
name|i
operator|=
literal|1
expr_stmt|;
name|ioctl
argument_list|(
literal|0
argument_list|,
name|TIOCSPGRP
argument_list|,
operator|&
name|i
argument_list|)
expr_stmt|;
name|setlogin
argument_list|(
literal|"root"
argument_list|)
expr_stmt|;
name|debug_fd
operator|=
name|open
argument_list|(
literal|"/dev/ttyv1"
argument_list|,
name|O_WRONLY
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|debug_fd
operator|=
name|open
argument_list|(
literal|"sysinstall.debug"
argument_list|,
name|O_WRONLY
operator||
name|O_CREAT
operator||
name|O_TRUNC
argument_list|,
literal|0644
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|set_termcap
argument_list|()
operator|==
operator|-
literal|1
condition|)
block|{
name|Fatal
argument_list|(
literal|"Can't find terminal entry\n"
argument_list|)
expr_stmt|;
block|}
comment|/* XXX too early to use fatal ! */
comment|/* XXX - libdialog has particularly bad return value checking */
name|init_dialog
argument_list|()
expr_stmt|;
comment|/* If we haven't crashed I guess dialog is running ! */
name|dialog_active
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|alloc_memory
argument_list|()
operator|<
literal|0
condition|)
name|Fatal
argument_list|(
literal|"No memory\n"
argument_list|)
expr_stmt|;
name|setjmp
argument_list|(
name|jmp_restart
argument_list|)
expr_stmt|;
comment|/* XXX Allow people to "restart" */
if|if
condition|(
name|getenv
argument_list|(
literal|"STAGE0"
argument_list|)
operator|||
operator|!
name|access
argument_list|(
literal|"/this_is_boot_flp"
argument_list|,
name|R_OK
argument_list|)
condition|)
block|{
name|stage0
argument_list|()
expr_stmt|;
name|stage1
argument_list|()
expr_stmt|;
name|stage2
argument_list|()
expr_stmt|;
name|reboot
argument_list|(
name|RB_AUTOBOOT
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|stage3
argument_list|()
expr_stmt|;
name|stage4
argument_list|()
expr_stmt|;
name|stage5
argument_list|()
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

