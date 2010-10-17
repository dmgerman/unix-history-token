begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is te-go32.h */
end_comment

begin_define
define|#
directive|define
name|TE_GO32
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_DOLLAR
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-go32"
end_define

begin_comment
comment|/* GAS should treat '.align value' as an alignment of 2**value.  */
end_comment

begin_define
define|#
directive|define
name|USE_ALIGN_PTWO
end_define

begin_define
define|#
directive|define
name|COFF_LONG_SECTION_NAMES
end_define

begin_comment
comment|/* these define interfaces */
end_comment

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

end_unit

