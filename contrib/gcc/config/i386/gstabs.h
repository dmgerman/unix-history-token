begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"i386/gas.h"
end_include

begin_comment
comment|/* We do not want to output SDB debugging information.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_comment
comment|/* We want to output DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

end_unit

