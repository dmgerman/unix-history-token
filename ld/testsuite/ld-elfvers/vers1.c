begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Basic test of versioning.  The idea with this is that we define  * a bunch of definitions of the same symbol, and we can theoretically  * then link applications against varying sets of these.  */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|show_bar1
init|=
literal|"asdf"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|show_bar2
init|=
literal|"asdf"
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|new2_foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bar33
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|bar
parameter_list|()
block|{
return|return
literal|3
return|;
block|}
end_function

begin_comment
comment|/*  * The 'hide' prefix is something so that we can automatically search the  * symbol table and verify that none of these symbols were actually exported.  */
end_comment

begin_function
name|int
name|hide_original_foo
parameter_list|()
block|{
return|return
literal|1
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|hide_old_foo
parameter_list|()
block|{
return|return
literal|10
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|hide_old_foo1
parameter_list|()
block|{
return|return
literal|100
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|hide_new_foo
parameter_list|()
block|{
return|return
literal|1000
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_asm
asm|__asm__(".symver hide_original_foo,show_foo@");
end_asm

begin_asm
asm|__asm__(".symver hide_old_foo,show_foo@VERS_1.1");
end_asm

begin_asm
asm|__asm__(".symver hide_old_foo1,show_foo@VERS_1.2");
end_asm

begin_asm
asm|__asm__(".symver hide_new_foo,show_foo@@VERS_2.0");
end_asm

begin_ifdef
ifdef|#
directive|ifdef
name|DO_TEST10
end_ifdef

begin_comment
comment|/* In test 10, we try and define a non-existant version node.  The linker  * should catch this and complain. */
end_comment

begin_function
name|int
name|hide_new_bogus_foo
parameter_list|()
block|{
return|return
literal|1000
operator|+
name|bar
argument_list|()
return|;
block|}
end_function

begin_asm
asm|__asm__(".symver hide_new_bogus_foo,show_foo@VERS_2.2");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DO_TEST11
end_ifdef

begin_comment
comment|/*  * This test is designed to catch a couple of syntactic errors.  The assembler  * should complain about both of the directives below.  */
end_comment

begin_function
name|void
name|xyzzz
parameter_list|()
block|{
name|new2_foo
argument_list|()
expr_stmt|;
name|bar33
argument_list|()
expr_stmt|;
block|}
end_function

begin_asm
asm|__asm__(".symver new2_foo,fooVERS_2.0");
end_asm

begin_asm
asm|__asm__(".symver bar33,bar@@VERS_2.0");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DO_TEST12
end_ifdef

begin_comment
comment|/*  * This test is designed to catch a couple of syntactic errors.  The assembler  * should complain about both of the directives below.  */
end_comment

begin_function
name|void
name|xyzzz
parameter_list|()
block|{
name|new2_foo
argument_list|()
expr_stmt|;
name|bar33
argument_list|()
expr_stmt|;
block|}
end_function

begin_asm
asm|__asm__(".symver bar33,bar@@VERS_2.0");
end_asm

begin_endif
endif|#
directive|endif
end_endif

end_unit

