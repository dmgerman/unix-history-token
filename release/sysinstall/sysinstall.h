begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last attempt in the `sysinstall' line, the next  * generation being slated to essentially a complete rewrite.  *  * $Id: sysinstall.h,v 1.141 1997/09/17 16:18:21 pst Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

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
file|"ui_objects.h"
end_include

begin_include
include|#
directive|include
file|"dir.h"
end_include

begin_include
include|#
directive|include
file|"colors.h"
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

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_comment
comment|/*** Defines ***/
end_comment

begin_comment
comment|/* Different packages we depend on - update this when package version change! */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_GATED
value|"gated-3.5b3"
end_define

begin_define
define|#
directive|define
name|PACKAGE_NETCON
value|"commerce/netcon/bsd61"
end_define

begin_define
define|#
directive|define
name|PACKAGE_PCNFSD
value|"pcnfsd-93.02.16"
end_define

begin_define
define|#
directive|define
name|PACKAGE_LYNX
value|"lynx-2.7.1"
end_define

begin_comment
comment|/* device limits */
end_comment

begin_define
define|#
directive|define
name|DEV_NAME_MAX
value|64
end_define

begin_comment
comment|/* The maximum length of a device name	*/
end_comment

begin_define
define|#
directive|define
name|DEV_MAX
value|100
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

begin_define
define|#
directive|define
name|IO_ERROR
value|-2
end_define

begin_comment
comment|/* Status code for I/O error rather than normal EOF */
end_comment

begin_comment
comment|/* Number of seconds to wait for data to come off even the slowest media */
end_comment

begin_define
define|#
directive|define
name|MEDIA_TIMEOUT
value|300
end_define

begin_comment
comment|/*  * I make some pretty gross assumptions about having a max of 50 chunks  * total - 8 slices and 42 partitions.  I can't easily display many more  * than that on the screen at once!  *  * For 2.1 I'll revisit this and try to make it more dynamic, but since  * this will catch 99.99% of all possible cases, I'm not too worried.  */
end_comment

begin_define
define|#
directive|define
name|MAX_CHUNKS
value|40
end_define

begin_comment
comment|/* Internal environment variable names */
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
name|DISK_SELECTED
value|"_diskSelected"
end_define

begin_define
define|#
directive|define
name|SYSTEM_STATE
value|"_systemState"
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

begin_comment
comment|/* Ones that can be tweaked from config files */
end_comment

begin_define
define|#
directive|define
name|VAR_BLANKTIME
value|"blanktime"
end_define

begin_define
define|#
directive|define
name|VAR_BOOTMGR
value|"bootManager"
end_define

begin_define
define|#
directive|define
name|VAR_BROWSER_BINARY
value|"browserBinary"
end_define

begin_define
define|#
directive|define
name|VAR_BROWSER_PACKAGE
value|"browserPackage"
end_define

begin_define
define|#
directive|define
name|VAR_CPIO_VERBOSITY
value|"cpioVerbose"
end_define

begin_define
define|#
directive|define
name|VAR_DEBUG
value|"debug"
end_define

begin_define
define|#
directive|define
name|VAR_DISK
value|"disk"
end_define

begin_define
define|#
directive|define
name|VAR_DISTS
value|"dists"
end_define

begin_define
define|#
directive|define
name|VAR_DIST_MAIN
value|"distMain"
end_define

begin_define
define|#
directive|define
name|VAR_DIST_DES
value|"distDES"
end_define

begin_define
define|#
directive|define
name|VAR_DIST_SRC
value|"distSRC"
end_define

begin_define
define|#
directive|define
name|VAR_DIST_X11
value|"distX11"
end_define

begin_define
define|#
directive|define
name|VAR_DIST_XSERVER
value|"distXserver"
end_define

begin_define
define|#
directive|define
name|VAR_DIST_XFONTS
value|"distXfonts"
end_define

begin_define
define|#
directive|define
name|VAR_DEDICATE_DISK
value|"dedicateDisk"
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
name|VAR_EDITOR
value|"editor"
end_define

begin_define
define|#
directive|define
name|VAR_EXTRAS
value|"ifconfig_"
end_define

begin_define
define|#
directive|define
name|VAR_COMMAND
value|"command"
end_define

begin_define
define|#
directive|define
name|VAR_CONFIG_FILE
value|"configFile"
end_define

begin_define
define|#
directive|define
name|VAR_FTP_DIR
value|"ftpDirectory"
end_define

begin_define
define|#
directive|define
name|VAR_FTP_PASS
value|"ftpPass"
end_define

begin_define
define|#
directive|define
name|VAR_FTP_PATH
value|"ftp"
end_define

begin_define
define|#
directive|define
name|VAR_FTP_PORT
value|"ftpPort"
end_define

begin_define
define|#
directive|define
name|VAR_FTP_STATE
value|"ftpState"
end_define

begin_define
define|#
directive|define
name|VAR_FTP_USER
value|"ftpUser"
end_define

begin_define
define|#
directive|define
name|VAR_FTP_HOST
value|"ftpHost"
end_define

begin_define
define|#
directive|define
name|VAR_GATED_PKG
value|"gated_pkg"
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
name|VAR_GEOMETRY
value|"geometry"
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
name|VAR_IFCONFIG
value|"ifconfig_"
end_define

begin_define
define|#
directive|define
name|VAR_INTERFACES
value|"network_interfaces"
end_define

begin_define
define|#
directive|define
name|VAR_INSTALL_CFG
value|"installConfig"
end_define

begin_define
define|#
directive|define
name|VAR_INSTALL_ROOT
value|"installRoot"
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
name|VAR_KEYMAP
value|"keymap"
end_define

begin_define
define|#
directive|define
name|VAR_LABEL
value|"label"
end_define

begin_define
define|#
directive|define
name|VAR_LABEL_COUNT
value|"labelCount"
end_define

begin_define
define|#
directive|define
name|VAR_MEDIA_TYPE
value|"mediaType"
end_define

begin_define
define|#
directive|define
name|VAR_MEDIA_TIMEOUT
value|"MEDIA_TIMEOUT"
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
name|VAR_NETINTERACTIVE
value|"netInteractive"
end_define

begin_define
define|#
directive|define
name|VAR_NETMASK
value|"netmask"
end_define

begin_define
define|#
directive|define
name|VAR_NETWORK_DEVICE
value|"netDev"
end_define

begin_define
define|#
directive|define
name|VAR_NFS_PATH
value|"nfs"
end_define

begin_define
define|#
directive|define
name|VAR_NFS_HOST
value|"nfsHost"
end_define

begin_define
define|#
directive|define
name|VAR_NFS_SECURE
value|"nfsSecure"
end_define

begin_define
define|#
directive|define
name|VAR_NFS_SERVER
value|"nfs_server_enable"
end_define

begin_define
define|#
directive|define
name|VAR_NO_CONFIRM
value|"noConfirm"
end_define

begin_define
define|#
directive|define
name|VAR_NO_ERROR
value|"noError"
end_define

begin_define
define|#
directive|define
name|VAR_NO_WARN
value|"noWarn"
end_define

begin_define
define|#
directive|define
name|VAR_NONINTERACTIVE
value|"nonInteractive"
end_define

begin_define
define|#
directive|define
name|VAR_NOVELL
value|"novell"
end_define

begin_define
define|#
directive|define
name|VAR_NTPDATE_FLAGS
value|"ntpdate_flags"
end_define

begin_define
define|#
directive|define
name|VAR_PACKAGE
value|"package"
end_define

begin_define
define|#
directive|define
name|VAR_PARTITION
value|"partition"
end_define

begin_define
define|#
directive|define
name|VAR_PCNFSD
value|"pcnfsd"
end_define

begin_define
define|#
directive|define
name|VAR_PCNFSD_PKG
value|"pcnfsd_pkg"
end_define

begin_define
define|#
directive|define
name|VAR_PKG_TMPDIR
value|"PKG_TMPDIR"
end_define

begin_define
define|#
directive|define
name|VAR_PORTS_PATH
value|"ports"
end_define

begin_define
define|#
directive|define
name|VAR_RELNAME
value|"releaseName"
end_define

begin_define
define|#
directive|define
name|VAR_ROOT_SIZE
value|"rootSize"
end_define

begin_define
define|#
directive|define
name|VAR_ROUTER
value|"router"
end_define

begin_define
define|#
directive|define
name|VAR_ROUTER_ENABLE
value|"router_enable"
end_define

begin_define
define|#
directive|define
name|VAR_ROUTERFLAGS
value|"routerflags"
end_define

begin_define
define|#
directive|define
name|VAR_SERIAL_SPEED
value|"serialSpeed"
end_define

begin_define
define|#
directive|define
name|VAR_SLOW_ETHER
value|"slowEthernetCard"
end_define

begin_define
define|#
directive|define
name|VAR_SWAP_SIZE
value|"swapSize"
end_define

begin_define
define|#
directive|define
name|VAR_TAPE_BLOCKSIZE
value|"tapeBlocksize"
end_define

begin_define
define|#
directive|define
name|VAR_UFS_PATH
value|"ufs"
end_define

begin_define
define|#
directive|define
name|VAR_USR_SIZE
value|"usrSize"
end_define

begin_define
define|#
directive|define
name|VAR_VAR_SIZE
value|"varSize"
end_define

begin_define
define|#
directive|define
name|VAR_XF86_CONFIG
value|"xf86config"
end_define

begin_define
define|#
directive|define
name|DEFAULT_TAPE_BLOCKSIZE
value|"20"
end_define

begin_comment
comment|/* One MB worth of blocks */
end_comment

begin_define
define|#
directive|define
name|ONE_MEG
value|2048
end_define

begin_comment
comment|/* Which selection attributes to use */
end_comment

begin_define
define|#
directive|define
name|ATTR_SELECTED
value|(ColorDisplay ? item_selected_attr : item_attr)
end_define

begin_define
define|#
directive|define
name|ATTR_TITLE
value|button_active_attr
end_define

begin_comment
comment|/* Handy strncpy() macro */
end_comment

begin_define
define|#
directive|define
name|SAFE_STRCPY
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|)
value|sstrncpy((to), (from), sizeof (to) - 1)
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
comment|/* Normal dialog menu           */
end_comment

begin_define
define|#
directive|define
name|DMENU_RADIO_TYPE
value|0x2
end_define

begin_comment
comment|/* Radio dialog menu            */
end_comment

begin_define
define|#
directive|define
name|DMENU_CHECKLIST_TYPE
value|0x4
end_define

begin_comment
comment|/* Multiple choice menu         */
end_comment

begin_define
define|#
directive|define
name|DMENU_SELECTION_RETURNS
value|0x8
end_define

begin_comment
comment|/* Immediate return on item selection */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_dmenu
block|{
name|int
name|type
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
name|dialogMenuItem
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
comment|/* An rc.conf variable */
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
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
name|Variable
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NO_ECHO_OBJ
parameter_list|(
name|type
parameter_list|)
value|((type) | (DITEM_NO_ECHO<< 16))
end_define

begin_define
define|#
directive|define
name|TYPE_OF_OBJ
parameter_list|(
name|type
parameter_list|)
value|((type)& 0xff)
end_define

begin_define
define|#
directive|define
name|ATTR_OF_OBJ
parameter_list|(
name|type
parameter_list|)
value|((type)>> 16)
end_define

begin_comment
comment|/* A screen layout structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_layout
block|{
name|int
name|y
decl_stmt|;
comment|/* x& Y co-ordinates */
name|int
name|x
decl_stmt|;
name|int
name|len
decl_stmt|;
comment|/* The size of the dialog on the screen */
name|int
name|maxlen
decl_stmt|;
comment|/* How much the user can type in ... */
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* The string for the prompt */
name|char
modifier|*
name|help
decl_stmt|;
comment|/* The display for the help line */
name|void
modifier|*
name|var
decl_stmt|;
comment|/* The var to set when this changes */
name|int
name|type
decl_stmt|;
comment|/* The type of the dialog to create */
name|void
modifier|*
name|obj
decl_stmt|;
comment|/* The obj pointer returned by libdialog */
block|}
name|Layout
typedef|;
end_typedef

begin_comment
comment|/* For attribs */
end_comment

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
value|64
end_define

begin_define
define|#
directive|define
name|MAX_VALUE
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|_attribs
block|{
name|char
name|name
index|[
name|MAX_NAME
index|]
decl_stmt|;
name|char
name|value
index|[
name|MAX_VALUE
index|]
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
name|DEVICE_TYPE_UFS
block|,
name|DEVICE_TYPE_NFS
block|,
name|DEVICE_TYPE_ANY
block|, }
name|DeviceType
typedef|;
end_typedef

begin_comment
comment|/* CDROM mount codes */
end_comment

begin_define
define|#
directive|define
name|CD_UNMOUNTED
value|0
end_define

begin_define
define|#
directive|define
name|CD_ALREADY_MOUNTED
value|1
end_define

begin_define
define|#
directive|define
name|CD_WE_MOUNTED_IT
value|2
end_define

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
name|dev
parameter_list|)
function_decl|;
name|FILE
modifier|*
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|struct
name|_device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
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
name|dev
parameter_list|)
function_decl|;
name|void
modifier|*
name|private
decl_stmt|;
name|unsigned
name|int
name|flags
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

begin_comment
comment|/* An option */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_opt
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
enum|enum
block|{
name|OPT_IS_STRING
block|,
name|OPT_IS_INT
block|,
name|OPT_IS_FUNC
block|,
name|OPT_IS_VAR
block|}
name|type
enum|;
name|void
modifier|*
name|data
decl_stmt|;
name|void
modifier|*
name|aux
decl_stmt|;
name|char
modifier|*
function_decl|(
modifier|*
name|check
function_decl|)
parameter_list|()
function_decl|;
block|}
name|Option
typedef|;
end_typedef

begin_comment
comment|/* Weird index nodey things we use for keeping track of package information */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PACKAGE
block|,
name|PLACE
block|}
name|node_type
typedef|;
end_typedef

begin_comment
comment|/* Types of nodes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_pkgnode
block|{
comment|/* A node in the reconstructed hierarchy */
name|struct
name|_pkgnode
modifier|*
name|next
decl_stmt|;
comment|/* My next sibling			*/
name|node_type
name|type
decl_stmt|;
comment|/* What am I?				*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* My name				*/
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* My description (Hook)		*/
name|struct
name|_pkgnode
modifier|*
name|kids
decl_stmt|;
comment|/* My little children			*/
name|void
modifier|*
name|data
decl_stmt|;
comment|/* A place to hang my data		*/
block|}
name|PkgNode
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PkgNode
modifier|*
name|PkgNodePtr
typedef|;
end_typedef

begin_comment
comment|/* A single package */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_indexEntry
block|{
comment|/* A single entry in an INDEX file */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name				*/
name|char
modifier|*
name|path
decl_stmt|;
comment|/* full path to port		*/
name|char
modifier|*
name|prefix
decl_stmt|;
comment|/* port prefix			*/
name|char
modifier|*
name|comment
decl_stmt|;
comment|/* one line description		*/
name|char
modifier|*
name|descrfile
decl_stmt|;
comment|/* path to description file	*/
name|char
modifier|*
name|deps
decl_stmt|;
comment|/* packages this depends on	*/
name|char
modifier|*
name|maintainer
decl_stmt|;
comment|/* maintainer			*/
block|}
name|IndexEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IndexEntry
modifier|*
name|IndexEntryPtr
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
value|128
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
value|128
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
name|jmp_buf
name|BailOut
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used to get the heck out */
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
name|Fake
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't actually modify anything - testing	*/
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
name|DESDists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which naughty distributions we want		*/
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
name|int
name|BootMgr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which boot manager to use 			*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|StatusLine
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where to print our status messages		*/
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
name|MenuFixit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fixit repair menu				*/
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
name|MenuFTPOptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FTP Installation options			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index menu					*/
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
name|MenuMedia
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Media type menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMouse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mouse type menu				*/
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
name|MenuSysconsFont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System console font configuration menu	*/
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
name|MenuSysconsScrnmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System console screenmap configuration menu	*/
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
name|MenuInstallCustom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Custom Installation menu			*/
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
name|MenuSubDistributions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Custom distribution menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDESDistributions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DES distribution menu			*/
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
name|MenuXF86SelectPC98Server
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

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuHTMLDoc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* HTML Documentation menu			*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuUsermgmt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* User management menu				*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuFixit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fixit floppy/CDROM/shell menu		*/
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuXF86Config
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Select XFree86 configuration type		*/
end_comment

begin_comment
comment|/* Stuff from libdialog which isn't properly declared outside */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_helpfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|display_helpline
parameter_list|(
name|WINDOW
modifier|*
name|w
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*** Prototypes ***/
end_comment

begin_comment
comment|/* anonFTP.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|configAnonFTP
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* attrs.c */
end_comment

begin_function_decl
specifier|extern
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
name|attr_parse_file
parameter_list|(
name|Attribs
modifier|*
name|attr
parameter_list|,
name|char
modifier|*
name|file
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
name|attr
parameter_list|,
name|FILE
modifier|*
name|fp
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
name|FILE
modifier|*
name|mediaGetCDROM
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
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
name|int
name|configFstab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|configEnvironmentRC_conf
parameter_list|(
name|char
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|configEnvironmentResolv
parameter_list|(
name|char
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|configRC_conf
parameter_list|(
name|char
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configRC
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configRegister
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
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
name|configPackages
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configSaver
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configSaverTimeout
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configNTP
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configUsers
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configXEnvironment
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configRouter
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configPCNFSD
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configNFSServer
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configWriteRC_conf
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NETCON_EXTENTIONS
end_ifdef

begin_function_decl
specifier|extern
name|int
name|configNovell
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* crc.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|crc
parameter_list|(
name|int
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
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
parameter_list|(
name|dialogMenuItem
modifier|*
name|d
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|check
function_decl|)
parameter_list|(
name|dialogMenuItem
modifier|*
name|d
parameter_list|)
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
name|Device
modifier|*
modifier|*
name|deviceFindDescr
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|desc
parameter_list|,
name|DeviceType
name|class
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
name|FILE
modifier|*
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
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

begin_function_decl
specifier|extern
name|Boolean
name|dummyInit
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|dummyGet
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|dist
parameter_list|,
name|Boolean
name|probe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dummyShutdown
parameter_list|(
name|Device
modifier|*
name|dev
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
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|diskPartitionWrite
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|diskGetSelectCount
parameter_list|(
name|Device
modifier|*
modifier|*
modifier|*
name|devs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|diskPartition
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dispatch.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|dispatchCommand
parameter_list|(
name|char
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dispatch_load_floppy
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dispatch_load_file_int
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dispatch_load_file
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
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
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distConfig
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetCustom
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetDeveloper
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetXDeveloper
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetKernDeveloper
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetUser
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetXUser
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetMinimum
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetEverything
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetDES
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetSrc
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distSetXF86
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|distExtractAll
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dmenu.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|dmenuDisplayFile
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSubmenu
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSystemCommand
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSystemCommandBox
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuExit
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSetVariable
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSetKmapVariable
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSetVariables
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuToggleVariable
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSetFlag
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuSetValue
parameter_list|(
name|dialogMenuItem
modifier|*
name|tmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
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
parameter_list|,
name|Boolean
name|buttons
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|dmenuOpenSimple
parameter_list|(
name|DMenu
modifier|*
name|menu
parameter_list|,
name|Boolean
name|buttons
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuVarCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuVarsCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuFlagCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dmenuRadioCheck
parameter_list|(
name|dialogMenuItem
modifier|*
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* doc.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|docBrowser
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|docShowDocument
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dos.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaCloseDOS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

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
name|FILE
modifier|*
name|mediaGetDOS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
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
name|FILE
modifier|*
name|mediaGetFloppy
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
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
name|FILE
modifier|*
name|fp
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
name|FILE
modifier|*
name|mediaGetFTP
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
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
comment|/* index.c */
end_comment

begin_function_decl
name|int
name|index_read
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|PkgNodePtr
name|papa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|index_menu
parameter_list|(
name|PkgNodePtr
name|top
parameter_list|,
name|PkgNodePtr
name|plist
parameter_list|,
name|int
modifier|*
name|pos
parameter_list|,
name|int
modifier|*
name|scroll
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|index_init
parameter_list|(
name|PkgNodePtr
name|top
parameter_list|,
name|PkgNodePtr
name|plist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|index_node_free
parameter_list|(
name|PkgNodePtr
name|top
parameter_list|,
name|PkgNodePtr
name|plist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|index_sort
parameter_list|(
name|PkgNodePtr
name|top
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|index_print
parameter_list|(
name|PkgNodePtr
name|top
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|index_extract
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|PkgNodePtr
name|top
parameter_list|,
name|PkgNodePtr
name|plist
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* install.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|checkLabels
parameter_list|(
name|Boolean
name|whinge
parameter_list|,
name|Chunk
modifier|*
modifier|*
name|rdev
parameter_list|,
name|Chunk
modifier|*
modifier|*
name|sdev
parameter_list|,
name|Chunk
modifier|*
modifier|*
name|udev
parameter_list|,
name|Chunk
modifier|*
modifier|*
name|vdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installCommit
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installCustomCommit
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installExpress
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installNovice
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installFixitHoloShell
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installFixitCDROM
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installFixitFloppy
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installFixup
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installUpgrade
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installFilesystems
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installVarDefaults
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|installEnvironment
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|copySelf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* keymap.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|loadKeymap
parameter_list|(
specifier|const
name|char
modifier|*
name|lang
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
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|diskLabelCommit
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lndir.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|lndir
parameter_list|(
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
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
name|termcap_ansi
index|[]
decl_stmt|;
end_decl_stmt

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
name|char
modifier|*
name|cpioVerbosity
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaClose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaTimeout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetCDROM
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFloppy
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetDOS
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetTape
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFTP
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFTPActive
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFTPPassive
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetUFS
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetNFS
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetFTPUserPass
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaSetCPIOVerbosity
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mediaGetType
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
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
name|dir
parameter_list|,
name|char
modifier|*
name|dist
parameter_list|,
name|FILE
modifier|*
name|fp
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
name|Boolean
name|directory_exists
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|root_bias
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|itoa
parameter_list|(
name|int
name|value
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
name|string_concat3
parameter_list|(
name|char
modifier|*
name|p1
parameter_list|,
name|char
modifier|*
name|p2
parameter_list|,
name|char
modifier|*
name|p3
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
name|char
modifier|*
name|string_copy
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
name|char
modifier|*
name|s2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|pathBaseName
parameter_list|(
specifier|const
name|char
modifier|*
name|path
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
name|dialogMenuItem
modifier|*
name|item_add
parameter_list|(
name|dialogMenuItem
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|,
name|char
modifier|*
name|title
parameter_list|,
name|int
function_decl|(
modifier|*
name|checked
function_decl|)
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
name|fire
function_decl|)
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|selected
function_decl|)
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|,
name|int
name|is_selected
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|int
name|aux
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
name|dialogMenuItem
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
name|WINDOW
modifier|*
name|openLayoutDialog
parameter_list|(
name|char
modifier|*
name|helpfile
parameter_list|,
name|char
modifier|*
name|title
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ComposeObj
modifier|*
name|initLayoutDialog
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|Layout
modifier|*
name|layout
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
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
name|layoutDialogLoop
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|Layout
modifier|*
name|layout
parameter_list|,
name|ComposeObj
modifier|*
modifier|*
name|obj
parameter_list|,
name|int
modifier|*
name|n
parameter_list|,
name|int
name|max
parameter_list|,
name|int
modifier|*
name|cbutton
parameter_list|,
name|int
modifier|*
name|cancel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|WINDOW
modifier|*
name|savescr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restorescr
parameter_list|(
name|WINDOW
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|sstrncpy
parameter_list|(
name|char
modifier|*
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
name|src
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* msg.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|isDebug
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|int
name|msgSimpleConfirm
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|msgSimpleNotify
parameter_list|(
name|char
modifier|*
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

begin_comment
comment|/* nfs.c */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|mediaInitNFS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|mediaGetNFS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mediaShutdownNFS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* options.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|optionsEditor
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* package.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|packageAdd
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|package_add
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|package_extract
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|Boolean
name|depended
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|package_exists
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* register.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|registerOpenDialog
parameter_list|(
name|void
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
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|execExecute
parameter_list|(
name|char
modifier|*
name|cmd
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
name|systemDisplayHelp
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
name|void
name|systemCreateHoloshell
parameter_list|(
name|void
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
name|char
modifier|*
name|mediaTapeBlocksize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|FILE
modifier|*
name|mediaGetTape
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
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
name|tcpMenuSelect
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Device
modifier|*
name|tcpDeviceSelect
parameter_list|(
name|void
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
name|void
name|mediaShutdownUFS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

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
name|FILE
modifier|*
name|mediaGetUFS
parameter_list|(
name|Device
modifier|*
name|dev
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|Boolean
name|probe
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* user.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|userAddGroup
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|userAddUser
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* variable.c */
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

begin_function_decl
specifier|extern
name|char
modifier|*
name|variable_get
parameter_list|(
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|variable_cmp
parameter_list|(
name|char
modifier|*
name|var
parameter_list|,
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|variable_unset
parameter_list|(
name|char
modifier|*
name|var
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|variable_get_value
parameter_list|(
name|char
modifier|*
name|var
parameter_list|,
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|variable_check
parameter_list|(
name|char
modifier|*
name|data
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

