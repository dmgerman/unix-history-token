begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for an i860 running Mach as the target machine.  */
end_comment

begin_include
include|#
directive|include
file|"i860.h"
end_include

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i860 Mach3.x)");
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di860 -DMACH"
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

end_unit

