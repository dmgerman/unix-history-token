begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: mem.h,v 10.1 86/11/29 13:53:41 jg Rel $ */
end_comment

begin_comment
comment|/* $Header: mem.h,v 10.1 86/11/29 13:53:41 jg Rel $ */
end_comment

begin_comment
comment|/* mem.h	Data structure for maintaining memory allocation of vs100  *		framebuffer memory.  *  * Author:	Paul J. Asente  * 		Digital Equipment Corporation  * 		Western Reseach Lab  * Date:	June 1983  */
end_comment

begin_comment
comment|/****************************************************************************  *									    *  *  Copyright (c) 1983, 1984 by						    *  *  DIGITAL EQUIPMENT CORPORATION, Maynard, Massachusetts.		    *  *  All rights reserved.						    *  * 									    *  *  This software is furnished on an as-is basis and may be used and copied *  *  only with inclusion of the above copyright notice. This software or any *  *  other copies thereof may be provided or otherwise made available to     *  *  others only for non-commercial purposes.  No title to or ownership of   *  *  the software is hereby transferred.					    *  * 									    *  *  The information in this software is  subject to change without notice   *  *  and  should  not  be  construed as  a commitment by DIGITAL EQUIPMENT   *  *  CORPORATION.							    *  * 									    *  *  DIGITAL assumes no responsibility for the use  or  reliability of its   *  *  software on equipment which is not supplied by DIGITAL.		    *  * 									    *  *									    *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|_VSArea
block|{
name|struct
name|_VSArea
modifier|*
name|next
decl_stmt|;
name|struct
name|_VSArea
modifier|*
name|prev
decl_stmt|;
name|caddr_t
name|vsPtr
decl_stmt|;
struct|struct
block|{
name|unsigned
name|int
name|_vsFreeFlag
range|:
literal|1
decl_stmt|;
name|int
name|_vsSize
range|:
literal|31
decl_stmt|;
block|}
name|s
struct|;
union|union
block|{
struct|struct
block|{
name|struct
name|_VSArea
modifier|*
name|next
decl_stmt|;
name|struct
name|_VSArea
modifier|*
name|prev
decl_stmt|;
block|}
name|_vsFree
struct|;
name|int
name|_vsType
decl_stmt|;
block|}
name|u
union|;
block|}
name|VSArea
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vsFreeFlag
value|s._vsFreeFlag
end_define

begin_define
define|#
directive|define
name|vsSize
value|s._vsSize
end_define

begin_define
define|#
directive|define
name|vsFree
value|u._vsFree
end_define

begin_define
define|#
directive|define
name|vsType
value|u._vsType
end_define

begin_define
define|#
directive|define
name|VS_FREE
value|0
end_define

begin_define
define|#
directive|define
name|VS_INUSE
value|1
end_define

begin_define
define|#
directive|define
name|BITMAP_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|HALFTONE_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|FONT_TYPE
value|3
end_define

end_unit

