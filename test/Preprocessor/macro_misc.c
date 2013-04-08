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

begin_comment
comment|// RUN: %clang_cc1 -fms-extensions -DMS_EXT %s -Eonly -verify
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MS_EXT
end_ifndef

begin_comment
comment|// This should under C99.
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a+b)
end_define

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x+y)
end_define

begin_comment
comment|// expected-warning {{'FUNC_LIKE4' macro redefined}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// This shouldn't under MS extensions.
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a+b)
end_define

begin_define
define|#
directive|define
name|FUNC_LIKE4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x+y)
end_define

begin_comment
comment|// This should.
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE5
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a+b)
end_define

begin_comment
comment|// expected-note {{previous definition is here}}
end_comment

begin_define
define|#
directive|define
name|FUNC_LIKE5
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(y+x)
end_define

begin_comment
comment|// expected-warning {{'FUNC_LIKE5' macro redefined}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

