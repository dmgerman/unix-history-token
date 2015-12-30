begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|var
name|__attribute__
argument_list|(
operator|(
name|internal_linkage
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|var2
name|__attribute__
argument_list|(
operator|(
name|internal_linkage
operator|,
name|common
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'internal_linkage' and 'common' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note{{conflicting attribute is here}}
end_comment

begin_decl_stmt
name|int
name|var3
name|__attribute__
argument_list|(
operator|(
name|common
operator|,
name|internal_linkage
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'common' and 'internal_linkage' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note{{conflicting attribute is here}}
end_comment

begin_decl_stmt
name|int
name|var4
name|__attribute__
argument_list|(
operator|(
name|common
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'common' and 'internal_linkage' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note{{previous definition is here}}
end_comment

begin_decl_stmt
name|int
name|var4
name|__attribute__
argument_list|(
operator|(
name|internal_linkage
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{conflicting attribute is here}} \
end_comment

begin_comment
comment|// expected-error{{'internal_linkage' attribute does not appear on the first declaration of 'var4'}}
end_comment

begin_decl_stmt
name|int
name|var5
name|__attribute__
argument_list|(
operator|(
name|internal_linkage
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'internal_linkage' and 'common' attributes are not compatible}}
end_comment

begin_decl_stmt
name|int
name|var5
name|__attribute__
argument_list|(
operator|(
name|common
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note{{conflicting attribute is here}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(internal_linkage)
argument_list|)
end_macro

begin_function
name|int
name|f
parameter_list|()
block|{}
end_function

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(internal_linkage)
argument_list|)
name|S
block|{
comment|// expected-warning{{'internal_linkage' attribute only applies to variables and functions}}
block|}
struct|;
end_struct

begin_macro
name|__attribute__
argument_list|(
argument|(internal_linkage(
literal|"foo"
argument|))
argument_list|)
end_macro

begin_function
name|int
name|g
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-error{{'internal_linkage' attribute takes no arguments}}
end_comment

end_unit

