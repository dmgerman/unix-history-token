begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_ET
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
modifier|*
name|msgs
decl_stmt|;
name|int
name|base
decl_stmt|;
name|int
name|n_msgs
decl_stmt|;
block|}
name|error_table
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|error_table
modifier|*
modifier|*
name|_et_list
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ERROR_CODE
value|"int"
end_define

begin_comment
comment|/* type used for error codes */
end_comment

begin_define
define|#
directive|define
name|ERRCODE_RANGE
value|8
end_define

begin_comment
comment|/* # of bits to shift table number */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_CHAR
value|6
end_define

begin_comment
comment|/* # bits to shift per character in name */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|error_table_name
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_ET
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

