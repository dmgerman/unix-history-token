begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* status.c    Strings for status codes.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|"uudefs.h"
end_include

begin_comment
comment|/* Status strings.  These must match enum tstatus_type.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|azStatus
index|[]
init|=
block|{
literal|"Conversation complete"
block|,
literal|"Port unavailable"
block|,
literal|"Dial failed"
block|,
literal|"Login failed"
block|,
literal|"Handshake failed"
block|,
literal|"Call failed"
block|,
literal|"Talking"
block|,
literal|"Wrong time to call"
block|}
decl_stmt|;
end_decl_stmt

end_unit

