begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1984-2000  Mark Nudelman  *  * You may distribute under the terms of either the GNU General Public  * License or the Less License, as specified in the README file.  *  * For more information about less, or for information on how to   * contact the author, see the README file.  */
end_comment

begin_define
define|#
directive|define
name|END_OPTION_STRING
value|('$')
end_define

begin_comment
comment|/*  * Types of options.  */
end_comment

begin_define
define|#
directive|define
name|BOOL
value|01
end_define

begin_comment
comment|/* Boolean option: 0 or 1 */
end_comment

begin_define
define|#
directive|define
name|TRIPLE
value|02
end_define

begin_comment
comment|/* Triple-valued option: 0, 1 or 2 */
end_comment

begin_define
define|#
directive|define
name|NUMBER
value|04
end_define

begin_comment
comment|/* Numeric option */
end_comment

begin_define
define|#
directive|define
name|STRING
value|010
end_define

begin_comment
comment|/* String-valued option */
end_comment

begin_define
define|#
directive|define
name|NOVAR
value|020
end_define

begin_comment
comment|/* No associated variable */
end_comment

begin_define
define|#
directive|define
name|REPAINT
value|040
end_define

begin_comment
comment|/* Repaint screen after toggling option */
end_comment

begin_define
define|#
directive|define
name|NO_TOGGLE
value|0100
end_define

begin_comment
comment|/* Option cannot be toggled with "-" cmd */
end_comment

begin_define
define|#
directive|define
name|HL_REPAINT
value|0200
end_define

begin_comment
comment|/* Repaint hilites after toggling option */
end_comment

begin_define
define|#
directive|define
name|NO_QUERY
value|0400
end_define

begin_comment
comment|/* Option cannot be queried with "_" cmd */
end_comment

begin_define
define|#
directive|define
name|OTYPE
value|(BOOL|TRIPLE|NUMBER|STRING|NOVAR)
end_define

begin_comment
comment|/*  * Argument to a handling function tells what type of activity:  */
end_comment

begin_define
define|#
directive|define
name|INIT
value|0
end_define

begin_comment
comment|/* Initialization (from command line) */
end_comment

begin_define
define|#
directive|define
name|QUERY
value|1
end_define

begin_comment
comment|/* Query (from _ or - command) */
end_comment

begin_define
define|#
directive|define
name|TOGGLE
value|2
end_define

begin_comment
comment|/* Change value (from - command) */
end_comment

begin_comment
comment|/* Flag to toggle_option to specify how to "toggle" */
end_comment

begin_define
define|#
directive|define
name|OPT_NO_TOGGLE
value|0
end_define

begin_define
define|#
directive|define
name|OPT_TOGGLE
value|1
end_define

begin_define
define|#
directive|define
name|OPT_UNSET
value|2
end_define

begin_define
define|#
directive|define
name|OPT_SET
value|3
end_define

begin_define
define|#
directive|define
name|OPT_NO_PROMPT
value|0100
end_define

begin_comment
comment|/* Error code from findopt_name */
end_comment

begin_define
define|#
directive|define
name|OPT_AMBIG
value|1
end_define

begin_struct
struct|struct
name|optname
block|{
name|char
modifier|*
name|oname
decl_stmt|;
comment|/* Long (GNU-style) option name */
name|struct
name|optname
modifier|*
name|onext
decl_stmt|;
comment|/* List of synonymous option names */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|option
block|{
name|char
name|oletter
decl_stmt|;
comment|/* The controlling letter (a-z) */
name|struct
name|optname
modifier|*
name|onames
decl_stmt|;
comment|/* Long (GNU-style) option name */
name|int
name|otype
decl_stmt|;
comment|/* Type of the option */
name|int
name|odefault
decl_stmt|;
comment|/* Default value */
name|int
modifier|*
name|ovar
decl_stmt|;
comment|/* Pointer to the associated variable */
name|void
function_decl|(
modifier|*
name|ofunc
function_decl|)
parameter_list|()
function_decl|;
comment|/* Pointer to special handling function */
name|char
modifier|*
name|odesc
index|[
literal|3
index|]
decl_stmt|;
comment|/* Description of each value */
block|}
struct|;
end_struct

end_unit

