begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__ARM_ARCH_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARM_ARCH_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ARM_ARCH__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CC_ARM
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH__
value|__TARGET_ARCH_ARM
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARMEB__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ARMEL__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_comment
comment|/*    * Why doesn't gcc define __ARM_ARCH__? Instead it defines    * bunch of below macros. See all_architectires[] table in    * gcc/config/arm/arm.c. On a side note it defines    * __ARMEL__/__ARMEB__ for little-/big-endian.    */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_7R__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7M__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_7EM__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__ARM_ARCH__
value|7
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6M__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6T2__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__ARM_ARCH__
value|6
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_5__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5T__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_5E__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_5TE__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_5TEJ__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__ARM_ARCH__
value|5
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_4__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_4T__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|__ARM_ARCH__
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"unsupported ARM architecture"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_FIPSCANISTER
end_ifdef

begin_include
include|#
directive|include
file|<openssl/fipssyms.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|__ASSEMBLER__
end_if

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|OPENSSL_armcap_P
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ARMV7_NEON
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|ARMV7_TICK
value|(1<<1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

