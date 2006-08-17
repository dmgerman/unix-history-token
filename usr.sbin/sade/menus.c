begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sade.h"
end_include

begin_comment
comment|/* All the system menus go here.  *  * Hardcoded things like version number strings will disappear from  * these menus just as soon as I add the code for doing inline variable  * expansion.  */
end_comment

begin_decl_stmt
name|DMenu
name|MenuDiskDevices
init|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select Drive(s)"
block|,
literal|"Please select the drive, or drives, on which you wish to perform\n"
literal|"this operation.  If you are attempting to install a boot partition\n"
literal|"on a drive other than the first one or have multiple operating\n"
literal|"systems on your machine, you will have the option to install a boot\n"
literal|"manager later.  To select a drive, use the arrow keys to move to it\n"
literal|"and press [SPACE] or [ENTER].  To de-select it, press it again.\n\n"
literal|"Use [TAB] to get to the buttons and leave this menu."
block|,
literal|"Press F1 for important information regarding disk geometry!"
block|,
literal|"drives"
block|,
block|{
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuMain
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Disklabel and partitioning utility"
block|,
literal|"This is a utility for partitioning and/or labelling your disks."
block|,
literal|"DISKUTIL"
block|,
literal|"main"
block|,
block|{
ifdef|#
directive|ifdef
name|WITH_SLICES
block|{
literal|"1 Partition"
block|,
literal|"Managing disk partitions"
block|,
name|NULL
block|,
name|diskPartitionEditor
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
endif|#
directive|endif
block|{
literal|"2 Label"
block|,
literal|"Label allocated disk partitions"
block|,
name|NULL
block|,
name|diskLabelEditor
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* IPL type menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuIPLType
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"overwrite me"
block|,
comment|/* will be disk specific label */
literal|"If you want a FreeBSD Boot Manager, select \"BootMgr\".  If you would\n"
literal|"prefer your Boot Manager to remain untouched then select \"None\".\n\n"
block|,
literal|"Press F1 to read about drive setup"
block|,
literal|"drives"
block|,
block|{
block|{
literal|"BootMgr"
block|,
literal|"Install the FreeBSD Boot Manager"
block|,
name|dmenuRadioCheck
block|,
name|dmenuSetValue
block|,
name|NULL
block|,
operator|&
name|BootMgr
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"None"
block|,
literal|"Leave the IPL untouched"
block|,
name|dmenuRadioCheck
block|,
name|dmenuSetValue
block|,
name|NULL
block|,
operator|&
name|BootMgr
block|,
literal|'('
block|,
literal|'*'
block|,
literal|')'
block|,
literal|1
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MBR type menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuMBRType
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"overwrite me"
block|,
comment|/* will be disk specific label */
literal|"FreeBSD comes with a boot selector that allows you to easily\n"
literal|"select between FreeBSD and any other operating systems on your machine\n"
literal|"at boot time.  If you have more than one drive and want to boot\n"
literal|"from the second one, the boot selector will also make it possible\n"
literal|"to do so (limitations in the PC BIOS usually prevent this otherwise).\n"
literal|"If you do not want a boot selector, or wish to replace an existing\n"
literal|"one, select \"standard\".  If you would prefer your Master Boot\n"
literal|"Record to remain untouched then select \"None\".\n\n"
literal|"  NOTE:  PC-DOS users will almost certainly require \"None\"!"
block|,
literal|"Press F1 to read about drive setup"
block|,
literal|"drives"
block|,
block|{
block|{
literal|"BootMgr"
block|,
literal|"Install the FreeBSD Boot Manager"
block|,
name|dmenuRadioCheck
block|,
name|dmenuSetValue
block|,
name|NULL
block|,
operator|&
name|BootMgr
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Standard"
block|,
literal|"Install a standard MBR (no boot manager)"
block|,
name|dmenuRadioCheck
block|,
name|dmenuSetValue
block|,
name|NULL
block|,
operator|&
name|BootMgr
block|,
literal|'('
block|,
literal|'*'
block|,
literal|')'
block|,
literal|1
block|}
block|,
block|{
literal|"None"
block|,
literal|"Leave the Master Boot Record untouched"
block|,
name|dmenuRadioCheck
block|,
name|dmenuSetValue
block|,
name|NULL
block|,
operator|&
name|BootMgr
block|,
literal|'('
block|,
literal|'*'
block|,
literal|')'
block|,
literal|2
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

end_unit

