begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PARSE_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|PARSE_INCLUDE
end_define

begin_comment
comment|/* macros for the   parse_args   routine */
end_comment

begin_define
define|#
directive|define
name|P_STRING
value|1
end_define

begin_comment
comment|/* Macros for the result_type attribute */
end_comment

begin_define
define|#
directive|define
name|P_CHAR
value|2
end_define

begin_define
define|#
directive|define
name|P_SHORT
value|3
end_define

begin_define
define|#
directive|define
name|P_INT
value|4
end_define

begin_define
define|#
directive|define
name|P_LONG
value|5
end_define

begin_define
define|#
directive|define
name|P_FILE
value|6
end_define

begin_define
define|#
directive|define
name|P_OLD_FILE
value|7
end_define

begin_define
define|#
directive|define
name|P_NEW_FILE
value|8
end_define

begin_define
define|#
directive|define
name|P_FLOAT
value|9
end_define

begin_define
define|#
directive|define
name|P_DOUBLE
value|10
end_define

begin_define
define|#
directive|define
name|P_CASE_INSENSITIVE
value|01
end_define

begin_comment
comment|/* Macros for the   flags   attribute */
end_comment

begin_define
define|#
directive|define
name|P_REQUIRED_PREFIX
value|02
end_define

begin_define
define|#
directive|define
name|P_NO_ARGS
value|0
end_define

begin_comment
comment|/* Macros for the   arg_count   attribute */
end_comment

begin_define
define|#
directive|define
name|P_ONE_ARG
value|1
end_define

begin_define
define|#
directive|define
name|P_INFINITE_ARGS
value|2
end_define

begin_define
define|#
directive|define
name|p_entry
parameter_list|(
name|pref
parameter_list|,
name|swit
parameter_list|,
name|flag
parameter_list|,
name|count
parameter_list|,
name|type
parameter_list|,
name|store
parameter_list|,
name|size
parameter_list|)
define|\
value|{ (pref), (swit), (flag), (count), (type), (int *) (store), (size) }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|prefix
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|result_type
decl_stmt|;
name|int
modifier|*
name|result_ptr
decl_stmt|;
name|int
name|table_size
decl_stmt|;
block|}
name|arg_info
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_define
define|#
directive|define
name|Argdcl
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Argdcl
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|arg_verify
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|,
name|arg_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_store
name|Argdcl
argument_list|(
operator|(
name|arg_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|match_table
name|Argdcl
argument_list|(
operator|(
name|char
operator|*
operator|,
name|arg_info
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|parse_args
name|Argdcl
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|arg_info
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

