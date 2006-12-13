begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last program in the `sysinstall' line - the next  * generation being essentially a complete rewrite.  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
name|setKernel
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|Dists
operator||=
name|DIST_KERNEL
expr_stmt|;
name|KernelDists
operator|=
name|DIST_KERNEL_ALL
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
name|clearKernel
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|Dists
operator|&=
operator|~
name|DIST_KERNEL
expr_stmt|;
name|KernelDists
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
name|setX11Misc
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
block|{
name|XOrgDists
operator||=
name|DIST_XORG_MISC_ALL
expr_stmt|;
name|Dists
operator||=
name|DIST_XORG
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
name|XOrgDists
operator|&=
operator|~
name|DIST_XORG_MISC_ALL
expr_stmt|;
if|if
condition|(
operator|!
name|XOrgDists
condition|)
name|Dists
operator|&=
operator|~
name|DIST_XORG
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
name|XOrgDists
operator||=
name|DIST_XORG_SERVER_ALL
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
name|XOrgDists
operator|&=
operator|~
name|DIST_XORG_SERVER_ALL
expr_stmt|;
if|if
condition|(
operator|!
name|XOrgDists
condition|)
name|Dists
operator|&=
operator|~
name|DIST_XORG
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
name|XOrgDists
operator||=
name|DIST_XORG_FONTS_ALL
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
name|XOrgDists
operator|&=
operator|~
name|DIST_XORG_FONTS_ALL
expr_stmt|;
if|if
condition|(
operator|!
name|XOrgDists
condition|)
name|Dists
operator|&=
operator|~
name|DIST_XORG
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
name|DIST_XORG
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
name|DIST_XORG
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
name|DIST_XORG
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
operator|(
name|DIST_BASE
operator||
name|DIST_KERNEL
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
name|Dists
operator|==
name|DIST_ALL
operator|&&
name|_IS_SET
argument_list|(
name|SrcDists
argument_list|,
name|DIST_SRC_ALL
argument_list|)
operator|&&
name|_IS_SET
argument_list|(
name|XOrgDists
argument_list|,
name|DIST_XORG_ALL
argument_list|)
operator|&&
name|_IS_SET
argument_list|(
name|KernelDists
argument_list|,
name|DIST_KERNEL_ALL
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
if|if
condition|(
name|XOrgDists
operator|!=
literal|0
condition|)
name|Dists
operator||=
name|DIST_XORG
expr_stmt|;
else|else
name|Dists
operator|&=
operator|~
name|DIST_XORG
expr_stmt|;
return|return
name|Dists
operator|&
name|DIST_XORG
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|kernelFlagCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
block|{
return|return
name|KernelDists
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
literal|"this program (sysinstall).  Invoke an option by pressing [SPACE] or\n"
literal|"[ENTER].  To exit, use [TAB] to move to the Cancel button."
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
literal|" Country"
block|,
literal|"Set the system's country"
block|,
name|NULL
block|,
name|configCountry
block|}
block|,
ifdef|#
directive|ifdef
name|WITH_SYSCONS
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
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|WITH_MICE
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
endif|#
directive|endif
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
literal|" Distributions, X.Org"
block|,
literal|"X.Org distribution menu."
block|,
name|NULL
block|,
name|distSetXOrg
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
literal|" Doc, Errata"
block|,
literal|"The distribution errata."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"ERRATA"
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
name|WITH_SLICES
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
literal|" inetd Configuration"
block|,
literal|"Configure inetd and simple internet services."
block|,
name|dmenuVarCheck
block|,
name|configInetd
block|,
name|NULL
block|,
literal|"inetd_enable=YES"
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
literal|" Media, CDROM/DVD"
block|,
literal|"Select CDROM/DVD installation media."
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
ifdef|#
directive|ifdef
name|WITH_SLICES
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
endif|#
directive|endif
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
literal|"Configure system security options"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSecurity
block|}
block|,
ifdef|#
directive|ifdef
name|WITH_SYSCONS
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
ifndef|#
directive|ifndef
name|PC98
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
endif|#
directive|endif
block|{
literal|" Syscons, Keymap"
block|,
literal|"The console keymap configuration menu."
block|,
name|NULL
block|,
name|keymapMenuSelect
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
ifndef|#
directive|ifndef
name|PC98
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
literal|" Syscons, Ttys"
block|,
literal|"The console terminal type menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsTtys
block|}
block|,
endif|#
directive|endif
endif|#
directive|endif
comment|/* WITH_SYSCONS */
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
literal|" TTYs"
block|,
literal|"Configure system ttys."
block|,
name|NULL
block|,
name|configEtcTtys
block|,
name|NULL
block|,
literal|"ttys"
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
literal|" X.Org, Fonts"
block|,
literal|"X.Org Font selection menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXOrgSelectFonts
block|}
block|,
block|{
literal|" X.Org, Server"
block|,
literal|"X.Org Server selection menu."
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuXOrgSelectServer
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
comment|/* The country menu */
end_comment

begin_include
include|#
directive|include
file|"countries.h"
end_include

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
literal|"sysinstall Main Menu"
block|,
comment|/* title */
literal|"Welcome to the FreeBSD installation and configuration tool.  Please\n"
comment|/* prompt */
literal|"select one of the options below by using the arrow keys or typing the\n"
literal|"first character of the option name you're interested in.  Invoke an\n"
literal|"option with [SPACE] or [ENTER].  To exit, use [TAB] to move to Exit."
block|,
literal|"Press F1 for Installation Guide"
block|,
comment|/* help line */
literal|"INSTALL"
block|,
comment|/* help file */
block|{
block|{
literal|" Select "
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
literal|"Begin a quick installation (for experts)"
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
ifdef|#
directive|ifdef
name|WITH_SYSCONS
block|{
literal|"Keymap"
block|,
literal|"Select keyboard type"
block|,
name|NULL
block|,
name|keymapMenuSelect
block|}
block|,
endif|#
directive|endif
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
literal|"Repair mode with CDROM/DVD/floppy or start shell"
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
literal|"README"
block|}
block|,
block|{
literal|"2 Errata"
block|,
literal|"Late-breaking, post-release news."
block|,
name|NULL
block|,
name|dmenuDisplayFile
block|,
name|NULL
block|,
literal|"ERRATA"
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

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_MICE
end_ifdef

begin_decl_stmt
name|DMenu
name|MenuMouseType
init|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
ifdef|#
directive|ifdef
name|PC98
literal|"Select a protocol type for your mouse"
block|,
literal|"If your mouse is attached to the bus mouse port, you should always choose\n"
literal|"\"Auto\", regardless of the model and the brand of the mouse.  All other\n"
literal|"protocol types are for serial mice and should not be used with the bus\n"
literal|"mouse.  If you have a serial mouse and are not sure about its protocol,\n"
literal|"you should also try \"Auto\".  It may not work for the serial mouse if the\n"
literal|"mouse does not support the PnP standard.  But, it won't hurt.  Many\n"
literal|"2-button serial mice are compatible with \"Microsoft\" or \"MouseMan\".\n"
literal|"3-button serial mice may be compatible with \"MouseSystems\" or \"MouseMan\".\n"
literal|"If the serial mouse has a wheel, it may be compatible with \"IntelliMouse\"."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"1 Auto"
block|,
literal|"Bus mouse or PnP serial mouse"
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
else|#
directive|else
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
endif|#
directive|endif
comment|/* PC98 */
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
block|;
ifdef|#
directive|ifdef
name|PC98
name|DMenu
name|MenuMousePort
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select your mouse port from the following menu"
block|,
literal|"The built-in pointing device of laptop/notebook computers is usually\n"
literal|"a BusMouse style device."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"1 BusMouse"
block|,
literal|"PC-98x1 bus mouse (/dev/mse0)"
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
literal|"2 COM1"
block|,
literal|"Serial mouse on COM1 (/dev/cuad0)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuad0"
block|}
block|,
block|{
literal|"3 COM2"
block|,
literal|"Serial mouse on COM2 (/dev/cuad1)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuad1"
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
else|#
directive|else
name|DMenu
name|MenuMousePort
operator|=
block|{
name|DMENU_NORMAL_TYPE
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
literal|"Serial mouse on COM1 (/dev/cuad0)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuad0"
block|}
block|,
block|{
literal|"3 COM2"
block|,
literal|"Serial mouse on COM2 (/dev/cuad1)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuad1"
block|}
block|,
block|{
literal|"4 COM3"
block|,
literal|"Serial mouse on COM3 (/dev/cuad2)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuad2"
block|}
block|,
block|{
literal|"5 COM4"
block|,
literal|"Serial mouse on COM4 (/dev/cuad3)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_MOUSED_PORT
literal|"=/dev/cuad3"
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
block|;
endif|#
directive|endif
comment|/* PC98 */
name|DMenu
name|MenuMouse
operator|=
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
block|;
endif|#
directive|endif
comment|/* WITH_MICE */
name|DMenu
name|MenuMediaCDROM
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose a CD/DVD type"
block|,
literal|"FreeBSD can be installed directly from a CD/DVD containing a valid\n"
literal|"FreeBSD distribution.  If you are seeing this menu it is because\n"
literal|"more than one CD/DVD drive was found on your system.  Please select one\n"
literal|"of the following CD/DVD drives as your installation drive."
block|,
literal|"Press F1 to read the installation guide"
block|,
literal|"INSTALL"
block|,
block|{
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuMediaFloppy
operator|=
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
block|;
name|DMenu
name|MenuMediaDOS
operator|=
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
literal|"INSTALL"
block|,
block|{
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuMediaFTP
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Please select a FreeBSD FTP distribution site"
block|,
literal|"Please select the site closest to you or \"other\" if you'd like to\n"
literal|"specify a different choice.  Also note that not every site listed here\n"
literal|"carries more than the base distribution kits. Only Primary sites are\n"
literal|"guaranteed to carry the full range of possible distributions."
block|,
literal|"Select a site that's close!"
block|,
literal|"INSTALL"
block|,
block|{
block|{
literal|"Main Site"
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
literal|"Snapshots Server Japan"
block|,
literal|"snapshots.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://snapshots.jp.freebsd.org"
block|}
block|,
block|{
literal|"Snapshots Server Sweden"
block|,
literal|"snapshots.se.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://snapshots.se.freebsd.org"
block|}
block|,
block|{
literal|"IPv6 Main Site"
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
literal|" IPv6 Ireland"
block|,
literal|"ftp3.ie.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.ie.freebsd.org"
block|}
block|,
block|{
literal|" IPv6 Israel"
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
literal|" IPv6 Japan"
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
literal|" IPv6 USA"
block|,
literal|"ftp4.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.us.freebsd.org"
block|}
block|,
block|{
literal|" IPv6 Turkey"
block|,
literal|"ftp2.tr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.tr.freebsd.org"
block|}
block|,
block|{
literal|"Primary"
block|,
literal|"ftp1.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp1.freebsd.org"
block|}
block|,
block|{
literal|" Primary #2"
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
literal|" Primary #3"
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
literal|" Primary #4"
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
literal|" Primary #5"
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
literal|" Primary #6"
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
literal|" Primary #7"
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
literal|"=ftp://ftp7.freebsd.org"
block|}
block|,
block|{
literal|" Primary #8"
block|,
literal|"ftp8.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp8.freebsd.org"
block|}
block|,
block|{
literal|" Primary #9"
block|,
literal|"ftp9.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp9.freebsd.org"
block|}
block|,
block|{
literal|" Primary #10"
block|,
literal|"ftp10.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp10.freebsd.org"
block|}
block|,
block|{
literal|" Primary #11"
block|,
literal|"ftp11.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp11.freebsd.org"
block|}
block|,
block|{
literal|" Primary #12"
block|,
literal|"ftp12.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp12.freebsd.org"
block|}
block|,
block|{
literal|" Primary #13"
block|,
literal|"ftp13.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp13.freebsd.org"
block|}
block|,
block|{
literal|" Primary #14"
block|,
literal|"ftp14.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp14.freebsd.org"
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
literal|"Austria"
block|,
literal|"ftp.at.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.at.freebsd.org"
block|}
block|,
block|{
literal|" Austria #2"
block|,
literal|"ftp2.at.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.at.freebsd.org"
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
literal|"=ftp://ftp.ca.freebsd.org"
block|}
block|,
block|{
literal|"China"
block|,
literal|"ftp.cn.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.cn.freebsd.org"
block|}
block|,
block|{
literal|" China #2"
block|,
literal|"ftp2.cn.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.cn.freebsd.org"
block|}
block|,
block|{
literal|"Croatia"
block|,
literal|"ftp.hr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.hr.freebsd.org"
block|}
block|,
block|{
literal|"Czech Republic"
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
literal|"France"
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
literal|" France #8"
block|,
literal|"ftp8.fr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp8.fr.freebsd.org"
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
literal|" Germany #8"
block|,
literal|"ftp8.de.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp8.de.freebsd.org"
block|}
block|,
block|{
literal|"Greece"
block|,
literal|"ftp.gr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.gr.freebsd.org"
block|}
block|,
block|{
literal|" Greece #2"
block|,
literal|"ftp2.gr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.gr.freebsd.org"
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
literal|"=ftp://ftp.hk.super.net"
block|}
block|,
block|{
literal|"Hungary"
block|,
literal|"ftp.hu.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.hu.freebsd.org"
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
literal|"=ftp://ftp.ie.freebsd.org"
block|}
block|,
block|{
literal|" Ireland #2"
block|,
literal|"ftp2.ie.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.ie.freebsd.org"
block|}
block|,
block|{
literal|" Ireland #3"
block|,
literal|"ftp3.ie.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.ie.freebsd.org"
block|}
block|,
block|{
literal|"Isreal"
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
literal|"Italy"
block|,
literal|"ftp.it.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.it.freebsd.org"
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
literal|" Japan #8"
block|,
literal|"ftp8.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp8.jp.freebsd.org"
block|}
block|,
block|{
literal|" Japan #9"
block|,
literal|"ftp9.jp.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp9.jp.freebsd.org"
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
literal|"Netherlands"
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
literal|" Netherlands #2"
block|,
literal|"ftp2.nl.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.nl.freebsd.org"
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
literal|" Norway #3"
block|,
literal|"ftp3.no.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.no.freebsd.org"
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
literal|" Poland #2"
block|,
literal|"ftp2.pl.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.pl.freebsd.org"
block|}
block|,
block|{
literal|" Poland #5"
block|,
literal|"ftp5.pl.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.pl.freebsd.org"
block|}
block|,
block|{
literal|"Portugal"
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
literal|" Portugal #4"
block|,
literal|"ftp4.pt.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.pt.freebsd.org"
block|}
block|,
block|{
literal|"Romania"
block|,
literal|"ftp.ro.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ro.freebsd.org"
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
literal|"Singapore"
block|,
literal|"ftp.sg.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.sg.freebsd.org"
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
literal|" Slovenia #2"
block|,
literal|"ftp2.si.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.si.freebsd.org"
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
literal|"Spain"
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
literal|" Spain #3"
block|,
literal|"ftp3.es.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.es.freebsd.org"
block|}
block|,
block|{
literal|"Sweden"
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
literal|" Sweden #5"
block|,
literal|"ftp5.se.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.se.freebsd.org"
block|}
block|,
block|{
literal|"Switzerland"
block|,
literal|"ftp.ch.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ch.freebsd.org"
block|}
block|,
block|{
literal|" Switzerland #2"
block|,
literal|"ftp2.ch.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.ch.freebsd.org"
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
literal|" Taiwan #6"
block|,
literal|"ftp6.tw.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.tw.freebsd.org"
block|}
block|,
block|{
literal|" Taiwan #11"
block|,
literal|"ftp11.tw.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp11.tw.freebsd.org"
block|}
block|,
block|{
literal|"Turkey"
block|,
literal|"ftp.tr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.tr.freebsd.org"
block|}
block|,
block|{
literal|" Turkey #2"
block|,
literal|"ftp2.tr.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.tr.freebsd.org"
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
literal|" UK #6"
block|,
literal|"ftp6.uk.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.uk.freebsd.org"
block|}
block|,
block|{
literal|"Ukraine"
block|,
literal|"ftp.ua.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp.ua.freebsd.org"
block|}
block|,
block|{
literal|" Ukraine #2"
block|,
literal|"ftp2.ua.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.ua.freebsd.org"
block|}
block|,
block|{
literal|" Ukraine #5"
block|,
literal|"ftp5.ua.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.ua.freebsd.org"
block|}
block|,
block|{
literal|" Ukraine #6"
block|,
literal|"ftp6.ua.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.ua.freebsd.org"
block|}
block|,
block|{
literal|" Ukraine #7"
block|,
literal|"ftp7.ua.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp7.ua.freebsd.org"
block|}
block|,
block|{
literal|" Ukraine #8"
block|,
literal|"ftp8.ua.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp8.ua.freebsd.org"
block|}
block|,
block|{
literal|"USA #1"
block|,
literal|"ftp1.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp1.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #2"
block|,
literal|"ftp2.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp2.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #3"
block|,
literal|"ftp3.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp3.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #4"
block|,
literal|"ftp4.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp4.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #5"
block|,
literal|"ftp5.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp5.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #6"
block|,
literal|"ftp6.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp6.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #7"
block|,
literal|"ftp7.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp7.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #8"
block|,
literal|"ftp8.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp8.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #9"
block|,
literal|"ftp9.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp9.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #10"
block|,
literal|"ftp10.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp10.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #11"
block|,
literal|"ftp11.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp11.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #12"
block|,
literal|"ftp12.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp12.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #13"
block|,
literal|"ftp13.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp13.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #14"
block|,
literal|"ftp14.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp14.us.freebsd.org"
block|}
block|,
block|{
literal|" USA #15"
block|,
literal|"ftp15.us.freebsd.org"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_FTP_PATH
literal|"=ftp://ftp15.us.freebsd.org"
block|}
block|,
block|{
name|NULL
block|}
block|}
block|}
block|;
name|DMenu
name|MenuMediaTape
operator|=
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
literal|"INSTALL"
block|,
block|{
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuNetworkDevice
operator|=
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
literal|"cable to another machine running FreeBSD."
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
block|;
comment|/* Prototype KLD load menu */
name|DMenu
name|MenuKLD
operator|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"KLD Menu"
block|,
literal|"Load a KLD from a floppy\n"
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
block|;
comment|/* The media selection menu */
name|DMenu
name|MenuMedia
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Choose Installation Media"
block|,
literal|"FreeBSD can be installed from a variety of different installation\n"
literal|"media, ranging from floppies to an Internet FTP server.  If you're\n"
literal|"installing FreeBSD from a supported CD/DVD drive then this is generally\n"
literal|"the best media to use if you have no overriding reason for using other\n"
literal|"media."
block|,
literal|"Press F1 for more information on the various media types"
block|,
literal|"media"
block|,
block|{
block|{
literal|"1 CD/DVD"
block|,
literal|"Install from a FreeBSD CD/DVD"
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
block|;
comment|/* The distributions menu */
name|DMenu
name|MenuDistributions
operator|=
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
literal|"Choose an item by pressing [SPACE] or [ENTER].  When finished, choose the\n"
literal|"Exit item or move to the OK button with [TAB]."
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
literal|"All system sources, binaries and X Window System"
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
block|;
name|DMenu
name|MenuSubDistributions
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select the distributions you wish to install."
block|,
literal|"Please check off the distributions you wish to install.  At the\n"
literal|"very minimum, this should be \"base\"."
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
literal|" base"
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
name|DIST_BASE
block|}
block|,
block|{
literal|" kernels"
block|,
literal|"Binary kernel distributions (required)"
block|,
name|kernelFlagCheck
block|,
name|distSetKernel
block|}
block|,
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
ifdef|#
directive|ifdef
name|__amd64__
block|{
literal|" lib32"
block|,
literal|"32-bit runtime compatibility libraries"
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
name|DIST_LIB32
block|}
block|,
endif|#
directive|endif
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
literal|"Sources for everything"
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
literal|" X.Org"
block|,
literal|"The X.Org distribution"
block|,
name|x11FlagCheck
block|,
name|distSetXOrg
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuKernelDistributions
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select the operating system kernels you wish to install."
block|,
literal|"Please check off those kernels you wish to install.\n"
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
name|setKernel
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
name|clearKernel
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
literal|" GENERIC"
block|,
literal|"GENERIC kernel configuration"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|KernelDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_KERNEL_GENERIC
block|}
block|,
ifdef|#
directive|ifdef
name|WITH_SMP
block|{
literal|" SMP"
block|,
literal|"GENERIC symmetric multiprocessor kernel configuration"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|KernelDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_KERNEL_SMP
block|}
block|,
endif|#
directive|endif
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuSrcDistributions
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Select the sub-components of src you wish to install."
block|,
literal|"Please check off those portions of the FreeBSD source tree\n"
literal|"you wish to install."
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
literal|" crypto"
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
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_SCRYPTO
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
literal|" krb5"
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
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_SKERBEROS5
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
literal|" rescue"
block|,
literal|"/usr/src/rescue (static rescue tools)"
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
name|DIST_SRC_RESCUE
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
literal|" secure"
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
name|SrcDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_SRC_SSECURE
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
block|;
name|DMenu
name|MenuXOrgConfig
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Please select the X.Org configuration tool you want to use."
block|,
literal|"The first option, xorgcfg, is fully graphical.\n"
literal|"The second option provides a menu-based interface similar to\n"
literal|"what you are currently using. "
literal|"The third option, xorgconfig, is\n"
literal|"a more simplistic shell-script based tool and less friendly to\n"
literal|"new users, but it may work in situations where the other options\n"
literal|"do not."
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
literal|"2 xorgcfg"
block|,
literal|"Fully graphical X.Org configuration tool."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_XORG_CONFIG
literal|"=xorgcfg"
block|}
block|,
block|{
literal|"3 xorgcfg -textmode"
block|,
literal|"ncurses-based X.Org configuration tool."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_XORG_CONFIG
literal|"=xorgcfg -textmode"
block|}
block|,
block|{
literal|"4 xorgconfig"
block|,
literal|"Shell-script based X.Org configuration tool."
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_XORG_CONFIG
literal|"=xorgconfig"
block|}
block|,
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
block|;
name|DMenu
name|MenuXDesktops
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Please select the default X desktop to use."
block|,
literal|"By default, X.Org comes with a fairly vanilla desktop which\n"
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
literal|"The K Desktop Environment (Lite Edition)"
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
literal|"3 GNOME 2"
block|,
literal|"The GNOME 2 Desktop Environment (Lite Edition)"
block|,
name|NULL
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_DESKSTYLE
literal|"=gnome2"
block|}
block|,
block|{
literal|"4 Afterstep"
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
literal|"5 Windowmaker"
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
literal|"6 fvwm"
block|,
literal|"The fvwm window manager"
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
block|;
name|DMenu
name|MenuXOrgSelect
operator|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"X.Org Distribution"
block|,
literal|"Please select the components you need from the X.Org\n"
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
name|MenuXOrgSelectCore
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
name|MenuXOrgSelectServer
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
name|MenuXOrgSelectFonts
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuXOrgSelectCore
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"X.Org base distribution types"
block|,
literal|"Please check off the basic X.Org components you wish to install.\n"
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
literal|" lib"
block|,
literal|"Shared libraries and data files needed at runtime"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_LIB
block|}
block|,
block|{
literal|" bin"
block|,
literal|"Client applications"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_CLIENTS
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
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_MAN
block|}
block|,
block|{
literal|" doc"
block|,
literal|"Documentation"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_DOC
block|}
block|,
block|{
literal|" prog"
block|,
literal|"Programming tools"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_IMAKE
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuXOrgSelectFonts
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"X.Org Font distribution selection."
block|,
literal|"Please check off the individual font distributions you wish to\n\ install.  At the minimum, you should install the standard\n\ 75 DPI and misc fonts if you're also installing an X server\n\ (these are selected by default).  The TrueType set is also \n\ highly recommended.  The font server is unnecessary in most\n\ configurations."
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
literal|" fmsc"
block|,
literal|"Standard miscellaneous fonts"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_FONTS_MISC
block|}
block|,
block|{
literal|" f75"
block|,
literal|"75 DPI fonts"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_FONTS_75
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
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_FONTS_100
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
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_FONTS_CYR
block|}
block|,
block|{
literal|" ft1"
block|,
literal|"Type1 scalable fonts"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_FONTS_T1
block|}
block|,
block|{
literal|" ftt"
block|,
literal|"TrueType scalable fonts"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_FONTS_TT
block|}
block|,
block|{
literal|" fs"
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
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_FONTSERVER
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuXOrgSelectServer
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"X.Org X Server selection."
block|,
literal|"Please check off the types of X servers you wish to install.\n"
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
literal|" srv"
block|,
literal|"Standard Graphics Framebuffer"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_SERVER
block|}
block|,
block|{
literal|" nest"
block|,
literal|"Nested X Server"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_NESTSERVER
block|}
block|,
block|{
literal|" prt"
block|,
literal|"X Print Server"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_PRINTSERVER
block|}
block|,
block|{
literal|" vfb"
block|,
literal|"Virtual Framebuffer"
block|,
name|dmenuFlagCheck
block|,
name|dmenuSetFlag
block|,
name|NULL
block|,
operator|&
name|XOrgDists
block|,
literal|'['
block|,
literal|'X'
block|,
literal|']'
block|,
name|DIST_XORG_VFBSERVER
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuDiskDevices
operator|=
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
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuHTMLDoc
operator|=
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
block|;
comment|/* The main installation menu */
name|DMenu
name|MenuInstallCustom
operator|=
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
literal|"INSTALL"
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
ifndef|#
directive|ifndef
name|WITH_SLICES
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
block|;
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
ifdef|#
directive|ifdef
name|PC98
comment|/* IPL type menu */
name|DMenu
name|MenuIPLType
operator|=
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
block|}
block|}
block|, }
block|;
else|#
directive|else
comment|/* MBR type menu */
name|DMenu
name|MenuMBRType
operator|=
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
block|;
endif|#
directive|endif
comment|/* PC98 */
endif|#
directive|endif
comment|/* __i386__ */
comment|/* Final configuration menu */
name|DMenu
name|MenuConfigure
operator|=
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
name|WITH_SLICES
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
ifdef|#
directive|ifdef
name|WITH_SYSCONS
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
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|WITH_MICE
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
block|}
block|,
endif|#
directive|endif
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
literal|"Configure system security options"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSecurity
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
literal|" TTYs"
block|,
literal|"Configure system ttys."
block|,
name|NULL
block|,
name|configEtcTtys
block|,
name|NULL
block|,
literal|"ttys"
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
literal|" Load KLD"
block|,
literal|"Load a KLD from a floppy"
block|,
name|NULL
block|,
name|kldBrowser
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuStartup
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Startup Services Menu"
block|,
literal|"This menu allows you to configure various aspects of your system's\n"
literal|"startup configuration.  Use [SPACE] or [ENTER] to select items, and\n"
literal|"[TAB] to move to the buttons.  Select Exit to leave this menu."
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
ifdef|#
directive|ifdef
name|__i386__
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PCCARD_ARCH
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
endif|#
directive|endif
block|{
literal|" usbd"
block|,
literal|"Enable USB daemon (detect USB attach / detach)"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"usbd_enable=YES"
block|}
block|,
block|{
literal|" usbd flags"
block|,
literal|"Set default flags to usbd (if enabled)"
block|,
name|dmenuVarCheck
block|,
name|dmenuISetVariable
block|,
name|NULL
block|,
literal|"usbd_flags"
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
literal|" Startup dirs"
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
literal|" NIS client"
block|,
literal|"This host wishes to be an NIS client."
block|,
name|dmenuVarCheck
block|,
name|configRpcBind
block|,
name|NULL
block|,
literal|"nis_client_enable=YES"
block|}
block|,
block|{
literal|" NIS domainname"
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
literal|" NIS server"
block|,
literal|"This host wishes to be an NIS server."
block|,
name|dmenuVarCheck
block|,
name|configRpcBind
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
literal|" Accounting"
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
name|WITH_LINUX
block|{
literal|" Linux"
block|,
literal|"This host wants to be able to run Linux binaries."
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__i386__
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__alpha__
block|{
literal|" OSF/1"
block|,
literal|"This host wants to be able to run DEC OSF/1 binaries."
block|,
name|dmenuVarCheck
block|,
name|configOSF1
block|,
name|NULL
block|,
name|VAR_OSF1_ENABLE
literal|"=YES"
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
block|;
name|DMenu
name|MenuNetworking
operator|=
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
name|configRpcBind
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
name|configInetd
block|,
name|NULL
block|,
literal|"inetd_enable=YES"
block|}
block|,
block|{
literal|" Mail"
block|,
literal|"This machine wants to run a Mail Transfer Agent"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuMTA
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
operator|(
name|uintptr_t
operator|)
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
literal|" rpcbind"
block|,
literal|"RPC port mapping daemon (formerly portmapper)"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"rpcbind_enable=YES"
block|}
block|,
block|{
literal|" rpc.statd"
block|,
literal|"NFS status monitoring daemon"
block|,
name|dmenuVarCheck
block|,
name|configRpcBind
block|,
name|NULL
block|,
literal|"rpc_statd_enable=YES"
block|}
block|,
block|{
literal|" rpc.lockd"
block|,
literal|"NFS file locking daemon"
block|,
name|dmenuVarCheck
block|,
name|configRpcBind
block|,
name|NULL
block|,
literal|"rpc_lockd_enable=YES"
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
literal|" sshd"
block|,
literal|"This machine wants to run the SSH daemon"
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
block|;
name|DMenu
name|MenuMTA
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Mail Transfer Agent Selection"
block|,
literal|"You can choose which Mail Transfer Agent (MTA) you wish to install and run.\n"
literal|"Selecting Sendmail local disables sendmail's network socket for\n"
literal|"incoming mail, but still enables sendmail for local and outbound mail.\n"
literal|"The Postfix option will install the Postfix MTA from the ports\n"
literal|"collection.  The Exim option will install the Exim MTA from the ports\n"
literal|"collection.  To return to the previous menu, select Exit."
block|,
name|NULL
block|,
name|NULL
block|,
block|{
block|{
literal|"Sendmail"
block|,
literal|"Use sendmail"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"sendmail_enable=YES"
block|}
block|,
block|{
literal|"Sendmail local"
block|,
literal|"Use sendmail, but do not listen on the network"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"sendmail_enable=NO"
block|}
block|,
block|{
literal|"Postfix"
block|,
literal|"Use the Postfix MTA"
block|,
name|NULL
block|,
name|configMTAPostfix
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|"Exim"
block|,
literal|"Use the Exim MTA"
block|,
name|NULL
block|,
name|configMTAExim
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
literal|"None"
block|,
literal|"Do not install an MTA"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"sendmail_enable=NONE"
block|}
block|,
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
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuNTP
operator|=
block|{
name|DMENU_NORMAL_TYPE
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
literal|"Worldwide"
block|,
literal|"pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=pool.ntp.org"
block|}
block|,
block|{
literal|"Asia"
block|,
literal|"asia.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=asia.pool.ntp.org"
block|}
block|,
block|{
literal|"Europe"
block|,
literal|"europe.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=europe.pool.ntp.org"
block|}
block|,
block|{
literal|"Oceania"
block|,
literal|"oceania.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=oceania.pool.ntp.org"
block|}
block|,
block|{
literal|"North America"
block|,
literal|"north-america.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=north-america.pool.ntp.org"
block|}
block|,
block|{
literal|"Argentina"
block|,
literal|"tick.nap.com.ar"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tick.nap.com.ar"
block|}
block|,
block|{
literal|"Argentina #2"
block|,
literal|"time.sinectis.com.ar"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.sinectis.com.ar"
block|}
block|,
block|{
literal|"Argentina #3"
block|,
literal|"tock.nap.com.ar"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tock.nap.com.ar"
block|}
block|,
block|{
literal|"Australia"
block|,
literal|"au.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=au.pool.ntp.org"
block|}
block|,
block|{
literal|"Australia #2"
block|,
literal|"augean.eleceng.adelaide.edu.au"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=augean.eleceng.adelaide.edu.au"
block|}
block|,
block|{
literal|"Australia #3"
block|,
literal|"ntp.adelaide.edu.au"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.adelaide.edu.au"
block|}
block|,
block|{
literal|"Australia #4"
block|,
literal|"ntp.saard.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.saard.net"
block|}
block|,
block|{
literal|"Australia #5"
block|,
literal|"time.deakin.edu.au"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.deakin.edu.au"
block|}
block|,
block|{
literal|"Belgium"
block|,
literal|"ntp1.belbone.be"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.belbone.be"
block|}
block|,
block|{
literal|"Belgium #2"
block|,
literal|"ntp2.belbone.be"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.belbone.be"
block|}
block|,
block|{
literal|"Brazil"
block|,
literal|"ntp.cais.rnp.br"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.cais.rnp.br"
block|}
block|,
block|{
literal|"Brazil #2"
block|,
literal|"ntp.pop-df.rnp.br"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.pop-df.rnp.br"
block|}
block|,
block|{
literal|"Brazil #3"
block|,
literal|"ntp.ufes.br"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.ufes.br"
block|}
block|,
block|{
literal|"Brazil #4"
block|,
literal|"ntp1.pucpr.br"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.pucpr.br"
block|}
block|,
block|{
literal|"Canada"
block|,
literal|"ca.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ca.pool.ntp.org"
block|}
block|,
block|{
literal|"Canada #2"
block|,
literal|"ntp.cpsc.ucalgary.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.cpsc.ucalgary.ca"
block|}
block|,
block|{
literal|"Canada #3"
block|,
literal|"ntp1.cmc.ec.gc.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.cmc.ec.gc.ca"
block|}
block|,
block|{
literal|"Canada #4"
block|,
literal|"ntp2.cmc.ec.gc.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.cmc.ec.gc.ca"
block|}
block|,
block|{
literal|"Canada #5"
block|,
literal|"tick.utoronto.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tick.utoronto.ca"
block|}
block|,
block|{
literal|"Canada #6"
block|,
literal|"time.chu.nrc.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.chu.nrc.ca"
block|}
block|,
block|{
literal|"Canada #7"
block|,
literal|"time.nrc.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.nrc.ca"
block|}
block|,
block|{
literal|"Canada #8"
block|,
literal|"timelord.uregina.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=timelord.uregina.ca"
block|}
block|,
block|{
literal|"Canada #9"
block|,
literal|"tock.utoronto.ca"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tock.utoronto.ca"
block|}
block|,
block|{
literal|"Czech"
block|,
literal|"ntp.karpo.cz"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.karpo.cz"
block|}
block|,
block|{
literal|"Czech #2"
block|,
literal|"ntp.cgi.cz"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.cgi.cz"
block|}
block|,
block|{
literal|"Denmark"
block|,
literal|"clock.netcetera.dk"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock.netcetera.dk"
block|}
block|,
block|{
literal|"Denmark"
block|,
literal|"clock2.netcetera.dk"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock2.netcetera.dk"
block|}
block|,
block|{
literal|"Spain"
block|,
literal|"slug.ctv.es"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=slug.ctv.es"
block|}
block|,
block|{
literal|"Finland"
block|,
literal|"tick.keso.fi"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tick.keso.fi"
block|}
block|,
block|{
literal|"Finland #2"
block|,
literal|"tock.keso.fi"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tock.keso.fi"
block|}
block|,
block|{
literal|"France"
block|,
literal|"ntp.obspm.fr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.obspm.fr"
block|}
block|,
block|{
literal|"France #2"
block|,
literal|"ntp.univ-lyon1.fr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.univ-lyon1.fr"
block|}
block|,
block|{
literal|"France #3"
block|,
literal|"ntp.via.ecp.fr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.via.ecp.fr"
block|}
block|,
block|{
literal|"Croatia"
block|,
literal|"zg1.ntp.carnet.hr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=zg1.ntp.carnet.hr"
block|}
block|,
block|{
literal|"Croatia #2"
block|,
literal|"zg2.ntp.carnet.hr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=zg2.ntp.carnet.hr"
block|}
block|,
block|{
literal|"Croatia #3"
block|,
literal|"st.ntp.carnet.hr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=st.ntp.carnet.hr"
block|}
block|,
block|{
literal|"Croatia #4"
block|,
literal|"ri.ntp.carnet.hr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ri.ntp.carnet.hr"
block|}
block|,
block|{
literal|"Croatia #5"
block|,
literal|"os.ntp.carnet.hr"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=os.ntp.carnet.hr"
block|}
block|,
block|{
literal|"Hungary"
block|,
literal|"time.kfki.hu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.kfki.hu"
block|}
block|,
block|{
literal|"Indonesia"
block|,
literal|"ntp.kim.lipi.go.id"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.kim.lipi.go.id"
block|}
block|,
block|{
literal|"Ireland"
block|,
literal|"ntp.maths.tcd.ie"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.maths.tcd.ie"
block|}
block|,
block|{
literal|"Italy"
block|,
literal|"it.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=it.pool.ntp.org"
block|}
block|,
block|{
literal|"Japan"
block|,
literal|"ntp.jst.mfeed.ad.jp"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.jst.mfeed.ad.jp"
block|}
block|,
block|{
literal|"Japan IPv6"
block|,
literal|"ntp1.v6.mfeed.ad.jp"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.v6.mfeed.ad.jp"
block|}
block|,
block|{
literal|"Korea"
block|,
literal|"time.nuri.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.nuri.net"
block|}
block|,
block|{
literal|"Mexico"
block|,
literal|"mx.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=mx.pool.ntp.org"
block|}
block|,
block|{
literal|"Netherlands"
block|,
literal|"ntp0.nl.net"
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
literal|"Netherlands #2"
block|,
literal|"ntp1.nl.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.nl.net"
block|}
block|,
block|{
literal|"Netherlands #3"
block|,
literal|"ntp2.nl.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.nl.net"
block|}
block|,
block|{
literal|"Norway"
block|,
literal|"fartein.ifi.uio.no"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=fartein.ifi.uio.no"
block|}
block|,
block|{
literal|"Norway #2"
block|,
literal|"time.alcanet.no"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.alcanet.no"
block|}
block|,
block|{
literal|"New Zealand"
block|,
literal|"ntp.massey.ac.nz"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.massey.ac.nz"
block|}
block|,
block|{
literal|"New Zealand #2"
block|,
literal|"ntp.public.otago.ac.nz"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.public.otago.ac.nz"
block|}
block|,
block|{
literal|"New Zealand #3"
block|,
literal|"tk1.ihug.co.nz"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tk1.ihug.co.nz"
block|}
block|,
block|{
literal|"New Zealand #4"
block|,
literal|"ntp.waikato.ac.nz"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.waikato.ac.nz"
block|}
block|,
block|{
literal|"Poland"
block|,
literal|"info.cyf-kr.edu.pl"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=info.cyf-kr.edu.pl"
block|}
block|,
block|{
literal|"Romania"
block|,
literal|"ticks.roedu.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ticks.roedu.net"
block|}
block|,
block|{
literal|"Russia"
block|,
literal|"ru.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ru.pool.ntp.org"
block|}
block|,
block|{
literal|"Russia #2"
block|,
literal|"ntp.psn.ru"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.psn.ru"
block|}
block|,
block|{
literal|"Sweden"
block|,
literal|"se.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=se.pool.ntp.org"
block|}
block|,
block|{
literal|"Sweden #2"
block|,
literal|"ntp.lth.se"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.lth.se"
block|}
block|,
block|{
literal|"Sweden #3"
block|,
literal|"ntp1.sp.se"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.sp.se"
block|}
block|,
block|{
literal|"Sweden #4"
block|,
literal|"ntp2.sp.se"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.sp.se"
block|}
block|,
block|{
literal|"Sweden #5"
block|,
literal|"ntp.kth.se"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.kth.se"
block|}
block|,
block|{
literal|"Singapore"
block|,
literal|"sg.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=sg.pool.ntp.org"
block|}
block|,
block|{
literal|"Slovenia"
block|,
literal|"si.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=si.pool.ntp.org"
block|}
block|,
block|{
literal|"Slovenia #2"
block|,
literal|"sizif.mf.uni-lj.si"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=sizif.mf.uni-lj.si"
block|}
block|,
block|{
literal|"Slovenia #3"
block|,
literal|"ntp1.arnes.si"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.arnes.si"
block|}
block|,
block|{
literal|"Slovenia #4"
block|,
literal|"ntp2.arnes.si"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.arnes.si"
block|}
block|,
block|{
literal|"Slovenia #5"
block|,
literal|"time.ijs.si"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.ijs.si"
block|}
block|,
block|{
literal|"Scotland"
block|,
literal|"ntp.cs.strath.ac.uk"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.cs.strath.ac.uk"
block|}
block|,
block|{
literal|"Taiwan"
block|,
literal|"time.stdtime.gov.tw"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.stdtime.gov.tw"
block|}
block|,
block|{
literal|"Taiwan #2"
block|,
literal|"clock.stdtime.gov.tw"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock.stdtime.gov.tw"
block|}
block|,
block|{
literal|"Taiwan #3"
block|,
literal|"tick.stdtime.gov.tw"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tick.stdtime.gov.tw"
block|}
block|,
block|{
literal|"Taiwan #4"
block|,
literal|"tock.stdtime.gov.tw"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tock.stdtime.gov.tw"
block|}
block|,
block|{
literal|"Taiwan #5"
block|,
literal|"watch.stdtime.gov.tw"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=watch.stdtime.gov.tw"
block|}
block|,
block|{
literal|"United Kingdom"
block|,
literal|"uk.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=uk.pool.ntp.org"
block|}
block|,
block|{
literal|"United Kingdom #2"
block|,
literal|"ntp.exnet.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.exnet.com"
block|}
block|,
block|{
literal|"United Kingdom #3"
block|,
literal|"ntp0.uk.uu.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp0.uk.uu.net"
block|}
block|,
block|{
literal|"United Kingdom #4"
block|,
literal|"ntp1.uk.uu.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.uk.uu.net"
block|}
block|,
block|{
literal|"United Kingdom #5"
block|,
literal|"ntp2.uk.uu.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.uk.uu.net"
block|}
block|,
block|{
literal|"United Kingdom #6"
block|,
literal|"ntp2a.mcc.ac.uk"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2a.mcc.ac.uk"
block|}
block|,
block|{
literal|"United Kingdom #7"
block|,
literal|"ntp2b.mcc.ac.uk"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2b.mcc.ac.uk"
block|}
block|,
block|{
literal|"United Kingdom #8"
block|,
literal|"ntp2c.mcc.ac.uk"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2c.mcc.ac.uk"
block|}
block|,
block|{
literal|"United Kingdom #9"
block|,
literal|"ntp2d.mcc.ac.uk"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2d.mcc.ac.uk"
block|}
block|,
block|{
literal|"U.S."
block|,
literal|"us.pool.ntp.org"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=us.pool.ntp.org"
block|}
block|,
block|{
literal|"U.S. AR"
block|,
literal|"sushi.lyon.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=sushi.compsci.lyon.edu"
block|}
block|,
block|{
literal|"U.S. AZ"
block|,
literal|"ntp.drydog.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.drydog.com"
block|}
block|,
block|{
literal|"U.S. CA"
block|,
literal|"ntp.ucsd.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.ucsd.edu"
block|}
block|,
block|{
literal|"U.S. CA #2"
block|,
literal|"ntp1.mainecoon.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.mainecoon.com"
block|}
block|,
block|{
literal|"U.S. CA #3"
block|,
literal|"ntp2.mainecoon.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.mainecoon.com"
block|}
block|,
block|{
literal|"U.S. CA #4"
block|,
literal|"reloj.kjsl.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=reloj.kjsl.com"
block|}
block|,
block|{
literal|"U.S. CA #5"
block|,
literal|"time.five-ten-sg.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time.five-ten-sg.com"
block|}
block|,
block|{
literal|"U.S. DE"
block|,
literal|"louie.udel.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=louie.udel.edu"
block|}
block|,
block|{
literal|"U.S. GA"
block|,
literal|"ntp.shorty.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.shorty.com"
block|}
block|,
block|{
literal|"U.S. GA #2"
block|,
literal|"rolex.usg.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=rolex.usg.edu"
block|}
block|,
block|{
literal|"U.S. GA #3"
block|,
literal|"timex.usg.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=timex.usg.edu"
block|}
block|,
block|{
literal|"U.S. IL"
block|,
literal|"ntp-0.cso.uiuc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-0.cso.uiuc.edu"
block|}
block|,
block|{
literal|"U.S. IL #2"
block|,
literal|"ntp-1.cso.uiuc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-1.cso.uiuc.edu"
block|}
block|,
block|{
literal|"U.S. IL #3"
block|,
literal|"ntp-1.mcs.anl.gov"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-1.mcs.anl.gov"
block|}
block|,
block|{
literal|"U.S. IL #4"
block|,
literal|"ntp-2.cso.uiuc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-2.cso.uiuc.edu"
block|}
block|,
block|{
literal|"U.S. IL #5"
block|,
literal|"ntp-2.mcs.anl.gov"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-2.mcs.anl.gov"
block|}
block|,
block|{
literal|"U.S. IN"
block|,
literal|"gilbreth.ecn.purdue.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=gilbreth.ecn.purdue.edu"
block|}
block|,
block|{
literal|"U.S. IN #2"
block|,
literal|"harbor.ecn.purdue.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=harbor.ecn.purdue.edu"
block|}
block|,
block|{
literal|"U.S. IN #3"
block|,
literal|"molecule.ecn.purdue.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=molecule.ecn.purdue.edu"
block|}
block|,
block|{
literal|"U.S. KS"
block|,
literal|"ntp1.kansas.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.kansas.net"
block|}
block|,
block|{
literal|"U.S. KS #2"
block|,
literal|"ntp2.kansas.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.kansas.net"
block|}
block|,
block|{
literal|"U.S. MA"
block|,
literal|"ntp.ourconcord.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.ourconcord.net"
block|}
block|,
block|{
literal|"U.S. MA #2"
block|,
literal|"timeserver.cs.umb.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=timeserver.cs.umb.edu"
block|}
block|,
block|{
literal|"U.S. MN"
block|,
literal|"ns.nts.umn.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ns.nts.umn.edu"
block|}
block|,
block|{
literal|"U.S. MN #2"
block|,
literal|"nss.nts.umn.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=nss.nts.umn.edu"
block|}
block|,
block|{
literal|"U.S. MO"
block|,
literal|"time-ext.missouri.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=time-ext.missouri.edu"
block|}
block|,
block|{
literal|"U.S. MT"
block|,
literal|"chronos1.umt.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=chronos1.umt.edu"
block|}
block|,
block|{
literal|"U.S. MT #2"
block|,
literal|"chronos2.umt.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=chronos2.umt.edu"
block|}
block|,
block|{
literal|"U.S. MT #3"
block|,
literal|"chronos3.umt.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=chronos3.umt.edu"
block|}
block|,
block|{
literal|"U.S. NC"
block|,
literal|"clock1.unc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock1.unc.edu"
block|}
block|,
block|{
literal|"U.S. NV"
block|,
literal|"cuckoo.nevada.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=cuckoo.nevada.edu"
block|}
block|,
block|{
literal|"U.S. NV #2"
block|,
literal|"tick.cs.unlv.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tick.cs.unlv.edu"
block|}
block|,
block|{
literal|"U.S. NV #3"
block|,
literal|"tock.cs.unlv.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tock.cs.unlv.edu"
block|}
block|,
block|{
literal|"U.S. NY"
block|,
literal|"ntp0.cornell.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp0.cornell.edu"
block|}
block|,
block|{
literal|"U.S. NY #2"
block|,
literal|"sundial.columbia.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=sundial.columbia.edu"
block|}
block|,
block|{
literal|"U.S. NY #3"
block|,
literal|"timex.cs.columbia.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=timex.cs.columbia.edu"
block|}
block|,
block|{
literal|"U.S. PA"
block|,
literal|"clock-1.cs.cmu.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock-1.cs.cmu.edu"
block|}
block|,
block|{
literal|"U.S. PA #2"
block|,
literal|"clock-2.cs.cmu.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock-2.cs.cmu.edu"
block|}
block|,
block|{
literal|"U.S. PA #3"
block|,
literal|"clock.psu.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=clock.psu.edu"
block|}
block|,
block|{
literal|"U.S. PA #4"
block|,
literal|"fuzz.psc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=fuzz.psc.edu"
block|}
block|,
block|{
literal|"U.S. PA #5"
block|,
literal|"ntp-1.ece.cmu.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-1.ece.cmu.edu"
block|}
block|,
block|{
literal|"U.S. PA #6"
block|,
literal|"ntp-2.ece.cmu.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-2.ece.cmu.edu"
block|}
block|,
block|{
literal|"U.S. TX"
block|,
literal|"ntp.fnbhs.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.fnbhs.com"
block|}
block|,
block|{
literal|"U.S. TX #2"
block|,
literal|"ntp.tmc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.tmc.edu"
block|}
block|,
block|{
literal|"U.S. TX #3"
block|,
literal|"ntp5.tamu.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp5.tamu.edu"
block|}
block|,
block|{
literal|"U.S. TX #4"
block|,
literal|"tick.greyware.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tick.greyware.com"
block|}
block|,
block|{
literal|"U.S. TX #5"
block|,
literal|"tock.greyware.com"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=tock.greyware.com"
block|}
block|,
block|{
literal|"U.S. VA"
block|,
literal|"ntp-1.vt.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-1.vt.edu"
block|}
block|,
block|{
literal|"U.S. VA #2"
block|,
literal|"ntp-2.vt.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp-2.vt.edu"
block|}
block|,
block|{
literal|"U.S. VA #3"
block|,
literal|"ntp.cmr.gov"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.cmr.gov"
block|}
block|,
block|{
literal|"U.S. VT"
block|,
literal|"ntp0.state.vt.us"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp0.state.vt.us"
block|}
block|,
block|{
literal|"U.S. VT #2"
block|,
literal|"ntp1.state.vt.us"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.state.vt.us"
block|}
block|,
block|{
literal|"U.S. VT #3"
block|,
literal|"ntp2.state.vt.us"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp2.state.vt.us"
block|}
block|,
block|{
literal|"U.S. WA"
block|,
literal|"ntp.tcp-udp.net"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.tcp-udp.net"
block|}
block|,
block|{
literal|"U.S. WI"
block|,
literal|"ntp1.cs.wisc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp1.cs.wisc.edu"
block|}
block|,
block|{
literal|"U.S. WI #2"
block|,
literal|"ntp3.cs.wisc.edu"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp3.cs.wisc.edu"
block|}
block|,
block|{
literal|"South Africa"
block|,
literal|"ntp.cs.unp.ac.za"
block|,
name|dmenuVarsCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"ntpdate_enable=YES,ntpdate_flags=ntp.cs.unp.ac.za"
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
ifdef|#
directive|ifdef
name|WITH_SYSCONS
name|DMenu
name|MenuSyscons
operator|=
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
ifdef|#
directive|ifdef
name|PC98
block|{
literal|"2 Keymap"
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
literal|"3 Repeat"
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
literal|"4 Saver"
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
else|#
directive|else
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
literal|"7 Ttys"
block|,
literal|"Choose console terminal type"
block|,
name|NULL
block|,
name|dmenuSubmenu
block|,
name|NULL
block|,
operator|&
name|MenuSysconsTtys
block|}
block|,
endif|#
directive|endif
block|{
name|NULL
block|}
block|}
block|, }
block|;
ifdef|#
directive|ifdef
name|PC98
name|DMenu
name|MenuSysconsKeymap
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"System Console Keymap"
block|,
literal|"The default system console driver for FreeBSD (syscons) defaults\n"
literal|"to a standard \"PC-98x1\" keyboard map.  Users may wish to choose\n"
literal|"one of the other keymaps below.\n"
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
literal|"Japanese PC-98x1"
block|,
literal|"Japanese PC-98x1 keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=jp.pc98"
block|}
block|,
block|{
literal|" Japanese PC-98x1 (ISO)"
block|,
literal|"Japanese PC-98x1 (ISO) keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=jp.pc98.iso"
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
else|#
directive|else
name|DMenu
name|MenuSysconsKeymap
operator|=
block|{
name|DMENU_NORMAL_TYPE
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
literal|" Bulgarian BDS"
block|,
literal|"Bulgarian BDS keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=bg.bds.ctrlcaps"
block|}
block|,
block|{
literal|" Bulgarian Phonetic"
block|,
literal|"Bulgarian Phonetic keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=bg.phonetic.ctrlcaps"
block|}
block|,
block|{
literal|"Central European ISO"
block|,
literal|"Central European ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=ce.iso2"
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
literal|" Czech ISO (accent)"
block|,
literal|"Czech ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=cs.latin2.qwertz"
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
literal|" Greek 101"
block|,
literal|"Greek ISO keymap (101 keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=gr.us101.acc"
block|}
block|,
block|{
literal|" Greek 104"
block|,
literal|"Greek ISO keymap (104 keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=el.iso07"
block|}
block|,
block|{
literal|" Greek ELOT"
block|,
literal|"Greek ISO keymap (ELOT 1000)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=gr.elot.acc"
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
literal|"Latin American (accent)"
block|,
literal|"Latin American ISO keymap (accent keys)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=latinamerican.iso.acc"
block|}
block|,
block|{
literal|" Latin American"
block|,
literal|"Latin American ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=latinamerican"
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
literal|"keymap=pl_PL.ISO8859-2"
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
literal|"Russia KOI8-R"
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
literal|"Slovak"
block|,
literal|"Slovak ISO keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=sk.iso2"
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
literal|" Ukrainian KOI8-U"
block|,
literal|"Ukrainian KOI8-U keymap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=ua.koi8-u"
block|}
block|,
block|{
literal|" Ukrainian KOI8-U+KOI8-R"
block|,
literal|"Ukrainian KOI8-U+KOI8-R keymap (alter)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetKmapVariable
block|,
name|NULL
block|,
literal|"keymap=ua.koi8-u.shift.alt"
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
block|;
endif|#
directive|endif
comment|/* PC98 */
name|DMenu
name|MenuSysconsKeyrate
operator|=
block|{
name|DMENU_NORMAL_TYPE
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
block|;
name|DMenu
name|MenuSysconsSaver
operator|=
block|{
name|DMENU_NORMAL_TYPE
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
literal|"Dragon"
block|,
literal|"Dragon screensaver (graphics)"
block|,
name|dmenuVarCheck
block|,
name|configSaver
block|,
name|NULL
block|,
literal|"saver=dragon"
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
block|;
ifndef|#
directive|ifndef
name|PC98
name|DMenu
name|MenuSysconsScrnmap
operator|=
block|{
name|DMENU_NORMAL_TYPE
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
literal|"1 None"
block|,
literal|"No screenmap, don't touch font"
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
literal|"2 ISO 8859-1 to IBM437"
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
literal|"3 ISO 8859-7 to IBM437"
block|,
literal|"Greek ISO 8859-7 to IBM 437 screenmap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"scrnmap=iso-8859-7_to_cp437"
block|}
block|,
block|{
literal|"4 US-ASCII to IBM437"
block|,
literal|"US-ASCII to IBM 437 screenmap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"scrnmap=us-ascii_to_cp437"
block|}
block|,
block|{
literal|"5 KOI8-R to IBM866"
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
literal|"6 KOI8-U to IBM866u"
block|,
literal|"Ukrainian KOI8-U to IBM 866u screenmap"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
literal|"scrnmap=koi8-u2cp866u"
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuSysconsTtys
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"System Console Terminal Type"
block|,
literal|"For various console encodings, a corresponding terminal type\n"
literal|"must be chosen in /etc/ttys.\n\n"
literal|"WARNING: For compatibility reasons, only entries starting with\n"
literal|"ttyv and terminal types starting with cons[0-9] can be changed\n"
literal|"via this menu.\n"
block|,
literal|"Choose a terminal type"
block|,
name|NULL
block|,
block|{
block|{
literal|"1 None"
block|,
literal|"Don't touch anything"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=NO"
block|}
block|,
block|{
literal|"2 IBM437 (VGA default)"
block|,
literal|"cons25"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=cons25"
block|}
block|,
block|{
literal|"3 ISO 8859-1"
block|,
literal|"cons25l1"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=cons25l1"
block|}
block|,
block|{
literal|"4 ISO 8859-2"
block|,
literal|"cons25l2"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=cons25l2"
block|}
block|,
block|{
literal|"5 ISO 8859-7"
block|,
literal|"cons25l7"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=cons25l7"
block|}
block|,
block|{
literal|"6 KOI8-R"
block|,
literal|"cons25r"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=cons25r"
block|}
block|,
block|{
literal|"7 KOI8-U"
block|,
literal|"cons25u"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=cons25u"
block|}
block|,
block|{
literal|"8 US-ASCII"
block|,
literal|"cons25w"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariable
block|,
name|NULL
block|,
name|VAR_CONSTERM
literal|"=cons25w"
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuSysconsFont
operator|=
block|{
name|DMENU_NORMAL_TYPE
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
literal|"Use hardware default font"
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
literal|"English and others, VGA default"
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
literal|"Russian, IBM encoding (use with KOI8-R screenmap)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=cp866-8x8,font8x14=cp866-8x14,font8x16=cp866b-8x16,mousechar_start=3"
block|}
block|,
block|{
literal|"6 IBM 866u"
block|,
literal|"Ukrainian, IBM encoding (use with KOI8-U screenmap)"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=cp866u-8x8,font8x14=cp866u-8x14,font8x16=cp866u-8x16,mousechar_start=3"
block|}
block|,
block|{
literal|"7 IBM 1251"
block|,
literal|"Cyrillic, MS Windows encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=cp1251-8x8,font8x14=cp1251-8x14,font8x16=cp1251-8x16,mousechar_start=3"
block|}
block|,
block|{
literal|"8 ISO 8859-1"
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
literal|"9 ISO 8859-2"
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
literal|"a ISO 8859-4"
block|,
literal|"Baltic, ISO encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=iso04-8x8,font8x14=iso04-8x14,font8x16=iso04-8x16"
block|}
block|,
block|{
literal|"b ISO 8859-7"
block|,
literal|"Greek, ISO encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=iso07-8x8,font8x14=iso07-8x14,font8x16=iso07-8x16"
block|}
block|,
block|{
literal|"c ISO 8859-8"
block|,
literal|"Hebrew, ISO encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=iso08-8x8,font8x14=iso08-8x14,font8x16=iso08-8x16"
block|}
block|,
block|{
literal|"d ISO 8859-15"
block|,
literal|"Europe, ISO encoding"
block|,
name|dmenuVarCheck
block|,
name|dmenuSetVariables
block|,
name|NULL
block|,
literal|"font8x8=iso15-8x8,font8x14=iso15-8x14,font8x16=iso15-8x16"
block|}
block|,
block|{
literal|"e SWISS"
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
block|;
endif|#
directive|endif
comment|/* PC98 */
endif|#
directive|endif
comment|/* WITH_SYSCONS */
name|DMenu
name|MenuUsermgmt
operator|=
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
block|;
name|DMenu
name|MenuSecurity
operator|=
block|{
name|DMENU_CHECKLIST_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"System Security Options Menu"
block|,
literal|"This menu allows you to configure aspects of the operating system security\n"
literal|"policy.  Please read the system documentation carefully before modifying\n"
literal|"these settings, as they may cause service disruption if used improperly.\n"
literal|"\n"
literal|"Most settings will take affect only following a system reboot."
block|,
literal|"Configure system security options"
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
literal|" Securelevel"
block|,
literal|"Configure securelevels for the system"
block|,
name|NULL
block|,
name|configSecurelevel
block|}
block|,
if|#
directive|if
literal|0
block|{ " LOMAC",         "Use Low Watermark Mandatory Access Control at boot", 	dmenuVarCheck,  dmenuToggleVariable, NULL, "lomac_enable=YES" },
endif|#
directive|endif
block|{
literal|" NFS port"
block|,
literal|"Require that the NFS clients use reserved ports"
block|,
name|dmenuVarCheck
block|,
name|dmenuToggleVariable
block|,
name|NULL
block|,
literal|"nfs_reserved_port_only=YES"
block|}
block|,
block|{
name|NULL
block|}
block|}
block|, }
block|;
name|DMenu
name|MenuSecurelevel
operator|=
block|{
name|DMENU_NORMAL_TYPE
operator||
name|DMENU_SELECTION_RETURNS
block|,
literal|"Securelevel Configuration Menu"
block|,
literal|"This menu allows you to select the securelevel your system runs with.\n"
literal|"When operating at a securelevel, certain root privileges are disabled,\n"
literal|"which may increase resistance to exploits and protect system integrity.\n"
literal|"In secure mode system flags may not be overriden by the root user,\n"
literal|"access to direct kernel memory is limited, and kernel modules may not\n"
literal|"be changed.  In highly secure mode, mounted file systems may not be\n"
literal|"modified on-disk, tampering with the system clock is prohibited.  In\n"
literal|"network secure mode configuration changes to firwalling are prohibited.\n"
block|,
literal|"Select a securelevel to operate at - F1 for help"
block|,
literal|"securelevel"
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
literal|"Disabled"
block|,
literal|"Disable securelevels"
block|,
name|NULL
block|,
name|configSecurelevelDisabled
block|, }
block|,
block|{
literal|"Secure"
block|,
literal|"Secure mode"
block|,
name|NULL
block|,
name|configSecurelevelSecure
block|}
block|,
block|{
literal|"Highly Secure"
block|,
literal|"Highly secure mode"
block|,
name|NULL
block|,
name|configSecurelevelHighlySecure
block|}
block|,
block|{
literal|"Network Secure"
block|,
literal|"Network secure mode"
block|,
name|NULL
block|,
name|configSecurelevelNetworkSecure
block|}
block|,
block|{
name|NULL
block|}
block|}
block|}
block|;
name|DMenu
name|MenuFixit
operator|=
block|{
name|DMENU_NORMAL_TYPE
block|,
literal|"Please choose a fixit option"
block|,
literal|"There are three ways of going into \"fixit\" mode:\n"
literal|"- you can use the live filesystem CDROM/DVD, in which case there will be\n"
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
literal|"2 CDROM/DVD"
block|,
literal|"Use the \"live\" filesystem CDROM/DVD"
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
block|;
end_decl_stmt

end_unit

