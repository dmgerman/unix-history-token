begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is an 1st attempt to stop other include files pulling     in real<stdio.h>.    A more ambitious set of possible symbols can be found in    sfio.h (inside an _cplusplus gard). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_STDIO_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|FILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STDIO_INCLUDED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDIO_LOADED
argument_list|)
end_if

begin_define
define|#
directive|define
name|_STDIO_H
end_define

begin_define
define|#
directive|define
name|_STDIO_INCLUDED
end_define

begin_define
define|#
directive|define
name|__STDIO_LOADED
end_define

begin_struct_decl
struct_decl|struct
name|_FILE
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|FILE
value|struct _FILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_CANNOT
value|"CANNOT"
end_define

begin_undef
undef|#
directive|undef
name|stdin
end_undef

begin_undef
undef|#
directive|undef
name|stdout
end_undef

begin_undef
undef|#
directive|undef
name|stderr
end_undef

begin_undef
undef|#
directive|undef
name|getc
end_undef

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_undef
undef|#
directive|undef
name|clearerr
end_undef

begin_undef
undef|#
directive|undef
name|fflush
end_undef

begin_undef
undef|#
directive|undef
name|feof
end_undef

begin_undef
undef|#
directive|undef
name|ferror
end_undef

begin_undef
undef|#
directive|undef
name|fileno
end_undef

end_unit

