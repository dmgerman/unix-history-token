begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The new sysinstall program.  *  * This is probably the last attempt in the `sysinstall' line, the next  * generation being slated to essentially a complete rewrite.  *  * $Id: sysinstall.h,v 1.1.1.1 1995/04/27 12:50:34 jkh Exp $  *  * Copyright (c) 1995  *	Jordan Hubbard.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,   *    verbatim and that no modifications are made prior to this   *    point in the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jordan Hubbard  *	for the FreeBSD Project.  * 4. The name of Jordan Hubbard or the FreeBSD project may not be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JORDAN HUBBARD ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL JORDAN HUBBARD OR HIS PETS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, LIFE OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_comment
comment|/* Types */
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
name|MENU_SHELL_ESCAPE
block|,
comment|/* Fork a shell */
name|MENU_DISPLAY_FILE
block|,
comment|/* Display a file's contents */
name|MENU_SUBMENU
block|,
comment|/* Recurse into another menu */
name|MENU_SYSTEM_COMMAND
block|,
comment|/* Run shell commmand */
name|MENU_SYSTEM_COMMAND_BOX
block|,
comment|/* Same as above, but in prgbox */
name|MENU_SET_VARIABLE
block|,
comment|/* Set an environment/system var */
name|MENU_CALL
block|,
comment|/* Call back a C function */
name|MENU_CANCEL
block|,
comment|/* Cancel out of this menu */
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
comment|/* Our title */
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* Our prompt */
name|DMenuItemType
name|type
decl_stmt|;
comment|/* What type of item we are */
name|void
modifier|*
name|ptr
decl_stmt|;
comment|/* Generic data ptr */
name|int
name|disabled
decl_stmt|;
comment|/* Are we temporarily disabled? */
block|}
name|DMenuItem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_dmenu
block|{
name|char
modifier|*
name|title
decl_stmt|;
comment|/* Our title */
name|char
modifier|*
name|prompt
decl_stmt|;
comment|/* Our prompt */
name|char
modifier|*
name|helpline
decl_stmt|;
comment|/* Line of help at bottom */
name|char
modifier|*
name|helpfile
decl_stmt|;
comment|/* Help file for "F1" */
name|DMenuItem
modifier|*
name|items
decl_stmt|;
comment|/* Array of menu items */
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
name|value
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|Variable
typedef|;
end_typedef

begin_comment
comment|/* Externs */
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
comment|/* Where diagnostic output goes */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnCDROM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we running off of a CDROM? */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|OnSerial
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we on a serial console? */
end_comment

begin_decl_stmt
specifier|extern
name|Boolean
name|DialogActive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is the dialog() stuff up? */
end_comment

begin_decl_stmt
specifier|extern
name|Variable
modifier|*
name|VarHead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The head of the variable chain */
end_comment

begin_comment
comment|/* All the menus to which forward references exist */
end_comment

begin_decl_stmt
specifier|extern
name|DMenu
name|MenuDocumenation
decl_stmt|,
name|MenuInitial
decl_stmt|,
name|MenuLanguage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prototypes */
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
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|installExpress
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

begin_comment
comment|/* media.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|mediaSetCDROM
parameter_list|(
name|void
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

