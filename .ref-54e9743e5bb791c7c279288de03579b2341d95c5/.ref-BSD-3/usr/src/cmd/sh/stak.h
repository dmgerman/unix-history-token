begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *	UNIX shell  *  *	S. R. Bourne  *	Bell Telephone Laboratories  *  */
end_comment

begin_comment
comment|/* To use stack as temporary workspace across  * possible storage allocation (eg name lookup)  * a) get ptr from `relstak'  * b) can now use `pushstak'  * c) then reset with `setstak'  * d) `absstak' gives real address if needed  */
end_comment

begin_define
define|#
directive|define
name|relstak
parameter_list|()
value|(staktop-stakbot)
end_define

begin_define
define|#
directive|define
name|absstak
parameter_list|(
name|x
parameter_list|)
value|(stakbot+Rcheat(x))
end_define

begin_define
define|#
directive|define
name|setstak
parameter_list|(
name|x
parameter_list|)
value|(staktop=absstak(x))
end_define

begin_define
define|#
directive|define
name|pushstak
parameter_list|(
name|c
parameter_list|)
value|(*staktop++=(c))
end_define

begin_define
define|#
directive|define
name|zerostak
parameter_list|()
value|(*staktop=0)
end_define

begin_comment
comment|/* Used to address an item left on the top of  * the stack (very temporary)  */
end_comment

begin_define
define|#
directive|define
name|curstak
parameter_list|()
value|(staktop)
end_define

begin_comment
comment|/* `usestak' before `pushstak' then `fixstak'  * These routines are safe against heap  * being allocated.  */
end_comment

begin_define
define|#
directive|define
name|usestak
parameter_list|()
value|{locstak();}
end_define

begin_comment
comment|/* for local use only since it hands  * out a real address for the stack top  */
end_comment

begin_function_decl
name|STKPTR
name|locstak
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Will allocate the item being used and return its  * address (safe now).  */
end_comment

begin_define
define|#
directive|define
name|fixstak
parameter_list|()
value|endstak(staktop)
end_define

begin_comment
comment|/* For use after `locstak' to hand back  * new stack top and then allocate item  */
end_comment

begin_function_decl
name|STKPTR
name|endstak
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Copy a string onto the stack and  * allocate the space.  */
end_comment

begin_function_decl
name|STKPTR
name|cpystak
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Allocate given ammount of stack space */
end_comment

begin_function_decl
name|STKPTR
name|getstak
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* A chain of ptrs of stack blocks that  * have become covered by heap allocation.  * `tdystak' will return them to the heap.  */
end_comment

begin_decl_stmt
name|BLKPTR
name|stakbsy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Base of the entire stack */
end_comment

begin_decl_stmt
name|STKPTR
name|stakbas
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Top of entire stack */
end_comment

begin_decl_stmt
name|STKPTR
name|brkend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Base of current item */
end_comment

begin_decl_stmt
name|STKPTR
name|stakbot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Top of current item */
end_comment

begin_decl_stmt
name|STKPTR
name|staktop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used with tdystak */
end_comment

begin_function_decl
name|STKPTR
name|savstak
parameter_list|()
function_decl|;
end_function_decl

end_unit

