begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: random.h,v 1.2 87/11/21 17:19:53 arnold Exp $ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|srandom
value|srand48
end_define

begin_define
define|#
directive|define
name|random
value|lrand48
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NO_RANDOM
end_ifdef

begin_undef
undef|#
directive|undef
name|NO_RANDOM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|srnd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|rnd
parameter_list|()
function_decl|;
end_function_decl

end_unit

