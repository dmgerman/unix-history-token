begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $Id: menus.c,v 1.41.2.20 1995/06/05 10:43:06 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
literal|"This is the main menu of the FreeBSD installation system.  Please\n\ select one of the options below by using the arrow keys or typing the\n\ first character of the option name you're interested in.  Invoke an\n\ option by pressing [ENTER]."
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
literal|"usage.hlp"
block|,
literal|0
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
operator|&
name|MenuDocumentation
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Language"
block|,
literal|"Set your preferred language."
block|,
comment|/* L */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuOptionsLanguage
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Options"
block|,
literal|"Select various options for this utility."
block|,
comment|/* O */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuOptions
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Proceed"
block|,
literal|"Go to the installation menu"
block|,
comment|/* P */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuInstall
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Quit"
block|,
literal|"Exit this menu (and the installation)"
block|,
comment|/* Q */
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
literal|"If you are at all unsure about the configuration of your hardware\n\ or are looking to build a system specifically for FreeBSD, read the\n\ Hardware guide!  New users should also read the Install document for\n\ a step-by-step tutorial on installing FreeBSD.  For general information,\n\ consult the README file.  If you are having other problems, you may find\n\ answers in the FAQ."
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
literal|"README"
block|,
literal|0
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
literal|"hardware.hlp"
block|,
literal|0
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
literal|"install.hlp"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Copyright"
block|,
literal|"The FreeBSD Copyright notices."
block|,
comment|/* C */
name|DMENU_DISPLAY_FILE
block|,
literal|"COPYRIGHT"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Release"
block|,
literal|"The release notes for this version of FreeBSD."
block|,
comment|/* R */
name|DMENU_DISPLAY_FILE
block|,
literal|"RELNOTES"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
comment|/* E */
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
comment|/*  * The language selection menu.  */
end_comment

