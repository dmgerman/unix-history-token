begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* like pmax except BIG ENDIAN instead of LITTLE ENDIAN  */
end_comment

begin_define
define|#
directive|define
name|DECSTATION
end_define

begin_include
include|#
directive|include
file|"tm-mips.h"
end_include

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_comment
comment|/* default RISC NEWS environment */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"-Dr3000 -DLANGUAGE_C -DMIPSEB -DSYSTYPE_BSD -Dsony_news -Dunix -I/usr/include2.11"
end_define

begin_undef
undef|#
directive|undef
name|MACHINE_TYPE
end_undef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"Sony NEWS (RISC NEWS)"
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered. */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is numbered. */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
end_define

end_unit

