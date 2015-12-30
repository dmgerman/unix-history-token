begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -index-file %s -target i686-pc-linux \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix CHECK -check-prefix CHECK-LINUX
end_comment

begin_comment
comment|// RUN: c-index-test -index-file -Wno-unsupported-visibility %s -target i386-darwin \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s -check-prefix CHECK -check-prefix CHECK-DARWIN
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"default"
argument_list|)
operator|)
argument_list|)
name|default_visibility
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:<attribute>: attribute(visibility)=default
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"hidden"
argument_list|)
operator|)
argument_list|)
name|hidden_visibility
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:<attribute>: attribute(visibility)=hidden
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|visibility
argument_list|(
literal|"protected"
argument_list|)
operator|)
argument_list|)
name|protected_visibility
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LINUX:<attribute>: attribute(visibility)=protected
end_comment

begin_comment
comment|// CHECK-DARWIN:<attribute>: attribute(visibility)=default
end_comment

end_unit

