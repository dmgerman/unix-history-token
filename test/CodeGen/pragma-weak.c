begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux-gnu -emit-llvm %s -o - -verify | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @weakvar = weak global
end_comment

begin_comment
comment|// CHECK: @__weakvar_alias = common global
end_comment

begin_comment
comment|// CHECK: @correct_linkage = weak global
end_comment

begin_comment
comment|// CHECK-DAG: @both = alias void (), void ()* @__both
end_comment

begin_comment
comment|// CHECK-DAG: @both2 = alias void (), void ()* @__both2
end_comment

begin_comment
comment|// CHECK-DAG: @weakvar_alias = weak alias i32, i32* @__weakvar_alias
end_comment

begin_comment
comment|// CHECK-DAG: @foo = weak alias void (), void ()* @__foo
end_comment

begin_comment
comment|// CHECK-DAG: @foo2 = weak alias void (), void ()* @__foo2
end_comment

begin_comment
comment|// CHECK-DAG: @stutter = weak alias void (), void ()* @__stutter
end_comment

begin_comment
comment|// CHECK-DAG: @stutter2 = weak alias void (), void ()* @__stutter2
end_comment

begin_comment
comment|// CHECK-DAG: @declfirst = weak alias void (), void ()* @__declfirst
end_comment

begin_comment
comment|// CHECK-DAG: @declfirstattr = weak alias void (), void ()* @__declfirstattr
end_comment

begin_comment
comment|// CHECK-DAG: @mix2 = weak alias void (), void ()* @__mix2
end_comment

begin_comment
comment|// CHECK-DAG: @a1 = weak alias void (), void ()* @__a1
end_comment

begin_comment
comment|// CHECK-DAG: @xxx = weak alias void (), void ()* @__xxx
end_comment

begin_comment
comment|// CHECK-LABEL: define weak void @weakdef()
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|weakvar
end_pragma

begin_decl_stmt
name|int
name|weakvar
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|weakdef
end_pragma

begin_function
name|void
name|weakdef
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|param
end_pragma

begin_comment
comment|// expected-warning {{weak identifier 'param' never declared}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|correct_linkage
end_pragma

