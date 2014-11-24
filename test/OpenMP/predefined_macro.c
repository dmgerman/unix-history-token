begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fopenmp=libiomp5 -verify -DFOPENMP -o - %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -o - %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOPENMP
end_ifdef

begin_comment
comment|// -fopenmp=libiomp5 option is specified
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENMP
end_ifndef

begin_error
error|#
directive|error
literal|"No _OPENMP macro is defined with -fopenmp option"
end_error

begin_empty
empty|#elsif _OPENMP != 201307
end_empty

begin_error
error|#
directive|error
literal|"_OPENMP has incorrect value"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_OPENMP
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// No -fopenmp=libiomp5 option is specified
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_OPENMP
end_ifdef

begin_error
error|#
directive|error
literal|"_OPENMP macro is defined without -fopenmp option"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _OPENMP
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FOPENMP
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fopenmp=libiomp5 -verify -DFOPENMP -o - %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -o - %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOPENMP
end_ifdef

begin_comment
comment|// -fopenmp=libiomp5 option is specified
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENMP
end_ifndef

begin_error
error|#
directive|error
literal|"No _OPENMP macro is defined with -fopenmp option"
end_error

begin_empty
empty|#elsif _OPENMP != 201307
end_empty

begin_error
error|#
directive|error
literal|"_OPENMP has incorrect value"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _OPENMP
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// No -fopenmp=libiomp5 option is specified
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_OPENMP
end_ifdef

begin_error
error|#
directive|error
literal|"_OPENMP macro is defined without -fopenmp option"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _OPENMP
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// FOPENMP
end_comment

end_unit

