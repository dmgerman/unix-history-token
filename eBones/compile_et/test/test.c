begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"test1.h"
end_include

begin_include
include|#
directive|include
file|"test2.h"
end_include

begin_function_decl
name|char
modifier|*
name|error_message
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|,
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"\nBefore initiating error table:\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Table name '%s'\n"
argument_list|,
name|error_table_name
argument_list|(
name|KRB_MK_AP_TGTEXP
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"UNIX  name '%s'\n"
argument_list|,
name|error_table_name
argument_list|(
name|EPERM
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg TGT-expired is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|KRB_MK_AP_TGTEXP
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg EPERM is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|EPERM
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg FOO_ERR is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|FOO_ERR
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg {sys_nerr-1} is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|sys_nerr
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg {sys_nerr} is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|sys_nerr
argument_list|)
argument_list|)
expr_stmt|;
name|init_error_table
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"With 0: tgt-expired -> %s\n"
argument_list|,
name|error_message
argument_list|(
name|KRB_MK_AP_TGTEXP
argument_list|)
argument_list|)
expr_stmt|;
name|init_krb_err_tbl
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"KRB error table initialized:  base %d (%s), name %s\n"
argument_list|,
name|krb_err_base
argument_list|,
name|error_message
argument_list|(
name|krb_err_base
argument_list|)
argument_list|,
name|error_table_name
argument_list|(
name|krb_err_base
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"With krb: tgt-expired -> %s\n"
argument_list|,
name|error_message
argument_list|(
name|KRB_MK_AP_TGTEXP
argument_list|)
argument_list|)
expr_stmt|;
name|init_quux_err_tbl
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"QUUX error table initialized: base %d (%s), name %s\n"
argument_list|,
name|quux_err_base
argument_list|,
name|error_message
argument_list|(
name|quux_err_base
argument_list|)
argument_list|,
name|error_table_name
argument_list|(
name|quux_err_base
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg for TGT-expired is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|KRB_MK_AP_TGTEXP
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg {sys_nerr-1} is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|sys_nerr
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg FOO_ERR is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|FOO_ERR
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg KRB_SKDC_CANT is '%s'\n"
argument_list|,
name|error_message
argument_list|(
name|KRB_SKDC_CANT
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Msg 1e6 is '%s'\n"
argument_list|,
name|error_message
argument_list|(
literal|1000000
argument_list|)
argument_list|)
expr_stmt|;
name|errno
operator|=
name|FOO_ERR
expr_stmt|;
name|perror
argument_list|(
literal|"FOO_ERR"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

