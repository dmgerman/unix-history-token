begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_struct
struct|struct
name|group
block|{
name|char
modifier|*
name|gr_name
decl_stmt|;
name|gid_t
name|gr_gid
decl_stmt|;
name|char
modifier|*
name|gr_passwd
decl_stmt|;
name|char
modifier|*
modifier|*
name|gr_mem
decl_stmt|;
block|}
struct|;
end_struct

end_unit

