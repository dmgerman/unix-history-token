begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|H_H
end_ifndef

begin_define
define|#
directive|define
name|H_H
end_define

begin_include
include|#
directive|include
file|"c.h"
end_include

begin_include
include|#
directive|include
file|"d.h"
end_include

begin_comment
comment|// expected-error {{does not depend on a module exporting}}
end_comment

begin_include
include|#
directive|include
file|"h1.h"
end_include

begin_decl_stmt
specifier|const
name|int
name|h1
init|=
name|aux_h
operator|*
name|c
operator|*
literal|7
operator|*
name|d
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

