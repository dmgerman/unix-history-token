begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"tm-sparc.h"
end_include

begin_comment
comment|/* Define the Sun-asm flag, which is necessary for Sun 4 with os version 3.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|7
end_define

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fprintf (FILE, "\tsethi %%hi(LP%d),%%o0\n\tcall .mcount\n\tor %%lo(LP%d),%%o0,%%o0\n", \ 	   (LABELNO), (LABELNO))
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

