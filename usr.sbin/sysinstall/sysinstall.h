begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last attempt in the `sysinstall' line, the next  * generation being slated to essentially a complete rewrite.  *  * $Id: sysinstall.h,v 1.38 1995/05/28 03:05:03 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYSINSTALL_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_SYSINSTALL_H_INCLUDE
end_define

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
file|<dialog.h>
end_include

begin_include
include|#
directive|include
file|"libdisk.h"
end_include

begin_include
include|#
directive|include
file|"dist.h"
end_include

begin_comment
comment|/*** Defines ***/
end_comment

begin_comment
comment|/* Bitfields for menu options */
end_comment

begin_define
define|#
directive|define
name|DMENU_NORMAL_TYPE
value|0x1
end_define

begin_comment
comment|/* Normal dialog menu		*/
end_comment

begin_define
define|#
directive|define
name|DMENU_RADIO_TYPE
value|0x2
end_define

begin_comment
comment|/* Radio dialog menu		*/
end_comment

begin_define
define|#
directive|define
name|DMENU_MULTIPLE_TYPE
value|0x4
end_define

begin_comment
comment|/* Multiple choice menu		*/
end_comment

begin_define
define|#
directive|define
name|DMENU_SELECTION_RETURNS
value|0x8
end_define

begin_comment
comment|/* Select item then exit	*/
end_comment

begin_define
define|#
directive|define
name|DMENU_CALL_FIRST
value|0x10
end_define

begin_comment
comment|/* In multiple, use one handler */
end_comment

begin_comment
comment|/* variable limits */
end_comment

begin_define
define|#
directive|define
name|VAR_NAME_MAX
value|128
end_define

begin_define
define|#
directive|define
name|VAR_VALUE_MAX
value|1024
end_define

begin_comment
comment|/* device limits */
end_comment

begin_define
define|#
directive|define
name|DEV_NAME_MAX
value|128
end_define

begin_comment
comment|/* The maximum length of a device name	*/
end_comment

begin_define
define|#
directive|define
name|DEV_MAX
value|200
end_define

begin_comment
comment|/* The maximum number of devices we'll deal with */
end_comment

begin_define
define|#
directive|define
name|INTERFACE_MAX
value|50
end_define

begin_comment
comment|/* Maximum number of network interfaces we'll deal with */
end_comment

begin_comment
comment|/*  * I make some pretty gross assumptions about having a max of 50 chunks  * total - 8 slices and 42 partitions.  I can't easily display many more  * than that on the screen at once!  *  * For 2.1 I'll revisit this and try to make it more dynamic, but since  * this will catch 99.99% of all possible cases, I'm not too worried.  */
end_comment

begin_define
define|#
directive|define
name|MAX_CHUNKS
value|50
end_define

begin_comment
comment|/* Internal flag variables */
end_comment

begin_define
define|#
directive|define
name|DISK_PARTITIONED
value|"_diskPartitioned"
end_define

begin_define
define|#
directive|define
name|DISK_LABELLED
value|"_diskLabelled"
end_define

begin_define
define|#
directive|define
name|RUNNING_ON_ROOT
value|"_runningOnRoot"
end_define

begin_define
define|#
directive|define
name|TCP_CONFIGURED
value|"_tcpConfigured"
end_define

begin_define
define|#
directive|define
name|NO_CONFIRMATION
value|"noConfirmation"
end_define

begin_define
define|#
directive|define
name|VAR_HOSTNAME
value|"hostname"
end_define

begin_define
define|#
directive|define
name|VAR_DOMAINNAME
value|"domainname"
end_define

begin_define
define|#
directive|define
name|VAR_NAMESERVER
value|"nameserver"
end_define

begin_define
define|#
directive|define
name|VAR_GATEWAY
value|"defaultrouter"
end_define

begin_define
define|#
directive|define
name|VAR_IPADDR
value|"ipaddr"
end_define

begin_define
define|#
directive|define
name|VAR_IFCONFIG
value|"ifconfig_"
end_define

begin_define
define|#
directive|define
name|VAR_INTERFACES
value|"network_interfaces"
end_define

begin_comment
comment|/* The help file for the TCP/IP setup screen */
end_comment

begin_define
define|#
directive|define
name|TCP_HELPFILE
value|"tcp.hlp"
end_define

begin_comment
comment|/*** Types ***/
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|disk
name|Disk
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|chunk
name|Chunk
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|DMENU_SHELL_ESCAPE
block|,
comment|/* Fork a shell			*/
name|DMENU_DISPLAY_FILE
block|,
comment|/* Display a file's contents	*/
name|DMENU_SUBMENU
block|,
comment|/* Recurse into another menu	*/
name|DMENU_SYSTEM_COMMAND
block|,
comment|/* Run shell commmand		*/
name|DMENU_SYSTEM_COMMAND_BOX
block|,
comment|/* Same as above, but in prgbox	*/
name|DMENU_SET_VARIABLE
block|,
comment|/* Set an environment/system var */
name|DMENU_SET_FLAG
block|,
comment|/* Set flag in an unsigned int	*/
name|DMENU_CALL
block|,
comment|/* Call back a C function	*/
name|DMENU_CANCEL
block|,
comment|/* Cancel out of this menu	*/
name|DMENU_NOP
block|,
comment|/* Do nothing special for item	*/
block|}
name|DMenuItemType
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dmenuItem
block|{
name|char
modifier|*
name|title
decl_stmt|;
comment|/* Our title			*/
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* Our prompt			*/
name|DMenuItemType
name|type
decl_stmt|;
comment|/* What type of item we are	*/
name|void
modifier|*
name|ptr
decl_stmt|;
comment|/* Generic data ptr		*/
name|u_long
name|parm
decl_stmt|;
comment|/* Parameter for above		*/
name|Boolean
name|disabled
decl_stmt|;
comment|/* Are we temporarily disabled?	*/
block|}
name|DMenuItem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dmenu
block|{
name|unsigned
name|int
name|options
decl_stmt|;
comment|/* What sort of menu we are	*/
name|char
modifier|*
name|title
decl_stmt|;
comment|/* Our title			*/
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* Our prompt			*/
name|char
modifier|*
name|helpline
decl_stmt|;
comment|/* Line of help at bottom	*/
name|char
modifier|*
name|helpfile
decl_stmt|;
comment|/* Help file for "F1"		*/
name|DMenuItem
name|items
index|[
literal|0
index|]
decl_stmt|;
comment|/* Array of menu items		*/
block|}
name|DMenu
typedef|;
end_typedef

begin_comment
comment|/* A sysconfig variable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_variable
block|{
name|struct
name|_variable
modifier|*
name|next
decl_stmt|;
name|char
name|name
index|[
name|VAR_NAME_MAX
index|]
decl_stmt|;
name|char
name|value
index|[
name|VAR_VALUE_MAX
index|]
decl_stmt|;
block|}
name|Variable
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_ATTRIBS
value|200
end_define

begin_define
define|#
directive|define
name|MAX_NAME
value|511
end_define

begin_define
define|#
directive|define
name|MAX_VALUE
value|4095
end_define

begin_typedef
typedef|typedef
struct|struct
name|_attribs
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|Attribs
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVICE_TYPE_NONE
block|,
name|DEVICE_TYPE_DISK
block|,
name|DEVICE_TYPE_FLOPPY
block|,
name|DEVICE_TYPE_FTP
block|,
name|DEVICE_TYPE_NETWORK
block|,
name|DEVICE_TYPE_CDROM
block|,
name|DEVICE_TYPE_TAPE
block|,
name|DEVICE_TYPE_DOS
block|,
name|DEVICE_TYPE_ANY
block|, }
name|DeviceType
typedef|;
end_typedef

begin_comment
comment|/* A "device" from sysinstall's point of view */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_device
block|{
name|char
name|name
index|[
name|DEV_NAME_MAX
index|]
decl_stmt|;
name|char
modifier|*
name|description
decl_stmt|;
name|char
modifier|*
name|devname
decl_stmt|;
name|DeviceType
name|type
decl_stmt|;
name|Boolean
name|enabled
decl_stmt|;
name|Boolean
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|_device
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
name|Boolean
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|struct
name|_device
modifier|*
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|shutdown
function_decl|)
parameter_list|(
name|struct
name|_device
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|private
decl_stmt|;
block|}
name|Device
typedef|;
end_typedef

begin_comment
comment|/* Some internal representations of partitions */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PART_NONE
block|,
name|PART_SLICE
block|,
name|PART_SWAP
block|,
name|PART_FILESYSTEM
block|,
name|PART_FAT
block|, }
name|PartType
typedef|;
end_typedef

begin_comment
comment|/* The longest newfs command we'll hand to system() */
end_comment

begin_define
define|#
directive|define
name|NEWFS_CMD_MAX
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|_part_info
block|{
name|Boolean
name|newfs
decl_stmt|;
name|char
name|mountpoint
index|[
name|FILENAME_MAX
index|]
decl_stmt|;
name|char
name|newfs_cmd
index|[
name|NEWFS_CMD_MAX
index|]
decl_stmt|;
block|}
name|PartInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|commandFunc
function_decl|)
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|HOSTNAME_FIELD_LEN
value|256
end_define

begin_define
define|#
directive|define
name|IPADDR_FIELD_LEN
value|16
end_define

begin_define
define|#
directive|define
name|EXTRAS_FIELD_LEN
value|256
end_define

begin_comment
comment|/* This is the structure that Network devices carry around in their private, erm, structures */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_devPriv
block|{
name|char
name|ipaddr
index|[
name|IPADDR_FIELD_LEN
index|]
decl_stmt|;
name|char
name|netmask
index|[
name|IPADDR_FIELD_LEN
index|]
decl_stmt|;
name|char
name|extras
index|[
name|EXTRAS_FIELD_LEN
index|]
decl_stmt|;
block|}
name|DevInfo
typedef|;
end_typedef

begin_comment
comment|/*** Externs ***/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|DebugFD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where diagnostic output goes			*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnCDROM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we running off of a CDROM?		*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnSerial
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a serial console?			*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|SystemWasInstalled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Did we install it?				*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|RunningAsInit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we running stand-alone?			*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|DialogActive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is the dialog() stuff up?			*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|ColorDisplay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a color display?			*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnVTY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* On a syscons VTY?				*/
end_comment

begin_decl_stmt
specifier|extern
name|Variable
modifier|*
name|VarHead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The head of the variable chain		*/
end_comment

begin_decl_stmt
specifier|extern
name|Device
modifier|*
name|mediaDevice
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where we're getting our distribution from	*/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|Dists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which distributions we want			*/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|SrcDists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which src distributions we want		*/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|XF86Dists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which XFree86 dists we want			*/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|XF86ServerDists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The XFree86 servers we want			*/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|XF86FontDists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The XFree86 fonts we want			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuInitial
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initial installation menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMBRType
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of MBR to write on the disk		*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuConfigure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Final configuration menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDocumentation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Documentation menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuOptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Installation options				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuOptionsLanguage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Language options menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuOptionsFTP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FTP options menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMedia
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Media type menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMediaCDROM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CDROM media menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMediaDOS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DOS media menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMediaFloppy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Floppy media menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMediaFTP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FTP media menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMediaTape
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tape media menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuNetworkDevice
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Network device menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuNTP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NTP time server menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuSyscons
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System console configuration menu		*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuSysconsKeymap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System console keymap configuration menu	*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuSysconsKeyrate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System console keyrate configuration menu	*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuSysconsSaver
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System console saver configuration menu	*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuNetworking
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Network configuration menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuInstall
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Installation menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuInstallType
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Installation type menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDistributions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Distribution menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuSrcDistributions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Source distribution menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuXF86
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XFree86 main menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuXF86Select
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XFree86 distribution selection menu		*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuXF86SelectCore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XFree86 core distribution menu		*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuXF86SelectServer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XFree86 server distribution menu		*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuXF86SelectFonts
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XFree86 font selection menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDiskDevices
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Disk devices menu				*/
end_comment

begin_comment
comment|/*** Prototypes ***/
end_comment

begin_comment
comment|/* attrs.c */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|attr_match
parameter_list|(
name|Attribs
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|attr_parse
parameter_list|(
name|Attribs
modifier|*
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cdrom.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitCDROM
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaGetCDROM
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaShutdownCDROM
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* command.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|command_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|command_sort
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|command_execute
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|command_shell_add
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|command_func_add
parameter_list|(
name|char
modifier|*
name|key
parameter_list|,
name|commandFunc
name|func
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* config.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|configFstab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|configSysconfig
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|configResolv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configPorts
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configPackages
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configSaverTimeout
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* decode.c */
end_comment

begin_function_decl
specifier|extern
name|DMenuItem
modifier|*
name|decode
parameter_list|(
name|DMenu
modifier|*
name|menu
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|dispatch
parameter_list|(
name|DMenuItem
modifier|*
name|tmp
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|decode_and_dispatch_multiple
parameter_list|(
name|DMenu
modifier|*
name|menu
parameter_list|,
name|char
modifier|*
name|names
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* devices.c */
end_comment

begin_function_decl
specifier|extern
name|DMenu
modifier|*
name|deviceCreateMenu
parameter_list|(
name|DMenu
modifier|*
name|menu
parameter_list|,
name|DeviceType
name|type
parameter_list|,
name|int
function_decl|(
modifier|*
name|hook
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deviceGetAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Device
modifier|*
modifier|*
name|deviceFind
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|DeviceType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|deviceCount
parameter_list|(
name|Device
modifier|*
modifier|*
name|devs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Device
modifier|*
name|new_device
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Device
modifier|*
name|deviceRegister
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|desc
parameter_list|,
name|char
modifier|*
name|devname
parameter_list|,
name|DeviceType
name|type
parameter_list|,
name|Boolean
name|enabled
parameter_list|,
name|Boolean
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|Device
modifier|*
name|mediadev
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
parameter_list|,
name|Boolean
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
name|Device
modifier|*
name|mediadev
parameter_list|,
name|int
name|fd
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|shutDown
function_decl|)
parameter_list|(
name|Device
modifier|*
name|mediadev
parameter_list|)
parameter_list|,
name|void
modifier|*
name|private
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* disks.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|diskPartitionEditor
parameter_list|(
name|char
modifier|*
name|unused
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dist.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|distReset
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetDeveloper
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetXDeveloper
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetUser
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetXUser
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetMinimum
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetEverything
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetSrc
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|distExtractAll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dmenu.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|dmenuOpen
parameter_list|(
name|DMenu
modifier|*
name|menu
parameter_list|,
name|int
modifier|*
name|choice
parameter_list|,
name|int
modifier|*
name|scroll
parameter_list|,
name|int
modifier|*
name|curr
parameter_list|,
name|int
modifier|*
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dmenuOpenSimple
parameter_list|(
name|DMenu
modifier|*
name|menu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dos.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitDOS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaGetDOS
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaShutdownDOS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* floppy.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|getRootFloppy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitFloppy
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaGetFloppy
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaShutdownFloppy
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ftp_strat.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaCloseFTP
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitFTP
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaGetFTP
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaShutdownFTP
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* globals.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|globalsInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* install.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|installCommit
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lang.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|lang_set_Danish
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_Dutch
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_English
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_French
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_German
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_Italian
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_Japanese
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_Norwegian
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_Russian
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_Spanish
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lang_set_Swedish
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* label.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|diskLabelEditor
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* makedevs.c (auto-generated) */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|termcap_vt100
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|termcap_cons25
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|termcap_cons25_m
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|termcap_cons25r
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|termcap_cons25r_m
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|termcap_cons25l1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|termcap_cons25l1_m
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
name|font_iso_8x16
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
name|font_cp850_8x16
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
name|font_cp866_8x16
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
name|koi8_r2cp866
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|default_scrnmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* media.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mediaSetCDROM
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFloppy
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetDOS
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetTape
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFTP
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFS
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|mediaGetType
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|mediaExtractDist
parameter_list|(
name|char
modifier|*
name|distname
parameter_list|,
name|char
modifier|*
name|dir
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|mediaExtractDistBegin
parameter_list|(
name|char
modifier|*
name|distname
parameter_list|,
name|char
modifier|*
name|dir
parameter_list|,
name|int
modifier|*
name|fd
parameter_list|,
name|int
modifier|*
name|zpid
parameter_list|,
name|int
modifier|*
name|cpic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|mediaExtractDistEnd
parameter_list|(
name|int
name|zpid
parameter_list|,
name|int
name|cpid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|mediaVerify
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* misc.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|file_readable
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|file_executable
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|string_concat
parameter_list|(
name|char
modifier|*
name|p1
parameter_list|,
name|char
modifier|*
name|p2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|string_prune
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|string_skipwhite
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|safe_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|safe_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|safe_realloc
parameter_list|(
name|void
modifier|*
name|orig
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|item_add
parameter_list|(
name|char
modifier|*
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|item
parameter_list|,
name|int
modifier|*
name|curr
parameter_list|,
name|int
modifier|*
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|item_add_pair
parameter_list|(
name|char
modifier|*
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|item1
parameter_list|,
name|char
modifier|*
name|item2
parameter_list|,
name|int
modifier|*
name|curr
parameter_list|,
name|int
modifier|*
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|items_free
parameter_list|(
name|char
modifier|*
modifier|*
name|list
parameter_list|,
name|int
modifier|*
name|curr
parameter_list|,
name|int
modifier|*
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Mkdir
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Mount
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Mount_DOS
parameter_list|(
name|char
modifier|*
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* msg.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|msgInfo
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgYap
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgWarn
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgDebug
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgError
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgFatal
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgConfirm
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgNotify
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|msgWeHaveOutput
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|msgYesNo
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|msgGetInput
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* network.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitNetwork
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaShutdownNetwork
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configRoutedFlags
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* system.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|systemInitialize
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|systemShutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|systemWelcome
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|systemExecute
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|systemShellEscape
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|systemDisplayFile
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|systemHelpFile
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|systemChangeFont
parameter_list|(
specifier|const
name|u_char
name|font
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|systemChangeLang
parameter_list|(
name|char
modifier|*
name|lang
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|systemChangeTerminal
parameter_list|(
name|char
modifier|*
name|color
parameter_list|,
specifier|const
name|u_char
name|c_termcap
index|[]
parameter_list|,
name|char
modifier|*
name|mono
parameter_list|,
specifier|const
name|u_char
name|m_termcap
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|systemChangeScreenmap
parameter_list|(
specifier|const
name|u_char
name|newmap
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vsystem
parameter_list|(
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tape.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitTape
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaGetTape
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaShutdownTape
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tcpip.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|tcpOpenDialog
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcpDeviceSelect
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* termcap.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|set_termcap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ufs.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitUFS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaGetUFS
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* variables.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|variable_set
parameter_list|(
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|variable_set2
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* wizard.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|slice_wizard
parameter_list|(
name|Disk
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYSINSTALL_H_INCLUDE */
end_comment

end_unit

