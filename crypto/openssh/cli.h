begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: cli.h,v 1.2 2000/10/16 09:38:44 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLI_H
end_ifndef

begin_define
define|#
directive|define
name|CLI_H
end_define

begin_comment
comment|/*  * Presents a prompt and returns the response allocated with xmalloc().  * Uses /dev/tty or stdin/out depending on arg.  Optionally disables echo  * of response depending on arg.  Tries to ensure that no other userland  * buffer is storing the response.  */
end_comment

begin_function_decl
name|char
modifier|*
name|cli_read_passphrase
parameter_list|(
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|from_stdin
parameter_list|,
name|int
name|echo_enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cli_prompt
parameter_list|(
name|char
modifier|*
name|prompt
parameter_list|,
name|int
name|echo_enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cli_mesg
parameter_list|(
name|char
modifier|*
name|mesg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLI_H */
end_comment

end_unit

