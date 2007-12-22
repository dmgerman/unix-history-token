begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Top - a top users display for Berkeley Unix  *  *  General (global) definitions  */
end_comment

begin_comment
comment|/* Current major version number */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|3
end_define

begin_comment
comment|/* Number of lines of header information on the standard screen */
end_comment

begin_define
define|#
directive|define
name|Header_lines
value|7
end_define

begin_comment
comment|/* Maximum number of columns allowed for display */
end_comment

begin_define
define|#
directive|define
name|MAX_COLS
value|128
end_define

begin_comment
comment|/* Log base 2 of 1024 is 10 (2^10 == 1024) */
end_comment

begin_define
define|#
directive|define
name|LOG1024
value|10
end_define

begin_function_decl
name|char
modifier|*
name|itoa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|itoa7
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|version_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Special atoi routine returns either a non-negative number or one of: */
end_comment

begin_define
define|#
directive|define
name|Infinity
value|-1
end_define

begin_define
define|#
directive|define
name|Invalid
value|-2
end_define

begin_comment
comment|/* maximum number we can have */
end_comment

begin_define
define|#
directive|define
name|Largest
value|0x7fffffff
end_define

begin_comment
comment|/*  * The entire display is based on these next numbers being defined as is.  */
end_comment

begin_define
define|#
directive|define
name|NUM_AVERAGES
value|3
end_define

begin_enum
enum|enum
name|displaymodes
block|{
name|DISP_CPU
init|=
literal|0
block|,
name|DISP_IO
block|,
name|DISP_MAX
block|}
enum|;
end_enum

begin_comment
comment|/*  * Format modifiers  */
end_comment

begin_define
define|#
directive|define
name|FMT_SHOWARGS
value|0x00000001
end_define

begin_decl_stmt
specifier|extern
name|enum
name|displaymodes
name|displaymode
decl_stmt|;
end_decl_stmt

end_unit

