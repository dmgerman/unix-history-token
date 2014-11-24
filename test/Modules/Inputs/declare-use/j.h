begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|J_H
end_ifndef

begin_define
define|#
directive|define
name|J_H
end_define

begin_define
define|#
directive|define
name|STR
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|HDR
parameter_list|(
name|x
parameter_list|)
value|STR(x.h)
end_define

begin_include
include|#
directive|include
include|ALLOWED_INC
end_include

begin_include
include|#
directive|include
include|HDR(a)
end_include

begin_decl_stmt
specifier|const
name|int
name|j
init|=
name|a
operator|*
name|a
operator|+
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

