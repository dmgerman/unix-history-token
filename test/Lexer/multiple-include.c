begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XVID_AUTO_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|XVID_AUTO_INCLUDE
end_define

begin_define
define|#
directive|define
name|FUNC_H
value|H_Pass_16_C
end_define

begin_include
include|#
directive|include
file|"multiple-include.c"
end_include

begin_define
define|#
directive|define
name|FUNC_H
value|H_Pass_8_C
end_define

begin_include
include|#
directive|include
file|"multiple-include.c"
end_include

begin_undef
undef|#
directive|undef
name|XVID_AUTO_INCLUDE
end_undef

begin_typedef
typedef|typedef
name|void
name|ff
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ff
modifier|*
name|a
decl_stmt|;
block|}
name|S
typedef|;
end_typedef

begin_decl_stmt
name|S
name|s
init|=
block|{
name|H_Pass_8_C
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XVID_AUTO_INCLUDE
argument_list|)
operator|&&
name|defined
argument_list|(
name|REFERENCE_CODE
argument_list|)
end_if

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|XVID_AUTO_INCLUDE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|REFERENCE_CODE
argument_list|)
end_elif

begin_function
specifier|static
name|void
name|FUNC_H
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_undef
undef|#
directive|undef
name|FUNC_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

