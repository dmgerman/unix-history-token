begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* System-dependent stuff for AIX 3.1 on RS/6000 */
end_comment

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|dirent
name|dirent
typedef|;
end_typedef

end_unit

