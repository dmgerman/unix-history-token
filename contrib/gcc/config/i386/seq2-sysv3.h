begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Sequent DYNIX/ptx 2.x (SVr3) */
end_comment

begin_include
include|#
directive|include
file|"i386/seq-sysv3.h"
end_include

begin_comment
comment|/* Use atexit for static destructors, instead of defining    our own exit function.  */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_ATEXIT
end_undef

end_unit

