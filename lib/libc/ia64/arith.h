begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * MD header for contrib/gdtoa  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|IEEE_8087
end_define

begin_define
define|#
directive|define
name|Arith_Kind_ASL
value|1
end_define

begin_define
define|#
directive|define
name|Long
value|int
end_define

begin_define
define|#
directive|define
name|Intcast
value|(int)(long)
end_define

begin_define
define|#
directive|define
name|Double_Align
end_define

begin_define
define|#
directive|define
name|X64_bit_pointers
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BYTE_ORDER == _LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|IEEE_MC68k
end_define

begin_define
define|#
directive|define
name|Arith_Kind_ASL
value|2
end_define

begin_define
define|#
directive|define
name|Long
value|int
end_define

begin_define
define|#
directive|define
name|Intcast
value|(int)(long)
end_define

begin_define
define|#
directive|define
name|Double_Align
end_define

begin_define
define|#
directive|define
name|X64_bit_pointers
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gcc_bug
end_ifdef

begin_comment
comment|/* XXX Why does arithchk report sudden underflow here? */
end_comment

begin_define
define|#
directive|define
name|Sudden_Underflow
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

