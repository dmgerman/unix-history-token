begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm< %s -o -
end_comment

begin_comment
comment|// A nice and complicated initialization example with unions from Python
end_comment

begin_typedef
typedef|typedef
name|int
name|Py_ssize_t
typedef|;
end_typedef

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
name|Py_ssize_t
name|gc_refs
decl_stmt|;
block|}
name|gc
struct|;
name|long
name|double
name|dummy
decl_stmt|;
comment|/* force worst-case alignment */
block|}
name|PyGC_Head
typedef|;
end_typedef

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
comment|/* collection threshold */
name|int
name|count
decl_stmt|;
comment|/* count of allocations or collections of younger                     generations */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NUM_GENERATIONS
value|3
end_define

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
comment|/* linked lists of container objects */
end_comment

begin_decl_stmt
name|struct
name|gc_generation
name|generations
index|[
name|NUM_GENERATIONS
index|]
init|=
block|{
comment|/* PyGC_Head,                     threshold,      count */
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

