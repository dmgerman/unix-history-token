begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by MIT Student Information Processing Board  *  * For copyright information, see mit-sipb-copyright.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ss_h
end_ifndef

begin_define
define|#
directive|define
name|_ss_h
value|__FILE__
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<ss/mit-sipb-copyright.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IN_MK_CMDS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBSS
end_ifdef

begin_include
include|#
directive|include
file|"ss_err.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<ss/ss_err.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__SS_CONST
value|const
end_define

begin_define
define|#
directive|define
name|__SS_PROTO
value|(int, const char * const *, int, void *)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__SS_CONST
end_define

begin_define
define|#
directive|define
name|__SS_PROTO
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__SS_CONST
struct|struct
name|_ss_request_entry
block|{
name|__SS_CONST
name|char
modifier|*
name|__SS_CONST
modifier|*
name|command_names
decl_stmt|;
comment|/* whatever */
name|void
argument_list|(
argument|* __SS_CONST function
argument_list|)
name|__SS_PROTO
expr_stmt|;
comment|/* foo */
name|__SS_CONST
name|char
modifier|*
name|__SS_CONST
name|info_string
decl_stmt|;
comment|/* NULL */
name|int
name|flags
decl_stmt|;
comment|/* 0 */
block|}
name|ss_request_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__SS_CONST
struct|struct
name|_ss_request_table
block|{
name|int
name|version
decl_stmt|;
name|ss_request_entry
modifier|*
name|requests
decl_stmt|;
block|}
name|ss_request_table
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SS_RQT_TBL_V2
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ss_rp_options
block|{
comment|/* DEFAULT VALUES */
name|int
name|version
decl_stmt|;
comment|/* SS_RP_V1 */
name|void
argument_list|(
argument|*unknown
argument_list|)
name|__SS_PROTO
expr_stmt|;
comment|/* call for unknown command */
name|int
name|allow_suspend
decl_stmt|;
name|int
name|catch_int
decl_stmt|;
block|}
name|ss_rp_options
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SS_RP_V1
value|1
end_define

begin_define
define|#
directive|define
name|SS_OPT_DONT_LIST
value|0x0001
end_define

begin_define
define|#
directive|define
name|SS_OPT_DONT_SUMMARIZE
value|0x0002
end_define

begin_decl_stmt
name|void
name|ss_help
name|__SS_PROTO
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ss_current_request
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ss_name
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|ss_error
parameter_list|(
name|int
parameter_list|,
name|long
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ss_perror
parameter_list|(
name|int
parameter_list|,
name|long
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|ss_error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ss_perror
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ss_abort_subsystem
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|ss_request_table
name|ss_std_requests
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ss_h */
end_comment

end_unit

