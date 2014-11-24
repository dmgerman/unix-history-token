begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|DefinedInBImpl
block|{
name|void
name|f
parameter_list|()
function_decl|;
struct|struct
name|Inner
block|{}
struct|;
name|friend
name|void
name|FoundByADL
parameter_list|(
name|DefinedInBImpl
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
unit|@
name|import
name|cxx_templates_common
decl_stmt|;
end_decl_stmt

begin_macro
name|template
end_macro

begin_expr_stmt
unit|struct
name|TemplateInstantiationVisibility
operator|<
name|char
index|[
literal|1
index|]
operator|>
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern template struct TemplateInstantiationVisibility<char[2]>;
end_extern

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|TemplateInstantiationVisibility
operator|<
name|char
index|[
literal|3
index|]
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern TemplateInstantiationVisibility<char[4]>::type     TemplateInstantiationVisibility_ImplicitInstantiation;
end_extern

end_unit

