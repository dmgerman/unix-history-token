begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -pedantic -Wall -fixit %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -pedantic -Wall -Werror %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -o - %t | FileCheck %s
end_comment

begin_comment
comment|/* This is a test of the various code modification hints that are    provided as part of warning or extension diagnostics. All of the    warnings will be fixed by -fixit, and the resulting file should    compile cleanly with -Werror -pedantic. */
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

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__INTMAX_TYPE__
name|intmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__UINTMAX_TYPE__
name|uintmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__PTRDIFF_TYPE__
name|ptrdiff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__WCHAR_TYPE__
name|wchar_t
typedef|;
end_typedef

begin_function
name|void
name|test
parameter_list|()
block|{
comment|// Basic types
name|printf
argument_list|(
literal|"%s"
argument_list|,
operator|(
name|int
operator|)
literal|123
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"abc%0f"
argument_list|,
literal|"testing testing 123"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%u"
argument_list|,
operator|(
name|long
operator|)
operator|-
literal|12
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%p"
argument_list|,
literal|123
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
literal|"x"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%c\n"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// Larger types
name|printf
argument_list|(
literal|"%+.2d"
argument_list|,
operator|(
name|unsigned
name|long
name|long
operator|)
literal|123456
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%1d"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|1.23
argument_list|)
expr_stmt|;
comment|// Flag handling
name|printf
argument_list|(
literal|"%0+s"
argument_list|,
operator|(
name|unsigned
operator|)
literal|31337
argument_list|)
expr_stmt|;
comment|// 0 flag should stay
name|printf
argument_list|(
literal|"%#p"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"% +f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// + flag should stay
name|printf
argument_list|(
literal|"%0-f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// - flag should stay
comment|// Positional arguments
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
comment|// Don't warn about using positional arguments.
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wformat-non-iso"
name|printf
argument_list|(
literal|"%1$f:%2$.*3$f:%4$.*3$f\n"
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
comment|// Precision
name|printf
argument_list|(
literal|"%10.5d"
argument_list|,
literal|1l
argument_list|)
expr_stmt|;
comment|// (bug 7394)
name|printf
argument_list|(
literal|"%.2c"
argument_list|,
literal|'a'
argument_list|)
expr_stmt|;
comment|// Ignored flags
name|printf
argument_list|(
literal|"%0-f"
argument_list|,
literal|1.23
argument_list|)
expr_stmt|;
comment|// Bad length modifiers
name|printf
argument_list|(
literal|"%hhs"
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
pragma|#
directive|pragma
name|clang
name|diagnostic
name|push
comment|// Don't warn about using positional arguments.
pragma|#
directive|pragma
name|clang
name|diagnostic
name|ignored
literal|"-Wformat-non-iso"
name|printf
argument_list|(
literal|"%1$zp"
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
pragma|#
directive|pragma
name|clang
name|diagnostic
name|pop
comment|// Preserve the original formatting for unsigned integers.
name|unsigned
name|long
name|val
init|=
literal|42
decl_stmt|;
name|printf
argument_list|(
literal|"%X"
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|// size_t, etc.
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|size_t
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|intmax_t
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|uintmax_t
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|ptrdiff_t
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// Look beyond the first typedef.
typedef|typedef
name|size_t
name|my_size_type
typedef|;
typedef|typedef
name|intmax_t
name|my_intmax_type
typedef|;
typedef|typedef
name|uintmax_t
name|my_uintmax_type
typedef|;
typedef|typedef
name|ptrdiff_t
name|my_ptrdiff_type
typedef|;
typedef|typedef
name|int
name|my_int_type
typedef|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_size_type
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_intmax_type
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_uintmax_type
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_ptrdiff_type
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_int_type
operator|)
literal|42
argument_list|)
expr_stmt|;
comment|// string
name|printf
argument_list|(
literal|"%ld"
argument_list|,
literal|"foo"
argument_list|)
expr_stmt|;
comment|// Preserve the original choice of conversion specifier.
name|printf
argument_list|(
literal|"%o"
argument_list|,
operator|(
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%u"
argument_list|,
operator|(
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%x"
argument_list|,
operator|(
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%X"
argument_list|,
operator|(
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%i"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%d"
argument_list|,
operator|(
name|unsigned
name|long
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%F"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%e"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%E"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%g"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%G"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%a"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%A"
argument_list|,
operator|(
name|long
name|double
operator|)
literal|42
argument_list|)
expr_stmt|;
block|}
end_function

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
name|test2
parameter_list|(
name|int
name|intSAParm
index|[
specifier|static
literal|2
index|]
parameter_list|)
block|{
name|char
name|str
index|[
literal|100
index|]
decl_stmt|;
name|char
modifier|*
name|vstr
init|=
literal|"abc"
decl_stmt|;
name|short
name|shortVar
decl_stmt|;
name|unsigned
name|short
name|uShortVar
decl_stmt|;
name|int
name|intVar
decl_stmt|;
name|int
name|intAVar
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|uIntVar
decl_stmt|;
name|float
name|floatVar
decl_stmt|;
name|double
name|doubleVar
decl_stmt|;
name|long
name|double
name|longDoubleVar
decl_stmt|;
name|long
name|longVar
decl_stmt|;
name|unsigned
name|long
name|uLongVar
decl_stmt|;
name|long
name|long
name|longLongVar
decl_stmt|;
name|unsigned
name|long
name|long
name|uLongLongVar
decl_stmt|;
name|size_t
name|sizeVar
decl_stmt|;
name|intmax_t
name|intmaxVar
decl_stmt|;
name|uintmax_t
name|uIntmaxVar
decl_stmt|;
name|ptrdiff_t
name|ptrdiffVar
decl_stmt|;
enum|enum
block|{
name|A
block|,
name|B
block|,
name|C
block|}
name|enumVar
enum|;
comment|// Some string types.
name|scanf
argument_list|(
literal|"%lf"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%lf"
argument_list|,
name|vstr
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%ls"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%ls"
argument_list|,
name|str
argument_list|)
expr_stmt|;
comment|// Some integer types.
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|shortVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|uShortVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%p"
argument_list|,
operator|&
name|intVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
name|intAVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
name|intSAParm
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%Lf"
argument_list|,
operator|&
name|uIntVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%ld"
argument_list|,
operator|&
name|floatVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|doubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|longVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|uLongVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|longLongVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|uLongLongVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|&
name|enumVar
argument_list|)
expr_stmt|;
comment|// FIXME: We ought to fix specifiers for enums.
comment|// Some named ints.
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|sizeVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|intmaxVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|uIntmaxVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|&
name|ptrdiffVar
argument_list|)
expr_stmt|;
comment|// Look beyond the first typedef for named integer types.
typedef|typedef
name|size_t
name|my_size_type
typedef|;
typedef|typedef
name|intmax_t
name|my_intmax_type
typedef|;
typedef|typedef
name|uintmax_t
name|my_uintmax_type
typedef|;
typedef|typedef
name|ptrdiff_t
name|my_ptrdiff_type
typedef|;
typedef|typedef
name|int
name|my_int_type
typedef|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_size_type
operator|*
operator|)
operator|&
name|sizeVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_intmax_type
operator|*
operator|)
operator|&
name|intmaxVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_uintmax_type
operator|*
operator|)
operator|&
name|uIntmaxVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_ptrdiff_type
operator|*
operator|)
operator|&
name|ptrdiffVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%f"
argument_list|,
operator|(
name|my_int_type
operator|*
operator|)
operator|&
name|intVar
argument_list|)
expr_stmt|;
comment|// Preserve the original formatting.
name|scanf
argument_list|(
literal|"%o"
argument_list|,
operator|&
name|longVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%u"
argument_list|,
operator|&
name|longVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%x"
argument_list|,
operator|&
name|longVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%X"
argument_list|,
operator|&
name|longVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%i"
argument_list|,
operator|&
name|uLongVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%d"
argument_list|,
operator|&
name|uLongVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%F"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%e"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%E"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%g"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%G"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%a"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
name|scanf
argument_list|(
literal|"%A"
argument_list|,
operator|&
name|longDoubleVar
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Validate the fixes.
end_comment

begin_comment
comment|// CHECK: printf("%d", (int) 123);
end_comment

begin_comment
comment|// CHECK: printf("abc%s", "testing testing 123");
end_comment

begin_comment
comment|// CHECK: printf("%ld", (long) -12);
end_comment

begin_comment
comment|// CHECK: printf("%d", 123);
end_comment

begin_comment
comment|// CHECK: printf("%s\n", "x");
end_comment

begin_comment
comment|// CHECK: printf("%f\n", 1.23);
end_comment

begin_comment
comment|// CHECK: printf("%+.2lld", (unsigned long long) 123456);
end_comment

begin_comment
comment|// CHECK: printf("%1Lf", (long double) 1.23);
end_comment

begin_comment
comment|// CHECK: printf("%0u", (unsigned) 31337);
end_comment

begin_comment
comment|// CHECK: printf("%p", (void *) 0);
end_comment

begin_comment
comment|// CHECK: printf("%+f", 1.23);
end_comment

begin_comment
comment|// CHECK: printf("%-f", 1.23);
end_comment

begin_comment
comment|// CHECK: printf("%1$d:%2$.*3$d:%4$.*3$d\n", 1, 2, 3, 4);
end_comment

begin_comment
comment|// CHECK: printf("%10.5ld", 1l);
end_comment

begin_comment
comment|// CHECK: printf("%c", 'a');
end_comment

begin_comment
comment|// CHECK: printf("%-f", 1.23);
end_comment

begin_comment
comment|// CHECK: printf("%s", "foo");
end_comment

begin_comment
comment|// CHECK: printf("%1$p", (void *)0);
end_comment

begin_comment
comment|// CHECK: printf("%lX", val);
end_comment

begin_comment
comment|// CHECK: printf("%zu", (size_t) 42);
end_comment

begin_comment
comment|// CHECK: printf("%jd", (intmax_t) 42);
end_comment

begin_comment
comment|// CHECK: printf("%ju", (uintmax_t) 42);
end_comment

begin_comment
comment|// CHECK: printf("%td", (ptrdiff_t) 42);
end_comment

begin_comment
comment|// CHECK: printf("%zu", (my_size_type) 42);
end_comment

begin_comment
comment|// CHECK: printf("%jd", (my_intmax_type) 42);
end_comment

begin_comment
comment|// CHECK: printf("%ju", (my_uintmax_type) 42);
end_comment

begin_comment
comment|// CHECK: printf("%td", (my_ptrdiff_type) 42);
end_comment

begin_comment
comment|// CHECK: printf("%d", (my_int_type) 42);
end_comment

begin_comment
comment|// CHECK: printf("%s", "foo");
end_comment

begin_comment
comment|// CHECK: printf("%lo", (long) 42);
end_comment

begin_comment
comment|// CHECK: printf("%ld", (long) 42);
end_comment

begin_comment
comment|// CHECK: printf("%lx", (long) 42);
end_comment

begin_comment
comment|// CHECK: printf("%lX", (long) 42);
end_comment

begin_comment
comment|// CHECK: printf("%lu", (unsigned long) 42);
end_comment

begin_comment
comment|// CHECK: printf("%lu", (unsigned long) 42);
end_comment

begin_comment
comment|// CHECK: printf("%LF", (long double) 42);
end_comment

begin_comment
comment|// CHECK: printf("%Le", (long double) 42);
end_comment

begin_comment
comment|// CHECK: printf("%LE", (long double) 42);
end_comment

begin_comment
comment|// CHECK: printf("%Lg", (long double) 42);
end_comment

begin_comment
comment|// CHECK: printf("%LG", (long double) 42);
end_comment

begin_comment
comment|// CHECK: printf("%La", (long double) 42);
end_comment

begin_comment
comment|// CHECK: printf("%LA", (long double) 42);
end_comment

begin_comment
comment|// CHECK: scanf("%99s", str);
end_comment

begin_comment
comment|// CHECK: scanf("%s", vstr);
end_comment

begin_comment
comment|// CHECK: scanf("%99s", str);
end_comment

begin_comment
comment|// CHECK: scanf("%99s", str);
end_comment

begin_comment
comment|// CHECK: scanf("%hd",&shortVar);
end_comment

begin_comment
comment|// CHECK: scanf("%hu",&uShortVar);
end_comment

begin_comment
comment|// CHECK: scanf("%d",&intVar);
end_comment

begin_comment
comment|// CHECK: scanf("%d", intAVar);
end_comment

begin_comment
comment|// CHECK: scanf("%d", intSAParm);
end_comment

begin_comment
comment|// CHECK: scanf("%u",&uIntVar);
end_comment

begin_comment
comment|// CHECK: scanf("%f",&floatVar);
end_comment

begin_comment
comment|// CHECK: scanf("%lf",&doubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%Lf",&longDoubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%ld",&longVar);
end_comment

begin_comment
comment|// CHECK: scanf("%lu",&uLongVar);
end_comment

begin_comment
comment|// CHECK: scanf("%lld",&longLongVar);
end_comment

begin_comment
comment|// CHECK: scanf("%llu",&uLongLongVar);
end_comment

begin_comment
comment|// CHECK: scanf("%d",&enumVar);
end_comment

begin_comment
comment|// CHECK: scanf("%zu",&sizeVar);
end_comment

begin_comment
comment|// CHECK: scanf("%jd",&intmaxVar);
end_comment

begin_comment
comment|// CHECK: scanf("%ju",&uIntmaxVar);
end_comment

begin_comment
comment|// CHECK: scanf("%td",&ptrdiffVar);
end_comment

begin_comment
comment|// CHECK: scanf("%zu", (my_size_type*)&sizeVar);
end_comment

begin_comment
comment|// CHECK: scanf("%jd", (my_intmax_type*)&intmaxVar);
end_comment

begin_comment
comment|// CHECK: scanf("%ju", (my_uintmax_type*)&uIntmaxVar);
end_comment

begin_comment
comment|// CHECK: scanf("%td", (my_ptrdiff_type*)&ptrdiffVar);
end_comment

begin_comment
comment|// CHECK: scanf("%d", (my_int_type*)&intVar);
end_comment

begin_comment
comment|// CHECK: scanf("%lo",&longVar);
end_comment

begin_comment
comment|// CHECK: scanf("%lu",&longVar);
end_comment

begin_comment
comment|// CHECK: scanf("%lx",&longVar);
end_comment

begin_comment
comment|// CHECK: scanf("%lX",&longVar);
end_comment

begin_comment
comment|// CHECK: scanf("%li",&uLongVar);
end_comment

begin_comment
comment|// CHECK: scanf("%ld",&uLongVar);
end_comment

begin_comment
comment|// CHECK: scanf("%LF",&longDoubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%Le",&longDoubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%LE",&longDoubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%Lg",&longDoubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%LG",&longDoubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%La",&longDoubleVar);
end_comment

begin_comment
comment|// CHECK: scanf("%LA",&longDoubleVar);
end_comment

end_unit

