begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)types.c	4.1 (Berkeley) 5/6/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LONG
end_if

begin_define
define|#
directive|define
name|ptr
value|long
end_define

begin_define
define|#
directive|define
name|uptr
value|long
end_define

begin_define
define|#
directive|define
name|getp
value|getl
end_define

begin_define
define|#
directive|define
name|putp
value|putl
end_define

begin_define
define|#
directive|define
name|MONE
value|-1L
end_define

begin_function_decl
specifier|extern
name|long
name|getl
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ptr
value|int
end_define

begin_define
define|#
directive|define
name|uptr
value|unsigned
end_define

begin_define
define|#
directive|define
name|getp
value|getw
end_define

begin_define
define|#
directive|define
name|putp
value|putw
end_define

begin_define
define|#
directive|define
name|MONE
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

