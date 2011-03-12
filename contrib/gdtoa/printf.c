begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|__sun
end_ifdef

begin_define
define|#
directive|define
name|Use_GDTOA_Qtype
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
end_if

begin_define
define|#
directive|define
name|Use_GDTOA_for_i386_long_double
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"printf.c0"
end_include

end_unit

