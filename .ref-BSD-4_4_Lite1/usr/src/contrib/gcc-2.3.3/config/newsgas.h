begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* In Sony versions before 3.0, use the GNU Assembler, because the    system's assembler has no way to assemble the difference of two    labels for the displacement in a switch-dispatch instruction.  */
end_comment

begin_define
define|#
directive|define
name|USE_GAS
end_define

begin_include
include|#
directive|include
file|"news.h"
end_include

end_unit

