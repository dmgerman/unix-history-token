begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/include/binio.h,v 4.2 1998/06/28 16:52:15 kardel RELEASE_19990228_A  *  * $Created: Sun Jul 20 13:03:05 1997 $  *  * Copyright (C) 1997-1998 by Frank Kardel  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BINIO_H
end_ifndef

begin_define
define|#
directive|define
name|BINIO_H
end_define

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_decl_stmt
name|long
name|get_lsb_short
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|put_lsb_short
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|get_lsb_long
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|put_lsb_long
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|get_msb_short
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|put_msb_short
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|get_msb_long
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|put_msb_long
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * binio.h,v  * Revision 4.2  1998/06/28 16:52:15  kardel  * added binio MSB prototypes for {get,put}_msb_{short,long}  *  * Revision 4.1  1998/06/12 15:07:40  kardel  * fixed prototyping  *  * Revision 4.0  1998/04/10 19:50:38  kardel  * Start 4.0 release version numbering  *  * Revision 1.1  1998/04/10 19:27:32  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  * Revision 1.1  1997/10/06 20:55:37  kardel  * new parse structure  *  */
end_comment

end_unit

