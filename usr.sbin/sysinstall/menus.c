begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $Id: menus.c,v 1.85 1996/09/08 01:39:25 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|"sysinstall.h"
end_include

begin_comment
comment|/* Miscellaneous work routines for menus */
end_comment

begin_function
specifier|static
name|int
name|setSrc
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|Dists
operator||=
name|DIST_SRC
expr_stmt|;
name|SrcDists
operator|=
name|DIST_SRC_ALL
operator||
name|DIST_SRC_SMAILCF
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|clearSrc
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|Dists
operator|&=
operator|~
name|DIST_SRC
expr_stmt|;
name|SrcDists
operator|=
literal|0
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|setX11All
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XF86Dists
operator|=
name|DIST_XF86_ALL
expr_stmt|;
name|XF86ServerDists
operator|=
name|DIST_XF86_SERVER_ALL
expr_stmt|;
name|XF86FontDists
operator|=
name|DIST_XF86_FONTS_ALL
expr_stmt|;
name|Dists
operator||=
name|DIST_XF86
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|clearX11All
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
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
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|setX11Misc
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XF86Dists
operator||=
name|DIST_XF86_MISC_ALL
expr_stmt|;
name|Dists
operator||=
name|DIST_XF86
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|clearX11Misc
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XF86Dists
operator|&=
operator|~
name|DIST_XF86_MISC_ALL
expr_stmt|;
if|if
condition|(
operator|!
name|XF86ServerDists
operator|&&
operator|!
name|XF86FontDists
condition|)
name|Dists
operator|&=
operator|~
name|DIST_XF86
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|setX11Servers
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XF86Dists
operator||=
name|DIST_XF86_SERVER
expr_stmt|;
name|XF86ServerDists
operator|=
name|DIST_XF86_SERVER_ALL
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|clearX11Servers
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XF86Dists
operator|&=
operator|~
name|DIST_XF86_SERVER
expr_stmt|;
name|XF86ServerDists
operator|=
literal|0
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|setX11Fonts
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XF86Dists
operator||=
name|DIST_XF86_FONTS
expr_stmt|;
name|XF86FontDists
operator|=
name|DIST_XF86_FONTS_ALL
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|clearX11Fonts
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XF86Dists
operator|&=
operator|~
name|DIST_XF86_FONTS
expr_stmt|;
name|XF86FontDists
operator|=
literal|0
expr_stmt|;
return|return
name|DITEM_SUCCESS
operator||
name|DITEM_REDRAW
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IS_DEVELOPER
parameter_list|(
name|dist
parameter_list|,
name|extra
parameter_list|)
value|(((dist) == (_DIST_DEVELOPER | (extra))) || ((dist) == (_DIST_DEVELOPER | DIST_DES | (extra))))
end_define

begin_define
define|#
directive|define
name|IS_USER
parameter_list|(
name|dist
parameter_list|,
name|extra
parameter_list|)
value|(((dist) == (_DIST_USER | (extra))) || ((dist) == (_DIST_USER | DIST_DES | (extra))))
end_define

