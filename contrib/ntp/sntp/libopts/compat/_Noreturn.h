begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
operator|!
name|defined
specifier|_Noreturn
operator|&&
name|__STDC_VERSION__
operator|<
literal|201112
end_if

begin_if
if|#
directive|if
operator|(
literal|3
operator|<=
name|__GNUC__
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
literal|8
operator|<=
name|__GNUC_MINOR__
operator|)
expr|\
operator|||
literal|0x5110
operator|<=
name|__SUNPRO_C
operator|)
end_if

begin_define
define|#
directive|define
name|_Noreturn
value|__attribute__ ((__noreturn__))
end_define

begin_elif
elif|#
directive|elif
literal|1200
operator|<=
name|_MSC_VER
end_elif

begin_define
define|#
directive|define
name|_Noreturn
value|__declspec (noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_Noreturn
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

