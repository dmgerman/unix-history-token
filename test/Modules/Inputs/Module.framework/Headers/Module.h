begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
specifier|const
name|char
modifier|*
name|getModuleVersion
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FOO
end_ifdef

begin_error
error|#
directive|error
error|Module should have been built without -DFOO
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|@
name|interface
name|Module
operator|+
operator|(
specifier|const
name|char
operator|*
operator|)
name|version
expr_stmt|;
end_expr_stmt

begin_comment
comment|// retrieve module version
end_comment

begin_expr_stmt
operator|+
name|alloc
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_define
define|#
directive|define
name|MODULE_H_MACRO
value|1
end_define

end_unit

