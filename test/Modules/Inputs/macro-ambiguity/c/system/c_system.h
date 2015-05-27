begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|C_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|C_SYSTEM_H
end_define

begin_comment
comment|// FIXME: We have to use this to mark the header as a system header in
end_comment

begin_comment
comment|// a module because header search didn't actually occur and so we can't have
end_comment

begin_comment
comment|// found the header via system header search, even though when we map to this
end_comment

begin_comment
comment|// header and load the module we will have mapped to the header by finding it
end_comment

begin_comment
comment|// via system header search.
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_define
define|#
directive|define
name|FOO1_SYSTEM
parameter_list|(
name|x
parameter_list|)
value|2 * x
end_define

begin_define
define|#
directive|define
name|FOO2_SYSTEM
parameter_list|(
name|x
parameter_list|)
value|2 * x
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

