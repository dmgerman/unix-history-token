begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Jordan Hubbard, Paul Richards and Poul-Henning Kamp.  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *  * [Note: This file bears almost no resemblance to what was here in an  * earlier incarnation].  */
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<dialog.h>
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
modifier|*
name|welcome
index|[]
init|=
block|{
literal|"1. README"
block|,
literal|"READ THIS FIRST."
block|,
literal|"2. Release Notes"
block|,
literal|"Read the 2.0 Release Notes (recommended)."
block|,
literal|"3. Troubleshooting"
block|,
literal|"Read this in case of trouble."
block|,
literal|"4. Partitions and MBRs"
block|,
literal|"Verbose description of how these work."
block|,
literal|"5. COPYRIGHT"
block|,
literal|"Read FreeBSD Copyright Information."
block|,
literal|"6. Install"
block|,
literal|"Proceed with full installation."
block|,
literal|"7. Fixit"
block|,
literal|"Repair existing installation (`fixit' mode)."
block|,
literal|"8. Quit"
block|,
literal|"Don't do anything, just reboot."
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|stage0
parameter_list|()
block|{
name|evil_goto
label|:
if|if
condition|(
name|dialog_menu
argument_list|(
literal|"Welcome to FreeBSD!"
argument_list|,
literal|"Use ALT-F2 and ALT-F1 to toggle between debugging\ninformation screen (ALT-F2) or this dialog screen (ALT-F1)\n\nPlease select one of the following options:"
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|welcome
argument_list|,
name|selection
argument_list|)
condition|)
name|ExitSysinstall
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|atoi
argument_list|(
name|selection
argument_list|)
condition|)
block|{
case|case
literal|1
case|:
comment|/* View the README */
name|ShowFile
argument_list|(
name|README_FILE
argument_list|,
literal|"Read Me First"
argument_list|)
expr_stmt|;
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|2
case|:
comment|/* View the release notes */
name|ShowFile
argument_list|(
name|RELNOTES_FILE
argument_list|,
literal|"Release Notes"
argument_list|)
expr_stmt|;
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|3
case|:
comment|/* View the troubleshooting file */
name|ShowFile
argument_list|(
name|TROUBLE_FILE
argument_list|,
literal|"Troubleshooting"
argument_list|)
expr_stmt|;
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|4
case|:
comment|/* View DISK FAQ */
name|ShowFile
argument_list|(
name|HELPME_FILE
argument_list|,
literal|"DISK FAQ"
argument_list|)
expr_stmt|;
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|5
case|:
comment|/* View copyrights */
name|ShowFile
argument_list|(
name|COPYRIGHT_FILE
argument_list|,
literal|"COPYRIGHT"
argument_list|)
expr_stmt|;
goto|goto
name|evil_goto
goto|;
break|break;
case|case
literal|6
case|:
comment|/* Proceed (do nothing special, really) */
break|break;
case|case
literal|7
case|:
name|dialog_msgbox
argument_list|(
literal|"WARNING!"
argument_list|,
literal|"The usual install procedure will be invoked, but with most of the sanity checks disabled.  The suggested course of action is to: 	1. Go to (F)disk and do a (W)rite, and possibly a (B)oot too 	   if your MBR has been wiped. 	2. Go into (D)isklabel and identify your root (/) and swap 	   partitions. 	3. Select (P)roceed to reboot and load the cpio floppy. 	4. You will now be in the stand-alone shell, where you may 	   conduct further repairs with the tools you'll find in 	   /stand. 	5. Good luck...  You'll probably need it."
argument_list|,
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|fixit
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|8
case|:
comment|/* Be neat.. */
name|ExitSysinstall
argument_list|()
expr_stmt|;
break|break;
comment|/* hope not! :) */
block|}
block|}
end_function

end_unit

