begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"i386/xm-i386.h"
end_include

begin_comment
comment|/* malloc does better with chunks the size of a page.  */
end_comment

begin_define
define|#
directive|define
name|OBSTACK_CHUNK_SIZE
value|(getpagesize ())
end_define

end_unit

