begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1991, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)options.h	10.19 (Berkeley) 10/10/96  */
end_comment

begin_comment
comment|/*  * Edit option information.  Historically, if you set a boolean or numeric  * edit option value to its "default" value, it didn't show up in the :set  * display, i.e. it wasn't considered "changed".  String edit options would  * show up as changed, regardless.  We maintain a parallel set of values  * which are the default values and never consider an edit option changed  * if it was reset to the default value.  *  * Macros to retrieve boolean, integral and string option values, and to  * set, clear and test boolean option values.  Some options (secure, lines,  * columns, terminal type) are global in scope, and are therefore stored  * in the global area.  The offset in the global options array is stored  * in the screen's value field.  This is set up when the options are first  * initialized.  */
end_comment

begin_define
define|#
directive|define
name|O_V
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|,
name|fld
parameter_list|)
define|\
value|(F_ISSET(&(sp)->opts[(o)], OPT_GLOBAL) ?			\ 	    (sp)->gp->opts[(sp)->opts[(o)].o_cur.val].fld :		\ 	    (sp)->opts[(o)].fld)
end_define

begin_comment
comment|/* Global option macros. */
end_comment

begin_define
define|#
directive|define
name|OG_CLR
parameter_list|(
name|gp
parameter_list|,
name|o
parameter_list|)
value|((gp)->opts[(o)].o_cur.val) = 0
end_define

begin_define
define|#
directive|define
name|OG_SET
parameter_list|(
name|gp
parameter_list|,
name|o
parameter_list|)
value|((gp)->opts[(o)].o_cur.val) = 1
end_define

begin_define
define|#
directive|define
name|OG_STR
parameter_list|(
name|gp
parameter_list|,
name|o
parameter_list|)
value|((gp)->opts[(o)].o_cur.str)
end_define

begin_define
define|#
directive|define
name|OG_VAL
parameter_list|(
name|gp
parameter_list|,
name|o
parameter_list|)
value|((gp)->opts[(o)].o_cur.val)
end_define

begin_define
define|#
directive|define
name|OG_ISSET
parameter_list|(
name|gp
parameter_list|,
name|o
parameter_list|)
value|OG_VAL(gp, o)
end_define

begin_define
define|#
directive|define
name|OG_D_STR
parameter_list|(
name|gp
parameter_list|,
name|o
parameter_list|)
value|((gp)->opts[(o)].o_def.str)
end_define

begin_define
define|#
directive|define
name|OG_D_VAL
parameter_list|(
name|gp
parameter_list|,
name|o
parameter_list|)
value|((gp)->opts[(o)].o_def.val)
end_define

begin_comment
comment|/*  * Flags to o_set(); need explicit OS_STR as can be setting the value to  * NULL.  */
end_comment

begin_define
define|#
directive|define
name|OS_DEF
value|0x01
end_define

begin_comment
comment|/* Set the default value. */
end_comment

begin_define
define|#
directive|define
name|OS_NOFREE
value|0x02
end_define

begin_comment
comment|/* Don't free the old string. */
end_comment

begin_define
define|#
directive|define
name|OS_STR
value|0x04
end_define

begin_comment
comment|/* Set to string argument. */
end_comment

begin_define
define|#
directive|define
name|OS_STRDUP
value|0x08
end_define

begin_comment
comment|/* Copy then set to string argument. */
end_comment

begin_struct
struct|struct
name|_option
block|{
union|union
block|{
name|u_long
name|val
decl_stmt|;
comment|/* Value or boolean. */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* String. */
block|}
name|o_cur
union|;
define|#
directive|define
name|O_CLR
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|o_set(sp, o, 0, NULL, 0)
define|#
directive|define
name|O_SET
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|o_set(sp, o, 0, NULL, 1)
define|#
directive|define
name|O_STR
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|O_V(sp, o, o_cur.str)
define|#
directive|define
name|O_VAL
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|O_V(sp, o, o_cur.val)
define|#
directive|define
name|O_ISSET
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|O_VAL(sp, o)
union|union
block|{
name|u_long
name|val
decl_stmt|;
comment|/* Value or boolean. */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* String. */
block|}
name|o_def
union|;
define|#
directive|define
name|O_D_CLR
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|o_set(sp, o, OS_DEF, NULL, 0)
define|#
directive|define
name|O_D_SET
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|o_set(sp, o, OS_DEF, NULL, 1)
define|#
directive|define
name|O_D_STR
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|O_V(sp, o, o_def.str)
define|#
directive|define
name|O_D_VAL
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|O_V(sp, o, o_def.val)
define|#
directive|define
name|O_D_ISSET
parameter_list|(
name|sp
parameter_list|,
name|o
parameter_list|)
value|O_D_VAL(sp, o)
define|#
directive|define
name|OPT_GLOBAL
value|0x01
comment|/* Option is global. */
define|#
directive|define
name|OPT_SELECTED
value|0x02
comment|/* Selected for display. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* List of option names, associated update functions and information. */
end_comment

begin_struct
struct|struct
name|_optlist
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name. */
comment|/* Change function. */
name|int
argument_list|(
argument|*func
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|OPTION
operator|*
operator|,
name|char
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Type of object. */
enum|enum
block|{
name|OPT_0BOOL
block|,
name|OPT_1BOOL
block|,
name|OPT_NUM
block|,
name|OPT_STR
block|}
name|type
enum|;
define|#
directive|define
name|OPT_ADISP
value|0x001
comment|/* Always display the option. */
define|#
directive|define
name|OPT_ALWAYS
value|0x002
comment|/* Always call the support function. */
define|#
directive|define
name|OPT_NDISP
value|0x004
comment|/* Never display the option. */
define|#
directive|define
name|OPT_NOSAVE
value|0x008
comment|/* Mkexrc command doesn't save. */
define|#
directive|define
name|OPT_NOSET
value|0x010
comment|/* Option may not be set. */
define|#
directive|define
name|OPT_NOUNSET
value|0x020
comment|/* Option may not be unset. */
define|#
directive|define
name|OPT_NOZERO
value|0x040
comment|/* Option may not be set to 0. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Option argument to opts_dump(). */
end_comment

begin_enum
enum|enum
name|optdisp
block|{
name|NO_DISPLAY
block|,
name|ALL_DISPLAY
block|,
name|CHANGED_DISPLAY
block|,
name|SELECT_DISPLAY
block|}
enum|;
end_enum

begin_comment
comment|/* Options array. */
end_comment

begin_decl_stmt
specifier|extern
name|OPTLIST
specifier|const
name|optlist
index|[]
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"options_def.h"
end_include

end_unit

