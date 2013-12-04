begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Generated header for gperf generated source Fri Apr 29 15:43:59 PDT 2011  *  This file enumerates the list of names and declares the  *  procedure for mapping string names to the enum value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_XAT_ATTRIBUTE_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_XAT_ATTRIBUTE_H_GUARD
value|1
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|XAT_KWD_INVALID
block|,
name|XAT_KWD_TYPE
block|,
name|XAT_KWD_WORDS
block|,
name|XAT_KWD_MEMBERS
block|,
name|XAT_KWD_COOKED
block|,
name|XAT_KWD_UNCOOKED
block|,
name|XAT_KWD_KEEP
block|,
name|XAT_COUNT_KWD
block|}
name|xat_attribute_enum_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|xat_attribute_enum_t
name|find_xat_attribute_id
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
comment|/* AUTOOPTS_XAT_ATTRIBUTE_H_GUARD */
end_comment

end_unit

