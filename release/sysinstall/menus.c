begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * $FreeBSD$  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
expr_stmt|;
name|CRYPTODists
operator||=
operator|(
name|DIST_CRYPTO_SCRYPTO
operator||
name|DIST_CRYPTO_SSECURE
operator||
name|DIST_CRYPTO_SKERBEROS4
operator||
name|DIST_CRYPTO_SKERBEROS5
operator|)
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
name|CRYPTODists
operator|&=
operator|~
operator|(
name|DIST_CRYPTO_SCRYPTO
operator||
name|DIST_CRYPTO_SSECURE
operator||
name|DIST_CRYPTO_SKERBEROS4
operator||
name|DIST_CRYPTO_SKERBEROS5
operator|)
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
name|_IS_SET
parameter_list|(
name|dist
parameter_list|,
name|set
parameter_list|)
value|(((dist)& (set)) == (set))
end_define

begin_define
define|#
directive|define
name|IS_DEVELOPER
parameter_list|(
name|dist
parameter_list|,
name|extra
parameter_list|)
value|(_IS_SET(dist, _DIST_DEVELOPER | extra) || \ 	_IS_SET(dist, _DIST_DEVELOPER | extra))
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
value|(_IS_SET(dist, _DIST_USER | extra) || \ 	_IS_SET(dist, _DIST_USER | extra))
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
name|IS_DEVELOPER
argument_list|(
name|Dists
argument_list|,
literal|0
argument_list|)
operator|&&
name|_IS_SET
argument_list|(
name|SrcDists
argument_list|,
name|DIST_SRC_ALL
argument_list|)
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
name|IS_DEVELOPER
argument_list|(
name|Dists
argument_list|,
name|DIST_XF86
argument_list|)
operator|&&
name|_IS_SET
argument_list|(
name|SrcDists
argument_list|,
name|DIST_SRC_ALL
argument_list|)
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
name|IS_DEVELOPER
argument_list|(
name|Dists
argument_list|,
literal|0
argument_list|)
operator|&&
name|_IS_SET
argument_list|(
name|SrcDists
argument_list|,
name|DIST_SRC_SYS
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|checkDistXKernDeveloper
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
return|return
name|IS_DEVELOPER
argument_list|(
name|Dists
argument_list|,
name|DIST_XF86
argument_list|)
operator|&&
name|_IS_SET
argument_list|(
name|SrcDists
argument_list|,
name|DIST_SRC_SYS
argument_list|)
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
name|IS_USER
argument_list|(
name|Dists
argument_list|,
literal|0
argument_list|)
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
name|IS_USER
argument_list|(
name|Dists
argument_list|,
name|DIST_XF86
argument_list|)
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
name|Dists
operator|==
name|DIST_BIN
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
name|Dists
operator|==
name|DIST_ALL
operator|&&
name|CRYPTODists
operator|==
name|DIST_CRYPTO_ALL
operator|&&
expr|\
name|_IS_SET
argument_list|(
name|SrcDists
argument_list|,
name|DIST_SRC_ALL
argument_list|)
operator|&&
expr|\
name|_IS_SET
argument_list|(
name|XF86Dists
argument_list|,
name|DIST_XF86_ALL
argument_list|)
operator|&&
expr|\
name|_IS_SET
argument_list|(
name|XF86ServerDists
argument_list|,
name|DIST_XF86_SERVER_ALL
argument_list|)
operator|&&
expr|\
name|_IS_SET
argument_list|(
name|XF86FontDists
argument_list|,
name|DIST_XF86_FONTS_ALL
argument_list|)
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
name|Dists
operator|&
name|DIST_XF86
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
literal|" Anon FTP"
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
literal|" Commit"
block|,
literal|"Commit any pending actions (dangerous!)"
block|,
name|NULL
block|,
name|installCustomCommit
block|}
block|,
block|{
literal|" Console settings"
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
literal|" Configure"
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
literal|" Defaults, Load"
block|,
literal|"Load default settings."
block|,
name|NULL
block|,
name|dispatch_load_floppy
block|}
block|,
block|{
literal|" Device, Mouse"
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
literal|" Disklabel"
block|,
literal|"The disk Label editor"
block|,
name|NULL
block|,
name|diskLabelEditor
block|}
block|,
block|{
literal|" Dists, All"
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
literal|" Dists, Basic"
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
literal|" Dists, Developer"
block|,
literal|"Select developer's distribution."
block|,
name|checkDistDeveloper
block|,
name|distSetDeveloper
block|}
block|,
block|{
literal|" Dists, Src"
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
literal|" Dists, X Developer"
block|,
literal|"Select X developer's distribution."
block|,
name|checkDistXDeveloper
block|,
name|distSetXDeveloper
block|}
block|,
block|{
literal|" Dists, Kern Developer"
block|,
literal|"Select kernel developer's distribution."
block|,
name|checkDistKernDeveloper
block|,
name|distSetKernDeveloper
block|}
block|,
block|{
literal|" Dists, User"
block|,
literal|"Select average user distribution."
block|,
name|checkDistUser
block|,
name|distSetUser
block|}
block|,
block|{
literal|" Dists, X User"
block|,
literal|"Select average X user distribution."
block|,
name|checkDistXUser
block|,
name|distSetXUser
block|}
block|,
block|{
literal|" Distributions, Adding"
block|,
literal|"Installing additional distribution sets"
block|,
name|NULL
block|,
name|distExtractAll
block|}
block|,
block|{
literal|" Distributions, XFree86"
block|,
literal|"XFree86 distribution menu."
block|,
name|NULL
block|,
name|distSetXF86
block|}
block|,
block|{
literal|" Documentation"
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
literal|" Doc, README"
block|,
literal|"The distribution README file."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"README"
block|}
block|,
block|{
literal|" Doc, Hardware"
block|,
literal|"The distribution hardware guide."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"HARDWARE"
block|}
block|,
block|{
literal|" Doc, Install"
block|,
literal|"The distribution installation guide."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"INSTALL"
block|}
block|,
block|{
literal|" Doc, Copyright"
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
literal|" Doc, Release"
block|,
literal|"The distribution release notes."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"RELNOTES"
block|}
block|,
block|{
literal|" Doc, HTML"
block|,
literal|"The HTML documentation menu."
block|,
name|NULL
block|,
name|docBrowser
block|}
block|,
block|{
literal|" Dump Vars"
block|,
literal|"(debugging) dump out internal variables."
block|,
name|NULL
block|,
name|dump_variables
block|}
block|,
block|{
literal|" Emergency shell"
block|,
literal|"Start an Emergency Holographic shell."
block|,
name|NULL
block|,
name|installFixitHoloShell
block|}
block|,
ifdef|#
directive|ifdef
name|__i386__
block|{
literal|" Fdisk"
block|,
literal|"The disk Partition Editor"
block|,
name|NULL
block|,
name|diskPartitionEditor
block|}
block|,
endif|#
directive|endif
block|{
literal|" Fixit"
block|,
literal|"Repair mode with CDROM or fixit floppy."
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
literal|" FTP sites"
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
literal|" Gateway"
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
literal|" HTML Docs"
block|,
literal|"The HTML documentation menu"
block|,
name|NULL
block|,
name|docBrowser
block|}
block|,
block|{
literal|" Install, Standard"
block|,
literal|"A standard system installation."
block|,
name|NULL
block|,
name|installStandard
block|}
block|,
block|{
literal|" Install, Express"
block|,
literal|"An express system installation."
block|,
name|NULL
block|,
name|installExpress
block|}
block|,
block|{
literal|" Install, Custom"
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
literal|" Label"
block|,
literal|"The disk Label editor"
block|,
name|NULL
block|,
name|diskLabelEditor
block|}
block|,
block|{
literal|" Media"
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
literal|" Media, Tape"
block|,
literal|"Select tape installation media."
block|,
name|NULL
block|,
name|mediaSetTape
block|}
block|,
block|{
literal|" Media, NFS"
block|,
literal|"Select NFS installation media."
block|,
name|NULL
block|,
name|mediaSetNFS
block|}
block|,
block|{
literal|" Media, Floppy"
block|,
literal|"Select floppy installation media."
block|,
name|NULL
block|,
name|mediaSetFloppy
block|}
block|,
block|{
literal|" Media, CDROM"
block|,
literal|"Select CDROM installation media."
block|,
name|NULL
block|,
name|mediaSetCDROM
block|}
block|,
block|{
literal|" Media, DOS"
block|,
literal|"Select DOS installation media."
block|,
name|NULL
block|,
name|mediaSetDOS
block|}
block|,
block|{
literal|" Media, UFS"
block|,
literal|"Select UFS installation media."
block|,
name|NULL
block|,
name|mediaSetUFS
block|}
block|,
block|{
literal|" Media, FTP"
block|,
literal|"Select FTP installation media."
block|,
name|NULL
block|,
name|mediaSetFTP
block|}
block|,
block|{
literal|" Media, FTP Passive"
block|,
literal|"Select passive FTP installation media."
block|,
name|NULL
block|,
name|mediaSetFTPPassive
block|}
block|,
block|{
literal|" Media, HTTP"
block|,
literal|"Select FTP via HTTP proxy installation media."
block|,
name|NULL
block|,
name|mediaSetHTTP
block|}
block|,
block|{
literal|" Network Interfaces"
block|,
literal|"Configure network interfaces"
block|,
name|NULL
block|,
name|tcpMenuSelect
block|}
block|,
block|{
literal|" Networking Services"
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
literal|" NFS, client"
block|,
literal|"Set NFS client flag."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"nfs_client_enable=YES"
block|}
block|,
block|{
literal|" NFS, server"
block|,
literal|"Set NFS server flag."
block|,
name|dmenuVarCheck
block|,
name|configNFSServer
block|,
name|NULL
block|,
literal|"nfs_server_enable=YES"
block|}
block|,
block|{
literal|" NTP Menu"
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
literal|" Options"
block|,
literal|"The options editor."
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
block|{
literal|" Packages"
block|,
literal|"The packages collection"
block|,
name|NULL
block|,
name|configPackages
block|}
block|,
block|{
literal|" Partition"
block|,
literal|"The disk Slice (PC-style partition) Editor"
block|,
name|NULL
block|,
name|diskPartitionEditor
block|}
block|,
block|{
literal|" PCNFSD"
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
literal|" Root Password"
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
literal|" Router"
block|,
literal|"Select routing daemon (default: routed)"
block|,
name|NULL
block|,
name|configRouter
block|,
name|NULL
block|,
literal|"router_enable"
block|}
block|,
block|{
literal|" Security"
block|,
literal|"Select a default system security profile."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSecurityProfile
block|}
block|,
block|{
literal|" Syscons"
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
literal|" Syscons, Font"
block|,
literal|"The console screen font."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsFont
block|}
block|,
block|{
literal|" Syscons, Keymap"
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
literal|" Syscons, Keyrate"
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
literal|" Syscons, Saver"
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
literal|" Syscons, Screenmap"
block|,
literal|"The console screenmap configuration menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsScrnmap
block|}
block|,
block|{
literal|" Time Zone"
block|,
literal|"Set the system's time zone."
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"tzsetup"
block|}
block|,
block|{
literal|" Upgrade"
block|,
literal|"Upgrade an existing system."
block|,
name|NULL
block|,
name|installUpgrade
block|}
block|,
block|{
literal|" Usage"
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
literal|" User Management"
block|,
literal|"Add user and group information."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuUsermgmt
block|}
block|,
block|{
literal|" XFree86, Fonts"
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
literal|" XFree86, Server"
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
ifdef|#
directive|ifdef
name|__i386__
block|{
literal|" XFree86, PC98 Server"
block|,
literal|"XFree86 PC98 Server selection menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXF86SelectPC98Server
block|}
block|,
endif|#
directive|endif
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
literal|"/stand/sysinstall Main Menu"
block|,
comment|/* title */
literal|"Welcome to the FreeBSD installation and configuration tool.  Please\n"
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
literal|"X Exit Install"
block|,
name|NULL
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|" Usage"
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
literal|"Standard"
block|,
literal|"Begin a standard installation (recommended)"
block|,
name|NULL
block|,
name|installStandard
block|}
block|,
block|{
literal|"Express"
block|,
literal|"Begin a quick installation (for the impatient)"
block|,
name|NULL
block|,
name|installExpress
block|}
block|,
block|{
literal|" Custom"
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
literal|"Configure"
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
literal|"Doc"
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
literal|"Keymap"
block|,
literal|"Select keyboard type"
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
literal|"Options"
block|,
literal|"View/Set various installation options"
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
block|{
literal|"Fixit"
block|,
literal|"Enter repair mode with CDROM/floppy or start shell"
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
literal|"Upgrade"
block|,
literal|"Upgrade an existing system"
block|,
name|NULL
block|,
name|installUpgrade
block|}
block|,
block|{
literal|"Load Config"
block|,
literal|"Load default install configuration"
block|,
name|NULL
block|,
name|dispatch_load_floppy
block|}
block|,
block|{
literal|"Index"
block|,
literal|"Glossary of functions"
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
literal|"FreeBSD Documentation Menu"
block|,
literal|"If you are at all unsure about the configuration of your hardware\n"
literal|"or are looking to build a system specifically for FreeBSD, read the\n"
literal|"Hardware guide!  New users should also read the Install document for\n"
literal|"a step-by-step tutorial on installing FreeBSD.  For general information,\n"
literal|"consult the README file."
block|,
literal|"Confused?  Press F1 for help."
block|,
literal|"usage"
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"2 README"
block|,
literal|"A general description of FreeBSD.  Read this!"
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"README"
block|}
block|,
block|{
literal|"3 Hardware"
block|,
literal|"The FreeBSD survival guide for PC hardware."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"HARDWARE"
block|}
block|,
block|{
literal|"4 Install"
block|,
literal|"A step-by-step guide to installing FreeBSD."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"INSTALL"
block|}
block|,
block|{
literal|"5 Copyright"
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
literal|"6 Release"
block|,
literal|"The release notes for this version of FreeBSD."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"RELNOTES"
block|}
block|,
block|{
literal|"7 Shortcuts"
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
literal|"8 HTML Docs"
block|,
literal|"Go to the HTML documentation menu (post-install)."
block|,
name|NULL
block|,
name|docBrowser
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
name|MenuMouseType
init|=
block|{
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select a protocol type for your mouse"
block|,
literal|"If your mouse is attached to the PS/2 mouse port or the bus mouse port,\n"
literal|"you should always choose \"Auto\", regardless of the model and the brand\n"
literal|"of the mouse.  All other protocol types are for serial mice and should\n"
literal|"not be used with the PS/2 port mouse or the bus mouse.  If you have\n"
literal|"a serial mouse and are not sure about its protocol, you should also try\n"
literal|"\"Auto\".  It may not work for the serial mouse if the mouse does not\n"
literal|"support the PnP standard.  But, it won't hurt.  Many 2-button serial mice\n"
literal|"are compatible with \"Microsoft\" or \"MouseMan\".  3-button serial mice\n"
literal|"may be compatible with \"MouseSystems\" or \"MouseMan\".  If the serial\n"
literal|"mouse has a wheel, it may be compatible with \"IntelliMouse\"."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"1 Auto"
block|,
literal|"Bus mouse, PS/2 style mouse or PnP serial mouse"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=auto"
block|}
block|,
block|{
literal|"2 GlidePoint"
block|,
literal|"ALPS GlidePoint pad (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=glidepoint"
block|}
block|,
block|{
literal|"3 Hitachi"
block|,
literal|"Hitachi tablet (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=mmhittab"
block|}
block|,
block|{
literal|"4 IntelliMouse"
block|,
literal|"Microsoft IntelliMouse (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=intellimouse"
block|}
block|,
block|{
literal|"5 Logitech"
block|,
literal|"Logitech protocol (old models) (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=logitech"
block|}
block|,
block|{
literal|"6 Microsoft"
block|,
literal|"Microsoft protocol (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=microsoft"
block|}
block|,
block|{
literal|"7 MM Series"
block|,
literal|"MM Series protocol (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=mmseries"
block|}
block|,
block|{
literal|"8 MouseMan"
block|,
literal|"Logitech MouseMan/TrackMan models (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=mouseman"
block|}
block|,
block|{
literal|"9 MouseSystems"
block|,
literal|"MouseSystems protocol (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=mousesystems"
block|}
block|,
block|{
literal|"A ThinkingMouse"
block|,
literal|"Kensington ThinkingMouse (serial)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_TYPE
literal|"=thinkingmouse"
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
name|MenuMousePort
init|=
block|{
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select your mouse port from the following menu"
block|,
literal|"The built-in pointing device of laptop/notebook computers is usually\n"
literal|"a PS/2 style device."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"1 PS/2"
block|,
literal|"PS/2 style mouse (/dev/psm0)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/psm0"
block|}
block|,
block|{
literal|"2 COM1"
block|,
literal|"Serial mouse on COM1 (/dev/cuaa0)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuaa0"
block|}
block|,
block|{
literal|"3 COM2"
block|,
literal|"Serial mouse on COM2 (/dev/cuaa1)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuaa1"
block|}
block|,
block|{
literal|"4 COM3"
block|,
literal|"Serial mouse on COM3 (/dev/cuaa2)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuaa2"
block|}
block|,
block|{
literal|"5 COM4"
block|,
literal|"Serial mouse on COM4 (/dev/cuaa3)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuaa3"
block|}
block|,
block|{
literal|"6 BusMouse"
block|,
literal|"Logitech, ATI or MS bus mouse (/dev/mse0)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/mse0"
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
name|MenuMouse
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Please configure your mouse"
block|,
literal|"You can cut and paste text in the text console by running the mouse\n"
literal|"daemon.  Specify a port and a protocol type of your mouse and enable\n"
literal|"the mouse daemon.  If you don't want this feature, select 6 to disable\n"
literal|"the daemon.\n"
literal|"Once you've enabled the mouse daemon, you can specify \"/dev/sysmouse\"\n"
literal|"as your mouse device and \"SysMouse\" or \"MouseSystems\" as mouse\n"
literal|"protocol when running the X configuration utility (see Configuration\n"
literal|"menu)."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"2 Enable"
block|,
literal|"Test and run the mouse daemon"
block|,
name|NULL
block|,
name|mousedTest
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|"3 Type"
block|,
literal|"Select mouse protocol type"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMouseType
block|}
block|,
block|{
literal|"4 Port"
block|,
literal|"Select mouse port"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMousePort
block|}
block|,
block|{
literal|"5 Flags"
block|,
literal|"Set additional flags"
block|,
name|dmenuVarCheck
block|,
name|setMouseFlags
block|,
name|NULL
block|,
name|VAR_MOUSED_FLAGS
literal|"="
block|}
block|,
block|{
literal|"6 Disable"
block|,
literal|"Disable the mouse daemon"
block|,
name|NULL
block|,
name|mousedDisable
block|,
name|NULL
block|,
name|NULL
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
literal|"FreeBSD can be installed directly from a CDROM containing a valid\n"
literal|"FreeBSD distribution.  If you are seeing this menu it is because\n"
literal|"more than one CDROM drive was found on your system.  Please select one\n"
literal|"of the following CDROM drives as your installation drive."
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
literal|"You have more than one floppy drive.  Please choose which drive\n"
literal|"you would like to use."
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
literal|"FreeBSD can be installed directly from a DOS partition\n"
literal|"assuming, of course, that you have copied the relevant\n"
literal|"distributions into your DOS partition before starting this\n"
literal|"installation.  If this is not the case then you should reboot\n"
literal|"DOS at this time and copy the distributions you wish to install\n"
literal|"into a \"FREEBSD\" subdirectory on one of your DOS partitions.\n"
literal|"Otherwise, please select the DOS partition containing the FreeBSD\n"
literal|"distribution files."
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
literal|"Please select the site closest to you or \"other\" if you'd like to\n"
literal|"specify a different choice.  Also note that not every site listed here\n"
literal|"carries more than the base distribution kits. Only the Primary site is\n"
literal|"guaranteed to carry the full range of possible distributions."
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
literal|"=ftp://ftp.freebsd.org"
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
literal|" 5.0 SNAP Server"
block|,
literal|"current.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://current.freebsd.org"
block|}
block|,
block|{
literal|" 4.0 SNAP Server"
block|,
literal|"releng4.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://releng4.freebsd.org/pub/FreeBSD/snapshots/"
block|}
block|,
block|{
literal|" IPv6 Ready"
block|,
literal|"ftp7.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp7.jp.freebsd.org"
block|}
block|,
block|{
literal|"Argentina"
block|,
literal|"ftp.ar.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ar.freebsd.org"
block|}
block|,
block|{
literal|" Australia"
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
literal|"=ftp://ftp.au.freebsd.org"
block|}
block|,
block|{
literal|" Australia #2"
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
literal|"=ftp://ftp2.au.freebsd.org"
block|}
block|,
block|{
literal|" Australia #3"
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
literal|"=ftp://ftp3.au.freebsd.org"
block|}
block|,
block|{
literal|" Australia #4"
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
literal|"=ftp://ftp4.au.freebsd.org"
block|}
block|,
block|{
literal|" Australia #5"
block|,
literal|"ftp5.au.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.au.freebsd.org"
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
literal|"=ftp://ftp.br.freebsd.org"
block|}
block|,
block|{
literal|" Brazil #2"
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
literal|"=ftp://ftp2.br.freebsd.org"
block|}
block|,
block|{
literal|" Brazil #3"
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
literal|"=ftp://ftp3.br.freebsd.org"
block|}
block|,
block|{
literal|" Brazil #4"
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
literal|"=ftp://ftp4.br.freebsd.org"
block|}
block|,
block|{
literal|" Brazil #5"
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
literal|"=ftp://ftp5.br.freebsd.org"
block|}
block|,
block|{
literal|" Brazil #6"
block|,
literal|"ftp6.br.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.br.freebsd.org"
block|}
block|,
block|{
literal|" Brazil #7"
block|,
literal|"ftp7.br.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp7.br.freebsd.org"
block|}
block|,
block|{
literal|" Canada"
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
literal|"=ftp://ftp.ca.freebsd.org"
block|}
block|,
block|{
literal|" Czech Republic"
block|,
literal|"ftp.cz.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.cz.freebsd.org"
block|}
block|,
block|{
literal|"Denmark"
block|,
literal|"ftp.dk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.dk.freebsd.org"
block|}
block|,
block|{
literal|" Denmark #2"
block|,
literal|"ftp2.dk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.dk.freebsd.org"
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
literal|"=ftp://ftp.ee.freebsd.org"
block|}
block|,
block|{
literal|"Finland"
block|,
literal|"ftp.fi.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.fi.freebsd.org"
block|}
block|,
block|{
literal|" France"
block|,
literal|"ftp.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.fr.freebsd.org"
block|}
block|,
block|{
literal|" France #1"
block|,
literal|"ftp.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.fr.freebsd.org"
block|}
block|,
block|{
literal|" France #2"
block|,
literal|"ftp2.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.fr.freebsd.org"
block|}
block|,
block|{
literal|" France #3"
block|,
literal|"ftp3.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.fr.freebsd.org"
block|}
block|,
block|{
literal|" France #4"
block|,
literal|"ftp4.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.fr.freebsd.org"
block|}
block|,
block|{
literal|" France #5"
block|,
literal|"ftp5.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.fr.freebsd.org"
block|}
block|,
block|{
literal|" France #6"
block|,
literal|"ftp6.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.fr.freebsd.org"
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
literal|"=ftp://ftp.de.freebsd.org"
block|}
block|,
block|{
literal|" Germany #2"
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
literal|"=ftp://ftp2.de.freebsd.org"
block|}
block|,
block|{
literal|" Germany #3"
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
literal|"=ftp://ftp3.de.freebsd.org"
block|}
block|,
block|{
literal|" Germany #4"
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
literal|"=ftp://ftp4.de.freebsd.org"
block|}
block|,
block|{
literal|" Germany #5"
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
literal|"=ftp://ftp5.de.freebsd.org"
block|}
block|,
block|{
literal|" Germany #6"
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
literal|"=ftp://ftp6.de.freebsd.org"
block|}
block|,
block|{
literal|" Germany #7"
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
literal|"=ftp://ftp7.de.freebsd.org"
block|}
block|,
block|{
literal|"Holland"
block|,
literal|"ftp.nl.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.nl.freebsd.org"
block|}
block|,
block|{
literal|" Hong Kong"
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
literal|"=ftp://ftp.hk.super.net"
block|}
block|,
block|{
literal|"Iceland"
block|,
literal|"ftp.is.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.is.freebsd.org"
block|}
block|,
block|{
literal|" Ireland"
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
literal|"=ftp://ftp.ie.freebsd.org"
block|}
block|,
block|{
literal|" Israel"
block|,
literal|"ftp.il.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.il.freebsd.org"
block|}
block|,
block|{
literal|" Israel #2"
block|,
literal|"ftp2.il.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.il.freebsd.org"
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
literal|"=ftp://ftp.jp.freebsd.org"
block|}
block|,
block|{
literal|" Japan #2"
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
literal|"=ftp://ftp2.jp.freebsd.org"
block|}
block|,
block|{
literal|" Japan #3"
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
literal|"=ftp://ftp3.jp.freebsd.org"
block|}
block|,
block|{
literal|" Japan #4"
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
literal|"=ftp://ftp4.jp.freebsd.org"
block|}
block|,
block|{
literal|" Japan #5"
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
literal|"=ftp://ftp5.jp.freebsd.org"
block|}
block|,
block|{
literal|" Japan #6"
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
literal|"=ftp://ftp6.jp.freebsd.org"
block|}
block|,
block|{
literal|" Japan #7"
block|,
literal|"ftp7.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp7.jp.freebsd.org"
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
literal|"=ftp://ftp.kr.freebsd.org"
block|}
block|,
block|{
literal|" Korea #2"
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
literal|"=ftp://ftp2.kr.freebsd.org"
block|}
block|,
block|{
literal|" Korea #3"
block|,
literal|"ftp3.kr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.kr.freebsd.org"
block|}
block|,
block|{
literal|" Korea #4"
block|,
literal|"ftp4.kr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.kr.freebsd.org"
block|}
block|,
block|{
literal|" Korea #5"
block|,
literal|"ftp5.kr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.kr.freebsd.org"
block|}
block|,
block|{
literal|"Lithuania"
block|,
literal|"ftp.lt.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.lt.freebsd.org"
block|}
block|,
block|{
literal|"New Zealand"
block|,
literal|"ftp.nz.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.nz.freebsd.org"
block|}
block|,
block|{
literal|"Norway"
block|,
literal|"ftp.no.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.no.freebsd.org"
block|}
block|,
block|{
literal|"Poland"
block|,
literal|"ftp.pl.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.pl.freebsd.org"
block|}
block|,
block|{
literal|" Portugal"
block|,
literal|"ftp.pt.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.pt.freebsd.org"
block|}
block|,
block|{
literal|" Portugal #2"
block|,
literal|"ftp2.pt.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.pt.freebsd.org"
block|}
block|,
block|{
literal|"Russia"
block|,
literal|"ftp.ru.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ru.freebsd.org"
block|}
block|,
block|{
literal|" Russia #2"
block|,
literal|"ftp2.ru.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.ru.freebsd.org"
block|}
block|,
block|{
literal|" Russia #3"
block|,
literal|"ftp3.ru.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.ru.freebsd.org"
block|}
block|,
block|{
literal|" Russia #4"
block|,
literal|"ftp4.ru.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.ru.freebsd.org"
block|}
block|,
block|{
literal|"Slovak Republic"
block|,
literal|"ftp.sk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.sk.freebsd.org"
block|}
block|,
block|{
literal|"Slovenia"
block|,
literal|"ftp.si.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.si.freebsd.org"
block|}
block|,
block|{
literal|" South Africa"
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
literal|"=ftp://ftp.za.freebsd.org"
block|}
block|,
block|{
literal|" South Africa #2"
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
literal|"=ftp://ftp2.za.freebsd.org"
block|}
block|,
block|{
literal|" South Africa #3"
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
literal|"=ftp://ftp3.za.freebsd.org"
block|}
block|,
block|{
literal|" South Africa #4"
block|,
literal|"ftp4.za.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.za.freebsd.org"
block|}
block|,
block|{
literal|" Spain"
block|,
literal|"ftp.es.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.es.freebsd.org"
block|}
block|,
block|{
literal|" Spain #2"
block|,
literal|"ftp2.es.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.es.freebsd.org"
block|}
block|,
block|{
literal|" Sweden"
block|,
literal|"ftp.se.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.se.freebsd.org"
block|}
block|,
block|{
literal|" Sweden #2"
block|,
literal|"ftp2.se.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.se.freebsd.org"
block|}
block|,
block|{
literal|" Sweden #3"
block|,
literal|"ftp3.se.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.se.freebsd.org"
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
literal|"=ftp://ftp.tw.freebsd.org"
block|}
block|,
block|{
literal|" Taiwan #2"
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
literal|"=ftp://ftp2.tw.freebsd.org"
block|}
block|,
block|{
literal|" Taiwan #3"
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
literal|"=ftp://ftp3.tw.freebsd.org"
block|}
block|,
block|{
literal|" Taiwan #4"
block|,
literal|"ftp4.tw.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.tw.freebsd.org"
block|}
block|,
block|{
literal|" Thailand"
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
literal|"=ftp://ftp.uk.freebsd.org"
block|}
block|,
block|{
literal|" UK #2"
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
literal|"=ftp://ftp2.uk.freebsd.org"
block|}
block|,
block|{
literal|" UK #3"
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
literal|"=ftp://ftp3.uk.freebsd.org"
block|}
block|,
block|{
literal|" UK #4"
block|,
literal|"ftp4.uk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.uk.freebsd.org"
block|}
block|,
block|{
literal|" UK #5"
block|,
literal|"ftp5.uk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.uk.freebsd.org"
block|}
block|,
block|{
literal|" USA"
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
literal|"=ftp://ftp.freebsd.org"
block|}
block|,
block|{
literal|" USA #2"
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
literal|"=ftp://ftp2.freebsd.org"
block|}
block|,
block|{
literal|" USA #3"
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
literal|"=ftp://ftp3.freebsd.org"
block|}
block|,
block|{
literal|" USA #4"
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
literal|"=ftp://ftp4.freebsd.org"
block|}
block|,
block|{
literal|" USA #5"
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
literal|"=ftp://ftp5.freebsd.org"
block|}
block|,
block|{
literal|" USA #6"
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
literal|"=ftp://ftp6.freebsd.org"
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
literal|"FreeBSD can be installed from tape drive, though this installation\n"
literal|"method requires a certain amount of temporary storage in addition\n"
literal|"to the space required by the distribution itself (tape drives make\n"
literal|"poor random-access devices, so we extract _everything_ on the tape\n"
literal|"in one pass).  If you have sufficient space for this, then you should\n"
literal|"select one of the following tape devices detected on your system."
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
literal|"cable to another machine running a fairly recent (2.0R or later)\n"
literal|"version of FreeBSD."
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
literal|"FreeBSD can be installed from a variety of different installation\n"
literal|"media, ranging from floppies to an Internet FTP server.  If you're\n"
literal|"installing FreeBSD from a supported CDROM drive then this is generally\n"
literal|"the best media to use if you have no overriding reason for using other\n"
literal|"media."
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
literal|"4 HTTP"
block|,
literal|"Install from an FTP server through a http proxy"
block|,
name|NULL
block|,
name|mediaSetHTTP
block|}
block|,
block|{
literal|"5 DOS"
block|,
literal|"Install from a DOS partition"
block|,
name|NULL
block|,
name|mediaSetDOS
block|}
block|,
block|{
literal|"6 NFS"
block|,
literal|"Install over NFS"
block|,
name|NULL
block|,
name|mediaSetNFS
block|}
block|,
block|{
literal|"7 File System"
block|,
literal|"Install from an existing filesystem"
block|,
name|NULL
block|,
name|mediaSetUFS
block|}
block|,
block|{
literal|"8 Floppy"
block|,
literal|"Install from a floppy disk set"
block|,
name|NULL
block|,
name|mediaSetFloppy
block|}
block|,
block|{
literal|"9 Tape"
block|,
literal|"Install from SCSI or QIC tape"
block|,
name|NULL
block|,
name|mediaSetTape
block|}
block|,
block|{
literal|"X Options"
block|,
literal|"Go to the Options screen"
block|,
name|NULL
block|,
name|optionsEditor
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
literal|"As a convenience, we provide several \"canned\" distribution sets.\n"
literal|"These select what we consider to be the most reasonable defaults for the\n"
literal|"type of system in question.  If you would prefer to pick and choose the\n"
literal|"list of distributions yourself, simply select \"Custom\".  You can also\n"
literal|"pick a canned distribution set and then fine-tune it with the Custom item.\n\n"
literal|"Choose an item by pressing [SPACE]. When you are finished, choose the Exit\n"
literal|"item or press [ENTER]."
block|,
literal|"Press F1 for more information on these options."
block|,
literal|"distributions"
block|,
block|{
block|{
literal|"X Exit"
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
literal|"All"
block|,
literal|"All system sources, binaries and X Window System)"
block|,
name|checkDistEverything
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
literal|"Reset"
block|,
literal|"Reset selected distribution list to nothing"
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
literal|"4 Developer"
block|,
literal|"Full sources, binaries and doc but no games"
block|,
name|checkDistDeveloper
block|,
name|distSetDeveloper
block|}
block|,
block|{
literal|"5 X-Developer"
block|,
literal|"Same as above + X Window System"
block|,
name|checkDistXDeveloper
block|,
name|distSetXDeveloper
block|}
block|,
block|{
literal|"6 Kern-Developer"
block|,
literal|"Full binaries and doc, kernel sources only"
block|,
name|checkDistKernDeveloper
block|,
name|distSetKernDeveloper
block|}
block|,
block|{
literal|"7 X-Kern-Developer"
block|,
literal|"Same as above + X Window System"
block|,
name|checkDistXKernDeveloper
block|,
name|distSetXKernDeveloper
block|}
block|,
block|{
literal|"8 User"
block|,
literal|"Average user - binaries and doc only"
block|,
name|checkDistUser
block|,
name|distSetUser
block|}
block|,
block|{
literal|"9 X-User"
block|,
literal|"Same as above + X Window System"
block|,
name|checkDistXUser
block|,
name|distSetXUser
block|}
block|,
block|{
literal|"A Minimal"
block|,
literal|"The smallest configuration possible"
block|,
name|checkDistMinimum
block|,
name|distSetMinimum
block|}
block|,
block|{
literal|"B Custom"
block|,
literal|"Specify your own distribution set"
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
literal|'>'
block|,
literal|'>'
block|,
literal|'>'
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
literal|"Please check off the distributions you wish to install.  At the\n"
literal|"very minimum, this should be \"bin\"."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
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
literal|"All"
block|,
literal|"All system sources, binaries and X Window System"
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
literal|"Reset"
block|,
literal|"Reset all of the below"
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
literal|" bin"
block|,
literal|"Binary base distribution (required)"
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
ifdef|#
directive|ifdef
name|__i386__
block|{
literal|" compat1x"
block|,
literal|"FreeBSD 1.x binary compatibility"
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
literal|" compat20"
block|,
literal|"FreeBSD 2.0 binary compatibility"
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
literal|" compat21"
block|,
literal|"FreeBSD 2.1 binary compatibility"
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
literal|" compat22"
block|,
literal|"FreeBSD 2.2.x and 3.0 a.out binary compatibility"
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
name|DIST_COMPAT22
block|}
block|,
if|#
directive|if
name|__FreeBSD__
operator|>
literal|3
block|{
literal|" compat3x"
block|,
literal|"FreeBSD 3.x binary compatibility"
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
name|DIST_COMPAT3X
block|}
block|,
endif|#
directive|endif
endif|#
directive|endif
block|{
literal|" crypto"
block|,
literal|"Basic encryption services"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_CRYPTO
block|, }
block|,
if|#
directive|if
name|__FreeBSD__
operator|<=
literal|3
block|{
literal|" krb"
block|,
literal|"KerberosIV authentication services"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_KERBEROS
block|}
block|,
else|#
directive|else
block|{
literal|" krb4"
block|,
literal|"KerberosIV authentication services"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_KERBEROS4
block|}
block|,
block|{
literal|" krb5"
block|,
literal|"Kerberos5 authentication services"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_KERBEROS5
block|}
block|,
endif|#
directive|endif
block|{
literal|" dict"
block|,
literal|"Spelling checker dictionary files"
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
literal|" doc"
block|,
literal|"Miscellaneous FreeBSD online docs"
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
literal|" games"
block|,
literal|"Games (non-commercial)"
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
literal|" info"
block|,
literal|"GNU info files"
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
literal|" man"
block|,
literal|"System manual pages - recommended"
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
literal|" catman"
block|,
literal|"Preformatted system manual pages"
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
name|DIST_CATPAGES
block|}
block|,
block|{
literal|" proflibs"
block|,
literal|"Profiled versions of the libraries"
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
literal|" src"
block|,
literal|"Sources for everything but encryption"
block|,
name|srcFlagCheck
block|,
name|distSetSrc
block|}
block|,
block|{
literal|" ports"
block|,
literal|"The FreeBSD Ports collection"
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
name|DIST_PORTS
block|}
block|,
block|{
literal|" local"
block|,
literal|"Local additions collection"
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
name|DIST_LOCAL
block|}
block|,
block|{
literal|" XFree86"
block|,
literal|"The XFree86 3.3.6 distribution"
block|,
name|x11FlagCheck
block|,
name|distSetXF86
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
literal|"Please check off those portions of the FreeBSD source tree\n"
literal|"you wish to install (remember to use SPACE, not ENTER!)."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
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
literal|"All"
block|,
literal|"Select all of the below"
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
literal|"Reset"
block|,
literal|"Reset all of the below"
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
literal|" base"
block|,
literal|"top-level files in /usr/src"
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
literal|" contrib"
block|,
literal|"/usr/src/contrib (contributed software)"
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
name|DIST_SRC_CONTRIB
block|}
block|,
block|{
literal|" gnu"
block|,
literal|"/usr/src/gnu (software from the GNU Project)"
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
literal|" etc"
block|,
literal|"/usr/src/etc (miscellaneous system files)"
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
literal|" games"
block|,
literal|"/usr/src/games (the obvious!)"
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
literal|" include"
block|,
literal|"/usr/src/include (header files)"
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
literal|" lib"
block|,
literal|"/usr/src/lib (system libraries)"
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
literal|" libexec"
block|,
literal|"/usr/src/libexec (system programs)"
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
literal|" release"
block|,
literal|"/usr/src/release (release-generation tools)"
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
literal|" bin"
block|,
literal|"/usr/src/bin (system binaries)"
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
literal|" sbin"
block|,
literal|"/usr/src/sbin (system binaries)"
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
literal|" scrypto"
block|,
literal|"/usr/src/crypto (contrib encryption sources)"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_SCRYPTO
block|}
block|,
block|{
literal|" share"
block|,
literal|"/usr/src/share (documents and shared files)"
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
literal|" skrb4"
block|,
literal|"/usr/src/kerberosIV (sources for KerberosIV)"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_SKERBEROS4
block|}
block|,
block|{
literal|" skrb5"
block|,
literal|"/usr/src/kerberos5 (sources for Kerberos5)"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_SKERBEROS5
block|}
block|,
block|{
literal|" ssecure"
block|,
literal|"/usr/src/secure (BSD encryption sources)"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|CRYPTODists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_CRYPTO_SSECURE
block|}
block|,
block|{
literal|" sys"
block|,
literal|"/usr/src/sys (FreeBSD kernel)"
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
literal|" tools"
block|,
literal|"/usr/src/tools (miscellaneous tools)"
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
name|DIST_SRC_TOOLS
block|}
block|,
block|{
literal|" ubin"
block|,
literal|"/usr/src/usr.bin (user binaries)"
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
literal|" usbin"
block|,
literal|"/usr/src/usr.sbin (aux system binaries)"
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
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuXF86Config
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Please select the XFree86 configuration tool you want to use."
block|,
ifdef|#
directive|ifdef
name|__alpha__
literal|"Due to problems with the VGA16 server right now, only the\n"
literal|"text-mode configuration tool (xf86config) is currently supported."
block|,
else|#
directive|else
literal|"The first tool, XF86Setup, is fully graphical and requires the\n"
literal|"VGA16 server in order to work (should have been selected by\n"
literal|"default, but if you de-selected it then you won't be able to\n"
literal|"use this fancy setup tool).  The second tool, xf86config, is\n"
literal|"a more simplistic shell-script based tool and less friendly to\n"
literal|"new users, but it may work in situations where the fancier one\n"
literal|"does not."
block|,
endif|#
directive|endif
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
ifdef|#
directive|ifdef
name|__alpha__
block|{
literal|"2 xf86config"
block|,
literal|"Shell-script based XFree86 configuration tool."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_XF86_CONFIG
literal|"=xf86config"
block|}
block|,
else|#
directive|else
block|{
literal|"2 XF86Setup"
block|,
literal|"Fully graphical XFree86 configuration tool."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_XF86_CONFIG
literal|"=XF86Setup"
block|}
block|,
block|{
literal|"3 xf86config"
block|,
literal|"Shell-script based XFree86 configuration tool."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_XF86_CONFIG
literal|"=xf86config"
block|}
block|,
block|{
literal|"4 XF98Setup"
block|,
literal|"Fully graphical XFree86 configuration tool (PC98)."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_XF86_CONFIG
literal|"=XF98Setup"
block|}
block|,
endif|#
directive|endif
block|{
literal|"D XDesktop"
block|,
literal|"X already set up, just do desktop configuration."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXDesktops
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
name|MenuXDesktops
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Please select the default X desktop to use."
block|,
literal|"By default, XFree86 comes with a fairly vanilla desktop which\n"
literal|"is based around the twm(1) window manager and does not offer\n"
literal|"much in the way of features.  It does have the advantage of\n"
literal|"being a standard part of X so you don't need to load anything\n"
literal|"extra in order to use it.  If, however, you have access to a\n"
literal|"reasonably full packages collection on your installation media,\n"
literal|"you can choose any one of the following desktops as alternatives."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"2 KDE"
block|,
literal|"The K Desktop Environment."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_DESKSTYLE
literal|"=kde"
block|}
block|,
block|{
literal|"3 GNOME + Afterstep"
block|,
literal|"GNOME + Afterstep window manager."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_DESKSTYLE
literal|"=gnome"
block|}
block|,
block|{
literal|"4 GNOME + Enlightenment"
block|,
literal|"GNOME + The E window manager"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_DESKSTYLE
literal|"=enlightenment"
block|}
block|,
block|{
literal|"5 Afterstep"
block|,
literal|"The Afterstep window manager"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_DESKSTYLE
literal|"=afterstep"
block|}
block|,
block|{
literal|"6 Windowmaker"
block|,
literal|"The Windowmaker window manager"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_DESKSTYLE
literal|"=windowmaker"
block|}
block|,
block|{
literal|"7 fvwm2"
block|,
literal|"The fvwm2 window manager"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_DESKSTYLE
literal|"=fvwm2"
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
literal|"XFree86 3.3.6 Distribution"
block|,
literal|"Please select the components you need from the XFree86 3.3.6\n"
literal|"distribution sets."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
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
literal|"XFree86 3.3.6 base distribution types"
block|,
literal|"Please check off the basic XFree86 components you wish to install.\n"
literal|"Bin, lib, and set are recommended for a minimum installaion."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
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
literal|"All"
block|,
literal|"Select all below"
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
literal|"Reset"
block|,
literal|"Reset all below"
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
literal|" bin"
block|,
literal|"Client applications and shared libs"
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
literal|" cfg"
block|,
literal|"Configuration files"
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
name|DIST_XF86_CFG
block|}
block|,
block|{
literal|" doc"
block|,
literal|"READMEs and release notes"
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
literal|" html"
block|,
literal|"HTML documentation files"
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
name|DIST_XF86_HTML
block|}
block|,
block|{
literal|" lib"
block|,
literal|"Data files needed at runtime"
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
literal|" lkit"
block|,
literal|"Server link kit for all other machines"
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
name|DIST_XF86_LKIT
block|}
block|,
block|{
literal|" man"
block|,
literal|"Manual pages"
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
literal|" prog"
block|,
literal|"Programmer's header and library files"
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
literal|" set"
block|,
literal|"XFree86 Setup Utility"
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
name|DIST_XF86_SET
block|}
block|,
ifdef|#
directive|ifdef
name|__i386__
block|{
literal|" 9set"
block|,
literal|"XFree86 Setup Utility for PC98 machines"
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
name|DIST_XF86_9SET
block|}
block|,
block|{
literal|" lk98"
block|,
literal|"Server link kit for PC98 machines"
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
name|DIST_XF86_LKIT98
block|}
block|,
endif|#
directive|endif
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
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
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
literal|"All"
block|,
literal|"All fonts"
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
literal|"Reset"
block|,
literal|"Reset font selections"
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
literal|" fnts"
block|,
literal|"Standard 75 DPI and miscellaneous fonts"
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
literal|" f100"
block|,
literal|"100 DPI fonts"
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
literal|" fcyr"
block|,
literal|"Cyrillic Fonts"
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
literal|" fscl"
block|,
literal|"Speedo and Type scalable fonts"
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
literal|" non"
block|,
literal|"Japanese, Chinese and other non-english fonts"
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
literal|" server"
block|,
literal|"Font server"
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
literal|"Please check off the types of X servers you wish to install.\n"
literal|"If you are unsure as to which server will work for your graphics card,\n"
literal|"it is recommended that try the SVGA or VGA16 servers or, for PC98\n"
literal|"machines, the 9EGC or 9840 servers."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
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
literal|"All"
block|,
literal|"Select all of the above"
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
literal|"Reset"
block|,
literal|"Reset all of the above"
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
literal|" SVGA"
block|,
literal|"Standard VGA or Super VGA card"
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
literal|" VGA16"
block|,
literal|"Standard 16 color VGA card"
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
literal|" Mono"
block|,
literal|"Standard Monochrome card"
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
literal|" 3DL"
block|,
literal|"8, 16 and 24 bit color 3D Labs boards"
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
name|DIST_XF86_SERVER_3DL
block|}
block|,
block|{
literal|" 8514"
block|,
literal|"8-bit (256 color) IBM 8514 or compatible card"
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
literal|" AGX"
block|,
literal|"8-bit AGX card"
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
literal|" I128"
block|,
literal|"8, 16 and 24-bit #9 Imagine I128 card"
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
name|DIST_XF86_SERVER_I128
block|}
block|,
block|{
literal|" Ma8"
block|,
literal|"8-bit ATI Mach8 card"
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
literal|" Ma32"
block|,
literal|"8 and 16-bit (65K color) ATI Mach32 card"
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
literal|" Ma64"
block|,
literal|"8 and 16-bit (65K color) ATI Mach64 card"
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
literal|" P9K"
block|,
literal|"8, 16, and 24-bit color Weitek P9000 based boards"
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
literal|" S3"
block|,
literal|"8, 16 and 24-bit color S3 based boards"
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
literal|" S3V"
block|,
literal|"8, 16 and 24-bit color S3 Virge based boards"
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
name|DIST_XF86_SERVER_S3V
block|}
block|,
block|{
literal|" W32"
block|,
literal|"8-bit ET4000/W32, /W32i and /W32p cards"
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
ifdef|#
directive|ifdef
name|__i386__
block|{
literal|" PC98"
block|,
literal|"Select an X server for a NEC PC98 [Submenu]"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXF86SelectPC98Server
block|,
literal|'>'
block|,
literal|' '
block|,
literal|'>'
block|,
literal|0
block|}
block|,
elif|#
directive|elif
name|__alpha__
block|{
literal|" TGA"
block|,
literal|"TGA cards (alpha architecture only)"
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
name|DIST_XF86_SERVER_TGA
block|}
block|,
endif|#
directive|endif
block|{
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_decl_stmt
name|DMenu
name|MenuXF86SelectPC98Server
init|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"PC98 X Server selection."
block|,
literal|"Please check off the types of NEC PC98 X servers you wish to install.\n\ If you are unsure as to which server will work for your graphics card,\n\ it is recommended that try the SVGA or VGA16 servers (the VGA16 and\n\ Mono servers are particularly well-suited to most LCD displays)."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|" 9480"
block|,
literal|"PC98 8-bit (256 color) PEGC-480 card"
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
name|DIST_XF86_SERVER_9480
block|}
block|,
block|{
literal|" 9EGC"
block|,
literal|"PC98 4-bit (16 color) EGC card"
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
name|DIST_XF86_SERVER_9EGC
block|}
block|,
block|{
literal|" 9GA9"
block|,
literal|"PC98 GA-968V4/PCI (S3 968) card"
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
name|DIST_XF86_SERVER_9GA9
block|}
block|,
block|{
literal|" 9GAN"
block|,
literal|"PC98 GANB-WAP (cirrus) card"
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
name|DIST_XF86_SERVER_9GAN
block|}
block|,
block|{
literal|" 9LPW"
block|,
literal|"PC98 PowerWindowLB (S3) card"
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
name|DIST_XF86_SERVER_9LPW
block|}
block|,
block|{
literal|" 9MGA"
block|,
literal|"PC98 MGA (Matrox) card"
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
name|DIST_XF86_SERVER_9MGA
block|}
block|,
block|{
literal|" 9NKV"
block|,
literal|"PC98 NKV-NEC (cirrus) card"
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
name|DIST_XF86_SERVER_9NKV
block|}
block|,
block|{
literal|" 9NS3"
block|,
literal|"PC98 NEC (S3) card"
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
name|DIST_XF86_SERVER_9NS3
block|}
block|,
block|{
literal|" 9SPW"
block|,
literal|"PC98 SKB-PowerWindow (S3) card"
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
name|DIST_XF86_SERVER_9SPW
block|}
block|,
block|{
literal|" 9SVG"
block|,
literal|"PC98 generic SVGA card"
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
name|DIST_XF86_SERVER_9SVG
block|}
block|,
block|{
literal|" 9TGU"
block|,
literal|"PC98 Cyber9320 and TGUI9680 cards"
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
name|DIST_XF86_SERVER_9TGU
block|}
block|,
block|{
literal|" 9WEP"
block|,
literal|"PC98 WAB-EP (cirrus) card"
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
name|DIST_XF86_SERVER_9WEP
block|}
block|,
block|{
literal|" 9WS"
block|,
literal|"PC98 WABS (cirrus) card"
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
name|DIST_XF86_SERVER_9WS
block|}
block|,
block|{
literal|" 9WSN"
block|,
literal|"PC98 WSN-A2F (cirrus) card"
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
name|DIST_XF86_SERVER_9WSN
block|}
block|,
block|{
name|NULL
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
literal|"and press [SPACE].  To de-select it, press [SPACE] again.\n\n"
literal|"Select OK or Cancel to leave this menu."
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
literal|"Please select the body of documentation you're interested in, the main\n"
literal|"ones right now being the FAQ and the Handbook.  You can also choose \"other\"\n"
literal|"to enter an arbitrary URL for browsing."
block|,
literal|"Press F1 for more help on what you see here."
block|,
literal|"html"
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"2 Handbook"
block|,
literal|"The FreeBSD Handbook."
block|,
name|NULL
block|,
name|docShowDocument
block|}
block|,
block|{
literal|"3 FAQ"
block|,
literal|"The Frequently Asked Questions guide."
block|,
name|NULL
block|,
name|docShowDocument
block|}
block|,
block|{
literal|"4 Home"
block|,
literal|"The Home Pages for the FreeBSD Project (requires net)"
block|,
name|NULL
block|,
name|docShowDocument
block|}
block|,
block|{
literal|"5 Other"
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
literal|"This is the custom installation menu. You may use this menu to specify\n"
literal|"details on the type of distribution you wish to have, where you wish\n"
literal|"to install it from and how you wish to allocate disk storage to FreeBSD."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"install"
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"2 Options"
block|,
literal|"View/Set various installation options"
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
ifdef|#
directive|ifdef
name|__alpha__
block|{
literal|"3 Label"
block|,
literal|"Label disk partitions"
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
else|#
directive|else
block|{
literal|"3 Partition"
block|,
literal|"Allocate disk space for FreeBSD"
block|,
name|NULL
block|,
name|diskPartitionEditor
block|}
block|,
block|{
literal|"4 Label"
block|,
literal|"Label allocated disk partitions"
block|,
name|NULL
block|,
name|diskLabelEditor
block|}
block|,
block|{
literal|"5 Distributions"
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
literal|"6 Media"
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
literal|"7 Commit"
block|,
literal|"Perform any pending Partition/Label/Extract actions"
block|,
name|NULL
block|,
name|installCustomCommit
block|}
block|,
endif|#
directive|endif
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
block|}
block|,
ifndef|#
directive|ifndef
name|PC98
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
endif|#
directive|endif
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
literal|"If you've already installed FreeBSD, you may use this menu to customize\n"
literal|"it somewhat to suit your particular configuration.  Most importantly,\n"
literal|"you can use the Packages utility to load extra \"3rd party\"\n"
literal|"software not provided in the base distributions."
block|,
literal|"Press F1 for more information on these options"
block|,
literal|"configure"
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|" Distributions"
block|,
literal|"Install additional distribution sets"
block|,
name|NULL
block|,
name|distExtractAll
block|}
block|,
block|{
literal|" Packages"
block|,
literal|"Install pre-packaged software for FreeBSD"
block|,
name|NULL
block|,
name|configPackages
block|}
block|,
block|{
literal|" Root Password"
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
ifdef|#
directive|ifdef
name|__i386__
block|{
literal|" Fdisk"
block|,
literal|"The disk Slice (PC-style partition) Editor"
block|,
name|NULL
block|,
name|diskPartitionEditor
block|}
block|,
endif|#
directive|endif
block|{
literal|" Label"
block|,
literal|"The disk Label editor"
block|,
name|NULL
block|,
name|diskLabelEditor
block|}
block|,
block|{
literal|" User Management"
block|,
literal|"Add user and group information"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuUsermgmt
block|}
block|,
block|{
literal|" Console"
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
literal|" Time Zone"
block|,
literal|"Set which time zone you're in"
block|,
name|NULL
block|,
name|dmenuSystemCommand
block|,
name|NULL
block|,
literal|"tzsetup"
block|}
block|,
block|{
literal|" Media"
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
literal|" Mouse"
block|,
literal|"Configure your mouse"
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
literal|" Networking"
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
literal|" Security"
block|,
literal|"Select default system security profile"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSecurityProfile
block|}
block|,
block|{
literal|" Startup"
block|,
literal|"Configure system startup options"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuStartup
block|}
block|,
block|{
literal|" Options"
block|,
literal|"View/Set various installation options"
block|,
name|NULL
block|,
name|optionsEditor
block|}
block|,
block|{
literal|" XFree86"
block|,
literal|"Configure XFree86 Server"
block|,
name|NULL
block|,
name|configXSetup
block|}
block|,
block|{
literal|" Desktop"
block|,
literal|"Configure XFree86 Desktop"
block|,
name|NULL
block|,
name|configXDesktop
block|}
block|,
block|{
literal|" HTML Docs"
block|,
literal|"Go to the HTML documentation menu (post-install)"
block|,
name|NULL
block|,
name|docBrowser
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
name|MenuStartup
init|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Startup Services Menu"
block|,
literal|"This menu allows you to configure various aspects of your system's\n"
literal|"startup configuration.  Remember to use SPACE to select items!  The\n"
literal|"RETURN key will leave this menu (as with all checkbox menus)."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
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
literal|" APM"
block|,
literal|"Auto-power management services (typically laptops)"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"apm_enable=YES"
block|}
block|,
block|{
literal|" pccard"
block|,
literal|"Enable PCCARD (AKA PCMCIA) services (also laptops)"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"pccard_enable=YES"
block|}
block|,
block|{
literal|" pccard mem"
block|,
literal|"Set PCCARD memory address (if enabled)"
block|,
name|dmenuVarCheck
block|,
name|dmenuISetVariable
block|,
name|NULL
block|,
literal|"pccard_mem"
block|}
block|,
block|{
literal|" pccard ifconfig"
block|,
literal|"List of PCCARD ethernet devices to configure"
block|,
name|dmenuVarCheck
block|,
name|dmenuISetVariable
block|,
name|NULL
block|,
literal|"pccard_ifconfig"
block|}
block|,
block|{
literal|" "
block|,
literal|" -- "
block|,
name|NULL
block|,
name|NULL
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
literal|" startup dirs"
block|,
literal|"Set the list of dirs to look for startup scripts"
block|,
name|dmenuVarCheck
block|,
name|dmenuISetVariable
block|,
name|NULL
block|,
literal|"local_startup"
block|}
block|,
block|{
literal|" named"
block|,
literal|"Run a local name server on this host"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"named_enable=YES"
block|}
block|,
block|{
literal|" named flags"
block|,
literal|"Set default flags to named (if enabled)"
block|,
name|dmenuVarCheck
block|,
name|dmenuISetVariable
block|,
name|NULL
block|,
literal|"named_flags"
block|}
block|,
block|{
literal|" nis client"
block|,
literal|"This host wishes to be an NIS client."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"nis_client_enable=YES"
block|}
block|,
block|{
literal|" nis domainname"
block|,
literal|"Set NIS domainname (if enabled)"
block|,
name|dmenuVarCheck
block|,
name|dmenuISetVariable
block|,
name|NULL
block|,
literal|"nisdomainname"
block|}
block|,
block|{
literal|" nis server"
block|,
literal|"This host wishes to be an NIS server."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"nis_server_enable=YES"
block|}
block|,
block|{
literal|" "
block|,
literal|" -- "
block|,
name|NULL
block|,
name|NULL
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
literal|" accounting"
block|,
literal|"This host wishes to run process accounting."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"accounting_enable=YES"
block|}
block|,
block|{
literal|" lpd"
block|,
literal|"This host has a printer and wants to run lpd."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"lpd_enable=YES"
block|}
block|,
ifdef|#
directive|ifdef
name|__i386__
block|{
literal|" linux"
block|,
literal|"This host wants to be able to run linux binaries."
block|,
name|dmenuVarCheck
block|,
name|configLinux
block|,
name|NULL
block|,
name|VAR_LINUX_ENABLE
literal|"=YES"
block|}
block|,
block|{
literal|" SVR4"
block|,
literal|"This host wants to be able to run SVR4 binaries."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"svr4_enable=YES"
block|}
block|,
block|{
literal|" SCO"
block|,
literal|"This host wants to be able to run IBCS2 binaries."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"ibcs2_enable=YES"
block|}
block|,
elif|#
directive|elif
name|__alpha__
block|{
literal|" OSF/1"
block|,
literal|"This host wants to be able to run DEC OSF/1 binaries."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"osf1_enable=YES"
block|}
block|,
endif|#
directive|endif
block|{
literal|" quotas"
block|,
literal|"This host wishes to check quotas on startup."
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"check_quotas=YES"
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
literal|"You may have already configured one network device (and the other\n"
literal|"various hostname/gateway/name server parameters) in the process\n"
literal|"of installing FreeBSD.  This menu allows you to configure other\n"
literal|"aspects of your system's network configuration."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
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
literal|" Interfaces"
block|,
literal|"Configure additional network interfaces"
block|,
name|NULL
block|,
name|tcpMenuSelect
block|}
block|,
block|{
literal|" AMD"
block|,
literal|"This machine wants to run the auto-mounter service"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"amd_enable=YES"
block|}
block|,
block|{
literal|" AMD Flags"
block|,
literal|"Set flags to AMD service (if enabled)"
block|,
name|dmenuVarCheck
block|,
name|dmenuISetVariable
block|,
name|NULL
block|,
literal|"amd_flags"
block|}
block|,
block|{
literal|" Anon FTP"
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
literal|" Gateway"
block|,
literal|"This machine will route packets between interfaces"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"gateway_enable=YES"
block|}
block|,
block|{
literal|" inetd"
block|,
literal|"This machine wants to run the inet daemon"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"inetd_enable=YES"
block|}
block|,
block|{
literal|" NFS client"
block|,
literal|"This machine will be an NFS client"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"nfs_client_enable=YES"
block|}
block|,
block|{
literal|" NFS server"
block|,
literal|"This machine will be an NFS server"
block|,
name|dmenuVarCheck
block|,
name|configNFSServer
block|,
name|NULL
block|,
literal|"nfs_server_enable=YES"
block|}
block|,
block|{
literal|" Ntpdate"
block|,
literal|"Select a clock-synchronization server"
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
literal|"ntpdate_enable=YES"
block|}
block|,
block|{
literal|" PCNFSD"
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
literal|" portmap"
block|,
literal|"This machine wants to run the portmapper daemon"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"portmap_enable=YES"
block|}
block|,
block|{
literal|" Routed"
block|,
literal|"Select routing daemon (default: routed)"
block|,
name|dmenuVarCheck
block|,
name|configRouter
block|,
name|NULL
block|,
literal|"router_enable=YES"
block|}
block|,
block|{
literal|" Rwhod"
block|,
literal|"This machine wants to run the rwho daemon"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"rwhod_enable=YES"
block|}
block|,
block|{
literal|" Sendmail"
block|,
literal|"This machine wants to run the sendmail daemon"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"sendmail_enable=YES"
block|}
block|,
block|{
literal|" Sshd"
block|,
literal|"This machine wants to run the ssh daemon"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"sshd_enable=YES"
block|}
block|,
block|{
literal|" TCP Extensions"
block|,
literal|"Allow RFC1323 and RFC1644 TCP extensions?"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"tcp_extensions=YES"
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
literal|"There are a number of time synchronization servers available\n"
literal|"for public use around the Internet.  Please select one reasonably\n"
literal|"close to you to have your system time synchronized accordingly."
block|,
literal|"These are the primary open-access NTP servers"
block|,
name|NULL
block|,
block|{
block|{
literal|"None"
block|,
literal|"No NTP server"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=NO,ntpdate_flags=none"
block|}
block|,
block|{
literal|"Other"
block|,
literal|"Select a site not on this list"
block|,
name|dmenuVarsCheck
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
literal|"ntp.nml.csiro.au (HP 5071A Cesium Beam)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.tip.csiro.au"
block|}
block|,
block|{
literal|" Canada"
block|,
literal|"tick.usask.ca (GOES clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tick.usask.ca"
block|}
block|,
block|{
literal|"France"
block|,
literal|"canon.inria.fr (TDF clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=canon.inria.fr"
block|}
block|,
block|{
literal|"Germany"
block|,
literal|"ntps1-{0,1,2}.uni-erlangen.de (GPS)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntps1-0.uni-erlangen.de"
block|}
block|,
block|{
literal|" Germany #2"
block|,
literal|"ntps1-0.cs.tu-berlin.de (GPS)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntps1-0.cs.tu-berlin.de"
block|}
block|,
block|{
literal|"Japan"
block|,
literal|"clock.nc.fukuoka-u.ac.jp (GPS clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock.nc.fukuoka-u.ac.jp"
block|}
block|,
block|{
literal|" Japan #2"
block|,
literal|"clock.tl.fukuoka-u.ac.jp (GPS clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock.tl.fukuoka-u.ac.jp"
block|}
block|,
block|{
literal|"Netherlands"
block|,
literal|"ntp0.nl.net (GPS clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp0.nl.net"
block|}
block|,
block|{
literal|" Norway"
block|,
literal|"timehost.ifi.uio.no (NTP clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=timehost.ifi.uio.no"
block|}
block|,
block|{
literal|"Sweden"
block|,
literal|"Time1.Stupi.SE (Cesium/GPS)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=Time1.Stupi.SE"
block|}
block|,
block|{
literal|" Switzerland"
block|,
literal|"swisstime.ethz.ch (DCF77 clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=swisstime.ethz.ch"
block|}
block|,
block|{
literal|"U.S. East Coast"
block|,
literal|"bitsy.mit.edu (WWV clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=bitsy.mit.edu"
block|}
block|,
block|{
literal|" U.S. East Coast #2"
block|,
literal|"otc1.psu.edu (WWV clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=otc1.psu.edu"
block|}
block|,
block|{
literal|" U.S. West Coast #1"
block|,
literal|"clepsydra.dec.com (GOES clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clepsydra.dec.com"
block|}
block|,
block|{
literal|" U.S. West Coast #2"
block|,
literal|"clock.llnl.gov (WWVB clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock.llnl.gov"
block|}
block|,
block|{
literal|" U.S. Midwest"
block|,
literal|"ncar.ucar.edu (WWVB clock)"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ncar.ucar.edu"
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
literal|"The default system console driver for FreeBSD (syscons) has a\n"
literal|"number of configuration options which may be set according to\n"
literal|"your preference.\n\n"
literal|"When you are done setting configuration options, select Cancel."
block|,
literal|"Configure your system console settings"
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"2 Font"
block|,
literal|"Choose an alternate screen font"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsFont
block|}
block|,
block|{
literal|"3 Keymap"
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
literal|"4 Repeat"
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
literal|"5 Saver"
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
literal|"6 Screenmap"
block|,
literal|"Choose an alternate screenmap"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsScrnmap
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
literal|"The default system console driver for FreeBSD (syscons) defaults\n"
literal|"to a standard \"American\" keyboard map.  Users in other countries\n"
literal|"(or with different keyboard preferences) may wish to choose one of\n"
literal|"the other keymaps below.\n"
literal|"Note that sysinstall itself only uses the part of the keyboard map\n"
literal|"which is required to generate the ANSI character subset, but your\n"
literal|"choice of keymap will also be saved for later (fuller) use."
block|,
literal|"Choose a keyboard map"
block|,
name|NULL
block|,
block|{
block|{
literal|"Belgian"
block|,
literal|"Belgian ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=be.iso"
block|}
block|,
block|{
literal|" Brazil CP850"
block|,
literal|"Brazil CP850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=br275.cp850"
block|}
block|,
block|{
literal|" Brazil ISO (accent)"
block|,
literal|"Brazil ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=br275.iso.acc"
block|}
block|,
block|{
literal|" Brazil ISO"
block|,
literal|"Brazil ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=br275.iso"
block|}
block|,
block|{
literal|" Croatian ISO"
block|,
literal|"Croatian ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=hr.iso"
block|}
block|,
block|{
literal|"Danish CP865"
block|,
literal|"Danish Code Page 865 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=danish.cp865"
block|}
block|,
block|{
literal|" Danish ISO"
block|,
literal|"Danish ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=danish.iso"
block|}
block|,
block|{
literal|"Estonian ISO"
block|,
literal|"Estonian ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=estonian.iso"
block|}
block|,
block|{
literal|" Estonian ISO 15"
block|,
literal|"Estonian ISO 8859-15 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=estonian.iso15"
block|}
block|,
block|{
literal|" Estonian CP850"
block|,
literal|"Estonian Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=estonian.cp850"
block|}
block|,
block|{
literal|"Finnish CP850"
block|,
literal|"Finnish Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=finnish.cp850"
block|}
block|,
block|{
literal|" Finnish ISO"
block|,
literal|"Finnish ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=finnish.iso"
block|}
block|,
block|{
literal|" French ISO (accent)"
block|,
literal|"French ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=fr.iso.acc"
block|}
block|,
block|{
literal|" French ISO"
block|,
literal|"French ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
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
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=german.cp850"
block|}
block|,
block|{
literal|" German ISO"
block|,
literal|"German ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=german.iso"
block|}
block|,
block|{
literal|"Hungarian 101"
block|,
literal|"Hungarian ISO keymap (101 key)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=hu.iso2.101keys"
block|}
block|,
block|{
literal|" Hungarian 102"
block|,
literal|"Hungarian ISO keymap (102 key)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=hu.iso2.102keys"
block|}
block|,
block|{
literal|"Icelandic (accent)"
block|,
literal|"Icelandic ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=icelandic.iso.acc"
block|}
block|,
block|{
literal|" Icelandic"
block|,
literal|"Icelandic ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=icelandic.iso"
block|}
block|,
block|{
literal|" Italian"
block|,
literal|"Italian ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
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
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=jp.106"
block|}
block|,
block|{
literal|"Latin American"
block|,
literal|"Latin American ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=lat-amer"
block|}
block|,
block|{
literal|"Norway ISO"
block|,
literal|"Norwegian ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=norwegian.iso"
block|}
block|,
block|{
literal|"Polish ISO"
block|,
literal|"Polish ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=pl_PL.ISO_8859-2"
block|}
block|,
block|{
literal|" Portuguese (accent)"
block|,
literal|"Portuguese ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=pt.iso.acc"
block|}
block|,
block|{
literal|" Portuguese"
block|,
literal|"Portuguese ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=pt.iso"
block|}
block|,
block|{
literal|"Russia CP866"
block|,
literal|"Russian CP866 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=ru.cp866"
block|}
block|,
block|{
literal|" Russia KOI8-R"
block|,
literal|"Russian KOI8-R keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=ru.koi8-r"
block|}
block|,
block|{
literal|"Slovenian"
block|,
literal|"Slovenian ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=si.iso"
block|}
block|,
block|{
literal|" Spanish (accent)"
block|,
literal|"Spanish ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=spanish.iso.acc"
block|}
block|,
block|{
literal|" Spanish"
block|,
literal|"Spanish ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=spanish.iso"
block|}
block|,
block|{
literal|" Swedish CP850"
block|,
literal|"Swedish Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swedish.cp850"
block|}
block|,
block|{
literal|" Swedish ISO"
block|,
literal|"Swedish ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swedish.iso"
block|}
block|,
block|{
literal|" Swiss French ISO (accent)"
block|,
literal|"Swiss French ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swissfrench.iso.acc"
block|}
block|,
block|{
literal|" Swiss French ISO"
block|,
literal|"Swiss French ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swissfrench.iso"
block|}
block|,
block|{
literal|" Swiss French CP850"
block|,
literal|"Swiss French Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swissfrench.cp850"
block|}
block|,
block|{
literal|" Swiss German ISO (accent)"
block|,
literal|"Swiss German ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swissgerman.iso.acc"
block|}
block|,
block|{
literal|" Swiss German ISO"
block|,
literal|"Swiss German ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swissgerman.iso"
block|}
block|,
block|{
literal|" Swiss German CP850"
block|,
literal|"Swiss German Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=swissgerman.cp850"
block|}
block|,
block|{
literal|"UK CP850"
block|,
literal|"UK Code Page 850 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=uk.cp850"
block|}
block|,
block|{
literal|" UK ISO"
block|,
literal|"UK ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=uk.iso"
block|}
block|,
block|{
literal|" USA CapsLock->Ctrl"
block|,
literal|"US standard (Caps as L-Control)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=us.pc-ctrl"
block|}
block|,
block|{
literal|" USA Dvorak"
block|,
literal|"US Dvorak keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=us.dvorak"
block|}
block|,
block|{
literal|" USA Dvorak (left)"
block|,
literal|"US left handed Dvorak keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=us.dvorakl"
block|}
block|,
block|{
literal|" USA Dvorak (right)"
block|,
literal|"US right handed Dvorak keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=us.dvorakr"
block|}
block|,
block|{
literal|" USA Emacs"
block|,
literal|"US standard optimized for EMACS"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=us.emacs"
block|}
block|,
block|{
literal|" USA ISO"
block|,
literal|"US ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=us.iso"
block|}
block|,
block|{
literal|" USA UNIX"
block|,
literal|"US traditional UNIX-workstation"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=us.unix"
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
literal|"This menu allows you to set the speed at which keys repeat\n"
literal|"when held down."
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
literal|"By default, the console driver will not attempt to do anything\n"
literal|"special with your screen when it's idle.  If you expect to leave your\n"
literal|"monitor switched on and idle for long periods of time then you should\n"
literal|"probably enable one of these screen savers to prevent phosphor burn-in."
block|,
literal|"Choose a nifty-looking screen saver"
block|,
name|NULL
block|,
block|{
block|{
literal|"1 Blank"
block|,
literal|"Simply blank the screen"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=blank"
block|}
block|,
block|{
literal|"2 Daemon"
block|,
literal|"\"BSD Daemon\" animated screen saver (text)"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=daemon"
block|}
block|,
block|{
literal|"3 Fade"
block|,
literal|"Fade out effect screen saver"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=fade"
block|}
block|,
block|{
literal|"4 Fire"
block|,
literal|"Flames effect screen saver"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=fire"
block|}
block|,
block|{
literal|"5 Green"
block|,
literal|"\"Green\" power saving mode (if supported by monitor)"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=green"
block|}
block|,
block|{
literal|"6 Logo"
block|,
literal|"\"BSD Daemon\" animated screen saver (graphics)"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=logo"
block|}
block|,
block|{
literal|"7 Rain"
block|,
literal|"Rain drops screen saver"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=rain"
block|}
block|,
block|{
literal|"8 Snake"
block|,
literal|"Draw a FreeBSD \"snake\" on your screen"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=snake"
block|}
block|,
block|{
literal|"9 Star"
block|,
literal|"A \"twinkling stars\" effect"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=star"
block|}
block|,
block|{
literal|"Warp"
block|,
literal|"A \"stars warping\" effect"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=warp"
block|}
block|,
block|{
literal|"Timeout"
block|,
literal|"Set the screen saver timeout interval"
block|,
name|NULL
block|,
name|configSaverTimeout
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
name|NULL
block|}
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DMenu
name|MenuSysconsScrnmap
init|=
block|{
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"System Console Screenmap"
block|,
literal|"Unless you load a specific font, most PC hardware defaults to\n"
literal|"displaying characters in the IBM 437 character set.  However,\n"
literal|"in the Unix world, this character set is very rarely used.  Most\n"
literal|"Western European countries, for example, prefer ISO 8859-1.\n"
literal|"American users won't notice the difference since the bottom half\n"
literal|"of all these character sets is ANSI anyway.\n"
literal|"If your hardware is capable of downloading a new display font,\n"
literal|"you should probably choose that option.  However, for hardware\n"
literal|"where this is not possible (e.g. monochrome adapters), a screen\n"
literal|"map will give you the best approximation that your hardware can\n"
literal|"display at all."
block|,
literal|"Choose a screen map"
block|,
name|NULL
block|,
block|{
block|{
literal|"None"
block|,
literal|"No screenmap, use default font"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"scrnmap=NO"
block|}
block|,
block|{
literal|"KOI8-R to IBM866"
block|,
literal|"Russian KOI8-R to IBM 866 screenmap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"scrnmap=koi8-r2cp866"
block|}
block|,
block|{
literal|"ISO 8859-1 to IBM437"
block|,
literal|"W-Europe ISO 8859-1 to IBM 437 screenmap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"scrnmap=iso-8859-1_to_cp437"
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
name|MenuSysconsFont
init|=
block|{
name|DMENU_RADIO_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"System Console Font"
block|,
literal|"Most PC hardware defaults to displaying characters in the\n"
literal|"IBM 437 character set.  However, in the Unix world, this\n"
literal|"character set is very rarely used.  Most Western European\n"
literal|"countries, for example, prefer ISO 8859-1.\n"
literal|"American users won't notice the difference since the bottom half\n"
literal|"of all these charactersets is ANSI anyway.  However, they might\n"
literal|"want to load a font anyway to use the 30- or 50-line displays.\n"
literal|"If your hardware is capable of downloading a new display font,\n"
literal|"you can select the appropriate font below."
block|,
literal|"Choose a font"
block|,
name|NULL
block|,
block|{
block|{
literal|"1 None"
block|,
literal|"Use default font"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=NO,font8x14=NO,font8x16=NO"
block|}
block|,
block|{
literal|"2 IBM 437"
block|,
literal|"English"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=cp437-8x8,font8x14=cp437-8x14,font8x16=cp437-8x16"
block|}
block|,
block|{
literal|"3 IBM 850"
block|,
literal|"Western Europe, IBM encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=cp850-8x8,font8x14=cp850-8x14,font8x16=cp850-8x16"
block|}
block|,
block|{
literal|"4 IBM 865"
block|,
literal|"Norwegian, IBM encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=cp865-8x8,font8x14=cp865-8x14,font8x16=cp865-8x16"
block|}
block|,
block|{
literal|"5 IBM 866"
block|,
literal|"Russian, IBM encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=cp866-8x8,font8x14=cp866-8x14,font8x16=cp866-8x16"
block|}
block|,
block|{
literal|"6 ISO 8859-1"
block|,
literal|"Western Europe, ISO encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=iso-8x8,font8x14=iso-8x14,font8x16=iso-8x16"
block|}
block|,
block|{
literal|"7 ISO 8859-2"
block|,
literal|"Eastern Europe, ISO encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=iso02-8x8,font8x14=iso02-8x14,font8x16=iso02-8x16"
block|}
block|,
block|{
literal|"8 KOI8-R"
block|,
literal|"Russian, KOI8-R encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=koi8-r-8x8,font8x14=koi8-r-8x14,font8x16=koi8-r-8x16"
block|}
block|,
block|{
literal|"9 SWISS"
block|,
literal|"English, better resolution"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=swiss-8x8,font8x14=NO,font8x16=swiss-8x16"
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
name|MenuUsermgmt
init|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"User and group management"
block|,
literal|"The submenus here allow to manipulate user groups and\n"
literal|"login accounts.\n"
block|,
literal|"Configure your user groups and users"
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"User"
block|,
literal|"Add a new user to the system."
block|,
name|NULL
block|,
name|userAddUser
block|}
block|,
block|{
literal|"Group"
block|,
literal|"Add a new user group to the system."
block|,
name|NULL
block|,
name|userAddGroup
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
name|MenuSecurityProfile
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Default system security profile"
block|,
literal|"Each item in this list will set what it considers to\n"
literal|"be \"appropriate\" values in that category for various\n"
literal|"security-related knobs in /etc/rc.conf."
block|,
literal|"Select a canned security profile."
block|,
name|NULL
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|configSecurityModerate
block|}
block|,
block|{
literal|"Low"
block|,
literal|"Fairly wide-open (little) security."
block|,
name|NULL
block|,
name|configSecurityLiberal
block|}
block|,
block|{
literal|"Medium"
block|,
literal|"Moderate security settings [DEFAULT]."
block|,
name|NULL
block|,
name|configSecurityModerate
block|}
block|,
block|{
literal|"High"
block|,
literal|"Fairly safe security settings."
block|,
name|NULL
block|,
name|configSecurityHigh
block|}
block|,
block|{
literal|"Extreme"
block|,
literal|"Very restrictive security settings."
block|,
name|NULL
block|,
name|configSecurityFascist
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
literal|"There are three ways of going into \"fixit\" mode:\n"
literal|"- you can use the 2nd FreeBSD CDROM, in which case there will be\n"
literal|"  full access to the complete set of FreeBSD commands and utilities,\n"
literal|"- you can use the more limited (but perhaps customized) fixit floppy,\n"
literal|"- or you can start an Emergency Holographic Shell now, which is\n"
literal|"  limited to the subset of commands that is already available right now."
block|,
literal|"Press F1 for more detailed repair instructions"
block|,
literal|"fixit"
block|,
block|{
block|{
literal|"X Exit"
block|,
literal|"Exit this menu (returning to previous)"
block|,
name|NULL
block|,
name|dmenuExit
block|}
block|,
block|{
literal|"2 CDROM"
block|,
literal|"Use the 2nd \"live\" CDROM from the distribution"
block|,
name|NULL
block|,
name|installFixitCDROM
block|}
block|,
block|{
literal|"3 Floppy"
block|,
literal|"Use a floppy generated from the fixit image"
block|,
name|NULL
block|,
name|installFixitFloppy
block|}
block|,
block|{
literal|"4 Shell"
block|,
literal|"Start an Emergency Holographic Shell"
block|,
name|NULL
block|,
name|installFixitHoloShell
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

