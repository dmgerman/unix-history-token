begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last attempt in the `sysinstall' line, the next  * generation being slated to essentially a complete rewrite.  *  * $Id: sysinstall.h,v 1.10 1995/05/07 02:04:29 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_comment
comment|/* Bitfields for distributions - hope we never have more than 32! :-) */
end_comment

begin_define
define|#
directive|define
name|DIST_BIN
value|0x1
end_define

begin_define
define|#
directive|define
name|DIST_GAMES
value|0x2
end_define

begin_define
define|#
directive|define
name|DIST_MANPAGES
value|0x4
end_define

begin_define
define|#
directive|define
name|DIST_PROFLIBS
value|0x8
end_define

begin_define
define|#
directive|define
name|DIST_DICT
value|0x10
end_define

begin_define
define|#
directive|define
name|DIST_SRC
value|0x20
end_define

begin_define
define|#
directive|define
name|DIST_DES
value|0x40
end_define

begin_define
define|#
directive|define
name|DIST_COMPAT1X
value|0x80
end_define

begin_define
define|#
directive|define
name|DIST_XFREE86
value|0x100
end_define

begin_define
define|#
directive|define
name|DIST_ALL
value|0xFFF
end_define

begin_comment
comment|/* Canned distribution sets */
end_comment

begin_define
define|#
directive|define
name|_DIST_DEVELOPER
define|\
value|(DIST_BIN | DIST_MANPAGES | DIST_DICT | DIST_PROFLIBS | DIST_SRC)
end_define

begin_define
define|#
directive|define
name|_DIST_XDEVELOPER
define|\
value|(_DIST_DEVELOPER | DIST_XFREE86)
end_define

begin_define
define|#
directive|define
name|_DIST_USER
define|\
value|(DIST_BIN | DIST_MANPAGES | DIST_DICT | DIST_COMPAT1X)
end_define

begin_define
define|#
directive|define
name|_DIST_XUSER
define|\
value|(_DIST_USER | DIST_XFREE86)
end_define

begin_comment
comment|/* Subtypes for SRC distribution */
end_comment

begin_define
define|#
directive|define
name|DIST_SRC_BASE
value|0x1
end_define

begin_define
define|#
directive|define
name|DIST_SRC_GNU
value|0x2
end_define

begin_define
define|#
directive|define
name|DIST_SRC_ETC
value|0x4
end_define

begin_define
define|#
directive|define
name|DIST_SRC_GAMES
value|0x8
end_define

begin_define
define|#
directive|define
name|DIST_SRC_INCLUDE
value|0x10
end_define

begin_define
define|#
directive|define
name|DIST_SRC_LIB
value|0x20
end_define

begin_define
define|#
directive|define
name|DIST_SRC_LIBEXEC
value|0x40
end_define

begin_define
define|#
directive|define
name|DIST_SRC_LKM
value|0x80
end_define

begin_define
define|#
directive|define
name|DIST_SRC_RELEASE
value|0x100
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SBIN
value|0x200
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SHARE
value|0x400
end_define

begin_define
define|#
directive|define
name|DIST_SRC_SYS
value|0x800
end_define

begin_define
define|#
directive|define
name|DIST_SRC_UBIN
value|0x1000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_USBIN
value|0x2000
end_define

begin_define
define|#
directive|define
name|DIST_SRC_ALL
value|0xFFFF
end_define

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
comment|/* handy */
end_comment

begin_define
define|#
directive|define
name|ONE_MEG
value|1048576
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

begin_typedef
typedef|typedef
enum|enum
block|{
name|DEVICE_TYPE_ANY
block|,
name|DEVICE_TYPE_DISK
block|,
name|DEVICE_TYPE_FLOPPY
block|,
name|DEVICE_TYPE_NETWORK
block|,
name|DEVICE_TYPE_CDROM
block|,
name|DEVICE_TYPE_TAPE
block|,
name|DEVICE_TYPE_SERIAL
block|,
name|DEVICE_TYPE_PARALLEL
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
name|DeviceType
name|type
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
block|}
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
comment|/*** Externs ***/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|CpioFD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The file descriptor for our CPIO floppy */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|DebugFD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Where diagnostic output goes	*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnCDROM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we running off of a CDROM?	*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnSerial
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a serial console?	*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|SystemWasInstalled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Did we install it?       */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|DialogActive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is the dialog() stuff up?	*/
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|ColorDisplay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a color display?     */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnVTY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* On a syscons VTY?			*/
end_comment

begin_decl_stmt
specifier|extern
name|Variable
modifier|*
name|VarHead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The head of the variable chain	*/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|Dists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which distributions we want        */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|SrcDists
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Which src distributions we want    */
end_comment

begin_comment
comment|/*** Prototypes ***/
end_comment

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
name|installCustom
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
name|installExpress
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
name|installMaint
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dist.c */
end_comment

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
comment|/* disks.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|partition_disks
parameter_list|(
name|struct
name|disk
modifier|*
modifier|*
name|disks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|write_disks
parameter_list|(
name|struct
name|disk
modifier|*
modifier|*
name|disks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|make_filesystems
parameter_list|(
name|struct
name|disk
modifier|*
modifier|*
name|disks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cpio_extract
parameter_list|(
name|struct
name|disk
modifier|*
modifier|*
name|disks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|extract_dists
parameter_list|(
name|struct
name|disk
modifier|*
modifier|*
name|disks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|install_configuration_files
parameter_list|(
name|struct
name|disk
modifier|*
modifier|*
name|disks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_final_setup
parameter_list|(
name|struct
name|disk
modifier|*
modifier|*
name|disks
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

begin_comment
comment|/* devices.c */
end_comment

begin_function_decl
specifier|extern
name|Device
modifier|*
name|device_get_all
parameter_list|(
name|DeviceType
name|type
parameter_list|,
name|int
modifier|*
name|ndevs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|disk
modifier|*
name|device_slice_disk
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DMenu
modifier|*
name|device_create_disk_menu
parameter_list|(
name|DMenu
modifier|*
name|menu
parameter_list|,
name|Device
modifier|*
modifier|*
name|rdevs
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
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
name|font_iso_8x14
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
name|font_cp850_8x14
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_char
name|font_koi8_r_8x14
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

begin_comment
comment|/* wizard.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|slice_wizard
parameter_list|(
name|struct
name|disk
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

