begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/* (c) Copyright Tai Jin, 1988.  All Rights Reserved.                    */
end_comment

begin_comment
comment|/*     Hewlett-Packard Laboratories.                                     */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/* Permission is hereby granted for unlimited modification, use, and     */
end_comment

begin_comment
comment|/* distribution.  This software is made available with no warranty of    */
end_comment

begin_comment
comment|/* any kind, express or implied.  This copyright notice must remain      */
end_comment

begin_comment
comment|/* intact in all versions of this software.                              */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/* The author would appreciate it if any bug fixes and enhancements were */
end_comment

begin_comment
comment|/* to be sent back to him for incorporation into future versions of this */
end_comment

begin_comment
comment|/* software.  Please send changes to tai@iag.hp.com or ken@sdd.hp.com.   */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/* "adjtime.h,v 3.1 1993/07/06 01:04:43 jbj Exp" */
end_comment

begin_comment
comment|/* adjtime.h,v  * Revision 3.1  1993/07/06  01:04:43  jbj  * NTP release 3.1  *  *  * Revision 1.5  90/02/07  15:34:18  15:34:18  src (Source Hacker)  * CHANGED KEY !!!  *   * Revision 1.4  89/02/09  12:26:35  12:26:35  tai (Tai Jin (Guest))  * *** empty log message ***  *   * Revision 1.4  89/02/09  12:26:35  12:26:35  tai (Tai Jin)  * added comment  *   * Revision 1.3  88/08/30  01:08:29  01:08:29  tai (Tai Jin)  * fix copyright notice again  *   * Revision 1.2  88/08/30  00:51:55  00:51:55  tai (Tai Jin)  * fix copyright notice  *   * Revision 1.1  88/04/02  14:56:54  14:56:54  tai (Tai Jin)  * Initial revision  *  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_define
define|#
directive|define
name|KEY
value|659847L
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|msgbuf
name|msgp
decl_stmt|;
struct|struct
block|{
name|long
name|mtype
decl_stmt|;
name|int
name|code
decl_stmt|;
name|struct
name|timeval
name|tv
decl_stmt|;
block|}
name|msgb
struct|;
block|}
name|MsgBuf
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSGSIZE
value|(sizeof(int) + sizeof(struct timeval))
end_define

begin_comment
comment|/*  * mtype values  */
end_comment

begin_define
define|#
directive|define
name|CLIENT
value|1L
end_define

begin_define
define|#
directive|define
name|SERVER
value|2L
end_define

begin_comment
comment|/*  * code values  */
end_comment

begin_define
define|#
directive|define
name|DELTA1
value|0
end_define

begin_define
define|#
directive|define
name|DELTA2
value|1
end_define

end_unit

