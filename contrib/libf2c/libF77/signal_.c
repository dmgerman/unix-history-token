begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_include
include|#
directive|include
file|"signal1.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_decl_stmt
name|void
modifier|*
name|G77_signal_0
argument_list|(
name|sigp
argument_list|,
name|proc
argument_list|)
name|integer
modifier|*
name|sigp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|sig_pf
name|proc
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|void
modifier|*
name|G77_signal_0
parameter_list|(
name|integer
modifier|*
name|sigp
parameter_list|,
name|sig_pf
name|proc
parameter_list|)
endif|#
directive|endif
block|{
name|int
name|sig
decl_stmt|;
name|sig
operator|=
operator|(
name|int
operator|)
operator|*
name|sigp
expr_stmt|;
return|return
operator|(
name|void
operator|*
operator|)
name|signal
argument_list|(
name|sig
argument_list|,
name|proc
argument_list|)
return|;
block|}
end_function

end_unit

