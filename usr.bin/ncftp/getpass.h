begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Getpass.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_getpass_h_
end_ifndef

begin_define
define|#
directive|define
name|_getpass_h_
end_define

begin_comment
comment|/*  $RCSfile: getpass.h,v $  *  $Revision: 14020.11 $  *  $Date: 93/05/21 05:45:36 $  */
end_comment

begin_define
define|#
directive|define
name|kMaxPassLen
value|127
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GETPASS
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getpass
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Use the system supplied getpass. */
end_comment

begin_else
else|#
directive|else
end_else

begin_function_decl
name|char
modifier|*
name|Getpass
parameter_list|(
name|char
modifier|*
name|prompt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|Echo
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _getpass_h_ */
end_comment

begin_comment
comment|/* eof Getpass.h */
end_comment

end_unit

