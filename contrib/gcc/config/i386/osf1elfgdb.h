begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80386 running OSF/1 1.3+    with gas and gdb.  */
end_comment

begin_comment
comment|/* Use stabs instead of DWARF debug format.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_include
include|#
directive|include
file|"i386/osf1elf.h"
end_include

end_unit

