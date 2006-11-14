begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* test.h */
end_comment

begin_comment
comment|/* $Id: test.h,v 1.1 2001/09/17 19:07:00 bodo Exp $ */
end_comment

begin_function_decl
name|void
name|test_process_init
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|client_p
parameter_list|,
name|void
modifier|*
name|apparg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TLS_APP_PROCESS_INIT
value|test_process_init
end_define

begin_undef
undef|#
directive|undef
name|TLS_CUMULATE_ERRORS
end_undef

begin_function_decl
name|void
name|test_errflush
parameter_list|(
name|int
name|child_p
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|size_t
name|num
parameter_list|,
name|void
modifier|*
name|apparg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TLS_APP_ERRFLUSH
value|test_errflush
end_define

end_unit

