begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i386 running Mach as the target machine.  */
end_comment

begin_comment
comment|/* We do want to add an underscore to the front of each user symbol.    i386/gas.h checks this.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|"i386/gstabs.h"
end_include

begin_comment
comment|/* Get perform_* macros to build libgcc.a.  */
end_comment

begin_include
include|#
directive|include
file|"i386/perform.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -DMACH -Asystem(unix) -Asystem(mach) -Acpu(i386) -Amachine(i386)"
end_define

begin_comment
comment|/* Specify extra dir to search for include files.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_INCLUDE_DIR
value|"/usr/mach/include"
end_define

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

end_unit

