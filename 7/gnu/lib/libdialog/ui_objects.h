begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Marc van Kempen  * Desc:   include file for UI-objects  *  * Copyright (c) 1995, Marc van Kempen  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  *  */
end_comment

begin_include
include|#
directive|include
file|"dialog.h"
end_include

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_comment
comment|/***********************************************************************  *  * Defines  *  ***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|ctrl
parameter_list|(
name|a
parameter_list|)
value|((a) - 'a' + 1)
end_define

begin_comment
comment|/* the Object types */
end_comment

begin_define
define|#
directive|define
name|STRINGOBJ
value|1
end_define

begin_define
define|#
directive|define
name|LISTOBJ
value|2
end_define

begin_define
define|#
directive|define
name|BUTTONOBJ
value|3
end_define

begin_comment
comment|/* the return signals from the selection routines */
end_comment

begin_comment
comment|/* 1000 and higher should avoid conflicts with keys pressed */
end_comment

begin_define
define|#
directive|define
name|SEL_CR
value|1001
end_define

begin_comment
comment|/* return was pressed */
end_comment

begin_define
define|#
directive|define
name|SEL_ESC
value|1002
end_define

begin_comment
comment|/* ESC pressed */
end_comment

begin_define
define|#
directive|define
name|SEL_TAB
value|1003
end_define

begin_comment
comment|/* TAB pressed */
end_comment

begin_define
define|#
directive|define
name|SEL_BACKTAB
value|1004
end_define

begin_comment
comment|/* SHIFT-TAB pressed */
end_comment

begin_define
define|#
directive|define
name|SEL_BUTTON
value|1005
end_define

begin_comment
comment|/* a button was pressed */
end_comment

begin_comment
comment|/***********************************************************************  *  * Typedefs  *  ***********************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|WINDOW
modifier|*
name|win
decl_stmt|;
comment|/* the window it's contained in */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* the prompt for the input field */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* initial value of the input field */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|w
decl_stmt|,
name|len
decl_stmt|;
comment|/* the (y, x) position of the upperleft */
comment|/* corner and the width<w> of the display */
comment|/* and length<len> of the field */
name|int
name|attr_mask
decl_stmt|;
comment|/* special attributes */
block|}
name|StringObj
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|WINDOW
modifier|*
name|win
decl_stmt|;
comment|/* the windows it's contained in */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* the title of the list */
name|char
modifier|*
modifier|*
name|name
decl_stmt|;
comment|/* the names of the list */
name|int
modifier|*
name|seld
decl_stmt|;
comment|/* the currently selected names */
name|char
modifier|*
name|elt
decl_stmt|;
comment|/* the current element in the list list[sel] */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|w
decl_stmt|,
name|h
decl_stmt|,
name|n
decl_stmt|;
comment|/* dimensions of list and # of elements (n) */
name|int
name|scroll
decl_stmt|,
name|sel
decl_stmt|;
comment|/* current position in the list */
block|}
name|ListObj
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|WINDOW
modifier|*
name|win
decl_stmt|;
comment|/* the window it's contained in */
name|char
modifier|*
name|title
decl_stmt|;
comment|/* title for the button */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|w
decl_stmt|,
name|h
decl_stmt|;
comment|/* its dimensions */
name|int
modifier|*
name|pushed
decl_stmt|;
comment|/* boolean that determines wether button was pushed */
block|}
name|ButtonObj
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ComposeObj
block|{
name|int
name|objtype
decl_stmt|;
name|void
modifier|*
name|obj
decl_stmt|;
name|struct
name|ComposeObj
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
name|ComposeObj
typedef|;
end_typedef

begin_comment
comment|/**********************************************************************  *  * Prototypes  *  **********************************************************************/
end_comment

begin_function_decl
name|void
name|RefreshStringObj
parameter_list|(
name|StringObj
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|StringObj
modifier|*
name|NewStringObj
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|char
modifier|*
name|title
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|SelectStringObj
parameter_list|(
name|StringObj
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DelStringObj
parameter_list|(
name|StringObj
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RefreshListObj
parameter_list|(
name|ListObj
modifier|*
name|lo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ListObj
modifier|*
name|NewListObj
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|char
modifier|*
name|title
parameter_list|,
name|char
modifier|*
modifier|*
name|list
parameter_list|,
name|char
modifier|*
name|listelt
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|h
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UpdateListObj
parameter_list|(
name|ListObj
modifier|*
name|lo
parameter_list|,
name|char
modifier|*
modifier|*
name|list
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|SelectListObj
parameter_list|(
name|ListObj
modifier|*
name|lo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DelListObj
parameter_list|(
name|ListObj
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkCurrentListObj
parameter_list|(
name|ListObj
modifier|*
name|lo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|MarkAllListObj
parameter_list|(
name|ListObj
modifier|*
name|lo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnMarkAllListObj
parameter_list|(
name|ListObj
modifier|*
name|lo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RefreshButtonObj
parameter_list|(
name|ButtonObj
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ButtonObj
modifier|*
name|NewButtonObj
parameter_list|(
name|WINDOW
modifier|*
name|win
parameter_list|,
name|char
modifier|*
name|title
parameter_list|,
name|int
modifier|*
name|pushed
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|SelectButtonObj
parameter_list|(
name|ButtonObj
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DelButtonObj
parameter_list|(
name|ButtonObj
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddObj
parameter_list|(
name|ComposeObj
modifier|*
modifier|*
name|Obj
parameter_list|,
name|int
name|objtype
parameter_list|,
name|void
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FreeObj
parameter_list|(
name|ComposeObj
modifier|*
name|Obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ReadObj
parameter_list|(
name|ComposeObj
modifier|*
name|Obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|PollObj
parameter_list|(
name|ComposeObj
modifier|*
modifier|*
name|Obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DelObj
parameter_list|(
name|ComposeObj
modifier|*
name|Obj
parameter_list|)
function_decl|;
end_function_decl

end_unit

