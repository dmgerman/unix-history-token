begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|AUTOGEN_PROJECT_H
end_ifndef

begin_define
define|#
directive|define
name|AUTOGEN_PROJECT_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/*  *  Procedure success codes  *  *  USAGE:  define procedures to return "tSuccess".  Test their results  *          with the SUCCEEDED, FAILED and HADGLITCH macros.  *  *  Microsoft sticks its nose into user space here, so for Windows' sake,  *  make sure all of these are undefined.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUCCESS
end_undef

begin_undef
undef|#
directive|undef
name|FAILURE
end_undef

begin_undef
undef|#
directive|undef
name|PROBLEM
end_undef

begin_undef
undef|#
directive|undef
name|SUCCEEDED
end_undef

begin_undef
undef|#
directive|undef
name|SUCCESSFUL
end_undef

begin_undef
undef|#
directive|undef
name|FAILED
end_undef

begin_undef
undef|#
directive|undef
name|HADGLITCH
end_undef

begin_define
define|#
directive|define
name|SUCCESS
value|((tSuccess) 0)
end_define

begin_define
define|#
directive|define
name|FAILURE
value|((tSuccess)-1)
end_define

begin_define
define|#
directive|define
name|PROBLEM
value|((tSuccess) 1)
end_define

begin_typedef
typedef|typedef
name|int
name|tSuccess
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SUCCEEDED
parameter_list|(
name|p
parameter_list|)
value|((p) == SUCCESS)
end_define

begin_define
define|#
directive|define
name|SUCCESSFUL
parameter_list|(
name|p
parameter_list|)
value|SUCCEEDED(p)
end_define

begin_define
define|#
directive|define
name|FAILED
parameter_list|(
name|p
parameter_list|)
value|((p)<  SUCCESS)
end_define

begin_define
define|#
directive|define
name|HADGLITCH
parameter_list|(
name|p
parameter_list|)
value|((p)>  SUCCESS)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STR
end_ifndef

begin_define
define|#
directive|define
name|__STR
parameter_list|(
name|s
parameter_list|)
value|#s
end_define

begin_define
define|#
directive|define
name|STR
parameter_list|(
name|s
parameter_list|)
value|__STR(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STRSIZE
parameter_list|(
name|s
parameter_list|)
value|(sizeof(s)-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINING
end_ifdef

begin_define
define|#
directive|define
name|VALUE
parameter_list|(
name|s
parameter_list|)
value|= s
end_define

begin_define
define|#
directive|define
name|MODE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VALUE
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODE
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOGEN_PROJECT_H */
end_comment

end_unit

