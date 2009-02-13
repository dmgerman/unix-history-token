begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|__IEEEFP_NOINLINES__
value|1
end_define

begin_include
include|#
directive|include
file|<ieeefp.h>
end_include

begin_function
name|fp_prec_t
name|fpgetprec
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__fpgetprec
argument_list|()
return|;
block|}
end_function

end_unit

