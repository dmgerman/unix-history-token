begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_DISABLE_MISSING_BRACES_WARNING_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_DISABLE_MISSING_BRACES_WARNING_H
end_define

begin_comment
comment|// std::array is explicitly allowed to be initialized with A a = { init-list };.
end_comment

begin_comment
comment|// Disable the missing braces warning for this reason.
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|diagnostic
name|ignored
literal|"-Wmissing-braces"
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_DISABLE_MISSING_BRACES_WARNING_H
end_comment

end_unit

