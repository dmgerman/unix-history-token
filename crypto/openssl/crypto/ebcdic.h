begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_EBCDIC_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_EBCDIC_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Avoid name clashes with other applications */
end_comment

begin_define
define|#
directive|define
name|os_toascii
value|_eay2000_os_toascii
end_define

begin_define
define|#
directive|define
name|os_toebcdic
value|_eay2000_os_toebcdic
end_define

begin_define
define|#
directive|define
name|ebcdic2ascii
value|_eay2000_ebcdic2ascii
end_define

begin_define
define|#
directive|define
name|ascii2ebcdic
value|_eay2000_ascii2ebcdic
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|os_toascii
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|os_toebcdic
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ebcdic2ascii
parameter_list|(
name|unsigned
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|srce
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ascii2ebcdic
parameter_list|(
name|unsigned
name|char
modifier|*
name|dest
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|srce
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

