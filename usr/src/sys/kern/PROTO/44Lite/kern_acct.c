begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	from: @(#)kern_acct.c	7.18 (Berkeley) 5/11/91  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"namei.h"
end_include

begin_include
include|#
directive|include
file|"resourcevar.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"termios.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"mount.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_include
include|#
directive|include
file|"acct.h"
end_include

begin_include
include|#
directive|include
file|"syslog.h"
end_include

begin_comment
comment|/*  * Values associated with enabling and disabling accounting  */
end_comment

begin_decl_stmt
name|int
name|acctsuspend
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stop accounting when< 2% free space left */
end_comment

begin_decl_stmt
name|int
name|acctresume
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resume when free space risen to> 4% */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|chk
init|=
block|{
literal|15
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* frequency to check space for accounting */
end_comment

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|acctp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file to which to do accounting */
end_comment

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|savacctp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file to which to do accounting when space */
end_comment

begin_comment
comment|/*  * Enable or disable process accounting.  *  * If a non-null filename is given, that file is used to store accounting  * records on process exit. If a null filename is given process accounting  * is suspended. If accounting is enabled, the system checks the amount  * of freespace on the filesystem at timeval intervals. If the amount of  * freespace is below acctsuspend percent, accounting is suspended. If  * accounting has been suspended, and freespace rises above acctresume,  * accounting is resumed.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|sysacct
argument_list|(
argument|p
argument_list|,
argument|uap
argument_list|,
argument|retval
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|args
block|{
name|char
modifier|*
name|fname
decl_stmt|;
block|}
modifier|*
name|uap
struct|;
end_struct

begin_decl_stmt
name|int
modifier|*
name|retval
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Periodically check the file system to see if accounting  * should be turned on or off.  */
end_comment

begin_macro
name|acctwatch
argument_list|(
argument|resettime
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|timeval
modifier|*
name|resettime
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|statfs
name|sb
decl_stmt|;
if|if
condition|(
name|savacctp
condition|)
block|{
operator|(
name|void
operator|)
name|VFS_STATFS
argument_list|(
name|savacctp
operator|->
name|v_mount
argument_list|,
operator|&
name|sb
argument_list|,
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sb
operator|.
name|f_bavail
operator|>
name|acctresume
operator|*
name|sb
operator|.
name|f_blocks
operator|/
literal|100
condition|)
block|{
name|acctp
operator|=
name|savacctp
expr_stmt|;
name|savacctp
operator|=
name|NULL
expr_stmt|;
name|log
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Accounting resumed\n"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
name|acctp
operator|==
name|NULL
condition|)
return|return;
operator|(
name|void
operator|)
name|VFS_STATFS
argument_list|(
name|acctp
operator|->
name|v_mount
argument_list|,
operator|&
name|sb
argument_list|,
operator|(
expr|struct
name|proc
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sb
operator|.
name|f_bavail
operator|<=
name|acctsuspend
operator|*
name|sb
operator|.
name|f_blocks
operator|/
literal|100
condition|)
block|{
name|savacctp
operator|=
name|acctp
expr_stmt|;
name|acctp
operator|=
name|NULL
expr_stmt|;
name|log
argument_list|(
name|LOG_NOTICE
argument_list|,
literal|"Accounting suspended\n"
argument_list|)
expr_stmt|;
block|}
name|timeout
argument_list|(
name|acctwatch
argument_list|,
operator|(
name|caddr_t
operator|)
name|resettime
argument_list|,
name|hzto
argument_list|(
name|resettime
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * This routine calculates an accounting record for a process and,  * if accounting is enabled, writes it to the accounting file.  */
end_comment

begin_expr_stmt
name|acct
argument_list|(
name|p
argument_list|)
specifier|register
expr|struct
name|proc
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

end_unit