begin_decl_stmt
name|DMenu
name|MenuOptionsLanguage
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Natural language selection"
block|,
comment|/* title */
literal|"Please specify the language you would like to use by default.\n\n\ While almost all of the system's documentation is still written\n\ in english (and may never be translated), there are a few guides\n\ and types of system documentation that may be written in your\n\ preferred language.  When such are found, they will be used instead\n\ of the english versions.  This feature is nonetheless considered\n\ to be in experimental status at this time."
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
name|lang_set_Danish
block|,
literal|0
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
name|lang_set_Dutch
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"English"
block|,
literal|"English language (system default)"
block|,
comment|/* E */
name|DMENU_CALL
block|,
name|lang_set_English
block|,
literal|0
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
name|lang_set_French
block|,
literal|0
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
name|lang_set_German
block|,
literal|0
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
name|lang_set_Italian
block|,
literal|0
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
name|lang_set_Japanese
block|,
literal|0
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
name|lang_set_Norwegian
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Russian"
block|,
literal|"Russian language and character set (KOI8-R)"
block|,
comment|/* R */
name|DMENU_CALL
block|,
name|lang_set_Russian
block|,
literal|0
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
name|lang_set_Spanish
block|,
literal|0
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
name|lang_set_Swedish
block|,
literal|0
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
name|MenuMediaCDROM
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose a CDROM type"
block|,
literal|"FreeBSD can be installed directly from a CDROM containing a valid\n\ FreeBSD 2.0.5 distribution.  If you are seeing this menu it is because\n\ more than one CDROM drive was found on your system.  Please select one\n\ of the following CDROM drives as your installation drive."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install.hlp"
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
name|MenuMediaFloppy
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose a Floppy drive"
block|,
literal|"You have more than one floppy drive.  Please chose the drive\n\ you would like to use for this operation"
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
name|MenuMediaDOS
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose a DOS partition"
block|,
literal|"FreeBSD can be installed directly from a DOS partition\n\ assuming, of course, that you have copied the relevant\n\ distributions into your DOS partition before starting this\n\ installation.  If this is not the case then you should reboot\n\ DOS at this time and copy the distributions you wish to install\n\ into a \"FREEBSD\" subdirectory on one of your DOS partitions.\n\ Otherwise, please select the DOS partition containing the FreeBSD\n\ distribution files."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install.hlp"
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
name|MenuMediaFTP
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Please specify an FTP site"
block|,
literal|"FreeBSD is distributed from a number of sites on the Internet. Please\n\ select the site closest to you or \"other\" if you'd like to specify another\n\ choice.  Also note that not all sites carry every possible distribution!\n\ Distributions other than the basic user set are only guaranteed to be\n\ available from the Primary site.\n\n\ If the first site selected doesn't respond, try one of the alternates.\n\ You may also wish to investigate the options menu in case of trouble.\n\ To specify a URL not in this list, chose \"other\"."
block|,
literal|"Select a site that's close!"
block|,
literal|"install.hlp"
block|,
block|{
block|{
literal|"Primary Site"
block|,
literal|"ftp.freebsd.org"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.freebsd.org/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Secondary Site"
block|,
literal|"freefall.cdrom.com"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://freefall.cdrom.com/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Other"
block|,
literal|"Specify some other ftp site by URL"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=other"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Australia"
block|,
literal|"ftp.physics.usyd.edu.au"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.physics.usyd.edu.au/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Finland"
block|,
literal|"nic.funet.fi"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://nic.funet.fi/pub/unix/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"France"
block|,
literal|"ftp.ibp.fr"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.ibp.fr/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Germany"
block|,
literal|"ftp.fb9dv.uni-duisburg.de"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.fb9dv.uni-duisburg.de/pub/unix/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Germany #2"
block|,
literal|"gil.physik.rwth-aachen.de"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://gil.physik.rwth-aachen.de/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Germany #3"
block|,
literal|"ftp.uni-paderborn.de"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.uni-paderborn.de/freebsd/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Hong Kong"
block|,
literal|"ftp.hk.super.net"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.hk.super.net/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Israel"
block|,
literal|"orgchem.weizmann.ac.il"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://orgchem.weizmann.ac.il/pub/FreeBSD-2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan"
block|,
literal|"ftp.sra.co.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.sra.co.jp/pub/os/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #2"
block|,
literal|"ftp.mei.co.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.mei.co.jp/free/PC-UNIX/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #3"
block|,
literal|"ftp.waseda.ac.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.waseda.ac.jp/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #4"
block|,
literal|"ftp.pu-toyama.ac.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.pu-toyama.ac.jp/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #5"
block|,
literal|"ftpsv1.u-aizu.ac.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftpsv1.u-aizu.ac.jp/pub/os/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #6"
block|,
literal|"ftp.tut.ac.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp://ftp.tut.ac.jp/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #7"
block|,
literal|"ftp.ee.uec.ac.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.ee.uec.ac.jp/pub/os/mirror/ftp.freebsd.org/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #8"
block|,
literal|"ftp.tokyonet.ad.jp"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp://ftp.tokyonet.ad.jp/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Korea"
block|,
literal|"ftp.cau.ac.kr"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.cau.ac.kr/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Netherlands"
block|,
literal|"ftp.nl.net"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.nl.net/pub/os/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Russia"
block|,
literal|"ftp.kiae.su"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.kiae.su/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Sweden"
block|,
literal|"ftp.luth.se"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.luth.se/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Taiwan"
block|,
literal|"netbsd.csie.nctu.edu.tw"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://netbsd.csie.nctu.edu.tw/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Thailand"
block|,
literal|"ftp.nectec.or.th"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.nectec.or.th/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"UK"
block|,
literal|"ftp.demon.co.uk"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.demon.co.uk/pub/BSD/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"UK #2"
block|,
literal|"src.doc.ic.ac.uk"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://src.doc.ic.ac.uk/packages/unix/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"UK #3"
block|,
literal|"unix.hensa.ac.uk"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://unix.hensa.ac.uk/mirrors/walnut.creek/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"USA"
block|,
literal|"ref.tfs.com"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ref.tfs.com/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"USA #2"
block|,
literal|"ftp.dataplex.net"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.dataplex.net/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"USA #3"
block|,
literal|"kryten.atinc.com"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://kryten.atinc.com/pub/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"USA #4"
block|,
literal|"ftp.neosoft.com"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ftp=ftp://ftp.neosoft.com/systems/FreeBSD/2.0.5-ALPHA"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
name|NULL
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuMediaTape
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose a tape drive type"
block|,
literal|"FreeBSD can be installed from tape drive, though this installation\n\ method requires a certain amount of temporary storage in addition\n\ to the space required by the distribution itself (tape drives make\n\ poor random-access devices, so we extract _everything_ on the tape\n\ in one pass).  If you have sufficient space for this, then you should\n\ select one of the following tape devices detected on your system."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install.hlp"
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
name|MenuNetworkDevice
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose a network interface type"
block|,
literal|"FreeBSD can be installed directly over a network, using NFS or FTP.\n If you are using PPP over a serial device (cuaa0 or cuaa1) as opposed\n\ to a direct ethernet connection, then you may need to first dial your\n\ service provider using a special utility we provide for that purpose.\n\ You can also install over a parallel port using a special \"laplink\"\n\ cable, though this only works if you have another FreeBSD machine running\n\ a fairly recent (2.0R or later) release to talk to.\n\n\ To use PPP select one of the serial devices, otherwise select lp0 for\n\ the parallel port or one of the ethernet controllers (if you have one)\n\ for an ethernet installation."
block|,
literal|"Press F1 to read network configuration manual"
block|,
literal|"network_device.hlp"
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
comment|/* The media selection menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuMedia
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose Installation Media"
block|,
literal|"FreeBSD can be installed from a variety of different installation\n\ media, ranging from floppies to the Internet.  If you're installing\n\ FreeBSD from a supported CDROM drive then this is generally the best\n\ method to use unless you have some overriding reason for using another\n\ method."
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
name|mediaSetCDROM
block|,
literal|0
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
name|mediaSetDOS
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"File System"
block|,
literal|"Install from a mounted filesystem"
block|,
name|DMENU_CALL
block|,
name|mediaSetUFS
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Floppy"
block|,
literal|"Install from a floppy disk set"
block|,
name|DMENU_CALL
block|,
name|mediaSetFloppy
block|,
literal|0
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
name|mediaSetFTP
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"NFS"
block|,
literal|"Install over NFS"
block|,
name|DMENU_CALL
block|,
name|mediaSetNFS
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Tape"
block|,
literal|"Install from SCSI or QIC tape"
block|,
name|DMENU_CALL
block|,
name|mediaSetTape
block|,
literal|0
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
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose Installation Type"
block|,
literal|"As a convenience, we provide several \"canned\" installation types.\n\ These select what we consider to be the most reasonable defaults for the\n\ type of system in question.  If you would prefer to pick and choose\n\ the list of distributions yourself, simply select \"custom\"."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"Developer"
block|,
literal|"Full sources, binaries and doc but no games [171MB]"
block|,
name|DMENU_CALL
block|,
name|distSetDeveloper
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"X-Developer"
block|,
literal|"Same as above, but includes XFree86 [196MB]"
block|,
name|DMENU_CALL
block|,
name|distSetXDeveloper
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Kern-Developer"
block|,
literal|"Full binaries and doc, kernel sources only [35MB]"
block|,
name|DMENU_CALL
block|,
name|distSetKernDeveloper
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"User"
block|,
literal|"Average user - binaries and doc but no sources [19MB]"
block|,
name|DMENU_CALL
block|,
name|distSetUser
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"X-User"
block|,
literal|"Same as above, but includes XFree86 [45MB]"
block|,
name|DMENU_CALL
block|,
name|distSetXUser
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Minimal"
block|,
literal|"The smallest configuration possible [15MB]"
block|,
name|DMENU_CALL
block|,
name|distSetMinimum
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Everything"
block|,
literal|"All sources, binaries and XFree86 binaries [203MB]"
block|,
name|DMENU_CALL
block|,
name|distSetEverything
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Custom"
block|,
literal|"Specify your own distribution set [?]"
block|,
name|DMENU_SUBMENU
block|,
operator|&
name|MenuDistributions
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Reset"
block|,
literal|"Reset selected distribution list to None"
block|,
name|DMENU_CALL
block|,
name|distReset
block|,
literal|0
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

begin_function
specifier|static
name|char
modifier|*
name|srcFlagCheck
parameter_list|(
name|DMenuItem
modifier|*
name|item
parameter_list|)
block|{
if|if
condition|(
name|isDebug
argument_list|()
condition|)
name|msgDebug
argument_list|(
literal|"Dists& DIST_SRC = %d\n"
argument_list|,
name|Dists
operator|&
name|DIST_SRC
argument_list|)
expr_stmt|;
return|return
operator|(
name|Dists
operator|&
name|DIST_SRC
operator|)
condition|?
literal|"ON"
else|:
literal|"OFF"
return|;
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|x11FlagCheck
parameter_list|(
name|DMenuItem
modifier|*
name|item
parameter_list|)
block|{
if|if
condition|(
name|isDebug
argument_list|()
condition|)
name|msgDebug
argument_list|(
literal|"Dists& DIST_XF86 = %d\n"
argument_list|,
name|Dists
operator|&
name|DIST_XF86
argument_list|)
expr_stmt|;
return|return
operator|(
name|Dists
operator|&
name|DIST_XF86
operator|)
condition|?
literal|"ON"
else|:
literal|"OFF"
return|;
block|}
end_function

begin_decl_stmt
name|DMenu
name|MenuDistributions
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select the distributions you wish to install."
block|,
literal|"Please check off the distributions you wish to install.  At the\n\ very minimum, this should be \"bin\".  WARNING:  Do not export the\n\ DES distribution out of the U.S.!  It is for U.S. customers only."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"bin"
block|,
literal|"Binary base distribution (required) [36MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_BIN
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"commercial"
block|,
literal|"Commercial demos and shareware [10MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_COMMERCIAL
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"compat1x"
block|,
literal|"FreeBSD 1.x binary compatibility package [2MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_COMPAT1X
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"compat20"
block|,
literal|"FreeBSD 2.0 binary compatibility package [2MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_COMPAT20
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"DES"
block|,
literal|"DES encryption code and sources [.3MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_DES
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"dict"
block|,
literal|"Spelling checker dictionary files [4.2MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_DICT
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"games"
block|,
literal|"Games and other amusements (non-commercial) [6.4MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_GAMES
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"info"
block|,
literal|"GNU info files [4.1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_INFO
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"man"
block|,
literal|"System manual pages - strongly recommended [3.3MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_MANPAGES
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"proflibs"
block|,
literal|"Profiled versions of the libraries [3.3MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|Dists
block|,
name|DIST_PROFLIBS
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"src"
block|,
literal|"Sources for everything but DES [120MB]"
block|,
name|DMENU_CALL
block|,
name|distSetSrc
block|,
literal|0
block|,
literal|0
block|,
name|srcFlagCheck
block|}
block|,
block|{
literal|"XFree86"
block|,
literal|"The XFree86 3.1.1u1 distribution [?]"
block|,
name|DMENU_CALL
block|,
name|distSetXF86
block|,
literal|0
block|,
literal|0
block|,
name|x11FlagCheck
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
name|MenuSrcDistributions
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select the sub-components of src you wish to install."
block|,
literal|"Please check off those portions of the FreeBSD source tree\n\ you wish to install."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"base"
block|,
literal|"top-level files in /usr/src [300K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_BASE
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"gnu"
block|,
literal|"/usr/src/gnu (software from the GNU Project) [42MB]]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_GNU
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"etc"
block|,
literal|"/usr/src/etc (miscellaneous system files) [460K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_ETC
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"games"
block|,
literal|"/usr/src/games (diversions) [7.8MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_GAMES
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"include"
block|,
literal|"/usr/src/include (header files) [467K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_INCLUDE
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"lib"
block|,
literal|"/usr/src/lib (system libraries) [9.2MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_LIB
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"libexec"
block|,
literal|"/usr/src/libexec (system programs) [1.2MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_LIBEXEC
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"lkm"
block|,
literal|"/usr/src/lkm (Loadable Kernel Modules) [193K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_LKM
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"release"
block|,
literal|"/usr/src/release (release-generation tools) [533K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_RELEASE
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"sbin"
block|,
literal|"/usr/src/sbin (system binaries) [1.3MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_SBIN
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"share"
block|,
literal|"/usr/src/share (documents and shared files) [10MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_SHARE
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"sys"
block|,
literal|"/usr/src/sys (FreeBSD kernel) [13MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_SYS
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"ubin"
block|,
literal|"/usr/src/usr.bin (user binaries) [13MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_UBIN
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"usbin"
block|,
literal|"/usr/src/usr.sbin (aux system binaries) [14MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|SrcDists
block|,
name|DIST_SRC_USBIN
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|clearx11
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
name|XF86Dists
operator|=
literal|0
expr_stmt|;
name|XF86ServerDists
operator|=
literal|0
expr_stmt|;
name|XF86FontDists
operator|=
literal|0
expr_stmt|;
name|Dists
operator|&=
operator|~
name|DIST_XF86
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|DMenu
name|MenuXF86Select
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"XFree86 3.1.1u1 Distribution"
block|,
literal|"Please select the components you need from the XFree86 3.1.1u1\n\ distribution.  We recommend that you select what you need from the basic\n\ components set and at least one entry from the Server and Font set menus."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86.hlp"
block|,
block|{
block|{
literal|"Basic"
block|,
literal|"Basic component menu (required)"
block|,
comment|/* B */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuXF86SelectCore
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Server"
block|,
literal|"X server menu"
block|,
comment|/* S */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuXF86SelectServer
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Fonts"
block|,
literal|"Font set menu"
block|,
comment|/* F */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuXF86SelectFonts
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Reset XFree86 distribution list"
block|,
name|DMENU_CALL
block|,
name|clearx11
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
comment|/* E */
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
name|MenuXF86SelectCore
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"XFree86 3.1.1 base distribution types"
block|,
literal|"Please check off the basic XFree86 components you wish to install."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86.hlp"
block|,
block|{
block|{
literal|"bin"
block|,
literal|"X client applications and shared libs [4MB]."
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_BIN
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"lib"
block|,
literal|"Data files needed at runtime [600K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_LIB
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"xicf"
block|,
literal|"Customizable xinit runtime configuration file [100K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_XINIT
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"xdcf"
block|,
literal|"Customizable xdm runtime configuration file [100K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_XDMCF
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"doc"
block|,
literal|"READMEs and XFree86 specific man pages [500K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_DOC
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"man"
block|,
literal|"Man pages (except XFree86 specific ones) [1.2MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_MAN
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"prog"
block|,
literal|"Programmer's header and library files [4MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_PROG
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"link"
block|,
literal|"X Server reconfiguration kit [7.8MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_LINK
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"pex"
block|,
literal|"PEX fonts and libs needed by PEX apps [500K]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_PEX
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"sources"
block|,
literal|"XFree86 3.1.1u1 source + contrib distribution [200MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86Dists
block|,
name|DIST_XF86_SRC
block|,
literal|0
block|,
name|dmenuFlagCheck
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
name|MenuXF86SelectFonts
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Font distribution selection."
block|,
literal|"Please check off the individual font distributions you wish to\n\ install.  At the minimum, you should install the standard\n\ 75 DPI and misc fonts if you're also installing a server\n\ (these are selected by default)."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86.hlp"
block|,
block|{
block|{
literal|"fnts"
block|,
literal|"Standard 75 DPI and miscellaneous fonts [3.6MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86FontDists
block|,
name|DIST_XF86_FONTS_MISC
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"f100"
block|,
literal|"100 DPI fonts [1.8MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86FontDists
block|,
name|DIST_XF86_FONTS_100
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"fscl"
block|,
literal|"Speedo and Type scalable fonts [1.6MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86FontDists
block|,
name|DIST_XF86_FONTS_SCALE
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"non"
block|,
literal|"Japanese, Chinese and other non-english fonts [3.3MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86FontDists
block|,
name|DIST_XF86_FONTS_NON
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"server"
block|,
literal|"Font server [0.3MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86FontDists
block|,
name|DIST_XF86_FONTS_SERVER
block|,
literal|0
block|,
name|dmenuFlagCheck
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
name|MenuXF86SelectServer
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"X Server selection."
block|,
literal|"Please check off the types of X servers you wish to install.\n\ If you are unsure as to which server will work for your graphics card,\n\ it is recommended that try the SVGA or VGA16 servers (the VGA16 and\n\ Mono servers are particularly well-suited to most LCD displays)."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86.hlp"
block|,
block|{
block|{
literal|"SVGA"
block|,
literal|"Standard VGA or Super VGA display [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_SVGA
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"VGA16"
block|,
literal|"Standard 16 color VGA display [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_VGA16
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"Mono"
block|,
literal|"Standard Monochrome display [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_MONO
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"8514"
block|,
literal|"8-bit (256 color) IBM 8514 or compatible card [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_8514
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"AGX"
block|,
literal|"8-bit AGX card [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_AGX
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"Ma8"
block|,
literal|"8-bit ATI Mach8 card [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_MACH8
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"Ma32"
block|,
literal|"8 and 16-bit (65K color) for ATI Mach32 card [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_MACH32
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"Ma64"
block|,
literal|"8 and 16-bit (65K color) for ATI Mach64 card [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_MACH64
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"P9K"
block|,
literal|"8, 16, and 24-bit color for Weitek P9000 based boards [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_P9000
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"S3"
block|,
literal|"8, 16 and 24-bit color for S3 based boards [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_S3
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"W32"
block|,
literal|"8-bit Color for ET4000/W32, /W32i and /W32p cards [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_W32
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"nest"
block|,
literal|"A nested server for testing purposes [1MB]"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|XF86ServerDists
block|,
name|DIST_XF86_SERVER_NEST
block|,
literal|0
block|,
name|dmenuFlagCheck
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
name|MenuDiskDevices
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select Drive(s)"
block|,
literal|"Please select the drive, or drives, on which you wish to install\n\ FreeBSD.  You need to select at least one drive containing some free\n\ space, though FreeBSD can be installed across several drives if you do\n\ not have the required space on a single drive.  If you wish to boot\n\ off a drive that's not a `zero drive', or have multiple operating\n\ systems on your machine, you will have the option to install a boot\n\ manager later.  To select a drive, use the arrow keys to move to it\n\ and press [SPACE]."
block|,
literal|"Press F1 for important information regarding geometry!"
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
comment|/* Local work func for MenuOptions */
end_comment

begin_function
specifier|static
name|int
name|clearFlags
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
block|{
name|OptFlags
operator|=
literal|0
expr_stmt|;
return|return
literal|1
return|;
comment|/* Gross, but forces menu rebuild */
block|}
end_function

begin_function
specifier|static
name|char
modifier|*
name|ftpFlagCheck
parameter_list|(
name|DMenuItem
modifier|*
name|item
parameter_list|)
block|{
comment|/* Verify that everything's sane */
if|if
condition|(
operator|(
name|OptFlags
operator|&
operator|(
name|OPT_FTP_ABORT
operator|+
name|OPT_FTP_RESELECT
operator|)
operator|)
operator|==
operator|(
name|OPT_FTP_ABORT
operator|+
name|OPT_FTP_RESELECT
operator|)
condition|)
name|OptFlags
operator|&=
operator|~
name|OPT_FTP_RESELECT
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|OptFlags
operator|&
operator|(
name|OPT_FTP_ABORT
operator|+
name|OPT_FTP_RESELECT
operator|)
operator|)
condition|)
name|OptFlags
operator||=
name|OPT_FTP_ABORT
expr_stmt|;
if|if
condition|(
operator|(
name|OptFlags
operator|&
operator|(
name|OPT_FTP_ACTIVE
operator|+
name|OPT_FTP_PASSIVE
operator|)
operator|)
operator|==
operator|(
name|OPT_FTP_ACTIVE
operator|+
name|OPT_FTP_PASSIVE
operator|)
condition|)
name|OptFlags
operator|&=
operator|~
name|OPT_FTP_ACTIVE
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|OptFlags
operator|&
operator|(
name|OPT_FTP_ACTIVE
operator|+
name|OPT_FTP_PASSIVE
operator|)
operator|)
condition|)
name|OptFlags
operator||=
name|OPT_FTP_PASSIVE
expr_stmt|;
if|if
condition|(
operator|*
operator|(
operator|(
name|unsigned
name|int
operator|*
operator|)
name|item
operator|->
name|ptr
operator|)
operator|&
name|item
operator|->
name|parm
condition|)
return|return
literal|"ON"
return|;
return|return
literal|"OFF"
return|;
block|}
end_function

begin_comment
comment|/* The installation options menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuOptions
init|=
block|{
name|DMENU_MULTIPLE_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose Installation Options"
block|,
literal|"The following options control how this utility will deal\n\ with various possible error conditions and how verbose it will\n\ be at various stages."
block|,
literal|"Press F1 for more help on these options"
block|,
literal|"options.hlp"
block|,
block|{
block|{
literal|"NFS Secure"
block|,
literal|"NFS server talks only on a secure port"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_NFS_SECURE
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"NFS Slow"
block|,
literal|"User is using a slow PC or ethernet card"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_SLOW_ETHER
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"FTP Abort"
block|,
literal|"On transfer failure, abort"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_FTP_ABORT
block|,
literal|0
block|,
name|ftpFlagCheck
block|}
block|,
block|{
literal|"FTP Reselect"
block|,
literal|"On transfer failure, ask for another host"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_FTP_RESELECT
block|,
literal|0
block|,
name|ftpFlagCheck
block|}
block|,
block|{
literal|"FTP active"
block|,
literal|"Use \"active mode\" for standard FTP"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_FTP_ACTIVE
block|,
literal|0
block|,
name|ftpFlagCheck
block|}
block|,
block|{
literal|"FTP passive"
block|,
literal|"Use \"passive mode\" for firewalled FTP"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_FTP_PASSIVE
block|,
literal|0
block|,
name|ftpFlagCheck
block|}
block|,
block|{
literal|"Debugging"
block|,
literal|"Turn on the extra debugging flag"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_DEBUG
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"Yes To All"
block|,
literal|"Assume \"Yes\" answers to all non-critical dialogs"
block|,
name|DMENU_SET_FLAG
block|,
operator|&
name|OptFlags
block|,
name|OPT_NO_CONFIRM
block|,
literal|0
block|,
name|dmenuFlagCheck
block|}
block|,
block|{
literal|"FTP userpass"
block|,
literal|"Specify username and password instead of anonymous"
block|,
name|DMENU_CALL
block|,
name|mediaSetFtpUserPass
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Clear All Option Flags"
block|,
name|DMENU_CALL
block|,
name|clearFlags
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
literal|"Before installation can continue, you need to specify a few\n\ details on the type of distribution you wish to have, where you wish\n\ to install it from and how you wish to allocate disk storage to FreeBSD.\n\n\ None of the items in this menu will actually modify the contents of\n\ your disk until you select the \"Install\" menu item (and even then, only\n\ after a final confirmation)."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install.hlp"
block|,
block|{
block|{
literal|"Partition"
block|,
literal|"Allocate disk space for FreeBSD"
block|,
comment|/* P */
name|DMENU_CALL
block|,
name|diskPartitionEditor
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Label"
block|,
literal|"Label allocated disk partitions"
block|,
comment|/* L */
name|DMENU_CALL
block|,
name|diskLabelEditor
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Distributions"
block|,
literal|"Choose the type of installation you want"
block|,
comment|/* T */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuInstallType
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Media"
block|,
literal|"Choose the installation media type"
block|,
comment|/* M */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuMedia
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Options"
block|,
literal|"Go to Options submenu"
block|,
comment|/* O */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuOptions
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Commit"
block|,
literal|"Install FreeBSD onto your hard disk(s)"
block|,
comment|/* C */
name|DMENU_CALL
block|,
name|installCommit
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Configure"
block|,
literal|"Do post-install configuration of FreeBSD"
block|,
comment|/* C */
name|DMENU_SUBMENU
block|,
operator|&
name|MenuConfigure
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
comment|/* MBR type menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuMBRType
init|=
block|{
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Chose boot manager type"
block|,
comment|/* title */
literal|"FreeBSD comes with a boot selector that allows you to easily\n\ select between FreeBSD and other operating systems on your machine\n\ at boot time.  If you have more than one drive and wish to boot\n\ from other than the first, the boot selector will also allow you\n\ to do so (limitations in the PC BIOS usually prevent this otherwise).\n\ If you do not want a boot selector, or wish to replace an existing\n\ one, select \"standard\".  If you would prefer your Master Boot\n\ Record to remain untouched, then select \"none\"."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install.hlp"
block|,
block|{
block|{
literal|"BootMgr"
block|,
literal|"Install the FreeBSD Boot Manager (\"Booteasy\")"
block|,
comment|/* B */
name|DMENU_SET_VALUE
block|,
operator|&
name|BootMgr
block|,
literal|0
block|,
literal|0
block|,
name|dmenuRadioCheck
block|}
block|,
block|{
literal|"Standard"
block|,
literal|"Use a standard MBR (no boot manager)"
block|,
comment|/* S */
name|DMENU_SET_VALUE
block|,
operator|&
name|BootMgr
block|,
literal|1
block|,
literal|0
block|,
name|dmenuRadioCheck
block|}
block|,
block|{
literal|"None"
block|,
literal|"Leave the Master Boot Record untouched"
block|,
comment|/* N */
name|DMENU_SET_VALUE
block|,
operator|&
name|BootMgr
block|,
literal|2
block|,
literal|0
block|,
name|dmenuRadioCheck
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
comment|/* Final configuration menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuConfigure
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"FreeBSD Configuration Menu"
block|,
comment|/* title */
literal|"If you've already installed FreeBSD, you may use this menu to\n\ customize it somewhat to suit your particular configuration.  Most\n\ importantly, you can use the Packages utility to load extra \"3rd party\"\n\ software not provided in the base distributions."
block|,
literal|"Press F1 for more information on these options"
block|,
literal|"configure.hlp"
block|,
block|{
block|{
literal|"Add User"
block|,
literal|"Add users to the system"
block|,
name|DMENU_SYSTEM_COMMAND
block|,
literal|"adduser -silent"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Console"
block|,
literal|"Customize system console behavior"
block|,
name|DMENU_SUBMENU
block|,
operator|&
name|MenuSyscons
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Networking"
block|,
literal|"Configure additional network services"
block|,
name|DMENU_SUBMENU
block|,
operator|&
name|MenuNetworking
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Time Zone"
block|,
literal|"Set which time zone you're in"
block|,
name|DMENU_SYSTEM_COMMAND
block|,
literal|"tzsetup"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Packages"
block|,
literal|"Install extra FreeBSD packaged software"
block|,
name|DMENU_CALL
block|,
name|configPackages
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Ports"
block|,
literal|"Enable the FreeBSD Ports Collection from CD"
block|,
name|DMENU_CALL
block|,
name|configPorts
block|,
literal|0
block|,
literal|1
block|}
block|,
block|{
literal|"Root Password"
block|,
literal|"Set the system manager's password"
block|,
name|DMENU_SYSTEM_COMMAND
block|,
literal|"passwd root"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"XFree86"
block|,
literal|"Configure XFree86 (if installed)"
block|,
name|DMENU_SYSTEM_COMMAND
block|,
literal|"PATH=/usr/bin:/bin:/usr/X11R6/bin xf86config"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
name|MenuNetworking
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Network Services Menu"
block|,
literal|"You may have already configured one network device (and the\n\ other various hostname/gateway/name server parameters) in the process\n\ of installing FreeBSD.  This menu allows you to configure other\n\ aspects of your system's network configuration."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"NFS client"
block|,
literal|"This machine will be an NFS client"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"nfs_client=YES"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"NFS server"
block|,
literal|"This machine will be an NFS server"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"nfs_server=YES"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Interfaces"
block|,
literal|"Configure network interfaces"
block|,
name|DMENU_CALL
block|,
name|tcpMenuSelect
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"ntpdate"
block|,
literal|"Select a clock-syncronization server"
block|,
name|DMENU_SUBMENU
block|,
operator|&
name|MenuNTP
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"routed"
block|,
literal|"Set flags for routed (default: -q)"
block|,
name|DMENU_CALL
block|,
name|configRoutedFlags
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"rwhod"
block|,
literal|"This machine wants to run the rwho daemon"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"rwhod=YES"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
name|MenuNTP
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"NTPDATE Server Selection"
block|,
literal|"There are a number of time syncronization servers available\n\ for public use around the Internet.  Please select one reasonably\n\ close to you to have your system time syncronized accordingly."
block|,
literal|"These are the primary open-access NTP servers"
block|,
name|NULL
block|,
block|{
block|{
literal|"Other"
block|,
literal|"Select a site not on this list"
block|,
name|DMENU_CALL
block|,
name|configNTP
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Australia"
block|,
literal|"ntp.syd.dms.csiro.au (HP 5061 Cesium Beam)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=ntp.syd.dms.csiro.au"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Canada"
block|,
literal|"tick.usask.ca (GOES clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=tick.usask.ca"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"France"
block|,
literal|"canon.inria.fr (TDF clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=canon.inria.fr"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Germany"
block|,
literal|"ntps1-{0,1,2}.uni-erlangen.de (GPS)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=ntps1-0.uni-erlangen.de"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Germany #2"
block|,
literal|"ntps1-0.cs.tu-berlin.de (GPS)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=ntps1-0.cs.tu-berlin.de"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan"
block|,
literal|"clock.nc.fukuoka-u.ac.jp (GPS clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=clock.nc.fukuoka-u.ac.jp"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Japan #2"
block|,
literal|"clock.tl.fukuoka-u.ac.jp (GPS clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=clock.tl.fukuoka-u.ac.jp"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Netherlands"
block|,
literal|"ntp0.nl.net (GPS clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=ntp0.nl.net"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Norway"
block|,
literal|"timer.unik.no (NTP clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=timer.unik.no"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Sweden"
block|,
literal|"Time1.Stupi.SE (Cesium/GPS)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=Time1.Stupi.SE"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Switzerland"
block|,
literal|"swisstime.ethz.ch (DCF77 clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=swisstime.ethz.ch"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. East Coast"
block|,
literal|"bitsy.mit.edu (WWV clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=bitsy.mit.edu"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. East Coast #2"
block|,
literal|"otc1.psu.edu (WWV clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=otc1.psu.edu"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. West Coast"
block|,
literal|"apple.com (WWV clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=apple.com"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. West Coast #2"
block|,
literal|"clepsydra.dec.com (GOES clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=clepsydra.dec.com"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. West Coast #3"
block|,
literal|"clock.llnl.gov (WWVB clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=clock.llnl.gov"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. Midwest"
block|,
literal|"ncar.ucar.edu (WWVB clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=ncar.ucar.edu"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. Pacific"
block|,
literal|"chantry.hawaii.net (WWV/H clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=chantry.hawaii.net"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. Southwest"
block|,
literal|"shorty.chpc.utexas.edu (WWV clock)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"ntpdate=shorty.chpc.utexas.edu"
block|,
literal|0
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
name|MenuSyscons
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"System Console Configuration"
block|,
literal|"The default system console driver for FreeBSD (syscons) has a\n\ number of configuration options which may be set according to\n\ your preference.\n\n\ When you are done setting configuration options, select Cancel."
block|,
literal|"Configure your system console settings"
block|,
name|NULL
block|,
block|{
block|{
literal|"Keymap"
block|,
literal|"Choose an alternate keyboard map"
block|,
name|DMENU_SUBMENU
block|,
operator|&
name|MenuSysconsKeymap
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Repeat"
block|,
literal|"Set the rate at which keys repeat"
block|,
name|DMENU_SUBMENU
block|,
operator|&
name|MenuSysconsKeyrate
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Saver"
block|,
literal|"Configure the screen saver"
block|,
name|DMENU_SUBMENU
block|,
operator|&
name|MenuSysconsSaver
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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
name|MenuSysconsKeymap
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"System Console Keymap"
block|,
literal|"The default system console driver for FreeBSD (syscons) defaults\n\ to a standard \"American\" keyboard map.  Users in other countries\n\ (or with different keyboard preferences) may wish to choose one of\n\ the other keymaps below."
block|,
literal|"Choose a keyboard map"
block|,
name|NULL
block|,
block|{
block|{
literal|"Danish CP865"
block|,
literal|"Danish Code Page 865 keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=danish.cp865"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Danish ISO"
block|,
literal|"Danish ISO keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=danish.iso"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"French ISO"
block|,
literal|"French ISO keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=fr.iso"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"German CP850"
block|,
literal|"German Code Page 850 keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=german.cp850"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"German ISO"
block|,
literal|"German ISO keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=german.iso"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Russian CP866"
block|,
literal|"Russian Code Page 866 keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=ru.cp866"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Russian KOI8"
block|,
literal|"Russian koi8 keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=ru.koi8-r"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Russian s-KOI8"
block|,
literal|"Russian shifted koi8 keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=ru.koi8-r.shift"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Swedish CP850"
block|,
literal|"Swedish Code Page 850 keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=swedish.cp850"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Swedish ISO"
block|,
literal|"Swedish ISO keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=swedish.iso"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.K. CP850"
block|,
literal|"United Kingdom Code Page 850 keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=uk.cp850"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.K. ISO"
block|,
literal|"United Kingdom ISO keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=uk.iso"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"U.S. ISO"
block|,
literal|"United States ISO keymap"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keymap=us.iso"
block|,
literal|0
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
name|MenuSysconsKeyrate
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"System Console Keyboard Repeat Rate"
block|,
literal|"This menu allows you to set the speed at which keys repeat\n\ when held down."
block|,
literal|"Choose a keyboard repeat rate"
block|,
name|NULL
block|,
block|{
block|{
literal|"Slow"
block|,
literal|"Slow keyboard repeat rate"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keyrate=slow"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Normal"
block|,
literal|"\"Normal\" keyboard repeat rate"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keyrate=normal"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Fast"
block|,
literal|"Fast keyboard repeat rate"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keyrate=fast"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Default"
block|,
literal|"Use default keyboard repeat rate"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"keyrate=NO"
block|,
literal|0
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
name|MenuSysconsSaver
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"System Console Screen Saver"
block|,
literal|"By default, the console driver will not attempt to do anything\n\ special with your screen when it's idle.  If you expect to leave your\n\ monitor switched on and idle for long periods of time then you should\n\ probably enable one of these screen savers to prevent phosphor burn-in."
block|,
literal|"Choose a nifty-looking screen saver"
block|,
name|NULL
block|,
block|{
block|{
literal|"blank"
block|,
literal|"Simply blank the screen"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"saver=star"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Green"
block|,
literal|"\"Green\" power saving mode (if supported by monitor)"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"saver=snake"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Snake"
block|,
literal|"Draw a FreeBSD \"snake\" on your screen"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"saver=snake"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Star"
block|,
literal|"A \"twinkling stars\" effect"
block|,
name|DMENU_SET_VARIABLE
block|,
literal|"saver=star"
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Timeout"
block|,
literal|"Set the screen saver timeout interval"
block|,
name|DMENU_CALL
block|,
name|configSaverTimeout
block|,
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|DMENU_CANCEL
block|,
name|NULL
block|,
literal|0
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

