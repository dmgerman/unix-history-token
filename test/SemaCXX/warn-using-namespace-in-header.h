begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Lots of vertical space to make the error line match up with the line of the
end_comment

begin_comment
comment|// expected line in the source file.
end_comment

begin_decl_stmt
name|namespace
name|warn_in_header_in_global_context
block|{}
end_decl_stmt

begin_decl_stmt
name|using
name|namespace
name|warn_in_header_in_global_context
decl_stmt|;
end_decl_stmt

begin_comment
comment|// While we want to error on the previous using directive, we don't when we are
end_comment

begin_comment
comment|// inside a namespace
end_comment

begin_decl_stmt
name|namespace
name|dont_warn_here
block|{
name|using
name|namespace
name|warn_in_header_in_global_context
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// We should warn in toplevel extern contexts.
end_comment

begin_decl_stmt
name|namespace
name|warn_inside_linkage
block|{}
end_decl_stmt

begin_extern
extern|extern
literal|"C++"
block|{
name|using
name|namespace
name|warn_inside_linkage
decl_stmt|;
block|}
end_extern

begin_comment
comment|// This is really silly, but we should warn on it:
end_comment

begin_extern
extern|extern
literal|"C++"
block|{
extern|extern
literal|"C"
block|{
extern|extern
literal|"C++"
block|{
name|using
name|namespace
name|warn_inside_linkage
decl_stmt|;
block|}
block|}
block|}
end_extern

begin_comment
comment|// But we shouldn't warn in extern contexts inside namespaces.
end_comment

begin_decl_stmt
name|namespace
name|dont_warn_here
block|{
extern|extern
literal|"C++"
block|{
name|using
name|namespace
name|warn_in_header_in_global_context
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// We also shouldn't warn in case of functions.
end_comment

begin_function
specifier|inline
name|void
name|foo
parameter_list|()
block|{
name|using
name|namespace
name|warn_in_header_in_global_context
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|namespace
name|macronamespace
block|{}
end_decl_stmt

begin_define
define|#
directive|define
name|USING_MACRO
value|using namespace macronamespace;
end_define

begin_comment
comment|// |using namespace| through a macro should warn if the instantiation is in a
end_comment

begin_comment
comment|// header.
end_comment

begin_macro
name|USING_MACRO
end_macro

end_unit

