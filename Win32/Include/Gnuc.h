begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inline foo */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

