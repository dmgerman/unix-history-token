begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"s-bsd4-2.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This may have been needed for an earlier version of Sun OS 4. 	  It seems to cause warnings in 4.0.3 and 4.1.  */
end_comment

begin_define
define|#
directive|define
name|O_NDELAY
value|FNDELAY
end_define

begin_comment
comment|/* Non-blocking I/O (4.2 style) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LD_SWITCH_SYSTEM
value|-e __start -Bstatic
end_define

begin_comment
comment|/* In SunOS 4.1, a static function called by tzsetwall reportedly    clears the byte just past an eight byte region it mallocs, corrupting    GNU malloc's memory pool.  But Sun's malloc doesn't seem to mind. */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_MALLOC
end_define

begin_comment
comment|/* 4.1.1 makes these system calls interruptable.  */
end_comment

begin_define
define|#
directive|define
name|read
value|sys_read
end_define

begin_define
define|#
directive|define
name|write
value|sys_write
end_define

begin_define
define|#
directive|define
name|open
value|sys_open
end_define

begin_define
define|#
directive|define
name|close
value|sys_close
end_define

begin_define
define|#
directive|define
name|INTERRUPTABLE_OPEN
end_define

begin_define
define|#
directive|define
name|INTERRUPTABLE_CLOSE
end_define

begin_define
define|#
directive|define
name|INTERRUPTABLE_IO
end_define

end_unit

