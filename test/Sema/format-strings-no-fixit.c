begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fixit %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -o - %t | FileCheck %s
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. Only    warnings for format strings within the function call will be    fixed by -fixit.  Other format strings will be left alone. */
end_comment

begin_function_decl
name|int
name|printf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scanf
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|pr9751
parameter_list|()
block|{
specifier|const
name|char
name|kFormat1
index|[]
init|=
literal|"%s"
decl_stmt|;
name|printf
argument_list|(
name|kFormat1
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
specifier|const
name|char
name|kFormat2
index|[]
init|=
literal|"%.3p"
decl_stmt|;
name|void
modifier|*
name|p
decl_stmt|;
name|printf
argument_list|(
name|kFormat2
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%.3p"
argument_list|,
name|p
argument_list|)
expr_stmt|;
specifier|const
name|char
name|kFormat3
index|[]
init|=
literal|"%0s"
decl_stmt|;
name|printf
argument_list|(
name|kFormat3
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%0s"
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
specifier|const
name|char
name|kFormat4
index|[]
init|=
literal|"%hhs"
decl_stmt|;
name|printf
argument_list|(
name|kFormat4
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%hhs"
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
specifier|const
name|char
name|kFormat5
index|[]
init|=
literal|"%-0d"
decl_stmt|;
name|printf
argument_list|(
name|kFormat5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%-0d"
argument_list|,
literal|5
argument_list|)
expr_stmt|;
specifier|const
name|char
name|kFormat6
index|[]
init|=
literal|"%00d"
decl_stmt|;
name|int
modifier|*
name|i
decl_stmt|;
name|scanf
argument_list|(
name|kFormat6
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%00d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK:  const char kFormat1[] = "%s";
end_comment

begin_comment
comment|// CHECK:  printf(kFormat1, 5);
end_comment

begin_comment
comment|// CHECK:  printf("%d", 5);
end_comment

begin_comment
comment|// CHECK:  const char kFormat2[] = "%.3p";
end_comment

begin_comment
comment|// CHECK:  void *p;
end_comment

begin_comment
comment|// CHECK:  printf(kFormat2, p);
end_comment

begin_comment
comment|// CHECK:  printf("%p", p);
end_comment

begin_comment
comment|// CHECK:  const char kFormat3[] = "%0s";
end_comment

begin_comment
comment|// CHECK:  printf(kFormat3, "a");
end_comment

begin_comment
comment|// CHECK:  printf("%s", "a");
end_comment

begin_comment
comment|// CHECK:  const char kFormat4[] = "%hhs";
end_comment

begin_comment
comment|// CHECK:  printf(kFormat4, "a");
end_comment

begin_comment
comment|// CHECK:  printf("%s", "a");
end_comment

begin_comment
comment|// CHECK:  const char kFormat5[] = "%-0d";
end_comment

begin_comment
comment|// CHECK:  printf(kFormat5, 5);
end_comment

begin_comment
comment|// CHECK:  printf("%-d", 5);
end_comment

begin_comment
comment|// CHECK:  const char kFormat6[] = "%00d";
end_comment

begin_comment
comment|// CHECK:  int *i;
end_comment

begin_comment
comment|// CHECK:  scanf(kFormat6, i);
end_comment

begin_comment
comment|// CHECK:  scanf("%d", i);
end_comment

end_unit

