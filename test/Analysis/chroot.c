begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=alpha.unix.Chroot -analyzer-store region -verify %s
end_comment

begin_function_decl
specifier|extern
name|int
name|chroot
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|chdir
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|f1
parameter_list|(
name|void
parameter_list|)
block|{
name|chroot
argument_list|(
literal|"/usr/local"
argument_list|)
expr_stmt|;
comment|// root changed.
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning {{No call of chdir("/") immediately after chroot}}
block|}
end_function

begin_function
name|void
name|f2
parameter_list|(
name|void
parameter_list|)
block|{
name|chroot
argument_list|(
literal|"/usr/local"
argument_list|)
expr_stmt|;
comment|// root changed.
name|chdir
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
comment|// enter the jail.
name|foo
argument_list|()
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
name|chroot
argument_list|(
literal|"/usr/local"
argument_list|)
expr_stmt|;
comment|// root changed.
name|chdir
argument_list|(
literal|"../"
argument_list|)
expr_stmt|;
comment|// change working directory, still out of jail.
name|foo
argument_list|()
expr_stmt|;
comment|// expected-warning {{No call of chdir("/") immediately after chroot}}
block|}
end_function

end_unit

