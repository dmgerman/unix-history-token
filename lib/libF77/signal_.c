begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"f2c.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_typedef
typedef|typedef
name|VOID
function_decl|(
modifier|*
name|sig_pf
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|sig_pf
name|signal
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|signal1
value|signal
end_define

begin_decl_stmt
name|ftnint
name|signal_
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

begin_include
include|#
directive|include
file|"signal1.h"
end_include

begin_function
name|ftnint
name|signal_
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
name|ftnint
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

