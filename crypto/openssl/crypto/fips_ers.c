begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_FIPS
end_ifdef

begin_include
include|#
directive|include
file|"fips_err.h"
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|void
modifier|*
name|dummy
init|=
operator|&
name|dummy
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

