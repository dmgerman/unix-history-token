begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|MOTOROLA_SYNTAX
end_define

begin_comment
comment|/* Allow OP as an alias for OP.l (or OP.w or OP.b, depend on OP). */
end_comment

begin_define
define|#
directive|define
name|ALLOW_DEFAULT_SIZES
end_define

begin_comment
comment|/* Customers want bhi and friends to be variable sized - stolen from jhi */
end_comment

begin_define
define|#
directive|define
name|BRANCH_IS_VARIABLE_SIZED
end_define

begin_include
include|#
directive|include
file|"m68k.h"
end_include

end_unit

