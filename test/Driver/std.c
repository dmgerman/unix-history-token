begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -w -std=c99 -trigraphs -std=gnu99 %s -E -o - | FileCheck -check-prefix=OVERRIDE %s
end_comment

begin_comment
comment|// OVERRIDE: ??(??)
end_comment

begin_comment
comment|// RUN: %clang -w -std=c99 -trigraphs -std=gnu99 %s -E -o - | FileCheck -check-prefix=FOVERRIDE %s
end_comment

begin_comment
comment|// FOVERRIDE: ??(??)
end_comment

begin_comment
comment|// RUN: %clang -w -ansi %s -E -o - | FileCheck -check-prefix=ANSI %s
end_comment

begin_comment
comment|// ANSI: []
end_comment

begin_comment
comment|// RUN: %clang -w -ansi %s -fno-trigraphs -E -o - | FileCheck -check-prefix=ANSI-OVERRIDE %s
end_comment

begin_comment
comment|// ANSI-OVERRIDE: ??(??)
end_comment

begin_comment
comment|// RUN: %clang -w -std=gnu99 -trigraphs %s -E -o - | FileCheck -check-prefix=EXPLICIT %s
end_comment

begin_comment
comment|// EXPLICIT: []
end_comment

begin_comment
comment|// RUN: %clang -w -std=gnu99 -ftrigraphs %s -E -o - | FileCheck -check-prefix=FEXPLICIT %s
end_comment

begin_comment
comment|// FEXPLICIT: []
end_comment

begin_comment
comment|// RUN: %clang -w -ftrigraphs -fno-trigraphs %s -E -o - | FileCheck -check-prefix=ONOFF %s
end_comment

begin_comment
comment|// ONOFF: ??(??)
end_comment

begin_comment
comment|// RUN: %clang -w -fno-trigraphs -trigraphs %s -E -o - | FileCheck -check-prefix=OFFFON %s
end_comment

begin_comment
comment|// OFFFON: []
end_comment

begin_expr_stmt
operator|??
operator|(
operator|??
operator|)
end_expr_stmt

end_unit

