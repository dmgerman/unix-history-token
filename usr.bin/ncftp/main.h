begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* main.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_main_h_
end_ifndef

begin_define
define|#
directive|define
name|_main_h_
end_define

begin_comment
comment|/*  $RCSfile: main.h,v $  *  $Revision: 14020.12 $  *  $Date: 93/05/21 05:45:33 $  */
end_comment

begin_struct
struct|struct
name|userinfo
block|{
name|str32
name|username
decl_stmt|;
name|string
name|homedir
decl_stmt|;
name|string
name|shell
decl_stmt|;
name|string
name|hostname
decl_stmt|;
name|int
name|uid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|intr
name|SIG_PARAMS
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|getuserinfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|init_arrays
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_transfer_buffer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_prompt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|lostpeer
name|SIG_PARAMS
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cmdscanner
parameter_list|(
name|int
name|top
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strprompt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makeargv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|slurpstring
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|help
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
name|void
name|trim_log
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CheckNewMail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CURSES
end_ifdef

begin_function_decl
name|void
name|tcap_put
parameter_list|(
name|char
modifier|*
name|cap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|termcap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|termcap_get
parameter_list|(
name|char
modifier|*
modifier|*
name|dest
parameter_list|,
name|char
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|TERMH
end_ifndef

begin_comment
comment|/*<term.h> would take care of this. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_CONST
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgetstr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|tgetstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TERMH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CURSES */
end_comment

begin_comment
comment|/* Should be in a 'tips.h,' but... */
end_comment

begin_function_decl
name|void
name|PrintTip
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _main_h_ */
end_comment

end_unit

