begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This case came up when using PTH with Boost (<rdar://problem/8227989>).
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R8227989_PREPROCESSOR_CONFIG_CONFIG_HPP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|R8227989_PP_CONFIG_FLAGS
end_ifndef

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#
end_empty

begin_ifndef
ifndef|#
directive|ifndef
name|R8227989_PP_CONFIG_ERRORS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NDEBUG
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

