begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"itbl-mips.h"
end_include

begin_comment
comment|/* Choose a default ABI for MIPS targets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_DEFAULT_ABI
end_ifndef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_ABI
value|NO_ABI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default CPU for MIPS targets.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CPU_STRING_DEFAULT
value|"from-abi"
end_define

begin_comment
comment|/* Generate 64-bit code by default on MIPS targets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_DEFAULT_64BIT
end_ifndef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_64BIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allow use of E_MIPS_ABI_O32 on MIPS targets.  */
end_comment

begin_define
define|#
directive|define
name|USE_E_MIPS_ABI_O32
value|1
end_define

begin_comment
comment|/* Use traditional mips */
end_comment

begin_define
define|#
directive|define
name|TE_TMIPS
value|1
end_define

end_unit

