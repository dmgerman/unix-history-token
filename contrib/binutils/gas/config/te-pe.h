begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|/* The PE format supports long section names.  */
end_comment

begin_define
define|#
directive|define
name|COFF_LONG_SECTION_NAMES
end_define

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

end_unit

