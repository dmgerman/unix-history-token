begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a vax under 4.2bsd. */
end_comment

begin_comment
comment|/* We have to include these files now, so that GDB will not make    competing definitions in defs.h.  */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_include
include|#
directive|include
file|"xm-vax.h"
end_include

begin_comment
comment|/* In non-ANSI compiles, memcpy and memset are still void *, not char *.  */
end_comment

begin_define
define|#
directive|define
name|MEM_FNS_DECLARED
end_define

end_unit

