begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A replacement for Digital Unix's<va_list.h>.  */
end_comment

begin_include
include|#
directive|include
file|<va-alpha.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_VA_LIST
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_HIDDEN_VA_LIST
argument_list|)
end_if

begin_define
define|#
directive|define
name|_VA_LIST
end_define

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_HIDDEN_VA_LIST
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_HIDDEN_VA_LIST_DONE
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_HIDDEN_VA_LIST_DONE
end_define

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|__va_list
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_HIDDEN_VA_LIST
argument_list|)
operator|&&
name|defined
argument_list|(
name|_VA_LIST
argument_list|)
end_elif

begin_undef
undef|#
directive|undef
name|_HIDDEN_VA_LIST
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

