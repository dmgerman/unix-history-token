begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|"useful.h"
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|sysexits
operator|.
name|c
literal|3.3
operator|%
name|G
operator|%
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* **  SYSEXITS.C -- error messages corresponding to sysexits.h */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SysExMsg
index|[]
init|=
block|{
comment|/* 64 */
literal|"Bad usage"
block|,
comment|/* 65 */
literal|"Data format error"
block|,
comment|/* 66 */
literal|"Cannot open input"
block|,
comment|/* 67 */
literal|"User unknown"
block|,
comment|/* 68 */
literal|"Host unknown"
block|,
comment|/* 69 */
literal|"Service unavailable"
block|,
comment|/* 70 */
literal|"Internal error"
block|,
comment|/* 71 */
literal|"Operating system error"
block|,
comment|/* 72 */
literal|"System file missing"
block|,
comment|/* 73 */
literal|"Can't create output"
block|,
comment|/* 74 */
literal|"I/O error"
block|,
comment|/* 75 */
literal|"Temporary failure"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|N_SysEx
init|=
sizeof|sizeof
name|SysExMsg
operator|/
sizeof|sizeof
name|SysExMsg
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

end_unit

