begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)tncomp.h	3.2 (Berkeley) 3/28/88  */
end_comment

begin_comment
comment|/*  * Where the fields fall on the formatted screen used by tncomp, tnrecv,  * and tnsend.  */
end_comment

begin_define
define|#
directive|define
name|SEND_SEQUENCE
value|1
end_define

begin_define
define|#
directive|define
name|SEND_SEQUENCE_LENGTH
value|23
end_define

begin_define
define|#
directive|define
name|ACK_SEQUENCE
value|(SEND_SEQUENCE+SEND_SEQUENCE_LENGTH+1)
end_define

begin_define
define|#
directive|define
name|ACK_SEQUENCE_LENGTH
value|22
end_define

begin_define
define|#
directive|define
name|CHECKSUM
value|(ACK_SEQUENCE+ACK_SEQUENCE_LENGTH+1)
end_define

begin_define
define|#
directive|define
name|CHECKSUM_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|DATA
value|(CHECKSUM+CHECKSUM_LENGTH+1)
end_define

begin_define
define|#
directive|define
name|DATA_LENGTH
value|((80*22)+79)
end_define

end_unit

