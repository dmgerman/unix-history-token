begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Protocol for a sorting service.  */
end_comment

begin_define
define|#
directive|define
name|SORTPROG
value|((long) 22855)
end_define

begin_define
define|#
directive|define
name|SORTVERS
value|((long) 1)
end_define

begin_define
define|#
directive|define
name|SORT
value|((long) 1)
end_define

begin_comment
comment|/*  * The sort procedure receives an array of strings and returns an array  * of strings.  This toy service handles a maximum of 64 strings.  */
end_comment

begin_define
define|#
directive|define
name|MAXSORTSIZE
value|((long) 64)
end_define

begin_struct
struct|struct
name|sortstrings
block|{
name|long
name|ns
decl_stmt|;
comment|/* number of strings in the array */
name|char
modifier|*
modifier|*
name|s
decl_stmt|;
comment|/* pointer to the array of strings */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|xdr_sortstrings
parameter_list|()
function_decl|;
end_function_decl

end_unit

