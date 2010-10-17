begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is te-psos.h for embedded systems running pSOS.    Contributed by Martin Anantharaman (martin@mail.imech.uni-duisburg.de).  */
end_comment

begin_define
define|#
directive|define
name|TE_PSOS
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

begin_comment
comment|/* This makes GAS more versatile and blocks some ELF'isms in    tc-m68k.h.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_PREFIX_OPTIONAL
value|1
end_define

begin_include
include|#
directive|include
file|"obj-format.h"
end_include

begin_comment
comment|/* end of te-psos.h */
end_comment

end_unit

