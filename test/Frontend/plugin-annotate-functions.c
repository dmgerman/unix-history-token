begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fplugin=%llvmshlibdir/AnnotateFunctions%pluginext -emit-llvm -DPRAGMA_ON -S %s -o - | FileCheck %s --check-prefix=PRAGMA
end_comment

begin_comment
comment|// RUN: %clang -fplugin=%llvmshlibdir/AnnotateFunctions%pluginext -emit-llvm -S %s -o - | FileCheck %s --check-prefix=NOPRAGMA
end_comment

begin_comment
comment|// RUN: not %clang -fplugin=%llvmshlibdir/AnnotateFunctions%pluginext -emit-llvm -DBAD_PRAGMA -S %s -o - 2>&1 | FileCheck %s --check-prefix=BADPRAGMA
end_comment

begin_comment
comment|// REQUIRES: plugins, examples
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PRAGMA_ON
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|enable_annotate
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// BADPRAGMA: warning: extra tokens at end of #pragma directive
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BAD_PRAGMA
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|enable_annotate
name|something
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PRAGMA: [[STR_VAR:@.+]] = private unnamed_addr constant [19 x i8] c"example_annotation\00"
end_comment

begin_comment
comment|// PRAGMA: @llvm.global.annotations = {{.*}}@fn1{{.*}}[[STR_VAR]]{{.*}}@fn2{{.*}}[[STR_VAR]]
end_comment

begin_comment
comment|// NOPRAGMA-NOT: [[STR_VAR:@.+]] = private unnamed_addr constant [19 x i8] c"example_annotation\00"
end_comment

begin_comment
comment|// NOPRAGMA-NOT: @llvm.global.annotations = {{.*}}@fn1{{.*}}[[STR_VAR]]{{.*}}@fn2{{.*}}[[STR_VAR]]
end_comment

begin_function
name|void
name|fn1
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|fn2
parameter_list|()
block|{ }
end_function

begin_comment
comment|// BADPRAGMA: error: #pragma enable_annotate not allowed after declarations
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BAD_PRAGMA
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|enable_annotate
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

