begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Eonly -verify
end_comment

begin_comment
comment|// This should not be rejected.
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|defined
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PR3764
end_comment

begin_comment
comment|// This should not produce a redefinition warning.
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|FUNC_LIKE
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_comment
comment|// This either.
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE2
parameter_list|(
name|a
parameter_list|)
define|\
value|(a)
end_define

begin_define
define|#
directive|define
name|FUNC_LIKE2
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_comment
comment|// This should.
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE3
parameter_list|(
name|a
parameter_list|)
value|( a)
end_define

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE3
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_comment
comment|// expected-warning {{'FUNC_LIKE3' macro redefined}}
end_comment

end_unit

