begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|D1
end_ifdef

begin_comment
comment|/*Line 3*/
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|D2
end_ifdef

begin_comment
comment|/*Line 7*/
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|A
end_ifdef

begin_comment
comment|/*Line 11*/
end_comment

begin_undef
undef|#
directive|undef
name|A
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

