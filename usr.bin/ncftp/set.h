begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Set.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_set_h_
end_ifndef

begin_define
define|#
directive|define
name|_set_h_
end_define

begin_comment
comment|/*  $RCSfile: set.h,v $  *  $Revision: 14020.11 $  *  $Date: 93/06/26 06:21:32 $  */
end_comment

begin_comment
comment|/* Variable types. */
end_comment

begin_define
define|#
directive|define
name|INT
value|1
end_define

begin_define
define|#
directive|define
name|LONG
value|2
end_define

begin_define
define|#
directive|define
name|STR
value|3
end_define

begin_define
define|#
directive|define
name|BOOL
value|4
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|setvarproc
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|var
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|short
name|nmlen
decl_stmt|;
name|short
name|type
decl_stmt|;
name|short
name|conn_required
decl_stmt|;
name|void
modifier|*
name|var
decl_stmt|;
name|setvarproc
name|proc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VARENTRY
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|c
parameter_list|,
name|v
parameter_list|,
name|p
parameter_list|)
value|{ (n), (short)(sizeof(n) - 1), (t), (c), (v), (setvarproc)(p) }
end_define

begin_define
define|#
directive|define
name|NVARS
value|((int) (sizeof(vars)/sizeof(struct var)))
end_define

begin_function_decl
name|void
name|set_prompt
parameter_list|(
name|char
modifier|*
name|new
parameter_list|,
name|int
name|unset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_log
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|unset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_ldir
parameter_list|(
name|char
modifier|*
name|ldir
parameter_list|,
name|int
name|unset
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_function_decl
name|void
name|set_gateway
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_gatelogin
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|set_pager
parameter_list|(
name|char
modifier|*
name|new
parameter_list|,
name|int
name|unset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_verbose
parameter_list|(
name|char
modifier|*
name|new
parameter_list|,
name|int
name|unset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_type
parameter_list|(
name|char
modifier|*
name|newtype
parameter_list|,
name|int
name|unset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|var
modifier|*
name|match_var
parameter_list|(
name|char
modifier|*
name|varname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show_var
parameter_list|(
name|struct
name|var
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|show
parameter_list|(
name|char
modifier|*
name|varname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_show
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _set_h_ */
end_comment

end_unit

