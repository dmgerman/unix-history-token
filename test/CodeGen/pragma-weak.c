begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -verify | FileCheck %s
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
comment|// CHECK: @both = alias void ()* @__both
end_comment

begin_comment
comment|// CHECK: @both2 = alias void ()* @__both2
end_comment

begin_comment
comment|// CHECK: @both3 = alias weak void ()* @__both3
end_comment

begin_comment
comment|// CHECK: @a3 = alias weak void ()* @__a3
end_comment

begin_comment
comment|// CHECK: @weakvar_alias = alias weak i32* @__weakvar_alias
end_comment

begin_comment
comment|// CHECK: @foo = alias weak void ()* @__foo
end_comment

begin_comment
comment|// CHECK: @foo2 = alias weak void ()* @__foo2
end_comment

begin_comment
comment|// CHECK: @stutter = alias weak void ()* @__stutter
end_comment

begin_comment
comment|// CHECK: @stutter2 = alias weak void ()* @__stutter2
end_comment

begin_comment
comment|// CHECK: @declfirst = alias weak void ()* @__declfirst
end_comment

begin_comment
comment|// CHECK: @declfirstattr = alias weak void ()* @__declfirstattr
end_comment

begin_comment
comment|// CHECK: @mix2 = alias weak void ()* @__mix2
end_comment

begin_comment
comment|// CHECK: @a1 = alias weak void ()* @__a1
end_comment

begin_comment
comment|// CHECK: @xxx = alias weak void ()* @__xxx
end_comment

begin_comment
comment|// CHECK: define weak void @weakdef()
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
comment|// CHECK: define void @__foo()
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
comment|// CHECK: define void @__foo2()
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
comment|// expected-warning {{weak identifier 'td' never declared}}
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
comment|// expected-warning {{weak identifier '__td2' never declared}}
end_comment

begin_typedef
typedef|typedef
name|int
name|__td2
typedef|;
end_typedef

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
comment|// CHECK: define void @__stutter()
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
comment|// CHECK: define void @__stutter2()
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
comment|// CHECK: define void @__declfirst()
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
comment|// CHECK: define void @__declfirstattr()
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
comment|// CHECK: define weak void @mix()
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
comment|// CHECK: define void @__mix2()
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
comment|// CHECK: define void @__both()
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
comment|// CHECK: define void @__both2()
end_comment

begin_function_decl
name|void
name|__both3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|weak
name|both3
name|=
name|__both3
end_pragma

begin_comment
comment|// first, wins
end_comment

begin_function_decl
name|void
name|both3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"__both3"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|__both3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @__both3()
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
comment|// CHECK: define void @__a1()
end_comment

begin_comment
comment|// attributes introduced BEFORE a combination of #pragma weak and alias()
end_comment

begin_comment
comment|// hold...
end_comment

begin_function_decl
name|void
name|__a3
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
name|a3
name|=
name|__a3
end_pragma

begin_function_decl
name|void
name|a3
parameter_list|(
name|void
parameter_list|)
function_decl|__attribute
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"__a3"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|__a3
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK: define void @__a3()
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
argument|(pure,noinline,const,fastcall)
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
comment|// CHECK: void @__xxx()
end_comment

begin_comment
comment|/// TODO: stuff that still doesn't work
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
comment|// CHECK: define void @yyy()
end_comment

begin_decl_stmt
name|int
name|correct_linkage
decl_stmt|;
end_decl_stmt

end_unit

