begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* callback.h - callback demo definitions */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/others/callback/RCS/callback.h,v 7.1 91/02/22 09:26:37 mrose Interim $  *  *  * $Log:	callback.h,v $  * Revision 7.1  91/02/22  09:26:37  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  21:58:11  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"psap2.h"
end_include

begin_include
include|#
directive|include
file|"ssap.h"
end_include

begin_include
include|#
directive|include
file|"tsap.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_define
define|#
directive|define
name|RMASK
define|\
value|"\020\01HALFDUPLEX\02DUPLEX\03EXPEDITED\04MINORSYNC\05MAJORSYNC\06RESYNC\ \07ACTIVITY\010NEGOTIATED\011CAPABILITY\012EXCEPTIONS\013TYPEDATA"
end_define

begin_typedef
typedef|typedef
struct|struct
name|sblk
block|{
name|int
name|sb_sd
decl_stmt|;
comment|/* session-descriptor */
name|struct
name|SSAPref
name|sb_connect
decl_stmt|;
comment|/* session connection reference */
name|int
name|sb_requirements
decl_stmt|;
comment|/* session requirements */
name|int
name|sb_settings
decl_stmt|;
comment|/* initial settings */
name|int
name|sb_owned
decl_stmt|;
comment|/* session tokens we own */
name|long
name|sb_ssn
decl_stmt|;
comment|/* session serial number */
name|long
name|sb_isn
decl_stmt|;
comment|/* initial serial number */
block|}
typedef|*
name|SB
typedef|;
end_typedef

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

