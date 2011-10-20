begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -emit-llvm -triple x86_64-apple-darwin -o - | FileCheck %s  The FE must generate padding here both at the end of each PyG_Head and between array elements.  Reduced from Python. */
end_comment

begin_typedef
typedef|typedef
union|union
name|_gc_head
block|{
struct|struct
block|{
name|union
name|_gc_head
modifier|*
name|gc_next
decl_stmt|;
name|union
name|_gc_head
modifier|*
name|gc_prev
decl_stmt|;
name|long
name|gc_refs
decl_stmt|;
block|}
name|gc
struct|;
name|int
name|dummy
name|__attribute__
decl|((
name|aligned
decl|(16
decl_stmt|)
block|)
typedef|);
end_typedef

begin_empty_stmt
unit|} PyGC_Head
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|gc_generation
block|{
name|PyGC_Head
name|head
decl_stmt|;
name|int
name|threshold
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GEN_HEAD
parameter_list|(
name|n
parameter_list|)
value|(&generations[n].head)
end_define

begin_comment
comment|// The idea is that there are 6 undefs in this structure initializer to cover
end_comment

begin_comment
comment|// the padding between elements.
end_comment

begin_comment
comment|// CHECK: @generations = global [3 x %struct.gc_generation] [%struct.gc_generation { %union._gc_head { %struct.anon { %union._gc_head* getelementptr inbounds ([3 x %struct.gc_generation]* @generations, i32 0, i32 0, i32 0), %union._gc_head* getelementptr inbounds ([3 x %struct.gc_generation]* @generations, i32 0, i32 0, i32 0), i64 0 }, [8 x i8] undef }, i32 700, i32 0, [8 x i8] undef }, %struct.gc_generation { %union._gc_head { %struct.anon { %union._gc_head* bitcast (i8* getelementptr (i8* bitcast ([3 x %struct.gc_generation]* @generations to i8*), i64 48) to %union._gc_head*), %union._gc_head* bitcast (i8* getelementptr (i8* bitcast ([3 x %struct.gc_generation]* @generations to i8*), i64 48) to %union._gc_head*), i64 0 }, [8 x i8] undef }, i32 10, i32 0, [8 x i8] undef }, %struct.gc_generation { %union._gc_head { %struct.anon { %union._gc_head* bitcast (i8* getelementptr (i8* bitcast ([3 x %struct.gc_generation]* @generations to i8*), i64 96) to %union._gc_head*), %union._gc_head* bitcast (i8* getelementptr (i8* bitcast ([3 x %struct.gc_generation]* @generations to i8*), i64 96) to %union._gc_head*), i64 0 }, [8 x i8] undef }, i32 10, i32 0, [8 x i8] undef }]
end_comment

begin_comment
comment|/* linked lists of container objects */
end_comment

begin_decl_stmt
name|struct
name|gc_generation
name|generations
index|[
literal|3
index|]
init|=
block|{
comment|/* PyGC_Head,                           threshold,      count */
block|{
block|{
block|{
name|GEN_HEAD
argument_list|(
literal|0
argument_list|)
block|,
name|GEN_HEAD
argument_list|(
literal|0
argument_list|)
block|,
literal|0
block|}
block|}
block|,
literal|700
block|,
literal|0
block|}
block|,
block|{
block|{
block|{
name|GEN_HEAD
argument_list|(
literal|1
argument_list|)
block|,
name|GEN_HEAD
argument_list|(
literal|1
argument_list|)
block|,
literal|0
block|}
block|}
block|,
literal|10
block|,
literal|0
block|}
block|,
block|{
block|{
block|{
name|GEN_HEAD
argument_list|(
literal|2
argument_list|)
block|,
name|GEN_HEAD
argument_list|(
literal|2
argument_list|)
block|,
literal|0
block|}
block|}
block|,
literal|10
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

