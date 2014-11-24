begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|cool
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|cool
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|really_cool
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// really_cool
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|hot
argument_list|)
end_elif

begin_comment
comment|// hot
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// trailing comment
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|cool
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|uncool
end_ifndef

begin_decl_stmt
name|int
name|probably_hot
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// uncool
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// cool
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_SHOW_SKIPPED_RANGES=1 c-index-test -test-annotate-tokens=%s:1:1:16:1 %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Skipping: [5:2 - 6:7]
end_comment

begin_comment
comment|// CHECK: Skipping: [8:2 - 12:7]
end_comment

begin_comment
comment|// CHECK: Skipping: [14:2 - 20:7]
end_comment

end_unit

