begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|E_H
end_ifndef

begin_define
define|#
directive|define
name|E_H
end_define

begin_define
define|#
directive|define
name|HEADER
value|"a.h"
end_define

begin_include
include|#
directive|include
include|HEADER
end_include

begin_include
include|#
directive|include
file|"b.h"
end_include

begin_decl_stmt
specifier|const
name|int
name|e
init|=
name|a
operator|*
name|b
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

