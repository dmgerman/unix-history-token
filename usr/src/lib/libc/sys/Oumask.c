begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Oumask.c 4.1 82/12/04 */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_define
define|#
directive|define
name|SYS_umask
value|60
end_define

begin_macro
name|SYSCALL
argument_list|(
argument|umask
argument_list|)
end_macro

begin_macro
name|ret
end_macro

end_unit

