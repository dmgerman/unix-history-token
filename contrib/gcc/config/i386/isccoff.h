begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running Interactive Unix System V.    Specifically, this is for recent versions that support POSIX;    for version 2.0.2, use configuration option i386-sysv instead.    (But set TARGET_DEFAULT to (MASK_80307 | MASK_FLOAT_RETURNS)    if you do that, if you don't have a real 80387.)  */
end_comment

begin_comment
comment|/* Mostly it's like AT&T Unix System V.  */
end_comment

begin_include
include|#
directive|include
file|"i386/sysv3.h"
end_include

begin_comment
comment|/* But with a few changes.  */
end_comment

begin_include
include|#
directive|include
file|"i386/isc.h"
end_include

end_unit

