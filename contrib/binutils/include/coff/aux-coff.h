begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Modifications of internal.h and m68k.h needed by A/UX    Suggested by Ian Lance Taylor<ian@cygnus.com> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GNU_COFF_AUX_H
end_ifndef

begin_define
define|#
directive|define
name|GNU_COFF_AUX_H
value|1
end_define

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_include
include|#
directive|include
file|"coff/m68k.h"
end_include

begin_comment
comment|/* Section contains 64-byte padded pathnames of shared libraries */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_LIB
end_undef

begin_define
define|#
directive|define
name|STYP_LIB
value|0x200
end_define

begin_comment
comment|/* Section contains shared library initialization code */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_INIT
end_undef

begin_define
define|#
directive|define
name|STYP_INIT
value|0x400
end_define

begin_comment
comment|/* Section contains .ident information */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_IDENT
end_undef

begin_define
define|#
directive|define
name|STYP_IDENT
value|0x800
end_define

begin_comment
comment|/* Section types used by bfd and gas not defined (directly) by A/UX */
end_comment

begin_undef
undef|#
directive|undef
name|STYP_OVER
end_undef

begin_define
define|#
directive|define
name|STYP_OVER
value|0
end_define

begin_undef
undef|#
directive|undef
name|STYP_INFO
end_undef

begin_define
define|#
directive|define
name|STYP_INFO
value|STYP_IDENT
end_define

begin_comment
comment|/* Traditional name of the section tagged with STYP_LIB */
end_comment

begin_define
define|#
directive|define
name|_LIB
value|".lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNU_COFF_AUX_H */
end_comment

end_unit

