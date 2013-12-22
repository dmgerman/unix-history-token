begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: mkdir -p %t.h.gch
end_comment

begin_comment
comment|// RUN: %clang -x c-header %S/pch-dir.h -DFOO=foo -o %t.h.gch/c.gch
end_comment

begin_comment
comment|// RUN: %clang -x c-header %S/pch-dir.h -DFOO=bar -o %t.h.gch/cbar.gch
end_comment

begin_comment
comment|// RUN: %clang -x c++-header -std=c++98 %S/pch-dir.h -o %t.h.gch/cpp.gch
end_comment

begin_comment
comment|// RUN: %clang -include %t.h -DFOO=foo -fsyntax-only %s -Xclang -print-stats 2> %t.clog
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-C %s< %t.clog
end_comment

begin_comment
comment|// RUN: %clang -include %t.h -DFOO=bar -DBAR=bar -fsyntax-only %s -Xclang -ast-print> %t.cbarlog
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-CBAR %s< %t.cbarlog
end_comment

begin_comment
comment|// RUN: %clang -x c++ -include %t.h -std=c++98 -fsyntax-only %s -Xclang -print-stats 2> %t.cpplog
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-CPP %s< %t.cpplog
end_comment

begin_comment
comment|// RUN: not %clang -x c++ -std=c++11 -include %t.h -fsyntax-only %s 2> %t.cpp11log
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-CPP11 %s< %t.cpp11log
end_comment

begin_comment
comment|// CHECK-CBAR: int bar
end_comment

begin_decl_stmt
name|int
name|FOO
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|get
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|__cplusplus
comment|// CHECK-CPP: .h.gch{{[/\\]}}cpp.gch
return|return
name|i
return|;
else|#
directive|else
comment|// CHECK-C: .h.gch{{[/\\]}}c.gch
return|return
name|j
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|// CHECK-CPP11: no suitable precompiled header file found in directory
end_comment

end_unit

