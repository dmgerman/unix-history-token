begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    verbatim and that no modifications are made prior to this  *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SADE_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_SADE_H_INCLUDE
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
file|<errno.h>
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

begin_comment
comment|/*** Defines ***/
end_comment

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

begin_define
define|#
directive|define
name|WITH_SYSCONS
end_define

begin_define
define|#
directive|define
name|WITH_MICE
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|WITH_SLICES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|WITH_LINUX
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|100
end_define

begin_comment
comment|/* The maximum number of devices we'll deal with */
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
name|VAR_DISKINTERACTIVE
value|"diskInteractive"
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
name|VAR_GEOMETRY
value|"geometry"
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
name|VAR_NEWFS_ARGS
value|"newfsArgs"
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
name|VAR_NO_USR
value|"noUsr"
end_define

begin_define
define|#
directive|define
name|VAR_NO_TMP
value|"noTmp"
end_define

begin_define
define|#
directive|define
name|VAR_NO_HOME
value|"noHome"
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
name|VAR_PARTITION
value|"partition"
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
name|VAR_TMP_SIZE
value|"tmpSize"
end_define

begin_define
define|#
directive|define
name|VAR_TERM
value|"TERM"
end_define

begin_define
define|#
directive|define
name|VAR_CONSTERM
value|"_consterm"
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

begin_define
define|#
directive|define
name|ONE_GIG
value|(ONE_MEG * 1024)
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
index|[]
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
name|int
name|dirty
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

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVICE_TYPE_NONE
block|,
name|DEVICE_TYPE_DISK
block|,
name|DEVICE_TYPE_DOS
block|,
name|DEVICE_TYPE_UFS
block|,
name|DEVICE_TYPE_ANY
block|, }
name|DeviceType
typedef|;
end_typedef

begin_comment
comment|/* A "device" from sade's point of view */
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
name|unsigned
name|int
name|volume
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
block|,
name|PART_EFI
block|}
name|PartType
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NEWFS_UFS_CMD
value|"newfs"
end_define

begin_define
define|#
directive|define
name|NEWFS_MSDOS_CMD
value|"newfs_msdos"
end_define

begin_enum
enum|enum
name|newfs_type
block|{
name|NEWFS_UFS
block|,
name|NEWFS_MSDOS
block|,
name|NEWFS_CUSTOM
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NEWFS_UFS_STRING
value|"UFS"
end_define

begin_define
define|#
directive|define
name|NEWFS_MSDOS_STRING
value|"FAT"
end_define

begin_define
define|#
directive|define
name|NEWFS_CUSTOM_STRING
value|"CST"
end_define

begin_comment
comment|/* The longest set of custom command line arguments we'll pass. */
end_comment

begin_define
define|#
directive|define
name|NEWFS_CMD_ARGS_MAX
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|_part_info
block|{
name|char
name|mountpoint
index|[
name|FILENAME_MAX
index|]
decl_stmt|;
comment|/* Is invocation of newfs desired? */
name|Boolean
name|do_newfs
decl_stmt|;
name|enum
name|newfs_type
name|newfs_type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|char
name|user_options
index|[
name|NEWFS_CMD_ARGS_MAX
index|]
decl_stmt|;
name|Boolean
name|acls
decl_stmt|;
comment|/* unused */
name|Boolean
name|multilabel
decl_stmt|;
comment|/* unused */
name|Boolean
name|softupdates
decl_stmt|;
name|Boolean
name|ufs1
decl_stmt|;
block|}
name|newfs_ufs
struct|;
struct|struct
block|{
comment|/* unused */
block|}
name|newfs_msdos
struct|;
struct|struct
block|{
name|char
name|command
index|[
name|NEWFS_CMD_ARGS_MAX
index|]
decl_stmt|;
block|}
name|newfs_custom
struct|;
block|}
name|newfs_data
union|;
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
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|Option
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
name|EXTRAS_FIELD_LEN
value|128
end_define

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
name|Restarting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we restarting sysinstall?		*/
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

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuIPLType
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of IPL to write on the disk		*/
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMBRType
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of MBR to write on the disk		*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuMain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New main menu */
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDiskDevices
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Disk type devices                            */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|StartName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which name we were started as */
end_comment

begin_comment
comment|/* Important chunks. */
end_comment

begin_decl_stmt
specifier|extern
name|Chunk
modifier|*
name|HomeChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Chunk
modifier|*
name|RootChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Chunk
modifier|*
name|SwapChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Chunk
modifier|*
name|TmpChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Chunk
modifier|*
name|UsrChunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Chunk
modifier|*
name|VarChunk
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_decl_stmt
specifier|extern
name|Chunk
modifier|*
name|EfiChunk
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
name|configEnvironmentRC_conf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|configRC_conf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|configFstab
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
name|configWriteRC_conf
parameter_list|(
name|dialogMenuItem
modifier|*
name|self
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
name|void
name|deviceReset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|deviceRescan
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
name|devicename
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

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_SLICES
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

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
name|dmenuISetVariable
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
name|bscroll
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
name|Boolean
name|checkLabels
parameter_list|(
name|Boolean
name|whinge
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
comment|/* kget.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|kget
parameter_list|(
name|char
modifier|*
name|out
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
modifier|*
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
name|Mkdir_command
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
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printf0like
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgYap
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgWarn
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgDebug
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgError
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgFatal
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgConfirm
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgNotify
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|msgWeHaveOutput
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|msgYesNo
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|msgNoYes
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|msgSimpleConfirm
parameter_list|(
specifier|const
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
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* pccard.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|pccardInitialize
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
name|void
name|systemSuspendDialog
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|systemResumeDialog
parameter_list|(
name|void
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
name|int
name|vsystem
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

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
parameter_list|,
name|int
name|dirty
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
parameter_list|,
name|int
name|dirty
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
parameter_list|,
name|int
name|dirty
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

begin_function_decl
specifier|extern
name|int
name|variable_check2
parameter_list|(
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dump_variables
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
name|free_variables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pvariable_set
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
name|pvariable_get
parameter_list|(
name|char
modifier|*
name|var
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

begin_comment
comment|/*  * Macros.  Please find a better place for us!  */
end_comment

begin_define
define|#
directive|define
name|DEVICE_INIT
parameter_list|(
name|d
parameter_list|)
value|((d) != NULL ? (d)->init((d)) : (Boolean)0)
end_define

begin_define
define|#
directive|define
name|DEVICE_GET
parameter_list|(
name|d
parameter_list|,
name|b
parameter_list|,
name|f
parameter_list|)
value|((d) != NULL ? (d)->get((d), (b), (f)) : NULL)
end_define

begin_define
define|#
directive|define
name|DEVICE_SHUTDOWN
parameter_list|(
name|d
parameter_list|)
value|((d) != NULL ? (d)->shutdown((d)) : (void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYSINSTALL_H_INCLUDE */
end_comment

end_unit

