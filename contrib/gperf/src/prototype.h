begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_prototype_h
end_ifndef

begin_define
define|#
directive|define
name|_prototype_h
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|X
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|ODD
parameter_list|(
name|X
parameter_list|)
value|((X)& 1)
end_define

begin_define
define|#
directive|define
name|EVEN
parameter_list|(
name|X
parameter_list|)
value|(!((X)& 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _prototype_h */
end_comment

end_unit

