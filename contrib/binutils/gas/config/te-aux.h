begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|TE_AUX
end_define

begin_comment
comment|/* From obj-coff.h:    This internal_lineno crap is to stop namespace pollution from the    bfd internal coff headerfile. */
end_comment

begin_define
define|#
directive|define
name|internal_lineno
value|bfd_internal_lineno
end_define

begin_include
include|#
directive|include
file|"coff/aux-coff.h"
end_include

begin_comment
comment|/* override bits in coff/internal.h */
end_comment

begin_undef
undef|#
directive|undef
name|internal_lineno
end_undef

begin_define
define|#
directive|define
name|COFF_NOLOAD_PROBLEM
end_define

begin_define
define|#
directive|define
name|KEEP_RELOC_INFO
end_define

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABELS_FB
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

