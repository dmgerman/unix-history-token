begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vhangup.c 4.3 82/12/29 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_define
define|#
directive|define
name|SYS_vhangup
value|76
end_define

begin_macro
name|SYSCALL
argument_list|(
argument|vhangup
argument_list|)
end_macro

begin_macro
name|ret
end_macro

end_unit

