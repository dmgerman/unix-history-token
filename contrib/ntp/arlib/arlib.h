begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * arlib.h (C)opyright 1992 Darren Reed.  */
end_comment

begin_define
define|#
directive|define
name|ARES_INITLIST
value|1
end_define

begin_define
define|#
directive|define
name|ARES_CALLINIT
value|2
end_define

begin_define
define|#
directive|define
name|ARES_INITSOCK
value|4
end_define

begin_define
define|#
directive|define
name|ARES_INITDEBG
value|8
end_define

begin_define
define|#
directive|define
name|ARES_INITCACH
value|16
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|hostent
modifier|*
name|ar_answer
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_delete
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_gethostbyname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_gethostbyaddr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|ar_timeout
parameter_list|(
name|time_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|struct
name|hostent
modifier|*
name|ar_answer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ar_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_gethostbyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_gethostbyaddr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ar_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|ar_timeout
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

