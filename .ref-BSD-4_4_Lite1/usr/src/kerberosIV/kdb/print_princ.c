begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/kdb/RCS/print_princ.c,v $  * $Author: bostic $   *  * Copyright 1988 by the Massachusetts Institute of Technology.   *  * For copying and distribution information, please see the file  *<mit-copyright.h>.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_print_principal_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/kdb/RCS/print_princ.c,v 4.8 91/02/25 15:18:39 bostic Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<krb_db.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tm
modifier|*
name|time_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|kerb_debug
decl_stmt|;
end_decl_stmt

begin_macro
name|krb_print_principal
argument_list|(
argument|a_n
argument_list|)
end_macro

begin_decl_stmt
name|Principal
modifier|*
name|a_n
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* run-time database does not contain string versions */
name|time_p
operator|=
name|localtime
argument_list|(
operator|(
name|time_t
operator|*
operator|)
operator|&
operator|(
name|a_n
operator|->
name|exp_date
operator|)
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n%s %s expires %4d-%2d-%2d %2d:%2d, max_life %d*5 = %d min  attr 0x%02x"
argument_list|,
name|a_n
operator|->
name|name
argument_list|,
name|a_n
operator|->
name|instance
argument_list|,
name|time_p
operator|->
name|tm_year
operator|>
literal|1900
condition|?
name|time_p
operator|->
name|tm_year
else|:
name|time_p
operator|->
name|tm_year
operator|+
literal|1900
argument_list|,
name|time_p
operator|->
name|tm_mon
operator|+
literal|1
argument_list|,
name|time_p
operator|->
name|tm_mday
argument_list|,
name|time_p
operator|->
name|tm_hour
argument_list|,
name|time_p
operator|->
name|tm_min
argument_list|,
name|a_n
operator|->
name|max_life
argument_list|,
literal|5
operator|*
name|a_n
operator|->
name|max_life
argument_list|,
name|a_n
operator|->
name|attributes
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n\tkey_ver %d  k_low 0x%08x  k_high 0x%08x  akv %d  exists %d\n"
argument_list|,
name|a_n
operator|->
name|key_version
argument_list|,
name|a_n
operator|->
name|key_low
argument_list|,
name|a_n
operator|->
name|key_high
argument_list|,
name|a_n
operator|->
name|kdc_key_ver
argument_list|,
name|a_n
operator|->
name|old
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

