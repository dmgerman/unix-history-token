begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: $FreeBSD$  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
endif|lint
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
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

begin_decl_stmt
name|long
name|kerb_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|tm
modifier|*
name|time_p
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|krb_print_principal
parameter_list|(
name|a_n
parameter_list|)
name|Principal
modifier|*
name|a_n
decl_stmt|;
block|{
comment|/* run-time database does not contain string versions */
name|time_p
operator|=
name|localtime
argument_list|(
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
literal|"\n\tkey_ver %d  k_low 0x%08lx  k_high 0x%08lx  akv %d  exists %d\n"
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
operator|(
name|int
operator|)
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
end_function

end_unit

