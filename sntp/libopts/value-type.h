begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Generated header for gperf generated source Fri Apr 29 15:43:59 PDT 2011  *  This file enumerates the list of names and declares the  *  procedure for mapping string names to the enum value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_VALUE_TYPE_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_VALUE_TYPE_H_GUARD
value|1
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|VTP_KWD_INVALID
block|,
name|VTP_KWD_STRING
block|,
name|VTP_KWD_INTEGER
block|,
name|VTP_KWD_BOOLEAN
block|,
name|VTP_KWD_BOOL
block|,
name|VTP_KWD_KEYWORD
block|,
name|VTP_KWD_SET
block|,
name|VTP_KWD_SET_MEMBERSHIP
block|,
name|VTP_KWD_NESTED
block|,
name|VTP_KWD_HIERARCHY
block|,
name|VTP_COUNT_KWD
block|}
name|value_type_enum_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|value_type_enum_t
name|find_value_type_id
parameter_list|(
name|char
specifier|const
modifier|*
name|str
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOOPTS_VALUE_TYPE_H_GUARD */
end_comment

end_unit

