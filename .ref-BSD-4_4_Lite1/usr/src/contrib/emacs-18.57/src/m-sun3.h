begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Sun 68000's OPERATING SYSTEM version 3    (for either 68000 or 68020 systems).  */
end_comment

begin_include
include|#
directive|include
file|"m-sun2.h"
end_include

begin_undef
undef|#
directive|undef
name|sun2
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|sun3
end_ifndef

begin_define
define|#
directive|define
name|sun3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Say that the text segment of a.out includes the header;    the header actually occupies the first few bytes of the text segment    and is counted in hdr.a_text.  */
end_comment

begin_define
define|#
directive|define
name|A_TEXT_OFFSET
parameter_list|(
name|HDR
parameter_list|)
value|sizeof (HDR)
end_define

begin_comment
comment|/* In case we are using floating point, work together with crt0.c.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|C_SWITCH_MACHINE
value|-fsoft
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This line is needed if you are linking with X windows    and the library xlib was compiled to use the 68881.    For maximum cleanliness, don't edit this file;    instead, insert this line in config.h.  */
end_comment

begin_comment
comment|/* #define START_FILES crt0.o /usr/lib/Mcrt1.o  */
end_comment

end_unit