begin_function
specifier|static
name|int
name|checkDistDeveloper
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
name|IS_DEVELOPER
argument_list|(
name|Dists
argument_list|,
literal|0
argument_list|)
operator|&&
name|SrcDists
operator|==
name|DIST_SRC_ALL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkDistXDeveloper
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
name|IS_DEVELOPER
argument_list|(
name|Dists
argument_list|,
name|DIST_XF86
argument_list|)
operator|&&
name|SrcDists
operator|==
name|DIST_SRC_ALL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkDistKernDeveloper
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
name|IS_DEVELOPER
argument_list|(
name|Dists
argument_list|,
literal|0
argument_list|)
operator|&&
name|SrcDists
operator|==
name|DIST_SRC_SYS
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkDistUser
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
name|IS_USER
argument_list|(
name|Dists
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkDistXUser
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
name|IS_USER
argument_list|(
name|Dists
argument_list|,
name|DIST_XF86
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkDistMinimum
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
name|Dists
operator|==
name|DIST_BIN
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkDistEverything
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
operator|(
name|Dists
operator|==
name|DIST_ALL
operator|&&
name|SrcDists
operator|==
name|DIST_SRC_ALL
operator|&&
name|XF86Dists
operator|==
name|DIST_XF86_ALL
operator|&&
name|XF86ServerDists
operator|==
name|DIST_XF86_SERVER_ALL
operator|&&
name|XF86FontDists
operator|==
name|DIST_XF86_FONTS_ALL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|DESFlagCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
block|{
return|return
name|DESDists
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|srcFlagCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
block|{
return|return
name|SrcDists
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|x11FlagCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
block|{
return|return
name|XF86Dists
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkTrue
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* All the system menus go here.  *  * Hardcoded things like version number strings will disappear from  * these menus just as soon as I add the code for doing inline variable  * expansion.  */
end_comment

begin_decl_stmt
name|DMenu
name|MenuIndex
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Glossary of functions"
block|,
literal|"This menu contains an alphabetized index of the top level functions in\n"
literal|"this program (sysinstall).  Invoke an option by pressing [ENTER].\n"
literal|"Leave the index page by selecting Cancel [TAB-ENTER]."
block|,
literal|"Use PageUp or PageDown to move through this menu faster!"
block|,
name|NULL
block|,
block|{
block|{
literal|"Add User"
block|,
literal|"Add users to the system."
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"adduser -config_create ; adduser -s"
block|}
block|,
block|{
literal|"Anon FTP"
block|,
literal|"Configure anonymous FTP logins."
block|,
name|dmenuVarCheck
block|,
name|configAnonFTP
block|,
name|NULL
block|,
literal|"anon_ftp"
block|}
block|,
block|{
literal|"Commit"
block|,
literal|"Commit any pending actions (dangerous!)"
block|,
name|NULL
block|,
name|installCustomCommit
block|}
block|,
block|{
literal|"Console settings"
block|,
literal|"Customize system console behavior."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSyscons
block|}
block|,
block|{
literal|"Configure"
block|,
literal|"The system configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuConfigure
block|}
block|,
block|{
literal|"Device, Mouse"
block|,
literal|"The mouse configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMouse
block|}
block|,
block|{
literal|"Dists, All"
block|,
literal|"Root of the distribution tree."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuDistributions
block|}
block|,
block|{
literal|"Dists, Basic"
block|,
literal|"Basic FreeBSD distribution menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSubDistributions
block|}
block|,
block|{
literal|"Dists, DES"
block|,
literal|"DES distribution menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuDESDistributions
block|}
block|,
block|{
literal|"Dists, Developer"
block|,
literal|"Select developer's distribution."
block|,
name|checkDistDeveloper
block|,
name|distSetDeveloper
block|}
block|,
block|{
literal|"Dists, Src"
block|,
literal|"Src distribution menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSrcDistributions
block|}
block|,
block|{
literal|"Dists, X Developer"
block|,
literal|"Select X developer's distribution."
block|,
name|checkDistXDeveloper
block|,
name|distSetXDeveloper
block|}
block|,
block|{
literal|"Dists, Kern Developer"
block|,
literal|"Select kernel developer's distribution."
block|,
name|checkDistKernDeveloper
block|,
name|distSetKernDeveloper
block|}
block|,
block|{
literal|"Dists, User"
block|,
literal|"Select average user distribution."
block|,
name|checkDistUser
block|,
name|distSetUser
block|}
block|,
block|{
literal|"Dists, X User"
block|,
literal|"Select average X user distribution."
block|,
name|checkDistXUser
block|,
name|distSetXUser
block|}
block|,
block|{
literal|"Distributions, XFree86"
block|,
literal|"XFree86 distribution menu."
block|,
name|NULL
block|,
name|distSetXF86
block|}
block|,
block|{
literal|"Documentation"
block|,
literal|"Installation instructions, README, etc."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuDocumentation
block|}
block|,
block|{
literal|"Doc, README"
block|,
literal|"The distribution README file."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"readme"
block|}
block|,
block|{
literal|"Doc, Hardware"
block|,
literal|"The distribution hardware guide."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"hardware"
block|}
block|,
block|{
literal|"Doc, Install"
block|,
literal|"The distribution installation guide."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"install"
block|}
block|,
block|{
literal|"Doc, Copyright"
block|,
literal|"The distribution copyright notices."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"COPYRIGHT"
block|}
block|,
block|{
literal|"Doc, Release"
block|,
literal|"The distribution release notes."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"relnotes"
block|}
block|,
block|{
literal|"Doc, HTML"
block|,
literal|"The HTML documentation menu."
block|,
name|NULL
block|,
name|docBrowser
block|}
block|,
block|{
literal|"Extract"
block|,
literal|"Extract selected distributions from media."
block|,
name|NULL
block|,
name|distExtractAll
block|}
block|,
block|{
literal|"Fixit"
block|,
literal|"Repair mode with CDROM or floppy."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuFixit
block|}
block|,
block|{
literal|"FTP sites"
block|,
literal|"The FTP mirror site listing."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMediaFTP
block|}
block|,
block|{
literal|"Gated"
block|,
literal|"Load and configure gated instead of routed."
block|,
name|dmenuVarCheck
block|,
name|configGated
block|,
name|NULL
block|,
literal|"gated"
block|}
block|,
block|{
literal|"Gateway"
block|,
literal|"Set flag to route packets between interfaces."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"gateway=YES"
block|}
block|,
block|{
literal|"HTML Docs"
block|,
literal|"The HTML documentation menu"
block|,
name|NULL
block|,
name|docBrowser
block|}
block|,
block|{
literal|"Install, Novice"
block|,
literal|"A novice system installation."
block|,
name|NULL
block|,
name|installNovice
block|}
block|,
block|{
literal|"Install, Express"
block|,
literal|"An express system installation."
block|,
name|NULL
block|,
name|installExpress
block|}
block|,
block|{
literal|"Install, Custom"
block|,
literal|"The custom installation menu"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuInstallCustom
block|}
block|,
block|{
literal|"Label"
block|,
literal|"The disk Label editor"
block|,
name|NULL
block|,
name|diskLabelEditor
block|}
block|,
block|{
literal|"Media"
block|,
literal|"Top level media selection menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMedia
block|}
block|,
block|{
literal|"Media, Tape"
block|,
literal|"Select tape installation media."
block|,
name|NULL
block|,
name|mediaSetTape
block|}
block|,
block|{
literal|"Media, NFS"
block|,
literal|"Select NFS installation media."
block|,
name|NULL
block|,
name|mediaSetNFS
block|}
block|,
block|{
literal|"Media, Floppy"
block|,
literal|"Select floppy installation media."
block|,
name|NULL
block|,
name|mediaSetFloppy
block|}
block|,
block|{
literal|"Media, CDROM"
block|,
literal|"Select CDROM installation media."
block|,
name|NULL
block|,
name|mediaSetCDROM
block|}
block|,
block|{
literal|"Media, DOS"
block|,
literal|"Select DOS installation media."
block|,
name|NULL
block|,
name|mediaSetDOS
block|}
block|,
block|{
literal|"Media, UFS"
block|,
literal|"Select UFS installation media."
block|,
name|NULL
block|,
name|mediaSetUFS
block|}
block|,
block|{
literal|"Media, FTP"
block|,
literal|"Select FTP installation media."
block|,
name|NULL
block|,
name|mediaSetFTP
block|}
block|,
block|{
literal|"Media, FTP Passive"
block|,
literal|"Select passive FTP installation media."
block|,
name|NULL
block|,
name|mediaSetFTPPassive
block|}
block|,
block|{
literal|"Network Interfaces"
block|,
literal|"Configure network interfaces"
block|,
name|NULL
block|,
name|tcpMenuSelect
block|}
block|,
block|{
literal|"Networking Services"
block|,
literal|"The network services menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuNetworking
block|}
block|,
block|{
literal|"NFS, client"
block|,
literal|"Set NFS client flag."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"nfs_client=YES"
block|}
block|,
block|{
literal|"NFS, server"
block|,
literal|"Set NFS server flag."
block|,
name|dmenuVarCheck
block|,
name|configNFSServer
block|,
name|NULL
block|,
literal|"nfs_server"
block|}
block|,
block|{
literal|"NTP Menu"
block|,
literal|"The NTP configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuNTP
block|}
block|,
block|{
literal|"Options"
block|,
literal|"The options editor."
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
block|{
literal|"Packages"
block|,
literal|"The packages collection"
block|,
name|NULL
block|,
name|configPackages
block|}
block|,
block|{
literal|"Partition"
block|,
literal|"The disk Partition Editor"
block|,
name|NULL
block|,
name|diskPartitionEditor
block|}
block|,
block|{
literal|"PCNFSD"
block|,
literal|"Run authentication server for PC-NFS."
block|,
name|dmenuVarCheck
block|,
name|configPCNFSD
block|,
name|NULL
block|,
literal|"pcnfsd"
block|}
block|,
block|{
literal|"Ports"
block|,
literal|"Link to FreeBSD ports collection."
block|,
name|NULL
block|,
name|configPorts
block|}
block|,
block|{
literal|"Root Password"
block|,
literal|"Set the system manager's password."
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"passwd root"
block|}
block|,
block|{
literal|"Routed"
block|,
literal|"Set flags for routed (default: -q)"
block|,
name|dmenuVarCheck
block|,
name|configRoutedFlags
block|,
name|NULL
block|,
literal|"routed"
block|}
block|,
block|{
literal|"Samba"
block|,
literal|"Configure Samba for LanManager access."
block|,
name|dmenuVarCheck
block|,
name|configSamba
block|,
name|NULL
block|,
literal|"samba"
block|}
block|,
block|{
literal|"Syscons"
block|,
literal|"The system console configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSyscons
block|}
block|,
block|{
literal|"Syscons, Keymap"
block|,
literal|"The console keymap configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsKeymap
block|}
block|,
block|{
literal|"Syscons, Keyrate"
block|,
literal|"The console key rate configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsKeyrate
block|}
block|,
block|{
literal|"Syscons, Saver"
block|,
literal|"The console screen saver configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsSaver
block|}
block|,
block|{
literal|"Time Zone"
block|,
literal|"Set the system's time zone."
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"rm -f /etc/wall_cmos_clock /etc/localtime; tzsetup"
block|}
block|,
block|{
literal|"Upgrade"
block|,
literal|"Upgrade an existing system."
block|,
name|NULL
block|,
name|installUpgrade
block|}
block|,
block|{
literal|"Usage"
block|,
literal|"Quick start - How to use this menu system."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"usage"
block|}
block|,
block|{
literal|"WEB Server"
block|,
literal|"Configure host as a WWW server."
block|,
name|dmenuVarCheck
block|,
name|configApache
block|,
name|NULL
block|,
literal|"apache_httpd"
block|}
block|,
block|{
literal|"XFree86, Fonts"
block|,
literal|"XFree86 Font selection menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXF86SelectFonts
block|}
block|,
block|{
literal|"XFree86, Server"
block|,
literal|"XFree86 Server selection menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXF86SelectServer
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
comment|/* The initial installation menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuInitial
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Welcome to FreeBSD!"
block|,
comment|/* title */
literal|"This is the main menu of the FreeBSD installation system.  Please\n"
comment|/* prompt */
literal|"select one of the options below by using the arrow keys or typing the\n"
literal|"first character of the option name you're interested in.  Invoke an\n"
literal|"option by pressing [ENTER] or [TAB-ENTER] to exit the installation."
block|,
literal|"Press F1 for Installation Guide"
block|,
comment|/* help line */
literal|"install"
block|,
comment|/* help file */
block|{
block|{
literal|"Select"
block|}
block|,
block|{
literal|"Exit Install"
block|,
name|NULL
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"1 Usage"
block|,
literal|"Quick start - How to use this menu system"
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"usage"
block|}
block|,
block|{
literal|"2 Doc"
block|,
literal|"Installation instructions, README, etc."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuDocumentation
block|}
block|,
block|{
literal|"3 Options"
block|,
literal|"Go to the options editor"
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
block|{
literal|"4 Novice"
block|,
literal|"Begin a novice installation (for beginners)"
block|,
name|NULL
block|,
name|installNovice
block|}
block|,
block|{
literal|"5 Express"
block|,
literal|"Begin a quick installation (for the impatient)"
block|,
name|NULL
block|,
name|installExpress
block|}
block|,
block|{
literal|"6 Custom"
block|,
literal|"Begin a custom installation (for experts)"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuInstallCustom
block|}
block|,
block|{
literal|"7 Fixit"
block|,
literal|"Go into repair mode with CDROM or floppy"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuFixit
block|}
block|,
block|{
literal|"8 Upgrade"
block|,
literal|"Upgrade an existing system"
block|,
name|NULL
block|,
name|installUpgrade
block|}
block|,
block|{
literal|"9 Configure"
block|,
literal|"Do post-install configuration of FreeBSD"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuConfigure
block|}
block|,
block|{
literal|"0 Index"
block|,
literal|"Glossary of functions."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuIndex
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
name|MenuFixit
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Please choose a fixit option"
block|,
literal|"There are two ways of going into \"fixit\" mode - you may either elect\n\ to use the 2nd FreeBSD CDROM, in which case there will be full access\n\ access to the complete set of FreeBSD commands and utilities, or you\n\ can use the more limited fixit floppy if you don't have a CDROM or are\n\ somehow faced with a situation where a CDROM is impractical.  The fixit\n\ floppy has only a minimal subset of commands which we deemed most useful\n\ for fixing a system in trouble."
block|,
literal|"Press F1 for more detailed repair instructions"
block|,
literal|"fixit"
block|,
block|{
block|{
literal|"1 CDROM"
block|,
literal|"Use the 2nd \"live\" CDROM from the distribution"
block|,
name|NULL
block|,
name|installFixitCDROM
block|}
block|,
block|{
literal|"2 Floppy"
block|,
literal|"Use a floppy generated from the fixit image"
block|,
name|NULL
block|,
name|installFixitFloppy
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
literal|"Documentation for FreeBSD "
name|RELEASE_NAME
block|,
literal|"If you are at all unsure about the configuration of your hardware\n\ or are looking to build a system specifically for FreeBSD, read the\n\ Hardware guide!  New users should also read the Install document for\n\ a step-by-step tutorial on installing FreeBSD.  For general information,\n\ consult the README file."
block|,
literal|"Confused?  Press F1 for help."
block|,
literal|"usage"
block|,
block|{
block|{
literal|"1 README"
block|,
literal|"A general description of FreeBSD.  Read this!"
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"readme"
block|}
block|,
block|{
literal|"2 Hardware"
block|,
literal|"The FreeBSD survival guide for PC hardware."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"hardware"
block|}
block|,
block|{
literal|"3 Install"
block|,
literal|"A step-by-step guide to installing FreeBSD."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"install"
block|}
block|,
block|{
literal|"4 Copyright"
block|,
literal|"The FreeBSD Copyright notices."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"COPYRIGHT"
block|}
block|,
block|{
literal|"5 Release"
block|,
literal|"The release notes for this version of FreeBSD."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"relnotes"
block|}
block|,
block|{
literal|"6 Shortcuts"
block|,
literal|"Creating shortcuts to sysinstall."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"shortcuts"
block|}
block|,
block|{
literal|"7 HTML Docs"
block|,
literal|"Go to the HTML documentation menu (post-install)."
block|,
name|NULL
block|,
name|docBrowser
block|}
block|,
block|{
literal|"0 Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
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
name|whichMouse
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|file_readable
argument_list|(
literal|"/dev/mouse"
argument_list|)
condition|)
return|return
name|FALSE
return|;
if|if
condition|(
name|readlink
argument_list|(
literal|"/dev/mouse"
argument_list|,
name|buf
argument_list|,
name|BUFSIZ
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
name|FALSE
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|self
operator|->
name|prompt
argument_list|,
literal|"COM1"
argument_list|)
condition|)
return|return
operator|!
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"/dev/cuaa0"
argument_list|)
return|;
elseif|else
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|self
operator|->
name|prompt
argument_list|,
literal|"COM2"
argument_list|)
condition|)
return|return
operator|!
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"/dev/cuaa1"
argument_list|)
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|self
operator|->
name|prompt
argument_list|,
literal|"COM3"
argument_list|)
condition|)
return|return
operator|!
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"/dev/cuaa2"
argument_list|)
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|self
operator|->
name|prompt
argument_list|,
literal|"COM4"
argument_list|)
condition|)
return|return
operator|!
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"/dev/cuaa3"
argument_list|)
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|self
operator|->
name|prompt
argument_list|,
literal|"BusMouse"
argument_list|)
condition|)
return|return
operator|!
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"/dev/msg0"
argument_list|)
return|;
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|self
operator|->
name|prompt
argument_list|,
literal|"PS/2"
argument_list|)
condition|)
return|return
operator|!
name|strcmp
argument_list|(
name|buf
argument_list|,
literal|"/dev/psm0"
argument_list|)
return|;
return|return
name|FALSE
return|;
block|}
end_function

