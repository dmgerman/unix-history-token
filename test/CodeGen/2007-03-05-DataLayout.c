begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Testcase for PR1242
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - | grep datalayout | \
end_comment

begin_comment
comment|// RUN:    not grep {"\[Ee\]-p:\[36\]\[24\]:\[36\]\[24\]"}
end_comment

begin_comment
comment|// END.
end_comment

begin_typedef
typedef|typedef
name|__SIZE_TYPE__
name|size_t
typedef|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NDIM
value|3
end_define

begin_define
define|#
directive|define
name|BODY
value|01
end_define

begin_typedef
typedef|typedef
name|double
name|vector
index|[
name|NDIM
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bnode
modifier|*
name|bodyptr
typedef|;
end_typedef

begin_comment
comment|// { i16, double, [3 x double], i32, i32, [3 x double], [3 x double], [3 x
end_comment

begin_comment
comment|// double], double, \2 *, \2 * }
end_comment

begin_struct
struct|struct
name|bnode
block|{
name|short
name|int
name|type
decl_stmt|;
name|double
name|mass
decl_stmt|;
name|vector
name|pos
decl_stmt|;
name|int
name|proc
decl_stmt|;
name|int
name|new_proc
decl_stmt|;
name|vector
name|vel
decl_stmt|;
name|vector
name|acc
decl_stmt|;
name|vector
name|new_acc
decl_stmt|;
name|double
name|phi
decl_stmt|;
name|bodyptr
name|next
decl_stmt|;
name|bodyptr
name|proc_next
decl_stmt|;
block|}
name|body
struct|;
end_struct

begin_define
define|#
directive|define
name|Type
parameter_list|(
name|x
parameter_list|)
value|((x)->type)
end_define

begin_define
define|#
directive|define
name|Mass
parameter_list|(
name|x
parameter_list|)
value|((x)->mass)
end_define

begin_define
define|#
directive|define
name|Pos
parameter_list|(
name|x
parameter_list|)
value|((x)->pos)
end_define

begin_define
define|#
directive|define
name|Proc
parameter_list|(
name|x
parameter_list|)
value|((x)->proc)
end_define

begin_define
define|#
directive|define
name|New_Proc
parameter_list|(
name|x
parameter_list|)
value|((x)->new_proc)
end_define

begin_define
define|#
directive|define
name|Vel
parameter_list|(
name|x
parameter_list|)
value|((x)->vel)
end_define

begin_define
define|#
directive|define
name|Acc
parameter_list|(
name|x
parameter_list|)
value|((x)->acc)
end_define

begin_define
define|#
directive|define
name|New_Acc
parameter_list|(
name|x
parameter_list|)
value|((x)->new_acc)
end_define

begin_define
define|#
directive|define
name|Phi
parameter_list|(
name|x
parameter_list|)
value|((x)->phi)
end_define

begin_define
define|#
directive|define
name|Next
parameter_list|(
name|x
parameter_list|)
value|((x)->next)
end_define

begin_define
define|#
directive|define
name|Proc_Next
parameter_list|(
name|x
parameter_list|)
value|((x)->proc_next)
end_define

begin_function
name|bodyptr
name|ubody_alloc
parameter_list|(
name|int
name|p
parameter_list|)
block|{
specifier|register
name|bodyptr
name|tmp
decl_stmt|;
name|tmp
operator|=
operator|(
name|bodyptr
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|body
argument_list|)
argument_list|)
expr_stmt|;
name|Type
argument_list|(
name|tmp
argument_list|)
operator|=
name|BODY
expr_stmt|;
name|Proc
argument_list|(
name|tmp
argument_list|)
operator|=
name|p
expr_stmt|;
name|Proc_Next
argument_list|(
name|tmp
argument_list|)
operator|=
name|NULL
expr_stmt|;
name|New_Proc
argument_list|(
name|tmp
argument_list|)
operator|=
name|p
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|bodyptr
name|b
init|=
name|ubody_alloc
argument_list|(
literal|17
argument_list|)
decl_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

