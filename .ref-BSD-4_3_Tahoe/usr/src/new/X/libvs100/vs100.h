begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: vs100.h,v 10.3 86/02/01 15:47:56 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"packet.h"
end_include

begin_include
include|#
directive|include
file|"mem.h"
end_include

begin_include
include|#
directive|include
file|"../X/vsinput.h"
end_include

begin_include
include|#
directive|include
file|"../X/Xdev.h"
end_include

begin_include
include|#
directive|include
file|"../X/X.h"
end_include

begin_define
define|#
directive|define
name|HTCROCK
end_define

begin_comment
comment|/* Writearound for Halftone alignment problem */
end_comment

begin_define
define|#
directive|define
name|VBUFSIZE
value|2048
end_define

begin_define
define|#
directive|define
name|MAPTYPE
parameter_list|(
name|x
parameter_list|)
value|(x>> 4)
end_define

begin_define
define|#
directive|define
name|MAPLIT
parameter_list|(
name|x
parameter_list|)
value|(x& 0xf)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_curspriv
block|{
name|BITMAP
modifier|*
name|image
decl_stmt|;
name|BITMAP
modifier|*
name|mask
decl_stmt|;
name|short
name|map
decl_stmt|;
block|}
name|CursPriv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CDATA
parameter_list|(
name|x
parameter_list|)
value|((CursPriv *) x->data)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_fontpriv
block|{
name|short
modifier|*
name|widths
decl_stmt|;
name|VSArea
modifier|*
name|remote
decl_stmt|;
block|}
name|FontPriv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FDATA
parameter_list|(
name|x
parameter_list|)
value|((FontPriv *) x->data)
end_define

begin_define
define|#
directive|define
name|BDATA
parameter_list|(
name|x
parameter_list|)
value|((VSArea *) x->data)
end_define

begin_define
define|#
directive|define
name|PDATA
parameter_list|(
name|x
parameter_list|)
value|((BITMAP *) x->data)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HTCROCK
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|_tilepriv
block|{
name|BITMAP
modifier|*
name|bitmap
decl_stmt|;
name|short
name|data
index|[
literal|16
index|]
decl_stmt|;
block|}
name|TilePriv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TDATA
parameter_list|(
name|x
parameter_list|)
value|((TilePriv *) x->data)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

