begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine specific defines for the dpx2 machine.  */
end_comment

begin_comment
comment|/* The magic number is not the usual MC68MAGIC.  */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC
value|MC68KBCSMAGIC
end_define

begin_define
define|#
directive|define
name|REGISTER_PREFIX_OPTIONAL
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-m68k-un"
end_define

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/* end of te-dpx2.h */
end_comment

end_unit

