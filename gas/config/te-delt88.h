begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is te-delta88.h.  */
end_comment

begin_define
define|#
directive|define
name|TE_DELTA88
value|1
end_define

begin_define
define|#
directive|define
name|COFF_NOLOAD_PROBLEM
value|1
end_define

begin_comment
comment|/* Added these, because if we don't know what we're targeting we may    need an assembler version of libgcc, and that will use local    labels.  */
end_comment

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

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

end_unit

