begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|DEFS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NATIVE_WINDOWS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FALSE
end_ifdef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUE
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NATIVE_WINDOWS */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
name|Boolean
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEFS_H */
end_comment

end_unit

