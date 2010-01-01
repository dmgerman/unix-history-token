begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly %s -DOPT_O2 -O2 -verify
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPT_O2
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__OPTIMIZE__
end_ifndef

begin_error
error|#
directive|error
literal|"__OPTIMIZE__ not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE_SIZE__
end_ifdef

begin_error
error|#
directive|error
literal|"__OPTIMIZE_SIZE__ defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: %clang_cc1 -Eonly %s -DOPT_O0 -O0 -verify
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPT_O0
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_error
error|#
directive|error
literal|"__OPTIMIZE__ defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE_SIZE__
end_ifdef

begin_error
error|#
directive|error
literal|"__OPTIMIZE_SIZE__ defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: %clang_cc1 -Eonly %s -DOPT_OS -Os -verify
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPT_OS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__OPTIMIZE__
end_ifndef

begin_error
error|#
directive|error
literal|"__OPTIMIZE__ not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE_SIZE__
end_ifdef

begin_error
error|#
directive|error
literal|"__OPTIMIZE_SIZE__ not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