begin_function
name|void
name|f
parameter_list|(
name|int
name|param
parameter_list|)
block|{
name|int
name|correct_linkage
decl_stmt|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|weakvar_alias
name|=
name|__weakvar_alias
end_pragma

begin_decl_stmt
name|int
name|__weakvar_alias
decl_stmt|;
end_decl_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|foo
name|=
name|__foo
end_pragma

begin_function
name|void
name|__foo
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @__foo()
end_comment

begin_function
name|void
name|__foo2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|foo2
name|=
name|__foo2
end_pragma

begin_comment
comment|// CHECK-LABEL: define void @__foo2()
end_comment

begin_comment
comment|///// test errors
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|unused
end_pragma

begin_comment
comment|// expected-warning {{weak identifier 'unused' never declared}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|unused_alias
name|=
name|__unused_alias
end_pragma

begin_comment
comment|// expected-warning {{weak identifier '__unused_alias' never declared}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|td
end_pragma

begin_comment
comment|// expected-warning {{'weak' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|int
name|td
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|weak
name|td2
name|=
name|__td2
end_pragma

begin_comment
comment|// expected-warning {{'weak' attribute only applies to variables and functions}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__td2
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__td3
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|weak
name|td3
name|=
name|__td3
end_pragma

begin_comment
comment|// expected-warning {{'weak' attribute only applies to variables and functions}}
end_comment

begin_comment
comment|///// test weird cases
end_comment

begin_comment
comment|// test repeats
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|stutter
name|=
name|__stutter
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|stutter
name|=
name|__stutter
end_pragma

begin_function
name|void
name|__stutter
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @__stutter()
end_comment

begin_function
name|void
name|__stutter2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|stutter2
name|=
name|__stutter2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|weak
name|stutter2
name|=
name|__stutter2
end_pragma

begin_comment
comment|// CHECK-LABEL: define void @__stutter2()
end_comment

begin_comment
comment|// test decl/pragma weak order
end_comment

begin_function_decl
name|void
name|__declfirst
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|weak
name|declfirst
name|=
name|__declfirst
end_pragma

begin_function
name|void
name|__declfirst
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @__declfirst()
end_comment

begin_function_decl
name|void
name|__declfirstattr
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|declfirstattr
name|=
name|__declfirstattr
end_pragma

begin_function
name|void
name|__declfirstattr
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @__declfirstattr()
end_comment

begin_comment
comment|//// test that other attributes are preserved
end_comment

begin_comment
comment|//// ensure that pragma weak/__attribute((weak)) play nice
end_comment

begin_function_decl
name|void
name|mix
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|weak
name|mix
end_pragma

begin_macro
name|__attribute
argument_list|(
argument|(weak)
argument_list|)
end_macro

begin_function
name|void
name|mix
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK-LABEL: define weak void @mix()
end_comment

begin_comment
comment|// ensure following __attributes are preserved and that only a single
end_comment

begin_comment
comment|// alias is generated
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|mix2
name|=
name|__mix2
end_pragma

begin_function_decl
name|void
name|__mix2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|__mix2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|__mix2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @__mix2()
end_comment

begin_comment
comment|////////////// test #pragma weak/__attribute combinations
end_comment

begin_comment
comment|// if the SAME ALIAS is already declared then it overrides #pragma weak
end_comment

begin_comment
comment|// resulting in a non-weak alias in this case
end_comment

begin_function_decl
name|void
name|both
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"__both"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|both
name|=
name|__both
end_pragma

begin_function
name|void
name|__both
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @__both()
end_comment

begin_comment
comment|// if the TARGET is previously declared then whichever aliasing method
end_comment

begin_comment
comment|// comes first applies and subsequent aliases are discarded.
end_comment

begin_comment
comment|// TODO: warn about this
end_comment

begin_function_decl
name|void
name|__both2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|both2
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"__both2"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// first, wins
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|both2
name|=
name|__both2
end_pragma

begin_function
name|void
name|__both2
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define void @__both2()
end_comment

begin_comment
comment|///////////// ensure that #pragma weak does not alter existing __attributes()
end_comment

begin_function_decl
name|void
name|__a1
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_pragma
pragma|#
directive|pragma
name|weak
name|a1
name|=
name|__a1
end_pragma

begin_function
name|void
name|__a1
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @__a1() [[NI:#[0-9]+]]
end_comment

begin_pragma
pragma|#
directive|pragma
name|weak
name|xxx
name|=
name|__xxx
end_pragma

begin_macro
name|__attribute
argument_list|(
argument|(pure,noinline,const)
argument_list|)
end_macro

begin_function
name|void
name|__xxx
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// CHECK: void @__xxx() [[RN:#[0-9]+]]
end_comment

begin_comment
comment|///////////// PR10878: Make sure we can call a weak alias
end_comment

begin_function
name|void
name|SHA512Pad
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|SHA384Pad
name|=
name|SHA512Pad
end_pragma

begin_function
name|void
name|PR10878
parameter_list|()
block|{
name|SHA384Pad
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: call void @SHA384Pad(i8* null)
end_comment

begin_comment
comment|// PR14046: Parse #pragma weak in function-local context
end_comment

begin_function_decl
specifier|extern
name|int
name|PR14046e
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|PR14046f
parameter_list|()
block|{
pragma|#
directive|pragma
name|weak
name|PR14046e
name|PR14046e
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare extern_weak i32 @PR14046e()
end_comment

begin_comment
comment|// Parse #pragma weak after a label or case statement
end_comment

begin_function_decl
specifier|extern
name|int
name|PR16705a
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PR16705b
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PR16705c
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|PR16705f
parameter_list|(
name|int
name|a
parameter_list|)
block|{
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|1
case|:
pragma|#
directive|pragma
name|weak
name|PR16705a
name|PR16705a
argument_list|()
expr_stmt|;
default|default:
pragma|#
directive|pragma
name|weak
name|PR16705b
name|PR16705b
argument_list|()
expr_stmt|;
block|}
name|label
label|:
pragma|#
directive|pragma
name|weak
name|PR16705c
name|PR16705c
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: declare extern_weak i32 @PR16705a()
end_comment

begin_comment
comment|// CHECK: declare extern_weak i32 @PR16705b()
end_comment

begin_comment
comment|// CHECK: declare extern_weak i32 @PR16705c()
end_comment

begin_comment
comment|///////////// TODO: stuff that still doesn't work
end_comment

begin_comment
comment|// due to the fact that disparate TopLevelDecls cannot affect each other
end_comment

begin_comment
comment|// (due to clang's Parser and ASTConsumer behavior, and quite reasonable)
end_comment

begin_comment
comment|// #pragma weak must appear before or within the same TopLevelDecl as it
end_comment

begin_comment
comment|// references.
end_comment

begin_function
name|void
name|yyy
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|void
name|zzz
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|yyy
end_pragma

begin_comment
comment|// NOTE: weak doesn't apply, not before or in same TopLevelDec(!)
end_comment

begin_comment
comment|// CHECK-LABEL: define void @yyy()
end_comment

begin_decl_stmt
name|int
name|correct_linkage
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: attributes [[NI]] = { noinline nounwind{{.*}} }
end_comment

begin_comment
comment|// CHECK: attributes [[RN]] = { noinline nounwind optnone readnone{{.*}} }
end_comment

end_unit