begin_decl_stmt
name|DMenu
name|MenuMouse
init|=
block|{
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Please select your mouse type from the following menu"
block|,
literal|"There are many different types of mice currently on the market,\n\ but this configuration menu should at least narrow down the choices\n\ somewhat.  Once you've selected one of the below, you can specify\n\ /dev/mouse as your mouse device when running the XFree86 configuration\n\ utility (see Configuration menu).  Please note that for PS/2 mice,\n\ a kernel recompile is also required!  See the handbook for more details\n\ on building a kernel."
block|,
literal|"For more information, visit the Documentation menu"
block|,
name|NULL
block|,
block|{
block|{
literal|"COM1"
block|,
literal|"Serial mouse on COM1"
block|,
name|whichMouse
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"ln -fs /dev/cuaa0 /dev/mouse"
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
literal|"COM2"
block|,
literal|"Serial mouse on COM2"
block|,
name|whichMouse
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"ln -fs /dev/cuaa1 /dev/mouse"
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
literal|"COM3"
block|,
literal|"Serial mouse on COM3"
block|,
name|whichMouse
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"ln -fs /dev/cuaa2 /dev/mouse"
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
literal|"COM4"
block|,
literal|"Serial mouse on COM4"
block|,
name|whichMouse
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"ln -fs /dev/cuaa3 /dev/mouse"
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
literal|"BusMouse"
block|,
literal|"Logitech or ATI bus mouse"
block|,
name|whichMouse
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"ln -fs /dev/mse0 /dev/mouse"
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
literal|"PS/2"
block|,
literal|"PS/2 style mouse (must enable psm0 device)"
block|,
name|whichMouse
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"ln -fs /dev/psm0 /dev/mouse"
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
literal|"FreeBSD can be installed directly from a CDROM containing a valid\n\ FreeBSD distribution.  If you are seeing this menu it is because\n\ more than one CDROM drive was found on your system.  Please select one\n\ of the following CDROM drives as your installation drive."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install"
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
literal|"You have more than one floppy drive.  Please chose which drive\n\ you would like to use."
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
literal|"install"
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
literal|"Please select a FreeBSD FTP distribution site"
block|,
literal|"Please select the site closest to you or \"other\" if you'd like to\n\ specify a different choice.  Also note that not every site listed here\n\ carries more than the base distribution kits. Only the Primary site is\n\ guaranteed to carry the full range of possible distributions."
block|,
literal|"Select a site that's close!"
block|,
literal|"install"
block|,
block|{
block|{
literal|"Primary Site"
block|,
literal|"ftp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"URL"
block|,
literal|"Specify some other ftp site by URL"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=other"
block|}
block|,
block|{
literal|"Australia"
block|,
literal|"ftp.au.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.au.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Australia #2"
block|,
literal|"ftp2.au.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.au.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Australia #3"
block|,
literal|"ftp3.au.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.au.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Australia #4"
block|,
literal|"ftp4.au.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.au.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Brazil"
block|,
literal|"ftp.br.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.br.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Brazil #2"
block|,
literal|"ftp2.br.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.br.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Brazil #3"
block|,
literal|"ftp3.br.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.br.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Brazil #4"
block|,
literal|"ftp4.br.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.br.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Brazil #5"
block|,
literal|"ftp5.br.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.br.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Canada"
block|,
literal|"ftp.ca.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ca.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Czech Republic"
block|,
literal|"sunsite.mff.cuni.cz"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://sunsite.mff.cuni.cz/OS/FreeBSD/"
block|}
block|,
block|{
literal|"Estonia"
block|,
literal|"ftp.ee.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ee.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Finland"
block|,
literal|"nic.funet.fi"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://nic.funet.fi/pub/unix/FreeBSD/"
block|}
block|,
block|{
literal|"France"
block|,
literal|"ftp.ibp.fr"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ibp.fr/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Germany"
block|,
literal|"ftp.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.de.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Germany #2"
block|,
literal|"ftp2.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.de.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Germany #3"
block|,
literal|"ftp3.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.de.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Germany #4"
block|,
literal|"ftp4.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.de.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Germany #5"
block|,
literal|"ftp5.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.de.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Germany #6"
block|,
literal|"ftp6.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.de.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Germany #7"
block|,
literal|"ftp7.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp7.de.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Holland"
block|,
literal|"ftp.nl.freebsd.ort"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.nl.freebsd.org/pub/os/FreeBSD/cdrom/"
block|}
block|,
block|{
literal|"Hong Kong"
block|,
literal|"ftp.hk.super.net"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.hk.super.net/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Ireland"
block|,
literal|"ftp.ie.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ie.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Israel"
block|,
literal|"orgchem.weizmann.ac.il"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://orgchem.weizmann.ac.il/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Israel #2"
block|,
literal|"xray4.weizmann.ac.il"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://xray4.weizmann.ac.il/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Japan"
block|,
literal|"ftp.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.jp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Japan #2"
block|,
literal|"ftp2.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.jp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Japan #3"
block|,
literal|"ftp3.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.jp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Japan #4"
block|,
literal|"ftp4.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.jp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Japan #5"
block|,
literal|"ftp5.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.jp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Japan #6"
block|,
literal|"ftp6.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.jp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Korea"
block|,
literal|"ftp.kr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.kr.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Korea #2"
block|,
literal|"ftp2.kr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.kr.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Netherlands"
block|,
literal|"ftp.nl.net"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.nl.net/pub/os/FreeBSD/"
block|}
block|,
block|{
literal|"Poland"
block|,
literal|"SunSITE.icm.edu.pl"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://SunSITE.icm.edu.pl/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Portugal"
block|,
literal|"ftp.ua.pt"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ua.pt/pub/misc/FreeBSD/"
block|}
block|,
block|{
literal|"Russia"
block|,
literal|"ftp.kiae.su"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.kiae.su/FreeBSD/"
block|}
block|,
block|{
literal|"South Africa"
block|,
literal|"ftp.za.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.za.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"South Africa #2"
block|,
literal|"ftp2.za.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.za.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"South Africa #3"
block|,
literal|"ftp3.za.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.za.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Sweden"
block|,
literal|"ftp.luth.se"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.luth.se/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Taiwan"
block|,
literal|"ftp.tw.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.tw.freebsd.org/pub/FreeBSD"
block|}
block|,
block|{
literal|"Taiwan #2"
block|,
literal|"ftp2.tw.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.tw.freebsd.org/pub/FreeBSD"
block|}
block|,
block|{
literal|"Taiwan #3"
block|,
literal|"ftp3.tw.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.tw.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"Thailand"
block|,
literal|"ftp.nectec.or.th"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.nectec.or.th/pub/mirrors/FreeBSD/"
block|}
block|,
block|{
literal|"UK"
block|,
literal|"ftp.uk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.uk.freebsd.org/pub/BSD/FreeBSD/"
block|}
block|,
block|{
literal|"UK #2"
block|,
literal|"ftp2.uk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.uk.freebsd.org/pub/BSD/FreeBSD/"
block|}
block|,
block|{
literal|"UK #3"
block|,
literal|"ftp3.uk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.uk.freebsd.org/pub/BSD/FreeBSD/"
block|}
block|,
block|{
literal|"USA"
block|,
literal|"ftp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"USA #2"
block|,
literal|"ftp2.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"USA #3"
block|,
literal|"ftp3.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"USA #4"
block|,
literal|"ftp4.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"USA #5"
block|,
literal|"ftp5.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"USA #6"
block|,
literal|"ftp6.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.freebsd.org/pub/FreeBSD/"
block|}
block|,
block|{
literal|"USA #7"
block|,
literal|"ftp7.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp7.freebsd.org/pub/FreeBSD/"
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
literal|"install"
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
literal|"Network interface information required"
block|,
literal|"If you are using PPP over a serial device, as opposed to a direct\n"
literal|"ethernet connection, then you may first need to dial your Internet\n"
literal|"Service Provider using the ppp utility we provide for that purpose.\n"
literal|"If you're using SLIP over a serial device then the expectation is\n"
literal|"that you have a HARDWIRED connection.\n\n"
literal|"You can also install over a parallel port using a special \"laplink\"\n"
literal|"cable to another machine running a fairly recent (2.0R or later) version\n"
literal|"of FreeBSD."
block|,
literal|"Press F1 to read network configuration manual"
block|,
literal|"network_device"
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
literal|"FreeBSD can be installed from a variety of different installation\n\ media, ranging from floppies to an Internet FTP server.  If you're\n\ installing FreeBSD from a supported CDROM drive then this is generally\n\ the best media to use if you have no overriding reason for using other\n\ media."
block|,
literal|"Press F1 for more information on the various media types"
block|,
literal|"media"
block|,
block|{
block|{
literal|"1 CDROM"
block|,
literal|"Install from a FreeBSD CDROM"
block|,
name|NULL
block|,
name|mediaSetCDROM
block|}
block|,
block|{
literal|"2 FTP"
block|,
literal|"Install from an FTP server"
block|,
name|NULL
block|,
name|mediaSetFTPActive
block|}
block|,
block|{
literal|"3 FTP Passive"
block|,
literal|"Install from an FTP server through a firewall"
block|,
name|NULL
block|,
name|mediaSetFTPPassive
block|}
block|,
block|{
literal|"4 DOS"
block|,
literal|"Install from a DOS partition"
block|,
name|NULL
block|,
name|mediaSetDOS
block|}
block|,
block|{
literal|"5 NFS"
block|,
literal|"Install over NFS"
block|,
name|NULL
block|,
name|mediaSetNFS
block|}
block|,
block|{
literal|"6 File System"
block|,
literal|"Install from an existing filesystem"
block|,
name|NULL
block|,
name|mediaSetUFS
block|}
block|,
block|{
literal|"7 Floppy"
block|,
literal|"Install from a floppy disk set"
block|,
name|NULL
block|,
name|mediaSetFloppy
block|}
block|,
block|{
literal|"8 Tape"
block|,
literal|"Install from SCSI or QIC tape"
block|,
name|NULL
block|,
name|mediaSetTape
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
comment|/* The distributions menu */
end_comment

begin_decl_stmt
name|DMenu
name|MenuDistributions
init|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose Distributions"
block|,
literal|"As a convenience, we provide several \"canned\" distribution sets.\n\ These select what we consider to be the most reasonable defaults for the\n\ type of system in question.  If you would prefer to pick and choose the\n\ list of distributions yourself, simply select \"Custom\".  You can also\n\ pick a canned distribution set and then fine-tune it with the Custom item.\n\n\ Choose an item by pressing [SPACE]. When you are finished, chose the Exit\n\ item or press [ENTER]."
block|,
literal|"Press F1 for more information on these options."
block|,
literal|"distributions"
block|,
block|{
block|{
literal|"1 Developer"
block|,
literal|"Full sources, binaries and doc but no games [180MB]"
block|,
name|checkDistDeveloper
block|,
name|distSetDeveloper
block|}
block|,
block|{
literal|"2 X-Developer"
block|,
literal|"Same as above, but includes XFree86 [201MB]"
block|,
name|checkDistXDeveloper
block|,
name|distSetXDeveloper
block|}
block|,
block|{
literal|"3 Kern-Developer"
block|,
literal|"Full binaries and doc, kernel sources only [70MB]"
block|,
name|checkDistKernDeveloper
block|,
name|distSetKernDeveloper
block|}
block|,
block|{
literal|"4 User"
block|,
literal|"Average user - binaries and doc only [52MB]"
block|,
name|checkDistUser
block|,
name|distSetUser
block|}
block|,
block|{
literal|"5 X-User"
block|,
literal|"Same as above, but includes XFree86 [52MB]"
block|,
name|checkDistXUser
block|,
name|distSetXUser
block|}
block|,
block|{
literal|"6 Minimal"
block|,
literal|"The smallest configuration possible [44MB]"
block|,
name|checkDistMinimum
block|,
name|distSetMinimum
block|}
block|,
block|{
literal|"7 All"
block|,
literal|"All sources, binaries and XFree86 binaries [700MB]"
block|,
name|checkDistEverything
block|,
name|distSetEverything
block|}
block|,
block|{
literal|"8 Custom"
block|,
literal|"Specify your own distribution set [?]"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSubDistributions
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"9 Clear"
block|,
literal|"Reset selected distribution list to nothing [0MB]"
block|,
name|NULL
block|,
name|distReset
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"0 Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|MenuSubDistributions
init|=
block|{
name|DMENU_CHECKLIST_TYPE
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
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_BIN
block|}
block|,
block|{
literal|"commerce"
block|,
literal|"Commercial and shareware demos [10MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_COMMERCIAL
block|}
block|,
block|{
literal|"compat1x"
block|,
literal|"FreeBSD 1.x binary compatibility [2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_COMPAT1X
block|}
block|,
block|{
literal|"compat20"
block|,
literal|"FreeBSD 2.0 binary compatibility [2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_COMPAT20
block|}
block|,
block|{
literal|"compat21"
block|,
literal|"FreeBSD 2.1 binary compatibility [2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_COMPAT21
block|}
block|,
block|{
literal|"DES"
block|,
literal|"DES encryption code - NOT FOR EXPORT! [.3MB]"
block|,
name|DESFlagCheck
block|,
name|distSetDES
block|}
block|,
block|{
literal|"dict"
block|,
literal|"Spelling checker dictionary files [4.2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_DICT
block|}
block|,
block|{
literal|"doc"
block|,
literal|"FreeBSD Handbook and other online docs [10MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_DOC
block|}
block|,
block|{
literal|"games"
block|,
literal|"Games (non-commercial) [6.4MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_GAMES
block|}
block|,
block|{
literal|"info"
block|,
literal|"GNU info files [4.1MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_INFO
block|}
block|,
block|{
literal|"man"
block|,
literal|"System manual pages - recommended [3.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_MANPAGES
block|}
block|,
block|{
literal|"proflibs"
block|,
literal|"Profiled versions of the libraries [3.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_PROFLIBS
block|}
block|,
block|{
literal|"src"
block|,
literal|"Sources for everything but DES [120MB]"
block|,
name|srcFlagCheck
block|,
name|distSetSrc
block|}
block|,
block|{
literal|"XFree86"
block|,
literal|"The XFree86 3.1.2-S distribution"
block|,
name|x11FlagCheck
block|,
name|distSetXF86
block|}
block|,
block|{
literal|"xperimnt"
block|,
literal|"Experimental work in progress!"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_EXPERIMENTAL
block|}
block|,
block|{
literal|"All"
block|,
literal|"All sources, binaries and XFree86 binaries [700MB]"
block|,
name|NULL
block|,
name|distSetEverything
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Reset all of the above [0MB]"
block|,
name|NULL
block|,
name|distReset
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|MenuDESDistributions
init|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select the encryption facilities you wish to install."
block|,
literal|"Please check off any special DES-based encryption distributions\n\ you would like to install.  Please note that these services are NOT FOR\n\ EXPORT from the United States.  For information on non-U.S. FTP\n\ distributions of this software, please consult the release notes."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"des"
block|,
literal|"Basic DES encryption services [1MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|DESDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_DES_DES
block|, }
block|,
block|{
literal|"krb"
block|,
literal|"Kerberos encryption services [2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|DESDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_DES_KERBEROS
block|}
block|,
block|{
literal|"sebones"
block|,
literal|"Sources for eBones (Kerberos) [1MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|DESDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_DES_SEBONES
block|}
block|,
block|{
literal|"ssecure"
block|,
literal|"Sources for DES [1MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|DESDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_DES_SSECURE
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|DMENU_CHECKLIST_TYPE
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
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_BASE
block|}
block|,
block|{
literal|"gnu"
block|,
literal|"/usr/src/gnu (software from the GNU Project) [42MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_GNU
block|}
block|,
block|{
literal|"etc"
block|,
literal|"/usr/src/etc (miscellaneous system files) [460K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_ETC
block|}
block|,
block|{
literal|"games"
block|,
literal|"/usr/src/games (the obvious!) [7.8MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_GAMES
block|}
block|,
block|{
literal|"include"
block|,
literal|"/usr/src/include (header files) [467K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_INCLUDE
block|}
block|,
block|{
literal|"lib"
block|,
literal|"/usr/src/lib (system libraries) [9.2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_LIB
block|}
block|,
block|{
literal|"libexec"
block|,
literal|"/usr/src/libexec (system programs) [1.2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_LIBEXEC
block|}
block|,
block|{
literal|"lkm"
block|,
literal|"/usr/src/lkm (Loadable Kernel Modules) [193K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_LKM
block|}
block|,
block|{
literal|"release"
block|,
literal|"/usr/src/release (release-generation tools) [533K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_RELEASE
block|}
block|,
block|{
literal|"bin"
block|,
literal|"/usr/src/bin (system binaries) [2.5MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_BIN
block|}
block|,
block|{
literal|"sbin"
block|,
literal|"/usr/src/sbin (system binaries) [1.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_SBIN
block|}
block|,
block|{
literal|"share"
block|,
literal|"/usr/src/share (documents and shared files) [10MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_SHARE
block|}
block|,
block|{
literal|"sys"
block|,
literal|"/usr/src/sys (FreeBSD kernel) [13MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_SYS
block|}
block|,
block|{
literal|"ubin"
block|,
literal|"/usr/src/usr.bin (user binaries) [13MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_UBIN
block|}
block|,
block|{
literal|"usbin"
block|,
literal|"/usr/src/usr.sbin (aux system binaries) [14MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_USBIN
block|}
block|,
block|{
literal|"smailcf"
block|,
literal|"/usr/src/usr.sbin (sendmail config macros) [341K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_SMAILCF
block|}
block|,
block|{
literal|"All"
block|,
literal|"Select all of the above [120MB]"
block|,
name|NULL
block|,
name|setSrc
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Reset all of the above [0MB]"
block|,
name|NULL
block|,
name|clearSrc
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|MenuXF86Select
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"XFree86 3.1.2-S Distribution"
block|,
literal|"Please select the components you need from the XFree86 3.1.2-S\n\ distribution.  We recommend that you select what you need from the basic\n\ component set and at least one entry from the Server and Font set menus."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86"
block|,
block|{
block|{
literal|"Basic"
block|,
literal|"Basic component menu (required)"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXF86SelectCore
block|}
block|,
block|{
literal|"Server"
block|,
literal|"X server menu"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXF86SelectServer
block|}
block|,
block|{
literal|"Fonts"
block|,
literal|"Font set menu"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXF86SelectFonts
block|}
block|,
block|{
literal|"All"
block|,
literal|"Select the entire XFree86 distribution"
block|,
name|NULL
block|,
name|setX11All
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Reset XFree86 distribution list"
block|,
name|NULL
block|,
name|clearX11All
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"XFree86 3.1.2-S base distribution types"
block|,
literal|"Please check off the basic XFree86 components you wish to install.\n\ Bin, lib, xicf, and xdcf are recommended for a minimum installaion."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86"
block|,
block|{
block|{
literal|"bin"
block|,
literal|"Client applications and shared libs [4.1MB]."
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_BIN
block|}
block|,
block|{
literal|"lib"
block|,
literal|"Data files needed at runtime [750K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_LIB
block|}
block|,
block|{
literal|"xicf"
block|,
literal|"Customizable xinit runtime configuration file [10K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_XINIT
block|}
block|,
block|{
literal|"xdcf"
block|,
literal|"Customizable xdm runtime configuration file [20K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_XDMCF
block|}
block|,
block|{
literal|"etc"
block|,
literal|"Clock setting and diagnostic source codes [70K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_ETC
block|}
block|,
block|{
literal|"doc"
block|,
literal|"READMEs and release notes [600K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_DOC
block|}
block|,
block|{
literal|"man"
block|,
literal|"Manual pages [1.7MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_MAN
block|}
block|,
block|{
literal|"ctrb"
block|,
literal|"Various contributed binaries (ico, xman, etc) [550K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_CTRB
block|}
block|,
block|{
literal|"prog"
block|,
literal|"Programmer's header and library files [4.1MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_PROG
block|}
block|,
block|{
literal|"link"
block|,
literal|"Kit to reconfigure/rebuild X Servers [8.8MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_LINK
block|}
block|,
block|{
literal|"ubin"
block|,
literal|"rstart daemon [2K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_UBIN
block|}
block|,
block|{
literal|"pex"
block|,
literal|"PEX fonts and libs needed by PEX apps [290K]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_PEX
block|}
block|,
block|{
literal|"sources"
block|,
literal|"XFree86 3.1.2-S standard + contrib sources [200MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86Dists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SRC
block|}
block|,
block|{
literal|"All"
block|,
literal|"Select all of the above [20MB]"
block|,
name|NULL
block|,
name|setX11Misc
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Reset all of the above [0MB]"
block|,
name|NULL
block|,
name|clearX11Misc
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Font distribution selection."
block|,
literal|"Please check off the individual font distributions you wish to\n\ install.  At the minimum, you should install the standard\n\ 75 DPI and misc fonts if you're also installing a server\n\ (these are selected by default)."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86"
block|,
block|{
block|{
literal|"fnts"
block|,
literal|"Standard 75 DPI and miscellaneous fonts [3.6MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86FontDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_FONTS_MISC
block|}
block|,
block|{
literal|"f100"
block|,
literal|"100 DPI fonts [1.8MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86FontDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_FONTS_100
block|}
block|,
block|{
literal|"fcyr"
block|,
literal|"Cyrillic Fonts [1.8MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86FontDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_FONTS_CYR
block|}
block|,
block|{
literal|"fscl"
block|,
literal|"Speedo and Type scalable fonts [1.6MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86FontDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_FONTS_SCALE
block|}
block|,
block|{
literal|"non"
block|,
literal|"Japanese, Chinese and other non-english fonts [3.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86FontDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_FONTS_NON
block|}
block|,
block|{
literal|"server"
block|,
literal|"Font server [0.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86FontDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_FONTS_SERVER
block|}
block|,
block|{
literal|"All"
block|,
literal|"All fonts [10MB]"
block|,
name|NULL
block|,
name|setX11Fonts
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Reset font selections [0MB]"
block|,
name|NULL
block|,
name|clearX11Fonts
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"X Server selection."
block|,
literal|"Please check off the types of X servers you wish to install.\n\ If you are unsure as to which server will work for your graphics card,\n\ it is recommended that try the SVGA or VGA16 servers (the VGA16 and\n\ Mono servers are particularly well-suited to most LCD displays)."
block|,
literal|"Press F1 to read the XFree86 release notes for FreeBSD"
block|,
literal|"XF86"
block|,
block|{
block|{
literal|"SVGA"
block|,
literal|"Standard VGA or Super VGA display [2.8MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_SVGA
block|}
block|,
block|{
literal|"VGA16"
block|,
literal|"Standard 16 color VGA display [1.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_VGA16
block|}
block|,
block|{
literal|"Mono"
block|,
literal|"Standard Monochrome display [1.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_MONO
block|}
block|,
block|{
literal|"8514"
block|,
literal|"8-bit (256 color) IBM 8514 or compatible card [2.2MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_8514
block|}
block|,
block|{
literal|"AGX"
block|,
literal|"8-bit AGX card [2.4MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_AGX
block|}
block|,
block|{
literal|"Ma8"
block|,
literal|"8-bit ATI Mach8 card [2.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_MACH8
block|}
block|,
block|{
literal|"Ma32"
block|,
literal|"8 and 16-bit (65K color) for ATI Mach32 card [2.4MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_MACH32
block|}
block|,
block|{
literal|"Ma64"
block|,
literal|"8 and 16-bit (65K color) for ATI Mach64 card [2.5MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_MACH64
block|}
block|,
block|{
literal|"P9K"
block|,
literal|"8, 16, and 24-bit color for Weitek P9000 based boards [2.5MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_P9000
block|}
block|,
block|{
literal|"S3"
block|,
literal|"8, 16 and 24-bit color for S3 based boards [2.7MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_S3
block|}
block|,
block|{
literal|"W32"
block|,
literal|"8-bit Color for ET4000/W32, /W32i and /W32p cards [2.3MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_W32
block|}
block|,
block|{
literal|"nest"
block|,
literal|"A nested server for testing purposes [1.8MB]"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XF86ServerDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XF86_SERVER_NEST
block|}
block|,
block|{
literal|"All"
block|,
literal|"Select all of the above [25MB]"
block|,
name|NULL
block|,
name|setX11Servers
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Clear"
block|,
literal|"Reset all of the above [0MB]"
block|,
name|NULL
block|,
name|clearX11Servers
block|,
name|NULL
block|,
name|NULL
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select Drive(s)"
block|,
literal|"Please select the drive, or drives, on which you wish to perform\n\ this operation.  If you are attempting to install a boot partition\n\ on a drive other than the first one or have multiple operating\n\ systems on your machine, you will have the option to install a boot\n\ manager later.  To select a drive, use the arrow keys to move to it\n\ and press [SPACE].  To de-select it, press [SPACE] again.\n\n\ Select OK or Cancel to leave this menu."
block|,
literal|"Press F1 for important information regarding disk geometry!"
block|,
literal|"drives"
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
name|MenuHTMLDoc
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Select HTML Documentation pointer"
block|,
literal|"Please select the body of documentation you're interested in, the main\n\ ones right now being the FAQ and the Handbook.  You can also chose \"other\"\n\ to enter an arbitrary URL for browsing."
block|,
literal|"Press F1 for more help on what you see here."
block|,
literal|"html"
block|,
block|{
block|{
literal|"Handbook"
block|,
literal|"The FreeBSD Handbook."
block|,
name|NULL
block|,
name|docShowDocument
block|}
block|,
block|{
literal|"FAQ"
block|,
literal|"The Frequently Asked Questions guide."
block|,
name|NULL
block|,
name|docShowDocument
block|}
block|,
block|{
literal|"Home"
block|,
literal|"The Home Pages for the FreeBSD Project (requires net)"
block|,
name|NULL
block|,
name|docShowDocument
block|}
block|,
block|{
literal|"Other"
block|,
literal|"Enter a URL."
block|,
name|NULL
block|,
name|docShowDocument
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
name|MenuInstallCustom
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Choose Custom Installation Options"
block|,
literal|"This is the custom installation menu. You may use this menu to specify\n\ details on the type of distribution you wish to have, where you wish\n\ to install it from and how you wish to allocate disk storage to FreeBSD."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install"
block|,
block|{
block|{
literal|"1 Options"
block|,
literal|"Go to Options editor"
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
block|{
literal|"2 Partition"
block|,
literal|"Allocate disk space for FreeBSD"
block|,
name|NULL
block|,
name|diskPartitionEditor
block|}
block|,
block|{
literal|"3 Label"
block|,
literal|"Label allocated disk partitions"
block|,
name|NULL
block|,
name|diskLabelEditor
block|}
block|,
block|{
literal|"4 Distributions"
block|,
literal|"Select distribution(s) to extract"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuDistributions
block|}
block|,
block|{
literal|"5 Media"
block|,
literal|"Choose the installation media type"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMedia
block|}
block|,
block|{
literal|"6 Commit"
block|,
literal|"Perform any pending Partition/Label/Extract actions"
block|,
name|NULL
block|,
name|installCustomCommit
block|}
block|,
block|{
literal|"7 Extract"
block|,
literal|"Just do distribution extract step"
block|,
name|NULL
block|,
name|distExtractAll
block|}
block|,
block|{
literal|"0 Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
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
literal|"Press F1 to read the installation guide"
block|,
literal|"install"
block|,
block|{
block|{
literal|"BootMgr"
block|,
literal|"Install the FreeBSD Boot Manager (\"Booteasy\")"
block|,
name|dmenuRadioCheck
block|,
name|dmenuSetValue
block|,
name|NULL
block|,
operator|&
name|BootMgr
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
literal|"If you've already installed FreeBSD, you may use this menu to customize\n\ it somewhat to suit your particular configuration.  Most importantly,\n\ you can use the Packages utility to load extra \"3rd party\"\n\ software not provided in the base distributions."
block|,
literal|"Press F1 for more information on these options"
block|,
literal|"configure"
block|,
block|{
block|{
literal|"1 Add User"
block|,
literal|"Add users to the system"
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"adduser -config_create ; adduser -s"
block|}
block|,
block|{
literal|"2 Console"
block|,
literal|"Customize system console behavior"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSyscons
block|}
block|,
block|{
literal|"3 Time Zone"
block|,
literal|"Set which time zone you're in"
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"rm -f /etc/wall_cmos_clock /etc/localtime; tzsetup"
block|}
block|,
block|{
literal|"4 Media"
block|,
literal|"Change the installation media type"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMedia
block|}
block|,
block|{
literal|"5 Mouse"
block|,
literal|"Select the type of mouse you have"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMouse
block|,
name|NULL
block|}
block|,
block|{
literal|"6 Networking"
block|,
literal|"Configure additional network services"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuNetworking
block|}
block|,
block|{
literal|"7 Options"
block|,
literal|"Go to options editor"
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
block|{
literal|"8 Packages"
block|,
literal|"Install pre-packaged software for FreeBSD"
block|,
name|NULL
block|,
name|configPackages
block|}
block|,
block|{
literal|"9 Ports"
block|,
literal|"Link to FreeBSD Ports Collection on CD"
block|,
name|NULL
block|,
name|configPorts
block|}
block|,
block|{
literal|"A Root Password"
block|,
literal|"Set the system manager's password"
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"passwd root"
block|}
block|,
block|{
literal|"B HTML Docs"
block|,
literal|"Go to the HTML documentation menu (post-install)"
block|,
name|NULL
block|,
name|docBrowser
block|}
block|,
block|{
literal|"C XFree86"
block|,
literal|"Configure XFree86"
block|,
name|NULL
block|,
name|configXFree86
block|}
block|,
block|{
literal|"0 Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
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
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Network Services Menu"
block|,
literal|"You may have already configured one network device (and the other\n\ various hostname/gateway/name server parameters) in the process\n\ of installing FreeBSD.  This menu allows you to configure other\n\ aspects of your system's network configuration."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"Interfaces"
block|,
literal|"Configure additional network interfaces"
block|,
name|NULL
block|,
name|tcpMenuSelect
block|}
block|,
block|{
literal|"NFS client"
block|,
literal|"This machine will be an NFS client"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"nfs_client=YES"
block|}
block|,
block|{
literal|"NFS server"
block|,
literal|"This machine will be an NFS server"
block|,
name|dmenuVarCheck
block|,
name|configNFSServer
block|,
name|NULL
block|,
literal|"nfs_server"
block|}
block|,
block|{
literal|"Gateway"
block|,
literal|"This machine will route packets between interfaces"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"gateway=YES"
block|}
block|,
block|{
literal|"Gated"
block|,
literal|"This machine wants to run gated instead of routed"
block|,
name|dmenuVarCheck
block|,
name|configGated
block|,
name|NULL
block|,
literal|"gated"
block|}
block|,
block|{
literal|"Netcon"
block|,
literal|"Install the Novell client/server demo package"
block|,
name|dmenuVarCheck
block|,
name|configNovell
block|,
name|NULL
block|,
literal|"novell"
block|}
block|,
block|{
literal|"Ntpdate"
block|,
literal|"Select a clock-syncronization server"
block|,
name|dmenuVarCheck
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuNTP
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
operator|(
name|int
operator|)
name|VAR_NTPDATE
block|}
block|,
block|{
literal|"Routed"
block|,
literal|"Set flags for routed (default: -q)"
block|,
name|dmenuVarCheck
block|,
name|configRoutedFlags
block|,
name|NULL
block|,
literal|"routed"
block|}
block|,
block|{
literal|"Rwhod"
block|,
literal|"This machine wants to run the rwho daemon"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"rwhod=YES"
block|}
block|,
block|{
literal|"Anon FTP"
block|,
literal|"This machine wishes to allow anonymous FTP."
block|,
name|dmenuVarCheck
block|,
name|configAnonFTP
block|,
name|NULL
block|,
literal|"anon_ftp"
block|}
block|,
block|{
literal|"WEB Server"
block|,
literal|"This machine wishes to be a WWW server."
block|,
name|dmenuVarCheck
block|,
name|configApache
block|,
name|NULL
block|,
literal|"apache_httpd"
block|}
block|,
block|{
literal|"Samba"
block|,
literal|"Install Samba for LanManager (NETBUI) access."
block|,
name|dmenuVarCheck
block|,
name|configSamba
block|,
name|NULL
block|,
literal|"samba"
block|}
block|,
block|{
literal|"PCNFSD"
block|,
literal|"Run authentication server for clients with PC-NFS."
block|,
name|dmenuVarCheck
block|,
name|configPCNFSD
block|,
name|NULL
block|,
literal|"pcnfsd"
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|checkTrue
block|,
name|dmenuExit
block|,
name|NULL
block|,
name|NULL
block|,
literal|'<'
block|,
literal|'<'
block|,
literal|'<'
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
name|DMENU_RADIO_TYPE
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
name|dmenuVarCheck
block|,
name|configNTP
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|"Australia"
block|,
literal|"ntp.syd.dms.csiro.au (HP 5061 Cesium Beam)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=ntp.syd.dms.csiro.au"
block|}
block|,
block|{
literal|"Canada"
block|,
literal|"tick.usask.ca (GOES clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=tick.usask.ca"
block|}
block|,
block|{
literal|"France"
block|,
literal|"canon.inria.fr (TDF clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=canon.inria.fr"
block|}
block|,
block|{
literal|"Germany"
block|,
literal|"ntps1-{0,1,2}.uni-erlangen.de (GPS)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=ntps1-0.uni-erlangen.de"
block|}
block|,
block|{
literal|"Germany #2"
block|,
literal|"ntps1-0.cs.tu-berlin.de (GPS)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=ntps1-0.cs.tu-berlin.de"
block|}
block|,
block|{
literal|"Japan"
block|,
literal|"clock.nc.fukuoka-u.ac.jp (GPS clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=clock.nc.fukuoka-u.ac.jp"
block|}
block|,
block|{
literal|"Japan #2"
block|,
literal|"clock.tl.fukuoka-u.ac.jp (GPS clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=clock.tl.fukuoka-u.ac.jp"
block|}
block|,
block|{
literal|"Netherlands"
block|,
literal|"ntp0.nl.net (GPS clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=ntp0.nl.net"
block|}
block|,
block|{
literal|"Norway"
block|,
literal|"timer.unik.no (NTP clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=timer.unik.no"
block|}
block|,
block|{
literal|"Sweden"
block|,
literal|"Time1.Stupi.SE (Cesium/GPS)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=Time1.Stupi.SE"
block|}
block|,
block|{
literal|"Switzerland"
block|,
literal|"swisstime.ethz.ch (DCF77 clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=swisstime.ethz.ch"
block|}
block|,
block|{
literal|"U.S. East Coast"
block|,
literal|"bitsy.mit.edu (WWV clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=bitsy.mit.edu"
block|}
block|,
block|{
literal|"U.S. East Coast #2"
block|,
literal|"otc1.psu.edu (WWV clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=otc1.psu.edu"
block|}
block|,
block|{
literal|"U.S. West Coast"
block|,
literal|"apple.com (WWV clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=apple.com"
block|}
block|,
block|{
literal|"U.S. West Coast #2"
block|,
literal|"clepsydra.dec.com (GOES clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=clepsydra.dec.com"
block|}
block|,
block|{
literal|"U.S. West Coast #3"
block|,
literal|"clock.llnl.gov (WWVB clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=clock.llnl.gov"
block|}
block|,
block|{
literal|"U.S. Midwest"
block|,
literal|"ncar.ucar.edu (WWVB clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=ncar.ucar.edu"
block|}
block|,
block|{
literal|"U.S. Pacific"
block|,
literal|"chantry.hawaii.net (WWV/H clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=chantry.hawaii.net"
block|}
block|,
block|{
literal|"U.S. Southwest"
block|,
literal|"shorty.chpc.utexas.edu (WWV clock)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_NTPDATE
literal|"=shorty.chpc.utexas.edu"
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
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsKeymap
block|}
block|,
block|{
literal|"Repeat"
block|,
literal|"Set the rate at which keys repeat"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsKeyrate
block|}
block|,
block|{
literal|"Saver"
block|,
literal|"Configure the screen saver"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsSaver
block|}
block|,
block|{
literal|"Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
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
name|DMENU_RADIO_TYPE
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
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=danish.cp865"
block|}
block|,
block|{
literal|"Danish ISO"
block|,
literal|"Danish ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=danish.iso"
block|}
block|,
block|{
literal|"French ISO"
block|,
literal|"French ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=fr.iso"
block|}
block|,
block|{
literal|"German CP850"
block|,
literal|"German Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=german.cp850"
block|}
block|,
block|{
literal|"German ISO"
block|,
literal|"German ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=german.iso"
block|}
block|,
block|{
literal|"Italian"
block|,
literal|"Italian ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=it.iso"
block|}
block|,
block|{
literal|"Japanese 106"
block|,
literal|"Japanese 106 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=jp.106"
block|}
block|,
block|{
literal|"Swedish CP850"
block|,
literal|"Swedish Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=swedish.cp850"
block|}
block|,
block|{
literal|"Swedish ISO"
block|,
literal|"Swedish ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=swedish.iso"
block|}
block|,
block|{
literal|"U.K. CP850"
block|,
literal|"United Kingdom Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=uk.cp850"
block|}
block|,
block|{
literal|"U.K. ISO"
block|,
literal|"United Kingdom ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=uk.iso"
block|}
block|,
block|{
literal|"U.S. ISO"
block|,
literal|"United States ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keymap=us.iso"
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
name|DMENU_RADIO_TYPE
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
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keyrate=slow"
block|}
block|,
block|{
literal|"Normal"
block|,
literal|"\"Normal\" keyboard repeat rate"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keyrate=normal"
block|}
block|,
block|{
literal|"Fast"
block|,
literal|"Fast keyboard repeat rate"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keyrate=fast"
block|}
block|,
block|{
literal|"Default"
block|,
literal|"Use default keyboard repeat rate"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"keyrate=NO"
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
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
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
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"saver=blank"
block|}
block|,
block|{
literal|"Green"
block|,
literal|"\"Green\" power saving mode (if supported by monitor)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"saver=green"
block|}
block|,
block|{
literal|"Snake"
block|,
literal|"Draw a FreeBSD \"snake\" on your screen"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"saver=snake"
block|}
block|,
block|{
literal|"Star"
block|,
literal|"A \"twinkling stars\" effect"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"saver=star"
block|}
block|,
block|{
literal|"Timeout"
block|,
literal|"Set the screen saver timeout interval"
block|,
name|dmenuVarCheck
block|,
name|configSaverTimeout
block|,
name|NULL
block|,
literal|"blanktime"
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
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

