begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|GCC_GSTAB_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_GSTAB_H
end_define

begin_define
define|#
directive|define
name|__define_stab
parameter_list|(
name|NAME
parameter_list|,
name|CODE
parameter_list|,
name|STRING
parameter_list|)
value|NAME=CODE,
end_define

begin_enum
enum|enum
name|__stab_debug_code
block|{
include|#
directive|include
file|"stab.def"
name|LAST_UNUSED_STAB_CODE
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|__define_stab
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_GSTAB_H */
end_comment

end_unit

