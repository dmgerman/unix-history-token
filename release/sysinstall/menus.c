begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $Id: menus.c,v 1.1.1.1 1995/04/27 12:50:34 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_comment
comment|/* All the system menus go here.  *  * Hardcoded things like version number strings will disappear from  * these menus just as soon as I add the code for doing inline variable  * expansion.  */
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

begin_comment
comment|/*  * Bloody C won't let me nest these initializers properly - do the  * items and the menus containing them as two seperate initializers  * done in two groups.  */
end_comment

begin_comment
comment|/* First, the lists of items */
end_comment

begin_comment
comment|/* Documentation menu */
end_comment

begin_decl_stmt
name|DMenuItem
name|_doc_items
index|[]
init|=
block|{
block|{
literal|"README"
block|,
literal|"Read this for a general description of FreeBSD"
block|,
comment|/* R */
name|MENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"help/readme.hlp"
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
name|MENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"help/hardware.hlp"
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
name|MENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"help/install.hlp"
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
name|MENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"help/faq.hlp"
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Language menu */
end_comment

begin_decl_stmt
name|DMenuItem
name|_lang_items
index|[]
init|=
block|{
block|{
literal|"English"
block|,
literal|"The system default language"
block|,
comment|/* E */
name|MENU_SET_VARIABLE
block|,
operator|(
name|void
operator|*
operator|)
literal|"LANG=en"
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
name|MENU_SET_VARIABLE
block|,
operator|(
name|void
operator|*
operator|)
literal|"LANG=fr"
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
name|MENU_SET_VARIABLE
block|,
operator|(
name|void
operator|*
operator|)
literal|"LANG=de"
block|,
literal|0
block|}
block|,
block|{
literal|"Japanese"
block|,
literal|"Japanese language and character set (JIS?)"
block|,
comment|/* J */
name|MENU_SET_VARIABLE
block|,
operator|(
name|void
operator|*
operator|)
literal|"LANG=jp"
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
name|MENU_SET_VARIABLE
block|,
operator|(
name|void
operator|*
operator|)
literal|"LANG=ru"
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The first menu */
end_comment

begin_decl_stmt
name|DMenuItem
name|_initial_items
index|[]
init|=
block|{
block|{
literal|"Usage"
block|,
literal|"Quick start - How to use this menu system."
block|,
comment|/* U */
name|MENU_DISPLAY_FILE
block|,
operator|(
name|void
operator|*
operator|)
literal|"help/initial.hlp"
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
name|MENU_SUBMENU
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
name|MENU_SUBMENU
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
literal|"Express"
block|,
literal|"Express installation (don't ask)"
block|,
comment|/* E */
name|MENU_CALL
block|,
operator|(
name|void
operator|*
operator|)
name|installExpress
block|,
literal|0
block|}
block|,
block|{
literal|"Custom"
block|,
literal|"Custom installation (please ask)"
block|,
comment|/* C */
name|MENU_CALL
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
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Installation media menu */
end_comment

begin_decl_stmt
name|DMenuItem
name|_media_items
index|[]
init|=
block|{
block|{
literal|"CDROM"
block|,
literal|"Install from a FreeBSD CDROM"
block|,
name|MENU_CALL
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
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Installation main menu */
end_comment

begin_decl_stmt
name|DMenuItem
name|_install_items
index|[]
init|=
block|{
block|{
literal|"Media"
block|,
literal|"Choose Installation media type"
block|,
comment|/* M */
name|MENU_SUBMENU
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
name|MENU_SUBMENU
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
name|MENU_SUBMENU
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
name|MENU_CANCEL
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
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenuItem
name|_null_items
index|[]
init|=
block|{
block|{
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start the menu outer bodies */
end_comment

begin_decl_stmt
name|DMenu
name|MenuInitial
init|=
block|{
literal|"Welcome to FreeBSD 2.0.5!"
block|,
comment|/* title */
literal|"This is the main menu of the FreeBSD installation system.  Please\n\ select one of the options below by using the arrow keys or typing the\n\ first character of the option name you're interested in.  Invoke an\n\ option by pressing enter."
block|,
comment|/* prompt */
literal|"Press F1 for further help"
block|,
comment|/* help line */
literal|"help/initial.hlp"
block|,
comment|/* help file */
name|_initial_items
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuDocumentation
init|=
block|{
literal|"Documentation for FreeBSD 2.0.5"
block|,
comment|/* Title */
literal|"If you are at all unsure about the configuration of your hardware\n or are looking to build a system specifically for FreeBSD, read the\n\ Hardware guide!  New users should also read the Install document for\n\ a step-by-step tutorial on installing FreeBSD.  For general information,\n\ consult the README file.  If you're having other problems, you may find\n\ answers in the FAQ."
block|,
literal|"Having trouble?  Press F1 for help!"
block|,
comment|/* help line */
literal|"help/usage.hlp"
block|,
comment|/* help file */
name|_doc_items
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuLanguage
init|=
block|{
literal|"Natural language selection"
block|,
comment|/* title */
literal|"Please specify the language you'd like to use by default.\n\ While a large amount of the system's documentation is still\n\ written in english (and may never be translated), there are some\n\ guides and system documentation that may be written in your\n\ preferred language.  When such are found, they will be used instead\n\ of the english versions."
block|,
comment|/* prompt */
literal|"Press F1 for more information"
block|,
comment|/* help line */
literal|"help/language.hlp"
block|,
comment|/* help file */
name|_lang_items
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuMedia
init|=
block|{
literal|"Choose Installation Media"
block|,
literal|"FreeBSD can be installed from a variety of different installation\n\ media, from floppies to the Internet.  If you're installing FreeBSD from\n\ a supported CDROM drive then this is generally the best method to\n\ use unless you have some overriding reason for using another method."
block|,
name|NULL
block|,
name|NULL
block|,
name|_media_items
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuInstallType
init|=
block|{
literal|"Choose Installation Type"
block|,
literal|"blah blah"
block|,
name|NULL
block|,
name|NULL
block|,
name|_null_items
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuInstallOptions
init|=
block|{
literal|"Choose Installation Options"
block|,
literal|"blah blah"
block|,
name|NULL
block|,
name|NULL
block|,
name|_null_items
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuInstall
init|=
block|{
literal|"Choose Installation Options"
block|,
comment|/* title */
literal|"Before installation can continue, you need to specify a few items\n\ of information regarding the location of the distribution and the kind\n\ of installation you want to have (and where).  There are also a number\n\ of options you can specify in the Options menu.  If you do not wish to\n\ install FreeBSD at this time, you may select Cancel to leave this menu"
block|,
literal|"You may wish to read the install guide - press F1 to do so"
block|,
literal|"help/install.hlp"
block|,
name|_install_items
block|, }
decl_stmt|;
end_decl_stmt

end_unit

