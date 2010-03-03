begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -triple x86_64-apple-darwin9 %s -emit-llvm -o - | FileCheck %s -check-prefix=X64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -triple i686-apple-darwin9 %s -emit-llvm -o - | FileCheck %s -check-prefix=X32
end_comment

begin_comment
comment|// X64: @.str = private constant [6 x i8] c"v8@?0\00"
end_comment

begin_comment
comment|// X64: @__block_literal_global = internal constant %1 { i8** @_NSConcreteGlobalBlock, i32 1342177280,
end_comment

begin_comment
comment|// X64: @.str1 = private constant [12 x i8] c"i16@?0c8f12\00"
end_comment

begin_comment
comment|// X64:   store i32 1073741824, i32*
end_comment

begin_comment
comment|// X32: @.str = private constant [6 x i8] c"v4@?0\00"
end_comment

begin_comment
comment|// X32: @__block_literal_global = internal constant %1 { i8** @_NSConcreteGlobalBlock, i32 1342177280,
end_comment

begin_comment
comment|// X32: @.str1 = private constant [11 x i8] c"i12@?0c4f8\00"
end_comment

begin_comment
comment|// X32:   store i32 1073741824, i32*
end_comment

begin_comment
comment|// rdar://7635294
end_comment

begin_decl_stmt
name|int
name|globalInt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|^
name|global
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
operator|++
name|globalInt
function_decl|;
end_function_decl

begin_function
unit|};
name|void
name|foo
parameter_list|(
name|int
name|param
parameter_list|)
block|{
specifier|extern
name|int
name|rand
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|rand_r
argument_list|(
name|int
argument_list|(
argument|^b
argument_list|)
operator|(
name|char
name|x
operator|,
name|float
name|y
operator|)
argument_list|)
decl_stmt|;
comment|// name a function present at runtime
while|while
condition|(
name|param
operator|--
condition|)
name|rand_r
argument_list|(
lambda|^
parameter_list|(
name|char
name|x
parameter_list|,
name|float
name|y
parameter_list|)
block|{
return|return
name|x
operator|+
operator|(
name|int
operator|)
name|y
operator|+
name|param
operator|+
name|rand
argument_list|()
return|;
block|}
argument_list|)
expr_stmt|;
comment|// generate a local block binding param
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
unit|enum {     BLOCK_HAS_COPY_DISPOSE =  (1<< 25),     BLOCK_HAS_CXX_OBJ =       (1<< 26),     BLOCK_IS_GLOBAL =         (1<< 28),     BLOCK_HAS_DESCRIPTOR =    (1<< 29),     BLOCK_HAS_OBJC_TYPE  =    (1<< 30) };  struct block_descriptor_big {     unsigned long int reserved;     unsigned long int size;     void (*copy)(void *dst, void *src);
comment|// conditional on BLOCK_HAS_COPY_DISPOSE
end_comment

begin_comment
unit|void (*dispose)(void *);
comment|// conditional on BLOCK_HAS_COPY_DISPOSE
end_comment

begin_comment
unit|const char *signature;
comment|// conditional on BLOCK_HAS_OBJC
end_comment

begin_comment
unit|const char *layout;
comment|// conditional on BLOCK_HAS_OBJC
end_comment

begin_comment
unit|}; struct block_descriptor_small {     unsigned long int reserved;     unsigned long int size;     const char *signature;
comment|// conditional on BLOCK_HAS_OBJC
end_comment

begin_comment
unit|const char *layout;
comment|// conditional on BLOCK_HAS_OBJC
end_comment

begin_comment
unit|};  struct block_layout_abi {
comment|// can't change
end_comment

begin_comment
unit|void *isa;   int flags;   int reserved;    void (*invoke)(void *, ...);   struct block_descriptor_big *descriptor; };  const char *getBlockSignature(void *block) {    struct block_layout_abi *layout = (struct block_layout_abi *)block;    if ((layout->flags& BLOCK_HAS_OBJC_TYPE) != BLOCK_HAS_OBJC_TYPE) return NULL;    if (layout->flags& BLOCK_HAS_COPY_DISPOSE)        return layout->descriptor->signature;    else       return ((struct block_descriptor_small *)layout->descriptor)->signature; }             int main(int argc, char *argv[]) {    printf("desired global flags: %d\n", BLOCK_IS_GLOBAL  | BLOCK_HAS_OBJC_TYPE);    printf("desired stack flags: %d\n",  BLOCK_HAS_OBJC_TYPE);        printf("types for global: %s\n", getBlockSignature(global));    printf("types for local: %s\n", getBlockSignature(^int(char x, float y) { return (int)(y + x); }));    return 0; }
comment|/* x86_64 desired global flags: 1342177280 desired stack flags: 1073741824 types for global: v8@?0 types for local: i16@?0c8f12  i386 desired global flags: 1342177280 desired stack flags: 1073741824 types for global: v4@?0 types for local: i12@?0c4f8 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

