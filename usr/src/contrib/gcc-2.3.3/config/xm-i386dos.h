begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"xm-i386.h"
end_include

begin_comment
comment|/* Inhibit cccp.c's definition of putenv.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
end_define

begin_comment
comment|/* Use semicolons to separate elements of a path.  */
end_comment

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|';'
end_define

begin_comment
comment|/* Suffix for executable file names.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTABLE_SUFFIX
value|".exe"
end_define

end_unit

