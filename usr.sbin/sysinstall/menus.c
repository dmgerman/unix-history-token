begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *<<<<<<< menus.c  * $Id: menus.c,v 1.5 1995/05/04 03:51:19 jkh Exp $ ||||||| 1.7  * $Id: menus.c,v 1.6 1995/05/04 19:48:14 jkh Exp $ =======  * $Id: menus.c,v 1.7 1995/05/04 23:36:20 jkh Exp $>>>>>>> /tmp/T4000279  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_comment
comment|/* All the system menus go here.  *  * Hardcoded things like version number strings will disappear from  * these menus just as soon as I add the code for doing inline variable  * expansion.  */
end_comment

begin_comment
comment|/* Forward decls for submenus */
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDocumentation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuLanguage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMedia
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuInstallType
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuInstallOptions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDistributions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The initial installation menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuInitial
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Welcome to FreeBSD 2.0.5!"
block|,
comment|/* title */
literal|"This is the main menu of the FreeBSD installation system.  Please\n\ select one of the options below by using the arrow keys or typing the\n\ first character of the option name you're interested in.  Invoke an\n\ option by pressing enter.  If you'd like a shell, press ESC"
block|,
comment|/* prompt */
literal|"Press F1 for usage instructions"
block|,
comment|/* help line */
literal|"usage.hlp"
block|,
comment|/* help file */
block|{
block|{
literal|"Usage"
block|,
literal|"Quick start - How to use this menu system."
block|,
comment|/* U */
name|DMENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"usage.hlp"
block|,
literal|0
block|}
block|,
block|{
literal|"Doc"
block|,
literal|"More detailed documentation on FreeBSD."
block|,
comment|/* D */
name|DMENU_SUBMENU
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|MenuDocumentation
block|,
literal|0
block|}
block|,
block|{
literal|"Lang"
block|,
literal|"Select natural language options."
block|,
comment|/* L */
name|DMENU_SUBMENU
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|MenuLanguage
block|,
literal|0
block|}
block|,
block|{
literal|"Install"
block|,
literal|"Begin installation"
block|,
comment|/* I */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|installCustom
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The main documentation menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuDocumentation
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Documentation for FreeBSD 2.0.5"
block|,
comment|/* Title */
literal|"If you are at all unsure about the configuration of your hardware\n\ or are looking to build a system specifically for FreeBSD, read the\n\ Hardware guide!  New users should also read the Install document for\n\ a step-by-step tutorial on installing FreeBSD.  For general information,\n\ consult the README file.  If you're having other problems, you may find\n\ answers in the FAQ."
block|,
literal|"Confused?  Press F1 for help."
block|,
literal|"usage.hlp"
block|,
comment|/* help file */
block|{
block|{
literal|"README"
block|,
literal|"Read this for a general description of FreeBSD"
block|,
comment|/* R */
name|DMENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"readme.hlp"
block|,
literal|0
block|}
block|,
block|{
literal|"Hardware"
block|,
literal|"The FreeBSD survival guide for PC hardware."
block|,
comment|/* H */
name|DMENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"hardware.hlp"
block|,
literal|0
block|}
block|,
block|{
literal|"Install"
block|,
literal|"A step-by-step guide to installing FreeBSD."
block|,
comment|/* I */
name|DMENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"install.hlp"
block|,
literal|0
block|}
block|,
block|{
literal|"FAQ"
block|,
literal|"Frequently Asked Questions about FreeBSD."
block|,
comment|/* F */
name|DMENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"faq.hlp"
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The language selection menu */
end_comment

begin_comment
comment|/*  * Note:  The RADIO menus use a slightly different syntax.  If an item  * name starts with `*', it's considered to be "ON" by default,  * otherwise off.  */
end_comment

begin_decl_stmt
name|DMenu
name|MenuLanguage
init|=
block|{
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Natural language selection"
block|,
comment|/* title */
literal|"Please specify the language you'd like to use by default.\n\n\ While almost all of the system's documentation is still written\n\ in english (and may never be translated), there are a few guides\n\ and types of system documentation that may be written in your\n\ preferred language.  When such are found, they will be used instead\n\ of the english versions."
block|,
comment|/* prompt */
literal|"Press F1 for more information"
block|,
comment|/* help line */
literal|"language.hlp"
block|,
comment|/* help file */
block|{
block|{
literal|"Danish"
block|,
literal|"Danish language and character set (ISO-8859-1)"
block|,
comment|/* D */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Danish
block|,
literal|0
block|}
block|,
block|{
literal|"Dutch"
block|,
literal|"Dutch language and character set (ISO-8859-1)"
block|,
comment|/* D */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Dutch
block|,
literal|0
block|}
block|,
block|{
literal|"*English"
block|,
literal|"English language (system default)"
block|,
comment|/* E */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_English
block|,
literal|0
block|}
block|,
block|{
literal|"French"
block|,
literal|"French language and character set (ISO-8859-1)"
block|,
comment|/* F */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_French
block|,
literal|0
block|}
block|,
block|{
literal|"German"
block|,
literal|"German language and character set (ISO-8859-1)"
block|,
comment|/* G */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_German
block|,
literal|0
block|}
block|,
block|{
literal|"Italian"
block|,
literal|"Italian language and character set (ISO-8859-1)"
block|,
comment|/* I */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Italian
block|,
literal|0
block|}
block|,
block|{
literal|"Japanese"
block|,
literal|"Japanese language and default character set (romaji)"
block|,
comment|/* J */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Japanese
block|,
literal|0
block|}
block|,
block|{
literal|"Norwegian"
block|,
literal|"Norwegian language and character set (ISO-8859-1)"
block|,
comment|/* N */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Norwegian
block|,
literal|0
block|}
block|,
block|{
literal|"Russian"
block|,
literal|"Russian language and character set (cp866-8x14)"
block|,
comment|/* R */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Russian
block|,
literal|0
block|}
block|,
block|{
literal|"Spanish"
block|,
literal|"Spanish language and character set (ISO-8859-1)"
block|,
comment|/* S */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Spanish
block|,
literal|0
block|}
block|,
block|{
literal|"Swedish"
block|,
literal|"Swedish language and character set (ISO-8859-1)"
block|,
comment|/* S */
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|lang_set_Swedish
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The media selection menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuMedia
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Choose Installation Media"
block|,
literal|"FreeBSD can be installed from a variety of different installation\n\ media, ranging from floppies to the Internet.  If you're installing\n\ FreeBSD from a supported CDROM drive then this is generally the best\n\ method to use unless you have some overriding reason for using another\n\ method. Please also note that the DES distribution is NOT available on \n\ CDROM due to U.S. export restrictions."
block|,
literal|"Press F1 for more information on the various media types"
block|,
literal|"media.hlp"
block|,
block|{
block|{
literal|"CDROM"
block|,
literal|"Install from a FreeBSD CDROM"
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|mediaSetCDROM
block|,
literal|0
block|}
block|,
block|{
literal|"FLOPPY"
block|,
literal|"Install from a floppy disk set"
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|mediaSetFloppy
block|,
literal|0
block|}
block|,
block|{
literal|"DOS"
block|,
literal|"Install from a DOS partition"
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|mediaSetDOS
block|,
literal|0
block|}
block|,
block|{
literal|"TAPE"
block|,
literal|"Install from SCSI or QIC tape"
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|mediaSetTape
block|,
literal|0
block|}
block|,
block|{
literal|"FTP"
block|,
literal|"Install from an Internet FTP server"
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|mediaSetFTP
block|,
literal|0
block|}
block|,
block|{
literal|"FILESYSTEM"
block|,
literal|"Install from a UFS or NFS mounted distribution"
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|mediaSetFS
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The installation type menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuInstallType
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Choose Installation Type"
block|,
literal|"As a convenience, we provide several `canned' installation types. \ These pick what we consider to be the most reasonable defaults for the \ type of system in question.  If you would prefer to pick and choose \ the list of distributions yourself, simply select `custom'."
block|,
literal|"Press F1 for more information on the various distributions"
block|,
literal|"dist_types.hlp"
block|,
block|{
block|{
literal|"Developer"
block|,
literal|"Includes full sources, binaries and doc but no games."
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|distSetDeveloper
block|,
literal|0
block|}
block|,
block|{
literal|"X-Developer"
block|,
literal|"Same as above, but includes XFree86."
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|distSetXDeveloper
block|,
literal|0
block|}
block|,
block|{
literal|"User"
block|,
literal|"General user.  Binaries and doc but no sources."
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|distSetUser
block|,
literal|0
block|}
block|,
block|{
literal|"X-User"
block|,
literal|"Same as above, but includes XFree86."
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|distSetXUser
block|,
literal|0
block|}
block|,
block|{
literal|"Minimal"
block|,
literal|"The smallest configuration possible."
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|distSetMinimum
block|,
literal|0
block|}
block|,
block|{
literal|"Everything"
block|,
literal|"The entire source and binary distribution."
block|,
name|DMENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|distSetEverything
block|,
literal|0
block|}
block|,
block|{
literal|"Custom"
block|,
literal|"Specify your own distribution set"
block|,
name|DMENU_SUBMENU
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|MenuDistributions
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuDistributions
init|=
block|{
name|DMENU_MULTIPLE_TYPE
block|,
literal|"Select the distributions you wish to install."
block|,
literal|"Please check off the distributions you wish to install."
block|,
literal|"Press F1 for a more complete description of these distributions."
block|,
literal|"distribution_types.hlp"
block|,
block|{
block|{
literal|"*bin"
block|,
literal|"Binary base distribution (required)"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"commercial"
block|,
literal|"Commercial demos and shareware"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"compat1x"
block|,
literal|"FreeBSD 1.x binary compatability package"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"DES"
block|,
literal|"DES encryption code and sources"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"dict"
block|,
literal|"Spelling checker disctionary files"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"games"
block|,
literal|"Games and other amusements (non-commercial)"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"info"
block|,
literal|"GNU info files"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"man"
block|,
literal|"System manual pages - strongly recommended"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"proflibs"
block|,
literal|"Profiled versions of the libraries"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"src"
block|,
literal|"Sources for everything but DES"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"XFree86"
block|,
literal|"The XFree86 3.1.1 distribution"
block|,
name|DMENU_NOP
block|,
name|NULL
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The installation options menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuInstallOptions
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Choose Installation Options"
block|,
literal|"blah blah"
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuDiskDevices
init|=
block|{
name|DMENU_MULTIPLE_TYPE
block|,
literal|"Select Drive(s)"
block|,
literal|"Please select the drive, or drives, on which you wish to install\n\ FreeBSD.  You need to select at least one drive containing some free\n\ space, though FreeBSD can be installed across several drives if you do\n\ not have the required space on a single drive.  If you wish to boot\n\ off a drive that's not a `zero drive', or have multiple operating\n\ systems on your machine, you will have the option to install a boot\n\ manager later."
block|,
literal|"Press F1 for more information on what you see here."
block|,
literal|"drives.hlp"
block|,
block|{
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The main installation menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuInstall
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Choose Installation Options"
block|,
comment|/* title */
literal|"Before installation can continue, you need to specify a few items\n\ of information regarding the location of the distribution and the kind\n\ of installation you want to have (and where).  There are also a number\n\ of options you can specify in the Options menu.  If you do not wish to\n\ install FreeBSD at this time, you may select Cancel to leave this menu"
block|,
literal|"You may wish to read the install guide - press F1 to do so"
block|,
literal|"install.hlp"
block|,
block|{
block|{
literal|"Media"
block|,
literal|"Choose Installation media type"
block|,
comment|/* M */
name|DMENU_SUBMENU
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|MenuMedia
block|,
literal|0
block|}
block|,
block|{
literal|"Type"
block|,
literal|"Choose the type of installation you want"
block|,
comment|/* T */
name|DMENU_SUBMENU
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|MenuInstallType
block|,
literal|0
block|}
block|,
block|{
literal|"Options"
block|,
literal|"Specify installation options"
block|,
comment|/* O */
name|DMENU_SUBMENU
block|,
operator|(
name|void
operator|*
operator|)
operator|&
name|MenuInstallOptions
block|,
literal|0
block|}
block|,
block|{
literal|"Proceed"
block|,
literal|"Proceed with installation"
block|,
comment|/* P */
name|DMENU_CANCEL
block|,
operator|(
name|void
operator|*
operator|)
name|NULL
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

