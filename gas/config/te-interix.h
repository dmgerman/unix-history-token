begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|TE_PE_DYN
end_define

begin_comment
comment|/* PE with dynamic linking (UNIX shared lib) support */
end_comment

begin_define
define|#
directive|define
name|TE_PE
end_define

begin_define
define|#
directive|define
name|LEX_AT
value|1
end_define

begin_comment
comment|/* can have @'s inside labels */
end_comment

begin_define
define|#
directive|define
name|LEX_QM
value|3
end_define

begin_comment
comment|/* can have ?'s in or begin labels */
end_comment

begin_comment
comment|/* The PE format supports long section names.  */
end_comment

begin_define
define|#
directive|define
name|COFF_LONG_SECTION_NAMES
end_define

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"__GLOBAL_OFFSET_TABLE_"
end_define

begin_comment
comment|/* Both architectures use these.  */
end_comment

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

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

end_unit

