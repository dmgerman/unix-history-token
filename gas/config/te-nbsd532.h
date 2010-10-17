begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is te-netbsd532.h    Written by Ian Dall<idall@eleceng.adelaide.edu.au>    19-Jun-94.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-ns32k-netbsd"
end_define

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/* Maybe these should be more like TC_NS32532 and TC_NS32381 in case    of conflicts. NS32381 is used in opcode/ns32k.h and that is also    used by GDB. Need to check.  */
end_comment

begin_define
define|#
directive|define
name|NS32532
end_define

begin_define
define|#
directive|define
name|NS32381
end_define

end_unit

