begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Defining TRUE and FALSE is usually a Bad Idea,
end_comment

begin_comment
comment|// because you will probably be inconsistent with anyone
end_comment

begin_comment
comment|// else who had the same clever idea.
end_comment

begin_comment
comment|// Therefore:  DON'T USE THIS FILE.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_bool_h
end_ifndef

begin_define
define|#
directive|define
name|_bool_h
value|1
end_define

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_enum
enum|enum
name|bool
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

