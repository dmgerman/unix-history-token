begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"sun3.h"
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
value|"-Dmc68000 -Dsun -Dsun3 -Dunix -DMACH -DCMU -DMTXINU -DBIT_MSF -DBYTE_MSF"
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
comment|/* LINK_SPEC is needed only for Sunos 4.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

end_unit

