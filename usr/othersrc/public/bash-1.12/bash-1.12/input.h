begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* input.h -- Structures and unions used for reading input. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_INPUT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_INPUT_H
end_define

begin_comment
comment|/* Function pointers can be declared as (Function *)foo. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FUNCTION_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FUNCTION_DEF
end_define

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FUNCTION_DEF */
end_comment

begin_comment
comment|/* Some stream `types'. */
end_comment

begin_define
define|#
directive|define
name|st_stream
value|1
end_define

begin_define
define|#
directive|define
name|st_string
value|2
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|FILE
modifier|*
name|file
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
block|}
name|INPUT_STREAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|INPUT_STREAM
name|location
decl_stmt|;
name|Function
modifier|*
name|getter
decl_stmt|;
name|Function
modifier|*
name|ungetter
decl_stmt|;
block|}
name|BASH_INPUT
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|BASH_INPUT
name|bash_input
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INPUT_H */
end_comment

end_unit

