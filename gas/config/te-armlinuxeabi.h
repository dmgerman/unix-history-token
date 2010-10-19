begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"te-linux.h"
end_include

begin_comment
comment|/* The EABI requires the use of VFP.  */
end_comment

begin_define
define|#
directive|define
name|FPU_DEFAULT
value|FPU_ARCH_VFP_V2
end_define

begin_define
define|#
directive|define
name|EABI_DEFAULT
value|EF_ARM_EABI_VER4
end_define

end_unit

